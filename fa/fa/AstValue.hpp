#ifndef __AST_VALUE_HPP__
#define __AST_VALUE_HPP__



#include <optional>
#include <string>

#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/IRBuilder.h>

#include <FaParser.h>
#include "ValueBuilder.hpp"
#include "TypeMap.hpp"
#include "Log.hpp"



class AstValue {
	enum class AstObjectType { None, Value, Var, Func, TypeStr };

public:
	AstValue () {}
	AstValue (std::nullopt_t) {}
	explicit AstValue (std::shared_ptr<ValueBuilder> _value_builder, FaParser::LiteralContext *_literal) {
		std::optional<llvm::Value *> _val;
		if (_literal->BoolLiteral ()) {
			_val = _value_builder->Build ("bool", _literal->getText (), _literal->start);
		} else if (_literal->IntLiteral ()) {
			_val = _value_builder->Build ("int32", _literal->getText (), _literal->start);
		} else if (_literal->FloatLiteral ()) {
			_val = _value_builder->Build ("float64", _literal->getText (), _literal->start);
		} else if (_literal->String1Literal ()) {
			std::string _data1 = _literal->getText ();
			_data1 = _data1.substr (1, _data1.size () - 2);
			std::string _data2;
			_data2.reserve (_data1.size ());
			_val = _value_builder->Build ("string", _literal->getText (), _literal->start);
		} else {
			LOG_ERROR (_literal->start, "未知数据类型");
		}

		if (_val.has_value ()) {
			m_type = AstObjectType::Value;
			m_value = _val.value ();
		}
	}
	AstValue (llvm::AllocaInst *_var): m_type (AstObjectType::Var), m_value (_var) {}
	AstValue (llvm::Value *_value): m_type (AstObjectType::Value), m_value (_value) {}
	AstValue (llvm::Function *_func): m_type (AstObjectType::Func), m_func (_func) {}
	AstValue &operator= (const llvm::Value *_val) { AstValue _o { const_cast<llvm::Value *> (_val) }; return operator= (_o); }
	AstValue &operator= (const llvm::Function *_val) { AstValue _o { const_cast<llvm::Function *> (_val) }; return operator= (_o); }
	AstValue &operator= (const AstValue &_o) {
		m_type = _o.m_type;
		m_value = _o.m_value;
		m_func = _o.m_func;
		return *this;
	}

	bool IsValid () const { return m_type != AstObjectType::None; }
	bool IsValue () const { return m_type == AstObjectType::Value || m_type == AstObjectType::Var; }
	bool IsVariable () const { return m_type == AstObjectType::Var; }
	bool IsFunction () const { return m_type == AstObjectType::Func; }
	bool IsTypeStr () const { return m_type == AstObjectType::Value || m_type == AstObjectType::Var || m_type == AstObjectType::TypeStr; }

	llvm::Value *Value (llvm::IRBuilder<> &_builder) {
		if (m_type == AstObjectType::Value) {
			return m_value;
		} else if (m_type == AstObjectType::Var) {
			return _builder.CreateLoad (m_value);
		} else {
			return nullptr;
		}
	}
	llvm::CallInst *FunctionCall (llvm::IRBuilder<> &_builder, std::vector<llvm::Value *> &_args) {
		if (m_type != AstObjectType::Func || m_func == nullptr)
			return nullptr;
		return _builder.CreateCall (m_func, _args);
	}
	//bool Assign (llvm::IRBuilder<> &_builder, AstValue &_val, antlr4::Token *_t) {
	//	if (m_type != AstObjectType::Var) {
	//		LOG_ERROR (_t, "非变量类型无法赋值");
	//		return false;
	//	}
	//	_builder.CreateStore (_val.Value (_builder), m_value);
	//	return true;
	//}
	AstValue DoOper1 (llvm::IRBuilder<> &_builder, std::shared_ptr<ValueBuilder> _value_builder, std::string _op, antlr4::Token *_t) {
		if (!IsValue ())
			return std::nullopt;
		llvm::Value *_tmp = Value (_builder);
		if (_op == "+") {
			return *this;
		} else {
			std::string _typestr = TypeMap::GetTypeName (m_value->getType ());
			if (_op == "-") {
				std::optional<llvm::Value *> _tmp2 = _value_builder->Build (_typestr, "0", _t);
				if (!_tmp2.has_value ())
					return std::nullopt;
				return _builder.CreateSub (_tmp2.value (), _tmp);
			} else if (_op == "++" || _op == "--") {
				std::optional<llvm::Value *> _tmp2 = _value_builder->Build (_typestr, "1", _t);
				if (!_tmp2.has_value ())
					return std::nullopt;
				AstValue _v;
				if (_op == "++") {
					_v = _builder.CreateAdd (Value (_builder), _tmp2.value ());
				} else {
					_v = _builder.CreateSub (Value (_builder), _tmp2.value ());
				}
				if (!Assign (_builder, _v, _t))
					return std::nullopt;
				return *this;
			} else if (_op == "~") {
				if (_typestr != "bool") {
					LOG_ERROR (_t, "非bool类型数据无法取反");
					return std::nullopt;
				}
				std::optional<llvm::Value *> _tmp2 = _value_builder->Build (_typestr, "true", _t);
				if (!_tmp2.has_value ())
					return std::nullopt;
				return _builder.CreateSub (_tmp2.value (), _tmp);
			}
		}

		LOG_ERROR (_t, fmt::format ("暂不支持的运算符 {}", _op));
		return std::nullopt;
	}
	AstValue DoOper2 (llvm::IRBuilder<> &_builder, std::shared_ptr<ValueBuilder> _value_builder, std::string _op, AstValue &_other, antlr4::Token *_t) {
		if (!_other.IsValid ())
			return std::nullopt;
		AstValue _tmp;
		if (_op.size () == 1) {
			switch (_op [0]) {
			case '+': return _builder.CreateAdd (Value (_builder), _other.Value (_builder));
			case '-': return _builder.CreateSub (Value (_builder), _other.Value (_builder));
			case '*': return _builder.CreateMul (Value (_builder), _other.Value (_builder));
			case '/': return _builder.CreateSDiv (Value (_builder), _other.Value (_builder));
			case '%': return _builder.CreateSRem (Value (_builder), _other.Value (_builder));
			case '|': return _builder.CreateOr (Value (_builder), _other.Value (_builder));
			case '&': return _builder.CreateAnd (Value (_builder), _other.Value (_builder));
			case '^': return _builder.CreateXor (Value (_builder), _other.Value (_builder));
			case '<': return _builder.CreateICmpSLT (Value (_builder), _other.Value (_builder));
			case '>': return _builder.CreateICmpSGT (Value (_builder), _other.Value (_builder));
			case '=':
				_builder.CreateStore (_other.Value (_builder), m_value);
				return *this;
			}
		} else if (_op.size () == 2) {
			if (_op [0] == _op [1]) {
				switch (_op [0]) {
				case '?': return _builder.CreateAdd (Value (_builder), _other.Value (_builder));
				case '*': return _builder.CreateAdd (Value (_builder), _other.Value (_builder));
				case '&': return _builder.CreateAnd (Value (_builder), _other.Value (_builder));
				case '|': return _builder.CreateOr (Value (_builder), _other.Value (_builder));
				case '<': return _builder.CreateShl (Value (_builder), _other.Value (_builder));
				case '>':
					_tmp = _other.DoOper1 (_builder, _value_builder, "-", _t);
					return _builder.CreateShl (Value (_builder), _tmp.Value (_builder));
				}
			} else if (_op [1] == '=') {
				switch (_op [0]) {
				case '<': return _builder.CreateICmpSLE (Value (_builder), _other.Value (_builder));
				case '>': return _builder.CreateICmpSGE (Value (_builder), _other.Value (_builder));
				case '+':
				case '-':
				case '*':
				case '/':
				case '%':
				case '|':
				case '&':
				case '^':
					std::string _tmp_op = "";
					_tmp_op += _op [0];
					_tmp = DoOper2 (_builder, _value_builder, _tmp_op, _other, _t);
					return DoOper2 (_builder, _value_builder, "=", _tmp, _t);
				}
			}
		} else if (_op.size () == 3) {
			if (_op == "<<=" || _op == ">>=") {
				_tmp = DoOper2 (_builder, _value_builder, _op.substr (0, 2), _other, _t);
				return DoOper2 (_builder, _value_builder, "=", _tmp, _t);
			}
		}
		return std::nullopt;
	}

private:
	AstObjectType m_type = AstObjectType::None;
	llvm::Value *m_value = nullptr;
	llvm::Function *m_func = nullptr;
};



#endif //__AST_VALUE_HPP__

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



class AstObject {
	enum class AstObjectType { None, Value, Var, Func, TypeStr };

public:
	AstObject () {}
	AstObject (std::nullopt_t) {}
	explicit AstObject (bool _allow_assign): m_allow_assign (_allow_assign) {}
	explicit AstObject (std::shared_ptr<ValueBuilder> _value_builder, FaParser::LiteralContext *_literal) {
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
	AstObject (llvm::AllocaInst *_var): m_type (AstObjectType::Var), m_value (_var) {}
	AstObject (llvm::Value *_value): m_type (AstObjectType::Value), m_value (_value) {}
	AstObject (llvm::Function *_func): m_type (AstObjectType::Func), m_func (_func) {}
	AstObject &operator= (const llvm::Value *_val) {
		AstObject _o { _val };
		return operator= (_o);
	}
	AstObject &operator= (const AstObject &_o) {
		if (m_allow_assign) {
			m_type = _o.m_type;
			m_value = _o.m_value;
			m_func = _o.m_func;
		} else {
			LOG_ERROR (nullptr, "当前 AstObject 对象不允许赋值");
		}
		return *this;
	}

	bool AllowAssign () const { return m_allow_assign; }
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
	bool Assign (llvm::IRBuilder<> &_builder, AstObject &_val, antlr4::Token *_t) {
		if (m_type != AstObjectType::Var) {
			LOG_ERROR (_t, "非变量类型无法赋值");
			return false;
		}
		_builder.CreateStore (_val.Value (_builder), m_value);
		return true;
	}
	AstObject DoOper1 (llvm::IRBuilder<> &_builder, std::shared_ptr<ValueBuilder> _value_builder, std::string _op, antlr4::Token *_t) {
		if (!IsValue ())
			return std::nullopt;
		llvm::Value *_tmp = _builder.CreateLoad (m_value);
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
				AstObject _v;
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
	AstObject DoOper2 (llvm::IRBuilder<> &_builder, std::shared_ptr<ValueBuilder> _value_builder, std::string _op, AstObject &_val, antlr4::Token *_t) {
		if (_op [_op.size () - 1] == '=') {
			if (_op.size () > 1) {
				AstObject _tmp = DoOper2 (_builder, _value_builder, _op.substr (0, _op.size () - 1), _val, _t);
				if (!_tmp.IsValid ())
					return std::nullopt;
				if (!Assign (_builder, _tmp, _t))
					return std::nullopt;
			} else {
				if (!Assign (_builder, _val, _t))
					return std::nullopt;
			}
			return *this;
		}
		llvm::Value *_tmp = _builder.CreateLoad (m_value);
		llvm::Value *_v = _val.Value (_builder);
		if (_op.size () == 1) {
			switch (_op [0]) {
			case '+': return _builder.CreateAdd (_tmp, _v);
			case '-': return _builder.CreateSub (_tmp, _v);
			case '*': return _builder.CreateMul (_tmp, _v);
			case '/': return _builder.CreateSDiv (_tmp, _v);
			case '%': return _builder.CreateSRem (_tmp, _v);
			case '|': return _builder.CreateOr (_tmp, _v);
			case '&': return _builder.CreateAnd (_tmp, _v);
			case '^': return _builder.CreateXor (_tmp, _v);
			}
		} else if (_op.size () == 2 && _op [0] == _op [1]) {
			switch (_op [0]) {
			case '?': return _builder.CreateAdd (_tmp, _v);
			case '*': return _builder.CreateAdd (_tmp, _v);
			case '&': return _builder.CreateAnd (_tmp, _v);
			case '|': return _builder.CreateOr (_tmp, _v);
			case '<': return _builder.CreateShl (_tmp, _v);
			case '>': return _builder.CreateShl (_tmp, DoOper1 (_builder, _value_builder, "-", _t).Value (_builder));
			}
		}
		return std::nullopt;
	}
	static AstObject nullopt;

private:
	bool m_allow_assign = true;
	AstObjectType m_type = AstObjectType::None;
	llvm::Value *m_value = nullptr;
	llvm::Function *m_func = nullptr;
};

inline AstObject AstObject::nullopt { false };



#endif //__AST_VALUE_HPP__

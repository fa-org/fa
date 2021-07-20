#ifndef __AST_VALUE_HPP__
#define __AST_VALUE_HPP__



#include <optional>
#include <string>

#include <llvm/IR/Value.h>
#include <llvm/IR/Instructions.h>

#include <FaParser.h>
#include "ValueBuilder.hpp"
#include "TypeMap.hpp"
#include "Log.hpp"



class AstValue {
	enum class AstValueType { None, Value, Var, Func };

public:
	AstValue () {}
	AstValue (std::nullopt_t) {}
	AstValue (std::shared_ptr<ValueBuilder> _value_builder, FaParser::LiteralContext *_literal) {
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
			m_type = AstValueType::Value;
			m_value = _val.value ();
		}
	}
	AstValue (std::shared_ptr<ValueBuilder> _value_builder, llvm::AllocaInst *_var) {
		m_type = AstValueType::Var;
		m_value = _var;
	}
	AstValue (llvm::Value *_value): m_type (AstValueType::Value), m_value (_value) {}
	AstValue (llvm::Function *_func): m_type (AstValueType::Func), m_func (_func) {}
	//AstValue &operator= (llvm::Value *_value) {
	//	m_type = AstValueType::Value;
	//	m_value = _value;
	//	return *this;
	//}

	bool IsValid () const { return m_type != AstValueType::None; }
	bool IsValue () const { return m_type == AstValueType::Value || m_type == AstValueType::Var; }
	bool IsVariable () const { return m_type == AstValueType::Var; }
	bool IsFunction () const { return m_type == AstValueType::Func; }

	llvm::Value *Value (llvm::IRBuilder<> &_builder) {
		if (m_type == AstValueType::Value) {
			return m_value;
		} else if (m_type == AstValueType::Var) {
			return _builder.CreateLoad (m_value);
		} else {
			return nullptr;
		}
	}
	llvm::CallInst *FunctionCall (llvm::IRBuilder<> &_builder, std::vector<llvm::Value *> &_args) {
		if (m_type != AstValueType::Func || m_func == nullptr)
			return nullptr;
		return _builder.CreateCall (m_func, _args);
	}
	bool Assign (llvm::IRBuilder<> &_builder, AstValue &_val, antlr4::Token *_t) {
		if (m_type != AstValueType::Var) {
			LOG_ERROR (_t, "非变量类型无法赋值");
			return false;
		}
		_builder.CreateStore (_val.Value (_builder), m_value);
		return true;
	}
	AstValue DoOper1 (llvm::IRBuilder<> &_builder, std::shared_ptr<ValueBuilder> _value_builder, std::string _op, antlr4::Token *_t) {
		if (!IsValue ())
			return std::nullopt;
		llvm::Value *_tmp = _builder.CreateLoad (m_value);
		if (_op == "+") {
			return *this;
		} else {
			std::string _type = TypeMap::GetTypeName (m_value->getType ());
			if (_op == "-") {
				std::optional<llvm::Value *> _tmp2 = _value_builder->Build (_type, "0", _t);
				if (!_tmp2.has_value ())
					return std::nullopt;
				return _builder.CreateSub (_tmp2.value (), _tmp);
			} else if (_op == "++" || _op == "--") {
				std::optional<llvm::Value *> _tmp2 = _value_builder->Build (_type, "1", _t);
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
				if (_type != "bool") {
					LOG_ERROR (_t, "非bool类型数据无法取反");
					return std::nullopt;
				}
				std::optional<llvm::Value *> _tmp2 = _value_builder->Build (_type, "true", _t);
				if (!_tmp2.has_value ())
					return std::nullopt;
				return _builder.CreateSub (_tmp2.value (), _tmp);
			}
		}

		LOG_ERROR (_t, fmt::format ("暂不支持的运算符 {}", _op));
		return std::nullopt;
	}
	AstValue DoOper2 (llvm::IRBuilder<> &_builder, std::string _op, AstValue &_val, antlr4::Token *_t) {
		if (_op [_op.size () - 1] == '=') {
			if (_op.size () > 1) {
				AstValue _tmp = DoOper2 (_builder, _op.substr (0, _op.size () - 1), _val, _t);
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
		}
		return std::nullopt;
	}

private:
	AstValueType m_type = AstValueType::None;
	llvm::Value *m_value = nullptr;
	llvm::Function *m_func = nullptr;
};



#endif //__AST_VALUE_HPP__

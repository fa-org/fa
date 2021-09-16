#ifndef __AST_VALUE_HPP__
#define __AST_VALUE_HPP__



#include <format>
#include <functional>
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <tuple>

#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/IRBuilder.h>

#include <FaParser.h>
#include "ValueBuilder.hpp"
#include "TypeMap.hpp"
#include "Log.hpp"
#include "FuncType.hpp"



class AstValue {
	enum class AstObjectType { None, Void, Value, Var, Func, TypeStr, MemberStr };

public:
	static AstValue FromVoid () { AstValue _v {}; _v.m_type = AstObjectType::Void; return _v; }
	AstValue () {}
	AstValue (std::nullopt_t) {}
	AstValue (std::shared_ptr<ValueBuilder> _value_builder, FaParser::LiteralContext *_literal, std::string _value_type) {
		if (_literal->BoolLiteral ()) {
			if (_value_type == "") {
				_value_type = "bool";
			} else if (_value_type != "bool") {
				LOG_ERROR (_literal->start, std::format ("当前数据无法转为 {} 类型", _value_type));
				return;
			}
		} else if (_literal->IntLiteral ()) {
			if (_value_type == "") {
				_value_type = "int";
			} else if (_value_type.substr (0, 3) != "int") {
				LOG_ERROR (_literal->start, std::format ("当前数据无法转为 {} 类型", _value_type));
				return;
			}
		} else if (_literal->FloatLiteral ()) {
			if (_value_type == "") {
				_value_type = "float64";
			} else if (_value_type.substr (0, 5) != "float") {
				LOG_ERROR (_literal->start, std::format ("当前数据无法转为 {} 类型", _value_type));
				return;
			}
		} else if (_literal->String1Literal ()) {
			if (_value_type == "") {
				_value_type = "int8*";
			} else if (_value_type != "int8*") {
				LOG_ERROR (_literal->start, std::format ("当前数据无法转为 {} 类型", _value_type));
				return;
			}
		} else {
			LOG_ERROR (_literal->start, "未知数据类型");
			return;
		}
		m_value_type = _value_type;
		std::optional<std::tuple<llvm::Value *, std::string>> _oval = _value_builder->Build (m_value_type, _literal->getText (), _literal->start);
		if (_oval.has_value ()) {
			m_type = AstObjectType::Value;
			std::tie (m_value, m_value_type) = _oval.value ();
		}
	}
	AstValue (llvm::AllocaInst *_var, std::string _value_type): m_type (_var ? AstObjectType::Var : AstObjectType::None), m_value (_var), m_value_type (_value_type) {}
	AstValue (llvm::Value *_value, std::string _value_type): m_type (_value ? AstObjectType::Value : AstObjectType::None), m_value (_value), m_value_type (_value_type) {}
	AstValue (std::shared_ptr<FuncType> _func): m_type (AstObjectType::Func), m_func (_func), m_value_type (_func->m_name) {}
	AstValue (std::string _member): m_member (_member), m_type (AstObjectType::MemberStr) {}
	//AstValue &operator= (const llvm::AllocaInst *_val) { AstValue _o { const_cast<llvm::AllocaInst *> (_val) }; return operator= (_o); }
	//AstValue &operator= (const llvm::Value *_val) { AstValue _o { const_cast<llvm::Value *> (_val) }; return operator= (_o); }
	//AstValue &operator= (const llvm::Function *_val) { AstValue _o { const_cast<llvm::Function *> (_val) }; return operator= (_o); }
	AstValue &operator= (const AstValue &_o) {
		m_type = _o.m_type;
		m_value = _o.m_value;
		m_func = _o.m_func;
		m_member = _o.m_member;
		m_value_type = _o.m_value_type;
		return *this;
	}

	bool IsValid () const { return m_type != AstObjectType::None; }
	bool IsVoid () const { return m_type == AstObjectType::Void; }
	bool IsValue () const { return m_type == AstObjectType::Value || m_type == AstObjectType::Var; }
	bool IsVariable () const { return m_type == AstObjectType::Var; }
	bool IsFunction () const { return m_type == AstObjectType::Func; }
	bool IsTypeStr () const { return m_type == AstObjectType::Value || m_type == AstObjectType::Var || m_type == AstObjectType::TypeStr; }
	bool IsMember () const { return m_type == AstObjectType::MemberStr; }

	llvm::Value *Value (llvm::IRBuilder<> &_builder) {
		if (m_type == AstObjectType::Value) {
			return m_value;
		} else if (m_type == AstObjectType::Var) {
			return _builder.CreateLoad (m_value);
		} else {
			return nullptr;
		}
	}
	llvm::CallInst *FuncInvoke (llvm::IRBuilder<> &_builder, std::vector<llvm::Value *> &_args) {
		if (m_type != AstObjectType::Func || m_func == nullptr)
			return nullptr;
		return _builder.CreateCall (m_func->m_fp, _args);
	}
	AstValue DoOper1 (llvm::IRBuilder<> &_builder, std::shared_ptr<ValueBuilder> _value_builder, std::string _op, antlr4::Token *_t) {
		if (!IsValue ())
			return std::nullopt;
		llvm::Value *_tmp = Value (_builder);
		if (_op == "+") {
			return *this;
		} else {
			std::string _typestr = TypeMap::GetTypeName (m_value->getType ());
			if (_op == "-") {
				auto _tmp2 = _value_builder->Build (m_value_type, "0", _t);
				if (!_tmp2.has_value ())
					return std::nullopt;
				auto [_tmp_val, _] = _tmp2.value ();
				return AstValue { _builder.CreateSub (_tmp_val, _tmp), m_value_type };
			} else if (_op == "++" || _op == "--") {
				auto _tmp2 = _value_builder->Build (m_value_type, "1", _t);
				if (!_tmp2.has_value ())
					return std::nullopt;
				auto [_tmp_val, _] = _tmp2.value ();
				AstValue _v;
				if (_op == "++") {
					_v = AstValue { _builder.CreateAdd (Value (_builder), _tmp_val), m_value_type };
				} else {
					_v = AstValue { _builder.CreateSub (Value (_builder), _tmp_val), m_value_type };
				}
				if (!m_value)
					return std::nullopt;
				_builder.CreateStore (_v.Value (_builder), m_value);
				return *this;
			} else if (_op == "~") {
				if (m_value_type != "bool") {
					LOG_ERROR (_t, "非bool类型数据无法取反");
					return std::nullopt;
				}
				auto _tmp2 = _value_builder->Build (m_value_type, "true", _t);
				if (!_tmp2.has_value ())
					return std::nullopt;
				auto [_tmp_val, _] = _tmp2.value ();
				return AstValue { _builder.CreateSub (_tmp_val, _tmp), m_value_type };
			}
		}

		LOG_ERROR (_t, std::format ("暂不支持的运算符 {}", _op));
		return std::nullopt;
	}
	AstValue DoOper2 (llvm::IRBuilder<> &_builder, std::shared_ptr<ValueBuilder> _value_builder, std::string _op, AstValue &_other, antlr4::Token *_t) {
		if (!_other.IsValid ())
			return std::nullopt;
		AstValue _tmp;
		if (_op.size () == 1) {
			switch (_op [0]) {
			case '+': return AstValue { _builder.CreateAdd (Value (_builder), _other.Value (_builder)), m_value_type };
			case '-': return AstValue { _builder.CreateSub (Value (_builder), _other.Value (_builder)), m_value_type };
			case '*': return AstValue { _builder.CreateMul (Value (_builder), _other.Value (_builder)), m_value_type };
			case '/': return AstValue { _builder.CreateSDiv (Value (_builder), _other.Value (_builder)), m_value_type };
			case '%': return AstValue { _builder.CreateSRem (Value (_builder), _other.Value (_builder)), m_value_type };
			case '|': return AstValue { _builder.CreateOr (Value (_builder), _other.Value (_builder)), m_value_type };
			case '&': return AstValue { _builder.CreateAnd (Value (_builder), _other.Value (_builder)), m_value_type };
			case '^': return AstValue { _builder.CreateXor (Value (_builder), _other.Value (_builder)), m_value_type };
			case '<': return AstValue { _builder.CreateICmpSLT (Value (_builder), _other.Value (_builder)), "bool" };
			case '>': return AstValue { _builder.CreateICmpSGT (Value (_builder), _other.Value (_builder)), "bool" };
			case '=':
				_builder.CreateStore (_other.Value (_builder), m_value);
				return *this;
			}
		} else if (_op.size () == 2) {
			if (_op [0] == _op [1]) {
				switch (_op [0]) {
				case '?':
				{
					std::string _tmp_value_type = "";
					if (m_value_type [m_value_type.size () - 1] == '?') {
						_tmp_value_type = m_value_type.substr (0, m_value_type.size () - 1);
					} else if (m_value_type [m_value_type.size () - 2] == '?') {
						_tmp_value_type = m_value_type.substr (0, m_value_type.size () - 1);
						_tmp_value_type [_tmp_value_type.size () - 1] = m_value_type [m_value_type.size () - 1];
					} else {
						LOG_ERROR (_t, "目标类型不可为空，无法使用 ?? 运算符");
						return std::nullopt;
					}
					return AstValue { _builder.CreateAdd (Value (_builder), _other.Value (_builder)), _tmp_value_type };
				}
				case '*': return AstValue { _builder.CreateAdd (Value (_builder), _other.Value (_builder)), m_value_type };
				case '&': return AstValue { _builder.CreateAnd (Value (_builder), _other.Value (_builder)), m_value_type };
				case '|': return AstValue { _builder.CreateOr (Value (_builder), _other.Value (_builder)), m_value_type };
				case '<': return AstValue { _builder.CreateShl (Value (_builder), _other.Value (_builder)), m_value_type };
				case '>':
					_tmp = _other.DoOper1 (_builder, _value_builder, "-", _t);
					return AstValue { _builder.CreateShl (Value (_builder), _tmp.Value (_builder)), m_value_type };
				case '=':
					return AstValue { _builder.CreateICmpEQ (Value (_builder), _other.Value (_builder)), "bool" };
				}
			} else if (_op [1] == '=') {
				switch (_op [0]) {
				case '<': return AstValue { _builder.CreateICmpSLE (Value (_builder), _other.Value (_builder)), "bool" };
				case '>': return AstValue { _builder.CreateICmpSGE (Value (_builder), _other.Value (_builder)), "bool" };
				case '+':
				case '-':
				case '*':
				case '/':
				case '%':
				case '|':
				case '&':
				case '^':
					_tmp = DoOper2 (_builder, _value_builder, _op.substr (0, 1), _other, _t);
					return DoOper2 (_builder, _value_builder, "=", _tmp, _t);
				case '!': return AstValue { _builder.CreateICmpNE (Value (_builder), _other.Value (_builder)), "bool" };
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

	std::string GetType () { return m_value_type; }

	std::string GetFuncReturnType () { return m_func->m_ret_type; }
	std::tuple<std::string, std::vector<std::string>> GetFuncType () { return { m_func->m_ret_type, m_func->m_arg_types }; }

private:
	AstObjectType				m_type = AstObjectType::None;
	llvm::Value					*m_value = nullptr;
	std::shared_ptr<FuncType>	m_func;
	std::string					m_member = "";
	std::string					m_value_type = "";
};



#endif //__AST_VALUE_HPP__

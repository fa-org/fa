#ifndef __FUNC_CONTEXT_HPP__
#define __FUNC_CONTEXT_HPP__



#include <format>
#include <functional>
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <tuple>
#include <vector>

#include <antlr4-runtime/Token.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Type.h>

#include "TypeMap.hpp"
#include "AstValue.hpp"
#include "AstExprOrValue.hpp"
#include "FuncType.hpp"
#include "Log.hpp"



class FuncContext {
public:
	FuncContext (AstClasses& _global_classes, std::shared_ptr<FuncTypes> _global_funcs, std::string _func_name, std::string _exp_type, std::string _namespace, std::vector<std::tuple<std::string, std::string>> &_args):
		m_global_classes (_global_classes), m_ctx (_global_funcs->m_ctx), m_module (_global_funcs->m_module),
		m_type_map (_global_funcs->m_type_map), m_value_builder (_global_funcs->m_value_builder),
		m_func (_global_funcs->GetFunc (_func_name).value ()), m_fp (_global_funcs->GetFuncPtr (_func_name)),
		m_exp_type (_exp_type), m_namespace (_namespace)
	{
		llvm::BasicBlock* _bb = llvm::BasicBlock::Create (*m_ctx, "", m_fp);
		m_builder = std::make_shared<llvm::IRBuilder<>> (_bb);
		m_builder->SetInsertPoint (_bb);
		////
		m_local_vars.reserve (32);
		m_local_vars.emplace_back (std::map<std::string, std::tuple<llvm::AllocaInst* , std::string>> {});
		//
		auto _arg_iter = m_fp->arg_begin ();
		for (size_t i = 0; i < _args.size (); i++, _arg_iter++) {
			auto [_arg_name, _arg_type] = _args [i];
			m_args [_arg_name] = { _arg_iter, _arg_type };
		}
	}

	std::optional<AstValue> DefineVariable (std::string _type, antlr4::Token* _t, std::string _name = "") {
		if (_type [0] == '$')
			_type = _type.substr (1);
		std::string _var_type = std::format ("${}", _type);
		if (_name != "" && GetVariable (_name).has_value ()) {
			LOG_ERROR (_t, std::format ("重复定义的变量：{}", _name));
			return std::nullopt;
		}
		std::optional<llvm::Type*> _ret_type = m_type_map->GetType (_type, _t);
		if (!_ret_type.has_value ())
			return std::nullopt;
		if (m_virtual)
			return AstValue { (llvm::AllocaInst* ) nullptr, _var_type };

		auto _inst = m_builder->CreateAlloca (_ret_type.value ());
		if (_name != "")
			(*m_local_vars.rbegin ()) [_name] = { _inst, _var_type };
		return AstValue { _inst, _var_type };
	}
	std::optional<AstValue> DefineArrayVariable (std::string _type, antlr4::Token* _t, AstValue &_capacity, std::string _name = "") {
		if (_type [0] == '$')
			_type = _type.substr (1);
		std::string _var_type = std::format ("${}[]", _type);
		if (_name != "" && GetVariable (_name).has_value ()) {
			LOG_ERROR (_t, std::format ("重复定义的变量：{}", _name));
			return std::nullopt;
		}
		std::optional<llvm::Type*> _ret_type = m_type_map->GetType (_type, _t);
		if (!_ret_type.has_value ())
			return std::nullopt;
		if (m_virtual)
			return AstValue { (llvm::AllocaInst*) nullptr, _var_type };

		auto _arr = m_builder->CreateAlloca (_ret_type.value (), _capacity.Value (*m_builder));
		if (_name != "")
			(*m_local_vars.rbegin ()) [_name] = { _arr, _var_type };
		auto _oint_type = m_type_map->GetType ("int32");
		if (!_oint_type.has_value ())
			return std::nullopt;
		auto _int_type = _oint_type.value ();
		auto _asize = m_builder->CreateAlloca (_int_type);
		auto _acapacity = m_builder->CreateAlloca (_int_type);
		m_array_attaches [_arr] = std::make_tuple (_asize, _acapacity);
		return AstValue { _arr, _asize, _acapacity, _var_type };
	}
	std::optional<AstValue> GetVariable (std::string _name) {
		for (auto _i = m_local_vars.rbegin (); _i != m_local_vars.rend (); ++_i) {
			if (_i->contains (_name)) {
				auto &[_var, _type] = (*_i)[_name];
				if (m_array_attaches.contains (_var)) {
					auto [_asize, _acapacity] = m_array_attaches [_var];
					return AstValue { _var, _asize, _acapacity, _type };
				} else {
					return AstValue { _var, _type };
				}
			}
		}
		return std::nullopt;
	}
	std::optional<AstValue> GetArgument (std::string _name) {
		if (!m_args.contains (_name))
			return std::nullopt;
		auto [_arg_val, _arg_type] = m_args [_name];
		return AstValue { _arg_val, _arg_type };
	}
	bool BindTempVariable (antlr4::Token *_t, AstValue &_val, std::string _name) {
		if (GetVariable (_name).has_value ()) {
			LOG_ERROR (_t, std::format ("重复定义的变量：{}", _name));
			return false;
		}
		(*m_local_vars.rbegin ()) [_name] = { (llvm::AllocaInst*) _val.ValueRaw (), _val.GetType () };
		return true;
	}

	bool InitClass (AstValue &_cls, std::shared_ptr<_AST_NewCtx> _newval, std::function<std::optional<AstValue> (_AST_ExprOrValue)> _cb) {
		//m_builder->CreateExtractElement
		//m_builder->CreateGEP ();
		for (size_t i = 0; i < _newval->m_cls_vars.size (); ++i) {
			auto _val_raw = m_builder->CreateStructGEP (_cls.ValueRaw (), (unsigned int) i);
			AstValue _op1 { (llvm::AllocaInst*) _val_raw, std::format ("${}", _newval->m_cls->m_vars [i]->m_type) };
			auto _oop2 = _cb (_newval->m_params [i]);
			if (!_oop2.has_value ())
				return false;
			auto _oval = DoOper2 (_op1, "=", _oop2.value (), _newval->m_t);
			if (!_oval.has_value ())
				return false;
		}
		return true;
	}

	// 访问类成员变量
	std::optional<AstValue> AccessMember (AstValue& _cls_var, std::string _member, antlr4::Token *_t) {
		std::string _cls_name = _cls_var.GetType ();
		if (_cls_name [0] == '$')
			_cls_name = _cls_name.substr (1);
		auto _ocls = m_global_classes.GetClass (_cls_name, m_namespace);
		if (!_ocls.has_value ()) {
			LOG_ERROR (_t, std::format ("未定义的类 {}", _cls_name));
			return std::nullopt;
		}
		auto _cls = _ocls.value ();
		auto _oidx = _cls->GetVarIndex (_member);
		if (!_oidx.has_value ()) {
			LOG_ERROR (_t, std::format ("类 {} 中未定义变量成员 {}", _cls_name, _member));
			return std::nullopt;
		}
		size_t _idx = _oidx.value ();
		auto _val_raw = m_builder->CreateStructGEP (_cls_var.ValueRaw (), (unsigned int) _idx);
		return AstValue { (llvm::AllocaInst*) _val_raw, std::format ("${}", _cls->GetMember (_member).value ()->GetStringType ()) };
	}

	std::optional<AstValue> AccessArrayMember (AstValue& _arr_var, AstValue &_index, antlr4::Token* _t) {
		auto _val_raw = m_builder->CreateGEP (_arr_var.ValueRaw (), _index.Value (*m_builder));
		std::string _type = _arr_var.GetType ();
		return AstValue { (llvm::AllocaInst*) _val_raw, _type.substr (0, _type.size () - 2) };
	}

	bool Return (antlr4::Token* _t) {
		if (m_exp_type != "void") {
			LOG_ERROR (_t, std::format ("需返回 {} 类型值", m_exp_type));
			return false;
		}
		if (!m_virtual)
			m_builder->CreateRetVoid ();
		return true;
	}
	bool Return (AstValue &_op1, antlr4::Token* _t) {
		if (_op1.GetType () != m_exp_type) {
			LOG_ERROR (_t, std::format ("需返回 {} 类型值", m_exp_type));
			return false;
		}
		if (!m_virtual)
			m_builder->CreateRet (_op1.Value (*m_builder));
		return true;
	}
	std::string GetReturnType () { return m_exp_type; }
	std::optional<AstValue> DoOper1 (AstValue &_op1, std::string _op, antlr4::Token* _t) {
		if (!m_virtual) {
			return _op1.DoOper1 (*m_builder, m_value_builder, _op, _t);
		} else {
			return _op1;
		}
	}
	std::optional<AstValue> DoOper2 (AstValue &_op1, std::string _op, AstValue &_op2, antlr4::Token* _t) {
		// TODO 这儿判断是否virtual
		return _op1.DoOper2 (*m_builder, m_value_builder, _op, _op2, _t);
	}
	AstValue FuncInvoke (AstValue &_func, std::vector<AstValue> &_args) {
		if (!m_virtual) {
			std::vector<llvm::Value*> _sargs;
			for (auto _arg : _args)
				_sargs.push_back (_arg.Value (*m_builder));
			llvm::Value* _val = _func.FuncInvoke (*m_builder, _sargs);
			return AstValue { _val, _func.GetFuncReturnType () };
		} else {
			return AstValue { (llvm::Value* ) nullptr, _func.GetFuncReturnType () };
		}
	}

	bool IfElse (AstValue &_cond, std::function<bool ()> _true_ctx, std::function<bool ()> _false_ctx) {
		if (!m_virtual) {
			llvm::BasicBlock* _true_bb = llvm::BasicBlock::Create (*m_ctx, "", m_fp);
			llvm::BasicBlock* _false_bb = llvm::BasicBlock::Create (*m_ctx, "", m_fp);
			llvm::BasicBlock* _endif_bb = llvm::BasicBlock::Create (*m_ctx, "", m_fp);
			m_builder->CreateCondBr (_cond.Value (*m_builder), _true_bb, _false_bb);
			//
			m_builder->SetInsertPoint (_true_bb);
			m_local_vars.push_back (std::map<std::string, std::tuple<llvm::AllocaInst* , std::string>> {});
			if (!_true_ctx ())
				return false;
			m_local_vars.erase (m_local_vars.begin () + m_local_vars.size () - 1);
			m_builder->CreateBr (_endif_bb);
			//
			m_builder->SetInsertPoint (_false_bb);
			m_local_vars.push_back (std::map<std::string, std::tuple<llvm::AllocaInst* , std::string>> {});
			if (!_false_ctx ())
				return false;
			m_local_vars.erase (m_local_vars.begin () + m_local_vars.size () - 1);
			m_builder->CreateBr (_endif_bb);
			//
			m_builder->SetInsertPoint (_endif_bb);
			return true;
		} else {
			LOG_TODO (nullptr);
			return false;
		}
	}

	bool While (_AST_ExprOrValue& _ev_cond, std::function<bool ()> _body_ctx, std::function<std::optional<AstValue> (_AST_ExprOrValue)> _cb) {
		if (!m_virtual) {
			llvm::BasicBlock* _cond_bb = llvm::BasicBlock::Create (*m_ctx, "", m_fp);
			llvm::BasicBlock* _body_bb = llvm::BasicBlock::Create (*m_ctx, "", m_fp);
			llvm::BasicBlock* _endwhile_bb = llvm::BasicBlock::Create (*m_ctx, "", m_fp);
			m_builder->CreateBr (_cond_bb);
			//
			m_builder->SetInsertPoint (_cond_bb);
			auto _ocond = _cb (_ev_cond);
			if (!_ocond.has_value ())
				return false;
			m_builder->CreateCondBr (_ocond.value ().Value (*m_builder), _body_bb, _endwhile_bb);
			//
			m_builder->SetInsertPoint (_body_bb);
			m_local_vars.push_back (std::map<std::string, std::tuple<llvm::AllocaInst*, std::string>> {});
			if (!_body_ctx ())
				return false;
			m_local_vars.erase (m_local_vars.begin () + m_local_vars.size () - 1);
			m_builder->CreateBr (_cond_bb);
			//
			m_builder->SetInsertPoint (_endwhile_bb);
			return true;
		} else {
			LOG_TODO (nullptr);
			return false;
		}
	}

	std::optional<std::tuple<std::string, std::vector<std::string>>> GetFuncType (_AST_ExprOrValue &_val) {
		if (_val.m_val) {
			AstValue &_val2 = _val.m_val->m_val;
			if (_val2.IsFunction ())
				return _val2.GetFuncType ();
		} else if (_val.m_opN_expr) {
			auto _oftype = GetFuncType (_val.m_opN_expr->m_left);
			if (_oftype.has_value ()) {
				std::string _tmp_full = std::get<0> (_oftype.value ());
				// TODO: 提取方法结果 _tmp_full 的函数类型返回值
			}
		}
		return std::nullopt;
	}

	// 创建虚拟环境，这个虚拟环境可以无限制创建变量，调用代码不会生效，结束回调后放弃，可递归调用
	template<typename T>
	T CreateVirtualEnv (std::function<T ()> _cb) {
		bool _change_virtual = !m_virtual;
		m_virtual = true;
		m_local_vars.push_back (std::map<std::string, std::tuple<llvm::AllocaInst* , std::string>> {});
		T _ret = _cb ();
		m_local_vars.erase (m_local_vars.begin () + m_local_vars.size () - 1);
		if (_change_virtual)
			m_virtual = false;
		return _ret;
	}

private:
	AstClasses&																		m_global_classes;
	std::shared_ptr<llvm::LLVMContext>												m_ctx;
	std::shared_ptr<llvm::Module>													m_module;
	std::shared_ptr<TypeMap>														m_type_map;
	std::shared_ptr<ValueBuilder>													m_value_builder;
	std::shared_ptr<FuncType>														m_func;
	llvm::Function*																	m_fp = nullptr;
	std::string																		m_exp_type;
	std::string																		m_namespace;
	std::map<std::string, std::tuple<llvm::Value*, std::string>>					m_args;
	//
	std::shared_ptr<llvm::IRBuilder<>>												m_builder;
	std::vector<std::map<std::string, std::tuple<llvm::AllocaInst* , std::string>>>	m_local_vars;
	std::map<llvm::AllocaInst*, std::tuple<llvm::AllocaInst*, llvm::AllocaInst*>>	m_array_attaches;
	//
	bool m_virtual = false;
};



#endif //__FUNC_CONTEXT_HPP__

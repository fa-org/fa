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
#include "OperAST.hpp"
#include "FuncType.hpp"



class FuncContext {
public:
	FuncContext (std::shared_ptr<FuncTypes> _global_funcs, std::string _func_name): m_ctx (_global_funcs->m_ctx), m_module (_global_funcs->m_module), m_type_map (_global_funcs->m_type_map), m_value_builder (_global_funcs->m_value_builder), m_func (_global_funcs->GetFunc (_func_name)) {
		llvm::BasicBlock *_bb = llvm::BasicBlock::Create (*m_ctx, "", m_func->m_fp);
		m_builder = std::make_shared<llvm::IRBuilder<>> (_bb);
		m_builder->SetInsertPoint (_bb);
		////
		m_local_vars.reserve (32);
		m_local_vars.emplace_back (std::map<std::string, std::tuple<llvm::AllocaInst *, std::string>> {});
	}

	AstValue DefineVariable (std::string _type, antlr4::Token *_t, std::string _name = "") {
		std::string _var_type = std::format ("${}", _type);
		if (_name != "" && GetVariable (_name).IsValid ()) {
			LOG_ERROR (_t, std::format ("重复定义的变量：{}", _name));
			return std::nullopt;
		}
		std::optional<llvm::Type *> _ret_type = m_type_map->GetType (_type, _t);
		if (!_ret_type.has_value ())
			return std::nullopt;
		if (m_virtual)
			return AstValue { (llvm::AllocaInst *) nullptr, _var_type };

		auto _inst = m_builder->CreateAlloca (_ret_type.value ());
		if (_name != "")
			(*m_local_vars.rbegin ()) [_name] = { _inst, _var_type };
		return AstValue { _inst, _var_type };
	}
	AstValue DefineVariable (FaParser::TypeContext *_type, std::string _name = "") {
		return DefineVariable (_type->getText (), _type->start, _name);
	}
	AstValue GetVariable (std::string _name) {
		for (auto _i = m_local_vars.rbegin (); _i != m_local_vars.rend (); ++_i) {
			if (_i->contains (_name)) {
				auto &[_var, _type] = (*_i)[_name];
				return AstValue { _var, _type };
			}
		}
		return std::nullopt;
	}

	void Return () {
		if (!m_virtual)
			m_builder->CreateRetVoid ();
	}
	void Return (AstValue &_op1) {
		if (!m_virtual)
			m_builder->CreateRet (_op1.Value (*m_builder));
	}
	AstValue DoOper1 (AstValue &_op1, std::string _op, antlr4::Token *_t) {
		if (!m_virtual) {
			return _op1.DoOper1 (*m_builder, m_value_builder, _op, _t);
		} else {
			return _op1;
		}
	}
	AstValue DoOper2 (AstValue &_op1, std::string _op, AstValue &_op2, antlr4::Token *_t) {
		return _op1.DoOper2 (*m_builder, m_value_builder, _op, _op2, _t);
	}
	AstValue FuncInvoke (AstValue &_func, std::vector<AstValue> &_args) {
		if (!m_virtual) {
			std::vector<llvm::Value *> _sargs;
			for (auto _arg : _args)
				_sargs.push_back (_arg.Value (*m_builder));
			llvm::Value *_val = _func.FuncInvoke (*m_builder, _sargs);
			return AstValue { _val, _func.GetFuncReturnType () };
		} else {
			return AstValue { (llvm::Value *) nullptr, _func.GetFuncReturnType () };
		}
	}

	bool IfElse (AstValue &_cond, std::function<bool ()> _true_ctx, std::function<bool ()> _false_ctx) {
		if (!m_virtual) {
			llvm::BasicBlock *_true_bb = llvm::BasicBlock::Create (*m_ctx, "", m_func->m_fp);
			llvm::BasicBlock *_false_bb = llvm::BasicBlock::Create (*m_ctx, "", m_func->m_fp);
			llvm::BasicBlock *_endif_bb = llvm::BasicBlock::Create (*m_ctx, "", m_func->m_fp);
			m_builder->CreateCondBr (_cond.Value (*m_builder), _true_bb, _false_bb);
			//
			m_builder->SetInsertPoint (_true_bb);
			m_local_vars.push_back (std::map<std::string, std::tuple<llvm::AllocaInst *, std::string>> {});
			if (!_true_ctx ())
				return false;
			m_local_vars.erase (m_local_vars.begin () + m_local_vars.size () - 1);
			m_builder->CreateBr (_endif_bb);
			//
			m_builder->SetInsertPoint (_false_bb);
			m_local_vars.push_back (std::map<std::string, std::tuple<llvm::AllocaInst *, std::string>> {});
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

	std::optional<std::tuple<std::string, std::vector<std::string>>> GetFuncType (_AST_ExprOrValue &_val) {
		if (_val._val) {
			AstValue &_val2 = _val._val->_val;
			if (_val2.IsFunction ())
				return _val2.GetFuncType ();
		} else if (_val._opN_expr) {

		}
		return std::nullopt;
	}

	// 创建虚拟环境，这个虚拟环境可以无限制创建变量，调用代码不会生效，结束回调后放弃，可递归调用
	template<typename T>
	T CreateVirtualEnv (std::function<T ()> _cb) {
		bool _change_virtual = !m_virtual;
		m_virtual = true;
		m_local_vars.push_back (std::map<std::string, std::tuple<llvm::AllocaInst *, std::string>> {});
		T _ret = _cb ();
		m_local_vars.erase (m_local_vars.begin () + m_local_vars.size () - 1);
		if (_change_virtual)
			m_virtual = false;
		return _ret;
	}

private:
	std::shared_ptr<llvm::LLVMContext> m_ctx;
	std::shared_ptr<llvm::Module> m_module;
	std::shared_ptr<TypeMap> m_type_map;
	std::shared_ptr<ValueBuilder> m_value_builder;
	std::shared_ptr<FuncType> m_func;
	//
	std::shared_ptr<llvm::IRBuilder<>> m_builder;
	std::vector<std::map<std::string, std::tuple<llvm::AllocaInst *, std::string>>> m_local_vars;
	//
	bool m_virtual = false;
};



#endif //__FUNC_CONTEXT_HPP__

#ifndef __FUNC_CONTEXT_HPP__
#define __FUNC_CONTEXT_HPP__



#include <functional>
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <tuple>
#include <vector>

#include <antlr4-runtime/Token.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Function.h>
#include <fmt/core.h>

#include "TypeMap.hpp"
#include "AstValue.hpp"



class FuncContext {
public:
	FuncContext (std::shared_ptr<llvm::LLVMContext> _ctx, std::shared_ptr<llvm::Module> _module, std::shared_ptr<TypeMap> _type_map, std::shared_ptr<ValueBuilder> _value_builder): m_ctx (_ctx), m_module (_module), m_type_map (_type_map), m_value_builder (_value_builder) {}

	bool InitFunc (std::string _func_name, FaParser::TypeContext *_ret_type) {
		static std::vector<FaParser::TypeContext *> _arg_types;
		return InitFunc (_func_name, _ret_type, _arg_types);
	}
	bool InitFunc (std::string _func_name, FaParser::TypeContext *_ret_type, std::vector<FaParser::TypeContext *> &_arg_types) {
		std::optional<llvm::Type *> _oret_type = m_type_map->GetType (_ret_type);
		if (!_oret_type.has_value ())
			return false;
		//
		llvm::FunctionType *_ft = nullptr;
		if (_arg_types.size () == 0) {
			_ft = llvm::FunctionType::get (_oret_type.value (), false);
		} else {
			std::vector<llvm::Type *> _arg_stypes;
			for (auto _arg_type : _arg_types) {
				std::optional<llvm::Type *> _oarg_type = m_type_map->GetType (_arg_type);
				if (!_oarg_type.has_value ())
					return false;
				_arg_stypes.push_back (_oarg_type.value ());
			}
			_ft = llvm::FunctionType::get (_oret_type.value (), _arg_stypes, false);
		}
		m_f = llvm::Function::Create (_ft, llvm::Function::ExternalLinkage, _func_name, *m_module);
		m_f->setCallingConv (llvm::CallingConv::C);
		llvm::BasicBlock *_bb = llvm::BasicBlock::Create (*m_ctx, "", m_f);
		m_builder = std::make_shared<llvm::IRBuilder<>> (_bb);
		m_builder->SetInsertPoint (_bb);
		////
		m_local_vars.reserve (32);
		m_local_vars.emplace_back (std::map<std::string, std::tuple<llvm::AllocaInst *, std::string>> {});
		return true;
	}

	AstValue DefineVariable (std::string _type, antlr4::Token *_t, std::string _name = "") {
		if (_name != "" && GetVariable (_name).IsValid ()) {
			LOG_ERROR (_t, fmt::format ("重复定义的变量：{}", _name));
			return std::nullopt;
		}
		std::optional<llvm::Type *> _ret_type = m_type_map->GetType (_type, _t);
		if (!_ret_type.has_value ())
			return std::nullopt;
		auto _inst = m_builder->CreateAlloca (_ret_type.value ());
		(*m_local_vars.rbegin ()) [_name] = { _inst, _type };
		return AstValue { _inst, _type };
	}
	AstValue DefineVariable (FaParser::TypeContext *_type, std::string _name = "") {
		return DefineVariable (_type->getText (), _type->start, _name);
	}
	AstValue GetVariable (std::string _name) {
		for (size_t i = 0; i < m_local_vars.size (); ++i) {
			if (m_local_vars [i].contains (_name)) {
				auto &[_var, _type] = m_local_vars [i][_name];
				return AstValue { _var, _type };
			}
		}
		return std::nullopt;
	}

	void Return () { m_builder->CreateRetVoid (); }
	void Return (AstValue &_op1) { m_builder->CreateRet (_op1.Value (*m_builder)); }
	AstValue DoOper1 (AstValue &_op1, std::string _op, antlr4::Token *_t) { return _op1.DoOper1 (*m_builder, m_value_builder, _op, _t); }
	AstValue DoOper2 (AstValue &_op1, std::string _op, AstValue &_op2, antlr4::Token *_t) { return _op1.DoOper2 (*m_builder, m_value_builder, _op, _op2, _t); }
	AstValue FuncInvoke (AstValue &_func, std::vector<AstValue> &_args) {
		auto [_ret_type, _arg_types] = _func.GetFuncType ();
		// TODO: 检查类型
		std::vector<llvm::Value *> _sargs;
		for (auto _arg : _args)
			_sargs.push_back (_arg.Value (*m_builder));
		llvm::Value *_val = _func.FuncInvoke (*m_builder, _sargs);
		// TODO: 生成函数返回对象
		return std::nullopt;
	}

	bool IfElse (AstValue &_cond, std::function<bool ()> _true_ctx, std::function<bool ()> _false_ctx) {
		llvm::BasicBlock *_true_bb = llvm::BasicBlock::Create (*m_ctx, "", m_f);
		llvm::BasicBlock *_false_bb = llvm::BasicBlock::Create (*m_ctx, "", m_f);
		llvm::BasicBlock *_endif_bb = llvm::BasicBlock::Create (*m_ctx, "", m_f);
		m_builder->CreateCondBr (_cond.Value (*m_builder), _true_bb, _false_bb);
		//
		m_builder->SetInsertPoint (_true_bb);
		if (!_true_ctx ())
			return false;
		m_builder->CreateBr (_endif_bb);
		//
		m_builder->SetInsertPoint (_false_bb);
		if (!_false_ctx ())
			return false;
		m_builder->CreateBr (_endif_bb);
		//
		m_builder->SetInsertPoint (_endif_bb);
		return true;
	}

private:
	std::shared_ptr<llvm::LLVMContext> m_ctx;
	std::shared_ptr<llvm::Module> m_module;
	std::shared_ptr<TypeMap> m_type_map;
	std::shared_ptr<ValueBuilder> m_value_builder;
	//
	llvm::Function *m_f = nullptr;
	std::shared_ptr<llvm::IRBuilder<>> m_builder;
	std::vector<std::map<std::string, std::tuple<llvm::AllocaInst *, std::string>>> m_local_vars;
};



#endif //__FUNC_CONTEXT_HPP__

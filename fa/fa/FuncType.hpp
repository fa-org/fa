#ifndef __FUNC_TYPE_HPP__
#define __FUNC_TYPE_HPP__



#include <format>
#include <map>
#include <memory>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

#include <llvm/IR/CallingConv.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>

#include <FaParser.h>
#include "TypeMap.hpp"
#include "AstClass.hpp"



class TypeMap;
class ValueBuilder;

class FuncType {
public:
	std::string								m_name = "";
	std::string								m_class_name = "";
	std::string								m_ret_type = "";
	std::vector<std::string>				m_arg_types;
	std::string								m_type = "";
	llvm::FunctionType*						m_fp_type = nullptr;
};



class FuncTypes {
public:
	FuncTypes (std::shared_ptr<llvm::LLVMContext> _ctx, std::shared_ptr<TypeMap> _type_map, std::shared_ptr<llvm::Module> _module, std::shared_ptr<ValueBuilder> _value_builder, std::map<std::string, std::shared_ptr<FuncType>>& _global_funcs): m_ctx (_ctx), m_type_map (_type_map), m_module (_module), m_value_builder (_value_builder), m_funcs (_global_funcs) {}

	bool MakeExtern (std::string _func_name, FaParser::TypeContext* _ret_type_raw, std::vector<FaParser::TypeContext*>& _arg_type_raws, llvm::CallingConv::ID _cc);
	void RemakeExtern (std::string _func_name, llvm::CallingConv::ID _cc = llvm::CallingConv::C) {
		auto _func = m_funcs [_func_name];
		auto _fp = llvm::Function::Create (_func->m_fp_type, llvm::Function::ExternalLinkage, _func_name, *m_module);
		_fp->setCallingConv (_cc);
		m_func_ptrs [_func_name] = _fp;
	}

	bool Make (std::string _class_name, std::string _func_name, std::string _ret_type, antlr4::Token* _ret_type_t, std::vector<std::string>& _arg_types, std::vector<antlr4::Token*>& _arg_type_ts, llvm::CallingConv::ID _cc = llvm::CallingConv::C);
	bool Make (std::string _class_name, std::string _func_name, FaParser::TypeContext* _ret_type_raw, const std::vector<FaParser::TypeContext*> &_arg_type_raws, llvm::CallingConv::ID _cc = llvm::CallingConv::C) {
		std::vector<std::string> _arg_types;
		std::vector<antlr4::Token*> _arg_type_ts;
		for (auto _arg_type_raw : _arg_type_raws) {
			_arg_types.push_back (_arg_type_raw->getText ());
			_arg_type_ts.push_back (_arg_type_raw->start);
		}
		return Make (_class_name, _func_name, _ret_type_raw->getText (), _ret_type_raw->start, _arg_types, _arg_type_ts, _cc);
	}

	bool Contains (std::string _func_name) {
		return m_funcs.contains (_func_name);
	}

	std::optional<std::shared_ptr<FuncType>> GetFunc (std::string _func_name) { return m_funcs.contains (_func_name) ? (std::optional<std::shared_ptr<FuncType>>) m_funcs [_func_name] : std::nullopt; }
	llvm::Function* GetFuncPtr (std::string _func_name) {
		if (!m_func_ptrs.contains (_func_name))
			RemakeExtern (_func_name);
		return m_func_ptrs [_func_name];
	}

public:
	std::shared_ptr<llvm::LLVMContext>					m_ctx;
	std::shared_ptr<TypeMap>							m_type_map;
	std::shared_ptr<llvm::Module>						m_module;
	std::map<std::string, std::shared_ptr<FuncType>>&	m_funcs;
	std::map<std::string, llvm::Function*>				m_func_ptrs;
	std::shared_ptr<ValueBuilder>						m_value_builder;
};



#endif //__FUNC_TYPE_HPP__

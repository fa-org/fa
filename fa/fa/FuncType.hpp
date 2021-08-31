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



class FuncType {
public:
	std::string					m_name = "";
	std::string					m_object_name = "";
	std::string					m_ret_type = "";
	std::vector<std::string>	m_arg_types;
	std::string					m_type = "";
	llvm::FunctionType			*m_fp_type = nullptr;
	llvm::Function				*m_fp = nullptr;
};



class FuncTypes {
public:
	FuncTypes (std::shared_ptr<llvm::LLVMContext> _ctx, std::shared_ptr<TypeMap> _type_map, std::shared_ptr<llvm::Module> _module, std::shared_ptr<ValueBuilder> _value_builder): m_ctx (_ctx), m_type_map (_type_map), m_module (_module), m_value_builder (_value_builder) {}

	bool MakeExtern (std::string _func_name, FaParser::ETypeContext *_ret_type_raw, std::vector<FaParser::ETypeContext *> &_arg_type_raws, llvm::CallingConv::ID _cc) {
		auto _ret = std::make_shared<FuncType> ();
		_ret->m_name = _func_name;
		auto _otype = m_type_map->GetExternType (_ret_type_raw);
		if (!_otype.has_value ())
			return false;
		llvm::Type *_tmp_ret_type = nullptr;
		std::tie (_tmp_ret_type, _ret->m_ret_type) = _otype.value ();
		if (_arg_type_raws.size () == 0) {
			_ret->m_fp_type = llvm::FunctionType::get (_tmp_ret_type, false);
			_ret->m_type = std::format ("Func<{} ()>", _ret->m_ret_type);
		} else {
			auto _otypes = m_type_map->GetExternTypes (_arg_type_raws);
			if (!_otypes.has_value ())
				return false;
			std::vector<llvm::Type *> m_arg_types;
			std::tie (m_arg_types, _ret->m_arg_types) = _otypes.value ();
			_ret->m_fp_type = llvm::FunctionType::get (_tmp_ret_type, m_arg_types, false);
			std::stringstream _ss;
			_ss << "Func<" << _ret->m_ret_type << "(";
			for (size_t i = 0; i < m_arg_types.size (); ++i)
				_ss << (i > 0 ? ", " : "") << _ret->m_arg_types [i];
			_ss << ")>";
			_ret->m_type = _ss.str ();
		}
		_ret->m_fp = llvm::Function::Create (_ret->m_fp_type, llvm::Function::ExternalLinkage, _func_name.substr (2), *m_module);
		_ret->m_fp->setCallingConv (_cc);
		m_funcs [_func_name] = _ret;
		return true;
	}

	bool Make (std::string _func_name, bool _static, FaParser::TypeContext *_ret_type_raw, std::vector<FaParser::TypeContext *> &_arg_type_raws, llvm::CallingConv::ID _cc) {
		auto _ret = std::make_shared<FuncType> ();
		_ret->m_name = _func_name;
		if (!_static) {
			size_t _p = _func_name.rfind ("::");
			if (_p != std::string::npos && _p > 0)
				_ret->m_object_name = _func_name.substr (0, _p);
		}
		auto _otype = m_type_map->GetTypeT (_ret_type_raw);
		if (!_otype.has_value ())
			return false;
		llvm::Type *_tmp_ret_type = nullptr;
		std::tie (_ret->m_ret_type, _tmp_ret_type) = _otype.value ();
		if (_arg_type_raws.size () == 0) {
			_ret->m_fp_type = llvm::FunctionType::get (_tmp_ret_type, false);
			_ret->m_type = std::format ("Func<{} ()>", _ret->m_ret_type);
		} else {
			auto _otypes = m_type_map->GetTypesT (_arg_type_raws);
			if (!_otypes.has_value ())
				return false;
			std::vector<llvm::Type *> m_arg_types;
			std::tie (_ret->m_arg_types, m_arg_types) = _otypes.value ();
			_ret->m_fp_type = llvm::FunctionType::get (_tmp_ret_type, m_arg_types, false);
			std::stringstream _ss;
			_ss << "Func<" << _ret->m_ret_type << "(";
			for (size_t i = 0; i < m_arg_types.size (); ++i)
				_ss << (i > 0 ? ", " : "") << m_arg_types [i];
			_ss << ")>";
			_ret->m_type = _ss.str ();
		}
		_ret->m_fp = llvm::Function::Create (_ret->m_fp_type, llvm::Function::ExternalLinkage, _func_name, *m_module);
		_ret->m_fp->setCallingConv (_cc);
		m_funcs [_func_name] = _ret;
		return true;
	}

	bool Contains (std::string _name) {
		return m_funcs.contains (_name);
	}

	std::shared_ptr<FuncType> GetFunc (std::string _name) { return m_funcs [_name]; }

public:
	std::shared_ptr<llvm::LLVMContext>					m_ctx;
	std::shared_ptr<TypeMap>							m_type_map;
	std::shared_ptr<llvm::Module>						m_module;
	std::map<std::string, std::shared_ptr<FuncType>>	m_funcs;
	std::shared_ptr<ValueBuilder>						m_value_builder;
};



#endif //__FUNC_TYPE_HPP__

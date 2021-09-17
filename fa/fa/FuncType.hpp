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



class FuncType {
public:
	std::string					m_name = "";
	std::string					m_class_name = "";
	std::string					m_ret_type = "";
	std::vector<std::string>	m_arg_types;
	std::string					m_type = "";
	llvm::FunctionType*			m_fp_type = nullptr;
	llvm::Function*				m_fp = nullptr;
};



class FuncTypes {
public:
	FuncTypes (std::shared_ptr<llvm::LLVMContext> _ctx, std::shared_ptr<TypeMap> _type_map, std::shared_ptr<llvm::Module> _module, std::shared_ptr<ValueBuilder> _value_builder): m_ctx (_ctx), m_type_map (_type_map), m_module (_module), m_value_builder (_value_builder) {}

	bool MakeExtern (std::string _func_name, FaParser::TypeContext* _ret_type_raw, std::vector<FaParser::TypeContext*> &_arg_type_raws, llvm::CallingConv::ID _cc) {
		auto _ret = std::make_shared<FuncType> ();
		_ret->m_name = _func_name;
		auto _otype = m_type_map->GetTypeT (_ret_type_raw);
		if (!_otype.has_value ())
			return false;
		llvm::Type* _tmp_ret_type = nullptr;
		std::tie (_tmp_ret_type, _ret->m_ret_type) = _otype.value ();
		if (_arg_type_raws.size () == 0) {
			_ret->m_fp_type = llvm::FunctionType::get (_tmp_ret_type, false);
			_ret->m_type = std::format ("Func<{} ()>", _ret->m_ret_type);
		} else {
			auto _otypes = m_type_map->GetTypesT (_arg_type_raws);
			if (!_otypes.has_value ())
				return false;
			std::vector<llvm::Type*> m_arg_types;
			std::tie (m_arg_types, _ret->m_arg_types) = _otypes.value ();
			_ret->m_fp_type = llvm::FunctionType::get (_tmp_ret_type, m_arg_types, false);
			std::stringstream _ss;
			_ss << "Func<" << _ret->m_ret_type << "(";
			for (size_t i = 0; i < m_arg_types.size (); ++i)
				_ss << (i > 0 ? ", " : "") << _ret->m_arg_types [i];
			_ss << ")>";
			_ret->m_type = _ss.str ();
		}
		_ret->m_fp = llvm::Function::Create (_ret->m_fp_type, llvm::Function::ExternalLinkage, _func_name.substr (2),* m_module);
		_ret->m_fp->setCallingConv (_cc);
		m_funcs [_func_name] = _ret;
		return true;
	}

	bool Make (std::string _class_name, std::string &_func_name, std::string _ret_type, antlr4::Token* _ret_type_t, std::vector<std::string> &_arg_types, std::vector<antlr4::Token*> &_arg_type_ts, llvm::CallingConv::ID _cc = llvm::CallingConv::C) {
		auto _ret = std::make_shared<FuncType> ();
		_ret->m_name = _func_name = std::format ("{}{}{}", _class_name, _class_name == "" ? "" : ".", _func_name);
		_ret->m_class_name = _class_name;
		_ret->m_ret_type = _ret_type;
		auto _otype = m_type_map->GetType (_ret_type, _ret_type_t);
		if (!_otype.has_value ())
			return false;
		llvm::Type* _ret_type_ = _otype.value ();
		if (_arg_types.size () == 0) {
			_ret->m_fp_type = llvm::FunctionType::get (_ret_type_, false);
			_ret->m_type = std::format ("Func<{} ()>", _ret->m_ret_type);
		} else {
			std::vector<llvm::Type*> _arg_types_;
			for (size_t i = 0; i < _arg_types.size (); ++i) {
				_otype = m_type_map->GetType (_arg_types [i], _arg_type_ts [i]);
				if (!_otype.has_value ())
					return false;
				_arg_types_.push_back (_otype.value ());
			}
			_ret->m_fp_type = llvm::FunctionType::get (_ret_type_, _arg_types_, false);
			std::stringstream _ss;
			_ss << "Func<" << _ret->m_ret_type << "(";
			for (size_t i = 0; i < _arg_types_.size (); ++i)
				_ss << (i > 0 ? ", " : "") << _arg_types_ [i];
			_ss << ")>";
			_ret->m_type = _ss.str ();
		}
		_ret->m_fp = llvm::Function::Create (_ret->m_fp_type, llvm::Function::ExternalLinkage, _func_name,* m_module);
		_ret->m_fp->setCallingConv (_cc);
		m_funcs [_func_name] = _ret;
		return true;
	}
	bool Make (std::string _class_name, std::string &_func_name, FaParser::TypeContext* _ret_type_raw, const std::vector<FaParser::TypeContext*> &_arg_type_raws, llvm::CallingConv::ID _cc = llvm::CallingConv::C) {
		std::vector<std::string> _arg_types;
		std::vector<antlr4::Token*> _arg_type_ts;
		for (auto _arg_type_raw : _arg_type_raws) {
			_arg_types.push_back (_arg_type_raw->getText ());
			_arg_type_ts.push_back (_arg_type_raw->start);
		}
		return Make (_class_name, _func_name, _ret_type_raw->getText (), _ret_type_raw->start, _arg_types, _arg_type_ts, _cc);
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

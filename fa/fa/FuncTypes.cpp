#include <sstream>

#include "AstClass.h"
#include "FuncType.h"



FuncTypes::FuncTypes (std::shared_ptr<llvm::LLVMContext> _ctx, std::shared_ptr<TypeMap> _type_map, std::shared_ptr<llvm::Module> _module, std::shared_ptr<ValueBuilder> _value_builder, std::map<std::string, std::shared_ptr<FuncType>>& _global_funcs): m_ctx (_ctx), m_type_map (_type_map), m_module (_module), m_value_builder (_value_builder), m_funcs (_global_funcs) {}

bool FuncTypes::MakeExtern (std::string _func_name, FaParser::TypeContext* _ret_type_raw, std::vector<FaParser::TypeContext*>& _arg_type_raws, llvm::CallingConv::ID _cc) {
	auto _ret = std::make_shared<FuncType> ();
	_ret->m_name = _func_name;
	auto _otype = m_type_map->GetTypeT (_ret_type_raw);
	if (!_otype.has_value ())
		return false;
	llvm::Type* _tmp_ret_type = nullptr;
	std::tie (_tmp_ret_type, _ret->m_ret_type) = _otype.value ();
	llvm::FunctionType* _fp_type;
	if (_arg_type_raws.size () == 0) {
		_fp_type = llvm::FunctionType::get (_tmp_ret_type, false);
		_ret->m_type = std::format ("Func<{} ()>", _ret->m_ret_type);
	} else {
		auto _otypes = m_type_map->GetTypesT (_arg_type_raws);
		if (!_otypes.has_value ())
			return false;
		std::vector<llvm::Type*> m_arg_types;
		std::tie (m_arg_types, _ret->m_arg_types) = _otypes.value ();
		_fp_type = llvm::FunctionType::get (_tmp_ret_type, m_arg_types, false);
		std::stringstream _ss;
		_ss << "Func<" << _ret->m_ret_type << "(";
		for (size_t i = 0; i < m_arg_types.size (); ++i)
			_ss << (i > 0 ? ", " : "") << _ret->m_arg_types [i];
		_ss << ")>";
		_ret->m_type = _ss.str ();
	}
	auto _fp = llvm::Function::Create (_fp_type, llvm::Function::ExternalLinkage, _func_name.substr (2), *m_module);
	_fp->setCallingConv (_cc);
	m_func_ptrs [_func_name] = _fp;
	m_funcs [_func_name] = _ret;
	return true;
}

void FuncTypes::RemakeExtern (std::string _func_name, llvm::CallingConv::ID _cc) {
	auto _func = m_funcs [_func_name];
	llvm::FunctionType* _fp_type;
	llvm::Type* _ret_type_ = m_type_map->GetType (_func->m_ret_type, nullptr).value ();
	if (_func->m_arg_types.size () == 0) {
		_fp_type = llvm::FunctionType::get (_ret_type_, false);
	} else {
		std::vector<llvm::Type*> _arg_types_;
		for (size_t i = 0; i < _func->m_arg_types.size (); ++i) {
			_arg_types_.push_back (m_type_map->GetType (_func->m_arg_types [i], nullptr).value ());
		}
		_fp_type = llvm::FunctionType::get (_ret_type_, _arg_types_, false);
	}
	auto _fp = llvm::Function::Create (_fp_type, llvm::Function::ExternalLinkage, _func_name, *m_module);
	_fp->setCallingConv (_cc);
	m_func_ptrs [_func_name] = _fp;
}

bool FuncTypes::Make (std::string _class_name, std::string _func_name, std::string _ret_type, antlr4::Token* _ret_type_t, std::vector<std::string>& _arg_types, std::vector<antlr4::Token*>& _arg_type_ts, llvm::CallingConv::ID _cc) {
	auto _ret = std::make_shared<FuncType> ();
	_ret->m_name = _func_name;
	_ret->m_class_name = _class_name;
	_ret->m_ret_type = _ret_type;
	auto _otype = m_type_map->GetType (_ret_type, _ret_type_t);
	if (!_otype.has_value ())
		return false;
	llvm::Type* _ret_type_ = _otype.value ();
	llvm::FunctionType* _fp_type;
	if (_arg_types.size () == 0) {
		_fp_type = llvm::FunctionType::get (_ret_type_, false);
		_ret->m_type = std::format ("Func<{} ()>", _ret->m_ret_type);
	} else {
		std::vector<llvm::Type*> _arg_types_;
		for (size_t i = 0; i < _arg_types.size (); ++i) {
			std::string _arg_type = _arg_types [i];
			if (_arg_type.substr (_arg_type.size () - 2) == "[]") {
				_arg_types_.push_back (m_type_map->GetType ("int32", nullptr).value ());
				_arg_types_.push_back (m_type_map->GetType ("int32", nullptr).value ());
				_otype = m_type_map->GetType (_arg_type.substr (0, _arg_type.size () - 2), _arg_type_ts [i]);
				if (!_otype.has_value ())
					return false;
				_arg_types_.push_back (_otype.value ());
			} else {
				_otype = m_type_map->GetType (_arg_type, _arg_type_ts [i]);
				if (!_otype.has_value ())
					return false;
				_arg_types_.push_back (_otype.value ());
			}
		}
		_ret->m_arg_types = _arg_types;
		_fp_type = llvm::FunctionType::get (_ret_type_, _arg_types_, false);
		std::stringstream _ss;
		_ss << "Func<" << _ret->m_ret_type << "(";
		for (size_t i = 0; i < _arg_types.size (); ++i)
			_ss << (i > 0 ? ", " : "") << _arg_types [i];
		_ss << ")>";
		_ret->m_type = _ss.str ();
	}
	auto _fp = llvm::Function::Create (_fp_type, llvm::Function::ExternalLinkage, _func_name, *m_module);
	_fp->setCallingConv (_cc);
	m_func_ptrs [_func_name] = _fp;
	m_funcs [_func_name] = _ret;
	return true;
}

bool FuncTypes::Make (std::string _class_name, std::string _func_name, FaParser::TypeContext* _ret_type_raw, const std::vector<FaParser::TypeContext*>& _arg_type_raws, llvm::CallingConv::ID _cc) {
	std::vector<std::string> _arg_types;
	std::vector<antlr4::Token*> _arg_type_ts;
	for (auto _arg_type_raw : _arg_type_raws) {
		_arg_types.push_back (_arg_type_raw->getText ());
		_arg_type_ts.push_back (_arg_type_raw->start);
	}
	return Make (_class_name, _func_name, _ret_type_raw->getText (), _ret_type_raw->start, _arg_types, _arg_type_ts, _cc);
}

bool FuncTypes::Contains (std::string _func_name) {
	return m_funcs.contains (_func_name);
}

std::optional<std::shared_ptr<FuncType>> FuncTypes::GetFunc (std::string _func_name) {
	return m_funcs.contains (_func_name) ? (std::optional<std::shared_ptr<FuncType>>) m_funcs [_func_name] : std::nullopt;
}

llvm::Function* FuncTypes::GetFuncPtr (std::string _func_name) {
	if (!m_func_ptrs.contains (_func_name))
		RemakeExtern (_func_name);
	return m_func_ptrs [_func_name];
}

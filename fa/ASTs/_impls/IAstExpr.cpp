#include "pch.h"

#include "../Blocks/AstClass.hpp"
#include "../Exprs/BuildIns/AstBuildInExpr_Console.hpp"
#include "../Exprs/BuildIns/AstBuildInExpr_Dictionary.hpp"
#include "../Exprs/BuildIns/AstBuildInExpr_List.hpp"
#include "../Exprs/BuildIns/AstBuildInExpr_Object.hpp"
#include "../Exprs/BuildIns/AstBuildInExpr_Option.hpp"
#include "../Exprs/BuildIns/AstBuildInExpr_String.hpp"
#include "../Exprs/NameExprs/AstNameExpr_arg.hpp"
#include "../Exprs/NameExprs/AstNameExpr_class_func.hpp"
#include "../Exprs/NameExprs/AstNameExpr_class_var.hpp"
#include "../Exprs/NameExprs/AstNameExpr_enum_item.hpp"
#include "../Exprs/NameExprs/AstNameExpr_func.hpp"
#include "../Exprs/NameExprs/AstNameExpr_var.hpp"
#include "../Exprs/AstExpr_array1.hpp"
#include "../Exprs/AstExpr_array2.hpp"
#include "../Exprs/AstExpr_if.hpp"
#include "../Exprs/AstExpr_is.hpp"
#include "../Exprs/AstExpr_invoke.hpp"
#include "../Exprs/AstExpr_new.hpp"
#include "../Exprs/AstExpr_op1.hpp"
#include "../Exprs/AstExpr_op2.hpp"
#include "../Exprs/AstExpr_temp_name.hpp"
#include "../Exprs/AstExpr_type_wrap.hpp"
#include "../Exprs/AstExpr_value.hpp"
#include "../Exprs/IAstExpr.hpp"
#include "../Types/AstType_bool.hpp"
#include "../Types/AstType_float.hpp"
#include "../Types/AstType_int.hpp"
#include "../Types/AstType_temp_name.hpp"
#include "../Stmts/AstStmt_continue.hpp"
#include "../Stmts/AstStmt_define_var.hpp"
#include "../Stmts/AstStmt_expr_wrap.hpp"
#include "../Stmts/AstStmt_for1.hpp"
#include "../Stmts/AstStmt_if.hpp"
#include "../../common/CompileEnv.hpp"



std::optional<PAstType> IAstExpr::TryAsType () {
	if (auto _p = dynamic_cast<AstExpr_type_wrap *> (this))
		return _p->m_type;
	return std::nullopt;
}

std::optional<PAstExpr> IAstBuildInExpr::StaticInvoke (antlr4::Token *_token, Evaluation &_eval, std::string _class_name, std::string _func_name, std::vector<PAstType> _templates, std::vector<PAstExpr> _args) {
	static std::map<std::string, std::function<std::optional<PAstExpr> (antlr4::Token *_token, Evaluation &_eval, std::string _func_name, std::vector<PAstType> _templates, std::vector<PAstExpr> _args)>> s_static_funcs {
		{ "fa.Console",    AstBuildInExpr_Console::StaticInvoke },
		{ "fa.Dictionary", AstBuildInExpr_Dictionary::StaticInvoke },
		{ "fa.List",       AstBuildInExpr_List::StaticInvoke },
		{ "fa.Object",     AstBuildInExpr_Object::StaticInvoke },
		{ "fa.Option",     AstBuildInExpr_Option::StaticInvoke },
		{ "fa.String",     AstBuildInExpr_String::StaticInvoke },
	};
	return s_static_funcs [_class_name] (_token, _eval, _func_name, _templates, _args);
}

std::optional<PAstExpr> IAstBuildInExpr::CreateBuildInExpr (antlr4::Token *_token, std::string _name, std::vector<PAstType> _templates) {
	if (_name == "fa.Console") {
		return AstBuildInExpr_Console::Make (_token);
	} else if (_name == "fa.Dictionary") {
		return AstBuildInExpr_Dictionary::Make (_token, _templates [0], _templates [1]);
	} else if (_name == "fa.List") {
		return AstBuildInExpr_List::Make (_token, _templates [0]);
	} else if (_name == "fa.Object") {
		return AstBuildInExpr_Object::Make (_token);
	} else if (_name == "fa.Option") {
		return AstBuildInExpr_Option::Make (_token, _templates [0], std::nullopt);
	} else if (_name == "fa.String") {
		return AstBuildInExpr_String::Make (_token);
	} else {
		return std::nullopt;
	}
}



std::optional<PAstType> AstExpr_array1::GuessType () {
	if (m_var_types.size () == 0) {
		auto _oarr_type = m_arr_expr->GuessType ();
		if (!_oarr_type.has_value ())
			throw std::nullopt;
		auto _arr_type = dynamic_cast<AstType_class *> (_oarr_type.value ().get ());
		if (!_arr_type || _arr_type->m_class->m_full_name != "fa.List")
			throw std::nullopt;
		PAstType _item_type = _arr_type->m_template_types [0];
		if (m_var_unwrap) {
			auto _tuple_type = dynamic_cast<AstType_tuple_wrap *> (_item_type.get ());
			if (!_tuple_type)
				throw std::nullopt;
			if (_tuple_type->m_base_types.size () != m_var_names.size ())
				throw fa::Exception (m_token, "元组包含变量数量（{}）与实际变量数量（{}）不匹配", _tuple_type->m_base_types.size (), m_var_names.size ());
			m_var_types = _tuple_type->m_base_types;
		} else {
			m_var_types.push_back (_item_type);
		}
	}

	if (m_run_expr.has_value ())
		return AstType_void::Make (m_token);

	CompileEnv::CurrentFuncVariables.AddLevel ();
	for (size_t i = 0; i < m_var_names.size (); ++i)
		CompileEnv::CurrentFuncVariables.AddVariable (m_var_names [i], shared_from_this ());
	auto _select_type = m_select_expr.value ()->GuessType ();
	CompileEnv::CurrentFuncVariables.RemoveLevel ();
	if (!_select_type.has_value ())
		return std::nullopt;
	return AstType_temp_name::Make (m_token, "fa.List", { _select_type.value () });
}



PAstExpr AstExpr_array1::ProcessCodeType (std::optional<PAstType> _type) {
	m_arr_expr = m_arr_expr->ProcessCodeType (std::nullopt);
	m_real_type = GuessType ();
	if (!m_real_type.has_value ())
		throw fa::Exception (m_token, "无法识别数组的数据类型");

	throw fa::Exception (m_token, "not implement");
}



PAstExpr AstExpr_new::ProcessCodeType (std::optional<PAstType> _type) {
	if (_type.has_value ()) {
		if (m_real_type.has_value ()) {
			if (!m_real_type->IsSame (_type.value ())) {
				throw fa::Exception (m_token, "表达式无法转为指定类型");
			}
		} else {
			m_real_type = _type;
		}
	} else if (!m_real_type.has_value ()) {
		throw fa::Exception (m_token, "未知类型");
	}
	m_real_type = m_real_type.value ()->ProcessDeclareType ();
	auto _tclass = dynamic_cast<AstType_class *> (m_real_type.value ().get ());
	if (!_tclass)
		throw fa::Exception (m_token, "编译器内部类型错误");
	auto _class = _tclass->m_class;
	std::set<std::string> _necessary_vars;
	for (auto &[_var_name, _var] : _class->m_vars) {
		if (!_var->m_init_value.value ().get ())
			_necessary_vars.emplace (std::string (_var_name));
	}
	for (auto &[_var_name, _var_value] : m_init_values) {
		if (_necessary_vars.contains (_var_name))
			_necessary_vars.erase (_var_name);
		if (!_class->m_vars.contains (_var_name))
			throw fa::Exception (m_token, "类 {} 不存在成员变量 {}", _class->m_name, _var_name);
	}
	for (auto &[_var_name, _var_value] : m_init_values) {
		auto _var_type = _class->m_vars [_var_name]->m_type;
		_var_value = _var_value->ProcessCodeType (_var_type);
	}
	for (auto &[_var_name, _var] : _class->m_vars) {
		if (!m_init_values.contains (_var_name)) {
			auto _val = _var->m_init_value.value ()->ProcessCodeType (_var->m_type);
			m_init_values.emplace (_var_name, _val);
		}
	}
	return shared_from_this ();
}



AstNameExpr_argument::AstNameExpr_argument (antlr4::Token *_token, std::shared_ptr<AstClassFuncEmpty> _func, size_t _arg_index):
		IAstNameExpr (_token), m_func (_func), m_arg_index (_arg_index) {
	m_real_type = m_func->m_arg_types [m_arg_index];
}

std::optional<PAstExpr> AstNameExpr_argument::Evaluate (Evaluation &_eval) {
	return _eval.m_vars.Find (shared_from_this ()).value ();
}

std::string AstNameExpr_argument::GenCppCodeForArg (size_t _indent, std::string _func_name) {
	std::string _arg_name = m_func->m_arg_names [m_arg_index];
	if (m_func->m_arg_attrs [m_arg_index] == fa::ArgAttr::Disperse) {
		//auto _array_type = dynamic_cast<AstType_array_wrap *> (m_func->m_arg_types [m_arg_index].get ());
		if (_func_name == "std::vformat") {
			return std::format ("std::make_format_args ({}...)", _arg_name);
		} else {
			return std::format ("std::forward ({})...", _arg_name);
		}
	} else {
		return _arg_name;
	}
}

bool AstNameExpr_argument::IsSameVar (IAstNameExpr *_other) const {
	auto _other1 = dynamic_cast<typename decltype (this)> (_other);
	if (!_other1)
		return false;
	if (m_arg_index != _other1->m_arg_index)
		return false;
	return m_func->IsSameFunc (_other1->m_func.get ());
}

std::string AstNameExpr_argument::GetName () const { return m_func->m_arg_names [m_arg_index]; }



AstNameExpr_class_var::AstNameExpr_class_var (antlr4::Token *_token, std::optional<PAstExpr> _base, std::shared_ptr<AstClass> _class, std::vector<PAstType> _template_types, std::string _varname):
		IAstNameExpr (_token), m_base (_base), m_class (_class), m_template_types (_template_types), m_varname (_varname) {
	m_real_type = m_class->m_vars [_varname]->m_type;
}

bool AstNameExpr_class_var::IsSameVar (IAstNameExpr *_other) const {
	auto _other1 = dynamic_cast<typename decltype (this)> (_other);
	if (!_other1)
		return false;
	if (m_varname != _other1->m_varname)
		return false;
	return m_class->m_full_name == _other1->m_class->m_full_name;
}



AstNameExpr_class_func::AstNameExpr_class_func (antlr4::Token *_token, std::optional<PAstExpr> _base, std::shared_ptr<AstClassFuncEmpty> _func, std::vector<PAstType> _class_template_types, std::vector<PAstType> _func_template_types):
	IAstNameExpr (_token), m_base (_base), m_func (_func), m_class_template_types (_class_template_types), m_func_template_types (_func_template_types) {
	m_real_type = m_func->GetFuncType ();
}

bool AstNameExpr_class_func::IsSameVar (IAstNameExpr *_other) const {
	auto _other1 = dynamic_cast<typename decltype (this)> (_other);
	if (!_other1)
		return false;
	return m_func->IsSameFunc (_other1->m_func.get ());
}

std::string AstNameExpr_class_func::GetName () const { return m_func->m_name; }



bool AstNameExpr_enumitem::IsSameVar (IAstNameExpr *_other) const {
	auto _other1 = dynamic_cast<typename decltype (this)> (_other);
	if (!_other1)
		return false;
	if (m_index != _other1->m_index)
		return false;
	return m_enum->m_full_name == _other1->m_enum->m_full_name;
}

std::string AstNameExpr_enumitem::GetName () const { return m_enum->m_enum_items [m_index]->m_name; }

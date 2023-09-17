#include "pch.h"

#include <map>
#include <set>
#include <string>

#include "../Blocks/AstClass.hpp"
#include "../Blocks/AstAnnoPart.hpp"
#include "../Blocks/AstProgram.hpp"
#include "../Blocks/AstClassFuncEmpty.hpp"
#include "../Types/AstType_class.hpp"
#include "../Types/AstType_class_template_item.hpp"
#include "../Types/AstType_func_template.hpp"
#include "../../common/Evaluation.hpp"



void AstAnnoPart::ProcessDeclareType () {
	if (auto _p = CompileEnv::AstProgram->m_classes.find (m_tmp_name); _p != CompileEnv::AstProgram->m_classes.end ()) {
		m_parent = _p->second;
	} else {
		throw fa::Exception (m_token, "cannot find annotation: {}", m_tmp_name);
	}
	for (auto &[_var_name, _var] : m_var_values) {
		if (!m_parent->m_vars.contains (_var_name))
			throw fa::Exception (m_token, "Signal [{}] is not a field of Annotation structures.", _var_name);
		m_parent->m_vars.at (_var_name)->ProcessDeclareType ();
	}
	for (auto &[_var_name, _var] : m_parent->m_vars) {
		if ((!_var->m_init_value) && (!m_var_values.contains (_var_name)))
			throw fa::Exception (m_token, "Must special field value [{}].", _var_name);
	}
}

void AstAnnoPart::ProcessCodeType () {
	for (auto &[_var_name, _var] : m_var_values) {
		_var = Evaluation::Expr (_var->ProcessCodeType (m_parent->m_vars.at (_var_name)->m_type)).value ();
	}
}

PAstExpr AstAnnoPart::GetValue (std::string _name) {
	if (m_var_values.contains (_name))
		return m_var_values.at (_name);
	return m_parent->m_vars.at (_name)->m_init_value.value ();
}

PAstAnnoPart AstAnnoPart::Clone () {
	auto _new_anno_part = std::make_shared<AstAnnoPart> (m_token);
	_new_anno_part->m_tmp_name = m_tmp_name;
	_new_anno_part->m_parent = m_parent;
	for (auto &[_anno_var_name, _var_value] : m_var_values) {
		_new_anno_part->m_var_values.emplace (_anno_var_name, _var_value->ProcessCodeType (_new_anno_part->m_parent->m_vars.at (_anno_var_name)->m_type));
	}
	return _new_anno_part;
}



void AstClass::SetMembers (fa::ParseType _type, std::vector<AstObj *> _values) {
	if (_type == fa::ParseType::AnnoPart) {
		for (auto _value : _values)
			m_anno_parts.push_back (std::shared_ptr<AstAnnoPart> (dynamic_cast<AstAnnoPart *> (_value)));
	} else if (_type == fa::ParseType::EnumItem) {
		for (auto _value : _values)
			m_enum_items.push_back (std::shared_ptr<AstEnumItem> (dynamic_cast<AstEnumItem *> (_value)));
	} else if (_type == fa::ParseType::ClassVar) {
		for (auto _value : _values) {
			auto _var = std::shared_ptr<AstClassVar> (dynamic_cast<AstClassVar *> (_value));
			m_vars.emplace (_var->m_name, _var);
		}
	} else if (_type == fa::ParseType::ClassFunc) {
		for (auto _value : _values) {
			auto _func = std::shared_ptr<AstClassFuncEmpty> (dynamic_cast<AstClassFuncEmpty *> (_value));
			m_funcs.emplace (_func->m_name, _func);
		}
	} else {
		throw fa::Exception (m_token, "not implement");
	}
}

void AstClass::SetValues (fa::ParseValueType _type, std::vector<fa::ParseValue_t> _values) {
	if (_type == fa::ParseValueType::PublicLevel) {
		m_level = std::get<fa::PublicLevel> (_values [0]);
	} else if (_type == fa::ParseValueType::Name) {
		m_name = std::get<std::string> (_values [0]);
	} else if (_type == fa::ParseValueType::FullName) {
		m_full_name = std::get<std::string> (_values [0]);
	} else if (_type == fa::ParseValueType::Templates) {
		for (auto _value : _values) {
			m_tpl_names.push_back (std::get<std::string> (_value));
		}
	} else {
		throw fa::Exception (m_token, "not implement");
	}
}

void AstClass::ProcessDeclareType () {
	if (IsTemplateClass ()) {
		for (auto &[_inst_type_name, _inst] : m_tpl_insts) {
			_inst->ProcessDeclareType ();
		}
	} else {
		if (m_processed_declare)
			return;
		CompileEnv::CurrentClass = shared_from_this ();
		CompileEnv::CurrentFunc = nullptr;
		for (auto &_anno_part : m_anno_parts)
			_anno_part->ProcessDeclareType ();
		for (auto &_item : m_enum_items)
			_item->ProcessDeclareType ();
		for (auto &[_var_name, _var] : m_vars)
			_var->ProcessDeclareType ();
		for (auto &[_func_name, _func] : m_funcs)
			_func->ProcessDeclareType ();
		m_processed_declare = true;
	}
}

void AstClass::ProcessCodeType () {
	if (IsTemplateClass ()) {
		for (auto &[_inst_type_name, _inst] : m_tpl_insts) {
			_inst->ProcessCodeType ();
		}
	} else {
		if (m_processed_code)
			return;
		CompileEnv::CurrentClass = shared_from_this ();
		CompileEnv::CurrentFunc = nullptr;
		for (auto &_anno_part : m_anno_parts)
			_anno_part->ProcessCodeType ();
		for (auto &_item : m_enum_items)
			_item->ProcessCodeType ();
		for (auto &[_var_name, _var] : m_vars)
			_var->ProcessCodeType ();
		for (auto &[_func_name, _func] : m_funcs)
			_func->ProcessCodeType ();
		m_processed_code = true;
	}
}

PAstType AstClass::GetType () {
	return AstType_class::Make (m_token, shared_from_this (), {});
}

std::shared_ptr<AstClass> AstClass::GetInst (std::vector<PAstType> _tpl_inst_types) {
	if (_tpl_inst_types.size () == 0) {
		throw fa::Exception (m_token, "not implement");
	}
	if (m_tpl_inst_types.size () != 0) {
		throw fa::Exception (m_token, "not implement");
	}
	if (_tpl_inst_types.size () != m_tpl_names.size ()) {
		throw fa::Exception (m_token, "not implement");
	}
	auto _new_class = std::make_shared<AstClass> (m_token, m_class_type);
	_new_class->m_anno_parts = m_anno_parts;
	_new_class->m_level = m_level;
	_new_class->m_class_type = m_class_type;
	_new_class->m_full_name = m_full_name;
	_new_class->m_name = m_name;
	_new_class->m_enum_items = m_enum_items;
	for (auto [_var_name, _var] : m_vars) {
		_new_class->m_vars.insert (std::make_pair (_var_name, _var->Clone (_new_class)));
	}
	for (auto [_func_name, _func] : m_funcs) {
		_new_class->m_funcs.insert (std::make_pair (_func_name, _func->Clone (_new_class)));
	}
	_new_class->m_processed_declare = m_processed_declare;
	_new_class->m_processed_code = m_processed_code;
	_new_class->m_tpl_names = m_tpl_names;
	_new_class->m_tpl_inst_types = _tpl_inst_types;
	for (size_t i = 0; i < _tpl_inst_types.size (); ++i)
		_tpl_inst_types [i] = _tpl_inst_types [i]->ProcessDeclareType ();
	std::string _type_name = StrUtils::GetName (_tpl_inst_types);
	m_tpl_insts.insert (std::make_pair (_type_name, _new_class));
	return _new_class;
}



template<>
_AstClassVar<AstAnnoPart>::_AstClassVar (antlr4::Token *_token):
	IAstBlock (_token), m_level (fa::PublicLevel::Public), m_type (std::nullopt), m_init_value (std::nullopt) {}

template<>
void _AstClassVar<AstAnnoPart>::SetMembers (fa::ParseType _type, std::vector<AstObj *> _values) {
	if (_type == fa::ParseType::Part_Type) {
		m_type = std::shared_ptr<IAstType> (dynamic_cast<IAstType *> (_values [0]));
	} else if (_type == fa::ParseType::Part_Parent) {
		m_parent = dynamic_cast<AstClass *> (_values [0]);
	} else if (_type == fa::ParseType::AnnoPart) {
		for (auto _value : _values)
			m_anno_parts.push_back (std::shared_ptr<AstAnnoPart> (dynamic_cast<AstAnnoPart *> (_value)));
	} else if (_type == fa::ParseType::Part_Func) {
		for (auto _value : _values) {
			auto _func = dynamic_cast<AstClassFuncEmpty *> (_value);
			bool _is_get = _func->m_name == "get";
			if (_is_get) {
				_func->m_ret_type = m_type.value ();
				//if (_func->m_contents.size () == 0)
				//	_func->m_contents.push_back ();
				//TODO
			} else {
				_func->m_ret_type = AstType_void::Make (m_type.value ()->m_token);
				_func->m_arg_attrs.push_back (fa::ArgAttr::None);
				_func->m_arg_types.push_back (m_type.value ());
				_func->m_arg_names.push_back ("value");
				//if (_func->m_contents.size () == 0)
				//	_func->m_contents.push_back ();
				//TODO
			}
		}
	} else {
		throw fa::Exception (m_token, "not implement");
	}
}

template<>
std::shared_ptr<_AstClassVar<AstAnnoPart>> _AstClassVar<AstAnnoPart>::Clone (std::shared_ptr<AstClass> _cls) {
	auto _new_var = std::make_shared<_AstClassVar<AstAnnoPart>> (m_token);
	_new_var->m_parent = _cls.get ();
	for (auto &_old_anno_part : m_anno_parts)
		_new_var->m_anno_parts.push_back (_old_anno_part->Clone ());
	_new_var->m_level = m_level;
	_new_var->m_static = m_static;
	_new_var->m_name = m_name;
	_new_var->m_type = m_type.has_value () ? m_type.value ()->ProcessDeclareType () : m_init_value.value ()->GuessType ();
	for (auto &[_func_name, _old_func] : m_funcs) {
		_new_var->m_funcs.emplace (_func_name, _old_func->Clone (_cls));
	}
	_new_var->m_init_value = m_init_value.has_value () ? (std::optional<PAstExpr>) m_init_value.value ()->ProcessCodeType (_new_var->m_type) : std::nullopt;
	return _new_var;
}

void AstClassFuncEmpty::SetMembers (fa::ParseType _type, std::vector<AstObj *> _values) {
	if (_type == fa::ParseType::Part_ReturnType) {
		m_ret_type = std::shared_ptr<IAstType> (dynamic_cast<IAstType *> (_values [0]));
	} else if (_type == fa::ParseType::Part_Parent) {
		m_parent = dynamic_cast<AstClass *> (_values [0]);
	} else if (_type == fa::ParseType::AnnoPart) {
		for (auto _value : _values)
			m_anno_parts.push_back (std::shared_ptr<AstAnnoPart> (dynamic_cast<AstAnnoPart *> (_value)));
	} else if (_type == fa::ParseType::Part_ArgType) {
		for (auto _value : _values)
			m_arg_types.push_back (std::shared_ptr<IAstType> (dynamic_cast<IAstType *> (_value)));
	} else {
		throw fa::Exception (m_token, "not implement");
	}
}

void AstClassFuncEmpty::ProcessDeclareType () {
	CompileEnv::CurrentClass = m_parent->shared_from_this ();
	CompileEnv::CurrentFunc = shared_from_this ();
	m_ret_type = m_ret_type->ProcessDeclareType ();
	for (auto &_anno_part : m_anno_parts)
		_anno_part->ProcessDeclareType ();
	for (auto &_arg_types : m_arg_types)
		_arg_types = _arg_types->ProcessDeclareType ();
}

void AstClassFuncEmpty::ProcessCodeType () {
	if (m_processed_code)
		return;
	CompileEnv::CurrentClass = m_parent->shared_from_this ();
	CompileEnv::CurrentFunc = shared_from_this ();
	for (auto &_anno_part : m_anno_parts)
		_anno_part->ProcessCodeType ();
	m_processed_code = true;
	for (auto &[_type_name, _template_inst] : m_tpl_insts) {
		_template_inst.m_func = ProcessInstanceCodeType (_type_name, _template_inst.m_template_types);
	}
}

void AstClassFuncEmpty::do_Clone (AstClassFuncEmpty *_new_func, std::shared_ptr<AstClass> _cls) {
	_new_func->m_parent = _cls.get ();
	for (auto &_old_anno_part : m_anno_parts)
		_new_func->m_anno_parts.push_back (_old_anno_part->Clone ());
	_new_func->m_level = m_level;
	_new_func->m_static = m_static;
	_new_func->m_name = m_name;
	_new_func->m_tpl_names.assign (m_tpl_names.begin (), m_tpl_names.end ());
	_new_func->m_ret_type = m_ret_type->ProcessDeclareType ();
	_new_func->m_arg_attrs.assign (m_arg_attrs.begin (), m_arg_attrs.end ());
	for (auto &_arg_type : m_arg_types)
		_new_func->m_arg_types.push_back (_arg_type->ProcessDeclareType ());
	_new_func->m_arg_names.assign (m_arg_names.begin (), m_arg_names.end ());
	_new_func->m_processed_code = true;
}

bool AstClassFuncEmpty::IsSameFunc (const AstClassFuncEmpty *_other) const {
	if (m_name != _other->m_name)
		return false;
	if (m_parent && _other->m_parent) {
		return m_parent->m_full_name == _other->m_parent->m_full_name;
	} else {
		return (!m_parent) && (!_other->m_parent);
	}
}

std::shared_ptr<AstClassFuncEmpty> AstClassFuncEmpty::GetInst (std::vector<PAstType> _tpl_inst_types) {
	if (_tpl_inst_types.size () == 0) {
		throw fa::Exception (m_token, "not implement");
	}
	if (m_tpl_inst_types.size () != 0) {
		throw fa::Exception (m_token, "not implement");
	}
	if (_tpl_inst_types.size () != m_tpl_names.size ()) {
		throw fa::Exception (m_token, "not implement");
	}
	auto _new_func = std::make_shared<AstClassFuncEmpty> (m_token);
	_new_func->m_parent = m_parent;
	_new_func->m_anno_parts = m_anno_parts;
	_new_func->m_level = m_level;
	_new_func->m_static = m_static;
	_new_func->m_name = m_name;
	_new_func->m_tpl_names = m_tpl_names;
	_new_func->m_ret_type = m_ret_type;
	_new_func->m_arg_attrs = m_arg_attrs;
	_new_func->m_arg_types = m_arg_types;
	_new_func->m_arg_names = m_arg_names;
	_new_func->m_tpl_names = m_tpl_names;
	_new_func->m_tpl_inst_types = _tpl_inst_types;
	for (size_t i = 0; i < _tpl_inst_types.size (); ++i)
		_tpl_inst_types [i] = _tpl_inst_types [i]->ProcessDeclareType ();
	std::string _type_name = StrUtils::GetName (_tpl_inst_types);
	m_tpl_insts.insert (std::make_pair (_type_name, _new_func));
	return _new_func;
}

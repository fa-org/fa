#include "pch.h"

#include <format>
#include <functional>
#include <map>
#include <set>

#include "../Blocks/AstClass.hpp"
#include "../Blocks/AstProgram.hpp"
#include "../Exprs/AstExpr_type_wrap.hpp"
#include "../Exprs/NameExprs/AstNameExpr_arg.hpp"
#include "../Exprs/NameExprs/AstNameExpr_class_var.hpp"
#include "../Exprs/NameExprs/AstNameExpr_class_func.hpp"
#include "../Types/IAstType.hpp"
#include "../Types/AstType_any.hpp"
#include "../Types/AstType_bool.hpp"
#include "../Types/AstType_class.hpp"
#include "../Types/AstType_class.hpp"
#include "../Types/AstType_float.hpp"
#include "../Types/AstType_int.hpp"
#include "../Types/AstType_temp_item.hpp"
#include "../Types/AstType_temp_name.hpp"
#include "../Types/AstType_tuple_wrap.hpp"
#include "../Types/AstType_unsure_wrap.hpp"
#include "../Types/AstType_void.hpp"
#include "../../common/CompileEnv.hpp"
#include "../../common/Evaluation.hpp"



bool PAstType::IsSame (PAstType &_other) {
	auto _this = (*this)->ProcessDeclareType ();
	_other = _other->ProcessDeclareType ();
	if (_this->GetTypeName () == _other->GetTypeName ())
		return true;
	if (auto _other_unsure = dynamic_cast<AstType_unsure_wrap *> (_other.get ())) {
		for (auto _other_item : _other_unsure->m_base_types) {
			if (IsSame (_other_item))
				return true;
		}
	}
	return false;
}



PAstType AstType_temp_name::ProcessDeclareType () {
	auto _oval = CompileEnv::FindName (m_token, m_name, m_templates);
	if (!_oval.has_value ())
		throw fa::Exception (m_token, "not implement");
	if (auto _expr_type = dynamic_cast<AstExpr_type_wrap *> (_oval.value ().get ())) {
		auto _type =_expr_type->m_type;
		if (m_templates.size () > 0) {
			if (auto _class_type = dynamic_cast<AstType_class *> (_type.get ())) {
				_type = AstType_class::Make (m_token, _class_type->m_class, m_templates);
			}
		}
		return _type;
	}
	throw fa::Exception (m_token, "not implement");
}

std::string AstType_class::GetTypeName () {
	if (m_template_types.size () == 0)
		return m_class->m_full_name;
	std::stringstream _ss;
	_ss << m_class->m_full_name << "<";
	for (size_t i = 0; i < m_template_types.size (); ++i) {
		if (i > 0)
			_ss << ", ";
		_ss << m_template_types [i]->GetTypeName ();
	}
	_ss << ">";
	return _ss.str ();
}

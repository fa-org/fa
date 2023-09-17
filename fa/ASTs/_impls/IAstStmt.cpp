#include "pch.h"

#include "../Exprs/NameExprs/AstNameExpr_var.hpp"
#include "../Exprs/BuildIns/AstBuildInExpr_List.hpp"
#include "../Stmts/IAstStmt.hpp"
#include "../Stmts/AstStmt_break.hpp"
#include "../Stmts/AstStmt_continue.hpp"
#include "../Stmts/AstStmt_define_var.hpp"
#include "../Stmts/AstStmt_expr_wrap.hpp"
#include "../Stmts/AstStmt_for1.hpp"
#include "../Stmts/AstStmt_if.hpp"
#include "../Stmts/AstStmt_return.hpp"
#include "../Blocks/AstClassFunc.hpp"
#include "../../common/Evaluation.hpp"
#include "../../common/CompileEnv.hpp"



PAstStmt AstStmt_for1::ProcessCodeType () {
	m_arr_expr = m_arr_expr->ProcessCodeType (std::nullopt);
	auto _arr_type = dynamic_cast<AstType_class *> (m_arr_expr->m_real_type.value ().get ());
	if (!_arr_type)
		throw fa::Exception (m_token, "not implement");
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
	//
	CompileEnv::CurrentFuncVariables.AddLevel ();
	for (size_t i = 0; i < m_var_names.size (); ++i)
		CompileEnv::CurrentFuncVariables.AddVariable (m_var_names [i], AstNameExpr_var::Make (m_token, m_var_names [i], shared_from_this ()));
	for (auto &_item : m_body) {
		_item = _item->ProcessCodeType ();
	}
	CompileEnv::CurrentFuncVariables.RemoveLevel ();
	return shared_from_this ();
}

void AstStmt_for1::Evaluate (Evaluation &_eval) {
	if (AstType_class *arr_type = dynamic_cast<AstType_class *> (m_arr_expr->m_real_type.value ().get ())) {
		if (!(m_var_types.size () == 1 && arr_type->m_template_types [0].IsSame (m_var_types [0])))
			throw fa::Exception (m_token, "not implement");
		if (AstBuildInExpr_List *arr_expr = dynamic_cast<AstBuildInExpr_List *> (m_arr_expr.get ()))
		for (size_t i = 0; i < arr_expr->m_values.size (); ++i) {
			_eval.m_vars.AddLevel ();
			_eval.m_vars.Add (AstNameExpr_var::Make (m_token, m_var_names [0], shared_from_this ()), AstExpr_value::Make (m_token, arr_expr->m_values [i]));
			for (size_t i = 0; i < m_body.size (); ++i)
				m_body [i]->Evaluate (_eval);
			_eval.m_vars.RemoveLevel ();
		}
	} else {
		throw fa::Exception (m_token, "not implement");
	}
}



PAstStmt AstStmt_define_var::ProcessCodeType () {
	m_type = m_type.value ()->ProcessDeclareType ();
	if (m_expr.has_value ()) {
		m_expr = m_expr.value ()->ProcessCodeType (m_type);
		if (!m_type.has_value ())
			m_type = m_expr.value ()->m_real_type;
	} else {
		if (!m_type.has_value ())
			throw fa::Exception (m_token, "无法计算变量类型");
	}
	CompileEnv::CurrentFuncVariables.AddVariable (m_name, AstNameExpr_var::Make (m_token, m_name, shared_from_this ()));
	return shared_from_this ();
}

void AstStmt_define_var::Evaluate (Evaluation &_eval) {
	auto _var = AstNameExpr_var::Make (m_token, m_name, shared_from_this ());
	if (_eval.m_vars.Find (_var).has_value ())
		throw fa::Exception (m_token, "redefined symbol {}", m_name);
	if (m_type.has_value ())
		_eval.m_vars.Add (_var, m_expr.value ()->Evaluate (_eval).value ());
}

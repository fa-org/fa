#include "AstExprOrValue.h"



_AST_ValueCtx::_AST_ValueCtx (AstValue _val, antlr4::Token* _t, std::string _expect_type): m_val (_val), m_t (_t), m_expect_type (_expect_type) {}



_AST_Arr1ValueCtx::_AST_Arr1ValueCtx (std::vector<_AST_ExprOrValue> _vals, std::string _str_capacity, antlr4::Token* _t, std::string _expect_type) : m_vals (_vals), m_str_capacity (_str_capacity), m_t (_t), m_expect_type (_expect_type) {}



_AST_Arr2ValueCtx::_AST_Arr2ValueCtx (std::vector<_AST_ExprOrValue> _vals, std::string _str_capacity, antlr4::Token* _t, std::string _expect_type) : m_vals (_vals), m_str_capacity (_str_capacity), m_t (_t), m_expect_type (_expect_type) {}



_AST_NewCtx::_AST_NewCtx (antlr4::Token* _t, IAstClass* _cls, std::string _expect_type) : m_t (_t), m_cls (_cls), m_expect_type (_expect_type) {
	m_cls->GetVars ([&] (AstClassVar* _cls_var) {
		if (!_cls_var->m_is_static)
			m_init_params.push_back (std::nullopt);
		return CallbackFunc::Continue;
	});
}

// 设置初始化参数
bool _AST_NewCtx::SetInitVar (std::string _name, _AST_ExprOrValue _param, antlr4::Token* _t) {
	bool _no_repeat = true;
	bool _success = false;
	m_cls->GetVars ([&] (AstClassVar* _cls_var) {
		if (_cls_var->m_is_static)
			return CallbackFunc::Continue;
		if (_cls_var->m_name != _name)
			return CallbackFunc::Continue;
		if (m_init_params [_cls_var->m_ast_pos].has_value ()) {
			_no_repeat = false;
		} else {
			m_init_params [_cls_var->m_ast_pos] = _param;
			_success = true;
		}
		return CallbackFunc::Break;
	});
	if (!_no_repeat) {
		LOG_ERROR (_t, std::format ("成员变量 {} 重复赋值", _name));
		return false;
	}
	if (!_success) {
		LOG_ERROR (_t, std::format ("未识别的成员变量 {}", _name));
		return false;
	}
	return true;
}

// 检查是否所有参数已初始化
bool _AST_NewCtx::CheckVarsAllInit (antlr4::Token* _t, std::function<std::optional<_AST_ExprOrValue> (FaParser::ExprContext*, std::string)> _cb) {
	bool _success = true;
	m_cls->GetVars ([&] (AstClassVar* _cls_var) {
		if (_cls_var->m_is_static)
			return CallbackFunc::Continue;
		if (!m_init_params [_cls_var->m_ast_pos].has_value ()) {
			auto _oval = _cb (_cls_var->m_init_value, _cls_var->m_type);
			if (!_oval.has_value ()) {
				_success = false;
				return CallbackFunc::Break;
			}
			m_init_params [_cls_var->m_ast_pos] = _oval.value ();
		}
		return CallbackFunc::Continue;
	});
	if (!_success)
		return false;
	for (size_t i = 0; i < m_init_params.size (); ++i) {
		if (m_init_params [i].has_value ())
			continue;
		std::optional<AstClassVar*> _ovar = std::nullopt;
		m_cls->GetVars ([&] (AstClassVar* _cls_var) {
			if (_cls_var->m_ast_pos != i)
				return CallbackFunc::Continue;
			_ovar = _cls_var;
			return CallbackFunc::Break;
		});
		LOG_ERROR (_t, std::format ("成员变量 {} 未指定初始化值", _ovar.value ()->m_name));
		return false;
	}
	return true;
}



_AST_NewArrayCtx::_AST_NewArrayCtx (std::string _item_type, antlr4::Token* _t): m_item_type (_item_type), m_expect_type (std::format ("{}[]", _item_type)), m_t (_t) {}

void _AST_NewArrayCtx::SetSize (std::shared_ptr<_AST_ExprOrValue> _eov) {
	m_size = _eov;
}



_AST_Oper1Ctx::_AST_Oper1Ctx (): m_type (_Op1Type::None) {}

_AST_Oper1Ctx::_AST_Oper1Ctx (FaParser::StrongExprPrefixContext* _op_raw) : m_op (_op_raw->getText ()), m_t (_op_raw->start) {}

_AST_Oper1Ctx::_AST_Oper1Ctx (FaParser::StrongExprSuffixContext* _op_raw) : m_op (_op_raw->getText ()), m_t (_op_raw->start) {
	if ((!_op_raw->AddAddOp ()) && (!_op_raw->SubSubOp ())) {
		LOG_ERROR (_op_raw->start, "当前运算符无法解析为一元后缀表达式");
	}
}



_AST_Oper2Ctx::_AST_Oper2Ctx (): m_type (_Op2Type::None) {}
_AST_Oper2Ctx::_AST_Oper2Ctx (FaParser::AllAssignContext* _op_raw) : m_op (_op_raw->getText ()), m_t (_op_raw->start), m_type (_Op2Type::Assign) {}
_AST_Oper2Ctx::_AST_Oper2Ctx (FaParser::AllOp2Context* _op_raw) : m_op (_op_raw->getText ()), m_t (_op_raw->start) {
	if (_op_raw->selfOp2 ()) {
		m_type = _Op2Type::NoChange;
	} else if (_op_raw->changeOp2 ()->compareOp2 ()) {
		m_type = _Op2Type::Compare;
	}
}
_AST_Oper2Ctx::_AST_Oper2Ctx (FaParser::StrongExprSuffixContext* _op_raw): m_t (_op_raw->start) {
	if (_op_raw->PointOp ()) {
		m_op = _op_raw->PointOp ()->getText ();
	} else if (_op_raw->QuotYuanL ()) {
		m_op = "()";
	} else if (_op_raw->QuotFangL ()) {
		m_op = "[]";
	} else {
		LOG_ERROR (_op_raw->start, "当前运算符无法解析为二元表达式");
	}
}



_AST_ExprOrValue::_AST_ExprOrValue () {}
_AST_ExprOrValue::_AST_ExprOrValue (std::shared_ptr<_AST_ValueCtx> val): m_val (val) {}
_AST_ExprOrValue::_AST_ExprOrValue (std::shared_ptr<_AST_Arr1ValueCtx> val) : m_arrval1 (val) {}
_AST_ExprOrValue::_AST_ExprOrValue (std::shared_ptr<_AST_Arr2ValueCtx> val) : m_arrval2 (val) {}
_AST_ExprOrValue::_AST_ExprOrValue (std::shared_ptr<_AST_NewCtx> newval) : m_newval (newval) {}
_AST_ExprOrValue::_AST_ExprOrValue (std::shared_ptr<_AST_NewArrayCtx> newarrval) : m_newarrval (newarrval) {}
_AST_ExprOrValue::_AST_ExprOrValue (std::shared_ptr<_AST_Op1ExprTreeCtx> op1_expr) : m_op1_expr (op1_expr) {}
_AST_ExprOrValue::_AST_ExprOrValue (std::shared_ptr<_AST_Op2ExprTreeCtx> op2_expr) : m_op2_expr (op2_expr) {}
_AST_ExprOrValue::_AST_ExprOrValue (std::shared_ptr<_AST_OpNExprTreeCtx> opN_expr) : m_opN_expr (opN_expr) {}
_AST_ExprOrValue::_AST_ExprOrValue (std::shared_ptr<_AST_IfExprTreeCtx> if_expr) : m_if_expr (if_expr) {}

std::string _AST_ExprOrValue::GetExpectType () {
	if (m_val)
		return m_val->m_expect_type;
	if (m_arrval1)
		return m_arrval1->m_expect_type;
	if (m_arrval2)
		return m_arrval2->m_expect_type;
	if (m_newval)
		return m_newval->m_expect_type;
	if (m_newarrval)
		return m_newarrval->m_expect_type;
	if (m_op1_expr)
		return m_op1_expr->m_expect_type;
	if (m_op2_expr)
		return m_op2_expr->m_expect_type;
	if (m_opN_expr)
		return m_opN_expr->m_expect_type;
	if (m_if_expr)
		return m_if_expr->m_expect_type;
	return "";
}

void _AST_ExprOrValue::SetExpectType (std::string _type) {
	if (m_val) {
		m_val->m_expect_type = _type;
	} else if (m_arrval1) {
		m_arrval1->m_expect_type = _type;
	} else if (m_arrval2) {
		m_arrval2->m_expect_type = _type;
	} else if (m_newval) {
		m_newval->m_expect_type = _type;
	} else if (m_newarrval) {
		m_newarrval->m_expect_type = _type;
	} else if (m_op1_expr) {
		m_op1_expr->m_expect_type = _type;
	} else if (m_op2_expr) {
		m_op2_expr->m_expect_type = _type;
	} else if (m_opN_expr) {
		m_opN_expr->m_expect_type = _type;
	} else if (m_if_expr) {
		m_if_expr->m_expect_type = _type;
	}
}

std::string _AST_ExprOrValue::GetFuncName () {
	if (m_val) {
		return m_val->m_val.GetType ();
	} else if (m_op2_expr) {
		return m_op2_expr->m_expect_type;
	} else {
		return "";
	}
}

antlr4::Token* _AST_ExprOrValue::GetToken () {
	if (m_val)
		return m_val->m_t;
	if (m_arrval1)
		return m_arrval1->m_t;
	if (m_arrval2)
		return m_arrval2->m_t;
	if (m_newval)
		return m_newval->m_t;
	if (m_newarrval)
		return m_newarrval->m_t;
	if (m_op1_expr)
		return m_op1_expr->m_op.m_t;
	if (m_op2_expr)
		return m_op2_expr->m_op.m_t;
	if (m_opN_expr)
		return m_opN_expr->m_op.m_t;
	if (m_if_expr)
		return m_if_expr->m_t;
	return nullptr;
}



bool _AST_Op2ExprTreeCtx::CalcExpectType (AstClasses& _classes, std::string _namespace, std::vector<std::string>& _uses) {
	const static std::set<std::string> s_compare_ops { ">", ">=", "<", "<=", "==", "!=" };
	std::string _op_str = m_op.m_op;
	if (s_compare_ops.contains (_op_str)) {
		m_expect_type = "bool";
		return true;
	}

	if (_op_str == ".") {
		std::string _class_name = m_left.GetExpectType ();
		if (_class_name == "" || _class_name == "[member]")
			_class_name = m_left.m_val->m_val.m_member;
		if (_class_name == "cptr" && m_right.m_val->m_val.m_member == "Size") {
			m_expect_type = "int32";
			return true;
		}
		auto _ocls = _classes.GetClass (_class_name, _namespace, _uses);
		if (!_ocls.has_value ()) {
			LOG_ERROR (m_op.m_t, "仅支持结构体对象访问成员1");
			return false;
		}
		if (m_right.GetExpectType () != "[member]") {
			LOG_ERROR (m_op.m_t, "仅支持结构体对象访问成员2");
			return false;
		}
		auto _oitem = _ocls.value ()->GetMember (m_right.m_val->m_val.m_member);
		if (!_oitem.has_value ()) {
			LOG_ERROR (m_op.m_t, "仅支持结构体对象访问成员3");
			return false;
		}
		m_expect_type = _oitem.value ()->GetStringType ();
		return true;
	}

	if (_op_str == "??") {
		return false;
	}

	m_expect_type = m_left.GetExpectType ();
	return m_expect_type != "";
}



size_t OperAST::GetOpLevel (std::string _op2_str) {
	static std::map<std::string, size_t> s_priv_level {
		{ "**", 1 },
		{ "*", 2 }, { "/", 2 }, { "%", 2 },
		{ "+", 3 }, { "-", 3 },
		{ "<<", 4 }, { ">>", 4 },
		{ "&", 5 }, { "|", 5 }, { "^", 5 },
		{ "??", 6 },
		{ "<", 7 }, { "<=", 7 }, { ">", 7 }, { ">=", 7 }, { "==", 7 }, { "!=", 7 },
		{ "&&", 8 },
		{ "||", 9 },
	};
	if (s_priv_level.contains (_op2_str)) {
		return s_priv_level [_op2_str];
	} else {
		return std::string::npos;
	}
}

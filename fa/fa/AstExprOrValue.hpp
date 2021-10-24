#ifndef __AST_EXPR_OR_VALUE_HPP__
#define __AST_EXPR_OR_VALUE_HPP__



#include <algorithm>
#include <functional>
#include <optional>
#include <set>
#include <string>
#include <vector>

#include <antlr4-runtime/Token.h>

#include <FaParser.h>
#include "AstValue.h"



struct _AST_ExprOrValue;

enum class _Op1Type { None, Prefix, Suffix };
enum class _Op2Type { None, Assign, NoChange, Compare, Other };

struct _AST_ValueCtx {
	_AST_ValueCtx (AstValue _val, antlr4::Token* _t, std::string _expect_type): m_val (_val), m_t (_t), m_expect_type (_expect_type) {}

	AstValue					m_val {};
	antlr4::Token*				m_t = nullptr;
	std::string					m_expect_type = "";
};

struct _AST_Arr1ValueCtx {
	_AST_Arr1ValueCtx (std::vector<_AST_ExprOrValue> _vals, std::string _str_capacity, antlr4::Token* _t, std::string _expect_type): m_vals (_vals), m_str_capacity (_str_capacity), m_t (_t), m_expect_type (_expect_type) {}

	std::vector<_AST_ExprOrValue>	m_vals;					// start、stop、step
	std::string						m_str_capacity = "";
	antlr4::Token*					m_t = nullptr;
	std::string						m_expect_type = "";
};

struct _AST_Arr2ValueCtx {
	_AST_Arr2ValueCtx (std::vector<_AST_ExprOrValue> _vals, std::string _str_capacity, antlr4::Token* _t, std::string _expect_type): m_vals (_vals), m_str_capacity (_str_capacity), m_t (_t), m_expect_type (_expect_type) {}

	std::vector<_AST_ExprOrValue>	m_vals;
	std::string						m_str_capacity = "";
	antlr4::Token*					m_t = nullptr;
	std::string						m_expect_type = "";
};

struct _AST_NewCtx {
	_AST_NewCtx (antlr4::Token* _t, IAstClass *_cls, std::string _expect_type): m_t (_t), m_cls (_cls), m_expect_type (_expect_type) {
		m_cls->GetVars ([&] (AstClassVar* _cls_var) {
			if (_cls_var->m_is_static)
				return true;
			m_tvar_all.emplace (_cls_var->m_name);
			m_tvar_all_tmp.emplace (_cls_var->m_name);
			if (!_cls_var->m_init_value)
				m_tvar_init.emplace (_cls_var->m_name);
			return true;
		});
	}

	// 设置初始化参数
	bool SetInitVar (std::string _cls_var, _AST_ExprOrValue &_param, antlr4::Token* _t) {
		if (!m_tvar_all.contains (_cls_var)) {
			if (m_tvar_all_tmp.contains (_cls_var)) {
				LOG_ERROR (_t, std::format ("对象初始化时传递的 {} 参数重复", _cls_var));
			} else {
				LOG_ERROR (_t, std::format ("对象初始化不需要传递 {} 参数", _cls_var));
			}
			return false;
		}
		m_tvar_all.erase (_cls_var);
		if (m_tvar_init.contains (_cls_var))
			m_tvar_init.erase (_cls_var);
		m_cls_vars.push_back (_cls_var);
		m_params.push_back (_param);
		return true;
	}

	// 检查是否所有参数已初始化
	bool CheckVarsAllInit (antlr4::Token *_t, std::function<std::optional<_AST_ExprOrValue> (FaParser::ExprContext *, std::string)> _cb);

	antlr4::Token*					m_t = nullptr;
	IAstClass*						m_cls = nullptr;
	std::string						m_expect_type = "";
	std::vector<std::string>		m_cls_vars;
	std::vector<_AST_ExprOrValue>	m_params;

private:
	std::set<std::string>			m_tvar_all;
	std::set<std::string>			m_tvar_all_tmp;
	std::set<std::string>			m_tvar_init;
};

struct _AST_Oper1Ctx {
	_AST_Oper1Ctx (): m_type (_Op1Type::None) {}
	_AST_Oper1Ctx (FaParser::StrongExprPrefixContext* _op_raw): m_op (_op_raw->getText ()), m_t (_op_raw->start) {}
	_AST_Oper1Ctx (FaParser::StrongExprSuffixContext* _op_raw): m_op (_op_raw->getText ()), m_t (_op_raw->start) {
		if ((!_op_raw->AddAddOp ()) && (!_op_raw->SubSubOp ())) {
			LOG_ERROR (_op_raw->start, "当前运算符无法解析为一元后缀表达式");
		}
	}

	std::string					m_op = "";
	antlr4::Token*				m_t = nullptr;
	_Op1Type					m_type = _Op1Type::Prefix;
};

struct _AST_Oper2Ctx {
	_AST_Oper2Ctx (): m_type (_Op2Type::None) {}
	_AST_Oper2Ctx (FaParser::AllAssignContext* _op_raw): m_op (_op_raw->getText ()), m_t (_op_raw->start), m_type (_Op2Type::Assign) {}
	_AST_Oper2Ctx (FaParser::AllOp2Context* _op_raw): m_op (_op_raw->getText ()), m_t (_op_raw->start) {
		if (_op_raw->selfOp2 ()) {
			m_type = _Op2Type::NoChange;
		} else if (_op_raw->changeOp2 ()->compareOp2 ()) {
			m_type = _Op2Type::Compare;
		}
	}
	_AST_Oper2Ctx (FaParser::StrongExprSuffixContext* _op_raw): m_t (_op_raw->start) {
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

	std::string					m_op = "";
	antlr4::Token*				m_t = nullptr;
	_Op2Type					m_type = _Op2Type::Other;
};

struct _AST_Op1ExprTreeCtx;
struct _AST_Op2ExprTreeCtx;
struct _AST_OpNExprTreeCtx;
struct _AST_IfExprTreeCtx;
struct _AST_ExprOrValue {
	_AST_ExprOrValue () {}
	_AST_ExprOrValue (std::shared_ptr<_AST_ValueCtx> val): m_val (val) {}
	_AST_ExprOrValue (std::shared_ptr<_AST_Arr1ValueCtx> val): m_arrval1 (val) {}
	_AST_ExprOrValue (std::shared_ptr<_AST_Arr2ValueCtx> val): m_arrval2 (val) {}
	_AST_ExprOrValue (std::shared_ptr<_AST_NewCtx> newval): m_newval (newval) {}
	_AST_ExprOrValue (std::shared_ptr<_AST_Op1ExprTreeCtx> op1_expr): m_op1_expr (op1_expr) {}
	_AST_ExprOrValue (std::shared_ptr<_AST_Op2ExprTreeCtx> op2_expr): m_op2_expr (op2_expr) {}
	_AST_ExprOrValue (std::shared_ptr<_AST_OpNExprTreeCtx> opN_expr): m_opN_expr (opN_expr) {}
	_AST_ExprOrValue (std::shared_ptr<_AST_IfExprTreeCtx> if_expr): m_if_expr (if_expr) {}
	_AST_ExprOrValue &operator= (const _AST_ExprOrValue &_o) {
		m_val = _o.m_val;
		m_arrval1 = _o.m_arrval1;
		m_arrval2 = _o.m_arrval2;
		m_newval = _o.m_newval;
		m_op1_expr = _o.m_op1_expr;
		m_op2_expr = _o.m_op2_expr;
		m_opN_expr = _o.m_opN_expr;
		m_if_expr = _o.m_if_expr;
		return* this;
	}

	std::shared_ptr<_AST_ValueCtx>						m_val;
	std::shared_ptr<_AST_Arr1ValueCtx>					m_arrval1;
	std::shared_ptr<_AST_Arr2ValueCtx>					m_arrval2;
	std::shared_ptr<_AST_NewCtx>						m_newval;
	std::shared_ptr<_AST_Op1ExprTreeCtx>				m_op1_expr;
	std::shared_ptr<_AST_Op2ExprTreeCtx>				m_op2_expr;
	std::shared_ptr<_AST_OpNExprTreeCtx>				m_opN_expr;
	std::shared_ptr<_AST_IfExprTreeCtx>					m_if_expr;

	std::string GetExpectType ();
	void SetExpectType (std::string _type);
	std::string GetFuncName ();
	antlr4::Token* GetToken ();
};

//using _AST_ExprOrValue = std::variant<
//	_AST_ValueCtx,
//	std::shared_ptr<_AST_Op1ExprTreeCtx>,
//	std::shared_ptr<_AST_Op2ExprTreeCtx>,
//	std::shared_ptr<_AST_OpNExprTreeCtx>,
//	std::shared_ptr<_AST_IfExprTreeCtx>
//>;
struct _AST_Op1ExprTreeCtx {
	_AST_Oper1Ctx										m_op;
	_AST_ExprOrValue									m_left;
	std::string											m_expect_type;
};

struct _AST_Op2ExprTreeCtx {
	_AST_ExprOrValue									m_left;
	_AST_Oper2Ctx										m_op;
	_AST_ExprOrValue									m_right;
	std::string											m_expect_type;

	bool CalcExpectType (AstClasses &_classes, std::string _namespace) {
		const static std::set<std::string> s_compare_ops { ">", ">=", "<", "<=", "==", "!=" };
		std::string _op_str = m_op.m_op;
		if (s_compare_ops.contains (_op_str)) {
			m_expect_type = "bool";
			return true;
		}

		if (_op_str == ".") {
			std::string _class_name = m_left.GetExpectType ();
			if (_class_name == "")
				_class_name = m_left.m_val->m_val.m_member;
			auto _ocls = _classes.GetClass (_class_name, _namespace);
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
};

struct _AST_OpNExprTreeCtx {
	_AST_ExprOrValue									m_left;
	_AST_Oper2Ctx										m_op;
	std::vector<_AST_ExprOrValue>						m_rights;
	std::string											m_expect_type;
};

struct _AST_IfExprTreeCtx {
	std::vector<_AST_ExprOrValue>						m_conds;
	std::vector<std::vector<FaParser::StmtContext*>>	m_bodys1_raw;
	std::vector<FaParser::ExprContext*>					m_bodys2;
	std::string											m_expect_type;
};

inline std::string _AST_ExprOrValue::GetExpectType () {
	if (m_val)
		return m_val->m_expect_type;
	if (m_arrval1)
		return m_arrval1->m_expect_type;
	if (m_arrval2)
		return m_arrval2->m_expect_type;
	if (m_newval)
		return m_newval->m_expect_type;
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

inline void _AST_ExprOrValue::SetExpectType (std::string _type) {
	if (m_val) {
		m_val->m_expect_type = _type;
	} else if (m_arrval1) {
		m_arrval1->m_expect_type = _type;
	} else if (m_arrval2) {
		m_arrval2->m_expect_type = _type;
	} else if (m_newval) {
		m_newval->m_expect_type = _type;
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

inline std::string _AST_ExprOrValue::GetFuncName () {
	if (m_val) {
		return m_val->m_val.GetType ();
	} else if (m_op2_expr) {
		return m_op2_expr->m_expect_type;
	} else {
		return "";
	}
}

inline antlr4::Token* _AST_ExprOrValue::GetToken () {
	if (m_val)
		return m_val->m_t;
	if (m_arrval1)
		return m_arrval1->m_t;
	if (m_arrval2)
		return m_arrval2->m_t;
	if (m_newval)
		return m_newval->m_t;
	if (m_op1_expr)
		return m_op1_expr->m_op.m_t;
	if (m_op2_expr)
		return m_op2_expr->m_op.m_t;
	if (m_opN_expr)
		return m_opN_expr->m_op.m_t;
	if (m_if_expr)
		return m_if_expr->m_conds [0].GetToken ();
	return nullptr;
}

inline bool _AST_NewCtx::CheckVarsAllInit (antlr4::Token *_t, std::function<std::optional<_AST_ExprOrValue> (FaParser::ExprContext *, std::string)> _cb) {
	if (m_tvar_init.size () != 0) {
		for (auto _tvar_init : m_tvar_init)
			LOG_ERROR (_t, std::format ("未初始化的参数 {}", _tvar_init));
		return false;
	}

	// new 表达式未指定，但带有默认参数的值，拷贝进去
	for (auto _tvar : m_tvar_all) {
		auto _var = dynamic_cast<AstClassVar*> (m_cls->GetMember (_tvar).value ());
		m_cls_vars.push_back (_tvar);
		auto _oparam = _cb (_var->m_init_value, _var->m_type);
		if (!_oparam.has_value ())
			return false;
		m_params.push_back (_oparam.value ());
	}

	// 初始化参数列表排序
	std::vector<size_t> _vidx;
	for (size_t i = 0; i < m_cls_vars.size (); ++i) {
		auto _oidx = m_cls->GetVarIndex (m_cls_vars [i]);
		if (!_oidx.has_value ()) {
			LOG_ERROR (_t, std::format ("成员变量 {} 未定义", m_cls_vars [i]));
			return false;
		}
		_vidx.push_back (_oidx.value ());
	}
	for (size_t i = 0; i < _vidx.size () - 1; ++i) {
		for (size_t j = i; j < _vidx.size (); ++j) {
			if (_vidx[j] < _vidx[i]) {
				std::tie (_vidx[j], _vidx[i]) = std::make_tuple (_vidx[i], _vidx[j]);
				std::tie (m_cls_vars[j], m_cls_vars[i]) = std::make_tuple (m_cls_vars[i], m_cls_vars[j]);
				std::tie (m_params[j], m_params[i]) = std::make_tuple (m_params[i], m_params[j]);
			}
		}
	}
	return true;
}



class OperAST {
public:
	static size_t GetOpLevel (std::string _op2_str) {
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
};



#endif //__AST_EXPR_OR_VALUE_HPP__

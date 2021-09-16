#ifndef __AST_EXPR_OR_VALUE_HPP__
#define __AST_EXPR_OR_VALUE_HPP__



#include <set>
#include <string>
#include <vector>

#include <FaParser.h>
#include "AstValue.hpp"



struct _AST_ExprOrValue;

enum class _Op1Type { None, Prefix, Suffix };
enum class _Op2Type { None, Assign, NoChange, Compare, Other };

struct _AST_ValueCtx {
	_AST_ValueCtx (AstValue _val, antlr4::Token *_t, std::string _expect_type): m_val (_val), m_t (_t), m_expect_type (_expect_type) {}

	AstValue					m_val {};
	antlr4::Token				*m_t = nullptr;
	std::string					m_expect_type = "";
};

struct _AST_NewCtx {
	_AST_NewCtx (std::shared_ptr<AstClass> _cls, std::string _expect_type): m_cls (_cls), m_expect_type (_expect_type) {
		for (auto _cls_var : m_cls->m_vars) {
			if (_cls_var->m_is_static)
				continue;
			m_tvar_all.emplace (_cls_var->m_name);
			m_tvar_all_copy.emplace (_cls_var->m_name);
			if (!_cls_var->m_init_value)
				m_tvar_init.emplace (_cls_var->m_name);
		}
	}

	// 设置初始化参数
	bool SetInitVar (std::string _cls_var, _AST_ExprOrValue &_param, antlr4::Token *_t) {
		if (!m_tvar_all.contains (_cls_var)) {
			if (m_tvar_all_copy.contains (_cls_var)) {
				LOG_ERROR (_t, std::format ("对象初始化时传递的 {} 参数重复", _cls_var));
			} else {
				LOG_ERROR (_t, std::format ("对象初始化不需要传递 {} 参数", _cls_var));
			}
			return false;
		}
		m_tvar_all.erase (_cls_var);
		if (m_tvar_init.contains (_cls_var))
			m_tvar_all.erase (_cls_var);
		m_cls_vars.push_back (_cls_var);
		m_params.push_back (_param);
		return true;
	}

	// 检查是否所有参数已初始化
	bool CheckVarsAllInit (antlr4::Token *_t) {
		if (m_tvar_init.size () == 0)
			return true;
		for (auto _tvar_init : m_tvar_init)
			LOG_ERROR (_t, std::format ("未初始化的参数 {}", _tvar_init));
		return false;
	}

	std::shared_ptr<AstClass>		m_cls;
	std::string						m_expect_type = "";
	std::vector<std::string>		m_cls_vars;
	std::vector<_AST_ExprOrValue>	m_params;

private:
	std::set<std::string>			m_tvar_all;
	std::set<std::string>			m_tvar_all_copy;
	std::set<std::string>			m_tvar_init;
};

struct _AST_Oper1Ctx {
	_AST_Oper1Ctx (): m_type (_Op1Type::None) {}
	_AST_Oper1Ctx (FaParser::StrongExprPrefixContext *_op_raw): m_op (_op_raw->getText ()), m_t (_op_raw->start) {}
	_AST_Oper1Ctx (FaParser::StrongExprSuffixContext *_op_raw): m_op (_op_raw->getText ()), m_t (_op_raw->start) {
		if ((!_op_raw->AddAddOp ()) && (!_op_raw->SubSubOp ())) {
			LOG_ERROR (_op_raw->start, "当前运算符无法解析为一元后缀表达式");
		}
	}

	std::string					m_op = "";
	antlr4::Token				*m_t = nullptr;
	_Op1Type					m_type = _Op1Type::Prefix;
};

struct _AST_Oper2Ctx {
	_AST_Oper2Ctx (): m_type (_Op2Type::None) {}
	_AST_Oper2Ctx (FaParser::AllAssignContext *_op_raw): m_op (_op_raw->getText ()), m_t (_op_raw->start), m_type (_Op2Type::Assign) {}
	_AST_Oper2Ctx (FaParser::AllOp2Context *_op_raw): m_op (_op_raw->getText ()), m_t (_op_raw->start) {
		if (_op_raw->selfOp2 ()) {
			m_type = _Op2Type::NoChange;
		} else if (_op_raw->changeOp2 ()->compareOp2 ()) {
			m_type = _Op2Type::Compare;
		}
	}
	_AST_Oper2Ctx (FaParser::StrongExprSuffixContext *_op_raw): m_t (_op_raw->start) {
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
	antlr4::Token				*m_t = nullptr;
	_Op2Type					m_type = _Op2Type::Other;
};

struct _AST_Op1ExprTreeCtx;
struct _AST_Op2ExprTreeCtx;
struct _AST_OpNExprTreeCtx;
struct _AST_IfExprTreeCtx;
struct _AST_ExprOrValue {
	_AST_ExprOrValue () {}
	_AST_ExprOrValue (std::shared_ptr<_AST_ValueCtx> val): m_val (val) {}
	_AST_ExprOrValue (std::shared_ptr<_AST_NewCtx> newval): m_newval (newval) {}
	_AST_ExprOrValue (std::shared_ptr<_AST_Op1ExprTreeCtx> op1_expr): m_op1_expr (op1_expr) {}
	_AST_ExprOrValue (std::shared_ptr<_AST_Op2ExprTreeCtx> op2_expr): m_op2_expr (op2_expr) {}
	_AST_ExprOrValue (std::shared_ptr<_AST_OpNExprTreeCtx> opN_expr): m_opN_expr (opN_expr) {}
	_AST_ExprOrValue (std::shared_ptr<_AST_IfExprTreeCtx> if_expr): m_if_expr (if_expr) {}
	_AST_ExprOrValue &operator= (const _AST_ExprOrValue &_o) {
		m_val = _o.m_val;
		m_newval = _o.m_newval;
		m_op1_expr = _o.m_op1_expr;
		m_op2_expr = _o.m_op2_expr;
		m_opN_expr = _o.m_opN_expr;
		m_if_expr = _o.m_if_expr;
		return *this;
	}

	std::shared_ptr<_AST_ValueCtx>						m_val;
	std::shared_ptr<_AST_NewCtx>						m_newval;
	std::shared_ptr<_AST_Op1ExprTreeCtx>				m_op1_expr;
	std::shared_ptr<_AST_Op2ExprTreeCtx>				m_op2_expr;
	std::shared_ptr<_AST_OpNExprTreeCtx>				m_opN_expr;
	std::shared_ptr<_AST_IfExprTreeCtx>					m_if_expr;

	std::string GetExpectType ();
	std::string GetFuncName ();
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

	bool CalcExpectType () {
		const static std::set<std::string> s_compare_ops { ">", ">=", "<", "<=", "==", "!=" };
		std::string _op_str = m_op.m_op;
		if (s_compare_ops.contains (_op_str)) {
			m_expect_type = "bool";
			return true;
		}

		if (_op_str == "??" || _op_str == ".") {
			// TODO
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
	std::vector<std::vector<FaParser::StmtContext *>>	m_bodys1_raw;
	std::vector<FaParser::ExprContext *>				m_bodys2;
	std::string											m_expect_type;
};

inline std::string _AST_ExprOrValue::GetExpectType () {
	if (m_val) {
		return m_val->m_expect_type;
	} else if (m_newval) {
		return m_newval->m_expect_type;
	} else if (m_op1_expr) {
		return m_op1_expr->m_expect_type;
	} else if (m_op2_expr) {
		return m_op2_expr->m_expect_type;
	} else if (m_opN_expr) {
		return m_opN_expr->m_expect_type;
	} else if (m_if_expr) {
		return m_if_expr->m_expect_type;
	} else {
		return "";
	}
}

inline std::string _AST_ExprOrValue::GetFuncName () {
	if (m_val) {
		return m_val->m_val.GetType ();
	} else {
		return "";
	}
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

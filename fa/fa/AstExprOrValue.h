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
	_AST_ValueCtx (AstValue _val, antlr4::Token* _t, std::string _expect_type);

	AstValue						m_val {};
	antlr4::Token*					m_t = nullptr;
	std::string						m_expect_type = "";
};

struct _AST_Arr1ValueCtx {
	_AST_Arr1ValueCtx (std::vector<_AST_ExprOrValue> _vals, std::string _str_capacity, antlr4::Token* _t, std::string _expect_type);

	std::vector<_AST_ExprOrValue>	m_vals;					// start、stop、step
	std::string						m_str_capacity = "";
	antlr4::Token*					m_t = nullptr;
	std::string						m_expect_type = "";
};

struct _AST_Arr2ValueCtx {
	_AST_Arr2ValueCtx (std::vector<_AST_ExprOrValue> _vals, std::string _str_capacity, antlr4::Token* _t, std::string _expect_type);

	std::vector<_AST_ExprOrValue>	m_vals;
	std::string						m_str_capacity = "";
	antlr4::Token*					m_t = nullptr;
	std::string						m_expect_type = "";
};

struct _AST_NewCtx {
	_AST_NewCtx (antlr4::Token* _t, IAstClass* _cls, std::string _expect_type);

	// 设置初始化参数
	bool SetInitVar (std::string _name, _AST_ExprOrValue _param, antlr4::Token* _t);

	// 检查是否所有参数已初始化
	bool CheckVarsAllInit (antlr4::Token* _t, std::function<std::optional<_AST_ExprOrValue> (FaParser::ExprContext*, std::string)> _cb);

	antlr4::Token*									m_t = nullptr;
	IAstClass*										m_cls = nullptr;
	std::string										m_expect_type = "";
	std::vector<std::optional<_AST_ExprOrValue>>	m_init_params;
};

struct _AST_NewArrayCtx {
	_AST_NewArrayCtx (std::string _item_type, antlr4::Token* _t);

	void SetSize (std::shared_ptr<_AST_ExprOrValue> _eov);

	std::string							m_item_type = "";
	std::string							m_expect_type = "";
	antlr4::Token*						m_t = nullptr;
	std::shared_ptr<_AST_ExprOrValue>	m_size; // only use 1 item
};

struct _AST_Oper1Ctx {
	_AST_Oper1Ctx ();
	_AST_Oper1Ctx (FaParser::StrongExprPrefixContext* _op_raw);
	_AST_Oper1Ctx (FaParser::StrongExprSuffixContext* _op_raw);

	std::string							m_op = "";
	antlr4::Token*						m_t = nullptr;
	_Op1Type							m_type = _Op1Type::Prefix;
};

struct _AST_Oper2Ctx {
	_AST_Oper2Ctx ();
	_AST_Oper2Ctx (FaParser::AllAssignContext* _op_raw);
	_AST_Oper2Ctx (FaParser::AllOp2Context* _op_raw);
	_AST_Oper2Ctx (FaParser::StrongExprSuffixContext* _op_raw);

	std::string							m_op = "";
	antlr4::Token*						m_t = nullptr;
	_Op2Type							m_type = _Op2Type::Other;
};

struct _AST_Op1ExprTreeCtx;
struct _AST_Op2ExprTreeCtx;
struct _AST_OpNExprTreeCtx;
struct _AST_IfExprTreeCtx;
struct _AST_ExprOrValue {
	_AST_ExprOrValue ();
	_AST_ExprOrValue (std::shared_ptr<_AST_ValueCtx> val);
	_AST_ExprOrValue (std::shared_ptr<_AST_Arr1ValueCtx> val);
	_AST_ExprOrValue (std::shared_ptr<_AST_Arr2ValueCtx> val);
	_AST_ExprOrValue (std::shared_ptr<_AST_NewCtx> newval);
	_AST_ExprOrValue (std::shared_ptr<_AST_NewArrayCtx> newarrval);
	_AST_ExprOrValue (std::shared_ptr<_AST_Op1ExprTreeCtx> op1_expr);
	_AST_ExprOrValue (std::shared_ptr<_AST_Op2ExprTreeCtx> op2_expr);
	_AST_ExprOrValue (std::shared_ptr<_AST_OpNExprTreeCtx> opN_expr);
	_AST_ExprOrValue (std::shared_ptr<_AST_IfExprTreeCtx> if_expr);
	_AST_ExprOrValue& operator= (const _AST_ExprOrValue& _o) = default;

	std::shared_ptr<_AST_ValueCtx>						m_val;
	std::shared_ptr<_AST_Arr1ValueCtx>					m_arrval1;
	std::shared_ptr<_AST_Arr2ValueCtx>					m_arrval2;
	std::shared_ptr<_AST_NewCtx>						m_newval;
	std::shared_ptr<_AST_NewArrayCtx>					m_newarrval;
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

	bool CalcExpectType (AstClasses& _classes, std::string _namespace, std::vector<std::string>& _uses);
};

struct _AST_OpNExprTreeCtx {
	_AST_ExprOrValue									m_left;
	_AST_Oper2Ctx										m_op;
	std::vector<_AST_ExprOrValue>						m_rights;
	std::string											m_expect_type;
};

struct _AST_IfExprTreeCtx {
	antlr4::Token* m_t = nullptr;
	std::vector<_AST_ExprOrValue>						m_conds;
	std::vector<std::vector<FaParser::StmtContext*>>	m_bodys1_raw;
	std::vector<FaParser::ExprContext*>					m_bodys2;
	std::string											m_expect_type;
};

struct OperAST {
	static size_t GetOpLevel (std::string _op2_str);
};



#endif //__AST_EXPR_OR_VALUE_HPP__

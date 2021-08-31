#ifndef __OPER_AST_HPP__
#define __OPER_AST_HPP__



#include <string>
#include <vector>

#include <FaParser.h>
#include "AstValue.hpp"



enum class _Op1Type { None, Prefix, Suffix };
enum class _Op2Type { None, Assign, NoChange, Compare, Other };

struct _AST_ValueCtx {
	_AST_ValueCtx (AstValue __val, antlr4::Token *__t, std::string __expect_type): _val (__val), _t (__t), _expect_type (__expect_type) {}

	AstValue _val {};
	antlr4::Token *_t = nullptr;
	std::string _expect_type = "";
};

struct _AST_Oper1Ctx {
	_AST_Oper1Ctx (): _type (_Op1Type::None) {}
	_AST_Oper1Ctx (FaParser::StrongExprPrefixContext *_op_raw): _op (_op_raw->getText ()), _t (_op_raw->start) {}
	_AST_Oper1Ctx (FaParser::StrongExprSuffixContext *_op_raw): _op (_op_raw->getText ()), _t (_op_raw->start) {
		if ((!_op_raw->AddAddOp ()) && (!_op_raw->SubSubOp ())) {
			LOG_ERROR (_op_raw->start, "当前运算符无法解析为一元后缀表达式");
		}
	}

	std::string _op = "";
	antlr4::Token *_t = nullptr;
	_Op1Type _type = _Op1Type::Prefix;
};

struct _AST_Oper2Ctx {
	_AST_Oper2Ctx (): _type (_Op2Type::None) {}
	_AST_Oper2Ctx (FaParser::AllAssignContext *_op_raw): _op (_op_raw->getText ()), _t (_op_raw->start), _type (_Op2Type::Assign) {}
	_AST_Oper2Ctx (FaParser::AllOp2Context *_op_raw): _op (_op_raw->getText ()), _t (_op_raw->start) {
		if (_op_raw->selfOp2 ()) {
			_type = _Op2Type::NoChange;
		} else if (_op_raw->changeOp2 ()->compareOp2 ()) {
			_type = _Op2Type::Compare;
		}
	}
	_AST_Oper2Ctx (FaParser::StrongExprSuffixContext *_op_raw): _t (_op_raw->start) {
		if (_op_raw->PointOp ()) {
			_op = _op_raw->PointOp ()->getText ();
		} else if (_op_raw->QuotYuanL ()) {
			_op = "()";
		} else if (_op_raw->QuotFangL ()) {
			_op = "[]";
		} else {
			LOG_ERROR (_op_raw->start, "当前运算符无法解析为二元表达式");
		}
	}

	std::string _op = "";
	antlr4::Token *_t = nullptr;
	_Op2Type _type = _Op2Type::Other;
};

struct _AST_Op1ExprTreeCtx;
struct _AST_Op2ExprTreeCtx;
struct _AST_OpNExprTreeCtx;
struct _AST_IfExprTreeCtx;
struct _AST_ExprOrValue {
	_AST_ExprOrValue () {}
	_AST_ExprOrValue (std::shared_ptr<_AST_ValueCtx> __val): _val (__val) {}
	_AST_ExprOrValue (std::shared_ptr<_AST_Op1ExprTreeCtx> __op1_expr): _op1_expr (__op1_expr) {}
	_AST_ExprOrValue (std::shared_ptr<_AST_Op2ExprTreeCtx> __op2_expr): _op2_expr (__op2_expr) {}
	_AST_ExprOrValue (std::shared_ptr<_AST_OpNExprTreeCtx> __opN_expr): _opN_expr (__opN_expr) {}
	_AST_ExprOrValue (std::shared_ptr<_AST_IfExprTreeCtx> __if_expr): _if_expr (__if_expr) {}
	_AST_ExprOrValue &operator= (const _AST_ExprOrValue &_o) {
		_val = _o._val;
		_op1_expr = _o._op1_expr;
		_op2_expr = _o._op2_expr;
		_opN_expr = _o._opN_expr;
		_if_expr = _o._if_expr;
		return *this;
	}

	std::shared_ptr<_AST_ValueCtx>						_val;
	std::shared_ptr<_AST_Op1ExprTreeCtx>				_op1_expr;
	std::shared_ptr<_AST_Op2ExprTreeCtx>				_op2_expr;
	std::shared_ptr<_AST_OpNExprTreeCtx>				_opN_expr;
	std::shared_ptr<_AST_IfExprTreeCtx>					_if_expr;

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
	_AST_Oper1Ctx										_op;
	_AST_ExprOrValue									_left;
	std::string											_expect_type;
};

struct _AST_Op2ExprTreeCtx {
	_AST_ExprOrValue									_left;
	_AST_Oper2Ctx										_op;
	_AST_ExprOrValue									_right;
	std::string											_expect_type;

	bool CalcExpectType () {
		const static std::set<std::string> s_compare_ops { ">", ">=", "<", "<=", "==", "!=" };
		std::string _op_str = _op._op;
		if (s_compare_ops.contains (_op_str)) {
			_expect_type = "bool";
			return true;
		}

		if (_op_str == "??" || _op_str == ".") {
			// TODO
			return false;
		}

		_expect_type = _left.GetExpectType ();
		return _expect_type != "";
	}
};

struct _AST_OpNExprTreeCtx {
	_AST_ExprOrValue									_left;
	_AST_Oper2Ctx										_op;
	std::vector<_AST_ExprOrValue>						_rights;
	std::string											_expect_type;
};

struct _AST_IfExprTreeCtx {
	std::vector<_AST_ExprOrValue>						_conds;
	std::vector<std::vector<FaParser::StmtContext *>>	_bodys1_raw;
	std::vector<FaParser::ExprContext *>				_bodys2;
	std::string											_expect_type;
};

inline std::string _AST_ExprOrValue::GetExpectType () {
	if (_val) {
		return _val->_expect_type;
	} else if (_op1_expr) {
		return _op1_expr->_expect_type;
	} else if (_op2_expr) {
		return _op2_expr->_expect_type;
	} else if (_opN_expr) {
		return _opN_expr->_expect_type;
	} else if (_if_expr) {
		return _if_expr->_expect_type;
	} else {
		return "";
	}
}

inline std::string _AST_ExprOrValue::GetFuncName () {
	if (_val) {
		return _val->_val.GetType ();
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



#endif //__OPER_AST_HPP__

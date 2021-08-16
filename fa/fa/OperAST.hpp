#ifndef __OPER_AST_HPP__
#define __OPER_AST_HPP__



#include <string>
#include <vector>

#include <FaParser.h>
#include "AstValue.hpp"



enum class _Op1Type { Prefix, Suffix };
enum class _Op2Type { Assign, NoChange, Compare, Other };

struct _ValueCtx {
	_ValueCtx (AstValue __val, antlr4::Token *__t, std::string __expect_type): _val (__val), _t (__t), _expect_type (__expect_type) {}

	AstValue _val {};
	antlr4::Token *_t = nullptr;
	std::string _expect_type = "";
};

struct _Oper1Ctx {
	_Oper1Ctx (FaParser::StrongExprPrefixContext *_op_raw): _op (_op_raw->getText ()), _t (_op_raw->start) {}
	_Oper1Ctx (FaParser::StrongExprSuffixContext *_op_raw): _op (_op_raw->getText ()), _t (_op_raw->start) {
		if ((!_op_raw->AddAddOp ()) && (!_op_raw->SubSubOp ())) {
			LOG_ERROR (_op_raw->start, "当前运算符无法解析为一元后缀表达式");
		}
	}

	std::string _op = "";
	antlr4::Token *_t = nullptr;
	_Op1Type _type = _Op1Type::Prefix;
};

struct _Oper2Ctx {
	_Oper2Ctx (FaParser::AllAssignContext *_op_raw): _op (_op_raw->getText ()), _t (_op_raw->start), _type (_Op2Type::Assign) {}
	_Oper2Ctx (FaParser::AllOp2Context *_op_raw): _op (_op_raw->getText ()), _t (_op_raw->start) {
		if (_op_raw->selfOp2 ()) {
			_type = _Op2Type::NoChange;
		} else if (_op_raw->changeOp2 ()->compareOp2 ()) {
			_type = _Op2Type::Compare;
		}
	}
	_Oper2Ctx (FaParser::StrongExprSuffixContext *_op_raw): _t (_op_raw->start) {
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

struct _Op1ExprTreeCtx;
struct _Op2ExprTreeCtx;
struct _OpNExprTreeCtx;
struct _IfExprTreeCtx;
struct _ExprOrValue {
	_ExprOrValue () {}
	_ExprOrValue (std::shared_ptr<_ValueCtx> __val): _val (__val) {}
	_ExprOrValue (std::shared_ptr<_Op1ExprTreeCtx> __op1_expr): _op1_expr (__op1_expr) {}
	_ExprOrValue (std::shared_ptr<_Op2ExprTreeCtx> __op2_expr): _op2_expr (__op2_expr) {}
	_ExprOrValue (std::shared_ptr<_OpNExprTreeCtx> __opN_expr): _opN_expr (__opN_expr) {}
	_ExprOrValue (std::shared_ptr<_IfExprTreeCtx> __if_expr): _if_expr (__if_expr) {}

	std::shared_ptr<_ValueCtx> _val;
	std::shared_ptr<_Op1ExprTreeCtx> _op1_expr;
	std::shared_ptr<_Op2ExprTreeCtx> _op2_expr;
	std::shared_ptr<_OpNExprTreeCtx> _opN_expr;
	std::shared_ptr<_IfExprTreeCtx> _if_expr;

	std::string GetExpectType ();
};

//using _ExprOrValue = std::variant<
//	_ValueCtx,
//	std::shared_ptr<_Op1ExprTreeCtx>,
//	std::shared_ptr<_Op2ExprTreeCtx>,
//	std::shared_ptr<_OpNExprTreeCtx>,
//	std::shared_ptr<_IfExprTreeCtx>
//>;
struct _Op1ExprTreeCtx {
	_Oper1Ctx											_op;
	_ExprOrValue										_left;
	std::string											_expect_type;
};

struct _Op2ExprTreeCtx {
	_ExprOrValue										_left;
	_Oper2Ctx											_op;
	_ExprOrValue										_right;
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

struct _OpNExprTreeCtx {
	_ExprOrValue										_left;
	_Oper2Ctx											_op;
	std::vector<_ExprOrValue>							_rights;
	std::string											_expect_type;
};

struct _IfExprTreeCtx {
	std::vector<_ExprOrValue>							_conds;
	std::vector<std::vector<FaParser::StmtContext *>>	_bodys1_raw;
	std::vector<_ExprOrValue>							_bodys2;
	std::string											_expect_type;
};

inline std::string _ExprOrValue::GetExpectType () {
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

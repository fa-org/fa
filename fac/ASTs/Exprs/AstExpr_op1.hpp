#ifndef __AST_EXPR_OP1_HPP__
#define __AST_EXPR_OP1_HPP__



#include <memory>
#include <string>

#include "IAstExpr.hpp"



struct AstExpr_op1: public IAstExpr {
	PAstExpr m_base;
	std::string m_op;
	bool m_prefix;

	AstExpr_op1 (antlr4::Token *_token, PAstExpr _base, std::string _op, bool _prefix):
		IAstExpr (_token), m_base (_base), m_op (_op), m_prefix (_prefix) {}

	std::string GenCppCode (size_t _indent) override {
		if (m_prefix) {
			return std::format ("{}{}", m_op, m_base->GenCppCode (_indent));
		} else {
			return std::format ("{}{}", m_base->GenCppCode (_indent), m_op);
		}
	}

	void GetChildTypes (std::function<void (PAstType &)> _cb) override {}

	void GetChildExprs (std::function<void (PAstExpr &)> _cb) override { _cb (m_base); }

	void GetChildStmts (std::function<void (PAstStmt &)> _cb) override {}

	static PAstExpr Make (antlr4::Token *_token, PAstExpr _base, std::string _op, bool _prefix) {
		return new AstExpr_op1 { _token, _base, _op, _prefix };
	}
};



#endif //__AST_EXPR_OP1_HPP__

#ifndef __AST_EXPR_OP2_HPP__
#define __AST_EXPR_OP2_HPP__



#include <memory>
#include <string>

#include "IAstExpr.hpp"



struct AstExpr_op2: public IAstExpr {
	PAstExpr m_left, m_right;
	std::string m_op;

	AstExpr_op2 (antlr4::Token *_token, PAstExpr _left, std::string _op, PAstExpr _right):
		IAstExpr (_token), m_left (_left), m_op (_op), m_right (_right) {}



	void GetChildTypes (std::function<void (PAstType &)> _cb) override {}

	void GetChildExprs (std::function<void (PAstExpr &)> _cb) override { _cb (m_left); _cb (m_right); }

	void GetChildStmts (std::function<void (PAstStmt &)> _cb) override {}



	PAstType GuessType () override { throw NOT_IMPLEMENT (); }

	void ProcessCode (PAstType _type) override { throw NOT_IMPLEMENT (); }

	std::string GenCppCode (size_t _indent) override {
		std::string _s = std::format ("{} {} {}", m_left->GenCppCode (_indent), m_op, m_right->GenCppCode (_indent));
		if (!(m_op [m_op.size () - 1] == '=' && m_op != ">=" && m_op != "<="))
			_s = std::format ("({})", _s);
		return _s;
	}



	static PAstExpr Make (antlr4::Token *_token, PAstExpr _left, std::string _op, PAstExpr _right) {
		return new AstExpr_op2 { _token, _left, _op, _right };
	}
};



#endif //__AST_EXPR_OP2_HPP__

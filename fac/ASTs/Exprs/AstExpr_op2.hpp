#ifndef __AST_EXPR_OP2_HPP__
#define __AST_EXPR_OP2_HPP__



#include <memory>
#include <string>

#include "IAstExpr.hpp"



struct AstExpr_op2: public IAstExpr {
	std::shared_ptr<IAstExpr> m_left, m_right;
	std::string m_op;

	AstExpr_op2 (antlr4::Token *_token, std::shared_ptr<IAstExpr> _left, std::string _op, std::shared_ptr<IAstExpr> _right):
		IAstExpr (_token), m_left (_left), m_op (_op), m_right (_right) {}

	std::string GenCppCode (size_t _indent) override {
		std::string _s = std::format ("{} {} {}", m_left->GenCppCode (_indent), m_op, m_right->GenCppCode (_indent));
		if (!(m_op [m_op.size () - 1] == '=' && m_op != ">=" && m_op != "<="))
			_s = std::format ("({})", _s);
		return _s;
	}

	static std::shared_ptr<IAstExpr> Make (antlr4::Token *_token, std::shared_ptr<IAstExpr> _left, std::string _op, std::shared_ptr<IAstExpr> _right) {
		return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstExpr_op2 { _token, _left, _op, _right });
	}
};



#endif //__AST_EXPR_OP2_HPP__

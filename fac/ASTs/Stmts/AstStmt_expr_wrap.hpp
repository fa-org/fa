#ifndef __AST_STMT_EXPR_WRAP_HPP__
#define __AST_STMT_EXPR_WRAP_HPP__



#include <format>
#include <memory>
#include <vector>

#include "IAstStmt.hpp"
#include "../Exprs/IAstExpr.hpp"



struct AstStmt_expr_wrap: public IAstStmt {
	std::shared_ptr<IAstExpr> m_expr;

	AstStmt_expr_wrap (antlr4::Token *_token, std::shared_ptr<IAstExpr> _expr): IAstStmt (_token),  m_expr (_expr) {}

	std::string GenCppCode (size_t _indent) override { return std::format ("{}{};\n", Indent (_indent), m_expr->GenCppCode (_indent)); }

	static std::shared_ptr<IAstStmt> FromExpr (antlr4::Token *_token, std::shared_ptr<IAstExpr> _expr) {
		return std::shared_ptr<IAstStmt> ((IAstStmt *) new AstStmt_expr_wrap { _token, _expr });
	}
};



#endif //__AST_STMT_EXPR_WRAP_HPP__

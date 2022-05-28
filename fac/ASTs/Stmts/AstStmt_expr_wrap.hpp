#ifndef __AST_STMT_EXPR_WRAP_HPP__
#define __AST_STMT_EXPR_WRAP_HPP__



#include <memory>
#include <vector>

#include "IAstStmt.hpp"
#include "../Exprs/IAstExpr.hpp"



struct AstStmt_expr_wrap: public IAstStmt {
	std::shared_ptr<IAstExpr> m_expr;

	AstStmt_expr_wrap (std::shared_ptr<IAstExpr> _expr): m_expr (_expr) {}
	std::string GenCppCode () override { return std::format ("{};", m_expr->GenCppCode ()); }

	static std::shared_ptr<IAstStmt> FromExpr (std::shared_ptr<IAstExpr> _expr) {
		return std::shared_ptr<IAstStmt> ((IAstStmt *) new AstStmt_expr_wrap (_expr));
	}
};



#endif //__AST_STMT_EXPR_WRAP_HPP__

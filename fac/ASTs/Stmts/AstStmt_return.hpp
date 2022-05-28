#ifndef __AST_STMT_RETURN_HPP__
#define __AST_STMT_RETURN_HPP__



#include <memory>
#include <vector>

#include "IAstStmt.hpp"
#include "../Exprs/IAstExpr.hpp"



struct AstStmt_return: public IAstStmt {
	std::shared_ptr<IAstExpr> m_expr;

	AstStmt_return (std::shared_ptr<IAstExpr> _expr): m_expr (_expr) {}
	std::string GenCppCode () override { return std::format ("return {};", m_expr ? m_expr->GenCppCode () : ""); }

	static std::shared_ptr<IAstStmt> FromExpr (std::shared_ptr<IAstExpr> _expr) {
		return std::shared_ptr<IAstStmt> ((IAstStmt *) new AstStmt_return (_expr));
	}
};



#endif //__AST_STMT_RETURN_HPP__

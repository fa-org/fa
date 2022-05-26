#ifndef __AST_RETURN_STMT_HPP__
#define __AST_RETURN_STMT_HPP__



#include <memory>
#include <vector>

#include "IAstStmt.hpp"
#include "../Exprs/IAstExpr.hpp"



struct AstReturnStmt: public IAstStmt {
	std::shared_ptr<IAstExpr> m_expr;

	AstReturnStmt (std::shared_ptr<IAstExpr> _expr): m_expr (_expr) {}

	static std::shared_ptr<IAstStmt> FromExpr (std::shared_ptr<IAstExpr> _expr) {
		return std::shared_ptr<IAstStmt> ((IAstStmt *) new AstReturnStmt (_expr));
	}
};



#endif //__AST_RETURN_STMT_HPP__

#ifndef __AST_RETURN_STMT_HPP__
#define __AST_RETURN_STMT_HPP__



#include <memory>
#include <vector>

#include "AstStmt.hpp"
#include "../Exprs/AstExpr.hpp"



struct AstReturnStmt: public AstStmt {
	std::shared_ptr<AstExpr> m_expr;

	AstReturnStmt (std::shared_ptr<AstExpr> _expr): m_expr (_expr) {}
};



#endif //__AST_RETURN_STMT_HPP__

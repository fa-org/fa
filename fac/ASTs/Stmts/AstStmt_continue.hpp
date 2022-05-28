#ifndef __AST_STMT_CONTINUE_HPP__
#define __AST_STMT_CONTINUE_HPP__



#include <memory>
#include <vector>

#include "IAstStmt.hpp"
#include "../Exprs/IAstExpr.hpp"



struct AstStmt_continue: public IAstStmt {
	std::string GenCppCode () override { return "continue;"; }
};



#endif //__AST_STMT_CONTINUE_HPP__

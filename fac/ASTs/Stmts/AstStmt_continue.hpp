#ifndef __AST_STMT_CONTINUE_HPP__
#define __AST_STMT_CONTINUE_HPP__



#include <memory>
#include <vector>

#include "IAstStmt.hpp"
#include "../Exprs/IAstExpr.hpp"



struct AstStmt_continue: public IAstStmt {
	std::string GenCppCode (size_t _indent) override { return std::format ("{}continue;\n", Indent (_indent)); }
};



#endif //__AST_STMT_CONTINUE_HPP__

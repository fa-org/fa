#ifndef __AST_STMT_BREAK_HPP__
#define __AST_STMT_BREAK_HPP__



#include <memory>
#include <vector>

#include "IAstStmt.hpp"
#include "../Exprs/IAstExpr.hpp"



struct AstStmt_break: public IAstStmt {
	std::string GenCppCode (size_t _indent) override { return std::format ("{}break;\n", Indent (_indent)); }
};



#endif //__AST_STMT_BREAK_HPP__

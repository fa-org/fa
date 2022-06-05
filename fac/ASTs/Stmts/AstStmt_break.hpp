#ifndef __AST_STMT_BREAK_HPP__
#define __AST_STMT_BREAK_HPP__



#include <memory>
#include <vector>

#include "IAstStmt.hpp"
#include "../Exprs/IAstExpr.hpp"



struct AstStmt_break: public IAstStmt {
	AstStmt_break (antlr4::Token *_token): IAstStmt (_token) {}

	std::string GenCppCode (size_t _indent) override { return std::format ("{}break;\n", Indent (_indent)); }

	static PAstStmt Make (antlr4::Token *_token) {
		return new AstStmt_break { _token };
	}
};



#endif //__AST_STMT_BREAK_HPP__

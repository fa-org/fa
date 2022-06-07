#ifndef __AST_STMT_CONTINUE_HPP__
#define __AST_STMT_CONTINUE_HPP__



#include <memory>
#include <vector>

#include "IAstStmt.hpp"
#include "../Exprs/IAstExpr.hpp"



struct AstStmt_continue: public IAstStmt {
	AstStmt_continue (antlr4::Token *_token): IAstStmt (_token) {}

	std::string GenCppCode (size_t _indent) override { return std::format ("{}continue;\n", Indent (_indent)); }

	void GetChildTypes (std::function<void (PAstType &)> _cb) override {}

	void GetChildExprs (std::function<void (PAstExpr &)> _cb) override {}

	void GetChildStmts (std::function<void (PAstStmt &)> _cb) override {}

	static PAstStmt Make (antlr4::Token *_token) {
		return new AstStmt_continue { _token };
	}
};



#endif //__AST_STMT_CONTINUE_HPP__

#ifndef __AST_STMT_HPP__
#define __AST_STMT_HPP__



#include <memory>
#include <vector>

#include "../IAst.hpp"



struct IAstStmt;
struct PAstStmt: public std::shared_ptr<IAstStmt> {
	PAstStmt (IAstStmt *_stmt = nullptr): std::shared_ptr<IAstStmt> (_stmt) {}
};

struct IAstStmt: public IAst  {
	IAstStmt (antlr4::Token *_token): IAst (_token) {}

	static PAstStmt FromCtx (FaParser::NormalStmtContext *_ctx);
	static std::vector<PAstStmt> FromCtx (FaParser::StmtContext *_ctx);
	static std::vector<PAstStmt> FromCtx (std::vector<FaParser::StmtContext *> _ctxs);
	static std::vector<PAstStmt> FromCtx (FaParser::ClassItemFuncExtBodyContext *_ctx);
};



#endif //__AST_STMT_HPP__

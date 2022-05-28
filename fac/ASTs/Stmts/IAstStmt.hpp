#ifndef __AST_STMT_HPP__
#define __AST_STMT_HPP__



#include <memory>
#include <vector>

#include "../IAst.hpp"



struct IAstStmt: public IAst  {
	static std::shared_ptr<IAstStmt> FromCtx (FaParser::NormalStmtContext *_ctx);
	static std::shared_ptr<IAstStmt> FromCtx (FaParser::StmtContext *_ctx);
	static std::vector<std::shared_ptr<IAstStmt>> FromCtx (std::vector<FaParser::StmtContext *> _ctxs);
	static std::vector<std::shared_ptr<IAstStmt>> FromCtx (FaParser::ClassItemFuncExtBodyContext *_ctx);
};



#endif //__AST_STMT_HPP__

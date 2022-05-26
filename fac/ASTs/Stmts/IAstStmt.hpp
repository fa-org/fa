#ifndef __AST_STMT_HPP__
#define __AST_STMT_HPP__



#include <memory>
#include <vector>



struct IAstStmt {
	static std::shared_ptr<IAstStmt> FromCtx (FaParser::StmtContext *_ctx);
	static std::vector<std::shared_ptr<IAstStmt>> FromCtx (std::vector<FaParser::StmtContext *> _ctxs);
	static std::vector<std::shared_ptr<IAstStmt>> FromCtx (FaParser::ClassItemFuncExtBodyContext *_ctx);

protected:
	IAstStmt () {}
	IAstStmt (const IAstStmt &) = delete;
};



#endif //__AST_STMT_HPP__

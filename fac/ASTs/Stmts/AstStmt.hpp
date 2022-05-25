#ifndef __AST_STMT_HPP__
#define __AST_STMT_HPP__



#include <memory>
#include <vector>



struct AstStmt {
	static std::shared_ptr<AstStmt> FromCtx (FaParser::StmtContext *_ctx);
	static std::vector<std::shared_ptr<AstStmt>> FromCtx (std::vector<FaParser::StmtContext *> _ctxs);
	static std::vector<std::shared_ptr<AstStmt>> FromCtx (FaParser::ClassItemFuncExtBodyContext *_ctx);
};



#endif //__AST_STMT_HPP__

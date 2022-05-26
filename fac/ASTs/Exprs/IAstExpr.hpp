#ifndef __AST_EXPR_HPP__
#define __AST_EXPR_HPP__



#include <memory>
#include <vector>



struct IAstExpr {
	static std::shared_ptr<IAstExpr> FromCtx (FaParser::ExprContext *_ctx);

protected:
	IAstExpr () {}
	IAstExpr (const IAstExpr &) = delete;
};



#endif //__AST_EXPR_HPP__

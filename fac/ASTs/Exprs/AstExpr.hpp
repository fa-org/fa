#ifndef __AST_EXPR_HPP__
#define __AST_EXPR_HPP__



#include <memory>
#include <vector>



struct AstExpr {
	AstExpr () = delete;

	static std::shared_ptr<AstExpr> FromCtx (FaParser::ExprContext *_ctx);
};



#endif //__AST_EXPR_HPP__

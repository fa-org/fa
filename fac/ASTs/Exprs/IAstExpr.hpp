#ifndef __AST_EXPR_HPP__
#define __AST_EXPR_HPP__



#include <memory>
#include <vector>

#include "../IAst.hpp"
#include "../../Exception.hpp"



struct IAstExpr: public IAst {
	IAstExpr (antlr4::Token *_token): IAst (_token) {}

	static std::shared_ptr<IAstExpr> FromCtx (FaParser::StrongExprBaseContext *_ctx);
	static std::shared_ptr<IAstExpr> FromCtx (FaParser::StrongExprContext *_ctx);
	static std::shared_ptr<IAstExpr> FromCtx (FaParser::MiddleExprContext *_ctx);
	static std::shared_ptr<IAstExpr> FromCtx (FaParser::ExprContext *_ctx);
	static std::vector<std::shared_ptr<IAstExpr>> FromCtx (std::vector < FaParser::ExprContext *> _ctx);
	static std::shared_ptr<IAstExpr> FromCtx (FaParser::ExprOptContext *_ctx);
	static std::vector<std::shared_ptr<IAstExpr>> FromCtx (std::vector < FaParser::ExprOptContext *> _ctx);
	static std::shared_ptr<IAstExpr> FromCtx (FaParser::LiteralContext *_ctx);
};



#endif //__AST_EXPR_HPP__

#ifndef __AST_EXPR_HPP__
#define __AST_EXPR_HPP__



#include <memory>
#include <vector>

#include "../IAst.hpp"
#include "../Types/IAstType.hpp"
#include "../../Exception.hpp"



struct IAstExpr;
struct PAstExpr: public std::shared_ptr<IAstExpr> {
	PAstExpr (IAstExpr *_expr = nullptr): std::shared_ptr<IAstExpr> (_expr) {}
};

struct IAstExpr: public IAst {
	PAstType m_real_type;

	IAstExpr (antlr4::Token *_token): IAst (_token) {}

	virtual PAstType GuessType () = 0;
	virtual void ProcessCode (PAstType _type) = 0;

	static PAstExpr FromCtx (FaParser::StrongExprBaseContext *_ctx);
	static PAstExpr FromCtx (FaParser::StrongExprContext *_ctx);
	static PAstExpr FromCtx (FaParser::MiddleExprContext *_ctx);
	static PAstExpr FromCtx (FaParser::ExprContext *_ctx);
	static std::vector<PAstExpr> FromCtx (std::vector<FaParser::ExprContext *> _ctx);
	static PAstExpr FromCtx (FaParser::ExprOptContext *_ctx);
	static std::vector<PAstExpr> FromCtx (std::vector<FaParser::ExprOptContext *> _ctx);
	static PAstExpr FromCtx (FaParser::LiteralContext *_ctx);
};



#endif //__AST_EXPR_HPP__

#include "antlr_gen/FaParser.h"
#include "ASTs/Exprs/IAstExpr.hpp"
#include "ASTs/Stmts/IAstStmt.hpp"
#include "ASTs/Stmts/AstStmt_return.hpp"
#include "ASTs/Stmts/AstStmt_expr_wrap.hpp"
#include "ASTs/Stmts/AstStmt_break.hpp"
#include "ASTs/Stmts/AstStmt_continue.hpp"
#include "Exception.hpp"



std::shared_ptr<IAstStmt> IAstStmt::FromCtx (FaParser::NormalStmtContext *_ctx) {
	if (_ctx->Return ()) {
		return AstStmt_return::FromExpr (IAstExpr::FromCtx (_ctx->expr ()));
	} else if (_ctx->expr ()) {
		return AstStmt_expr_wrap::FromExpr (IAstExpr::FromCtx (_ctx->expr ()));
	} else if (_ctx->Break ()) {
		return std::make_shared<AstStmt_break> ();
	} else if (_ctx->Continue ()) {
		return std::make_shared<AstStmt_continue> ();
	}
	throw NOT_IMPLEMENT ();
}



std::shared_ptr<IAstStmt> IAstStmt::FromCtx (FaParser::StmtContext *_ctx) {
	if (_ctx->normalStmt ()) {
		return FromCtx (_ctx->normalStmt ());
	} else {
		throw NOT_IMPLEMENT ();
	}
}



std::vector<std::shared_ptr<IAstStmt>> IAstStmt::FromCtx (std::vector<FaParser::StmtContext *> _ctxs) {
	std::vector<std::shared_ptr<IAstStmt>> _v;
	for (auto _ctx : _ctxs)
		_v.push_back (FromCtx (_ctx));
	return _v;
}



std::vector<std::shared_ptr<IAstStmt>> IAstStmt::FromCtx (FaParser::ClassItemFuncExtBodyContext *_ctx) {
	if (_ctx->expr ()) {
		std::vector<std::shared_ptr<IAstStmt>> _v;
		_v.push_back (AstStmt_return::FromExpr (IAstExpr::FromCtx (_ctx->expr ())));
		return _v;
	} else {
		return FromCtx (_ctx->stmt ());
	}
}

#include "antlr_gen/FaParser.h"
#include "ASTs/Exprs/IAstExpr.hpp"
#include "ASTs/Stmts/IAstStmt.hpp"
#include "ASTs/Stmts/AstReturnStmt.hpp"
#include "Exception.hpp"



std::shared_ptr<IAstStmt> IAstStmt::FromCtx (FaParser::StmtContext *_ctx) {
	// TODO
	//throw Exception::NotImplement ();
	return std::shared_ptr<IAstStmt> (new IAstStmt ());
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
		_v.push_back (AstReturnStmt::FromExpr (IAstExpr::FromCtx (_ctx->expr ())));
		return _v;
	} else {
		return FromCtx (_ctx->stmt ());
	}
}

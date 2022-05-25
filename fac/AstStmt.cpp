#include "antlr_gen/FaParser.h"
#include "ASTs/Exprs/AstExpr.hpp"
#include "ASTs/Stmts/AstStmt.hpp"
#include "ASTs/Stmts/AstReturnStmt.hpp"



std::vector<std::shared_ptr<AstStmt>> AstStmt::FromCtx (FaParser::ClassItemFuncExtBodyContext *_ctx) {
	// TODO
	if (_ctx->expr ()) {
		std::vector<std::shared_ptr<AstStmt>> _v;
		_v.push_back (std::shared_ptr<AstStmt> (new AstReturnStmt (AstExpr::FromCtx (_ctx->expr ()))));
		return _v;
	} else {

	}
}

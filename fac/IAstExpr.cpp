#include "antlr_gen/FaParser.h"
#include "ASTs/Exprs/IAstExpr.hpp"
#include "Exception.hpp"



std::shared_ptr<IAstExpr> IAstExpr::FromCtx (FaParser::ExprContext *_ctx) {
	// TODO
	throw Exception::NotImplement ();
}

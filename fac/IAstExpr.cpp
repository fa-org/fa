#include "antlr_gen/FaParser.h"
#include "ASTs/Exprs/IAstExpr.hpp"
#include "ASTs/Exprs/AstExpr_invoke.hpp"
#include "ASTs/Exprs/AstExpr_op1.hpp"
#include "ASTs/Exprs/AstExpr_op2.hpp"
#include "Exception.hpp"



std::shared_ptr<IAstExpr> IAstExpr::FromCtx (FaParser::StrongExprBaseContext *_ctx) {

}



std::shared_ptr<IAstExpr> IAstExpr::FromCtx (FaParser::StrongExprContext *_ctx) {
	auto _ret = FromCtx (_ctx->strongExprBase ());
	for (auto _suffix : _ctx->strongExprSuffix ()) {
		if (_suffix->AddAddOp () || _suffix->SubSubOp ()) {
			_ret = AstExpr_op1::Make (_suffix->start, _ret, _suffix->getText (), false);
		} else if (_suffix->quotYuanL ()) {
			AstExpr_invoke::Make (_suffix->start, _ret, FromCtx (_suffix->expr ()));
		} else if (_suffix->quotFangL ()) {

		}
	}
	auto _prefixs = _ctx->strongExprPrefix ();
	for (auto _pprefix = _prefixs.crbegin (); _pprefix != _prefixs.crend (); ++_pprefix) {
		auto _prefix = *_pprefix;
		_ret = AstExpr_op1::Make (_prefix->start, _ret, _prefix->getText (), false);
	}
}



std::shared_ptr<IAstExpr> IAstExpr::FromCtx (FaParser::MiddleExprContext *_ctx) {
	if (!_ctx)
		return nullptr;
	auto _middles = _ctx->strongExpr ();
	auto _ops = _ctx->allOp2 ();
	auto _ret = FromCtx (_middles [_middles.size () - 1]);
	for (size_t i = _middles.size () - 2; i != std::string::npos; --i)
		_ret = AstExpr_op2::Make (_ops [i]->start, FromCtx (_middles [i]), _ops [i]->getText (), _ret);
	return _ret;
}



std::shared_ptr<IAstExpr> IAstExpr::FromCtx (FaParser::ExprContext *_ctx) {
	if (!_ctx)
		return nullptr;
	auto _middles = _ctx->middleExpr ();
	auto _ops = _ctx->allAssign ();
	auto _ret = FromCtx (_middles [_middles.size () - 1]);
	for (size_t i = _middles.size () - 2; i != std::string::npos; --i)
		_ret = AstExpr_op2::Make (_ops [i]->start, FromCtx (_middles [i]), _ops [i]->getText (), _ret);
	return _ret;
}



std::vector<std::shared_ptr<IAstExpr>> IAstExpr::FromCtx (std::vector<FaParser::ExprContext *> _ctx) {
	std::vector<std::shared_ptr<IAstExpr>> _v;
	for (auto _item : _ctx)
		_v.push_back (FromCtx (_item));
	return _v;
}

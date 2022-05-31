#include "antlr_gen/FaParser.h"
#include "ASTs/Exprs/IAstExpr.hpp"
#include "ASTs/Exprs/AstExpr_invoke.hpp"
#include "ASTs/Exprs/AstExpr_op1.hpp"
#include "ASTs/Exprs/AstExpr_op2.hpp"
#include "ASTs/Exprs/AstExpr_temp_id.hpp"
#include "ASTs/Exprs/AstExpr_value.hpp"
#include "ASTs/Types/AstType_bool.hpp"
#include "ASTs/Types/AstType_float.hpp"
#include "ASTs/Types/AstType_int.hpp"
#include "ASTs/Types/AstType_string.hpp"
#include "Exception.hpp"



std::shared_ptr<IAstExpr> IAstExpr::FromCtx (FaParser::StrongExprBaseContext *_ctx) {
	if (_ctx->ids ()) {
		return AstExpr_temp_id::Make (_ctx->start, _ctx->getText ());
	} else if (_ctx->literal ()) {
		return AstExpr_value::FromCtx (_ctx->literal ());
	} else if (_ctx->quotExpr ()) {
		return FromCtx (_ctx->quotExpr ()->expr ());
	}
	throw NOT_IMPLEMENT ();
}



std::shared_ptr<IAstExpr> IAstExpr::FromCtx (FaParser::StrongExprContext *_ctx) {
	auto _ret = FromCtx (_ctx->strongExprBase ());
	for (auto _suffix : _ctx->strongExprSuffix ()) {
		if (_suffix->AddAddOp () || _suffix->SubSubOp ()) {
			_ret = AstExpr_op1::Make (_suffix->start, _ret, _suffix->getText (), false);
		} else if (_suffix->quotYuanL ()) {
			_ret = AstExpr_invoke::Make (_suffix->start, _ret, FromCtx (_suffix->expr ()), "()");
		} else if (_suffix->quotFangL ()) {
			_ret = AstExpr_invoke::Make (_suffix->start, _ret, FromCtx (_suffix->exprOpt ()), "[]");
		} else if (_suffix->PointOp ()) {
			_ret = AstExpr_op2::Make (_suffix->start, _ret, ".", AstExpr_temp_id::Make (_suffix->id ()->start, _suffix->id ()->getText ()));
		} else {
			throw NOT_IMPLEMENT ();
		}
	}
	auto _prefixs = _ctx->strongExprPrefix ();
	for (auto _pprefix = _prefixs.crbegin (); _pprefix != _prefixs.crend (); ++_pprefix) {
		auto _prefix = *_pprefix;
		_ret = AstExpr_op1::Make (_prefix->start, _ret, _prefix->getText (), false);
	}
	return _ret;
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



std::shared_ptr<IAstExpr> IAstExpr::FromCtx (FaParser::ExprOptContext *_ctx) {
	if (!_ctx)
		return nullptr;
	return FromCtx (_ctx->expr ());
}



std::vector<std::shared_ptr<IAstExpr>> IAstExpr::FromCtx (std::vector < FaParser::ExprOptContext *> _ctx) {
	std::vector<std::shared_ptr<IAstExpr>> _v;
	for (auto _item : _ctx)
		_v.push_back (FromCtx (_item));
	return _v;
}



std::shared_ptr<IAstExpr> IAstExpr::FromCtx (FaParser::LiteralContext *_ctx) {
	if (_ctx->BoolLiteral ()) {
		return AstExpr_value::Make (_ctx->start, AstType_bool::Make (_ctx->start), _ctx->getText ());
	} else if (_ctx->intNum ()) {
		return AstExpr_value::Make (_ctx->start, AstType_int::Make (_ctx->start, 64, true), _ctx->getText ());
	} else if (_ctx->floatNum ()) {
		return AstExpr_value::Make (_ctx->start, AstType_float::Make (_ctx->start, 64), _ctx->getText ());
	} else if (_ctx->String1Literal ()) {
		return AstExpr_value::Make (_ctx->start, AstType_string::Make (_ctx->start), _ctx->getText ());
	}
	throw NOT_IMPLEMENT ();
}

#include "antlr_gen/FaParser.h"
#include "ASTs/Types/IAstType.hpp"
#include "ASTs/Exprs/IAstExpr.hpp"
#include "ASTs/Stmts/IAstStmt.hpp"
#include "ASTs/Stmts/AstStmt_break.hpp"
#include "ASTs/Stmts/AstStmt_continue.hpp"
#include "ASTs/Stmts/AstStmt_define_var.hpp"
#include "ASTs/Stmts/AstStmt_expr_wrap.hpp"
#include "ASTs/Stmts/AstStmt_return.hpp"
#include "Exception.hpp"



PAstStmt IAstStmt::FromCtx (FaParser::NormalStmtContext *_ctx) {
	if (_ctx->Return ()) {
		return AstStmt_return::FromExpr (_ctx->start, IAstExpr::FromCtx (_ctx->expr ()));
	} else if (_ctx->expr ()) {
		return AstStmt_expr_wrap::FromExpr (_ctx->start, IAstExpr::FromCtx (_ctx->expr ()));
	} else if (_ctx->Break ()) {
		return AstStmt_break::Make (_ctx->start);
	} else if (_ctx->Continue ()) {
		return AstStmt_continue::Make (_ctx->start);
	}
	throw NOT_IMPLEMENT ();
}



std::vector<PAstStmt> IAstStmt::FromCtx (FaParser::StmtContext *_ctx) {
	std::vector<PAstStmt> _v;
	if (_ctx->defVarStmt ()) {
		for (auto _item : _ctx->defVarStmt ()->idAssignExpr ()) {
			auto _type = IAstType::FromCtx (_item->type ());
			std::string _name = _item->id ()->getText ();
			auto _expr = IAstExpr::FromCtx (_item->expr ());
			_v.push_back (AstStmt_define_var::Make (_item->Assign ()->getSymbol (), _type, _name, _expr));
		}
		return _v;
	} else if (_ctx->defVarStmt2 ()) {
		auto _type = IAstType::FromCtx (_ctx->defVarStmt2 ()->type ());
		for (auto _item : _ctx->defVarStmt2 ()->idAssignExpr2 ()) {
			std::string _name = _item->id ()->getText ();
			auto _expr = IAstExpr::FromCtx (_item->expr ());
			_v.push_back (AstStmt_define_var::Make (_item->Assign ()->getSymbol (), _type, _name, _expr));
		}
		return _v;
	} else if (_ctx->normalStmt ()) {
		_v.push_back (FromCtx (_ctx->normalStmt ()));
		return _v;
	} else {
	}
	throw NOT_IMPLEMENT ();
}



std::vector<PAstStmt> IAstStmt::FromCtx (std::vector<FaParser::StmtContext *> _ctxs) {
	std::vector<PAstStmt> _v;
	for (auto _ctx : _ctxs) {
		auto _v2 = FromCtx (_ctx);
		_v.insert (_v.end (), _v2.begin (), _v2.end ());
	}
	return _v;
}



std::vector<PAstStmt> IAstStmt::FromCtx (FaParser::ClassItemFuncExtBodyContext *_ctx) {
	if (_ctx->expr ()) {
		std::vector<PAstStmt> _v;
		_v.push_back (AstStmt_return::FromExpr (_ctx->start, IAstExpr::FromCtx (_ctx->expr ())));
		return _v;
	} else {
		return FromCtx (_ctx->stmt ());
	}
}

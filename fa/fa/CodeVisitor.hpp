#ifndef __CODE_VISITOR_HPP__
#define __CODE_VISITOR_HPP__



#include <tuple>

#include "FaBaseVisitor.h"



class CodeVisitor: public FaBaseVisitor {
public:
	antlrcpp::Any visitIds (FaParser::IdsContext *ctx) override {
		return ctx->getText ();
	}

	antlrcpp::Any visitUseStmt (FaParser::UseStmtContext *ctx) override {
		return visitIds (ctx->ids ());
	}

	antlrcpp::Any visitFaEntryMainFuncStmt (FaParser::FaEntryMainFuncStmtContext *ctx) override {
		return visitChildren (ctx);
	}

	antlrcpp::Any visitProgram (FaParser::ProgramContext *ctx) override {
		std::vector<std::string> _uses;
		for (auto _use_expr : ctx->useStmt ())
			_uses.push_back (visitUseStmt (_use_expr));
		std::vector<ExternStmtContext*> _externs = ctx->externStmt ();
		std::vector<ClassStmtContext*> _classes = ctx->classStmt ();
		auto _entry = dynamic_cast<FaParser::FaEntryMainFuncStmtContext*> (ctx->faEntryMainFuncStmt ());
		return std::make_tuple (_uses, _externs, _classes, _entry);
	}
};



#endif //__CODE_VISITOR_HPP__

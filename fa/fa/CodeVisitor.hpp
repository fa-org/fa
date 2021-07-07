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

	antlrcpp::Any visitImportBlock (FaParser::ImportBlockContext *ctx) override {
		std::vector<std::string> _imports, _libs;
		for (auto _import_item : ctx->importStmt ())
			_imports.push_back (_import_item->Id ()->getText ());
		for (auto _lib_item : ctx->libStmt ()) {
			std::string _tmp = _lib_item->String1Literal ()->getText ();
			_libs.push_back (_tmp.substr (1, _tmp.size () - 2));
		}
		return std::make_tuple (_imports, _libs);
	}

	antlrcpp::Any visitFaEntryMainFuncBlock (FaParser::FaEntryMainFuncBlockContext *ctx) override {
		// TODO
		return visitChildren (ctx);
	}

	antlrcpp::Any visitProgram (FaParser::ProgramContext *ctx) override {
		std::vector<std::string> _uses;
		for (auto _use_expr : ctx->useStmt ())
			_uses.push_back (visitUseStmt (_use_expr));
		FaParser::ImportBlockContext *_imports = ctx->importBlock ();
		std::vector<FaParser::ClassBlockContext *> _classes = ctx->classBlock ();
		auto _entry = dynamic_cast<FaParser::FaEntryMainFuncBlockContext *> (ctx->faEntryMainFuncBlock ());
		return std::make_tuple (_uses, _imports, _classes, _entry);
	}
};



#endif //__CODE_VISITOR_HPP__

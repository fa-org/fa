#ifndef __CODE_VISITOR_HPP__
#define __CODE_VISITOR_HPP__



#include <string>
#include <tuple>
#include <vector>

#include "FaBaseVisitor.h"



class CodeVisitor: public FaBaseVisitor {
public:
	antlrcpp::Any visitIds (FaParser::IdsContext *ctx) override {
		return ctx->getText ();
	}

	antlrcpp::Any visitUseStmt (FaParser::UseStmtContext *ctx) override {
		return visitIds (ctx->ids ());
	}

	antlrcpp::Any visitImportStmt (FaParser::ImportStmtContext *ctx) override {
		std::string _name = ctx->Id ()->getText ();
		FaParser::ETypeContext *_ret_type_raw = ctx->eType ();
		std::vector<FaParser::ETypeVarContext *> _arg_types_raw_tmp = ctx->eTypeVarList ()->eTypeVar ();
		std::vector<FaParser::ETypeContext *> _arg_types_raw;
		for (size_t i = 0; i < _arg_types_raw_tmp.size (); ++i)
			_arg_types_raw.push_back (_arg_types_raw_tmp[i]->eType ());
		std::string _cc = ctx->callConvention ()->getText ();
		return std::make_tuple (_name, _ret_type_raw, _arg_types_raw, _cc);
	}

	antlrcpp::Any visitEType (FaParser::ETypeContext *ctx) override {
		auto _psign = ctx->eSign ();
		bool _sign = _psign != nullptr ? (_psign->getText () == "signed") : true;
		std::string _name = ctx->Id ()->getText ();
		size_t _ptr_level = ctx->eTypeAfter ().size ();
		return std::make_tuple (_sign, _name, _ptr_level);
	}

	antlrcpp::Any visitImportBlock (FaParser::ImportBlockContext *ctx) override {
		std::vector<FaParser::ImportStmtContext *> _imports;
		std::vector<std::string> _libs;
		for (auto _import_item : ctx->importStmt ())
			_imports.push_back (_import_item);
		for (auto _lib_item : ctx->libStmt ()) {
			std::string _tmp = _lib_item->String1Literal ()->getText ();
			_libs.push_back (_tmp.substr (1, _tmp.size () - 2));
		}
		return std::make_tuple (_imports, _libs);
	}

	antlrcpp::Any visitFaEntryMainFuncBlock (FaParser::FaEntryMainFuncBlockContext *ctx) override {
		FaParser::TypeContext *_ret_type_raw = ctx->type ();
		std::vector<FaParser::StmtContext *> _stmts_raw = ctx->stmt ();
		return std::make_tuple (_ret_type_raw, _stmts_raw);
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

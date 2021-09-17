#ifndef __CODE_VISITOR_HPP__
#define __CODE_VISITOR_HPP__



#include <string>
#include <tuple>
#include <vector>

#include "FaBaseVisitor.h"
#include "AstClass.hpp"



class CodeVisitor: public FaBaseVisitor {
public:
	antlrcpp::Any visitIds (FaParser::IdsContext* ctx) override {
		return ctx->getText ();
	}

	antlrcpp::Any visitUseStmt (FaParser::UseStmtContext* ctx) override {
		return visitIds (ctx->ids ());
	}

	antlrcpp::Any visitImportStmt (FaParser::ImportStmtContext* ctx) override {
		std::string _name = ctx->Id ()->getText ();
		FaParser::TypeContext* _ret_type_raw = ctx->type ();
		std::vector<FaParser::TypeVarContext*> _arg_types_raw_tmp = ctx->typeVarList ()->typeVar ();
		std::vector<FaParser::TypeContext*> _arg_types_raw;
		for (size_t i = 0; i < _arg_types_raw_tmp.size (); ++i)
			_arg_types_raw.push_back (_arg_types_raw_tmp[i]->type ());
		std::string _cc = ctx->callConvention ()->getText ();
		return std::make_tuple (_name, _ret_type_raw, _arg_types_raw, _cc);
	}

	//antlrcpp::Any visitEType (FaParser::ETypeContext* ctx) override {
	//	auto _psign = ctx->eSign ();
	//	bool _sign = _psign != nullptr ? (_psign->getText () == "signed") : true;
	//	std::string _name = ctx->Id ()->getText ();
	//	size_t _ptr_level = ctx->eTypeAfter ().size ();
	//	return std::make_tuple (_sign, _name, _ptr_level);
	//}

	antlrcpp::Any visitIfStmt (FaParser::IfStmtContext* ctx) override {
		std::vector<std::vector<FaParser::StmtContext*>> _bodys;
		for (auto _body_part_raw : ctx->quotStmtPart ())
			_bodys.push_back (_body_part_raw->stmt ());
		return std::make_tuple (ctx->expr (), _bodys);
	}

	antlrcpp::Any visitIfExpr (FaParser::IfExprContext* ctx) override {
		std::vector<std::vector<FaParser::StmtContext*>> _bodys1;
		std::vector<FaParser::ExprContext*> _bodys2;
		for (auto _body_part_raw : ctx->quotStmtExpr ()) {
			_bodys1.push_back (_body_part_raw->stmt ());
			_bodys2.push_back (_body_part_raw->expr ());
		}
		return std::make_tuple (ctx->expr (), _bodys1, _bodys2);
	}

	antlrcpp::Any visitImportBlock (FaParser::ImportBlockContext* ctx) override {
		std::vector<FaParser::ImportStmtContext*> _imports;
		std::vector<std::string> _libs;
		for (auto _import_item : ctx->importStmt ())
			_imports.push_back (_import_item);
		for (auto _lib_item : ctx->libStmt ()) {
			std::string _tmp = _lib_item->String1Literal ()->getText ();
			_libs.push_back (_tmp.substr (1, _tmp.size () - 2));
		}
		return std::make_tuple (_imports, _libs);
	}

	antlrcpp::Any visitFaMainFuncBlock (FaParser::FaMainFuncBlockContext* ctx) override {
		FaParser::TypeContext* _ret_type_raw = ctx->type ();
		std::vector<FaParser::StmtContext*> _stmts_raw = ctx->stmt ();
		return std::make_tuple (_ret_type_raw, _stmts_raw);
	}

	antlrcpp::Any visitProgram (FaParser::ProgramContext* ctx) override {
		std::vector<std::string> _uses;
		for (auto _use_expr : ctx->useStmt ())
			_uses.push_back (visitUseStmt (_use_expr));
		FaParser::ImportBlockContext* _imports = ctx->importBlock ();
		std::vector<FaParser::ClassStmtContext*> _classes = ctx->classStmt ();
		auto _entry = dynamic_cast<FaParser::FaMainFuncBlockContext*> (ctx->faMainFuncBlock ());
		return std::make_tuple (_uses, _imports, _classes, _entry);
	}

	antlrcpp::Any visitPublicLevel (FaParser::PublicLevelContext* context) override {
		if (context->Public ()) {
			return PublicLevel::Public;
		} else if (context->Internal ()) {
			return PublicLevel::Internal;
		} else if (context->Protected ()) {
			return PublicLevel::Protected;
		} else if (context->Private ()) {
			return PublicLevel::Private;
		} else {
			return PublicLevel::Unknown;
		}
	}

	antlrcpp::Any visitClassParent (FaParser::ClassParentContext* context) override {
		std::vector<std::string> _ids;
		for (auto _parent_name_raw : context->ids ())
			_ids.push_back (_parent_name_raw->getText ());
		return _ids;
	}
};



#endif //__CODE_VISITOR_HPP__

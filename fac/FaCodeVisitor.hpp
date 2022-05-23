#ifndef __FA_CODE_VISITOR_HPP__
#define __FA_CODE_VISITOR_HPP__



#include <string>
#include <tuple>
#include <vector>

#include "antlr_gen/FaBaseVisitor.h"



struct FaCodeVisitor: public FaBaseVisitor {
	antlrcpp::Any visitProgram (FaParser::ProgramContext *ctx) override {
		std::vector<std::tuple<std::string, std::string>> _uses;
		for (auto _use_stmt : ctx->useStmt ())
			_uses.push_back ({ _use_stmt->Id () ? _use_stmt->Id ()->getText () : "", _use_stmt->ids ()->getText () });
		std::string _namespace = ctx->namespaceStmt ()->getText ();
		return std::make_tuple (_uses, _namespace);
	}
};



#endif //__FA_CODE_VISITOR_HPP__

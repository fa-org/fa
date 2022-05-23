#ifndef __FA_CODE_VISITOR_HPP__
#define __FA_CODE_VISITOR_HPP__



#include "antlr_gen/FaBaseVisitor.h"



struct FaCodeVisitor: public FaBaseVisitor {
	antlrcpp::Any visitProgram (FaParser::ProgramContext *ctx) override {
		std::vector<std::string> _uses;
		//return visitChildren (ctx);
	}
};



#endif //__FA_CODE_VISITOR_HPP__

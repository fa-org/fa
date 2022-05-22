#ifndef __FA_CODE_VISITOR_HPP__
#define __FA_CODE_VISITOR_HPP__



#include "antlr_gen/FaBaseVisitor.h"



struct FaCodeVisitor: public FaBaseVisitor {
	antlrcpp::Any visitProgram (FaParser::ProgramContext *ctx) override {
		return visitChildren (ctx);
	}
};



#endif //__FA_CODE_VISITOR_HPP__

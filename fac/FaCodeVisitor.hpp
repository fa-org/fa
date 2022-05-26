#ifndef __FA_CODE_VISITOR_HPP__
#define __FA_CODE_VISITOR_HPP__



#include <memory>
#include <string>
#include <tuple>
#include <vector>

#include "antlr_gen/FaBaseVisitor.h"
#include "ASTs/Blocks/AstProgram.hpp"



struct FaCodeVisitor: public FaBaseVisitor {
	antlrcpp::Any visitProgramEntry (FaParser::ProgramEntryContext *_ctx) override {
		return AstProgram::FromCtx (_ctx->program ());
	}
};



#endif //__FA_CODE_VISITOR_HPP__

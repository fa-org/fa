#ifndef __FA_CODE_VISITOR_HPP__
#define __FA_CODE_VISITOR_HPP__



#include <memory>
#include <string>
#include <tuple>
#include <vector>

#include "antlr_gen/FaBaseVisitor.h"
#include "ASTs/Blocks/AstProgram.hpp"



struct FaCodeVisitor: public FaBaseVisitor {
	antlrcpp::Any visitProgram (FaParser::ProgramContext *ctx) override {
		return std::make_shared<AstProgram> (ctx);
	}
};



#endif //__FA_CODE_VISITOR_HPP__


// Generated from Fa.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "FaParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by FaParser.
 */
class  FaVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by FaParser.
   */
    virtual antlrcpp::Any visitUseExpr(FaParser::UseExprContext *context) = 0;

    virtual antlrcpp::Any visitProgram(FaParser::ProgramContext *context) = 0;


};


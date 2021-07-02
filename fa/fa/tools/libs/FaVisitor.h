
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
    virtual antlrcpp::Any visitIds(FaParser::IdsContext *context) = 0;

    virtual antlrcpp::Any visitTypeAfter(FaParser::TypeAfterContext *context) = 0;

    virtual antlrcpp::Any visitTypeExpr(FaParser::TypeExprContext *context) = 0;

    virtual antlrcpp::Any visitUseStmt(FaParser::UseStmtContext *context) = 0;

    virtual antlrcpp::Any visitReturnStmt(FaParser::ReturnStmtContext *context) = 0;

    virtual antlrcpp::Any visitClassParent(FaParser::ClassParentContext *context) = 0;

    virtual antlrcpp::Any visitTypeVar(FaParser::TypeVarContext *context) = 0;

    virtual antlrcpp::Any visitTypeVarList(FaParser::TypeVarListContext *context) = 0;

    virtual antlrcpp::Any visitClassItemExpr(FaParser::ClassItemExprContext *context) = 0;

    virtual antlrcpp::Any visitClassItemFieldStmt(FaParser::ClassItemFieldStmtContext *context) = 0;

    virtual antlrcpp::Any visitClassItemFuncStmt(FaParser::ClassItemFuncStmtContext *context) = 0;

    virtual antlrcpp::Any visitClassStmt(FaParser::ClassStmtContext *context) = 0;

    virtual antlrcpp::Any visitProgram(FaParser::ProgramContext *context) = 0;


};


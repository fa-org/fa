
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
    virtual antlrcpp::Any visitShiftLOp(FaParser::ShiftLOpContext *context) = 0;

    virtual antlrcpp::Any visitShiftROp(FaParser::ShiftROpContext *context) = 0;

    virtual antlrcpp::Any visitLiteral(FaParser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitIds(FaParser::IdsContext *context) = 0;

    virtual antlrcpp::Any visitTypeAfter(FaParser::TypeAfterContext *context) = 0;

    virtual antlrcpp::Any visitType(FaParser::TypeContext *context) = 0;

    virtual antlrcpp::Any visitETypeAfter(FaParser::ETypeAfterContext *context) = 0;

    virtual antlrcpp::Any visitESign(FaParser::ESignContext *context) = 0;

    virtual antlrcpp::Any visitEType(FaParser::ETypeContext *context) = 0;

    virtual antlrcpp::Any visitTypeVar(FaParser::TypeVarContext *context) = 0;

    virtual antlrcpp::Any visitTypeVarList(FaParser::TypeVarListContext *context) = 0;

    virtual antlrcpp::Any visitETypeVar(FaParser::ETypeVarContext *context) = 0;

    virtual antlrcpp::Any visitETypeVarList(FaParser::ETypeVarListContext *context) = 0;

    virtual antlrcpp::Any visitIfPart(FaParser::IfPartContext *context) = 0;

    virtual antlrcpp::Any visitStmtOrExpr(FaParser::StmtOrExprContext *context) = 0;

    virtual antlrcpp::Any visitQuotStmtPart(FaParser::QuotStmtPartContext *context) = 0;

    virtual antlrcpp::Any visitQuotStmtExpr(FaParser::QuotStmtExprContext *context) = 0;

    virtual antlrcpp::Any visitIfStmt(FaParser::IfStmtContext *context) = 0;

    virtual antlrcpp::Any visitIfExpr(FaParser::IfExprContext *context) = 0;

    virtual antlrcpp::Any visitWhileStmtPart(FaParser::WhileStmtPartContext *context) = 0;

    virtual antlrcpp::Any visitWhileStmt(FaParser::WhileStmtContext *context) = 0;

    virtual antlrcpp::Any visitAllAssign(FaParser::AllAssignContext *context) = 0;

    virtual antlrcpp::Any visitAllOp(FaParser::AllOpContext *context) = 0;

    virtual antlrcpp::Any visitQuotExpr(FaParser::QuotExprContext *context) = 0;

    virtual antlrcpp::Any visitExprPrefix(FaParser::ExprPrefixContext *context) = 0;

    virtual antlrcpp::Any visitExprBody(FaParser::ExprBodyContext *context) = 0;

    virtual antlrcpp::Any visitExprSuffix(FaParser::ExprSuffixContext *context) = 0;

    virtual antlrcpp::Any visitNormalExpr(FaParser::NormalExprContext *context) = 0;

    virtual antlrcpp::Any visitExpr(FaParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitUseStmt(FaParser::UseStmtContext *context) = 0;

    virtual antlrcpp::Any visitNormalStmt(FaParser::NormalStmtContext *context) = 0;

    virtual antlrcpp::Any visitStmt(FaParser::StmtContext *context) = 0;

    virtual antlrcpp::Any visitPublicLevel(FaParser::PublicLevelContext *context) = 0;

    virtual antlrcpp::Any visitClassParent(FaParser::ClassParentContext *context) = 0;

    virtual antlrcpp::Any visitClassItemPart(FaParser::ClassItemPartContext *context) = 0;

    virtual antlrcpp::Any visitClassItemFieldBlock(FaParser::ClassItemFieldBlockContext *context) = 0;

    virtual antlrcpp::Any visitClassItemFuncBlock(FaParser::ClassItemFuncBlockContext *context) = 0;

    virtual antlrcpp::Any visitClassBlock(FaParser::ClassBlockContext *context) = 0;

    virtual antlrcpp::Any visitCallConvention(FaParser::CallConventionContext *context) = 0;

    virtual antlrcpp::Any visitImportStmt(FaParser::ImportStmtContext *context) = 0;

    virtual antlrcpp::Any visitLibStmt(FaParser::LibStmtContext *context) = 0;

    virtual antlrcpp::Any visitImportBlock(FaParser::ImportBlockContext *context) = 0;

    virtual antlrcpp::Any visitFaEntryMainFuncBlock(FaParser::FaEntryMainFuncBlockContext *context) = 0;

    virtual antlrcpp::Any visitProgram(FaParser::ProgramContext *context) = 0;


};


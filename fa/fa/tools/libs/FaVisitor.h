
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
    virtual antlrcpp::Any visitAddAssign(FaParser::AddAssignContext *context) = 0;

    virtual antlrcpp::Any visitSubAssign(FaParser::SubAssignContext *context) = 0;

    virtual antlrcpp::Any visitStarAssign(FaParser::StarAssignContext *context) = 0;

    virtual antlrcpp::Any visitDivAssign(FaParser::DivAssignContext *context) = 0;

    virtual antlrcpp::Any visitModAssign(FaParser::ModAssignContext *context) = 0;

    virtual antlrcpp::Any visitOrAssign(FaParser::OrAssignContext *context) = 0;

    virtual antlrcpp::Any visitAndAssign(FaParser::AndAssignContext *context) = 0;

    virtual antlrcpp::Any visitXorAssign(FaParser::XorAssignContext *context) = 0;

    virtual antlrcpp::Any visitQusQusAssign(FaParser::QusQusAssignContext *context) = 0;

    virtual antlrcpp::Any visitStarStarAssign(FaParser::StarStarAssignContext *context) = 0;

    virtual antlrcpp::Any visitAndAndAssign(FaParser::AndAndAssignContext *context) = 0;

    virtual antlrcpp::Any visitOrOrAssign(FaParser::OrOrAssignContext *context) = 0;

    virtual antlrcpp::Any visitShiftLAssign(FaParser::ShiftLAssignContext *context) = 0;

    virtual antlrcpp::Any visitShiftRAssign(FaParser::ShiftRAssignContext *context) = 0;

    virtual antlrcpp::Any visitAllAssign(FaParser::AllAssignContext *context) = 0;

    virtual antlrcpp::Any visitQusQusOp(FaParser::QusQusOpContext *context) = 0;

    virtual antlrcpp::Any visitStarStarOp(FaParser::StarStarOpContext *context) = 0;

    virtual antlrcpp::Any visitAndAndOp(FaParser::AndAndOpContext *context) = 0;

    virtual antlrcpp::Any visitOrOrOp(FaParser::OrOrOpContext *context) = 0;

    virtual antlrcpp::Any visitShiftLOp(FaParser::ShiftLOpContext *context) = 0;

    virtual antlrcpp::Any visitShiftROp(FaParser::ShiftROpContext *context) = 0;

    virtual antlrcpp::Any visitLtOp(FaParser::LtOpContext *context) = 0;

    virtual antlrcpp::Any visitLtEqualOp(FaParser::LtEqualOpContext *context) = 0;

    virtual antlrcpp::Any visitGtOp(FaParser::GtOpContext *context) = 0;

    virtual antlrcpp::Any visitGtEqualOp(FaParser::GtEqualOpContext *context) = 0;

    virtual antlrcpp::Any visitEqualOp(FaParser::EqualOpContext *context) = 0;

    virtual antlrcpp::Any visitNotEqualOp(FaParser::NotEqualOpContext *context) = 0;

    virtual antlrcpp::Any visitExprFuncDef(FaParser::ExprFuncDefContext *context) = 0;

    virtual antlrcpp::Any visitSelfOp2(FaParser::SelfOp2Context *context) = 0;

    virtual antlrcpp::Any visitCompareOp2(FaParser::CompareOp2Context *context) = 0;

    virtual antlrcpp::Any visitChangeOp2(FaParser::ChangeOp2Context *context) = 0;

    virtual antlrcpp::Any visitAllOp2(FaParser::AllOp2Context *context) = 0;

    virtual antlrcpp::Any visitLiteral(FaParser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitIds(FaParser::IdsContext *context) = 0;

    virtual antlrcpp::Any visitTypeAfter(FaParser::TypeAfterContext *context) = 0;

    virtual antlrcpp::Any visitType(FaParser::TypeContext *context) = 0;

    virtual antlrcpp::Any visitTypeNewable(FaParser::TypeNewableContext *context) = 0;

    virtual antlrcpp::Any visitTypeVar(FaParser::TypeVarContext *context) = 0;

    virtual antlrcpp::Any visitTypeVarList(FaParser::TypeVarListContext *context) = 0;

    virtual antlrcpp::Any visitQuotStmtPart(FaParser::QuotStmtPartContext *context) = 0;

    virtual antlrcpp::Any visitQuotStmtExpr(FaParser::QuotStmtExprContext *context) = 0;

    virtual antlrcpp::Any visitIfStmt(FaParser::IfStmtContext *context) = 0;

    virtual antlrcpp::Any visitIfExpr(FaParser::IfExprContext *context) = 0;

    virtual antlrcpp::Any visitWhileStmt(FaParser::WhileStmtContext *context) = 0;

    virtual antlrcpp::Any visitQuotExpr(FaParser::QuotExprContext *context) = 0;

    virtual antlrcpp::Any visitExprOpt(FaParser::ExprOptContext *context) = 0;

    virtual antlrcpp::Any visitNewExprItem(FaParser::NewExprItemContext *context) = 0;

    virtual antlrcpp::Any visitNewExpr(FaParser::NewExprContext *context) = 0;

    virtual antlrcpp::Any visitStrongExprBase(FaParser::StrongExprBaseContext *context) = 0;

    virtual antlrcpp::Any visitStrongExprPrefix(FaParser::StrongExprPrefixContext *context) = 0;

    virtual antlrcpp::Any visitStrongExprSuffix(FaParser::StrongExprSuffixContext *context) = 0;

    virtual antlrcpp::Any visitStrongExpr(FaParser::StrongExprContext *context) = 0;

    virtual antlrcpp::Any visitMiddleExpr(FaParser::MiddleExprContext *context) = 0;

    virtual antlrcpp::Any visitExpr(FaParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitTmpAssignExpr(FaParser::TmpAssignExprContext *context) = 0;

    virtual antlrcpp::Any visitDefVarStmt(FaParser::DefVarStmtContext *context) = 0;

    virtual antlrcpp::Any visitUseStmt(FaParser::UseStmtContext *context) = 0;

    virtual antlrcpp::Any visitNormalStmt(FaParser::NormalStmtContext *context) = 0;

    virtual antlrcpp::Any visitStmt(FaParser::StmtContext *context) = 0;

    virtual antlrcpp::Any visitPublicLevel(FaParser::PublicLevelContext *context) = 0;

    virtual antlrcpp::Any visitClassParent(FaParser::ClassParentContext *context) = 0;

    virtual antlrcpp::Any visitClassStmt(FaParser::ClassStmtContext *context) = 0;

    virtual antlrcpp::Any visitClassVarExtFunc(FaParser::ClassVarExtFuncContext *context) = 0;

    virtual antlrcpp::Any visitClassVarExt(FaParser::ClassVarExtContext *context) = 0;

    virtual antlrcpp::Any visitClassVar(FaParser::ClassVarContext *context) = 0;

    virtual antlrcpp::Any visitClassFuncName(FaParser::ClassFuncNameContext *context) = 0;

    virtual antlrcpp::Any visitClassFuncBody(FaParser::ClassFuncBodyContext *context) = 0;

    virtual antlrcpp::Any visitClassFunc(FaParser::ClassFuncContext *context) = 0;

    virtual antlrcpp::Any visitCallConvention(FaParser::CallConventionContext *context) = 0;

    virtual antlrcpp::Any visitImportStmt(FaParser::ImportStmtContext *context) = 0;

    virtual antlrcpp::Any visitLibStmt(FaParser::LibStmtContext *context) = 0;

    virtual antlrcpp::Any visitImportBlock(FaParser::ImportBlockContext *context) = 0;

    virtual antlrcpp::Any visitFaMainFuncBlock(FaParser::FaMainFuncBlockContext *context) = 0;

    virtual antlrcpp::Any visitProgram(FaParser::ProgramContext *context) = 0;


};



// Generated from Fa.g4 by ANTLR 4.9.3

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
    virtual antlrcpp::Any visitShiftLAssign(FaParser::ShiftLAssignContext *context) = 0;

    virtual antlrcpp::Any visitShiftRAssign(FaParser::ShiftRAssignContext *context) = 0;

    virtual antlrcpp::Any visitAllAssign(FaParser::AllAssignContext *context) = 0;

    virtual antlrcpp::Any visitShiftLOp(FaParser::ShiftLOpContext *context) = 0;

    virtual antlrcpp::Any visitShiftROp(FaParser::ShiftROpContext *context) = 0;

    virtual antlrcpp::Any visitEndl(FaParser::EndlContext *context) = 0;

    virtual antlrcpp::Any visitEndl2(FaParser::Endl2Context *context) = 0;

    virtual antlrcpp::Any visitQFangL(FaParser::QFangLContext *context) = 0;

    virtual antlrcpp::Any visitQFangR(FaParser::QFangRContext *context) = 0;

    virtual antlrcpp::Any visitQJianL(FaParser::QJianLContext *context) = 0;

    virtual antlrcpp::Any visitQJianR(FaParser::QJianRContext *context) = 0;

    virtual antlrcpp::Any visitQHuaL(FaParser::QHuaLContext *context) = 0;

    virtual antlrcpp::Any visitQHuaR(FaParser::QHuaRContext *context) = 0;

    virtual antlrcpp::Any visitQYuanL(FaParser::QYuanLContext *context) = 0;

    virtual antlrcpp::Any visitQYuanR(FaParser::QYuanRContext *context) = 0;

    virtual antlrcpp::Any visitQuotFangL(FaParser::QuotFangLContext *context) = 0;

    virtual antlrcpp::Any visitQuotFangR(FaParser::QuotFangRContext *context) = 0;

    virtual antlrcpp::Any visitQuotJianL(FaParser::QuotJianLContext *context) = 0;

    virtual antlrcpp::Any visitQuotJianR(FaParser::QuotJianRContext *context) = 0;

    virtual antlrcpp::Any visitQuotHuaL(FaParser::QuotHuaLContext *context) = 0;

    virtual antlrcpp::Any visitQuotHuaR(FaParser::QuotHuaRContext *context) = 0;

    virtual antlrcpp::Any visitQuotYuanL(FaParser::QuotYuanLContext *context) = 0;

    virtual antlrcpp::Any visitQuotYuanR(FaParser::QuotYuanRContext *context) = 0;

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

    virtual antlrcpp::Any visitIntNum(FaParser::IntNumContext *context) = 0;

    virtual antlrcpp::Any visitFloatNum(FaParser::FloatNumContext *context) = 0;

    virtual antlrcpp::Any visitLiteral(FaParser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitId(FaParser::IdContext *context) = 0;

    virtual antlrcpp::Any visitIds(FaParser::IdsContext *context) = 0;

    virtual antlrcpp::Any visitTypeAfter(FaParser::TypeAfterContext *context) = 0;

    virtual antlrcpp::Any visitTypeSingle(FaParser::TypeSingleContext *context) = 0;

    virtual antlrcpp::Any visitTypeMulti(FaParser::TypeMultiContext *context) = 0;

    virtual antlrcpp::Any visitType(FaParser::TypeContext *context) = 0;

    virtual antlrcpp::Any visitTypeWrap(FaParser::TypeWrapContext *context) = 0;

    virtual antlrcpp::Any visitTypeVar(FaParser::TypeVarContext *context) = 0;

    virtual antlrcpp::Any visitTypeVarList(FaParser::TypeVarListContext *context) = 0;

    virtual antlrcpp::Any visitTypeWrapVar1(FaParser::TypeWrapVar1Context *context) = 0;

    virtual antlrcpp::Any visitTypeWrapVarList1(FaParser::TypeWrapVarList1Context *context) = 0;

    virtual antlrcpp::Any visitTypeWrapVar2(FaParser::TypeWrapVar2Context *context) = 0;

    virtual antlrcpp::Any visitTypeWrapVarList2(FaParser::TypeWrapVarList2Context *context) = 0;

    virtual antlrcpp::Any visitTypeWrapVar3(FaParser::TypeWrapVar3Context *context) = 0;

    virtual antlrcpp::Any visitTypeWrapVarList3(FaParser::TypeWrapVarList3Context *context) = 0;

    virtual antlrcpp::Any visitQuotStmtPart(FaParser::QuotStmtPartContext *context) = 0;

    virtual antlrcpp::Any visitQuotStmtExpr(FaParser::QuotStmtExprContext *context) = 0;

    virtual antlrcpp::Any visitIfStmt(FaParser::IfStmtContext *context) = 0;

    virtual antlrcpp::Any visitIfExpr(FaParser::IfExprContext *context) = 0;

    virtual antlrcpp::Any visitWhileStmt(FaParser::WhileStmtContext *context) = 0;

    virtual antlrcpp::Any visitWhileStmt2(FaParser::WhileStmt2Context *context) = 0;

    virtual antlrcpp::Any visitForStmt(FaParser::ForStmtContext *context) = 0;

    virtual antlrcpp::Any visitForStmt2(FaParser::ForStmt2Context *context) = 0;

    virtual antlrcpp::Any visitSwitchStmtPart2Last(FaParser::SwitchStmtPart2LastContext *context) = 0;

    virtual antlrcpp::Any visitQuotStmtExprWrap(FaParser::QuotStmtExprWrapContext *context) = 0;

    virtual antlrcpp::Any visitSwitchExprPartLast(FaParser::SwitchExprPartLastContext *context) = 0;

    virtual antlrcpp::Any visitSwitchStmtPart(FaParser::SwitchStmtPartContext *context) = 0;

    virtual antlrcpp::Any visitSwitchStmt(FaParser::SwitchStmtContext *context) = 0;

    virtual antlrcpp::Any visitSwitchStmtPart2(FaParser::SwitchStmtPart2Context *context) = 0;

    virtual antlrcpp::Any visitSwitchStmt2(FaParser::SwitchStmt2Context *context) = 0;

    virtual antlrcpp::Any visitSwitchExprPart(FaParser::SwitchExprPartContext *context) = 0;

    virtual antlrcpp::Any visitSwitchExpr(FaParser::SwitchExprContext *context) = 0;

    virtual antlrcpp::Any visitSwitchExprPart2(FaParser::SwitchExprPart2Context *context) = 0;

    virtual antlrcpp::Any visitSwitchExpr2(FaParser::SwitchExpr2Context *context) = 0;

    virtual antlrcpp::Any visitQuotExpr(FaParser::QuotExprContext *context) = 0;

    virtual antlrcpp::Any visitExprOpt(FaParser::ExprOptContext *context) = 0;

    virtual antlrcpp::Any visitNewExprItem(FaParser::NewExprItemContext *context) = 0;

    virtual antlrcpp::Any visitNewExpr1(FaParser::NewExpr1Context *context) = 0;

    virtual antlrcpp::Any visitNewExpr2(FaParser::NewExpr2Context *context) = 0;

    virtual antlrcpp::Any visitArrayExpr1(FaParser::ArrayExpr1Context *context) = 0;

    virtual antlrcpp::Any visitArrayExpr2(FaParser::ArrayExpr2Context *context) = 0;

    virtual antlrcpp::Any visitLambdaExpr(FaParser::LambdaExprContext *context) = 0;

    virtual antlrcpp::Any visitStrongExprBase(FaParser::StrongExprBaseContext *context) = 0;

    virtual antlrcpp::Any visitStrongExprPrefix(FaParser::StrongExprPrefixContext *context) = 0;

    virtual antlrcpp::Any visitStrongExprSuffix(FaParser::StrongExprSuffixContext *context) = 0;

    virtual antlrcpp::Any visitStrongExpr(FaParser::StrongExprContext *context) = 0;

    virtual antlrcpp::Any visitMiddleExpr(FaParser::MiddleExprContext *context) = 0;

    virtual antlrcpp::Any visitExpr(FaParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitIdAssignExpr(FaParser::IdAssignExprContext *context) = 0;

    virtual antlrcpp::Any visitDefVarStmt(FaParser::DefVarStmtContext *context) = 0;

    virtual antlrcpp::Any visitIdAssignExpr2(FaParser::IdAssignExpr2Context *context) = 0;

    virtual antlrcpp::Any visitDefVarStmt2(FaParser::DefVarStmt2Context *context) = 0;

    virtual antlrcpp::Any visitNormalStmt(FaParser::NormalStmtContext *context) = 0;

    virtual antlrcpp::Any visitStmt(FaParser::StmtContext *context) = 0;

    virtual antlrcpp::Any visitPublicLevel(FaParser::PublicLevelContext *context) = 0;

    virtual antlrcpp::Any visitClassItemFuncExtBody(FaParser::ClassItemFuncExtBodyContext *context) = 0;

    virtual antlrcpp::Any visitClassItemVar(FaParser::ClassItemVarContext *context) = 0;

    virtual antlrcpp::Any visitClassItemFunc(FaParser::ClassItemFuncContext *context) = 0;

    virtual antlrcpp::Any visitClassBlock(FaParser::ClassBlockContext *context) = 0;

    virtual antlrcpp::Any visitClassItemFuncExt2(FaParser::ClassItemFuncExt2Context *context) = 0;

    virtual antlrcpp::Any visitClassItem2(FaParser::ClassItem2Context *context) = 0;

    virtual antlrcpp::Any visitClassBlock2(FaParser::ClassBlock2Context *context) = 0;

    virtual antlrcpp::Any visitEnumItem(FaParser::EnumItemContext *context) = 0;

    virtual antlrcpp::Any visitEnumBlock(FaParser::EnumBlockContext *context) = 0;

    virtual antlrcpp::Any visitEnumBlock2(FaParser::EnumBlock2Context *context) = 0;

    virtual antlrcpp::Any visitUseStmt(FaParser::UseStmtContext *context) = 0;

    virtual antlrcpp::Any visitCallConvention(FaParser::CallConventionContext *context) = 0;

    virtual antlrcpp::Any visitImportStmt(FaParser::ImportStmtContext *context) = 0;

    virtual antlrcpp::Any visitLibStmt(FaParser::LibStmtContext *context) = 0;

    virtual antlrcpp::Any visitNamespaceStmt(FaParser::NamespaceStmtContext *context) = 0;

    virtual antlrcpp::Any visitProgram(FaParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitProgramEntry(FaParser::ProgramEntryContext *context) = 0;


};


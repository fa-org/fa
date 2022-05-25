
// Generated from Fa.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "FaVisitor.h"


/**
 * This class provides an empty implementation of FaVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  FaBaseVisitor : public FaVisitor {
public:

  virtual antlrcpp::Any visitShiftLAssign(FaParser::ShiftLAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShiftRAssign(FaParser::ShiftRAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAllAssign(FaParser::AllAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShiftLOp(FaParser::ShiftLOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShiftROp(FaParser::ShiftROpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEndStmt(FaParser::EndStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEndStmt2(FaParser::EndStmt2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLtOp(FaParser::LtOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLtEqualOp(FaParser::LtEqualOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGtOp(FaParser::GtOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGtEqualOp(FaParser::GtEqualOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEqualOp(FaParser::EqualOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNotEqualOp(FaParser::NotEqualOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprFuncDef(FaParser::ExprFuncDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelfOp2(FaParser::SelfOp2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCompareOp2(FaParser::CompareOp2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChangeOp2(FaParser::ChangeOp2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAllOp2(FaParser::AllOp2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntNum(FaParser::IntNumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFloatNum(FaParser::FloatNumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteral(FaParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitId(FaParser::IdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIds(FaParser::IdsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdExt(FaParser::IdExtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeAfter(FaParser::TypeAfterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeSingle(FaParser::TypeSingleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeMulti(FaParser::TypeMultiContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(FaParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeWrap(FaParser::TypeWrapContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeVar(FaParser::TypeVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeVarList(FaParser::TypeVarListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeWrapVar(FaParser::TypeWrapVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeWrapVarList(FaParser::TypeWrapVarListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeWrapVar2(FaParser::TypeWrapVar2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeWrapVar2List(FaParser::TypeWrapVar2ListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuotStmtPart(FaParser::QuotStmtPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuotStmtExpr(FaParser::QuotStmtExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfStmt(FaParser::IfStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfExpr(FaParser::IfExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileStmt(FaParser::WhileStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileStmt2(FaParser::WhileStmt2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForStmt(FaParser::ForStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForStmt2(FaParser::ForStmt2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwitchStmtPart2Last(FaParser::SwitchStmtPart2LastContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuotStmtExprWrap(FaParser::QuotStmtExprWrapContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwitchExprPartLast(FaParser::SwitchExprPartLastContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwitchStmtPart(FaParser::SwitchStmtPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwitchStmt(FaParser::SwitchStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwitchStmtPart2(FaParser::SwitchStmtPart2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwitchStmt2(FaParser::SwitchStmt2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwitchExprPart(FaParser::SwitchExprPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwitchExpr(FaParser::SwitchExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwitchExprPart2(FaParser::SwitchExprPart2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwitchExpr2(FaParser::SwitchExpr2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuotExpr(FaParser::QuotExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprOpt(FaParser::ExprOptContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNewExprItem(FaParser::NewExprItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNewExpr1(FaParser::NewExpr1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNewExpr2(FaParser::NewExpr2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayExpr1(FaParser::ArrayExpr1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayExpr2(FaParser::ArrayExpr2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLambdaExpr(FaParser::LambdaExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStrongExprBase(FaParser::StrongExprBaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStrongExprPrefix(FaParser::StrongExprPrefixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStrongExprSuffix(FaParser::StrongExprSuffixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStrongExpr(FaParser::StrongExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMiddleExpr(FaParser::MiddleExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr(FaParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTmpAssignExpr(FaParser::TmpAssignExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdAssignExpr(FaParser::IdAssignExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefVarStmt(FaParser::DefVarStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNormalStmt(FaParser::NormalStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmt(FaParser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPublicLevel(FaParser::PublicLevelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassTemplates(FaParser::ClassTemplatesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassParent(FaParser::ClassParentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassEnum(FaParser::ClassEnumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassItemFuncExtBody(FaParser::ClassItemFuncExtBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassItemFuncExt(FaParser::ClassItemFuncExtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassItem(FaParser::ClassItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassFuncItem(FaParser::ClassFuncItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnumStmt(FaParser::EnumStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassStmt(FaParser::ClassStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUseStmt(FaParser::UseStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCallConvention(FaParser::CallConventionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImportStmt(FaParser::ImportStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLibStmt(FaParser::LibStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNamespaceStmt(FaParser::NamespaceStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProgram(FaParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProgramEntry(FaParser::ProgramEntryContext *ctx) override {
    return visitChildren(ctx);
  }


};



// Generated from Fa.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "FaVisitor.h"


/**
 * This class provides an empty implementation of FaVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  FaBaseVisitor : public FaVisitor {
public:

  virtual antlrcpp::Any visitAddAssign(FaParser::AddAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubAssign(FaParser::SubAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStarAssign(FaParser::StarAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDivAssign(FaParser::DivAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModAssign(FaParser::ModAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOrAssign(FaParser::OrAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAndAssign(FaParser::AndAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitXorAssign(FaParser::XorAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQusQusAssign(FaParser::QusQusAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStarStarAssign(FaParser::StarStarAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAndAndAssign(FaParser::AndAndAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOrOrAssign(FaParser::OrOrAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShiftLAssign(FaParser::ShiftLAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShiftRAssign(FaParser::ShiftRAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAllAssign(FaParser::AllAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQusQusOp(FaParser::QusQusOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStarStarOp(FaParser::StarStarOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAndAndOp(FaParser::AndAndOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOrOrOp(FaParser::OrOrOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShiftLOp(FaParser::ShiftLOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShiftROp(FaParser::ShiftROpContext *ctx) override {
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

  virtual antlrcpp::Any visitIds(FaParser::IdsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeAfter(FaParser::TypeAfterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(FaParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeNewable(FaParser::TypeNewableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeVar(FaParser::TypeVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeVarList(FaParser::TypeVarListContext *ctx) override {
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

  virtual antlrcpp::Any visitNumIterStmt(FaParser::NumIterStmtContext *ctx) override {
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

  virtual antlrcpp::Any visitNewExpr(FaParser::NewExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayExpr1(FaParser::ArrayExpr1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayExpr2(FaParser::ArrayExpr2Context *ctx) override {
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

  virtual antlrcpp::Any visitDefVarStmt(FaParser::DefVarStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUseStmt(FaParser::UseStmtContext *ctx) override {
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

  virtual antlrcpp::Any visitClassParent(FaParser::ClassParentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassStmt(FaParser::ClassStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassVarExtFunc(FaParser::ClassVarExtFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassVarExt(FaParser::ClassVarExtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassVar(FaParser::ClassVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassFuncName(FaParser::ClassFuncNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassFuncBody(FaParser::ClassFuncBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassFunc(FaParser::ClassFuncContext *ctx) override {
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

  virtual antlrcpp::Any visitImportBlock(FaParser::ImportBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFaMainFuncBlock(FaParser::FaMainFuncBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProgram(FaParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }


};


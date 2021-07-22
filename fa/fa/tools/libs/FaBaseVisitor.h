
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

  virtual antlrcpp::Any visitAllOp2(FaParser::AllOp2Context *ctx) override {
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

  virtual antlrcpp::Any visitLtOps(FaParser::LtOpsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGtOps(FaParser::GtOpsContext *ctx) override {
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

  virtual antlrcpp::Any visitETypeAfter(FaParser::ETypeAfterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitESign(FaParser::ESignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEType(FaParser::ETypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeVar(FaParser::TypeVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeVarList(FaParser::TypeVarListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitETypeVar(FaParser::ETypeVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitETypeVarList(FaParser::ETypeVarListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfPart(FaParser::IfPartContext *ctx) override {
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

  virtual antlrcpp::Any visitQuotExpr(FaParser::QuotExprContext *ctx) override {
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

  virtual antlrcpp::Any visitWeakExprSuffix(FaParser::WeakExprSuffixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr(FaParser::ExprContext *ctx) override {
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

  virtual antlrcpp::Any visitClassItemPart(FaParser::ClassItemPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassItemFieldBlock(FaParser::ClassItemFieldBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassItemFuncBlock(FaParser::ClassItemFuncBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassBlock(FaParser::ClassBlockContext *ctx) override {
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

  virtual antlrcpp::Any visitFaEntryMainFuncBlock(FaParser::FaEntryMainFuncBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProgram(FaParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }


};


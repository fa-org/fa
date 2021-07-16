
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

  virtual antlrcpp::Any visitShiftLOp(FaParser::ShiftLOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShiftROp(FaParser::ShiftROpContext *ctx) override {
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

  virtual antlrcpp::Any visitStmtOrIfExpr(FaParser::StmtOrIfExprContext *ctx) override {
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

  virtual antlrcpp::Any visitIfElseExpr(FaParser::IfElseExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileStmt(FaParser::WhileStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAllAssign(FaParser::AllAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAllOp(FaParser::AllOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuotExpr(FaParser::QuotExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprPrefix(FaParser::ExprPrefixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprBody(FaParser::ExprBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprSuffix(FaParser::ExprSuffixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNormalExpr(FaParser::NormalExprContext *ctx) override {
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


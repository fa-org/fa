
// Generated from ../Fa.g4 by ANTLR 4.9.3

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

  virtual antlrcpp::Any visitAllOp2(FaParser::AllOp2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteral(FaParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuotStmtPart(FaParser::QuotStmtPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfStmt(FaParser::IfStmtContext *ctx) override {
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

  virtual antlrcpp::Any visitSwitchStmtPart(FaParser::SwitchStmtPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwitchStmt(FaParser::SwitchStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprOpt(FaParser::ExprOptContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuotExpr(FaParser::QuotExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFnExpr(FaParser::FnExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassExprItem(FaParser::ClassExprItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassExpr(FaParser::ClassExprContext *ctx) override {
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

  virtual antlrcpp::Any visitFnStmt(FaParser::FnStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmt(FaParser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassItemFuncExt(FaParser::ClassItemFuncExtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassItemStmt(FaParser::ClassItemStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassStmt(FaParser::ClassStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUseStmt(FaParser::UseStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNamespaceStmt(FaParser::NamespaceStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProgram(FaParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }


};



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

  virtual antlrcpp::Any visitIds(FaParser::IdsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeAfter(FaParser::TypeAfterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeExpr(FaParser::TypeExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUseStmt(FaParser::UseStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturnStmt(FaParser::ReturnStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassParent(FaParser::ClassParentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeVar(FaParser::TypeVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeVarList(FaParser::TypeVarListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassItemExpr(FaParser::ClassItemExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassItemFieldStmt(FaParser::ClassItemFieldStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassItemFuncStmt(FaParser::ClassItemFuncStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassStmt(FaParser::ClassStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProgram(FaParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }


};


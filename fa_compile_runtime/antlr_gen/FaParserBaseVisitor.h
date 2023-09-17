
// Generated from FaParser.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "FaParserVisitor.h"


/**
 * This class provides an empty implementation of FaParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  FaParserBaseVisitor : public FaParserVisitor {
public:

  virtual std::any visitShiftLAssignOp(FaParser::ShiftLAssignOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShiftRAssignOp(FaParser::ShiftRAssignOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAllAssignOp(FaParser::AllAssignOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShiftLOp(FaParser::ShiftLOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShiftROp(FaParser::ShiftROpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEndl(FaParser::EndlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEndl2(FaParser::Endl2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuotFangL(FaParser::QuotFangLContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuotFangR(FaParser::QuotFangRContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuotJianL(FaParser::QuotJianLContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuotJianR(FaParser::QuotJianRContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuotHuaL(FaParser::QuotHuaLContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuotHuaR(FaParser::QuotHuaRContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuotYuanL(FaParser::QuotYuanLContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuotYuanR(FaParser::QuotYuanRContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelfOp2(FaParser::SelfOp2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompareOp2(FaParser::CompareOp2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitChangeOp2(FaParser::ChangeOp2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAllOp2(FaParser::AllOp2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntNum(FaParser::IntNumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFloatNum(FaParser::FloatNumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFormatString1Part(FaParser::FormatString1PartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFormatString1(FaParser::FormatString1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFormatString2Part(FaParser::FormatString2PartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFormatString2(FaParser::FormatString2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringLiteral(FaParser::StringLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteral(FaParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIds(FaParser::IdsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeAfter(FaParser::TypeAfterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeTuple(FaParser::TypeTupleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypes(FaParser::TypesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType(FaParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgAttr(FaParser::ArgAttrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeVar(FaParser::TypeVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeVarList(FaParser::TypeVarListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeWrapVar1(FaParser::TypeWrapVar1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeWrapVarList1(FaParser::TypeWrapVarList1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeWrapVar2(FaParser::TypeWrapVar2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeWrapVarList2(FaParser::TypeWrapVarList2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeWrapVar3(FaParser::TypeWrapVar3Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeWrapVarList3(FaParser::TypeWrapVarList3Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeWrapVar4(FaParser::TypeWrapVar4Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeWrapVarList4(FaParser::TypeWrapVarList4Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuotStmtPart(FaParser::QuotStmtPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStmt(FaParser::IfStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuotStmtExpr(FaParser::QuotStmtExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfExpr(FaParser::IfExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileStmt(FaParser::WhileStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileStmt2(FaParser::WhileStmt2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForHeader1(FaParser::ForHeader1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForHeader2(FaParser::ForHeader2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForHeader(FaParser::ForHeaderContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForStmt(FaParser::ForStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSwitchStmtPart2Last(FaParser::SwitchStmtPart2LastContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuotStmtExprWrap(FaParser::QuotStmtExprWrapContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSwitchExprPartLast(FaParser::SwitchExprPartLastContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSwitchStmtPart(FaParser::SwitchStmtPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSwitchStmt(FaParser::SwitchStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSwitchStmtPart2(FaParser::SwitchStmtPart2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSwitchStmt2(FaParser::SwitchStmt2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSwitchExprPart(FaParser::SwitchExprPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSwitchExpr1(FaParser::SwitchExpr1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSwitchExprPart2(FaParser::SwitchExprPart2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSwitchExpr2(FaParser::SwitchExpr2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuotExpr(FaParser::QuotExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTupleExprItem(FaParser::TupleExprItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTupleExpr(FaParser::TupleExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprOpt(FaParser::ExprOptContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewExprItem(FaParser::NewExprItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewExpr1(FaParser::NewExpr1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewExpr2(FaParser::NewExpr2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayExpr1Cond(FaParser::ArrayExpr1CondContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayExpr1(FaParser::ArrayExpr1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayExpr2(FaParser::ArrayExpr2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayExpr3(FaParser::ArrayExpr3Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLambdaExpr(FaParser::LambdaExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStrongExprBase(FaParser::StrongExprBaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStrongExprPrefix(FaParser::StrongExprPrefixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStrongExprSuffix(FaParser::StrongExprSuffixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStrongExpr(FaParser::StrongExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMiddle3OpExpr(FaParser::Middle3OpExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMiddle2OpExpr(FaParser::Middle2OpExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMiddleAstExpr(FaParser::MiddleAstExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMiddleExpr(FaParser::MiddleExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr(FaParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdAssignOpExpr(FaParser::IdAssignOpExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDefVarStmtPart(FaParser::DefVarStmtPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdAssignOpExpr2(FaParser::IdAssignOpExpr2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDefVarStmt2Part(FaParser::DefVarStmt2PartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDefTypeStmt(FaParser::DefTypeStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNormalStmtPart(FaParser::NormalStmtPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNormalStmt(FaParser::NormalStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmt(FaParser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPublicLevel(FaParser::PublicLevelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlockTemplates(FaParser::BlockTemplatesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitItemName(FaParser::ItemNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeNameTuple(FaParser::TypeNameTupleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeNameArgsTuple(FaParser::TypeNameArgsTupleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNameArgsTuple(FaParser::NameArgsTupleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncBody(FaParser::FuncBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAnnoArg(FaParser::AnnoArgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAnnoPart(FaParser::AnnoPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAnnoBlock(FaParser::AnnoBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImportedConstructFunc(FaParser::ImportedConstructFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarAccesser(FaParser::VarAccesserContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarAccesserItems(FaParser::VarAccesserItemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassVar(FaParser::ClassVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassFunc(FaParser::ClassFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassBlock(FaParser::ClassBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnumItem(FaParser::EnumItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnumBlock(FaParser::EnumBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUseStmt(FaParser::UseStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNamespaceStmt(FaParser::NamespaceStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgram(FaParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgramEntry(FaParser::ProgramEntryContext *ctx) override {
    return visitChildren(ctx);
  }


};


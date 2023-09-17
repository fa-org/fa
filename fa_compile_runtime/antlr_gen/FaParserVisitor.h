
// Generated from FaParser.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "FaParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by FaParser.
 */
class  FaParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by FaParser.
   */
    virtual std::any visitShiftLAssignOp(FaParser::ShiftLAssignOpContext *context) = 0;

    virtual std::any visitShiftRAssignOp(FaParser::ShiftRAssignOpContext *context) = 0;

    virtual std::any visitAllAssignOp(FaParser::AllAssignOpContext *context) = 0;

    virtual std::any visitShiftLOp(FaParser::ShiftLOpContext *context) = 0;

    virtual std::any visitShiftROp(FaParser::ShiftROpContext *context) = 0;

    virtual std::any visitEndl(FaParser::EndlContext *context) = 0;

    virtual std::any visitEndl2(FaParser::Endl2Context *context) = 0;

    virtual std::any visitQuotFangL(FaParser::QuotFangLContext *context) = 0;

    virtual std::any visitQuotFangR(FaParser::QuotFangRContext *context) = 0;

    virtual std::any visitQuotJianL(FaParser::QuotJianLContext *context) = 0;

    virtual std::any visitQuotJianR(FaParser::QuotJianRContext *context) = 0;

    virtual std::any visitQuotHuaL(FaParser::QuotHuaLContext *context) = 0;

    virtual std::any visitQuotHuaR(FaParser::QuotHuaRContext *context) = 0;

    virtual std::any visitQuotYuanL(FaParser::QuotYuanLContext *context) = 0;

    virtual std::any visitQuotYuanR(FaParser::QuotYuanRContext *context) = 0;

    virtual std::any visitSelfOp2(FaParser::SelfOp2Context *context) = 0;

    virtual std::any visitCompareOp2(FaParser::CompareOp2Context *context) = 0;

    virtual std::any visitChangeOp2(FaParser::ChangeOp2Context *context) = 0;

    virtual std::any visitAllOp2(FaParser::AllOp2Context *context) = 0;

    virtual std::any visitIntNum(FaParser::IntNumContext *context) = 0;

    virtual std::any visitFloatNum(FaParser::FloatNumContext *context) = 0;

    virtual std::any visitFormatString1Part(FaParser::FormatString1PartContext *context) = 0;

    virtual std::any visitFormatString1(FaParser::FormatString1Context *context) = 0;

    virtual std::any visitFormatString2Part(FaParser::FormatString2PartContext *context) = 0;

    virtual std::any visitFormatString2(FaParser::FormatString2Context *context) = 0;

    virtual std::any visitStringLiteral(FaParser::StringLiteralContext *context) = 0;

    virtual std::any visitLiteral(FaParser::LiteralContext *context) = 0;

    virtual std::any visitIds(FaParser::IdsContext *context) = 0;

    virtual std::any visitTypeAfter(FaParser::TypeAfterContext *context) = 0;

    virtual std::any visitTypeTuple(FaParser::TypeTupleContext *context) = 0;

    virtual std::any visitTypes(FaParser::TypesContext *context) = 0;

    virtual std::any visitType(FaParser::TypeContext *context) = 0;

    virtual std::any visitArgAttr(FaParser::ArgAttrContext *context) = 0;

    virtual std::any visitTypeVar(FaParser::TypeVarContext *context) = 0;

    virtual std::any visitTypeVarList(FaParser::TypeVarListContext *context) = 0;

    virtual std::any visitTypeWrapVar1(FaParser::TypeWrapVar1Context *context) = 0;

    virtual std::any visitTypeWrapVarList1(FaParser::TypeWrapVarList1Context *context) = 0;

    virtual std::any visitTypeWrapVar2(FaParser::TypeWrapVar2Context *context) = 0;

    virtual std::any visitTypeWrapVarList2(FaParser::TypeWrapVarList2Context *context) = 0;

    virtual std::any visitTypeWrapVar3(FaParser::TypeWrapVar3Context *context) = 0;

    virtual std::any visitTypeWrapVarList3(FaParser::TypeWrapVarList3Context *context) = 0;

    virtual std::any visitTypeWrapVar4(FaParser::TypeWrapVar4Context *context) = 0;

    virtual std::any visitTypeWrapVarList4(FaParser::TypeWrapVarList4Context *context) = 0;

    virtual std::any visitQuotStmtPart(FaParser::QuotStmtPartContext *context) = 0;

    virtual std::any visitIfStmt(FaParser::IfStmtContext *context) = 0;

    virtual std::any visitQuotStmtExpr(FaParser::QuotStmtExprContext *context) = 0;

    virtual std::any visitIfExpr(FaParser::IfExprContext *context) = 0;

    virtual std::any visitWhileStmt(FaParser::WhileStmtContext *context) = 0;

    virtual std::any visitWhileStmt2(FaParser::WhileStmt2Context *context) = 0;

    virtual std::any visitForHeader1(FaParser::ForHeader1Context *context) = 0;

    virtual std::any visitForHeader2(FaParser::ForHeader2Context *context) = 0;

    virtual std::any visitForHeader(FaParser::ForHeaderContext *context) = 0;

    virtual std::any visitForStmt(FaParser::ForStmtContext *context) = 0;

    virtual std::any visitSwitchStmtPart2Last(FaParser::SwitchStmtPart2LastContext *context) = 0;

    virtual std::any visitQuotStmtExprWrap(FaParser::QuotStmtExprWrapContext *context) = 0;

    virtual std::any visitSwitchExprPartLast(FaParser::SwitchExprPartLastContext *context) = 0;

    virtual std::any visitSwitchStmtPart(FaParser::SwitchStmtPartContext *context) = 0;

    virtual std::any visitSwitchStmt(FaParser::SwitchStmtContext *context) = 0;

    virtual std::any visitSwitchStmtPart2(FaParser::SwitchStmtPart2Context *context) = 0;

    virtual std::any visitSwitchStmt2(FaParser::SwitchStmt2Context *context) = 0;

    virtual std::any visitSwitchExprPart(FaParser::SwitchExprPartContext *context) = 0;

    virtual std::any visitSwitchExpr1(FaParser::SwitchExpr1Context *context) = 0;

    virtual std::any visitSwitchExprPart2(FaParser::SwitchExprPart2Context *context) = 0;

    virtual std::any visitSwitchExpr2(FaParser::SwitchExpr2Context *context) = 0;

    virtual std::any visitQuotExpr(FaParser::QuotExprContext *context) = 0;

    virtual std::any visitTupleExprItem(FaParser::TupleExprItemContext *context) = 0;

    virtual std::any visitTupleExpr(FaParser::TupleExprContext *context) = 0;

    virtual std::any visitExprOpt(FaParser::ExprOptContext *context) = 0;

    virtual std::any visitNewExprItem(FaParser::NewExprItemContext *context) = 0;

    virtual std::any visitNewExpr1(FaParser::NewExpr1Context *context) = 0;

    virtual std::any visitNewExpr2(FaParser::NewExpr2Context *context) = 0;

    virtual std::any visitArrayExpr1Cond(FaParser::ArrayExpr1CondContext *context) = 0;

    virtual std::any visitArrayExpr1(FaParser::ArrayExpr1Context *context) = 0;

    virtual std::any visitArrayExpr2(FaParser::ArrayExpr2Context *context) = 0;

    virtual std::any visitArrayExpr3(FaParser::ArrayExpr3Context *context) = 0;

    virtual std::any visitLambdaExpr(FaParser::LambdaExprContext *context) = 0;

    virtual std::any visitStrongExprBase(FaParser::StrongExprBaseContext *context) = 0;

    virtual std::any visitStrongExprPrefix(FaParser::StrongExprPrefixContext *context) = 0;

    virtual std::any visitStrongExprSuffix(FaParser::StrongExprSuffixContext *context) = 0;

    virtual std::any visitStrongExpr(FaParser::StrongExprContext *context) = 0;

    virtual std::any visitMiddle3OpExpr(FaParser::Middle3OpExprContext *context) = 0;

    virtual std::any visitMiddle2OpExpr(FaParser::Middle2OpExprContext *context) = 0;

    virtual std::any visitMiddleAstExpr(FaParser::MiddleAstExprContext *context) = 0;

    virtual std::any visitMiddleExpr(FaParser::MiddleExprContext *context) = 0;

    virtual std::any visitExpr(FaParser::ExprContext *context) = 0;

    virtual std::any visitIdAssignOpExpr(FaParser::IdAssignOpExprContext *context) = 0;

    virtual std::any visitDefVarStmtPart(FaParser::DefVarStmtPartContext *context) = 0;

    virtual std::any visitIdAssignOpExpr2(FaParser::IdAssignOpExpr2Context *context) = 0;

    virtual std::any visitDefVarStmt2Part(FaParser::DefVarStmt2PartContext *context) = 0;

    virtual std::any visitDefTypeStmt(FaParser::DefTypeStmtContext *context) = 0;

    virtual std::any visitNormalStmtPart(FaParser::NormalStmtPartContext *context) = 0;

    virtual std::any visitNormalStmt(FaParser::NormalStmtContext *context) = 0;

    virtual std::any visitStmt(FaParser::StmtContext *context) = 0;

    virtual std::any visitPublicLevel(FaParser::PublicLevelContext *context) = 0;

    virtual std::any visitBlockTemplates(FaParser::BlockTemplatesContext *context) = 0;

    virtual std::any visitItemName(FaParser::ItemNameContext *context) = 0;

    virtual std::any visitTypeNameTuple(FaParser::TypeNameTupleContext *context) = 0;

    virtual std::any visitTypeNameArgsTuple(FaParser::TypeNameArgsTupleContext *context) = 0;

    virtual std::any visitNameArgsTuple(FaParser::NameArgsTupleContext *context) = 0;

    virtual std::any visitFuncBody(FaParser::FuncBodyContext *context) = 0;

    virtual std::any visitAnnoArg(FaParser::AnnoArgContext *context) = 0;

    virtual std::any visitAnnoPart(FaParser::AnnoPartContext *context) = 0;

    virtual std::any visitAnnoBlock(FaParser::AnnoBlockContext *context) = 0;

    virtual std::any visitImportedConstructFunc(FaParser::ImportedConstructFuncContext *context) = 0;

    virtual std::any visitVarAccesser(FaParser::VarAccesserContext *context) = 0;

    virtual std::any visitVarAccesserItems(FaParser::VarAccesserItemsContext *context) = 0;

    virtual std::any visitClassVar(FaParser::ClassVarContext *context) = 0;

    virtual std::any visitClassFunc(FaParser::ClassFuncContext *context) = 0;

    virtual std::any visitClassBlock(FaParser::ClassBlockContext *context) = 0;

    virtual std::any visitEnumItem(FaParser::EnumItemContext *context) = 0;

    virtual std::any visitEnumBlock(FaParser::EnumBlockContext *context) = 0;

    virtual std::any visitUseStmt(FaParser::UseStmtContext *context) = 0;

    virtual std::any visitNamespaceStmt(FaParser::NamespaceStmtContext *context) = 0;

    virtual std::any visitProgram(FaParser::ProgramContext *context) = 0;

    virtual std::any visitProgramEntry(FaParser::ProgramEntryContext *context) = 0;


};


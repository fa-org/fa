
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

    virtual antlrcpp::Any visitEndStmt(FaParser::EndStmtContext *context) = 0;

    virtual antlrcpp::Any visitLtOp(FaParser::LtOpContext *context) = 0;

    virtual antlrcpp::Any visitLtEqualOp(FaParser::LtEqualOpContext *context) = 0;

    virtual antlrcpp::Any visitGtOp(FaParser::GtOpContext *context) = 0;

    virtual antlrcpp::Any visitGtEqualOp(FaParser::GtEqualOpContext *context) = 0;

    virtual antlrcpp::Any visitEqualOp(FaParser::EqualOpContext *context) = 0;

    virtual antlrcpp::Any visitNotEqualOp(FaParser::NotEqualOpContext *context) = 0;

    virtual antlrcpp::Any visitExprFuncDef(FaParser::ExprFuncDefContext *context) = 0;

    virtual antlrcpp::Any visitSelfOp2(FaParser::SelfOp2Context *context) = 0;

    virtual antlrcpp::Any visitCompareOp2(FaParser::CompareOp2Context *context) = 0;

    virtual antlrcpp::Any visitAllOp2(FaParser::AllOp2Context *context) = 0;

    virtual antlrcpp::Any visitLiteral(FaParser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitIds(FaParser::IdsContext *context) = 0;

    virtual antlrcpp::Any visitQuotStmtPart(FaParser::QuotStmtPartContext *context) = 0;

    virtual antlrcpp::Any visitIfStmt(FaParser::IfStmtContext *context) = 0;

    virtual antlrcpp::Any visitWhileStmt(FaParser::WhileStmtContext *context) = 0;

    virtual antlrcpp::Any visitWhileStmt2(FaParser::WhileStmt2Context *context) = 0;

    virtual antlrcpp::Any visitForStmt(FaParser::ForStmtContext *context) = 0;

    virtual antlrcpp::Any visitForStmt2(FaParser::ForStmt2Context *context) = 0;

    virtual antlrcpp::Any visitSwitchStmtPart(FaParser::SwitchStmtPartContext *context) = 0;

    virtual antlrcpp::Any visitSwitchStmt(FaParser::SwitchStmtContext *context) = 0;

    virtual antlrcpp::Any visitExprOpt(FaParser::ExprOptContext *context) = 0;

    virtual antlrcpp::Any visitQuotExpr(FaParser::QuotExprContext *context) = 0;

    virtual antlrcpp::Any visitFnExpr(FaParser::FnExprContext *context) = 0;

    virtual antlrcpp::Any visitClassExprItem(FaParser::ClassExprItemContext *context) = 0;

    virtual antlrcpp::Any visitClassExpr(FaParser::ClassExprContext *context) = 0;

    virtual antlrcpp::Any visitStrongExprBase(FaParser::StrongExprBaseContext *context) = 0;

    virtual antlrcpp::Any visitStrongExprPrefix(FaParser::StrongExprPrefixContext *context) = 0;

    virtual antlrcpp::Any visitStrongExprSuffix(FaParser::StrongExprSuffixContext *context) = 0;

    virtual antlrcpp::Any visitStrongExpr(FaParser::StrongExprContext *context) = 0;

    virtual antlrcpp::Any visitMiddleExpr(FaParser::MiddleExprContext *context) = 0;

    virtual antlrcpp::Any visitExpr(FaParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitFnStmt(FaParser::FnStmtContext *context) = 0;

    virtual antlrcpp::Any visitStmt(FaParser::StmtContext *context) = 0;

    virtual antlrcpp::Any visitClassItemFuncExt(FaParser::ClassItemFuncExtContext *context) = 0;

    virtual antlrcpp::Any visitClassItemStmt(FaParser::ClassItemStmtContext *context) = 0;

    virtual antlrcpp::Any visitClassStmt(FaParser::ClassStmtContext *context) = 0;

    virtual antlrcpp::Any visitUseStmt(FaParser::UseStmtContext *context) = 0;

    virtual antlrcpp::Any visitNamespaceStmt(FaParser::NamespaceStmtContext *context) = 0;

    virtual antlrcpp::Any visitProgram(FaParser::ProgramContext *context) = 0;


};


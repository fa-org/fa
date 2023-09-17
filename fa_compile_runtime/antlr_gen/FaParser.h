
// Generated from FaParser.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  FaParser : public antlr4::Parser {
public:
  enum {
    CC__Cdecl = 1, CC__FastCall = 2, CC__StdCall = 3, Annotation = 4, Base = 5, 
    Break = 6, Calc = 7, Continue = 8, Class = 9, Cast = 10, Const = 11, 
    Disperse = 12, Do = 13, Else = 14, Enum = 15, Expr = 16, For = 17, From = 18, 
    Get = 19, If = 20, In = 21, Is = 22, Internal = 23, Mut = 24, Namespace = 25, 
    New = 26, Operator = 27, Params = 28, Public = 29, Protected = 30, Private = 31, 
    Return = 32, Run = 33, Select = 34, Set = 35, Signed = 36, Static = 37, 
    Stmt = 38, SwitchExpr = 39, Switch = 40, Type = 41, Unsigned = 42, Use = 43, 
    AstClassVar = 44, When = 45, Where = 46, While = 47, AssignOp = 48, AddAssignOp = 49, 
    SubAssignOp = 50, StarAssignOp = 51, DivAssignOp = 52, ModAssignOp = 53, 
    OrAssignOp = 54, AndAssignOp = 55, XorAssignOp = 56, QusQusAssignOp = 57, 
    StarStarAssignOp = 58, AndAndAssignOp = 59, OrOrAssignOp = 60, ReverseOp = 61, 
    AddAddOp = 62, SubSubOp = 63, Exclam = 64, PointOp = 65, AddOp = 66, 
    SubOp = 67, StarOp = 68, DivOp = 69, ModOp = 70, OrOp = 71, AndOp = 72, 
    XorOp = 73, PointPoint = 74, QusQusOp = 75, StarStarOp = 76, AndAndOp = 77, 
    OrOrOp = 78, Qus = 79, Comma = 80, ColonColon = 81, Colon = 82, Lf = 83, 
    Semi = 84, Underline = 85, QFangL = 86, QFangR = 87, LessThan = 88, 
    GreatThan = 89, QHuaL = 90, QHuaR = 91, QYuanL = 92, QYuanR = 93, LtEqualOp = 94, 
    GtEqualOp = 95, EqualOp = 96, NotEqualOp = 97, ExprFuncDef = 98, BoolLiteral = 99, 
    HexLiteral = 100, IntLiteral = 101, FloatLiteral = 102, String1Literal = 103, 
    String2Literal = 104, String3Literal = 105, FmtString1 = 106, FmtString2 = 107, 
    Id = 108, Comment1 = 109, Comment2 = 110, WS = 111, QHuaLQHuaL = 112, 
    QHuaRQHuaR = 113, QHuaLInside = 114, RegularCharInside = 115, VerbatiumDoubleQuoteInside = 116, 
    DoubleQuoteInside = 117, RegularStringInside = 118, VerbatiumInsideString = 119, 
    QHuaRInside = 120, FormatString = 121
  };

  enum {
    RuleShiftLAssignOp = 0, RuleShiftRAssignOp = 1, RuleAllAssignOp = 2, 
    RuleShiftLOp = 3, RuleShiftROp = 4, RuleEndl = 5, RuleEndl2 = 6, RuleQuotFangL = 7, 
    RuleQuotFangR = 8, RuleQuotJianL = 9, RuleQuotJianR = 10, RuleQuotHuaL = 11, 
    RuleQuotHuaR = 12, RuleQuotYuanL = 13, RuleQuotYuanR = 14, RuleSelfOp2 = 15, 
    RuleCompareOp2 = 16, RuleChangeOp2 = 17, RuleAllOp2 = 18, RuleIntNum = 19, 
    RuleFloatNum = 20, RuleFormatString1Part = 21, RuleFormatString1 = 22, 
    RuleFormatString2Part = 23, RuleFormatString2 = 24, RuleStringLiteral = 25, 
    RuleLiteral = 26, RuleIds = 27, RuleTypeAfter = 28, RuleTypeTuple = 29, 
    RuleTypes = 30, RuleType = 31, RuleArgAttr = 32, RuleTypeVar = 33, RuleTypeVarList = 34, 
    RuleTypeWrapVar1 = 35, RuleTypeWrapVarList1 = 36, RuleTypeWrapVar2 = 37, 
    RuleTypeWrapVarList2 = 38, RuleTypeWrapVar3 = 39, RuleTypeWrapVarList3 = 40, 
    RuleTypeWrapVar4 = 41, RuleTypeWrapVarList4 = 42, RuleQuotStmtPart = 43, 
    RuleIfStmt = 44, RuleQuotStmtExpr = 45, RuleIfExpr = 46, RuleWhileStmt = 47, 
    RuleWhileStmt2 = 48, RuleForHeader1 = 49, RuleForHeader2 = 50, RuleForHeader = 51, 
    RuleForStmt = 52, RuleSwitchStmtPart2Last = 53, RuleQuotStmtExprWrap = 54, 
    RuleSwitchExprPartLast = 55, RuleSwitchStmtPart = 56, RuleSwitchStmt = 57, 
    RuleSwitchStmtPart2 = 58, RuleSwitchStmt2 = 59, RuleSwitchExprPart = 60, 
    RuleSwitchExpr1 = 61, RuleSwitchExprPart2 = 62, RuleSwitchExpr2 = 63, 
    RuleQuotExpr = 64, RuleTupleExprItem = 65, RuleTupleExpr = 66, RuleExprOpt = 67, 
    RuleNewExprItem = 68, RuleNewExpr1 = 69, RuleNewExpr2 = 70, RuleArrayExpr1Cond = 71, 
    RuleArrayExpr1 = 72, RuleArrayExpr2 = 73, RuleArrayExpr3 = 74, RuleLambdaExpr = 75, 
    RuleStrongExprBase = 76, RuleStrongExprPrefix = 77, RuleStrongExprSuffix = 78, 
    RuleStrongExpr = 79, RuleMiddle3OpExpr = 80, RuleMiddle2OpExpr = 81, 
    RuleMiddleAstExpr = 82, RuleMiddleExpr = 83, RuleExpr = 84, RuleIdAssignOpExpr = 85, 
    RuleDefVarStmtPart = 86, RuleIdAssignOpExpr2 = 87, RuleDefVarStmt2Part = 88, 
    RuleDefTypeStmt = 89, RuleNormalStmtPart = 90, RuleNormalStmt = 91, 
    RuleStmt = 92, RulePublicLevel = 93, RuleBlockTemplates = 94, RuleItemName = 95, 
    RuleTypeNameTuple = 96, RuleTypeNameArgsTuple = 97, RuleNameArgsTuple = 98, 
    RuleFuncBody = 99, RuleAnnoArg = 100, RuleAnnoPart = 101, RuleAnnoBlock = 102, 
    RuleImportedConstructFunc = 103, RuleVarAccesser = 104, RuleVarAccesserItems = 105, 
    RuleClassVar = 106, RuleClassFunc = 107, RuleClassBlock = 108, RuleEnumItem = 109, 
    RuleEnumBlock = 110, RuleUseStmt = 111, RuleNamespaceStmt = 112, RuleProgram = 113, 
    RuleProgramEntry = 114
  };

  explicit FaParser(antlr4::TokenStream *input);

  FaParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~FaParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ShiftLAssignOpContext;
  class ShiftRAssignOpContext;
  class AllAssignOpContext;
  class ShiftLOpContext;
  class ShiftROpContext;
  class EndlContext;
  class Endl2Context;
  class QuotFangLContext;
  class QuotFangRContext;
  class QuotJianLContext;
  class QuotJianRContext;
  class QuotHuaLContext;
  class QuotHuaRContext;
  class QuotYuanLContext;
  class QuotYuanRContext;
  class SelfOp2Context;
  class CompareOp2Context;
  class ChangeOp2Context;
  class AllOp2Context;
  class IntNumContext;
  class FloatNumContext;
  class FormatString1PartContext;
  class FormatString1Context;
  class FormatString2PartContext;
  class FormatString2Context;
  class StringLiteralContext;
  class LiteralContext;
  class IdsContext;
  class TypeAfterContext;
  class TypeTupleContext;
  class TypesContext;
  class TypeContext;
  class ArgAttrContext;
  class TypeVarContext;
  class TypeVarListContext;
  class TypeWrapVar1Context;
  class TypeWrapVarList1Context;
  class TypeWrapVar2Context;
  class TypeWrapVarList2Context;
  class TypeWrapVar3Context;
  class TypeWrapVarList3Context;
  class TypeWrapVar4Context;
  class TypeWrapVarList4Context;
  class QuotStmtPartContext;
  class IfStmtContext;
  class QuotStmtExprContext;
  class IfExprContext;
  class WhileStmtContext;
  class WhileStmt2Context;
  class ForHeader1Context;
  class ForHeader2Context;
  class ForHeaderContext;
  class ForStmtContext;
  class SwitchStmtPart2LastContext;
  class QuotStmtExprWrapContext;
  class SwitchExprPartLastContext;
  class SwitchStmtPartContext;
  class SwitchStmtContext;
  class SwitchStmtPart2Context;
  class SwitchStmt2Context;
  class SwitchExprPartContext;
  class SwitchExpr1Context;
  class SwitchExprPart2Context;
  class SwitchExpr2Context;
  class QuotExprContext;
  class TupleExprItemContext;
  class TupleExprContext;
  class ExprOptContext;
  class NewExprItemContext;
  class NewExpr1Context;
  class NewExpr2Context;
  class ArrayExpr1CondContext;
  class ArrayExpr1Context;
  class ArrayExpr2Context;
  class ArrayExpr3Context;
  class LambdaExprContext;
  class StrongExprBaseContext;
  class StrongExprPrefixContext;
  class StrongExprSuffixContext;
  class StrongExprContext;
  class Middle3OpExprContext;
  class Middle2OpExprContext;
  class MiddleAstExprContext;
  class MiddleExprContext;
  class ExprContext;
  class IdAssignOpExprContext;
  class DefVarStmtPartContext;
  class IdAssignOpExpr2Context;
  class DefVarStmt2PartContext;
  class DefTypeStmtContext;
  class NormalStmtPartContext;
  class NormalStmtContext;
  class StmtContext;
  class PublicLevelContext;
  class BlockTemplatesContext;
  class ItemNameContext;
  class TypeNameTupleContext;
  class TypeNameArgsTupleContext;
  class NameArgsTupleContext;
  class FuncBodyContext;
  class AnnoArgContext;
  class AnnoPartContext;
  class AnnoBlockContext;
  class ImportedConstructFuncContext;
  class VarAccesserContext;
  class VarAccesserItemsContext;
  class ClassVarContext;
  class ClassFuncContext;
  class ClassBlockContext;
  class EnumItemContext;
  class EnumBlockContext;
  class UseStmtContext;
  class NamespaceStmtContext;
  class ProgramContext;
  class ProgramEntryContext; 

  class  ShiftLAssignOpContext : public antlr4::ParserRuleContext {
  public:
    ShiftLAssignOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ShiftLOpContext *shiftLOp();
    antlr4::tree::TerminalNode *AssignOp();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ShiftLAssignOpContext* shiftLAssignOp();

  class  ShiftRAssignOpContext : public antlr4::ParserRuleContext {
  public:
    ShiftRAssignOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ShiftROpContext *shiftROp();
    antlr4::tree::TerminalNode *AssignOp();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ShiftRAssignOpContext* shiftRAssignOp();

  class  AllAssignOpContext : public antlr4::ParserRuleContext {
  public:
    AllAssignOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AssignOp();
    antlr4::tree::TerminalNode *QusQusAssignOp();
    antlr4::tree::TerminalNode *AddAssignOp();
    antlr4::tree::TerminalNode *SubAssignOp();
    antlr4::tree::TerminalNode *StarAssignOp();
    antlr4::tree::TerminalNode *StarStarAssignOp();
    antlr4::tree::TerminalNode *DivAssignOp();
    antlr4::tree::TerminalNode *ModAssignOp();
    antlr4::tree::TerminalNode *AndAssignOp();
    antlr4::tree::TerminalNode *OrAssignOp();
    antlr4::tree::TerminalNode *XorAssignOp();
    antlr4::tree::TerminalNode *AndAndAssignOp();
    antlr4::tree::TerminalNode *OrOrAssignOp();
    ShiftLAssignOpContext *shiftLAssignOp();
    ShiftRAssignOpContext *shiftRAssignOp();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AllAssignOpContext* allAssignOp();

  class  ShiftLOpContext : public antlr4::ParserRuleContext {
  public:
    ShiftLOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> LessThan();
    antlr4::tree::TerminalNode* LessThan(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ShiftLOpContext* shiftLOp();

  class  ShiftROpContext : public antlr4::ParserRuleContext {
  public:
    ShiftROpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> GreatThan();
    antlr4::tree::TerminalNode* GreatThan(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ShiftROpContext* shiftROp();

  class  EndlContext : public antlr4::ParserRuleContext {
  public:
    EndlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Lf();
    antlr4::tree::TerminalNode* Lf(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Semi();
    antlr4::tree::TerminalNode* Semi(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EndlContext* endl();

  class  Endl2Context : public antlr4::ParserRuleContext {
  public:
    Endl2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Comma();
    std::vector<antlr4::tree::TerminalNode *> Lf();
    antlr4::tree::TerminalNode* Lf(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Endl2Context* endl2();

  class  QuotFangLContext : public antlr4::ParserRuleContext {
  public:
    QuotFangLContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QFangL();
    EndlContext *endl();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuotFangLContext* quotFangL();

  class  QuotFangRContext : public antlr4::ParserRuleContext {
  public:
    QuotFangRContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QFangR();
    EndlContext *endl();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuotFangRContext* quotFangR();

  class  QuotJianLContext : public antlr4::ParserRuleContext {
  public:
    QuotJianLContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LessThan();
    EndlContext *endl();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuotJianLContext* quotJianL();

  class  QuotJianRContext : public antlr4::ParserRuleContext {
  public:
    QuotJianRContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GreatThan();
    EndlContext *endl();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuotJianRContext* quotJianR();

  class  QuotHuaLContext : public antlr4::ParserRuleContext {
  public:
    QuotHuaLContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QHuaL();
    EndlContext *endl();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuotHuaLContext* quotHuaL();

  class  QuotHuaRContext : public antlr4::ParserRuleContext {
  public:
    QuotHuaRContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QHuaR();
    EndlContext *endl();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuotHuaRContext* quotHuaR();

  class  QuotYuanLContext : public antlr4::ParserRuleContext {
  public:
    QuotYuanLContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QYuanL();
    EndlContext *endl();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuotYuanLContext* quotYuanL();

  class  QuotYuanRContext : public antlr4::ParserRuleContext {
  public:
    QuotYuanRContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QYuanR();
    EndlContext *endl();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuotYuanRContext* quotYuanR();

  class  SelfOp2Context : public antlr4::ParserRuleContext {
  public:
    SelfOp2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AddOp();
    antlr4::tree::TerminalNode *SubOp();
    antlr4::tree::TerminalNode *StarOp();
    antlr4::tree::TerminalNode *DivOp();
    antlr4::tree::TerminalNode *StarStarOp();
    antlr4::tree::TerminalNode *ModOp();
    antlr4::tree::TerminalNode *AndOp();
    antlr4::tree::TerminalNode *OrOp();
    antlr4::tree::TerminalNode *XorOp();
    antlr4::tree::TerminalNode *AndAndOp();
    antlr4::tree::TerminalNode *OrOrOp();
    ShiftLOpContext *shiftLOp();
    ShiftROpContext *shiftROp();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SelfOp2Context* selfOp2();

  class  CompareOp2Context : public antlr4::ParserRuleContext {
  public:
    CompareOp2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LessThan();
    antlr4::tree::TerminalNode *LtEqualOp();
    antlr4::tree::TerminalNode *GreatThan();
    antlr4::tree::TerminalNode *GtEqualOp();
    antlr4::tree::TerminalNode *EqualOp();
    antlr4::tree::TerminalNode *NotEqualOp();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompareOp2Context* compareOp2();

  class  ChangeOp2Context : public antlr4::ParserRuleContext {
  public:
    ChangeOp2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QusQusOp();
    CompareOp2Context *compareOp2();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ChangeOp2Context* changeOp2();

  class  AllOp2Context : public antlr4::ParserRuleContext {
  public:
    AllOp2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SelfOp2Context *selfOp2();
    ChangeOp2Context *changeOp2();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AllOp2Context* allOp2();

  class  IntNumContext : public antlr4::ParserRuleContext {
  public:
    IntNumContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IntLiteral();
    antlr4::tree::TerminalNode *SubOp();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IntNumContext* intNum();

  class  FloatNumContext : public antlr4::ParserRuleContext {
  public:
    FloatNumContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FloatLiteral();
    antlr4::tree::TerminalNode *SubOp();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FloatNumContext* floatNum();

  class  FormatString1PartContext : public antlr4::ParserRuleContext {
  public:
    FormatString1PartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MiddleExprContext *middleExpr();
    antlr4::tree::TerminalNode *Colon();
    antlr4::tree::TerminalNode *FormatString();
    antlr4::tree::TerminalNode *QHuaLQHuaL();
    antlr4::tree::TerminalNode *QHuaRQHuaR();
    antlr4::tree::TerminalNode *RegularCharInside();
    antlr4::tree::TerminalNode *RegularStringInside();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FormatString1PartContext* formatString1Part();

  class  FormatString1Context : public antlr4::ParserRuleContext {
  public:
    FormatString1Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FmtString1();
    antlr4::tree::TerminalNode *DoubleQuoteInside();
    std::vector<FormatString1PartContext *> formatString1Part();
    FormatString1PartContext* formatString1Part(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FormatString1Context* formatString1();

  class  FormatString2PartContext : public antlr4::ParserRuleContext {
  public:
    FormatString2PartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MiddleExprContext *middleExpr();
    antlr4::tree::TerminalNode *Colon();
    antlr4::tree::TerminalNode *FormatString();
    antlr4::tree::TerminalNode *QHuaLQHuaL();
    antlr4::tree::TerminalNode *QHuaRQHuaR();
    antlr4::tree::TerminalNode *VerbatiumDoubleQuoteInside();
    antlr4::tree::TerminalNode *VerbatiumInsideString();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FormatString2PartContext* formatString2Part();

  class  FormatString2Context : public antlr4::ParserRuleContext {
  public:
    FormatString2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FmtString2();
    antlr4::tree::TerminalNode *DoubleQuoteInside();
    std::vector<FormatString2PartContext *> formatString2Part();
    FormatString2PartContext* formatString2Part(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FormatString2Context* formatString2();

  class  StringLiteralContext : public antlr4::ParserRuleContext {
  public:
    StringLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *String1Literal();
    antlr4::tree::TerminalNode *String2Literal();
    antlr4::tree::TerminalNode *String3Literal();
    FormatString1Context *formatString1();
    FormatString2Context *formatString2();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StringLiteralContext* stringLiteral();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BoolLiteral();
    antlr4::tree::TerminalNode *HexLiteral();
    IntNumContext *intNum();
    FloatNumContext *floatNum();
    StringLiteralContext *stringLiteral();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LiteralContext* literal();

  class  IdsContext : public antlr4::ParserRuleContext {
  public:
    IdsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Id();
    antlr4::tree::TerminalNode* Id(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PointOp();
    antlr4::tree::TerminalNode* PointOp(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdsContext* ids();

  class  TypeAfterContext : public antlr4::ParserRuleContext {
  public:
    TypeAfterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuotFangLContext *quotFangL();
    QuotFangRContext *quotFangR();
    antlr4::tree::TerminalNode *Qus();
    antlr4::tree::TerminalNode *ColonColon();
    antlr4::tree::TerminalNode *Base();
    antlr4::tree::TerminalNode *IntLiteral();
    QuotJianLContext *quotJianL();
    TypesContext *types();
    QuotJianRContext *quotJianR();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeAfterContext* typeAfter();

  class  TypeTupleContext : public antlr4::ParserRuleContext {
  public:
    TypeTupleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuotYuanLContext *quotYuanL();
    std::vector<TypeVarContext *> typeVar();
    TypeVarContext* typeVar(size_t i);
    QuotYuanRContext *quotYuanR();
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeTupleContext* typeTuple();

  class  TypesContext : public antlr4::ParserRuleContext {
  public:
    TypesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypesContext* types();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdsContext *ids();
    TypeTupleContext *typeTuple();
    antlr4::tree::TerminalNode *Type();
    std::vector<TypeAfterContext *> typeAfter();
    TypeAfterContext* typeAfter(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeContext* type();

  class  ArgAttrContext : public antlr4::ParserRuleContext {
  public:
    ArgAttrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Mut();
    antlr4::tree::TerminalNode *Params();
    antlr4::tree::TerminalNode *Disperse();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgAttrContext* argAttr();

  class  TypeVarContext : public antlr4::ParserRuleContext {
  public:
    TypeVarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *Id();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeVarContext* typeVar();

  class  TypeVarListContext : public antlr4::ParserRuleContext {
  public:
    TypeVarListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypeVarContext *> typeVar();
    TypeVarContext* typeVar(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeVarListContext* typeVarList();

  class  TypeWrapVar1Context : public antlr4::ParserRuleContext {
  public:
    TypeWrapVar1Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Id();
    antlr4::tree::TerminalNode *Colon();
    TypeContext *type();
    ArgAttrContext *argAttr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeWrapVar1Context* typeWrapVar1();

  class  TypeWrapVarList1Context : public antlr4::ParserRuleContext {
  public:
    TypeWrapVarList1Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypeWrapVar1Context *> typeWrapVar1();
    TypeWrapVar1Context* typeWrapVar1(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeWrapVarList1Context* typeWrapVarList1();

  class  TypeWrapVar2Context : public antlr4::ParserRuleContext {
  public:
    TypeWrapVar2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    ArgAttrContext *argAttr();
    antlr4::tree::TerminalNode *Id();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeWrapVar2Context* typeWrapVar2();

  class  TypeWrapVarList2Context : public antlr4::ParserRuleContext {
  public:
    TypeWrapVarList2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypeWrapVar2Context *> typeWrapVar2();
    TypeWrapVar2Context* typeWrapVar2(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeWrapVarList2Context* typeWrapVarList2();

  class  TypeWrapVar3Context : public antlr4::ParserRuleContext {
  public:
    TypeWrapVar3Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Id();
    TypeContext *type();
    ArgAttrContext *argAttr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeWrapVar3Context* typeWrapVar3();

  class  TypeWrapVarList3Context : public antlr4::ParserRuleContext {
  public:
    TypeWrapVarList3Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypeWrapVar3Context *> typeWrapVar3();
    TypeWrapVar3Context* typeWrapVar3(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeWrapVarList3Context* typeWrapVarList3();

  class  TypeWrapVar4Context : public antlr4::ParserRuleContext {
  public:
    TypeWrapVar4Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Id();
    ArgAttrContext *argAttr();
    antlr4::tree::TerminalNode *Colon();
    TypeContext *type();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeWrapVar4Context* typeWrapVar4();

  class  TypeWrapVarList4Context : public antlr4::ParserRuleContext {
  public:
    TypeWrapVarList4Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypeWrapVar4Context *> typeWrapVar4();
    TypeWrapVar4Context* typeWrapVar4(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeWrapVarList4Context* typeWrapVarList4();

  class  QuotStmtPartContext : public antlr4::ParserRuleContext {
  public:
    QuotStmtPartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuotHuaLContext *quotHuaL();
    QuotHuaRContext *quotHuaR();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuotStmtPartContext* quotStmtPart();

  class  IfStmtContext : public antlr4::ParserRuleContext {
  public:
    IfStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> If();
    antlr4::tree::TerminalNode* If(size_t i);
    std::vector<MiddleExprContext *> middleExpr();
    MiddleExprContext* middleExpr(size_t i);
    std::vector<QuotStmtPartContext *> quotStmtPart();
    QuotStmtPartContext* quotStmtPart(size_t i);
    EndlContext *endl();
    std::vector<antlr4::tree::TerminalNode *> Else();
    antlr4::tree::TerminalNode* Else(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfStmtContext* ifStmt();

  class  QuotStmtExprContext : public antlr4::ParserRuleContext {
  public:
    QuotStmtExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuotHuaLContext *quotHuaL();
    ExprContext *expr();
    QuotHuaRContext *quotHuaR();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuotStmtExprContext* quotStmtExpr();

  class  IfExprContext : public antlr4::ParserRuleContext {
  public:
    IfExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> If();
    antlr4::tree::TerminalNode* If(size_t i);
    std::vector<MiddleExprContext *> middleExpr();
    MiddleExprContext* middleExpr(size_t i);
    std::vector<QuotStmtExprContext *> quotStmtExpr();
    QuotStmtExprContext* quotStmtExpr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Else();
    antlr4::tree::TerminalNode* Else(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfExprContext* ifExpr();

  class  WhileStmtContext : public antlr4::ParserRuleContext {
  public:
    WhileStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *While();
    MiddleExprContext *middleExpr();
    QuotHuaLContext *quotHuaL();
    QuotHuaRContext *quotHuaR();
    EndlContext *endl();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhileStmtContext* whileStmt();

  class  WhileStmt2Context : public antlr4::ParserRuleContext {
  public:
    WhileStmt2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Do();
    QuotHuaLContext *quotHuaL();
    QuotHuaRContext *quotHuaR();
    antlr4::tree::TerminalNode *While();
    MiddleExprContext *middleExpr();
    EndlContext *endl();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhileStmt2Context* whileStmt2();

  class  ForHeader1Context : public antlr4::ParserRuleContext {
  public:
    ForHeader1Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Colon();
    MiddleExprContext *middleExpr();
    antlr4::tree::TerminalNode *AstClassVar();
    TypeContext *type();
    std::vector<antlr4::tree::TerminalNode *> Id();
    antlr4::tree::TerminalNode* Id(size_t i);
    QuotYuanLContext *quotYuanL();
    QuotYuanRContext *quotYuanR();
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForHeader1Context* forHeader1();

  class  ForHeader2Context : public antlr4::ParserRuleContext {
  public:
    ForHeader2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Semi();
    antlr4::tree::TerminalNode* Semi(size_t i);
    MiddleExprContext *middleExpr();
    ExprContext *expr();
    DefVarStmtPartContext *defVarStmtPart();
    DefVarStmt2PartContext *defVarStmt2Part();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForHeader2Context* forHeader2();

  class  ForHeaderContext : public antlr4::ParserRuleContext {
  public:
    ForHeaderContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ForHeader1Context *forHeader1();
    ForHeader2Context *forHeader2();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForHeaderContext* forHeader();

  class  ForStmtContext : public antlr4::ParserRuleContext {
  public:
    ForStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *For();
    QuotHuaLContext *quotHuaL();
    QuotHuaRContext *quotHuaR();
    EndlContext *endl();
    ForHeaderContext *forHeader();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);
    QuotYuanLContext *quotYuanL();
    QuotYuanRContext *quotYuanR();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForStmtContext* forStmt();

  class  SwitchStmtPart2LastContext : public antlr4::ParserRuleContext {
  public:
    SwitchStmtPart2LastContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Underline();
    antlr4::tree::TerminalNode *ExprFuncDef();
    StmtContext *stmt();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SwitchStmtPart2LastContext* switchStmtPart2Last();

  class  QuotStmtExprWrapContext : public antlr4::ParserRuleContext {
  public:
    QuotStmtExprWrapContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuotStmtExprContext *quotStmtExpr();
    ExprContext *expr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuotStmtExprWrapContext* quotStmtExprWrap();

  class  SwitchExprPartLastContext : public antlr4::ParserRuleContext {
  public:
    SwitchExprPartLastContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Underline();
    antlr4::tree::TerminalNode *ExprFuncDef();
    QuotStmtExprWrapContext *quotStmtExprWrap();
    Endl2Context *endl2();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SwitchExprPartLastContext* switchExprPartLast();

  class  SwitchStmtPartContext : public antlr4::ParserRuleContext {
  public:
    SwitchStmtPartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *ExprFuncDef();
    StmtContext *stmt();
    antlr4::tree::TerminalNode *When();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SwitchStmtPartContext* switchStmtPart();

  class  SwitchStmtContext : public antlr4::ParserRuleContext {
  public:
    SwitchStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Switch();
    ExprContext *expr();
    QuotHuaLContext *quotHuaL();
    QuotHuaRContext *quotHuaR();
    EndlContext *endl();
    std::vector<SwitchStmtPartContext *> switchStmtPart();
    SwitchStmtPartContext* switchStmtPart(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SwitchStmtContext* switchStmt();

  class  SwitchStmtPart2Context : public antlr4::ParserRuleContext {
  public:
    SwitchStmtPart2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *When();
    ExprContext *expr();
    antlr4::tree::TerminalNode *ExprFuncDef();
    StmtContext *stmt();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SwitchStmtPart2Context* switchStmtPart2();

  class  SwitchStmt2Context : public antlr4::ParserRuleContext {
  public:
    SwitchStmt2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Switch();
    QuotHuaLContext *quotHuaL();
    SwitchStmtPart2LastContext *switchStmtPart2Last();
    QuotHuaRContext *quotHuaR();
    EndlContext *endl();
    std::vector<SwitchStmtPart2Context *> switchStmtPart2();
    SwitchStmtPart2Context* switchStmtPart2(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SwitchStmt2Context* switchStmt2();

  class  SwitchExprPartContext : public antlr4::ParserRuleContext {
  public:
    SwitchExprPartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *ExprFuncDef();
    QuotStmtExprWrapContext *quotStmtExprWrap();
    Endl2Context *endl2();
    antlr4::tree::TerminalNode *When();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SwitchExprPartContext* switchExprPart();

  class  SwitchExpr1Context : public antlr4::ParserRuleContext {
  public:
    SwitchExpr1Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SwitchExpr();
    ExprContext *expr();
    QuotHuaLContext *quotHuaL();
    SwitchExprPartLastContext *switchExprPartLast();
    QuotHuaRContext *quotHuaR();
    std::vector<SwitchExprPartContext *> switchExprPart();
    SwitchExprPartContext* switchExprPart(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SwitchExpr1Context* switchExpr1();

  class  SwitchExprPart2Context : public antlr4::ParserRuleContext {
  public:
    SwitchExprPart2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *When();
    ExprContext *expr();
    antlr4::tree::TerminalNode *ExprFuncDef();
    QuotStmtExprWrapContext *quotStmtExprWrap();
    Endl2Context *endl2();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SwitchExprPart2Context* switchExprPart2();

  class  SwitchExpr2Context : public antlr4::ParserRuleContext {
  public:
    SwitchExpr2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SwitchExpr();
    QuotHuaLContext *quotHuaL();
    SwitchExprPartLastContext *switchExprPartLast();
    QuotHuaRContext *quotHuaR();
    std::vector<SwitchExprPart2Context *> switchExprPart2();
    SwitchExprPart2Context* switchExprPart2(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SwitchExpr2Context* switchExpr2();

  class  QuotExprContext : public antlr4::ParserRuleContext {
  public:
    QuotExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuotYuanLContext *quotYuanL();
    ExprContext *expr();
    QuotYuanRContext *quotYuanR();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuotExprContext* quotExpr();

  class  TupleExprItemContext : public antlr4::ParserRuleContext {
  public:
    TupleExprItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MiddleExprContext *middleExpr();
    antlr4::tree::TerminalNode *Id();
    antlr4::tree::TerminalNode *Colon();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TupleExprItemContext* tupleExprItem();

  class  TupleExprContext : public antlr4::ParserRuleContext {
  public:
    TupleExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuotYuanLContext *quotYuanL();
    std::vector<TupleExprItemContext *> tupleExprItem();
    TupleExprItemContext* tupleExprItem(size_t i);
    QuotYuanRContext *quotYuanR();
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TupleExprContext* tupleExpr();

  class  ExprOptContext : public antlr4::ParserRuleContext {
  public:
    ExprOptContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprOptContext* exprOpt();

  class  NewExprItemContext : public antlr4::ParserRuleContext {
  public:
    NewExprItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Id();
    antlr4::tree::TerminalNode *AssignOp();
    MiddleExprContext *middleExpr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NewExprItemContext* newExprItem();

  class  NewExpr1Context : public antlr4::ParserRuleContext {
  public:
    NewExpr1Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *New();
    QuotHuaLContext *quotHuaL();
    QuotHuaRContext *quotHuaR();
    TypeContext *type();
    std::vector<NewExprItemContext *> newExprItem();
    NewExprItemContext* newExprItem(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NewExpr1Context* newExpr1();

  class  NewExpr2Context : public antlr4::ParserRuleContext {
  public:
    NewExpr2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *New();
    QuotYuanLContext *quotYuanL();
    QuotYuanRContext *quotYuanR();
    TypeContext *type();
    std::vector<MiddleExprContext *> middleExpr();
    MiddleExprContext* middleExpr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NewExpr2Context* newExpr2();

  class  ArrayExpr1CondContext : public antlr4::ParserRuleContext {
  public:
    ArrayExpr1CondContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Where();
    MiddleExprContext *middleExpr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayExpr1CondContext* arrayExpr1Cond();

  class  ArrayExpr1Context : public antlr4::ParserRuleContext {
  public:
    ArrayExpr1Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuotFangLContext *quotFangL();
    antlr4::tree::TerminalNode *From();
    antlr4::tree::TerminalNode *In();
    std::vector<MiddleExprContext *> middleExpr();
    MiddleExprContext* middleExpr(size_t i);
    QuotFangRContext *quotFangR();
    antlr4::tree::TerminalNode *Select();
    antlr4::tree::TerminalNode *Run();
    std::vector<antlr4::tree::TerminalNode *> Id();
    antlr4::tree::TerminalNode* Id(size_t i);
    std::vector<ArrayExpr1CondContext *> arrayExpr1Cond();
    ArrayExpr1CondContext* arrayExpr1Cond(size_t i);
    QuotYuanLContext *quotYuanL();
    QuotYuanRContext *quotYuanR();
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayExpr1Context* arrayExpr1();

  class  ArrayExpr2Context : public antlr4::ParserRuleContext {
  public:
    ArrayExpr2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuotFangLContext *quotFangL();
    QuotFangRContext *quotFangR();
    std::vector<MiddleExprContext *> middleExpr();
    MiddleExprContext* middleExpr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayExpr2Context* arrayExpr2();

  class  ArrayExpr3Context : public antlr4::ParserRuleContext {
  public:
    ArrayExpr3Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuotFangLContext *quotFangL();
    std::vector<MiddleExprContext *> middleExpr();
    MiddleExprContext* middleExpr(size_t i);
    antlr4::tree::TerminalNode *PointPoint();
    QuotFangRContext *quotFangR();
    antlr4::tree::TerminalNode *Comma();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayExpr3Context* arrayExpr3();

  class  LambdaExprContext : public antlr4::ParserRuleContext {
  public:
    LambdaExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Id();
    antlr4::tree::TerminalNode *ExprFuncDef();
    QuotYuanLContext *quotYuanL();
    QuotYuanRContext *quotYuanR();
    MiddleExprContext *middleExpr();
    QuotHuaLContext *quotHuaL();
    QuotHuaRContext *quotHuaR();
    TypeWrapVarList3Context *typeWrapVarList3();
    TypeWrapVarList4Context *typeWrapVarList4();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LambdaExprContext* lambdaExpr();

  class  StrongExprBaseContext : public antlr4::ParserRuleContext {
  public:
    StrongExprBaseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdsContext *ids();
    antlr4::tree::TerminalNode *ColonColon();
    LiteralContext *literal();
    LambdaExprContext *lambdaExpr();
    QuotExprContext *quotExpr();
    TupleExprContext *tupleExpr();
    NewExpr1Context *newExpr1();
    NewExpr2Context *newExpr2();
    ArrayExpr1Context *arrayExpr1();
    ArrayExpr2Context *arrayExpr2();
    ArrayExpr3Context *arrayExpr3();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StrongExprBaseContext* strongExprBase();

  class  StrongExprPrefixContext : public antlr4::ParserRuleContext {
  public:
    StrongExprPrefixContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SubOp();
    antlr4::tree::TerminalNode *AddAddOp();
    antlr4::tree::TerminalNode *SubSubOp();
    antlr4::tree::TerminalNode *ReverseOp();
    antlr4::tree::TerminalNode *Exclam();
    antlr4::tree::TerminalNode *Cast();
    QuotJianLContext *quotJianL();
    TypeContext *type();
    QuotJianRContext *quotJianR();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StrongExprPrefixContext* strongExprPrefix();

  class  StrongExprSuffixContext : public antlr4::ParserRuleContext {
  public:
    StrongExprSuffixContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AddAddOp();
    antlr4::tree::TerminalNode *SubSubOp();
    QuotYuanLContext *quotYuanL();
    QuotYuanRContext *quotYuanR();
    std::vector<MiddleExprContext *> middleExpr();
    MiddleExprContext* middleExpr(size_t i);
    std::vector<Endl2Context *> endl2();
    Endl2Context* endl2(size_t i);
    QuotFangLContext *quotFangL();
    QuotFangRContext *quotFangR();
    std::vector<ExprOptContext *> exprOpt();
    ExprOptContext* exprOpt(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Colon();
    antlr4::tree::TerminalNode* Colon(size_t i);
    QuotJianLContext *quotJianL();
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    QuotJianRContext *quotJianR();
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);
    antlr4::tree::TerminalNode *PointOp();
    antlr4::tree::TerminalNode *Id();
    antlr4::tree::TerminalNode *Qus();
    antlr4::tree::TerminalNode *Is();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StrongExprSuffixContext* strongExprSuffix();

  class  StrongExprContext : public antlr4::ParserRuleContext {
  public:
    StrongExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StrongExprBaseContext *strongExprBase();
    std::vector<StrongExprPrefixContext *> strongExprPrefix();
    StrongExprPrefixContext* strongExprPrefix(size_t i);
    std::vector<StrongExprSuffixContext *> strongExprSuffix();
    StrongExprSuffixContext* strongExprSuffix(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StrongExprContext* strongExpr();

  class  Middle3OpExprContext : public antlr4::ParserRuleContext {
  public:
    Middle3OpExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StrongExprContext *> strongExpr();
    StrongExprContext* strongExpr(size_t i);
    antlr4::tree::TerminalNode *Qus();
    antlr4::tree::TerminalNode *Colon();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Middle3OpExprContext* middle3OpExpr();

  class  Middle2OpExprContext : public antlr4::ParserRuleContext {
  public:
    Middle2OpExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StrongExprContext *> strongExpr();
    StrongExprContext* strongExpr(size_t i);
    std::vector<AllOp2Context *> allOp2();
    AllOp2Context* allOp2(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Middle2OpExprContext* middle2OpExpr();

  class  MiddleAstExprContext : public antlr4::ParserRuleContext {
  public:
    MiddleAstExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Stmt();
    NormalStmtPartContext *normalStmtPart();
    antlr4::tree::TerminalNode *Expr();
    Middle2OpExprContext *middle2OpExpr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MiddleAstExprContext* middleAstExpr();

  class  MiddleExprContext : public antlr4::ParserRuleContext {
  public:
    MiddleExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Middle3OpExprContext *middle3OpExpr();
    Middle2OpExprContext *middle2OpExpr();
    MiddleAstExprContext *middleAstExpr();
    antlr4::tree::TerminalNode *Calc();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MiddleExprContext* middleExpr();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IfExprContext *ifExpr();
    SwitchExpr2Context *switchExpr2();
    SwitchExpr1Context *switchExpr1();
    MiddleExprContext *middleExpr();
    std::vector<StrongExprContext *> strongExpr();
    StrongExprContext* strongExpr(size_t i);
    std::vector<AllAssignOpContext *> allAssignOp();
    AllAssignOpContext* allAssignOp(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprContext* expr();

  class  IdAssignOpExprContext : public antlr4::ParserRuleContext {
  public:
    IdAssignOpExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Id();
    antlr4::tree::TerminalNode *AssignOp();
    MiddleExprContext *middleExpr();
    antlr4::tree::TerminalNode *Colon();
    TypeContext *type();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdAssignOpExprContext* idAssignOpExpr();

  class  DefVarStmtPartContext : public antlr4::ParserRuleContext {
  public:
    DefVarStmtPartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AstClassVar();
    std::vector<IdAssignOpExprContext *> idAssignOpExpr();
    IdAssignOpExprContext* idAssignOpExpr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefVarStmtPartContext* defVarStmtPart();

  class  IdAssignOpExpr2Context : public antlr4::ParserRuleContext {
  public:
    IdAssignOpExpr2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Id();
    antlr4::tree::TerminalNode *AssignOp();
    MiddleExprContext *middleExpr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdAssignOpExpr2Context* idAssignOpExpr2();

  class  DefVarStmt2PartContext : public antlr4::ParserRuleContext {
  public:
    DefVarStmt2PartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    std::vector<IdAssignOpExpr2Context *> idAssignOpExpr2();
    IdAssignOpExpr2Context* idAssignOpExpr2(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefVarStmt2PartContext* defVarStmt2Part();

  class  DefTypeStmtContext : public antlr4::ParserRuleContext {
  public:
    DefTypeStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Type();
    antlr4::tree::TerminalNode *Id();
    antlr4::tree::TerminalNode *AssignOp();
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    EndlContext *endl();
    std::vector<antlr4::tree::TerminalNode *> OrOrOp();
    antlr4::tree::TerminalNode* OrOrOp(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefTypeStmtContext* defTypeStmt();

  class  NormalStmtPartContext : public antlr4::ParserRuleContext {
  public:
    NormalStmtPartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    antlr4::tree::TerminalNode *Return();
    antlr4::tree::TerminalNode *Break();
    antlr4::tree::TerminalNode *Continue();
    DefVarStmtPartContext *defVarStmtPart();
    DefVarStmt2PartContext *defVarStmt2Part();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NormalStmtPartContext* normalStmtPart();

  class  NormalStmtContext : public antlr4::ParserRuleContext {
  public:
    NormalStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NormalStmtPartContext *normalStmtPart();
    EndlContext *endl();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NormalStmtContext* normalStmt();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IfStmtContext *ifStmt();
    WhileStmtContext *whileStmt();
    WhileStmt2Context *whileStmt2();
    ForStmtContext *forStmt();
    QuotStmtPartContext *quotStmtPart();
    EndlContext *endl();
    SwitchStmt2Context *switchStmt2();
    SwitchStmtContext *switchStmt();
    NormalStmtContext *normalStmt();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StmtContext* stmt();

  class  PublicLevelContext : public antlr4::ParserRuleContext {
  public:
    PublicLevelContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Public();
    antlr4::tree::TerminalNode *Internal();
    antlr4::tree::TerminalNode *Protected();
    antlr4::tree::TerminalNode *Private();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PublicLevelContext* publicLevel();

  class  BlockTemplatesContext : public antlr4::ParserRuleContext {
  public:
    BlockTemplatesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuotJianLContext *quotJianL();
    std::vector<antlr4::tree::TerminalNode *> Id();
    antlr4::tree::TerminalNode* Id(size_t i);
    QuotJianRContext *quotJianR();
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockTemplatesContext* blockTemplates();

  class  ItemNameContext : public antlr4::ParserRuleContext {
  public:
    ItemNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Id();
    antlr4::tree::TerminalNode *Operator();
    AllOp2Context *allOp2();
    antlr4::tree::TerminalNode *QFangL();
    antlr4::tree::TerminalNode *QFangR();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ItemNameContext* itemName();

  class  TypeNameTupleContext : public antlr4::ParserRuleContext {
  public:
    TypeNameTupleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ItemNameContext *itemName();
    antlr4::tree::TerminalNode *Colon();
    TypeContext *type();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeNameTupleContext* typeNameTuple();

  class  TypeNameArgsTupleContext : public antlr4::ParserRuleContext {
  public:
    TypeNameArgsTupleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ItemNameContext *itemName();
    QuotYuanLContext *quotYuanL();
    QuotYuanRContext *quotYuanR();
    antlr4::tree::TerminalNode *Colon();
    TypeContext *type();
    BlockTemplatesContext *blockTemplates();
    TypeWrapVarList1Context *typeWrapVarList1();
    TypeWrapVarList2Context *typeWrapVarList2();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeNameArgsTupleContext* typeNameArgsTuple();

  class  NameArgsTupleContext : public antlr4::ParserRuleContext {
  public:
    NameArgsTupleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Id();
    QuotYuanLContext *quotYuanL();
    QuotYuanRContext *quotYuanR();
    TypeWrapVarList1Context *typeWrapVarList1();
    TypeWrapVarList2Context *typeWrapVarList2();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NameArgsTupleContext* nameArgsTuple();

  class  FuncBodyContext : public antlr4::ParserRuleContext {
  public:
    FuncBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ExprFuncDef();
    ExprContext *expr();
    QuotHuaLContext *quotHuaL();
    QuotHuaRContext *quotHuaR();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncBodyContext* funcBody();

  class  AnnoArgContext : public antlr4::ParserRuleContext {
  public:
    AnnoArgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Id();
    antlr4::tree::TerminalNode *AssignOp();
    MiddleExprContext *middleExpr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnnoArgContext* annoArg();

  class  AnnoPartContext : public antlr4::ParserRuleContext {
  public:
    AnnoPartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Id();
    EndlContext *endl();
    QuotHuaLContext *quotHuaL();
    QuotHuaRContext *quotHuaR();
    std::vector<AnnoArgContext *> annoArg();
    AnnoArgContext* annoArg(size_t i);
    std::vector<Endl2Context *> endl2();
    Endl2Context* endl2(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnnoPartContext* annoPart();

  class  AnnoBlockContext : public antlr4::ParserRuleContext {
  public:
    AnnoBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Annotation();
    antlr4::tree::TerminalNode *Id();
    QuotHuaLContext *quotHuaL();
    QuotHuaRContext *quotHuaR();
    EndlContext *endl();
    std::vector<AnnoPartContext *> annoPart();
    AnnoPartContext* annoPart(size_t i);
    std::vector<ClassVarContext *> classVar();
    ClassVarContext* classVar(size_t i);
    std::vector<ClassFuncContext *> classFunc();
    ClassFuncContext* classFunc(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnnoBlockContext* annoBlock();

  class  ImportedConstructFuncContext : public antlr4::ParserRuleContext {
  public:
    ImportedConstructFuncContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameArgsTupleContext *nameArgsTuple();
    EndlContext *endl();
    std::vector<AnnoPartContext *> annoPart();
    AnnoPartContext* annoPart(size_t i);
    PublicLevelContext *publicLevel();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ImportedConstructFuncContext* importedConstructFunc();

  class  VarAccesserContext : public antlr4::ParserRuleContext {
  public:
    VarAccesserContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Get();
    antlr4::tree::TerminalNode *Set();
    PublicLevelContext *publicLevel();
    FuncBodyContext *funcBody();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarAccesserContext* varAccesser();

  class  VarAccesserItemsContext : public antlr4::ParserRuleContext {
  public:
    VarAccesserItemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<VarAccesserContext *> varAccesser();
    VarAccesserContext* varAccesser(size_t i);
    std::vector<EndlContext *> endl();
    EndlContext* endl(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarAccesserItemsContext* varAccesserItems();

  class  ClassVarContext : public antlr4::ParserRuleContext {
  public:
    ClassVarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeNameTupleContext *typeNameTuple();
    EndlContext *endl();
    std::vector<AnnoPartContext *> annoPart();
    AnnoPartContext* annoPart(size_t i);
    PublicLevelContext *publicLevel();
    antlr4::tree::TerminalNode *Static();
    QuotHuaLContext *quotHuaL();
    VarAccesserItemsContext *varAccesserItems();
    QuotHuaRContext *quotHuaR();
    antlr4::tree::TerminalNode *AssignOp();
    MiddleExprContext *middleExpr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassVarContext* classVar();

  class  ClassFuncContext : public antlr4::ParserRuleContext {
  public:
    ClassFuncContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeNameArgsTupleContext *typeNameArgsTuple();
    EndlContext *endl();
    std::vector<AnnoPartContext *> annoPart();
    AnnoPartContext* annoPart(size_t i);
    PublicLevelContext *publicLevel();
    antlr4::tree::TerminalNode *Static();
    FuncBodyContext *funcBody();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassFuncContext* classFunc();

  class  ClassBlockContext : public antlr4::ParserRuleContext {
  public:
    ClassBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Class();
    antlr4::tree::TerminalNode *Id();
    QuotHuaLContext *quotHuaL();
    QuotHuaRContext *quotHuaR();
    EndlContext *endl();
    std::vector<AnnoPartContext *> annoPart();
    AnnoPartContext* annoPart(size_t i);
    PublicLevelContext *publicLevel();
    BlockTemplatesContext *blockTemplates();
    std::vector<ClassVarContext *> classVar();
    ClassVarContext* classVar(size_t i);
    std::vector<ClassFuncContext *> classFunc();
    ClassFuncContext* classFunc(size_t i);
    std::vector<ImportedConstructFuncContext *> importedConstructFunc();
    ImportedConstructFuncContext* importedConstructFunc(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassBlockContext* classBlock();

  class  EnumItemContext : public antlr4::ParserRuleContext {
  public:
    EnumItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Id();
    std::vector<AnnoPartContext *> annoPart();
    AnnoPartContext* annoPart(size_t i);
    QuotYuanLContext *quotYuanL();
    TypeContext *type();
    QuotYuanRContext *quotYuanR();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumItemContext* enumItem();

  class  EnumBlockContext : public antlr4::ParserRuleContext {
  public:
    EnumBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Enum();
    antlr4::tree::TerminalNode *Id();
    QuotHuaLContext *quotHuaL();
    QuotHuaRContext *quotHuaR();
    EndlContext *endl();
    std::vector<EnumItemContext *> enumItem();
    EnumItemContext* enumItem(size_t i);
    std::vector<AnnoPartContext *> annoPart();
    AnnoPartContext* annoPart(size_t i);
    PublicLevelContext *publicLevel();
    BlockTemplatesContext *blockTemplates();
    std::vector<Endl2Context *> endl2();
    Endl2Context* endl2(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumBlockContext* enumBlock();

  class  UseStmtContext : public antlr4::ParserRuleContext {
  public:
    UseStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Use();
    IdsContext *ids();
    EndlContext *endl();
    antlr4::tree::TerminalNode *Id();
    antlr4::tree::TerminalNode *AssignOp();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UseStmtContext* useStmt();

  class  NamespaceStmtContext : public antlr4::ParserRuleContext {
  public:
    NamespaceStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Namespace();
    IdsContext *ids();
    EndlContext *endl();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NamespaceStmtContext* namespaceStmt();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<EndlContext *> endl();
    EndlContext* endl(size_t i);
    std::vector<UseStmtContext *> useStmt();
    UseStmtContext* useStmt(size_t i);
    NamespaceStmtContext *namespaceStmt();
    std::vector<DefTypeStmtContext *> defTypeStmt();
    DefTypeStmtContext* defTypeStmt(size_t i);
    std::vector<AnnoBlockContext *> annoBlock();
    AnnoBlockContext* annoBlock(size_t i);
    std::vector<EnumBlockContext *> enumBlock();
    EnumBlockContext* enumBlock(size_t i);
    std::vector<ClassBlockContext *> classBlock();
    ClassBlockContext* classBlock(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  ProgramEntryContext : public antlr4::ParserRuleContext {
  public:
    ProgramEntryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProgramContext *program();
    antlr4::tree::TerminalNode *EOF();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramEntryContext* programEntry();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};


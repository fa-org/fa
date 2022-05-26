
// Generated from Fa.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"




class  FaParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, AImport = 9, ALib = 10, Break = 11, CC__Cdecl = 12, CC__FastCall = 13, 
    CC__StdCall = 14, Continue = 15, Class = 16, Const = 17, Do = 18, Else = 19, 
    Enum = 20, FaMain = 21, For = 22, If = 23, Is = 24, Internal = 25, Mut = 26, 
    Namespace = 27, New = 28, Params = 29, Public = 30, Protected = 31, 
    Private = 32, Return = 33, Signed = 34, Static = 35, Step = 36, Switch = 37, 
    Unsigned = 38, Use = 39, When = 40, While = 41, Assign = 42, AddAssign = 43, 
    SubAssign = 44, StarAssign = 45, DivAssign = 46, ModAssign = 47, OrAssign = 48, 
    AndAssign = 49, XorAssign = 50, QusQusAssign = 51, StarStarAssign = 52, 
    AndAndAssign = 53, OrOrAssign = 54, ReverseOp = 55, AddAddOp = 56, SubSubOp = 57, 
    Exclam = 58, PointPoint = 59, PointOp = 60, AddOp = 61, SubOp = 62, 
    StarOp = 63, DivOp = 64, ModOp = 65, OrOp = 66, AndOp = 67, XorOp = 68, 
    QusQusOp = 69, StarStarOp = 70, AndAndOp = 71, OrOrOp = 72, Qus = 73, 
    Comma = 74, ColonColon = 75, Colon = 76, NewLine = 77, Semi = 78, Underline = 79, 
    BoolLiteral = 80, IntLiteral = 81, FloatLiteral = 82, String1Literal = 83, 
    RawId = 84, Comment1 = 85, Comment2 = 86, WS = 87
  };

  enum {
    RuleShiftLAssign = 0, RuleShiftRAssign = 1, RuleAllAssign = 2, RuleShiftLOp = 3, 
    RuleShiftROp = 4, RuleEndStmt = 5, RuleEndStmt2 = 6, RuleQuotFangL = 7, 
    RuleQuotFangR = 8, RuleQuotJianL = 9, RuleQuotJianR = 10, RuleQuotHuaL = 11, 
    RuleQuotHuaR = 12, RuleQuotYuanL = 13, RuleQuotYuanR = 14, RuleLtOp = 15, 
    RuleLtEqualOp = 16, RuleGtOp = 17, RuleGtEqualOp = 18, RuleEqualOp = 19, 
    RuleNotEqualOp = 20, RuleExprFuncDef = 21, RuleSelfOp2 = 22, RuleCompareOp2 = 23, 
    RuleChangeOp2 = 24, RuleAllOp2 = 25, RuleIntNum = 26, RuleFloatNum = 27, 
    RuleLiteral = 28, RuleId = 29, RuleIds = 30, RuleIdExt = 31, RuleTypeAfter = 32, 
    RuleTypeSingle = 33, RuleTypeMulti = 34, RuleType = 35, RuleTypeWrap = 36, 
    RuleTypeVar = 37, RuleTypeVarList = 38, RuleTypeWrapVar = 39, RuleTypeWrapVarList = 40, 
    RuleTypeWrapVar2 = 41, RuleTypeWrapVar2List = 42, RuleQuotStmtPart = 43, 
    RuleQuotStmtExpr = 44, RuleIfStmt = 45, RuleIfExpr = 46, RuleWhileStmt = 47, 
    RuleWhileStmt2 = 48, RuleForStmt = 49, RuleForStmt2 = 50, RuleSwitchStmtPart2Last = 51, 
    RuleQuotStmtExprWrap = 52, RuleSwitchExprPartLast = 53, RuleSwitchStmtPart = 54, 
    RuleSwitchStmt = 55, RuleSwitchStmtPart2 = 56, RuleSwitchStmt2 = 57, 
    RuleSwitchExprPart = 58, RuleSwitchExpr = 59, RuleSwitchExprPart2 = 60, 
    RuleSwitchExpr2 = 61, RuleQuotExpr = 62, RuleExprOpt = 63, RuleNewExprItem = 64, 
    RuleNewExpr1 = 65, RuleNewExpr2 = 66, RuleArrayExpr1 = 67, RuleArrayExpr2 = 68, 
    RuleLambdaExpr = 69, RuleStrongExprBase = 70, RuleStrongExprPrefix = 71, 
    RuleStrongExprSuffix = 72, RuleStrongExpr = 73, RuleMiddleExpr = 74, 
    RuleExpr = 75, RuleTmpAssignExpr = 76, RuleIdAssignExpr = 77, RuleDefVarStmt = 78, 
    RuleNormalStmt = 79, RuleStmt = 80, RulePublicLevel = 81, RuleEnumItem = 82, 
    RuleClassItemFuncExtBody = 83, RuleClassItemFuncExt = 84, RuleClassItem = 85, 
    RuleEnumBlock = 86, RuleClassBlock = 87, RuleUseStmt = 88, RuleCallConvention = 89, 
    RuleImportStmt = 90, RuleLibStmt = 91, RuleNamespaceStmt = 92, RuleProgram = 93, 
    RuleProgramEntry = 94
  };

  explicit FaParser(antlr4::TokenStream *input);
  ~FaParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ShiftLAssignContext;
  class ShiftRAssignContext;
  class AllAssignContext;
  class ShiftLOpContext;
  class ShiftROpContext;
  class EndStmtContext;
  class EndStmt2Context;
  class QuotFangLContext;
  class QuotFangRContext;
  class QuotJianLContext;
  class QuotJianRContext;
  class QuotHuaLContext;
  class QuotHuaRContext;
  class QuotYuanLContext;
  class QuotYuanRContext;
  class LtOpContext;
  class LtEqualOpContext;
  class GtOpContext;
  class GtEqualOpContext;
  class EqualOpContext;
  class NotEqualOpContext;
  class ExprFuncDefContext;
  class SelfOp2Context;
  class CompareOp2Context;
  class ChangeOp2Context;
  class AllOp2Context;
  class IntNumContext;
  class FloatNumContext;
  class LiteralContext;
  class IdContext;
  class IdsContext;
  class IdExtContext;
  class TypeAfterContext;
  class TypeSingleContext;
  class TypeMultiContext;
  class TypeContext;
  class TypeWrapContext;
  class TypeVarContext;
  class TypeVarListContext;
  class TypeWrapVarContext;
  class TypeWrapVarListContext;
  class TypeWrapVar2Context;
  class TypeWrapVar2ListContext;
  class QuotStmtPartContext;
  class QuotStmtExprContext;
  class IfStmtContext;
  class IfExprContext;
  class WhileStmtContext;
  class WhileStmt2Context;
  class ForStmtContext;
  class ForStmt2Context;
  class SwitchStmtPart2LastContext;
  class QuotStmtExprWrapContext;
  class SwitchExprPartLastContext;
  class SwitchStmtPartContext;
  class SwitchStmtContext;
  class SwitchStmtPart2Context;
  class SwitchStmt2Context;
  class SwitchExprPartContext;
  class SwitchExprContext;
  class SwitchExprPart2Context;
  class SwitchExpr2Context;
  class QuotExprContext;
  class ExprOptContext;
  class NewExprItemContext;
  class NewExpr1Context;
  class NewExpr2Context;
  class ArrayExpr1Context;
  class ArrayExpr2Context;
  class LambdaExprContext;
  class StrongExprBaseContext;
  class StrongExprPrefixContext;
  class StrongExprSuffixContext;
  class StrongExprContext;
  class MiddleExprContext;
  class ExprContext;
  class TmpAssignExprContext;
  class IdAssignExprContext;
  class DefVarStmtContext;
  class NormalStmtContext;
  class StmtContext;
  class PublicLevelContext;
  class EnumItemContext;
  class ClassItemFuncExtBodyContext;
  class ClassItemFuncExtContext;
  class ClassItemContext;
  class EnumBlockContext;
  class ClassBlockContext;
  class UseStmtContext;
  class CallConventionContext;
  class ImportStmtContext;
  class LibStmtContext;
  class NamespaceStmtContext;
  class ProgramContext;
  class ProgramEntryContext; 

  class  ShiftLAssignContext : public antlr4::ParserRuleContext {
  public:
    ShiftLAssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ShiftLOpContext *shiftLOp();
    antlr4::tree::TerminalNode *Assign();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ShiftLAssignContext* shiftLAssign();

  class  ShiftRAssignContext : public antlr4::ParserRuleContext {
  public:
    ShiftRAssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ShiftROpContext *shiftROp();
    antlr4::tree::TerminalNode *Assign();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ShiftRAssignContext* shiftRAssign();

  class  AllAssignContext : public antlr4::ParserRuleContext {
  public:
    AllAssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Assign();
    antlr4::tree::TerminalNode *QusQusAssign();
    antlr4::tree::TerminalNode *AddAssign();
    antlr4::tree::TerminalNode *SubAssign();
    antlr4::tree::TerminalNode *StarAssign();
    antlr4::tree::TerminalNode *StarStarAssign();
    antlr4::tree::TerminalNode *DivAssign();
    antlr4::tree::TerminalNode *ModAssign();
    antlr4::tree::TerminalNode *AndAssign();
    antlr4::tree::TerminalNode *OrAssign();
    antlr4::tree::TerminalNode *XorAssign();
    antlr4::tree::TerminalNode *AndAndAssign();
    antlr4::tree::TerminalNode *OrOrAssign();
    ShiftLAssignContext *shiftLAssign();
    ShiftRAssignContext *shiftRAssign();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AllAssignContext* allAssign();

  class  ShiftLOpContext : public antlr4::ParserRuleContext {
  public:
    ShiftLOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<QuotJianLContext *> quotJianL();
    QuotJianLContext* quotJianL(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ShiftLOpContext* shiftLOp();

  class  ShiftROpContext : public antlr4::ParserRuleContext {
  public:
    ShiftROpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<QuotJianRContext *> quotJianR();
    QuotJianRContext* quotJianR(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ShiftROpContext* shiftROp();

  class  EndStmtContext : public antlr4::ParserRuleContext {
  public:
    EndStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NewLine();
    antlr4::tree::TerminalNode* NewLine(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Semi();
    antlr4::tree::TerminalNode* Semi(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EndStmtContext* endStmt();

  class  EndStmt2Context : public antlr4::ParserRuleContext {
  public:
    EndStmt2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NewLine();
    antlr4::tree::TerminalNode* NewLine(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EndStmt2Context* endStmt2();

  class  QuotFangLContext : public antlr4::ParserRuleContext {
  public:
    QuotFangLContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EndStmtContext *endStmt();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuotFangLContext* quotFangL();

  class  QuotFangRContext : public antlr4::ParserRuleContext {
  public:
    QuotFangRContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EndStmtContext *endStmt();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuotFangRContext* quotFangR();

  class  QuotJianLContext : public antlr4::ParserRuleContext {
  public:
    QuotJianLContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EndStmtContext *endStmt();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuotJianLContext* quotJianL();

  class  QuotJianRContext : public antlr4::ParserRuleContext {
  public:
    QuotJianRContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EndStmtContext *endStmt();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuotJianRContext* quotJianR();

  class  QuotHuaLContext : public antlr4::ParserRuleContext {
  public:
    QuotHuaLContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EndStmtContext *endStmt();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuotHuaLContext* quotHuaL();

  class  QuotHuaRContext : public antlr4::ParserRuleContext {
  public:
    QuotHuaRContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EndStmtContext *endStmt();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuotHuaRContext* quotHuaR();

  class  QuotYuanLContext : public antlr4::ParserRuleContext {
  public:
    QuotYuanLContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EndStmtContext *endStmt();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuotYuanLContext* quotYuanL();

  class  QuotYuanRContext : public antlr4::ParserRuleContext {
  public:
    QuotYuanRContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EndStmtContext *endStmt();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuotYuanRContext* quotYuanR();

  class  LtOpContext : public antlr4::ParserRuleContext {
  public:
    LtOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuotJianLContext *quotJianL();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LtOpContext* ltOp();

  class  LtEqualOpContext : public antlr4::ParserRuleContext {
  public:
    LtEqualOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuotJianLContext *quotJianL();
    antlr4::tree::TerminalNode *Assign();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LtEqualOpContext* ltEqualOp();

  class  GtOpContext : public antlr4::ParserRuleContext {
  public:
    GtOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuotJianRContext *quotJianR();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GtOpContext* gtOp();

  class  GtEqualOpContext : public antlr4::ParserRuleContext {
  public:
    GtEqualOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuotJianRContext *quotJianR();
    antlr4::tree::TerminalNode *Assign();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GtEqualOpContext* gtEqualOp();

  class  EqualOpContext : public antlr4::ParserRuleContext {
  public:
    EqualOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Assign();
    antlr4::tree::TerminalNode* Assign(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EqualOpContext* equalOp();

  class  NotEqualOpContext : public antlr4::ParserRuleContext {
  public:
    NotEqualOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Exclam();
    antlr4::tree::TerminalNode *Assign();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NotEqualOpContext* notEqualOp();

  class  ExprFuncDefContext : public antlr4::ParserRuleContext {
  public:
    ExprFuncDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Assign();
    QuotJianRContext *quotJianR();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprFuncDefContext* exprFuncDef();

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


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SelfOp2Context* selfOp2();

  class  CompareOp2Context : public antlr4::ParserRuleContext {
  public:
    CompareOp2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LtOpContext *ltOp();
    LtEqualOpContext *ltEqualOp();
    GtOpContext *gtOp();
    GtEqualOpContext *gtEqualOp();
    EqualOpContext *equalOp();
    NotEqualOpContext *notEqualOp();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompareOp2Context* compareOp2();

  class  ChangeOp2Context : public antlr4::ParserRuleContext {
  public:
    ChangeOp2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QusQusOp();
    CompareOp2Context *compareOp2();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ChangeOp2Context* changeOp2();

  class  AllOp2Context : public antlr4::ParserRuleContext {
  public:
    AllOp2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SelfOp2Context *selfOp2();
    ChangeOp2Context *changeOp2();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AllOp2Context* allOp2();

  class  IntNumContext : public antlr4::ParserRuleContext {
  public:
    IntNumContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IntLiteral();
    antlr4::tree::TerminalNode *SubOp();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IntNumContext* intNum();

  class  FloatNumContext : public antlr4::ParserRuleContext {
  public:
    FloatNumContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FloatLiteral();
    antlr4::tree::TerminalNode *SubOp();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FloatNumContext* floatNum();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BoolLiteral();
    IntNumContext *intNum();
    FloatNumContext *floatNum();
    antlr4::tree::TerminalNode *String1Literal();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LiteralContext* literal();

  class  IdContext : public antlr4::ParserRuleContext {
  public:
    IdContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Underline();
    antlr4::tree::TerminalNode *RawId();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdContext* id();

  class  IdsContext : public antlr4::ParserRuleContext {
  public:
    IdsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<IdContext *> id();
    IdContext* id(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PointOp();
    antlr4::tree::TerminalNode* PointOp(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdsContext* ids();

  class  IdExtContext : public antlr4::ParserRuleContext {
  public:
    IdExtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdsContext *ids();
    QuotJianLContext *quotJianL();
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    QuotJianRContext *quotJianR();
    antlr4::tree::TerminalNode *PointOp();
    IdContext *id();
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdExtContext* idExt();

  class  TypeAfterContext : public antlr4::ParserRuleContext {
  public:
    TypeAfterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuotFangLContext *quotFangL();
    QuotFangRContext *quotFangR();
    antlr4::tree::TerminalNode *Qus();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeAfterContext* typeAfter();

  class  TypeSingleContext : public antlr4::ParserRuleContext {
  public:
    TypeSingleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdsContext *ids();
    QuotJianLContext *quotJianL();
    std::vector<TypeWrapContext *> typeWrap();
    TypeWrapContext* typeWrap(size_t i);
    QuotJianRContext *quotJianR();
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeSingleContext* typeSingle();

  class  TypeMultiContext : public antlr4::ParserRuleContext {
  public:
    TypeMultiContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuotYuanLContext *quotYuanL();
    std::vector<TypeVarContext *> typeVar();
    TypeVarContext* typeVar(size_t i);
    QuotYuanRContext *quotYuanR();
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeMultiContext* typeMulti();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeSingleContext *typeSingle();
    TypeMultiContext *typeMulti();
    std::vector<TypeAfterContext *> typeAfter();
    TypeAfterContext* typeAfter(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeContext* type();

  class  TypeWrapContext : public antlr4::ParserRuleContext {
  public:
    TypeWrapContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *Mut();
    antlr4::tree::TerminalNode *Params();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeWrapContext* typeWrap();

  class  TypeVarContext : public antlr4::ParserRuleContext {
  public:
    TypeVarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    IdContext *id();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeVarListContext* typeVarList();

  class  TypeWrapVarContext : public antlr4::ParserRuleContext {
  public:
    TypeWrapVarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeWrapContext *typeWrap();
    IdContext *id();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeWrapVarContext* typeWrapVar();

  class  TypeWrapVarListContext : public antlr4::ParserRuleContext {
  public:
    TypeWrapVarListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypeWrapVarContext *> typeWrapVar();
    TypeWrapVarContext* typeWrapVar(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeWrapVarListContext* typeWrapVarList();

  class  TypeWrapVar2Context : public antlr4::ParserRuleContext {
  public:
    TypeWrapVar2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdContext *id();
    TypeWrapContext *typeWrap();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeWrapVar2Context* typeWrapVar2();

  class  TypeWrapVar2ListContext : public antlr4::ParserRuleContext {
  public:
    TypeWrapVar2ListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypeWrapVar2Context *> typeWrapVar2();
    TypeWrapVar2Context* typeWrapVar2(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeWrapVar2ListContext* typeWrapVar2List();

  class  QuotStmtPartContext : public antlr4::ParserRuleContext {
  public:
    QuotStmtPartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuotHuaLContext *quotHuaL();
    QuotHuaRContext *quotHuaR();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuotStmtPartContext* quotStmtPart();

  class  QuotStmtExprContext : public antlr4::ParserRuleContext {
  public:
    QuotStmtExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuotHuaLContext *quotHuaL();
    ExprContext *expr();
    QuotHuaRContext *quotHuaR();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuotStmtExprContext* quotStmtExpr();

  class  IfStmtContext : public antlr4::ParserRuleContext {
  public:
    IfStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> If();
    antlr4::tree::TerminalNode* If(size_t i);
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<QuotStmtPartContext *> quotStmtPart();
    QuotStmtPartContext* quotStmtPart(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Else();
    antlr4::tree::TerminalNode* Else(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfStmtContext* ifStmt();

  class  IfExprContext : public antlr4::ParserRuleContext {
  public:
    IfExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> If();
    antlr4::tree::TerminalNode* If(size_t i);
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<QuotStmtExprContext *> quotStmtExpr();
    QuotStmtExprContext* quotStmtExpr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Else();
    antlr4::tree::TerminalNode* Else(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfExprContext* ifExpr();

  class  WhileStmtContext : public antlr4::ParserRuleContext {
  public:
    WhileStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *While();
    ExprContext *expr();
    QuotHuaLContext *quotHuaL();
    QuotHuaRContext *quotHuaR();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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
    ExprContext *expr();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhileStmt2Context* whileStmt2();

  class  ForStmtContext : public antlr4::ParserRuleContext {
  public:
    ForStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *For();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *Semi();
    QuotHuaLContext *quotHuaL();
    QuotHuaRContext *quotHuaR();
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForStmtContext* forStmt();

  class  ForStmt2Context : public antlr4::ParserRuleContext {
  public:
    ForStmt2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *For();
    TypeContext *type();
    IdContext *id();
    antlr4::tree::TerminalNode *Colon();
    ExprContext *expr();
    QuotHuaLContext *quotHuaL();
    QuotHuaRContext *quotHuaR();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForStmt2Context* forStmt2();

  class  SwitchStmtPart2LastContext : public antlr4::ParserRuleContext {
  public:
    SwitchStmtPart2LastContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Underline();
    ExprFuncDefContext *exprFuncDef();
    StmtContext *stmt();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SwitchStmtPart2LastContext* switchStmtPart2Last();

  class  QuotStmtExprWrapContext : public antlr4::ParserRuleContext {
  public:
    QuotStmtExprWrapContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuotStmtExprContext *quotStmtExpr();
    ExprContext *expr();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuotStmtExprWrapContext* quotStmtExprWrap();

  class  SwitchExprPartLastContext : public antlr4::ParserRuleContext {
  public:
    SwitchExprPartLastContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Underline();
    ExprFuncDefContext *exprFuncDef();
    QuotStmtExprWrapContext *quotStmtExprWrap();
    antlr4::tree::TerminalNode *Comma();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SwitchExprPartLastContext* switchExprPartLast();

  class  SwitchStmtPartContext : public antlr4::ParserRuleContext {
  public:
    SwitchStmtPartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    ExprFuncDefContext *exprFuncDef();
    StmtContext *stmt();
    antlr4::tree::TerminalNode *When();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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
    std::vector<SwitchStmtPartContext *> switchStmtPart();
    SwitchStmtPartContext* switchStmtPart(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SwitchStmtContext* switchStmt();

  class  SwitchStmtPart2Context : public antlr4::ParserRuleContext {
  public:
    SwitchStmtPart2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *When();
    ExprContext *expr();
    ExprFuncDefContext *exprFuncDef();
    StmtContext *stmt();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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
    std::vector<SwitchStmtPart2Context *> switchStmtPart2();
    SwitchStmtPart2Context* switchStmtPart2(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SwitchStmt2Context* switchStmt2();

  class  SwitchExprPartContext : public antlr4::ParserRuleContext {
  public:
    SwitchExprPartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    ExprFuncDefContext *exprFuncDef();
    QuotStmtExprWrapContext *quotStmtExprWrap();
    antlr4::tree::TerminalNode *Comma();
    antlr4::tree::TerminalNode *When();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SwitchExprPartContext* switchExprPart();

  class  SwitchExprContext : public antlr4::ParserRuleContext {
  public:
    SwitchExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Switch();
    ExprContext *expr();
    QuotHuaLContext *quotHuaL();
    SwitchExprPartLastContext *switchExprPartLast();
    QuotHuaRContext *quotHuaR();
    std::vector<SwitchExprPartContext *> switchExprPart();
    SwitchExprPartContext* switchExprPart(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SwitchExprContext* switchExpr();

  class  SwitchExprPart2Context : public antlr4::ParserRuleContext {
  public:
    SwitchExprPart2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *When();
    ExprContext *expr();
    ExprFuncDefContext *exprFuncDef();
    QuotStmtExprWrapContext *quotStmtExprWrap();
    antlr4::tree::TerminalNode *Comma();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SwitchExprPart2Context* switchExprPart2();

  class  SwitchExpr2Context : public antlr4::ParserRuleContext {
  public:
    SwitchExpr2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Switch();
    QuotHuaLContext *quotHuaL();
    SwitchExprPartLastContext *switchExprPartLast();
    QuotHuaRContext *quotHuaR();
    std::vector<SwitchExprPart2Context *> switchExprPart2();
    SwitchExprPart2Context* switchExprPart2(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SwitchExpr2Context* switchExpr2();

  class  QuotExprContext : public antlr4::ParserRuleContext {
  public:
    QuotExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuotYuanLContext *quotYuanL();
    ExprContext *expr();
    QuotYuanRContext *quotYuanR();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuotExprContext* quotExpr();

  class  ExprOptContext : public antlr4::ParserRuleContext {
  public:
    ExprOptContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprOptContext* exprOpt();

  class  NewExprItemContext : public antlr4::ParserRuleContext {
  public:
    NewExprItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdContext *id();
    antlr4::tree::TerminalNode *Assign();
    MiddleExprContext *middleExpr();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NewExprItemContext* newExprItem();

  class  NewExpr1Context : public antlr4::ParserRuleContext {
  public:
    NewExpr1Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *New();
    TypeSingleContext *typeSingle();
    QuotHuaLContext *quotHuaL();
    QuotHuaRContext *quotHuaR();
    std::vector<NewExprItemContext *> newExprItem();
    NewExprItemContext* newExprItem(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NewExpr1Context* newExpr1();

  class  NewExpr2Context : public antlr4::ParserRuleContext {
  public:
    NewExpr2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *New();
    TypeSingleContext *typeSingle();
    QuotYuanLContext *quotYuanL();
    QuotYuanRContext *quotYuanR();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NewExpr2Context* newExpr2();

  class  ArrayExpr1Context : public antlr4::ParserRuleContext {
  public:
    ArrayExpr1Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuotFangLContext *quotFangL();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *PointPoint();
    QuotFangRContext *quotFangR();
    antlr4::tree::TerminalNode *Step();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayExpr1Context* arrayExpr1();

  class  ArrayExpr2Context : public antlr4::ParserRuleContext {
  public:
    ArrayExpr2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuotFangLContext *quotFangL();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    QuotFangRContext *quotFangR();
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayExpr2Context* arrayExpr2();

  class  LambdaExprContext : public antlr4::ParserRuleContext {
  public:
    LambdaExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuotYuanLContext *quotYuanL();
    QuotYuanRContext *quotYuanR();
    ExprFuncDefContext *exprFuncDef();
    ExprContext *expr();
    TypeWrapVar2ListContext *typeWrapVar2List();
    QuotHuaLContext *quotHuaL();
    QuotHuaRContext *quotHuaR();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LambdaExprContext* lambdaExpr();

  class  StrongExprBaseContext : public antlr4::ParserRuleContext {
  public:
    StrongExprBaseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdContext *id();
    antlr4::tree::TerminalNode *ColonColon();
    LiteralContext *literal();
    IfExprContext *ifExpr();
    QuotExprContext *quotExpr();
    NewExpr1Context *newExpr1();
    NewExpr2Context *newExpr2();
    ArrayExpr1Context *arrayExpr1();
    ArrayExpr2Context *arrayExpr2();
    SwitchExpr2Context *switchExpr2();
    SwitchExprContext *switchExpr();
    LambdaExprContext *lambdaExpr();
    IdExtContext *idExt();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);
    QuotFangLContext *quotFangL();
    QuotFangRContext *quotFangR();
    std::vector<ExprOptContext *> exprOpt();
    ExprOptContext* exprOpt(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Colon();
    antlr4::tree::TerminalNode* Colon(size_t i);
    antlr4::tree::TerminalNode *PointOp();
    IdContext *id();
    antlr4::tree::TerminalNode *Is();
    IdsContext *ids();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StrongExprContext* strongExpr();

  class  MiddleExprContext : public antlr4::ParserRuleContext {
  public:
    MiddleExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StrongExprContext *> strongExpr();
    StrongExprContext* strongExpr(size_t i);
    std::vector<AllOp2Context *> allOp2();
    AllOp2Context* allOp2(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MiddleExprContext* middleExpr();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<MiddleExprContext *> middleExpr();
    MiddleExprContext* middleExpr(size_t i);
    std::vector<AllAssignContext *> allAssign();
    AllAssignContext* allAssign(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprContext* expr();

  class  TmpAssignExprContext : public antlr4::ParserRuleContext {
  public:
    TmpAssignExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Assign();
    MiddleExprContext *middleExpr();
    EndStmtContext *endStmt();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TmpAssignExprContext* tmpAssignExpr();

  class  IdAssignExprContext : public antlr4::ParserRuleContext {
  public:
    IdAssignExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdContext *id();
    antlr4::tree::TerminalNode *Assign();
    ExprContext *expr();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdAssignExprContext* idAssignExpr();

  class  DefVarStmtContext : public antlr4::ParserRuleContext {
  public:
    DefVarStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    std::vector<IdAssignExprContext *> idAssignExpr();
    IdAssignExprContext* idAssignExpr(size_t i);
    EndStmtContext *endStmt();
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefVarStmtContext* defVarStmt();

  class  NormalStmtContext : public antlr4::ParserRuleContext {
  public:
    NormalStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EndStmtContext *endStmt();
    antlr4::tree::TerminalNode *Break();
    antlr4::tree::TerminalNode *Continue();
    antlr4::tree::TerminalNode *Return();
    ExprContext *expr();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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
    ForStmt2Context *forStmt2();
    QuotStmtPartContext *quotStmtPart();
    SwitchStmt2Context *switchStmt2();
    SwitchStmtContext *switchStmt();
    DefVarStmtContext *defVarStmt();
    NormalStmtContext *normalStmt();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PublicLevelContext* publicLevel();

  class  EnumItemContext : public antlr4::ParserRuleContext {
  public:
    EnumItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdContext *id();
    QuotYuanLContext *quotYuanL();
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    QuotYuanRContext *quotYuanR();
    EndStmt2Context *endStmt2();
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumItemContext* enumItem();

  class  ClassItemFuncExtBodyContext : public antlr4::ParserRuleContext {
  public:
    ClassItemFuncExtBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprFuncDefContext *exprFuncDef();
    ExprContext *expr();
    antlr4::tree::TerminalNode *Semi();
    QuotHuaLContext *quotHuaL();
    QuotHuaRContext *quotHuaR();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassItemFuncExtBodyContext* classItemFuncExtBody();

  class  ClassItemFuncExtContext : public antlr4::ParserRuleContext {
  public:
    ClassItemFuncExtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuotYuanLContext *quotYuanL();
    QuotYuanRContext *quotYuanR();
    ClassItemFuncExtBodyContext *classItemFuncExtBody();
    TypeWrapVarListContext *typeWrapVarList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassItemFuncExtContext* classItemFuncExt();

  class  ClassItemContext : public antlr4::ParserRuleContext {
  public:
    ClassItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    IdContext *id();
    EndStmtContext *endStmt();
    PublicLevelContext *publicLevel();
    antlr4::tree::TerminalNode *Static();
    ClassItemFuncExtContext *classItemFuncExt();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassItemContext* classItem();

  class  EnumBlockContext : public antlr4::ParserRuleContext {
  public:
    EnumBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Enum();
    IdContext *id();
    QuotHuaLContext *quotHuaL();
    QuotHuaRContext *quotHuaR();
    EndStmtContext *endStmt();
    PublicLevelContext *publicLevel();
    std::vector<EnumItemContext *> enumItem();
    EnumItemContext* enumItem(size_t i);
    std::vector<ClassItemContext *> classItem();
    ClassItemContext* classItem(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumBlockContext* enumBlock();

  class  ClassBlockContext : public antlr4::ParserRuleContext {
  public:
    ClassBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Class();
    IdContext *id();
    QuotHuaLContext *quotHuaL();
    QuotHuaRContext *quotHuaR();
    EndStmtContext *endStmt();
    PublicLevelContext *publicLevel();
    std::vector<ClassItemContext *> classItem();
    ClassItemContext* classItem(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassBlockContext* classBlock();

  class  UseStmtContext : public antlr4::ParserRuleContext {
  public:
    UseStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Use();
    IdsContext *ids();
    EndStmtContext *endStmt();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UseStmtContext* useStmt();

  class  CallConventionContext : public antlr4::ParserRuleContext {
  public:
    CallConventionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CC__Cdecl();
    antlr4::tree::TerminalNode *CC__FastCall();
    antlr4::tree::TerminalNode *CC__StdCall();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CallConventionContext* callConvention();

  class  ImportStmtContext : public antlr4::ParserRuleContext {
  public:
    ImportStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AImport();
    TypeContext *type();
    CallConventionContext *callConvention();
    IdContext *id();
    QuotYuanLContext *quotYuanL();
    TypeVarListContext *typeVarList();
    QuotYuanRContext *quotYuanR();
    EndStmtContext *endStmt();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ImportStmtContext* importStmt();

  class  LibStmtContext : public antlr4::ParserRuleContext {
  public:
    LibStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ALib();
    antlr4::tree::TerminalNode *String1Literal();
    EndStmtContext *endStmt();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LibStmtContext* libStmt();

  class  NamespaceStmtContext : public antlr4::ParserRuleContext {
  public:
    NamespaceStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Namespace();
    IdsContext *ids();
    EndStmtContext *endStmt();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NamespaceStmtContext* namespaceStmt();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<UseStmtContext *> useStmt();
    UseStmtContext* useStmt(size_t i);
    std::vector<ImportStmtContext *> importStmt();
    ImportStmtContext* importStmt(size_t i);
    std::vector<LibStmtContext *> libStmt();
    LibStmtContext* libStmt(size_t i);
    NamespaceStmtContext *namespaceStmt();
    std::vector<EnumBlockContext *> enumBlock();
    EnumBlockContext* enumBlock(size_t i);
    std::vector<ClassBlockContext *> classBlock();
    ClassBlockContext* classBlock(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  ProgramEntryContext : public antlr4::ParserRuleContext {
  public:
    ProgramEntryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProgramContext *program();
    antlr4::tree::TerminalNode *EOF();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramEntryContext* programEntry();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

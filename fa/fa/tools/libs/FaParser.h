
// Generated from Fa.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  FaParser : public antlr4::Parser {
public:
  enum {
    AImport = 1, ALib = 2, Break = 3, CC__Cdecl = 4, CC__FastCall = 5, CC__StdCall = 6, 
    Continue = 7, Class = 8, Const = 9, Else = 10, FaEntryMain = 11, If = 12, 
    Internal = 13, Public = 14, Protected = 15, Private = 16, Return = 17, 
    Signed = 18, Static = 19, Unsigned = 20, Use = 21, While = 22, Assign = 23, 
    ReverseOp = 24, AddAddOp = 25, SubSubOp = 26, PointOp = 27, AddOp = 28, 
    SubOp = 29, StarOp = 30, DivOp = 31, ModOp = 32, OrOp = 33, AndOp = 34, 
    XorOp = 35, Qus = 36, Comma = 37, ColonColon = 38, Colon = 39, Semi = 40, 
    Exclam = 41, QuotFangL = 42, QuotFangR = 43, QuotJianL = 44, QuotJianR = 45, 
    QuotHuaL = 46, QuotHuaR = 47, QuotYuanL = 48, QuotYuanR = 49, BoolLiteral = 50, 
    IntLiteral = 51, FloatLiteral = 52, String1Literal = 53, Id = 54, Comment1 = 55, 
    Comment2 = 56, WS = 57
  };

  enum {
    RuleAddAssign = 0, RuleSubAssign = 1, RuleStarAssign = 2, RuleDivAssign = 3, 
    RuleModAssign = 4, RuleOrAssign = 5, RuleAndAssign = 6, RuleXorAssign = 7, 
    RuleQusQusAssign = 8, RuleStarStarAssign = 9, RuleAndAndAssign = 10, 
    RuleOrOrAssign = 11, RuleShiftLAssign = 12, RuleShiftRAssign = 13, RuleAllAssign = 14, 
    RuleQusQusOp = 15, RuleStarStarOp = 16, RuleAndAndOp = 17, RuleOrOrOp = 18, 
    RuleShiftLOp = 19, RuleShiftROp = 20, RuleLtOp = 21, RuleLtEqualOp = 22, 
    RuleGtOp = 23, RuleGtEqualOp = 24, RuleEqualOp = 25, RuleNotEqualOp = 26, 
    RuleSelfOp2 = 27, RuleCompareOp2 = 28, RuleChangeOp2 = 29, RuleAllOp2 = 30, 
    RuleLiteral = 31, RuleIds = 32, RuleTypeAfter = 33, RuleType = 34, RuleETypeAfter = 35, 
    RuleESign = 36, RuleEType = 37, RuleTypeVar = 38, RuleTypeVarList = 39, 
    RuleETypeVar = 40, RuleETypeVarList = 41, RuleQuotStmtPart = 42, RuleQuotStmtExpr = 43, 
    RuleIfStmt = 44, RuleIfExpr = 45, RuleWhileStmt = 46, RuleQuotExpr = 47, 
    RuleExprOpt = 48, RuleStrongExprBase = 49, RuleStrongExprPrefix = 50, 
    RuleStrongExprSuffix = 51, RuleStrongExpr = 52, RuleMiddleExpr = 53, 
    RuleExpr = 54, RuleDefVarStmt = 55, RuleUseStmt = 56, RuleNormalStmt = 57, 
    RuleStmt = 58, RulePublicLevel = 59, RuleClassParent = 60, RuleClassItemPart = 61, 
    RuleClassItemFieldBlock = 62, RuleClassItemFuncBlock = 63, RuleClassBlock = 64, 
    RuleCallConvention = 65, RuleImportStmt = 66, RuleLibStmt = 67, RuleImportBlock = 68, 
    RuleFaEntryMainFuncBlock = 69, RuleProgram = 70
  };

  explicit FaParser(antlr4::TokenStream *input);
  ~FaParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class AddAssignContext;
  class SubAssignContext;
  class StarAssignContext;
  class DivAssignContext;
  class ModAssignContext;
  class OrAssignContext;
  class AndAssignContext;
  class XorAssignContext;
  class QusQusAssignContext;
  class StarStarAssignContext;
  class AndAndAssignContext;
  class OrOrAssignContext;
  class ShiftLAssignContext;
  class ShiftRAssignContext;
  class AllAssignContext;
  class QusQusOpContext;
  class StarStarOpContext;
  class AndAndOpContext;
  class OrOrOpContext;
  class ShiftLOpContext;
  class ShiftROpContext;
  class LtOpContext;
  class LtEqualOpContext;
  class GtOpContext;
  class GtEqualOpContext;
  class EqualOpContext;
  class NotEqualOpContext;
  class SelfOp2Context;
  class CompareOp2Context;
  class ChangeOp2Context;
  class AllOp2Context;
  class LiteralContext;
  class IdsContext;
  class TypeAfterContext;
  class TypeContext;
  class ETypeAfterContext;
  class ESignContext;
  class ETypeContext;
  class TypeVarContext;
  class TypeVarListContext;
  class ETypeVarContext;
  class ETypeVarListContext;
  class QuotStmtPartContext;
  class QuotStmtExprContext;
  class IfStmtContext;
  class IfExprContext;
  class WhileStmtContext;
  class QuotExprContext;
  class ExprOptContext;
  class StrongExprBaseContext;
  class StrongExprPrefixContext;
  class StrongExprSuffixContext;
  class StrongExprContext;
  class MiddleExprContext;
  class ExprContext;
  class DefVarStmtContext;
  class UseStmtContext;
  class NormalStmtContext;
  class StmtContext;
  class PublicLevelContext;
  class ClassParentContext;
  class ClassItemPartContext;
  class ClassItemFieldBlockContext;
  class ClassItemFuncBlockContext;
  class ClassBlockContext;
  class CallConventionContext;
  class ImportStmtContext;
  class LibStmtContext;
  class ImportBlockContext;
  class FaEntryMainFuncBlockContext;
  class ProgramContext; 

  class  AddAssignContext : public antlr4::ParserRuleContext {
  public:
    AddAssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AddOp();
    antlr4::tree::TerminalNode *Assign();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AddAssignContext* addAssign();

  class  SubAssignContext : public antlr4::ParserRuleContext {
  public:
    SubAssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SubOp();
    antlr4::tree::TerminalNode *Assign();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SubAssignContext* subAssign();

  class  StarAssignContext : public antlr4::ParserRuleContext {
  public:
    StarAssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *StarOp();
    antlr4::tree::TerminalNode *Assign();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StarAssignContext* starAssign();

  class  DivAssignContext : public antlr4::ParserRuleContext {
  public:
    DivAssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DivOp();
    antlr4::tree::TerminalNode *Assign();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DivAssignContext* divAssign();

  class  ModAssignContext : public antlr4::ParserRuleContext {
  public:
    ModAssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ModOp();
    antlr4::tree::TerminalNode *Assign();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModAssignContext* modAssign();

  class  OrAssignContext : public antlr4::ParserRuleContext {
  public:
    OrAssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OrOp();
    antlr4::tree::TerminalNode *Assign();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OrAssignContext* orAssign();

  class  AndAssignContext : public antlr4::ParserRuleContext {
  public:
    AndAssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AndOp();
    antlr4::tree::TerminalNode *Assign();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AndAssignContext* andAssign();

  class  XorAssignContext : public antlr4::ParserRuleContext {
  public:
    XorAssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *XorOp();
    antlr4::tree::TerminalNode *Assign();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  XorAssignContext* xorAssign();

  class  QusQusAssignContext : public antlr4::ParserRuleContext {
  public:
    QusQusAssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QusQusOpContext *qusQusOp();
    antlr4::tree::TerminalNode *Assign();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QusQusAssignContext* qusQusAssign();

  class  StarStarAssignContext : public antlr4::ParserRuleContext {
  public:
    StarStarAssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StarStarOpContext *starStarOp();
    antlr4::tree::TerminalNode *Assign();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StarStarAssignContext* starStarAssign();

  class  AndAndAssignContext : public antlr4::ParserRuleContext {
  public:
    AndAndAssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AndAndOpContext *andAndOp();
    antlr4::tree::TerminalNode *Assign();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AndAndAssignContext* andAndAssign();

  class  OrOrAssignContext : public antlr4::ParserRuleContext {
  public:
    OrOrAssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OrOrOpContext *orOrOp();
    antlr4::tree::TerminalNode *Assign();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OrOrAssignContext* orOrAssign();

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
    QusQusAssignContext *qusQusAssign();
    AddAssignContext *addAssign();
    SubAssignContext *subAssign();
    StarAssignContext *starAssign();
    StarStarAssignContext *starStarAssign();
    DivAssignContext *divAssign();
    ModAssignContext *modAssign();
    AndAssignContext *andAssign();
    OrAssignContext *orAssign();
    XorAssignContext *xorAssign();
    AndAndAssignContext *andAndAssign();
    OrOrAssignContext *orOrAssign();
    ShiftLAssignContext *shiftLAssign();
    ShiftRAssignContext *shiftRAssign();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AllAssignContext* allAssign();

  class  QusQusOpContext : public antlr4::ParserRuleContext {
  public:
    QusQusOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Qus();
    antlr4::tree::TerminalNode* Qus(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QusQusOpContext* qusQusOp();

  class  StarStarOpContext : public antlr4::ParserRuleContext {
  public:
    StarStarOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> StarOp();
    antlr4::tree::TerminalNode* StarOp(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StarStarOpContext* starStarOp();

  class  AndAndOpContext : public antlr4::ParserRuleContext {
  public:
    AndAndOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> AndOp();
    antlr4::tree::TerminalNode* AndOp(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AndAndOpContext* andAndOp();

  class  OrOrOpContext : public antlr4::ParserRuleContext {
  public:
    OrOrOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> OrOp();
    antlr4::tree::TerminalNode* OrOp(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OrOrOpContext* orOrOp();

  class  ShiftLOpContext : public antlr4::ParserRuleContext {
  public:
    ShiftLOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> QuotJianL();
    antlr4::tree::TerminalNode* QuotJianL(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ShiftLOpContext* shiftLOp();

  class  ShiftROpContext : public antlr4::ParserRuleContext {
  public:
    ShiftROpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> QuotJianR();
    antlr4::tree::TerminalNode* QuotJianR(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ShiftROpContext* shiftROp();

  class  LtOpContext : public antlr4::ParserRuleContext {
  public:
    LtOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QuotJianL();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LtOpContext* ltOp();

  class  LtEqualOpContext : public antlr4::ParserRuleContext {
  public:
    LtEqualOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QuotJianL();
    antlr4::tree::TerminalNode *Assign();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LtEqualOpContext* ltEqualOp();

  class  GtOpContext : public antlr4::ParserRuleContext {
  public:
    GtOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QuotJianR();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GtOpContext* gtOp();

  class  GtEqualOpContext : public antlr4::ParserRuleContext {
  public:
    GtEqualOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QuotJianR();
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

  class  SelfOp2Context : public antlr4::ParserRuleContext {
  public:
    SelfOp2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AddOp();
    antlr4::tree::TerminalNode *SubOp();
    antlr4::tree::TerminalNode *StarOp();
    antlr4::tree::TerminalNode *DivOp();
    StarStarOpContext *starStarOp();
    antlr4::tree::TerminalNode *ModOp();
    antlr4::tree::TerminalNode *AndOp();
    antlr4::tree::TerminalNode *OrOp();
    antlr4::tree::TerminalNode *XorOp();
    AndAndOpContext *andAndOp();
    OrOrOpContext *orOrOp();
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
    QusQusOpContext *qusQusOp();
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

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BoolLiteral();
    antlr4::tree::TerminalNode *IntLiteral();
    antlr4::tree::TerminalNode *FloatLiteral();
    antlr4::tree::TerminalNode *String1Literal();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdsContext* ids();

  class  TypeAfterContext : public antlr4::ParserRuleContext {
  public:
    TypeAfterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QuotFangL();
    antlr4::tree::TerminalNode *QuotFangR();
    antlr4::tree::TerminalNode *AndOp();
    antlr4::tree::TerminalNode *Qus();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeAfterContext* typeAfter();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Id();
    antlr4::tree::TerminalNode *Const();
    std::vector<TypeAfterContext *> typeAfter();
    TypeAfterContext* typeAfter(size_t i);
    antlr4::tree::TerminalNode *QuotJianL();
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    antlr4::tree::TerminalNode *QuotJianR();
    antlr4::tree::TerminalNode *QuotYuanL();
    antlr4::tree::TerminalNode *QuotYuanR();
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeContext* type();

  class  ETypeAfterContext : public antlr4::ParserRuleContext {
  public:
    ETypeAfterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QuotFangL();
    antlr4::tree::TerminalNode *QuotFangR();
    antlr4::tree::TerminalNode *AndOp();
    antlr4::tree::TerminalNode *StarOp();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ETypeAfterContext* eTypeAfter();

  class  ESignContext : public antlr4::ParserRuleContext {
  public:
    ESignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Signed();
    antlr4::tree::TerminalNode *Unsigned();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ESignContext* eSign();

  class  ETypeContext : public antlr4::ParserRuleContext {
  public:
    ETypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Id();
    antlr4::tree::TerminalNode *Const();
    ESignContext *eSign();
    std::vector<ETypeAfterContext *> eTypeAfter();
    ETypeAfterContext* eTypeAfter(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ETypeContext* eType();

  class  TypeVarContext : public antlr4::ParserRuleContext {
  public:
    TypeVarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *Id();


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

  class  ETypeVarContext : public antlr4::ParserRuleContext {
  public:
    ETypeVarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ETypeContext *eType();
    antlr4::tree::TerminalNode *Id();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ETypeVarContext* eTypeVar();

  class  ETypeVarListContext : public antlr4::ParserRuleContext {
  public:
    ETypeVarListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ETypeVarContext *> eTypeVar();
    ETypeVarContext* eTypeVar(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ETypeVarListContext* eTypeVarList();

  class  QuotStmtPartContext : public antlr4::ParserRuleContext {
  public:
    QuotStmtPartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QuotHuaL();
    antlr4::tree::TerminalNode *QuotHuaR();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuotStmtPartContext* quotStmtPart();

  class  QuotStmtExprContext : public antlr4::ParserRuleContext {
  public:
    QuotStmtExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QuotHuaL();
    ExprContext *expr();
    antlr4::tree::TerminalNode *QuotHuaR();
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
    antlr4::tree::TerminalNode *QuotYuanL();
    ExprContext *expr();
    antlr4::tree::TerminalNode *QuotYuanR();
    antlr4::tree::TerminalNode *QuotHuaL();
    antlr4::tree::TerminalNode *QuotHuaR();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhileStmtContext* whileStmt();

  class  QuotExprContext : public antlr4::ParserRuleContext {
  public:
    QuotExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QuotYuanL();
    ExprContext *expr();
    antlr4::tree::TerminalNode *QuotYuanR();


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

  class  StrongExprBaseContext : public antlr4::ParserRuleContext {
  public:
    StrongExprBaseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdsContext *ids();
    antlr4::tree::TerminalNode *ColonColon();
    antlr4::tree::TerminalNode *Id();
    LiteralContext *literal();
    IfExprContext *ifExpr();
    QuotExprContext *quotExpr();


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


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StrongExprPrefixContext* strongExprPrefix();

  class  StrongExprSuffixContext : public antlr4::ParserRuleContext {
  public:
    StrongExprSuffixContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AddAddOp();
    antlr4::tree::TerminalNode *SubSubOp();
    antlr4::tree::TerminalNode *QuotYuanL();
    antlr4::tree::TerminalNode *QuotYuanR();
    std::vector<ExprOptContext *> exprOpt();
    ExprOptContext* exprOpt(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);
    antlr4::tree::TerminalNode *QuotFangL();
    antlr4::tree::TerminalNode *QuotFangR();
    std::vector<antlr4::tree::TerminalNode *> Colon();
    antlr4::tree::TerminalNode* Colon(size_t i);
    antlr4::tree::TerminalNode *PointOp();
    antlr4::tree::TerminalNode *Id();


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

  class  DefVarStmtContext : public antlr4::ParserRuleContext {
  public:
    DefVarStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *Id();
    antlr4::tree::TerminalNode *Assign();
    ExprContext *expr();
    antlr4::tree::TerminalNode *Semi();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefVarStmtContext* defVarStmt();

  class  UseStmtContext : public antlr4::ParserRuleContext {
  public:
    UseStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Use();
    IdsContext *ids();
    antlr4::tree::TerminalNode *Semi();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UseStmtContext* useStmt();

  class  NormalStmtContext : public antlr4::ParserRuleContext {
  public:
    NormalStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Semi();
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
    NormalStmtContext *normalStmt();
    IfStmtContext *ifStmt();
    WhileStmtContext *whileStmt();
    DefVarStmtContext *defVarStmt();


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

  class  ClassParentContext : public antlr4::ParserRuleContext {
  public:
    ClassParentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Colon();
    std::vector<IdsContext *> ids();
    IdsContext* ids(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassParentContext* classParent();

  class  ClassItemPartContext : public antlr4::ParserRuleContext {
  public:
    ClassItemPartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Id();
    antlr4::tree::TerminalNode* Id(size_t i);
    PublicLevelContext *publicLevel();
    antlr4::tree::TerminalNode *Static();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassItemPartContext* classItemPart();

  class  ClassItemFieldBlockContext : public antlr4::ParserRuleContext {
  public:
    ClassItemFieldBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ClassItemPartContext *classItemPart();
    antlr4::tree::TerminalNode *Semi();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassItemFieldBlockContext* classItemFieldBlock();

  class  ClassItemFuncBlockContext : public antlr4::ParserRuleContext {
  public:
    ClassItemFuncBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ClassItemPartContext *classItemPart();
    antlr4::tree::TerminalNode *QuotYuanL();
    TypeVarListContext *typeVarList();
    antlr4::tree::TerminalNode *QuotYuanR();
    antlr4::tree::TerminalNode *QuotHuaL();
    antlr4::tree::TerminalNode *QuotHuaR();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassItemFuncBlockContext* classItemFuncBlock();

  class  ClassBlockContext : public antlr4::ParserRuleContext {
  public:
    ClassBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Class();
    antlr4::tree::TerminalNode *Id();
    antlr4::tree::TerminalNode *QuotHuaL();
    antlr4::tree::TerminalNode *QuotHuaR();
    PublicLevelContext *publicLevel();
    ClassParentContext *classParent();
    std::vector<ClassItemFieldBlockContext *> classItemFieldBlock();
    ClassItemFieldBlockContext* classItemFieldBlock(size_t i);
    std::vector<ClassItemFuncBlockContext *> classItemFuncBlock();
    ClassItemFuncBlockContext* classItemFuncBlock(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassBlockContext* classBlock();

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
    ETypeContext *eType();
    CallConventionContext *callConvention();
    antlr4::tree::TerminalNode *Id();
    antlr4::tree::TerminalNode *QuotYuanL();
    ETypeVarListContext *eTypeVarList();
    antlr4::tree::TerminalNode *QuotYuanR();
    antlr4::tree::TerminalNode *Semi();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ImportStmtContext* importStmt();

  class  LibStmtContext : public antlr4::ParserRuleContext {
  public:
    LibStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ALib();
    antlr4::tree::TerminalNode *String1Literal();
    antlr4::tree::TerminalNode *Semi();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LibStmtContext* libStmt();

  class  ImportBlockContext : public antlr4::ParserRuleContext {
  public:
    ImportBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ImportStmtContext *> importStmt();
    ImportStmtContext* importStmt(size_t i);
    std::vector<LibStmtContext *> libStmt();
    LibStmtContext* libStmt(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ImportBlockContext* importBlock();

  class  FaEntryMainFuncBlockContext : public antlr4::ParserRuleContext {
  public:
    FaEntryMainFuncBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Static();
    TypeContext *type();
    antlr4::tree::TerminalNode *FaEntryMain();
    antlr4::tree::TerminalNode *QuotYuanL();
    antlr4::tree::TerminalNode *QuotYuanR();
    antlr4::tree::TerminalNode *QuotHuaL();
    antlr4::tree::TerminalNode *QuotHuaR();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FaEntryMainFuncBlockContext* faEntryMainFuncBlock();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<UseStmtContext *> useStmt();
    UseStmtContext* useStmt(size_t i);
    ImportBlockContext *importBlock();
    std::vector<ClassBlockContext *> classBlock();
    ClassBlockContext* classBlock(size_t i);
    FaEntryMainFuncBlockContext *faEntryMainFuncBlock();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();


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


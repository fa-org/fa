
// Generated from Fa.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  FaParser : public antlr4::Parser {
public:
  enum {
    AImport = 1, ALib = 2, Break = 3, CC__Cdecl = 4, CC__FastCall = 5, CC__StdCall = 6, 
    Continue = 7, Class = 8, Const = 9, Else = 10, FaEntryMain = 11, If = 12, 
    Internal = 13, Public = 14, Protected = 15, Private = 16, Return = 17, 
    Signed = 18, Static = 19, Unsigned = 20, Use = 21, While = 22, Id = 23, 
    Assign = 24, QusQusAssign = 25, AddAssign = 26, SubAssign = 27, StarAssign = 28, 
    StarStarAssign = 29, DivAssign = 30, ModAssign = 31, AndAssign = 32, 
    OrAssign = 33, XorAssign = 34, AndAndAssign = 35, OrOrAssign = 36, ShiftLAssign = 37, 
    ShiftRAssign = 38, ReverseOp = 39, AddAddOp = 40, SubSubOp = 41, PointOp = 42, 
    QusQusOp = 43, AddOp = 44, SubOp = 45, StarOp = 46, DivOp = 47, StarStarOp = 48, 
    ModOp = 49, AndOp = 50, OrOp = 51, XorOp = 52, AndAndOp = 53, OrOrOp = 54, 
    Qus = 55, Comma = 56, ColonColon = 57, Colon = 58, Semi = 59, QuotFangL = 60, 
    QuotFangR = 61, QuotJianL = 62, QuotJianR = 63, QuotHuaL = 64, QuotHuaR = 65, 
    QuotYuanL = 66, QuotYuanR = 67, BoolLiteral = 68, IntLiteral = 69, FloatLiteral = 70, 
    String1Literal = 71, Comment1 = 72, Comment2 = 73, WS = 74
  };

  enum {
    RuleIds = 0, RuleShiftLOp = 1, RuleShiftROp = 2, RuleLiteral = 3, RuleTypeAfter = 4, 
    RuleType = 5, RuleETypeAfter = 6, RuleESign = 7, RuleEType = 8, RuleTypeVar = 9, 
    RuleTypeVarList = 10, RuleETypeVar = 11, RuleETypeVarList = 12, RuleIfPart = 13, 
    RuleStmtOrExpr = 14, RuleQuotStmtPart = 15, RuleQuotStmtExpr = 16, RuleIfStmt = 17, 
    RuleIfExpr = 18, RuleWhileStmtPart = 19, RuleWhileStmt = 20, RuleAllAssign = 21, 
    RuleAllOp = 22, RuleQuotExpr = 23, RuleExprPrefix = 24, RuleExprBody = 25, 
    RuleExprSuffix = 26, RuleNormalExpr = 27, RuleExpr = 28, RuleUseStmt = 29, 
    RuleNormalStmt = 30, RuleStmt = 31, RulePublicLevel = 32, RuleClassParent = 33, 
    RuleClassItemPart = 34, RuleClassItemFieldBlock = 35, RuleClassItemFuncBlock = 36, 
    RuleClassBlock = 37, RuleCallConvention = 38, RuleImportStmt = 39, RuleLibStmt = 40, 
    RuleImportBlock = 41, RuleFaEntryMainFuncBlock = 42, RuleProgram = 43
  };

  explicit FaParser(antlr4::TokenStream *input);
  ~FaParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class IdsContext;
  class ShiftLOpContext;
  class ShiftROpContext;
  class LiteralContext;
  class TypeAfterContext;
  class TypeContext;
  class ETypeAfterContext;
  class ESignContext;
  class ETypeContext;
  class TypeVarContext;
  class TypeVarListContext;
  class ETypeVarContext;
  class ETypeVarListContext;
  class IfPartContext;
  class StmtOrExprContext;
  class QuotStmtPartContext;
  class QuotStmtExprContext;
  class IfStmtContext;
  class IfExprContext;
  class WhileStmtPartContext;
  class WhileStmtContext;
  class AllAssignContext;
  class AllOpContext;
  class QuotExprContext;
  class ExprPrefixContext;
  class ExprBodyContext;
  class ExprSuffixContext;
  class NormalExprContext;
  class ExprContext;
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

  class  IfPartContext : public antlr4::ParserRuleContext {
  public:
    IfPartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *If();
    antlr4::tree::TerminalNode *QuotYuanL();
    ExprContext *expr();
    antlr4::tree::TerminalNode *QuotYuanR();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfPartContext* ifPart();

  class  StmtOrExprContext : public antlr4::ParserRuleContext {
  public:
    StmtOrExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StmtContext *stmt();
    ExprContext *expr();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StmtOrExprContext* stmtOrExpr();

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
    std::vector<StmtOrExprContext *> stmtOrExpr();
    StmtOrExprContext* stmtOrExpr(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuotStmtExprContext* quotStmtExpr();

  class  IfStmtContext : public antlr4::ParserRuleContext {
  public:
    IfStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<IfPartContext *> ifPart();
    IfPartContext* ifPart(size_t i);
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
    std::vector<IfPartContext *> ifPart();
    IfPartContext* ifPart(size_t i);
    std::vector<QuotStmtExprContext *> quotStmtExpr();
    QuotStmtExprContext* quotStmtExpr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Else();
    antlr4::tree::TerminalNode* Else(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfExprContext* ifExpr();

  class  WhileStmtPartContext : public antlr4::ParserRuleContext {
  public:
    WhileStmtPartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QuotHuaL();
    antlr4::tree::TerminalNode *QuotHuaR();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhileStmtPartContext* whileStmtPart();

  class  WhileStmtContext : public antlr4::ParserRuleContext {
  public:
    WhileStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *While();
    antlr4::tree::TerminalNode *QuotYuanL();
    ExprContext *expr();
    antlr4::tree::TerminalNode *QuotYuanR();
    WhileStmtPartContext *whileStmtPart();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhileStmtContext* whileStmt();

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
    antlr4::tree::TerminalNode *ShiftLAssign();
    antlr4::tree::TerminalNode *ShiftRAssign();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AllAssignContext* allAssign();

  class  AllOpContext : public antlr4::ParserRuleContext {
  public:
    AllOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QusQusOp();
    antlr4::tree::TerminalNode *PointOp();
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

  AllOpContext* allOp();

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

  class  ExprPrefixContext : public antlr4::ParserRuleContext {
  public:
    ExprPrefixContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AddOp();
    antlr4::tree::TerminalNode *SubOp();
    antlr4::tree::TerminalNode *AddAddOp();
    antlr4::tree::TerminalNode *SubSubOp();
    antlr4::tree::TerminalNode *ReverseOp();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprPrefixContext* exprPrefix();

  class  ExprBodyContext : public antlr4::ParserRuleContext {
  public:
    ExprBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdsContext *ids();
    LiteralContext *literal();
    antlr4::tree::TerminalNode *ColonColon();
    antlr4::tree::TerminalNode *Id();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprBodyContext* exprBody();

  class  ExprSuffixContext : public antlr4::ParserRuleContext {
  public:
    ExprSuffixContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> AddAddOp();
    antlr4::tree::TerminalNode* AddAddOp(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SubSubOp();
    antlr4::tree::TerminalNode* SubSubOp(size_t i);
    std::vector<antlr4::tree::TerminalNode *> QuotYuanL();
    antlr4::tree::TerminalNode* QuotYuanL(size_t i);
    std::vector<antlr4::tree::TerminalNode *> QuotYuanR();
    antlr4::tree::TerminalNode* QuotYuanR(size_t i);
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);
    std::vector<antlr4::tree::TerminalNode *> QuotFangL();
    antlr4::tree::TerminalNode* QuotFangL(size_t i);
    std::vector<AllAssignContext *> allAssign();
    AllAssignContext* allAssign(size_t i);
    std::vector<AllOpContext *> allOp();
    AllOpContext* allOp(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprSuffixContext* exprSuffix();

  class  NormalExprContext : public antlr4::ParserRuleContext {
  public:
    NormalExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuotExprContext *quotExpr();
    ExprBodyContext *exprBody();
    std::vector<ExprPrefixContext *> exprPrefix();
    ExprPrefixContext* exprPrefix(size_t i);
    std::vector<ExprSuffixContext *> exprSuffix();
    ExprSuffixContext* exprSuffix(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NormalExprContext* normalExpr();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NormalExprContext *normalExpr();
    IfExprContext *ifExpr();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprContext* expr();

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
    ExprContext *expr();
    antlr4::tree::TerminalNode *Return();


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


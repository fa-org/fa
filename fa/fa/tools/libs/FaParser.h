
// Generated from Fa.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  FaParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, Class = 2, PublicLevel = 3, Return = 4, Static = 5, Use = 6, 
    Id = 7, QuotFangL = 8, QuotFangR = 9, QuotJianL = 10, QuotJianR = 11, 
    QuotHuaL = 12, QuotHuaR = 13, QuotYuanL = 14, QuotYuanR = 15, BitAnd = 16, 
    BitOr = 17, BitXor = 18, Comma = 19, Colon = 20, Semi = 21, Num = 22, 
    Comment1 = 23, Comment2 = 24, WS = 25
  };

  enum {
    RuleIds = 0, RuleTypeAfter = 1, RuleTypeExpr = 2, RuleUseStmt = 3, RuleReturnStmt = 4, 
    RuleClassParent = 5, RuleTypeVar = 6, RuleTypeVarList = 7, RuleClassItemExpr = 8, 
    RuleClassItemFieldStmt = 9, RuleClassItemFuncStmt = 10, RuleClassStmt = 11, 
    RuleProgram = 12
  };

  explicit FaParser(antlr4::TokenStream *input);
  ~FaParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class IdsContext;
  class TypeAfterContext;
  class TypeExprContext;
  class UseStmtContext;
  class ReturnStmtContext;
  class ClassParentContext;
  class TypeVarContext;
  class TypeVarListContext;
  class ClassItemExprContext;
  class ClassItemFieldStmtContext;
  class ClassItemFuncStmtContext;
  class ClassStmtContext;
  class ProgramContext; 

  class  IdsContext : public antlr4::ParserRuleContext {
  public:
    IdsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Id();
    antlr4::tree::TerminalNode* Id(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdsContext* ids();

  class  TypeAfterContext : public antlr4::ParserRuleContext {
  public:
    TypeAfterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QuotFangL();
    antlr4::tree::TerminalNode *QuotFangR();
    antlr4::tree::TerminalNode *BitAnd();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeAfterContext* typeAfter();

  class  TypeExprContext : public antlr4::ParserRuleContext {
  public:
    TypeExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Id();
    std::vector<TypeAfterContext *> typeAfter();
    TypeAfterContext* typeAfter(size_t i);
    antlr4::tree::TerminalNode *QuotJianL();
    std::vector<TypeExprContext *> typeExpr();
    TypeExprContext* typeExpr(size_t i);
    antlr4::tree::TerminalNode *QuotJianR();
    antlr4::tree::TerminalNode *QuotYuanL();
    antlr4::tree::TerminalNode *QuotYuanR();
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeExprContext* typeExpr();

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

  class  ReturnStmtContext : public antlr4::ParserRuleContext {
  public:
    ReturnStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Return();
    antlr4::tree::TerminalNode *Semi();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturnStmtContext* returnStmt();

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

  class  TypeVarContext : public antlr4::ParserRuleContext {
  public:
    TypeVarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeExprContext *typeExpr();
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

  class  ClassItemExprContext : public antlr4::ParserRuleContext {
  public:
    ClassItemExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Id();
    antlr4::tree::TerminalNode* Id(size_t i);
    antlr4::tree::TerminalNode *PublicLevel();
    antlr4::tree::TerminalNode *Static();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassItemExprContext* classItemExpr();

  class  ClassItemFieldStmtContext : public antlr4::ParserRuleContext {
  public:
    ClassItemFieldStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ClassItemExprContext *classItemExpr();
    antlr4::tree::TerminalNode *Semi();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassItemFieldStmtContext* classItemFieldStmt();

  class  ClassItemFuncStmtContext : public antlr4::ParserRuleContext {
  public:
    ClassItemFuncStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ClassItemExprContext *classItemExpr();
    antlr4::tree::TerminalNode *QuotYuanL();
    TypeVarListContext *typeVarList();
    antlr4::tree::TerminalNode *QuotYuanR();
    antlr4::tree::TerminalNode *QuotHuaL();
    antlr4::tree::TerminalNode *QuotHuaR();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassItemFuncStmtContext* classItemFuncStmt();

  class  ClassStmtContext : public antlr4::ParserRuleContext {
  public:
    ClassStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Class();
    antlr4::tree::TerminalNode *Id();
    antlr4::tree::TerminalNode *QuotHuaL();
    antlr4::tree::TerminalNode *QuotHuaR();
    antlr4::tree::TerminalNode *PublicLevel();
    ClassParentContext *classParent();
    std::vector<ClassItemFieldStmtContext *> classItemFieldStmt();
    ClassItemFieldStmtContext* classItemFieldStmt(size_t i);
    std::vector<ClassItemFuncStmtContext *> classItemFuncStmt();
    ClassItemFuncStmtContext* classItemFuncStmt(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassStmtContext* classStmt();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<UseStmtContext *> useStmt();
    UseStmtContext* useStmt(size_t i);
    std::vector<ClassStmtContext *> classStmt();
    ClassStmtContext* classStmt(size_t i);


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


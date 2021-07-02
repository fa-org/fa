
// Generated from Fa.g4 by ANTLR 4.9.2


#include "FaVisitor.h"

#include "FaParser.h"


using namespace antlrcpp;
using namespace antlr4;

FaParser::FaParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

FaParser::~FaParser() {
  delete _interpreter;
}

std::string FaParser::getGrammarFileName() const {
  return "Fa.g4";
}

const std::vector<std::string>& FaParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& FaParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- IdsContext ------------------------------------------------------------------

FaParser::IdsContext::IdsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FaParser::IdsContext::Id() {
  return getTokens(FaParser::Id);
}

tree::TerminalNode* FaParser::IdsContext::Id(size_t i) {
  return getToken(FaParser::Id, i);
}


size_t FaParser::IdsContext::getRuleIndex() const {
  return FaParser::RuleIds;
}


antlrcpp::Any FaParser::IdsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitIds(this);
  else
    return visitor->visitChildren(this);
}

FaParser::IdsContext* FaParser::ids() {
  IdsContext *_localctx = _tracker.createInstance<IdsContext>(_ctx, getState());
  enterRule(_localctx, 0, FaParser::RuleIds);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(26);
    match(FaParser::Id);
    setState(31);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::T__0) {
      setState(27);
      match(FaParser::T__0);
      setState(28);
      match(FaParser::Id);
      setState(33);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeAfterContext ------------------------------------------------------------------

FaParser::TypeAfterContext::TypeAfterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::TypeAfterContext::QuotFangL() {
  return getToken(FaParser::QuotFangL, 0);
}

tree::TerminalNode* FaParser::TypeAfterContext::QuotFangR() {
  return getToken(FaParser::QuotFangR, 0);
}

tree::TerminalNode* FaParser::TypeAfterContext::BitAnd() {
  return getToken(FaParser::BitAnd, 0);
}


size_t FaParser::TypeAfterContext::getRuleIndex() const {
  return FaParser::RuleTypeAfter;
}


antlrcpp::Any FaParser::TypeAfterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitTypeAfter(this);
  else
    return visitor->visitChildren(this);
}

FaParser::TypeAfterContext* FaParser::typeAfter() {
  TypeAfterContext *_localctx = _tracker.createInstance<TypeAfterContext>(_ctx, getState());
  enterRule(_localctx, 2, FaParser::RuleTypeAfter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(37);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::QuotFangL: {
        enterOuterAlt(_localctx, 1);
        setState(34);
        match(FaParser::QuotFangL);
        setState(35);
        match(FaParser::QuotFangR);
        break;
      }

      case FaParser::BitAnd: {
        enterOuterAlt(_localctx, 2);
        setState(36);
        match(FaParser::BitAnd);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeExprContext ------------------------------------------------------------------

FaParser::TypeExprContext::TypeExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::TypeExprContext::Id() {
  return getToken(FaParser::Id, 0);
}

std::vector<FaParser::TypeAfterContext *> FaParser::TypeExprContext::typeAfter() {
  return getRuleContexts<FaParser::TypeAfterContext>();
}

FaParser::TypeAfterContext* FaParser::TypeExprContext::typeAfter(size_t i) {
  return getRuleContext<FaParser::TypeAfterContext>(i);
}

tree::TerminalNode* FaParser::TypeExprContext::QuotJianL() {
  return getToken(FaParser::QuotJianL, 0);
}

std::vector<FaParser::TypeExprContext *> FaParser::TypeExprContext::typeExpr() {
  return getRuleContexts<FaParser::TypeExprContext>();
}

FaParser::TypeExprContext* FaParser::TypeExprContext::typeExpr(size_t i) {
  return getRuleContext<FaParser::TypeExprContext>(i);
}

tree::TerminalNode* FaParser::TypeExprContext::QuotJianR() {
  return getToken(FaParser::QuotJianR, 0);
}

tree::TerminalNode* FaParser::TypeExprContext::QuotYuanL() {
  return getToken(FaParser::QuotYuanL, 0);
}

tree::TerminalNode* FaParser::TypeExprContext::QuotYuanR() {
  return getToken(FaParser::QuotYuanR, 0);
}

std::vector<tree::TerminalNode *> FaParser::TypeExprContext::Comma() {
  return getTokens(FaParser::Comma);
}

tree::TerminalNode* FaParser::TypeExprContext::Comma(size_t i) {
  return getToken(FaParser::Comma, i);
}


size_t FaParser::TypeExprContext::getRuleIndex() const {
  return FaParser::RuleTypeExpr;
}


antlrcpp::Any FaParser::TypeExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitTypeExpr(this);
  else
    return visitor->visitChildren(this);
}

FaParser::TypeExprContext* FaParser::typeExpr() {
  TypeExprContext *_localctx = _tracker.createInstance<TypeExprContext>(_ctx, getState());
  enterRule(_localctx, 4, FaParser::RuleTypeExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(62);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      setState(39);
      match(FaParser::Id);
      break;
    }

    case 2: {
      setState(40);
      match(FaParser::Id);
      setState(41);
      match(FaParser::QuotJianL);
      setState(42);
      typeExpr();
      setState(47);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FaParser::Comma) {
        setState(43);
        match(FaParser::Comma);
        setState(44);
        typeExpr();
        setState(49);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(50);
      match(FaParser::QuotJianR);
      break;
    }

    case 3: {
      setState(52);
      match(FaParser::QuotYuanL);
      setState(53);
      typeExpr();
      setState(56); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(54);
        match(FaParser::Comma);
        setState(55);
        typeExpr();
        setState(58); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == FaParser::Comma);
      setState(60);
      match(FaParser::QuotYuanR);
      break;
    }

    default:
      break;
    }
    setState(67);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::QuotFangL

    || _la == FaParser::BitAnd) {
      setState(64);
      typeAfter();
      setState(69);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UseStmtContext ------------------------------------------------------------------

FaParser::UseStmtContext::UseStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::UseStmtContext::Use() {
  return getToken(FaParser::Use, 0);
}

FaParser::IdsContext* FaParser::UseStmtContext::ids() {
  return getRuleContext<FaParser::IdsContext>(0);
}

tree::TerminalNode* FaParser::UseStmtContext::Semi() {
  return getToken(FaParser::Semi, 0);
}


size_t FaParser::UseStmtContext::getRuleIndex() const {
  return FaParser::RuleUseStmt;
}


antlrcpp::Any FaParser::UseStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitUseStmt(this);
  else
    return visitor->visitChildren(this);
}

FaParser::UseStmtContext* FaParser::useStmt() {
  UseStmtContext *_localctx = _tracker.createInstance<UseStmtContext>(_ctx, getState());
  enterRule(_localctx, 6, FaParser::RuleUseStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(70);
    match(FaParser::Use);
    setState(71);
    ids();
    setState(72);
    match(FaParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStmtContext ------------------------------------------------------------------

FaParser::ReturnStmtContext::ReturnStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::ReturnStmtContext::Return() {
  return getToken(FaParser::Return, 0);
}

tree::TerminalNode* FaParser::ReturnStmtContext::Semi() {
  return getToken(FaParser::Semi, 0);
}


size_t FaParser::ReturnStmtContext::getRuleIndex() const {
  return FaParser::RuleReturnStmt;
}


antlrcpp::Any FaParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ReturnStmtContext* FaParser::returnStmt() {
  ReturnStmtContext *_localctx = _tracker.createInstance<ReturnStmtContext>(_ctx, getState());
  enterRule(_localctx, 8, FaParser::RuleReturnStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(74);
    match(FaParser::Return);
    setState(75);
    match(FaParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassParentContext ------------------------------------------------------------------

FaParser::ClassParentContext::ClassParentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::ClassParentContext::Colon() {
  return getToken(FaParser::Colon, 0);
}

std::vector<FaParser::IdsContext *> FaParser::ClassParentContext::ids() {
  return getRuleContexts<FaParser::IdsContext>();
}

FaParser::IdsContext* FaParser::ClassParentContext::ids(size_t i) {
  return getRuleContext<FaParser::IdsContext>(i);
}

std::vector<tree::TerminalNode *> FaParser::ClassParentContext::Comma() {
  return getTokens(FaParser::Comma);
}

tree::TerminalNode* FaParser::ClassParentContext::Comma(size_t i) {
  return getToken(FaParser::Comma, i);
}


size_t FaParser::ClassParentContext::getRuleIndex() const {
  return FaParser::RuleClassParent;
}


antlrcpp::Any FaParser::ClassParentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitClassParent(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ClassParentContext* FaParser::classParent() {
  ClassParentContext *_localctx = _tracker.createInstance<ClassParentContext>(_ctx, getState());
  enterRule(_localctx, 10, FaParser::RuleClassParent);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(77);
    match(FaParser::Colon);
    setState(78);
    ids();
    setState(83);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(79);
      match(FaParser::Comma);
      setState(80);
      ids();
      setState(85);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeVarContext ------------------------------------------------------------------

FaParser::TypeVarContext::TypeVarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::TypeExprContext* FaParser::TypeVarContext::typeExpr() {
  return getRuleContext<FaParser::TypeExprContext>(0);
}

tree::TerminalNode* FaParser::TypeVarContext::Id() {
  return getToken(FaParser::Id, 0);
}


size_t FaParser::TypeVarContext::getRuleIndex() const {
  return FaParser::RuleTypeVar;
}


antlrcpp::Any FaParser::TypeVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitTypeVar(this);
  else
    return visitor->visitChildren(this);
}

FaParser::TypeVarContext* FaParser::typeVar() {
  TypeVarContext *_localctx = _tracker.createInstance<TypeVarContext>(_ctx, getState());
  enterRule(_localctx, 12, FaParser::RuleTypeVar);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(86);
    typeExpr();
    setState(87);
    match(FaParser::Id);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeVarListContext ------------------------------------------------------------------

FaParser::TypeVarListContext::TypeVarListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FaParser::TypeVarContext *> FaParser::TypeVarListContext::typeVar() {
  return getRuleContexts<FaParser::TypeVarContext>();
}

FaParser::TypeVarContext* FaParser::TypeVarListContext::typeVar(size_t i) {
  return getRuleContext<FaParser::TypeVarContext>(i);
}

std::vector<tree::TerminalNode *> FaParser::TypeVarListContext::Comma() {
  return getTokens(FaParser::Comma);
}

tree::TerminalNode* FaParser::TypeVarListContext::Comma(size_t i) {
  return getToken(FaParser::Comma, i);
}


size_t FaParser::TypeVarListContext::getRuleIndex() const {
  return FaParser::RuleTypeVarList;
}


antlrcpp::Any FaParser::TypeVarListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitTypeVarList(this);
  else
    return visitor->visitChildren(this);
}

FaParser::TypeVarListContext* FaParser::typeVarList() {
  TypeVarListContext *_localctx = _tracker.createInstance<TypeVarListContext>(_ctx, getState());
  enterRule(_localctx, 14, FaParser::RuleTypeVarList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(89);
    typeVar();
    setState(94);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(90);
      match(FaParser::Comma);
      setState(91);
      typeVar();
      setState(96);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassItemExprContext ------------------------------------------------------------------

FaParser::ClassItemExprContext::ClassItemExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FaParser::ClassItemExprContext::Id() {
  return getTokens(FaParser::Id);
}

tree::TerminalNode* FaParser::ClassItemExprContext::Id(size_t i) {
  return getToken(FaParser::Id, i);
}

tree::TerminalNode* FaParser::ClassItemExprContext::PublicLevel() {
  return getToken(FaParser::PublicLevel, 0);
}

tree::TerminalNode* FaParser::ClassItemExprContext::Static() {
  return getToken(FaParser::Static, 0);
}


size_t FaParser::ClassItemExprContext::getRuleIndex() const {
  return FaParser::RuleClassItemExpr;
}


antlrcpp::Any FaParser::ClassItemExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitClassItemExpr(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ClassItemExprContext* FaParser::classItemExpr() {
  ClassItemExprContext *_localctx = _tracker.createInstance<ClassItemExprContext>(_ctx, getState());
  enterRule(_localctx, 16, FaParser::RuleClassItemExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(98);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::PublicLevel) {
      setState(97);
      match(FaParser::PublicLevel);
    }
    setState(101);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Static) {
      setState(100);
      match(FaParser::Static);
    }
    setState(103);
    match(FaParser::Id);
    setState(104);
    match(FaParser::Id);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassItemFieldStmtContext ------------------------------------------------------------------

FaParser::ClassItemFieldStmtContext::ClassItemFieldStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::ClassItemExprContext* FaParser::ClassItemFieldStmtContext::classItemExpr() {
  return getRuleContext<FaParser::ClassItemExprContext>(0);
}

tree::TerminalNode* FaParser::ClassItemFieldStmtContext::Semi() {
  return getToken(FaParser::Semi, 0);
}


size_t FaParser::ClassItemFieldStmtContext::getRuleIndex() const {
  return FaParser::RuleClassItemFieldStmt;
}


antlrcpp::Any FaParser::ClassItemFieldStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitClassItemFieldStmt(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ClassItemFieldStmtContext* FaParser::classItemFieldStmt() {
  ClassItemFieldStmtContext *_localctx = _tracker.createInstance<ClassItemFieldStmtContext>(_ctx, getState());
  enterRule(_localctx, 18, FaParser::RuleClassItemFieldStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(106);
    classItemExpr();
    setState(107);
    match(FaParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassItemFuncStmtContext ------------------------------------------------------------------

FaParser::ClassItemFuncStmtContext::ClassItemFuncStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::ClassItemExprContext* FaParser::ClassItemFuncStmtContext::classItemExpr() {
  return getRuleContext<FaParser::ClassItemExprContext>(0);
}

tree::TerminalNode* FaParser::ClassItemFuncStmtContext::QuotYuanL() {
  return getToken(FaParser::QuotYuanL, 0);
}

FaParser::TypeVarListContext* FaParser::ClassItemFuncStmtContext::typeVarList() {
  return getRuleContext<FaParser::TypeVarListContext>(0);
}

tree::TerminalNode* FaParser::ClassItemFuncStmtContext::QuotYuanR() {
  return getToken(FaParser::QuotYuanR, 0);
}

tree::TerminalNode* FaParser::ClassItemFuncStmtContext::QuotHuaL() {
  return getToken(FaParser::QuotHuaL, 0);
}

tree::TerminalNode* FaParser::ClassItemFuncStmtContext::QuotHuaR() {
  return getToken(FaParser::QuotHuaR, 0);
}


size_t FaParser::ClassItemFuncStmtContext::getRuleIndex() const {
  return FaParser::RuleClassItemFuncStmt;
}


antlrcpp::Any FaParser::ClassItemFuncStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitClassItemFuncStmt(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ClassItemFuncStmtContext* FaParser::classItemFuncStmt() {
  ClassItemFuncStmtContext *_localctx = _tracker.createInstance<ClassItemFuncStmtContext>(_ctx, getState());
  enterRule(_localctx, 20, FaParser::RuleClassItemFuncStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(109);
    classItemExpr();
    setState(110);
    match(FaParser::QuotYuanL);
    setState(111);
    typeVarList();
    setState(112);
    match(FaParser::QuotYuanR);
    setState(113);
    match(FaParser::QuotHuaL);
    setState(114);
    match(FaParser::QuotHuaR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassStmtContext ------------------------------------------------------------------

FaParser::ClassStmtContext::ClassStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::ClassStmtContext::Class() {
  return getToken(FaParser::Class, 0);
}

tree::TerminalNode* FaParser::ClassStmtContext::Id() {
  return getToken(FaParser::Id, 0);
}

tree::TerminalNode* FaParser::ClassStmtContext::QuotHuaL() {
  return getToken(FaParser::QuotHuaL, 0);
}

tree::TerminalNode* FaParser::ClassStmtContext::QuotHuaR() {
  return getToken(FaParser::QuotHuaR, 0);
}

tree::TerminalNode* FaParser::ClassStmtContext::PublicLevel() {
  return getToken(FaParser::PublicLevel, 0);
}

FaParser::ClassParentContext* FaParser::ClassStmtContext::classParent() {
  return getRuleContext<FaParser::ClassParentContext>(0);
}

std::vector<FaParser::ClassItemFieldStmtContext *> FaParser::ClassStmtContext::classItemFieldStmt() {
  return getRuleContexts<FaParser::ClassItemFieldStmtContext>();
}

FaParser::ClassItemFieldStmtContext* FaParser::ClassStmtContext::classItemFieldStmt(size_t i) {
  return getRuleContext<FaParser::ClassItemFieldStmtContext>(i);
}

std::vector<FaParser::ClassItemFuncStmtContext *> FaParser::ClassStmtContext::classItemFuncStmt() {
  return getRuleContexts<FaParser::ClassItemFuncStmtContext>();
}

FaParser::ClassItemFuncStmtContext* FaParser::ClassStmtContext::classItemFuncStmt(size_t i) {
  return getRuleContext<FaParser::ClassItemFuncStmtContext>(i);
}


size_t FaParser::ClassStmtContext::getRuleIndex() const {
  return FaParser::RuleClassStmt;
}


antlrcpp::Any FaParser::ClassStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitClassStmt(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ClassStmtContext* FaParser::classStmt() {
  ClassStmtContext *_localctx = _tracker.createInstance<ClassStmtContext>(_ctx, getState());
  enterRule(_localctx, 22, FaParser::RuleClassStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(117);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::PublicLevel) {
      setState(116);
      match(FaParser::PublicLevel);
    }
    setState(119);
    match(FaParser::Class);
    setState(120);
    match(FaParser::Id);
    setState(122);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Colon) {
      setState(121);
      classParent();
    }
    setState(124);
    match(FaParser::QuotHuaL);
    setState(129);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::PublicLevel)
      | (1ULL << FaParser::Static)
      | (1ULL << FaParser::Id))) != 0)) {
      setState(127);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
      case 1: {
        setState(125);
        classItemFieldStmt();
        break;
      }

      case 2: {
        setState(126);
        classItemFuncStmt();
        break;
      }

      default:
        break;
      }
      setState(131);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(132);
    match(FaParser::QuotHuaR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

FaParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FaParser::UseStmtContext *> FaParser::ProgramContext::useStmt() {
  return getRuleContexts<FaParser::UseStmtContext>();
}

FaParser::UseStmtContext* FaParser::ProgramContext::useStmt(size_t i) {
  return getRuleContext<FaParser::UseStmtContext>(i);
}

std::vector<FaParser::ClassStmtContext *> FaParser::ProgramContext::classStmt() {
  return getRuleContexts<FaParser::ClassStmtContext>();
}

FaParser::ClassStmtContext* FaParser::ProgramContext::classStmt(size_t i) {
  return getRuleContext<FaParser::ClassStmtContext>(i);
}


size_t FaParser::ProgramContext::getRuleIndex() const {
  return FaParser::RuleProgram;
}


antlrcpp::Any FaParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ProgramContext* FaParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 24, FaParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(137);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Use) {
      setState(134);
      useStmt();
      setState(139);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(143);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Class

    || _la == FaParser::PublicLevel) {
      setState(140);
      classStmt();
      setState(145);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> FaParser::_decisionToDFA;
atn::PredictionContextCache FaParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN FaParser::_atn;
std::vector<uint16_t> FaParser::_serializedATN;

std::vector<std::string> FaParser::_ruleNames = {
  "ids", "typeAfter", "typeExpr", "useStmt", "returnStmt", "classParent", 
  "typeVar", "typeVarList", "classItemExpr", "classItemFieldStmt", "classItemFuncStmt", 
  "classStmt", "program"
};

std::vector<std::string> FaParser::_literalNames = {
  "", "'.'", "'class'", "", "'return'", "'static'", "'use'", "", "'['", 
  "']'", "'<'", "'>'", "'{'", "'}'", "'('", "')'", "'&'", "'|'", "'^'", 
  "','", "':'", "';'"
};

std::vector<std::string> FaParser::_symbolicNames = {
  "", "", "Class", "PublicLevel", "Return", "Static", "Use", "Id", "QuotFangL", 
  "QuotFangR", "QuotJianL", "QuotJianR", "QuotHuaL", "QuotHuaR", "QuotYuanL", 
  "QuotYuanR", "BitAnd", "BitOr", "BitXor", "Comma", "Colon", "Semi", "Num", 
  "Comment1", "Comment2", "WS"
};

dfa::Vocabulary FaParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> FaParser::_tokenNames;

FaParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x1b, 0x95, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x20, 0xa, 
       0x2, 0xc, 0x2, 0xe, 0x2, 0x23, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x5, 0x3, 0x28, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x30, 0xa, 0x4, 0xc, 0x4, 0xe, 
       0x4, 0x33, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x6, 0x4, 0x3b, 0xa, 0x4, 0xd, 0x4, 0xe, 0x4, 0x3c, 
       0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x41, 0xa, 0x4, 0x3, 0x4, 0x7, 0x4, 
       0x44, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x47, 0xb, 0x4, 0x3, 0x5, 0x3, 
       0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 
       0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x54, 0xa, 0x7, 0xc, 0x7, 
       0xe, 0x7, 0x57, 0xb, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 
       0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x5f, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 
       0x62, 0xb, 0x9, 0x3, 0xa, 0x5, 0xa, 0x65, 0xa, 0xa, 0x3, 0xa, 0x5, 
       0xa, 0x68, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 
       0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
       0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x5, 0xd, 0x78, 0xa, 0xd, 0x3, 0xd, 
       0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x7d, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 
       0x3, 0xd, 0x7, 0xd, 0x82, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x85, 0xb, 
       0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x7, 0xe, 0x8a, 0xa, 0xe, 0xc, 
       0xe, 0xe, 0xe, 0x8d, 0xb, 0xe, 0x3, 0xe, 0x7, 0xe, 0x90, 0xa, 0xe, 
       0xc, 0xe, 0xe, 0xe, 0x93, 0xb, 0xe, 0x3, 0xe, 0x2, 0x2, 0xf, 0x2, 
       0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
       0x2, 0x2, 0x2, 0x98, 0x2, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x4, 0x27, 0x3, 
       0x2, 0x2, 0x2, 0x6, 0x40, 0x3, 0x2, 0x2, 0x2, 0x8, 0x48, 0x3, 0x2, 
       0x2, 0x2, 0xa, 0x4c, 0x3, 0x2, 0x2, 0x2, 0xc, 0x4f, 0x3, 0x2, 0x2, 
       0x2, 0xe, 0x58, 0x3, 0x2, 0x2, 0x2, 0x10, 0x5b, 0x3, 0x2, 0x2, 0x2, 
       0x12, 0x64, 0x3, 0x2, 0x2, 0x2, 0x14, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x16, 
       0x6f, 0x3, 0x2, 0x2, 0x2, 0x18, 0x77, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x8b, 
       0x3, 0x2, 0x2, 0x2, 0x1c, 0x21, 0x7, 0x9, 0x2, 0x2, 0x1d, 0x1e, 0x7, 
       0x3, 0x2, 0x2, 0x1e, 0x20, 0x7, 0x9, 0x2, 0x2, 0x1f, 0x1d, 0x3, 0x2, 
       0x2, 0x2, 0x20, 0x23, 0x3, 0x2, 0x2, 0x2, 0x21, 0x1f, 0x3, 0x2, 0x2, 
       0x2, 0x21, 0x22, 0x3, 0x2, 0x2, 0x2, 0x22, 0x3, 0x3, 0x2, 0x2, 0x2, 
       0x23, 0x21, 0x3, 0x2, 0x2, 0x2, 0x24, 0x25, 0x7, 0xa, 0x2, 0x2, 0x25, 
       0x28, 0x7, 0xb, 0x2, 0x2, 0x26, 0x28, 0x7, 0x12, 0x2, 0x2, 0x27, 
       0x24, 0x3, 0x2, 0x2, 0x2, 0x27, 0x26, 0x3, 0x2, 0x2, 0x2, 0x28, 0x5, 
       0x3, 0x2, 0x2, 0x2, 0x29, 0x41, 0x7, 0x9, 0x2, 0x2, 0x2a, 0x2b, 0x7, 
       0x9, 0x2, 0x2, 0x2b, 0x2c, 0x7, 0xc, 0x2, 0x2, 0x2c, 0x31, 0x5, 0x6, 
       0x4, 0x2, 0x2d, 0x2e, 0x7, 0x15, 0x2, 0x2, 0x2e, 0x30, 0x5, 0x6, 
       0x4, 0x2, 0x2f, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x30, 0x33, 0x3, 0x2, 0x2, 
       0x2, 0x31, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x3, 0x2, 0x2, 0x2, 
       0x32, 0x34, 0x3, 0x2, 0x2, 0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 0x34, 
       0x35, 0x7, 0xd, 0x2, 0x2, 0x35, 0x41, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 
       0x7, 0x10, 0x2, 0x2, 0x37, 0x3a, 0x5, 0x6, 0x4, 0x2, 0x38, 0x39, 
       0x7, 0x15, 0x2, 0x2, 0x39, 0x3b, 0x5, 0x6, 0x4, 0x2, 0x3a, 0x38, 
       0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3a, 0x3, 
       0x2, 0x2, 0x2, 0x3c, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 0x3, 0x2, 
       0x2, 0x2, 0x3e, 0x3f, 0x7, 0x11, 0x2, 0x2, 0x3f, 0x41, 0x3, 0x2, 
       0x2, 0x2, 0x40, 0x29, 0x3, 0x2, 0x2, 0x2, 0x40, 0x2a, 0x3, 0x2, 0x2, 
       0x2, 0x40, 0x36, 0x3, 0x2, 0x2, 0x2, 0x41, 0x45, 0x3, 0x2, 0x2, 0x2, 
       0x42, 0x44, 0x5, 0x4, 0x3, 0x2, 0x43, 0x42, 0x3, 0x2, 0x2, 0x2, 0x44, 
       0x47, 0x3, 0x2, 0x2, 0x2, 0x45, 0x43, 0x3, 0x2, 0x2, 0x2, 0x45, 0x46, 
       0x3, 0x2, 0x2, 0x2, 0x46, 0x7, 0x3, 0x2, 0x2, 0x2, 0x47, 0x45, 0x3, 
       0x2, 0x2, 0x2, 0x48, 0x49, 0x7, 0x8, 0x2, 0x2, 0x49, 0x4a, 0x5, 0x2, 
       0x2, 0x2, 0x4a, 0x4b, 0x7, 0x17, 0x2, 0x2, 0x4b, 0x9, 0x3, 0x2, 0x2, 
       0x2, 0x4c, 0x4d, 0x7, 0x6, 0x2, 0x2, 0x4d, 0x4e, 0x7, 0x17, 0x2, 
       0x2, 0x4e, 0xb, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0x7, 0x16, 0x2, 0x2, 
       0x50, 0x55, 0x5, 0x2, 0x2, 0x2, 0x51, 0x52, 0x7, 0x15, 0x2, 0x2, 
       0x52, 0x54, 0x5, 0x2, 0x2, 0x2, 0x53, 0x51, 0x3, 0x2, 0x2, 0x2, 0x54, 
       0x57, 0x3, 0x2, 0x2, 0x2, 0x55, 0x53, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 
       0x3, 0x2, 0x2, 0x2, 0x56, 0xd, 0x3, 0x2, 0x2, 0x2, 0x57, 0x55, 0x3, 
       0x2, 0x2, 0x2, 0x58, 0x59, 0x5, 0x6, 0x4, 0x2, 0x59, 0x5a, 0x7, 0x9, 
       0x2, 0x2, 0x5a, 0xf, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x60, 0x5, 0xe, 0x8, 
       0x2, 0x5c, 0x5d, 0x7, 0x15, 0x2, 0x2, 0x5d, 0x5f, 0x5, 0xe, 0x8, 
       0x2, 0x5e, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x62, 0x3, 0x2, 0x2, 0x2, 
       0x60, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x3, 0x2, 0x2, 0x2, 0x61, 
       0x11, 0x3, 0x2, 0x2, 0x2, 0x62, 0x60, 0x3, 0x2, 0x2, 0x2, 0x63, 0x65, 
       0x7, 0x5, 0x2, 0x2, 0x64, 0x63, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 0x3, 
       0x2, 0x2, 0x2, 0x65, 0x67, 0x3, 0x2, 0x2, 0x2, 0x66, 0x68, 0x7, 0x7, 
       0x2, 0x2, 0x67, 0x66, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x3, 0x2, 0x2, 
       0x2, 0x68, 0x69, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x7, 0x9, 0x2, 0x2, 
       0x6a, 0x6b, 0x7, 0x9, 0x2, 0x2, 0x6b, 0x13, 0x3, 0x2, 0x2, 0x2, 0x6c, 
       0x6d, 0x5, 0x12, 0xa, 0x2, 0x6d, 0x6e, 0x7, 0x17, 0x2, 0x2, 0x6e, 
       0x15, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x5, 0x12, 0xa, 0x2, 0x70, 
       0x71, 0x7, 0x10, 0x2, 0x2, 0x71, 0x72, 0x5, 0x10, 0x9, 0x2, 0x72, 
       0x73, 0x7, 0x11, 0x2, 0x2, 0x73, 0x74, 0x7, 0xe, 0x2, 0x2, 0x74, 
       0x75, 0x7, 0xf, 0x2, 0x2, 0x75, 0x17, 0x3, 0x2, 0x2, 0x2, 0x76, 0x78, 
       0x7, 0x5, 0x2, 0x2, 0x77, 0x76, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0x3, 
       0x2, 0x2, 0x2, 0x78, 0x79, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x7, 0x4, 
       0x2, 0x2, 0x7a, 0x7c, 0x7, 0x9, 0x2, 0x2, 0x7b, 0x7d, 0x5, 0xc, 0x7, 
       0x2, 0x7c, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x3, 0x2, 0x2, 0x2, 
       0x7d, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x83, 0x7, 0xe, 0x2, 0x2, 0x7f, 
       0x82, 0x5, 0x14, 0xb, 0x2, 0x80, 0x82, 0x5, 0x16, 0xc, 0x2, 0x81, 
       0x7f, 0x3, 0x2, 0x2, 0x2, 0x81, 0x80, 0x3, 0x2, 0x2, 0x2, 0x82, 0x85, 
       0x3, 0x2, 0x2, 0x2, 0x83, 0x81, 0x3, 0x2, 0x2, 0x2, 0x83, 0x84, 0x3, 
       0x2, 0x2, 0x2, 0x84, 0x86, 0x3, 0x2, 0x2, 0x2, 0x85, 0x83, 0x3, 0x2, 
       0x2, 0x2, 0x86, 0x87, 0x7, 0xf, 0x2, 0x2, 0x87, 0x19, 0x3, 0x2, 0x2, 
       0x2, 0x88, 0x8a, 0x5, 0x8, 0x5, 0x2, 0x89, 0x88, 0x3, 0x2, 0x2, 0x2, 
       0x8a, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8b, 
       0x8c, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x91, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8b, 
       0x3, 0x2, 0x2, 0x2, 0x8e, 0x90, 0x5, 0x18, 0xd, 0x2, 0x8f, 0x8e, 
       0x3, 0x2, 0x2, 0x2, 0x90, 0x93, 0x3, 0x2, 0x2, 0x2, 0x91, 0x8f, 0x3, 
       0x2, 0x2, 0x2, 0x91, 0x92, 0x3, 0x2, 0x2, 0x2, 0x92, 0x1b, 0x3, 0x2, 
       0x2, 0x2, 0x93, 0x91, 0x3, 0x2, 0x2, 0x2, 0x12, 0x21, 0x27, 0x31, 
       0x3c, 0x40, 0x45, 0x55, 0x60, 0x64, 0x67, 0x77, 0x7c, 0x81, 0x83, 
       0x8b, 0x91, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

FaParser::Initializer FaParser::_init;

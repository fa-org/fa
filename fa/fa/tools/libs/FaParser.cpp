
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
    setState(46);
    match(FaParser::Id);
    setState(51);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::T__0) {
      setState(47);
      match(FaParser::T__0);
      setState(48);
      match(FaParser::Id);
      setState(53);
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

//----------------- PublicLevelContext ------------------------------------------------------------------

FaParser::PublicLevelContext::PublicLevelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::PublicLevelContext::Public() {
  return getToken(FaParser::Public, 0);
}

tree::TerminalNode* FaParser::PublicLevelContext::Internal() {
  return getToken(FaParser::Internal, 0);
}

tree::TerminalNode* FaParser::PublicLevelContext::Protected() {
  return getToken(FaParser::Protected, 0);
}

tree::TerminalNode* FaParser::PublicLevelContext::Private() {
  return getToken(FaParser::Private, 0);
}


size_t FaParser::PublicLevelContext::getRuleIndex() const {
  return FaParser::RulePublicLevel;
}


antlrcpp::Any FaParser::PublicLevelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitPublicLevel(this);
  else
    return visitor->visitChildren(this);
}

FaParser::PublicLevelContext* FaParser::publicLevel() {
  PublicLevelContext *_localctx = _tracker.createInstance<PublicLevelContext>(_ctx, getState());
  enterRule(_localctx, 2, FaParser::RulePublicLevel);
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
    setState(54);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeBeforeContext ------------------------------------------------------------------

FaParser::TypeBeforeContext::TypeBeforeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::TypeBeforeContext::Const() {
  return getToken(FaParser::Const, 0);
}

tree::TerminalNode* FaParser::TypeBeforeContext::Volatile() {
  return getToken(FaParser::Volatile, 0);
}


size_t FaParser::TypeBeforeContext::getRuleIndex() const {
  return FaParser::RuleTypeBefore;
}


antlrcpp::Any FaParser::TypeBeforeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitTypeBefore(this);
  else
    return visitor->visitChildren(this);
}

FaParser::TypeBeforeContext* FaParser::typeBefore() {
  TypeBeforeContext *_localctx = _tracker.createInstance<TypeBeforeContext>(_ctx, getState());
  enterRule(_localctx, 4, FaParser::RuleTypeBefore);
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
    setState(56);
    _la = _input->LA(1);
    if (!(_la == FaParser::Const

    || _la == FaParser::Volatile)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
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
  enterRule(_localctx, 6, FaParser::RuleTypeAfter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(61);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::QuotFangL: {
        enterOuterAlt(_localctx, 1);
        setState(58);
        match(FaParser::QuotFangL);
        setState(59);
        match(FaParser::QuotFangR);
        break;
      }

      case FaParser::BitAnd: {
        enterOuterAlt(_localctx, 2);
        setState(60);
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

//----------------- TypeContext ------------------------------------------------------------------

FaParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::TypeContext::Id() {
  return getToken(FaParser::Id, 0);
}

FaParser::TypeBeforeContext* FaParser::TypeContext::typeBefore() {
  return getRuleContext<FaParser::TypeBeforeContext>(0);
}

std::vector<FaParser::TypeAfterContext *> FaParser::TypeContext::typeAfter() {
  return getRuleContexts<FaParser::TypeAfterContext>();
}

FaParser::TypeAfterContext* FaParser::TypeContext::typeAfter(size_t i) {
  return getRuleContext<FaParser::TypeAfterContext>(i);
}

tree::TerminalNode* FaParser::TypeContext::QuotJianL() {
  return getToken(FaParser::QuotJianL, 0);
}

std::vector<FaParser::TypeContext *> FaParser::TypeContext::type() {
  return getRuleContexts<FaParser::TypeContext>();
}

FaParser::TypeContext* FaParser::TypeContext::type(size_t i) {
  return getRuleContext<FaParser::TypeContext>(i);
}

tree::TerminalNode* FaParser::TypeContext::QuotJianR() {
  return getToken(FaParser::QuotJianR, 0);
}

tree::TerminalNode* FaParser::TypeContext::QuotYuanL() {
  return getToken(FaParser::QuotYuanL, 0);
}

tree::TerminalNode* FaParser::TypeContext::QuotYuanR() {
  return getToken(FaParser::QuotYuanR, 0);
}

std::vector<tree::TerminalNode *> FaParser::TypeContext::Comma() {
  return getTokens(FaParser::Comma);
}

tree::TerminalNode* FaParser::TypeContext::Comma(size_t i) {
  return getToken(FaParser::Comma, i);
}


size_t FaParser::TypeContext::getRuleIndex() const {
  return FaParser::RuleType;
}


antlrcpp::Any FaParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

FaParser::TypeContext* FaParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 8, FaParser::RuleType);
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
    setState(64);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Const

    || _la == FaParser::Volatile) {
      setState(63);
      typeBefore();
    }
    setState(89);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      setState(66);
      match(FaParser::Id);
      break;
    }

    case 2: {
      setState(67);
      match(FaParser::Id);
      setState(68);
      match(FaParser::QuotJianL);
      setState(69);
      type();
      setState(74);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FaParser::Comma) {
        setState(70);
        match(FaParser::Comma);
        setState(71);
        type();
        setState(76);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(77);
      match(FaParser::QuotJianR);
      break;
    }

    case 3: {
      setState(79);
      match(FaParser::QuotYuanL);
      setState(80);
      type();
      setState(83); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(81);
        match(FaParser::Comma);
        setState(82);
        type();
        setState(85); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == FaParser::Comma);
      setState(87);
      match(FaParser::QuotYuanR);
      break;
    }

    default:
      break;
    }
    setState(94);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::QuotFangL

    || _la == FaParser::BitAnd) {
      setState(91);
      typeAfter();
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

//----------------- ETypeBeforeContext ------------------------------------------------------------------

FaParser::ETypeBeforeContext::ETypeBeforeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::ETypeBeforeContext::Const() {
  return getToken(FaParser::Const, 0);
}


size_t FaParser::ETypeBeforeContext::getRuleIndex() const {
  return FaParser::RuleETypeBefore;
}


antlrcpp::Any FaParser::ETypeBeforeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitETypeBefore(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ETypeBeforeContext* FaParser::eTypeBefore() {
  ETypeBeforeContext *_localctx = _tracker.createInstance<ETypeBeforeContext>(_ctx, getState());
  enterRule(_localctx, 10, FaParser::RuleETypeBefore);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(97);
    match(FaParser::Const);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ETypeAfterContext ------------------------------------------------------------------

FaParser::ETypeAfterContext::ETypeAfterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::ETypeAfterContext::QuotFangL() {
  return getToken(FaParser::QuotFangL, 0);
}

tree::TerminalNode* FaParser::ETypeAfterContext::QuotFangR() {
  return getToken(FaParser::QuotFangR, 0);
}

tree::TerminalNode* FaParser::ETypeAfterContext::BitAnd() {
  return getToken(FaParser::BitAnd, 0);
}

tree::TerminalNode* FaParser::ETypeAfterContext::Star() {
  return getToken(FaParser::Star, 0);
}


size_t FaParser::ETypeAfterContext::getRuleIndex() const {
  return FaParser::RuleETypeAfter;
}


antlrcpp::Any FaParser::ETypeAfterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitETypeAfter(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ETypeAfterContext* FaParser::eTypeAfter() {
  ETypeAfterContext *_localctx = _tracker.createInstance<ETypeAfterContext>(_ctx, getState());
  enterRule(_localctx, 12, FaParser::RuleETypeAfter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(103);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::QuotFangL: {
        enterOuterAlt(_localctx, 1);
        setState(99);
        match(FaParser::QuotFangL);
        setState(100);
        match(FaParser::QuotFangR);
        break;
      }

      case FaParser::BitAnd: {
        enterOuterAlt(_localctx, 2);
        setState(101);
        match(FaParser::BitAnd);
        break;
      }

      case FaParser::Star: {
        enterOuterAlt(_localctx, 3);
        setState(102);
        match(FaParser::Star);
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

//----------------- ETypeContext ------------------------------------------------------------------

FaParser::ETypeContext::ETypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::ETypeContext::Id() {
  return getToken(FaParser::Id, 0);
}

FaParser::ETypeBeforeContext* FaParser::ETypeContext::eTypeBefore() {
  return getRuleContext<FaParser::ETypeBeforeContext>(0);
}

std::vector<FaParser::ETypeAfterContext *> FaParser::ETypeContext::eTypeAfter() {
  return getRuleContexts<FaParser::ETypeAfterContext>();
}

FaParser::ETypeAfterContext* FaParser::ETypeContext::eTypeAfter(size_t i) {
  return getRuleContext<FaParser::ETypeAfterContext>(i);
}


size_t FaParser::ETypeContext::getRuleIndex() const {
  return FaParser::RuleEType;
}


antlrcpp::Any FaParser::ETypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitEType(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ETypeContext* FaParser::eType() {
  ETypeContext *_localctx = _tracker.createInstance<ETypeContext>(_ctx, getState());
  enterRule(_localctx, 14, FaParser::RuleEType);
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
    setState(106);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Const) {
      setState(105);
      eTypeBefore();
    }
    setState(108);
    match(FaParser::Id);
    setState(112);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::QuotFangL)
      | (1ULL << FaParser::BitAnd)
      | (1ULL << FaParser::Star))) != 0)) {
      setState(109);
      eTypeAfter();
      setState(114);
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

FaParser::TypeContext* FaParser::TypeVarContext::type() {
  return getRuleContext<FaParser::TypeContext>(0);
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
  enterRule(_localctx, 16, FaParser::RuleTypeVar);
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
    setState(115);
    type();
    setState(117);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Id) {
      setState(116);
      match(FaParser::Id);
    }
   
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
  enterRule(_localctx, 18, FaParser::RuleTypeVarList);
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
    setState(119);
    typeVar();
    setState(124);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(120);
      match(FaParser::Comma);
      setState(121);
      typeVar();
      setState(126);
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

//----------------- ETypeVarContext ------------------------------------------------------------------

FaParser::ETypeVarContext::ETypeVarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::ETypeContext* FaParser::ETypeVarContext::eType() {
  return getRuleContext<FaParser::ETypeContext>(0);
}

tree::TerminalNode* FaParser::ETypeVarContext::Id() {
  return getToken(FaParser::Id, 0);
}


size_t FaParser::ETypeVarContext::getRuleIndex() const {
  return FaParser::RuleETypeVar;
}


antlrcpp::Any FaParser::ETypeVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitETypeVar(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ETypeVarContext* FaParser::eTypeVar() {
  ETypeVarContext *_localctx = _tracker.createInstance<ETypeVarContext>(_ctx, getState());
  enterRule(_localctx, 20, FaParser::RuleETypeVar);
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
    setState(127);
    eType();
    setState(129);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Id) {
      setState(128);
      match(FaParser::Id);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ETypeVarListContext ------------------------------------------------------------------

FaParser::ETypeVarListContext::ETypeVarListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FaParser::ETypeVarContext *> FaParser::ETypeVarListContext::eTypeVar() {
  return getRuleContexts<FaParser::ETypeVarContext>();
}

FaParser::ETypeVarContext* FaParser::ETypeVarListContext::eTypeVar(size_t i) {
  return getRuleContext<FaParser::ETypeVarContext>(i);
}

std::vector<tree::TerminalNode *> FaParser::ETypeVarListContext::Comma() {
  return getTokens(FaParser::Comma);
}

tree::TerminalNode* FaParser::ETypeVarListContext::Comma(size_t i) {
  return getToken(FaParser::Comma, i);
}


size_t FaParser::ETypeVarListContext::getRuleIndex() const {
  return FaParser::RuleETypeVarList;
}


antlrcpp::Any FaParser::ETypeVarListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitETypeVarList(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ETypeVarListContext* FaParser::eTypeVarList() {
  ETypeVarListContext *_localctx = _tracker.createInstance<ETypeVarListContext>(_ctx, getState());
  enterRule(_localctx, 22, FaParser::RuleETypeVarList);
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
    setState(131);
    eTypeVar();
    setState(136);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(132);
      match(FaParser::Comma);
      setState(133);
      eTypeVar();
      setState(138);
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
  enterRule(_localctx, 24, FaParser::RuleUseStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(139);
    match(FaParser::Use);
    setState(140);
    ids();
    setState(141);
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
  enterRule(_localctx, 26, FaParser::RuleReturnStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(143);
    match(FaParser::Return);
    setState(144);
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
  enterRule(_localctx, 28, FaParser::RuleClassParent);
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
    setState(146);
    match(FaParser::Colon);
    setState(147);
    ids();
    setState(152);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(148);
      match(FaParser::Comma);
      setState(149);
      ids();
      setState(154);
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

FaParser::PublicLevelContext* FaParser::ClassItemExprContext::publicLevel() {
  return getRuleContext<FaParser::PublicLevelContext>(0);
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
  enterRule(_localctx, 30, FaParser::RuleClassItemExpr);
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
    setState(156);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(155);
      publicLevel();
    }
    setState(159);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Static) {
      setState(158);
      match(FaParser::Static);
    }
    setState(161);
    match(FaParser::Id);
    setState(162);
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
  enterRule(_localctx, 32, FaParser::RuleClassItemFieldStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(164);
    classItemExpr();
    setState(165);
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
  enterRule(_localctx, 34, FaParser::RuleClassItemFuncStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(167);
    classItemExpr();
    setState(168);
    match(FaParser::QuotYuanL);
    setState(169);
    typeVarList();
    setState(170);
    match(FaParser::QuotYuanR);
    setState(171);
    match(FaParser::QuotHuaL);
    setState(172);
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

FaParser::PublicLevelContext* FaParser::ClassStmtContext::publicLevel() {
  return getRuleContext<FaParser::PublicLevelContext>(0);
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
  enterRule(_localctx, 36, FaParser::RuleClassStmt);
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
    setState(175);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(174);
      publicLevel();
    }
    setState(177);
    match(FaParser::Class);
    setState(178);
    match(FaParser::Id);
    setState(180);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Colon) {
      setState(179);
      classParent();
    }
    setState(182);
    match(FaParser::QuotHuaL);
    setState(187);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private)
      | (1ULL << FaParser::Static)
      | (1ULL << FaParser::Id))) != 0)) {
      setState(185);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
      case 1: {
        setState(183);
        classItemFieldStmt();
        break;
      }

      case 2: {
        setState(184);
        classItemFuncStmt();
        break;
      }

      default:
        break;
      }
      setState(189);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(190);
    match(FaParser::QuotHuaR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallConventionContext ------------------------------------------------------------------

FaParser::CallConventionContext::CallConventionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::CallConventionContext::CC__Cdecl() {
  return getToken(FaParser::CC__Cdecl, 0);
}

tree::TerminalNode* FaParser::CallConventionContext::CC__FastCall() {
  return getToken(FaParser::CC__FastCall, 0);
}

tree::TerminalNode* FaParser::CallConventionContext::CC__StdCall() {
  return getToken(FaParser::CC__StdCall, 0);
}


size_t FaParser::CallConventionContext::getRuleIndex() const {
  return FaParser::RuleCallConvention;
}


antlrcpp::Any FaParser::CallConventionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitCallConvention(this);
  else
    return visitor->visitChildren(this);
}

FaParser::CallConventionContext* FaParser::callConvention() {
  CallConventionContext *_localctx = _tracker.createInstance<CallConventionContext>(_ctx, getState());
  enterRule(_localctx, 38, FaParser::RuleCallConvention);
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
    setState(192);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::CC__Cdecl)
      | (1ULL << FaParser::CC__FastCall)
      | (1ULL << FaParser::CC__StdCall))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExternStmtContext ------------------------------------------------------------------

FaParser::ExternStmtContext::ExternStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::ExternStmtContext::Extern() {
  return getToken(FaParser::Extern, 0);
}

FaParser::ETypeContext* FaParser::ExternStmtContext::eType() {
  return getRuleContext<FaParser::ETypeContext>(0);
}

FaParser::CallConventionContext* FaParser::ExternStmtContext::callConvention() {
  return getRuleContext<FaParser::CallConventionContext>(0);
}

tree::TerminalNode* FaParser::ExternStmtContext::Id() {
  return getToken(FaParser::Id, 0);
}

tree::TerminalNode* FaParser::ExternStmtContext::QuotYuanL() {
  return getToken(FaParser::QuotYuanL, 0);
}

FaParser::ETypeVarListContext* FaParser::ExternStmtContext::eTypeVarList() {
  return getRuleContext<FaParser::ETypeVarListContext>(0);
}

tree::TerminalNode* FaParser::ExternStmtContext::QuotYuanR() {
  return getToken(FaParser::QuotYuanR, 0);
}

tree::TerminalNode* FaParser::ExternStmtContext::Semi() {
  return getToken(FaParser::Semi, 0);
}


size_t FaParser::ExternStmtContext::getRuleIndex() const {
  return FaParser::RuleExternStmt;
}


antlrcpp::Any FaParser::ExternStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitExternStmt(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ExternStmtContext* FaParser::externStmt() {
  ExternStmtContext *_localctx = _tracker.createInstance<ExternStmtContext>(_ctx, getState());
  enterRule(_localctx, 40, FaParser::RuleExternStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(194);
    match(FaParser::Extern);
    setState(195);
    eType();
    setState(196);
    callConvention();
    setState(197);
    match(FaParser::Id);
    setState(198);
    match(FaParser::QuotYuanL);
    setState(199);
    eTypeVarList();
    setState(200);
    match(FaParser::QuotYuanR);
    setState(201);
    match(FaParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FaEntryMainFuncStmtContext ------------------------------------------------------------------

FaParser::FaEntryMainFuncStmtContext::FaEntryMainFuncStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::FaEntryMainFuncStmtContext::Static() {
  return getToken(FaParser::Static, 0);
}

FaParser::TypeContext* FaParser::FaEntryMainFuncStmtContext::type() {
  return getRuleContext<FaParser::TypeContext>(0);
}

tree::TerminalNode* FaParser::FaEntryMainFuncStmtContext::FaEntryMain() {
  return getToken(FaParser::FaEntryMain, 0);
}

tree::TerminalNode* FaParser::FaEntryMainFuncStmtContext::QuotYuanL() {
  return getToken(FaParser::QuotYuanL, 0);
}

tree::TerminalNode* FaParser::FaEntryMainFuncStmtContext::QuotYuanR() {
  return getToken(FaParser::QuotYuanR, 0);
}

tree::TerminalNode* FaParser::FaEntryMainFuncStmtContext::QuotHuaL() {
  return getToken(FaParser::QuotHuaL, 0);
}

tree::TerminalNode* FaParser::FaEntryMainFuncStmtContext::QuotHuaR() {
  return getToken(FaParser::QuotHuaR, 0);
}


size_t FaParser::FaEntryMainFuncStmtContext::getRuleIndex() const {
  return FaParser::RuleFaEntryMainFuncStmt;
}


antlrcpp::Any FaParser::FaEntryMainFuncStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitFaEntryMainFuncStmt(this);
  else
    return visitor->visitChildren(this);
}

FaParser::FaEntryMainFuncStmtContext* FaParser::faEntryMainFuncStmt() {
  FaEntryMainFuncStmtContext *_localctx = _tracker.createInstance<FaEntryMainFuncStmtContext>(_ctx, getState());
  enterRule(_localctx, 42, FaParser::RuleFaEntryMainFuncStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(203);
    match(FaParser::Static);
    setState(204);
    type();
    setState(205);
    match(FaParser::FaEntryMain);
    setState(206);
    match(FaParser::QuotYuanL);
    setState(207);
    match(FaParser::QuotYuanR);
    setState(208);
    match(FaParser::QuotHuaL);
    setState(209);
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

std::vector<FaParser::ExternStmtContext *> FaParser::ProgramContext::externStmt() {
  return getRuleContexts<FaParser::ExternStmtContext>();
}

FaParser::ExternStmtContext* FaParser::ProgramContext::externStmt(size_t i) {
  return getRuleContext<FaParser::ExternStmtContext>(i);
}

std::vector<FaParser::ClassStmtContext *> FaParser::ProgramContext::classStmt() {
  return getRuleContexts<FaParser::ClassStmtContext>();
}

FaParser::ClassStmtContext* FaParser::ProgramContext::classStmt(size_t i) {
  return getRuleContext<FaParser::ClassStmtContext>(i);
}

FaParser::FaEntryMainFuncStmtContext* FaParser::ProgramContext::faEntryMainFuncStmt() {
  return getRuleContext<FaParser::FaEntryMainFuncStmtContext>(0);
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
  enterRule(_localctx, 44, FaParser::RuleProgram);
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
    setState(214);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Use) {
      setState(211);
      useStmt();
      setState(216);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(220);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Extern) {
      setState(217);
      externStmt();
      setState(222);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(226);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Class)
      | (1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(223);
      classStmt();
      setState(228);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(230);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Static) {
      setState(229);
      faEntryMainFuncStmt();
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
  "ids", "publicLevel", "typeBefore", "typeAfter", "type", "eTypeBefore", 
  "eTypeAfter", "eType", "typeVar", "typeVarList", "eTypeVar", "eTypeVarList", 
  "useStmt", "returnStmt", "classParent", "classItemExpr", "classItemFieldStmt", 
  "classItemFuncStmt", "classStmt", "callConvention", "externStmt", "faEntryMainFuncStmt", 
  "program"
};

std::vector<std::string> FaParser::_literalNames = {
  "", "'.'", "'__cdecl'", "'__fastcall'", "'__stdcall'", "'class'", "'const'", 
  "'extern'", "'FaEntryMain'", "'internal'", "'public'", "'protected'", 
  "'private'", "'return'", "'static'", "'use'", "'volatile'", "", "'['", 
  "']'", "'<'", "'>'", "'{'", "'}'", "'('", "')'", "'&'", "'|'", "'^'", 
  "','", "':'", "';'", "'*'"
};

std::vector<std::string> FaParser::_symbolicNames = {
  "", "", "CC__Cdecl", "CC__FastCall", "CC__StdCall", "Class", "Const", 
  "Extern", "FaEntryMain", "Internal", "Public", "Protected", "Private", 
  "Return", "Static", "Use", "Volatile", "Id", "QuotFangL", "QuotFangR", 
  "QuotJianL", "QuotJianR", "QuotHuaL", "QuotHuaR", "QuotYuanL", "QuotYuanR", 
  "BitAnd", "BitOr", "BitXor", "Comma", "Colon", "Semi", "Star", "Num", 
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
       0x3, 0x26, 0xeb, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 
       0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 
       0x2, 0x34, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x37, 0xb, 0x2, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 
       0x5, 0x40, 0xa, 0x5, 0x3, 0x6, 0x5, 0x6, 0x43, 0xa, 0x6, 0x3, 0x6, 
       0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x4b, 
       0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x4e, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 
       0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x6, 0x6, 0x56, 0xa, 0x6, 
       0xd, 0x6, 0xe, 0x6, 0x57, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x5c, 0xa, 
       0x6, 0x3, 0x6, 0x7, 0x6, 0x5f, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x62, 
       0xb, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
       0x8, 0x5, 0x8, 0x6a, 0xa, 0x8, 0x3, 0x9, 0x5, 0x9, 0x6d, 0xa, 0x9, 
       0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x71, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 
       0x74, 0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x78, 0xa, 0xa, 0x3, 
       0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x7d, 0xa, 0xb, 0xc, 0xb, 0xe, 
       0xb, 0x80, 0xb, 0xb, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x84, 0xa, 0xc, 
       0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x89, 0xa, 0xd, 0xc, 0xd, 
       0xe, 0xd, 0x8c, 0xb, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
       0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
       0x10, 0x7, 0x10, 0x99, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0x9c, 0xb, 
       0x10, 0x3, 0x11, 0x5, 0x11, 0x9f, 0xa, 0x11, 0x3, 0x11, 0x5, 0x11, 
       0xa2, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 
       0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
       0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x5, 0x14, 0xb2, 0xa, 0x14, 
       0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0xb7, 0xa, 0x14, 0x3, 
       0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0xbc, 0xa, 0x14, 0xc, 0x14, 
       0xe, 0x14, 0xbf, 0xb, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 
       0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
       0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 
       0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
       0x18, 0x7, 0x18, 0xd7, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0xda, 0xb, 
       0x18, 0x3, 0x18, 0x7, 0x18, 0xdd, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 
       0xe0, 0xb, 0x18, 0x3, 0x18, 0x7, 0x18, 0xe3, 0xa, 0x18, 0xc, 0x18, 
       0xe, 0x18, 0xe6, 0xb, 0x18, 0x3, 0x18, 0x5, 0x18, 0xe9, 0xa, 0x18, 
       0x3, 0x18, 0x2, 0x2, 0x19, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
       0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 
       0x28, 0x2a, 0x2c, 0x2e, 0x2, 0x5, 0x3, 0x2, 0xb, 0xe, 0x4, 0x2, 0x8, 
       0x8, 0x12, 0x12, 0x3, 0x2, 0x4, 0x6, 0x2, 0xee, 0x2, 0x30, 0x3, 0x2, 
       0x2, 0x2, 0x4, 0x38, 0x3, 0x2, 0x2, 0x2, 0x6, 0x3a, 0x3, 0x2, 0x2, 
       0x2, 0x8, 0x3f, 0x3, 0x2, 0x2, 0x2, 0xa, 0x42, 0x3, 0x2, 0x2, 0x2, 
       0xc, 0x63, 0x3, 0x2, 0x2, 0x2, 0xe, 0x69, 0x3, 0x2, 0x2, 0x2, 0x10, 
       0x6c, 0x3, 0x2, 0x2, 0x2, 0x12, 0x75, 0x3, 0x2, 0x2, 0x2, 0x14, 0x79, 
       0x3, 0x2, 0x2, 0x2, 0x16, 0x81, 0x3, 0x2, 0x2, 0x2, 0x18, 0x85, 0x3, 
       0x2, 0x2, 0x2, 0x1a, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x91, 0x3, 0x2, 
       0x2, 0x2, 0x1e, 0x94, 0x3, 0x2, 0x2, 0x2, 0x20, 0x9e, 0x3, 0x2, 0x2, 
       0x2, 0x22, 0xa6, 0x3, 0x2, 0x2, 0x2, 0x24, 0xa9, 0x3, 0x2, 0x2, 0x2, 
       0x26, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x28, 0xc2, 0x3, 0x2, 0x2, 0x2, 0x2a, 
       0xc4, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xcd, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xd8, 
       0x3, 0x2, 0x2, 0x2, 0x30, 0x35, 0x7, 0x13, 0x2, 0x2, 0x31, 0x32, 
       0x7, 0x3, 0x2, 0x2, 0x32, 0x34, 0x7, 0x13, 0x2, 0x2, 0x33, 0x31, 
       0x3, 0x2, 0x2, 0x2, 0x34, 0x37, 0x3, 0x2, 0x2, 0x2, 0x35, 0x33, 0x3, 
       0x2, 0x2, 0x2, 0x35, 0x36, 0x3, 0x2, 0x2, 0x2, 0x36, 0x3, 0x3, 0x2, 
       0x2, 0x2, 0x37, 0x35, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x9, 0x2, 0x2, 
       0x2, 0x39, 0x5, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 0x9, 0x3, 0x2, 0x2, 
       0x3b, 0x7, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0x14, 0x2, 0x2, 0x3d, 
       0x40, 0x7, 0x15, 0x2, 0x2, 0x3e, 0x40, 0x7, 0x1c, 0x2, 0x2, 0x3f, 
       0x3c, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 0x9, 
       0x3, 0x2, 0x2, 0x2, 0x41, 0x43, 0x5, 0x6, 0x4, 0x2, 0x42, 0x41, 0x3, 
       0x2, 0x2, 0x2, 0x42, 0x43, 0x3, 0x2, 0x2, 0x2, 0x43, 0x5b, 0x3, 0x2, 
       0x2, 0x2, 0x44, 0x5c, 0x7, 0x13, 0x2, 0x2, 0x45, 0x46, 0x7, 0x13, 
       0x2, 0x2, 0x46, 0x47, 0x7, 0x16, 0x2, 0x2, 0x47, 0x4c, 0x5, 0xa, 
       0x6, 0x2, 0x48, 0x49, 0x7, 0x1f, 0x2, 0x2, 0x49, 0x4b, 0x5, 0xa, 
       0x6, 0x2, 0x4a, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4e, 0x3, 0x2, 0x2, 
       0x2, 0x4c, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x3, 0x2, 0x2, 0x2, 
       0x4d, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4f, 
       0x50, 0x7, 0x17, 0x2, 0x2, 0x50, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x51, 
       0x52, 0x7, 0x1a, 0x2, 0x2, 0x52, 0x55, 0x5, 0xa, 0x6, 0x2, 0x53, 
       0x54, 0x7, 0x1f, 0x2, 0x2, 0x54, 0x56, 0x5, 0xa, 0x6, 0x2, 0x55, 
       0x53, 0x3, 0x2, 0x2, 0x2, 0x56, 0x57, 0x3, 0x2, 0x2, 0x2, 0x57, 0x55, 
       0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x3, 
       0x2, 0x2, 0x2, 0x59, 0x5a, 0x7, 0x1b, 0x2, 0x2, 0x5a, 0x5c, 0x3, 
       0x2, 0x2, 0x2, 0x5b, 0x44, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x45, 0x3, 0x2, 
       0x2, 0x2, 0x5b, 0x51, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x60, 0x3, 0x2, 0x2, 
       0x2, 0x5d, 0x5f, 0x5, 0x8, 0x5, 0x2, 0x5e, 0x5d, 0x3, 0x2, 0x2, 0x2, 
       0x5f, 0x62, 0x3, 0x2, 0x2, 0x2, 0x60, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x60, 
       0x61, 0x3, 0x2, 0x2, 0x2, 0x61, 0xb, 0x3, 0x2, 0x2, 0x2, 0x62, 0x60, 
       0x3, 0x2, 0x2, 0x2, 0x63, 0x64, 0x7, 0x8, 0x2, 0x2, 0x64, 0xd, 0x3, 
       0x2, 0x2, 0x2, 0x65, 0x66, 0x7, 0x14, 0x2, 0x2, 0x66, 0x6a, 0x7, 
       0x15, 0x2, 0x2, 0x67, 0x6a, 0x7, 0x1c, 0x2, 0x2, 0x68, 0x6a, 0x7, 
       0x22, 0x2, 0x2, 0x69, 0x65, 0x3, 0x2, 0x2, 0x2, 0x69, 0x67, 0x3, 
       0x2, 0x2, 0x2, 0x69, 0x68, 0x3, 0x2, 0x2, 0x2, 0x6a, 0xf, 0x3, 0x2, 
       0x2, 0x2, 0x6b, 0x6d, 0x5, 0xc, 0x7, 0x2, 0x6c, 0x6b, 0x3, 0x2, 0x2, 
       0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 0x3, 0x2, 0x2, 0x2, 
       0x6e, 0x72, 0x7, 0x13, 0x2, 0x2, 0x6f, 0x71, 0x5, 0xe, 0x8, 0x2, 
       0x70, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x71, 0x74, 0x3, 0x2, 0x2, 0x2, 0x72, 
       0x70, 0x3, 0x2, 0x2, 0x2, 0x72, 0x73, 0x3, 0x2, 0x2, 0x2, 0x73, 0x11, 
       0x3, 0x2, 0x2, 0x2, 0x74, 0x72, 0x3, 0x2, 0x2, 0x2, 0x75, 0x77, 0x5, 
       0xa, 0x6, 0x2, 0x76, 0x78, 0x7, 0x13, 0x2, 0x2, 0x77, 0x76, 0x3, 
       0x2, 0x2, 0x2, 0x77, 0x78, 0x3, 0x2, 0x2, 0x2, 0x78, 0x13, 0x3, 0x2, 
       0x2, 0x2, 0x79, 0x7e, 0x5, 0x12, 0xa, 0x2, 0x7a, 0x7b, 0x7, 0x1f, 
       0x2, 0x2, 0x7b, 0x7d, 0x5, 0x12, 0xa, 0x2, 0x7c, 0x7a, 0x3, 0x2, 
       0x2, 0x2, 0x7d, 0x80, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7c, 0x3, 0x2, 0x2, 
       0x2, 0x7e, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x15, 0x3, 0x2, 0x2, 0x2, 
       0x80, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x81, 0x83, 0x5, 0x10, 0x9, 0x2, 
       0x82, 0x84, 0x7, 0x13, 0x2, 0x2, 0x83, 0x82, 0x3, 0x2, 0x2, 0x2, 
       0x83, 0x84, 0x3, 0x2, 0x2, 0x2, 0x84, 0x17, 0x3, 0x2, 0x2, 0x2, 0x85, 
       0x8a, 0x5, 0x16, 0xc, 0x2, 0x86, 0x87, 0x7, 0x1f, 0x2, 0x2, 0x87, 
       0x89, 0x5, 0x16, 0xc, 0x2, 0x88, 0x86, 0x3, 0x2, 0x2, 0x2, 0x89, 
       0x8c, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 
       0x3, 0x2, 0x2, 0x2, 0x8b, 0x19, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8a, 0x3, 
       0x2, 0x2, 0x2, 0x8d, 0x8e, 0x7, 0x11, 0x2, 0x2, 0x8e, 0x8f, 0x5, 
       0x2, 0x2, 0x2, 0x8f, 0x90, 0x7, 0x21, 0x2, 0x2, 0x90, 0x1b, 0x3, 
       0x2, 0x2, 0x2, 0x91, 0x92, 0x7, 0xf, 0x2, 0x2, 0x92, 0x93, 0x7, 0x21, 
       0x2, 0x2, 0x93, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x7, 0x20, 
       0x2, 0x2, 0x95, 0x9a, 0x5, 0x2, 0x2, 0x2, 0x96, 0x97, 0x7, 0x1f, 
       0x2, 0x2, 0x97, 0x99, 0x5, 0x2, 0x2, 0x2, 0x98, 0x96, 0x3, 0x2, 0x2, 
       0x2, 0x99, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x98, 0x3, 0x2, 0x2, 0x2, 
       0x9a, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x9c, 
       0x9a, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9f, 0x5, 0x4, 0x3, 0x2, 0x9e, 0x9d, 
       0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa1, 0x3, 
       0x2, 0x2, 0x2, 0xa0, 0xa2, 0x7, 0x10, 0x2, 0x2, 0xa1, 0xa0, 0x3, 
       0x2, 0x2, 0x2, 0xa1, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa3, 0x3, 0x2, 
       0x2, 0x2, 0xa3, 0xa4, 0x7, 0x13, 0x2, 0x2, 0xa4, 0xa5, 0x7, 0x13, 
       0x2, 0x2, 0xa5, 0x21, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x5, 0x20, 
       0x11, 0x2, 0xa7, 0xa8, 0x7, 0x21, 0x2, 0x2, 0xa8, 0x23, 0x3, 0x2, 
       0x2, 0x2, 0xa9, 0xaa, 0x5, 0x20, 0x11, 0x2, 0xaa, 0xab, 0x7, 0x1a, 
       0x2, 0x2, 0xab, 0xac, 0x5, 0x14, 0xb, 0x2, 0xac, 0xad, 0x7, 0x1b, 
       0x2, 0x2, 0xad, 0xae, 0x7, 0x18, 0x2, 0x2, 0xae, 0xaf, 0x7, 0x19, 
       0x2, 0x2, 0xaf, 0x25, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb2, 0x5, 0x4, 0x3, 
       0x2, 0xb1, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x3, 0x2, 0x2, 0x2, 
       0xb2, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 0x7, 0x7, 0x2, 0x2, 0xb4, 
       0xb6, 0x7, 0x13, 0x2, 0x2, 0xb5, 0xb7, 0x5, 0x1e, 0x10, 0x2, 0xb6, 
       0xb5, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 
       0x3, 0x2, 0x2, 0x2, 0xb8, 0xbd, 0x7, 0x18, 0x2, 0x2, 0xb9, 0xbc, 
       0x5, 0x22, 0x12, 0x2, 0xba, 0xbc, 0x5, 0x24, 0x13, 0x2, 0xbb, 0xb9, 
       0x3, 0x2, 0x2, 0x2, 0xbb, 0xba, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbf, 0x3, 
       0x2, 0x2, 0x2, 0xbd, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbe, 0x3, 0x2, 
       0x2, 0x2, 0xbe, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xbd, 0x3, 0x2, 0x2, 
       0x2, 0xc0, 0xc1, 0x7, 0x19, 0x2, 0x2, 0xc1, 0x27, 0x3, 0x2, 0x2, 
       0x2, 0xc2, 0xc3, 0x9, 0x4, 0x2, 0x2, 0xc3, 0x29, 0x3, 0x2, 0x2, 0x2, 
       0xc4, 0xc5, 0x7, 0x9, 0x2, 0x2, 0xc5, 0xc6, 0x5, 0x10, 0x9, 0x2, 
       0xc6, 0xc7, 0x5, 0x28, 0x15, 0x2, 0xc7, 0xc8, 0x7, 0x13, 0x2, 0x2, 
       0xc8, 0xc9, 0x7, 0x1a, 0x2, 0x2, 0xc9, 0xca, 0x5, 0x18, 0xd, 0x2, 
       0xca, 0xcb, 0x7, 0x1b, 0x2, 0x2, 0xcb, 0xcc, 0x7, 0x21, 0x2, 0x2, 
       0xcc, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 0x7, 0x10, 0x2, 0x2, 
       0xce, 0xcf, 0x5, 0xa, 0x6, 0x2, 0xcf, 0xd0, 0x7, 0xa, 0x2, 0x2, 0xd0, 
       0xd1, 0x7, 0x1a, 0x2, 0x2, 0xd1, 0xd2, 0x7, 0x1b, 0x2, 0x2, 0xd2, 
       0xd3, 0x7, 0x18, 0x2, 0x2, 0xd3, 0xd4, 0x7, 0x19, 0x2, 0x2, 0xd4, 
       0x2d, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd7, 0x5, 0x1a, 0xe, 0x2, 0xd6, 
       0xd5, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xda, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd6, 
       0x3, 0x2, 0x2, 0x2, 0xd8, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xde, 0x3, 
       0x2, 0x2, 0x2, 0xda, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdd, 0x5, 0x2a, 
       0x16, 0x2, 0xdc, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xe0, 0x3, 0x2, 
       0x2, 0x2, 0xde, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 0x3, 0x2, 0x2, 
       0x2, 0xdf, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xde, 0x3, 0x2, 0x2, 0x2, 
       0xe1, 0xe3, 0x5, 0x26, 0x14, 0x2, 0xe2, 0xe1, 0x3, 0x2, 0x2, 0x2, 
       0xe3, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe4, 
       0xe5, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe4, 
       0x3, 0x2, 0x2, 0x2, 0xe7, 0xe9, 0x5, 0x2c, 0x17, 0x2, 0xe8, 0xe7, 
       0x3, 0x2, 0x2, 0x2, 0xe8, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xe9, 0x2f, 0x3, 
       0x2, 0x2, 0x2, 0x1b, 0x35, 0x3f, 0x42, 0x4c, 0x57, 0x5b, 0x60, 0x69, 
       0x6c, 0x72, 0x77, 0x7e, 0x83, 0x8a, 0x9a, 0x9e, 0xa1, 0xb1, 0xb6, 
       0xbb, 0xbd, 0xd8, 0xde, 0xe4, 0xe8, 
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

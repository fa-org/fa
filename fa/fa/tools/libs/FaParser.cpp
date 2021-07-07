
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

std::vector<tree::TerminalNode *> FaParser::IdsContext::PointOp() {
  return getTokens(FaParser::PointOp);
}

tree::TerminalNode* FaParser::IdsContext::PointOp(size_t i) {
  return getToken(FaParser::PointOp, i);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(56);
    match(FaParser::Id);
    setState(61);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(57);
        match(FaParser::PointOp);
        setState(58);
        match(FaParser::Id); 
      }
      setState(63);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

FaParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::LiteralContext::BoolLiteral() {
  return getToken(FaParser::BoolLiteral, 0);
}

tree::TerminalNode* FaParser::LiteralContext::IntLiteral() {
  return getToken(FaParser::IntLiteral, 0);
}

tree::TerminalNode* FaParser::LiteralContext::FloatLiteral() {
  return getToken(FaParser::FloatLiteral, 0);
}


size_t FaParser::LiteralContext::getRuleIndex() const {
  return FaParser::RuleLiteral;
}


antlrcpp::Any FaParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

FaParser::LiteralContext* FaParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 2, FaParser::RuleLiteral);
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
    _la = _input->LA(1);
    if (!(((((_la - 63) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 63)) & ((1ULL << (FaParser::BoolLiteral - 63))
      | (1ULL << (FaParser::IntLiteral - 63))
      | (1ULL << (FaParser::FloatLiteral - 63)))) != 0))) {
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

tree::TerminalNode* FaParser::TypeAfterContext::AndOp() {
  return getToken(FaParser::AndOp, 0);
}

tree::TerminalNode* FaParser::TypeAfterContext::Qus() {
  return getToken(FaParser::Qus, 0);
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
  enterRule(_localctx, 4, FaParser::RuleTypeAfter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(70);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::QuotFangL: {
        enterOuterAlt(_localctx, 1);
        setState(66);
        match(FaParser::QuotFangL);
        setState(67);
        match(FaParser::QuotFangR);
        break;
      }

      case FaParser::AndOp: {
        enterOuterAlt(_localctx, 2);
        setState(68);
        match(FaParser::AndOp);
        break;
      }

      case FaParser::Qus: {
        enterOuterAlt(_localctx, 3);
        setState(69);
        match(FaParser::Qus);
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

tree::TerminalNode* FaParser::TypeContext::Const() {
  return getToken(FaParser::Const, 0);
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
  enterRule(_localctx, 6, FaParser::RuleType);
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
    setState(73);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Const) {
      setState(72);
      match(FaParser::Const);
    }
    setState(98);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      setState(75);
      match(FaParser::Id);
      break;
    }

    case 2: {
      setState(76);
      match(FaParser::Id);
      setState(77);
      match(FaParser::QuotJianL);
      setState(78);
      type();
      setState(83);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FaParser::Comma) {
        setState(79);
        match(FaParser::Comma);
        setState(80);
        type();
        setState(85);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(86);
      match(FaParser::QuotJianR);
      break;
    }

    case 3: {
      setState(88);
      match(FaParser::QuotYuanL);
      setState(89);
      type();
      setState(92); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(90);
        match(FaParser::Comma);
        setState(91);
        type();
        setState(94); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == FaParser::Comma);
      setState(96);
      match(FaParser::QuotYuanR);
      break;
    }

    default:
      break;
    }
    setState(103);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::AndOp)
      | (1ULL << FaParser::Qus)
      | (1ULL << FaParser::QuotFangL))) != 0)) {
      setState(100);
      typeAfter();
      setState(105);
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

tree::TerminalNode* FaParser::ETypeAfterContext::AndOp() {
  return getToken(FaParser::AndOp, 0);
}

tree::TerminalNode* FaParser::ETypeAfterContext::StarOp() {
  return getToken(FaParser::StarOp, 0);
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
  enterRule(_localctx, 8, FaParser::RuleETypeAfter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(110);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::QuotFangL: {
        enterOuterAlt(_localctx, 1);
        setState(106);
        match(FaParser::QuotFangL);
        setState(107);
        match(FaParser::QuotFangR);
        break;
      }

      case FaParser::AndOp: {
        enterOuterAlt(_localctx, 2);
        setState(108);
        match(FaParser::AndOp);
        break;
      }

      case FaParser::StarOp: {
        enterOuterAlt(_localctx, 3);
        setState(109);
        match(FaParser::StarOp);
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

tree::TerminalNode* FaParser::ETypeContext::Const() {
  return getToken(FaParser::Const, 0);
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
  enterRule(_localctx, 10, FaParser::RuleEType);
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
    setState(113);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Const) {
      setState(112);
      match(FaParser::Const);
    }
    setState(115);
    match(FaParser::Id);
    setState(119);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::StarOp)
      | (1ULL << FaParser::AndOp)
      | (1ULL << FaParser::QuotFangL))) != 0)) {
      setState(116);
      eTypeAfter();
      setState(121);
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
  enterRule(_localctx, 12, FaParser::RuleTypeVar);
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
    setState(122);
    type();
    setState(124);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Id) {
      setState(123);
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
    setState(126);
    typeVar();
    setState(131);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(127);
      match(FaParser::Comma);
      setState(128);
      typeVar();
      setState(133);
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
  enterRule(_localctx, 16, FaParser::RuleETypeVar);
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
    setState(134);
    eType();
    setState(136);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Id) {
      setState(135);
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
  enterRule(_localctx, 18, FaParser::RuleETypeVarList);
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
    setState(138);
    eTypeVar();
    setState(143);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(139);
      match(FaParser::Comma);
      setState(140);
      eTypeVar();
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

//----------------- AllAssignContext ------------------------------------------------------------------

FaParser::AllAssignContext::AllAssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::AllAssignContext::Assign() {
  return getToken(FaParser::Assign, 0);
}

tree::TerminalNode* FaParser::AllAssignContext::QusQusAssign() {
  return getToken(FaParser::QusQusAssign, 0);
}

tree::TerminalNode* FaParser::AllAssignContext::AddAssign() {
  return getToken(FaParser::AddAssign, 0);
}

tree::TerminalNode* FaParser::AllAssignContext::SubAssign() {
  return getToken(FaParser::SubAssign, 0);
}

tree::TerminalNode* FaParser::AllAssignContext::StarAssign() {
  return getToken(FaParser::StarAssign, 0);
}

tree::TerminalNode* FaParser::AllAssignContext::StarStarAssign() {
  return getToken(FaParser::StarStarAssign, 0);
}

tree::TerminalNode* FaParser::AllAssignContext::DivAssign() {
  return getToken(FaParser::DivAssign, 0);
}

tree::TerminalNode* FaParser::AllAssignContext::ModAssign() {
  return getToken(FaParser::ModAssign, 0);
}

tree::TerminalNode* FaParser::AllAssignContext::AndAssign() {
  return getToken(FaParser::AndAssign, 0);
}

tree::TerminalNode* FaParser::AllAssignContext::OrAssign() {
  return getToken(FaParser::OrAssign, 0);
}

tree::TerminalNode* FaParser::AllAssignContext::XorAssign() {
  return getToken(FaParser::XorAssign, 0);
}

tree::TerminalNode* FaParser::AllAssignContext::AndAndAssign() {
  return getToken(FaParser::AndAndAssign, 0);
}

tree::TerminalNode* FaParser::AllAssignContext::OrOrAssign() {
  return getToken(FaParser::OrOrAssign, 0);
}

tree::TerminalNode* FaParser::AllAssignContext::ShiftLAssign() {
  return getToken(FaParser::ShiftLAssign, 0);
}

tree::TerminalNode* FaParser::AllAssignContext::ShiftRAssign() {
  return getToken(FaParser::ShiftRAssign, 0);
}


size_t FaParser::AllAssignContext::getRuleIndex() const {
  return FaParser::RuleAllAssign;
}


antlrcpp::Any FaParser::AllAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitAllAssign(this);
  else
    return visitor->visitChildren(this);
}

FaParser::AllAssignContext* FaParser::allAssign() {
  AllAssignContext *_localctx = _tracker.createInstance<AllAssignContext>(_ctx, getState());
  enterRule(_localctx, 20, FaParser::RuleAllAssign);
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
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Assign)
      | (1ULL << FaParser::QusQusAssign)
      | (1ULL << FaParser::AddAssign)
      | (1ULL << FaParser::SubAssign)
      | (1ULL << FaParser::StarAssign)
      | (1ULL << FaParser::StarStarAssign)
      | (1ULL << FaParser::DivAssign)
      | (1ULL << FaParser::ModAssign)
      | (1ULL << FaParser::AndAssign)
      | (1ULL << FaParser::OrAssign)
      | (1ULL << FaParser::XorAssign)
      | (1ULL << FaParser::AndAndAssign)
      | (1ULL << FaParser::OrOrAssign)
      | (1ULL << FaParser::ShiftLAssign)
      | (1ULL << FaParser::ShiftRAssign))) != 0))) {
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

//----------------- AllOpContext ------------------------------------------------------------------

FaParser::AllOpContext::AllOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::AllOpContext::QusQusOp() {
  return getToken(FaParser::QusQusOp, 0);
}

tree::TerminalNode* FaParser::AllOpContext::PointOp() {
  return getToken(FaParser::PointOp, 0);
}

tree::TerminalNode* FaParser::AllOpContext::AddOp() {
  return getToken(FaParser::AddOp, 0);
}

tree::TerminalNode* FaParser::AllOpContext::SubOp() {
  return getToken(FaParser::SubOp, 0);
}

tree::TerminalNode* FaParser::AllOpContext::StarOp() {
  return getToken(FaParser::StarOp, 0);
}

tree::TerminalNode* FaParser::AllOpContext::DivOp() {
  return getToken(FaParser::DivOp, 0);
}

tree::TerminalNode* FaParser::AllOpContext::StarStarOp() {
  return getToken(FaParser::StarStarOp, 0);
}

tree::TerminalNode* FaParser::AllOpContext::ModOp() {
  return getToken(FaParser::ModOp, 0);
}

tree::TerminalNode* FaParser::AllOpContext::AndOp() {
  return getToken(FaParser::AndOp, 0);
}

tree::TerminalNode* FaParser::AllOpContext::OrOp() {
  return getToken(FaParser::OrOp, 0);
}

tree::TerminalNode* FaParser::AllOpContext::XorOp() {
  return getToken(FaParser::XorOp, 0);
}

tree::TerminalNode* FaParser::AllOpContext::AndAndOp() {
  return getToken(FaParser::AndAndOp, 0);
}

tree::TerminalNode* FaParser::AllOpContext::OrOrOp() {
  return getToken(FaParser::OrOrOp, 0);
}

tree::TerminalNode* FaParser::AllOpContext::ShiftLOp() {
  return getToken(FaParser::ShiftLOp, 0);
}

tree::TerminalNode* FaParser::AllOpContext::ShiftROp() {
  return getToken(FaParser::ShiftROp, 0);
}


size_t FaParser::AllOpContext::getRuleIndex() const {
  return FaParser::RuleAllOp;
}


antlrcpp::Any FaParser::AllOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitAllOp(this);
  else
    return visitor->visitChildren(this);
}

FaParser::AllOpContext* FaParser::allOp() {
  AllOpContext *_localctx = _tracker.createInstance<AllOpContext>(_ctx, getState());
  enterRule(_localctx, 22, FaParser::RuleAllOp);
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
    setState(148);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::PointOp)
      | (1ULL << FaParser::QusQusOp)
      | (1ULL << FaParser::AddOp)
      | (1ULL << FaParser::SubOp)
      | (1ULL << FaParser::StarOp)
      | (1ULL << FaParser::DivOp)
      | (1ULL << FaParser::StarStarOp)
      | (1ULL << FaParser::ModOp)
      | (1ULL << FaParser::AndOp)
      | (1ULL << FaParser::OrOp)
      | (1ULL << FaParser::XorOp)
      | (1ULL << FaParser::AndAndOp)
      | (1ULL << FaParser::OrOrOp)
      | (1ULL << FaParser::ShiftLOp)
      | (1ULL << FaParser::ShiftROp))) != 0))) {
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

//----------------- ExprContext ------------------------------------------------------------------

FaParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FaParser::ExprContext::QuotYuanL() {
  return getTokens(FaParser::QuotYuanL);
}

tree::TerminalNode* FaParser::ExprContext::QuotYuanL(size_t i) {
  return getToken(FaParser::QuotYuanL, i);
}

std::vector<FaParser::ExprContext *> FaParser::ExprContext::expr() {
  return getRuleContexts<FaParser::ExprContext>();
}

FaParser::ExprContext* FaParser::ExprContext::expr(size_t i) {
  return getRuleContext<FaParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> FaParser::ExprContext::QuotYuanR() {
  return getTokens(FaParser::QuotYuanR);
}

tree::TerminalNode* FaParser::ExprContext::QuotYuanR(size_t i) {
  return getToken(FaParser::QuotYuanR, i);
}

FaParser::IdsContext* FaParser::ExprContext::ids() {
  return getRuleContext<FaParser::IdsContext>(0);
}

FaParser::LiteralContext* FaParser::ExprContext::literal() {
  return getRuleContext<FaParser::LiteralContext>(0);
}

std::vector<tree::TerminalNode *> FaParser::ExprContext::AddOp() {
  return getTokens(FaParser::AddOp);
}

tree::TerminalNode* FaParser::ExprContext::AddOp(size_t i) {
  return getToken(FaParser::AddOp, i);
}

std::vector<tree::TerminalNode *> FaParser::ExprContext::SubOp() {
  return getTokens(FaParser::SubOp);
}

tree::TerminalNode* FaParser::ExprContext::SubOp(size_t i) {
  return getToken(FaParser::SubOp, i);
}

std::vector<tree::TerminalNode *> FaParser::ExprContext::AddAddOp() {
  return getTokens(FaParser::AddAddOp);
}

tree::TerminalNode* FaParser::ExprContext::AddAddOp(size_t i) {
  return getToken(FaParser::AddAddOp, i);
}

std::vector<tree::TerminalNode *> FaParser::ExprContext::SubSubOp() {
  return getTokens(FaParser::SubSubOp);
}

tree::TerminalNode* FaParser::ExprContext::SubSubOp(size_t i) {
  return getToken(FaParser::SubSubOp, i);
}

std::vector<tree::TerminalNode *> FaParser::ExprContext::ReverseOp() {
  return getTokens(FaParser::ReverseOp);
}

tree::TerminalNode* FaParser::ExprContext::ReverseOp(size_t i) {
  return getToken(FaParser::ReverseOp, i);
}

tree::TerminalNode* FaParser::ExprContext::ColonColon() {
  return getToken(FaParser::ColonColon, 0);
}

tree::TerminalNode* FaParser::ExprContext::Id() {
  return getToken(FaParser::Id, 0);
}

std::vector<tree::TerminalNode *> FaParser::ExprContext::QuotFangL() {
  return getTokens(FaParser::QuotFangL);
}

tree::TerminalNode* FaParser::ExprContext::QuotFangL(size_t i) {
  return getToken(FaParser::QuotFangL, i);
}

std::vector<FaParser::AllAssignContext *> FaParser::ExprContext::allAssign() {
  return getRuleContexts<FaParser::AllAssignContext>();
}

FaParser::AllAssignContext* FaParser::ExprContext::allAssign(size_t i) {
  return getRuleContext<FaParser::AllAssignContext>(i);
}

std::vector<FaParser::AllOpContext *> FaParser::ExprContext::allOp() {
  return getRuleContexts<FaParser::AllOpContext>();
}

FaParser::AllOpContext* FaParser::ExprContext::allOp(size_t i) {
  return getRuleContext<FaParser::AllOpContext>(i);
}

std::vector<tree::TerminalNode *> FaParser::ExprContext::Comma() {
  return getTokens(FaParser::Comma);
}

tree::TerminalNode* FaParser::ExprContext::Comma(size_t i) {
  return getToken(FaParser::Comma, i);
}


size_t FaParser::ExprContext::getRuleIndex() const {
  return FaParser::RuleExpr;
}


antlrcpp::Any FaParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ExprContext* FaParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 24, FaParser::RuleExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(198);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::QuotYuanL: {
        enterOuterAlt(_localctx, 1);
        setState(150);
        match(FaParser::QuotYuanL);
        setState(151);
        expr();
        setState(152);
        match(FaParser::QuotYuanR);
        break;
      }

      case FaParser::Id:
      case FaParser::ReverseOp:
      case FaParser::AddAddOp:
      case FaParser::SubSubOp:
      case FaParser::AddOp:
      case FaParser::SubOp:
      case FaParser::ColonColon:
      case FaParser::BoolLiteral:
      case FaParser::IntLiteral:
      case FaParser::FloatLiteral: {
        enterOuterAlt(_localctx, 2);
        setState(157);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << FaParser::ReverseOp)
          | (1ULL << FaParser::AddAddOp)
          | (1ULL << FaParser::SubSubOp)
          | (1ULL << FaParser::AddOp)
          | (1ULL << FaParser::SubOp))) != 0)) {
          setState(154);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << FaParser::ReverseOp)
            | (1ULL << FaParser::AddAddOp)
            | (1ULL << FaParser::SubSubOp)
            | (1ULL << FaParser::AddOp)
            | (1ULL << FaParser::SubOp))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(159);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(164);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case FaParser::Id: {
            setState(160);
            ids();
            break;
          }

          case FaParser::ColonColon: {
            setState(161);
            match(FaParser::ColonColon);
            setState(162);
            match(FaParser::Id);
            break;
          }

          case FaParser::BoolLiteral:
          case FaParser::IntLiteral:
          case FaParser::FloatLiteral: {
            setState(163);
            literal();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(195);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(193);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case FaParser::AddAddOp:
              case FaParser::SubSubOp: {
                setState(166);
                _la = _input->LA(1);
                if (!(_la == FaParser::AddAddOp

                || _la == FaParser::SubSubOp)) {
                _errHandler->recoverInline(this);
                }
                else {
                  _errHandler->reportMatch(this);
                  consume();
                }
                break;
              }

              case FaParser::QuotYuanL: {
                setState(167);
                match(FaParser::QuotYuanL);
                setState(176);
                _errHandler->sync(this);

                _la = _input->LA(1);
                if (((((_la - 16) & ~ 0x3fULL) == 0) &&
                  ((1ULL << (_la - 16)) & ((1ULL << (FaParser::Id - 16))
                  | (1ULL << (FaParser::ReverseOp - 16))
                  | (1ULL << (FaParser::AddAddOp - 16))
                  | (1ULL << (FaParser::SubSubOp - 16))
                  | (1ULL << (FaParser::AddOp - 16))
                  | (1ULL << (FaParser::SubOp - 16))
                  | (1ULL << (FaParser::ColonColon - 16))
                  | (1ULL << (FaParser::QuotYuanL - 16))
                  | (1ULL << (FaParser::BoolLiteral - 16))
                  | (1ULL << (FaParser::IntLiteral - 16))
                  | (1ULL << (FaParser::FloatLiteral - 16)))) != 0)) {
                  setState(168);
                  expr();
                  setState(173);
                  _errHandler->sync(this);
                  _la = _input->LA(1);
                  while (_la == FaParser::Comma) {
                    setState(169);
                    match(FaParser::Comma);
                    setState(170);
                    expr();
                    setState(175);
                    _errHandler->sync(this);
                    _la = _input->LA(1);
                  }
                }
                setState(178);
                match(FaParser::QuotYuanR);
                break;
              }

              case FaParser::QuotFangL: {
                setState(179);
                match(FaParser::QuotFangL);
                setState(180);
                expr();
                setState(181);
                match(FaParser::QuotFangL);
                break;
              }

              case FaParser::Assign:
              case FaParser::QusQusAssign:
              case FaParser::AddAssign:
              case FaParser::SubAssign:
              case FaParser::StarAssign:
              case FaParser::StarStarAssign:
              case FaParser::DivAssign:
              case FaParser::ModAssign:
              case FaParser::AndAssign:
              case FaParser::OrAssign:
              case FaParser::XorAssign:
              case FaParser::AndAndAssign:
              case FaParser::OrOrAssign:
              case FaParser::ShiftLAssign:
              case FaParser::ShiftRAssign:
              case FaParser::PointOp:
              case FaParser::QusQusOp:
              case FaParser::AddOp:
              case FaParser::SubOp:
              case FaParser::StarOp:
              case FaParser::DivOp:
              case FaParser::StarStarOp:
              case FaParser::ModOp:
              case FaParser::AndOp:
              case FaParser::OrOp:
              case FaParser::XorOp:
              case FaParser::AndAndOp:
              case FaParser::OrOrOp:
              case FaParser::ShiftLOp:
              case FaParser::ShiftROp: {
                setState(189); 
                _errHandler->sync(this);
                alt = 1;
                do {
                  switch (alt) {
                    case 1: {
                          setState(185);
                          _errHandler->sync(this);
                          switch (_input->LA(1)) {
                            case FaParser::Assign:
                            case FaParser::QusQusAssign:
                            case FaParser::AddAssign:
                            case FaParser::SubAssign:
                            case FaParser::StarAssign:
                            case FaParser::StarStarAssign:
                            case FaParser::DivAssign:
                            case FaParser::ModAssign:
                            case FaParser::AndAssign:
                            case FaParser::OrAssign:
                            case FaParser::XorAssign:
                            case FaParser::AndAndAssign:
                            case FaParser::OrOrAssign:
                            case FaParser::ShiftLAssign:
                            case FaParser::ShiftRAssign: {
                              setState(183);
                              allAssign();
                              break;
                            }

                            case FaParser::PointOp:
                            case FaParser::QusQusOp:
                            case FaParser::AddOp:
                            case FaParser::SubOp:
                            case FaParser::StarOp:
                            case FaParser::DivOp:
                            case FaParser::StarStarOp:
                            case FaParser::ModOp:
                            case FaParser::AndOp:
                            case FaParser::OrOp:
                            case FaParser::XorOp:
                            case FaParser::AndAndOp:
                            case FaParser::OrOrOp:
                            case FaParser::ShiftLOp:
                            case FaParser::ShiftROp: {
                              setState(184);
                              allOp();
                              break;
                            }

                          default:
                            throw NoViableAltException(this);
                          }
                          setState(187);
                          expr();
                          break;
                        }

                  default:
                    throw NoViableAltException(this);
                  }
                  setState(191); 
                  _errHandler->sync(this);
                  alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
                } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
                break;
              }

            default:
              throw NoViableAltException(this);
            } 
          }
          setState(197);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
        }
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
  enterRule(_localctx, 26, FaParser::RuleUseStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(200);
    match(FaParser::Use);
    setState(201);
    ids();
    setState(202);
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

FaParser::ExprContext* FaParser::ReturnStmtContext::expr() {
  return getRuleContext<FaParser::ExprContext>(0);
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
  enterRule(_localctx, 28, FaParser::RuleReturnStmt);
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
    setState(204);
    match(FaParser::Return);
    setState(206);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 16) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 16)) & ((1ULL << (FaParser::Id - 16))
      | (1ULL << (FaParser::ReverseOp - 16))
      | (1ULL << (FaParser::AddAddOp - 16))
      | (1ULL << (FaParser::SubSubOp - 16))
      | (1ULL << (FaParser::AddOp - 16))
      | (1ULL << (FaParser::SubOp - 16))
      | (1ULL << (FaParser::ColonColon - 16))
      | (1ULL << (FaParser::QuotYuanL - 16))
      | (1ULL << (FaParser::BoolLiteral - 16))
      | (1ULL << (FaParser::IntLiteral - 16))
      | (1ULL << (FaParser::FloatLiteral - 16)))) != 0)) {
      setState(205);
      expr();
    }
    setState(208);
    match(FaParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

FaParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::ReturnStmtContext* FaParser::StmtContext::returnStmt() {
  return getRuleContext<FaParser::ReturnStmtContext>(0);
}

FaParser::ExprContext* FaParser::StmtContext::expr() {
  return getRuleContext<FaParser::ExprContext>(0);
}

tree::TerminalNode* FaParser::StmtContext::Semi() {
  return getToken(FaParser::Semi, 0);
}


size_t FaParser::StmtContext::getRuleIndex() const {
  return FaParser::RuleStmt;
}


antlrcpp::Any FaParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

FaParser::StmtContext* FaParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 30, FaParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(214);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::Return: {
        enterOuterAlt(_localctx, 1);
        setState(210);
        returnStmt();
        break;
      }

      case FaParser::Id:
      case FaParser::ReverseOp:
      case FaParser::AddAddOp:
      case FaParser::SubSubOp:
      case FaParser::AddOp:
      case FaParser::SubOp:
      case FaParser::ColonColon:
      case FaParser::QuotYuanL:
      case FaParser::BoolLiteral:
      case FaParser::IntLiteral:
      case FaParser::FloatLiteral: {
        enterOuterAlt(_localctx, 2);
        setState(211);
        expr();
        setState(212);
        match(FaParser::Semi);
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
  enterRule(_localctx, 32, FaParser::RulePublicLevel);
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
    setState(216);
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
  enterRule(_localctx, 34, FaParser::RuleClassParent);
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
    setState(218);
    match(FaParser::Colon);
    setState(219);
    ids();
    setState(224);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(220);
      match(FaParser::Comma);
      setState(221);
      ids();
      setState(226);
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

//----------------- ClassItemPartContext ------------------------------------------------------------------

FaParser::ClassItemPartContext::ClassItemPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FaParser::ClassItemPartContext::Id() {
  return getTokens(FaParser::Id);
}

tree::TerminalNode* FaParser::ClassItemPartContext::Id(size_t i) {
  return getToken(FaParser::Id, i);
}

FaParser::PublicLevelContext* FaParser::ClassItemPartContext::publicLevel() {
  return getRuleContext<FaParser::PublicLevelContext>(0);
}

tree::TerminalNode* FaParser::ClassItemPartContext::Static() {
  return getToken(FaParser::Static, 0);
}


size_t FaParser::ClassItemPartContext::getRuleIndex() const {
  return FaParser::RuleClassItemPart;
}


antlrcpp::Any FaParser::ClassItemPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitClassItemPart(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ClassItemPartContext* FaParser::classItemPart() {
  ClassItemPartContext *_localctx = _tracker.createInstance<ClassItemPartContext>(_ctx, getState());
  enterRule(_localctx, 36, FaParser::RuleClassItemPart);
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
    setState(228);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(227);
      publicLevel();
    }
    setState(231);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Static) {
      setState(230);
      match(FaParser::Static);
    }
    setState(233);
    match(FaParser::Id);
    setState(234);
    match(FaParser::Id);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassItemFieldBlockContext ------------------------------------------------------------------

FaParser::ClassItemFieldBlockContext::ClassItemFieldBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::ClassItemPartContext* FaParser::ClassItemFieldBlockContext::classItemPart() {
  return getRuleContext<FaParser::ClassItemPartContext>(0);
}

tree::TerminalNode* FaParser::ClassItemFieldBlockContext::Semi() {
  return getToken(FaParser::Semi, 0);
}


size_t FaParser::ClassItemFieldBlockContext::getRuleIndex() const {
  return FaParser::RuleClassItemFieldBlock;
}


antlrcpp::Any FaParser::ClassItemFieldBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitClassItemFieldBlock(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ClassItemFieldBlockContext* FaParser::classItemFieldBlock() {
  ClassItemFieldBlockContext *_localctx = _tracker.createInstance<ClassItemFieldBlockContext>(_ctx, getState());
  enterRule(_localctx, 38, FaParser::RuleClassItemFieldBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(236);
    classItemPart();
    setState(237);
    match(FaParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassItemFuncBlockContext ------------------------------------------------------------------

FaParser::ClassItemFuncBlockContext::ClassItemFuncBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::ClassItemPartContext* FaParser::ClassItemFuncBlockContext::classItemPart() {
  return getRuleContext<FaParser::ClassItemPartContext>(0);
}

tree::TerminalNode* FaParser::ClassItemFuncBlockContext::QuotYuanL() {
  return getToken(FaParser::QuotYuanL, 0);
}

FaParser::TypeVarListContext* FaParser::ClassItemFuncBlockContext::typeVarList() {
  return getRuleContext<FaParser::TypeVarListContext>(0);
}

tree::TerminalNode* FaParser::ClassItemFuncBlockContext::QuotYuanR() {
  return getToken(FaParser::QuotYuanR, 0);
}

tree::TerminalNode* FaParser::ClassItemFuncBlockContext::QuotHuaL() {
  return getToken(FaParser::QuotHuaL, 0);
}

tree::TerminalNode* FaParser::ClassItemFuncBlockContext::QuotHuaR() {
  return getToken(FaParser::QuotHuaR, 0);
}

std::vector<FaParser::StmtContext *> FaParser::ClassItemFuncBlockContext::stmt() {
  return getRuleContexts<FaParser::StmtContext>();
}

FaParser::StmtContext* FaParser::ClassItemFuncBlockContext::stmt(size_t i) {
  return getRuleContext<FaParser::StmtContext>(i);
}


size_t FaParser::ClassItemFuncBlockContext::getRuleIndex() const {
  return FaParser::RuleClassItemFuncBlock;
}


antlrcpp::Any FaParser::ClassItemFuncBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitClassItemFuncBlock(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ClassItemFuncBlockContext* FaParser::classItemFuncBlock() {
  ClassItemFuncBlockContext *_localctx = _tracker.createInstance<ClassItemFuncBlockContext>(_ctx, getState());
  enterRule(_localctx, 40, FaParser::RuleClassItemFuncBlock);
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
    setState(239);
    classItemPart();
    setState(240);
    match(FaParser::QuotYuanL);
    setState(241);
    typeVarList();
    setState(242);
    match(FaParser::QuotYuanR);
    setState(243);
    match(FaParser::QuotHuaL);
    setState(247);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 13) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 13)) & ((1ULL << (FaParser::Return - 13))
      | (1ULL << (FaParser::Id - 13))
      | (1ULL << (FaParser::ReverseOp - 13))
      | (1ULL << (FaParser::AddAddOp - 13))
      | (1ULL << (FaParser::SubSubOp - 13))
      | (1ULL << (FaParser::AddOp - 13))
      | (1ULL << (FaParser::SubOp - 13))
      | (1ULL << (FaParser::ColonColon - 13))
      | (1ULL << (FaParser::QuotYuanL - 13))
      | (1ULL << (FaParser::BoolLiteral - 13))
      | (1ULL << (FaParser::IntLiteral - 13))
      | (1ULL << (FaParser::FloatLiteral - 13)))) != 0)) {
      setState(244);
      stmt();
      setState(249);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(250);
    match(FaParser::QuotHuaR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassBlockContext ------------------------------------------------------------------

FaParser::ClassBlockContext::ClassBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::ClassBlockContext::Class() {
  return getToken(FaParser::Class, 0);
}

tree::TerminalNode* FaParser::ClassBlockContext::Id() {
  return getToken(FaParser::Id, 0);
}

tree::TerminalNode* FaParser::ClassBlockContext::QuotHuaL() {
  return getToken(FaParser::QuotHuaL, 0);
}

tree::TerminalNode* FaParser::ClassBlockContext::QuotHuaR() {
  return getToken(FaParser::QuotHuaR, 0);
}

FaParser::PublicLevelContext* FaParser::ClassBlockContext::publicLevel() {
  return getRuleContext<FaParser::PublicLevelContext>(0);
}

FaParser::ClassParentContext* FaParser::ClassBlockContext::classParent() {
  return getRuleContext<FaParser::ClassParentContext>(0);
}

std::vector<FaParser::ClassItemFieldBlockContext *> FaParser::ClassBlockContext::classItemFieldBlock() {
  return getRuleContexts<FaParser::ClassItemFieldBlockContext>();
}

FaParser::ClassItemFieldBlockContext* FaParser::ClassBlockContext::classItemFieldBlock(size_t i) {
  return getRuleContext<FaParser::ClassItemFieldBlockContext>(i);
}

std::vector<FaParser::ClassItemFuncBlockContext *> FaParser::ClassBlockContext::classItemFuncBlock() {
  return getRuleContexts<FaParser::ClassItemFuncBlockContext>();
}

FaParser::ClassItemFuncBlockContext* FaParser::ClassBlockContext::classItemFuncBlock(size_t i) {
  return getRuleContext<FaParser::ClassItemFuncBlockContext>(i);
}


size_t FaParser::ClassBlockContext::getRuleIndex() const {
  return FaParser::RuleClassBlock;
}


antlrcpp::Any FaParser::ClassBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitClassBlock(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ClassBlockContext* FaParser::classBlock() {
  ClassBlockContext *_localctx = _tracker.createInstance<ClassBlockContext>(_ctx, getState());
  enterRule(_localctx, 42, FaParser::RuleClassBlock);
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
    setState(253);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(252);
      publicLevel();
    }
    setState(255);
    match(FaParser::Class);
    setState(256);
    match(FaParser::Id);
    setState(258);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Colon) {
      setState(257);
      classParent();
    }
    setState(260);
    match(FaParser::QuotHuaL);
    setState(265);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private)
      | (1ULL << FaParser::Static)
      | (1ULL << FaParser::Id))) != 0)) {
      setState(263);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
      case 1: {
        setState(261);
        classItemFieldBlock();
        break;
      }

      case 2: {
        setState(262);
        classItemFuncBlock();
        break;
      }

      default:
        break;
      }
      setState(267);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(268);
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
  enterRule(_localctx, 44, FaParser::RuleCallConvention);
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
    setState(270);
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

//----------------- ImportStmtContext ------------------------------------------------------------------

FaParser::ImportStmtContext::ImportStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::ImportStmtContext::AImport() {
  return getToken(FaParser::AImport, 0);
}

FaParser::ETypeContext* FaParser::ImportStmtContext::eType() {
  return getRuleContext<FaParser::ETypeContext>(0);
}

FaParser::CallConventionContext* FaParser::ImportStmtContext::callConvention() {
  return getRuleContext<FaParser::CallConventionContext>(0);
}

tree::TerminalNode* FaParser::ImportStmtContext::Id() {
  return getToken(FaParser::Id, 0);
}

tree::TerminalNode* FaParser::ImportStmtContext::QuotYuanL() {
  return getToken(FaParser::QuotYuanL, 0);
}

FaParser::ETypeVarListContext* FaParser::ImportStmtContext::eTypeVarList() {
  return getRuleContext<FaParser::ETypeVarListContext>(0);
}

tree::TerminalNode* FaParser::ImportStmtContext::QuotYuanR() {
  return getToken(FaParser::QuotYuanR, 0);
}

tree::TerminalNode* FaParser::ImportStmtContext::Semi() {
  return getToken(FaParser::Semi, 0);
}


size_t FaParser::ImportStmtContext::getRuleIndex() const {
  return FaParser::RuleImportStmt;
}


antlrcpp::Any FaParser::ImportStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitImportStmt(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ImportStmtContext* FaParser::importStmt() {
  ImportStmtContext *_localctx = _tracker.createInstance<ImportStmtContext>(_ctx, getState());
  enterRule(_localctx, 46, FaParser::RuleImportStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(272);
    match(FaParser::AImport);
    setState(273);
    eType();
    setState(274);
    callConvention();
    setState(275);
    match(FaParser::Id);
    setState(276);
    match(FaParser::QuotYuanL);
    setState(277);
    eTypeVarList();
    setState(278);
    match(FaParser::QuotYuanR);
    setState(279);
    match(FaParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LibStmtContext ------------------------------------------------------------------

FaParser::LibStmtContext::LibStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::LibStmtContext::ALib() {
  return getToken(FaParser::ALib, 0);
}

tree::TerminalNode* FaParser::LibStmtContext::String1Literal() {
  return getToken(FaParser::String1Literal, 0);
}

tree::TerminalNode* FaParser::LibStmtContext::Semi() {
  return getToken(FaParser::Semi, 0);
}


size_t FaParser::LibStmtContext::getRuleIndex() const {
  return FaParser::RuleLibStmt;
}


antlrcpp::Any FaParser::LibStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitLibStmt(this);
  else
    return visitor->visitChildren(this);
}

FaParser::LibStmtContext* FaParser::libStmt() {
  LibStmtContext *_localctx = _tracker.createInstance<LibStmtContext>(_ctx, getState());
  enterRule(_localctx, 48, FaParser::RuleLibStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(281);
    match(FaParser::ALib);
    setState(282);
    match(FaParser::String1Literal);
    setState(283);
    match(FaParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportBlockContext ------------------------------------------------------------------

FaParser::ImportBlockContext::ImportBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FaParser::ImportStmtContext *> FaParser::ImportBlockContext::importStmt() {
  return getRuleContexts<FaParser::ImportStmtContext>();
}

FaParser::ImportStmtContext* FaParser::ImportBlockContext::importStmt(size_t i) {
  return getRuleContext<FaParser::ImportStmtContext>(i);
}

std::vector<FaParser::LibStmtContext *> FaParser::ImportBlockContext::libStmt() {
  return getRuleContexts<FaParser::LibStmtContext>();
}

FaParser::LibStmtContext* FaParser::ImportBlockContext::libStmt(size_t i) {
  return getRuleContext<FaParser::LibStmtContext>(i);
}


size_t FaParser::ImportBlockContext::getRuleIndex() const {
  return FaParser::RuleImportBlock;
}


antlrcpp::Any FaParser::ImportBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitImportBlock(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ImportBlockContext* FaParser::importBlock() {
  ImportBlockContext *_localctx = _tracker.createInstance<ImportBlockContext>(_ctx, getState());
  enterRule(_localctx, 50, FaParser::RuleImportBlock);
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
    setState(287); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(287);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case FaParser::AImport: {
          setState(285);
          importStmt();
          break;
        }

        case FaParser::ALib: {
          setState(286);
          libStmt();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(289); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == FaParser::AImport

    || _la == FaParser::ALib);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FaEntryMainFuncBlockContext ------------------------------------------------------------------

FaParser::FaEntryMainFuncBlockContext::FaEntryMainFuncBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::FaEntryMainFuncBlockContext::Static() {
  return getToken(FaParser::Static, 0);
}

FaParser::TypeContext* FaParser::FaEntryMainFuncBlockContext::type() {
  return getRuleContext<FaParser::TypeContext>(0);
}

tree::TerminalNode* FaParser::FaEntryMainFuncBlockContext::FaEntryMain() {
  return getToken(FaParser::FaEntryMain, 0);
}

tree::TerminalNode* FaParser::FaEntryMainFuncBlockContext::QuotYuanL() {
  return getToken(FaParser::QuotYuanL, 0);
}

tree::TerminalNode* FaParser::FaEntryMainFuncBlockContext::QuotYuanR() {
  return getToken(FaParser::QuotYuanR, 0);
}

tree::TerminalNode* FaParser::FaEntryMainFuncBlockContext::QuotHuaL() {
  return getToken(FaParser::QuotHuaL, 0);
}

tree::TerminalNode* FaParser::FaEntryMainFuncBlockContext::QuotHuaR() {
  return getToken(FaParser::QuotHuaR, 0);
}

std::vector<FaParser::StmtContext *> FaParser::FaEntryMainFuncBlockContext::stmt() {
  return getRuleContexts<FaParser::StmtContext>();
}

FaParser::StmtContext* FaParser::FaEntryMainFuncBlockContext::stmt(size_t i) {
  return getRuleContext<FaParser::StmtContext>(i);
}


size_t FaParser::FaEntryMainFuncBlockContext::getRuleIndex() const {
  return FaParser::RuleFaEntryMainFuncBlock;
}


antlrcpp::Any FaParser::FaEntryMainFuncBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitFaEntryMainFuncBlock(this);
  else
    return visitor->visitChildren(this);
}

FaParser::FaEntryMainFuncBlockContext* FaParser::faEntryMainFuncBlock() {
  FaEntryMainFuncBlockContext *_localctx = _tracker.createInstance<FaEntryMainFuncBlockContext>(_ctx, getState());
  enterRule(_localctx, 52, FaParser::RuleFaEntryMainFuncBlock);
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
    setState(291);
    match(FaParser::Static);
    setState(292);
    type();
    setState(293);
    match(FaParser::FaEntryMain);
    setState(294);
    match(FaParser::QuotYuanL);
    setState(295);
    match(FaParser::QuotYuanR);
    setState(296);
    match(FaParser::QuotHuaL);
    setState(300);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 13) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 13)) & ((1ULL << (FaParser::Return - 13))
      | (1ULL << (FaParser::Id - 13))
      | (1ULL << (FaParser::ReverseOp - 13))
      | (1ULL << (FaParser::AddAddOp - 13))
      | (1ULL << (FaParser::SubSubOp - 13))
      | (1ULL << (FaParser::AddOp - 13))
      | (1ULL << (FaParser::SubOp - 13))
      | (1ULL << (FaParser::ColonColon - 13))
      | (1ULL << (FaParser::QuotYuanL - 13))
      | (1ULL << (FaParser::BoolLiteral - 13))
      | (1ULL << (FaParser::IntLiteral - 13))
      | (1ULL << (FaParser::FloatLiteral - 13)))) != 0)) {
      setState(297);
      stmt();
      setState(302);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(303);
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

FaParser::ImportBlockContext* FaParser::ProgramContext::importBlock() {
  return getRuleContext<FaParser::ImportBlockContext>(0);
}

std::vector<FaParser::ClassBlockContext *> FaParser::ProgramContext::classBlock() {
  return getRuleContexts<FaParser::ClassBlockContext>();
}

FaParser::ClassBlockContext* FaParser::ProgramContext::classBlock(size_t i) {
  return getRuleContext<FaParser::ClassBlockContext>(i);
}

FaParser::FaEntryMainFuncBlockContext* FaParser::ProgramContext::faEntryMainFuncBlock() {
  return getRuleContext<FaParser::FaEntryMainFuncBlockContext>(0);
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
  enterRule(_localctx, 54, FaParser::RuleProgram);
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
    setState(308);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Use) {
      setState(305);
      useStmt();
      setState(310);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(312);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::AImport

    || _la == FaParser::ALib) {
      setState(311);
      importBlock();
    }
    setState(317);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Class)
      | (1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(314);
      classBlock();
      setState(319);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(321);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Static) {
      setState(320);
      faEntryMainFuncBlock();
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
  "ids", "literal", "typeAfter", "type", "eTypeAfter", "eType", "typeVar", 
  "typeVarList", "eTypeVar", "eTypeVarList", "allAssign", "allOp", "expr", 
  "useStmt", "returnStmt", "stmt", "publicLevel", "classParent", "classItemPart", 
  "classItemFieldBlock", "classItemFuncBlock", "classBlock", "callConvention", 
  "importStmt", "libStmt", "importBlock", "faEntryMainFuncBlock", "program"
};

std::vector<std::string> FaParser::_literalNames = {
  "", "'@import'", "'@lib'", "'__cdecl'", "'__fastcall'", "'__stdcall'", 
  "'class'", "'const'", "'FaEntryMain'", "'internal'", "'public'", "'protected'", 
  "'private'", "'return'", "'static'", "'use'", "", "'='", "'\u003F\u003F='", 
  "'+='", "'-='", "'*='", "'**='", "'/='", "'%='", "'&='", "'|='", "'^='", 
  "'&&='", "'||='", "'<<='", "'>>='", "'~'", "'++'", "'--'", "'.'", "'\u003F\u003F'", 
  "'+'", "'-'", "'*'", "'/'", "'**'", "'%'", "'&'", "'|'", "'^'", "'&&'", 
  "'||'", "'<<'", "'>>'", "'\u003F'", "','", "'::'", "':'", "';'", "'['", 
  "']'", "'<'", "'>'", "'{'", "'}'", "'('", "')'"
};

std::vector<std::string> FaParser::_symbolicNames = {
  "", "AImport", "ALib", "CC__Cdecl", "CC__FastCall", "CC__StdCall", "Class", 
  "Const", "FaEntryMain", "Internal", "Public", "Protected", "Private", 
  "Return", "Static", "Use", "Id", "Assign", "QusQusAssign", "AddAssign", 
  "SubAssign", "StarAssign", "StarStarAssign", "DivAssign", "ModAssign", 
  "AndAssign", "OrAssign", "XorAssign", "AndAndAssign", "OrOrAssign", "ShiftLAssign", 
  "ShiftRAssign", "ReverseOp", "AddAddOp", "SubSubOp", "PointOp", "QusQusOp", 
  "AddOp", "SubOp", "StarOp", "DivOp", "StarStarOp", "ModOp", "AndOp", "OrOp", 
  "XorOp", "AndAndOp", "OrOrOp", "ShiftLOp", "ShiftROp", "Qus", "Comma", 
  "ColonColon", "Colon", "Semi", "QuotFangL", "QuotFangR", "QuotJianL", 
  "QuotJianR", "QuotHuaL", "QuotHuaR", "QuotYuanL", "QuotYuanR", "BoolLiteral", 
  "IntLiteral", "FloatLiteral", "String1Literal", "Comment1", "Comment2", 
  "WS"
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
       0x3, 0x47, 0x146, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 
       0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 
       0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 
       0x9, 0x1d, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x3e, 0xa, 0x2, 
       0xc, 0x2, 0xe, 0x2, 0x41, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x49, 0xa, 0x4, 0x3, 0x5, 
       0x5, 0x5, 0x4c, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x54, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 
       0x57, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
       0x3, 0x5, 0x6, 0x5, 0x5f, 0xa, 0x5, 0xd, 0x5, 0xe, 0x5, 0x60, 0x3, 
       0x5, 0x3, 0x5, 0x5, 0x5, 0x65, 0xa, 0x5, 0x3, 0x5, 0x7, 0x5, 0x68, 
       0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x6b, 0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 
       0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x71, 0xa, 0x6, 0x3, 0x7, 0x5, 0x7, 
       0x74, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x78, 0xa, 0x7, 0xc, 
       0x7, 0xe, 0x7, 0x7b, 0xb, 0x7, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x7f, 
       0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x84, 0xa, 0x9, 
       0xc, 0x9, 0xe, 0x9, 0x87, 0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 
       0x8b, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x90, 0xa, 
       0xb, 0xc, 0xb, 0xe, 0xb, 0x93, 0xb, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 
       0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
       0x7, 0xe, 0x9e, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0xa1, 0xb, 0xe, 0x3, 
       0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xa7, 0xa, 0xe, 0x3, 
       0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0xae, 0xa, 
       0xe, 0xc, 0xe, 0xe, 0xe, 0xb1, 0xb, 0xe, 0x5, 0xe, 0xb3, 0xa, 0xe, 
       0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
       0xe, 0x5, 0xe, 0xbc, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x6, 0xe, 0xc0, 
       0xa, 0xe, 0xd, 0xe, 0xe, 0xe, 0xc1, 0x7, 0xe, 0xc4, 0xa, 0xe, 0xc, 
       0xe, 0xe, 0xe, 0xc7, 0xb, 0xe, 0x5, 0xe, 0xc9, 0xa, 0xe, 0x3, 0xf, 
       0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xd1, 
       0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
       0x3, 0x11, 0x5, 0x11, 0xd9, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 
       0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0xe1, 0xa, 0x13, 
       0xc, 0x13, 0xe, 0x13, 0xe4, 0xb, 0x13, 0x3, 0x14, 0x5, 0x14, 0xe7, 
       0xa, 0x14, 0x3, 0x14, 0x5, 0x14, 0xea, 0xa, 0x14, 0x3, 0x14, 0x3, 
       0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 
       0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x7, 0x16, 0xf8, 
       0xa, 0x16, 0xc, 0x16, 0xe, 0x16, 0xfb, 0xb, 0x16, 0x3, 0x16, 0x3, 
       0x16, 0x3, 0x17, 0x5, 0x17, 0x100, 0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 
       0x3, 0x17, 0x5, 0x17, 0x105, 0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
       0x17, 0x7, 0x17, 0x10a, 0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 0x10d, 0xb, 
       0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 
       0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
       0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
       0x1b, 0x3, 0x1b, 0x6, 0x1b, 0x122, 0xa, 0x1b, 0xd, 0x1b, 0xe, 0x1b, 
       0x123, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
       0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x12d, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 
       0x130, 0xb, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x7, 0x1d, 0x135, 
       0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 0x138, 0xb, 0x1d, 0x3, 0x1d, 0x5, 
       0x1d, 0x13b, 0xa, 0x1d, 0x3, 0x1d, 0x7, 0x1d, 0x13e, 0xa, 0x1d, 0xc, 
       0x1d, 0xe, 0x1d, 0x141, 0xb, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x144, 0xa, 
       0x1d, 0x3, 0x1d, 0x2, 0x2, 0x1e, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 
       0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 
       0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x2, 
       0x9, 0x3, 0x2, 0x41, 0x43, 0x3, 0x2, 0x13, 0x21, 0x3, 0x2, 0x25, 
       0x33, 0x4, 0x2, 0x22, 0x24, 0x27, 0x28, 0x3, 0x2, 0x23, 0x24, 0x3, 
       0x2, 0xb, 0xe, 0x3, 0x2, 0x5, 0x7, 0x2, 0x157, 0x2, 0x3a, 0x3, 0x2, 
       0x2, 0x2, 0x4, 0x42, 0x3, 0x2, 0x2, 0x2, 0x6, 0x48, 0x3, 0x2, 0x2, 
       0x2, 0x8, 0x4b, 0x3, 0x2, 0x2, 0x2, 0xa, 0x70, 0x3, 0x2, 0x2, 0x2, 
       0xc, 0x73, 0x3, 0x2, 0x2, 0x2, 0xe, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x10, 
       0x80, 0x3, 0x2, 0x2, 0x2, 0x12, 0x88, 0x3, 0x2, 0x2, 0x2, 0x14, 0x8c, 
       0x3, 0x2, 0x2, 0x2, 0x16, 0x94, 0x3, 0x2, 0x2, 0x2, 0x18, 0x96, 0x3, 
       0x2, 0x2, 0x2, 0x1a, 0xc8, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xca, 0x3, 0x2, 
       0x2, 0x2, 0x1e, 0xce, 0x3, 0x2, 0x2, 0x2, 0x20, 0xd8, 0x3, 0x2, 0x2, 
       0x2, 0x22, 0xda, 0x3, 0x2, 0x2, 0x2, 0x24, 0xdc, 0x3, 0x2, 0x2, 0x2, 
       0x26, 0xe6, 0x3, 0x2, 0x2, 0x2, 0x28, 0xee, 0x3, 0x2, 0x2, 0x2, 0x2a, 
       0xf1, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xff, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x110, 
       0x3, 0x2, 0x2, 0x2, 0x30, 0x112, 0x3, 0x2, 0x2, 0x2, 0x32, 0x11b, 
       0x3, 0x2, 0x2, 0x2, 0x34, 0x121, 0x3, 0x2, 0x2, 0x2, 0x36, 0x125, 
       0x3, 0x2, 0x2, 0x2, 0x38, 0x136, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3f, 
       0x7, 0x12, 0x2, 0x2, 0x3b, 0x3c, 0x7, 0x25, 0x2, 0x2, 0x3c, 0x3e, 
       0x7, 0x12, 0x2, 0x2, 0x3d, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x41, 
       0x3, 0x2, 0x2, 0x2, 0x3f, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x3, 
       0x2, 0x2, 0x2, 0x40, 0x3, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3f, 0x3, 0x2, 
       0x2, 0x2, 0x42, 0x43, 0x9, 0x2, 0x2, 0x2, 0x43, 0x5, 0x3, 0x2, 0x2, 
       0x2, 0x44, 0x45, 0x7, 0x39, 0x2, 0x2, 0x45, 0x49, 0x7, 0x3a, 0x2, 
       0x2, 0x46, 0x49, 0x7, 0x2d, 0x2, 0x2, 0x47, 0x49, 0x7, 0x34, 0x2, 
       0x2, 0x48, 0x44, 0x3, 0x2, 0x2, 0x2, 0x48, 0x46, 0x3, 0x2, 0x2, 0x2, 
       0x48, 0x47, 0x3, 0x2, 0x2, 0x2, 0x49, 0x7, 0x3, 0x2, 0x2, 0x2, 0x4a, 
       0x4c, 0x7, 0x9, 0x2, 0x2, 0x4b, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 
       0x3, 0x2, 0x2, 0x2, 0x4c, 0x64, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x65, 0x7, 
       0x12, 0x2, 0x2, 0x4e, 0x4f, 0x7, 0x12, 0x2, 0x2, 0x4f, 0x50, 0x7, 
       0x3b, 0x2, 0x2, 0x50, 0x55, 0x5, 0x8, 0x5, 0x2, 0x51, 0x52, 0x7, 
       0x35, 0x2, 0x2, 0x52, 0x54, 0x5, 0x8, 0x5, 0x2, 0x53, 0x51, 0x3, 
       0x2, 0x2, 0x2, 0x54, 0x57, 0x3, 0x2, 0x2, 0x2, 0x55, 0x53, 0x3, 0x2, 
       0x2, 0x2, 0x55, 0x56, 0x3, 0x2, 0x2, 0x2, 0x56, 0x58, 0x3, 0x2, 0x2, 
       0x2, 0x57, 0x55, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x7, 0x3c, 0x2, 
       0x2, 0x59, 0x65, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5b, 0x7, 0x3f, 0x2, 
       0x2, 0x5b, 0x5e, 0x5, 0x8, 0x5, 0x2, 0x5c, 0x5d, 0x7, 0x35, 0x2, 
       0x2, 0x5d, 0x5f, 0x5, 0x8, 0x5, 0x2, 0x5e, 0x5c, 0x3, 0x2, 0x2, 0x2, 
       0x5f, 0x60, 0x3, 0x2, 0x2, 0x2, 0x60, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x60, 
       0x61, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 
       0x7, 0x40, 0x2, 0x2, 0x63, 0x65, 0x3, 0x2, 0x2, 0x2, 0x64, 0x4d, 
       0x3, 0x2, 0x2, 0x2, 0x64, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x64, 0x5a, 0x3, 
       0x2, 0x2, 0x2, 0x65, 0x69, 0x3, 0x2, 0x2, 0x2, 0x66, 0x68, 0x5, 0x6, 
       0x4, 0x2, 0x67, 0x66, 0x3, 0x2, 0x2, 0x2, 0x68, 0x6b, 0x3, 0x2, 0x2, 
       0x2, 0x69, 0x67, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x3, 0x2, 0x2, 0x2, 
       0x6a, 0x9, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6c, 
       0x6d, 0x7, 0x39, 0x2, 0x2, 0x6d, 0x71, 0x7, 0x3a, 0x2, 0x2, 0x6e, 
       0x71, 0x7, 0x2d, 0x2, 0x2, 0x6f, 0x71, 0x7, 0x29, 0x2, 0x2, 0x70, 
       0x6c, 0x3, 0x2, 0x2, 0x2, 0x70, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x70, 0x6f, 
       0x3, 0x2, 0x2, 0x2, 0x71, 0xb, 0x3, 0x2, 0x2, 0x2, 0x72, 0x74, 0x7, 
       0x9, 0x2, 0x2, 0x73, 0x72, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x3, 0x2, 
       0x2, 0x2, 0x74, 0x75, 0x3, 0x2, 0x2, 0x2, 0x75, 0x79, 0x7, 0x12, 
       0x2, 0x2, 0x76, 0x78, 0x5, 0xa, 0x6, 0x2, 0x77, 0x76, 0x3, 0x2, 0x2, 
       0x2, 0x78, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x79, 0x77, 0x3, 0x2, 0x2, 0x2, 
       0x79, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7a, 0xd, 0x3, 0x2, 0x2, 0x2, 0x7b, 
       0x79, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7e, 0x5, 0x8, 0x5, 0x2, 0x7d, 0x7f, 
       0x7, 0x12, 0x2, 0x2, 0x7e, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 
       0x3, 0x2, 0x2, 0x2, 0x7f, 0xf, 0x3, 0x2, 0x2, 0x2, 0x80, 0x85, 0x5, 
       0xe, 0x8, 0x2, 0x81, 0x82, 0x7, 0x35, 0x2, 0x2, 0x82, 0x84, 0x5, 
       0xe, 0x8, 0x2, 0x83, 0x81, 0x3, 0x2, 0x2, 0x2, 0x84, 0x87, 0x3, 0x2, 
       0x2, 0x2, 0x85, 0x83, 0x3, 0x2, 0x2, 0x2, 0x85, 0x86, 0x3, 0x2, 0x2, 
       0x2, 0x86, 0x11, 0x3, 0x2, 0x2, 0x2, 0x87, 0x85, 0x3, 0x2, 0x2, 0x2, 
       0x88, 0x8a, 0x5, 0xc, 0x7, 0x2, 0x89, 0x8b, 0x7, 0x12, 0x2, 0x2, 
       0x8a, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8b, 
       0x13, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x91, 0x5, 0x12, 0xa, 0x2, 0x8d, 
       0x8e, 0x7, 0x35, 0x2, 0x2, 0x8e, 0x90, 0x5, 0x12, 0xa, 0x2, 0x8f, 
       0x8d, 0x3, 0x2, 0x2, 0x2, 0x90, 0x93, 0x3, 0x2, 0x2, 0x2, 0x91, 0x8f, 
       0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x3, 0x2, 0x2, 0x2, 0x92, 0x15, 0x3, 
       0x2, 0x2, 0x2, 0x93, 0x91, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x9, 0x3, 
       0x2, 0x2, 0x95, 0x17, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 0x9, 0x4, 0x2, 
       0x2, 0x97, 0x19, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x7, 0x3f, 0x2, 
       0x2, 0x99, 0x9a, 0x5, 0x1a, 0xe, 0x2, 0x9a, 0x9b, 0x7, 0x40, 0x2, 
       0x2, 0x9b, 0xc9, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9e, 0x9, 0x5, 0x2, 0x2, 
       0x9d, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9e, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x9f, 
       0x9d, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa6, 
       0x3, 0x2, 0x2, 0x2, 0xa1, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa7, 0x5, 
       0x2, 0x2, 0x2, 0xa3, 0xa4, 0x7, 0x36, 0x2, 0x2, 0xa4, 0xa7, 0x7, 
       0x12, 0x2, 0x2, 0xa5, 0xa7, 0x5, 0x4, 0x3, 0x2, 0xa6, 0xa2, 0x3, 
       0x2, 0x2, 0x2, 0xa6, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa5, 0x3, 0x2, 
       0x2, 0x2, 0xa7, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xc4, 0x9, 0x6, 0x2, 
       0x2, 0xa9, 0xb2, 0x7, 0x3f, 0x2, 0x2, 0xaa, 0xaf, 0x5, 0x1a, 0xe, 
       0x2, 0xab, 0xac, 0x7, 0x35, 0x2, 0x2, 0xac, 0xae, 0x5, 0x1a, 0xe, 
       0x2, 0xad, 0xab, 0x3, 0x2, 0x2, 0x2, 0xae, 0xb1, 0x3, 0x2, 0x2, 0x2, 
       0xaf, 0xad, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb0, 
       0xb3, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xaa, 
       0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 0x3, 
       0x2, 0x2, 0x2, 0xb4, 0xc4, 0x7, 0x40, 0x2, 0x2, 0xb5, 0xb6, 0x7, 
       0x39, 0x2, 0x2, 0xb6, 0xb7, 0x5, 0x1a, 0xe, 0x2, 0xb7, 0xb8, 0x7, 
       0x39, 0x2, 0x2, 0xb8, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xbc, 0x5, 
       0x16, 0xc, 0x2, 0xba, 0xbc, 0x5, 0x18, 0xd, 0x2, 0xbb, 0xb9, 0x3, 
       0x2, 0x2, 0x2, 0xbb, 0xba, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x3, 0x2, 
       0x2, 0x2, 0xbd, 0xbe, 0x5, 0x1a, 0xe, 0x2, 0xbe, 0xc0, 0x3, 0x2, 
       0x2, 0x2, 0xbf, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc1, 0x3, 0x2, 0x2, 
       0x2, 0xc1, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x3, 0x2, 0x2, 0x2, 
       0xc2, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xc3, 
       0xa9, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xbf, 
       0x3, 0x2, 0x2, 0x2, 0xc4, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc3, 0x3, 
       0x2, 0x2, 0x2, 0xc5, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc9, 0x3, 0x2, 
       0x2, 0x2, 0xc7, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc8, 0x98, 0x3, 0x2, 0x2, 
       0x2, 0xc8, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xc9, 0x1b, 0x3, 0x2, 0x2, 0x2, 
       0xca, 0xcb, 0x7, 0x11, 0x2, 0x2, 0xcb, 0xcc, 0x5, 0x2, 0x2, 0x2, 
       0xcc, 0xcd, 0x7, 0x38, 0x2, 0x2, 0xcd, 0x1d, 0x3, 0x2, 0x2, 0x2, 
       0xce, 0xd0, 0x7, 0xf, 0x2, 0x2, 0xcf, 0xd1, 0x5, 0x1a, 0xe, 0x2, 
       0xd0, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd1, 
       0xd2, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0x7, 0x38, 0x2, 0x2, 0xd3, 
       0x1f, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd9, 0x5, 0x1e, 0x10, 0x2, 0xd5, 
       0xd6, 0x5, 0x1a, 0xe, 0x2, 0xd6, 0xd7, 0x7, 0x38, 0x2, 0x2, 0xd7, 
       0xd9, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd5, 
       0x3, 0x2, 0x2, 0x2, 0xd9, 0x21, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdb, 0x9, 
       0x7, 0x2, 0x2, 0xdb, 0x23, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x7, 0x37, 
       0x2, 0x2, 0xdd, 0xe2, 0x5, 0x2, 0x2, 0x2, 0xde, 0xdf, 0x7, 0x35, 
       0x2, 0x2, 0xdf, 0xe1, 0x5, 0x2, 0x2, 0x2, 0xe0, 0xde, 0x3, 0x2, 0x2, 
       0x2, 0xe1, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe0, 0x3, 0x2, 0x2, 0x2, 
       0xe2, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe3, 0x25, 0x3, 0x2, 0x2, 0x2, 0xe4, 
       0xe2, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe7, 0x5, 0x22, 0x12, 0x2, 0xe6, 
       0xe5, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe9, 
       0x3, 0x2, 0x2, 0x2, 0xe8, 0xea, 0x7, 0x10, 0x2, 0x2, 0xe9, 0xe8, 
       0x3, 0x2, 0x2, 0x2, 0xe9, 0xea, 0x3, 0x2, 0x2, 0x2, 0xea, 0xeb, 0x3, 
       0x2, 0x2, 0x2, 0xeb, 0xec, 0x7, 0x12, 0x2, 0x2, 0xec, 0xed, 0x7, 
       0x12, 0x2, 0x2, 0xed, 0x27, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 0x5, 
       0x26, 0x14, 0x2, 0xef, 0xf0, 0x7, 0x38, 0x2, 0x2, 0xf0, 0x29, 0x3, 
       0x2, 0x2, 0x2, 0xf1, 0xf2, 0x5, 0x26, 0x14, 0x2, 0xf2, 0xf3, 0x7, 
       0x3f, 0x2, 0x2, 0xf3, 0xf4, 0x5, 0x10, 0x9, 0x2, 0xf4, 0xf5, 0x7, 
       0x40, 0x2, 0x2, 0xf5, 0xf9, 0x7, 0x3d, 0x2, 0x2, 0xf6, 0xf8, 0x5, 
       0x20, 0x11, 0x2, 0xf7, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xfb, 0x3, 
       0x2, 0x2, 0x2, 0xf9, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x3, 0x2, 
       0x2, 0x2, 0xfa, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xf9, 0x3, 0x2, 0x2, 
       0x2, 0xfc, 0xfd, 0x7, 0x3e, 0x2, 0x2, 0xfd, 0x2b, 0x3, 0x2, 0x2, 
       0x2, 0xfe, 0x100, 0x5, 0x22, 0x12, 0x2, 0xff, 0xfe, 0x3, 0x2, 0x2, 
       0x2, 0xff, 0x100, 0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 0x3, 0x2, 0x2, 
       0x2, 0x101, 0x102, 0x7, 0x8, 0x2, 0x2, 0x102, 0x104, 0x7, 0x12, 0x2, 
       0x2, 0x103, 0x105, 0x5, 0x24, 0x13, 0x2, 0x104, 0x103, 0x3, 0x2, 
       0x2, 0x2, 0x104, 0x105, 0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 0x3, 0x2, 
       0x2, 0x2, 0x106, 0x10b, 0x7, 0x3d, 0x2, 0x2, 0x107, 0x10a, 0x5, 0x28, 
       0x15, 0x2, 0x108, 0x10a, 0x5, 0x2a, 0x16, 0x2, 0x109, 0x107, 0x3, 
       0x2, 0x2, 0x2, 0x109, 0x108, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10d, 0x3, 
       0x2, 0x2, 0x2, 0x10b, 0x109, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x10c, 0x3, 
       0x2, 0x2, 0x2, 0x10c, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10b, 0x3, 
       0x2, 0x2, 0x2, 0x10e, 0x10f, 0x7, 0x3e, 0x2, 0x2, 0x10f, 0x2d, 0x3, 
       0x2, 0x2, 0x2, 0x110, 0x111, 0x9, 0x8, 0x2, 0x2, 0x111, 0x2f, 0x3, 
       0x2, 0x2, 0x2, 0x112, 0x113, 0x7, 0x3, 0x2, 0x2, 0x113, 0x114, 0x5, 
       0xc, 0x7, 0x2, 0x114, 0x115, 0x5, 0x2e, 0x18, 0x2, 0x115, 0x116, 
       0x7, 0x12, 0x2, 0x2, 0x116, 0x117, 0x7, 0x3f, 0x2, 0x2, 0x117, 0x118, 
       0x5, 0x14, 0xb, 0x2, 0x118, 0x119, 0x7, 0x40, 0x2, 0x2, 0x119, 0x11a, 
       0x7, 0x38, 0x2, 0x2, 0x11a, 0x31, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 
       0x7, 0x4, 0x2, 0x2, 0x11c, 0x11d, 0x7, 0x44, 0x2, 0x2, 0x11d, 0x11e, 
       0x7, 0x38, 0x2, 0x2, 0x11e, 0x33, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x122, 
       0x5, 0x30, 0x19, 0x2, 0x120, 0x122, 0x5, 0x32, 0x1a, 0x2, 0x121, 
       0x11f, 0x3, 0x2, 0x2, 0x2, 0x121, 0x120, 0x3, 0x2, 0x2, 0x2, 0x122, 
       0x123, 0x3, 0x2, 0x2, 0x2, 0x123, 0x121, 0x3, 0x2, 0x2, 0x2, 0x123, 
       0x124, 0x3, 0x2, 0x2, 0x2, 0x124, 0x35, 0x3, 0x2, 0x2, 0x2, 0x125, 
       0x126, 0x7, 0x10, 0x2, 0x2, 0x126, 0x127, 0x5, 0x8, 0x5, 0x2, 0x127, 
       0x128, 0x7, 0xa, 0x2, 0x2, 0x128, 0x129, 0x7, 0x3f, 0x2, 0x2, 0x129, 
       0x12a, 0x7, 0x40, 0x2, 0x2, 0x12a, 0x12e, 0x7, 0x3d, 0x2, 0x2, 0x12b, 
       0x12d, 0x5, 0x20, 0x11, 0x2, 0x12c, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12d, 
       0x130, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12e, 
       0x12f, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x131, 0x3, 0x2, 0x2, 0x2, 0x130, 
       0x12e, 0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 0x7, 0x3e, 0x2, 0x2, 0x132, 
       0x37, 0x3, 0x2, 0x2, 0x2, 0x133, 0x135, 0x5, 0x1c, 0xf, 0x2, 0x134, 
       0x133, 0x3, 0x2, 0x2, 0x2, 0x135, 0x138, 0x3, 0x2, 0x2, 0x2, 0x136, 
       0x134, 0x3, 0x2, 0x2, 0x2, 0x136, 0x137, 0x3, 0x2, 0x2, 0x2, 0x137, 
       0x13a, 0x3, 0x2, 0x2, 0x2, 0x138, 0x136, 0x3, 0x2, 0x2, 0x2, 0x139, 
       0x13b, 0x5, 0x34, 0x1b, 0x2, 0x13a, 0x139, 0x3, 0x2, 0x2, 0x2, 0x13a, 
       0x13b, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x13c, 
       0x13e, 0x5, 0x2c, 0x17, 0x2, 0x13d, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x13e, 
       0x141, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13f, 
       0x140, 0x3, 0x2, 0x2, 0x2, 0x140, 0x143, 0x3, 0x2, 0x2, 0x2, 0x141, 
       0x13f, 0x3, 0x2, 0x2, 0x2, 0x142, 0x144, 0x5, 0x36, 0x1c, 0x2, 0x143, 
       0x142, 0x3, 0x2, 0x2, 0x2, 0x143, 0x144, 0x3, 0x2, 0x2, 0x2, 0x144, 
       0x39, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x3f, 0x48, 0x4b, 0x55, 0x60, 0x64, 
       0x69, 0x70, 0x73, 0x79, 0x7e, 0x85, 0x8a, 0x91, 0x9f, 0xa6, 0xaf, 
       0xb2, 0xbb, 0xc1, 0xc3, 0xc5, 0xc8, 0xd0, 0xd8, 0xe2, 0xe6, 0xe9, 
       0xf9, 0xff, 0x104, 0x109, 0x10b, 0x121, 0x123, 0x12e, 0x136, 0x13a, 
       0x13f, 0x143, 
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

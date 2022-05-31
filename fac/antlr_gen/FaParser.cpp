
// Generated from Fa.g4 by ANTLR 4.9.3


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


//----------------- ShiftLAssignContext ------------------------------------------------------------------

FaParser::ShiftLAssignContext::ShiftLAssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::ShiftLOpContext* FaParser::ShiftLAssignContext::shiftLOp() {
  return getRuleContext<FaParser::ShiftLOpContext>(0);
}

tree::TerminalNode* FaParser::ShiftLAssignContext::Assign() {
  return getToken(FaParser::Assign, 0);
}


size_t FaParser::ShiftLAssignContext::getRuleIndex() const {
  return FaParser::RuleShiftLAssign;
}


antlrcpp::Any FaParser::ShiftLAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitShiftLAssign(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ShiftLAssignContext* FaParser::shiftLAssign() {
  ShiftLAssignContext *_localctx = _tracker.createInstance<ShiftLAssignContext>(_ctx, getState());
  enterRule(_localctx, 0, FaParser::RuleShiftLAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(220);
    shiftLOp();
    setState(221);
    match(FaParser::Assign);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShiftRAssignContext ------------------------------------------------------------------

FaParser::ShiftRAssignContext::ShiftRAssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::ShiftROpContext* FaParser::ShiftRAssignContext::shiftROp() {
  return getRuleContext<FaParser::ShiftROpContext>(0);
}

tree::TerminalNode* FaParser::ShiftRAssignContext::Assign() {
  return getToken(FaParser::Assign, 0);
}


size_t FaParser::ShiftRAssignContext::getRuleIndex() const {
  return FaParser::RuleShiftRAssign;
}


antlrcpp::Any FaParser::ShiftRAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitShiftRAssign(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ShiftRAssignContext* FaParser::shiftRAssign() {
  ShiftRAssignContext *_localctx = _tracker.createInstance<ShiftRAssignContext>(_ctx, getState());
  enterRule(_localctx, 2, FaParser::RuleShiftRAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(223);
    shiftROp();
    setState(224);
    match(FaParser::Assign);
   
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

FaParser::ShiftLAssignContext* FaParser::AllAssignContext::shiftLAssign() {
  return getRuleContext<FaParser::ShiftLAssignContext>(0);
}

FaParser::ShiftRAssignContext* FaParser::AllAssignContext::shiftRAssign() {
  return getRuleContext<FaParser::ShiftRAssignContext>(0);
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
  enterRule(_localctx, 4, FaParser::RuleAllAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(241);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::Assign: {
        enterOuterAlt(_localctx, 1);
        setState(226);
        match(FaParser::Assign);
        break;
      }

      case FaParser::QusQusAssign: {
        enterOuterAlt(_localctx, 2);
        setState(227);
        match(FaParser::QusQusAssign);
        break;
      }

      case FaParser::AddAssign: {
        enterOuterAlt(_localctx, 3);
        setState(228);
        match(FaParser::AddAssign);
        break;
      }

      case FaParser::SubAssign: {
        enterOuterAlt(_localctx, 4);
        setState(229);
        match(FaParser::SubAssign);
        break;
      }

      case FaParser::StarAssign: {
        enterOuterAlt(_localctx, 5);
        setState(230);
        match(FaParser::StarAssign);
        break;
      }

      case FaParser::StarStarAssign: {
        enterOuterAlt(_localctx, 6);
        setState(231);
        match(FaParser::StarStarAssign);
        break;
      }

      case FaParser::DivAssign: {
        enterOuterAlt(_localctx, 7);
        setState(232);
        match(FaParser::DivAssign);
        break;
      }

      case FaParser::ModAssign: {
        enterOuterAlt(_localctx, 8);
        setState(233);
        match(FaParser::ModAssign);
        break;
      }

      case FaParser::AndAssign: {
        enterOuterAlt(_localctx, 9);
        setState(234);
        match(FaParser::AndAssign);
        break;
      }

      case FaParser::OrAssign: {
        enterOuterAlt(_localctx, 10);
        setState(235);
        match(FaParser::OrAssign);
        break;
      }

      case FaParser::XorAssign: {
        enterOuterAlt(_localctx, 11);
        setState(236);
        match(FaParser::XorAssign);
        break;
      }

      case FaParser::AndAndAssign: {
        enterOuterAlt(_localctx, 12);
        setState(237);
        match(FaParser::AndAndAssign);
        break;
      }

      case FaParser::OrOrAssign: {
        enterOuterAlt(_localctx, 13);
        setState(238);
        match(FaParser::OrOrAssign);
        break;
      }

      case FaParser::T__2: {
        enterOuterAlt(_localctx, 14);
        setState(239);
        shiftLAssign();
        break;
      }

      case FaParser::T__3: {
        enterOuterAlt(_localctx, 15);
        setState(240);
        shiftRAssign();
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

//----------------- ShiftLOpContext ------------------------------------------------------------------

FaParser::ShiftLOpContext::ShiftLOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FaParser::QJianLContext *> FaParser::ShiftLOpContext::qJianL() {
  return getRuleContexts<FaParser::QJianLContext>();
}

FaParser::QJianLContext* FaParser::ShiftLOpContext::qJianL(size_t i) {
  return getRuleContext<FaParser::QJianLContext>(i);
}


size_t FaParser::ShiftLOpContext::getRuleIndex() const {
  return FaParser::RuleShiftLOp;
}


antlrcpp::Any FaParser::ShiftLOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitShiftLOp(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ShiftLOpContext* FaParser::shiftLOp() {
  ShiftLOpContext *_localctx = _tracker.createInstance<ShiftLOpContext>(_ctx, getState());
  enterRule(_localctx, 6, FaParser::RuleShiftLOp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(243);
    qJianL();
    setState(244);
    qJianL();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShiftROpContext ------------------------------------------------------------------

FaParser::ShiftROpContext::ShiftROpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FaParser::QJianRContext *> FaParser::ShiftROpContext::qJianR() {
  return getRuleContexts<FaParser::QJianRContext>();
}

FaParser::QJianRContext* FaParser::ShiftROpContext::qJianR(size_t i) {
  return getRuleContext<FaParser::QJianRContext>(i);
}


size_t FaParser::ShiftROpContext::getRuleIndex() const {
  return FaParser::RuleShiftROp;
}


antlrcpp::Any FaParser::ShiftROpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitShiftROp(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ShiftROpContext* FaParser::shiftROp() {
  ShiftROpContext *_localctx = _tracker.createInstance<ShiftROpContext>(_ctx, getState());
  enterRule(_localctx, 8, FaParser::RuleShiftROp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(246);
    qJianR();
    setState(247);
    qJianR();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EndlContext ------------------------------------------------------------------

FaParser::EndlContext::EndlContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FaParser::EndlContext::Lf() {
  return getTokens(FaParser::Lf);
}

tree::TerminalNode* FaParser::EndlContext::Lf(size_t i) {
  return getToken(FaParser::Lf, i);
}

std::vector<tree::TerminalNode *> FaParser::EndlContext::Semi() {
  return getTokens(FaParser::Semi);
}

tree::TerminalNode* FaParser::EndlContext::Semi(size_t i) {
  return getToken(FaParser::Semi, i);
}


size_t FaParser::EndlContext::getRuleIndex() const {
  return FaParser::RuleEndl;
}


antlrcpp::Any FaParser::EndlContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitEndl(this);
  else
    return visitor->visitChildren(this);
}

FaParser::EndlContext* FaParser::endl() {
  EndlContext *_localctx = _tracker.createInstance<EndlContext>(_ctx, getState());
  enterRule(_localctx, 10, FaParser::RuleEndl);
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
    enterOuterAlt(_localctx, 1);
    setState(250); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(249);
              _la = _input->LA(1);
              if (!(_la == FaParser::Lf

              || _la == FaParser::Semi)) {
              _errHandler->recoverInline(this);
              }
              else {
                _errHandler->reportMatch(this);
                consume();
              }
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(252); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Endl2Context ------------------------------------------------------------------

FaParser::Endl2Context::Endl2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FaParser::Endl2Context::Lf() {
  return getTokens(FaParser::Lf);
}

tree::TerminalNode* FaParser::Endl2Context::Lf(size_t i) {
  return getToken(FaParser::Lf, i);
}

std::vector<tree::TerminalNode *> FaParser::Endl2Context::Comma() {
  return getTokens(FaParser::Comma);
}

tree::TerminalNode* FaParser::Endl2Context::Comma(size_t i) {
  return getToken(FaParser::Comma, i);
}


size_t FaParser::Endl2Context::getRuleIndex() const {
  return FaParser::RuleEndl2;
}


antlrcpp::Any FaParser::Endl2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitEndl2(this);
  else
    return visitor->visitChildren(this);
}

FaParser::Endl2Context* FaParser::endl2() {
  Endl2Context *_localctx = _tracker.createInstance<Endl2Context>(_ctx, getState());
  enterRule(_localctx, 12, FaParser::RuleEndl2);
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
    enterOuterAlt(_localctx, 1);
    setState(255); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(254);
              _la = _input->LA(1);
              if (!(_la == FaParser::Comma

              || _la == FaParser::Lf)) {
              _errHandler->recoverInline(this);
              }
              else {
                _errHandler->reportMatch(this);
                consume();
              }
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(257); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QFangLContext ------------------------------------------------------------------

FaParser::QFangLContext::QFangLContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FaParser::QFangLContext::getRuleIndex() const {
  return FaParser::RuleQFangL;
}


antlrcpp::Any FaParser::QFangLContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitQFangL(this);
  else
    return visitor->visitChildren(this);
}

FaParser::QFangLContext* FaParser::qFangL() {
  QFangLContext *_localctx = _tracker.createInstance<QFangLContext>(_ctx, getState());
  enterRule(_localctx, 14, FaParser::RuleQFangL);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(259);
    match(FaParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QFangRContext ------------------------------------------------------------------

FaParser::QFangRContext::QFangRContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FaParser::QFangRContext::getRuleIndex() const {
  return FaParser::RuleQFangR;
}


antlrcpp::Any FaParser::QFangRContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitQFangR(this);
  else
    return visitor->visitChildren(this);
}

FaParser::QFangRContext* FaParser::qFangR() {
  QFangRContext *_localctx = _tracker.createInstance<QFangRContext>(_ctx, getState());
  enterRule(_localctx, 16, FaParser::RuleQFangR);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(261);
    match(FaParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QJianLContext ------------------------------------------------------------------

FaParser::QJianLContext::QJianLContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FaParser::QJianLContext::getRuleIndex() const {
  return FaParser::RuleQJianL;
}


antlrcpp::Any FaParser::QJianLContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitQJianL(this);
  else
    return visitor->visitChildren(this);
}

FaParser::QJianLContext* FaParser::qJianL() {
  QJianLContext *_localctx = _tracker.createInstance<QJianLContext>(_ctx, getState());
  enterRule(_localctx, 18, FaParser::RuleQJianL);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(263);
    match(FaParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QJianRContext ------------------------------------------------------------------

FaParser::QJianRContext::QJianRContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FaParser::QJianRContext::getRuleIndex() const {
  return FaParser::RuleQJianR;
}


antlrcpp::Any FaParser::QJianRContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitQJianR(this);
  else
    return visitor->visitChildren(this);
}

FaParser::QJianRContext* FaParser::qJianR() {
  QJianRContext *_localctx = _tracker.createInstance<QJianRContext>(_ctx, getState());
  enterRule(_localctx, 20, FaParser::RuleQJianR);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(265);
    match(FaParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QHuaLContext ------------------------------------------------------------------

FaParser::QHuaLContext::QHuaLContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FaParser::QHuaLContext::getRuleIndex() const {
  return FaParser::RuleQHuaL;
}


antlrcpp::Any FaParser::QHuaLContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitQHuaL(this);
  else
    return visitor->visitChildren(this);
}

FaParser::QHuaLContext* FaParser::qHuaL() {
  QHuaLContext *_localctx = _tracker.createInstance<QHuaLContext>(_ctx, getState());
  enterRule(_localctx, 22, FaParser::RuleQHuaL);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(267);
    match(FaParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QHuaRContext ------------------------------------------------------------------

FaParser::QHuaRContext::QHuaRContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FaParser::QHuaRContext::getRuleIndex() const {
  return FaParser::RuleQHuaR;
}


antlrcpp::Any FaParser::QHuaRContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitQHuaR(this);
  else
    return visitor->visitChildren(this);
}

FaParser::QHuaRContext* FaParser::qHuaR() {
  QHuaRContext *_localctx = _tracker.createInstance<QHuaRContext>(_ctx, getState());
  enterRule(_localctx, 24, FaParser::RuleQHuaR);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(269);
    match(FaParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QYuanLContext ------------------------------------------------------------------

FaParser::QYuanLContext::QYuanLContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FaParser::QYuanLContext::getRuleIndex() const {
  return FaParser::RuleQYuanL;
}


antlrcpp::Any FaParser::QYuanLContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitQYuanL(this);
  else
    return visitor->visitChildren(this);
}

FaParser::QYuanLContext* FaParser::qYuanL() {
  QYuanLContext *_localctx = _tracker.createInstance<QYuanLContext>(_ctx, getState());
  enterRule(_localctx, 26, FaParser::RuleQYuanL);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(271);
    match(FaParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QYuanRContext ------------------------------------------------------------------

FaParser::QYuanRContext::QYuanRContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FaParser::QYuanRContext::getRuleIndex() const {
  return FaParser::RuleQYuanR;
}


antlrcpp::Any FaParser::QYuanRContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitQYuanR(this);
  else
    return visitor->visitChildren(this);
}

FaParser::QYuanRContext* FaParser::qYuanR() {
  QYuanRContext *_localctx = _tracker.createInstance<QYuanRContext>(_ctx, getState());
  enterRule(_localctx, 28, FaParser::RuleQYuanR);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(273);
    match(FaParser::T__7);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuotFangLContext ------------------------------------------------------------------

FaParser::QuotFangLContext::QuotFangLContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::QFangLContext* FaParser::QuotFangLContext::qFangL() {
  return getRuleContext<FaParser::QFangLContext>(0);
}

FaParser::EndlContext* FaParser::QuotFangLContext::endl() {
  return getRuleContext<FaParser::EndlContext>(0);
}


size_t FaParser::QuotFangLContext::getRuleIndex() const {
  return FaParser::RuleQuotFangL;
}


antlrcpp::Any FaParser::QuotFangLContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitQuotFangL(this);
  else
    return visitor->visitChildren(this);
}

FaParser::QuotFangLContext* FaParser::quotFangL() {
  QuotFangLContext *_localctx = _tracker.createInstance<QuotFangLContext>(_ctx, getState());
  enterRule(_localctx, 30, FaParser::RuleQuotFangL);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(275);
    qFangL();
    setState(277);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      setState(276);
      endl();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuotFangRContext ------------------------------------------------------------------

FaParser::QuotFangRContext::QuotFangRContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::QFangRContext* FaParser::QuotFangRContext::qFangR() {
  return getRuleContext<FaParser::QFangRContext>(0);
}

FaParser::EndlContext* FaParser::QuotFangRContext::endl() {
  return getRuleContext<FaParser::EndlContext>(0);
}


size_t FaParser::QuotFangRContext::getRuleIndex() const {
  return FaParser::RuleQuotFangR;
}


antlrcpp::Any FaParser::QuotFangRContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitQuotFangR(this);
  else
    return visitor->visitChildren(this);
}

FaParser::QuotFangRContext* FaParser::quotFangR() {
  QuotFangRContext *_localctx = _tracker.createInstance<QuotFangRContext>(_ctx, getState());
  enterRule(_localctx, 32, FaParser::RuleQuotFangR);
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
    setState(280);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Lf

    || _la == FaParser::Semi) {
      setState(279);
      endl();
    }
    setState(282);
    qFangR();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuotJianLContext ------------------------------------------------------------------

FaParser::QuotJianLContext::QuotJianLContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::QJianLContext* FaParser::QuotJianLContext::qJianL() {
  return getRuleContext<FaParser::QJianLContext>(0);
}

FaParser::EndlContext* FaParser::QuotJianLContext::endl() {
  return getRuleContext<FaParser::EndlContext>(0);
}


size_t FaParser::QuotJianLContext::getRuleIndex() const {
  return FaParser::RuleQuotJianL;
}


antlrcpp::Any FaParser::QuotJianLContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitQuotJianL(this);
  else
    return visitor->visitChildren(this);
}

FaParser::QuotJianLContext* FaParser::quotJianL() {
  QuotJianLContext *_localctx = _tracker.createInstance<QuotJianLContext>(_ctx, getState());
  enterRule(_localctx, 34, FaParser::RuleQuotJianL);
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
    setState(284);
    qJianL();
    setState(286);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Lf

    || _la == FaParser::Semi) {
      setState(285);
      endl();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuotJianRContext ------------------------------------------------------------------

FaParser::QuotJianRContext::QuotJianRContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::QJianRContext* FaParser::QuotJianRContext::qJianR() {
  return getRuleContext<FaParser::QJianRContext>(0);
}

FaParser::EndlContext* FaParser::QuotJianRContext::endl() {
  return getRuleContext<FaParser::EndlContext>(0);
}


size_t FaParser::QuotJianRContext::getRuleIndex() const {
  return FaParser::RuleQuotJianR;
}


antlrcpp::Any FaParser::QuotJianRContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitQuotJianR(this);
  else
    return visitor->visitChildren(this);
}

FaParser::QuotJianRContext* FaParser::quotJianR() {
  QuotJianRContext *_localctx = _tracker.createInstance<QuotJianRContext>(_ctx, getState());
  enterRule(_localctx, 36, FaParser::RuleQuotJianR);
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
    setState(289);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Lf

    || _la == FaParser::Semi) {
      setState(288);
      endl();
    }
    setState(291);
    qJianR();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuotHuaLContext ------------------------------------------------------------------

FaParser::QuotHuaLContext::QuotHuaLContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::QHuaLContext* FaParser::QuotHuaLContext::qHuaL() {
  return getRuleContext<FaParser::QHuaLContext>(0);
}

FaParser::EndlContext* FaParser::QuotHuaLContext::endl() {
  return getRuleContext<FaParser::EndlContext>(0);
}


size_t FaParser::QuotHuaLContext::getRuleIndex() const {
  return FaParser::RuleQuotHuaL;
}


antlrcpp::Any FaParser::QuotHuaLContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitQuotHuaL(this);
  else
    return visitor->visitChildren(this);
}

FaParser::QuotHuaLContext* FaParser::quotHuaL() {
  QuotHuaLContext *_localctx = _tracker.createInstance<QuotHuaLContext>(_ctx, getState());
  enterRule(_localctx, 38, FaParser::RuleQuotHuaL);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(293);
    qHuaL();
    setState(295);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      setState(294);
      endl();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuotHuaRContext ------------------------------------------------------------------

FaParser::QuotHuaRContext::QuotHuaRContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::QHuaRContext* FaParser::QuotHuaRContext::qHuaR() {
  return getRuleContext<FaParser::QHuaRContext>(0);
}

FaParser::EndlContext* FaParser::QuotHuaRContext::endl() {
  return getRuleContext<FaParser::EndlContext>(0);
}


size_t FaParser::QuotHuaRContext::getRuleIndex() const {
  return FaParser::RuleQuotHuaR;
}


antlrcpp::Any FaParser::QuotHuaRContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitQuotHuaR(this);
  else
    return visitor->visitChildren(this);
}

FaParser::QuotHuaRContext* FaParser::quotHuaR() {
  QuotHuaRContext *_localctx = _tracker.createInstance<QuotHuaRContext>(_ctx, getState());
  enterRule(_localctx, 40, FaParser::RuleQuotHuaR);
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
    setState(298);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Lf

    || _la == FaParser::Semi) {
      setState(297);
      endl();
    }
    setState(300);
    qHuaR();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuotYuanLContext ------------------------------------------------------------------

FaParser::QuotYuanLContext::QuotYuanLContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::QYuanLContext* FaParser::QuotYuanLContext::qYuanL() {
  return getRuleContext<FaParser::QYuanLContext>(0);
}

FaParser::EndlContext* FaParser::QuotYuanLContext::endl() {
  return getRuleContext<FaParser::EndlContext>(0);
}


size_t FaParser::QuotYuanLContext::getRuleIndex() const {
  return FaParser::RuleQuotYuanL;
}


antlrcpp::Any FaParser::QuotYuanLContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitQuotYuanL(this);
  else
    return visitor->visitChildren(this);
}

FaParser::QuotYuanLContext* FaParser::quotYuanL() {
  QuotYuanLContext *_localctx = _tracker.createInstance<QuotYuanLContext>(_ctx, getState());
  enterRule(_localctx, 42, FaParser::RuleQuotYuanL);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(302);
    qYuanL();
    setState(304);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      setState(303);
      endl();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuotYuanRContext ------------------------------------------------------------------

FaParser::QuotYuanRContext::QuotYuanRContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::QYuanRContext* FaParser::QuotYuanRContext::qYuanR() {
  return getRuleContext<FaParser::QYuanRContext>(0);
}

FaParser::EndlContext* FaParser::QuotYuanRContext::endl() {
  return getRuleContext<FaParser::EndlContext>(0);
}


size_t FaParser::QuotYuanRContext::getRuleIndex() const {
  return FaParser::RuleQuotYuanR;
}


antlrcpp::Any FaParser::QuotYuanRContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitQuotYuanR(this);
  else
    return visitor->visitChildren(this);
}

FaParser::QuotYuanRContext* FaParser::quotYuanR() {
  QuotYuanRContext *_localctx = _tracker.createInstance<QuotYuanRContext>(_ctx, getState());
  enterRule(_localctx, 44, FaParser::RuleQuotYuanR);
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
    setState(307);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Lf

    || _la == FaParser::Semi) {
      setState(306);
      endl();
    }
    setState(309);
    qYuanR();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LtOpContext ------------------------------------------------------------------

FaParser::LtOpContext::LtOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::QJianLContext* FaParser::LtOpContext::qJianL() {
  return getRuleContext<FaParser::QJianLContext>(0);
}


size_t FaParser::LtOpContext::getRuleIndex() const {
  return FaParser::RuleLtOp;
}


antlrcpp::Any FaParser::LtOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitLtOp(this);
  else
    return visitor->visitChildren(this);
}

FaParser::LtOpContext* FaParser::ltOp() {
  LtOpContext *_localctx = _tracker.createInstance<LtOpContext>(_ctx, getState());
  enterRule(_localctx, 46, FaParser::RuleLtOp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(311);
    qJianL();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LtEqualOpContext ------------------------------------------------------------------

FaParser::LtEqualOpContext::LtEqualOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::QJianLContext* FaParser::LtEqualOpContext::qJianL() {
  return getRuleContext<FaParser::QJianLContext>(0);
}

tree::TerminalNode* FaParser::LtEqualOpContext::Assign() {
  return getToken(FaParser::Assign, 0);
}


size_t FaParser::LtEqualOpContext::getRuleIndex() const {
  return FaParser::RuleLtEqualOp;
}


antlrcpp::Any FaParser::LtEqualOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitLtEqualOp(this);
  else
    return visitor->visitChildren(this);
}

FaParser::LtEqualOpContext* FaParser::ltEqualOp() {
  LtEqualOpContext *_localctx = _tracker.createInstance<LtEqualOpContext>(_ctx, getState());
  enterRule(_localctx, 48, FaParser::RuleLtEqualOp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(313);
    qJianL();
    setState(314);
    match(FaParser::Assign);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GtOpContext ------------------------------------------------------------------

FaParser::GtOpContext::GtOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::QJianRContext* FaParser::GtOpContext::qJianR() {
  return getRuleContext<FaParser::QJianRContext>(0);
}


size_t FaParser::GtOpContext::getRuleIndex() const {
  return FaParser::RuleGtOp;
}


antlrcpp::Any FaParser::GtOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitGtOp(this);
  else
    return visitor->visitChildren(this);
}

FaParser::GtOpContext* FaParser::gtOp() {
  GtOpContext *_localctx = _tracker.createInstance<GtOpContext>(_ctx, getState());
  enterRule(_localctx, 50, FaParser::RuleGtOp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(316);
    qJianR();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GtEqualOpContext ------------------------------------------------------------------

FaParser::GtEqualOpContext::GtEqualOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::QJianRContext* FaParser::GtEqualOpContext::qJianR() {
  return getRuleContext<FaParser::QJianRContext>(0);
}

tree::TerminalNode* FaParser::GtEqualOpContext::Assign() {
  return getToken(FaParser::Assign, 0);
}


size_t FaParser::GtEqualOpContext::getRuleIndex() const {
  return FaParser::RuleGtEqualOp;
}


antlrcpp::Any FaParser::GtEqualOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitGtEqualOp(this);
  else
    return visitor->visitChildren(this);
}

FaParser::GtEqualOpContext* FaParser::gtEqualOp() {
  GtEqualOpContext *_localctx = _tracker.createInstance<GtEqualOpContext>(_ctx, getState());
  enterRule(_localctx, 52, FaParser::RuleGtEqualOp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(318);
    qJianR();
    setState(319);
    match(FaParser::Assign);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EqualOpContext ------------------------------------------------------------------

FaParser::EqualOpContext::EqualOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FaParser::EqualOpContext::Assign() {
  return getTokens(FaParser::Assign);
}

tree::TerminalNode* FaParser::EqualOpContext::Assign(size_t i) {
  return getToken(FaParser::Assign, i);
}


size_t FaParser::EqualOpContext::getRuleIndex() const {
  return FaParser::RuleEqualOp;
}


antlrcpp::Any FaParser::EqualOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitEqualOp(this);
  else
    return visitor->visitChildren(this);
}

FaParser::EqualOpContext* FaParser::equalOp() {
  EqualOpContext *_localctx = _tracker.createInstance<EqualOpContext>(_ctx, getState());
  enterRule(_localctx, 54, FaParser::RuleEqualOp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(321);
    match(FaParser::Assign);
    setState(322);
    match(FaParser::Assign);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NotEqualOpContext ------------------------------------------------------------------

FaParser::NotEqualOpContext::NotEqualOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::NotEqualOpContext::Exclam() {
  return getToken(FaParser::Exclam, 0);
}

tree::TerminalNode* FaParser::NotEqualOpContext::Assign() {
  return getToken(FaParser::Assign, 0);
}


size_t FaParser::NotEqualOpContext::getRuleIndex() const {
  return FaParser::RuleNotEqualOp;
}


antlrcpp::Any FaParser::NotEqualOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitNotEqualOp(this);
  else
    return visitor->visitChildren(this);
}

FaParser::NotEqualOpContext* FaParser::notEqualOp() {
  NotEqualOpContext *_localctx = _tracker.createInstance<NotEqualOpContext>(_ctx, getState());
  enterRule(_localctx, 56, FaParser::RuleNotEqualOp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(324);
    match(FaParser::Exclam);
    setState(325);
    match(FaParser::Assign);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprFuncDefContext ------------------------------------------------------------------

FaParser::ExprFuncDefContext::ExprFuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::ExprFuncDefContext::Assign() {
  return getToken(FaParser::Assign, 0);
}

FaParser::QJianRContext* FaParser::ExprFuncDefContext::qJianR() {
  return getRuleContext<FaParser::QJianRContext>(0);
}


size_t FaParser::ExprFuncDefContext::getRuleIndex() const {
  return FaParser::RuleExprFuncDef;
}


antlrcpp::Any FaParser::ExprFuncDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitExprFuncDef(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ExprFuncDefContext* FaParser::exprFuncDef() {
  ExprFuncDefContext *_localctx = _tracker.createInstance<ExprFuncDefContext>(_ctx, getState());
  enterRule(_localctx, 58, FaParser::RuleExprFuncDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(327);
    match(FaParser::Assign);
    setState(328);
    qJianR();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SelfOp2Context ------------------------------------------------------------------

FaParser::SelfOp2Context::SelfOp2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::SelfOp2Context::AddOp() {
  return getToken(FaParser::AddOp, 0);
}

tree::TerminalNode* FaParser::SelfOp2Context::SubOp() {
  return getToken(FaParser::SubOp, 0);
}

tree::TerminalNode* FaParser::SelfOp2Context::StarOp() {
  return getToken(FaParser::StarOp, 0);
}

tree::TerminalNode* FaParser::SelfOp2Context::DivOp() {
  return getToken(FaParser::DivOp, 0);
}

tree::TerminalNode* FaParser::SelfOp2Context::StarStarOp() {
  return getToken(FaParser::StarStarOp, 0);
}

tree::TerminalNode* FaParser::SelfOp2Context::ModOp() {
  return getToken(FaParser::ModOp, 0);
}

tree::TerminalNode* FaParser::SelfOp2Context::AndOp() {
  return getToken(FaParser::AndOp, 0);
}

tree::TerminalNode* FaParser::SelfOp2Context::OrOp() {
  return getToken(FaParser::OrOp, 0);
}

tree::TerminalNode* FaParser::SelfOp2Context::XorOp() {
  return getToken(FaParser::XorOp, 0);
}

tree::TerminalNode* FaParser::SelfOp2Context::AndAndOp() {
  return getToken(FaParser::AndAndOp, 0);
}

tree::TerminalNode* FaParser::SelfOp2Context::OrOrOp() {
  return getToken(FaParser::OrOrOp, 0);
}

FaParser::ShiftLOpContext* FaParser::SelfOp2Context::shiftLOp() {
  return getRuleContext<FaParser::ShiftLOpContext>(0);
}

FaParser::ShiftROpContext* FaParser::SelfOp2Context::shiftROp() {
  return getRuleContext<FaParser::ShiftROpContext>(0);
}


size_t FaParser::SelfOp2Context::getRuleIndex() const {
  return FaParser::RuleSelfOp2;
}


antlrcpp::Any FaParser::SelfOp2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitSelfOp2(this);
  else
    return visitor->visitChildren(this);
}

FaParser::SelfOp2Context* FaParser::selfOp2() {
  SelfOp2Context *_localctx = _tracker.createInstance<SelfOp2Context>(_ctx, getState());
  enterRule(_localctx, 60, FaParser::RuleSelfOp2);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(343);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::AddOp: {
        enterOuterAlt(_localctx, 1);
        setState(330);
        match(FaParser::AddOp);
        break;
      }

      case FaParser::SubOp: {
        enterOuterAlt(_localctx, 2);
        setState(331);
        match(FaParser::SubOp);
        break;
      }

      case FaParser::StarOp: {
        enterOuterAlt(_localctx, 3);
        setState(332);
        match(FaParser::StarOp);
        break;
      }

      case FaParser::DivOp: {
        enterOuterAlt(_localctx, 4);
        setState(333);
        match(FaParser::DivOp);
        break;
      }

      case FaParser::StarStarOp: {
        enterOuterAlt(_localctx, 5);
        setState(334);
        match(FaParser::StarStarOp);
        break;
      }

      case FaParser::ModOp: {
        enterOuterAlt(_localctx, 6);
        setState(335);
        match(FaParser::ModOp);
        break;
      }

      case FaParser::AndOp: {
        enterOuterAlt(_localctx, 7);
        setState(336);
        match(FaParser::AndOp);
        break;
      }

      case FaParser::OrOp: {
        enterOuterAlt(_localctx, 8);
        setState(337);
        match(FaParser::OrOp);
        break;
      }

      case FaParser::XorOp: {
        enterOuterAlt(_localctx, 9);
        setState(338);
        match(FaParser::XorOp);
        break;
      }

      case FaParser::AndAndOp: {
        enterOuterAlt(_localctx, 10);
        setState(339);
        match(FaParser::AndAndOp);
        break;
      }

      case FaParser::OrOrOp: {
        enterOuterAlt(_localctx, 11);
        setState(340);
        match(FaParser::OrOrOp);
        break;
      }

      case FaParser::T__2: {
        enterOuterAlt(_localctx, 12);
        setState(341);
        shiftLOp();
        break;
      }

      case FaParser::T__3: {
        enterOuterAlt(_localctx, 13);
        setState(342);
        shiftROp();
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

//----------------- CompareOp2Context ------------------------------------------------------------------

FaParser::CompareOp2Context::CompareOp2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::LtOpContext* FaParser::CompareOp2Context::ltOp() {
  return getRuleContext<FaParser::LtOpContext>(0);
}

FaParser::LtEqualOpContext* FaParser::CompareOp2Context::ltEqualOp() {
  return getRuleContext<FaParser::LtEqualOpContext>(0);
}

FaParser::GtOpContext* FaParser::CompareOp2Context::gtOp() {
  return getRuleContext<FaParser::GtOpContext>(0);
}

FaParser::GtEqualOpContext* FaParser::CompareOp2Context::gtEqualOp() {
  return getRuleContext<FaParser::GtEqualOpContext>(0);
}

FaParser::EqualOpContext* FaParser::CompareOp2Context::equalOp() {
  return getRuleContext<FaParser::EqualOpContext>(0);
}

FaParser::NotEqualOpContext* FaParser::CompareOp2Context::notEqualOp() {
  return getRuleContext<FaParser::NotEqualOpContext>(0);
}


size_t FaParser::CompareOp2Context::getRuleIndex() const {
  return FaParser::RuleCompareOp2;
}


antlrcpp::Any FaParser::CompareOp2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitCompareOp2(this);
  else
    return visitor->visitChildren(this);
}

FaParser::CompareOp2Context* FaParser::compareOp2() {
  CompareOp2Context *_localctx = _tracker.createInstance<CompareOp2Context>(_ctx, getState());
  enterRule(_localctx, 62, FaParser::RuleCompareOp2);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(351);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(345);
      ltOp();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(346);
      ltEqualOp();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(347);
      gtOp();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(348);
      gtEqualOp();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(349);
      equalOp();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(350);
      notEqualOp();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ChangeOp2Context ------------------------------------------------------------------

FaParser::ChangeOp2Context::ChangeOp2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::ChangeOp2Context::QusQusOp() {
  return getToken(FaParser::QusQusOp, 0);
}

FaParser::CompareOp2Context* FaParser::ChangeOp2Context::compareOp2() {
  return getRuleContext<FaParser::CompareOp2Context>(0);
}


size_t FaParser::ChangeOp2Context::getRuleIndex() const {
  return FaParser::RuleChangeOp2;
}


antlrcpp::Any FaParser::ChangeOp2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitChangeOp2(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ChangeOp2Context* FaParser::changeOp2() {
  ChangeOp2Context *_localctx = _tracker.createInstance<ChangeOp2Context>(_ctx, getState());
  enterRule(_localctx, 64, FaParser::RuleChangeOp2);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(355);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::QusQusOp: {
        enterOuterAlt(_localctx, 1);
        setState(353);
        match(FaParser::QusQusOp);
        break;
      }

      case FaParser::T__2:
      case FaParser::T__3:
      case FaParser::Assign:
      case FaParser::Exclam: {
        enterOuterAlt(_localctx, 2);
        setState(354);
        compareOp2();
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

//----------------- AllOp2Context ------------------------------------------------------------------

FaParser::AllOp2Context::AllOp2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::SelfOp2Context* FaParser::AllOp2Context::selfOp2() {
  return getRuleContext<FaParser::SelfOp2Context>(0);
}

FaParser::ChangeOp2Context* FaParser::AllOp2Context::changeOp2() {
  return getRuleContext<FaParser::ChangeOp2Context>(0);
}


size_t FaParser::AllOp2Context::getRuleIndex() const {
  return FaParser::RuleAllOp2;
}


antlrcpp::Any FaParser::AllOp2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitAllOp2(this);
  else
    return visitor->visitChildren(this);
}

FaParser::AllOp2Context* FaParser::allOp2() {
  AllOp2Context *_localctx = _tracker.createInstance<AllOp2Context>(_ctx, getState());
  enterRule(_localctx, 66, FaParser::RuleAllOp2);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(359);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(357);
      selfOp2();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(358);
      changeOp2();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntNumContext ------------------------------------------------------------------

FaParser::IntNumContext::IntNumContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::IntNumContext::IntLiteral() {
  return getToken(FaParser::IntLiteral, 0);
}

tree::TerminalNode* FaParser::IntNumContext::SubOp() {
  return getToken(FaParser::SubOp, 0);
}


size_t FaParser::IntNumContext::getRuleIndex() const {
  return FaParser::RuleIntNum;
}


antlrcpp::Any FaParser::IntNumContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitIntNum(this);
  else
    return visitor->visitChildren(this);
}

FaParser::IntNumContext* FaParser::intNum() {
  IntNumContext *_localctx = _tracker.createInstance<IntNumContext>(_ctx, getState());
  enterRule(_localctx, 68, FaParser::RuleIntNum);
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
    setState(362);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::SubOp) {
      setState(361);
      match(FaParser::SubOp);
    }
    setState(364);
    match(FaParser::IntLiteral);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FloatNumContext ------------------------------------------------------------------

FaParser::FloatNumContext::FloatNumContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::FloatNumContext::FloatLiteral() {
  return getToken(FaParser::FloatLiteral, 0);
}

tree::TerminalNode* FaParser::FloatNumContext::SubOp() {
  return getToken(FaParser::SubOp, 0);
}


size_t FaParser::FloatNumContext::getRuleIndex() const {
  return FaParser::RuleFloatNum;
}


antlrcpp::Any FaParser::FloatNumContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitFloatNum(this);
  else
    return visitor->visitChildren(this);
}

FaParser::FloatNumContext* FaParser::floatNum() {
  FloatNumContext *_localctx = _tracker.createInstance<FloatNumContext>(_ctx, getState());
  enterRule(_localctx, 70, FaParser::RuleFloatNum);
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
    setState(367);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::SubOp) {
      setState(366);
      match(FaParser::SubOp);
    }
    setState(369);
    match(FaParser::FloatLiteral);
   
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

FaParser::IntNumContext* FaParser::LiteralContext::intNum() {
  return getRuleContext<FaParser::IntNumContext>(0);
}

FaParser::FloatNumContext* FaParser::LiteralContext::floatNum() {
  return getRuleContext<FaParser::FloatNumContext>(0);
}

tree::TerminalNode* FaParser::LiteralContext::String1Literal() {
  return getToken(FaParser::String1Literal, 0);
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
  enterRule(_localctx, 72, FaParser::RuleLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(375);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(371);
      match(FaParser::BoolLiteral);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(372);
      intNum();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(373);
      floatNum();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(374);
      match(FaParser::String1Literal);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdContext ------------------------------------------------------------------

FaParser::IdContext::IdContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::IdContext::Underline() {
  return getToken(FaParser::Underline, 0);
}

tree::TerminalNode* FaParser::IdContext::RawId() {
  return getToken(FaParser::RawId, 0);
}


size_t FaParser::IdContext::getRuleIndex() const {
  return FaParser::RuleId;
}


antlrcpp::Any FaParser::IdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitId(this);
  else
    return visitor->visitChildren(this);
}

FaParser::IdContext* FaParser::id() {
  IdContext *_localctx = _tracker.createInstance<IdContext>(_ctx, getState());
  enterRule(_localctx, 74, FaParser::RuleId);
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
    setState(377);
    _la = _input->LA(1);
    if (!(_la == FaParser::Underline

    || _la == FaParser::RawId)) {
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

//----------------- IdsContext ------------------------------------------------------------------

FaParser::IdsContext::IdsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FaParser::IdContext *> FaParser::IdsContext::id() {
  return getRuleContexts<FaParser::IdContext>();
}

FaParser::IdContext* FaParser::IdsContext::id(size_t i) {
  return getRuleContext<FaParser::IdContext>(i);
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
  enterRule(_localctx, 76, FaParser::RuleIds);

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
    setState(379);
    id();
    setState(384);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(380);
        match(FaParser::PointOp);
        setState(381);
        id(); 
      }
      setState(386);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
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

FaParser::QuotFangLContext* FaParser::TypeAfterContext::quotFangL() {
  return getRuleContext<FaParser::QuotFangLContext>(0);
}

FaParser::QuotFangRContext* FaParser::TypeAfterContext::quotFangR() {
  return getRuleContext<FaParser::QuotFangRContext>(0);
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
  enterRule(_localctx, 78, FaParser::RuleTypeAfter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(391);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(387);
        quotFangL();
        setState(388);
        quotFangR();
        break;
      }

      case FaParser::Qus: {
        enterOuterAlt(_localctx, 2);
        setState(390);
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

//----------------- TypeSingleContext ------------------------------------------------------------------

FaParser::TypeSingleContext::TypeSingleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::IdsContext* FaParser::TypeSingleContext::ids() {
  return getRuleContext<FaParser::IdsContext>(0);
}

FaParser::QuotJianLContext* FaParser::TypeSingleContext::quotJianL() {
  return getRuleContext<FaParser::QuotJianLContext>(0);
}

std::vector<FaParser::TypeContext *> FaParser::TypeSingleContext::type() {
  return getRuleContexts<FaParser::TypeContext>();
}

FaParser::TypeContext* FaParser::TypeSingleContext::type(size_t i) {
  return getRuleContext<FaParser::TypeContext>(i);
}

FaParser::QuotJianRContext* FaParser::TypeSingleContext::quotJianR() {
  return getRuleContext<FaParser::QuotJianRContext>(0);
}

std::vector<tree::TerminalNode *> FaParser::TypeSingleContext::Comma() {
  return getTokens(FaParser::Comma);
}

tree::TerminalNode* FaParser::TypeSingleContext::Comma(size_t i) {
  return getToken(FaParser::Comma, i);
}


size_t FaParser::TypeSingleContext::getRuleIndex() const {
  return FaParser::RuleTypeSingle;
}


antlrcpp::Any FaParser::TypeSingleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitTypeSingle(this);
  else
    return visitor->visitChildren(this);
}

FaParser::TypeSingleContext* FaParser::typeSingle() {
  TypeSingleContext *_localctx = _tracker.createInstance<TypeSingleContext>(_ctx, getState());
  enterRule(_localctx, 80, FaParser::RuleTypeSingle);
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
    setState(393);
    ids();
    setState(405);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::T__2) {
      setState(394);
      quotJianL();
      setState(395);
      type();
      setState(400);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FaParser::Comma) {
        setState(396);
        match(FaParser::Comma);
        setState(397);
        type();
        setState(402);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(403);
      quotJianR();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeMultiContext ------------------------------------------------------------------

FaParser::TypeMultiContext::TypeMultiContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::QuotYuanLContext* FaParser::TypeMultiContext::quotYuanL() {
  return getRuleContext<FaParser::QuotYuanLContext>(0);
}

std::vector<FaParser::TypeVarContext *> FaParser::TypeMultiContext::typeVar() {
  return getRuleContexts<FaParser::TypeVarContext>();
}

FaParser::TypeVarContext* FaParser::TypeMultiContext::typeVar(size_t i) {
  return getRuleContext<FaParser::TypeVarContext>(i);
}

FaParser::QuotYuanRContext* FaParser::TypeMultiContext::quotYuanR() {
  return getRuleContext<FaParser::QuotYuanRContext>(0);
}

std::vector<tree::TerminalNode *> FaParser::TypeMultiContext::Comma() {
  return getTokens(FaParser::Comma);
}

tree::TerminalNode* FaParser::TypeMultiContext::Comma(size_t i) {
  return getToken(FaParser::Comma, i);
}


size_t FaParser::TypeMultiContext::getRuleIndex() const {
  return FaParser::RuleTypeMulti;
}


antlrcpp::Any FaParser::TypeMultiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitTypeMulti(this);
  else
    return visitor->visitChildren(this);
}

FaParser::TypeMultiContext* FaParser::typeMulti() {
  TypeMultiContext *_localctx = _tracker.createInstance<TypeMultiContext>(_ctx, getState());
  enterRule(_localctx, 82, FaParser::RuleTypeMulti);
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
    setState(407);
    quotYuanL();
    setState(408);
    typeVar();
    setState(411); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(409);
      match(FaParser::Comma);
      setState(410);
      typeVar();
      setState(413); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == FaParser::Comma);
    setState(415);
    quotYuanR();
   
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

FaParser::TypeSingleContext* FaParser::TypeContext::typeSingle() {
  return getRuleContext<FaParser::TypeSingleContext>(0);
}

FaParser::TypeMultiContext* FaParser::TypeContext::typeMulti() {
  return getRuleContext<FaParser::TypeMultiContext>(0);
}

std::vector<FaParser::TypeAfterContext *> FaParser::TypeContext::typeAfter() {
  return getRuleContexts<FaParser::TypeAfterContext>();
}

FaParser::TypeAfterContext* FaParser::TypeContext::typeAfter(size_t i) {
  return getRuleContext<FaParser::TypeAfterContext>(i);
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
  enterRule(_localctx, 84, FaParser::RuleType);
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
    setState(419);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::Underline:
      case FaParser::RawId: {
        setState(417);
        typeSingle();
        break;
      }

      case FaParser::T__6: {
        setState(418);
        typeMulti();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(424);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::T__0 || _la == FaParser::Qus) {
      setState(421);
      typeAfter();
      setState(426);
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

//----------------- TypeWrapContext ------------------------------------------------------------------

FaParser::TypeWrapContext::TypeWrapContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::TypeContext* FaParser::TypeWrapContext::type() {
  return getRuleContext<FaParser::TypeContext>(0);
}

tree::TerminalNode* FaParser::TypeWrapContext::Mut() {
  return getToken(FaParser::Mut, 0);
}

tree::TerminalNode* FaParser::TypeWrapContext::Params() {
  return getToken(FaParser::Params, 0);
}


size_t FaParser::TypeWrapContext::getRuleIndex() const {
  return FaParser::RuleTypeWrap;
}


antlrcpp::Any FaParser::TypeWrapContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitTypeWrap(this);
  else
    return visitor->visitChildren(this);
}

FaParser::TypeWrapContext* FaParser::typeWrap() {
  TypeWrapContext *_localctx = _tracker.createInstance<TypeWrapContext>(_ctx, getState());
  enterRule(_localctx, 86, FaParser::RuleTypeWrap);
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
    setState(428);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Mut

    || _la == FaParser::Params) {
      setState(427);
      _la = _input->LA(1);
      if (!(_la == FaParser::Mut

      || _la == FaParser::Params)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(430);
    type();
   
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

FaParser::IdContext* FaParser::TypeVarContext::id() {
  return getRuleContext<FaParser::IdContext>(0);
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
  enterRule(_localctx, 88, FaParser::RuleTypeVar);
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
    setState(432);
    type();
    setState(434);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Underline

    || _la == FaParser::RawId) {
      setState(433);
      id();
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
  enterRule(_localctx, 90, FaParser::RuleTypeVarList);
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
    setState(436);
    typeVar();
    setState(441);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(437);
      match(FaParser::Comma);
      setState(438);
      typeVar();
      setState(443);
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

//----------------- TypeWrapVar1Context ------------------------------------------------------------------

FaParser::TypeWrapVar1Context::TypeWrapVar1Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::IdContext* FaParser::TypeWrapVar1Context::id() {
  return getRuleContext<FaParser::IdContext>(0);
}

tree::TerminalNode* FaParser::TypeWrapVar1Context::Colon() {
  return getToken(FaParser::Colon, 0);
}

FaParser::TypeWrapContext* FaParser::TypeWrapVar1Context::typeWrap() {
  return getRuleContext<FaParser::TypeWrapContext>(0);
}


size_t FaParser::TypeWrapVar1Context::getRuleIndex() const {
  return FaParser::RuleTypeWrapVar1;
}


antlrcpp::Any FaParser::TypeWrapVar1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitTypeWrapVar1(this);
  else
    return visitor->visitChildren(this);
}

FaParser::TypeWrapVar1Context* FaParser::typeWrapVar1() {
  TypeWrapVar1Context *_localctx = _tracker.createInstance<TypeWrapVar1Context>(_ctx, getState());
  enterRule(_localctx, 92, FaParser::RuleTypeWrapVar1);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(444);
    id();
    setState(445);
    match(FaParser::Colon);
    setState(446);
    typeWrap();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeWrapVarList1Context ------------------------------------------------------------------

FaParser::TypeWrapVarList1Context::TypeWrapVarList1Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FaParser::TypeWrapVar1Context *> FaParser::TypeWrapVarList1Context::typeWrapVar1() {
  return getRuleContexts<FaParser::TypeWrapVar1Context>();
}

FaParser::TypeWrapVar1Context* FaParser::TypeWrapVarList1Context::typeWrapVar1(size_t i) {
  return getRuleContext<FaParser::TypeWrapVar1Context>(i);
}

std::vector<tree::TerminalNode *> FaParser::TypeWrapVarList1Context::Comma() {
  return getTokens(FaParser::Comma);
}

tree::TerminalNode* FaParser::TypeWrapVarList1Context::Comma(size_t i) {
  return getToken(FaParser::Comma, i);
}


size_t FaParser::TypeWrapVarList1Context::getRuleIndex() const {
  return FaParser::RuleTypeWrapVarList1;
}


antlrcpp::Any FaParser::TypeWrapVarList1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitTypeWrapVarList1(this);
  else
    return visitor->visitChildren(this);
}

FaParser::TypeWrapVarList1Context* FaParser::typeWrapVarList1() {
  TypeWrapVarList1Context *_localctx = _tracker.createInstance<TypeWrapVarList1Context>(_ctx, getState());
  enterRule(_localctx, 94, FaParser::RuleTypeWrapVarList1);
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
    setState(448);
    typeWrapVar1();
    setState(453);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(449);
      match(FaParser::Comma);
      setState(450);
      typeWrapVar1();
      setState(455);
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

//----------------- TypeWrapVar2Context ------------------------------------------------------------------

FaParser::TypeWrapVar2Context::TypeWrapVar2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::TypeWrapContext* FaParser::TypeWrapVar2Context::typeWrap() {
  return getRuleContext<FaParser::TypeWrapContext>(0);
}

FaParser::IdContext* FaParser::TypeWrapVar2Context::id() {
  return getRuleContext<FaParser::IdContext>(0);
}


size_t FaParser::TypeWrapVar2Context::getRuleIndex() const {
  return FaParser::RuleTypeWrapVar2;
}


antlrcpp::Any FaParser::TypeWrapVar2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitTypeWrapVar2(this);
  else
    return visitor->visitChildren(this);
}

FaParser::TypeWrapVar2Context* FaParser::typeWrapVar2() {
  TypeWrapVar2Context *_localctx = _tracker.createInstance<TypeWrapVar2Context>(_ctx, getState());
  enterRule(_localctx, 96, FaParser::RuleTypeWrapVar2);
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
    setState(456);
    typeWrap();
    setState(458);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Underline

    || _la == FaParser::RawId) {
      setState(457);
      id();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeWrapVarList2Context ------------------------------------------------------------------

FaParser::TypeWrapVarList2Context::TypeWrapVarList2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FaParser::TypeWrapVar2Context *> FaParser::TypeWrapVarList2Context::typeWrapVar2() {
  return getRuleContexts<FaParser::TypeWrapVar2Context>();
}

FaParser::TypeWrapVar2Context* FaParser::TypeWrapVarList2Context::typeWrapVar2(size_t i) {
  return getRuleContext<FaParser::TypeWrapVar2Context>(i);
}

std::vector<tree::TerminalNode *> FaParser::TypeWrapVarList2Context::Comma() {
  return getTokens(FaParser::Comma);
}

tree::TerminalNode* FaParser::TypeWrapVarList2Context::Comma(size_t i) {
  return getToken(FaParser::Comma, i);
}


size_t FaParser::TypeWrapVarList2Context::getRuleIndex() const {
  return FaParser::RuleTypeWrapVarList2;
}


antlrcpp::Any FaParser::TypeWrapVarList2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitTypeWrapVarList2(this);
  else
    return visitor->visitChildren(this);
}

FaParser::TypeWrapVarList2Context* FaParser::typeWrapVarList2() {
  TypeWrapVarList2Context *_localctx = _tracker.createInstance<TypeWrapVarList2Context>(_ctx, getState());
  enterRule(_localctx, 98, FaParser::RuleTypeWrapVarList2);
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
    setState(460);
    typeWrapVar2();
    setState(465);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(461);
      match(FaParser::Comma);
      setState(462);
      typeWrapVar2();
      setState(467);
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

//----------------- TypeWrapVar3Context ------------------------------------------------------------------

FaParser::TypeWrapVar3Context::TypeWrapVar3Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::IdContext* FaParser::TypeWrapVar3Context::id() {
  return getRuleContext<FaParser::IdContext>(0);
}

FaParser::TypeWrapContext* FaParser::TypeWrapVar3Context::typeWrap() {
  return getRuleContext<FaParser::TypeWrapContext>(0);
}


size_t FaParser::TypeWrapVar3Context::getRuleIndex() const {
  return FaParser::RuleTypeWrapVar3;
}


antlrcpp::Any FaParser::TypeWrapVar3Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitTypeWrapVar3(this);
  else
    return visitor->visitChildren(this);
}

FaParser::TypeWrapVar3Context* FaParser::typeWrapVar3() {
  TypeWrapVar3Context *_localctx = _tracker.createInstance<TypeWrapVar3Context>(_ctx, getState());
  enterRule(_localctx, 100, FaParser::RuleTypeWrapVar3);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(469);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      setState(468);
      typeWrap();
      break;
    }

    default:
      break;
    }
    setState(471);
    id();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeWrapVarList3Context ------------------------------------------------------------------

FaParser::TypeWrapVarList3Context::TypeWrapVarList3Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FaParser::TypeWrapVar3Context *> FaParser::TypeWrapVarList3Context::typeWrapVar3() {
  return getRuleContexts<FaParser::TypeWrapVar3Context>();
}

FaParser::TypeWrapVar3Context* FaParser::TypeWrapVarList3Context::typeWrapVar3(size_t i) {
  return getRuleContext<FaParser::TypeWrapVar3Context>(i);
}

std::vector<tree::TerminalNode *> FaParser::TypeWrapVarList3Context::Comma() {
  return getTokens(FaParser::Comma);
}

tree::TerminalNode* FaParser::TypeWrapVarList3Context::Comma(size_t i) {
  return getToken(FaParser::Comma, i);
}


size_t FaParser::TypeWrapVarList3Context::getRuleIndex() const {
  return FaParser::RuleTypeWrapVarList3;
}


antlrcpp::Any FaParser::TypeWrapVarList3Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitTypeWrapVarList3(this);
  else
    return visitor->visitChildren(this);
}

FaParser::TypeWrapVarList3Context* FaParser::typeWrapVarList3() {
  TypeWrapVarList3Context *_localctx = _tracker.createInstance<TypeWrapVarList3Context>(_ctx, getState());
  enterRule(_localctx, 102, FaParser::RuleTypeWrapVarList3);
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
    setState(473);
    typeWrapVar3();
    setState(478);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(474);
      match(FaParser::Comma);
      setState(475);
      typeWrapVar3();
      setState(480);
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

//----------------- QuotStmtPartContext ------------------------------------------------------------------

FaParser::QuotStmtPartContext::QuotStmtPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::QuotHuaLContext* FaParser::QuotStmtPartContext::quotHuaL() {
  return getRuleContext<FaParser::QuotHuaLContext>(0);
}

FaParser::QuotHuaRContext* FaParser::QuotStmtPartContext::quotHuaR() {
  return getRuleContext<FaParser::QuotHuaRContext>(0);
}

std::vector<FaParser::StmtContext *> FaParser::QuotStmtPartContext::stmt() {
  return getRuleContexts<FaParser::StmtContext>();
}

FaParser::StmtContext* FaParser::QuotStmtPartContext::stmt(size_t i) {
  return getRuleContext<FaParser::StmtContext>(i);
}


size_t FaParser::QuotStmtPartContext::getRuleIndex() const {
  return FaParser::RuleQuotStmtPart;
}


antlrcpp::Any FaParser::QuotStmtPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitQuotStmtPart(this);
  else
    return visitor->visitChildren(this);
}

FaParser::QuotStmtPartContext* FaParser::quotStmtPart() {
  QuotStmtPartContext *_localctx = _tracker.createInstance<QuotStmtPartContext>(_ctx, getState());
  enterRule(_localctx, 104, FaParser::RuleQuotStmtPart);

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
    setState(481);
    quotHuaL();
    setState(485);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(482);
        stmt(); 
      }
      setState(487);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    }
    setState(488);
    quotHuaR();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuotStmtExprContext ------------------------------------------------------------------

FaParser::QuotStmtExprContext::QuotStmtExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::QuotHuaLContext* FaParser::QuotStmtExprContext::quotHuaL() {
  return getRuleContext<FaParser::QuotHuaLContext>(0);
}

FaParser::ExprContext* FaParser::QuotStmtExprContext::expr() {
  return getRuleContext<FaParser::ExprContext>(0);
}

FaParser::QuotHuaRContext* FaParser::QuotStmtExprContext::quotHuaR() {
  return getRuleContext<FaParser::QuotHuaRContext>(0);
}

std::vector<FaParser::StmtContext *> FaParser::QuotStmtExprContext::stmt() {
  return getRuleContexts<FaParser::StmtContext>();
}

FaParser::StmtContext* FaParser::QuotStmtExprContext::stmt(size_t i) {
  return getRuleContext<FaParser::StmtContext>(i);
}


size_t FaParser::QuotStmtExprContext::getRuleIndex() const {
  return FaParser::RuleQuotStmtExpr;
}


antlrcpp::Any FaParser::QuotStmtExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitQuotStmtExpr(this);
  else
    return visitor->visitChildren(this);
}

FaParser::QuotStmtExprContext* FaParser::quotStmtExpr() {
  QuotStmtExprContext *_localctx = _tracker.createInstance<QuotStmtExprContext>(_ctx, getState());
  enterRule(_localctx, 106, FaParser::RuleQuotStmtExpr);

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
    setState(490);
    quotHuaL();
    setState(494);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(491);
        stmt(); 
      }
      setState(496);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    }
    setState(497);
    expr();
    setState(498);
    quotHuaR();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStmtContext ------------------------------------------------------------------

FaParser::IfStmtContext::IfStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FaParser::IfStmtContext::If() {
  return getTokens(FaParser::If);
}

tree::TerminalNode* FaParser::IfStmtContext::If(size_t i) {
  return getToken(FaParser::If, i);
}

std::vector<FaParser::ExprContext *> FaParser::IfStmtContext::expr() {
  return getRuleContexts<FaParser::ExprContext>();
}

FaParser::ExprContext* FaParser::IfStmtContext::expr(size_t i) {
  return getRuleContext<FaParser::ExprContext>(i);
}

std::vector<FaParser::QuotStmtPartContext *> FaParser::IfStmtContext::quotStmtPart() {
  return getRuleContexts<FaParser::QuotStmtPartContext>();
}

FaParser::QuotStmtPartContext* FaParser::IfStmtContext::quotStmtPart(size_t i) {
  return getRuleContext<FaParser::QuotStmtPartContext>(i);
}

std::vector<tree::TerminalNode *> FaParser::IfStmtContext::Else() {
  return getTokens(FaParser::Else);
}

tree::TerminalNode* FaParser::IfStmtContext::Else(size_t i) {
  return getToken(FaParser::Else, i);
}


size_t FaParser::IfStmtContext::getRuleIndex() const {
  return FaParser::RuleIfStmt;
}


antlrcpp::Any FaParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}

FaParser::IfStmtContext* FaParser::ifStmt() {
  IfStmtContext *_localctx = _tracker.createInstance<IfStmtContext>(_ctx, getState());
  enterRule(_localctx, 108, FaParser::RuleIfStmt);
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
    enterOuterAlt(_localctx, 1);
    setState(500);
    match(FaParser::If);
    setState(501);
    expr();
    setState(502);
    quotStmtPart();
    setState(510);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(503);
        match(FaParser::Else);
        setState(504);
        match(FaParser::If);
        setState(505);
        expr();
        setState(506);
        quotStmtPart(); 
      }
      setState(512);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    }
    setState(515);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Else) {
      setState(513);
      match(FaParser::Else);
      setState(514);
      quotStmtPart();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfExprContext ------------------------------------------------------------------

FaParser::IfExprContext::IfExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FaParser::IfExprContext::If() {
  return getTokens(FaParser::If);
}

tree::TerminalNode* FaParser::IfExprContext::If(size_t i) {
  return getToken(FaParser::If, i);
}

std::vector<FaParser::ExprContext *> FaParser::IfExprContext::expr() {
  return getRuleContexts<FaParser::ExprContext>();
}

FaParser::ExprContext* FaParser::IfExprContext::expr(size_t i) {
  return getRuleContext<FaParser::ExprContext>(i);
}

std::vector<FaParser::QuotStmtExprContext *> FaParser::IfExprContext::quotStmtExpr() {
  return getRuleContexts<FaParser::QuotStmtExprContext>();
}

FaParser::QuotStmtExprContext* FaParser::IfExprContext::quotStmtExpr(size_t i) {
  return getRuleContext<FaParser::QuotStmtExprContext>(i);
}

std::vector<tree::TerminalNode *> FaParser::IfExprContext::Else() {
  return getTokens(FaParser::Else);
}

tree::TerminalNode* FaParser::IfExprContext::Else(size_t i) {
  return getToken(FaParser::Else, i);
}


size_t FaParser::IfExprContext::getRuleIndex() const {
  return FaParser::RuleIfExpr;
}


antlrcpp::Any FaParser::IfExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitIfExpr(this);
  else
    return visitor->visitChildren(this);
}

FaParser::IfExprContext* FaParser::ifExpr() {
  IfExprContext *_localctx = _tracker.createInstance<IfExprContext>(_ctx, getState());
  enterRule(_localctx, 110, FaParser::RuleIfExpr);

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
    setState(517);
    match(FaParser::If);
    setState(518);
    expr();
    setState(519);
    quotStmtExpr();
    setState(527);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(520);
        match(FaParser::Else);
        setState(521);
        match(FaParser::If);
        setState(522);
        expr();
        setState(523);
        quotStmtExpr(); 
      }
      setState(529);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
    }
    setState(530);
    match(FaParser::Else);
    setState(531);
    quotStmtExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStmtContext ------------------------------------------------------------------

FaParser::WhileStmtContext::WhileStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::WhileStmtContext::While() {
  return getToken(FaParser::While, 0);
}

FaParser::ExprContext* FaParser::WhileStmtContext::expr() {
  return getRuleContext<FaParser::ExprContext>(0);
}

FaParser::QuotHuaLContext* FaParser::WhileStmtContext::quotHuaL() {
  return getRuleContext<FaParser::QuotHuaLContext>(0);
}

FaParser::QuotHuaRContext* FaParser::WhileStmtContext::quotHuaR() {
  return getRuleContext<FaParser::QuotHuaRContext>(0);
}

std::vector<FaParser::StmtContext *> FaParser::WhileStmtContext::stmt() {
  return getRuleContexts<FaParser::StmtContext>();
}

FaParser::StmtContext* FaParser::WhileStmtContext::stmt(size_t i) {
  return getRuleContext<FaParser::StmtContext>(i);
}


size_t FaParser::WhileStmtContext::getRuleIndex() const {
  return FaParser::RuleWhileStmt;
}


antlrcpp::Any FaParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitWhileStmt(this);
  else
    return visitor->visitChildren(this);
}

FaParser::WhileStmtContext* FaParser::whileStmt() {
  WhileStmtContext *_localctx = _tracker.createInstance<WhileStmtContext>(_ctx, getState());
  enterRule(_localctx, 112, FaParser::RuleWhileStmt);

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
    setState(533);
    match(FaParser::While);
    setState(534);
    expr();
    setState(535);
    quotHuaL();
    setState(539);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(536);
        stmt(); 
      }
      setState(541);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    }
    setState(542);
    quotHuaR();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStmt2Context ------------------------------------------------------------------

FaParser::WhileStmt2Context::WhileStmt2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::WhileStmt2Context::Do() {
  return getToken(FaParser::Do, 0);
}

FaParser::QuotHuaLContext* FaParser::WhileStmt2Context::quotHuaL() {
  return getRuleContext<FaParser::QuotHuaLContext>(0);
}

FaParser::QuotHuaRContext* FaParser::WhileStmt2Context::quotHuaR() {
  return getRuleContext<FaParser::QuotHuaRContext>(0);
}

tree::TerminalNode* FaParser::WhileStmt2Context::While() {
  return getToken(FaParser::While, 0);
}

FaParser::ExprContext* FaParser::WhileStmt2Context::expr() {
  return getRuleContext<FaParser::ExprContext>(0);
}

std::vector<FaParser::StmtContext *> FaParser::WhileStmt2Context::stmt() {
  return getRuleContexts<FaParser::StmtContext>();
}

FaParser::StmtContext* FaParser::WhileStmt2Context::stmt(size_t i) {
  return getRuleContext<FaParser::StmtContext>(i);
}


size_t FaParser::WhileStmt2Context::getRuleIndex() const {
  return FaParser::RuleWhileStmt2;
}


antlrcpp::Any FaParser::WhileStmt2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitWhileStmt2(this);
  else
    return visitor->visitChildren(this);
}

FaParser::WhileStmt2Context* FaParser::whileStmt2() {
  WhileStmt2Context *_localctx = _tracker.createInstance<WhileStmt2Context>(_ctx, getState());
  enterRule(_localctx, 114, FaParser::RuleWhileStmt2);

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
    setState(544);
    match(FaParser::Do);
    setState(545);
    quotHuaL();
    setState(549);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(546);
        stmt(); 
      }
      setState(551);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    }
    setState(552);
    quotHuaR();
    setState(553);
    match(FaParser::While);
    setState(554);
    expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStmtContext ------------------------------------------------------------------

FaParser::ForStmtContext::ForStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::ForStmtContext::For() {
  return getToken(FaParser::For, 0);
}

std::vector<FaParser::StmtContext *> FaParser::ForStmtContext::stmt() {
  return getRuleContexts<FaParser::StmtContext>();
}

FaParser::StmtContext* FaParser::ForStmtContext::stmt(size_t i) {
  return getRuleContext<FaParser::StmtContext>(i);
}

std::vector<FaParser::ExprContext *> FaParser::ForStmtContext::expr() {
  return getRuleContexts<FaParser::ExprContext>();
}

FaParser::ExprContext* FaParser::ForStmtContext::expr(size_t i) {
  return getRuleContext<FaParser::ExprContext>(i);
}

tree::TerminalNode* FaParser::ForStmtContext::Semi() {
  return getToken(FaParser::Semi, 0);
}

FaParser::QuotHuaLContext* FaParser::ForStmtContext::quotHuaL() {
  return getRuleContext<FaParser::QuotHuaLContext>(0);
}

FaParser::QuotHuaRContext* FaParser::ForStmtContext::quotHuaR() {
  return getRuleContext<FaParser::QuotHuaRContext>(0);
}

std::vector<tree::TerminalNode *> FaParser::ForStmtContext::Comma() {
  return getTokens(FaParser::Comma);
}

tree::TerminalNode* FaParser::ForStmtContext::Comma(size_t i) {
  return getToken(FaParser::Comma, i);
}


size_t FaParser::ForStmtContext::getRuleIndex() const {
  return FaParser::RuleForStmt;
}


antlrcpp::Any FaParser::ForStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitForStmt(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ForStmtContext* FaParser::forStmt() {
  ForStmtContext *_localctx = _tracker.createInstance<ForStmtContext>(_ctx, getState());
  enterRule(_localctx, 116, FaParser::RuleForStmt);
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
    enterOuterAlt(_localctx, 1);
    setState(556);
    match(FaParser::For);
    setState(557);
    stmt();
    setState(558);
    expr();
    setState(559);
    match(FaParser::Semi);
    setState(568);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::T__0)
      | (1ULL << FaParser::T__6)
      | (1ULL << FaParser::If)
      | (1ULL << FaParser::New)
      | (1ULL << FaParser::Switch)
      | (1ULL << FaParser::ReverseOp)
      | (1ULL << FaParser::AddAddOp)
      | (1ULL << FaParser::SubSubOp)
      | (1ULL << FaParser::Exclam)
      | (1ULL << FaParser::SubOp))) != 0) || ((((_la - 76) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 76)) & ((1ULL << (FaParser::ColonColon - 76))
      | (1ULL << (FaParser::Underline - 76))
      | (1ULL << (FaParser::BoolLiteral - 76))
      | (1ULL << (FaParser::IntLiteral - 76))
      | (1ULL << (FaParser::FloatLiteral - 76))
      | (1ULL << (FaParser::String1Literal - 76))
      | (1ULL << (FaParser::RawId - 76)))) != 0)) {
      setState(560);
      expr();
      setState(565);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FaParser::Comma) {
        setState(561);
        match(FaParser::Comma);
        setState(562);
        expr();
        setState(567);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(570);
    quotHuaL();
    setState(574);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(571);
        stmt(); 
      }
      setState(576);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
    }
    setState(577);
    quotHuaR();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStmt2Context ------------------------------------------------------------------

FaParser::ForStmt2Context::ForStmt2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::ForStmt2Context::For() {
  return getToken(FaParser::For, 0);
}

FaParser::TypeContext* FaParser::ForStmt2Context::type() {
  return getRuleContext<FaParser::TypeContext>(0);
}

FaParser::IdContext* FaParser::ForStmt2Context::id() {
  return getRuleContext<FaParser::IdContext>(0);
}

tree::TerminalNode* FaParser::ForStmt2Context::Colon() {
  return getToken(FaParser::Colon, 0);
}

FaParser::ExprContext* FaParser::ForStmt2Context::expr() {
  return getRuleContext<FaParser::ExprContext>(0);
}

FaParser::QuotHuaLContext* FaParser::ForStmt2Context::quotHuaL() {
  return getRuleContext<FaParser::QuotHuaLContext>(0);
}

FaParser::QuotHuaRContext* FaParser::ForStmt2Context::quotHuaR() {
  return getRuleContext<FaParser::QuotHuaRContext>(0);
}

std::vector<FaParser::StmtContext *> FaParser::ForStmt2Context::stmt() {
  return getRuleContexts<FaParser::StmtContext>();
}

FaParser::StmtContext* FaParser::ForStmt2Context::stmt(size_t i) {
  return getRuleContext<FaParser::StmtContext>(i);
}


size_t FaParser::ForStmt2Context::getRuleIndex() const {
  return FaParser::RuleForStmt2;
}


antlrcpp::Any FaParser::ForStmt2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitForStmt2(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ForStmt2Context* FaParser::forStmt2() {
  ForStmt2Context *_localctx = _tracker.createInstance<ForStmt2Context>(_ctx, getState());
  enterRule(_localctx, 118, FaParser::RuleForStmt2);

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
    setState(579);
    match(FaParser::For);
    setState(580);
    type();
    setState(581);
    id();
    setState(582);
    match(FaParser::Colon);
    setState(583);
    expr();
    setState(584);
    quotHuaL();
    setState(588);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(585);
        stmt(); 
      }
      setState(590);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
    }
    setState(591);
    quotHuaR();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchStmtPart2LastContext ------------------------------------------------------------------

FaParser::SwitchStmtPart2LastContext::SwitchStmtPart2LastContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::SwitchStmtPart2LastContext::Underline() {
  return getToken(FaParser::Underline, 0);
}

FaParser::ExprFuncDefContext* FaParser::SwitchStmtPart2LastContext::exprFuncDef() {
  return getRuleContext<FaParser::ExprFuncDefContext>(0);
}

FaParser::StmtContext* FaParser::SwitchStmtPart2LastContext::stmt() {
  return getRuleContext<FaParser::StmtContext>(0);
}


size_t FaParser::SwitchStmtPart2LastContext::getRuleIndex() const {
  return FaParser::RuleSwitchStmtPart2Last;
}


antlrcpp::Any FaParser::SwitchStmtPart2LastContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitSwitchStmtPart2Last(this);
  else
    return visitor->visitChildren(this);
}

FaParser::SwitchStmtPart2LastContext* FaParser::switchStmtPart2Last() {
  SwitchStmtPart2LastContext *_localctx = _tracker.createInstance<SwitchStmtPart2LastContext>(_ctx, getState());
  enterRule(_localctx, 120, FaParser::RuleSwitchStmtPart2Last);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(593);
    match(FaParser::Underline);
    setState(594);
    exprFuncDef();
    setState(595);
    stmt();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuotStmtExprWrapContext ------------------------------------------------------------------

FaParser::QuotStmtExprWrapContext::QuotStmtExprWrapContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::QuotStmtExprContext* FaParser::QuotStmtExprWrapContext::quotStmtExpr() {
  return getRuleContext<FaParser::QuotStmtExprContext>(0);
}

FaParser::ExprContext* FaParser::QuotStmtExprWrapContext::expr() {
  return getRuleContext<FaParser::ExprContext>(0);
}


size_t FaParser::QuotStmtExprWrapContext::getRuleIndex() const {
  return FaParser::RuleQuotStmtExprWrap;
}


antlrcpp::Any FaParser::QuotStmtExprWrapContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitQuotStmtExprWrap(this);
  else
    return visitor->visitChildren(this);
}

FaParser::QuotStmtExprWrapContext* FaParser::quotStmtExprWrap() {
  QuotStmtExprWrapContext *_localctx = _tracker.createInstance<QuotStmtExprWrapContext>(_ctx, getState());
  enterRule(_localctx, 122, FaParser::RuleQuotStmtExprWrap);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(599);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::T__4: {
        enterOuterAlt(_localctx, 1);
        setState(597);
        quotStmtExpr();
        break;
      }

      case FaParser::T__0:
      case FaParser::T__6:
      case FaParser::If:
      case FaParser::New:
      case FaParser::Switch:
      case FaParser::ReverseOp:
      case FaParser::AddAddOp:
      case FaParser::SubSubOp:
      case FaParser::Exclam:
      case FaParser::SubOp:
      case FaParser::ColonColon:
      case FaParser::Underline:
      case FaParser::BoolLiteral:
      case FaParser::IntLiteral:
      case FaParser::FloatLiteral:
      case FaParser::String1Literal:
      case FaParser::RawId: {
        enterOuterAlt(_localctx, 2);
        setState(598);
        expr();
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

//----------------- SwitchExprPartLastContext ------------------------------------------------------------------

FaParser::SwitchExprPartLastContext::SwitchExprPartLastContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::SwitchExprPartLastContext::Underline() {
  return getToken(FaParser::Underline, 0);
}

FaParser::ExprFuncDefContext* FaParser::SwitchExprPartLastContext::exprFuncDef() {
  return getRuleContext<FaParser::ExprFuncDefContext>(0);
}

FaParser::QuotStmtExprWrapContext* FaParser::SwitchExprPartLastContext::quotStmtExprWrap() {
  return getRuleContext<FaParser::QuotStmtExprWrapContext>(0);
}

tree::TerminalNode* FaParser::SwitchExprPartLastContext::Comma() {
  return getToken(FaParser::Comma, 0);
}


size_t FaParser::SwitchExprPartLastContext::getRuleIndex() const {
  return FaParser::RuleSwitchExprPartLast;
}


antlrcpp::Any FaParser::SwitchExprPartLastContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitSwitchExprPartLast(this);
  else
    return visitor->visitChildren(this);
}

FaParser::SwitchExprPartLastContext* FaParser::switchExprPartLast() {
  SwitchExprPartLastContext *_localctx = _tracker.createInstance<SwitchExprPartLastContext>(_ctx, getState());
  enterRule(_localctx, 124, FaParser::RuleSwitchExprPartLast);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(601);
    match(FaParser::Underline);
    setState(602);
    exprFuncDef();
    setState(603);
    quotStmtExprWrap();
    setState(604);
    match(FaParser::Comma);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchStmtPartContext ------------------------------------------------------------------

FaParser::SwitchStmtPartContext::SwitchStmtPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FaParser::ExprContext *> FaParser::SwitchStmtPartContext::expr() {
  return getRuleContexts<FaParser::ExprContext>();
}

FaParser::ExprContext* FaParser::SwitchStmtPartContext::expr(size_t i) {
  return getRuleContext<FaParser::ExprContext>(i);
}

FaParser::ExprFuncDefContext* FaParser::SwitchStmtPartContext::exprFuncDef() {
  return getRuleContext<FaParser::ExprFuncDefContext>(0);
}

FaParser::StmtContext* FaParser::SwitchStmtPartContext::stmt() {
  return getRuleContext<FaParser::StmtContext>(0);
}

tree::TerminalNode* FaParser::SwitchStmtPartContext::When() {
  return getToken(FaParser::When, 0);
}


size_t FaParser::SwitchStmtPartContext::getRuleIndex() const {
  return FaParser::RuleSwitchStmtPart;
}


antlrcpp::Any FaParser::SwitchStmtPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitSwitchStmtPart(this);
  else
    return visitor->visitChildren(this);
}

FaParser::SwitchStmtPartContext* FaParser::switchStmtPart() {
  SwitchStmtPartContext *_localctx = _tracker.createInstance<SwitchStmtPartContext>(_ctx, getState());
  enterRule(_localctx, 126, FaParser::RuleSwitchStmtPart);
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
    setState(606);
    expr();
    setState(609);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::When) {
      setState(607);
      match(FaParser::When);
      setState(608);
      expr();
    }
    setState(611);
    exprFuncDef();
    setState(612);
    stmt();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchStmtContext ------------------------------------------------------------------

FaParser::SwitchStmtContext::SwitchStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::SwitchStmtContext::Switch() {
  return getToken(FaParser::Switch, 0);
}

FaParser::ExprContext* FaParser::SwitchStmtContext::expr() {
  return getRuleContext<FaParser::ExprContext>(0);
}

FaParser::QuotHuaLContext* FaParser::SwitchStmtContext::quotHuaL() {
  return getRuleContext<FaParser::QuotHuaLContext>(0);
}

FaParser::QuotHuaRContext* FaParser::SwitchStmtContext::quotHuaR() {
  return getRuleContext<FaParser::QuotHuaRContext>(0);
}

std::vector<FaParser::SwitchStmtPartContext *> FaParser::SwitchStmtContext::switchStmtPart() {
  return getRuleContexts<FaParser::SwitchStmtPartContext>();
}

FaParser::SwitchStmtPartContext* FaParser::SwitchStmtContext::switchStmtPart(size_t i) {
  return getRuleContext<FaParser::SwitchStmtPartContext>(i);
}


size_t FaParser::SwitchStmtContext::getRuleIndex() const {
  return FaParser::RuleSwitchStmt;
}


antlrcpp::Any FaParser::SwitchStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitSwitchStmt(this);
  else
    return visitor->visitChildren(this);
}

FaParser::SwitchStmtContext* FaParser::switchStmt() {
  SwitchStmtContext *_localctx = _tracker.createInstance<SwitchStmtContext>(_ctx, getState());
  enterRule(_localctx, 128, FaParser::RuleSwitchStmt);
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
    setState(614);
    match(FaParser::Switch);
    setState(615);
    expr();
    setState(616);
    quotHuaL();
    setState(620);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::T__0)
      | (1ULL << FaParser::T__6)
      | (1ULL << FaParser::If)
      | (1ULL << FaParser::New)
      | (1ULL << FaParser::Switch)
      | (1ULL << FaParser::ReverseOp)
      | (1ULL << FaParser::AddAddOp)
      | (1ULL << FaParser::SubSubOp)
      | (1ULL << FaParser::Exclam)
      | (1ULL << FaParser::SubOp))) != 0) || ((((_la - 76) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 76)) & ((1ULL << (FaParser::ColonColon - 76))
      | (1ULL << (FaParser::Underline - 76))
      | (1ULL << (FaParser::BoolLiteral - 76))
      | (1ULL << (FaParser::IntLiteral - 76))
      | (1ULL << (FaParser::FloatLiteral - 76))
      | (1ULL << (FaParser::String1Literal - 76))
      | (1ULL << (FaParser::RawId - 76)))) != 0)) {
      setState(617);
      switchStmtPart();
      setState(622);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(623);
    quotHuaR();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchStmtPart2Context ------------------------------------------------------------------

FaParser::SwitchStmtPart2Context::SwitchStmtPart2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::SwitchStmtPart2Context::When() {
  return getToken(FaParser::When, 0);
}

FaParser::ExprContext* FaParser::SwitchStmtPart2Context::expr() {
  return getRuleContext<FaParser::ExprContext>(0);
}

FaParser::ExprFuncDefContext* FaParser::SwitchStmtPart2Context::exprFuncDef() {
  return getRuleContext<FaParser::ExprFuncDefContext>(0);
}

FaParser::StmtContext* FaParser::SwitchStmtPart2Context::stmt() {
  return getRuleContext<FaParser::StmtContext>(0);
}


size_t FaParser::SwitchStmtPart2Context::getRuleIndex() const {
  return FaParser::RuleSwitchStmtPart2;
}


antlrcpp::Any FaParser::SwitchStmtPart2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitSwitchStmtPart2(this);
  else
    return visitor->visitChildren(this);
}

FaParser::SwitchStmtPart2Context* FaParser::switchStmtPart2() {
  SwitchStmtPart2Context *_localctx = _tracker.createInstance<SwitchStmtPart2Context>(_ctx, getState());
  enterRule(_localctx, 130, FaParser::RuleSwitchStmtPart2);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(625);
    match(FaParser::When);
    setState(626);
    expr();
    setState(627);
    exprFuncDef();
    setState(628);
    stmt();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchStmt2Context ------------------------------------------------------------------

FaParser::SwitchStmt2Context::SwitchStmt2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::SwitchStmt2Context::Switch() {
  return getToken(FaParser::Switch, 0);
}

FaParser::QuotHuaLContext* FaParser::SwitchStmt2Context::quotHuaL() {
  return getRuleContext<FaParser::QuotHuaLContext>(0);
}

FaParser::SwitchStmtPart2LastContext* FaParser::SwitchStmt2Context::switchStmtPart2Last() {
  return getRuleContext<FaParser::SwitchStmtPart2LastContext>(0);
}

FaParser::QuotHuaRContext* FaParser::SwitchStmt2Context::quotHuaR() {
  return getRuleContext<FaParser::QuotHuaRContext>(0);
}

std::vector<FaParser::SwitchStmtPart2Context *> FaParser::SwitchStmt2Context::switchStmtPart2() {
  return getRuleContexts<FaParser::SwitchStmtPart2Context>();
}

FaParser::SwitchStmtPart2Context* FaParser::SwitchStmt2Context::switchStmtPart2(size_t i) {
  return getRuleContext<FaParser::SwitchStmtPart2Context>(i);
}


size_t FaParser::SwitchStmt2Context::getRuleIndex() const {
  return FaParser::RuleSwitchStmt2;
}


antlrcpp::Any FaParser::SwitchStmt2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitSwitchStmt2(this);
  else
    return visitor->visitChildren(this);
}

FaParser::SwitchStmt2Context* FaParser::switchStmt2() {
  SwitchStmt2Context *_localctx = _tracker.createInstance<SwitchStmt2Context>(_ctx, getState());
  enterRule(_localctx, 132, FaParser::RuleSwitchStmt2);
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
    setState(630);
    match(FaParser::Switch);
    setState(631);
    quotHuaL();
    setState(635);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::When) {
      setState(632);
      switchStmtPart2();
      setState(637);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(638);
    switchStmtPart2Last();
    setState(639);
    quotHuaR();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchExprPartContext ------------------------------------------------------------------

FaParser::SwitchExprPartContext::SwitchExprPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FaParser::ExprContext *> FaParser::SwitchExprPartContext::expr() {
  return getRuleContexts<FaParser::ExprContext>();
}

FaParser::ExprContext* FaParser::SwitchExprPartContext::expr(size_t i) {
  return getRuleContext<FaParser::ExprContext>(i);
}

FaParser::ExprFuncDefContext* FaParser::SwitchExprPartContext::exprFuncDef() {
  return getRuleContext<FaParser::ExprFuncDefContext>(0);
}

FaParser::QuotStmtExprWrapContext* FaParser::SwitchExprPartContext::quotStmtExprWrap() {
  return getRuleContext<FaParser::QuotStmtExprWrapContext>(0);
}

tree::TerminalNode* FaParser::SwitchExprPartContext::Comma() {
  return getToken(FaParser::Comma, 0);
}

tree::TerminalNode* FaParser::SwitchExprPartContext::When() {
  return getToken(FaParser::When, 0);
}


size_t FaParser::SwitchExprPartContext::getRuleIndex() const {
  return FaParser::RuleSwitchExprPart;
}


antlrcpp::Any FaParser::SwitchExprPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitSwitchExprPart(this);
  else
    return visitor->visitChildren(this);
}

FaParser::SwitchExprPartContext* FaParser::switchExprPart() {
  SwitchExprPartContext *_localctx = _tracker.createInstance<SwitchExprPartContext>(_ctx, getState());
  enterRule(_localctx, 134, FaParser::RuleSwitchExprPart);
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
    setState(641);
    expr();
    setState(644);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::When) {
      setState(642);
      match(FaParser::When);
      setState(643);
      expr();
    }
    setState(646);
    exprFuncDef();
    setState(647);
    quotStmtExprWrap();
    setState(648);
    match(FaParser::Comma);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchExprContext ------------------------------------------------------------------

FaParser::SwitchExprContext::SwitchExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::SwitchExprContext::Switch() {
  return getToken(FaParser::Switch, 0);
}

FaParser::ExprContext* FaParser::SwitchExprContext::expr() {
  return getRuleContext<FaParser::ExprContext>(0);
}

FaParser::QuotHuaLContext* FaParser::SwitchExprContext::quotHuaL() {
  return getRuleContext<FaParser::QuotHuaLContext>(0);
}

FaParser::SwitchExprPartLastContext* FaParser::SwitchExprContext::switchExprPartLast() {
  return getRuleContext<FaParser::SwitchExprPartLastContext>(0);
}

FaParser::QuotHuaRContext* FaParser::SwitchExprContext::quotHuaR() {
  return getRuleContext<FaParser::QuotHuaRContext>(0);
}

std::vector<FaParser::SwitchExprPartContext *> FaParser::SwitchExprContext::switchExprPart() {
  return getRuleContexts<FaParser::SwitchExprPartContext>();
}

FaParser::SwitchExprPartContext* FaParser::SwitchExprContext::switchExprPart(size_t i) {
  return getRuleContext<FaParser::SwitchExprPartContext>(i);
}


size_t FaParser::SwitchExprContext::getRuleIndex() const {
  return FaParser::RuleSwitchExpr;
}


antlrcpp::Any FaParser::SwitchExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitSwitchExpr(this);
  else
    return visitor->visitChildren(this);
}

FaParser::SwitchExprContext* FaParser::switchExpr() {
  SwitchExprContext *_localctx = _tracker.createInstance<SwitchExprContext>(_ctx, getState());
  enterRule(_localctx, 136, FaParser::RuleSwitchExpr);

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
    setState(650);
    match(FaParser::Switch);
    setState(651);
    expr();
    setState(652);
    quotHuaL();
    setState(656);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(653);
        switchExprPart(); 
      }
      setState(658);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx);
    }
    setState(659);
    switchExprPartLast();
    setState(660);
    quotHuaR();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchExprPart2Context ------------------------------------------------------------------

FaParser::SwitchExprPart2Context::SwitchExprPart2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::SwitchExprPart2Context::When() {
  return getToken(FaParser::When, 0);
}

FaParser::ExprContext* FaParser::SwitchExprPart2Context::expr() {
  return getRuleContext<FaParser::ExprContext>(0);
}

FaParser::ExprFuncDefContext* FaParser::SwitchExprPart2Context::exprFuncDef() {
  return getRuleContext<FaParser::ExprFuncDefContext>(0);
}

FaParser::QuotStmtExprWrapContext* FaParser::SwitchExprPart2Context::quotStmtExprWrap() {
  return getRuleContext<FaParser::QuotStmtExprWrapContext>(0);
}

tree::TerminalNode* FaParser::SwitchExprPart2Context::Comma() {
  return getToken(FaParser::Comma, 0);
}


size_t FaParser::SwitchExprPart2Context::getRuleIndex() const {
  return FaParser::RuleSwitchExprPart2;
}


antlrcpp::Any FaParser::SwitchExprPart2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitSwitchExprPart2(this);
  else
    return visitor->visitChildren(this);
}

FaParser::SwitchExprPart2Context* FaParser::switchExprPart2() {
  SwitchExprPart2Context *_localctx = _tracker.createInstance<SwitchExprPart2Context>(_ctx, getState());
  enterRule(_localctx, 138, FaParser::RuleSwitchExprPart2);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(662);
    match(FaParser::When);
    setState(663);
    expr();
    setState(664);
    exprFuncDef();
    setState(665);
    quotStmtExprWrap();
    setState(666);
    match(FaParser::Comma);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchExpr2Context ------------------------------------------------------------------

FaParser::SwitchExpr2Context::SwitchExpr2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::SwitchExpr2Context::Switch() {
  return getToken(FaParser::Switch, 0);
}

FaParser::QuotHuaLContext* FaParser::SwitchExpr2Context::quotHuaL() {
  return getRuleContext<FaParser::QuotHuaLContext>(0);
}

FaParser::SwitchExprPartLastContext* FaParser::SwitchExpr2Context::switchExprPartLast() {
  return getRuleContext<FaParser::SwitchExprPartLastContext>(0);
}

FaParser::QuotHuaRContext* FaParser::SwitchExpr2Context::quotHuaR() {
  return getRuleContext<FaParser::QuotHuaRContext>(0);
}

std::vector<FaParser::SwitchExprPart2Context *> FaParser::SwitchExpr2Context::switchExprPart2() {
  return getRuleContexts<FaParser::SwitchExprPart2Context>();
}

FaParser::SwitchExprPart2Context* FaParser::SwitchExpr2Context::switchExprPart2(size_t i) {
  return getRuleContext<FaParser::SwitchExprPart2Context>(i);
}


size_t FaParser::SwitchExpr2Context::getRuleIndex() const {
  return FaParser::RuleSwitchExpr2;
}


antlrcpp::Any FaParser::SwitchExpr2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitSwitchExpr2(this);
  else
    return visitor->visitChildren(this);
}

FaParser::SwitchExpr2Context* FaParser::switchExpr2() {
  SwitchExpr2Context *_localctx = _tracker.createInstance<SwitchExpr2Context>(_ctx, getState());
  enterRule(_localctx, 140, FaParser::RuleSwitchExpr2);
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
    setState(668);
    match(FaParser::Switch);
    setState(669);
    quotHuaL();
    setState(673);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::When) {
      setState(670);
      switchExprPart2();
      setState(675);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(676);
    switchExprPartLast();
    setState(677);
    quotHuaR();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuotExprContext ------------------------------------------------------------------

FaParser::QuotExprContext::QuotExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::QuotYuanLContext* FaParser::QuotExprContext::quotYuanL() {
  return getRuleContext<FaParser::QuotYuanLContext>(0);
}

FaParser::ExprContext* FaParser::QuotExprContext::expr() {
  return getRuleContext<FaParser::ExprContext>(0);
}

FaParser::QuotYuanRContext* FaParser::QuotExprContext::quotYuanR() {
  return getRuleContext<FaParser::QuotYuanRContext>(0);
}


size_t FaParser::QuotExprContext::getRuleIndex() const {
  return FaParser::RuleQuotExpr;
}


antlrcpp::Any FaParser::QuotExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitQuotExpr(this);
  else
    return visitor->visitChildren(this);
}

FaParser::QuotExprContext* FaParser::quotExpr() {
  QuotExprContext *_localctx = _tracker.createInstance<QuotExprContext>(_ctx, getState());
  enterRule(_localctx, 142, FaParser::RuleQuotExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(679);
    quotYuanL();
    setState(680);
    expr();
    setState(681);
    quotYuanR();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprOptContext ------------------------------------------------------------------

FaParser::ExprOptContext::ExprOptContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::ExprContext* FaParser::ExprOptContext::expr() {
  return getRuleContext<FaParser::ExprContext>(0);
}


size_t FaParser::ExprOptContext::getRuleIndex() const {
  return FaParser::RuleExprOpt;
}


antlrcpp::Any FaParser::ExprOptContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitExprOpt(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ExprOptContext* FaParser::exprOpt() {
  ExprOptContext *_localctx = _tracker.createInstance<ExprOptContext>(_ctx, getState());
  enterRule(_localctx, 144, FaParser::RuleExprOpt);
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
    setState(684);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::T__0)
      | (1ULL << FaParser::T__6)
      | (1ULL << FaParser::If)
      | (1ULL << FaParser::New)
      | (1ULL << FaParser::Switch)
      | (1ULL << FaParser::ReverseOp)
      | (1ULL << FaParser::AddAddOp)
      | (1ULL << FaParser::SubSubOp)
      | (1ULL << FaParser::Exclam)
      | (1ULL << FaParser::SubOp))) != 0) || ((((_la - 76) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 76)) & ((1ULL << (FaParser::ColonColon - 76))
      | (1ULL << (FaParser::Underline - 76))
      | (1ULL << (FaParser::BoolLiteral - 76))
      | (1ULL << (FaParser::IntLiteral - 76))
      | (1ULL << (FaParser::FloatLiteral - 76))
      | (1ULL << (FaParser::String1Literal - 76))
      | (1ULL << (FaParser::RawId - 76)))) != 0)) {
      setState(683);
      expr();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NewExprItemContext ------------------------------------------------------------------

FaParser::NewExprItemContext::NewExprItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::IdContext* FaParser::NewExprItemContext::id() {
  return getRuleContext<FaParser::IdContext>(0);
}

tree::TerminalNode* FaParser::NewExprItemContext::Assign() {
  return getToken(FaParser::Assign, 0);
}

FaParser::MiddleExprContext* FaParser::NewExprItemContext::middleExpr() {
  return getRuleContext<FaParser::MiddleExprContext>(0);
}


size_t FaParser::NewExprItemContext::getRuleIndex() const {
  return FaParser::RuleNewExprItem;
}


antlrcpp::Any FaParser::NewExprItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitNewExprItem(this);
  else
    return visitor->visitChildren(this);
}

FaParser::NewExprItemContext* FaParser::newExprItem() {
  NewExprItemContext *_localctx = _tracker.createInstance<NewExprItemContext>(_ctx, getState());
  enterRule(_localctx, 146, FaParser::RuleNewExprItem);
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
    setState(686);
    id();
    setState(689);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Assign) {
      setState(687);
      match(FaParser::Assign);
      setState(688);
      middleExpr();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NewExpr1Context ------------------------------------------------------------------

FaParser::NewExpr1Context::NewExpr1Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::NewExpr1Context::New() {
  return getToken(FaParser::New, 0);
}

FaParser::TypeSingleContext* FaParser::NewExpr1Context::typeSingle() {
  return getRuleContext<FaParser::TypeSingleContext>(0);
}

FaParser::QuotHuaLContext* FaParser::NewExpr1Context::quotHuaL() {
  return getRuleContext<FaParser::QuotHuaLContext>(0);
}

FaParser::QuotHuaRContext* FaParser::NewExpr1Context::quotHuaR() {
  return getRuleContext<FaParser::QuotHuaRContext>(0);
}

std::vector<FaParser::NewExprItemContext *> FaParser::NewExpr1Context::newExprItem() {
  return getRuleContexts<FaParser::NewExprItemContext>();
}

FaParser::NewExprItemContext* FaParser::NewExpr1Context::newExprItem(size_t i) {
  return getRuleContext<FaParser::NewExprItemContext>(i);
}

std::vector<tree::TerminalNode *> FaParser::NewExpr1Context::Comma() {
  return getTokens(FaParser::Comma);
}

tree::TerminalNode* FaParser::NewExpr1Context::Comma(size_t i) {
  return getToken(FaParser::Comma, i);
}


size_t FaParser::NewExpr1Context::getRuleIndex() const {
  return FaParser::RuleNewExpr1;
}


antlrcpp::Any FaParser::NewExpr1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitNewExpr1(this);
  else
    return visitor->visitChildren(this);
}

FaParser::NewExpr1Context* FaParser::newExpr1() {
  NewExpr1Context *_localctx = _tracker.createInstance<NewExpr1Context>(_ctx, getState());
  enterRule(_localctx, 148, FaParser::RuleNewExpr1);
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
    setState(691);
    match(FaParser::New);
    setState(692);
    typeSingle();
    setState(693);
    quotHuaL();
    setState(702);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Underline

    || _la == FaParser::RawId) {
      setState(694);
      newExprItem();
      setState(699);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FaParser::Comma) {
        setState(695);
        match(FaParser::Comma);
        setState(696);
        newExprItem();
        setState(701);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(704);
    quotHuaR();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NewExpr2Context ------------------------------------------------------------------

FaParser::NewExpr2Context::NewExpr2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::NewExpr2Context::New() {
  return getToken(FaParser::New, 0);
}

FaParser::TypeSingleContext* FaParser::NewExpr2Context::typeSingle() {
  return getRuleContext<FaParser::TypeSingleContext>(0);
}

FaParser::QuotYuanLContext* FaParser::NewExpr2Context::quotYuanL() {
  return getRuleContext<FaParser::QuotYuanLContext>(0);
}

FaParser::QuotYuanRContext* FaParser::NewExpr2Context::quotYuanR() {
  return getRuleContext<FaParser::QuotYuanRContext>(0);
}

std::vector<FaParser::ExprContext *> FaParser::NewExpr2Context::expr() {
  return getRuleContexts<FaParser::ExprContext>();
}

FaParser::ExprContext* FaParser::NewExpr2Context::expr(size_t i) {
  return getRuleContext<FaParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> FaParser::NewExpr2Context::Comma() {
  return getTokens(FaParser::Comma);
}

tree::TerminalNode* FaParser::NewExpr2Context::Comma(size_t i) {
  return getToken(FaParser::Comma, i);
}


size_t FaParser::NewExpr2Context::getRuleIndex() const {
  return FaParser::RuleNewExpr2;
}


antlrcpp::Any FaParser::NewExpr2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitNewExpr2(this);
  else
    return visitor->visitChildren(this);
}

FaParser::NewExpr2Context* FaParser::newExpr2() {
  NewExpr2Context *_localctx = _tracker.createInstance<NewExpr2Context>(_ctx, getState());
  enterRule(_localctx, 150, FaParser::RuleNewExpr2);
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
    setState(706);
    match(FaParser::New);
    setState(707);
    typeSingle();
    setState(708);
    quotYuanL();
    setState(717);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::T__0)
      | (1ULL << FaParser::T__6)
      | (1ULL << FaParser::If)
      | (1ULL << FaParser::New)
      | (1ULL << FaParser::Switch)
      | (1ULL << FaParser::ReverseOp)
      | (1ULL << FaParser::AddAddOp)
      | (1ULL << FaParser::SubSubOp)
      | (1ULL << FaParser::Exclam)
      | (1ULL << FaParser::SubOp))) != 0) || ((((_la - 76) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 76)) & ((1ULL << (FaParser::ColonColon - 76))
      | (1ULL << (FaParser::Underline - 76))
      | (1ULL << (FaParser::BoolLiteral - 76))
      | (1ULL << (FaParser::IntLiteral - 76))
      | (1ULL << (FaParser::FloatLiteral - 76))
      | (1ULL << (FaParser::String1Literal - 76))
      | (1ULL << (FaParser::RawId - 76)))) != 0)) {
      setState(709);
      expr();
      setState(714);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FaParser::Comma) {
        setState(710);
        match(FaParser::Comma);
        setState(711);
        expr();
        setState(716);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(719);
    quotYuanR();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayExpr1Context ------------------------------------------------------------------

FaParser::ArrayExpr1Context::ArrayExpr1Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::QuotFangLContext* FaParser::ArrayExpr1Context::quotFangL() {
  return getRuleContext<FaParser::QuotFangLContext>(0);
}

std::vector<FaParser::ExprContext *> FaParser::ArrayExpr1Context::expr() {
  return getRuleContexts<FaParser::ExprContext>();
}

FaParser::ExprContext* FaParser::ArrayExpr1Context::expr(size_t i) {
  return getRuleContext<FaParser::ExprContext>(i);
}

tree::TerminalNode* FaParser::ArrayExpr1Context::PointPoint() {
  return getToken(FaParser::PointPoint, 0);
}

FaParser::QuotFangRContext* FaParser::ArrayExpr1Context::quotFangR() {
  return getRuleContext<FaParser::QuotFangRContext>(0);
}

tree::TerminalNode* FaParser::ArrayExpr1Context::Step() {
  return getToken(FaParser::Step, 0);
}


size_t FaParser::ArrayExpr1Context::getRuleIndex() const {
  return FaParser::RuleArrayExpr1;
}


antlrcpp::Any FaParser::ArrayExpr1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitArrayExpr1(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ArrayExpr1Context* FaParser::arrayExpr1() {
  ArrayExpr1Context *_localctx = _tracker.createInstance<ArrayExpr1Context>(_ctx, getState());
  enterRule(_localctx, 152, FaParser::RuleArrayExpr1);
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
    setState(721);
    quotFangL();
    setState(722);
    expr();
    setState(723);
    match(FaParser::PointPoint);
    setState(724);
    expr();
    setState(727);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Step) {
      setState(725);
      match(FaParser::Step);
      setState(726);
      expr();
    }
    setState(729);
    quotFangR();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayExpr2Context ------------------------------------------------------------------

FaParser::ArrayExpr2Context::ArrayExpr2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::QuotFangLContext* FaParser::ArrayExpr2Context::quotFangL() {
  return getRuleContext<FaParser::QuotFangLContext>(0);
}

std::vector<FaParser::ExprContext *> FaParser::ArrayExpr2Context::expr() {
  return getRuleContexts<FaParser::ExprContext>();
}

FaParser::ExprContext* FaParser::ArrayExpr2Context::expr(size_t i) {
  return getRuleContext<FaParser::ExprContext>(i);
}

FaParser::QuotFangRContext* FaParser::ArrayExpr2Context::quotFangR() {
  return getRuleContext<FaParser::QuotFangRContext>(0);
}

std::vector<tree::TerminalNode *> FaParser::ArrayExpr2Context::Comma() {
  return getTokens(FaParser::Comma);
}

tree::TerminalNode* FaParser::ArrayExpr2Context::Comma(size_t i) {
  return getToken(FaParser::Comma, i);
}


size_t FaParser::ArrayExpr2Context::getRuleIndex() const {
  return FaParser::RuleArrayExpr2;
}


antlrcpp::Any FaParser::ArrayExpr2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitArrayExpr2(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ArrayExpr2Context* FaParser::arrayExpr2() {
  ArrayExpr2Context *_localctx = _tracker.createInstance<ArrayExpr2Context>(_ctx, getState());
  enterRule(_localctx, 154, FaParser::RuleArrayExpr2);
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
    setState(731);
    quotFangL();
    setState(732);
    expr();
    setState(737);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(733);
      match(FaParser::Comma);
      setState(734);
      expr();
      setState(739);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(740);
    quotFangR();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LambdaExprContext ------------------------------------------------------------------

FaParser::LambdaExprContext::LambdaExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::QuotYuanLContext* FaParser::LambdaExprContext::quotYuanL() {
  return getRuleContext<FaParser::QuotYuanLContext>(0);
}

FaParser::QuotYuanRContext* FaParser::LambdaExprContext::quotYuanR() {
  return getRuleContext<FaParser::QuotYuanRContext>(0);
}

FaParser::ExprFuncDefContext* FaParser::LambdaExprContext::exprFuncDef() {
  return getRuleContext<FaParser::ExprFuncDefContext>(0);
}

FaParser::ExprContext* FaParser::LambdaExprContext::expr() {
  return getRuleContext<FaParser::ExprContext>(0);
}

FaParser::TypeWrapVarList3Context* FaParser::LambdaExprContext::typeWrapVarList3() {
  return getRuleContext<FaParser::TypeWrapVarList3Context>(0);
}

FaParser::QuotHuaLContext* FaParser::LambdaExprContext::quotHuaL() {
  return getRuleContext<FaParser::QuotHuaLContext>(0);
}

FaParser::QuotHuaRContext* FaParser::LambdaExprContext::quotHuaR() {
  return getRuleContext<FaParser::QuotHuaRContext>(0);
}

std::vector<FaParser::StmtContext *> FaParser::LambdaExprContext::stmt() {
  return getRuleContexts<FaParser::StmtContext>();
}

FaParser::StmtContext* FaParser::LambdaExprContext::stmt(size_t i) {
  return getRuleContext<FaParser::StmtContext>(i);
}


size_t FaParser::LambdaExprContext::getRuleIndex() const {
  return FaParser::RuleLambdaExpr;
}


antlrcpp::Any FaParser::LambdaExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitLambdaExpr(this);
  else
    return visitor->visitChildren(this);
}

FaParser::LambdaExprContext* FaParser::lambdaExpr() {
  LambdaExprContext *_localctx = _tracker.createInstance<LambdaExprContext>(_ctx, getState());
  enterRule(_localctx, 156, FaParser::RuleLambdaExpr);
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
    enterOuterAlt(_localctx, 1);
    setState(742);
    quotYuanL();
    setState(744);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::T__6)
      | (1ULL << FaParser::Mut)
      | (1ULL << FaParser::Params))) != 0) || _la == FaParser::Underline

    || _la == FaParser::RawId) {
      setState(743);
      typeWrapVarList3();
    }
    setState(746);
    quotYuanR();
    setState(747);
    exprFuncDef();
    setState(758);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::T__0:
      case FaParser::T__6:
      case FaParser::If:
      case FaParser::New:
      case FaParser::Switch:
      case FaParser::ReverseOp:
      case FaParser::AddAddOp:
      case FaParser::SubSubOp:
      case FaParser::Exclam:
      case FaParser::SubOp:
      case FaParser::ColonColon:
      case FaParser::Underline:
      case FaParser::BoolLiteral:
      case FaParser::IntLiteral:
      case FaParser::FloatLiteral:
      case FaParser::String1Literal:
      case FaParser::RawId: {
        setState(748);
        expr();
        break;
      }

      case FaParser::T__4: {
        setState(749);
        quotHuaL();
        setState(753);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(750);
            stmt(); 
          }
          setState(755);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx);
        }
        setState(756);
        quotHuaR();
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

//----------------- StrongExprBaseContext ------------------------------------------------------------------

FaParser::StrongExprBaseContext::StrongExprBaseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::IdsContext* FaParser::StrongExprBaseContext::ids() {
  return getRuleContext<FaParser::IdsContext>(0);
}

tree::TerminalNode* FaParser::StrongExprBaseContext::ColonColon() {
  return getToken(FaParser::ColonColon, 0);
}

FaParser::LiteralContext* FaParser::StrongExprBaseContext::literal() {
  return getRuleContext<FaParser::LiteralContext>(0);
}

FaParser::IfExprContext* FaParser::StrongExprBaseContext::ifExpr() {
  return getRuleContext<FaParser::IfExprContext>(0);
}

FaParser::QuotExprContext* FaParser::StrongExprBaseContext::quotExpr() {
  return getRuleContext<FaParser::QuotExprContext>(0);
}

FaParser::NewExpr1Context* FaParser::StrongExprBaseContext::newExpr1() {
  return getRuleContext<FaParser::NewExpr1Context>(0);
}

FaParser::NewExpr2Context* FaParser::StrongExprBaseContext::newExpr2() {
  return getRuleContext<FaParser::NewExpr2Context>(0);
}

FaParser::ArrayExpr1Context* FaParser::StrongExprBaseContext::arrayExpr1() {
  return getRuleContext<FaParser::ArrayExpr1Context>(0);
}

FaParser::ArrayExpr2Context* FaParser::StrongExprBaseContext::arrayExpr2() {
  return getRuleContext<FaParser::ArrayExpr2Context>(0);
}

FaParser::SwitchExpr2Context* FaParser::StrongExprBaseContext::switchExpr2() {
  return getRuleContext<FaParser::SwitchExpr2Context>(0);
}

FaParser::SwitchExprContext* FaParser::StrongExprBaseContext::switchExpr() {
  return getRuleContext<FaParser::SwitchExprContext>(0);
}

FaParser::LambdaExprContext* FaParser::StrongExprBaseContext::lambdaExpr() {
  return getRuleContext<FaParser::LambdaExprContext>(0);
}


size_t FaParser::StrongExprBaseContext::getRuleIndex() const {
  return FaParser::RuleStrongExprBase;
}


antlrcpp::Any FaParser::StrongExprBaseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitStrongExprBase(this);
  else
    return visitor->visitChildren(this);
}

FaParser::StrongExprBaseContext* FaParser::strongExprBase() {
  StrongExprBaseContext *_localctx = _tracker.createInstance<StrongExprBaseContext>(_ctx, getState());
  enterRule(_localctx, 158, FaParser::RuleStrongExprBase);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(774);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(761);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == FaParser::ColonColon) {
        setState(760);
        match(FaParser::ColonColon);
      }
      setState(763);
      ids();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(764);
      literal();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(765);
      ifExpr();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(766);
      quotExpr();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(767);
      newExpr1();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(768);
      newExpr2();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(769);
      arrayExpr1();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(770);
      arrayExpr2();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(771);
      switchExpr2();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(772);
      switchExpr();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(773);
      lambdaExpr();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StrongExprPrefixContext ------------------------------------------------------------------

FaParser::StrongExprPrefixContext::StrongExprPrefixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::StrongExprPrefixContext::SubOp() {
  return getToken(FaParser::SubOp, 0);
}

tree::TerminalNode* FaParser::StrongExprPrefixContext::AddAddOp() {
  return getToken(FaParser::AddAddOp, 0);
}

tree::TerminalNode* FaParser::StrongExprPrefixContext::SubSubOp() {
  return getToken(FaParser::SubSubOp, 0);
}

tree::TerminalNode* FaParser::StrongExprPrefixContext::ReverseOp() {
  return getToken(FaParser::ReverseOp, 0);
}

tree::TerminalNode* FaParser::StrongExprPrefixContext::Exclam() {
  return getToken(FaParser::Exclam, 0);
}


size_t FaParser::StrongExprPrefixContext::getRuleIndex() const {
  return FaParser::RuleStrongExprPrefix;
}


antlrcpp::Any FaParser::StrongExprPrefixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitStrongExprPrefix(this);
  else
    return visitor->visitChildren(this);
}

FaParser::StrongExprPrefixContext* FaParser::strongExprPrefix() {
  StrongExprPrefixContext *_localctx = _tracker.createInstance<StrongExprPrefixContext>(_ctx, getState());
  enterRule(_localctx, 160, FaParser::RuleStrongExprPrefix);
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
    setState(776);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::ReverseOp)
      | (1ULL << FaParser::AddAddOp)
      | (1ULL << FaParser::SubSubOp)
      | (1ULL << FaParser::Exclam)
      | (1ULL << FaParser::SubOp))) != 0))) {
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

//----------------- StrongExprSuffixContext ------------------------------------------------------------------

FaParser::StrongExprSuffixContext::StrongExprSuffixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::StrongExprSuffixContext::AddAddOp() {
  return getToken(FaParser::AddAddOp, 0);
}

tree::TerminalNode* FaParser::StrongExprSuffixContext::SubSubOp() {
  return getToken(FaParser::SubSubOp, 0);
}

FaParser::QuotYuanLContext* FaParser::StrongExprSuffixContext::quotYuanL() {
  return getRuleContext<FaParser::QuotYuanLContext>(0);
}

FaParser::QuotYuanRContext* FaParser::StrongExprSuffixContext::quotYuanR() {
  return getRuleContext<FaParser::QuotYuanRContext>(0);
}

std::vector<FaParser::ExprContext *> FaParser::StrongExprSuffixContext::expr() {
  return getRuleContexts<FaParser::ExprContext>();
}

FaParser::ExprContext* FaParser::StrongExprSuffixContext::expr(size_t i) {
  return getRuleContext<FaParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> FaParser::StrongExprSuffixContext::Comma() {
  return getTokens(FaParser::Comma);
}

tree::TerminalNode* FaParser::StrongExprSuffixContext::Comma(size_t i) {
  return getToken(FaParser::Comma, i);
}

FaParser::QuotFangLContext* FaParser::StrongExprSuffixContext::quotFangL() {
  return getRuleContext<FaParser::QuotFangLContext>(0);
}

FaParser::QuotFangRContext* FaParser::StrongExprSuffixContext::quotFangR() {
  return getRuleContext<FaParser::QuotFangRContext>(0);
}

std::vector<FaParser::ExprOptContext *> FaParser::StrongExprSuffixContext::exprOpt() {
  return getRuleContexts<FaParser::ExprOptContext>();
}

FaParser::ExprOptContext* FaParser::StrongExprSuffixContext::exprOpt(size_t i) {
  return getRuleContext<FaParser::ExprOptContext>(i);
}

std::vector<tree::TerminalNode *> FaParser::StrongExprSuffixContext::Colon() {
  return getTokens(FaParser::Colon);
}

tree::TerminalNode* FaParser::StrongExprSuffixContext::Colon(size_t i) {
  return getToken(FaParser::Colon, i);
}

tree::TerminalNode* FaParser::StrongExprSuffixContext::PointOp() {
  return getToken(FaParser::PointOp, 0);
}

FaParser::IdContext* FaParser::StrongExprSuffixContext::id() {
  return getRuleContext<FaParser::IdContext>(0);
}

tree::TerminalNode* FaParser::StrongExprSuffixContext::Is() {
  return getToken(FaParser::Is, 0);
}

FaParser::IdsContext* FaParser::StrongExprSuffixContext::ids() {
  return getRuleContext<FaParser::IdsContext>(0);
}


size_t FaParser::StrongExprSuffixContext::getRuleIndex() const {
  return FaParser::RuleStrongExprSuffix;
}


antlrcpp::Any FaParser::StrongExprSuffixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitStrongExprSuffix(this);
  else
    return visitor->visitChildren(this);
}

FaParser::StrongExprSuffixContext* FaParser::strongExprSuffix() {
  StrongExprSuffixContext *_localctx = _tracker.createInstance<StrongExprSuffixContext>(_ctx, getState());
  enterRule(_localctx, 162, FaParser::RuleStrongExprSuffix);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(814);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::AddAddOp: {
        enterOuterAlt(_localctx, 1);
        setState(778);
        match(FaParser::AddAddOp);
        break;
      }

      case FaParser::SubSubOp: {
        enterOuterAlt(_localctx, 2);
        setState(779);
        match(FaParser::SubSubOp);
        break;
      }

      case FaParser::T__6: {
        enterOuterAlt(_localctx, 3);
        setState(780);
        quotYuanL();
        setState(789);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << FaParser::T__0)
          | (1ULL << FaParser::T__6)
          | (1ULL << FaParser::If)
          | (1ULL << FaParser::New)
          | (1ULL << FaParser::Switch)
          | (1ULL << FaParser::ReverseOp)
          | (1ULL << FaParser::AddAddOp)
          | (1ULL << FaParser::SubSubOp)
          | (1ULL << FaParser::Exclam)
          | (1ULL << FaParser::SubOp))) != 0) || ((((_la - 76) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 76)) & ((1ULL << (FaParser::ColonColon - 76))
          | (1ULL << (FaParser::Underline - 76))
          | (1ULL << (FaParser::BoolLiteral - 76))
          | (1ULL << (FaParser::IntLiteral - 76))
          | (1ULL << (FaParser::FloatLiteral - 76))
          | (1ULL << (FaParser::String1Literal - 76))
          | (1ULL << (FaParser::RawId - 76)))) != 0)) {
          setState(781);
          expr();
          setState(786);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == FaParser::Comma) {
            setState(782);
            match(FaParser::Comma);
            setState(783);
            expr();
            setState(788);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(791);
        quotYuanR();
        break;
      }

      case FaParser::T__0: {
        enterOuterAlt(_localctx, 4);
        setState(793);
        quotFangL();

        setState(794);
        exprOpt();
        setState(799);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == FaParser::Colon) {
          setState(795);
          match(FaParser::Colon);
          setState(796);
          exprOpt();
          setState(801);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(802);
        quotFangR();
        break;
      }

      case FaParser::PointOp: {
        enterOuterAlt(_localctx, 5);
        setState(804);
        match(FaParser::PointOp);
        setState(805);
        id();
        break;
      }

      case FaParser::Is: {
        enterOuterAlt(_localctx, 6);
        setState(806);
        match(FaParser::Is);
        setState(807);
        ids();
        setState(812);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx)) {
        case 1: {
          setState(808);
          quotYuanL();
          setState(809);
          id();
          setState(810);
          quotYuanR();
          break;
        }

        default:
          break;
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

//----------------- StrongExprContext ------------------------------------------------------------------

FaParser::StrongExprContext::StrongExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::StrongExprBaseContext* FaParser::StrongExprContext::strongExprBase() {
  return getRuleContext<FaParser::StrongExprBaseContext>(0);
}

std::vector<FaParser::StrongExprPrefixContext *> FaParser::StrongExprContext::strongExprPrefix() {
  return getRuleContexts<FaParser::StrongExprPrefixContext>();
}

FaParser::StrongExprPrefixContext* FaParser::StrongExprContext::strongExprPrefix(size_t i) {
  return getRuleContext<FaParser::StrongExprPrefixContext>(i);
}

std::vector<FaParser::StrongExprSuffixContext *> FaParser::StrongExprContext::strongExprSuffix() {
  return getRuleContexts<FaParser::StrongExprSuffixContext>();
}

FaParser::StrongExprSuffixContext* FaParser::StrongExprContext::strongExprSuffix(size_t i) {
  return getRuleContext<FaParser::StrongExprSuffixContext>(i);
}


size_t FaParser::StrongExprContext::getRuleIndex() const {
  return FaParser::RuleStrongExpr;
}


antlrcpp::Any FaParser::StrongExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitStrongExpr(this);
  else
    return visitor->visitChildren(this);
}

FaParser::StrongExprContext* FaParser::strongExpr() {
  StrongExprContext *_localctx = _tracker.createInstance<StrongExprContext>(_ctx, getState());
  enterRule(_localctx, 164, FaParser::RuleStrongExpr);

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
    setState(819);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(816);
        strongExprPrefix(); 
      }
      setState(821);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx);
    }
    setState(822);
    strongExprBase();
    setState(826);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(823);
        strongExprSuffix(); 
      }
      setState(828);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MiddleExprContext ------------------------------------------------------------------

FaParser::MiddleExprContext::MiddleExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FaParser::StrongExprContext *> FaParser::MiddleExprContext::strongExpr() {
  return getRuleContexts<FaParser::StrongExprContext>();
}

FaParser::StrongExprContext* FaParser::MiddleExprContext::strongExpr(size_t i) {
  return getRuleContext<FaParser::StrongExprContext>(i);
}

std::vector<FaParser::AllOp2Context *> FaParser::MiddleExprContext::allOp2() {
  return getRuleContexts<FaParser::AllOp2Context>();
}

FaParser::AllOp2Context* FaParser::MiddleExprContext::allOp2(size_t i) {
  return getRuleContext<FaParser::AllOp2Context>(i);
}


size_t FaParser::MiddleExprContext::getRuleIndex() const {
  return FaParser::RuleMiddleExpr;
}


antlrcpp::Any FaParser::MiddleExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitMiddleExpr(this);
  else
    return visitor->visitChildren(this);
}

FaParser::MiddleExprContext* FaParser::middleExpr() {
  MiddleExprContext *_localctx = _tracker.createInstance<MiddleExprContext>(_ctx, getState());
  enterRule(_localctx, 166, FaParser::RuleMiddleExpr);

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
    setState(829);
    strongExpr();
    setState(835);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(830);
        allOp2();
        setState(831);
        strongExpr(); 
      }
      setState(837);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
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

std::vector<FaParser::MiddleExprContext *> FaParser::ExprContext::middleExpr() {
  return getRuleContexts<FaParser::MiddleExprContext>();
}

FaParser::MiddleExprContext* FaParser::ExprContext::middleExpr(size_t i) {
  return getRuleContext<FaParser::MiddleExprContext>(i);
}

std::vector<FaParser::AllAssignContext *> FaParser::ExprContext::allAssign() {
  return getRuleContexts<FaParser::AllAssignContext>();
}

FaParser::AllAssignContext* FaParser::ExprContext::allAssign(size_t i) {
  return getRuleContext<FaParser::AllAssignContext>(i);
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
  enterRule(_localctx, 168, FaParser::RuleExpr);

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
    setState(838);
    middleExpr();
    setState(844);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(839);
        allAssign();
        setState(840);
        middleExpr(); 
      }
      setState(846);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdAssignExprContext ------------------------------------------------------------------

FaParser::IdAssignExprContext::IdAssignExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::IdContext* FaParser::IdAssignExprContext::id() {
  return getRuleContext<FaParser::IdContext>(0);
}

tree::TerminalNode* FaParser::IdAssignExprContext::Colon() {
  return getToken(FaParser::Colon, 0);
}

FaParser::TypeContext* FaParser::IdAssignExprContext::type() {
  return getRuleContext<FaParser::TypeContext>(0);
}

tree::TerminalNode* FaParser::IdAssignExprContext::Assign() {
  return getToken(FaParser::Assign, 0);
}

FaParser::ExprContext* FaParser::IdAssignExprContext::expr() {
  return getRuleContext<FaParser::ExprContext>(0);
}


size_t FaParser::IdAssignExprContext::getRuleIndex() const {
  return FaParser::RuleIdAssignExpr;
}


antlrcpp::Any FaParser::IdAssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitIdAssignExpr(this);
  else
    return visitor->visitChildren(this);
}

FaParser::IdAssignExprContext* FaParser::idAssignExpr() {
  IdAssignExprContext *_localctx = _tracker.createInstance<IdAssignExprContext>(_ctx, getState());
  enterRule(_localctx, 170, FaParser::RuleIdAssignExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(847);
    id();
    setState(848);
    match(FaParser::Colon);
    setState(849);
    type();
    setState(850);
    match(FaParser::Assign);
    setState(851);
    expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefVarStmtContext ------------------------------------------------------------------

FaParser::DefVarStmtContext::DefVarStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::DefVarStmtContext::Var() {
  return getToken(FaParser::Var, 0);
}

std::vector<FaParser::IdAssignExprContext *> FaParser::DefVarStmtContext::idAssignExpr() {
  return getRuleContexts<FaParser::IdAssignExprContext>();
}

FaParser::IdAssignExprContext* FaParser::DefVarStmtContext::idAssignExpr(size_t i) {
  return getRuleContext<FaParser::IdAssignExprContext>(i);
}

FaParser::EndlContext* FaParser::DefVarStmtContext::endl() {
  return getRuleContext<FaParser::EndlContext>(0);
}

std::vector<tree::TerminalNode *> FaParser::DefVarStmtContext::Comma() {
  return getTokens(FaParser::Comma);
}

tree::TerminalNode* FaParser::DefVarStmtContext::Comma(size_t i) {
  return getToken(FaParser::Comma, i);
}


size_t FaParser::DefVarStmtContext::getRuleIndex() const {
  return FaParser::RuleDefVarStmt;
}


antlrcpp::Any FaParser::DefVarStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitDefVarStmt(this);
  else
    return visitor->visitChildren(this);
}

FaParser::DefVarStmtContext* FaParser::defVarStmt() {
  DefVarStmtContext *_localctx = _tracker.createInstance<DefVarStmtContext>(_ctx, getState());
  enterRule(_localctx, 172, FaParser::RuleDefVarStmt);
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
    setState(853);
    match(FaParser::Var);
    setState(854);
    idAssignExpr();
    setState(859);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(855);
      match(FaParser::Comma);
      setState(856);
      idAssignExpr();
      setState(861);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(862);
    endl();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdAssignExpr2Context ------------------------------------------------------------------

FaParser::IdAssignExpr2Context::IdAssignExpr2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::IdContext* FaParser::IdAssignExpr2Context::id() {
  return getRuleContext<FaParser::IdContext>(0);
}

tree::TerminalNode* FaParser::IdAssignExpr2Context::Assign() {
  return getToken(FaParser::Assign, 0);
}

FaParser::ExprContext* FaParser::IdAssignExpr2Context::expr() {
  return getRuleContext<FaParser::ExprContext>(0);
}


size_t FaParser::IdAssignExpr2Context::getRuleIndex() const {
  return FaParser::RuleIdAssignExpr2;
}


antlrcpp::Any FaParser::IdAssignExpr2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitIdAssignExpr2(this);
  else
    return visitor->visitChildren(this);
}

FaParser::IdAssignExpr2Context* FaParser::idAssignExpr2() {
  IdAssignExpr2Context *_localctx = _tracker.createInstance<IdAssignExpr2Context>(_ctx, getState());
  enterRule(_localctx, 174, FaParser::RuleIdAssignExpr2);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(864);
    id();
    setState(865);
    match(FaParser::Assign);
    setState(866);
    expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefVarStmt2Context ------------------------------------------------------------------

FaParser::DefVarStmt2Context::DefVarStmt2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::TypeContext* FaParser::DefVarStmt2Context::type() {
  return getRuleContext<FaParser::TypeContext>(0);
}

std::vector<FaParser::IdAssignExpr2Context *> FaParser::DefVarStmt2Context::idAssignExpr2() {
  return getRuleContexts<FaParser::IdAssignExpr2Context>();
}

FaParser::IdAssignExpr2Context* FaParser::DefVarStmt2Context::idAssignExpr2(size_t i) {
  return getRuleContext<FaParser::IdAssignExpr2Context>(i);
}

FaParser::EndlContext* FaParser::DefVarStmt2Context::endl() {
  return getRuleContext<FaParser::EndlContext>(0);
}

std::vector<tree::TerminalNode *> FaParser::DefVarStmt2Context::Comma() {
  return getTokens(FaParser::Comma);
}

tree::TerminalNode* FaParser::DefVarStmt2Context::Comma(size_t i) {
  return getToken(FaParser::Comma, i);
}


size_t FaParser::DefVarStmt2Context::getRuleIndex() const {
  return FaParser::RuleDefVarStmt2;
}


antlrcpp::Any FaParser::DefVarStmt2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitDefVarStmt2(this);
  else
    return visitor->visitChildren(this);
}

FaParser::DefVarStmt2Context* FaParser::defVarStmt2() {
  DefVarStmt2Context *_localctx = _tracker.createInstance<DefVarStmt2Context>(_ctx, getState());
  enterRule(_localctx, 176, FaParser::RuleDefVarStmt2);
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
    setState(868);
    type();
    setState(869);
    idAssignExpr2();
    setState(874);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(870);
      match(FaParser::Comma);
      setState(871);
      idAssignExpr2();
      setState(876);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(877);
    endl();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NormalStmtContext ------------------------------------------------------------------

FaParser::NormalStmtContext::NormalStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::EndlContext* FaParser::NormalStmtContext::endl() {
  return getRuleContext<FaParser::EndlContext>(0);
}

tree::TerminalNode* FaParser::NormalStmtContext::Break() {
  return getToken(FaParser::Break, 0);
}

tree::TerminalNode* FaParser::NormalStmtContext::Continue() {
  return getToken(FaParser::Continue, 0);
}

tree::TerminalNode* FaParser::NormalStmtContext::Return() {
  return getToken(FaParser::Return, 0);
}

FaParser::ExprContext* FaParser::NormalStmtContext::expr() {
  return getRuleContext<FaParser::ExprContext>(0);
}


size_t FaParser::NormalStmtContext::getRuleIndex() const {
  return FaParser::RuleNormalStmt;
}


antlrcpp::Any FaParser::NormalStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitNormalStmt(this);
  else
    return visitor->visitChildren(this);
}

FaParser::NormalStmtContext* FaParser::normalStmt() {
  NormalStmtContext *_localctx = _tracker.createInstance<NormalStmtContext>(_ctx, getState());
  enterRule(_localctx, 178, FaParser::RuleNormalStmt);
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
    setState(887);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::T__0:
      case FaParser::T__6:
      case FaParser::If:
      case FaParser::New:
      case FaParser::Return:
      case FaParser::Switch:
      case FaParser::ReverseOp:
      case FaParser::AddAddOp:
      case FaParser::SubSubOp:
      case FaParser::Exclam:
      case FaParser::SubOp:
      case FaParser::ColonColon:
      case FaParser::Lf:
      case FaParser::Semi:
      case FaParser::Underline:
      case FaParser::BoolLiteral:
      case FaParser::IntLiteral:
      case FaParser::FloatLiteral:
      case FaParser::String1Literal:
      case FaParser::RawId: {
        setState(880);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == FaParser::Return) {
          setState(879);
          match(FaParser::Return);
        }
        setState(883);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << FaParser::T__0)
          | (1ULL << FaParser::T__6)
          | (1ULL << FaParser::If)
          | (1ULL << FaParser::New)
          | (1ULL << FaParser::Switch)
          | (1ULL << FaParser::ReverseOp)
          | (1ULL << FaParser::AddAddOp)
          | (1ULL << FaParser::SubSubOp)
          | (1ULL << FaParser::Exclam)
          | (1ULL << FaParser::SubOp))) != 0) || ((((_la - 76) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 76)) & ((1ULL << (FaParser::ColonColon - 76))
          | (1ULL << (FaParser::Underline - 76))
          | (1ULL << (FaParser::BoolLiteral - 76))
          | (1ULL << (FaParser::IntLiteral - 76))
          | (1ULL << (FaParser::FloatLiteral - 76))
          | (1ULL << (FaParser::String1Literal - 76))
          | (1ULL << (FaParser::RawId - 76)))) != 0)) {
          setState(882);
          expr();
        }
        break;
      }

      case FaParser::Break: {
        setState(885);
        match(FaParser::Break);
        break;
      }

      case FaParser::Continue: {
        setState(886);
        match(FaParser::Continue);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(889);
    endl();
   
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

FaParser::IfStmtContext* FaParser::StmtContext::ifStmt() {
  return getRuleContext<FaParser::IfStmtContext>(0);
}

FaParser::WhileStmtContext* FaParser::StmtContext::whileStmt() {
  return getRuleContext<FaParser::WhileStmtContext>(0);
}

FaParser::WhileStmt2Context* FaParser::StmtContext::whileStmt2() {
  return getRuleContext<FaParser::WhileStmt2Context>(0);
}

FaParser::ForStmtContext* FaParser::StmtContext::forStmt() {
  return getRuleContext<FaParser::ForStmtContext>(0);
}

FaParser::ForStmt2Context* FaParser::StmtContext::forStmt2() {
  return getRuleContext<FaParser::ForStmt2Context>(0);
}

FaParser::QuotStmtPartContext* FaParser::StmtContext::quotStmtPart() {
  return getRuleContext<FaParser::QuotStmtPartContext>(0);
}

FaParser::SwitchStmt2Context* FaParser::StmtContext::switchStmt2() {
  return getRuleContext<FaParser::SwitchStmt2Context>(0);
}

FaParser::SwitchStmtContext* FaParser::StmtContext::switchStmt() {
  return getRuleContext<FaParser::SwitchStmtContext>(0);
}

FaParser::DefVarStmtContext* FaParser::StmtContext::defVarStmt() {
  return getRuleContext<FaParser::DefVarStmtContext>(0);
}

FaParser::DefVarStmt2Context* FaParser::StmtContext::defVarStmt2() {
  return getRuleContext<FaParser::DefVarStmt2Context>(0);
}

FaParser::NormalStmtContext* FaParser::StmtContext::normalStmt() {
  return getRuleContext<FaParser::NormalStmtContext>(0);
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
  enterRule(_localctx, 180, FaParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(902);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(891);
      ifStmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(892);
      whileStmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(893);
      whileStmt2();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(894);
      forStmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(895);
      forStmt2();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(896);
      quotStmtPart();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(897);
      switchStmt2();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(898);
      switchStmt();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(899);
      defVarStmt();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(900);
      defVarStmt2();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(901);
      normalStmt();
      break;
    }

    default:
      break;
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
  enterRule(_localctx, 182, FaParser::RulePublicLevel);
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
    setState(904);
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

//----------------- ClassItemFuncExtBodyContext ------------------------------------------------------------------

FaParser::ClassItemFuncExtBodyContext::ClassItemFuncExtBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::ExprFuncDefContext* FaParser::ClassItemFuncExtBodyContext::exprFuncDef() {
  return getRuleContext<FaParser::ExprFuncDefContext>(0);
}

FaParser::ExprContext* FaParser::ClassItemFuncExtBodyContext::expr() {
  return getRuleContext<FaParser::ExprContext>(0);
}

tree::TerminalNode* FaParser::ClassItemFuncExtBodyContext::Semi() {
  return getToken(FaParser::Semi, 0);
}

FaParser::QuotHuaLContext* FaParser::ClassItemFuncExtBodyContext::quotHuaL() {
  return getRuleContext<FaParser::QuotHuaLContext>(0);
}

FaParser::QuotHuaRContext* FaParser::ClassItemFuncExtBodyContext::quotHuaR() {
  return getRuleContext<FaParser::QuotHuaRContext>(0);
}

std::vector<FaParser::StmtContext *> FaParser::ClassItemFuncExtBodyContext::stmt() {
  return getRuleContexts<FaParser::StmtContext>();
}

FaParser::StmtContext* FaParser::ClassItemFuncExtBodyContext::stmt(size_t i) {
  return getRuleContext<FaParser::StmtContext>(i);
}


size_t FaParser::ClassItemFuncExtBodyContext::getRuleIndex() const {
  return FaParser::RuleClassItemFuncExtBody;
}


antlrcpp::Any FaParser::ClassItemFuncExtBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitClassItemFuncExtBody(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ClassItemFuncExtBodyContext* FaParser::classItemFuncExtBody() {
  ClassItemFuncExtBodyContext *_localctx = _tracker.createInstance<ClassItemFuncExtBodyContext>(_ctx, getState());
  enterRule(_localctx, 184, FaParser::RuleClassItemFuncExtBody);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(919);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::Assign: {
        enterOuterAlt(_localctx, 1);
        setState(906);
        exprFuncDef();
        setState(907);
        expr();
        setState(908);
        match(FaParser::Semi);
        break;
      }

      case FaParser::T__4: {
        enterOuterAlt(_localctx, 2);
        setState(910);
        quotHuaL();
        setState(914);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(911);
            stmt(); 
          }
          setState(916);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx);
        }
        setState(917);
        quotHuaR();
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

//----------------- ClassItemFuncExt1Context ------------------------------------------------------------------

FaParser::ClassItemFuncExt1Context::ClassItemFuncExt1Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::QuotYuanLContext* FaParser::ClassItemFuncExt1Context::quotYuanL() {
  return getRuleContext<FaParser::QuotYuanLContext>(0);
}

FaParser::QuotYuanRContext* FaParser::ClassItemFuncExt1Context::quotYuanR() {
  return getRuleContext<FaParser::QuotYuanRContext>(0);
}

tree::TerminalNode* FaParser::ClassItemFuncExt1Context::Colon() {
  return getToken(FaParser::Colon, 0);
}

FaParser::TypeContext* FaParser::ClassItemFuncExt1Context::type() {
  return getRuleContext<FaParser::TypeContext>(0);
}

FaParser::ClassItemFuncExtBodyContext* FaParser::ClassItemFuncExt1Context::classItemFuncExtBody() {
  return getRuleContext<FaParser::ClassItemFuncExtBodyContext>(0);
}

FaParser::TypeWrapVarList1Context* FaParser::ClassItemFuncExt1Context::typeWrapVarList1() {
  return getRuleContext<FaParser::TypeWrapVarList1Context>(0);
}


size_t FaParser::ClassItemFuncExt1Context::getRuleIndex() const {
  return FaParser::RuleClassItemFuncExt1;
}


antlrcpp::Any FaParser::ClassItemFuncExt1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitClassItemFuncExt1(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ClassItemFuncExt1Context* FaParser::classItemFuncExt1() {
  ClassItemFuncExt1Context *_localctx = _tracker.createInstance<ClassItemFuncExt1Context>(_ctx, getState());
  enterRule(_localctx, 186, FaParser::RuleClassItemFuncExt1);
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
    setState(921);
    quotYuanL();
    setState(923);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Underline

    || _la == FaParser::RawId) {
      setState(922);
      typeWrapVarList1();
    }
    setState(925);
    quotYuanR();
    setState(926);
    match(FaParser::Colon);
    setState(927);
    type();
    setState(928);
    classItemFuncExtBody();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassItemVarContext ------------------------------------------------------------------

FaParser::ClassItemVarContext::ClassItemVarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::IdContext* FaParser::ClassItemVarContext::id() {
  return getRuleContext<FaParser::IdContext>(0);
}

tree::TerminalNode* FaParser::ClassItemVarContext::Colon() {
  return getToken(FaParser::Colon, 0);
}

FaParser::TypeContext* FaParser::ClassItemVarContext::type() {
  return getRuleContext<FaParser::TypeContext>(0);
}

FaParser::EndlContext* FaParser::ClassItemVarContext::endl() {
  return getRuleContext<FaParser::EndlContext>(0);
}

FaParser::PublicLevelContext* FaParser::ClassItemVarContext::publicLevel() {
  return getRuleContext<FaParser::PublicLevelContext>(0);
}

tree::TerminalNode* FaParser::ClassItemVarContext::Static() {
  return getToken(FaParser::Static, 0);
}

tree::TerminalNode* FaParser::ClassItemVarContext::Assign() {
  return getToken(FaParser::Assign, 0);
}

FaParser::MiddleExprContext* FaParser::ClassItemVarContext::middleExpr() {
  return getRuleContext<FaParser::MiddleExprContext>(0);
}


size_t FaParser::ClassItemVarContext::getRuleIndex() const {
  return FaParser::RuleClassItemVar;
}


antlrcpp::Any FaParser::ClassItemVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitClassItemVar(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ClassItemVarContext* FaParser::classItemVar() {
  ClassItemVarContext *_localctx = _tracker.createInstance<ClassItemVarContext>(_ctx, getState());
  enterRule(_localctx, 188, FaParser::RuleClassItemVar);
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
    setState(931);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(930);
      publicLevel();
    }
    setState(934);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Static) {
      setState(933);
      match(FaParser::Static);
    }
    setState(936);
    id();
    setState(937);
    match(FaParser::Colon);
    setState(938);
    type();
    setState(941);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Assign) {
      setState(939);
      match(FaParser::Assign);
      setState(940);
      middleExpr();
    }
    setState(943);
    endl();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassItemFuncContext ------------------------------------------------------------------

FaParser::ClassItemFuncContext::ClassItemFuncContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::ClassItemFuncContext::Fn() {
  return getToken(FaParser::Fn, 0);
}

FaParser::IdContext* FaParser::ClassItemFuncContext::id() {
  return getRuleContext<FaParser::IdContext>(0);
}

FaParser::EndlContext* FaParser::ClassItemFuncContext::endl() {
  return getRuleContext<FaParser::EndlContext>(0);
}

FaParser::PublicLevelContext* FaParser::ClassItemFuncContext::publicLevel() {
  return getRuleContext<FaParser::PublicLevelContext>(0);
}

tree::TerminalNode* FaParser::ClassItemFuncContext::Static() {
  return getToken(FaParser::Static, 0);
}

FaParser::ClassItemFuncExt1Context* FaParser::ClassItemFuncContext::classItemFuncExt1() {
  return getRuleContext<FaParser::ClassItemFuncExt1Context>(0);
}


size_t FaParser::ClassItemFuncContext::getRuleIndex() const {
  return FaParser::RuleClassItemFunc;
}


antlrcpp::Any FaParser::ClassItemFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitClassItemFunc(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ClassItemFuncContext* FaParser::classItemFunc() {
  ClassItemFuncContext *_localctx = _tracker.createInstance<ClassItemFuncContext>(_ctx, getState());
  enterRule(_localctx, 190, FaParser::RuleClassItemFunc);
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
    setState(946);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(945);
      publicLevel();
    }
    setState(949);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Static) {
      setState(948);
      match(FaParser::Static);
    }
    setState(951);
    match(FaParser::Fn);
    setState(952);
    id();
    setState(954);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::T__6) {
      setState(953);
      classItemFuncExt1();
    }
    setState(956);
    endl();
   
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

FaParser::IdContext* FaParser::ClassBlockContext::id() {
  return getRuleContext<FaParser::IdContext>(0);
}

FaParser::QuotHuaLContext* FaParser::ClassBlockContext::quotHuaL() {
  return getRuleContext<FaParser::QuotHuaLContext>(0);
}

FaParser::QuotHuaRContext* FaParser::ClassBlockContext::quotHuaR() {
  return getRuleContext<FaParser::QuotHuaRContext>(0);
}

FaParser::EndlContext* FaParser::ClassBlockContext::endl() {
  return getRuleContext<FaParser::EndlContext>(0);
}

FaParser::PublicLevelContext* FaParser::ClassBlockContext::publicLevel() {
  return getRuleContext<FaParser::PublicLevelContext>(0);
}

std::vector<FaParser::ClassItemVarContext *> FaParser::ClassBlockContext::classItemVar() {
  return getRuleContexts<FaParser::ClassItemVarContext>();
}

FaParser::ClassItemVarContext* FaParser::ClassBlockContext::classItemVar(size_t i) {
  return getRuleContext<FaParser::ClassItemVarContext>(i);
}

std::vector<FaParser::ClassItemFuncContext *> FaParser::ClassBlockContext::classItemFunc() {
  return getRuleContexts<FaParser::ClassItemFuncContext>();
}

FaParser::ClassItemFuncContext* FaParser::ClassBlockContext::classItemFunc(size_t i) {
  return getRuleContext<FaParser::ClassItemFuncContext>(i);
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
  enterRule(_localctx, 192, FaParser::RuleClassBlock);
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
    setState(959);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(958);
      publicLevel();
    }
    setState(961);
    match(FaParser::Class);
    setState(962);
    id();
    setState(963);
    quotHuaL();
    setState(968);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Fn)
      | (1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private)
      | (1ULL << FaParser::Static))) != 0) || _la == FaParser::Underline

    || _la == FaParser::RawId) {
      setState(966);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 89, _ctx)) {
      case 1: {
        setState(964);
        classItemVar();
        break;
      }

      case 2: {
        setState(965);
        classItemFunc();
        break;
      }

      default:
        break;
      }
      setState(970);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(971);
    quotHuaR();
    setState(972);
    endl();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassItemFuncExt2Context ------------------------------------------------------------------

FaParser::ClassItemFuncExt2Context::ClassItemFuncExt2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::QuotYuanLContext* FaParser::ClassItemFuncExt2Context::quotYuanL() {
  return getRuleContext<FaParser::QuotYuanLContext>(0);
}

FaParser::QuotYuanRContext* FaParser::ClassItemFuncExt2Context::quotYuanR() {
  return getRuleContext<FaParser::QuotYuanRContext>(0);
}

FaParser::ClassItemFuncExtBodyContext* FaParser::ClassItemFuncExt2Context::classItemFuncExtBody() {
  return getRuleContext<FaParser::ClassItemFuncExtBodyContext>(0);
}

FaParser::TypeWrapVarList2Context* FaParser::ClassItemFuncExt2Context::typeWrapVarList2() {
  return getRuleContext<FaParser::TypeWrapVarList2Context>(0);
}


size_t FaParser::ClassItemFuncExt2Context::getRuleIndex() const {
  return FaParser::RuleClassItemFuncExt2;
}


antlrcpp::Any FaParser::ClassItemFuncExt2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitClassItemFuncExt2(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ClassItemFuncExt2Context* FaParser::classItemFuncExt2() {
  ClassItemFuncExt2Context *_localctx = _tracker.createInstance<ClassItemFuncExt2Context>(_ctx, getState());
  enterRule(_localctx, 194, FaParser::RuleClassItemFuncExt2);
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
    setState(974);
    quotYuanL();
    setState(976);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::T__6)
      | (1ULL << FaParser::Mut)
      | (1ULL << FaParser::Params))) != 0) || _la == FaParser::Underline

    || _la == FaParser::RawId) {
      setState(975);
      typeWrapVarList2();
    }
    setState(978);
    quotYuanR();
    setState(979);
    classItemFuncExtBody();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassItem2Context ------------------------------------------------------------------

FaParser::ClassItem2Context::ClassItem2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::TypeContext* FaParser::ClassItem2Context::type() {
  return getRuleContext<FaParser::TypeContext>(0);
}

FaParser::IdContext* FaParser::ClassItem2Context::id() {
  return getRuleContext<FaParser::IdContext>(0);
}

FaParser::EndlContext* FaParser::ClassItem2Context::endl() {
  return getRuleContext<FaParser::EndlContext>(0);
}

FaParser::PublicLevelContext* FaParser::ClassItem2Context::publicLevel() {
  return getRuleContext<FaParser::PublicLevelContext>(0);
}

tree::TerminalNode* FaParser::ClassItem2Context::Static() {
  return getToken(FaParser::Static, 0);
}

FaParser::ClassItemFuncExt2Context* FaParser::ClassItem2Context::classItemFuncExt2() {
  return getRuleContext<FaParser::ClassItemFuncExt2Context>(0);
}


size_t FaParser::ClassItem2Context::getRuleIndex() const {
  return FaParser::RuleClassItem2;
}


antlrcpp::Any FaParser::ClassItem2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitClassItem2(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ClassItem2Context* FaParser::classItem2() {
  ClassItem2Context *_localctx = _tracker.createInstance<ClassItem2Context>(_ctx, getState());
  enterRule(_localctx, 196, FaParser::RuleClassItem2);
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
    setState(982);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(981);
      publicLevel();
    }
    setState(985);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Static) {
      setState(984);
      match(FaParser::Static);
    }
    setState(987);
    type();
    setState(988);
    id();
    setState(990);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::T__6) {
      setState(989);
      classItemFuncExt2();
    }
    setState(992);
    endl();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassBlock2Context ------------------------------------------------------------------

FaParser::ClassBlock2Context::ClassBlock2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::ClassBlock2Context::Class() {
  return getToken(FaParser::Class, 0);
}

FaParser::IdContext* FaParser::ClassBlock2Context::id() {
  return getRuleContext<FaParser::IdContext>(0);
}

FaParser::QuotHuaLContext* FaParser::ClassBlock2Context::quotHuaL() {
  return getRuleContext<FaParser::QuotHuaLContext>(0);
}

FaParser::QuotHuaRContext* FaParser::ClassBlock2Context::quotHuaR() {
  return getRuleContext<FaParser::QuotHuaRContext>(0);
}

FaParser::EndlContext* FaParser::ClassBlock2Context::endl() {
  return getRuleContext<FaParser::EndlContext>(0);
}

FaParser::PublicLevelContext* FaParser::ClassBlock2Context::publicLevel() {
  return getRuleContext<FaParser::PublicLevelContext>(0);
}

std::vector<FaParser::ClassItem2Context *> FaParser::ClassBlock2Context::classItem2() {
  return getRuleContexts<FaParser::ClassItem2Context>();
}

FaParser::ClassItem2Context* FaParser::ClassBlock2Context::classItem2(size_t i) {
  return getRuleContext<FaParser::ClassItem2Context>(i);
}


size_t FaParser::ClassBlock2Context::getRuleIndex() const {
  return FaParser::RuleClassBlock2;
}


antlrcpp::Any FaParser::ClassBlock2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitClassBlock2(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ClassBlock2Context* FaParser::classBlock2() {
  ClassBlock2Context *_localctx = _tracker.createInstance<ClassBlock2Context>(_ctx, getState());
  enterRule(_localctx, 198, FaParser::RuleClassBlock2);
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
    setState(995);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(994);
      publicLevel();
    }
    setState(997);
    match(FaParser::Class);
    setState(998);
    id();
    setState(999);
    quotHuaL();
    setState(1003);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::T__6)
      | (1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private)
      | (1ULL << FaParser::Static))) != 0) || _la == FaParser::Underline

    || _la == FaParser::RawId) {
      setState(1000);
      classItem2();
      setState(1005);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1006);
    quotHuaR();
    setState(1007);
    endl();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumItemContext ------------------------------------------------------------------

FaParser::EnumItemContext::EnumItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::IdContext* FaParser::EnumItemContext::id() {
  return getRuleContext<FaParser::IdContext>(0);
}

FaParser::QuotYuanLContext* FaParser::EnumItemContext::quotYuanL() {
  return getRuleContext<FaParser::QuotYuanLContext>(0);
}

std::vector<FaParser::TypeContext *> FaParser::EnumItemContext::type() {
  return getRuleContexts<FaParser::TypeContext>();
}

FaParser::TypeContext* FaParser::EnumItemContext::type(size_t i) {
  return getRuleContext<FaParser::TypeContext>(i);
}

FaParser::QuotYuanRContext* FaParser::EnumItemContext::quotYuanR() {
  return getRuleContext<FaParser::QuotYuanRContext>(0);
}

FaParser::Endl2Context* FaParser::EnumItemContext::endl2() {
  return getRuleContext<FaParser::Endl2Context>(0);
}

std::vector<tree::TerminalNode *> FaParser::EnumItemContext::Comma() {
  return getTokens(FaParser::Comma);
}

tree::TerminalNode* FaParser::EnumItemContext::Comma(size_t i) {
  return getToken(FaParser::Comma, i);
}


size_t FaParser::EnumItemContext::getRuleIndex() const {
  return FaParser::RuleEnumItem;
}


antlrcpp::Any FaParser::EnumItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitEnumItem(this);
  else
    return visitor->visitChildren(this);
}

FaParser::EnumItemContext* FaParser::enumItem() {
  EnumItemContext *_localctx = _tracker.createInstance<EnumItemContext>(_ctx, getState());
  enterRule(_localctx, 200, FaParser::RuleEnumItem);
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
    setState(1009);
    id();

    setState(1010);
    quotYuanL();
    setState(1011);
    type();
    setState(1016);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(1012);
      match(FaParser::Comma);
      setState(1013);
      type();
      setState(1018);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1019);
    quotYuanR();
    setState(1022);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 98, _ctx)) {
    case 1: {
      setState(1021);
      endl2();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumBlockContext ------------------------------------------------------------------

FaParser::EnumBlockContext::EnumBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::EnumBlockContext::Enum() {
  return getToken(FaParser::Enum, 0);
}

FaParser::IdContext* FaParser::EnumBlockContext::id() {
  return getRuleContext<FaParser::IdContext>(0);
}

FaParser::QuotHuaLContext* FaParser::EnumBlockContext::quotHuaL() {
  return getRuleContext<FaParser::QuotHuaLContext>(0);
}

FaParser::QuotHuaRContext* FaParser::EnumBlockContext::quotHuaR() {
  return getRuleContext<FaParser::QuotHuaRContext>(0);
}

FaParser::EndlContext* FaParser::EnumBlockContext::endl() {
  return getRuleContext<FaParser::EndlContext>(0);
}

FaParser::PublicLevelContext* FaParser::EnumBlockContext::publicLevel() {
  return getRuleContext<FaParser::PublicLevelContext>(0);
}

std::vector<FaParser::EnumItemContext *> FaParser::EnumBlockContext::enumItem() {
  return getRuleContexts<FaParser::EnumItemContext>();
}

FaParser::EnumItemContext* FaParser::EnumBlockContext::enumItem(size_t i) {
  return getRuleContext<FaParser::EnumItemContext>(i);
}

std::vector<FaParser::ClassItemFuncContext *> FaParser::EnumBlockContext::classItemFunc() {
  return getRuleContexts<FaParser::ClassItemFuncContext>();
}

FaParser::ClassItemFuncContext* FaParser::EnumBlockContext::classItemFunc(size_t i) {
  return getRuleContext<FaParser::ClassItemFuncContext>(i);
}


size_t FaParser::EnumBlockContext::getRuleIndex() const {
  return FaParser::RuleEnumBlock;
}


antlrcpp::Any FaParser::EnumBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitEnumBlock(this);
  else
    return visitor->visitChildren(this);
}

FaParser::EnumBlockContext* FaParser::enumBlock() {
  EnumBlockContext *_localctx = _tracker.createInstance<EnumBlockContext>(_ctx, getState());
  enterRule(_localctx, 202, FaParser::RuleEnumBlock);
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
    setState(1025);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(1024);
      publicLevel();
    }
    setState(1027);
    match(FaParser::Enum);
    setState(1028);
    id();
    setState(1029);
    quotHuaL();
    setState(1031); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1030);
      enumItem();
      setState(1033); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == FaParser::Underline

    || _la == FaParser::RawId);
    setState(1038);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Fn)
      | (1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private)
      | (1ULL << FaParser::Static))) != 0)) {
      setState(1035);
      classItemFunc();
      setState(1040);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1041);
    quotHuaR();
    setState(1042);
    endl();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumBlock2Context ------------------------------------------------------------------

FaParser::EnumBlock2Context::EnumBlock2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::EnumBlock2Context::Enum() {
  return getToken(FaParser::Enum, 0);
}

FaParser::IdContext* FaParser::EnumBlock2Context::id() {
  return getRuleContext<FaParser::IdContext>(0);
}

FaParser::QuotHuaLContext* FaParser::EnumBlock2Context::quotHuaL() {
  return getRuleContext<FaParser::QuotHuaLContext>(0);
}

FaParser::QuotHuaRContext* FaParser::EnumBlock2Context::quotHuaR() {
  return getRuleContext<FaParser::QuotHuaRContext>(0);
}

FaParser::EndlContext* FaParser::EnumBlock2Context::endl() {
  return getRuleContext<FaParser::EndlContext>(0);
}

FaParser::PublicLevelContext* FaParser::EnumBlock2Context::publicLevel() {
  return getRuleContext<FaParser::PublicLevelContext>(0);
}

std::vector<FaParser::EnumItemContext *> FaParser::EnumBlock2Context::enumItem() {
  return getRuleContexts<FaParser::EnumItemContext>();
}

FaParser::EnumItemContext* FaParser::EnumBlock2Context::enumItem(size_t i) {
  return getRuleContext<FaParser::EnumItemContext>(i);
}

std::vector<FaParser::ClassItem2Context *> FaParser::EnumBlock2Context::classItem2() {
  return getRuleContexts<FaParser::ClassItem2Context>();
}

FaParser::ClassItem2Context* FaParser::EnumBlock2Context::classItem2(size_t i) {
  return getRuleContext<FaParser::ClassItem2Context>(i);
}


size_t FaParser::EnumBlock2Context::getRuleIndex() const {
  return FaParser::RuleEnumBlock2;
}


antlrcpp::Any FaParser::EnumBlock2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitEnumBlock2(this);
  else
    return visitor->visitChildren(this);
}

FaParser::EnumBlock2Context* FaParser::enumBlock2() {
  EnumBlock2Context *_localctx = _tracker.createInstance<EnumBlock2Context>(_ctx, getState());
  enterRule(_localctx, 204, FaParser::RuleEnumBlock2);
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
    enterOuterAlt(_localctx, 1);
    setState(1045);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(1044);
      publicLevel();
    }
    setState(1047);
    match(FaParser::Enum);
    setState(1048);
    id();
    setState(1049);
    quotHuaL();
    setState(1051); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(1050);
              enumItem();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(1053); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 103, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(1058);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::T__6)
      | (1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private)
      | (1ULL << FaParser::Static))) != 0) || _la == FaParser::Underline

    || _la == FaParser::RawId) {
      setState(1055);
      classItem2();
      setState(1060);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1061);
    quotHuaR();
    setState(1062);
    endl();
   
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

FaParser::EndlContext* FaParser::UseStmtContext::endl() {
  return getRuleContext<FaParser::EndlContext>(0);
}

FaParser::IdContext* FaParser::UseStmtContext::id() {
  return getRuleContext<FaParser::IdContext>(0);
}

tree::TerminalNode* FaParser::UseStmtContext::Assign() {
  return getToken(FaParser::Assign, 0);
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
  enterRule(_localctx, 206, FaParser::RuleUseStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1064);
    match(FaParser::Use);
    setState(1068);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 105, _ctx)) {
    case 1: {
      setState(1065);
      id();
      setState(1066);
      match(FaParser::Assign);
      break;
    }

    default:
      break;
    }
    setState(1070);
    ids();
    setState(1071);
    endl();
   
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
  enterRule(_localctx, 208, FaParser::RuleCallConvention);
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
    setState(1073);
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

FaParser::TypeContext* FaParser::ImportStmtContext::type() {
  return getRuleContext<FaParser::TypeContext>(0);
}

FaParser::CallConventionContext* FaParser::ImportStmtContext::callConvention() {
  return getRuleContext<FaParser::CallConventionContext>(0);
}

FaParser::IdContext* FaParser::ImportStmtContext::id() {
  return getRuleContext<FaParser::IdContext>(0);
}

FaParser::QuotYuanLContext* FaParser::ImportStmtContext::quotYuanL() {
  return getRuleContext<FaParser::QuotYuanLContext>(0);
}

FaParser::TypeVarListContext* FaParser::ImportStmtContext::typeVarList() {
  return getRuleContext<FaParser::TypeVarListContext>(0);
}

FaParser::QuotYuanRContext* FaParser::ImportStmtContext::quotYuanR() {
  return getRuleContext<FaParser::QuotYuanRContext>(0);
}

FaParser::EndlContext* FaParser::ImportStmtContext::endl() {
  return getRuleContext<FaParser::EndlContext>(0);
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
  enterRule(_localctx, 210, FaParser::RuleImportStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1075);
    match(FaParser::AImport);
    setState(1076);
    type();
    setState(1077);
    callConvention();
    setState(1078);
    id();
    setState(1079);
    quotYuanL();
    setState(1080);
    typeVarList();
    setState(1081);
    quotYuanR();
    setState(1082);
    endl();
   
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

FaParser::EndlContext* FaParser::LibStmtContext::endl() {
  return getRuleContext<FaParser::EndlContext>(0);
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
  enterRule(_localctx, 212, FaParser::RuleLibStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1084);
    match(FaParser::ALib);
    setState(1085);
    match(FaParser::String1Literal);
    setState(1086);
    endl();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NamespaceStmtContext ------------------------------------------------------------------

FaParser::NamespaceStmtContext::NamespaceStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::NamespaceStmtContext::Namespace() {
  return getToken(FaParser::Namespace, 0);
}

FaParser::IdsContext* FaParser::NamespaceStmtContext::ids() {
  return getRuleContext<FaParser::IdsContext>(0);
}

FaParser::EndlContext* FaParser::NamespaceStmtContext::endl() {
  return getRuleContext<FaParser::EndlContext>(0);
}


size_t FaParser::NamespaceStmtContext::getRuleIndex() const {
  return FaParser::RuleNamespaceStmt;
}


antlrcpp::Any FaParser::NamespaceStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitNamespaceStmt(this);
  else
    return visitor->visitChildren(this);
}

FaParser::NamespaceStmtContext* FaParser::namespaceStmt() {
  NamespaceStmtContext *_localctx = _tracker.createInstance<NamespaceStmtContext>(_ctx, getState());
  enterRule(_localctx, 214, FaParser::RuleNamespaceStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1088);
    match(FaParser::Namespace);
    setState(1089);
    ids();
    setState(1090);
    endl();
   
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

std::vector<FaParser::ImportStmtContext *> FaParser::ProgramContext::importStmt() {
  return getRuleContexts<FaParser::ImportStmtContext>();
}

FaParser::ImportStmtContext* FaParser::ProgramContext::importStmt(size_t i) {
  return getRuleContext<FaParser::ImportStmtContext>(i);
}

std::vector<FaParser::LibStmtContext *> FaParser::ProgramContext::libStmt() {
  return getRuleContexts<FaParser::LibStmtContext>();
}

FaParser::LibStmtContext* FaParser::ProgramContext::libStmt(size_t i) {
  return getRuleContext<FaParser::LibStmtContext>(i);
}

FaParser::NamespaceStmtContext* FaParser::ProgramContext::namespaceStmt() {
  return getRuleContext<FaParser::NamespaceStmtContext>(0);
}

std::vector<FaParser::EnumBlockContext *> FaParser::ProgramContext::enumBlock() {
  return getRuleContexts<FaParser::EnumBlockContext>();
}

FaParser::EnumBlockContext* FaParser::ProgramContext::enumBlock(size_t i) {
  return getRuleContext<FaParser::EnumBlockContext>(i);
}

std::vector<FaParser::EnumBlock2Context *> FaParser::ProgramContext::enumBlock2() {
  return getRuleContexts<FaParser::EnumBlock2Context>();
}

FaParser::EnumBlock2Context* FaParser::ProgramContext::enumBlock2(size_t i) {
  return getRuleContext<FaParser::EnumBlock2Context>(i);
}

std::vector<FaParser::ClassBlockContext *> FaParser::ProgramContext::classBlock() {
  return getRuleContexts<FaParser::ClassBlockContext>();
}

FaParser::ClassBlockContext* FaParser::ProgramContext::classBlock(size_t i) {
  return getRuleContext<FaParser::ClassBlockContext>(i);
}

std::vector<FaParser::ClassBlock2Context *> FaParser::ProgramContext::classBlock2() {
  return getRuleContexts<FaParser::ClassBlock2Context>();
}

FaParser::ClassBlock2Context* FaParser::ProgramContext::classBlock2(size_t i) {
  return getRuleContext<FaParser::ClassBlock2Context>(i);
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
  enterRule(_localctx, 216, FaParser::RuleProgram);
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
    setState(1097);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::AImport)
      | (1ULL << FaParser::ALib)
      | (1ULL << FaParser::Use))) != 0)) {
      setState(1095);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case FaParser::Use: {
          setState(1092);
          useStmt();
          break;
        }

        case FaParser::AImport: {
          setState(1093);
          importStmt();
          break;
        }

        case FaParser::ALib: {
          setState(1094);
          libStmt();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(1099);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1101);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Namespace) {
      setState(1100);
      namespaceStmt();
    }
    setState(1109);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Class)
      | (1ULL << FaParser::Enum)
      | (1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(1107);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 109, _ctx)) {
      case 1: {
        setState(1103);
        enumBlock();
        break;
      }

      case 2: {
        setState(1104);
        enumBlock2();
        break;
      }

      case 3: {
        setState(1105);
        classBlock();
        break;
      }

      case 4: {
        setState(1106);
        classBlock2();
        break;
      }

      default:
        break;
      }
      setState(1111);
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

//----------------- ProgramEntryContext ------------------------------------------------------------------

FaParser::ProgramEntryContext::ProgramEntryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::ProgramContext* FaParser::ProgramEntryContext::program() {
  return getRuleContext<FaParser::ProgramContext>(0);
}

tree::TerminalNode* FaParser::ProgramEntryContext::EOF() {
  return getToken(FaParser::EOF, 0);
}


size_t FaParser::ProgramEntryContext::getRuleIndex() const {
  return FaParser::RuleProgramEntry;
}


antlrcpp::Any FaParser::ProgramEntryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitProgramEntry(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ProgramEntryContext* FaParser::programEntry() {
  ProgramEntryContext *_localctx = _tracker.createInstance<ProgramEntryContext>(_ctx, getState());
  enterRule(_localctx, 218, FaParser::RuleProgramEntry);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1112);
    program();
    setState(1113);
    match(FaParser::EOF);
   
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
  "shiftLAssign", "shiftRAssign", "allAssign", "shiftLOp", "shiftROp", "endl", 
  "endl2", "qFangL", "qFangR", "qJianL", "qJianR", "qHuaL", "qHuaR", "qYuanL", 
  "qYuanR", "quotFangL", "quotFangR", "quotJianL", "quotJianR", "quotHuaL", 
  "quotHuaR", "quotYuanL", "quotYuanR", "ltOp", "ltEqualOp", "gtOp", "gtEqualOp", 
  "equalOp", "notEqualOp", "exprFuncDef", "selfOp2", "compareOp2", "changeOp2", 
  "allOp2", "intNum", "floatNum", "literal", "id", "ids", "typeAfter", "typeSingle", 
  "typeMulti", "type", "typeWrap", "typeVar", "typeVarList", "typeWrapVar1", 
  "typeWrapVarList1", "typeWrapVar2", "typeWrapVarList2", "typeWrapVar3", 
  "typeWrapVarList3", "quotStmtPart", "quotStmtExpr", "ifStmt", "ifExpr", 
  "whileStmt", "whileStmt2", "forStmt", "forStmt2", "switchStmtPart2Last", 
  "quotStmtExprWrap", "switchExprPartLast", "switchStmtPart", "switchStmt", 
  "switchStmtPart2", "switchStmt2", "switchExprPart", "switchExpr", "switchExprPart2", 
  "switchExpr2", "quotExpr", "exprOpt", "newExprItem", "newExpr1", "newExpr2", 
  "arrayExpr1", "arrayExpr2", "lambdaExpr", "strongExprBase", "strongExprPrefix", 
  "strongExprSuffix", "strongExpr", "middleExpr", "expr", "idAssignExpr", 
  "defVarStmt", "idAssignExpr2", "defVarStmt2", "normalStmt", "stmt", "publicLevel", 
  "classItemFuncExtBody", "classItemFuncExt1", "classItemVar", "classItemFunc", 
  "classBlock", "classItemFuncExt2", "classItem2", "classBlock2", "enumItem", 
  "enumBlock", "enumBlock2", "useStmt", "callConvention", "importStmt", 
  "libStmt", "namespaceStmt", "program", "programEntry"
};

std::vector<std::string> FaParser::_literalNames = {
  "", "'['", "']'", "'<'", "'>'", "'{'", "'}'", "'('", "')'", "'@import'", 
  "'@lib'", "'break'", "'__cdecl'", "'__fastcall'", "'__stdcall'", "'continue'", 
  "'class'", "'const'", "'do'", "'else'", "'enum'", "'Fn'", "'for'", "'if'", 
  "'is'", "'internal'", "'mut'", "'namespace'", "'new'", "'params'", "'public'", 
  "'protected'", "'private'", "'return'", "'signed'", "'static'", "'step'", 
  "'switch'", "'unsigned'", "'use'", "'var'", "'when'", "'while'", "'='", 
  "", "", "", "", "", "", "", "", "", "", "", "", "'~'", "'++'", "'--'", 
  "'!'", "'..'", "'.'", "'+'", "'-'", "'*'", "'/'", "'%'", "'|'", "'&'", 
  "'^'", "", "", "", "", "'\u003F'", "','", "'::'", "':'", "'\n'", "';'", 
  "'_'"
};

std::vector<std::string> FaParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "AImport", "ALib", "Break", "CC__Cdecl", 
  "CC__FastCall", "CC__StdCall", "Continue", "Class", "Const", "Do", "Else", 
  "Enum", "Fn", "For", "If", "Is", "Internal", "Mut", "Namespace", "New", 
  "Params", "Public", "Protected", "Private", "Return", "Signed", "Static", 
  "Step", "Switch", "Unsigned", "Use", "Var", "When", "While", "Assign", 
  "AddAssign", "SubAssign", "StarAssign", "DivAssign", "ModAssign", "OrAssign", 
  "AndAssign", "XorAssign", "QusQusAssign", "StarStarAssign", "AndAndAssign", 
  "OrOrAssign", "ReverseOp", "AddAddOp", "SubSubOp", "Exclam", "PointPoint", 
  "PointOp", "AddOp", "SubOp", "StarOp", "DivOp", "ModOp", "OrOp", "AndOp", 
  "XorOp", "QusQusOp", "StarStarOp", "AndAndOp", "OrOrOp", "Qus", "Comma", 
  "ColonColon", "Colon", "Lf", "Semi", "Underline", "BoolLiteral", "IntLiteral", 
  "FloatLiteral", "String1Literal", "RawId", "Comment1", "Comment2", "WS"
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
       0x3, 0x5a, 0x45e, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 
       0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 
       0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 
       0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 0x1f, 0x9, 0x1f, 0x4, 0x20, 
       0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 0x9, 0x22, 0x4, 0x23, 
       0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 0x25, 0x4, 0x26, 
       0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 0x4, 0x29, 
       0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 0x2c, 
       0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
       0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 
       0x9, 0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 
       0x9, 0x35, 0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 
       0x9, 0x38, 0x4, 0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 
       0x9, 0x3b, 0x4, 0x3c, 0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 
       0x9, 0x3e, 0x4, 0x3f, 0x9, 0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 
       0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 
       0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 0x46, 0x9, 0x46, 0x4, 0x47, 
       0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 0x9, 0x49, 0x4, 0x4a, 
       0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 0x4c, 0x4, 0x4d, 
       0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 0x4, 0x50, 
       0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 0x53, 
       0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x4, 0x56, 
       0x9, 0x56, 0x4, 0x57, 0x9, 0x57, 0x4, 0x58, 0x9, 0x58, 0x4, 0x59, 
       0x9, 0x59, 0x4, 0x5a, 0x9, 0x5a, 0x4, 0x5b, 0x9, 0x5b, 0x4, 0x5c, 
       0x9, 0x5c, 0x4, 0x5d, 0x9, 0x5d, 0x4, 0x5e, 0x9, 0x5e, 0x4, 0x5f, 
       0x9, 0x5f, 0x4, 0x60, 0x9, 0x60, 0x4, 0x61, 0x9, 0x61, 0x4, 0x62, 
       0x9, 0x62, 0x4, 0x63, 0x9, 0x63, 0x4, 0x64, 0x9, 0x64, 0x4, 0x65, 
       0x9, 0x65, 0x4, 0x66, 0x9, 0x66, 0x4, 0x67, 0x9, 0x67, 0x4, 0x68, 
       0x9, 0x68, 0x4, 0x69, 0x9, 0x69, 0x4, 0x6a, 0x9, 0x6a, 0x4, 0x6b, 
       0x9, 0x6b, 0x4, 0x6c, 0x9, 0x6c, 0x4, 0x6d, 0x9, 0x6d, 0x4, 0x6e, 
       0x9, 0x6e, 0x4, 0x6f, 0x9, 0x6f, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0xf4, 0xa, 
       0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
       0x3, 0x7, 0x6, 0x7, 0xfd, 0xa, 0x7, 0xd, 0x7, 0xe, 0x7, 0xfe, 0x3, 
       0x8, 0x6, 0x8, 0x102, 0xa, 0x8, 0xd, 0x8, 0xe, 0x8, 0x103, 0x3, 0x9, 
       0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 
       0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 
       0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x118, 0xa, 
       0x11, 0x3, 0x12, 0x5, 0x12, 0x11b, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 
       0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x121, 0xa, 0x13, 0x3, 0x14, 0x5, 
       0x14, 0x124, 0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 
       0x5, 0x15, 0x12a, 0xa, 0x15, 0x3, 0x16, 0x5, 0x16, 0x12d, 0xa, 0x16, 
       0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x133, 0xa, 
       0x17, 0x3, 0x18, 0x5, 0x18, 0x136, 0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 
       0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 
       0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 
       0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 
       0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
       0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
       0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x15a, 0xa, 0x20, 0x3, 0x21, 0x3, 
       0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x162, 
       0xa, 0x21, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x166, 0xa, 0x22, 0x3, 
       0x23, 0x3, 0x23, 0x5, 0x23, 0x16a, 0xa, 0x23, 0x3, 0x24, 0x5, 0x24, 
       0x16d, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x5, 0x25, 0x172, 
       0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 
       0x3, 0x26, 0x5, 0x26, 0x17a, 0xa, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 
       0x28, 0x3, 0x28, 0x3, 0x28, 0x7, 0x28, 0x181, 0xa, 0x28, 0xc, 0x28, 
       0xe, 0x28, 0x184, 0xb, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 
       0x29, 0x5, 0x29, 0x18a, 0xa, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 
       0x3, 0x2a, 0x3, 0x2a, 0x7, 0x2a, 0x191, 0xa, 0x2a, 0xc, 0x2a, 0xe, 
       0x2a, 0x194, 0xb, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x198, 0xa, 
       0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x6, 0x2b, 0x19e, 
       0xa, 0x2b, 0xd, 0x2b, 0xe, 0x2b, 0x19f, 0x3, 0x2b, 0x3, 0x2b, 0x3, 
       0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x1a6, 0xa, 0x2c, 0x3, 0x2c, 0x7, 0x2c, 
       0x1a9, 0xa, 0x2c, 0xc, 0x2c, 0xe, 0x2c, 0x1ac, 0xb, 0x2c, 0x3, 0x2d, 
       0x5, 0x2d, 0x1af, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 
       0x2e, 0x5, 0x2e, 0x1b5, 0xa, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
       0x7, 0x2f, 0x1ba, 0xa, 0x2f, 0xc, 0x2f, 0xe, 0x2f, 0x1bd, 0xb, 0x2f, 
       0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 
       0x3, 0x31, 0x7, 0x31, 0x1c6, 0xa, 0x31, 0xc, 0x31, 0xe, 0x31, 0x1c9, 
       0xb, 0x31, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x1cd, 0xa, 0x32, 0x3, 
       0x33, 0x3, 0x33, 0x3, 0x33, 0x7, 0x33, 0x1d2, 0xa, 0x33, 0xc, 0x33, 
       0xe, 0x33, 0x1d5, 0xb, 0x33, 0x3, 0x34, 0x5, 0x34, 0x1d8, 0xa, 0x34, 
       0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x7, 0x35, 
       0x1df, 0xa, 0x35, 0xc, 0x35, 0xe, 0x35, 0x1e2, 0xb, 0x35, 0x3, 0x36, 
       0x3, 0x36, 0x7, 0x36, 0x1e6, 0xa, 0x36, 0xc, 0x36, 0xe, 0x36, 0x1e9, 
       0xb, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 0x3, 0x37, 0x7, 0x37, 
       0x1ef, 0xa, 0x37, 0xc, 0x37, 0xe, 0x37, 0x1f2, 0xb, 0x37, 0x3, 0x37, 
       0x3, 0x37, 0x3, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 
       0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x7, 0x38, 0x1ff, 0xa, 
       0x38, 0xc, 0x38, 0xe, 0x38, 0x202, 0xb, 0x38, 0x3, 0x38, 0x3, 0x38, 
       0x5, 0x38, 0x206, 0xa, 0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 
       0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x7, 0x39, 0x210, 
       0xa, 0x39, 0xc, 0x39, 0xe, 0x39, 0x213, 0xb, 0x39, 0x3, 0x39, 0x3, 
       0x39, 0x3, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x7, 
       0x3a, 0x21c, 0xa, 0x3a, 0xc, 0x3a, 0xe, 0x3a, 0x21f, 0xb, 0x3a, 0x3, 
       0x3a, 0x3, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x7, 0x3b, 0x226, 
       0xa, 0x3b, 0xc, 0x3b, 0xe, 0x3b, 0x229, 0xb, 0x3b, 0x3, 0x3b, 0x3, 
       0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 
       0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x7, 0x3c, 0x236, 0xa, 0x3c, 
       0xc, 0x3c, 0xe, 0x3c, 0x239, 0xb, 0x3c, 0x5, 0x3c, 0x23b, 0xa, 0x3c, 
       0x3, 0x3c, 0x3, 0x3c, 0x7, 0x3c, 0x23f, 0xa, 0x3c, 0xc, 0x3c, 0xe, 
       0x3c, 0x242, 0xb, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 
       0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x7, 0x3d, 
       0x24d, 0xa, 0x3d, 0xc, 0x3d, 0xe, 0x3d, 0x250, 0xb, 0x3d, 0x3, 0x3d, 
       0x3, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3f, 
       0x3, 0x3f, 0x5, 0x3f, 0x25a, 0xa, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 
       0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x5, 
       0x41, 0x264, 0xa, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x42, 
       0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x7, 0x42, 0x26d, 0xa, 0x42, 0xc, 
       0x42, 0xe, 0x42, 0x270, 0xb, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x43, 
       0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x44, 0x3, 0x44, 
       0x3, 0x44, 0x7, 0x44, 0x27c, 0xa, 0x44, 0xc, 0x44, 0xe, 0x44, 0x27f, 
       0xb, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x45, 0x3, 0x45, 
       0x3, 0x45, 0x5, 0x45, 0x287, 0xa, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 
       0x45, 0x3, 0x45, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x7, 
       0x46, 0x291, 0xa, 0x46, 0xc, 0x46, 0xe, 0x46, 0x294, 0xb, 0x46, 0x3, 
       0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 
       0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x7, 
       0x48, 0x2a2, 0xa, 0x48, 0xc, 0x48, 0xe, 0x48, 0x2a5, 0xb, 0x48, 0x3, 
       0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 
       0x49, 0x3, 0x4a, 0x5, 0x4a, 0x2af, 0xa, 0x4a, 0x3, 0x4b, 0x3, 0x4b, 
       0x3, 0x4b, 0x5, 0x4b, 0x2b4, 0xa, 0x4b, 0x3, 0x4c, 0x3, 0x4c, 0x3, 
       0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x7, 0x4c, 0x2bc, 0xa, 0x4c, 
       0xc, 0x4c, 0xe, 0x4c, 0x2bf, 0xb, 0x4c, 0x5, 0x4c, 0x2c1, 0xa, 0x4c, 
       0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 
       0x3, 0x4d, 0x3, 0x4d, 0x7, 0x4d, 0x2cb, 0xa, 0x4d, 0xc, 0x4d, 0xe, 
       0x4d, 0x2ce, 0xb, 0x4d, 0x5, 0x4d, 0x2d0, 0xa, 0x4d, 0x3, 0x4d, 0x3, 
       0x4d, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 
       0x4e, 0x5, 0x4e, 0x2da, 0xa, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4f, 
       0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x7, 0x4f, 0x2e2, 0xa, 0x4f, 0xc, 
       0x4f, 0xe, 0x4f, 0x2e5, 0xb, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x50, 
       0x3, 0x50, 0x5, 0x50, 0x2eb, 0xa, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 
       0x50, 0x3, 0x50, 0x3, 0x50, 0x7, 0x50, 0x2f2, 0xa, 0x50, 0xc, 0x50, 
       0xe, 0x50, 0x2f5, 0xb, 0x50, 0x3, 0x50, 0x3, 0x50, 0x5, 0x50, 0x2f9, 
       0xa, 0x50, 0x3, 0x51, 0x5, 0x51, 0x2fc, 0xa, 0x51, 0x3, 0x51, 0x3, 
       0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 
       0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x5, 0x51, 0x309, 0xa, 0x51, 
       0x3, 0x52, 0x3, 0x52, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 
       0x3, 0x53, 0x3, 0x53, 0x7, 0x53, 0x313, 0xa, 0x53, 0xc, 0x53, 0xe, 
       0x53, 0x316, 0xb, 0x53, 0x5, 0x53, 0x318, 0xa, 0x53, 0x3, 0x53, 0x3, 
       0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x7, 0x53, 0x320, 
       0xa, 0x53, 0xc, 0x53, 0xe, 0x53, 0x323, 0xb, 0x53, 0x3, 0x53, 0x3, 
       0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 
       0x53, 0x3, 0x53, 0x3, 0x53, 0x5, 0x53, 0x32f, 0xa, 0x53, 0x5, 0x53, 
       0x331, 0xa, 0x53, 0x3, 0x54, 0x7, 0x54, 0x334, 0xa, 0x54, 0xc, 0x54, 
       0xe, 0x54, 0x337, 0xb, 0x54, 0x3, 0x54, 0x3, 0x54, 0x7, 0x54, 0x33b, 
       0xa, 0x54, 0xc, 0x54, 0xe, 0x54, 0x33e, 0xb, 0x54, 0x3, 0x55, 0x3, 
       0x55, 0x3, 0x55, 0x3, 0x55, 0x7, 0x55, 0x344, 0xa, 0x55, 0xc, 0x55, 
       0xe, 0x55, 0x347, 0xb, 0x55, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 
       0x56, 0x7, 0x56, 0x34d, 0xa, 0x56, 0xc, 0x56, 0xe, 0x56, 0x350, 0xb, 
       0x56, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 
       0x57, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x7, 0x58, 0x35c, 
       0xa, 0x58, 0xc, 0x58, 0xe, 0x58, 0x35f, 0xb, 0x58, 0x3, 0x58, 0x3, 
       0x58, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x5a, 0x3, 
       0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x7, 0x5a, 0x36b, 0xa, 0x5a, 0xc, 0x5a, 
       0xe, 0x5a, 0x36e, 0xb, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5b, 0x5, 
       0x5b, 0x373, 0xa, 0x5b, 0x3, 0x5b, 0x5, 0x5b, 0x376, 0xa, 0x5b, 0x3, 
       0x5b, 0x3, 0x5b, 0x5, 0x5b, 0x37a, 0xa, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 
       0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 
       0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x5, 0x5c, 
       0x389, 0xa, 0x5c, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5e, 0x3, 0x5e, 0x3, 
       0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x7, 0x5e, 0x393, 0xa, 0x5e, 
       0xc, 0x5e, 0xe, 0x5e, 0x396, 0xb, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x5, 
       0x5e, 0x39a, 0xa, 0x5e, 0x3, 0x5f, 0x3, 0x5f, 0x5, 0x5f, 0x39e, 0xa, 
       0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x3, 
       0x60, 0x5, 0x60, 0x3a6, 0xa, 0x60, 0x3, 0x60, 0x5, 0x60, 0x3a9, 0xa, 
       0x60, 0x3, 0x60, 0x3, 0x60, 0x3, 0x60, 0x3, 0x60, 0x3, 0x60, 0x5, 
       0x60, 0x3b0, 0xa, 0x60, 0x3, 0x60, 0x3, 0x60, 0x3, 0x61, 0x5, 0x61, 
       0x3b5, 0xa, 0x61, 0x3, 0x61, 0x5, 0x61, 0x3b8, 0xa, 0x61, 0x3, 0x61, 
       0x3, 0x61, 0x3, 0x61, 0x5, 0x61, 0x3bd, 0xa, 0x61, 0x3, 0x61, 0x3, 
       0x61, 0x3, 0x62, 0x5, 0x62, 0x3c2, 0xa, 0x62, 0x3, 0x62, 0x3, 0x62, 
       0x3, 0x62, 0x3, 0x62, 0x3, 0x62, 0x7, 0x62, 0x3c9, 0xa, 0x62, 0xc, 
       0x62, 0xe, 0x62, 0x3cc, 0xb, 0x62, 0x3, 0x62, 0x3, 0x62, 0x3, 0x62, 
       0x3, 0x63, 0x3, 0x63, 0x5, 0x63, 0x3d3, 0xa, 0x63, 0x3, 0x63, 0x3, 
       0x63, 0x3, 0x63, 0x3, 0x64, 0x5, 0x64, 0x3d9, 0xa, 0x64, 0x3, 0x64, 
       0x5, 0x64, 0x3dc, 0xa, 0x64, 0x3, 0x64, 0x3, 0x64, 0x3, 0x64, 0x5, 
       0x64, 0x3e1, 0xa, 0x64, 0x3, 0x64, 0x3, 0x64, 0x3, 0x65, 0x5, 0x65, 
       0x3e6, 0xa, 0x65, 0x3, 0x65, 0x3, 0x65, 0x3, 0x65, 0x3, 0x65, 0x7, 
       0x65, 0x3ec, 0xa, 0x65, 0xc, 0x65, 0xe, 0x65, 0x3ef, 0xb, 0x65, 0x3, 
       0x65, 0x3, 0x65, 0x3, 0x65, 0x3, 0x66, 0x3, 0x66, 0x3, 0x66, 0x3, 
       0x66, 0x3, 0x66, 0x7, 0x66, 0x3f9, 0xa, 0x66, 0xc, 0x66, 0xe, 0x66, 
       0x3fc, 0xb, 0x66, 0x3, 0x66, 0x3, 0x66, 0x3, 0x66, 0x5, 0x66, 0x401, 
       0xa, 0x66, 0x3, 0x67, 0x5, 0x67, 0x404, 0xa, 0x67, 0x3, 0x67, 0x3, 
       0x67, 0x3, 0x67, 0x3, 0x67, 0x6, 0x67, 0x40a, 0xa, 0x67, 0xd, 0x67, 
       0xe, 0x67, 0x40b, 0x3, 0x67, 0x7, 0x67, 0x40f, 0xa, 0x67, 0xc, 0x67, 
       0xe, 0x67, 0x412, 0xb, 0x67, 0x3, 0x67, 0x3, 0x67, 0x3, 0x67, 0x3, 
       0x68, 0x5, 0x68, 0x418, 0xa, 0x68, 0x3, 0x68, 0x3, 0x68, 0x3, 0x68, 
       0x3, 0x68, 0x6, 0x68, 0x41e, 0xa, 0x68, 0xd, 0x68, 0xe, 0x68, 0x41f, 
       0x3, 0x68, 0x7, 0x68, 0x423, 0xa, 0x68, 0xc, 0x68, 0xe, 0x68, 0x426, 
       0xb, 0x68, 0x3, 0x68, 0x3, 0x68, 0x3, 0x68, 0x3, 0x69, 0x3, 0x69, 
       0x3, 0x69, 0x3, 0x69, 0x5, 0x69, 0x42f, 0xa, 0x69, 0x3, 0x69, 0x3, 
       0x69, 0x3, 0x69, 0x3, 0x6a, 0x3, 0x6a, 0x3, 0x6b, 0x3, 0x6b, 0x3, 
       0x6b, 0x3, 0x6b, 0x3, 0x6b, 0x3, 0x6b, 0x3, 0x6b, 0x3, 0x6b, 0x3, 
       0x6b, 0x3, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x3, 0x6d, 0x3, 
       0x6d, 0x3, 0x6d, 0x3, 0x6d, 0x3, 0x6e, 0x3, 0x6e, 0x3, 0x6e, 0x7, 
       0x6e, 0x44a, 0xa, 0x6e, 0xc, 0x6e, 0xe, 0x6e, 0x44d, 0xb, 0x6e, 0x3, 
       0x6e, 0x5, 0x6e, 0x450, 0xa, 0x6e, 0x3, 0x6e, 0x3, 0x6e, 0x3, 0x6e, 
       0x3, 0x6e, 0x7, 0x6e, 0x456, 0xa, 0x6e, 0xc, 0x6e, 0xe, 0x6e, 0x459, 
       0xb, 0x6e, 0x3, 0x6f, 0x3, 0x6f, 0x3, 0x6f, 0x3, 0x6f, 0x2, 0x2, 
       0x70, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 
       0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 
       0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 
       0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 
       0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 
       0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 
       0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 
       0x9c, 0x9e, 0xa0, 0xa2, 0xa4, 0xa6, 0xa8, 0xaa, 0xac, 0xae, 0xb0, 
       0xb2, 0xb4, 0xb6, 0xb8, 0xba, 0xbc, 0xbe, 0xc0, 0xc2, 0xc4, 0xc6, 
       0xc8, 0xca, 0xcc, 0xce, 0xd0, 0xd2, 0xd4, 0xd6, 0xd8, 0xda, 0xdc, 
       0x2, 0x9, 0x3, 0x2, 0x50, 0x51, 0x4, 0x2, 0x4d, 0x4d, 0x50, 0x50, 
       0x4, 0x2, 0x52, 0x52, 0x57, 0x57, 0x4, 0x2, 0x1c, 0x1c, 0x1f, 0x1f, 
       0x4, 0x2, 0x3a, 0x3d, 0x41, 0x41, 0x4, 0x2, 0x1b, 0x1b, 0x20, 0x22, 
       0x3, 0x2, 0xe, 0x10, 0x2, 0x496, 0x2, 0xde, 0x3, 0x2, 0x2, 0x2, 0x4, 
       0xe1, 0x3, 0x2, 0x2, 0x2, 0x6, 0xf3, 0x3, 0x2, 0x2, 0x2, 0x8, 0xf5, 
       0x3, 0x2, 0x2, 0x2, 0xa, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xc, 0xfc, 0x3, 
       0x2, 0x2, 0x2, 0xe, 0x101, 0x3, 0x2, 0x2, 0x2, 0x10, 0x105, 0x3, 
       0x2, 0x2, 0x2, 0x12, 0x107, 0x3, 0x2, 0x2, 0x2, 0x14, 0x109, 0x3, 
       0x2, 0x2, 0x2, 0x16, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x18, 0x10d, 0x3, 
       0x2, 0x2, 0x2, 0x1a, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x111, 0x3, 
       0x2, 0x2, 0x2, 0x1e, 0x113, 0x3, 0x2, 0x2, 0x2, 0x20, 0x115, 0x3, 
       0x2, 0x2, 0x2, 0x22, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x24, 0x11e, 0x3, 
       0x2, 0x2, 0x2, 0x26, 0x123, 0x3, 0x2, 0x2, 0x2, 0x28, 0x127, 0x3, 
       0x2, 0x2, 0x2, 0x2a, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x130, 0x3, 
       0x2, 0x2, 0x2, 0x2e, 0x135, 0x3, 0x2, 0x2, 0x2, 0x30, 0x139, 0x3, 
       0x2, 0x2, 0x2, 0x32, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x34, 0x13e, 0x3, 
       0x2, 0x2, 0x2, 0x36, 0x140, 0x3, 0x2, 0x2, 0x2, 0x38, 0x143, 0x3, 
       0x2, 0x2, 0x2, 0x3a, 0x146, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x149, 0x3, 
       0x2, 0x2, 0x2, 0x3e, 0x159, 0x3, 0x2, 0x2, 0x2, 0x40, 0x161, 0x3, 
       0x2, 0x2, 0x2, 0x42, 0x165, 0x3, 0x2, 0x2, 0x2, 0x44, 0x169, 0x3, 
       0x2, 0x2, 0x2, 0x46, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x48, 0x171, 0x3, 
       0x2, 0x2, 0x2, 0x4a, 0x179, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x17b, 0x3, 
       0x2, 0x2, 0x2, 0x4e, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x50, 0x189, 0x3, 
       0x2, 0x2, 0x2, 0x52, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x54, 0x199, 0x3, 
       0x2, 0x2, 0x2, 0x56, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x58, 0x1ae, 0x3, 
       0x2, 0x2, 0x2, 0x5a, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x1b6, 0x3, 
       0x2, 0x2, 0x2, 0x5e, 0x1be, 0x3, 0x2, 0x2, 0x2, 0x60, 0x1c2, 0x3, 
       0x2, 0x2, 0x2, 0x62, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x64, 0x1ce, 0x3, 
       0x2, 0x2, 0x2, 0x66, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x68, 0x1db, 0x3, 
       0x2, 0x2, 0x2, 0x6a, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x1ec, 0x3, 
       0x2, 0x2, 0x2, 0x6e, 0x1f6, 0x3, 0x2, 0x2, 0x2, 0x70, 0x207, 0x3, 
       0x2, 0x2, 0x2, 0x72, 0x217, 0x3, 0x2, 0x2, 0x2, 0x74, 0x222, 0x3, 
       0x2, 0x2, 0x2, 0x76, 0x22e, 0x3, 0x2, 0x2, 0x2, 0x78, 0x245, 0x3, 
       0x2, 0x2, 0x2, 0x7a, 0x253, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x259, 0x3, 
       0x2, 0x2, 0x2, 0x7e, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x80, 0x260, 0x3, 
       0x2, 0x2, 0x2, 0x82, 0x268, 0x3, 0x2, 0x2, 0x2, 0x84, 0x273, 0x3, 
       0x2, 0x2, 0x2, 0x86, 0x278, 0x3, 0x2, 0x2, 0x2, 0x88, 0x283, 0x3, 
       0x2, 0x2, 0x2, 0x8a, 0x28c, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x298, 0x3, 
       0x2, 0x2, 0x2, 0x8e, 0x29e, 0x3, 0x2, 0x2, 0x2, 0x90, 0x2a9, 0x3, 
       0x2, 0x2, 0x2, 0x92, 0x2ae, 0x3, 0x2, 0x2, 0x2, 0x94, 0x2b0, 0x3, 
       0x2, 0x2, 0x2, 0x96, 0x2b5, 0x3, 0x2, 0x2, 0x2, 0x98, 0x2c4, 0x3, 
       0x2, 0x2, 0x2, 0x9a, 0x2d3, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x2dd, 0x3, 
       0x2, 0x2, 0x2, 0x9e, 0x2e8, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x308, 0x3, 
       0x2, 0x2, 0x2, 0xa2, 0x30a, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x330, 0x3, 
       0x2, 0x2, 0x2, 0xa6, 0x335, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x33f, 0x3, 
       0x2, 0x2, 0x2, 0xaa, 0x348, 0x3, 0x2, 0x2, 0x2, 0xac, 0x351, 0x3, 
       0x2, 0x2, 0x2, 0xae, 0x357, 0x3, 0x2, 0x2, 0x2, 0xb0, 0x362, 0x3, 
       0x2, 0x2, 0x2, 0xb2, 0x366, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x379, 0x3, 
       0x2, 0x2, 0x2, 0xb6, 0x388, 0x3, 0x2, 0x2, 0x2, 0xb8, 0x38a, 0x3, 
       0x2, 0x2, 0x2, 0xba, 0x399, 0x3, 0x2, 0x2, 0x2, 0xbc, 0x39b, 0x3, 
       0x2, 0x2, 0x2, 0xbe, 0x3a5, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x3b4, 0x3, 
       0x2, 0x2, 0x2, 0xc2, 0x3c1, 0x3, 0x2, 0x2, 0x2, 0xc4, 0x3d0, 0x3, 
       0x2, 0x2, 0x2, 0xc6, 0x3d8, 0x3, 0x2, 0x2, 0x2, 0xc8, 0x3e5, 0x3, 
       0x2, 0x2, 0x2, 0xca, 0x3f3, 0x3, 0x2, 0x2, 0x2, 0xcc, 0x403, 0x3, 
       0x2, 0x2, 0x2, 0xce, 0x417, 0x3, 0x2, 0x2, 0x2, 0xd0, 0x42a, 0x3, 
       0x2, 0x2, 0x2, 0xd2, 0x433, 0x3, 0x2, 0x2, 0x2, 0xd4, 0x435, 0x3, 
       0x2, 0x2, 0x2, 0xd6, 0x43e, 0x3, 0x2, 0x2, 0x2, 0xd8, 0x442, 0x3, 
       0x2, 0x2, 0x2, 0xda, 0x44b, 0x3, 0x2, 0x2, 0x2, 0xdc, 0x45a, 0x3, 
       0x2, 0x2, 0x2, 0xde, 0xdf, 0x5, 0x8, 0x5, 0x2, 0xdf, 0xe0, 0x7, 0x2d, 
       0x2, 0x2, 0xe0, 0x3, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe2, 0x5, 0xa, 0x6, 
       0x2, 0xe2, 0xe3, 0x7, 0x2d, 0x2, 0x2, 0xe3, 0x5, 0x3, 0x2, 0x2, 0x2, 
       0xe4, 0xf4, 0x7, 0x2d, 0x2, 0x2, 0xe5, 0xf4, 0x7, 0x36, 0x2, 0x2, 
       0xe6, 0xf4, 0x7, 0x2e, 0x2, 0x2, 0xe7, 0xf4, 0x7, 0x2f, 0x2, 0x2, 
       0xe8, 0xf4, 0x7, 0x30, 0x2, 0x2, 0xe9, 0xf4, 0x7, 0x37, 0x2, 0x2, 
       0xea, 0xf4, 0x7, 0x31, 0x2, 0x2, 0xeb, 0xf4, 0x7, 0x32, 0x2, 0x2, 
       0xec, 0xf4, 0x7, 0x34, 0x2, 0x2, 0xed, 0xf4, 0x7, 0x33, 0x2, 0x2, 
       0xee, 0xf4, 0x7, 0x35, 0x2, 0x2, 0xef, 0xf4, 0x7, 0x38, 0x2, 0x2, 
       0xf0, 0xf4, 0x7, 0x39, 0x2, 0x2, 0xf1, 0xf4, 0x5, 0x2, 0x2, 0x2, 
       0xf2, 0xf4, 0x5, 0x4, 0x3, 0x2, 0xf3, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xf3, 
       0xe5, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xe7, 
       0x3, 0x2, 0x2, 0x2, 0xf3, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xe9, 0x3, 
       0x2, 0x2, 0x2, 0xf3, 0xea, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xeb, 0x3, 0x2, 
       0x2, 0x2, 0xf3, 0xec, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xed, 0x3, 0x2, 0x2, 
       0x2, 0xf3, 0xee, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xef, 0x3, 0x2, 0x2, 0x2, 
       0xf3, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf3, 
       0xf2, 0x3, 0x2, 0x2, 0x2, 0xf4, 0x7, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf6, 
       0x5, 0x14, 0xb, 0x2, 0xf6, 0xf7, 0x5, 0x14, 0xb, 0x2, 0xf7, 0x9, 
       0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x5, 0x16, 0xc, 0x2, 0xf9, 0xfa, 
       0x5, 0x16, 0xc, 0x2, 0xfa, 0xb, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfd, 0x9, 
       0x2, 0x2, 0x2, 0xfc, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xfe, 0x3, 0x2, 
       0x2, 0x2, 0xfe, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x3, 0x2, 0x2, 
       0x2, 0xff, 0xd, 0x3, 0x2, 0x2, 0x2, 0x100, 0x102, 0x9, 0x3, 0x2, 
       0x2, 0x101, 0x100, 0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 0x3, 0x2, 0x2, 
       0x2, 0x103, 0x101, 0x3, 0x2, 0x2, 0x2, 0x103, 0x104, 0x3, 0x2, 0x2, 
       0x2, 0x104, 0xf, 0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 0x7, 0x3, 0x2, 
       0x2, 0x106, 0x11, 0x3, 0x2, 0x2, 0x2, 0x107, 0x108, 0x7, 0x4, 0x2, 
       0x2, 0x108, 0x13, 0x3, 0x2, 0x2, 0x2, 0x109, 0x10a, 0x7, 0x5, 0x2, 
       0x2, 0x10a, 0x15, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x10c, 0x7, 0x6, 0x2, 
       0x2, 0x10c, 0x17, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 0x7, 0x7, 0x2, 
       0x2, 0x10e, 0x19, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x110, 0x7, 0x8, 0x2, 
       0x2, 0x110, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x111, 0x112, 0x7, 0x9, 0x2, 
       0x2, 0x112, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x113, 0x114, 0x7, 0xa, 0x2, 
       0x2, 0x114, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x115, 0x117, 0x5, 0x10, 0x9, 
       0x2, 0x116, 0x118, 0x5, 0xc, 0x7, 0x2, 0x117, 0x116, 0x3, 0x2, 0x2, 
       0x2, 0x117, 0x118, 0x3, 0x2, 0x2, 0x2, 0x118, 0x21, 0x3, 0x2, 0x2, 
       0x2, 0x119, 0x11b, 0x5, 0xc, 0x7, 0x2, 0x11a, 0x119, 0x3, 0x2, 0x2, 
       0x2, 0x11a, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 0x3, 0x2, 0x2, 
       0x2, 0x11c, 0x11d, 0x5, 0x12, 0xa, 0x2, 0x11d, 0x23, 0x3, 0x2, 0x2, 
       0x2, 0x11e, 0x120, 0x5, 0x14, 0xb, 0x2, 0x11f, 0x121, 0x5, 0xc, 0x7, 
       0x2, 0x120, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x120, 0x121, 0x3, 0x2, 0x2, 
       0x2, 0x121, 0x25, 0x3, 0x2, 0x2, 0x2, 0x122, 0x124, 0x5, 0xc, 0x7, 
       0x2, 0x123, 0x122, 0x3, 0x2, 0x2, 0x2, 0x123, 0x124, 0x3, 0x2, 0x2, 
       0x2, 0x124, 0x125, 0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 0x5, 0x16, 0xc, 
       0x2, 0x126, 0x27, 0x3, 0x2, 0x2, 0x2, 0x127, 0x129, 0x5, 0x18, 0xd, 
       0x2, 0x128, 0x12a, 0x5, 0xc, 0x7, 0x2, 0x129, 0x128, 0x3, 0x2, 0x2, 
       0x2, 0x129, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x29, 0x3, 0x2, 0x2, 
       0x2, 0x12b, 0x12d, 0x5, 0xc, 0x7, 0x2, 0x12c, 0x12b, 0x3, 0x2, 0x2, 
       0x2, 0x12c, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 0x3, 0x2, 0x2, 
       0x2, 0x12e, 0x12f, 0x5, 0x1a, 0xe, 0x2, 0x12f, 0x2b, 0x3, 0x2, 0x2, 
       0x2, 0x130, 0x132, 0x5, 0x1c, 0xf, 0x2, 0x131, 0x133, 0x5, 0xc, 0x7, 
       0x2, 0x132, 0x131, 0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 0x3, 0x2, 0x2, 
       0x2, 0x133, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x134, 0x136, 0x5, 0xc, 0x7, 
       0x2, 0x135, 0x134, 0x3, 0x2, 0x2, 0x2, 0x135, 0x136, 0x3, 0x2, 0x2, 
       0x2, 0x136, 0x137, 0x3, 0x2, 0x2, 0x2, 0x137, 0x138, 0x5, 0x1e, 0x10, 
       0x2, 0x138, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13a, 0x5, 0x14, 0xb, 
       0x2, 0x13a, 0x31, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x13c, 0x5, 0x14, 0xb, 
       0x2, 0x13c, 0x13d, 0x7, 0x2d, 0x2, 0x2, 0x13d, 0x33, 0x3, 0x2, 0x2, 
       0x2, 0x13e, 0x13f, 0x5, 0x16, 0xc, 0x2, 0x13f, 0x35, 0x3, 0x2, 0x2, 
       0x2, 0x140, 0x141, 0x5, 0x16, 0xc, 0x2, 0x141, 0x142, 0x7, 0x2d, 
       0x2, 0x2, 0x142, 0x37, 0x3, 0x2, 0x2, 0x2, 0x143, 0x144, 0x7, 0x2d, 
       0x2, 0x2, 0x144, 0x145, 0x7, 0x2d, 0x2, 0x2, 0x145, 0x39, 0x3, 0x2, 
       0x2, 0x2, 0x146, 0x147, 0x7, 0x3d, 0x2, 0x2, 0x147, 0x148, 0x7, 0x2d, 
       0x2, 0x2, 0x148, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x149, 0x14a, 0x7, 0x2d, 
       0x2, 0x2, 0x14a, 0x14b, 0x5, 0x16, 0xc, 0x2, 0x14b, 0x3d, 0x3, 0x2, 
       0x2, 0x2, 0x14c, 0x15a, 0x7, 0x40, 0x2, 0x2, 0x14d, 0x15a, 0x7, 0x41, 
       0x2, 0x2, 0x14e, 0x15a, 0x7, 0x42, 0x2, 0x2, 0x14f, 0x15a, 0x7, 0x43, 
       0x2, 0x2, 0x150, 0x15a, 0x7, 0x49, 0x2, 0x2, 0x151, 0x15a, 0x7, 0x44, 
       0x2, 0x2, 0x152, 0x15a, 0x7, 0x46, 0x2, 0x2, 0x153, 0x15a, 0x7, 0x45, 
       0x2, 0x2, 0x154, 0x15a, 0x7, 0x47, 0x2, 0x2, 0x155, 0x15a, 0x7, 0x4a, 
       0x2, 0x2, 0x156, 0x15a, 0x7, 0x4b, 0x2, 0x2, 0x157, 0x15a, 0x5, 0x8, 
       0x5, 0x2, 0x158, 0x15a, 0x5, 0xa, 0x6, 0x2, 0x159, 0x14c, 0x3, 0x2, 
       0x2, 0x2, 0x159, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x159, 0x14e, 0x3, 0x2, 
       0x2, 0x2, 0x159, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x159, 0x150, 0x3, 0x2, 
       0x2, 0x2, 0x159, 0x151, 0x3, 0x2, 0x2, 0x2, 0x159, 0x152, 0x3, 0x2, 
       0x2, 0x2, 0x159, 0x153, 0x3, 0x2, 0x2, 0x2, 0x159, 0x154, 0x3, 0x2, 
       0x2, 0x2, 0x159, 0x155, 0x3, 0x2, 0x2, 0x2, 0x159, 0x156, 0x3, 0x2, 
       0x2, 0x2, 0x159, 0x157, 0x3, 0x2, 0x2, 0x2, 0x159, 0x158, 0x3, 0x2, 
       0x2, 0x2, 0x15a, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x162, 0x5, 0x30, 
       0x19, 0x2, 0x15c, 0x162, 0x5, 0x32, 0x1a, 0x2, 0x15d, 0x162, 0x5, 
       0x34, 0x1b, 0x2, 0x15e, 0x162, 0x5, 0x36, 0x1c, 0x2, 0x15f, 0x162, 
       0x5, 0x38, 0x1d, 0x2, 0x160, 0x162, 0x5, 0x3a, 0x1e, 0x2, 0x161, 
       0x15b, 0x3, 0x2, 0x2, 0x2, 0x161, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x161, 
       0x15d, 0x3, 0x2, 0x2, 0x2, 0x161, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x161, 
       0x15f, 0x3, 0x2, 0x2, 0x2, 0x161, 0x160, 0x3, 0x2, 0x2, 0x2, 0x162, 
       0x41, 0x3, 0x2, 0x2, 0x2, 0x163, 0x166, 0x7, 0x48, 0x2, 0x2, 0x164, 
       0x166, 0x5, 0x40, 0x21, 0x2, 0x165, 0x163, 0x3, 0x2, 0x2, 0x2, 0x165, 
       0x164, 0x3, 0x2, 0x2, 0x2, 0x166, 0x43, 0x3, 0x2, 0x2, 0x2, 0x167, 
       0x16a, 0x5, 0x3e, 0x20, 0x2, 0x168, 0x16a, 0x5, 0x42, 0x22, 0x2, 
       0x169, 0x167, 0x3, 0x2, 0x2, 0x2, 0x169, 0x168, 0x3, 0x2, 0x2, 0x2, 
       0x16a, 0x45, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x16d, 0x7, 0x41, 0x2, 0x2, 
       0x16c, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x16d, 0x3, 0x2, 0x2, 0x2, 
       0x16d, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x16f, 0x7, 0x54, 0x2, 0x2, 
       0x16f, 0x47, 0x3, 0x2, 0x2, 0x2, 0x170, 0x172, 0x7, 0x41, 0x2, 0x2, 
       0x171, 0x170, 0x3, 0x2, 0x2, 0x2, 0x171, 0x172, 0x3, 0x2, 0x2, 0x2, 
       0x172, 0x173, 0x3, 0x2, 0x2, 0x2, 0x173, 0x174, 0x7, 0x55, 0x2, 0x2, 
       0x174, 0x49, 0x3, 0x2, 0x2, 0x2, 0x175, 0x17a, 0x7, 0x53, 0x2, 0x2, 
       0x176, 0x17a, 0x5, 0x46, 0x24, 0x2, 0x177, 0x17a, 0x5, 0x48, 0x25, 
       0x2, 0x178, 0x17a, 0x7, 0x56, 0x2, 0x2, 0x179, 0x175, 0x3, 0x2, 0x2, 
       0x2, 0x179, 0x176, 0x3, 0x2, 0x2, 0x2, 0x179, 0x177, 0x3, 0x2, 0x2, 
       0x2, 0x179, 0x178, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x4b, 0x3, 0x2, 0x2, 
       0x2, 0x17b, 0x17c, 0x9, 0x4, 0x2, 0x2, 0x17c, 0x4d, 0x3, 0x2, 0x2, 
       0x2, 0x17d, 0x182, 0x5, 0x4c, 0x27, 0x2, 0x17e, 0x17f, 0x7, 0x3f, 
       0x2, 0x2, 0x17f, 0x181, 0x5, 0x4c, 0x27, 0x2, 0x180, 0x17e, 0x3, 
       0x2, 0x2, 0x2, 0x181, 0x184, 0x3, 0x2, 0x2, 0x2, 0x182, 0x180, 0x3, 
       0x2, 0x2, 0x2, 0x182, 0x183, 0x3, 0x2, 0x2, 0x2, 0x183, 0x4f, 0x3, 
       0x2, 0x2, 0x2, 0x184, 0x182, 0x3, 0x2, 0x2, 0x2, 0x185, 0x186, 0x5, 
       0x20, 0x11, 0x2, 0x186, 0x187, 0x5, 0x22, 0x12, 0x2, 0x187, 0x18a, 
       0x3, 0x2, 0x2, 0x2, 0x188, 0x18a, 0x7, 0x4c, 0x2, 0x2, 0x189, 0x185, 
       0x3, 0x2, 0x2, 0x2, 0x189, 0x188, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x51, 
       0x3, 0x2, 0x2, 0x2, 0x18b, 0x197, 0x5, 0x4e, 0x28, 0x2, 0x18c, 0x18d, 
       0x5, 0x24, 0x13, 0x2, 0x18d, 0x192, 0x5, 0x56, 0x2c, 0x2, 0x18e, 
       0x18f, 0x7, 0x4d, 0x2, 0x2, 0x18f, 0x191, 0x5, 0x56, 0x2c, 0x2, 0x190, 
       0x18e, 0x3, 0x2, 0x2, 0x2, 0x191, 0x194, 0x3, 0x2, 0x2, 0x2, 0x192, 
       0x190, 0x3, 0x2, 0x2, 0x2, 0x192, 0x193, 0x3, 0x2, 0x2, 0x2, 0x193, 
       0x195, 0x3, 0x2, 0x2, 0x2, 0x194, 0x192, 0x3, 0x2, 0x2, 0x2, 0x195, 
       0x196, 0x5, 0x26, 0x14, 0x2, 0x196, 0x198, 0x3, 0x2, 0x2, 0x2, 0x197, 
       0x18c, 0x3, 0x2, 0x2, 0x2, 0x197, 0x198, 0x3, 0x2, 0x2, 0x2, 0x198, 
       0x53, 0x3, 0x2, 0x2, 0x2, 0x199, 0x19a, 0x5, 0x2c, 0x17, 0x2, 0x19a, 
       0x19d, 0x5, 0x5a, 0x2e, 0x2, 0x19b, 0x19c, 0x7, 0x4d, 0x2, 0x2, 0x19c, 
       0x19e, 0x5, 0x5a, 0x2e, 0x2, 0x19d, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x19e, 
       0x19f, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x19f, 
       0x1a0, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x1a1, 
       0x1a2, 0x5, 0x2e, 0x18, 0x2, 0x1a2, 0x55, 0x3, 0x2, 0x2, 0x2, 0x1a3, 
       0x1a6, 0x5, 0x52, 0x2a, 0x2, 0x1a4, 0x1a6, 0x5, 0x54, 0x2b, 0x2, 
       0x1a5, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a5, 0x1a4, 0x3, 0x2, 0x2, 0x2, 
       0x1a6, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a9, 0x5, 0x50, 0x29, 
       0x2, 0x1a8, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1ac, 0x3, 0x2, 0x2, 
       0x2, 0x1aa, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1ab, 0x3, 0x2, 0x2, 
       0x2, 0x1ab, 0x57, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1aa, 0x3, 0x2, 0x2, 
       0x2, 0x1ad, 0x1af, 0x9, 0x5, 0x2, 0x2, 0x1ae, 0x1ad, 0x3, 0x2, 0x2, 
       0x2, 0x1ae, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x1b0, 0x3, 0x2, 0x2, 
       0x2, 0x1b0, 0x1b1, 0x5, 0x56, 0x2c, 0x2, 0x1b1, 0x59, 0x3, 0x2, 0x2, 
       0x2, 0x1b2, 0x1b4, 0x5, 0x56, 0x2c, 0x2, 0x1b3, 0x1b5, 0x5, 0x4c, 
       0x27, 0x2, 0x1b4, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1b5, 0x3, 0x2, 
       0x2, 0x2, 0x1b5, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1bb, 0x5, 0x5a, 
       0x2e, 0x2, 0x1b7, 0x1b8, 0x7, 0x4d, 0x2, 0x2, 0x1b8, 0x1ba, 0x5, 
       0x5a, 0x2e, 0x2, 0x1b9, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1ba, 0x1bd, 
       0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1bc, 
       0x3, 0x2, 0x2, 0x2, 0x1bc, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1bb, 
       0x3, 0x2, 0x2, 0x2, 0x1be, 0x1bf, 0x5, 0x4c, 0x27, 0x2, 0x1bf, 0x1c0, 
       0x7, 0x4f, 0x2, 0x2, 0x1c0, 0x1c1, 0x5, 0x58, 0x2d, 0x2, 0x1c1, 0x5f, 
       0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c7, 0x5, 0x5e, 0x30, 0x2, 0x1c3, 0x1c4, 
       0x7, 0x4d, 0x2, 0x2, 0x1c4, 0x1c6, 0x5, 0x5e, 0x30, 0x2, 0x1c5, 0x1c3, 
       0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1c5, 
       0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1c8, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x61, 
       0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1cc, 
       0x5, 0x58, 0x2d, 0x2, 0x1cb, 0x1cd, 0x5, 0x4c, 0x27, 0x2, 0x1cc, 
       0x1cb, 0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1cd, 
       0x63, 0x3, 0x2, 0x2, 0x2, 0x1ce, 0x1d3, 0x5, 0x62, 0x32, 0x2, 0x1cf, 
       0x1d0, 0x7, 0x4d, 0x2, 0x2, 0x1d0, 0x1d2, 0x5, 0x62, 0x32, 0x2, 0x1d1, 
       0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1d2, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d3, 
       0x1d1, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d4, 
       0x65, 0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1d3, 0x3, 0x2, 0x2, 0x2, 0x1d6, 
       0x1d8, 0x5, 0x58, 0x2d, 0x2, 0x1d7, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1d7, 
       0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1d9, 
       0x1da, 0x5, 0x4c, 0x27, 0x2, 0x1da, 0x67, 0x3, 0x2, 0x2, 0x2, 0x1db, 
       0x1e0, 0x5, 0x66, 0x34, 0x2, 0x1dc, 0x1dd, 0x7, 0x4d, 0x2, 0x2, 0x1dd, 
       0x1df, 0x5, 0x66, 0x34, 0x2, 0x1de, 0x1dc, 0x3, 0x2, 0x2, 0x2, 0x1df, 
       0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1de, 0x3, 0x2, 0x2, 0x2, 0x1e0, 
       0x1e1, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x69, 0x3, 0x2, 0x2, 0x2, 0x1e2, 
       0x1e0, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e7, 0x5, 0x28, 0x15, 0x2, 0x1e4, 
       0x1e6, 0x5, 0xb6, 0x5c, 0x2, 0x1e5, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1e6, 
       0x1e9, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x1e7, 
       0x1e8, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1ea, 0x3, 0x2, 0x2, 0x2, 0x1e9, 
       0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1eb, 0x5, 0x2a, 0x16, 0x2, 0x1eb, 
       0x6b, 0x3, 0x2, 0x2, 0x2, 0x1ec, 0x1f0, 0x5, 0x28, 0x15, 0x2, 0x1ed, 
       0x1ef, 0x5, 0xb6, 0x5c, 0x2, 0x1ee, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1ef, 
       0x1f2, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1ee, 0x3, 0x2, 0x2, 0x2, 0x1f0, 
       0x1f1, 0x3, 0x2, 0x2, 0x2, 0x1f1, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x1f2, 
       0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f4, 0x5, 0xaa, 0x56, 0x2, 0x1f4, 
       0x1f5, 0x5, 0x2a, 0x16, 0x2, 0x1f5, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x1f6, 
       0x1f7, 0x7, 0x19, 0x2, 0x2, 0x1f7, 0x1f8, 0x5, 0xaa, 0x56, 0x2, 0x1f8, 
       0x200, 0x5, 0x6a, 0x36, 0x2, 0x1f9, 0x1fa, 0x7, 0x15, 0x2, 0x2, 0x1fa, 
       0x1fb, 0x7, 0x19, 0x2, 0x2, 0x1fb, 0x1fc, 0x5, 0xaa, 0x56, 0x2, 0x1fc, 
       0x1fd, 0x5, 0x6a, 0x36, 0x2, 0x1fd, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x1fe, 
       0x1f9, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x202, 0x3, 0x2, 0x2, 0x2, 0x200, 
       0x1fe, 0x3, 0x2, 0x2, 0x2, 0x200, 0x201, 0x3, 0x2, 0x2, 0x2, 0x201, 
       0x205, 0x3, 0x2, 0x2, 0x2, 0x202, 0x200, 0x3, 0x2, 0x2, 0x2, 0x203, 
       0x204, 0x7, 0x15, 0x2, 0x2, 0x204, 0x206, 0x5, 0x6a, 0x36, 0x2, 0x205, 
       0x203, 0x3, 0x2, 0x2, 0x2, 0x205, 0x206, 0x3, 0x2, 0x2, 0x2, 0x206, 
       0x6f, 0x3, 0x2, 0x2, 0x2, 0x207, 0x208, 0x7, 0x19, 0x2, 0x2, 0x208, 
       0x209, 0x5, 0xaa, 0x56, 0x2, 0x209, 0x211, 0x5, 0x6c, 0x37, 0x2, 
       0x20a, 0x20b, 0x7, 0x15, 0x2, 0x2, 0x20b, 0x20c, 0x7, 0x19, 0x2, 
       0x2, 0x20c, 0x20d, 0x5, 0xaa, 0x56, 0x2, 0x20d, 0x20e, 0x5, 0x6c, 
       0x37, 0x2, 0x20e, 0x210, 0x3, 0x2, 0x2, 0x2, 0x20f, 0x20a, 0x3, 0x2, 
       0x2, 0x2, 0x210, 0x213, 0x3, 0x2, 0x2, 0x2, 0x211, 0x20f, 0x3, 0x2, 
       0x2, 0x2, 0x211, 0x212, 0x3, 0x2, 0x2, 0x2, 0x212, 0x214, 0x3, 0x2, 
       0x2, 0x2, 0x213, 0x211, 0x3, 0x2, 0x2, 0x2, 0x214, 0x215, 0x7, 0x15, 
       0x2, 0x2, 0x215, 0x216, 0x5, 0x6c, 0x37, 0x2, 0x216, 0x71, 0x3, 0x2, 
       0x2, 0x2, 0x217, 0x218, 0x7, 0x2c, 0x2, 0x2, 0x218, 0x219, 0x5, 0xaa, 
       0x56, 0x2, 0x219, 0x21d, 0x5, 0x28, 0x15, 0x2, 0x21a, 0x21c, 0x5, 
       0xb6, 0x5c, 0x2, 0x21b, 0x21a, 0x3, 0x2, 0x2, 0x2, 0x21c, 0x21f, 
       0x3, 0x2, 0x2, 0x2, 0x21d, 0x21b, 0x3, 0x2, 0x2, 0x2, 0x21d, 0x21e, 
       0x3, 0x2, 0x2, 0x2, 0x21e, 0x220, 0x3, 0x2, 0x2, 0x2, 0x21f, 0x21d, 
       0x3, 0x2, 0x2, 0x2, 0x220, 0x221, 0x5, 0x2a, 0x16, 0x2, 0x221, 0x73, 
       0x3, 0x2, 0x2, 0x2, 0x222, 0x223, 0x7, 0x14, 0x2, 0x2, 0x223, 0x227, 
       0x5, 0x28, 0x15, 0x2, 0x224, 0x226, 0x5, 0xb6, 0x5c, 0x2, 0x225, 
       0x224, 0x3, 0x2, 0x2, 0x2, 0x226, 0x229, 0x3, 0x2, 0x2, 0x2, 0x227, 
       0x225, 0x3, 0x2, 0x2, 0x2, 0x227, 0x228, 0x3, 0x2, 0x2, 0x2, 0x228, 
       0x22a, 0x3, 0x2, 0x2, 0x2, 0x229, 0x227, 0x3, 0x2, 0x2, 0x2, 0x22a, 
       0x22b, 0x5, 0x2a, 0x16, 0x2, 0x22b, 0x22c, 0x7, 0x2c, 0x2, 0x2, 0x22c, 
       0x22d, 0x5, 0xaa, 0x56, 0x2, 0x22d, 0x75, 0x3, 0x2, 0x2, 0x2, 0x22e, 
       0x22f, 0x7, 0x18, 0x2, 0x2, 0x22f, 0x230, 0x5, 0xb6, 0x5c, 0x2, 0x230, 
       0x231, 0x5, 0xaa, 0x56, 0x2, 0x231, 0x23a, 0x7, 0x51, 0x2, 0x2, 0x232, 
       0x237, 0x5, 0xaa, 0x56, 0x2, 0x233, 0x234, 0x7, 0x4d, 0x2, 0x2, 0x234, 
       0x236, 0x5, 0xaa, 0x56, 0x2, 0x235, 0x233, 0x3, 0x2, 0x2, 0x2, 0x236, 
       0x239, 0x3, 0x2, 0x2, 0x2, 0x237, 0x235, 0x3, 0x2, 0x2, 0x2, 0x237, 
       0x238, 0x3, 0x2, 0x2, 0x2, 0x238, 0x23b, 0x3, 0x2, 0x2, 0x2, 0x239, 
       0x237, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x232, 0x3, 0x2, 0x2, 0x2, 0x23a, 
       0x23b, 0x3, 0x2, 0x2, 0x2, 0x23b, 0x23c, 0x3, 0x2, 0x2, 0x2, 0x23c, 
       0x240, 0x5, 0x28, 0x15, 0x2, 0x23d, 0x23f, 0x5, 0xb6, 0x5c, 0x2, 
       0x23e, 0x23d, 0x3, 0x2, 0x2, 0x2, 0x23f, 0x242, 0x3, 0x2, 0x2, 0x2, 
       0x240, 0x23e, 0x3, 0x2, 0x2, 0x2, 0x240, 0x241, 0x3, 0x2, 0x2, 0x2, 
       0x241, 0x243, 0x3, 0x2, 0x2, 0x2, 0x242, 0x240, 0x3, 0x2, 0x2, 0x2, 
       0x243, 0x244, 0x5, 0x2a, 0x16, 0x2, 0x244, 0x77, 0x3, 0x2, 0x2, 0x2, 
       0x245, 0x246, 0x7, 0x18, 0x2, 0x2, 0x246, 0x247, 0x5, 0x56, 0x2c, 
       0x2, 0x247, 0x248, 0x5, 0x4c, 0x27, 0x2, 0x248, 0x249, 0x7, 0x4f, 
       0x2, 0x2, 0x249, 0x24a, 0x5, 0xaa, 0x56, 0x2, 0x24a, 0x24e, 0x5, 
       0x28, 0x15, 0x2, 0x24b, 0x24d, 0x5, 0xb6, 0x5c, 0x2, 0x24c, 0x24b, 
       0x3, 0x2, 0x2, 0x2, 0x24d, 0x250, 0x3, 0x2, 0x2, 0x2, 0x24e, 0x24c, 
       0x3, 0x2, 0x2, 0x2, 0x24e, 0x24f, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x251, 
       0x3, 0x2, 0x2, 0x2, 0x250, 0x24e, 0x3, 0x2, 0x2, 0x2, 0x251, 0x252, 
       0x5, 0x2a, 0x16, 0x2, 0x252, 0x79, 0x3, 0x2, 0x2, 0x2, 0x253, 0x254, 
       0x7, 0x52, 0x2, 0x2, 0x254, 0x255, 0x5, 0x3c, 0x1f, 0x2, 0x255, 0x256, 
       0x5, 0xb6, 0x5c, 0x2, 0x256, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x257, 0x25a, 
       0x5, 0x6c, 0x37, 0x2, 0x258, 0x25a, 0x5, 0xaa, 0x56, 0x2, 0x259, 
       0x257, 0x3, 0x2, 0x2, 0x2, 0x259, 0x258, 0x3, 0x2, 0x2, 0x2, 0x25a, 
       0x7d, 0x3, 0x2, 0x2, 0x2, 0x25b, 0x25c, 0x7, 0x52, 0x2, 0x2, 0x25c, 
       0x25d, 0x5, 0x3c, 0x1f, 0x2, 0x25d, 0x25e, 0x5, 0x7c, 0x3f, 0x2, 
       0x25e, 0x25f, 0x7, 0x4d, 0x2, 0x2, 0x25f, 0x7f, 0x3, 0x2, 0x2, 0x2, 
       0x260, 0x263, 0x5, 0xaa, 0x56, 0x2, 0x261, 0x262, 0x7, 0x2b, 0x2, 
       0x2, 0x262, 0x264, 0x5, 0xaa, 0x56, 0x2, 0x263, 0x261, 0x3, 0x2, 
       0x2, 0x2, 0x263, 0x264, 0x3, 0x2, 0x2, 0x2, 0x264, 0x265, 0x3, 0x2, 
       0x2, 0x2, 0x265, 0x266, 0x5, 0x3c, 0x1f, 0x2, 0x266, 0x267, 0x5, 
       0xb6, 0x5c, 0x2, 0x267, 0x81, 0x3, 0x2, 0x2, 0x2, 0x268, 0x269, 0x7, 
       0x27, 0x2, 0x2, 0x269, 0x26a, 0x5, 0xaa, 0x56, 0x2, 0x26a, 0x26e, 
       0x5, 0x28, 0x15, 0x2, 0x26b, 0x26d, 0x5, 0x80, 0x41, 0x2, 0x26c, 
       0x26b, 0x3, 0x2, 0x2, 0x2, 0x26d, 0x270, 0x3, 0x2, 0x2, 0x2, 0x26e, 
       0x26c, 0x3, 0x2, 0x2, 0x2, 0x26e, 0x26f, 0x3, 0x2, 0x2, 0x2, 0x26f, 
       0x271, 0x3, 0x2, 0x2, 0x2, 0x270, 0x26e, 0x3, 0x2, 0x2, 0x2, 0x271, 
       0x272, 0x5, 0x2a, 0x16, 0x2, 0x272, 0x83, 0x3, 0x2, 0x2, 0x2, 0x273, 
       0x274, 0x7, 0x2b, 0x2, 0x2, 0x274, 0x275, 0x5, 0xaa, 0x56, 0x2, 0x275, 
       0x276, 0x5, 0x3c, 0x1f, 0x2, 0x276, 0x277, 0x5, 0xb6, 0x5c, 0x2, 
       0x277, 0x85, 0x3, 0x2, 0x2, 0x2, 0x278, 0x279, 0x7, 0x27, 0x2, 0x2, 
       0x279, 0x27d, 0x5, 0x28, 0x15, 0x2, 0x27a, 0x27c, 0x5, 0x84, 0x43, 
       0x2, 0x27b, 0x27a, 0x3, 0x2, 0x2, 0x2, 0x27c, 0x27f, 0x3, 0x2, 0x2, 
       0x2, 0x27d, 0x27b, 0x3, 0x2, 0x2, 0x2, 0x27d, 0x27e, 0x3, 0x2, 0x2, 
       0x2, 0x27e, 0x280, 0x3, 0x2, 0x2, 0x2, 0x27f, 0x27d, 0x3, 0x2, 0x2, 
       0x2, 0x280, 0x281, 0x5, 0x7a, 0x3e, 0x2, 0x281, 0x282, 0x5, 0x2a, 
       0x16, 0x2, 0x282, 0x87, 0x3, 0x2, 0x2, 0x2, 0x283, 0x286, 0x5, 0xaa, 
       0x56, 0x2, 0x284, 0x285, 0x7, 0x2b, 0x2, 0x2, 0x285, 0x287, 0x5, 
       0xaa, 0x56, 0x2, 0x286, 0x284, 0x3, 0x2, 0x2, 0x2, 0x286, 0x287, 
       0x3, 0x2, 0x2, 0x2, 0x287, 0x288, 0x3, 0x2, 0x2, 0x2, 0x288, 0x289, 
       0x5, 0x3c, 0x1f, 0x2, 0x289, 0x28a, 0x5, 0x7c, 0x3f, 0x2, 0x28a, 
       0x28b, 0x7, 0x4d, 0x2, 0x2, 0x28b, 0x89, 0x3, 0x2, 0x2, 0x2, 0x28c, 
       0x28d, 0x7, 0x27, 0x2, 0x2, 0x28d, 0x28e, 0x5, 0xaa, 0x56, 0x2, 0x28e, 
       0x292, 0x5, 0x28, 0x15, 0x2, 0x28f, 0x291, 0x5, 0x88, 0x45, 0x2, 
       0x290, 0x28f, 0x3, 0x2, 0x2, 0x2, 0x291, 0x294, 0x3, 0x2, 0x2, 0x2, 
       0x292, 0x290, 0x3, 0x2, 0x2, 0x2, 0x292, 0x293, 0x3, 0x2, 0x2, 0x2, 
       0x293, 0x295, 0x3, 0x2, 0x2, 0x2, 0x294, 0x292, 0x3, 0x2, 0x2, 0x2, 
       0x295, 0x296, 0x5, 0x7e, 0x40, 0x2, 0x296, 0x297, 0x5, 0x2a, 0x16, 
       0x2, 0x297, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x298, 0x299, 0x7, 0x2b, 0x2, 
       0x2, 0x299, 0x29a, 0x5, 0xaa, 0x56, 0x2, 0x29a, 0x29b, 0x5, 0x3c, 
       0x1f, 0x2, 0x29b, 0x29c, 0x5, 0x7c, 0x3f, 0x2, 0x29c, 0x29d, 0x7, 
       0x4d, 0x2, 0x2, 0x29d, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x29e, 0x29f, 0x7, 
       0x27, 0x2, 0x2, 0x29f, 0x2a3, 0x5, 0x28, 0x15, 0x2, 0x2a0, 0x2a2, 
       0x5, 0x8c, 0x47, 0x2, 0x2a1, 0x2a0, 0x3, 0x2, 0x2, 0x2, 0x2a2, 0x2a5, 
       0x3, 0x2, 0x2, 0x2, 0x2a3, 0x2a1, 0x3, 0x2, 0x2, 0x2, 0x2a3, 0x2a4, 
       0x3, 0x2, 0x2, 0x2, 0x2a4, 0x2a6, 0x3, 0x2, 0x2, 0x2, 0x2a5, 0x2a3, 
       0x3, 0x2, 0x2, 0x2, 0x2a6, 0x2a7, 0x5, 0x7e, 0x40, 0x2, 0x2a7, 0x2a8, 
       0x5, 0x2a, 0x16, 0x2, 0x2a8, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x2a9, 0x2aa, 
       0x5, 0x2c, 0x17, 0x2, 0x2aa, 0x2ab, 0x5, 0xaa, 0x56, 0x2, 0x2ab, 
       0x2ac, 0x5, 0x2e, 0x18, 0x2, 0x2ac, 0x91, 0x3, 0x2, 0x2, 0x2, 0x2ad, 
       0x2af, 0x5, 0xaa, 0x56, 0x2, 0x2ae, 0x2ad, 0x3, 0x2, 0x2, 0x2, 0x2ae, 
       0x2af, 0x3, 0x2, 0x2, 0x2, 0x2af, 0x93, 0x3, 0x2, 0x2, 0x2, 0x2b0, 
       0x2b3, 0x5, 0x4c, 0x27, 0x2, 0x2b1, 0x2b2, 0x7, 0x2d, 0x2, 0x2, 0x2b2, 
       0x2b4, 0x5, 0xa8, 0x55, 0x2, 0x2b3, 0x2b1, 0x3, 0x2, 0x2, 0x2, 0x2b3, 
       0x2b4, 0x3, 0x2, 0x2, 0x2, 0x2b4, 0x95, 0x3, 0x2, 0x2, 0x2, 0x2b5, 
       0x2b6, 0x7, 0x1e, 0x2, 0x2, 0x2b6, 0x2b7, 0x5, 0x52, 0x2a, 0x2, 0x2b7, 
       0x2c0, 0x5, 0x28, 0x15, 0x2, 0x2b8, 0x2bd, 0x5, 0x94, 0x4b, 0x2, 
       0x2b9, 0x2ba, 0x7, 0x4d, 0x2, 0x2, 0x2ba, 0x2bc, 0x5, 0x94, 0x4b, 
       0x2, 0x2bb, 0x2b9, 0x3, 0x2, 0x2, 0x2, 0x2bc, 0x2bf, 0x3, 0x2, 0x2, 
       0x2, 0x2bd, 0x2bb, 0x3, 0x2, 0x2, 0x2, 0x2bd, 0x2be, 0x3, 0x2, 0x2, 
       0x2, 0x2be, 0x2c1, 0x3, 0x2, 0x2, 0x2, 0x2bf, 0x2bd, 0x3, 0x2, 0x2, 
       0x2, 0x2c0, 0x2b8, 0x3, 0x2, 0x2, 0x2, 0x2c0, 0x2c1, 0x3, 0x2, 0x2, 
       0x2, 0x2c1, 0x2c2, 0x3, 0x2, 0x2, 0x2, 0x2c2, 0x2c3, 0x5, 0x2a, 0x16, 
       0x2, 0x2c3, 0x97, 0x3, 0x2, 0x2, 0x2, 0x2c4, 0x2c5, 0x7, 0x1e, 0x2, 
       0x2, 0x2c5, 0x2c6, 0x5, 0x52, 0x2a, 0x2, 0x2c6, 0x2cf, 0x5, 0x2c, 
       0x17, 0x2, 0x2c7, 0x2cc, 0x5, 0xaa, 0x56, 0x2, 0x2c8, 0x2c9, 0x7, 
       0x4d, 0x2, 0x2, 0x2c9, 0x2cb, 0x5, 0xaa, 0x56, 0x2, 0x2ca, 0x2c8, 
       0x3, 0x2, 0x2, 0x2, 0x2cb, 0x2ce, 0x3, 0x2, 0x2, 0x2, 0x2cc, 0x2ca, 
       0x3, 0x2, 0x2, 0x2, 0x2cc, 0x2cd, 0x3, 0x2, 0x2, 0x2, 0x2cd, 0x2d0, 
       0x3, 0x2, 0x2, 0x2, 0x2ce, 0x2cc, 0x3, 0x2, 0x2, 0x2, 0x2cf, 0x2c7, 
       0x3, 0x2, 0x2, 0x2, 0x2cf, 0x2d0, 0x3, 0x2, 0x2, 0x2, 0x2d0, 0x2d1, 
       0x3, 0x2, 0x2, 0x2, 0x2d1, 0x2d2, 0x5, 0x2e, 0x18, 0x2, 0x2d2, 0x99, 
       0x3, 0x2, 0x2, 0x2, 0x2d3, 0x2d4, 0x5, 0x20, 0x11, 0x2, 0x2d4, 0x2d5, 
       0x5, 0xaa, 0x56, 0x2, 0x2d5, 0x2d6, 0x7, 0x3e, 0x2, 0x2, 0x2d6, 0x2d9, 
       0x5, 0xaa, 0x56, 0x2, 0x2d7, 0x2d8, 0x7, 0x26, 0x2, 0x2, 0x2d8, 0x2da, 
       0x5, 0xaa, 0x56, 0x2, 0x2d9, 0x2d7, 0x3, 0x2, 0x2, 0x2, 0x2d9, 0x2da, 
       0x3, 0x2, 0x2, 0x2, 0x2da, 0x2db, 0x3, 0x2, 0x2, 0x2, 0x2db, 0x2dc, 
       0x5, 0x22, 0x12, 0x2, 0x2dc, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x2dd, 0x2de, 
       0x5, 0x20, 0x11, 0x2, 0x2de, 0x2e3, 0x5, 0xaa, 0x56, 0x2, 0x2df, 
       0x2e0, 0x7, 0x4d, 0x2, 0x2, 0x2e0, 0x2e2, 0x5, 0xaa, 0x56, 0x2, 0x2e1, 
       0x2df, 0x3, 0x2, 0x2, 0x2, 0x2e2, 0x2e5, 0x3, 0x2, 0x2, 0x2, 0x2e3, 
       0x2e1, 0x3, 0x2, 0x2, 0x2, 0x2e3, 0x2e4, 0x3, 0x2, 0x2, 0x2, 0x2e4, 
       0x2e6, 0x3, 0x2, 0x2, 0x2, 0x2e5, 0x2e3, 0x3, 0x2, 0x2, 0x2, 0x2e6, 
       0x2e7, 0x5, 0x22, 0x12, 0x2, 0x2e7, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x2e8, 
       0x2ea, 0x5, 0x2c, 0x17, 0x2, 0x2e9, 0x2eb, 0x5, 0x68, 0x35, 0x2, 
       0x2ea, 0x2e9, 0x3, 0x2, 0x2, 0x2, 0x2ea, 0x2eb, 0x3, 0x2, 0x2, 0x2, 
       0x2eb, 0x2ec, 0x3, 0x2, 0x2, 0x2, 0x2ec, 0x2ed, 0x5, 0x2e, 0x18, 
       0x2, 0x2ed, 0x2f8, 0x5, 0x3c, 0x1f, 0x2, 0x2ee, 0x2f9, 0x5, 0xaa, 
       0x56, 0x2, 0x2ef, 0x2f3, 0x5, 0x28, 0x15, 0x2, 0x2f0, 0x2f2, 0x5, 
       0xb6, 0x5c, 0x2, 0x2f1, 0x2f0, 0x3, 0x2, 0x2, 0x2, 0x2f2, 0x2f5, 
       0x3, 0x2, 0x2, 0x2, 0x2f3, 0x2f1, 0x3, 0x2, 0x2, 0x2, 0x2f3, 0x2f4, 
       0x3, 0x2, 0x2, 0x2, 0x2f4, 0x2f6, 0x3, 0x2, 0x2, 0x2, 0x2f5, 0x2f3, 
       0x3, 0x2, 0x2, 0x2, 0x2f6, 0x2f7, 0x5, 0x2a, 0x16, 0x2, 0x2f7, 0x2f9, 
       0x3, 0x2, 0x2, 0x2, 0x2f8, 0x2ee, 0x3, 0x2, 0x2, 0x2, 0x2f8, 0x2ef, 
       0x3, 0x2, 0x2, 0x2, 0x2f9, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x2fa, 0x2fc, 
       0x7, 0x4e, 0x2, 0x2, 0x2fb, 0x2fa, 0x3, 0x2, 0x2, 0x2, 0x2fb, 0x2fc, 
       0x3, 0x2, 0x2, 0x2, 0x2fc, 0x2fd, 0x3, 0x2, 0x2, 0x2, 0x2fd, 0x309, 
       0x5, 0x4e, 0x28, 0x2, 0x2fe, 0x309, 0x5, 0x4a, 0x26, 0x2, 0x2ff, 
       0x309, 0x5, 0x70, 0x39, 0x2, 0x300, 0x309, 0x5, 0x90, 0x49, 0x2, 
       0x301, 0x309, 0x5, 0x96, 0x4c, 0x2, 0x302, 0x309, 0x5, 0x98, 0x4d, 
       0x2, 0x303, 0x309, 0x5, 0x9a, 0x4e, 0x2, 0x304, 0x309, 0x5, 0x9c, 
       0x4f, 0x2, 0x305, 0x309, 0x5, 0x8e, 0x48, 0x2, 0x306, 0x309, 0x5, 
       0x8a, 0x46, 0x2, 0x307, 0x309, 0x5, 0x9e, 0x50, 0x2, 0x308, 0x2fb, 
       0x3, 0x2, 0x2, 0x2, 0x308, 0x2fe, 0x3, 0x2, 0x2, 0x2, 0x308, 0x2ff, 
       0x3, 0x2, 0x2, 0x2, 0x308, 0x300, 0x3, 0x2, 0x2, 0x2, 0x308, 0x301, 
       0x3, 0x2, 0x2, 0x2, 0x308, 0x302, 0x3, 0x2, 0x2, 0x2, 0x308, 0x303, 
       0x3, 0x2, 0x2, 0x2, 0x308, 0x304, 0x3, 0x2, 0x2, 0x2, 0x308, 0x305, 
       0x3, 0x2, 0x2, 0x2, 0x308, 0x306, 0x3, 0x2, 0x2, 0x2, 0x308, 0x307, 
       0x3, 0x2, 0x2, 0x2, 0x309, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x30a, 0x30b, 
       0x9, 0x6, 0x2, 0x2, 0x30b, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x30c, 0x331, 
       0x7, 0x3b, 0x2, 0x2, 0x30d, 0x331, 0x7, 0x3c, 0x2, 0x2, 0x30e, 0x317, 
       0x5, 0x2c, 0x17, 0x2, 0x30f, 0x314, 0x5, 0xaa, 0x56, 0x2, 0x310, 
       0x311, 0x7, 0x4d, 0x2, 0x2, 0x311, 0x313, 0x5, 0xaa, 0x56, 0x2, 0x312, 
       0x310, 0x3, 0x2, 0x2, 0x2, 0x313, 0x316, 0x3, 0x2, 0x2, 0x2, 0x314, 
       0x312, 0x3, 0x2, 0x2, 0x2, 0x314, 0x315, 0x3, 0x2, 0x2, 0x2, 0x315, 
       0x318, 0x3, 0x2, 0x2, 0x2, 0x316, 0x314, 0x3, 0x2, 0x2, 0x2, 0x317, 
       0x30f, 0x3, 0x2, 0x2, 0x2, 0x317, 0x318, 0x3, 0x2, 0x2, 0x2, 0x318, 
       0x319, 0x3, 0x2, 0x2, 0x2, 0x319, 0x31a, 0x5, 0x2e, 0x18, 0x2, 0x31a, 
       0x331, 0x3, 0x2, 0x2, 0x2, 0x31b, 0x31c, 0x5, 0x20, 0x11, 0x2, 0x31c, 
       0x321, 0x5, 0x92, 0x4a, 0x2, 0x31d, 0x31e, 0x7, 0x4f, 0x2, 0x2, 0x31e, 
       0x320, 0x5, 0x92, 0x4a, 0x2, 0x31f, 0x31d, 0x3, 0x2, 0x2, 0x2, 0x320, 
       0x323, 0x3, 0x2, 0x2, 0x2, 0x321, 0x31f, 0x3, 0x2, 0x2, 0x2, 0x321, 
       0x322, 0x3, 0x2, 0x2, 0x2, 0x322, 0x324, 0x3, 0x2, 0x2, 0x2, 0x323, 
       0x321, 0x3, 0x2, 0x2, 0x2, 0x324, 0x325, 0x5, 0x22, 0x12, 0x2, 0x325, 
       0x331, 0x3, 0x2, 0x2, 0x2, 0x326, 0x327, 0x7, 0x3f, 0x2, 0x2, 0x327, 
       0x331, 0x5, 0x4c, 0x27, 0x2, 0x328, 0x329, 0x7, 0x1a, 0x2, 0x2, 0x329, 
       0x32e, 0x5, 0x4e, 0x28, 0x2, 0x32a, 0x32b, 0x5, 0x2c, 0x17, 0x2, 
       0x32b, 0x32c, 0x5, 0x4c, 0x27, 0x2, 0x32c, 0x32d, 0x5, 0x2e, 0x18, 
       0x2, 0x32d, 0x32f, 0x3, 0x2, 0x2, 0x2, 0x32e, 0x32a, 0x3, 0x2, 0x2, 
       0x2, 0x32e, 0x32f, 0x3, 0x2, 0x2, 0x2, 0x32f, 0x331, 0x3, 0x2, 0x2, 
       0x2, 0x330, 0x30c, 0x3, 0x2, 0x2, 0x2, 0x330, 0x30d, 0x3, 0x2, 0x2, 
       0x2, 0x330, 0x30e, 0x3, 0x2, 0x2, 0x2, 0x330, 0x31b, 0x3, 0x2, 0x2, 
       0x2, 0x330, 0x326, 0x3, 0x2, 0x2, 0x2, 0x330, 0x328, 0x3, 0x2, 0x2, 
       0x2, 0x331, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x332, 0x334, 0x5, 0xa2, 0x52, 
       0x2, 0x333, 0x332, 0x3, 0x2, 0x2, 0x2, 0x334, 0x337, 0x3, 0x2, 0x2, 
       0x2, 0x335, 0x333, 0x3, 0x2, 0x2, 0x2, 0x335, 0x336, 0x3, 0x2, 0x2, 
       0x2, 0x336, 0x338, 0x3, 0x2, 0x2, 0x2, 0x337, 0x335, 0x3, 0x2, 0x2, 
       0x2, 0x338, 0x33c, 0x5, 0xa0, 0x51, 0x2, 0x339, 0x33b, 0x5, 0xa4, 
       0x53, 0x2, 0x33a, 0x339, 0x3, 0x2, 0x2, 0x2, 0x33b, 0x33e, 0x3, 0x2, 
       0x2, 0x2, 0x33c, 0x33a, 0x3, 0x2, 0x2, 0x2, 0x33c, 0x33d, 0x3, 0x2, 
       0x2, 0x2, 0x33d, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x33e, 0x33c, 0x3, 0x2, 
       0x2, 0x2, 0x33f, 0x345, 0x5, 0xa6, 0x54, 0x2, 0x340, 0x341, 0x5, 
       0x44, 0x23, 0x2, 0x341, 0x342, 0x5, 0xa6, 0x54, 0x2, 0x342, 0x344, 
       0x3, 0x2, 0x2, 0x2, 0x343, 0x340, 0x3, 0x2, 0x2, 0x2, 0x344, 0x347, 
       0x3, 0x2, 0x2, 0x2, 0x345, 0x343, 0x3, 0x2, 0x2, 0x2, 0x345, 0x346, 
       0x3, 0x2, 0x2, 0x2, 0x346, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x347, 0x345, 
       0x3, 0x2, 0x2, 0x2, 0x348, 0x34e, 0x5, 0xa8, 0x55, 0x2, 0x349, 0x34a, 
       0x5, 0x6, 0x4, 0x2, 0x34a, 0x34b, 0x5, 0xa8, 0x55, 0x2, 0x34b, 0x34d, 
       0x3, 0x2, 0x2, 0x2, 0x34c, 0x349, 0x3, 0x2, 0x2, 0x2, 0x34d, 0x350, 
       0x3, 0x2, 0x2, 0x2, 0x34e, 0x34c, 0x3, 0x2, 0x2, 0x2, 0x34e, 0x34f, 
       0x3, 0x2, 0x2, 0x2, 0x34f, 0xab, 0x3, 0x2, 0x2, 0x2, 0x350, 0x34e, 
       0x3, 0x2, 0x2, 0x2, 0x351, 0x352, 0x5, 0x4c, 0x27, 0x2, 0x352, 0x353, 
       0x7, 0x4f, 0x2, 0x2, 0x353, 0x354, 0x5, 0x56, 0x2c, 0x2, 0x354, 0x355, 
       0x7, 0x2d, 0x2, 0x2, 0x355, 0x356, 0x5, 0xaa, 0x56, 0x2, 0x356, 0xad, 
       0x3, 0x2, 0x2, 0x2, 0x357, 0x358, 0x7, 0x2a, 0x2, 0x2, 0x358, 0x35d, 
       0x5, 0xac, 0x57, 0x2, 0x359, 0x35a, 0x7, 0x4d, 0x2, 0x2, 0x35a, 0x35c, 
       0x5, 0xac, 0x57, 0x2, 0x35b, 0x359, 0x3, 0x2, 0x2, 0x2, 0x35c, 0x35f, 
       0x3, 0x2, 0x2, 0x2, 0x35d, 0x35b, 0x3, 0x2, 0x2, 0x2, 0x35d, 0x35e, 
       0x3, 0x2, 0x2, 0x2, 0x35e, 0x360, 0x3, 0x2, 0x2, 0x2, 0x35f, 0x35d, 
       0x3, 0x2, 0x2, 0x2, 0x360, 0x361, 0x5, 0xc, 0x7, 0x2, 0x361, 0xaf, 
       0x3, 0x2, 0x2, 0x2, 0x362, 0x363, 0x5, 0x4c, 0x27, 0x2, 0x363, 0x364, 
       0x7, 0x2d, 0x2, 0x2, 0x364, 0x365, 0x5, 0xaa, 0x56, 0x2, 0x365, 0xb1, 
       0x3, 0x2, 0x2, 0x2, 0x366, 0x367, 0x5, 0x56, 0x2c, 0x2, 0x367, 0x36c, 
       0x5, 0xb0, 0x59, 0x2, 0x368, 0x369, 0x7, 0x4d, 0x2, 0x2, 0x369, 0x36b, 
       0x5, 0xb0, 0x59, 0x2, 0x36a, 0x368, 0x3, 0x2, 0x2, 0x2, 0x36b, 0x36e, 
       0x3, 0x2, 0x2, 0x2, 0x36c, 0x36a, 0x3, 0x2, 0x2, 0x2, 0x36c, 0x36d, 
       0x3, 0x2, 0x2, 0x2, 0x36d, 0x36f, 0x3, 0x2, 0x2, 0x2, 0x36e, 0x36c, 
       0x3, 0x2, 0x2, 0x2, 0x36f, 0x370, 0x5, 0xc, 0x7, 0x2, 0x370, 0xb3, 
       0x3, 0x2, 0x2, 0x2, 0x371, 0x373, 0x7, 0x23, 0x2, 0x2, 0x372, 0x371, 
       0x3, 0x2, 0x2, 0x2, 0x372, 0x373, 0x3, 0x2, 0x2, 0x2, 0x373, 0x375, 
       0x3, 0x2, 0x2, 0x2, 0x374, 0x376, 0x5, 0xaa, 0x56, 0x2, 0x375, 0x374, 
       0x3, 0x2, 0x2, 0x2, 0x375, 0x376, 0x3, 0x2, 0x2, 0x2, 0x376, 0x37a, 
       0x3, 0x2, 0x2, 0x2, 0x377, 0x37a, 0x7, 0xd, 0x2, 0x2, 0x378, 0x37a, 
       0x7, 0x11, 0x2, 0x2, 0x379, 0x372, 0x3, 0x2, 0x2, 0x2, 0x379, 0x377, 
       0x3, 0x2, 0x2, 0x2, 0x379, 0x378, 0x3, 0x2, 0x2, 0x2, 0x37a, 0x37b, 
       0x3, 0x2, 0x2, 0x2, 0x37b, 0x37c, 0x5, 0xc, 0x7, 0x2, 0x37c, 0xb5, 
       0x3, 0x2, 0x2, 0x2, 0x37d, 0x389, 0x5, 0x6e, 0x38, 0x2, 0x37e, 0x389, 
       0x5, 0x72, 0x3a, 0x2, 0x37f, 0x389, 0x5, 0x74, 0x3b, 0x2, 0x380, 
       0x389, 0x5, 0x76, 0x3c, 0x2, 0x381, 0x389, 0x5, 0x78, 0x3d, 0x2, 
       0x382, 0x389, 0x5, 0x6a, 0x36, 0x2, 0x383, 0x389, 0x5, 0x86, 0x44, 
       0x2, 0x384, 0x389, 0x5, 0x82, 0x42, 0x2, 0x385, 0x389, 0x5, 0xae, 
       0x58, 0x2, 0x386, 0x389, 0x5, 0xb2, 0x5a, 0x2, 0x387, 0x389, 0x5, 
       0xb4, 0x5b, 0x2, 0x388, 0x37d, 0x3, 0x2, 0x2, 0x2, 0x388, 0x37e, 
       0x3, 0x2, 0x2, 0x2, 0x388, 0x37f, 0x3, 0x2, 0x2, 0x2, 0x388, 0x380, 
       0x3, 0x2, 0x2, 0x2, 0x388, 0x381, 0x3, 0x2, 0x2, 0x2, 0x388, 0x382, 
       0x3, 0x2, 0x2, 0x2, 0x388, 0x383, 0x3, 0x2, 0x2, 0x2, 0x388, 0x384, 
       0x3, 0x2, 0x2, 0x2, 0x388, 0x385, 0x3, 0x2, 0x2, 0x2, 0x388, 0x386, 
       0x3, 0x2, 0x2, 0x2, 0x388, 0x387, 0x3, 0x2, 0x2, 0x2, 0x389, 0xb7, 
       0x3, 0x2, 0x2, 0x2, 0x38a, 0x38b, 0x9, 0x7, 0x2, 0x2, 0x38b, 0xb9, 
       0x3, 0x2, 0x2, 0x2, 0x38c, 0x38d, 0x5, 0x3c, 0x1f, 0x2, 0x38d, 0x38e, 
       0x5, 0xaa, 0x56, 0x2, 0x38e, 0x38f, 0x7, 0x51, 0x2, 0x2, 0x38f, 0x39a, 
       0x3, 0x2, 0x2, 0x2, 0x390, 0x394, 0x5, 0x28, 0x15, 0x2, 0x391, 0x393, 
       0x5, 0xb6, 0x5c, 0x2, 0x392, 0x391, 0x3, 0x2, 0x2, 0x2, 0x393, 0x396, 
       0x3, 0x2, 0x2, 0x2, 0x394, 0x392, 0x3, 0x2, 0x2, 0x2, 0x394, 0x395, 
       0x3, 0x2, 0x2, 0x2, 0x395, 0x397, 0x3, 0x2, 0x2, 0x2, 0x396, 0x394, 
       0x3, 0x2, 0x2, 0x2, 0x397, 0x398, 0x5, 0x2a, 0x16, 0x2, 0x398, 0x39a, 
       0x3, 0x2, 0x2, 0x2, 0x399, 0x38c, 0x3, 0x2, 0x2, 0x2, 0x399, 0x390, 
       0x3, 0x2, 0x2, 0x2, 0x39a, 0xbb, 0x3, 0x2, 0x2, 0x2, 0x39b, 0x39d, 
       0x5, 0x2c, 0x17, 0x2, 0x39c, 0x39e, 0x5, 0x60, 0x31, 0x2, 0x39d, 
       0x39c, 0x3, 0x2, 0x2, 0x2, 0x39d, 0x39e, 0x3, 0x2, 0x2, 0x2, 0x39e, 
       0x39f, 0x3, 0x2, 0x2, 0x2, 0x39f, 0x3a0, 0x5, 0x2e, 0x18, 0x2, 0x3a0, 
       0x3a1, 0x7, 0x4f, 0x2, 0x2, 0x3a1, 0x3a2, 0x5, 0x56, 0x2c, 0x2, 0x3a2, 
       0x3a3, 0x5, 0xba, 0x5e, 0x2, 0x3a3, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x3a4, 
       0x3a6, 0x5, 0xb8, 0x5d, 0x2, 0x3a5, 0x3a4, 0x3, 0x2, 0x2, 0x2, 0x3a5, 
       0x3a6, 0x3, 0x2, 0x2, 0x2, 0x3a6, 0x3a8, 0x3, 0x2, 0x2, 0x2, 0x3a7, 
       0x3a9, 0x7, 0x25, 0x2, 0x2, 0x3a8, 0x3a7, 0x3, 0x2, 0x2, 0x2, 0x3a8, 
       0x3a9, 0x3, 0x2, 0x2, 0x2, 0x3a9, 0x3aa, 0x3, 0x2, 0x2, 0x2, 0x3aa, 
       0x3ab, 0x5, 0x4c, 0x27, 0x2, 0x3ab, 0x3ac, 0x7, 0x4f, 0x2, 0x2, 0x3ac, 
       0x3af, 0x5, 0x56, 0x2c, 0x2, 0x3ad, 0x3ae, 0x7, 0x2d, 0x2, 0x2, 0x3ae, 
       0x3b0, 0x5, 0xa8, 0x55, 0x2, 0x3af, 0x3ad, 0x3, 0x2, 0x2, 0x2, 0x3af, 
       0x3b0, 0x3, 0x2, 0x2, 0x2, 0x3b0, 0x3b1, 0x3, 0x2, 0x2, 0x2, 0x3b1, 
       0x3b2, 0x5, 0xc, 0x7, 0x2, 0x3b2, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x3b3, 
       0x3b5, 0x5, 0xb8, 0x5d, 0x2, 0x3b4, 0x3b3, 0x3, 0x2, 0x2, 0x2, 0x3b4, 
       0x3b5, 0x3, 0x2, 0x2, 0x2, 0x3b5, 0x3b7, 0x3, 0x2, 0x2, 0x2, 0x3b6, 
       0x3b8, 0x7, 0x25, 0x2, 0x2, 0x3b7, 0x3b6, 0x3, 0x2, 0x2, 0x2, 0x3b7, 
       0x3b8, 0x3, 0x2, 0x2, 0x2, 0x3b8, 0x3b9, 0x3, 0x2, 0x2, 0x2, 0x3b9, 
       0x3ba, 0x7, 0x17, 0x2, 0x2, 0x3ba, 0x3bc, 0x5, 0x4c, 0x27, 0x2, 0x3bb, 
       0x3bd, 0x5, 0xbc, 0x5f, 0x2, 0x3bc, 0x3bb, 0x3, 0x2, 0x2, 0x2, 0x3bc, 
       0x3bd, 0x3, 0x2, 0x2, 0x2, 0x3bd, 0x3be, 0x3, 0x2, 0x2, 0x2, 0x3be, 
       0x3bf, 0x5, 0xc, 0x7, 0x2, 0x3bf, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x3c0, 
       0x3c2, 0x5, 0xb8, 0x5d, 0x2, 0x3c1, 0x3c0, 0x3, 0x2, 0x2, 0x2, 0x3c1, 
       0x3c2, 0x3, 0x2, 0x2, 0x2, 0x3c2, 0x3c3, 0x3, 0x2, 0x2, 0x2, 0x3c3, 
       0x3c4, 0x7, 0x12, 0x2, 0x2, 0x3c4, 0x3c5, 0x5, 0x4c, 0x27, 0x2, 0x3c5, 
       0x3ca, 0x5, 0x28, 0x15, 0x2, 0x3c6, 0x3c9, 0x5, 0xbe, 0x60, 0x2, 
       0x3c7, 0x3c9, 0x5, 0xc0, 0x61, 0x2, 0x3c8, 0x3c6, 0x3, 0x2, 0x2, 
       0x2, 0x3c8, 0x3c7, 0x3, 0x2, 0x2, 0x2, 0x3c9, 0x3cc, 0x3, 0x2, 0x2, 
       0x2, 0x3ca, 0x3c8, 0x3, 0x2, 0x2, 0x2, 0x3ca, 0x3cb, 0x3, 0x2, 0x2, 
       0x2, 0x3cb, 0x3cd, 0x3, 0x2, 0x2, 0x2, 0x3cc, 0x3ca, 0x3, 0x2, 0x2, 
       0x2, 0x3cd, 0x3ce, 0x5, 0x2a, 0x16, 0x2, 0x3ce, 0x3cf, 0x5, 0xc, 
       0x7, 0x2, 0x3cf, 0xc3, 0x3, 0x2, 0x2, 0x2, 0x3d0, 0x3d2, 0x5, 0x2c, 
       0x17, 0x2, 0x3d1, 0x3d3, 0x5, 0x64, 0x33, 0x2, 0x3d2, 0x3d1, 0x3, 
       0x2, 0x2, 0x2, 0x3d2, 0x3d3, 0x3, 0x2, 0x2, 0x2, 0x3d3, 0x3d4, 0x3, 
       0x2, 0x2, 0x2, 0x3d4, 0x3d5, 0x5, 0x2e, 0x18, 0x2, 0x3d5, 0x3d6, 
       0x5, 0xba, 0x5e, 0x2, 0x3d6, 0xc5, 0x3, 0x2, 0x2, 0x2, 0x3d7, 0x3d9, 
       0x5, 0xb8, 0x5d, 0x2, 0x3d8, 0x3d7, 0x3, 0x2, 0x2, 0x2, 0x3d8, 0x3d9, 
       0x3, 0x2, 0x2, 0x2, 0x3d9, 0x3db, 0x3, 0x2, 0x2, 0x2, 0x3da, 0x3dc, 
       0x7, 0x25, 0x2, 0x2, 0x3db, 0x3da, 0x3, 0x2, 0x2, 0x2, 0x3db, 0x3dc, 
       0x3, 0x2, 0x2, 0x2, 0x3dc, 0x3dd, 0x3, 0x2, 0x2, 0x2, 0x3dd, 0x3de, 
       0x5, 0x56, 0x2c, 0x2, 0x3de, 0x3e0, 0x5, 0x4c, 0x27, 0x2, 0x3df, 
       0x3e1, 0x5, 0xc4, 0x63, 0x2, 0x3e0, 0x3df, 0x3, 0x2, 0x2, 0x2, 0x3e0, 
       0x3e1, 0x3, 0x2, 0x2, 0x2, 0x3e1, 0x3e2, 0x3, 0x2, 0x2, 0x2, 0x3e2, 
       0x3e3, 0x5, 0xc, 0x7, 0x2, 0x3e3, 0xc7, 0x3, 0x2, 0x2, 0x2, 0x3e4, 
       0x3e6, 0x5, 0xb8, 0x5d, 0x2, 0x3e5, 0x3e4, 0x3, 0x2, 0x2, 0x2, 0x3e5, 
       0x3e6, 0x3, 0x2, 0x2, 0x2, 0x3e6, 0x3e7, 0x3, 0x2, 0x2, 0x2, 0x3e7, 
       0x3e8, 0x7, 0x12, 0x2, 0x2, 0x3e8, 0x3e9, 0x5, 0x4c, 0x27, 0x2, 0x3e9, 
       0x3ed, 0x5, 0x28, 0x15, 0x2, 0x3ea, 0x3ec, 0x5, 0xc6, 0x64, 0x2, 
       0x3eb, 0x3ea, 0x3, 0x2, 0x2, 0x2, 0x3ec, 0x3ef, 0x3, 0x2, 0x2, 0x2, 
       0x3ed, 0x3eb, 0x3, 0x2, 0x2, 0x2, 0x3ed, 0x3ee, 0x3, 0x2, 0x2, 0x2, 
       0x3ee, 0x3f0, 0x3, 0x2, 0x2, 0x2, 0x3ef, 0x3ed, 0x3, 0x2, 0x2, 0x2, 
       0x3f0, 0x3f1, 0x5, 0x2a, 0x16, 0x2, 0x3f1, 0x3f2, 0x5, 0xc, 0x7, 
       0x2, 0x3f2, 0xc9, 0x3, 0x2, 0x2, 0x2, 0x3f3, 0x3f4, 0x5, 0x4c, 0x27, 
       0x2, 0x3f4, 0x3f5, 0x5, 0x2c, 0x17, 0x2, 0x3f5, 0x3fa, 0x5, 0x56, 
       0x2c, 0x2, 0x3f6, 0x3f7, 0x7, 0x4d, 0x2, 0x2, 0x3f7, 0x3f9, 0x5, 
       0x56, 0x2c, 0x2, 0x3f8, 0x3f6, 0x3, 0x2, 0x2, 0x2, 0x3f9, 0x3fc, 
       0x3, 0x2, 0x2, 0x2, 0x3fa, 0x3f8, 0x3, 0x2, 0x2, 0x2, 0x3fa, 0x3fb, 
       0x3, 0x2, 0x2, 0x2, 0x3fb, 0x3fd, 0x3, 0x2, 0x2, 0x2, 0x3fc, 0x3fa, 
       0x3, 0x2, 0x2, 0x2, 0x3fd, 0x3fe, 0x5, 0x2e, 0x18, 0x2, 0x3fe, 0x400, 
       0x3, 0x2, 0x2, 0x2, 0x3ff, 0x401, 0x5, 0xe, 0x8, 0x2, 0x400, 0x3ff, 
       0x3, 0x2, 0x2, 0x2, 0x400, 0x401, 0x3, 0x2, 0x2, 0x2, 0x401, 0xcb, 
       0x3, 0x2, 0x2, 0x2, 0x402, 0x404, 0x5, 0xb8, 0x5d, 0x2, 0x403, 0x402, 
       0x3, 0x2, 0x2, 0x2, 0x403, 0x404, 0x3, 0x2, 0x2, 0x2, 0x404, 0x405, 
       0x3, 0x2, 0x2, 0x2, 0x405, 0x406, 0x7, 0x16, 0x2, 0x2, 0x406, 0x407, 
       0x5, 0x4c, 0x27, 0x2, 0x407, 0x409, 0x5, 0x28, 0x15, 0x2, 0x408, 
       0x40a, 0x5, 0xca, 0x66, 0x2, 0x409, 0x408, 0x3, 0x2, 0x2, 0x2, 0x40a, 
       0x40b, 0x3, 0x2, 0x2, 0x2, 0x40b, 0x409, 0x3, 0x2, 0x2, 0x2, 0x40b, 
       0x40c, 0x3, 0x2, 0x2, 0x2, 0x40c, 0x410, 0x3, 0x2, 0x2, 0x2, 0x40d, 
       0x40f, 0x5, 0xc0, 0x61, 0x2, 0x40e, 0x40d, 0x3, 0x2, 0x2, 0x2, 0x40f, 
       0x412, 0x3, 0x2, 0x2, 0x2, 0x410, 0x40e, 0x3, 0x2, 0x2, 0x2, 0x410, 
       0x411, 0x3, 0x2, 0x2, 0x2, 0x411, 0x413, 0x3, 0x2, 0x2, 0x2, 0x412, 
       0x410, 0x3, 0x2, 0x2, 0x2, 0x413, 0x414, 0x5, 0x2a, 0x16, 0x2, 0x414, 
       0x415, 0x5, 0xc, 0x7, 0x2, 0x415, 0xcd, 0x3, 0x2, 0x2, 0x2, 0x416, 
       0x418, 0x5, 0xb8, 0x5d, 0x2, 0x417, 0x416, 0x3, 0x2, 0x2, 0x2, 0x417, 
       0x418, 0x3, 0x2, 0x2, 0x2, 0x418, 0x419, 0x3, 0x2, 0x2, 0x2, 0x419, 
       0x41a, 0x7, 0x16, 0x2, 0x2, 0x41a, 0x41b, 0x5, 0x4c, 0x27, 0x2, 0x41b, 
       0x41d, 0x5, 0x28, 0x15, 0x2, 0x41c, 0x41e, 0x5, 0xca, 0x66, 0x2, 
       0x41d, 0x41c, 0x3, 0x2, 0x2, 0x2, 0x41e, 0x41f, 0x3, 0x2, 0x2, 0x2, 
       0x41f, 0x41d, 0x3, 0x2, 0x2, 0x2, 0x41f, 0x420, 0x3, 0x2, 0x2, 0x2, 
       0x420, 0x424, 0x3, 0x2, 0x2, 0x2, 0x421, 0x423, 0x5, 0xc6, 0x64, 
       0x2, 0x422, 0x421, 0x3, 0x2, 0x2, 0x2, 0x423, 0x426, 0x3, 0x2, 0x2, 
       0x2, 0x424, 0x422, 0x3, 0x2, 0x2, 0x2, 0x424, 0x425, 0x3, 0x2, 0x2, 
       0x2, 0x425, 0x427, 0x3, 0x2, 0x2, 0x2, 0x426, 0x424, 0x3, 0x2, 0x2, 
       0x2, 0x427, 0x428, 0x5, 0x2a, 0x16, 0x2, 0x428, 0x429, 0x5, 0xc, 
       0x7, 0x2, 0x429, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x42a, 0x42e, 0x7, 0x29, 
       0x2, 0x2, 0x42b, 0x42c, 0x5, 0x4c, 0x27, 0x2, 0x42c, 0x42d, 0x7, 
       0x2d, 0x2, 0x2, 0x42d, 0x42f, 0x3, 0x2, 0x2, 0x2, 0x42e, 0x42b, 0x3, 
       0x2, 0x2, 0x2, 0x42e, 0x42f, 0x3, 0x2, 0x2, 0x2, 0x42f, 0x430, 0x3, 
       0x2, 0x2, 0x2, 0x430, 0x431, 0x5, 0x4e, 0x28, 0x2, 0x431, 0x432, 
       0x5, 0xc, 0x7, 0x2, 0x432, 0xd1, 0x3, 0x2, 0x2, 0x2, 0x433, 0x434, 
       0x9, 0x8, 0x2, 0x2, 0x434, 0xd3, 0x3, 0x2, 0x2, 0x2, 0x435, 0x436, 
       0x7, 0xb, 0x2, 0x2, 0x436, 0x437, 0x5, 0x56, 0x2c, 0x2, 0x437, 0x438, 
       0x5, 0xd2, 0x6a, 0x2, 0x438, 0x439, 0x5, 0x4c, 0x27, 0x2, 0x439, 
       0x43a, 0x5, 0x2c, 0x17, 0x2, 0x43a, 0x43b, 0x5, 0x5c, 0x2f, 0x2, 
       0x43b, 0x43c, 0x5, 0x2e, 0x18, 0x2, 0x43c, 0x43d, 0x5, 0xc, 0x7, 
       0x2, 0x43d, 0xd5, 0x3, 0x2, 0x2, 0x2, 0x43e, 0x43f, 0x7, 0xc, 0x2, 
       0x2, 0x43f, 0x440, 0x7, 0x56, 0x2, 0x2, 0x440, 0x441, 0x5, 0xc, 0x7, 
       0x2, 0x441, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x442, 0x443, 0x7, 0x1d, 0x2, 
       0x2, 0x443, 0x444, 0x5, 0x4e, 0x28, 0x2, 0x444, 0x445, 0x5, 0xc, 
       0x7, 0x2, 0x445, 0xd9, 0x3, 0x2, 0x2, 0x2, 0x446, 0x44a, 0x5, 0xd0, 
       0x69, 0x2, 0x447, 0x44a, 0x5, 0xd4, 0x6b, 0x2, 0x448, 0x44a, 0x5, 
       0xd6, 0x6c, 0x2, 0x449, 0x446, 0x3, 0x2, 0x2, 0x2, 0x449, 0x447, 
       0x3, 0x2, 0x2, 0x2, 0x449, 0x448, 0x3, 0x2, 0x2, 0x2, 0x44a, 0x44d, 
       0x3, 0x2, 0x2, 0x2, 0x44b, 0x449, 0x3, 0x2, 0x2, 0x2, 0x44b, 0x44c, 
       0x3, 0x2, 0x2, 0x2, 0x44c, 0x44f, 0x3, 0x2, 0x2, 0x2, 0x44d, 0x44b, 
       0x3, 0x2, 0x2, 0x2, 0x44e, 0x450, 0x5, 0xd8, 0x6d, 0x2, 0x44f, 0x44e, 
       0x3, 0x2, 0x2, 0x2, 0x44f, 0x450, 0x3, 0x2, 0x2, 0x2, 0x450, 0x457, 
       0x3, 0x2, 0x2, 0x2, 0x451, 0x456, 0x5, 0xcc, 0x67, 0x2, 0x452, 0x456, 
       0x5, 0xce, 0x68, 0x2, 0x453, 0x456, 0x5, 0xc2, 0x62, 0x2, 0x454, 
       0x456, 0x5, 0xc8, 0x65, 0x2, 0x455, 0x451, 0x3, 0x2, 0x2, 0x2, 0x455, 
       0x452, 0x3, 0x2, 0x2, 0x2, 0x455, 0x453, 0x3, 0x2, 0x2, 0x2, 0x455, 
       0x454, 0x3, 0x2, 0x2, 0x2, 0x456, 0x459, 0x3, 0x2, 0x2, 0x2, 0x457, 
       0x455, 0x3, 0x2, 0x2, 0x2, 0x457, 0x458, 0x3, 0x2, 0x2, 0x2, 0x458, 
       0xdb, 0x3, 0x2, 0x2, 0x2, 0x459, 0x457, 0x3, 0x2, 0x2, 0x2, 0x45a, 
       0x45b, 0x5, 0xda, 0x6e, 0x2, 0x45b, 0x45c, 0x7, 0x2, 0x2, 0x3, 0x45c, 
       0xdd, 0x3, 0x2, 0x2, 0x2, 0x71, 0xf3, 0xfe, 0x103, 0x117, 0x11a, 
       0x120, 0x123, 0x129, 0x12c, 0x132, 0x135, 0x159, 0x161, 0x165, 0x169, 
       0x16c, 0x171, 0x179, 0x182, 0x189, 0x192, 0x197, 0x19f, 0x1a5, 0x1aa, 
       0x1ae, 0x1b4, 0x1bb, 0x1c7, 0x1cc, 0x1d3, 0x1d7, 0x1e0, 0x1e7, 0x1f0, 
       0x200, 0x205, 0x211, 0x21d, 0x227, 0x237, 0x23a, 0x240, 0x24e, 0x259, 
       0x263, 0x26e, 0x27d, 0x286, 0x292, 0x2a3, 0x2ae, 0x2b3, 0x2bd, 0x2c0, 
       0x2cc, 0x2cf, 0x2d9, 0x2e3, 0x2ea, 0x2f3, 0x2f8, 0x2fb, 0x308, 0x314, 
       0x317, 0x321, 0x32e, 0x330, 0x335, 0x33c, 0x345, 0x34e, 0x35d, 0x36c, 
       0x372, 0x375, 0x379, 0x388, 0x394, 0x399, 0x39d, 0x3a5, 0x3a8, 0x3af, 
       0x3b4, 0x3b7, 0x3bc, 0x3c1, 0x3c8, 0x3ca, 0x3d2, 0x3d8, 0x3db, 0x3e0, 
       0x3e5, 0x3ed, 0x3fa, 0x400, 0x403, 0x40b, 0x410, 0x417, 0x41f, 0x424, 
       0x42e, 0x449, 0x44b, 0x44f, 0x455, 0x457, 
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


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
    setState(206);
    shiftLOp();
    setState(207);
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
    setState(209);
    shiftROp();
    setState(210);
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
    setState(227);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::Assign: {
        enterOuterAlt(_localctx, 1);
        setState(212);
        match(FaParser::Assign);
        break;
      }

      case FaParser::QusQusAssign: {
        enterOuterAlt(_localctx, 2);
        setState(213);
        match(FaParser::QusQusAssign);
        break;
      }

      case FaParser::AddAssign: {
        enterOuterAlt(_localctx, 3);
        setState(214);
        match(FaParser::AddAssign);
        break;
      }

      case FaParser::SubAssign: {
        enterOuterAlt(_localctx, 4);
        setState(215);
        match(FaParser::SubAssign);
        break;
      }

      case FaParser::StarAssign: {
        enterOuterAlt(_localctx, 5);
        setState(216);
        match(FaParser::StarAssign);
        break;
      }

      case FaParser::StarStarAssign: {
        enterOuterAlt(_localctx, 6);
        setState(217);
        match(FaParser::StarStarAssign);
        break;
      }

      case FaParser::DivAssign: {
        enterOuterAlt(_localctx, 7);
        setState(218);
        match(FaParser::DivAssign);
        break;
      }

      case FaParser::ModAssign: {
        enterOuterAlt(_localctx, 8);
        setState(219);
        match(FaParser::ModAssign);
        break;
      }

      case FaParser::AndAssign: {
        enterOuterAlt(_localctx, 9);
        setState(220);
        match(FaParser::AndAssign);
        break;
      }

      case FaParser::OrAssign: {
        enterOuterAlt(_localctx, 10);
        setState(221);
        match(FaParser::OrAssign);
        break;
      }

      case FaParser::XorAssign: {
        enterOuterAlt(_localctx, 11);
        setState(222);
        match(FaParser::XorAssign);
        break;
      }

      case FaParser::AndAndAssign: {
        enterOuterAlt(_localctx, 12);
        setState(223);
        match(FaParser::AndAndAssign);
        break;
      }

      case FaParser::OrOrAssign: {
        enterOuterAlt(_localctx, 13);
        setState(224);
        match(FaParser::OrOrAssign);
        break;
      }

      case FaParser::T__2: {
        enterOuterAlt(_localctx, 14);
        setState(225);
        shiftLAssign();
        break;
      }

      case FaParser::T__3: {
        enterOuterAlt(_localctx, 15);
        setState(226);
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
    setState(229);
    qJianL();
    setState(230);
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
    setState(232);
    qJianR();
    setState(233);
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
    setState(236); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(235);
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
      setState(238); 
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
    setState(241); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(240);
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
      setState(243); 
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
    setState(245);
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
    setState(247);
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
    setState(249);
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
    setState(251);
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
    setState(253);
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
    setState(255);
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
    setState(257);
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
    setState(259);
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
    setState(261);
    qFangL();
    setState(263);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      setState(262);
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
    setState(266);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Lf

    || _la == FaParser::Semi) {
      setState(265);
      endl();
    }
    setState(268);
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
    setState(270);
    qJianL();
    setState(272);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Lf

    || _la == FaParser::Semi) {
      setState(271);
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
    setState(275);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Lf

    || _la == FaParser::Semi) {
      setState(274);
      endl();
    }
    setState(277);
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
    setState(279);
    qHuaL();
    setState(281);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      setState(280);
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
    setState(284);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Lf

    || _la == FaParser::Semi) {
      setState(283);
      endl();
    }
    setState(286);
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
    setState(288);
    qYuanL();
    setState(290);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      setState(289);
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
    setState(293);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Lf

    || _la == FaParser::Semi) {
      setState(292);
      endl();
    }
    setState(295);
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
    setState(297);
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
    setState(299);
    qJianL();
    setState(300);
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
    setState(302);
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
    setState(304);
    qJianR();
    setState(305);
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
    setState(307);
    match(FaParser::Assign);
    setState(308);
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
    setState(310);
    match(FaParser::Exclam);
    setState(311);
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
    setState(313);
    match(FaParser::Assign);
    setState(314);
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
    setState(329);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::AddOp: {
        enterOuterAlt(_localctx, 1);
        setState(316);
        match(FaParser::AddOp);
        break;
      }

      case FaParser::SubOp: {
        enterOuterAlt(_localctx, 2);
        setState(317);
        match(FaParser::SubOp);
        break;
      }

      case FaParser::StarOp: {
        enterOuterAlt(_localctx, 3);
        setState(318);
        match(FaParser::StarOp);
        break;
      }

      case FaParser::DivOp: {
        enterOuterAlt(_localctx, 4);
        setState(319);
        match(FaParser::DivOp);
        break;
      }

      case FaParser::StarStarOp: {
        enterOuterAlt(_localctx, 5);
        setState(320);
        match(FaParser::StarStarOp);
        break;
      }

      case FaParser::ModOp: {
        enterOuterAlt(_localctx, 6);
        setState(321);
        match(FaParser::ModOp);
        break;
      }

      case FaParser::AndOp: {
        enterOuterAlt(_localctx, 7);
        setState(322);
        match(FaParser::AndOp);
        break;
      }

      case FaParser::OrOp: {
        enterOuterAlt(_localctx, 8);
        setState(323);
        match(FaParser::OrOp);
        break;
      }

      case FaParser::XorOp: {
        enterOuterAlt(_localctx, 9);
        setState(324);
        match(FaParser::XorOp);
        break;
      }

      case FaParser::AndAndOp: {
        enterOuterAlt(_localctx, 10);
        setState(325);
        match(FaParser::AndAndOp);
        break;
      }

      case FaParser::OrOrOp: {
        enterOuterAlt(_localctx, 11);
        setState(326);
        match(FaParser::OrOrOp);
        break;
      }

      case FaParser::T__2: {
        enterOuterAlt(_localctx, 12);
        setState(327);
        shiftLOp();
        break;
      }

      case FaParser::T__3: {
        enterOuterAlt(_localctx, 13);
        setState(328);
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
    setState(337);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(331);
      ltOp();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(332);
      ltEqualOp();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(333);
      gtOp();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(334);
      gtEqualOp();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(335);
      equalOp();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(336);
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
    setState(341);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::QusQusOp: {
        enterOuterAlt(_localctx, 1);
        setState(339);
        match(FaParser::QusQusOp);
        break;
      }

      case FaParser::T__2:
      case FaParser::T__3:
      case FaParser::Assign:
      case FaParser::Exclam: {
        enterOuterAlt(_localctx, 2);
        setState(340);
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
    setState(345);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(343);
      selfOp2();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(344);
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
    setState(348);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::SubOp) {
      setState(347);
      match(FaParser::SubOp);
    }
    setState(350);
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
    setState(353);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::SubOp) {
      setState(352);
      match(FaParser::SubOp);
    }
    setState(355);
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
    setState(361);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(357);
      match(FaParser::BoolLiteral);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(358);
      intNum();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(359);
      floatNum();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(360);
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
    setState(363);
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
    setState(365);
    id();
    setState(370);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(366);
        match(FaParser::PointOp);
        setState(367);
        id(); 
      }
      setState(372);
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

//----------------- IdExtContext ------------------------------------------------------------------

FaParser::IdExtContext::IdExtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::IdsContext* FaParser::IdExtContext::ids() {
  return getRuleContext<FaParser::IdsContext>(0);
}

FaParser::QuotJianLContext* FaParser::IdExtContext::quotJianL() {
  return getRuleContext<FaParser::QuotJianLContext>(0);
}

std::vector<FaParser::TypeContext *> FaParser::IdExtContext::type() {
  return getRuleContexts<FaParser::TypeContext>();
}

FaParser::TypeContext* FaParser::IdExtContext::type(size_t i) {
  return getRuleContext<FaParser::TypeContext>(i);
}

FaParser::QuotJianRContext* FaParser::IdExtContext::quotJianR() {
  return getRuleContext<FaParser::QuotJianRContext>(0);
}

tree::TerminalNode* FaParser::IdExtContext::PointOp() {
  return getToken(FaParser::PointOp, 0);
}

FaParser::IdContext* FaParser::IdExtContext::id() {
  return getRuleContext<FaParser::IdContext>(0);
}

std::vector<tree::TerminalNode *> FaParser::IdExtContext::Comma() {
  return getTokens(FaParser::Comma);
}

tree::TerminalNode* FaParser::IdExtContext::Comma(size_t i) {
  return getToken(FaParser::Comma, i);
}


size_t FaParser::IdExtContext::getRuleIndex() const {
  return FaParser::RuleIdExt;
}


antlrcpp::Any FaParser::IdExtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitIdExt(this);
  else
    return visitor->visitChildren(this);
}

FaParser::IdExtContext* FaParser::idExt() {
  IdExtContext *_localctx = _tracker.createInstance<IdExtContext>(_ctx, getState());
  enterRule(_localctx, 78, FaParser::RuleIdExt);
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
    setState(373);
    ids();
    setState(374);
    quotJianL();
    setState(375);
    type();
    setState(380);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(376);
      match(FaParser::Comma);
      setState(377);
      type();
      setState(382);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(383);
    quotJianR();
    setState(384);
    match(FaParser::PointOp);
    setState(385);
    id();
   
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
  enterRule(_localctx, 80, FaParser::RuleTypeAfter);

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

std::vector<FaParser::TypeWrapContext *> FaParser::TypeSingleContext::typeWrap() {
  return getRuleContexts<FaParser::TypeWrapContext>();
}

FaParser::TypeWrapContext* FaParser::TypeSingleContext::typeWrap(size_t i) {
  return getRuleContext<FaParser::TypeWrapContext>(i);
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
  enterRule(_localctx, 82, FaParser::RuleTypeSingle);
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
      typeWrap();
      setState(400);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FaParser::Comma) {
        setState(396);
        match(FaParser::Comma);
        setState(397);
        typeWrap();
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
  enterRule(_localctx, 84, FaParser::RuleTypeMulti);
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
  enterRule(_localctx, 86, FaParser::RuleType);
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
  enterRule(_localctx, 88, FaParser::RuleTypeWrap);
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
  enterRule(_localctx, 90, FaParser::RuleTypeVar);
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
  enterRule(_localctx, 92, FaParser::RuleTypeVarList);
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

//----------------- TypeWrapVarContext ------------------------------------------------------------------

FaParser::TypeWrapVarContext::TypeWrapVarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::TypeWrapContext* FaParser::TypeWrapVarContext::typeWrap() {
  return getRuleContext<FaParser::TypeWrapContext>(0);
}

FaParser::IdContext* FaParser::TypeWrapVarContext::id() {
  return getRuleContext<FaParser::IdContext>(0);
}


size_t FaParser::TypeWrapVarContext::getRuleIndex() const {
  return FaParser::RuleTypeWrapVar;
}


antlrcpp::Any FaParser::TypeWrapVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitTypeWrapVar(this);
  else
    return visitor->visitChildren(this);
}

FaParser::TypeWrapVarContext* FaParser::typeWrapVar() {
  TypeWrapVarContext *_localctx = _tracker.createInstance<TypeWrapVarContext>(_ctx, getState());
  enterRule(_localctx, 94, FaParser::RuleTypeWrapVar);
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
    setState(444);
    typeWrap();
    setState(446);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Underline

    || _la == FaParser::RawId) {
      setState(445);
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

//----------------- TypeWrapVarListContext ------------------------------------------------------------------

FaParser::TypeWrapVarListContext::TypeWrapVarListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FaParser::TypeWrapVarContext *> FaParser::TypeWrapVarListContext::typeWrapVar() {
  return getRuleContexts<FaParser::TypeWrapVarContext>();
}

FaParser::TypeWrapVarContext* FaParser::TypeWrapVarListContext::typeWrapVar(size_t i) {
  return getRuleContext<FaParser::TypeWrapVarContext>(i);
}

std::vector<tree::TerminalNode *> FaParser::TypeWrapVarListContext::Comma() {
  return getTokens(FaParser::Comma);
}

tree::TerminalNode* FaParser::TypeWrapVarListContext::Comma(size_t i) {
  return getToken(FaParser::Comma, i);
}


size_t FaParser::TypeWrapVarListContext::getRuleIndex() const {
  return FaParser::RuleTypeWrapVarList;
}


antlrcpp::Any FaParser::TypeWrapVarListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitTypeWrapVarList(this);
  else
    return visitor->visitChildren(this);
}

FaParser::TypeWrapVarListContext* FaParser::typeWrapVarList() {
  TypeWrapVarListContext *_localctx = _tracker.createInstance<TypeWrapVarListContext>(_ctx, getState());
  enterRule(_localctx, 96, FaParser::RuleTypeWrapVarList);
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
    typeWrapVar();
    setState(453);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(449);
      match(FaParser::Comma);
      setState(450);
      typeWrapVar();
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

FaParser::IdContext* FaParser::TypeWrapVar2Context::id() {
  return getRuleContext<FaParser::IdContext>(0);
}

FaParser::TypeWrapContext* FaParser::TypeWrapVar2Context::typeWrap() {
  return getRuleContext<FaParser::TypeWrapContext>(0);
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
  enterRule(_localctx, 98, FaParser::RuleTypeWrapVar2);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(457);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      setState(456);
      typeWrap();
      break;
    }

    default:
      break;
    }
    setState(459);
    id();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeWrapVar2ListContext ------------------------------------------------------------------

FaParser::TypeWrapVar2ListContext::TypeWrapVar2ListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FaParser::TypeWrapVar2Context *> FaParser::TypeWrapVar2ListContext::typeWrapVar2() {
  return getRuleContexts<FaParser::TypeWrapVar2Context>();
}

FaParser::TypeWrapVar2Context* FaParser::TypeWrapVar2ListContext::typeWrapVar2(size_t i) {
  return getRuleContext<FaParser::TypeWrapVar2Context>(i);
}

std::vector<tree::TerminalNode *> FaParser::TypeWrapVar2ListContext::Comma() {
  return getTokens(FaParser::Comma);
}

tree::TerminalNode* FaParser::TypeWrapVar2ListContext::Comma(size_t i) {
  return getToken(FaParser::Comma, i);
}


size_t FaParser::TypeWrapVar2ListContext::getRuleIndex() const {
  return FaParser::RuleTypeWrapVar2List;
}


antlrcpp::Any FaParser::TypeWrapVar2ListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitTypeWrapVar2List(this);
  else
    return visitor->visitChildren(this);
}

FaParser::TypeWrapVar2ListContext* FaParser::typeWrapVar2List() {
  TypeWrapVar2ListContext *_localctx = _tracker.createInstance<TypeWrapVar2ListContext>(_ctx, getState());
  enterRule(_localctx, 100, FaParser::RuleTypeWrapVar2List);
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
    setState(461);
    typeWrapVar2();
    setState(466);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(462);
      match(FaParser::Comma);
      setState(463);
      typeWrapVar2();
      setState(468);
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
  enterRule(_localctx, 102, FaParser::RuleQuotStmtPart);

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
    setState(469);
    quotHuaL();
    setState(473);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(470);
        stmt(); 
      }
      setState(475);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    }
    setState(476);
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
  enterRule(_localctx, 104, FaParser::RuleQuotStmtExpr);

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
    setState(478);
    quotHuaL();
    setState(482);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(479);
        stmt(); 
      }
      setState(484);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    }
    setState(485);
    expr();
    setState(486);
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
  enterRule(_localctx, 106, FaParser::RuleIfStmt);
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
    setState(488);
    match(FaParser::If);
    setState(489);
    expr();
    setState(490);
    quotStmtPart();
    setState(498);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(491);
        match(FaParser::Else);
        setState(492);
        match(FaParser::If);
        setState(493);
        expr();
        setState(494);
        quotStmtPart(); 
      }
      setState(500);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    }
    setState(503);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Else) {
      setState(501);
      match(FaParser::Else);
      setState(502);
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
  enterRule(_localctx, 108, FaParser::RuleIfExpr);

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
    setState(505);
    match(FaParser::If);
    setState(506);
    expr();
    setState(507);
    quotStmtExpr();
    setState(515);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(508);
        match(FaParser::Else);
        setState(509);
        match(FaParser::If);
        setState(510);
        expr();
        setState(511);
        quotStmtExpr(); 
      }
      setState(517);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
    }
    setState(518);
    match(FaParser::Else);
    setState(519);
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
  enterRule(_localctx, 110, FaParser::RuleWhileStmt);

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
    setState(521);
    match(FaParser::While);
    setState(522);
    expr();
    setState(523);
    quotHuaL();
    setState(527);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(524);
        stmt(); 
      }
      setState(529);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    }
    setState(530);
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
  enterRule(_localctx, 112, FaParser::RuleWhileStmt2);

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
    setState(532);
    match(FaParser::Do);
    setState(533);
    quotHuaL();
    setState(537);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(534);
        stmt(); 
      }
      setState(539);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    }
    setState(540);
    quotHuaR();
    setState(541);
    match(FaParser::While);
    setState(542);
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
  enterRule(_localctx, 114, FaParser::RuleForStmt);
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
    setState(544);
    match(FaParser::For);
    setState(545);
    stmt();
    setState(546);
    expr();
    setState(547);
    match(FaParser::Semi);
    setState(556);
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
      | (1ULL << FaParser::SubOp))) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 75)) & ((1ULL << (FaParser::ColonColon - 75))
      | (1ULL << (FaParser::Underline - 75))
      | (1ULL << (FaParser::BoolLiteral - 75))
      | (1ULL << (FaParser::IntLiteral - 75))
      | (1ULL << (FaParser::FloatLiteral - 75))
      | (1ULL << (FaParser::String1Literal - 75))
      | (1ULL << (FaParser::RawId - 75)))) != 0)) {
      setState(548);
      expr();
      setState(553);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FaParser::Comma) {
        setState(549);
        match(FaParser::Comma);
        setState(550);
        expr();
        setState(555);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(558);
    quotHuaL();
    setState(562);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(559);
        stmt(); 
      }
      setState(564);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
    }
    setState(565);
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
  enterRule(_localctx, 116, FaParser::RuleForStmt2);

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
    setState(567);
    match(FaParser::For);
    setState(568);
    type();
    setState(569);
    id();
    setState(570);
    match(FaParser::Colon);
    setState(571);
    expr();
    setState(572);
    quotHuaL();
    setState(576);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(573);
        stmt(); 
      }
      setState(578);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
    }
    setState(579);
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
  enterRule(_localctx, 118, FaParser::RuleSwitchStmtPart2Last);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(581);
    match(FaParser::Underline);
    setState(582);
    exprFuncDef();
    setState(583);
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
  enterRule(_localctx, 120, FaParser::RuleQuotStmtExprWrap);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(587);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::T__4: {
        enterOuterAlt(_localctx, 1);
        setState(585);
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
        setState(586);
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
  enterRule(_localctx, 122, FaParser::RuleSwitchExprPartLast);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(589);
    match(FaParser::Underline);
    setState(590);
    exprFuncDef();
    setState(591);
    quotStmtExprWrap();
    setState(592);
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
  enterRule(_localctx, 124, FaParser::RuleSwitchStmtPart);
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
    setState(594);
    expr();
    setState(597);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::When) {
      setState(595);
      match(FaParser::When);
      setState(596);
      expr();
    }
    setState(599);
    exprFuncDef();
    setState(600);
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
  enterRule(_localctx, 126, FaParser::RuleSwitchStmt);
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
    setState(602);
    match(FaParser::Switch);
    setState(603);
    expr();
    setState(604);
    quotHuaL();
    setState(608);
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
      | (1ULL << FaParser::SubOp))) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 75)) & ((1ULL << (FaParser::ColonColon - 75))
      | (1ULL << (FaParser::Underline - 75))
      | (1ULL << (FaParser::BoolLiteral - 75))
      | (1ULL << (FaParser::IntLiteral - 75))
      | (1ULL << (FaParser::FloatLiteral - 75))
      | (1ULL << (FaParser::String1Literal - 75))
      | (1ULL << (FaParser::RawId - 75)))) != 0)) {
      setState(605);
      switchStmtPart();
      setState(610);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(611);
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
  enterRule(_localctx, 128, FaParser::RuleSwitchStmtPart2);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(613);
    match(FaParser::When);
    setState(614);
    expr();
    setState(615);
    exprFuncDef();
    setState(616);
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
  enterRule(_localctx, 130, FaParser::RuleSwitchStmt2);
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
    setState(618);
    match(FaParser::Switch);
    setState(619);
    quotHuaL();
    setState(623);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::When) {
      setState(620);
      switchStmtPart2();
      setState(625);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(626);
    switchStmtPart2Last();
    setState(627);
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
  enterRule(_localctx, 132, FaParser::RuleSwitchExprPart);
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
    setState(629);
    expr();
    setState(632);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::When) {
      setState(630);
      match(FaParser::When);
      setState(631);
      expr();
    }
    setState(634);
    exprFuncDef();
    setState(635);
    quotStmtExprWrap();
    setState(636);
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
  enterRule(_localctx, 134, FaParser::RuleSwitchExpr);

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
    setState(638);
    match(FaParser::Switch);
    setState(639);
    expr();
    setState(640);
    quotHuaL();
    setState(644);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(641);
        switchExprPart(); 
      }
      setState(646);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx);
    }
    setState(647);
    switchExprPartLast();
    setState(648);
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
  enterRule(_localctx, 136, FaParser::RuleSwitchExprPart2);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(650);
    match(FaParser::When);
    setState(651);
    expr();
    setState(652);
    exprFuncDef();
    setState(653);
    quotStmtExprWrap();
    setState(654);
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
  enterRule(_localctx, 138, FaParser::RuleSwitchExpr2);
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
    setState(656);
    match(FaParser::Switch);
    setState(657);
    quotHuaL();
    setState(661);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::When) {
      setState(658);
      switchExprPart2();
      setState(663);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(664);
    switchExprPartLast();
    setState(665);
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
  enterRule(_localctx, 140, FaParser::RuleQuotExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(667);
    quotYuanL();
    setState(668);
    expr();
    setState(669);
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
  enterRule(_localctx, 142, FaParser::RuleExprOpt);
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
    setState(672);
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
      | (1ULL << FaParser::SubOp))) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 75)) & ((1ULL << (FaParser::ColonColon - 75))
      | (1ULL << (FaParser::Underline - 75))
      | (1ULL << (FaParser::BoolLiteral - 75))
      | (1ULL << (FaParser::IntLiteral - 75))
      | (1ULL << (FaParser::FloatLiteral - 75))
      | (1ULL << (FaParser::String1Literal - 75))
      | (1ULL << (FaParser::RawId - 75)))) != 0)) {
      setState(671);
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
  enterRule(_localctx, 144, FaParser::RuleNewExprItem);
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
    setState(674);
    id();
    setState(677);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Assign) {
      setState(675);
      match(FaParser::Assign);
      setState(676);
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
  enterRule(_localctx, 146, FaParser::RuleNewExpr1);
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
    setState(679);
    match(FaParser::New);
    setState(680);
    typeSingle();
    setState(681);
    quotHuaL();
    setState(690);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Underline

    || _la == FaParser::RawId) {
      setState(682);
      newExprItem();
      setState(687);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FaParser::Comma) {
        setState(683);
        match(FaParser::Comma);
        setState(684);
        newExprItem();
        setState(689);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(692);
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
  enterRule(_localctx, 148, FaParser::RuleNewExpr2);
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
    setState(694);
    match(FaParser::New);
    setState(695);
    typeSingle();
    setState(696);
    quotYuanL();
    setState(705);
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
      | (1ULL << FaParser::SubOp))) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 75)) & ((1ULL << (FaParser::ColonColon - 75))
      | (1ULL << (FaParser::Underline - 75))
      | (1ULL << (FaParser::BoolLiteral - 75))
      | (1ULL << (FaParser::IntLiteral - 75))
      | (1ULL << (FaParser::FloatLiteral - 75))
      | (1ULL << (FaParser::String1Literal - 75))
      | (1ULL << (FaParser::RawId - 75)))) != 0)) {
      setState(697);
      expr();
      setState(702);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FaParser::Comma) {
        setState(698);
        match(FaParser::Comma);
        setState(699);
        expr();
        setState(704);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(707);
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
  enterRule(_localctx, 150, FaParser::RuleArrayExpr1);
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
    setState(709);
    quotFangL();
    setState(710);
    expr();
    setState(711);
    match(FaParser::PointPoint);
    setState(712);
    expr();
    setState(715);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Step) {
      setState(713);
      match(FaParser::Step);
      setState(714);
      expr();
    }
    setState(717);
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
  enterRule(_localctx, 152, FaParser::RuleArrayExpr2);
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
    setState(719);
    quotFangL();
    setState(720);
    expr();
    setState(725);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(721);
      match(FaParser::Comma);
      setState(722);
      expr();
      setState(727);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(728);
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

FaParser::TypeWrapVar2ListContext* FaParser::LambdaExprContext::typeWrapVar2List() {
  return getRuleContext<FaParser::TypeWrapVar2ListContext>(0);
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
  enterRule(_localctx, 154, FaParser::RuleLambdaExpr);
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
    setState(730);
    quotYuanL();
    setState(732);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::T__6)
      | (1ULL << FaParser::Mut)
      | (1ULL << FaParser::Params))) != 0) || _la == FaParser::Underline

    || _la == FaParser::RawId) {
      setState(731);
      typeWrapVar2List();
    }
    setState(734);
    quotYuanR();
    setState(735);
    exprFuncDef();
    setState(746);
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
        setState(736);
        expr();
        break;
      }

      case FaParser::T__4: {
        setState(737);
        quotHuaL();
        setState(741);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(738);
            stmt(); 
          }
          setState(743);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx);
        }
        setState(744);
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

FaParser::IdContext* FaParser::StrongExprBaseContext::id() {
  return getRuleContext<FaParser::IdContext>(0);
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

FaParser::IdExtContext* FaParser::StrongExprBaseContext::idExt() {
  return getRuleContext<FaParser::IdExtContext>(0);
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
  enterRule(_localctx, 156, FaParser::RuleStrongExprBase);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(763);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(749);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == FaParser::ColonColon) {
        setState(748);
        match(FaParser::ColonColon);
      }
      setState(751);
      id();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(752);
      literal();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(753);
      ifExpr();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(754);
      quotExpr();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(755);
      newExpr1();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(756);
      newExpr2();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(757);
      arrayExpr1();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(758);
      arrayExpr2();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(759);
      switchExpr2();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(760);
      switchExpr();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(761);
      lambdaExpr();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(762);
      idExt();
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
  enterRule(_localctx, 158, FaParser::RuleStrongExprPrefix);
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
    setState(765);
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
  enterRule(_localctx, 160, FaParser::RuleStrongExprSuffix);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(803);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::AddAddOp: {
        enterOuterAlt(_localctx, 1);
        setState(767);
        match(FaParser::AddAddOp);
        break;
      }

      case FaParser::SubSubOp: {
        enterOuterAlt(_localctx, 2);
        setState(768);
        match(FaParser::SubSubOp);
        break;
      }

      case FaParser::T__6: {
        enterOuterAlt(_localctx, 3);
        setState(769);
        quotYuanL();
        setState(778);
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
          | (1ULL << FaParser::SubOp))) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 75)) & ((1ULL << (FaParser::ColonColon - 75))
          | (1ULL << (FaParser::Underline - 75))
          | (1ULL << (FaParser::BoolLiteral - 75))
          | (1ULL << (FaParser::IntLiteral - 75))
          | (1ULL << (FaParser::FloatLiteral - 75))
          | (1ULL << (FaParser::String1Literal - 75))
          | (1ULL << (FaParser::RawId - 75)))) != 0)) {
          setState(770);
          expr();
          setState(775);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == FaParser::Comma) {
            setState(771);
            match(FaParser::Comma);
            setState(772);
            expr();
            setState(777);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(780);
        quotYuanR();
        break;
      }

      case FaParser::T__0: {
        enterOuterAlt(_localctx, 4);
        setState(782);
        quotFangL();

        setState(783);
        exprOpt();
        setState(788);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == FaParser::Colon) {
          setState(784);
          match(FaParser::Colon);
          setState(785);
          exprOpt();
          setState(790);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(791);
        quotFangR();
        break;
      }

      case FaParser::PointOp: {
        enterOuterAlt(_localctx, 5);
        setState(793);
        match(FaParser::PointOp);
        setState(794);
        id();
        break;
      }

      case FaParser::Is: {
        enterOuterAlt(_localctx, 6);
        setState(795);
        match(FaParser::Is);
        setState(796);
        ids();
        setState(801);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx)) {
        case 1: {
          setState(797);
          quotYuanL();
          setState(798);
          id();
          setState(799);
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
  enterRule(_localctx, 162, FaParser::RuleStrongExpr);

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
    setState(808);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(805);
        strongExprPrefix(); 
      }
      setState(810);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx);
    }
    setState(811);
    strongExprBase();
    setState(815);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(812);
        strongExprSuffix(); 
      }
      setState(817);
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
  enterRule(_localctx, 164, FaParser::RuleMiddleExpr);

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
    setState(818);
    strongExpr();
    setState(824);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(819);
        allOp2();
        setState(820);
        strongExpr(); 
      }
      setState(826);
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
  enterRule(_localctx, 166, FaParser::RuleExpr);

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
    setState(827);
    middleExpr();
    setState(833);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(828);
        allAssign();
        setState(829);
        middleExpr(); 
      }
      setState(835);
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

//----------------- TmpAssignExprContext ------------------------------------------------------------------

FaParser::TmpAssignExprContext::TmpAssignExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::TmpAssignExprContext::Assign() {
  return getToken(FaParser::Assign, 0);
}

FaParser::MiddleExprContext* FaParser::TmpAssignExprContext::middleExpr() {
  return getRuleContext<FaParser::MiddleExprContext>(0);
}

FaParser::EndlContext* FaParser::TmpAssignExprContext::endl() {
  return getRuleContext<FaParser::EndlContext>(0);
}


size_t FaParser::TmpAssignExprContext::getRuleIndex() const {
  return FaParser::RuleTmpAssignExpr;
}


antlrcpp::Any FaParser::TmpAssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitTmpAssignExpr(this);
  else
    return visitor->visitChildren(this);
}

FaParser::TmpAssignExprContext* FaParser::tmpAssignExpr() {
  TmpAssignExprContext *_localctx = _tracker.createInstance<TmpAssignExprContext>(_ctx, getState());
  enterRule(_localctx, 168, FaParser::RuleTmpAssignExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(836);
    match(FaParser::Assign);
    setState(837);
    middleExpr();
    setState(838);
    endl();
   
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
    setState(840);
    id();
    setState(841);
    match(FaParser::Assign);
    setState(842);
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

FaParser::TypeContext* FaParser::DefVarStmtContext::type() {
  return getRuleContext<FaParser::TypeContext>(0);
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
    setState(844);
    type();
    setState(845);
    idAssignExpr();
    setState(850);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(846);
      match(FaParser::Comma);
      setState(847);
      idAssignExpr();
      setState(852);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(853);
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
  enterRule(_localctx, 174, FaParser::RuleNormalStmt);
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
    setState(863);
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
        setState(856);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == FaParser::Return) {
          setState(855);
          match(FaParser::Return);
        }
        setState(859);
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
          | (1ULL << FaParser::SubOp))) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 75)) & ((1ULL << (FaParser::ColonColon - 75))
          | (1ULL << (FaParser::Underline - 75))
          | (1ULL << (FaParser::BoolLiteral - 75))
          | (1ULL << (FaParser::IntLiteral - 75))
          | (1ULL << (FaParser::FloatLiteral - 75))
          | (1ULL << (FaParser::String1Literal - 75))
          | (1ULL << (FaParser::RawId - 75)))) != 0)) {
          setState(858);
          expr();
        }
        break;
      }

      case FaParser::Break: {
        setState(861);
        match(FaParser::Break);
        break;
      }

      case FaParser::Continue: {
        setState(862);
        match(FaParser::Continue);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(865);
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
  enterRule(_localctx, 176, FaParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(877);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 77, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(867);
      ifStmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(868);
      whileStmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(869);
      whileStmt2();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(870);
      forStmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(871);
      forStmt2();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(872);
      quotStmtPart();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(873);
      switchStmt2();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(874);
      switchStmt();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(875);
      defVarStmt();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(876);
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
  enterRule(_localctx, 178, FaParser::RulePublicLevel);
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
    setState(879);
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
  enterRule(_localctx, 180, FaParser::RuleEnumItem);
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
    setState(881);
    id();

    setState(882);
    quotYuanL();
    setState(883);
    type();
    setState(888);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(884);
      match(FaParser::Comma);
      setState(885);
      type();
      setState(890);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(891);
    quotYuanR();
    setState(894);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx)) {
    case 1: {
      setState(893);
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
  enterRule(_localctx, 182, FaParser::RuleClassItemFuncExtBody);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(909);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::Assign: {
        enterOuterAlt(_localctx, 1);
        setState(896);
        exprFuncDef();
        setState(897);
        expr();
        setState(898);
        match(FaParser::Semi);
        break;
      }

      case FaParser::T__4: {
        enterOuterAlt(_localctx, 2);
        setState(900);
        quotHuaL();
        setState(904);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 80, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(901);
            stmt(); 
          }
          setState(906);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 80, _ctx);
        }
        setState(907);
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

//----------------- ClassItemFuncExtContext ------------------------------------------------------------------

FaParser::ClassItemFuncExtContext::ClassItemFuncExtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::QuotYuanLContext* FaParser::ClassItemFuncExtContext::quotYuanL() {
  return getRuleContext<FaParser::QuotYuanLContext>(0);
}

FaParser::QuotYuanRContext* FaParser::ClassItemFuncExtContext::quotYuanR() {
  return getRuleContext<FaParser::QuotYuanRContext>(0);
}

FaParser::ClassItemFuncExtBodyContext* FaParser::ClassItemFuncExtContext::classItemFuncExtBody() {
  return getRuleContext<FaParser::ClassItemFuncExtBodyContext>(0);
}

FaParser::TypeWrapVarListContext* FaParser::ClassItemFuncExtContext::typeWrapVarList() {
  return getRuleContext<FaParser::TypeWrapVarListContext>(0);
}


size_t FaParser::ClassItemFuncExtContext::getRuleIndex() const {
  return FaParser::RuleClassItemFuncExt;
}


antlrcpp::Any FaParser::ClassItemFuncExtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitClassItemFuncExt(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ClassItemFuncExtContext* FaParser::classItemFuncExt() {
  ClassItemFuncExtContext *_localctx = _tracker.createInstance<ClassItemFuncExtContext>(_ctx, getState());
  enterRule(_localctx, 184, FaParser::RuleClassItemFuncExt);
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
    setState(911);
    quotYuanL();
    setState(913);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::T__6)
      | (1ULL << FaParser::Mut)
      | (1ULL << FaParser::Params))) != 0) || _la == FaParser::Underline

    || _la == FaParser::RawId) {
      setState(912);
      typeWrapVarList();
    }
    setState(915);
    quotYuanR();
    setState(916);
    classItemFuncExtBody();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassItemContext ------------------------------------------------------------------

FaParser::ClassItemContext::ClassItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::TypeContext* FaParser::ClassItemContext::type() {
  return getRuleContext<FaParser::TypeContext>(0);
}

FaParser::IdContext* FaParser::ClassItemContext::id() {
  return getRuleContext<FaParser::IdContext>(0);
}

FaParser::EndlContext* FaParser::ClassItemContext::endl() {
  return getRuleContext<FaParser::EndlContext>(0);
}

FaParser::PublicLevelContext* FaParser::ClassItemContext::publicLevel() {
  return getRuleContext<FaParser::PublicLevelContext>(0);
}

tree::TerminalNode* FaParser::ClassItemContext::Static() {
  return getToken(FaParser::Static, 0);
}

FaParser::ClassItemFuncExtContext* FaParser::ClassItemContext::classItemFuncExt() {
  return getRuleContext<FaParser::ClassItemFuncExtContext>(0);
}


size_t FaParser::ClassItemContext::getRuleIndex() const {
  return FaParser::RuleClassItem;
}


antlrcpp::Any FaParser::ClassItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitClassItem(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ClassItemContext* FaParser::classItem() {
  ClassItemContext *_localctx = _tracker.createInstance<ClassItemContext>(_ctx, getState());
  enterRule(_localctx, 186, FaParser::RuleClassItem);
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
    setState(919);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(918);
      publicLevel();
    }
    setState(922);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Static) {
      setState(921);
      match(FaParser::Static);
    }
    setState(924);
    type();
    setState(925);
    id();
    setState(927);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::T__6) {
      setState(926);
      classItemFuncExt();
    }
    setState(929);
    endl();
   
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

std::vector<FaParser::ClassItemContext *> FaParser::EnumBlockContext::classItem() {
  return getRuleContexts<FaParser::ClassItemContext>();
}

FaParser::ClassItemContext* FaParser::EnumBlockContext::classItem(size_t i) {
  return getRuleContext<FaParser::ClassItemContext>(i);
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
  enterRule(_localctx, 188, FaParser::RuleEnumBlock);
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
    setState(932);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(931);
      publicLevel();
    }
    setState(934);
    match(FaParser::Enum);
    setState(935);
    id();
    setState(936);
    quotHuaL();
    setState(938); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(937);
              enumItem();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(940); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 87, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(945);
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
      setState(942);
      classItem();
      setState(947);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(948);
    quotHuaR();
    setState(949);
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

std::vector<FaParser::ClassItemContext *> FaParser::ClassBlockContext::classItem() {
  return getRuleContexts<FaParser::ClassItemContext>();
}

FaParser::ClassItemContext* FaParser::ClassBlockContext::classItem(size_t i) {
  return getRuleContext<FaParser::ClassItemContext>(i);
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
  enterRule(_localctx, 190, FaParser::RuleClassBlock);
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
    setState(952);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(951);
      publicLevel();
    }
    setState(954);
    match(FaParser::Class);
    setState(955);
    id();
    setState(956);
    quotHuaL();
    setState(960);
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
      setState(957);
      classItem();
      setState(962);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(963);
    quotHuaR();
    setState(964);
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
  enterRule(_localctx, 192, FaParser::RuleUseStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(966);
    match(FaParser::Use);
    setState(970);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 91, _ctx)) {
    case 1: {
      setState(967);
      id();
      setState(968);
      match(FaParser::Assign);
      break;
    }

    default:
      break;
    }
    setState(972);
    ids();
    setState(973);
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
  enterRule(_localctx, 194, FaParser::RuleCallConvention);
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
    setState(975);
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
  enterRule(_localctx, 196, FaParser::RuleImportStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(977);
    match(FaParser::AImport);
    setState(978);
    type();
    setState(979);
    callConvention();
    setState(980);
    id();
    setState(981);
    quotYuanL();
    setState(982);
    typeVarList();
    setState(983);
    quotYuanR();
    setState(984);
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
  enterRule(_localctx, 198, FaParser::RuleLibStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(986);
    match(FaParser::ALib);
    setState(987);
    match(FaParser::String1Literal);
    setState(988);
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
  enterRule(_localctx, 200, FaParser::RuleNamespaceStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(990);
    match(FaParser::Namespace);
    setState(991);
    ids();
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

std::vector<FaParser::ClassBlockContext *> FaParser::ProgramContext::classBlock() {
  return getRuleContexts<FaParser::ClassBlockContext>();
}

FaParser::ClassBlockContext* FaParser::ProgramContext::classBlock(size_t i) {
  return getRuleContext<FaParser::ClassBlockContext>(i);
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
  enterRule(_localctx, 202, FaParser::RuleProgram);
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
    setState(999);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::AImport)
      | (1ULL << FaParser::ALib)
      | (1ULL << FaParser::Use))) != 0)) {
      setState(997);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case FaParser::Use: {
          setState(994);
          useStmt();
          break;
        }

        case FaParser::AImport: {
          setState(995);
          importStmt();
          break;
        }

        case FaParser::ALib: {
          setState(996);
          libStmt();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(1001);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1003);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Namespace) {
      setState(1002);
      namespaceStmt();
    }
    setState(1009);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Class)
      | (1ULL << FaParser::Enum)
      | (1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(1007);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 95, _ctx)) {
      case 1: {
        setState(1005);
        enumBlock();
        break;
      }

      case 2: {
        setState(1006);
        classBlock();
        break;
      }

      default:
        break;
      }
      setState(1011);
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
  enterRule(_localctx, 204, FaParser::RuleProgramEntry);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1012);
    program();
    setState(1013);
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
  "allOp2", "intNum", "floatNum", "literal", "id", "ids", "idExt", "typeAfter", 
  "typeSingle", "typeMulti", "type", "typeWrap", "typeVar", "typeVarList", 
  "typeWrapVar", "typeWrapVarList", "typeWrapVar2", "typeWrapVar2List", 
  "quotStmtPart", "quotStmtExpr", "ifStmt", "ifExpr", "whileStmt", "whileStmt2", 
  "forStmt", "forStmt2", "switchStmtPart2Last", "quotStmtExprWrap", "switchExprPartLast", 
  "switchStmtPart", "switchStmt", "switchStmtPart2", "switchStmt2", "switchExprPart", 
  "switchExpr", "switchExprPart2", "switchExpr2", "quotExpr", "exprOpt", 
  "newExprItem", "newExpr1", "newExpr2", "arrayExpr1", "arrayExpr2", "lambdaExpr", 
  "strongExprBase", "strongExprPrefix", "strongExprSuffix", "strongExpr", 
  "middleExpr", "expr", "tmpAssignExpr", "idAssignExpr", "defVarStmt", "normalStmt", 
  "stmt", "publicLevel", "enumItem", "classItemFuncExtBody", "classItemFuncExt", 
  "classItem", "enumBlock", "classBlock", "useStmt", "callConvention", "importStmt", 
  "libStmt", "namespaceStmt", "program", "programEntry"
};

std::vector<std::string> FaParser::_literalNames = {
  "", "'['", "']'", "'<'", "'>'", "'{'", "'}'", "'('", "')'", "'@import'", 
  "'@lib'", "'break'", "'__cdecl'", "'__fastcall'", "'__stdcall'", "'continue'", 
  "'class'", "'const'", "'do'", "'else'", "'enum'", "'FaMain'", "'for'", 
  "'if'", "'is'", "'internal'", "'mut'", "'namespace'", "'new'", "'params'", 
  "'public'", "'protected'", "'private'", "'return'", "'signed'", "'static'", 
  "'step'", "'switch'", "'unsigned'", "'use'", "'when'", "'while'", "'='", 
  "", "", "", "", "", "", "", "", "", "", "", "", "'~'", "'++'", "'--'", 
  "'!'", "'..'", "'.'", "'+'", "'-'", "'*'", "'/'", "'%'", "'|'", "'&'", 
  "'^'", "", "", "", "", "'\u003F'", "','", "'::'", "':'", "'\n'", "';'", 
  "'_'"
};

std::vector<std::string> FaParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "AImport", "ALib", "Break", "CC__Cdecl", 
  "CC__FastCall", "CC__StdCall", "Continue", "Class", "Const", "Do", "Else", 
  "Enum", "FaMain", "For", "If", "Is", "Internal", "Mut", "Namespace", "New", 
  "Params", "Public", "Protected", "Private", "Return", "Signed", "Static", 
  "Step", "Switch", "Unsigned", "Use", "When", "While", "Assign", "AddAssign", 
  "SubAssign", "StarAssign", "DivAssign", "ModAssign", "OrAssign", "AndAssign", 
  "XorAssign", "QusQusAssign", "StarStarAssign", "AndAndAssign", "OrOrAssign", 
  "ReverseOp", "AddAddOp", "SubSubOp", "Exclam", "PointPoint", "PointOp", 
  "AddOp", "SubOp", "StarOp", "DivOp", "ModOp", "OrOp", "AndOp", "XorOp", 
  "QusQusOp", "StarStarOp", "AndAndOp", "OrOrOp", "Qus", "Comma", "ColonColon", 
  "Colon", "Lf", "Semi", "Underline", "BoolLiteral", "IntLiteral", "FloatLiteral", 
  "String1Literal", "RawId", "Comment1", "Comment2", "WS"
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
       0x3, 0x59, 0x3fa, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
       0x9, 0x68, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0xe6, 0xa, 0x4, 0x3, 0x5, 0x3, 
       0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x6, 0x7, 
       0xef, 0xa, 0x7, 0xd, 0x7, 0xe, 0x7, 0xf0, 0x3, 0x8, 0x6, 0x8, 0xf4, 
       0xa, 0x8, 0xd, 0x8, 0xe, 0x8, 0xf5, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 
       0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 
       0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 
       0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x10a, 0xa, 0x11, 0x3, 0x12, 0x5, 
       0x12, 0x10d, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 
       0x5, 0x13, 0x113, 0xa, 0x13, 0x3, 0x14, 0x5, 0x14, 0x116, 0xa, 0x14, 
       0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x11c, 0xa, 
       0x15, 0x3, 0x16, 0x5, 0x16, 0x11f, 0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 
       0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x125, 0xa, 0x17, 0x3, 0x18, 0x5, 
       0x18, 0x128, 0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 
       0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 
       0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 
       0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 
       0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
       0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
       0x5, 0x20, 0x14c, 0xa, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 
       0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x154, 0xa, 0x21, 0x3, 0x22, 
       0x3, 0x22, 0x5, 0x22, 0x158, 0xa, 0x22, 0x3, 0x23, 0x3, 0x23, 0x5, 
       0x23, 0x15c, 0xa, 0x23, 0x3, 0x24, 0x5, 0x24, 0x15f, 0xa, 0x24, 0x3, 
       0x24, 0x3, 0x24, 0x3, 0x25, 0x5, 0x25, 0x164, 0xa, 0x25, 0x3, 0x25, 
       0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 
       0x16c, 0xa, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 
       0x28, 0x7, 0x28, 0x173, 0xa, 0x28, 0xc, 0x28, 0xe, 0x28, 0x176, 0xb, 
       0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x7, 
       0x29, 0x17d, 0xa, 0x29, 0xc, 0x29, 0xe, 0x29, 0x180, 0xb, 0x29, 0x3, 
       0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 
       0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x18a, 0xa, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 
       0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x7, 0x2b, 0x191, 0xa, 0x2b, 0xc, 
       0x2b, 0xe, 0x2b, 0x194, 0xb, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 
       0x198, 0xa, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x6, 
       0x2c, 0x19e, 0xa, 0x2c, 0xd, 0x2c, 0xe, 0x2c, 0x19f, 0x3, 0x2c, 0x3, 
       0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x1a6, 0xa, 0x2d, 0x3, 0x2d, 
       0x7, 0x2d, 0x1a9, 0xa, 0x2d, 0xc, 0x2d, 0xe, 0x2d, 0x1ac, 0xb, 0x2d, 
       0x3, 0x2e, 0x5, 0x2e, 0x1af, 0xa, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 
       0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x1b5, 0xa, 0x2f, 0x3, 0x30, 0x3, 0x30, 
       0x3, 0x30, 0x7, 0x30, 0x1ba, 0xa, 0x30, 0xc, 0x30, 0xe, 0x30, 0x1bd, 
       0xb, 0x30, 0x3, 0x31, 0x3, 0x31, 0x5, 0x31, 0x1c1, 0xa, 0x31, 0x3, 
       0x32, 0x3, 0x32, 0x3, 0x32, 0x7, 0x32, 0x1c6, 0xa, 0x32, 0xc, 0x32, 
       0xe, 0x32, 0x1c9, 0xb, 0x32, 0x3, 0x33, 0x5, 0x33, 0x1cc, 0xa, 0x33, 
       0x3, 0x33, 0x3, 0x33, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x7, 0x34, 
       0x1d3, 0xa, 0x34, 0xc, 0x34, 0xe, 0x34, 0x1d6, 0xb, 0x34, 0x3, 0x35, 
       0x3, 0x35, 0x7, 0x35, 0x1da, 0xa, 0x35, 0xc, 0x35, 0xe, 0x35, 0x1dd, 
       0xb, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x36, 0x3, 0x36, 0x7, 0x36, 
       0x1e3, 0xa, 0x36, 0xc, 0x36, 0xe, 0x36, 0x1e6, 0xb, 0x36, 0x3, 0x36, 
       0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 
       0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x7, 0x37, 0x1f3, 0xa, 
       0x37, 0xc, 0x37, 0xe, 0x37, 0x1f6, 0xb, 0x37, 0x3, 0x37, 0x3, 0x37, 
       0x5, 0x37, 0x1fa, 0xa, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 
       0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x7, 0x38, 0x204, 
       0xa, 0x38, 0xc, 0x38, 0xe, 0x38, 0x207, 0xb, 0x38, 0x3, 0x38, 0x3, 
       0x38, 0x3, 0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x7, 
       0x39, 0x210, 0xa, 0x39, 0xc, 0x39, 0xe, 0x39, 0x213, 0xb, 0x39, 0x3, 
       0x39, 0x3, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x7, 0x3a, 0x21a, 
       0xa, 0x3a, 0xc, 0x3a, 0xe, 0x3a, 0x21d, 0xb, 0x3a, 0x3, 0x3a, 0x3, 
       0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 
       0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x7, 0x3b, 0x22a, 0xa, 0x3b, 
       0xc, 0x3b, 0xe, 0x3b, 0x22d, 0xb, 0x3b, 0x5, 0x3b, 0x22f, 0xa, 0x3b, 
       0x3, 0x3b, 0x3, 0x3b, 0x7, 0x3b, 0x233, 0xa, 0x3b, 0xc, 0x3b, 0xe, 
       0x3b, 0x236, 0xb, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 
       0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x7, 0x3c, 
       0x241, 0xa, 0x3c, 0xc, 0x3c, 0xe, 0x3c, 0x244, 0xb, 0x3c, 0x3, 0x3c, 
       0x3, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3e, 
       0x3, 0x3e, 0x5, 0x3e, 0x24e, 0xa, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 
       0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x5, 
       0x40, 0x258, 0xa, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x41, 
       0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x7, 0x41, 0x261, 0xa, 0x41, 0xc, 
       0x41, 0xe, 0x41, 0x264, 0xb, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x42, 
       0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x43, 0x3, 0x43, 
       0x3, 0x43, 0x7, 0x43, 0x270, 0xa, 0x43, 0xc, 0x43, 0xe, 0x43, 0x273, 
       0xb, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x44, 0x3, 0x44, 
       0x3, 0x44, 0x5, 0x44, 0x27b, 0xa, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 
       0x44, 0x3, 0x44, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x7, 
       0x45, 0x285, 0xa, 0x45, 0xc, 0x45, 0xe, 0x45, 0x288, 0xb, 0x45, 0x3, 
       0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 
       0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x7, 
       0x47, 0x296, 0xa, 0x47, 0xc, 0x47, 0xe, 0x47, 0x299, 0xb, 0x47, 0x3, 
       0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 
       0x48, 0x3, 0x49, 0x5, 0x49, 0x2a3, 0xa, 0x49, 0x3, 0x4a, 0x3, 0x4a, 
       0x3, 0x4a, 0x5, 0x4a, 0x2a8, 0xa, 0x4a, 0x3, 0x4b, 0x3, 0x4b, 0x3, 
       0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x7, 0x4b, 0x2b0, 0xa, 0x4b, 
       0xc, 0x4b, 0xe, 0x4b, 0x2b3, 0xb, 0x4b, 0x5, 0x4b, 0x2b5, 0xa, 0x4b, 
       0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 
       0x3, 0x4c, 0x3, 0x4c, 0x7, 0x4c, 0x2bf, 0xa, 0x4c, 0xc, 0x4c, 0xe, 
       0x4c, 0x2c2, 0xb, 0x4c, 0x5, 0x4c, 0x2c4, 0xa, 0x4c, 0x3, 0x4c, 0x3, 
       0x4c, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 
       0x4d, 0x5, 0x4d, 0x2ce, 0xa, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4e, 
       0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x7, 0x4e, 0x2d6, 0xa, 0x4e, 0xc, 
       0x4e, 0xe, 0x4e, 0x2d9, 0xb, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4f, 
       0x3, 0x4f, 0x5, 0x4f, 0x2df, 0xa, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 
       0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x7, 0x4f, 0x2e6, 0xa, 0x4f, 0xc, 0x4f, 
       0xe, 0x4f, 0x2e9, 0xb, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x5, 0x4f, 0x2ed, 
       0xa, 0x4f, 0x3, 0x50, 0x5, 0x50, 0x2f0, 0xa, 0x50, 0x3, 0x50, 0x3, 
       0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 
       0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x5, 0x50, 0x2fe, 
       0xa, 0x50, 0x3, 0x51, 0x3, 0x51, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 
       0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x7, 0x52, 0x308, 0xa, 0x52, 0xc, 
       0x52, 0xe, 0x52, 0x30b, 0xb, 0x52, 0x5, 0x52, 0x30d, 0xa, 0x52, 0x3, 
       0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x7, 
       0x52, 0x315, 0xa, 0x52, 0xc, 0x52, 0xe, 0x52, 0x318, 0xb, 0x52, 0x3, 
       0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 
       0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x5, 0x52, 0x324, 0xa, 0x52, 
       0x5, 0x52, 0x326, 0xa, 0x52, 0x3, 0x53, 0x7, 0x53, 0x329, 0xa, 0x53, 
       0xc, 0x53, 0xe, 0x53, 0x32c, 0xb, 0x53, 0x3, 0x53, 0x3, 0x53, 0x7, 
       0x53, 0x330, 0xa, 0x53, 0xc, 0x53, 0xe, 0x53, 0x333, 0xb, 0x53, 0x3, 
       0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x7, 0x54, 0x339, 0xa, 0x54, 
       0xc, 0x54, 0xe, 0x54, 0x33c, 0xb, 0x54, 0x3, 0x55, 0x3, 0x55, 0x3, 
       0x55, 0x3, 0x55, 0x7, 0x55, 0x342, 0xa, 0x55, 0xc, 0x55, 0xe, 0x55, 
       0x345, 0xb, 0x55, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 
       0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x58, 0x3, 0x58, 0x3, 
       0x58, 0x3, 0x58, 0x7, 0x58, 0x353, 0xa, 0x58, 0xc, 0x58, 0xe, 0x58, 
       0x356, 0xb, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x59, 0x5, 0x59, 0x35b, 
       0xa, 0x59, 0x3, 0x59, 0x5, 0x59, 0x35e, 0xa, 0x59, 0x3, 0x59, 0x3, 
       0x59, 0x5, 0x59, 0x362, 0xa, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x5a, 
       0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 
       0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x5, 0x5a, 0x370, 0xa, 0x5a, 0x3, 
       0x5b, 0x3, 0x5b, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 
       0x5c, 0x7, 0x5c, 0x379, 0xa, 0x5c, 0xc, 0x5c, 0xe, 0x5c, 0x37c, 0xb, 
       0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x5, 0x5c, 0x381, 0xa, 0x5c, 
       0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 
       0x7, 0x5d, 0x389, 0xa, 0x5d, 0xc, 0x5d, 0xe, 0x5d, 0x38c, 0xb, 0x5d, 
       0x3, 0x5d, 0x3, 0x5d, 0x5, 0x5d, 0x390, 0xa, 0x5d, 0x3, 0x5e, 0x3, 
       0x5e, 0x5, 0x5e, 0x394, 0xa, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 
       0x3, 0x5f, 0x5, 0x5f, 0x39a, 0xa, 0x5f, 0x3, 0x5f, 0x5, 0x5f, 0x39d, 
       0xa, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x5, 0x5f, 0x3a2, 0xa, 
       0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x60, 0x5, 0x60, 0x3a7, 0xa, 0x60, 
       0x3, 0x60, 0x3, 0x60, 0x3, 0x60, 0x3, 0x60, 0x6, 0x60, 0x3ad, 0xa, 
       0x60, 0xd, 0x60, 0xe, 0x60, 0x3ae, 0x3, 0x60, 0x7, 0x60, 0x3b2, 0xa, 
       0x60, 0xc, 0x60, 0xe, 0x60, 0x3b5, 0xb, 0x60, 0x3, 0x60, 0x3, 0x60, 
       0x3, 0x60, 0x3, 0x61, 0x5, 0x61, 0x3bb, 0xa, 0x61, 0x3, 0x61, 0x3, 
       0x61, 0x3, 0x61, 0x3, 0x61, 0x7, 0x61, 0x3c1, 0xa, 0x61, 0xc, 0x61, 
       0xe, 0x61, 0x3c4, 0xb, 0x61, 0x3, 0x61, 0x3, 0x61, 0x3, 0x61, 0x3, 
       0x62, 0x3, 0x62, 0x3, 0x62, 0x3, 0x62, 0x5, 0x62, 0x3cd, 0xa, 0x62, 
       0x3, 0x62, 0x3, 0x62, 0x3, 0x62, 0x3, 0x63, 0x3, 0x63, 0x3, 0x64, 
       0x3, 0x64, 0x3, 0x64, 0x3, 0x64, 0x3, 0x64, 0x3, 0x64, 0x3, 0x64, 
       0x3, 0x64, 0x3, 0x64, 0x3, 0x65, 0x3, 0x65, 0x3, 0x65, 0x3, 0x65, 
       0x3, 0x66, 0x3, 0x66, 0x3, 0x66, 0x3, 0x66, 0x3, 0x67, 0x3, 0x67, 
       0x3, 0x67, 0x7, 0x67, 0x3e8, 0xa, 0x67, 0xc, 0x67, 0xe, 0x67, 0x3eb, 
       0xb, 0x67, 0x3, 0x67, 0x5, 0x67, 0x3ee, 0xa, 0x67, 0x3, 0x67, 0x3, 
       0x67, 0x7, 0x67, 0x3f2, 0xa, 0x67, 0xc, 0x67, 0xe, 0x67, 0x3f5, 0xb, 
       0x67, 0x3, 0x68, 0x3, 0x68, 0x3, 0x68, 0x3, 0x68, 0x2, 0x2, 0x69, 
       0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 
       0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 
       0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 
       0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 
       0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 
       0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 
       0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 
       0x9e, 0xa0, 0xa2, 0xa4, 0xa6, 0xa8, 0xaa, 0xac, 0xae, 0xb0, 0xb2, 
       0xb4, 0xb6, 0xb8, 0xba, 0xbc, 0xbe, 0xc0, 0xc2, 0xc4, 0xc6, 0xc8, 
       0xca, 0xcc, 0xce, 0x2, 0x9, 0x3, 0x2, 0x4f, 0x50, 0x4, 0x2, 0x4c, 
       0x4c, 0x4f, 0x4f, 0x4, 0x2, 0x51, 0x51, 0x56, 0x56, 0x4, 0x2, 0x1c, 
       0x1c, 0x1f, 0x1f, 0x4, 0x2, 0x39, 0x3c, 0x40, 0x40, 0x4, 0x2, 0x1b, 
       0x1b, 0x20, 0x22, 0x3, 0x2, 0xe, 0x10, 0x2, 0x429, 0x2, 0xd0, 0x3, 
       0x2, 0x2, 0x2, 0x4, 0xd3, 0x3, 0x2, 0x2, 0x2, 0x6, 0xe5, 0x3, 0x2, 
       0x2, 0x2, 0x8, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xa, 0xea, 0x3, 0x2, 0x2, 
       0x2, 0xc, 0xee, 0x3, 0x2, 0x2, 0x2, 0xe, 0xf3, 0x3, 0x2, 0x2, 0x2, 
       0x10, 0xf7, 0x3, 0x2, 0x2, 0x2, 0x12, 0xf9, 0x3, 0x2, 0x2, 0x2, 0x14, 
       0xfb, 0x3, 0x2, 0x2, 0x2, 0x16, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x18, 0xff, 
       0x3, 0x2, 0x2, 0x2, 0x1a, 0x101, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x103, 
       0x3, 0x2, 0x2, 0x2, 0x1e, 0x105, 0x3, 0x2, 0x2, 0x2, 0x20, 0x107, 
       0x3, 0x2, 0x2, 0x2, 0x22, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x24, 0x110, 
       0x3, 0x2, 0x2, 0x2, 0x26, 0x115, 0x3, 0x2, 0x2, 0x2, 0x28, 0x119, 
       0x3, 0x2, 0x2, 0x2, 0x2a, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x122, 
       0x3, 0x2, 0x2, 0x2, 0x2e, 0x127, 0x3, 0x2, 0x2, 0x2, 0x30, 0x12b, 
       0x3, 0x2, 0x2, 0x2, 0x32, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x34, 0x130, 
       0x3, 0x2, 0x2, 0x2, 0x36, 0x132, 0x3, 0x2, 0x2, 0x2, 0x38, 0x135, 
       0x3, 0x2, 0x2, 0x2, 0x3a, 0x138, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x13b, 
       0x3, 0x2, 0x2, 0x2, 0x3e, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x40, 0x153, 
       0x3, 0x2, 0x2, 0x2, 0x42, 0x157, 0x3, 0x2, 0x2, 0x2, 0x44, 0x15b, 
       0x3, 0x2, 0x2, 0x2, 0x46, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x48, 0x163, 
       0x3, 0x2, 0x2, 0x2, 0x4a, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x16d, 
       0x3, 0x2, 0x2, 0x2, 0x4e, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x50, 0x177, 
       0x3, 0x2, 0x2, 0x2, 0x52, 0x189, 0x3, 0x2, 0x2, 0x2, 0x54, 0x18b, 
       0x3, 0x2, 0x2, 0x2, 0x56, 0x199, 0x3, 0x2, 0x2, 0x2, 0x58, 0x1a5, 
       0x3, 0x2, 0x2, 0x2, 0x5a, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x1b2, 
       0x3, 0x2, 0x2, 0x2, 0x5e, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x60, 0x1be, 
       0x3, 0x2, 0x2, 0x2, 0x62, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x64, 0x1cb, 
       0x3, 0x2, 0x2, 0x2, 0x66, 0x1cf, 0x3, 0x2, 0x2, 0x2, 0x68, 0x1d7, 
       0x3, 0x2, 0x2, 0x2, 0x6a, 0x1e0, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x1ea, 
       0x3, 0x2, 0x2, 0x2, 0x6e, 0x1fb, 0x3, 0x2, 0x2, 0x2, 0x70, 0x20b, 
       0x3, 0x2, 0x2, 0x2, 0x72, 0x216, 0x3, 0x2, 0x2, 0x2, 0x74, 0x222, 
       0x3, 0x2, 0x2, 0x2, 0x76, 0x239, 0x3, 0x2, 0x2, 0x2, 0x78, 0x247, 
       0x3, 0x2, 0x2, 0x2, 0x7a, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x24f, 
       0x3, 0x2, 0x2, 0x2, 0x7e, 0x254, 0x3, 0x2, 0x2, 0x2, 0x80, 0x25c, 
       0x3, 0x2, 0x2, 0x2, 0x82, 0x267, 0x3, 0x2, 0x2, 0x2, 0x84, 0x26c, 
       0x3, 0x2, 0x2, 0x2, 0x86, 0x277, 0x3, 0x2, 0x2, 0x2, 0x88, 0x280, 
       0x3, 0x2, 0x2, 0x2, 0x8a, 0x28c, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x292, 
       0x3, 0x2, 0x2, 0x2, 0x8e, 0x29d, 0x3, 0x2, 0x2, 0x2, 0x90, 0x2a2, 
       0x3, 0x2, 0x2, 0x2, 0x92, 0x2a4, 0x3, 0x2, 0x2, 0x2, 0x94, 0x2a9, 
       0x3, 0x2, 0x2, 0x2, 0x96, 0x2b8, 0x3, 0x2, 0x2, 0x2, 0x98, 0x2c7, 
       0x3, 0x2, 0x2, 0x2, 0x9a, 0x2d1, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x2dc, 
       0x3, 0x2, 0x2, 0x2, 0x9e, 0x2fd, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x2ff, 
       0x3, 0x2, 0x2, 0x2, 0xa2, 0x325, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x32a, 
       0x3, 0x2, 0x2, 0x2, 0xa6, 0x334, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x33d, 
       0x3, 0x2, 0x2, 0x2, 0xaa, 0x346, 0x3, 0x2, 0x2, 0x2, 0xac, 0x34a, 
       0x3, 0x2, 0x2, 0x2, 0xae, 0x34e, 0x3, 0x2, 0x2, 0x2, 0xb0, 0x361, 
       0x3, 0x2, 0x2, 0x2, 0xb2, 0x36f, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x371, 
       0x3, 0x2, 0x2, 0x2, 0xb6, 0x373, 0x3, 0x2, 0x2, 0x2, 0xb8, 0x38f, 
       0x3, 0x2, 0x2, 0x2, 0xba, 0x391, 0x3, 0x2, 0x2, 0x2, 0xbc, 0x399, 
       0x3, 0x2, 0x2, 0x2, 0xbe, 0x3a6, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x3ba, 
       0x3, 0x2, 0x2, 0x2, 0xc2, 0x3c8, 0x3, 0x2, 0x2, 0x2, 0xc4, 0x3d1, 
       0x3, 0x2, 0x2, 0x2, 0xc6, 0x3d3, 0x3, 0x2, 0x2, 0x2, 0xc8, 0x3dc, 
       0x3, 0x2, 0x2, 0x2, 0xca, 0x3e0, 0x3, 0x2, 0x2, 0x2, 0xcc, 0x3e9, 
       0x3, 0x2, 0x2, 0x2, 0xce, 0x3f6, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 
       0x5, 0x8, 0x5, 0x2, 0xd1, 0xd2, 0x7, 0x2c, 0x2, 0x2, 0xd2, 0x3, 0x3, 
       0x2, 0x2, 0x2, 0xd3, 0xd4, 0x5, 0xa, 0x6, 0x2, 0xd4, 0xd5, 0x7, 0x2c, 
       0x2, 0x2, 0xd5, 0x5, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xe6, 0x7, 0x2c, 0x2, 
       0x2, 0xd7, 0xe6, 0x7, 0x35, 0x2, 0x2, 0xd8, 0xe6, 0x7, 0x2d, 0x2, 
       0x2, 0xd9, 0xe6, 0x7, 0x2e, 0x2, 0x2, 0xda, 0xe6, 0x7, 0x2f, 0x2, 
       0x2, 0xdb, 0xe6, 0x7, 0x36, 0x2, 0x2, 0xdc, 0xe6, 0x7, 0x30, 0x2, 
       0x2, 0xdd, 0xe6, 0x7, 0x31, 0x2, 0x2, 0xde, 0xe6, 0x7, 0x33, 0x2, 
       0x2, 0xdf, 0xe6, 0x7, 0x32, 0x2, 0x2, 0xe0, 0xe6, 0x7, 0x34, 0x2, 
       0x2, 0xe1, 0xe6, 0x7, 0x37, 0x2, 0x2, 0xe2, 0xe6, 0x7, 0x38, 0x2, 
       0x2, 0xe3, 0xe6, 0x5, 0x2, 0x2, 0x2, 0xe4, 0xe6, 0x5, 0x4, 0x3, 0x2, 
       0xe5, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xe5, 
       0xd8, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xda, 
       0x3, 0x2, 0x2, 0x2, 0xe5, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xdc, 0x3, 
       0x2, 0x2, 0x2, 0xe5, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xde, 0x3, 0x2, 
       0x2, 0x2, 0xe5, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe0, 0x3, 0x2, 0x2, 
       0x2, 0xe5, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe2, 0x3, 0x2, 0x2, 0x2, 
       0xe5, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe6, 
       0x7, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 0x5, 0x14, 0xb, 0x2, 0xe8, 0xe9, 
       0x5, 0x14, 0xb, 0x2, 0xe9, 0x9, 0x3, 0x2, 0x2, 0x2, 0xea, 0xeb, 0x5, 
       0x16, 0xc, 0x2, 0xeb, 0xec, 0x5, 0x16, 0xc, 0x2, 0xec, 0xb, 0x3, 
       0x2, 0x2, 0x2, 0xed, 0xef, 0x9, 0x2, 0x2, 0x2, 0xee, 0xed, 0x3, 0x2, 
       0x2, 0x2, 0xef, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xee, 0x3, 0x2, 0x2, 
       0x2, 0xf0, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xd, 0x3, 0x2, 0x2, 0x2, 
       0xf2, 0xf4, 0x9, 0x3, 0x2, 0x2, 0xf3, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf4, 
       0xf5, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf6, 
       0x3, 0x2, 0x2, 0x2, 0xf6, 0xf, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf8, 0x7, 
       0x3, 0x2, 0x2, 0xf8, 0x11, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x7, 0x4, 
       0x2, 0x2, 0xfa, 0x13, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 0x7, 0x5, 0x2, 
       0x2, 0xfc, 0x15, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xfe, 0x7, 0x6, 0x2, 0x2, 
       0xfe, 0x17, 0x3, 0x2, 0x2, 0x2, 0xff, 0x100, 0x7, 0x7, 0x2, 0x2, 
       0x100, 0x19, 0x3, 0x2, 0x2, 0x2, 0x101, 0x102, 0x7, 0x8, 0x2, 0x2, 
       0x102, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x103, 0x104, 0x7, 0x9, 0x2, 0x2, 
       0x104, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 0x7, 0xa, 0x2, 0x2, 
       0x106, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x107, 0x109, 0x5, 0x10, 0x9, 0x2, 
       0x108, 0x10a, 0x5, 0xc, 0x7, 0x2, 0x109, 0x108, 0x3, 0x2, 0x2, 0x2, 
       0x109, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x21, 0x3, 0x2, 0x2, 0x2, 
       0x10b, 0x10d, 0x5, 0xc, 0x7, 0x2, 0x10c, 0x10b, 0x3, 0x2, 0x2, 0x2, 
       0x10c, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 0x3, 0x2, 0x2, 0x2, 
       0x10e, 0x10f, 0x5, 0x12, 0xa, 0x2, 0x10f, 0x23, 0x3, 0x2, 0x2, 0x2, 
       0x110, 0x112, 0x5, 0x14, 0xb, 0x2, 0x111, 0x113, 0x5, 0xc, 0x7, 0x2, 
       0x112, 0x111, 0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 0x3, 0x2, 0x2, 0x2, 
       0x113, 0x25, 0x3, 0x2, 0x2, 0x2, 0x114, 0x116, 0x5, 0xc, 0x7, 0x2, 
       0x115, 0x114, 0x3, 0x2, 0x2, 0x2, 0x115, 0x116, 0x3, 0x2, 0x2, 0x2, 
       0x116, 0x117, 0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 0x5, 0x16, 0xc, 0x2, 
       0x118, 0x27, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11b, 0x5, 0x18, 0xd, 0x2, 
       0x11a, 0x11c, 0x5, 0xc, 0x7, 0x2, 0x11b, 0x11a, 0x3, 0x2, 0x2, 0x2, 
       0x11b, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x29, 0x3, 0x2, 0x2, 0x2, 
       0x11d, 0x11f, 0x5, 0xc, 0x7, 0x2, 0x11e, 0x11d, 0x3, 0x2, 0x2, 0x2, 
       0x11e, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x120, 0x3, 0x2, 0x2, 0x2, 
       0x120, 0x121, 0x5, 0x1a, 0xe, 0x2, 0x121, 0x2b, 0x3, 0x2, 0x2, 0x2, 
       0x122, 0x124, 0x5, 0x1c, 0xf, 0x2, 0x123, 0x125, 0x5, 0xc, 0x7, 0x2, 
       0x124, 0x123, 0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 0x3, 0x2, 0x2, 0x2, 
       0x125, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x126, 0x128, 0x5, 0xc, 0x7, 0x2, 
       0x127, 0x126, 0x3, 0x2, 0x2, 0x2, 0x127, 0x128, 0x3, 0x2, 0x2, 0x2, 
       0x128, 0x129, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12a, 0x5, 0x1e, 0x10, 
       0x2, 0x12a, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 0x5, 0x14, 0xb, 
       0x2, 0x12c, 0x31, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 0x5, 0x14, 0xb, 
       0x2, 0x12e, 0x12f, 0x7, 0x2c, 0x2, 0x2, 0x12f, 0x33, 0x3, 0x2, 0x2, 
       0x2, 0x130, 0x131, 0x5, 0x16, 0xc, 0x2, 0x131, 0x35, 0x3, 0x2, 0x2, 
       0x2, 0x132, 0x133, 0x5, 0x16, 0xc, 0x2, 0x133, 0x134, 0x7, 0x2c, 
       0x2, 0x2, 0x134, 0x37, 0x3, 0x2, 0x2, 0x2, 0x135, 0x136, 0x7, 0x2c, 
       0x2, 0x2, 0x136, 0x137, 0x7, 0x2c, 0x2, 0x2, 0x137, 0x39, 0x3, 0x2, 
       0x2, 0x2, 0x138, 0x139, 0x7, 0x3c, 0x2, 0x2, 0x139, 0x13a, 0x7, 0x2c, 
       0x2, 0x2, 0x13a, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x13c, 0x7, 0x2c, 
       0x2, 0x2, 0x13c, 0x13d, 0x5, 0x16, 0xc, 0x2, 0x13d, 0x3d, 0x3, 0x2, 
       0x2, 0x2, 0x13e, 0x14c, 0x7, 0x3f, 0x2, 0x2, 0x13f, 0x14c, 0x7, 0x40, 
       0x2, 0x2, 0x140, 0x14c, 0x7, 0x41, 0x2, 0x2, 0x141, 0x14c, 0x7, 0x42, 
       0x2, 0x2, 0x142, 0x14c, 0x7, 0x48, 0x2, 0x2, 0x143, 0x14c, 0x7, 0x43, 
       0x2, 0x2, 0x144, 0x14c, 0x7, 0x45, 0x2, 0x2, 0x145, 0x14c, 0x7, 0x44, 
       0x2, 0x2, 0x146, 0x14c, 0x7, 0x46, 0x2, 0x2, 0x147, 0x14c, 0x7, 0x49, 
       0x2, 0x2, 0x148, 0x14c, 0x7, 0x4a, 0x2, 0x2, 0x149, 0x14c, 0x5, 0x8, 
       0x5, 0x2, 0x14a, 0x14c, 0x5, 0xa, 0x6, 0x2, 0x14b, 0x13e, 0x3, 0x2, 
       0x2, 0x2, 0x14b, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x140, 0x3, 0x2, 
       0x2, 0x2, 0x14b, 0x141, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x142, 0x3, 0x2, 
       0x2, 0x2, 0x14b, 0x143, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x144, 0x3, 0x2, 
       0x2, 0x2, 0x14b, 0x145, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x146, 0x3, 0x2, 
       0x2, 0x2, 0x14b, 0x147, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x148, 0x3, 0x2, 
       0x2, 0x2, 0x14b, 0x149, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x14a, 0x3, 0x2, 
       0x2, 0x2, 0x14c, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x154, 0x5, 0x30, 
       0x19, 0x2, 0x14e, 0x154, 0x5, 0x32, 0x1a, 0x2, 0x14f, 0x154, 0x5, 
       0x34, 0x1b, 0x2, 0x150, 0x154, 0x5, 0x36, 0x1c, 0x2, 0x151, 0x154, 
       0x5, 0x38, 0x1d, 0x2, 0x152, 0x154, 0x5, 0x3a, 0x1e, 0x2, 0x153, 
       0x14d, 0x3, 0x2, 0x2, 0x2, 0x153, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x153, 
       0x14f, 0x3, 0x2, 0x2, 0x2, 0x153, 0x150, 0x3, 0x2, 0x2, 0x2, 0x153, 
       0x151, 0x3, 0x2, 0x2, 0x2, 0x153, 0x152, 0x3, 0x2, 0x2, 0x2, 0x154, 
       0x41, 0x3, 0x2, 0x2, 0x2, 0x155, 0x158, 0x7, 0x47, 0x2, 0x2, 0x156, 
       0x158, 0x5, 0x40, 0x21, 0x2, 0x157, 0x155, 0x3, 0x2, 0x2, 0x2, 0x157, 
       0x156, 0x3, 0x2, 0x2, 0x2, 0x158, 0x43, 0x3, 0x2, 0x2, 0x2, 0x159, 
       0x15c, 0x5, 0x3e, 0x20, 0x2, 0x15a, 0x15c, 0x5, 0x42, 0x22, 0x2, 
       0x15b, 0x159, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x15a, 0x3, 0x2, 0x2, 0x2, 
       0x15c, 0x45, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15f, 0x7, 0x40, 0x2, 0x2, 
       0x15e, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15f, 0x3, 0x2, 0x2, 0x2, 
       0x15f, 0x160, 0x3, 0x2, 0x2, 0x2, 0x160, 0x161, 0x7, 0x53, 0x2, 0x2, 
       0x161, 0x47, 0x3, 0x2, 0x2, 0x2, 0x162, 0x164, 0x7, 0x40, 0x2, 0x2, 
       0x163, 0x162, 0x3, 0x2, 0x2, 0x2, 0x163, 0x164, 0x3, 0x2, 0x2, 0x2, 
       0x164, 0x165, 0x3, 0x2, 0x2, 0x2, 0x165, 0x166, 0x7, 0x54, 0x2, 0x2, 
       0x166, 0x49, 0x3, 0x2, 0x2, 0x2, 0x167, 0x16c, 0x7, 0x52, 0x2, 0x2, 
       0x168, 0x16c, 0x5, 0x46, 0x24, 0x2, 0x169, 0x16c, 0x5, 0x48, 0x25, 
       0x2, 0x16a, 0x16c, 0x7, 0x55, 0x2, 0x2, 0x16b, 0x167, 0x3, 0x2, 0x2, 
       0x2, 0x16b, 0x168, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x169, 0x3, 0x2, 0x2, 
       0x2, 0x16b, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x4b, 0x3, 0x2, 0x2, 
       0x2, 0x16d, 0x16e, 0x9, 0x4, 0x2, 0x2, 0x16e, 0x4d, 0x3, 0x2, 0x2, 
       0x2, 0x16f, 0x174, 0x5, 0x4c, 0x27, 0x2, 0x170, 0x171, 0x7, 0x3e, 
       0x2, 0x2, 0x171, 0x173, 0x5, 0x4c, 0x27, 0x2, 0x172, 0x170, 0x3, 
       0x2, 0x2, 0x2, 0x173, 0x176, 0x3, 0x2, 0x2, 0x2, 0x174, 0x172, 0x3, 
       0x2, 0x2, 0x2, 0x174, 0x175, 0x3, 0x2, 0x2, 0x2, 0x175, 0x4f, 0x3, 
       0x2, 0x2, 0x2, 0x176, 0x174, 0x3, 0x2, 0x2, 0x2, 0x177, 0x178, 0x5, 
       0x4e, 0x28, 0x2, 0x178, 0x179, 0x5, 0x24, 0x13, 0x2, 0x179, 0x17e, 
       0x5, 0x58, 0x2d, 0x2, 0x17a, 0x17b, 0x7, 0x4c, 0x2, 0x2, 0x17b, 0x17d, 
       0x5, 0x58, 0x2d, 0x2, 0x17c, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x180, 
       0x3, 0x2, 0x2, 0x2, 0x17e, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x17f, 
       0x3, 0x2, 0x2, 0x2, 0x17f, 0x181, 0x3, 0x2, 0x2, 0x2, 0x180, 0x17e, 
       0x3, 0x2, 0x2, 0x2, 0x181, 0x182, 0x5, 0x26, 0x14, 0x2, 0x182, 0x183, 
       0x7, 0x3e, 0x2, 0x2, 0x183, 0x184, 0x5, 0x4c, 0x27, 0x2, 0x184, 0x51, 
       0x3, 0x2, 0x2, 0x2, 0x185, 0x186, 0x5, 0x20, 0x11, 0x2, 0x186, 0x187, 
       0x5, 0x22, 0x12, 0x2, 0x187, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x188, 0x18a, 
       0x7, 0x4b, 0x2, 0x2, 0x189, 0x185, 0x3, 0x2, 0x2, 0x2, 0x189, 0x188, 
       0x3, 0x2, 0x2, 0x2, 0x18a, 0x53, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x197, 
       0x5, 0x4e, 0x28, 0x2, 0x18c, 0x18d, 0x5, 0x24, 0x13, 0x2, 0x18d, 
       0x192, 0x5, 0x5a, 0x2e, 0x2, 0x18e, 0x18f, 0x7, 0x4c, 0x2, 0x2, 0x18f, 
       0x191, 0x5, 0x5a, 0x2e, 0x2, 0x190, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x191, 
       0x194, 0x3, 0x2, 0x2, 0x2, 0x192, 0x190, 0x3, 0x2, 0x2, 0x2, 0x192, 
       0x193, 0x3, 0x2, 0x2, 0x2, 0x193, 0x195, 0x3, 0x2, 0x2, 0x2, 0x194, 
       0x192, 0x3, 0x2, 0x2, 0x2, 0x195, 0x196, 0x5, 0x26, 0x14, 0x2, 0x196, 
       0x198, 0x3, 0x2, 0x2, 0x2, 0x197, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x197, 
       0x198, 0x3, 0x2, 0x2, 0x2, 0x198, 0x55, 0x3, 0x2, 0x2, 0x2, 0x199, 
       0x19a, 0x5, 0x2c, 0x17, 0x2, 0x19a, 0x19d, 0x5, 0x5c, 0x2f, 0x2, 
       0x19b, 0x19c, 0x7, 0x4c, 0x2, 0x2, 0x19c, 0x19e, 0x5, 0x5c, 0x2f, 
       0x2, 0x19d, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x19f, 0x3, 0x2, 0x2, 
       0x2, 0x19f, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a0, 0x3, 0x2, 0x2, 
       0x2, 0x1a0, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x1a2, 0x5, 0x2e, 0x18, 
       0x2, 0x1a2, 0x57, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a6, 0x5, 0x54, 0x2b, 
       0x2, 0x1a4, 0x1a6, 0x5, 0x56, 0x2c, 0x2, 0x1a5, 0x1a3, 0x3, 0x2, 
       0x2, 0x2, 0x1a5, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1aa, 0x3, 0x2, 
       0x2, 0x2, 0x1a7, 0x1a9, 0x5, 0x52, 0x2a, 0x2, 0x1a8, 0x1a7, 0x3, 
       0x2, 0x2, 0x2, 0x1a9, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1a8, 0x3, 
       0x2, 0x2, 0x2, 0x1aa, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1ab, 0x59, 0x3, 
       0x2, 0x2, 0x2, 0x1ac, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1af, 0x9, 
       0x5, 0x2, 0x2, 0x1ae, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1af, 0x3, 
       0x2, 0x2, 0x2, 0x1af, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1b1, 0x5, 
       0x58, 0x2d, 0x2, 0x1b1, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b4, 0x5, 
       0x58, 0x2d, 0x2, 0x1b3, 0x1b5, 0x5, 0x4c, 0x27, 0x2, 0x1b4, 0x1b3, 
       0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x5d, 
       0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1bb, 0x5, 0x5c, 0x2f, 0x2, 0x1b7, 0x1b8, 
       0x7, 0x4c, 0x2, 0x2, 0x1b8, 0x1ba, 0x5, 0x5c, 0x2f, 0x2, 0x1b9, 0x1b7, 
       0x3, 0x2, 0x2, 0x2, 0x1ba, 0x1bd, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1b9, 
       0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1bc, 0x5f, 
       0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x1be, 0x1c0, 
       0x5, 0x5a, 0x2e, 0x2, 0x1bf, 0x1c1, 0x5, 0x4c, 0x27, 0x2, 0x1c0, 
       0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1c0, 0x1c1, 0x3, 0x2, 0x2, 0x2, 0x1c1, 
       0x61, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c7, 0x5, 0x60, 0x31, 0x2, 0x1c3, 
       0x1c4, 0x7, 0x4c, 0x2, 0x2, 0x1c4, 0x1c6, 0x5, 0x60, 0x31, 0x2, 0x1c5, 
       0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1c7, 
       0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1c8, 0x3, 0x2, 0x2, 0x2, 0x1c8, 
       0x63, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1ca, 
       0x1cc, 0x5, 0x5a, 0x2e, 0x2, 0x1cb, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x1cb, 
       0x1cc, 0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1cd, 
       0x1ce, 0x5, 0x4c, 0x27, 0x2, 0x1ce, 0x65, 0x3, 0x2, 0x2, 0x2, 0x1cf, 
       0x1d4, 0x5, 0x64, 0x33, 0x2, 0x1d0, 0x1d1, 0x7, 0x4c, 0x2, 0x2, 0x1d1, 
       0x1d3, 0x5, 0x64, 0x33, 0x2, 0x1d2, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x1d3, 
       0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d2, 0x3, 0x2, 0x2, 0x2, 0x1d4, 
       0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d5, 0x67, 0x3, 0x2, 0x2, 0x2, 0x1d6, 
       0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1db, 0x5, 0x28, 0x15, 0x2, 0x1d8, 
       0x1da, 0x5, 0xb2, 0x5a, 0x2, 0x1d9, 0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1da, 
       0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1db, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1db, 
       0x1dc, 0x3, 0x2, 0x2, 0x2, 0x1dc, 0x1de, 0x3, 0x2, 0x2, 0x2, 0x1dd, 
       0x1db, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x1df, 0x5, 0x2a, 0x16, 0x2, 0x1df, 
       0x69, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1e4, 0x5, 0x28, 0x15, 0x2, 0x1e1, 
       0x1e3, 0x5, 0xb2, 0x5a, 0x2, 0x1e2, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0x1e3, 
       0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e4, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1e4, 
       0x1e5, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1e6, 
       0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1e8, 0x5, 0xa8, 0x55, 0x2, 0x1e8, 
       0x1e9, 0x5, 0x2a, 0x16, 0x2, 0x1e9, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x1ea, 
       0x1eb, 0x7, 0x19, 0x2, 0x2, 0x1eb, 0x1ec, 0x5, 0xa8, 0x55, 0x2, 0x1ec, 
       0x1f4, 0x5, 0x68, 0x35, 0x2, 0x1ed, 0x1ee, 0x7, 0x15, 0x2, 0x2, 0x1ee, 
       0x1ef, 0x7, 0x19, 0x2, 0x2, 0x1ef, 0x1f0, 0x5, 0xa8, 0x55, 0x2, 0x1f0, 
       0x1f1, 0x5, 0x68, 0x35, 0x2, 0x1f1, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x1f2, 
       0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1f4, 
       0x1f2, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f5, 
       0x1f9, 0x3, 0x2, 0x2, 0x2, 0x1f6, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1f7, 
       0x1f8, 0x7, 0x15, 0x2, 0x2, 0x1f8, 0x1fa, 0x5, 0x68, 0x35, 0x2, 0x1f9, 
       0x1f7, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1fa, 
       0x6d, 0x3, 0x2, 0x2, 0x2, 0x1fb, 0x1fc, 0x7, 0x19, 0x2, 0x2, 0x1fc, 
       0x1fd, 0x5, 0xa8, 0x55, 0x2, 0x1fd, 0x205, 0x5, 0x6a, 0x36, 0x2, 
       0x1fe, 0x1ff, 0x7, 0x15, 0x2, 0x2, 0x1ff, 0x200, 0x7, 0x19, 0x2, 
       0x2, 0x200, 0x201, 0x5, 0xa8, 0x55, 0x2, 0x201, 0x202, 0x5, 0x6a, 
       0x36, 0x2, 0x202, 0x204, 0x3, 0x2, 0x2, 0x2, 0x203, 0x1fe, 0x3, 0x2, 
       0x2, 0x2, 0x204, 0x207, 0x3, 0x2, 0x2, 0x2, 0x205, 0x203, 0x3, 0x2, 
       0x2, 0x2, 0x205, 0x206, 0x3, 0x2, 0x2, 0x2, 0x206, 0x208, 0x3, 0x2, 
       0x2, 0x2, 0x207, 0x205, 0x3, 0x2, 0x2, 0x2, 0x208, 0x209, 0x7, 0x15, 
       0x2, 0x2, 0x209, 0x20a, 0x5, 0x6a, 0x36, 0x2, 0x20a, 0x6f, 0x3, 0x2, 
       0x2, 0x2, 0x20b, 0x20c, 0x7, 0x2b, 0x2, 0x2, 0x20c, 0x20d, 0x5, 0xa8, 
       0x55, 0x2, 0x20d, 0x211, 0x5, 0x28, 0x15, 0x2, 0x20e, 0x210, 0x5, 
       0xb2, 0x5a, 0x2, 0x20f, 0x20e, 0x3, 0x2, 0x2, 0x2, 0x210, 0x213, 
       0x3, 0x2, 0x2, 0x2, 0x211, 0x20f, 0x3, 0x2, 0x2, 0x2, 0x211, 0x212, 
       0x3, 0x2, 0x2, 0x2, 0x212, 0x214, 0x3, 0x2, 0x2, 0x2, 0x213, 0x211, 
       0x3, 0x2, 0x2, 0x2, 0x214, 0x215, 0x5, 0x2a, 0x16, 0x2, 0x215, 0x71, 
       0x3, 0x2, 0x2, 0x2, 0x216, 0x217, 0x7, 0x14, 0x2, 0x2, 0x217, 0x21b, 
       0x5, 0x28, 0x15, 0x2, 0x218, 0x21a, 0x5, 0xb2, 0x5a, 0x2, 0x219, 
       0x218, 0x3, 0x2, 0x2, 0x2, 0x21a, 0x21d, 0x3, 0x2, 0x2, 0x2, 0x21b, 
       0x219, 0x3, 0x2, 0x2, 0x2, 0x21b, 0x21c, 0x3, 0x2, 0x2, 0x2, 0x21c, 
       0x21e, 0x3, 0x2, 0x2, 0x2, 0x21d, 0x21b, 0x3, 0x2, 0x2, 0x2, 0x21e, 
       0x21f, 0x5, 0x2a, 0x16, 0x2, 0x21f, 0x220, 0x7, 0x2b, 0x2, 0x2, 0x220, 
       0x221, 0x5, 0xa8, 0x55, 0x2, 0x221, 0x73, 0x3, 0x2, 0x2, 0x2, 0x222, 
       0x223, 0x7, 0x18, 0x2, 0x2, 0x223, 0x224, 0x5, 0xb2, 0x5a, 0x2, 0x224, 
       0x225, 0x5, 0xa8, 0x55, 0x2, 0x225, 0x22e, 0x7, 0x50, 0x2, 0x2, 0x226, 
       0x22b, 0x5, 0xa8, 0x55, 0x2, 0x227, 0x228, 0x7, 0x4c, 0x2, 0x2, 0x228, 
       0x22a, 0x5, 0xa8, 0x55, 0x2, 0x229, 0x227, 0x3, 0x2, 0x2, 0x2, 0x22a, 
       0x22d, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x229, 0x3, 0x2, 0x2, 0x2, 0x22b, 
       0x22c, 0x3, 0x2, 0x2, 0x2, 0x22c, 0x22f, 0x3, 0x2, 0x2, 0x2, 0x22d, 
       0x22b, 0x3, 0x2, 0x2, 0x2, 0x22e, 0x226, 0x3, 0x2, 0x2, 0x2, 0x22e, 
       0x22f, 0x3, 0x2, 0x2, 0x2, 0x22f, 0x230, 0x3, 0x2, 0x2, 0x2, 0x230, 
       0x234, 0x5, 0x28, 0x15, 0x2, 0x231, 0x233, 0x5, 0xb2, 0x5a, 0x2, 
       0x232, 0x231, 0x3, 0x2, 0x2, 0x2, 0x233, 0x236, 0x3, 0x2, 0x2, 0x2, 
       0x234, 0x232, 0x3, 0x2, 0x2, 0x2, 0x234, 0x235, 0x3, 0x2, 0x2, 0x2, 
       0x235, 0x237, 0x3, 0x2, 0x2, 0x2, 0x236, 0x234, 0x3, 0x2, 0x2, 0x2, 
       0x237, 0x238, 0x5, 0x2a, 0x16, 0x2, 0x238, 0x75, 0x3, 0x2, 0x2, 0x2, 
       0x239, 0x23a, 0x7, 0x18, 0x2, 0x2, 0x23a, 0x23b, 0x5, 0x58, 0x2d, 
       0x2, 0x23b, 0x23c, 0x5, 0x4c, 0x27, 0x2, 0x23c, 0x23d, 0x7, 0x4e, 
       0x2, 0x2, 0x23d, 0x23e, 0x5, 0xa8, 0x55, 0x2, 0x23e, 0x242, 0x5, 
       0x28, 0x15, 0x2, 0x23f, 0x241, 0x5, 0xb2, 0x5a, 0x2, 0x240, 0x23f, 
       0x3, 0x2, 0x2, 0x2, 0x241, 0x244, 0x3, 0x2, 0x2, 0x2, 0x242, 0x240, 
       0x3, 0x2, 0x2, 0x2, 0x242, 0x243, 0x3, 0x2, 0x2, 0x2, 0x243, 0x245, 
       0x3, 0x2, 0x2, 0x2, 0x244, 0x242, 0x3, 0x2, 0x2, 0x2, 0x245, 0x246, 
       0x5, 0x2a, 0x16, 0x2, 0x246, 0x77, 0x3, 0x2, 0x2, 0x2, 0x247, 0x248, 
       0x7, 0x51, 0x2, 0x2, 0x248, 0x249, 0x5, 0x3c, 0x1f, 0x2, 0x249, 0x24a, 
       0x5, 0xb2, 0x5a, 0x2, 0x24a, 0x79, 0x3, 0x2, 0x2, 0x2, 0x24b, 0x24e, 
       0x5, 0x6a, 0x36, 0x2, 0x24c, 0x24e, 0x5, 0xa8, 0x55, 0x2, 0x24d, 
       0x24b, 0x3, 0x2, 0x2, 0x2, 0x24d, 0x24c, 0x3, 0x2, 0x2, 0x2, 0x24e, 
       0x7b, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x250, 0x7, 0x51, 0x2, 0x2, 0x250, 
       0x251, 0x5, 0x3c, 0x1f, 0x2, 0x251, 0x252, 0x5, 0x7a, 0x3e, 0x2, 
       0x252, 0x253, 0x7, 0x4c, 0x2, 0x2, 0x253, 0x7d, 0x3, 0x2, 0x2, 0x2, 
       0x254, 0x257, 0x5, 0xa8, 0x55, 0x2, 0x255, 0x256, 0x7, 0x2a, 0x2, 
       0x2, 0x256, 0x258, 0x5, 0xa8, 0x55, 0x2, 0x257, 0x255, 0x3, 0x2, 
       0x2, 0x2, 0x257, 0x258, 0x3, 0x2, 0x2, 0x2, 0x258, 0x259, 0x3, 0x2, 
       0x2, 0x2, 0x259, 0x25a, 0x5, 0x3c, 0x1f, 0x2, 0x25a, 0x25b, 0x5, 
       0xb2, 0x5a, 0x2, 0x25b, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x25c, 0x25d, 0x7, 
       0x27, 0x2, 0x2, 0x25d, 0x25e, 0x5, 0xa8, 0x55, 0x2, 0x25e, 0x262, 
       0x5, 0x28, 0x15, 0x2, 0x25f, 0x261, 0x5, 0x7e, 0x40, 0x2, 0x260, 
       0x25f, 0x3, 0x2, 0x2, 0x2, 0x261, 0x264, 0x3, 0x2, 0x2, 0x2, 0x262, 
       0x260, 0x3, 0x2, 0x2, 0x2, 0x262, 0x263, 0x3, 0x2, 0x2, 0x2, 0x263, 
       0x265, 0x3, 0x2, 0x2, 0x2, 0x264, 0x262, 0x3, 0x2, 0x2, 0x2, 0x265, 
       0x266, 0x5, 0x2a, 0x16, 0x2, 0x266, 0x81, 0x3, 0x2, 0x2, 0x2, 0x267, 
       0x268, 0x7, 0x2a, 0x2, 0x2, 0x268, 0x269, 0x5, 0xa8, 0x55, 0x2, 0x269, 
       0x26a, 0x5, 0x3c, 0x1f, 0x2, 0x26a, 0x26b, 0x5, 0xb2, 0x5a, 0x2, 
       0x26b, 0x83, 0x3, 0x2, 0x2, 0x2, 0x26c, 0x26d, 0x7, 0x27, 0x2, 0x2, 
       0x26d, 0x271, 0x5, 0x28, 0x15, 0x2, 0x26e, 0x270, 0x5, 0x82, 0x42, 
       0x2, 0x26f, 0x26e, 0x3, 0x2, 0x2, 0x2, 0x270, 0x273, 0x3, 0x2, 0x2, 
       0x2, 0x271, 0x26f, 0x3, 0x2, 0x2, 0x2, 0x271, 0x272, 0x3, 0x2, 0x2, 
       0x2, 0x272, 0x274, 0x3, 0x2, 0x2, 0x2, 0x273, 0x271, 0x3, 0x2, 0x2, 
       0x2, 0x274, 0x275, 0x5, 0x78, 0x3d, 0x2, 0x275, 0x276, 0x5, 0x2a, 
       0x16, 0x2, 0x276, 0x85, 0x3, 0x2, 0x2, 0x2, 0x277, 0x27a, 0x5, 0xa8, 
       0x55, 0x2, 0x278, 0x279, 0x7, 0x2a, 0x2, 0x2, 0x279, 0x27b, 0x5, 
       0xa8, 0x55, 0x2, 0x27a, 0x278, 0x3, 0x2, 0x2, 0x2, 0x27a, 0x27b, 
       0x3, 0x2, 0x2, 0x2, 0x27b, 0x27c, 0x3, 0x2, 0x2, 0x2, 0x27c, 0x27d, 
       0x5, 0x3c, 0x1f, 0x2, 0x27d, 0x27e, 0x5, 0x7a, 0x3e, 0x2, 0x27e, 
       0x27f, 0x7, 0x4c, 0x2, 0x2, 0x27f, 0x87, 0x3, 0x2, 0x2, 0x2, 0x280, 
       0x281, 0x7, 0x27, 0x2, 0x2, 0x281, 0x282, 0x5, 0xa8, 0x55, 0x2, 0x282, 
       0x286, 0x5, 0x28, 0x15, 0x2, 0x283, 0x285, 0x5, 0x86, 0x44, 0x2, 
       0x284, 0x283, 0x3, 0x2, 0x2, 0x2, 0x285, 0x288, 0x3, 0x2, 0x2, 0x2, 
       0x286, 0x284, 0x3, 0x2, 0x2, 0x2, 0x286, 0x287, 0x3, 0x2, 0x2, 0x2, 
       0x287, 0x289, 0x3, 0x2, 0x2, 0x2, 0x288, 0x286, 0x3, 0x2, 0x2, 0x2, 
       0x289, 0x28a, 0x5, 0x7c, 0x3f, 0x2, 0x28a, 0x28b, 0x5, 0x2a, 0x16, 
       0x2, 0x28b, 0x89, 0x3, 0x2, 0x2, 0x2, 0x28c, 0x28d, 0x7, 0x2a, 0x2, 
       0x2, 0x28d, 0x28e, 0x5, 0xa8, 0x55, 0x2, 0x28e, 0x28f, 0x5, 0x3c, 
       0x1f, 0x2, 0x28f, 0x290, 0x5, 0x7a, 0x3e, 0x2, 0x290, 0x291, 0x7, 
       0x4c, 0x2, 0x2, 0x291, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x292, 0x293, 0x7, 
       0x27, 0x2, 0x2, 0x293, 0x297, 0x5, 0x28, 0x15, 0x2, 0x294, 0x296, 
       0x5, 0x8a, 0x46, 0x2, 0x295, 0x294, 0x3, 0x2, 0x2, 0x2, 0x296, 0x299, 
       0x3, 0x2, 0x2, 0x2, 0x297, 0x295, 0x3, 0x2, 0x2, 0x2, 0x297, 0x298, 
       0x3, 0x2, 0x2, 0x2, 0x298, 0x29a, 0x3, 0x2, 0x2, 0x2, 0x299, 0x297, 
       0x3, 0x2, 0x2, 0x2, 0x29a, 0x29b, 0x5, 0x7c, 0x3f, 0x2, 0x29b, 0x29c, 
       0x5, 0x2a, 0x16, 0x2, 0x29c, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x29d, 0x29e, 
       0x5, 0x2c, 0x17, 0x2, 0x29e, 0x29f, 0x5, 0xa8, 0x55, 0x2, 0x29f, 
       0x2a0, 0x5, 0x2e, 0x18, 0x2, 0x2a0, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x2a1, 
       0x2a3, 0x5, 0xa8, 0x55, 0x2, 0x2a2, 0x2a1, 0x3, 0x2, 0x2, 0x2, 0x2a2, 
       0x2a3, 0x3, 0x2, 0x2, 0x2, 0x2a3, 0x91, 0x3, 0x2, 0x2, 0x2, 0x2a4, 
       0x2a7, 0x5, 0x4c, 0x27, 0x2, 0x2a5, 0x2a6, 0x7, 0x2c, 0x2, 0x2, 0x2a6, 
       0x2a8, 0x5, 0xa6, 0x54, 0x2, 0x2a7, 0x2a5, 0x3, 0x2, 0x2, 0x2, 0x2a7, 
       0x2a8, 0x3, 0x2, 0x2, 0x2, 0x2a8, 0x93, 0x3, 0x2, 0x2, 0x2, 0x2a9, 
       0x2aa, 0x7, 0x1e, 0x2, 0x2, 0x2aa, 0x2ab, 0x5, 0x54, 0x2b, 0x2, 0x2ab, 
       0x2b4, 0x5, 0x28, 0x15, 0x2, 0x2ac, 0x2b1, 0x5, 0x92, 0x4a, 0x2, 
       0x2ad, 0x2ae, 0x7, 0x4c, 0x2, 0x2, 0x2ae, 0x2b0, 0x5, 0x92, 0x4a, 
       0x2, 0x2af, 0x2ad, 0x3, 0x2, 0x2, 0x2, 0x2b0, 0x2b3, 0x3, 0x2, 0x2, 
       0x2, 0x2b1, 0x2af, 0x3, 0x2, 0x2, 0x2, 0x2b1, 0x2b2, 0x3, 0x2, 0x2, 
       0x2, 0x2b2, 0x2b5, 0x3, 0x2, 0x2, 0x2, 0x2b3, 0x2b1, 0x3, 0x2, 0x2, 
       0x2, 0x2b4, 0x2ac, 0x3, 0x2, 0x2, 0x2, 0x2b4, 0x2b5, 0x3, 0x2, 0x2, 
       0x2, 0x2b5, 0x2b6, 0x3, 0x2, 0x2, 0x2, 0x2b6, 0x2b7, 0x5, 0x2a, 0x16, 
       0x2, 0x2b7, 0x95, 0x3, 0x2, 0x2, 0x2, 0x2b8, 0x2b9, 0x7, 0x1e, 0x2, 
       0x2, 0x2b9, 0x2ba, 0x5, 0x54, 0x2b, 0x2, 0x2ba, 0x2c3, 0x5, 0x2c, 
       0x17, 0x2, 0x2bb, 0x2c0, 0x5, 0xa8, 0x55, 0x2, 0x2bc, 0x2bd, 0x7, 
       0x4c, 0x2, 0x2, 0x2bd, 0x2bf, 0x5, 0xa8, 0x55, 0x2, 0x2be, 0x2bc, 
       0x3, 0x2, 0x2, 0x2, 0x2bf, 0x2c2, 0x3, 0x2, 0x2, 0x2, 0x2c0, 0x2be, 
       0x3, 0x2, 0x2, 0x2, 0x2c0, 0x2c1, 0x3, 0x2, 0x2, 0x2, 0x2c1, 0x2c4, 
       0x3, 0x2, 0x2, 0x2, 0x2c2, 0x2c0, 0x3, 0x2, 0x2, 0x2, 0x2c3, 0x2bb, 
       0x3, 0x2, 0x2, 0x2, 0x2c3, 0x2c4, 0x3, 0x2, 0x2, 0x2, 0x2c4, 0x2c5, 
       0x3, 0x2, 0x2, 0x2, 0x2c5, 0x2c6, 0x5, 0x2e, 0x18, 0x2, 0x2c6, 0x97, 
       0x3, 0x2, 0x2, 0x2, 0x2c7, 0x2c8, 0x5, 0x20, 0x11, 0x2, 0x2c8, 0x2c9, 
       0x5, 0xa8, 0x55, 0x2, 0x2c9, 0x2ca, 0x7, 0x3d, 0x2, 0x2, 0x2ca, 0x2cd, 
       0x5, 0xa8, 0x55, 0x2, 0x2cb, 0x2cc, 0x7, 0x26, 0x2, 0x2, 0x2cc, 0x2ce, 
       0x5, 0xa8, 0x55, 0x2, 0x2cd, 0x2cb, 0x3, 0x2, 0x2, 0x2, 0x2cd, 0x2ce, 
       0x3, 0x2, 0x2, 0x2, 0x2ce, 0x2cf, 0x3, 0x2, 0x2, 0x2, 0x2cf, 0x2d0, 
       0x5, 0x22, 0x12, 0x2, 0x2d0, 0x99, 0x3, 0x2, 0x2, 0x2, 0x2d1, 0x2d2, 
       0x5, 0x20, 0x11, 0x2, 0x2d2, 0x2d7, 0x5, 0xa8, 0x55, 0x2, 0x2d3, 
       0x2d4, 0x7, 0x4c, 0x2, 0x2, 0x2d4, 0x2d6, 0x5, 0xa8, 0x55, 0x2, 0x2d5, 
       0x2d3, 0x3, 0x2, 0x2, 0x2, 0x2d6, 0x2d9, 0x3, 0x2, 0x2, 0x2, 0x2d7, 
       0x2d5, 0x3, 0x2, 0x2, 0x2, 0x2d7, 0x2d8, 0x3, 0x2, 0x2, 0x2, 0x2d8, 
       0x2da, 0x3, 0x2, 0x2, 0x2, 0x2d9, 0x2d7, 0x3, 0x2, 0x2, 0x2, 0x2da, 
       0x2db, 0x5, 0x22, 0x12, 0x2, 0x2db, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x2dc, 
       0x2de, 0x5, 0x2c, 0x17, 0x2, 0x2dd, 0x2df, 0x5, 0x66, 0x34, 0x2, 
       0x2de, 0x2dd, 0x3, 0x2, 0x2, 0x2, 0x2de, 0x2df, 0x3, 0x2, 0x2, 0x2, 
       0x2df, 0x2e0, 0x3, 0x2, 0x2, 0x2, 0x2e0, 0x2e1, 0x5, 0x2e, 0x18, 
       0x2, 0x2e1, 0x2ec, 0x5, 0x3c, 0x1f, 0x2, 0x2e2, 0x2ed, 0x5, 0xa8, 
       0x55, 0x2, 0x2e3, 0x2e7, 0x5, 0x28, 0x15, 0x2, 0x2e4, 0x2e6, 0x5, 
       0xb2, 0x5a, 0x2, 0x2e5, 0x2e4, 0x3, 0x2, 0x2, 0x2, 0x2e6, 0x2e9, 
       0x3, 0x2, 0x2, 0x2, 0x2e7, 0x2e5, 0x3, 0x2, 0x2, 0x2, 0x2e7, 0x2e8, 
       0x3, 0x2, 0x2, 0x2, 0x2e8, 0x2ea, 0x3, 0x2, 0x2, 0x2, 0x2e9, 0x2e7, 
       0x3, 0x2, 0x2, 0x2, 0x2ea, 0x2eb, 0x5, 0x2a, 0x16, 0x2, 0x2eb, 0x2ed, 
       0x3, 0x2, 0x2, 0x2, 0x2ec, 0x2e2, 0x3, 0x2, 0x2, 0x2, 0x2ec, 0x2e3, 
       0x3, 0x2, 0x2, 0x2, 0x2ed, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x2ee, 0x2f0, 
       0x7, 0x4d, 0x2, 0x2, 0x2ef, 0x2ee, 0x3, 0x2, 0x2, 0x2, 0x2ef, 0x2f0, 
       0x3, 0x2, 0x2, 0x2, 0x2f0, 0x2f1, 0x3, 0x2, 0x2, 0x2, 0x2f1, 0x2fe, 
       0x5, 0x4c, 0x27, 0x2, 0x2f2, 0x2fe, 0x5, 0x4a, 0x26, 0x2, 0x2f3, 
       0x2fe, 0x5, 0x6e, 0x38, 0x2, 0x2f4, 0x2fe, 0x5, 0x8e, 0x48, 0x2, 
       0x2f5, 0x2fe, 0x5, 0x94, 0x4b, 0x2, 0x2f6, 0x2fe, 0x5, 0x96, 0x4c, 
       0x2, 0x2f7, 0x2fe, 0x5, 0x98, 0x4d, 0x2, 0x2f8, 0x2fe, 0x5, 0x9a, 
       0x4e, 0x2, 0x2f9, 0x2fe, 0x5, 0x8c, 0x47, 0x2, 0x2fa, 0x2fe, 0x5, 
       0x88, 0x45, 0x2, 0x2fb, 0x2fe, 0x5, 0x9c, 0x4f, 0x2, 0x2fc, 0x2fe, 
       0x5, 0x50, 0x29, 0x2, 0x2fd, 0x2ef, 0x3, 0x2, 0x2, 0x2, 0x2fd, 0x2f2, 
       0x3, 0x2, 0x2, 0x2, 0x2fd, 0x2f3, 0x3, 0x2, 0x2, 0x2, 0x2fd, 0x2f4, 
       0x3, 0x2, 0x2, 0x2, 0x2fd, 0x2f5, 0x3, 0x2, 0x2, 0x2, 0x2fd, 0x2f6, 
       0x3, 0x2, 0x2, 0x2, 0x2fd, 0x2f7, 0x3, 0x2, 0x2, 0x2, 0x2fd, 0x2f8, 
       0x3, 0x2, 0x2, 0x2, 0x2fd, 0x2f9, 0x3, 0x2, 0x2, 0x2, 0x2fd, 0x2fa, 
       0x3, 0x2, 0x2, 0x2, 0x2fd, 0x2fb, 0x3, 0x2, 0x2, 0x2, 0x2fd, 0x2fc, 
       0x3, 0x2, 0x2, 0x2, 0x2fe, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x2ff, 0x300, 
       0x9, 0x6, 0x2, 0x2, 0x300, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x301, 0x326, 
       0x7, 0x3a, 0x2, 0x2, 0x302, 0x326, 0x7, 0x3b, 0x2, 0x2, 0x303, 0x30c, 
       0x5, 0x2c, 0x17, 0x2, 0x304, 0x309, 0x5, 0xa8, 0x55, 0x2, 0x305, 
       0x306, 0x7, 0x4c, 0x2, 0x2, 0x306, 0x308, 0x5, 0xa8, 0x55, 0x2, 0x307, 
       0x305, 0x3, 0x2, 0x2, 0x2, 0x308, 0x30b, 0x3, 0x2, 0x2, 0x2, 0x309, 
       0x307, 0x3, 0x2, 0x2, 0x2, 0x309, 0x30a, 0x3, 0x2, 0x2, 0x2, 0x30a, 
       0x30d, 0x3, 0x2, 0x2, 0x2, 0x30b, 0x309, 0x3, 0x2, 0x2, 0x2, 0x30c, 
       0x304, 0x3, 0x2, 0x2, 0x2, 0x30c, 0x30d, 0x3, 0x2, 0x2, 0x2, 0x30d, 
       0x30e, 0x3, 0x2, 0x2, 0x2, 0x30e, 0x30f, 0x5, 0x2e, 0x18, 0x2, 0x30f, 
       0x326, 0x3, 0x2, 0x2, 0x2, 0x310, 0x311, 0x5, 0x20, 0x11, 0x2, 0x311, 
       0x316, 0x5, 0x90, 0x49, 0x2, 0x312, 0x313, 0x7, 0x4e, 0x2, 0x2, 0x313, 
       0x315, 0x5, 0x90, 0x49, 0x2, 0x314, 0x312, 0x3, 0x2, 0x2, 0x2, 0x315, 
       0x318, 0x3, 0x2, 0x2, 0x2, 0x316, 0x314, 0x3, 0x2, 0x2, 0x2, 0x316, 
       0x317, 0x3, 0x2, 0x2, 0x2, 0x317, 0x319, 0x3, 0x2, 0x2, 0x2, 0x318, 
       0x316, 0x3, 0x2, 0x2, 0x2, 0x319, 0x31a, 0x5, 0x22, 0x12, 0x2, 0x31a, 
       0x326, 0x3, 0x2, 0x2, 0x2, 0x31b, 0x31c, 0x7, 0x3e, 0x2, 0x2, 0x31c, 
       0x326, 0x5, 0x4c, 0x27, 0x2, 0x31d, 0x31e, 0x7, 0x1a, 0x2, 0x2, 0x31e, 
       0x323, 0x5, 0x4e, 0x28, 0x2, 0x31f, 0x320, 0x5, 0x2c, 0x17, 0x2, 
       0x320, 0x321, 0x5, 0x4c, 0x27, 0x2, 0x321, 0x322, 0x5, 0x2e, 0x18, 
       0x2, 0x322, 0x324, 0x3, 0x2, 0x2, 0x2, 0x323, 0x31f, 0x3, 0x2, 0x2, 
       0x2, 0x323, 0x324, 0x3, 0x2, 0x2, 0x2, 0x324, 0x326, 0x3, 0x2, 0x2, 
       0x2, 0x325, 0x301, 0x3, 0x2, 0x2, 0x2, 0x325, 0x302, 0x3, 0x2, 0x2, 
       0x2, 0x325, 0x303, 0x3, 0x2, 0x2, 0x2, 0x325, 0x310, 0x3, 0x2, 0x2, 
       0x2, 0x325, 0x31b, 0x3, 0x2, 0x2, 0x2, 0x325, 0x31d, 0x3, 0x2, 0x2, 
       0x2, 0x326, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x327, 0x329, 0x5, 0xa0, 0x51, 
       0x2, 0x328, 0x327, 0x3, 0x2, 0x2, 0x2, 0x329, 0x32c, 0x3, 0x2, 0x2, 
       0x2, 0x32a, 0x328, 0x3, 0x2, 0x2, 0x2, 0x32a, 0x32b, 0x3, 0x2, 0x2, 
       0x2, 0x32b, 0x32d, 0x3, 0x2, 0x2, 0x2, 0x32c, 0x32a, 0x3, 0x2, 0x2, 
       0x2, 0x32d, 0x331, 0x5, 0x9e, 0x50, 0x2, 0x32e, 0x330, 0x5, 0xa2, 
       0x52, 0x2, 0x32f, 0x32e, 0x3, 0x2, 0x2, 0x2, 0x330, 0x333, 0x3, 0x2, 
       0x2, 0x2, 0x331, 0x32f, 0x3, 0x2, 0x2, 0x2, 0x331, 0x332, 0x3, 0x2, 
       0x2, 0x2, 0x332, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x333, 0x331, 0x3, 0x2, 
       0x2, 0x2, 0x334, 0x33a, 0x5, 0xa4, 0x53, 0x2, 0x335, 0x336, 0x5, 
       0x44, 0x23, 0x2, 0x336, 0x337, 0x5, 0xa4, 0x53, 0x2, 0x337, 0x339, 
       0x3, 0x2, 0x2, 0x2, 0x338, 0x335, 0x3, 0x2, 0x2, 0x2, 0x339, 0x33c, 
       0x3, 0x2, 0x2, 0x2, 0x33a, 0x338, 0x3, 0x2, 0x2, 0x2, 0x33a, 0x33b, 
       0x3, 0x2, 0x2, 0x2, 0x33b, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x33c, 0x33a, 
       0x3, 0x2, 0x2, 0x2, 0x33d, 0x343, 0x5, 0xa6, 0x54, 0x2, 0x33e, 0x33f, 
       0x5, 0x6, 0x4, 0x2, 0x33f, 0x340, 0x5, 0xa6, 0x54, 0x2, 0x340, 0x342, 
       0x3, 0x2, 0x2, 0x2, 0x341, 0x33e, 0x3, 0x2, 0x2, 0x2, 0x342, 0x345, 
       0x3, 0x2, 0x2, 0x2, 0x343, 0x341, 0x3, 0x2, 0x2, 0x2, 0x343, 0x344, 
       0x3, 0x2, 0x2, 0x2, 0x344, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x345, 0x343, 
       0x3, 0x2, 0x2, 0x2, 0x346, 0x347, 0x7, 0x2c, 0x2, 0x2, 0x347, 0x348, 
       0x5, 0xa6, 0x54, 0x2, 0x348, 0x349, 0x5, 0xc, 0x7, 0x2, 0x349, 0xab, 
       0x3, 0x2, 0x2, 0x2, 0x34a, 0x34b, 0x5, 0x4c, 0x27, 0x2, 0x34b, 0x34c, 
       0x7, 0x2c, 0x2, 0x2, 0x34c, 0x34d, 0x5, 0xa8, 0x55, 0x2, 0x34d, 0xad, 
       0x3, 0x2, 0x2, 0x2, 0x34e, 0x34f, 0x5, 0x58, 0x2d, 0x2, 0x34f, 0x354, 
       0x5, 0xac, 0x57, 0x2, 0x350, 0x351, 0x7, 0x4c, 0x2, 0x2, 0x351, 0x353, 
       0x5, 0xac, 0x57, 0x2, 0x352, 0x350, 0x3, 0x2, 0x2, 0x2, 0x353, 0x356, 
       0x3, 0x2, 0x2, 0x2, 0x354, 0x352, 0x3, 0x2, 0x2, 0x2, 0x354, 0x355, 
       0x3, 0x2, 0x2, 0x2, 0x355, 0x357, 0x3, 0x2, 0x2, 0x2, 0x356, 0x354, 
       0x3, 0x2, 0x2, 0x2, 0x357, 0x358, 0x5, 0xc, 0x7, 0x2, 0x358, 0xaf, 
       0x3, 0x2, 0x2, 0x2, 0x359, 0x35b, 0x7, 0x23, 0x2, 0x2, 0x35a, 0x359, 
       0x3, 0x2, 0x2, 0x2, 0x35a, 0x35b, 0x3, 0x2, 0x2, 0x2, 0x35b, 0x35d, 
       0x3, 0x2, 0x2, 0x2, 0x35c, 0x35e, 0x5, 0xa8, 0x55, 0x2, 0x35d, 0x35c, 
       0x3, 0x2, 0x2, 0x2, 0x35d, 0x35e, 0x3, 0x2, 0x2, 0x2, 0x35e, 0x362, 
       0x3, 0x2, 0x2, 0x2, 0x35f, 0x362, 0x7, 0xd, 0x2, 0x2, 0x360, 0x362, 
       0x7, 0x11, 0x2, 0x2, 0x361, 0x35a, 0x3, 0x2, 0x2, 0x2, 0x361, 0x35f, 
       0x3, 0x2, 0x2, 0x2, 0x361, 0x360, 0x3, 0x2, 0x2, 0x2, 0x362, 0x363, 
       0x3, 0x2, 0x2, 0x2, 0x363, 0x364, 0x5, 0xc, 0x7, 0x2, 0x364, 0xb1, 
       0x3, 0x2, 0x2, 0x2, 0x365, 0x370, 0x5, 0x6c, 0x37, 0x2, 0x366, 0x370, 
       0x5, 0x70, 0x39, 0x2, 0x367, 0x370, 0x5, 0x72, 0x3a, 0x2, 0x368, 
       0x370, 0x5, 0x74, 0x3b, 0x2, 0x369, 0x370, 0x5, 0x76, 0x3c, 0x2, 
       0x36a, 0x370, 0x5, 0x68, 0x35, 0x2, 0x36b, 0x370, 0x5, 0x84, 0x43, 
       0x2, 0x36c, 0x370, 0x5, 0x80, 0x41, 0x2, 0x36d, 0x370, 0x5, 0xae, 
       0x58, 0x2, 0x36e, 0x370, 0x5, 0xb0, 0x59, 0x2, 0x36f, 0x365, 0x3, 
       0x2, 0x2, 0x2, 0x36f, 0x366, 0x3, 0x2, 0x2, 0x2, 0x36f, 0x367, 0x3, 
       0x2, 0x2, 0x2, 0x36f, 0x368, 0x3, 0x2, 0x2, 0x2, 0x36f, 0x369, 0x3, 
       0x2, 0x2, 0x2, 0x36f, 0x36a, 0x3, 0x2, 0x2, 0x2, 0x36f, 0x36b, 0x3, 
       0x2, 0x2, 0x2, 0x36f, 0x36c, 0x3, 0x2, 0x2, 0x2, 0x36f, 0x36d, 0x3, 
       0x2, 0x2, 0x2, 0x36f, 0x36e, 0x3, 0x2, 0x2, 0x2, 0x370, 0xb3, 0x3, 
       0x2, 0x2, 0x2, 0x371, 0x372, 0x9, 0x7, 0x2, 0x2, 0x372, 0xb5, 0x3, 
       0x2, 0x2, 0x2, 0x373, 0x374, 0x5, 0x4c, 0x27, 0x2, 0x374, 0x375, 
       0x5, 0x2c, 0x17, 0x2, 0x375, 0x37a, 0x5, 0x58, 0x2d, 0x2, 0x376, 
       0x377, 0x7, 0x4c, 0x2, 0x2, 0x377, 0x379, 0x5, 0x58, 0x2d, 0x2, 0x378, 
       0x376, 0x3, 0x2, 0x2, 0x2, 0x379, 0x37c, 0x3, 0x2, 0x2, 0x2, 0x37a, 
       0x378, 0x3, 0x2, 0x2, 0x2, 0x37a, 0x37b, 0x3, 0x2, 0x2, 0x2, 0x37b, 
       0x37d, 0x3, 0x2, 0x2, 0x2, 0x37c, 0x37a, 0x3, 0x2, 0x2, 0x2, 0x37d, 
       0x37e, 0x5, 0x2e, 0x18, 0x2, 0x37e, 0x380, 0x3, 0x2, 0x2, 0x2, 0x37f, 
       0x381, 0x5, 0xe, 0x8, 0x2, 0x380, 0x37f, 0x3, 0x2, 0x2, 0x2, 0x380, 
       0x381, 0x3, 0x2, 0x2, 0x2, 0x381, 0xb7, 0x3, 0x2, 0x2, 0x2, 0x382, 
       0x383, 0x5, 0x3c, 0x1f, 0x2, 0x383, 0x384, 0x5, 0xa8, 0x55, 0x2, 
       0x384, 0x385, 0x7, 0x50, 0x2, 0x2, 0x385, 0x390, 0x3, 0x2, 0x2, 0x2, 
       0x386, 0x38a, 0x5, 0x28, 0x15, 0x2, 0x387, 0x389, 0x5, 0xb2, 0x5a, 
       0x2, 0x388, 0x387, 0x3, 0x2, 0x2, 0x2, 0x389, 0x38c, 0x3, 0x2, 0x2, 
       0x2, 0x38a, 0x388, 0x3, 0x2, 0x2, 0x2, 0x38a, 0x38b, 0x3, 0x2, 0x2, 
       0x2, 0x38b, 0x38d, 0x3, 0x2, 0x2, 0x2, 0x38c, 0x38a, 0x3, 0x2, 0x2, 
       0x2, 0x38d, 0x38e, 0x5, 0x2a, 0x16, 0x2, 0x38e, 0x390, 0x3, 0x2, 
       0x2, 0x2, 0x38f, 0x382, 0x3, 0x2, 0x2, 0x2, 0x38f, 0x386, 0x3, 0x2, 
       0x2, 0x2, 0x390, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x391, 0x393, 0x5, 0x2c, 
       0x17, 0x2, 0x392, 0x394, 0x5, 0x62, 0x32, 0x2, 0x393, 0x392, 0x3, 
       0x2, 0x2, 0x2, 0x393, 0x394, 0x3, 0x2, 0x2, 0x2, 0x394, 0x395, 0x3, 
       0x2, 0x2, 0x2, 0x395, 0x396, 0x5, 0x2e, 0x18, 0x2, 0x396, 0x397, 
       0x5, 0xb8, 0x5d, 0x2, 0x397, 0xbb, 0x3, 0x2, 0x2, 0x2, 0x398, 0x39a, 
       0x5, 0xb4, 0x5b, 0x2, 0x399, 0x398, 0x3, 0x2, 0x2, 0x2, 0x399, 0x39a, 
       0x3, 0x2, 0x2, 0x2, 0x39a, 0x39c, 0x3, 0x2, 0x2, 0x2, 0x39b, 0x39d, 
       0x7, 0x25, 0x2, 0x2, 0x39c, 0x39b, 0x3, 0x2, 0x2, 0x2, 0x39c, 0x39d, 
       0x3, 0x2, 0x2, 0x2, 0x39d, 0x39e, 0x3, 0x2, 0x2, 0x2, 0x39e, 0x39f, 
       0x5, 0x58, 0x2d, 0x2, 0x39f, 0x3a1, 0x5, 0x4c, 0x27, 0x2, 0x3a0, 
       0x3a2, 0x5, 0xba, 0x5e, 0x2, 0x3a1, 0x3a0, 0x3, 0x2, 0x2, 0x2, 0x3a1, 
       0x3a2, 0x3, 0x2, 0x2, 0x2, 0x3a2, 0x3a3, 0x3, 0x2, 0x2, 0x2, 0x3a3, 
       0x3a4, 0x5, 0xc, 0x7, 0x2, 0x3a4, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x3a5, 
       0x3a7, 0x5, 0xb4, 0x5b, 0x2, 0x3a6, 0x3a5, 0x3, 0x2, 0x2, 0x2, 0x3a6, 
       0x3a7, 0x3, 0x2, 0x2, 0x2, 0x3a7, 0x3a8, 0x3, 0x2, 0x2, 0x2, 0x3a8, 
       0x3a9, 0x7, 0x16, 0x2, 0x2, 0x3a9, 0x3aa, 0x5, 0x4c, 0x27, 0x2, 0x3aa, 
       0x3ac, 0x5, 0x28, 0x15, 0x2, 0x3ab, 0x3ad, 0x5, 0xb6, 0x5c, 0x2, 
       0x3ac, 0x3ab, 0x3, 0x2, 0x2, 0x2, 0x3ad, 0x3ae, 0x3, 0x2, 0x2, 0x2, 
       0x3ae, 0x3ac, 0x3, 0x2, 0x2, 0x2, 0x3ae, 0x3af, 0x3, 0x2, 0x2, 0x2, 
       0x3af, 0x3b3, 0x3, 0x2, 0x2, 0x2, 0x3b0, 0x3b2, 0x5, 0xbc, 0x5f, 
       0x2, 0x3b1, 0x3b0, 0x3, 0x2, 0x2, 0x2, 0x3b2, 0x3b5, 0x3, 0x2, 0x2, 
       0x2, 0x3b3, 0x3b1, 0x3, 0x2, 0x2, 0x2, 0x3b3, 0x3b4, 0x3, 0x2, 0x2, 
       0x2, 0x3b4, 0x3b6, 0x3, 0x2, 0x2, 0x2, 0x3b5, 0x3b3, 0x3, 0x2, 0x2, 
       0x2, 0x3b6, 0x3b7, 0x5, 0x2a, 0x16, 0x2, 0x3b7, 0x3b8, 0x5, 0xc, 
       0x7, 0x2, 0x3b8, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x3b9, 0x3bb, 0x5, 0xb4, 
       0x5b, 0x2, 0x3ba, 0x3b9, 0x3, 0x2, 0x2, 0x2, 0x3ba, 0x3bb, 0x3, 0x2, 
       0x2, 0x2, 0x3bb, 0x3bc, 0x3, 0x2, 0x2, 0x2, 0x3bc, 0x3bd, 0x7, 0x12, 
       0x2, 0x2, 0x3bd, 0x3be, 0x5, 0x4c, 0x27, 0x2, 0x3be, 0x3c2, 0x5, 
       0x28, 0x15, 0x2, 0x3bf, 0x3c1, 0x5, 0xbc, 0x5f, 0x2, 0x3c0, 0x3bf, 
       0x3, 0x2, 0x2, 0x2, 0x3c1, 0x3c4, 0x3, 0x2, 0x2, 0x2, 0x3c2, 0x3c0, 
       0x3, 0x2, 0x2, 0x2, 0x3c2, 0x3c3, 0x3, 0x2, 0x2, 0x2, 0x3c3, 0x3c5, 
       0x3, 0x2, 0x2, 0x2, 0x3c4, 0x3c2, 0x3, 0x2, 0x2, 0x2, 0x3c5, 0x3c6, 
       0x5, 0x2a, 0x16, 0x2, 0x3c6, 0x3c7, 0x5, 0xc, 0x7, 0x2, 0x3c7, 0xc1, 
       0x3, 0x2, 0x2, 0x2, 0x3c8, 0x3cc, 0x7, 0x29, 0x2, 0x2, 0x3c9, 0x3ca, 
       0x5, 0x4c, 0x27, 0x2, 0x3ca, 0x3cb, 0x7, 0x2c, 0x2, 0x2, 0x3cb, 0x3cd, 
       0x3, 0x2, 0x2, 0x2, 0x3cc, 0x3c9, 0x3, 0x2, 0x2, 0x2, 0x3cc, 0x3cd, 
       0x3, 0x2, 0x2, 0x2, 0x3cd, 0x3ce, 0x3, 0x2, 0x2, 0x2, 0x3ce, 0x3cf, 
       0x5, 0x4e, 0x28, 0x2, 0x3cf, 0x3d0, 0x5, 0xc, 0x7, 0x2, 0x3d0, 0xc3, 
       0x3, 0x2, 0x2, 0x2, 0x3d1, 0x3d2, 0x9, 0x8, 0x2, 0x2, 0x3d2, 0xc5, 
       0x3, 0x2, 0x2, 0x2, 0x3d3, 0x3d4, 0x7, 0xb, 0x2, 0x2, 0x3d4, 0x3d5, 
       0x5, 0x58, 0x2d, 0x2, 0x3d5, 0x3d6, 0x5, 0xc4, 0x63, 0x2, 0x3d6, 
       0x3d7, 0x5, 0x4c, 0x27, 0x2, 0x3d7, 0x3d8, 0x5, 0x2c, 0x17, 0x2, 
       0x3d8, 0x3d9, 0x5, 0x5e, 0x30, 0x2, 0x3d9, 0x3da, 0x5, 0x2e, 0x18, 
       0x2, 0x3da, 0x3db, 0x5, 0xc, 0x7, 0x2, 0x3db, 0xc7, 0x3, 0x2, 0x2, 
       0x2, 0x3dc, 0x3dd, 0x7, 0xc, 0x2, 0x2, 0x3dd, 0x3de, 0x7, 0x55, 0x2, 
       0x2, 0x3de, 0x3df, 0x5, 0xc, 0x7, 0x2, 0x3df, 0xc9, 0x3, 0x2, 0x2, 
       0x2, 0x3e0, 0x3e1, 0x7, 0x1d, 0x2, 0x2, 0x3e1, 0x3e2, 0x5, 0x4e, 
       0x28, 0x2, 0x3e2, 0x3e3, 0x5, 0xc, 0x7, 0x2, 0x3e3, 0xcb, 0x3, 0x2, 
       0x2, 0x2, 0x3e4, 0x3e8, 0x5, 0xc2, 0x62, 0x2, 0x3e5, 0x3e8, 0x5, 
       0xc6, 0x64, 0x2, 0x3e6, 0x3e8, 0x5, 0xc8, 0x65, 0x2, 0x3e7, 0x3e4, 
       0x3, 0x2, 0x2, 0x2, 0x3e7, 0x3e5, 0x3, 0x2, 0x2, 0x2, 0x3e7, 0x3e6, 
       0x3, 0x2, 0x2, 0x2, 0x3e8, 0x3eb, 0x3, 0x2, 0x2, 0x2, 0x3e9, 0x3e7, 
       0x3, 0x2, 0x2, 0x2, 0x3e9, 0x3ea, 0x3, 0x2, 0x2, 0x2, 0x3ea, 0x3ed, 
       0x3, 0x2, 0x2, 0x2, 0x3eb, 0x3e9, 0x3, 0x2, 0x2, 0x2, 0x3ec, 0x3ee, 
       0x5, 0xca, 0x66, 0x2, 0x3ed, 0x3ec, 0x3, 0x2, 0x2, 0x2, 0x3ed, 0x3ee, 
       0x3, 0x2, 0x2, 0x2, 0x3ee, 0x3f3, 0x3, 0x2, 0x2, 0x2, 0x3ef, 0x3f2, 
       0x5, 0xbe, 0x60, 0x2, 0x3f0, 0x3f2, 0x5, 0xc0, 0x61, 0x2, 0x3f1, 
       0x3ef, 0x3, 0x2, 0x2, 0x2, 0x3f1, 0x3f0, 0x3, 0x2, 0x2, 0x2, 0x3f2, 
       0x3f5, 0x3, 0x2, 0x2, 0x2, 0x3f3, 0x3f1, 0x3, 0x2, 0x2, 0x2, 0x3f3, 
       0x3f4, 0x3, 0x2, 0x2, 0x2, 0x3f4, 0xcd, 0x3, 0x2, 0x2, 0x2, 0x3f5, 
       0x3f3, 0x3, 0x2, 0x2, 0x2, 0x3f6, 0x3f7, 0x5, 0xcc, 0x67, 0x2, 0x3f7, 
       0x3f8, 0x7, 0x2, 0x2, 0x3, 0x3f8, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x63, 
       0xe5, 0xf0, 0xf5, 0x109, 0x10c, 0x112, 0x115, 0x11b, 0x11e, 0x124, 
       0x127, 0x14b, 0x153, 0x157, 0x15b, 0x15e, 0x163, 0x16b, 0x174, 0x17e, 
       0x189, 0x192, 0x197, 0x19f, 0x1a5, 0x1aa, 0x1ae, 0x1b4, 0x1bb, 0x1c0, 
       0x1c7, 0x1cb, 0x1d4, 0x1db, 0x1e4, 0x1f4, 0x1f9, 0x205, 0x211, 0x21b, 
       0x22b, 0x22e, 0x234, 0x242, 0x24d, 0x257, 0x262, 0x271, 0x27a, 0x286, 
       0x297, 0x2a2, 0x2a7, 0x2b1, 0x2b4, 0x2c0, 0x2c3, 0x2cd, 0x2d7, 0x2de, 
       0x2e7, 0x2ec, 0x2ef, 0x2fd, 0x309, 0x30c, 0x316, 0x323, 0x325, 0x32a, 
       0x331, 0x33a, 0x343, 0x354, 0x35a, 0x35d, 0x361, 0x36f, 0x37a, 0x380, 
       0x38a, 0x38f, 0x393, 0x399, 0x39c, 0x3a1, 0x3a6, 0x3ae, 0x3b3, 0x3ba, 
       0x3c2, 0x3cc, 0x3e7, 0x3e9, 0x3ed, 0x3f1, 0x3f3, 
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

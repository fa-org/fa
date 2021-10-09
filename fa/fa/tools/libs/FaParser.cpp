
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


//----------------- AddAssignContext ------------------------------------------------------------------

FaParser::AddAssignContext::AddAssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::AddAssignContext::AddOp() {
  return getToken(FaParser::AddOp, 0);
}

tree::TerminalNode* FaParser::AddAssignContext::Assign() {
  return getToken(FaParser::Assign, 0);
}


size_t FaParser::AddAssignContext::getRuleIndex() const {
  return FaParser::RuleAddAssign;
}


antlrcpp::Any FaParser::AddAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitAddAssign(this);
  else
    return visitor->visitChildren(this);
}

FaParser::AddAssignContext* FaParser::addAssign() {
  AddAssignContext *_localctx = _tracker.createInstance<AddAssignContext>(_ctx, getState());
  enterRule(_localctx, 0, FaParser::RuleAddAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(162);
    match(FaParser::AddOp);
    setState(163);
    match(FaParser::Assign);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubAssignContext ------------------------------------------------------------------

FaParser::SubAssignContext::SubAssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::SubAssignContext::SubOp() {
  return getToken(FaParser::SubOp, 0);
}

tree::TerminalNode* FaParser::SubAssignContext::Assign() {
  return getToken(FaParser::Assign, 0);
}


size_t FaParser::SubAssignContext::getRuleIndex() const {
  return FaParser::RuleSubAssign;
}


antlrcpp::Any FaParser::SubAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitSubAssign(this);
  else
    return visitor->visitChildren(this);
}

FaParser::SubAssignContext* FaParser::subAssign() {
  SubAssignContext *_localctx = _tracker.createInstance<SubAssignContext>(_ctx, getState());
  enterRule(_localctx, 2, FaParser::RuleSubAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(165);
    match(FaParser::SubOp);
    setState(166);
    match(FaParser::Assign);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StarAssignContext ------------------------------------------------------------------

FaParser::StarAssignContext::StarAssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::StarAssignContext::StarOp() {
  return getToken(FaParser::StarOp, 0);
}

tree::TerminalNode* FaParser::StarAssignContext::Assign() {
  return getToken(FaParser::Assign, 0);
}


size_t FaParser::StarAssignContext::getRuleIndex() const {
  return FaParser::RuleStarAssign;
}


antlrcpp::Any FaParser::StarAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitStarAssign(this);
  else
    return visitor->visitChildren(this);
}

FaParser::StarAssignContext* FaParser::starAssign() {
  StarAssignContext *_localctx = _tracker.createInstance<StarAssignContext>(_ctx, getState());
  enterRule(_localctx, 4, FaParser::RuleStarAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(168);
    match(FaParser::StarOp);
    setState(169);
    match(FaParser::Assign);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DivAssignContext ------------------------------------------------------------------

FaParser::DivAssignContext::DivAssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::DivAssignContext::DivOp() {
  return getToken(FaParser::DivOp, 0);
}

tree::TerminalNode* FaParser::DivAssignContext::Assign() {
  return getToken(FaParser::Assign, 0);
}


size_t FaParser::DivAssignContext::getRuleIndex() const {
  return FaParser::RuleDivAssign;
}


antlrcpp::Any FaParser::DivAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitDivAssign(this);
  else
    return visitor->visitChildren(this);
}

FaParser::DivAssignContext* FaParser::divAssign() {
  DivAssignContext *_localctx = _tracker.createInstance<DivAssignContext>(_ctx, getState());
  enterRule(_localctx, 6, FaParser::RuleDivAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(171);
    match(FaParser::DivOp);
    setState(172);
    match(FaParser::Assign);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ModAssignContext ------------------------------------------------------------------

FaParser::ModAssignContext::ModAssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::ModAssignContext::ModOp() {
  return getToken(FaParser::ModOp, 0);
}

tree::TerminalNode* FaParser::ModAssignContext::Assign() {
  return getToken(FaParser::Assign, 0);
}


size_t FaParser::ModAssignContext::getRuleIndex() const {
  return FaParser::RuleModAssign;
}


antlrcpp::Any FaParser::ModAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitModAssign(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ModAssignContext* FaParser::modAssign() {
  ModAssignContext *_localctx = _tracker.createInstance<ModAssignContext>(_ctx, getState());
  enterRule(_localctx, 8, FaParser::RuleModAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(174);
    match(FaParser::ModOp);
    setState(175);
    match(FaParser::Assign);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OrAssignContext ------------------------------------------------------------------

FaParser::OrAssignContext::OrAssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::OrAssignContext::OrOp() {
  return getToken(FaParser::OrOp, 0);
}

tree::TerminalNode* FaParser::OrAssignContext::Assign() {
  return getToken(FaParser::Assign, 0);
}


size_t FaParser::OrAssignContext::getRuleIndex() const {
  return FaParser::RuleOrAssign;
}


antlrcpp::Any FaParser::OrAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitOrAssign(this);
  else
    return visitor->visitChildren(this);
}

FaParser::OrAssignContext* FaParser::orAssign() {
  OrAssignContext *_localctx = _tracker.createInstance<OrAssignContext>(_ctx, getState());
  enterRule(_localctx, 10, FaParser::RuleOrAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(177);
    match(FaParser::OrOp);
    setState(178);
    match(FaParser::Assign);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AndAssignContext ------------------------------------------------------------------

FaParser::AndAssignContext::AndAssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::AndAssignContext::AndOp() {
  return getToken(FaParser::AndOp, 0);
}

tree::TerminalNode* FaParser::AndAssignContext::Assign() {
  return getToken(FaParser::Assign, 0);
}


size_t FaParser::AndAssignContext::getRuleIndex() const {
  return FaParser::RuleAndAssign;
}


antlrcpp::Any FaParser::AndAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitAndAssign(this);
  else
    return visitor->visitChildren(this);
}

FaParser::AndAssignContext* FaParser::andAssign() {
  AndAssignContext *_localctx = _tracker.createInstance<AndAssignContext>(_ctx, getState());
  enterRule(_localctx, 12, FaParser::RuleAndAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(180);
    match(FaParser::AndOp);
    setState(181);
    match(FaParser::Assign);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- XorAssignContext ------------------------------------------------------------------

FaParser::XorAssignContext::XorAssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::XorAssignContext::XorOp() {
  return getToken(FaParser::XorOp, 0);
}

tree::TerminalNode* FaParser::XorAssignContext::Assign() {
  return getToken(FaParser::Assign, 0);
}


size_t FaParser::XorAssignContext::getRuleIndex() const {
  return FaParser::RuleXorAssign;
}


antlrcpp::Any FaParser::XorAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitXorAssign(this);
  else
    return visitor->visitChildren(this);
}

FaParser::XorAssignContext* FaParser::xorAssign() {
  XorAssignContext *_localctx = _tracker.createInstance<XorAssignContext>(_ctx, getState());
  enterRule(_localctx, 14, FaParser::RuleXorAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(183);
    match(FaParser::XorOp);
    setState(184);
    match(FaParser::Assign);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QusQusAssignContext ------------------------------------------------------------------

FaParser::QusQusAssignContext::QusQusAssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::QusQusOpContext* FaParser::QusQusAssignContext::qusQusOp() {
  return getRuleContext<FaParser::QusQusOpContext>(0);
}

tree::TerminalNode* FaParser::QusQusAssignContext::Assign() {
  return getToken(FaParser::Assign, 0);
}


size_t FaParser::QusQusAssignContext::getRuleIndex() const {
  return FaParser::RuleQusQusAssign;
}


antlrcpp::Any FaParser::QusQusAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitQusQusAssign(this);
  else
    return visitor->visitChildren(this);
}

FaParser::QusQusAssignContext* FaParser::qusQusAssign() {
  QusQusAssignContext *_localctx = _tracker.createInstance<QusQusAssignContext>(_ctx, getState());
  enterRule(_localctx, 16, FaParser::RuleQusQusAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(186);
    qusQusOp();
    setState(187);
    match(FaParser::Assign);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StarStarAssignContext ------------------------------------------------------------------

FaParser::StarStarAssignContext::StarStarAssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::StarStarOpContext* FaParser::StarStarAssignContext::starStarOp() {
  return getRuleContext<FaParser::StarStarOpContext>(0);
}

tree::TerminalNode* FaParser::StarStarAssignContext::Assign() {
  return getToken(FaParser::Assign, 0);
}


size_t FaParser::StarStarAssignContext::getRuleIndex() const {
  return FaParser::RuleStarStarAssign;
}


antlrcpp::Any FaParser::StarStarAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitStarStarAssign(this);
  else
    return visitor->visitChildren(this);
}

FaParser::StarStarAssignContext* FaParser::starStarAssign() {
  StarStarAssignContext *_localctx = _tracker.createInstance<StarStarAssignContext>(_ctx, getState());
  enterRule(_localctx, 18, FaParser::RuleStarStarAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(189);
    starStarOp();
    setState(190);
    match(FaParser::Assign);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AndAndAssignContext ------------------------------------------------------------------

FaParser::AndAndAssignContext::AndAndAssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::AndAndOpContext* FaParser::AndAndAssignContext::andAndOp() {
  return getRuleContext<FaParser::AndAndOpContext>(0);
}

tree::TerminalNode* FaParser::AndAndAssignContext::Assign() {
  return getToken(FaParser::Assign, 0);
}


size_t FaParser::AndAndAssignContext::getRuleIndex() const {
  return FaParser::RuleAndAndAssign;
}


antlrcpp::Any FaParser::AndAndAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitAndAndAssign(this);
  else
    return visitor->visitChildren(this);
}

FaParser::AndAndAssignContext* FaParser::andAndAssign() {
  AndAndAssignContext *_localctx = _tracker.createInstance<AndAndAssignContext>(_ctx, getState());
  enterRule(_localctx, 20, FaParser::RuleAndAndAssign);

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
    andAndOp();
    setState(193);
    match(FaParser::Assign);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OrOrAssignContext ------------------------------------------------------------------

FaParser::OrOrAssignContext::OrOrAssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::OrOrOpContext* FaParser::OrOrAssignContext::orOrOp() {
  return getRuleContext<FaParser::OrOrOpContext>(0);
}

tree::TerminalNode* FaParser::OrOrAssignContext::Assign() {
  return getToken(FaParser::Assign, 0);
}


size_t FaParser::OrOrAssignContext::getRuleIndex() const {
  return FaParser::RuleOrOrAssign;
}


antlrcpp::Any FaParser::OrOrAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitOrOrAssign(this);
  else
    return visitor->visitChildren(this);
}

FaParser::OrOrAssignContext* FaParser::orOrAssign() {
  OrOrAssignContext *_localctx = _tracker.createInstance<OrOrAssignContext>(_ctx, getState());
  enterRule(_localctx, 22, FaParser::RuleOrOrAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(195);
    orOrOp();
    setState(196);
    match(FaParser::Assign);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
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
  enterRule(_localctx, 24, FaParser::RuleShiftLAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(198);
    shiftLOp();
    setState(199);
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
  enterRule(_localctx, 26, FaParser::RuleShiftRAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(201);
    shiftROp();
    setState(202);
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

FaParser::QusQusAssignContext* FaParser::AllAssignContext::qusQusAssign() {
  return getRuleContext<FaParser::QusQusAssignContext>(0);
}

FaParser::AddAssignContext* FaParser::AllAssignContext::addAssign() {
  return getRuleContext<FaParser::AddAssignContext>(0);
}

FaParser::SubAssignContext* FaParser::AllAssignContext::subAssign() {
  return getRuleContext<FaParser::SubAssignContext>(0);
}

FaParser::StarAssignContext* FaParser::AllAssignContext::starAssign() {
  return getRuleContext<FaParser::StarAssignContext>(0);
}

FaParser::StarStarAssignContext* FaParser::AllAssignContext::starStarAssign() {
  return getRuleContext<FaParser::StarStarAssignContext>(0);
}

FaParser::DivAssignContext* FaParser::AllAssignContext::divAssign() {
  return getRuleContext<FaParser::DivAssignContext>(0);
}

FaParser::ModAssignContext* FaParser::AllAssignContext::modAssign() {
  return getRuleContext<FaParser::ModAssignContext>(0);
}

FaParser::AndAssignContext* FaParser::AllAssignContext::andAssign() {
  return getRuleContext<FaParser::AndAssignContext>(0);
}

FaParser::OrAssignContext* FaParser::AllAssignContext::orAssign() {
  return getRuleContext<FaParser::OrAssignContext>(0);
}

FaParser::XorAssignContext* FaParser::AllAssignContext::xorAssign() {
  return getRuleContext<FaParser::XorAssignContext>(0);
}

FaParser::AndAndAssignContext* FaParser::AllAssignContext::andAndAssign() {
  return getRuleContext<FaParser::AndAndAssignContext>(0);
}

FaParser::OrOrAssignContext* FaParser::AllAssignContext::orOrAssign() {
  return getRuleContext<FaParser::OrOrAssignContext>(0);
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
  enterRule(_localctx, 28, FaParser::RuleAllAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(219);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(204);
      match(FaParser::Assign);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(205);
      qusQusAssign();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(206);
      addAssign();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(207);
      subAssign();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(208);
      starAssign();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(209);
      starStarAssign();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(210);
      divAssign();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(211);
      modAssign();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(212);
      andAssign();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(213);
      orAssign();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(214);
      xorAssign();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(215);
      andAndAssign();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(216);
      orOrAssign();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(217);
      shiftLAssign();
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(218);
      shiftRAssign();
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

//----------------- QusQusOpContext ------------------------------------------------------------------

FaParser::QusQusOpContext::QusQusOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FaParser::QusQusOpContext::Qus() {
  return getTokens(FaParser::Qus);
}

tree::TerminalNode* FaParser::QusQusOpContext::Qus(size_t i) {
  return getToken(FaParser::Qus, i);
}


size_t FaParser::QusQusOpContext::getRuleIndex() const {
  return FaParser::RuleQusQusOp;
}


antlrcpp::Any FaParser::QusQusOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitQusQusOp(this);
  else
    return visitor->visitChildren(this);
}

FaParser::QusQusOpContext* FaParser::qusQusOp() {
  QusQusOpContext *_localctx = _tracker.createInstance<QusQusOpContext>(_ctx, getState());
  enterRule(_localctx, 30, FaParser::RuleQusQusOp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(221);
    match(FaParser::Qus);
    setState(222);
    match(FaParser::Qus);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StarStarOpContext ------------------------------------------------------------------

FaParser::StarStarOpContext::StarStarOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FaParser::StarStarOpContext::StarOp() {
  return getTokens(FaParser::StarOp);
}

tree::TerminalNode* FaParser::StarStarOpContext::StarOp(size_t i) {
  return getToken(FaParser::StarOp, i);
}


size_t FaParser::StarStarOpContext::getRuleIndex() const {
  return FaParser::RuleStarStarOp;
}


antlrcpp::Any FaParser::StarStarOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitStarStarOp(this);
  else
    return visitor->visitChildren(this);
}

FaParser::StarStarOpContext* FaParser::starStarOp() {
  StarStarOpContext *_localctx = _tracker.createInstance<StarStarOpContext>(_ctx, getState());
  enterRule(_localctx, 32, FaParser::RuleStarStarOp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(224);
    match(FaParser::StarOp);
    setState(225);
    match(FaParser::StarOp);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AndAndOpContext ------------------------------------------------------------------

FaParser::AndAndOpContext::AndAndOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FaParser::AndAndOpContext::AndOp() {
  return getTokens(FaParser::AndOp);
}

tree::TerminalNode* FaParser::AndAndOpContext::AndOp(size_t i) {
  return getToken(FaParser::AndOp, i);
}


size_t FaParser::AndAndOpContext::getRuleIndex() const {
  return FaParser::RuleAndAndOp;
}


antlrcpp::Any FaParser::AndAndOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitAndAndOp(this);
  else
    return visitor->visitChildren(this);
}

FaParser::AndAndOpContext* FaParser::andAndOp() {
  AndAndOpContext *_localctx = _tracker.createInstance<AndAndOpContext>(_ctx, getState());
  enterRule(_localctx, 34, FaParser::RuleAndAndOp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(227);
    match(FaParser::AndOp);
    setState(228);
    match(FaParser::AndOp);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OrOrOpContext ------------------------------------------------------------------

FaParser::OrOrOpContext::OrOrOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FaParser::OrOrOpContext::OrOp() {
  return getTokens(FaParser::OrOp);
}

tree::TerminalNode* FaParser::OrOrOpContext::OrOp(size_t i) {
  return getToken(FaParser::OrOp, i);
}


size_t FaParser::OrOrOpContext::getRuleIndex() const {
  return FaParser::RuleOrOrOp;
}


antlrcpp::Any FaParser::OrOrOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitOrOrOp(this);
  else
    return visitor->visitChildren(this);
}

FaParser::OrOrOpContext* FaParser::orOrOp() {
  OrOrOpContext *_localctx = _tracker.createInstance<OrOrOpContext>(_ctx, getState());
  enterRule(_localctx, 36, FaParser::RuleOrOrOp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(230);
    match(FaParser::OrOp);
    setState(231);
    match(FaParser::OrOp);
   
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

std::vector<tree::TerminalNode *> FaParser::ShiftLOpContext::QuotJianL() {
  return getTokens(FaParser::QuotJianL);
}

tree::TerminalNode* FaParser::ShiftLOpContext::QuotJianL(size_t i) {
  return getToken(FaParser::QuotJianL, i);
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
  enterRule(_localctx, 38, FaParser::RuleShiftLOp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(233);
    match(FaParser::QuotJianL);
    setState(234);
    match(FaParser::QuotJianL);
   
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

std::vector<tree::TerminalNode *> FaParser::ShiftROpContext::QuotJianR() {
  return getTokens(FaParser::QuotJianR);
}

tree::TerminalNode* FaParser::ShiftROpContext::QuotJianR(size_t i) {
  return getToken(FaParser::QuotJianR, i);
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
  enterRule(_localctx, 40, FaParser::RuleShiftROp);

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
    match(FaParser::QuotJianR);
    setState(237);
    match(FaParser::QuotJianR);
   
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

tree::TerminalNode* FaParser::LtOpContext::QuotJianL() {
  return getToken(FaParser::QuotJianL, 0);
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
  enterRule(_localctx, 42, FaParser::RuleLtOp);

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
    match(FaParser::QuotJianL);
   
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

tree::TerminalNode* FaParser::LtEqualOpContext::QuotJianL() {
  return getToken(FaParser::QuotJianL, 0);
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
  enterRule(_localctx, 44, FaParser::RuleLtEqualOp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(241);
    match(FaParser::QuotJianL);
    setState(242);
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

tree::TerminalNode* FaParser::GtOpContext::QuotJianR() {
  return getToken(FaParser::QuotJianR, 0);
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
  enterRule(_localctx, 46, FaParser::RuleGtOp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(244);
    match(FaParser::QuotJianR);
   
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

tree::TerminalNode* FaParser::GtEqualOpContext::QuotJianR() {
  return getToken(FaParser::QuotJianR, 0);
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
  enterRule(_localctx, 48, FaParser::RuleGtEqualOp);

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
    match(FaParser::QuotJianR);
    setState(247);
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
  enterRule(_localctx, 50, FaParser::RuleEqualOp);

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
    match(FaParser::Assign);
    setState(250);
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
  enterRule(_localctx, 52, FaParser::RuleNotEqualOp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(252);
    match(FaParser::Exclam);
    setState(253);
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

tree::TerminalNode* FaParser::ExprFuncDefContext::QuotJianR() {
  return getToken(FaParser::QuotJianR, 0);
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
  enterRule(_localctx, 54, FaParser::RuleExprFuncDef);

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
    match(FaParser::Assign);
    setState(256);
    match(FaParser::QuotJianR);
   
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

FaParser::StarStarOpContext* FaParser::SelfOp2Context::starStarOp() {
  return getRuleContext<FaParser::StarStarOpContext>(0);
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

FaParser::AndAndOpContext* FaParser::SelfOp2Context::andAndOp() {
  return getRuleContext<FaParser::AndAndOpContext>(0);
}

FaParser::OrOrOpContext* FaParser::SelfOp2Context::orOrOp() {
  return getRuleContext<FaParser::OrOrOpContext>(0);
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
  enterRule(_localctx, 56, FaParser::RuleSelfOp2);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(271);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(258);
      match(FaParser::AddOp);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(259);
      match(FaParser::SubOp);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(260);
      match(FaParser::StarOp);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(261);
      match(FaParser::DivOp);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(262);
      starStarOp();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(263);
      match(FaParser::ModOp);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(264);
      match(FaParser::AndOp);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(265);
      match(FaParser::OrOp);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(266);
      match(FaParser::XorOp);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(267);
      andAndOp();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(268);
      orOrOp();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(269);
      shiftLOp();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(270);
      shiftROp();
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
  enterRule(_localctx, 58, FaParser::RuleCompareOp2);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(279);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(273);
      ltOp();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(274);
      ltEqualOp();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(275);
      gtOp();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(276);
      gtEqualOp();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(277);
      equalOp();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(278);
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

FaParser::QusQusOpContext* FaParser::ChangeOp2Context::qusQusOp() {
  return getRuleContext<FaParser::QusQusOpContext>(0);
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
  enterRule(_localctx, 60, FaParser::RuleChangeOp2);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(283);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::Qus: {
        enterOuterAlt(_localctx, 1);
        setState(281);
        qusQusOp();
        break;
      }

      case FaParser::Assign:
      case FaParser::Exclam:
      case FaParser::QuotJianL:
      case FaParser::QuotJianR: {
        enterOuterAlt(_localctx, 2);
        setState(282);
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
  enterRule(_localctx, 62, FaParser::RuleAllOp2);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(287);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(285);
      selfOp2();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(286);
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
  enterRule(_localctx, 64, FaParser::RuleIntNum);
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
    setState(290);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::SubOp) {
      setState(289);
      match(FaParser::SubOp);
    }
    setState(292);
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
  enterRule(_localctx, 66, FaParser::RuleFloatNum);
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
    setState(295);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::SubOp) {
      setState(294);
      match(FaParser::SubOp);
    }
    setState(297);
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
  enterRule(_localctx, 68, FaParser::RuleLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(303);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(299);
      match(FaParser::BoolLiteral);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(300);
      intNum();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(301);
      floatNum();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(302);
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
  enterRule(_localctx, 70, FaParser::RuleIds);

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
    setState(305);
    match(FaParser::Id);
    setState(310);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(306);
        match(FaParser::PointOp);
        setState(307);
        match(FaParser::Id); 
      }
      setState(312);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
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

tree::TerminalNode* FaParser::TypeAfterContext::QuotJianL() {
  return getToken(FaParser::QuotJianL, 0);
}

std::vector<FaParser::TypeContext *> FaParser::TypeAfterContext::type() {
  return getRuleContexts<FaParser::TypeContext>();
}

FaParser::TypeContext* FaParser::TypeAfterContext::type(size_t i) {
  return getRuleContext<FaParser::TypeContext>(i);
}

tree::TerminalNode* FaParser::TypeAfterContext::QuotJianR() {
  return getToken(FaParser::QuotJianR, 0);
}

std::vector<tree::TerminalNode *> FaParser::TypeAfterContext::Comma() {
  return getTokens(FaParser::Comma);
}

tree::TerminalNode* FaParser::TypeAfterContext::Comma(size_t i) {
  return getToken(FaParser::Comma, i);
}

tree::TerminalNode* FaParser::TypeAfterContext::StarOp() {
  return getToken(FaParser::StarOp, 0);
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
  enterRule(_localctx, 72, FaParser::RuleTypeAfter);
  size_t _la = 0;

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
      case FaParser::QuotFangL: {
        enterOuterAlt(_localctx, 1);
        setState(313);
        match(FaParser::QuotFangL);
        setState(314);
        match(FaParser::QuotFangR);
        break;
      }

      case FaParser::AndOp: {
        enterOuterAlt(_localctx, 2);
        setState(315);
        match(FaParser::AndOp);
        break;
      }

      case FaParser::Qus: {
        enterOuterAlt(_localctx, 3);
        setState(316);
        match(FaParser::Qus);
        break;
      }

      case FaParser::QuotJianL: {
        enterOuterAlt(_localctx, 4);
        setState(317);
        match(FaParser::QuotJianL);
        setState(318);
        type();
        setState(323);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == FaParser::Comma) {
          setState(319);
          match(FaParser::Comma);
          setState(320);
          type();
          setState(325);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(326);
        match(FaParser::QuotJianR);
        break;
      }

      case FaParser::StarOp: {
        enterOuterAlt(_localctx, 5);
        setState(328);
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

//----------------- TypeContext ------------------------------------------------------------------

FaParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::TypeContext::Id() {
  return getToken(FaParser::Id, 0);
}

std::vector<FaParser::TypeAfterContext *> FaParser::TypeContext::typeAfter() {
  return getRuleContexts<FaParser::TypeAfterContext>();
}

FaParser::TypeAfterContext* FaParser::TypeContext::typeAfter(size_t i) {
  return getRuleContext<FaParser::TypeAfterContext>(i);
}

tree::TerminalNode* FaParser::TypeContext::QuotYuanL() {
  return getToken(FaParser::QuotYuanL, 0);
}

std::vector<FaParser::TypeContext *> FaParser::TypeContext::type() {
  return getRuleContexts<FaParser::TypeContext>();
}

FaParser::TypeContext* FaParser::TypeContext::type(size_t i) {
  return getRuleContext<FaParser::TypeContext>(i);
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
  enterRule(_localctx, 74, FaParser::RuleType);
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
    setState(342);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::Id: {
        setState(331);
        match(FaParser::Id);
        break;
      }

      case FaParser::QuotYuanL: {
        setState(332);
        match(FaParser::QuotYuanL);
        setState(333);
        type();
        setState(336); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(334);
          match(FaParser::Comma);
          setState(335);
          type();
          setState(338); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == FaParser::Comma);
        setState(340);
        match(FaParser::QuotYuanR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(347);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(344);
        typeAfter(); 
      }
      setState(349);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeNewableContext ------------------------------------------------------------------

FaParser::TypeNewableContext::TypeNewableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::TypeNewableContext::Id() {
  return getToken(FaParser::Id, 0);
}

std::vector<FaParser::TypeAfterContext *> FaParser::TypeNewableContext::typeAfter() {
  return getRuleContexts<FaParser::TypeAfterContext>();
}

FaParser::TypeAfterContext* FaParser::TypeNewableContext::typeAfter(size_t i) {
  return getRuleContext<FaParser::TypeAfterContext>(i);
}


size_t FaParser::TypeNewableContext::getRuleIndex() const {
  return FaParser::RuleTypeNewable;
}


antlrcpp::Any FaParser::TypeNewableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitTypeNewable(this);
  else
    return visitor->visitChildren(this);
}

FaParser::TypeNewableContext* FaParser::typeNewable() {
  TypeNewableContext *_localctx = _tracker.createInstance<TypeNewableContext>(_ctx, getState());
  enterRule(_localctx, 76, FaParser::RuleTypeNewable);
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
    setState(350);
    match(FaParser::Id);
    setState(354);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::StarOp)
      | (1ULL << FaParser::AndOp)
      | (1ULL << FaParser::Qus)
      | (1ULL << FaParser::QuotFangL)
      | (1ULL << FaParser::QuotJianL))) != 0)) {
      setState(351);
      typeAfter();
      setState(356);
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
  enterRule(_localctx, 78, FaParser::RuleTypeVar);
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
    setState(357);
    type();
    setState(359);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Id) {
      setState(358);
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
  enterRule(_localctx, 80, FaParser::RuleTypeVarList);
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
    setState(361);
    typeVar();
    setState(366);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(362);
      match(FaParser::Comma);
      setState(363);
      typeVar();
      setState(368);
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

tree::TerminalNode* FaParser::QuotStmtPartContext::QuotHuaL() {
  return getToken(FaParser::QuotHuaL, 0);
}

tree::TerminalNode* FaParser::QuotStmtPartContext::QuotHuaR() {
  return getToken(FaParser::QuotHuaR, 0);
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
  enterRule(_localctx, 82, FaParser::RuleQuotStmtPart);
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
    setState(369);
    match(FaParser::QuotHuaL);
    setState(373);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Break)
      | (1ULL << FaParser::Continue)
      | (1ULL << FaParser::For)
      | (1ULL << FaParser::If)
      | (1ULL << FaParser::New)
      | (1ULL << FaParser::Return)
      | (1ULL << FaParser::While)
      | (1ULL << FaParser::ReverseOp)
      | (1ULL << FaParser::AddAddOp)
      | (1ULL << FaParser::SubSubOp)
      | (1ULL << FaParser::SubOp)
      | (1ULL << FaParser::ColonColon)
      | (1ULL << FaParser::Semi)
      | (1ULL << FaParser::QuotFangL)
      | (1ULL << FaParser::QuotYuanL)
      | (1ULL << FaParser::BoolLiteral)
      | (1ULL << FaParser::IntLiteral)
      | (1ULL << FaParser::FloatLiteral)
      | (1ULL << FaParser::String1Literal)
      | (1ULL << FaParser::Id))) != 0)) {
      setState(370);
      stmt();
      setState(375);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(376);
    match(FaParser::QuotHuaR);
   
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

tree::TerminalNode* FaParser::QuotStmtExprContext::QuotHuaL() {
  return getToken(FaParser::QuotHuaL, 0);
}

FaParser::ExprContext* FaParser::QuotStmtExprContext::expr() {
  return getRuleContext<FaParser::ExprContext>(0);
}

tree::TerminalNode* FaParser::QuotStmtExprContext::QuotHuaR() {
  return getToken(FaParser::QuotHuaR, 0);
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
  enterRule(_localctx, 84, FaParser::RuleQuotStmtExpr);

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
    setState(378);
    match(FaParser::QuotHuaL);
    setState(382);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(379);
        stmt(); 
      }
      setState(384);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
    setState(385);
    expr();
    setState(386);
    match(FaParser::QuotHuaR);
   
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
  enterRule(_localctx, 86, FaParser::RuleIfStmt);
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
    setState(388);
    match(FaParser::If);
    setState(389);
    expr();
    setState(390);
    quotStmtPart();
    setState(398);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(391);
        match(FaParser::Else);
        setState(392);
        match(FaParser::If);
        setState(393);
        expr();
        setState(394);
        quotStmtPart(); 
      }
      setState(400);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
    setState(403);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Else) {
      setState(401);
      match(FaParser::Else);
      setState(402);
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
  enterRule(_localctx, 88, FaParser::RuleIfExpr);

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
    setState(405);
    match(FaParser::If);
    setState(406);
    expr();
    setState(407);
    quotStmtExpr();
    setState(415);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(408);
        match(FaParser::Else);
        setState(409);
        match(FaParser::If);
        setState(410);
        expr();
        setState(411);
        quotStmtExpr(); 
      }
      setState(417);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
    setState(418);
    match(FaParser::Else);
    setState(419);
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

tree::TerminalNode* FaParser::WhileStmtContext::QuotHuaL() {
  return getToken(FaParser::QuotHuaL, 0);
}

tree::TerminalNode* FaParser::WhileStmtContext::QuotHuaR() {
  return getToken(FaParser::QuotHuaR, 0);
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
  enterRule(_localctx, 90, FaParser::RuleWhileStmt);
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
    setState(421);
    match(FaParser::While);
    setState(422);
    expr();
    setState(423);
    match(FaParser::QuotHuaL);
    setState(427);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Break)
      | (1ULL << FaParser::Continue)
      | (1ULL << FaParser::For)
      | (1ULL << FaParser::If)
      | (1ULL << FaParser::New)
      | (1ULL << FaParser::Return)
      | (1ULL << FaParser::While)
      | (1ULL << FaParser::ReverseOp)
      | (1ULL << FaParser::AddAddOp)
      | (1ULL << FaParser::SubSubOp)
      | (1ULL << FaParser::SubOp)
      | (1ULL << FaParser::ColonColon)
      | (1ULL << FaParser::Semi)
      | (1ULL << FaParser::QuotFangL)
      | (1ULL << FaParser::QuotYuanL)
      | (1ULL << FaParser::BoolLiteral)
      | (1ULL << FaParser::IntLiteral)
      | (1ULL << FaParser::FloatLiteral)
      | (1ULL << FaParser::String1Literal)
      | (1ULL << FaParser::Id))) != 0)) {
      setState(424);
      stmt();
      setState(429);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(430);
    match(FaParser::QuotHuaR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumIterStmtContext ------------------------------------------------------------------

FaParser::NumIterStmtContext::NumIterStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::NumIterStmtContext::For() {
  return getToken(FaParser::For, 0);
}

tree::TerminalNode* FaParser::NumIterStmtContext::Id() {
  return getToken(FaParser::Id, 0);
}

std::vector<tree::TerminalNode *> FaParser::NumIterStmtContext::Colon() {
  return getTokens(FaParser::Colon);
}

tree::TerminalNode* FaParser::NumIterStmtContext::Colon(size_t i) {
  return getToken(FaParser::Colon, i);
}

std::vector<FaParser::ExprOptContext *> FaParser::NumIterStmtContext::exprOpt() {
  return getRuleContexts<FaParser::ExprOptContext>();
}

FaParser::ExprOptContext* FaParser::NumIterStmtContext::exprOpt(size_t i) {
  return getRuleContext<FaParser::ExprOptContext>(i);
}

tree::TerminalNode* FaParser::NumIterStmtContext::QuotHuaL() {
  return getToken(FaParser::QuotHuaL, 0);
}

tree::TerminalNode* FaParser::NumIterStmtContext::QuotHuaR() {
  return getToken(FaParser::QuotHuaR, 0);
}

std::vector<FaParser::StmtContext *> FaParser::NumIterStmtContext::stmt() {
  return getRuleContexts<FaParser::StmtContext>();
}

FaParser::StmtContext* FaParser::NumIterStmtContext::stmt(size_t i) {
  return getRuleContext<FaParser::StmtContext>(i);
}


size_t FaParser::NumIterStmtContext::getRuleIndex() const {
  return FaParser::RuleNumIterStmt;
}


antlrcpp::Any FaParser::NumIterStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitNumIterStmt(this);
  else
    return visitor->visitChildren(this);
}

FaParser::NumIterStmtContext* FaParser::numIterStmt() {
  NumIterStmtContext *_localctx = _tracker.createInstance<NumIterStmtContext>(_ctx, getState());
  enterRule(_localctx, 92, FaParser::RuleNumIterStmt);
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
    match(FaParser::For);
    setState(433);
    match(FaParser::Id);
    setState(434);
    match(FaParser::Colon);
    setState(435);
    exprOpt();
    setState(438); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(436);
      match(FaParser::Colon);
      setState(437);
      exprOpt();
      setState(440); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == FaParser::Colon);
    setState(442);
    match(FaParser::QuotHuaL);
    setState(446);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Break)
      | (1ULL << FaParser::Continue)
      | (1ULL << FaParser::For)
      | (1ULL << FaParser::If)
      | (1ULL << FaParser::New)
      | (1ULL << FaParser::Return)
      | (1ULL << FaParser::While)
      | (1ULL << FaParser::ReverseOp)
      | (1ULL << FaParser::AddAddOp)
      | (1ULL << FaParser::SubSubOp)
      | (1ULL << FaParser::SubOp)
      | (1ULL << FaParser::ColonColon)
      | (1ULL << FaParser::Semi)
      | (1ULL << FaParser::QuotFangL)
      | (1ULL << FaParser::QuotYuanL)
      | (1ULL << FaParser::BoolLiteral)
      | (1ULL << FaParser::IntLiteral)
      | (1ULL << FaParser::FloatLiteral)
      | (1ULL << FaParser::String1Literal)
      | (1ULL << FaParser::Id))) != 0)) {
      setState(443);
      stmt();
      setState(448);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(449);
    match(FaParser::QuotHuaR);
   
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

tree::TerminalNode* FaParser::QuotExprContext::QuotYuanL() {
  return getToken(FaParser::QuotYuanL, 0);
}

FaParser::ExprContext* FaParser::QuotExprContext::expr() {
  return getRuleContext<FaParser::ExprContext>(0);
}

tree::TerminalNode* FaParser::QuotExprContext::QuotYuanR() {
  return getToken(FaParser::QuotYuanR, 0);
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
  enterRule(_localctx, 94, FaParser::RuleQuotExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(451);
    match(FaParser::QuotYuanL);
    setState(452);
    expr();
    setState(453);
    match(FaParser::QuotYuanR);
   
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
  enterRule(_localctx, 96, FaParser::RuleExprOpt);
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
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::If)
      | (1ULL << FaParser::New)
      | (1ULL << FaParser::ReverseOp)
      | (1ULL << FaParser::AddAddOp)
      | (1ULL << FaParser::SubSubOp)
      | (1ULL << FaParser::SubOp)
      | (1ULL << FaParser::ColonColon)
      | (1ULL << FaParser::QuotFangL)
      | (1ULL << FaParser::QuotYuanL)
      | (1ULL << FaParser::BoolLiteral)
      | (1ULL << FaParser::IntLiteral)
      | (1ULL << FaParser::FloatLiteral)
      | (1ULL << FaParser::String1Literal)
      | (1ULL << FaParser::Id))) != 0)) {
      setState(455);
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

tree::TerminalNode* FaParser::NewExprItemContext::Id() {
  return getToken(FaParser::Id, 0);
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
  enterRule(_localctx, 98, FaParser::RuleNewExprItem);
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
    setState(458);
    match(FaParser::Id);
    setState(461);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Assign) {
      setState(459);
      match(FaParser::Assign);
      setState(460);
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

//----------------- NewExprContext ------------------------------------------------------------------

FaParser::NewExprContext::NewExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::NewExprContext::New() {
  return getToken(FaParser::New, 0);
}

tree::TerminalNode* FaParser::NewExprContext::QuotHuaL() {
  return getToken(FaParser::QuotHuaL, 0);
}

tree::TerminalNode* FaParser::NewExprContext::QuotHuaR() {
  return getToken(FaParser::QuotHuaR, 0);
}

FaParser::IdsContext* FaParser::NewExprContext::ids() {
  return getRuleContext<FaParser::IdsContext>(0);
}

std::vector<FaParser::NewExprItemContext *> FaParser::NewExprContext::newExprItem() {
  return getRuleContexts<FaParser::NewExprItemContext>();
}

FaParser::NewExprItemContext* FaParser::NewExprContext::newExprItem(size_t i) {
  return getRuleContext<FaParser::NewExprItemContext>(i);
}

std::vector<tree::TerminalNode *> FaParser::NewExprContext::Comma() {
  return getTokens(FaParser::Comma);
}

tree::TerminalNode* FaParser::NewExprContext::Comma(size_t i) {
  return getToken(FaParser::Comma, i);
}


size_t FaParser::NewExprContext::getRuleIndex() const {
  return FaParser::RuleNewExpr;
}


antlrcpp::Any FaParser::NewExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitNewExpr(this);
  else
    return visitor->visitChildren(this);
}

FaParser::NewExprContext* FaParser::newExpr() {
  NewExprContext *_localctx = _tracker.createInstance<NewExprContext>(_ctx, getState());
  enterRule(_localctx, 100, FaParser::RuleNewExpr);
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
    setState(463);
    match(FaParser::New);
    setState(465);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Id) {
      setState(464);
      ids();
    }
    setState(467);
    match(FaParser::QuotHuaL);
    setState(476);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Id) {
      setState(468);
      newExprItem();
      setState(473);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FaParser::Comma) {
        setState(469);
        match(FaParser::Comma);
        setState(470);
        newExprItem();
        setState(475);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(478);
    match(FaParser::QuotHuaR);
   
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

tree::TerminalNode* FaParser::ArrayExpr1Context::QuotFangL() {
  return getToken(FaParser::QuotFangL, 0);
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

tree::TerminalNode* FaParser::ArrayExpr1Context::QuotFangR() {
  return getToken(FaParser::QuotFangR, 0);
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
  enterRule(_localctx, 102, FaParser::RuleArrayExpr1);
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
    setState(480);
    match(FaParser::QuotFangL);
    setState(481);
    expr();
    setState(482);
    match(FaParser::PointPoint);
    setState(483);
    expr();
    setState(486);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Step) {
      setState(484);
      match(FaParser::Step);
      setState(485);
      expr();
    }
    setState(488);
    match(FaParser::QuotFangR);
   
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

tree::TerminalNode* FaParser::ArrayExpr2Context::QuotFangL() {
  return getToken(FaParser::QuotFangL, 0);
}

std::vector<FaParser::ExprContext *> FaParser::ArrayExpr2Context::expr() {
  return getRuleContexts<FaParser::ExprContext>();
}

FaParser::ExprContext* FaParser::ArrayExpr2Context::expr(size_t i) {
  return getRuleContext<FaParser::ExprContext>(i);
}

tree::TerminalNode* FaParser::ArrayExpr2Context::QuotFangR() {
  return getToken(FaParser::QuotFangR, 0);
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
  enterRule(_localctx, 104, FaParser::RuleArrayExpr2);
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
    setState(490);
    match(FaParser::QuotFangL);
    setState(491);
    expr();
    setState(496);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(492);
      match(FaParser::Comma);
      setState(493);
      expr();
      setState(498);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(499);
    match(FaParser::QuotFangR);
   
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

tree::TerminalNode* FaParser::StrongExprBaseContext::Id() {
  return getToken(FaParser::Id, 0);
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

FaParser::NewExprContext* FaParser::StrongExprBaseContext::newExpr() {
  return getRuleContext<FaParser::NewExprContext>(0);
}

FaParser::ArrayExpr1Context* FaParser::StrongExprBaseContext::arrayExpr1() {
  return getRuleContext<FaParser::ArrayExpr1Context>(0);
}

FaParser::ArrayExpr2Context* FaParser::StrongExprBaseContext::arrayExpr2() {
  return getRuleContext<FaParser::ArrayExpr2Context>(0);
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
  enterRule(_localctx, 106, FaParser::RuleStrongExprBase);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(510);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(501);
      ids();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(502);
      match(FaParser::ColonColon);
      setState(503);
      match(FaParser::Id);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(504);
      literal();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(505);
      ifExpr();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(506);
      quotExpr();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(507);
      newExpr();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(508);
      arrayExpr1();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(509);
      arrayExpr2();
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
  enterRule(_localctx, 108, FaParser::RuleStrongExprPrefix);
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
    setState(512);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::ReverseOp)
      | (1ULL << FaParser::AddAddOp)
      | (1ULL << FaParser::SubSubOp)
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

tree::TerminalNode* FaParser::StrongExprSuffixContext::QuotYuanL() {
  return getToken(FaParser::QuotYuanL, 0);
}

tree::TerminalNode* FaParser::StrongExprSuffixContext::QuotYuanR() {
  return getToken(FaParser::QuotYuanR, 0);
}

std::vector<FaParser::ExprOptContext *> FaParser::StrongExprSuffixContext::exprOpt() {
  return getRuleContexts<FaParser::ExprOptContext>();
}

FaParser::ExprOptContext* FaParser::StrongExprSuffixContext::exprOpt(size_t i) {
  return getRuleContext<FaParser::ExprOptContext>(i);
}

std::vector<tree::TerminalNode *> FaParser::StrongExprSuffixContext::Comma() {
  return getTokens(FaParser::Comma);
}

tree::TerminalNode* FaParser::StrongExprSuffixContext::Comma(size_t i) {
  return getToken(FaParser::Comma, i);
}

tree::TerminalNode* FaParser::StrongExprSuffixContext::QuotFangL() {
  return getToken(FaParser::QuotFangL, 0);
}

tree::TerminalNode* FaParser::StrongExprSuffixContext::QuotFangR() {
  return getToken(FaParser::QuotFangR, 0);
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

tree::TerminalNode* FaParser::StrongExprSuffixContext::Id() {
  return getToken(FaParser::Id, 0);
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
  enterRule(_localctx, 110, FaParser::RuleStrongExprSuffix);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(540);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::AddAddOp: {
        enterOuterAlt(_localctx, 1);
        setState(514);
        match(FaParser::AddAddOp);
        break;
      }

      case FaParser::SubSubOp: {
        enterOuterAlt(_localctx, 2);
        setState(515);
        match(FaParser::SubSubOp);
        break;
      }

      case FaParser::QuotYuanL: {
        enterOuterAlt(_localctx, 3);
        setState(516);
        match(FaParser::QuotYuanL);

        setState(517);
        exprOpt();
        setState(522);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == FaParser::Comma) {
          setState(518);
          match(FaParser::Comma);
          setState(519);
          exprOpt();
          setState(524);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(525);
        match(FaParser::QuotYuanR);
        break;
      }

      case FaParser::QuotFangL: {
        enterOuterAlt(_localctx, 4);
        setState(527);
        match(FaParser::QuotFangL);

        setState(528);
        exprOpt();
        setState(533);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == FaParser::Colon) {
          setState(529);
          match(FaParser::Colon);
          setState(530);
          exprOpt();
          setState(535);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(536);
        match(FaParser::QuotFangR);
        break;
      }

      case FaParser::PointOp: {
        enterOuterAlt(_localctx, 5);
        setState(538);
        match(FaParser::PointOp);
        setState(539);
        match(FaParser::Id);
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
  enterRule(_localctx, 112, FaParser::RuleStrongExpr);
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
    setState(545);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(542);
        strongExprPrefix(); 
      }
      setState(547);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    }
    setState(548);
    strongExprBase();
    setState(552);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::AddAddOp)
      | (1ULL << FaParser::SubSubOp)
      | (1ULL << FaParser::PointOp)
      | (1ULL << FaParser::QuotFangL)
      | (1ULL << FaParser::QuotYuanL))) != 0)) {
      setState(549);
      strongExprSuffix();
      setState(554);
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
  enterRule(_localctx, 114, FaParser::RuleMiddleExpr);

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
    setState(555);
    strongExpr();
    setState(561);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(556);
        allOp2();
        setState(557);
        strongExpr(); 
      }
      setState(563);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
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
  enterRule(_localctx, 116, FaParser::RuleExpr);
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
    setState(564);
    middleExpr();
    setState(570);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Assign)
      | (1ULL << FaParser::AddOp)
      | (1ULL << FaParser::SubOp)
      | (1ULL << FaParser::StarOp)
      | (1ULL << FaParser::DivOp)
      | (1ULL << FaParser::ModOp)
      | (1ULL << FaParser::OrOp)
      | (1ULL << FaParser::AndOp)
      | (1ULL << FaParser::XorOp)
      | (1ULL << FaParser::Qus)
      | (1ULL << FaParser::QuotJianL)
      | (1ULL << FaParser::QuotJianR))) != 0)) {
      setState(565);
      allAssign();
      setState(566);
      middleExpr();
      setState(572);
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

//----------------- TmpAssignExprContext ------------------------------------------------------------------

FaParser::TmpAssignExprContext::TmpAssignExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::TmpAssignExprContext::Assign() {
  return getToken(FaParser::Assign, 0);
}

FaParser::ExprContext* FaParser::TmpAssignExprContext::expr() {
  return getRuleContext<FaParser::ExprContext>(0);
}

tree::TerminalNode* FaParser::TmpAssignExprContext::Semi() {
  return getToken(FaParser::Semi, 0);
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
  enterRule(_localctx, 118, FaParser::RuleTmpAssignExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(573);
    match(FaParser::Assign);
    setState(574);
    expr();
    setState(575);
    match(FaParser::Semi);
   
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

tree::TerminalNode* FaParser::DefVarStmtContext::Id() {
  return getToken(FaParser::Id, 0);
}

tree::TerminalNode* FaParser::DefVarStmtContext::Assign() {
  return getToken(FaParser::Assign, 0);
}

FaParser::ExprContext* FaParser::DefVarStmtContext::expr() {
  return getRuleContext<FaParser::ExprContext>(0);
}

tree::TerminalNode* FaParser::DefVarStmtContext::Semi() {
  return getToken(FaParser::Semi, 0);
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
  enterRule(_localctx, 120, FaParser::RuleDefVarStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(577);
    type();
    setState(578);
    match(FaParser::Id);
    setState(579);
    match(FaParser::Assign);
    setState(580);
    expr();
    setState(581);
    match(FaParser::Semi);
   
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
  enterRule(_localctx, 122, FaParser::RuleUseStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(583);
    match(FaParser::Use);
    setState(584);
    ids();
    setState(585);
    match(FaParser::Semi);
   
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

tree::TerminalNode* FaParser::NormalStmtContext::Semi() {
  return getToken(FaParser::Semi, 0);
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
  enterRule(_localctx, 124, FaParser::RuleNormalStmt);
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
    setState(595);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::If:
      case FaParser::New:
      case FaParser::Return:
      case FaParser::ReverseOp:
      case FaParser::AddAddOp:
      case FaParser::SubSubOp:
      case FaParser::SubOp:
      case FaParser::ColonColon:
      case FaParser::Semi:
      case FaParser::QuotFangL:
      case FaParser::QuotYuanL:
      case FaParser::BoolLiteral:
      case FaParser::IntLiteral:
      case FaParser::FloatLiteral:
      case FaParser::String1Literal:
      case FaParser::Id: {
        setState(588);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == FaParser::Return) {
          setState(587);
          match(FaParser::Return);
        }
        setState(591);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << FaParser::If)
          | (1ULL << FaParser::New)
          | (1ULL << FaParser::ReverseOp)
          | (1ULL << FaParser::AddAddOp)
          | (1ULL << FaParser::SubSubOp)
          | (1ULL << FaParser::SubOp)
          | (1ULL << FaParser::ColonColon)
          | (1ULL << FaParser::QuotFangL)
          | (1ULL << FaParser::QuotYuanL)
          | (1ULL << FaParser::BoolLiteral)
          | (1ULL << FaParser::IntLiteral)
          | (1ULL << FaParser::FloatLiteral)
          | (1ULL << FaParser::String1Literal)
          | (1ULL << FaParser::Id))) != 0)) {
          setState(590);
          expr();
        }
        break;
      }

      case FaParser::Break: {
        setState(593);
        match(FaParser::Break);
        break;
      }

      case FaParser::Continue: {
        setState(594);
        match(FaParser::Continue);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(597);
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

FaParser::NormalStmtContext* FaParser::StmtContext::normalStmt() {
  return getRuleContext<FaParser::NormalStmtContext>(0);
}

FaParser::IfStmtContext* FaParser::StmtContext::ifStmt() {
  return getRuleContext<FaParser::IfStmtContext>(0);
}

FaParser::DefVarStmtContext* FaParser::StmtContext::defVarStmt() {
  return getRuleContext<FaParser::DefVarStmtContext>(0);
}

FaParser::WhileStmtContext* FaParser::StmtContext::whileStmt() {
  return getRuleContext<FaParser::WhileStmtContext>(0);
}

FaParser::NumIterStmtContext* FaParser::StmtContext::numIterStmt() {
  return getRuleContext<FaParser::NumIterStmtContext>(0);
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
  enterRule(_localctx, 126, FaParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(604);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(599);
      normalStmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(600);
      ifStmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(601);
      defVarStmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(602);
      whileStmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(603);
      numIterStmt();
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
  enterRule(_localctx, 128, FaParser::RulePublicLevel);
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
  enterRule(_localctx, 130, FaParser::RuleClassParent);
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
    setState(608);
    match(FaParser::Colon);
    setState(609);
    ids();
    setState(614);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(610);
      match(FaParser::Comma);
      setState(611);
      ids();
      setState(616);
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

//----------------- ClassTypeContext ------------------------------------------------------------------

FaParser::ClassTypeContext::ClassTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::ClassTypeContext::Class() {
  return getToken(FaParser::Class, 0);
}

tree::TerminalNode* FaParser::ClassTypeContext::Struct() {
  return getToken(FaParser::Struct, 0);
}

tree::TerminalNode* FaParser::ClassTypeContext::Interface() {
  return getToken(FaParser::Interface, 0);
}

tree::TerminalNode* FaParser::ClassTypeContext::Enum() {
  return getToken(FaParser::Enum, 0);
}


size_t FaParser::ClassTypeContext::getRuleIndex() const {
  return FaParser::RuleClassType;
}


antlrcpp::Any FaParser::ClassTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitClassType(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ClassTypeContext* FaParser::classType() {
  ClassTypeContext *_localctx = _tracker.createInstance<ClassTypeContext>(_ctx, getState());
  enterRule(_localctx, 132, FaParser::RuleClassType);
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
    setState(617);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Class)
      | (1ULL << FaParser::Enum)
      | (1ULL << FaParser::Interface)
      | (1ULL << FaParser::Struct))) != 0))) {
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

//----------------- ClassStmtContext ------------------------------------------------------------------

FaParser::ClassStmtContext::ClassStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::ClassTypeContext* FaParser::ClassStmtContext::classType() {
  return getRuleContext<FaParser::ClassTypeContext>(0);
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

std::vector<FaParser::EnumAtomContext *> FaParser::ClassStmtContext::enumAtom() {
  return getRuleContexts<FaParser::EnumAtomContext>();
}

FaParser::EnumAtomContext* FaParser::ClassStmtContext::enumAtom(size_t i) {
  return getRuleContext<FaParser::EnumAtomContext>(i);
}

std::vector<FaParser::ClassVarContext *> FaParser::ClassStmtContext::classVar() {
  return getRuleContexts<FaParser::ClassVarContext>();
}

FaParser::ClassVarContext* FaParser::ClassStmtContext::classVar(size_t i) {
  return getRuleContext<FaParser::ClassVarContext>(i);
}

std::vector<FaParser::ClassFuncContext *> FaParser::ClassStmtContext::classFunc() {
  return getRuleContexts<FaParser::ClassFuncContext>();
}

FaParser::ClassFuncContext* FaParser::ClassStmtContext::classFunc(size_t i) {
  return getRuleContext<FaParser::ClassFuncContext>(i);
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
  enterRule(_localctx, 134, FaParser::RuleClassStmt);
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
    setState(620);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(619);
      publicLevel();
    }
    setState(622);
    classType();
    setState(623);
    match(FaParser::Id);
    setState(625);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Colon) {
      setState(624);
      classParent();
    }
    setState(627);
    match(FaParser::QuotHuaL);
    setState(631);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(628);
        enumAtom(); 
      }
      setState(633);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
    }
    setState(638);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private)
      | (1ULL << FaParser::Static)
      | (1ULL << FaParser::QuotYuanL)
      | (1ULL << FaParser::Id))) != 0)) {
      setState(636);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx)) {
      case 1: {
        setState(634);
        classVar();
        break;
      }

      case 2: {
        setState(635);
        classFunc();
        break;
      }

      default:
        break;
      }
      setState(640);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(641);
    match(FaParser::QuotHuaR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassVarExtFuncContext ------------------------------------------------------------------

FaParser::ClassVarExtFuncContext::ClassVarExtFuncContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::ClassVarExtFuncContext::Id() {
  return getToken(FaParser::Id, 0);
}

tree::TerminalNode* FaParser::ClassVarExtFuncContext::Semi() {
  return getToken(FaParser::Semi, 0);
}

FaParser::ClassFuncBodyContext* FaParser::ClassVarExtFuncContext::classFuncBody() {
  return getRuleContext<FaParser::ClassFuncBodyContext>(0);
}

FaParser::PublicLevelContext* FaParser::ClassVarExtFuncContext::publicLevel() {
  return getRuleContext<FaParser::PublicLevelContext>(0);
}


size_t FaParser::ClassVarExtFuncContext::getRuleIndex() const {
  return FaParser::RuleClassVarExtFunc;
}


antlrcpp::Any FaParser::ClassVarExtFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitClassVarExtFunc(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ClassVarExtFuncContext* FaParser::classVarExtFunc() {
  ClassVarExtFuncContext *_localctx = _tracker.createInstance<ClassVarExtFuncContext>(_ctx, getState());
  enterRule(_localctx, 136, FaParser::RuleClassVarExtFunc);
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
    setState(644);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(643);
      publicLevel();
    }
    setState(646);
    match(FaParser::Id);
    setState(649);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::Semi: {
        setState(647);
        match(FaParser::Semi);
        break;
      }

      case FaParser::Assign:
      case FaParser::QuotHuaL: {
        setState(648);
        classFuncBody();
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

//----------------- ClassVarExtContext ------------------------------------------------------------------

FaParser::ClassVarExtContext::ClassVarExtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::ClassVarExtContext::QuotHuaL() {
  return getToken(FaParser::QuotHuaL, 0);
}

tree::TerminalNode* FaParser::ClassVarExtContext::QuotHuaR() {
  return getToken(FaParser::QuotHuaR, 0);
}

std::vector<FaParser::ClassVarExtFuncContext *> FaParser::ClassVarExtContext::classVarExtFunc() {
  return getRuleContexts<FaParser::ClassVarExtFuncContext>();
}

FaParser::ClassVarExtFuncContext* FaParser::ClassVarExtContext::classVarExtFunc(size_t i) {
  return getRuleContext<FaParser::ClassVarExtFuncContext>(i);
}

FaParser::TmpAssignExprContext* FaParser::ClassVarExtContext::tmpAssignExpr() {
  return getRuleContext<FaParser::TmpAssignExprContext>(0);
}


size_t FaParser::ClassVarExtContext::getRuleIndex() const {
  return FaParser::RuleClassVarExt;
}


antlrcpp::Any FaParser::ClassVarExtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitClassVarExt(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ClassVarExtContext* FaParser::classVarExt() {
  ClassVarExtContext *_localctx = _tracker.createInstance<ClassVarExtContext>(_ctx, getState());
  enterRule(_localctx, 138, FaParser::RuleClassVarExt);
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
    setState(651);
    match(FaParser::QuotHuaL);
    setState(653); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(652);
      classVarExtFunc();
      setState(655); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private)
      | (1ULL << FaParser::Id))) != 0));
    setState(657);
    match(FaParser::QuotHuaR);
    setState(659);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Assign) {
      setState(658);
      tmpAssignExpr();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassVarContext ------------------------------------------------------------------

FaParser::ClassVarContext::ClassVarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::TypeContext* FaParser::ClassVarContext::type() {
  return getRuleContext<FaParser::TypeContext>(0);
}

tree::TerminalNode* FaParser::ClassVarContext::Id() {
  return getToken(FaParser::Id, 0);
}

tree::TerminalNode* FaParser::ClassVarContext::Semi() {
  return getToken(FaParser::Semi, 0);
}

FaParser::TmpAssignExprContext* FaParser::ClassVarContext::tmpAssignExpr() {
  return getRuleContext<FaParser::TmpAssignExprContext>(0);
}

FaParser::ClassVarExtContext* FaParser::ClassVarContext::classVarExt() {
  return getRuleContext<FaParser::ClassVarExtContext>(0);
}

FaParser::PublicLevelContext* FaParser::ClassVarContext::publicLevel() {
  return getRuleContext<FaParser::PublicLevelContext>(0);
}

tree::TerminalNode* FaParser::ClassVarContext::Static() {
  return getToken(FaParser::Static, 0);
}


size_t FaParser::ClassVarContext::getRuleIndex() const {
  return FaParser::RuleClassVar;
}


antlrcpp::Any FaParser::ClassVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitClassVar(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ClassVarContext* FaParser::classVar() {
  ClassVarContext *_localctx = _tracker.createInstance<ClassVarContext>(_ctx, getState());
  enterRule(_localctx, 140, FaParser::RuleClassVar);
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
    setState(662);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(661);
      publicLevel();
    }
    setState(665);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Static) {
      setState(664);
      match(FaParser::Static);
    }
    setState(667);
    type();
    setState(668);
    match(FaParser::Id);
    setState(672);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::Semi: {
        setState(669);
        match(FaParser::Semi);
        break;
      }

      case FaParser::Assign: {
        setState(670);
        tmpAssignExpr();
        break;
      }

      case FaParser::QuotHuaL: {
        setState(671);
        classVarExt();
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

//----------------- ClassFuncNameContext ------------------------------------------------------------------

FaParser::ClassFuncNameContext::ClassFuncNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::ClassFuncNameContext::Id() {
  return getToken(FaParser::Id, 0);
}

tree::TerminalNode* FaParser::ClassFuncNameContext::QuotFangL() {
  return getToken(FaParser::QuotFangL, 0);
}

tree::TerminalNode* FaParser::ClassFuncNameContext::QuotFangR() {
  return getToken(FaParser::QuotFangR, 0);
}

FaParser::AllOp2Context* FaParser::ClassFuncNameContext::allOp2() {
  return getRuleContext<FaParser::AllOp2Context>(0);
}

FaParser::AllAssignContext* FaParser::ClassFuncNameContext::allAssign() {
  return getRuleContext<FaParser::AllAssignContext>(0);
}


size_t FaParser::ClassFuncNameContext::getRuleIndex() const {
  return FaParser::RuleClassFuncName;
}


antlrcpp::Any FaParser::ClassFuncNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitClassFuncName(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ClassFuncNameContext* FaParser::classFuncName() {
  ClassFuncNameContext *_localctx = _tracker.createInstance<ClassFuncNameContext>(_ctx, getState());
  enterRule(_localctx, 142, FaParser::RuleClassFuncName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(679);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(674);
      match(FaParser::Id);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(675);
      match(FaParser::QuotFangL);
      setState(676);
      match(FaParser::QuotFangR);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(677);
      allOp2();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(678);
      allAssign();
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

//----------------- ClassFuncBodyContext ------------------------------------------------------------------

FaParser::ClassFuncBodyContext::ClassFuncBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::ExprFuncDefContext* FaParser::ClassFuncBodyContext::exprFuncDef() {
  return getRuleContext<FaParser::ExprFuncDefContext>(0);
}

FaParser::ExprContext* FaParser::ClassFuncBodyContext::expr() {
  return getRuleContext<FaParser::ExprContext>(0);
}

tree::TerminalNode* FaParser::ClassFuncBodyContext::Semi() {
  return getToken(FaParser::Semi, 0);
}

tree::TerminalNode* FaParser::ClassFuncBodyContext::QuotHuaL() {
  return getToken(FaParser::QuotHuaL, 0);
}

tree::TerminalNode* FaParser::ClassFuncBodyContext::QuotHuaR() {
  return getToken(FaParser::QuotHuaR, 0);
}

std::vector<FaParser::StmtContext *> FaParser::ClassFuncBodyContext::stmt() {
  return getRuleContexts<FaParser::StmtContext>();
}

FaParser::StmtContext* FaParser::ClassFuncBodyContext::stmt(size_t i) {
  return getRuleContext<FaParser::StmtContext>(i);
}


size_t FaParser::ClassFuncBodyContext::getRuleIndex() const {
  return FaParser::RuleClassFuncBody;
}


antlrcpp::Any FaParser::ClassFuncBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitClassFuncBody(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ClassFuncBodyContext* FaParser::classFuncBody() {
  ClassFuncBodyContext *_localctx = _tracker.createInstance<ClassFuncBodyContext>(_ctx, getState());
  enterRule(_localctx, 144, FaParser::RuleClassFuncBody);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(693);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::Assign: {
        enterOuterAlt(_localctx, 1);
        setState(681);
        exprFuncDef();
        setState(682);
        expr();
        setState(683);
        match(FaParser::Semi);
        break;
      }

      case FaParser::QuotHuaL: {
        enterOuterAlt(_localctx, 2);
        setState(685);
        match(FaParser::QuotHuaL);
        setState(689);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << FaParser::Break)
          | (1ULL << FaParser::Continue)
          | (1ULL << FaParser::For)
          | (1ULL << FaParser::If)
          | (1ULL << FaParser::New)
          | (1ULL << FaParser::Return)
          | (1ULL << FaParser::While)
          | (1ULL << FaParser::ReverseOp)
          | (1ULL << FaParser::AddAddOp)
          | (1ULL << FaParser::SubSubOp)
          | (1ULL << FaParser::SubOp)
          | (1ULL << FaParser::ColonColon)
          | (1ULL << FaParser::Semi)
          | (1ULL << FaParser::QuotFangL)
          | (1ULL << FaParser::QuotYuanL)
          | (1ULL << FaParser::BoolLiteral)
          | (1ULL << FaParser::IntLiteral)
          | (1ULL << FaParser::FloatLiteral)
          | (1ULL << FaParser::String1Literal)
          | (1ULL << FaParser::Id))) != 0)) {
          setState(686);
          stmt();
          setState(691);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(692);
        match(FaParser::QuotHuaR);
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

//----------------- ClassFuncContext ------------------------------------------------------------------

FaParser::ClassFuncContext::ClassFuncContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::TypeContext* FaParser::ClassFuncContext::type() {
  return getRuleContext<FaParser::TypeContext>(0);
}

FaParser::ClassFuncNameContext* FaParser::ClassFuncContext::classFuncName() {
  return getRuleContext<FaParser::ClassFuncNameContext>(0);
}

tree::TerminalNode* FaParser::ClassFuncContext::QuotYuanL() {
  return getToken(FaParser::QuotYuanL, 0);
}

tree::TerminalNode* FaParser::ClassFuncContext::QuotYuanR() {
  return getToken(FaParser::QuotYuanR, 0);
}

FaParser::ClassFuncBodyContext* FaParser::ClassFuncContext::classFuncBody() {
  return getRuleContext<FaParser::ClassFuncBodyContext>(0);
}

FaParser::PublicLevelContext* FaParser::ClassFuncContext::publicLevel() {
  return getRuleContext<FaParser::PublicLevelContext>(0);
}

tree::TerminalNode* FaParser::ClassFuncContext::Static() {
  return getToken(FaParser::Static, 0);
}

FaParser::TypeVarListContext* FaParser::ClassFuncContext::typeVarList() {
  return getRuleContext<FaParser::TypeVarListContext>(0);
}


size_t FaParser::ClassFuncContext::getRuleIndex() const {
  return FaParser::RuleClassFunc;
}


antlrcpp::Any FaParser::ClassFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitClassFunc(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ClassFuncContext* FaParser::classFunc() {
  ClassFuncContext *_localctx = _tracker.createInstance<ClassFuncContext>(_ctx, getState());
  enterRule(_localctx, 146, FaParser::RuleClassFunc);
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
    setState(696);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(695);
      publicLevel();
    }
    setState(699);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Static) {
      setState(698);
      match(FaParser::Static);
    }
    setState(701);
    type();
    setState(702);
    classFuncName();
    setState(703);
    match(FaParser::QuotYuanL);
    setState(705);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::QuotYuanL

    || _la == FaParser::Id) {
      setState(704);
      typeVarList();
    }
    setState(707);
    match(FaParser::QuotYuanR);
    setState(708);
    classFuncBody();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumAtomContext ------------------------------------------------------------------

FaParser::EnumAtomContext::EnumAtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::EnumAtomContext::Id() {
  return getToken(FaParser::Id, 0);
}

tree::TerminalNode* FaParser::EnumAtomContext::Comma() {
  return getToken(FaParser::Comma, 0);
}

FaParser::TypeContext* FaParser::EnumAtomContext::type() {
  return getRuleContext<FaParser::TypeContext>(0);
}


size_t FaParser::EnumAtomContext::getRuleIndex() const {
  return FaParser::RuleEnumAtom;
}


antlrcpp::Any FaParser::EnumAtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitEnumAtom(this);
  else
    return visitor->visitChildren(this);
}

FaParser::EnumAtomContext* FaParser::enumAtom() {
  EnumAtomContext *_localctx = _tracker.createInstance<EnumAtomContext>(_ctx, getState());
  enterRule(_localctx, 148, FaParser::RuleEnumAtom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(711);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx)) {
    case 1: {
      setState(710);
      type();
      break;
    }

    default:
      break;
    }
    setState(713);
    match(FaParser::Id);
    setState(714);
    match(FaParser::Comma);
   
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
  enterRule(_localctx, 150, FaParser::RuleCallConvention);
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
    setState(716);
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

tree::TerminalNode* FaParser::ImportStmtContext::Id() {
  return getToken(FaParser::Id, 0);
}

tree::TerminalNode* FaParser::ImportStmtContext::QuotYuanL() {
  return getToken(FaParser::QuotYuanL, 0);
}

FaParser::TypeVarListContext* FaParser::ImportStmtContext::typeVarList() {
  return getRuleContext<FaParser::TypeVarListContext>(0);
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
  enterRule(_localctx, 152, FaParser::RuleImportStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(718);
    match(FaParser::AImport);
    setState(719);
    type();
    setState(720);
    callConvention();
    setState(721);
    match(FaParser::Id);
    setState(722);
    match(FaParser::QuotYuanL);
    setState(723);
    typeVarList();
    setState(724);
    match(FaParser::QuotYuanR);
    setState(725);
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
  enterRule(_localctx, 154, FaParser::RuleLibStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(727);
    match(FaParser::ALib);
    setState(728);
    match(FaParser::String1Literal);
    setState(729);
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
  enterRule(_localctx, 156, FaParser::RuleImportBlock);
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
    setState(733); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(733);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case FaParser::AImport: {
          setState(731);
          importStmt();
          break;
        }

        case FaParser::ALib: {
          setState(732);
          libStmt();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(735); 
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

//----------------- FaMainFuncBlockContext ------------------------------------------------------------------

FaParser::FaMainFuncBlockContext::FaMainFuncBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::TypeContext* FaParser::FaMainFuncBlockContext::type() {
  return getRuleContext<FaParser::TypeContext>(0);
}

tree::TerminalNode* FaParser::FaMainFuncBlockContext::FaMain() {
  return getToken(FaParser::FaMain, 0);
}

tree::TerminalNode* FaParser::FaMainFuncBlockContext::QuotYuanL() {
  return getToken(FaParser::QuotYuanL, 0);
}

tree::TerminalNode* FaParser::FaMainFuncBlockContext::QuotYuanR() {
  return getToken(FaParser::QuotYuanR, 0);
}

tree::TerminalNode* FaParser::FaMainFuncBlockContext::QuotHuaL() {
  return getToken(FaParser::QuotHuaL, 0);
}

tree::TerminalNode* FaParser::FaMainFuncBlockContext::QuotHuaR() {
  return getToken(FaParser::QuotHuaR, 0);
}

std::vector<FaParser::StmtContext *> FaParser::FaMainFuncBlockContext::stmt() {
  return getRuleContexts<FaParser::StmtContext>();
}

FaParser::StmtContext* FaParser::FaMainFuncBlockContext::stmt(size_t i) {
  return getRuleContext<FaParser::StmtContext>(i);
}


size_t FaParser::FaMainFuncBlockContext::getRuleIndex() const {
  return FaParser::RuleFaMainFuncBlock;
}


antlrcpp::Any FaParser::FaMainFuncBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitFaMainFuncBlock(this);
  else
    return visitor->visitChildren(this);
}

FaParser::FaMainFuncBlockContext* FaParser::faMainFuncBlock() {
  FaMainFuncBlockContext *_localctx = _tracker.createInstance<FaMainFuncBlockContext>(_ctx, getState());
  enterRule(_localctx, 158, FaParser::RuleFaMainFuncBlock);
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
    setState(737);
    type();
    setState(738);
    match(FaParser::FaMain);
    setState(739);
    match(FaParser::QuotYuanL);
    setState(740);
    match(FaParser::QuotYuanR);
    setState(741);
    match(FaParser::QuotHuaL);
    setState(745);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Break)
      | (1ULL << FaParser::Continue)
      | (1ULL << FaParser::For)
      | (1ULL << FaParser::If)
      | (1ULL << FaParser::New)
      | (1ULL << FaParser::Return)
      | (1ULL << FaParser::While)
      | (1ULL << FaParser::ReverseOp)
      | (1ULL << FaParser::AddAddOp)
      | (1ULL << FaParser::SubSubOp)
      | (1ULL << FaParser::SubOp)
      | (1ULL << FaParser::ColonColon)
      | (1ULL << FaParser::Semi)
      | (1ULL << FaParser::QuotFangL)
      | (1ULL << FaParser::QuotYuanL)
      | (1ULL << FaParser::BoolLiteral)
      | (1ULL << FaParser::IntLiteral)
      | (1ULL << FaParser::FloatLiteral)
      | (1ULL << FaParser::String1Literal)
      | (1ULL << FaParser::Id))) != 0)) {
      setState(742);
      stmt();
      setState(747);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(748);
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

std::vector<FaParser::ClassStmtContext *> FaParser::ProgramContext::classStmt() {
  return getRuleContexts<FaParser::ClassStmtContext>();
}

FaParser::ClassStmtContext* FaParser::ProgramContext::classStmt(size_t i) {
  return getRuleContext<FaParser::ClassStmtContext>(i);
}

FaParser::FaMainFuncBlockContext* FaParser::ProgramContext::faMainFuncBlock() {
  return getRuleContext<FaParser::FaMainFuncBlockContext>(0);
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
  enterRule(_localctx, 160, FaParser::RuleProgram);
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
    setState(753);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Use) {
      setState(750);
      useStmt();
      setState(755);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(757);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::AImport

    || _la == FaParser::ALib) {
      setState(756);
      importBlock();
    }
    setState(762);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Class)
      | (1ULL << FaParser::Enum)
      | (1ULL << FaParser::Interface)
      | (1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private)
      | (1ULL << FaParser::Struct))) != 0)) {
      setState(759);
      classStmt();
      setState(764);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(766);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::QuotYuanL

    || _la == FaParser::Id) {
      setState(765);
      faMainFuncBlock();
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
  "addAssign", "subAssign", "starAssign", "divAssign", "modAssign", "orAssign", 
  "andAssign", "xorAssign", "qusQusAssign", "starStarAssign", "andAndAssign", 
  "orOrAssign", "shiftLAssign", "shiftRAssign", "allAssign", "qusQusOp", 
  "starStarOp", "andAndOp", "orOrOp", "shiftLOp", "shiftROp", "ltOp", "ltEqualOp", 
  "gtOp", "gtEqualOp", "equalOp", "notEqualOp", "exprFuncDef", "selfOp2", 
  "compareOp2", "changeOp2", "allOp2", "intNum", "floatNum", "literal", 
  "ids", "typeAfter", "type", "typeNewable", "typeVar", "typeVarList", "quotStmtPart", 
  "quotStmtExpr", "ifStmt", "ifExpr", "whileStmt", "numIterStmt", "quotExpr", 
  "exprOpt", "newExprItem", "newExpr", "arrayExpr1", "arrayExpr2", "strongExprBase", 
  "strongExprPrefix", "strongExprSuffix", "strongExpr", "middleExpr", "expr", 
  "tmpAssignExpr", "defVarStmt", "useStmt", "normalStmt", "stmt", "publicLevel", 
  "classParent", "classType", "classStmt", "classVarExtFunc", "classVarExt", 
  "classVar", "classFuncName", "classFuncBody", "classFunc", "enumAtom", 
  "callConvention", "importStmt", "libStmt", "importBlock", "faMainFuncBlock", 
  "program"
};

std::vector<std::string> FaParser::_literalNames = {
  "", "'@import'", "'@lib'", "'break'", "'__cdecl'", "'__fastcall'", "'__stdcall'", 
  "'continue'", "'class'", "'const'", "'else'", "'enum'", "'FaMain'", "'for'", 
  "'if'", "'interface'", "'internal'", "'new'", "'public'", "'protected'", 
  "'private'", "'return'", "'signed'", "'static'", "'step'", "'struct'", 
  "'unsigned'", "'use'", "'while'", "'='", "'~'", "'++'", "'--'", "'..'", 
  "'.'", "'+'", "'-'", "'*'", "'/'", "'%'", "'|'", "'&'", "'^'", "'\u003F'", 
  "','", "'::'", "':'", "';'", "'!'", "'['", "']'", "'<'", "'>'", "'{'", 
  "'}'", "'('", "')'"
};

std::vector<std::string> FaParser::_symbolicNames = {
  "", "AImport", "ALib", "Break", "CC__Cdecl", "CC__FastCall", "CC__StdCall", 
  "Continue", "Class", "Const", "Else", "Enum", "FaMain", "For", "If", "Interface", 
  "Internal", "New", "Public", "Protected", "Private", "Return", "Signed", 
  "Static", "Step", "Struct", "Unsigned", "Use", "While", "Assign", "ReverseOp", 
  "AddAddOp", "SubSubOp", "PointPoint", "PointOp", "AddOp", "SubOp", "StarOp", 
  "DivOp", "ModOp", "OrOp", "AndOp", "XorOp", "Qus", "Comma", "ColonColon", 
  "Colon", "Semi", "Exclam", "QuotFangL", "QuotFangR", "QuotJianL", "QuotJianR", 
  "QuotHuaL", "QuotHuaR", "QuotYuanL", "QuotYuanR", "BoolLiteral", "IntLiteral", 
  "FloatLiteral", "String1Literal", "Id", "Comment1", "Comment2", "WS"
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
       0x3, 0x42, 0x303, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
       0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x3, 0x2, 
       0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 
       0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 
       0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
       0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
       0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 
       0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
       0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
       0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xde, 
       0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 
       0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 
       0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 
       0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
       0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 
       0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 
       0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
       0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
       0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x112, 0xa, 0x1e, 0x3, 
       0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 
       0x1f, 0x11a, 0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x11e, 0xa, 
       0x20, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x122, 0xa, 0x21, 0x3, 0x22, 
       0x5, 0x22, 0x125, 0xa, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x5, 
       0x23, 0x12a, 0xa, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 
       0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x132, 0xa, 0x24, 0x3, 0x25, 0x3, 
       0x25, 0x3, 0x25, 0x7, 0x25, 0x137, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 
       0x13a, 0xb, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 
       0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x7, 0x26, 0x144, 0xa, 0x26, 
       0xc, 0x26, 0xe, 0x26, 0x147, 0xb, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 
       0x26, 0x5, 0x26, 0x14c, 0xa, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
       0x3, 0x27, 0x3, 0x27, 0x6, 0x27, 0x153, 0xa, 0x27, 0xd, 0x27, 0xe, 
       0x27, 0x154, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x159, 0xa, 0x27, 0x3, 
       0x27, 0x7, 0x27, 0x15c, 0xa, 0x27, 0xc, 0x27, 0xe, 0x27, 0x15f, 0xb, 
       0x27, 0x3, 0x28, 0x3, 0x28, 0x7, 0x28, 0x163, 0xa, 0x28, 0xc, 0x28, 
       0xe, 0x28, 0x166, 0xb, 0x28, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x16a, 
       0xa, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x7, 0x2a, 0x16f, 0xa, 
       0x2a, 0xc, 0x2a, 0xe, 0x2a, 0x172, 0xb, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 
       0x7, 0x2b, 0x176, 0xa, 0x2b, 0xc, 0x2b, 0xe, 0x2b, 0x179, 0xb, 0x2b, 
       0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x7, 0x2c, 0x17f, 0xa, 
       0x2c, 0xc, 0x2c, 0xe, 0x2c, 0x182, 0xb, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 
       0x3, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
       0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x7, 0x2d, 0x18f, 0xa, 0x2d, 0xc, 
       0x2d, 0xe, 0x2d, 0x192, 0xb, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 
       0x196, 0xa, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 
       0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x7, 0x2e, 0x1a0, 0xa, 0x2e, 
       0xc, 0x2e, 0xe, 0x2e, 0x1a3, 0xb, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 
       0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x7, 0x2f, 0x1ac, 
       0xa, 0x2f, 0xc, 0x2f, 0xe, 0x2f, 0x1af, 0xb, 0x2f, 0x3, 0x2f, 0x3, 
       0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 
       0x30, 0x6, 0x30, 0x1b9, 0xa, 0x30, 0xd, 0x30, 0xe, 0x30, 0x1ba, 0x3, 
       0x30, 0x3, 0x30, 0x7, 0x30, 0x1bf, 0xa, 0x30, 0xc, 0x30, 0xe, 0x30, 
       0x1c2, 0xb, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 
       0x31, 0x3, 0x31, 0x3, 0x32, 0x5, 0x32, 0x1cb, 0xa, 0x32, 0x3, 0x33, 
       0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x1d0, 0xa, 0x33, 0x3, 0x34, 0x3, 
       0x34, 0x5, 0x34, 0x1d4, 0xa, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 
       0x3, 0x34, 0x7, 0x34, 0x1da, 0xa, 0x34, 0xc, 0x34, 0xe, 0x34, 0x1dd, 
       0xb, 0x34, 0x5, 0x34, 0x1df, 0xa, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 
       0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x5, 
       0x35, 0x1e9, 0xa, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x36, 0x3, 0x36, 
       0x3, 0x36, 0x3, 0x36, 0x7, 0x36, 0x1f1, 0xa, 0x36, 0xc, 0x36, 0xe, 
       0x36, 0x1f4, 0xb, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 0x3, 0x37, 
       0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 
       0x3, 0x37, 0x5, 0x37, 0x201, 0xa, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 
       0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x7, 
       0x39, 0x20b, 0xa, 0x39, 0xc, 0x39, 0xe, 0x39, 0x20e, 0xb, 0x39, 0x3, 
       0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x7, 
       0x39, 0x216, 0xa, 0x39, 0xc, 0x39, 0xe, 0x39, 0x219, 0xb, 0x39, 0x3, 
       0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x5, 0x39, 0x21f, 0xa, 0x39, 
       0x3, 0x3a, 0x7, 0x3a, 0x222, 0xa, 0x3a, 0xc, 0x3a, 0xe, 0x3a, 0x225, 
       0xb, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x7, 0x3a, 0x229, 0xa, 0x3a, 0xc, 
       0x3a, 0xe, 0x3a, 0x22c, 0xb, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 
       0x3, 0x3b, 0x7, 0x3b, 0x232, 0xa, 0x3b, 0xc, 0x3b, 0xe, 0x3b, 0x235, 
       0xb, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x7, 0x3c, 
       0x23b, 0xa, 0x3c, 0xc, 0x3c, 0xe, 0x3c, 0x23e, 0xb, 0x3c, 0x3, 0x3d, 
       0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 
       0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 
       0x3, 0x3f, 0x3, 0x40, 0x5, 0x40, 0x24f, 0xa, 0x40, 0x3, 0x40, 0x5, 
       0x40, 0x252, 0xa, 0x40, 0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 0x256, 0xa, 
       0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 
       0x41, 0x3, 0x41, 0x5, 0x41, 0x25f, 0xa, 0x41, 0x3, 0x42, 0x3, 0x42, 
       0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x7, 0x43, 0x267, 0xa, 
       0x43, 0xc, 0x43, 0xe, 0x43, 0x26a, 0xb, 0x43, 0x3, 0x44, 0x3, 0x44, 
       0x3, 0x45, 0x5, 0x45, 0x26f, 0xa, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 
       0x45, 0x5, 0x45, 0x274, 0xa, 0x45, 0x3, 0x45, 0x3, 0x45, 0x7, 0x45, 
       0x278, 0xa, 0x45, 0xc, 0x45, 0xe, 0x45, 0x27b, 0xb, 0x45, 0x3, 0x45, 
       0x3, 0x45, 0x7, 0x45, 0x27f, 0xa, 0x45, 0xc, 0x45, 0xe, 0x45, 0x282, 
       0xb, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x46, 0x5, 0x46, 0x287, 0xa, 
       0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x5, 0x46, 0x28c, 0xa, 0x46, 
       0x3, 0x47, 0x3, 0x47, 0x6, 0x47, 0x290, 0xa, 0x47, 0xd, 0x47, 0xe, 
       0x47, 0x291, 0x3, 0x47, 0x3, 0x47, 0x5, 0x47, 0x296, 0xa, 0x47, 0x3, 
       0x48, 0x5, 0x48, 0x299, 0xa, 0x48, 0x3, 0x48, 0x5, 0x48, 0x29c, 0xa, 
       0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x5, 
       0x48, 0x2a3, 0xa, 0x48, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 
       0x3, 0x49, 0x5, 0x49, 0x2aa, 0xa, 0x49, 0x3, 0x4a, 0x3, 0x4a, 0x3, 
       0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x7, 0x4a, 0x2b2, 0xa, 0x4a, 
       0xc, 0x4a, 0xe, 0x4a, 0x2b5, 0xb, 0x4a, 0x3, 0x4a, 0x5, 0x4a, 0x2b8, 
       0xa, 0x4a, 0x3, 0x4b, 0x5, 0x4b, 0x2bb, 0xa, 0x4b, 0x3, 0x4b, 0x5, 
       0x4b, 0x2be, 0xa, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 
       0x5, 0x4b, 0x2c4, 0xa, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 
       0x4c, 0x5, 0x4c, 0x2ca, 0xa, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 
       0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 
       0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4f, 
       0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x50, 0x3, 0x50, 0x6, 0x50, 
       0x2e0, 0xa, 0x50, 0xd, 0x50, 0xe, 0x50, 0x2e1, 0x3, 0x51, 0x3, 0x51, 
       0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x7, 0x51, 0x2ea, 0xa, 
       0x51, 0xc, 0x51, 0xe, 0x51, 0x2ed, 0xb, 0x51, 0x3, 0x51, 0x3, 0x51, 
       0x3, 0x52, 0x7, 0x52, 0x2f2, 0xa, 0x52, 0xc, 0x52, 0xe, 0x52, 0x2f5, 
       0xb, 0x52, 0x3, 0x52, 0x5, 0x52, 0x2f8, 0xa, 0x52, 0x3, 0x52, 0x7, 
       0x52, 0x2fb, 0xa, 0x52, 0xc, 0x52, 0xe, 0x52, 0x2fe, 0xb, 0x52, 0x3, 
       0x52, 0x5, 0x52, 0x301, 0xa, 0x52, 0x3, 0x52, 0x2, 0x2, 0x53, 0x2, 
       0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
       0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 
       0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 
       0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 
       0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 
       0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 
       0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e, 
       0xa0, 0xa2, 0x2, 0x6, 0x4, 0x2, 0x20, 0x22, 0x26, 0x26, 0x4, 0x2, 
       0x12, 0x12, 0x14, 0x16, 0x6, 0x2, 0xa, 0xa, 0xd, 0xd, 0x11, 0x11, 
       0x1b, 0x1b, 0x3, 0x2, 0x6, 0x8, 0x2, 0x329, 0x2, 0xa4, 0x3, 0x2, 
       0x2, 0x2, 0x4, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x6, 0xaa, 0x3, 0x2, 0x2, 
       0x2, 0x8, 0xad, 0x3, 0x2, 0x2, 0x2, 0xa, 0xb0, 0x3, 0x2, 0x2, 0x2, 
       0xc, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xe, 0xb6, 0x3, 0x2, 0x2, 0x2, 0x10, 
       0xb9, 0x3, 0x2, 0x2, 0x2, 0x12, 0xbc, 0x3, 0x2, 0x2, 0x2, 0x14, 0xbf, 
       0x3, 0x2, 0x2, 0x2, 0x16, 0xc2, 0x3, 0x2, 0x2, 0x2, 0x18, 0xc5, 0x3, 
       0x2, 0x2, 0x2, 0x1a, 0xc8, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xcb, 0x3, 0x2, 
       0x2, 0x2, 0x1e, 0xdd, 0x3, 0x2, 0x2, 0x2, 0x20, 0xdf, 0x3, 0x2, 0x2, 
       0x2, 0x22, 0xe2, 0x3, 0x2, 0x2, 0x2, 0x24, 0xe5, 0x3, 0x2, 0x2, 0x2, 
       0x26, 0xe8, 0x3, 0x2, 0x2, 0x2, 0x28, 0xeb, 0x3, 0x2, 0x2, 0x2, 0x2a, 
       0xee, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xf1, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xf3, 
       0x3, 0x2, 0x2, 0x2, 0x30, 0xf6, 0x3, 0x2, 0x2, 0x2, 0x32, 0xf8, 0x3, 
       0x2, 0x2, 0x2, 0x34, 0xfb, 0x3, 0x2, 0x2, 0x2, 0x36, 0xfe, 0x3, 0x2, 
       0x2, 0x2, 0x38, 0x101, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x111, 0x3, 0x2, 
       0x2, 0x2, 0x3c, 0x119, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x11d, 0x3, 0x2, 
       0x2, 0x2, 0x40, 0x121, 0x3, 0x2, 0x2, 0x2, 0x42, 0x124, 0x3, 0x2, 
       0x2, 0x2, 0x44, 0x129, 0x3, 0x2, 0x2, 0x2, 0x46, 0x131, 0x3, 0x2, 
       0x2, 0x2, 0x48, 0x133, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x14b, 0x3, 0x2, 
       0x2, 0x2, 0x4c, 0x158, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x160, 0x3, 0x2, 
       0x2, 0x2, 0x50, 0x167, 0x3, 0x2, 0x2, 0x2, 0x52, 0x16b, 0x3, 0x2, 
       0x2, 0x2, 0x54, 0x173, 0x3, 0x2, 0x2, 0x2, 0x56, 0x17c, 0x3, 0x2, 
       0x2, 0x2, 0x58, 0x186, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x197, 0x3, 0x2, 
       0x2, 0x2, 0x5c, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x1b2, 0x3, 0x2, 
       0x2, 0x2, 0x60, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x62, 0x1ca, 0x3, 0x2, 
       0x2, 0x2, 0x64, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x66, 0x1d1, 0x3, 0x2, 
       0x2, 0x2, 0x68, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x1ec, 0x3, 0x2, 
       0x2, 0x2, 0x6c, 0x200, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x202, 0x3, 0x2, 
       0x2, 0x2, 0x70, 0x21e, 0x3, 0x2, 0x2, 0x2, 0x72, 0x223, 0x3, 0x2, 
       0x2, 0x2, 0x74, 0x22d, 0x3, 0x2, 0x2, 0x2, 0x76, 0x236, 0x3, 0x2, 
       0x2, 0x2, 0x78, 0x23f, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x243, 0x3, 0x2, 
       0x2, 0x2, 0x7c, 0x249, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x255, 0x3, 0x2, 
       0x2, 0x2, 0x80, 0x25e, 0x3, 0x2, 0x2, 0x2, 0x82, 0x260, 0x3, 0x2, 
       0x2, 0x2, 0x84, 0x262, 0x3, 0x2, 0x2, 0x2, 0x86, 0x26b, 0x3, 0x2, 
       0x2, 0x2, 0x88, 0x26e, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x286, 0x3, 0x2, 
       0x2, 0x2, 0x8c, 0x28d, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x298, 0x3, 0x2, 
       0x2, 0x2, 0x90, 0x2a9, 0x3, 0x2, 0x2, 0x2, 0x92, 0x2b7, 0x3, 0x2, 
       0x2, 0x2, 0x94, 0x2ba, 0x3, 0x2, 0x2, 0x2, 0x96, 0x2c9, 0x3, 0x2, 
       0x2, 0x2, 0x98, 0x2ce, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x2d0, 0x3, 0x2, 
       0x2, 0x2, 0x9c, 0x2d9, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x2df, 0x3, 0x2, 
       0x2, 0x2, 0xa0, 0x2e3, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x2f3, 0x3, 0x2, 
       0x2, 0x2, 0xa4, 0xa5, 0x7, 0x25, 0x2, 0x2, 0xa5, 0xa6, 0x7, 0x1f, 
       0x2, 0x2, 0xa6, 0x3, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x7, 0x26, 0x2, 
       0x2, 0xa8, 0xa9, 0x7, 0x1f, 0x2, 0x2, 0xa9, 0x5, 0x3, 0x2, 0x2, 0x2, 
       0xaa, 0xab, 0x7, 0x27, 0x2, 0x2, 0xab, 0xac, 0x7, 0x1f, 0x2, 0x2, 
       0xac, 0x7, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x7, 0x28, 0x2, 0x2, 0xae, 
       0xaf, 0x7, 0x1f, 0x2, 0x2, 0xaf, 0x9, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 
       0x7, 0x29, 0x2, 0x2, 0xb1, 0xb2, 0x7, 0x1f, 0x2, 0x2, 0xb2, 0xb, 
       0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 0x7, 0x2a, 0x2, 0x2, 0xb4, 0xb5, 
       0x7, 0x1f, 0x2, 0x2, 0xb5, 0xd, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0x7, 
       0x2b, 0x2, 0x2, 0xb7, 0xb8, 0x7, 0x1f, 0x2, 0x2, 0xb8, 0xf, 0x3, 
       0x2, 0x2, 0x2, 0xb9, 0xba, 0x7, 0x2c, 0x2, 0x2, 0xba, 0xbb, 0x7, 
       0x1f, 0x2, 0x2, 0xbb, 0x11, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x5, 
       0x20, 0x11, 0x2, 0xbd, 0xbe, 0x7, 0x1f, 0x2, 0x2, 0xbe, 0x13, 0x3, 
       0x2, 0x2, 0x2, 0xbf, 0xc0, 0x5, 0x22, 0x12, 0x2, 0xc0, 0xc1, 0x7, 
       0x1f, 0x2, 0x2, 0xc1, 0x15, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x5, 
       0x24, 0x13, 0x2, 0xc3, 0xc4, 0x7, 0x1f, 0x2, 0x2, 0xc4, 0x17, 0x3, 
       0x2, 0x2, 0x2, 0xc5, 0xc6, 0x5, 0x26, 0x14, 0x2, 0xc6, 0xc7, 0x7, 
       0x1f, 0x2, 0x2, 0xc7, 0x19, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0x5, 
       0x28, 0x15, 0x2, 0xc9, 0xca, 0x7, 0x1f, 0x2, 0x2, 0xca, 0x1b, 0x3, 
       0x2, 0x2, 0x2, 0xcb, 0xcc, 0x5, 0x2a, 0x16, 0x2, 0xcc, 0xcd, 0x7, 
       0x1f, 0x2, 0x2, 0xcd, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xce, 0xde, 0x7, 
       0x1f, 0x2, 0x2, 0xcf, 0xde, 0x5, 0x12, 0xa, 0x2, 0xd0, 0xde, 0x5, 
       0x2, 0x2, 0x2, 0xd1, 0xde, 0x5, 0x4, 0x3, 0x2, 0xd2, 0xde, 0x5, 0x6, 
       0x4, 0x2, 0xd3, 0xde, 0x5, 0x14, 0xb, 0x2, 0xd4, 0xde, 0x5, 0x8, 
       0x5, 0x2, 0xd5, 0xde, 0x5, 0xa, 0x6, 0x2, 0xd6, 0xde, 0x5, 0xe, 0x8, 
       0x2, 0xd7, 0xde, 0x5, 0xc, 0x7, 0x2, 0xd8, 0xde, 0x5, 0x10, 0x9, 
       0x2, 0xd9, 0xde, 0x5, 0x16, 0xc, 0x2, 0xda, 0xde, 0x5, 0x18, 0xd, 
       0x2, 0xdb, 0xde, 0x5, 0x1a, 0xe, 0x2, 0xdc, 0xde, 0x5, 0x1c, 0xf, 
       0x2, 0xdd, 0xce, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xcf, 0x3, 0x2, 0x2, 0x2, 
       0xdd, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xdd, 
       0xd2, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xd4, 
       0x3, 0x2, 0x2, 0x2, 0xdd, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xd6, 0x3, 
       0x2, 0x2, 0x2, 0xdd, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xd8, 0x3, 0x2, 
       0x2, 0x2, 0xdd, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xda, 0x3, 0x2, 0x2, 
       0x2, 0xdd, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdc, 0x3, 0x2, 0x2, 0x2, 
       0xde, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe0, 0x7, 0x2d, 0x2, 0x2, 
       0xe0, 0xe1, 0x7, 0x2d, 0x2, 0x2, 0xe1, 0x21, 0x3, 0x2, 0x2, 0x2, 
       0xe2, 0xe3, 0x7, 0x27, 0x2, 0x2, 0xe3, 0xe4, 0x7, 0x27, 0x2, 0x2, 
       0xe4, 0x23, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe6, 0x7, 0x2b, 0x2, 0x2, 
       0xe6, 0xe7, 0x7, 0x2b, 0x2, 0x2, 0xe7, 0x25, 0x3, 0x2, 0x2, 0x2, 
       0xe8, 0xe9, 0x7, 0x2a, 0x2, 0x2, 0xe9, 0xea, 0x7, 0x2a, 0x2, 0x2, 
       0xea, 0x27, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xec, 0x7, 0x35, 0x2, 0x2, 
       0xec, 0xed, 0x7, 0x35, 0x2, 0x2, 0xed, 0x29, 0x3, 0x2, 0x2, 0x2, 
       0xee, 0xef, 0x7, 0x36, 0x2, 0x2, 0xef, 0xf0, 0x7, 0x36, 0x2, 0x2, 
       0xf0, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf2, 0x7, 0x35, 0x2, 0x2, 
       0xf2, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 0x7, 0x35, 0x2, 0x2, 
       0xf4, 0xf5, 0x7, 0x1f, 0x2, 0x2, 0xf5, 0x2f, 0x3, 0x2, 0x2, 0x2, 
       0xf6, 0xf7, 0x7, 0x36, 0x2, 0x2, 0xf7, 0x31, 0x3, 0x2, 0x2, 0x2, 
       0xf8, 0xf9, 0x7, 0x36, 0x2, 0x2, 0xf9, 0xfa, 0x7, 0x1f, 0x2, 0x2, 
       0xfa, 0x33, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 0x7, 0x1f, 0x2, 0x2, 
       0xfc, 0xfd, 0x7, 0x1f, 0x2, 0x2, 0xfd, 0x35, 0x3, 0x2, 0x2, 0x2, 
       0xfe, 0xff, 0x7, 0x32, 0x2, 0x2, 0xff, 0x100, 0x7, 0x1f, 0x2, 0x2, 
       0x100, 0x37, 0x3, 0x2, 0x2, 0x2, 0x101, 0x102, 0x7, 0x1f, 0x2, 0x2, 
       0x102, 0x103, 0x7, 0x36, 0x2, 0x2, 0x103, 0x39, 0x3, 0x2, 0x2, 0x2, 
       0x104, 0x112, 0x7, 0x25, 0x2, 0x2, 0x105, 0x112, 0x7, 0x26, 0x2, 
       0x2, 0x106, 0x112, 0x7, 0x27, 0x2, 0x2, 0x107, 0x112, 0x7, 0x28, 
       0x2, 0x2, 0x108, 0x112, 0x5, 0x22, 0x12, 0x2, 0x109, 0x112, 0x7, 
       0x29, 0x2, 0x2, 0x10a, 0x112, 0x7, 0x2b, 0x2, 0x2, 0x10b, 0x112, 
       0x7, 0x2a, 0x2, 0x2, 0x10c, 0x112, 0x7, 0x2c, 0x2, 0x2, 0x10d, 0x112, 
       0x5, 0x24, 0x13, 0x2, 0x10e, 0x112, 0x5, 0x26, 0x14, 0x2, 0x10f, 
       0x112, 0x5, 0x28, 0x15, 0x2, 0x110, 0x112, 0x5, 0x2a, 0x16, 0x2, 
       0x111, 0x104, 0x3, 0x2, 0x2, 0x2, 0x111, 0x105, 0x3, 0x2, 0x2, 0x2, 
       0x111, 0x106, 0x3, 0x2, 0x2, 0x2, 0x111, 0x107, 0x3, 0x2, 0x2, 0x2, 
       0x111, 0x108, 0x3, 0x2, 0x2, 0x2, 0x111, 0x109, 0x3, 0x2, 0x2, 0x2, 
       0x111, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x111, 0x10b, 0x3, 0x2, 0x2, 0x2, 
       0x111, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x111, 0x10d, 0x3, 0x2, 0x2, 0x2, 
       0x111, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x111, 0x10f, 0x3, 0x2, 0x2, 0x2, 
       0x111, 0x110, 0x3, 0x2, 0x2, 0x2, 0x112, 0x3b, 0x3, 0x2, 0x2, 0x2, 
       0x113, 0x11a, 0x5, 0x2c, 0x17, 0x2, 0x114, 0x11a, 0x5, 0x2e, 0x18, 
       0x2, 0x115, 0x11a, 0x5, 0x30, 0x19, 0x2, 0x116, 0x11a, 0x5, 0x32, 
       0x1a, 0x2, 0x117, 0x11a, 0x5, 0x34, 0x1b, 0x2, 0x118, 0x11a, 0x5, 
       0x36, 0x1c, 0x2, 0x119, 0x113, 0x3, 0x2, 0x2, 0x2, 0x119, 0x114, 
       0x3, 0x2, 0x2, 0x2, 0x119, 0x115, 0x3, 0x2, 0x2, 0x2, 0x119, 0x116, 
       0x3, 0x2, 0x2, 0x2, 0x119, 0x117, 0x3, 0x2, 0x2, 0x2, 0x119, 0x118, 
       0x3, 0x2, 0x2, 0x2, 0x11a, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11e, 
       0x5, 0x20, 0x11, 0x2, 0x11c, 0x11e, 0x5, 0x3c, 0x1f, 0x2, 0x11d, 
       0x11b, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11e, 
       0x3f, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x122, 0x5, 0x3a, 0x1e, 0x2, 0x120, 
       0x122, 0x5, 0x3e, 0x20, 0x2, 0x121, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x121, 
       0x120, 0x3, 0x2, 0x2, 0x2, 0x122, 0x41, 0x3, 0x2, 0x2, 0x2, 0x123, 
       0x125, 0x7, 0x26, 0x2, 0x2, 0x124, 0x123, 0x3, 0x2, 0x2, 0x2, 0x124, 
       0x125, 0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 0x3, 0x2, 0x2, 0x2, 0x126, 
       0x127, 0x7, 0x3c, 0x2, 0x2, 0x127, 0x43, 0x3, 0x2, 0x2, 0x2, 0x128, 
       0x12a, 0x7, 0x26, 0x2, 0x2, 0x129, 0x128, 0x3, 0x2, 0x2, 0x2, 0x129, 
       0x12a, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12b, 
       0x12c, 0x7, 0x3d, 0x2, 0x2, 0x12c, 0x45, 0x3, 0x2, 0x2, 0x2, 0x12d, 
       0x132, 0x7, 0x3b, 0x2, 0x2, 0x12e, 0x132, 0x5, 0x42, 0x22, 0x2, 0x12f, 
       0x132, 0x5, 0x44, 0x23, 0x2, 0x130, 0x132, 0x7, 0x3e, 0x2, 0x2, 0x131, 
       0x12d, 0x3, 0x2, 0x2, 0x2, 0x131, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x131, 
       0x12f, 0x3, 0x2, 0x2, 0x2, 0x131, 0x130, 0x3, 0x2, 0x2, 0x2, 0x132, 
       0x47, 0x3, 0x2, 0x2, 0x2, 0x133, 0x138, 0x7, 0x3f, 0x2, 0x2, 0x134, 
       0x135, 0x7, 0x24, 0x2, 0x2, 0x135, 0x137, 0x7, 0x3f, 0x2, 0x2, 0x136, 
       0x134, 0x3, 0x2, 0x2, 0x2, 0x137, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x138, 
       0x136, 0x3, 0x2, 0x2, 0x2, 0x138, 0x139, 0x3, 0x2, 0x2, 0x2, 0x139, 
       0x49, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x138, 0x3, 0x2, 0x2, 0x2, 0x13b, 
       0x13c, 0x7, 0x33, 0x2, 0x2, 0x13c, 0x14c, 0x7, 0x34, 0x2, 0x2, 0x13d, 
       0x14c, 0x7, 0x2b, 0x2, 0x2, 0x13e, 0x14c, 0x7, 0x2d, 0x2, 0x2, 0x13f, 
       0x140, 0x7, 0x35, 0x2, 0x2, 0x140, 0x145, 0x5, 0x4c, 0x27, 0x2, 0x141, 
       0x142, 0x7, 0x2e, 0x2, 0x2, 0x142, 0x144, 0x5, 0x4c, 0x27, 0x2, 0x143, 
       0x141, 0x3, 0x2, 0x2, 0x2, 0x144, 0x147, 0x3, 0x2, 0x2, 0x2, 0x145, 
       0x143, 0x3, 0x2, 0x2, 0x2, 0x145, 0x146, 0x3, 0x2, 0x2, 0x2, 0x146, 
       0x148, 0x3, 0x2, 0x2, 0x2, 0x147, 0x145, 0x3, 0x2, 0x2, 0x2, 0x148, 
       0x149, 0x7, 0x36, 0x2, 0x2, 0x149, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x14a, 
       0x14c, 0x7, 0x27, 0x2, 0x2, 0x14b, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x14b, 
       0x13d, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x14b, 
       0x13f, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14c, 
       0x4b, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x159, 0x7, 0x3f, 0x2, 0x2, 0x14e, 
       0x14f, 0x7, 0x39, 0x2, 0x2, 0x14f, 0x152, 0x5, 0x4c, 0x27, 0x2, 0x150, 
       0x151, 0x7, 0x2e, 0x2, 0x2, 0x151, 0x153, 0x5, 0x4c, 0x27, 0x2, 0x152, 
       0x150, 0x3, 0x2, 0x2, 0x2, 0x153, 0x154, 0x3, 0x2, 0x2, 0x2, 0x154, 
       0x152, 0x3, 0x2, 0x2, 0x2, 0x154, 0x155, 0x3, 0x2, 0x2, 0x2, 0x155, 
       0x156, 0x3, 0x2, 0x2, 0x2, 0x156, 0x157, 0x7, 0x3a, 0x2, 0x2, 0x157, 
       0x159, 0x3, 0x2, 0x2, 0x2, 0x158, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x158, 
       0x14e, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x15a, 
       0x15c, 0x5, 0x4a, 0x26, 0x2, 0x15b, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x15c, 
       0x15f, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x15d, 
       0x15e, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x15f, 
       0x15d, 0x3, 0x2, 0x2, 0x2, 0x160, 0x164, 0x7, 0x3f, 0x2, 0x2, 0x161, 
       0x163, 0x5, 0x4a, 0x26, 0x2, 0x162, 0x161, 0x3, 0x2, 0x2, 0x2, 0x163, 
       0x166, 0x3, 0x2, 0x2, 0x2, 0x164, 0x162, 0x3, 0x2, 0x2, 0x2, 0x164, 
       0x165, 0x3, 0x2, 0x2, 0x2, 0x165, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x166, 
       0x164, 0x3, 0x2, 0x2, 0x2, 0x167, 0x169, 0x5, 0x4c, 0x27, 0x2, 0x168, 
       0x16a, 0x7, 0x3f, 0x2, 0x2, 0x169, 0x168, 0x3, 0x2, 0x2, 0x2, 0x169, 
       0x16a, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x51, 0x3, 0x2, 0x2, 0x2, 0x16b, 
       0x170, 0x5, 0x50, 0x29, 0x2, 0x16c, 0x16d, 0x7, 0x2e, 0x2, 0x2, 0x16d, 
       0x16f, 0x5, 0x50, 0x29, 0x2, 0x16e, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x16f, 
       0x172, 0x3, 0x2, 0x2, 0x2, 0x170, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x170, 
       0x171, 0x3, 0x2, 0x2, 0x2, 0x171, 0x53, 0x3, 0x2, 0x2, 0x2, 0x172, 
       0x170, 0x3, 0x2, 0x2, 0x2, 0x173, 0x177, 0x7, 0x37, 0x2, 0x2, 0x174, 
       0x176, 0x5, 0x80, 0x41, 0x2, 0x175, 0x174, 0x3, 0x2, 0x2, 0x2, 0x176, 
       0x179, 0x3, 0x2, 0x2, 0x2, 0x177, 0x175, 0x3, 0x2, 0x2, 0x2, 0x177, 
       0x178, 0x3, 0x2, 0x2, 0x2, 0x178, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x179, 
       0x177, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x17b, 0x7, 0x38, 0x2, 0x2, 0x17b, 
       0x55, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x180, 0x7, 0x37, 0x2, 0x2, 0x17d, 
       0x17f, 0x5, 0x80, 0x41, 0x2, 0x17e, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x17f, 
       0x182, 0x3, 0x2, 0x2, 0x2, 0x180, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x180, 
       0x181, 0x3, 0x2, 0x2, 0x2, 0x181, 0x183, 0x3, 0x2, 0x2, 0x2, 0x182, 
       0x180, 0x3, 0x2, 0x2, 0x2, 0x183, 0x184, 0x5, 0x76, 0x3c, 0x2, 0x184, 
       0x185, 0x7, 0x38, 0x2, 0x2, 0x185, 0x57, 0x3, 0x2, 0x2, 0x2, 0x186, 
       0x187, 0x7, 0x10, 0x2, 0x2, 0x187, 0x188, 0x5, 0x76, 0x3c, 0x2, 0x188, 
       0x190, 0x5, 0x54, 0x2b, 0x2, 0x189, 0x18a, 0x7, 0xc, 0x2, 0x2, 0x18a, 
       0x18b, 0x7, 0x10, 0x2, 0x2, 0x18b, 0x18c, 0x5, 0x76, 0x3c, 0x2, 0x18c, 
       0x18d, 0x5, 0x54, 0x2b, 0x2, 0x18d, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x18e, 
       0x189, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x192, 0x3, 0x2, 0x2, 0x2, 0x190, 
       0x18e, 0x3, 0x2, 0x2, 0x2, 0x190, 0x191, 0x3, 0x2, 0x2, 0x2, 0x191, 
       0x195, 0x3, 0x2, 0x2, 0x2, 0x192, 0x190, 0x3, 0x2, 0x2, 0x2, 0x193, 
       0x194, 0x7, 0xc, 0x2, 0x2, 0x194, 0x196, 0x5, 0x54, 0x2b, 0x2, 0x195, 
       0x193, 0x3, 0x2, 0x2, 0x2, 0x195, 0x196, 0x3, 0x2, 0x2, 0x2, 0x196, 
       0x59, 0x3, 0x2, 0x2, 0x2, 0x197, 0x198, 0x7, 0x10, 0x2, 0x2, 0x198, 
       0x199, 0x5, 0x76, 0x3c, 0x2, 0x199, 0x1a1, 0x5, 0x56, 0x2c, 0x2, 
       0x19a, 0x19b, 0x7, 0xc, 0x2, 0x2, 0x19b, 0x19c, 0x7, 0x10, 0x2, 0x2, 
       0x19c, 0x19d, 0x5, 0x76, 0x3c, 0x2, 0x19d, 0x19e, 0x5, 0x56, 0x2c, 
       0x2, 0x19e, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x19a, 0x3, 0x2, 0x2, 
       0x2, 0x1a0, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x19f, 0x3, 0x2, 0x2, 
       0x2, 0x1a1, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a4, 0x3, 0x2, 0x2, 
       0x2, 0x1a3, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a5, 0x7, 0xc, 0x2, 
       0x2, 0x1a5, 0x1a6, 0x5, 0x56, 0x2c, 0x2, 0x1a6, 0x5b, 0x3, 0x2, 0x2, 
       0x2, 0x1a7, 0x1a8, 0x7, 0x1e, 0x2, 0x2, 0x1a8, 0x1a9, 0x5, 0x76, 
       0x3c, 0x2, 0x1a9, 0x1ad, 0x7, 0x37, 0x2, 0x2, 0x1aa, 0x1ac, 0x5, 
       0x80, 0x41, 0x2, 0x1ab, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1af, 
       0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1ae, 
       0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x1ad, 
       0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1b1, 0x7, 0x38, 0x2, 0x2, 0x1b1, 0x5d, 
       0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b3, 0x7, 0xf, 0x2, 0x2, 0x1b3, 0x1b4, 
       0x7, 0x3f, 0x2, 0x2, 0x1b4, 0x1b5, 0x7, 0x30, 0x2, 0x2, 0x1b5, 0x1b8, 
       0x5, 0x62, 0x32, 0x2, 0x1b6, 0x1b7, 0x7, 0x30, 0x2, 0x2, 0x1b7, 0x1b9, 
       0x5, 0x62, 0x32, 0x2, 0x1b8, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1ba, 
       0x3, 0x2, 0x2, 0x2, 0x1ba, 0x1b8, 0x3, 0x2, 0x2, 0x2, 0x1ba, 0x1bb, 
       0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1bc, 0x1c0, 
       0x7, 0x37, 0x2, 0x2, 0x1bd, 0x1bf, 0x5, 0x80, 0x41, 0x2, 0x1be, 0x1bd, 
       0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c0, 0x1be, 
       0x3, 0x2, 0x2, 0x2, 0x1c0, 0x1c1, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1c3, 
       0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c4, 
       0x7, 0x38, 0x2, 0x2, 0x1c4, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c6, 
       0x7, 0x39, 0x2, 0x2, 0x1c6, 0x1c7, 0x5, 0x76, 0x3c, 0x2, 0x1c7, 0x1c8, 
       0x7, 0x3a, 0x2, 0x2, 0x1c8, 0x61, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1cb, 
       0x5, 0x76, 0x3c, 0x2, 0x1ca, 0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1cb, 
       0x3, 0x2, 0x2, 0x2, 0x1cb, 0x63, 0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1cf, 
       0x7, 0x3f, 0x2, 0x2, 0x1cd, 0x1ce, 0x7, 0x1f, 0x2, 0x2, 0x1ce, 0x1d0, 
       0x5, 0x74, 0x3b, 0x2, 0x1cf, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1d0, 
       0x3, 0x2, 0x2, 0x2, 0x1d0, 0x65, 0x3, 0x2, 0x2, 0x2, 0x1d1, 0x1d3, 
       0x7, 0x13, 0x2, 0x2, 0x1d2, 0x1d4, 0x5, 0x48, 0x25, 0x2, 0x1d3, 0x1d2, 
       0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d5, 
       0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1de, 0x7, 0x37, 0x2, 0x2, 0x1d6, 0x1db, 
       0x5, 0x64, 0x33, 0x2, 0x1d7, 0x1d8, 0x7, 0x2e, 0x2, 0x2, 0x1d8, 0x1da, 
       0x5, 0x64, 0x33, 0x2, 0x1d9, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x1dd, 
       0x3, 0x2, 0x2, 0x2, 0x1db, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1db, 0x1dc, 
       0x3, 0x2, 0x2, 0x2, 0x1dc, 0x1df, 0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1db, 
       0x3, 0x2, 0x2, 0x2, 0x1de, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x1df, 
       0x3, 0x2, 0x2, 0x2, 0x1df, 0x1e0, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1e1, 
       0x7, 0x38, 0x2, 0x2, 0x1e1, 0x67, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1e3, 
       0x7, 0x33, 0x2, 0x2, 0x1e3, 0x1e4, 0x5, 0x76, 0x3c, 0x2, 0x1e4, 0x1e5, 
       0x7, 0x23, 0x2, 0x2, 0x1e5, 0x1e8, 0x5, 0x76, 0x3c, 0x2, 0x1e6, 0x1e7, 
       0x7, 0x1a, 0x2, 0x2, 0x1e7, 0x1e9, 0x5, 0x76, 0x3c, 0x2, 0x1e8, 0x1e6, 
       0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1e9, 0x3, 0x2, 0x2, 0x2, 0x1e9, 0x1ea, 
       0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1eb, 0x7, 0x34, 0x2, 0x2, 0x1eb, 0x69, 
       0x3, 0x2, 0x2, 0x2, 0x1ec, 0x1ed, 0x7, 0x33, 0x2, 0x2, 0x1ed, 0x1f2, 
       0x5, 0x76, 0x3c, 0x2, 0x1ee, 0x1ef, 0x7, 0x2e, 0x2, 0x2, 0x1ef, 0x1f1, 
       0x5, 0x76, 0x3c, 0x2, 0x1f0, 0x1ee, 0x3, 0x2, 0x2, 0x2, 0x1f1, 0x1f4, 
       0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1f3, 
       0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1f2, 
       0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f6, 0x7, 0x34, 0x2, 0x2, 0x1f6, 0x6b, 
       0x3, 0x2, 0x2, 0x2, 0x1f7, 0x201, 0x5, 0x48, 0x25, 0x2, 0x1f8, 0x1f9, 
       0x7, 0x2f, 0x2, 0x2, 0x1f9, 0x201, 0x7, 0x3f, 0x2, 0x2, 0x1fa, 0x201, 
       0x5, 0x46, 0x24, 0x2, 0x1fb, 0x201, 0x5, 0x5a, 0x2e, 0x2, 0x1fc, 
       0x201, 0x5, 0x60, 0x31, 0x2, 0x1fd, 0x201, 0x5, 0x66, 0x34, 0x2, 
       0x1fe, 0x201, 0x5, 0x68, 0x35, 0x2, 0x1ff, 0x201, 0x5, 0x6a, 0x36, 
       0x2, 0x200, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x200, 0x1f8, 0x3, 0x2, 0x2, 
       0x2, 0x200, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x200, 0x1fb, 0x3, 0x2, 0x2, 
       0x2, 0x200, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x200, 0x1fd, 0x3, 0x2, 0x2, 
       0x2, 0x200, 0x1fe, 0x3, 0x2, 0x2, 0x2, 0x200, 0x1ff, 0x3, 0x2, 0x2, 
       0x2, 0x201, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x202, 0x203, 0x9, 0x2, 0x2, 
       0x2, 0x203, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x204, 0x21f, 0x7, 0x21, 0x2, 
       0x2, 0x205, 0x21f, 0x7, 0x22, 0x2, 0x2, 0x206, 0x207, 0x7, 0x39, 
       0x2, 0x2, 0x207, 0x20c, 0x5, 0x62, 0x32, 0x2, 0x208, 0x209, 0x7, 
       0x2e, 0x2, 0x2, 0x209, 0x20b, 0x5, 0x62, 0x32, 0x2, 0x20a, 0x208, 
       0x3, 0x2, 0x2, 0x2, 0x20b, 0x20e, 0x3, 0x2, 0x2, 0x2, 0x20c, 0x20a, 
       0x3, 0x2, 0x2, 0x2, 0x20c, 0x20d, 0x3, 0x2, 0x2, 0x2, 0x20d, 0x20f, 
       0x3, 0x2, 0x2, 0x2, 0x20e, 0x20c, 0x3, 0x2, 0x2, 0x2, 0x20f, 0x210, 
       0x7, 0x3a, 0x2, 0x2, 0x210, 0x21f, 0x3, 0x2, 0x2, 0x2, 0x211, 0x212, 
       0x7, 0x33, 0x2, 0x2, 0x212, 0x217, 0x5, 0x62, 0x32, 0x2, 0x213, 0x214, 
       0x7, 0x30, 0x2, 0x2, 0x214, 0x216, 0x5, 0x62, 0x32, 0x2, 0x215, 0x213, 
       0x3, 0x2, 0x2, 0x2, 0x216, 0x219, 0x3, 0x2, 0x2, 0x2, 0x217, 0x215, 
       0x3, 0x2, 0x2, 0x2, 0x217, 0x218, 0x3, 0x2, 0x2, 0x2, 0x218, 0x21a, 
       0x3, 0x2, 0x2, 0x2, 0x219, 0x217, 0x3, 0x2, 0x2, 0x2, 0x21a, 0x21b, 
       0x7, 0x34, 0x2, 0x2, 0x21b, 0x21f, 0x3, 0x2, 0x2, 0x2, 0x21c, 0x21d, 
       0x7, 0x24, 0x2, 0x2, 0x21d, 0x21f, 0x7, 0x3f, 0x2, 0x2, 0x21e, 0x204, 
       0x3, 0x2, 0x2, 0x2, 0x21e, 0x205, 0x3, 0x2, 0x2, 0x2, 0x21e, 0x206, 
       0x3, 0x2, 0x2, 0x2, 0x21e, 0x211, 0x3, 0x2, 0x2, 0x2, 0x21e, 0x21c, 
       0x3, 0x2, 0x2, 0x2, 0x21f, 0x71, 0x3, 0x2, 0x2, 0x2, 0x220, 0x222, 
       0x5, 0x6e, 0x38, 0x2, 0x221, 0x220, 0x3, 0x2, 0x2, 0x2, 0x222, 0x225, 
       0x3, 0x2, 0x2, 0x2, 0x223, 0x221, 0x3, 0x2, 0x2, 0x2, 0x223, 0x224, 
       0x3, 0x2, 0x2, 0x2, 0x224, 0x226, 0x3, 0x2, 0x2, 0x2, 0x225, 0x223, 
       0x3, 0x2, 0x2, 0x2, 0x226, 0x22a, 0x5, 0x6c, 0x37, 0x2, 0x227, 0x229, 
       0x5, 0x70, 0x39, 0x2, 0x228, 0x227, 0x3, 0x2, 0x2, 0x2, 0x229, 0x22c, 
       0x3, 0x2, 0x2, 0x2, 0x22a, 0x228, 0x3, 0x2, 0x2, 0x2, 0x22a, 0x22b, 
       0x3, 0x2, 0x2, 0x2, 0x22b, 0x73, 0x3, 0x2, 0x2, 0x2, 0x22c, 0x22a, 
       0x3, 0x2, 0x2, 0x2, 0x22d, 0x233, 0x5, 0x72, 0x3a, 0x2, 0x22e, 0x22f, 
       0x5, 0x40, 0x21, 0x2, 0x22f, 0x230, 0x5, 0x72, 0x3a, 0x2, 0x230, 
       0x232, 0x3, 0x2, 0x2, 0x2, 0x231, 0x22e, 0x3, 0x2, 0x2, 0x2, 0x232, 
       0x235, 0x3, 0x2, 0x2, 0x2, 0x233, 0x231, 0x3, 0x2, 0x2, 0x2, 0x233, 
       0x234, 0x3, 0x2, 0x2, 0x2, 0x234, 0x75, 0x3, 0x2, 0x2, 0x2, 0x235, 
       0x233, 0x3, 0x2, 0x2, 0x2, 0x236, 0x23c, 0x5, 0x74, 0x3b, 0x2, 0x237, 
       0x238, 0x5, 0x1e, 0x10, 0x2, 0x238, 0x239, 0x5, 0x74, 0x3b, 0x2, 
       0x239, 0x23b, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x237, 0x3, 0x2, 0x2, 0x2, 
       0x23b, 0x23e, 0x3, 0x2, 0x2, 0x2, 0x23c, 0x23a, 0x3, 0x2, 0x2, 0x2, 
       0x23c, 0x23d, 0x3, 0x2, 0x2, 0x2, 0x23d, 0x77, 0x3, 0x2, 0x2, 0x2, 
       0x23e, 0x23c, 0x3, 0x2, 0x2, 0x2, 0x23f, 0x240, 0x7, 0x1f, 0x2, 0x2, 
       0x240, 0x241, 0x5, 0x76, 0x3c, 0x2, 0x241, 0x242, 0x7, 0x31, 0x2, 
       0x2, 0x242, 0x79, 0x3, 0x2, 0x2, 0x2, 0x243, 0x244, 0x5, 0x4c, 0x27, 
       0x2, 0x244, 0x245, 0x7, 0x3f, 0x2, 0x2, 0x245, 0x246, 0x7, 0x1f, 
       0x2, 0x2, 0x246, 0x247, 0x5, 0x76, 0x3c, 0x2, 0x247, 0x248, 0x7, 
       0x31, 0x2, 0x2, 0x248, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x249, 0x24a, 0x7, 
       0x1d, 0x2, 0x2, 0x24a, 0x24b, 0x5, 0x48, 0x25, 0x2, 0x24b, 0x24c, 
       0x7, 0x31, 0x2, 0x2, 0x24c, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x24d, 0x24f, 
       0x7, 0x17, 0x2, 0x2, 0x24e, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x24e, 0x24f, 
       0x3, 0x2, 0x2, 0x2, 0x24f, 0x251, 0x3, 0x2, 0x2, 0x2, 0x250, 0x252, 
       0x5, 0x76, 0x3c, 0x2, 0x251, 0x250, 0x3, 0x2, 0x2, 0x2, 0x251, 0x252, 
       0x3, 0x2, 0x2, 0x2, 0x252, 0x256, 0x3, 0x2, 0x2, 0x2, 0x253, 0x256, 
       0x7, 0x5, 0x2, 0x2, 0x254, 0x256, 0x7, 0x9, 0x2, 0x2, 0x255, 0x24e, 
       0x3, 0x2, 0x2, 0x2, 0x255, 0x253, 0x3, 0x2, 0x2, 0x2, 0x255, 0x254, 
       0x3, 0x2, 0x2, 0x2, 0x256, 0x257, 0x3, 0x2, 0x2, 0x2, 0x257, 0x258, 
       0x7, 0x31, 0x2, 0x2, 0x258, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x259, 0x25f, 
       0x5, 0x7e, 0x40, 0x2, 0x25a, 0x25f, 0x5, 0x58, 0x2d, 0x2, 0x25b, 
       0x25f, 0x5, 0x7a, 0x3e, 0x2, 0x25c, 0x25f, 0x5, 0x5c, 0x2f, 0x2, 
       0x25d, 0x25f, 0x5, 0x5e, 0x30, 0x2, 0x25e, 0x259, 0x3, 0x2, 0x2, 
       0x2, 0x25e, 0x25a, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x25b, 0x3, 0x2, 0x2, 
       0x2, 0x25e, 0x25c, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x25d, 0x3, 0x2, 0x2, 
       0x2, 0x25f, 0x81, 0x3, 0x2, 0x2, 0x2, 0x260, 0x261, 0x9, 0x3, 0x2, 
       0x2, 0x261, 0x83, 0x3, 0x2, 0x2, 0x2, 0x262, 0x263, 0x7, 0x30, 0x2, 
       0x2, 0x263, 0x268, 0x5, 0x48, 0x25, 0x2, 0x264, 0x265, 0x7, 0x2e, 
       0x2, 0x2, 0x265, 0x267, 0x5, 0x48, 0x25, 0x2, 0x266, 0x264, 0x3, 
       0x2, 0x2, 0x2, 0x267, 0x26a, 0x3, 0x2, 0x2, 0x2, 0x268, 0x266, 0x3, 
       0x2, 0x2, 0x2, 0x268, 0x269, 0x3, 0x2, 0x2, 0x2, 0x269, 0x85, 0x3, 
       0x2, 0x2, 0x2, 0x26a, 0x268, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x26c, 0x9, 
       0x4, 0x2, 0x2, 0x26c, 0x87, 0x3, 0x2, 0x2, 0x2, 0x26d, 0x26f, 0x5, 
       0x82, 0x42, 0x2, 0x26e, 0x26d, 0x3, 0x2, 0x2, 0x2, 0x26e, 0x26f, 
       0x3, 0x2, 0x2, 0x2, 0x26f, 0x270, 0x3, 0x2, 0x2, 0x2, 0x270, 0x271, 
       0x5, 0x86, 0x44, 0x2, 0x271, 0x273, 0x7, 0x3f, 0x2, 0x2, 0x272, 0x274, 
       0x5, 0x84, 0x43, 0x2, 0x273, 0x272, 0x3, 0x2, 0x2, 0x2, 0x273, 0x274, 
       0x3, 0x2, 0x2, 0x2, 0x274, 0x275, 0x3, 0x2, 0x2, 0x2, 0x275, 0x279, 
       0x7, 0x37, 0x2, 0x2, 0x276, 0x278, 0x5, 0x96, 0x4c, 0x2, 0x277, 0x276, 
       0x3, 0x2, 0x2, 0x2, 0x278, 0x27b, 0x3, 0x2, 0x2, 0x2, 0x279, 0x277, 
       0x3, 0x2, 0x2, 0x2, 0x279, 0x27a, 0x3, 0x2, 0x2, 0x2, 0x27a, 0x280, 
       0x3, 0x2, 0x2, 0x2, 0x27b, 0x279, 0x3, 0x2, 0x2, 0x2, 0x27c, 0x27f, 
       0x5, 0x8e, 0x48, 0x2, 0x27d, 0x27f, 0x5, 0x94, 0x4b, 0x2, 0x27e, 
       0x27c, 0x3, 0x2, 0x2, 0x2, 0x27e, 0x27d, 0x3, 0x2, 0x2, 0x2, 0x27f, 
       0x282, 0x3, 0x2, 0x2, 0x2, 0x280, 0x27e, 0x3, 0x2, 0x2, 0x2, 0x280, 
       0x281, 0x3, 0x2, 0x2, 0x2, 0x281, 0x283, 0x3, 0x2, 0x2, 0x2, 0x282, 
       0x280, 0x3, 0x2, 0x2, 0x2, 0x283, 0x284, 0x7, 0x38, 0x2, 0x2, 0x284, 
       0x89, 0x3, 0x2, 0x2, 0x2, 0x285, 0x287, 0x5, 0x82, 0x42, 0x2, 0x286, 
       0x285, 0x3, 0x2, 0x2, 0x2, 0x286, 0x287, 0x3, 0x2, 0x2, 0x2, 0x287, 
       0x288, 0x3, 0x2, 0x2, 0x2, 0x288, 0x28b, 0x7, 0x3f, 0x2, 0x2, 0x289, 
       0x28c, 0x7, 0x31, 0x2, 0x2, 0x28a, 0x28c, 0x5, 0x92, 0x4a, 0x2, 0x28b, 
       0x289, 0x3, 0x2, 0x2, 0x2, 0x28b, 0x28a, 0x3, 0x2, 0x2, 0x2, 0x28c, 
       0x8b, 0x3, 0x2, 0x2, 0x2, 0x28d, 0x28f, 0x7, 0x37, 0x2, 0x2, 0x28e, 
       0x290, 0x5, 0x8a, 0x46, 0x2, 0x28f, 0x28e, 0x3, 0x2, 0x2, 0x2, 0x290, 
       0x291, 0x3, 0x2, 0x2, 0x2, 0x291, 0x28f, 0x3, 0x2, 0x2, 0x2, 0x291, 
       0x292, 0x3, 0x2, 0x2, 0x2, 0x292, 0x293, 0x3, 0x2, 0x2, 0x2, 0x293, 
       0x295, 0x7, 0x38, 0x2, 0x2, 0x294, 0x296, 0x5, 0x78, 0x3d, 0x2, 0x295, 
       0x294, 0x3, 0x2, 0x2, 0x2, 0x295, 0x296, 0x3, 0x2, 0x2, 0x2, 0x296, 
       0x8d, 0x3, 0x2, 0x2, 0x2, 0x297, 0x299, 0x5, 0x82, 0x42, 0x2, 0x298, 
       0x297, 0x3, 0x2, 0x2, 0x2, 0x298, 0x299, 0x3, 0x2, 0x2, 0x2, 0x299, 
       0x29b, 0x3, 0x2, 0x2, 0x2, 0x29a, 0x29c, 0x7, 0x19, 0x2, 0x2, 0x29b, 
       0x29a, 0x3, 0x2, 0x2, 0x2, 0x29b, 0x29c, 0x3, 0x2, 0x2, 0x2, 0x29c, 
       0x29d, 0x3, 0x2, 0x2, 0x2, 0x29d, 0x29e, 0x5, 0x4c, 0x27, 0x2, 0x29e, 
       0x2a2, 0x7, 0x3f, 0x2, 0x2, 0x29f, 0x2a3, 0x7, 0x31, 0x2, 0x2, 0x2a0, 
       0x2a3, 0x5, 0x78, 0x3d, 0x2, 0x2a1, 0x2a3, 0x5, 0x8c, 0x47, 0x2, 
       0x2a2, 0x29f, 0x3, 0x2, 0x2, 0x2, 0x2a2, 0x2a0, 0x3, 0x2, 0x2, 0x2, 
       0x2a2, 0x2a1, 0x3, 0x2, 0x2, 0x2, 0x2a3, 0x8f, 0x3, 0x2, 0x2, 0x2, 
       0x2a4, 0x2aa, 0x7, 0x3f, 0x2, 0x2, 0x2a5, 0x2a6, 0x7, 0x33, 0x2, 
       0x2, 0x2a6, 0x2aa, 0x7, 0x34, 0x2, 0x2, 0x2a7, 0x2aa, 0x5, 0x40, 
       0x21, 0x2, 0x2a8, 0x2aa, 0x5, 0x1e, 0x10, 0x2, 0x2a9, 0x2a4, 0x3, 
       0x2, 0x2, 0x2, 0x2a9, 0x2a5, 0x3, 0x2, 0x2, 0x2, 0x2a9, 0x2a7, 0x3, 
       0x2, 0x2, 0x2, 0x2a9, 0x2a8, 0x3, 0x2, 0x2, 0x2, 0x2aa, 0x91, 0x3, 
       0x2, 0x2, 0x2, 0x2ab, 0x2ac, 0x5, 0x38, 0x1d, 0x2, 0x2ac, 0x2ad, 
       0x5, 0x76, 0x3c, 0x2, 0x2ad, 0x2ae, 0x7, 0x31, 0x2, 0x2, 0x2ae, 0x2b8, 
       0x3, 0x2, 0x2, 0x2, 0x2af, 0x2b3, 0x7, 0x37, 0x2, 0x2, 0x2b0, 0x2b2, 
       0x5, 0x80, 0x41, 0x2, 0x2b1, 0x2b0, 0x3, 0x2, 0x2, 0x2, 0x2b2, 0x2b5, 
       0x3, 0x2, 0x2, 0x2, 0x2b3, 0x2b1, 0x3, 0x2, 0x2, 0x2, 0x2b3, 0x2b4, 
       0x3, 0x2, 0x2, 0x2, 0x2b4, 0x2b6, 0x3, 0x2, 0x2, 0x2, 0x2b5, 0x2b3, 
       0x3, 0x2, 0x2, 0x2, 0x2b6, 0x2b8, 0x7, 0x38, 0x2, 0x2, 0x2b7, 0x2ab, 
       0x3, 0x2, 0x2, 0x2, 0x2b7, 0x2af, 0x3, 0x2, 0x2, 0x2, 0x2b8, 0x93, 
       0x3, 0x2, 0x2, 0x2, 0x2b9, 0x2bb, 0x5, 0x82, 0x42, 0x2, 0x2ba, 0x2b9, 
       0x3, 0x2, 0x2, 0x2, 0x2ba, 0x2bb, 0x3, 0x2, 0x2, 0x2, 0x2bb, 0x2bd, 
       0x3, 0x2, 0x2, 0x2, 0x2bc, 0x2be, 0x7, 0x19, 0x2, 0x2, 0x2bd, 0x2bc, 
       0x3, 0x2, 0x2, 0x2, 0x2bd, 0x2be, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x2bf, 
       0x3, 0x2, 0x2, 0x2, 0x2bf, 0x2c0, 0x5, 0x4c, 0x27, 0x2, 0x2c0, 0x2c1, 
       0x5, 0x90, 0x49, 0x2, 0x2c1, 0x2c3, 0x7, 0x39, 0x2, 0x2, 0x2c2, 0x2c4, 
       0x5, 0x52, 0x2a, 0x2, 0x2c3, 0x2c2, 0x3, 0x2, 0x2, 0x2, 0x2c3, 0x2c4, 
       0x3, 0x2, 0x2, 0x2, 0x2c4, 0x2c5, 0x3, 0x2, 0x2, 0x2, 0x2c5, 0x2c6, 
       0x7, 0x3a, 0x2, 0x2, 0x2c6, 0x2c7, 0x5, 0x92, 0x4a, 0x2, 0x2c7, 0x95, 
       0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2ca, 0x5, 0x4c, 0x27, 0x2, 0x2c9, 0x2c8, 
       0x3, 0x2, 0x2, 0x2, 0x2c9, 0x2ca, 0x3, 0x2, 0x2, 0x2, 0x2ca, 0x2cb, 
       0x3, 0x2, 0x2, 0x2, 0x2cb, 0x2cc, 0x7, 0x3f, 0x2, 0x2, 0x2cc, 0x2cd, 
       0x7, 0x2e, 0x2, 0x2, 0x2cd, 0x97, 0x3, 0x2, 0x2, 0x2, 0x2ce, 0x2cf, 
       0x9, 0x5, 0x2, 0x2, 0x2cf, 0x99, 0x3, 0x2, 0x2, 0x2, 0x2d0, 0x2d1, 
       0x7, 0x3, 0x2, 0x2, 0x2d1, 0x2d2, 0x5, 0x4c, 0x27, 0x2, 0x2d2, 0x2d3, 
       0x5, 0x98, 0x4d, 0x2, 0x2d3, 0x2d4, 0x7, 0x3f, 0x2, 0x2, 0x2d4, 0x2d5, 
       0x7, 0x39, 0x2, 0x2, 0x2d5, 0x2d6, 0x5, 0x52, 0x2a, 0x2, 0x2d6, 0x2d7, 
       0x7, 0x3a, 0x2, 0x2, 0x2d7, 0x2d8, 0x7, 0x31, 0x2, 0x2, 0x2d8, 0x9b, 
       0x3, 0x2, 0x2, 0x2, 0x2d9, 0x2da, 0x7, 0x4, 0x2, 0x2, 0x2da, 0x2db, 
       0x7, 0x3e, 0x2, 0x2, 0x2db, 0x2dc, 0x7, 0x31, 0x2, 0x2, 0x2dc, 0x9d, 
       0x3, 0x2, 0x2, 0x2, 0x2dd, 0x2e0, 0x5, 0x9a, 0x4e, 0x2, 0x2de, 0x2e0, 
       0x5, 0x9c, 0x4f, 0x2, 0x2df, 0x2dd, 0x3, 0x2, 0x2, 0x2, 0x2df, 0x2de, 
       0x3, 0x2, 0x2, 0x2, 0x2e0, 0x2e1, 0x3, 0x2, 0x2, 0x2, 0x2e1, 0x2df, 
       0x3, 0x2, 0x2, 0x2, 0x2e1, 0x2e2, 0x3, 0x2, 0x2, 0x2, 0x2e2, 0x9f, 
       0x3, 0x2, 0x2, 0x2, 0x2e3, 0x2e4, 0x5, 0x4c, 0x27, 0x2, 0x2e4, 0x2e5, 
       0x7, 0xe, 0x2, 0x2, 0x2e5, 0x2e6, 0x7, 0x39, 0x2, 0x2, 0x2e6, 0x2e7, 
       0x7, 0x3a, 0x2, 0x2, 0x2e7, 0x2eb, 0x7, 0x37, 0x2, 0x2, 0x2e8, 0x2ea, 
       0x5, 0x80, 0x41, 0x2, 0x2e9, 0x2e8, 0x3, 0x2, 0x2, 0x2, 0x2ea, 0x2ed, 
       0x3, 0x2, 0x2, 0x2, 0x2eb, 0x2e9, 0x3, 0x2, 0x2, 0x2, 0x2eb, 0x2ec, 
       0x3, 0x2, 0x2, 0x2, 0x2ec, 0x2ee, 0x3, 0x2, 0x2, 0x2, 0x2ed, 0x2eb, 
       0x3, 0x2, 0x2, 0x2, 0x2ee, 0x2ef, 0x7, 0x38, 0x2, 0x2, 0x2ef, 0xa1, 
       0x3, 0x2, 0x2, 0x2, 0x2f0, 0x2f2, 0x5, 0x7c, 0x3f, 0x2, 0x2f1, 0x2f0, 
       0x3, 0x2, 0x2, 0x2, 0x2f2, 0x2f5, 0x3, 0x2, 0x2, 0x2, 0x2f3, 0x2f1, 
       0x3, 0x2, 0x2, 0x2, 0x2f3, 0x2f4, 0x3, 0x2, 0x2, 0x2, 0x2f4, 0x2f7, 
       0x3, 0x2, 0x2, 0x2, 0x2f5, 0x2f3, 0x3, 0x2, 0x2, 0x2, 0x2f6, 0x2f8, 
       0x5, 0x9e, 0x50, 0x2, 0x2f7, 0x2f6, 0x3, 0x2, 0x2, 0x2, 0x2f7, 0x2f8, 
       0x3, 0x2, 0x2, 0x2, 0x2f8, 0x2fc, 0x3, 0x2, 0x2, 0x2, 0x2f9, 0x2fb, 
       0x5, 0x88, 0x45, 0x2, 0x2fa, 0x2f9, 0x3, 0x2, 0x2, 0x2, 0x2fb, 0x2fe, 
       0x3, 0x2, 0x2, 0x2, 0x2fc, 0x2fa, 0x3, 0x2, 0x2, 0x2, 0x2fc, 0x2fd, 
       0x3, 0x2, 0x2, 0x2, 0x2fd, 0x300, 0x3, 0x2, 0x2, 0x2, 0x2fe, 0x2fc, 
       0x3, 0x2, 0x2, 0x2, 0x2ff, 0x301, 0x5, 0xa0, 0x51, 0x2, 0x300, 0x2ff, 
       0x3, 0x2, 0x2, 0x2, 0x300, 0x301, 0x3, 0x2, 0x2, 0x2, 0x301, 0xa3, 
       0x3, 0x2, 0x2, 0x2, 0x49, 0xdd, 0x111, 0x119, 0x11d, 0x121, 0x124, 
       0x129, 0x131, 0x138, 0x145, 0x14b, 0x154, 0x158, 0x15d, 0x164, 0x169, 
       0x170, 0x177, 0x180, 0x190, 0x195, 0x1a1, 0x1ad, 0x1ba, 0x1c0, 0x1ca, 
       0x1cf, 0x1d3, 0x1db, 0x1de, 0x1e8, 0x1f2, 0x200, 0x20c, 0x217, 0x21e, 
       0x223, 0x22a, 0x233, 0x23c, 0x24e, 0x251, 0x255, 0x25e, 0x268, 0x26e, 
       0x273, 0x279, 0x27e, 0x280, 0x286, 0x28b, 0x291, 0x295, 0x298, 0x29b, 
       0x2a2, 0x2a9, 0x2b3, 0x2b7, 0x2ba, 0x2bd, 0x2c3, 0x2c9, 0x2df, 0x2e1, 
       0x2eb, 0x2f3, 0x2f7, 0x2fc, 0x300, 
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

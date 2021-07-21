
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
    setState(142);
    match(FaParser::AddOp);
    setState(143);
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
    setState(145);
    match(FaParser::SubOp);
    setState(146);
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
    setState(148);
    match(FaParser::StarOp);
    setState(149);
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
    setState(151);
    match(FaParser::DivOp);
    setState(152);
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
    setState(154);
    match(FaParser::ModOp);
    setState(155);
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
    setState(157);
    match(FaParser::OrOp);
    setState(158);
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
    setState(160);
    match(FaParser::AndOp);
    setState(161);
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
    setState(163);
    match(FaParser::XorOp);
    setState(164);
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
    setState(166);
    qusQusOp();
    setState(167);
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
    setState(169);
    starStarOp();
    setState(170);
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
    setState(172);
    andAndOp();
    setState(173);
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
    setState(175);
    orOrOp();
    setState(176);
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
    setState(178);
    shiftLOp();
    setState(179);
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
    setState(181);
    shiftROp();
    setState(182);
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
    setState(199);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(184);
      match(FaParser::Assign);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(185);
      qusQusAssign();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(186);
      addAssign();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(187);
      subAssign();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(188);
      starAssign();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(189);
      starStarAssign();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(190);
      divAssign();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(191);
      modAssign();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(192);
      andAssign();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(193);
      orAssign();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(194);
      xorAssign();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(195);
      andAndAssign();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(196);
      orOrAssign();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(197);
      shiftLAssign();
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(198);
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
    setState(201);
    match(FaParser::Qus);
    setState(202);
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
    setState(204);
    match(FaParser::StarOp);
    setState(205);
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
    setState(207);
    match(FaParser::AndOp);
    setState(208);
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
    setState(210);
    match(FaParser::OrOp);
    setState(211);
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
    setState(213);
    match(FaParser::QuotJianL);
    setState(214);
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
    setState(216);
    match(FaParser::QuotJianR);
    setState(217);
    match(FaParser::QuotJianR);
   
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

FaParser::QusQusOpContext* FaParser::AllOp2Context::qusQusOp() {
  return getRuleContext<FaParser::QusQusOpContext>(0);
}

tree::TerminalNode* FaParser::AllOp2Context::PointOp() {
  return getToken(FaParser::PointOp, 0);
}

tree::TerminalNode* FaParser::AllOp2Context::AddOp() {
  return getToken(FaParser::AddOp, 0);
}

tree::TerminalNode* FaParser::AllOp2Context::SubOp() {
  return getToken(FaParser::SubOp, 0);
}

tree::TerminalNode* FaParser::AllOp2Context::StarOp() {
  return getToken(FaParser::StarOp, 0);
}

tree::TerminalNode* FaParser::AllOp2Context::DivOp() {
  return getToken(FaParser::DivOp, 0);
}

FaParser::StarStarOpContext* FaParser::AllOp2Context::starStarOp() {
  return getRuleContext<FaParser::StarStarOpContext>(0);
}

tree::TerminalNode* FaParser::AllOp2Context::ModOp() {
  return getToken(FaParser::ModOp, 0);
}

tree::TerminalNode* FaParser::AllOp2Context::AndOp() {
  return getToken(FaParser::AndOp, 0);
}

tree::TerminalNode* FaParser::AllOp2Context::OrOp() {
  return getToken(FaParser::OrOp, 0);
}

tree::TerminalNode* FaParser::AllOp2Context::XorOp() {
  return getToken(FaParser::XorOp, 0);
}

FaParser::AndAndOpContext* FaParser::AllOp2Context::andAndOp() {
  return getRuleContext<FaParser::AndAndOpContext>(0);
}

FaParser::OrOrOpContext* FaParser::AllOp2Context::orOrOp() {
  return getRuleContext<FaParser::OrOrOpContext>(0);
}

FaParser::ShiftLOpContext* FaParser::AllOp2Context::shiftLOp() {
  return getRuleContext<FaParser::ShiftLOpContext>(0);
}

FaParser::ShiftROpContext* FaParser::AllOp2Context::shiftROp() {
  return getRuleContext<FaParser::ShiftROpContext>(0);
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
  enterRule(_localctx, 42, FaParser::RuleAllOp2);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(234);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(219);
      qusQusOp();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(220);
      match(FaParser::PointOp);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(221);
      match(FaParser::AddOp);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(222);
      match(FaParser::SubOp);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(223);
      match(FaParser::StarOp);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(224);
      match(FaParser::DivOp);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(225);
      starStarOp();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(226);
      match(FaParser::ModOp);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(227);
      match(FaParser::AndOp);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(228);
      match(FaParser::OrOp);
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(229);
      match(FaParser::XorOp);
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(230);
      andAndOp();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(231);
      orOrOp();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(232);
      shiftLOp();
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(233);
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
  enterRule(_localctx, 44, FaParser::RuleLtOp);

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
  enterRule(_localctx, 46, FaParser::RuleLtEqualOp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(238);
    match(FaParser::QuotJianL);
    setState(239);
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
  enterRule(_localctx, 48, FaParser::RuleGtOp);

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
  enterRule(_localctx, 50, FaParser::RuleGtEqualOp);

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
    match(FaParser::QuotJianR);
    setState(244);
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
  enterRule(_localctx, 52, FaParser::RuleEqualOp);

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
    match(FaParser::Assign);
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
  enterRule(_localctx, 54, FaParser::RuleNotEqualOp);

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
    match(FaParser::Exclam);
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

//----------------- LtOpsContext ------------------------------------------------------------------

FaParser::LtOpsContext::LtOpsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::LtOpContext* FaParser::LtOpsContext::ltOp() {
  return getRuleContext<FaParser::LtOpContext>(0);
}

FaParser::LtEqualOpContext* FaParser::LtOpsContext::ltEqualOp() {
  return getRuleContext<FaParser::LtEqualOpContext>(0);
}


size_t FaParser::LtOpsContext::getRuleIndex() const {
  return FaParser::RuleLtOps;
}


antlrcpp::Any FaParser::LtOpsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitLtOps(this);
  else
    return visitor->visitChildren(this);
}

FaParser::LtOpsContext* FaParser::ltOps() {
  LtOpsContext *_localctx = _tracker.createInstance<LtOpsContext>(_ctx, getState());
  enterRule(_localctx, 56, FaParser::RuleLtOps);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(254);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(252);
      ltOp();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(253);
      ltEqualOp();
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

//----------------- GtOpsContext ------------------------------------------------------------------

FaParser::GtOpsContext::GtOpsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::GtOpContext* FaParser::GtOpsContext::gtOp() {
  return getRuleContext<FaParser::GtOpContext>(0);
}

FaParser::GtEqualOpContext* FaParser::GtOpsContext::gtEqualOp() {
  return getRuleContext<FaParser::GtEqualOpContext>(0);
}


size_t FaParser::GtOpsContext::getRuleIndex() const {
  return FaParser::RuleGtOps;
}


antlrcpp::Any FaParser::GtOpsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitGtOps(this);
  else
    return visitor->visitChildren(this);
}

FaParser::GtOpsContext* FaParser::gtOps() {
  GtOpsContext *_localctx = _tracker.createInstance<GtOpsContext>(_ctx, getState());
  enterRule(_localctx, 58, FaParser::RuleGtOps);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(258);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(256);
      gtOp();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(257);
      gtEqualOp();
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
  enterRule(_localctx, 60, FaParser::RuleLiteral);
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
    setState(260);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::BoolLiteral)
      | (1ULL << FaParser::IntLiteral)
      | (1ULL << FaParser::FloatLiteral)
      | (1ULL << FaParser::String1Literal))) != 0))) {
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
  enterRule(_localctx, 62, FaParser::RuleIds);

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
    setState(262);
    match(FaParser::Id);
    setState(267);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(263);
        match(FaParser::PointOp);
        setState(264);
        match(FaParser::Id); 
      }
      setState(269);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
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
  enterRule(_localctx, 64, FaParser::RuleTypeAfter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(274);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::QuotFangL: {
        enterOuterAlt(_localctx, 1);
        setState(270);
        match(FaParser::QuotFangL);
        setState(271);
        match(FaParser::QuotFangR);
        break;
      }

      case FaParser::AndOp: {
        enterOuterAlt(_localctx, 2);
        setState(272);
        match(FaParser::AndOp);
        break;
      }

      case FaParser::Qus: {
        enterOuterAlt(_localctx, 3);
        setState(273);
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
  enterRule(_localctx, 66, FaParser::RuleType);
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
    setState(277);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Const) {
      setState(276);
      match(FaParser::Const);
    }
    setState(302);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      setState(279);
      match(FaParser::Id);
      break;
    }

    case 2: {
      setState(280);
      match(FaParser::Id);
      setState(281);
      match(FaParser::QuotJianL);
      setState(282);
      type();
      setState(287);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FaParser::Comma) {
        setState(283);
        match(FaParser::Comma);
        setState(284);
        type();
        setState(289);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(290);
      match(FaParser::QuotJianR);
      break;
    }

    case 3: {
      setState(292);
      match(FaParser::QuotYuanL);
      setState(293);
      type();
      setState(296); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(294);
        match(FaParser::Comma);
        setState(295);
        type();
        setState(298); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == FaParser::Comma);
      setState(300);
      match(FaParser::QuotYuanR);
      break;
    }

    default:
      break;
    }
    setState(307);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::AndOp)
      | (1ULL << FaParser::Qus)
      | (1ULL << FaParser::QuotFangL))) != 0)) {
      setState(304);
      typeAfter();
      setState(309);
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
  enterRule(_localctx, 68, FaParser::RuleETypeAfter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(314);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::QuotFangL: {
        enterOuterAlt(_localctx, 1);
        setState(310);
        match(FaParser::QuotFangL);
        setState(311);
        match(FaParser::QuotFangR);
        break;
      }

      case FaParser::AndOp: {
        enterOuterAlt(_localctx, 2);
        setState(312);
        match(FaParser::AndOp);
        break;
      }

      case FaParser::StarOp: {
        enterOuterAlt(_localctx, 3);
        setState(313);
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

//----------------- ESignContext ------------------------------------------------------------------

FaParser::ESignContext::ESignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::ESignContext::Signed() {
  return getToken(FaParser::Signed, 0);
}

tree::TerminalNode* FaParser::ESignContext::Unsigned() {
  return getToken(FaParser::Unsigned, 0);
}


size_t FaParser::ESignContext::getRuleIndex() const {
  return FaParser::RuleESign;
}


antlrcpp::Any FaParser::ESignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitESign(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ESignContext* FaParser::eSign() {
  ESignContext *_localctx = _tracker.createInstance<ESignContext>(_ctx, getState());
  enterRule(_localctx, 70, FaParser::RuleESign);
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
    setState(316);
    _la = _input->LA(1);
    if (!(_la == FaParser::Signed

    || _la == FaParser::Unsigned)) {
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

FaParser::ESignContext* FaParser::ETypeContext::eSign() {
  return getRuleContext<FaParser::ESignContext>(0);
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
  enterRule(_localctx, 72, FaParser::RuleEType);
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
    setState(319);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Const) {
      setState(318);
      match(FaParser::Const);
    }
    setState(322);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Signed

    || _la == FaParser::Unsigned) {
      setState(321);
      eSign();
    }
    setState(324);
    match(FaParser::Id);
    setState(328);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::StarOp)
      | (1ULL << FaParser::AndOp)
      | (1ULL << FaParser::QuotFangL))) != 0)) {
      setState(325);
      eTypeAfter();
      setState(330);
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
  enterRule(_localctx, 74, FaParser::RuleTypeVar);
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
    setState(331);
    type();
    setState(333);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Id) {
      setState(332);
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
  enterRule(_localctx, 76, FaParser::RuleTypeVarList);
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
    setState(335);
    typeVar();
    setState(340);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(336);
      match(FaParser::Comma);
      setState(337);
      typeVar();
      setState(342);
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
  enterRule(_localctx, 78, FaParser::RuleETypeVar);
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
    setState(343);
    eType();
    setState(345);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Id) {
      setState(344);
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
  enterRule(_localctx, 80, FaParser::RuleETypeVarList);
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
    setState(347);
    eTypeVar();
    setState(352);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(348);
      match(FaParser::Comma);
      setState(349);
      eTypeVar();
      setState(354);
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

//----------------- IfPartContext ------------------------------------------------------------------

FaParser::IfPartContext::IfPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::IfPartContext::If() {
  return getToken(FaParser::If, 0);
}

tree::TerminalNode* FaParser::IfPartContext::QuotYuanL() {
  return getToken(FaParser::QuotYuanL, 0);
}

FaParser::ExprContext* FaParser::IfPartContext::expr() {
  return getRuleContext<FaParser::ExprContext>(0);
}

tree::TerminalNode* FaParser::IfPartContext::QuotYuanR() {
  return getToken(FaParser::QuotYuanR, 0);
}


size_t FaParser::IfPartContext::getRuleIndex() const {
  return FaParser::RuleIfPart;
}


antlrcpp::Any FaParser::IfPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitIfPart(this);
  else
    return visitor->visitChildren(this);
}

FaParser::IfPartContext* FaParser::ifPart() {
  IfPartContext *_localctx = _tracker.createInstance<IfPartContext>(_ctx, getState());
  enterRule(_localctx, 82, FaParser::RuleIfPart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(355);
    match(FaParser::If);
    setState(356);
    match(FaParser::QuotYuanL);
    setState(357);
    expr();
    setState(358);
    match(FaParser::QuotYuanR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtOrIfExprContext ------------------------------------------------------------------

FaParser::StmtOrIfExprContext::StmtOrIfExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::StmtContext* FaParser::StmtOrIfExprContext::stmt() {
  return getRuleContext<FaParser::StmtContext>(0);
}

FaParser::IfExprContext* FaParser::StmtOrIfExprContext::ifExpr() {
  return getRuleContext<FaParser::IfExprContext>(0);
}


size_t FaParser::StmtOrIfExprContext::getRuleIndex() const {
  return FaParser::RuleStmtOrIfExpr;
}


antlrcpp::Any FaParser::StmtOrIfExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitStmtOrIfExpr(this);
  else
    return visitor->visitChildren(this);
}

FaParser::StmtOrIfExprContext* FaParser::stmtOrIfExpr() {
  StmtOrIfExprContext *_localctx = _tracker.createInstance<StmtOrIfExprContext>(_ctx, getState());
  enterRule(_localctx, 84, FaParser::RuleStmtOrIfExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(362);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(360);
      stmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(361);
      ifExpr();
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
  enterRule(_localctx, 86, FaParser::RuleQuotStmtPart);
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
    setState(364);
    match(FaParser::QuotHuaL);
    setState(368);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Break)
      | (1ULL << FaParser::Continue)
      | (1ULL << FaParser::Const)
      | (1ULL << FaParser::If)
      | (1ULL << FaParser::Return)
      | (1ULL << FaParser::While)
      | (1ULL << FaParser::ReverseOp)
      | (1ULL << FaParser::AddAddOp)
      | (1ULL << FaParser::SubSubOp)
      | (1ULL << FaParser::AddOp)
      | (1ULL << FaParser::SubOp)
      | (1ULL << FaParser::ColonColon)
      | (1ULL << FaParser::QuotYuanL)
      | (1ULL << FaParser::BoolLiteral)
      | (1ULL << FaParser::IntLiteral)
      | (1ULL << FaParser::FloatLiteral)
      | (1ULL << FaParser::String1Literal)
      | (1ULL << FaParser::Id))) != 0)) {
      setState(365);
      stmt();
      setState(370);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(371);
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

std::vector<FaParser::StmtOrIfExprContext *> FaParser::QuotStmtExprContext::stmtOrIfExpr() {
  return getRuleContexts<FaParser::StmtOrIfExprContext>();
}

FaParser::StmtOrIfExprContext* FaParser::QuotStmtExprContext::stmtOrIfExpr(size_t i) {
  return getRuleContext<FaParser::StmtOrIfExprContext>(i);
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
  enterRule(_localctx, 88, FaParser::RuleQuotStmtExpr);

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
    setState(373);
    match(FaParser::QuotHuaL);
    setState(377);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(374);
        stmtOrIfExpr(); 
      }
      setState(379);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
    setState(380);
    expr();
    setState(381);
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

std::vector<FaParser::IfPartContext *> FaParser::IfStmtContext::ifPart() {
  return getRuleContexts<FaParser::IfPartContext>();
}

FaParser::IfPartContext* FaParser::IfStmtContext::ifPart(size_t i) {
  return getRuleContext<FaParser::IfPartContext>(i);
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
  enterRule(_localctx, 90, FaParser::RuleIfStmt);
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
    setState(383);
    ifPart();
    setState(384);
    quotStmtPart();
    setState(391);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(385);
        match(FaParser::Else);
        setState(386);
        ifPart();
        setState(387);
        quotStmtPart(); 
      }
      setState(393);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
    setState(396);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Else) {
      setState(394);
      match(FaParser::Else);
      setState(395);
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

std::vector<FaParser::IfPartContext *> FaParser::IfExprContext::ifPart() {
  return getRuleContexts<FaParser::IfPartContext>();
}

FaParser::IfPartContext* FaParser::IfExprContext::ifPart(size_t i) {
  return getRuleContext<FaParser::IfPartContext>(i);
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
  enterRule(_localctx, 92, FaParser::RuleIfExpr);

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
    setState(398);
    ifPart();
    setState(399);
    quotStmtExpr();
    setState(406);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(400);
        match(FaParser::Else);
        setState(401);
        ifPart();
        setState(402);
        quotStmtExpr(); 
      }
      setState(408);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfElseExprContext ------------------------------------------------------------------

FaParser::IfElseExprContext::IfElseExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::IfExprContext* FaParser::IfElseExprContext::ifExpr() {
  return getRuleContext<FaParser::IfExprContext>(0);
}

tree::TerminalNode* FaParser::IfElseExprContext::Else() {
  return getToken(FaParser::Else, 0);
}

FaParser::QuotStmtExprContext* FaParser::IfElseExprContext::quotStmtExpr() {
  return getRuleContext<FaParser::QuotStmtExprContext>(0);
}


size_t FaParser::IfElseExprContext::getRuleIndex() const {
  return FaParser::RuleIfElseExpr;
}


antlrcpp::Any FaParser::IfElseExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitIfElseExpr(this);
  else
    return visitor->visitChildren(this);
}

FaParser::IfElseExprContext* FaParser::ifElseExpr() {
  IfElseExprContext *_localctx = _tracker.createInstance<IfElseExprContext>(_ctx, getState());
  enterRule(_localctx, 94, FaParser::RuleIfElseExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(409);
    ifExpr();
    setState(410);
    match(FaParser::Else);
    setState(411);
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

tree::TerminalNode* FaParser::WhileStmtContext::QuotYuanL() {
  return getToken(FaParser::QuotYuanL, 0);
}

FaParser::ExprContext* FaParser::WhileStmtContext::expr() {
  return getRuleContext<FaParser::ExprContext>(0);
}

tree::TerminalNode* FaParser::WhileStmtContext::QuotYuanR() {
  return getToken(FaParser::QuotYuanR, 0);
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
  enterRule(_localctx, 96, FaParser::RuleWhileStmt);
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
    setState(413);
    match(FaParser::While);
    setState(414);
    match(FaParser::QuotYuanL);
    setState(415);
    expr();
    setState(416);
    match(FaParser::QuotYuanR);
    setState(417);
    match(FaParser::QuotHuaL);
    setState(421);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Break)
      | (1ULL << FaParser::Continue)
      | (1ULL << FaParser::Const)
      | (1ULL << FaParser::If)
      | (1ULL << FaParser::Return)
      | (1ULL << FaParser::While)
      | (1ULL << FaParser::ReverseOp)
      | (1ULL << FaParser::AddAddOp)
      | (1ULL << FaParser::SubSubOp)
      | (1ULL << FaParser::AddOp)
      | (1ULL << FaParser::SubOp)
      | (1ULL << FaParser::ColonColon)
      | (1ULL << FaParser::QuotYuanL)
      | (1ULL << FaParser::BoolLiteral)
      | (1ULL << FaParser::IntLiteral)
      | (1ULL << FaParser::FloatLiteral)
      | (1ULL << FaParser::String1Literal)
      | (1ULL << FaParser::Id))) != 0)) {
      setState(418);
      stmt();
      setState(423);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(424);
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
  enterRule(_localctx, 98, FaParser::RuleQuotExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(426);
    match(FaParser::QuotYuanL);
    setState(427);
    expr();
    setState(428);
    match(FaParser::QuotYuanR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprPrefixContext ------------------------------------------------------------------

FaParser::ExprPrefixContext::ExprPrefixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::ExprPrefixContext::AddOp() {
  return getToken(FaParser::AddOp, 0);
}

tree::TerminalNode* FaParser::ExprPrefixContext::SubOp() {
  return getToken(FaParser::SubOp, 0);
}

tree::TerminalNode* FaParser::ExprPrefixContext::AddAddOp() {
  return getToken(FaParser::AddAddOp, 0);
}

tree::TerminalNode* FaParser::ExprPrefixContext::SubSubOp() {
  return getToken(FaParser::SubSubOp, 0);
}

tree::TerminalNode* FaParser::ExprPrefixContext::ReverseOp() {
  return getToken(FaParser::ReverseOp, 0);
}


size_t FaParser::ExprPrefixContext::getRuleIndex() const {
  return FaParser::RuleExprPrefix;
}


antlrcpp::Any FaParser::ExprPrefixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitExprPrefix(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ExprPrefixContext* FaParser::exprPrefix() {
  ExprPrefixContext *_localctx = _tracker.createInstance<ExprPrefixContext>(_ctx, getState());
  enterRule(_localctx, 100, FaParser::RuleExprPrefix);
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
    setState(430);
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
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprBodyContext ------------------------------------------------------------------

FaParser::ExprBodyContext::ExprBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::IdsContext* FaParser::ExprBodyContext::ids() {
  return getRuleContext<FaParser::IdsContext>(0);
}

tree::TerminalNode* FaParser::ExprBodyContext::ColonColon() {
  return getToken(FaParser::ColonColon, 0);
}

tree::TerminalNode* FaParser::ExprBodyContext::Id() {
  return getToken(FaParser::Id, 0);
}

FaParser::LiteralContext* FaParser::ExprBodyContext::literal() {
  return getRuleContext<FaParser::LiteralContext>(0);
}

FaParser::IfElseExprContext* FaParser::ExprBodyContext::ifElseExpr() {
  return getRuleContext<FaParser::IfElseExprContext>(0);
}

FaParser::QuotExprContext* FaParser::ExprBodyContext::quotExpr() {
  return getRuleContext<FaParser::QuotExprContext>(0);
}


size_t FaParser::ExprBodyContext::getRuleIndex() const {
  return FaParser::RuleExprBody;
}


antlrcpp::Any FaParser::ExprBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitExprBody(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ExprBodyContext* FaParser::exprBody() {
  ExprBodyContext *_localctx = _tracker.createInstance<ExprBodyContext>(_ctx, getState());
  enterRule(_localctx, 102, FaParser::RuleExprBody);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(438);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::Id: {
        enterOuterAlt(_localctx, 1);
        setState(432);
        ids();
        break;
      }

      case FaParser::ColonColon: {
        enterOuterAlt(_localctx, 2);
        setState(433);
        match(FaParser::ColonColon);
        setState(434);
        match(FaParser::Id);
        break;
      }

      case FaParser::BoolLiteral:
      case FaParser::IntLiteral:
      case FaParser::FloatLiteral:
      case FaParser::String1Literal: {
        enterOuterAlt(_localctx, 3);
        setState(435);
        literal();
        break;
      }

      case FaParser::If: {
        enterOuterAlt(_localctx, 4);
        setState(436);
        ifElseExpr();
        break;
      }

      case FaParser::QuotYuanL: {
        enterOuterAlt(_localctx, 5);
        setState(437);
        quotExpr();
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

//----------------- ExprSuffixContext ------------------------------------------------------------------

FaParser::ExprSuffixContext::ExprSuffixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::ExprSuffixContext::AddAddOp() {
  return getToken(FaParser::AddAddOp, 0);
}

tree::TerminalNode* FaParser::ExprSuffixContext::SubSubOp() {
  return getToken(FaParser::SubSubOp, 0);
}

tree::TerminalNode* FaParser::ExprSuffixContext::QuotYuanL() {
  return getToken(FaParser::QuotYuanL, 0);
}

tree::TerminalNode* FaParser::ExprSuffixContext::QuotYuanR() {
  return getToken(FaParser::QuotYuanR, 0);
}

std::vector<FaParser::ExprContext *> FaParser::ExprSuffixContext::expr() {
  return getRuleContexts<FaParser::ExprContext>();
}

FaParser::ExprContext* FaParser::ExprSuffixContext::expr(size_t i) {
  return getRuleContext<FaParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> FaParser::ExprSuffixContext::Comma() {
  return getTokens(FaParser::Comma);
}

tree::TerminalNode* FaParser::ExprSuffixContext::Comma(size_t i) {
  return getToken(FaParser::Comma, i);
}

tree::TerminalNode* FaParser::ExprSuffixContext::QuotFangL() {
  return getToken(FaParser::QuotFangL, 0);
}

tree::TerminalNode* FaParser::ExprSuffixContext::QuotFangR() {
  return getToken(FaParser::QuotFangR, 0);
}

FaParser::AllAssignContext* FaParser::ExprSuffixContext::allAssign() {
  return getRuleContext<FaParser::AllAssignContext>(0);
}

FaParser::AllOp2Context* FaParser::ExprSuffixContext::allOp2() {
  return getRuleContext<FaParser::AllOp2Context>(0);
}

std::vector<FaParser::LtOpsContext *> FaParser::ExprSuffixContext::ltOps() {
  return getRuleContexts<FaParser::LtOpsContext>();
}

FaParser::LtOpsContext* FaParser::ExprSuffixContext::ltOps(size_t i) {
  return getRuleContext<FaParser::LtOpsContext>(i);
}

std::vector<FaParser::GtOpsContext *> FaParser::ExprSuffixContext::gtOps() {
  return getRuleContexts<FaParser::GtOpsContext>();
}

FaParser::GtOpsContext* FaParser::ExprSuffixContext::gtOps(size_t i) {
  return getRuleContext<FaParser::GtOpsContext>(i);
}

FaParser::EqualOpContext* FaParser::ExprSuffixContext::equalOp() {
  return getRuleContext<FaParser::EqualOpContext>(0);
}

FaParser::NotEqualOpContext* FaParser::ExprSuffixContext::notEqualOp() {
  return getRuleContext<FaParser::NotEqualOpContext>(0);
}


size_t FaParser::ExprSuffixContext::getRuleIndex() const {
  return FaParser::RuleExprSuffix;
}


antlrcpp::Any FaParser::ExprSuffixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitExprSuffix(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ExprSuffixContext* FaParser::exprSuffix() {
  ExprSuffixContext *_localctx = _tracker.createInstance<ExprSuffixContext>(_ctx, getState());
  enterRule(_localctx, 104, FaParser::RuleExprSuffix);
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
    setState(483);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(440);
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

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(441);
      match(FaParser::QuotYuanL);
      setState(450);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << FaParser::If)
        | (1ULL << FaParser::ReverseOp)
        | (1ULL << FaParser::AddAddOp)
        | (1ULL << FaParser::SubSubOp)
        | (1ULL << FaParser::AddOp)
        | (1ULL << FaParser::SubOp)
        | (1ULL << FaParser::ColonColon)
        | (1ULL << FaParser::QuotYuanL)
        | (1ULL << FaParser::BoolLiteral)
        | (1ULL << FaParser::IntLiteral)
        | (1ULL << FaParser::FloatLiteral)
        | (1ULL << FaParser::String1Literal)
        | (1ULL << FaParser::Id))) != 0)) {
        setState(442);
        expr();
        setState(447);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == FaParser::Comma) {
          setState(443);
          match(FaParser::Comma);
          setState(444);
          expr();
          setState(449);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(452);
      match(FaParser::QuotYuanR);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(453);
      match(FaParser::QuotFangL);
      setState(454);
      expr();
      setState(455);
      match(FaParser::QuotFangR);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(459);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
      case 1: {
        setState(457);
        allAssign();
        break;
      }

      case 2: {
        setState(458);
        allOp2();
        break;
      }

      default:
        break;
      }
      setState(461);
      expr();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(466); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(463);
                ltOps();
                setState(464);
                expr();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(468); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(473); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(470);
                gtOps();
                setState(471);
                expr();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(475); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(479);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case FaParser::Assign: {
          setState(477);
          equalOp();
          break;
        }

        case FaParser::Exclam: {
          setState(478);
          notEqualOp();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(481);
      expr();
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

//----------------- NormalExprContext ------------------------------------------------------------------

FaParser::NormalExprContext::NormalExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::ExprBodyContext* FaParser::NormalExprContext::exprBody() {
  return getRuleContext<FaParser::ExprBodyContext>(0);
}

std::vector<FaParser::ExprPrefixContext *> FaParser::NormalExprContext::exprPrefix() {
  return getRuleContexts<FaParser::ExprPrefixContext>();
}

FaParser::ExprPrefixContext* FaParser::NormalExprContext::exprPrefix(size_t i) {
  return getRuleContext<FaParser::ExprPrefixContext>(i);
}

std::vector<FaParser::ExprSuffixContext *> FaParser::NormalExprContext::exprSuffix() {
  return getRuleContexts<FaParser::ExprSuffixContext>();
}

FaParser::ExprSuffixContext* FaParser::NormalExprContext::exprSuffix(size_t i) {
  return getRuleContext<FaParser::ExprSuffixContext>(i);
}


size_t FaParser::NormalExprContext::getRuleIndex() const {
  return FaParser::RuleNormalExpr;
}


antlrcpp::Any FaParser::NormalExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitNormalExpr(this);
  else
    return visitor->visitChildren(this);
}

FaParser::NormalExprContext* FaParser::normalExpr() {
  NormalExprContext *_localctx = _tracker.createInstance<NormalExprContext>(_ctx, getState());
  enterRule(_localctx, 106, FaParser::RuleNormalExpr);
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
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::ReverseOp)
      | (1ULL << FaParser::AddAddOp)
      | (1ULL << FaParser::SubSubOp)
      | (1ULL << FaParser::AddOp)
      | (1ULL << FaParser::SubOp))) != 0)) {
      setState(485);
      exprPrefix();
      setState(490);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(491);
    exprBody();
    setState(495);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(492);
        exprSuffix(); 
      }
      setState(497);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
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

FaParser::IfElseExprContext* FaParser::ExprContext::ifElseExpr() {
  return getRuleContext<FaParser::IfElseExprContext>(0);
}

FaParser::QuotExprContext* FaParser::ExprContext::quotExpr() {
  return getRuleContext<FaParser::QuotExprContext>(0);
}

FaParser::NormalExprContext* FaParser::ExprContext::normalExpr() {
  return getRuleContext<FaParser::NormalExprContext>(0);
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
  enterRule(_localctx, 108, FaParser::RuleExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(501);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(498);
      ifElseExpr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(499);
      quotExpr();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(500);
      normalExpr();
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
  enterRule(_localctx, 110, FaParser::RuleDefVarStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(503);
    type();
    setState(504);
    match(FaParser::Id);
    setState(505);
    match(FaParser::Assign);
    setState(506);
    expr();
    setState(507);
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
  enterRule(_localctx, 112, FaParser::RuleUseStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(509);
    match(FaParser::Use);
    setState(510);
    ids();
    setState(511);
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

FaParser::ExprContext* FaParser::NormalStmtContext::expr() {
  return getRuleContext<FaParser::ExprContext>(0);
}

tree::TerminalNode* FaParser::NormalStmtContext::Return() {
  return getToken(FaParser::Return, 0);
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
  enterRule(_localctx, 114, FaParser::RuleNormalStmt);
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
    setState(519);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::If:
      case FaParser::Return:
      case FaParser::ReverseOp:
      case FaParser::AddAddOp:
      case FaParser::SubSubOp:
      case FaParser::AddOp:
      case FaParser::SubOp:
      case FaParser::ColonColon:
      case FaParser::QuotYuanL:
      case FaParser::BoolLiteral:
      case FaParser::IntLiteral:
      case FaParser::FloatLiteral:
      case FaParser::String1Literal:
      case FaParser::Id: {
        setState(514);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == FaParser::Return) {
          setState(513);
          match(FaParser::Return);
        }
        setState(516);
        expr();
        break;
      }

      case FaParser::Break: {
        setState(517);
        match(FaParser::Break);
        break;
      }

      case FaParser::Continue: {
        setState(518);
        match(FaParser::Continue);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(521);
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

FaParser::WhileStmtContext* FaParser::StmtContext::whileStmt() {
  return getRuleContext<FaParser::WhileStmtContext>(0);
}

FaParser::DefVarStmtContext* FaParser::StmtContext::defVarStmt() {
  return getRuleContext<FaParser::DefVarStmtContext>(0);
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
  enterRule(_localctx, 116, FaParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(527);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(523);
      normalStmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(524);
      ifStmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(525);
      whileStmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(526);
      defVarStmt();
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
  enterRule(_localctx, 118, FaParser::RulePublicLevel);
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
    setState(529);
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
  enterRule(_localctx, 120, FaParser::RuleClassParent);
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
    setState(531);
    match(FaParser::Colon);
    setState(532);
    ids();
    setState(537);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(533);
      match(FaParser::Comma);
      setState(534);
      ids();
      setState(539);
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
  enterRule(_localctx, 122, FaParser::RuleClassItemPart);
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
    setState(541);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(540);
      publicLevel();
    }
    setState(544);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Static) {
      setState(543);
      match(FaParser::Static);
    }
    setState(546);
    match(FaParser::Id);
    setState(547);
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
  enterRule(_localctx, 124, FaParser::RuleClassItemFieldBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(549);
    classItemPart();
    setState(550);
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
  enterRule(_localctx, 126, FaParser::RuleClassItemFuncBlock);
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
    setState(552);
    classItemPart();
    setState(553);
    match(FaParser::QuotYuanL);
    setState(554);
    typeVarList();
    setState(555);
    match(FaParser::QuotYuanR);
    setState(556);
    match(FaParser::QuotHuaL);
    setState(560);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Break)
      | (1ULL << FaParser::Continue)
      | (1ULL << FaParser::Const)
      | (1ULL << FaParser::If)
      | (1ULL << FaParser::Return)
      | (1ULL << FaParser::While)
      | (1ULL << FaParser::ReverseOp)
      | (1ULL << FaParser::AddAddOp)
      | (1ULL << FaParser::SubSubOp)
      | (1ULL << FaParser::AddOp)
      | (1ULL << FaParser::SubOp)
      | (1ULL << FaParser::ColonColon)
      | (1ULL << FaParser::QuotYuanL)
      | (1ULL << FaParser::BoolLiteral)
      | (1ULL << FaParser::IntLiteral)
      | (1ULL << FaParser::FloatLiteral)
      | (1ULL << FaParser::String1Literal)
      | (1ULL << FaParser::Id))) != 0)) {
      setState(557);
      stmt();
      setState(562);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(563);
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
  enterRule(_localctx, 128, FaParser::RuleClassBlock);
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
    setState(566);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(565);
      publicLevel();
    }
    setState(568);
    match(FaParser::Class);
    setState(569);
    match(FaParser::Id);
    setState(571);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Colon) {
      setState(570);
      classParent();
    }
    setState(573);
    match(FaParser::QuotHuaL);
    setState(578);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private)
      | (1ULL << FaParser::Static)
      | (1ULL << FaParser::Id))) != 0)) {
      setState(576);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
      case 1: {
        setState(574);
        classItemFieldBlock();
        break;
      }

      case 2: {
        setState(575);
        classItemFuncBlock();
        break;
      }

      default:
        break;
      }
      setState(580);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(581);
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
  enterRule(_localctx, 130, FaParser::RuleCallConvention);
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
    setState(583);
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
  enterRule(_localctx, 132, FaParser::RuleImportStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(585);
    match(FaParser::AImport);
    setState(586);
    eType();
    setState(587);
    callConvention();
    setState(588);
    match(FaParser::Id);
    setState(589);
    match(FaParser::QuotYuanL);
    setState(590);
    eTypeVarList();
    setState(591);
    match(FaParser::QuotYuanR);
    setState(592);
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
  enterRule(_localctx, 134, FaParser::RuleLibStmt);

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
    match(FaParser::ALib);
    setState(595);
    match(FaParser::String1Literal);
    setState(596);
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
  enterRule(_localctx, 136, FaParser::RuleImportBlock);
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
    setState(600); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(600);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case FaParser::AImport: {
          setState(598);
          importStmt();
          break;
        }

        case FaParser::ALib: {
          setState(599);
          libStmt();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(602); 
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
  enterRule(_localctx, 138, FaParser::RuleFaEntryMainFuncBlock);
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
    setState(604);
    match(FaParser::Static);
    setState(605);
    type();
    setState(606);
    match(FaParser::FaEntryMain);
    setState(607);
    match(FaParser::QuotYuanL);
    setState(608);
    match(FaParser::QuotYuanR);
    setState(609);
    match(FaParser::QuotHuaL);
    setState(613);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Break)
      | (1ULL << FaParser::Continue)
      | (1ULL << FaParser::Const)
      | (1ULL << FaParser::If)
      | (1ULL << FaParser::Return)
      | (1ULL << FaParser::While)
      | (1ULL << FaParser::ReverseOp)
      | (1ULL << FaParser::AddAddOp)
      | (1ULL << FaParser::SubSubOp)
      | (1ULL << FaParser::AddOp)
      | (1ULL << FaParser::SubOp)
      | (1ULL << FaParser::ColonColon)
      | (1ULL << FaParser::QuotYuanL)
      | (1ULL << FaParser::BoolLiteral)
      | (1ULL << FaParser::IntLiteral)
      | (1ULL << FaParser::FloatLiteral)
      | (1ULL << FaParser::String1Literal)
      | (1ULL << FaParser::Id))) != 0)) {
      setState(610);
      stmt();
      setState(615);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(616);
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
  enterRule(_localctx, 140, FaParser::RuleProgram);
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
    setState(621);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Use) {
      setState(618);
      useStmt();
      setState(623);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(625);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::AImport

    || _la == FaParser::ALib) {
      setState(624);
      importBlock();
    }
    setState(630);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Class)
      | (1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(627);
      classBlock();
      setState(632);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(634);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Static) {
      setState(633);
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
  "addAssign", "subAssign", "starAssign", "divAssign", "modAssign", "orAssign", 
  "andAssign", "xorAssign", "qusQusAssign", "starStarAssign", "andAndAssign", 
  "orOrAssign", "shiftLAssign", "shiftRAssign", "allAssign", "qusQusOp", 
  "starStarOp", "andAndOp", "orOrOp", "shiftLOp", "shiftROp", "allOp2", 
  "ltOp", "ltEqualOp", "gtOp", "gtEqualOp", "equalOp", "notEqualOp", "ltOps", 
  "gtOps", "literal", "ids", "typeAfter", "type", "eTypeAfter", "eSign", 
  "eType", "typeVar", "typeVarList", "eTypeVar", "eTypeVarList", "ifPart", 
  "stmtOrIfExpr", "quotStmtPart", "quotStmtExpr", "ifStmt", "ifExpr", "ifElseExpr", 
  "whileStmt", "quotExpr", "exprPrefix", "exprBody", "exprSuffix", "normalExpr", 
  "expr", "defVarStmt", "useStmt", "normalStmt", "stmt", "publicLevel", 
  "classParent", "classItemPart", "classItemFieldBlock", "classItemFuncBlock", 
  "classBlock", "callConvention", "importStmt", "libStmt", "importBlock", 
  "faEntryMainFuncBlock", "program"
};

std::vector<std::string> FaParser::_literalNames = {
  "", "'@import'", "'@lib'", "'break'", "'__cdecl'", "'__fastcall'", "'__stdcall'", 
  "'continue'", "'class'", "'const'", "'else'", "'FaEntryMain'", "'if'", 
  "'internal'", "'public'", "'protected'", "'private'", "'return'", "'signed'", 
  "'static'", "'unsigned'", "'use'", "'while'", "'='", "'~'", "'++'", "'--'", 
  "'.'", "'+'", "'-'", "'*'", "'/'", "'%'", "'|'", "'&'", "'^'", "'\u003F'", 
  "','", "'::'", "':'", "';'", "'!'", "'['", "']'", "'<'", "'>'", "'{'", 
  "'}'", "'('", "')'"
};

std::vector<std::string> FaParser::_symbolicNames = {
  "", "AImport", "ALib", "Break", "CC__Cdecl", "CC__FastCall", "CC__StdCall", 
  "Continue", "Class", "Const", "Else", "FaEntryMain", "If", "Internal", 
  "Public", "Protected", "Private", "Return", "Signed", "Static", "Unsigned", 
  "Use", "While", "Assign", "ReverseOp", "AddAddOp", "SubSubOp", "PointOp", 
  "AddOp", "SubOp", "StarOp", "DivOp", "ModOp", "OrOp", "AndOp", "XorOp", 
  "Qus", "Comma", "ColonColon", "Colon", "Semi", "Exclam", "QuotFangL", 
  "QuotFangR", "QuotJianL", "QuotJianR", "QuotHuaL", "QuotHuaR", "QuotYuanL", 
  "QuotYuanR", "BoolLiteral", "IntLiteral", "FloatLiteral", "String1Literal", 
  "Id", "Comment1", "Comment2", "WS"
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
       0x3, 0x3b, 0x27f, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
       0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 
       0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 
       0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 
       0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
       0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
       0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
       0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
       0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xca, 0xa, 0x10, 0x3, 0x11, 
       0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 
       0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 
       0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 
       0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
       0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
       0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0xed, 0xa, 0x17, 0x3, 0x18, 0x3, 
       0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
       0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
       0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x101, 
       0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x105, 0xa, 0x1f, 0x3, 
       0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x7, 0x21, 0x10c, 
       0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 0x10f, 0xb, 0x21, 0x3, 0x22, 0x3, 
       0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x115, 0xa, 0x22, 0x3, 0x23, 
       0x5, 0x23, 0x118, 0xa, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 
       0x23, 0x3, 0x23, 0x3, 0x23, 0x7, 0x23, 0x120, 0xa, 0x23, 0xc, 0x23, 
       0xe, 0x23, 0x123, 0xb, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 
       0x23, 0x3, 0x23, 0x3, 0x23, 0x6, 0x23, 0x12b, 0xa, 0x23, 0xd, 0x23, 
       0xe, 0x23, 0x12c, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x131, 0xa, 0x23, 
       0x3, 0x23, 0x7, 0x23, 0x134, 0xa, 0x23, 0xc, 0x23, 0xe, 0x23, 0x137, 
       0xb, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 
       0x13d, 0xa, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x26, 0x5, 0x26, 0x142, 
       0xa, 0x26, 0x3, 0x26, 0x5, 0x26, 0x145, 0xa, 0x26, 0x3, 0x26, 0x3, 
       0x26, 0x7, 0x26, 0x149, 0xa, 0x26, 0xc, 0x26, 0xe, 0x26, 0x14c, 0xb, 
       0x26, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x150, 0xa, 0x27, 0x3, 0x28, 
       0x3, 0x28, 0x3, 0x28, 0x7, 0x28, 0x155, 0xa, 0x28, 0xc, 0x28, 0xe, 
       0x28, 0x158, 0xb, 0x28, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x15c, 0xa, 
       0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x7, 0x2a, 0x161, 0xa, 0x2a, 
       0xc, 0x2a, 0xe, 0x2a, 0x164, 0xb, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 
       0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x16d, 
       0xa, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x7, 0x2d, 0x171, 0xa, 0x2d, 0xc, 
       0x2d, 0xe, 0x2d, 0x174, 0xb, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 
       0x3, 0x2e, 0x7, 0x2e, 0x17a, 0xa, 0x2e, 0xc, 0x2e, 0xe, 0x2e, 0x17d, 
       0xb, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 
       0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x7, 0x2f, 0x188, 0xa, 
       0x2f, 0xc, 0x2f, 0xe, 0x2f, 0x18b, 0xb, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
       0x5, 0x2f, 0x18f, 0xa, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 
       0x30, 0x3, 0x30, 0x3, 0x30, 0x7, 0x30, 0x197, 0xa, 0x30, 0xc, 0x30, 
       0xe, 0x30, 0x19a, 0xb, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 
       0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 
       0x32, 0x7, 0x32, 0x1a6, 0xa, 0x32, 0xc, 0x32, 0xe, 0x32, 0x1a9, 0xb, 
       0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 
       0x33, 0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 
       0x35, 0x3, 0x35, 0x3, 0x35, 0x5, 0x35, 0x1b9, 0xa, 0x35, 0x3, 0x36, 
       0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x7, 0x36, 0x1c0, 0xa, 
       0x36, 0xc, 0x36, 0xe, 0x36, 0x1c3, 0xb, 0x36, 0x5, 0x36, 0x1c5, 0xa, 
       0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 
       0x36, 0x3, 0x36, 0x5, 0x36, 0x1ce, 0xa, 0x36, 0x3, 0x36, 0x3, 0x36, 
       0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x6, 0x36, 0x1d5, 0xa, 0x36, 0xd, 
       0x36, 0xe, 0x36, 0x1d6, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x6, 0x36, 
       0x1dc, 0xa, 0x36, 0xd, 0x36, 0xe, 0x36, 0x1dd, 0x3, 0x36, 0x3, 0x36, 
       0x5, 0x36, 0x1e2, 0xa, 0x36, 0x3, 0x36, 0x3, 0x36, 0x5, 0x36, 0x1e6, 
       0xa, 0x36, 0x3, 0x37, 0x7, 0x37, 0x1e9, 0xa, 0x37, 0xc, 0x37, 0xe, 
       0x37, 0x1ec, 0xb, 0x37, 0x3, 0x37, 0x3, 0x37, 0x7, 0x37, 0x1f0, 0xa, 
       0x37, 0xc, 0x37, 0xe, 0x37, 0x1f3, 0xb, 0x37, 0x3, 0x38, 0x3, 0x38, 
       0x3, 0x38, 0x5, 0x38, 0x1f8, 0xa, 0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 
       0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 
       0x3a, 0x3, 0x3a, 0x3, 0x3b, 0x5, 0x3b, 0x205, 0xa, 0x3b, 0x3, 0x3b, 
       0x3, 0x3b, 0x3, 0x3b, 0x5, 0x3b, 0x20a, 0xa, 0x3b, 0x3, 0x3b, 0x3, 
       0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x5, 0x3c, 0x212, 
       0xa, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 
       0x3, 0x3e, 0x7, 0x3e, 0x21a, 0xa, 0x3e, 0xc, 0x3e, 0xe, 0x3e, 0x21d, 
       0xb, 0x3e, 0x3, 0x3f, 0x5, 0x3f, 0x220, 0xa, 0x3f, 0x3, 0x3f, 0x5, 
       0x3f, 0x223, 0xa, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x40, 
       0x3, 0x40, 0x3, 0x40, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 
       0x3, 0x41, 0x3, 0x41, 0x7, 0x41, 0x231, 0xa, 0x41, 0xc, 0x41, 0xe, 
       0x41, 0x234, 0xb, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x42, 0x5, 0x42, 
       0x239, 0xa, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x5, 0x42, 0x23e, 
       0xa, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x7, 0x42, 0x243, 0xa, 
       0x42, 0xc, 0x42, 0xe, 0x42, 0x246, 0xb, 0x42, 0x3, 0x42, 0x3, 0x42, 
       0x3, 0x43, 0x3, 0x43, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 
       0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x45, 
       0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x46, 0x3, 0x46, 0x6, 0x46, 
       0x25b, 0xa, 0x46, 0xd, 0x46, 0xe, 0x46, 0x25c, 0x3, 0x47, 0x3, 0x47, 
       0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x7, 0x47, 
       0x266, 0xa, 0x47, 0xc, 0x47, 0xe, 0x47, 0x269, 0xb, 0x47, 0x3, 0x47, 
       0x3, 0x47, 0x3, 0x48, 0x7, 0x48, 0x26e, 0xa, 0x48, 0xc, 0x48, 0xe, 
       0x48, 0x271, 0xb, 0x48, 0x3, 0x48, 0x5, 0x48, 0x274, 0xa, 0x48, 0x3, 
       0x48, 0x7, 0x48, 0x277, 0xa, 0x48, 0xc, 0x48, 0xe, 0x48, 0x27a, 0xb, 
       0x48, 0x3, 0x48, 0x5, 0x48, 0x27d, 0xa, 0x48, 0x3, 0x48, 0x2, 0x2, 
       0x49, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 
       0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 
       0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 
       0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 
       0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 
       0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 
       0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x2, 0x8, 0x3, 0x2, 0x34, 0x37, 0x4, 
       0x2, 0x14, 0x14, 0x16, 0x16, 0x4, 0x2, 0x1a, 0x1c, 0x1e, 0x1f, 0x3, 
       0x2, 0x1b, 0x1c, 0x3, 0x2, 0xf, 0x12, 0x3, 0x2, 0x6, 0x8, 0x2, 0x297, 
       0x2, 0x90, 0x3, 0x2, 0x2, 0x2, 0x4, 0x93, 0x3, 0x2, 0x2, 0x2, 0x6, 
       0x96, 0x3, 0x2, 0x2, 0x2, 0x8, 0x99, 0x3, 0x2, 0x2, 0x2, 0xa, 0x9c, 
       0x3, 0x2, 0x2, 0x2, 0xc, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xe, 0xa2, 0x3, 
       0x2, 0x2, 0x2, 0x10, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x12, 0xa8, 0x3, 0x2, 
       0x2, 0x2, 0x14, 0xab, 0x3, 0x2, 0x2, 0x2, 0x16, 0xae, 0x3, 0x2, 0x2, 
       0x2, 0x18, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xb4, 0x3, 0x2, 0x2, 0x2, 
       0x1c, 0xb7, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xc9, 0x3, 0x2, 0x2, 0x2, 0x20, 
       0xcb, 0x3, 0x2, 0x2, 0x2, 0x22, 0xce, 0x3, 0x2, 0x2, 0x2, 0x24, 0xd1, 
       0x3, 0x2, 0x2, 0x2, 0x26, 0xd4, 0x3, 0x2, 0x2, 0x2, 0x28, 0xd7, 0x3, 
       0x2, 0x2, 0x2, 0x2a, 0xda, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xec, 0x3, 0x2, 
       0x2, 0x2, 0x2e, 0xee, 0x3, 0x2, 0x2, 0x2, 0x30, 0xf0, 0x3, 0x2, 0x2, 
       0x2, 0x32, 0xf3, 0x3, 0x2, 0x2, 0x2, 0x34, 0xf5, 0x3, 0x2, 0x2, 0x2, 
       0x36, 0xf8, 0x3, 0x2, 0x2, 0x2, 0x38, 0xfb, 0x3, 0x2, 0x2, 0x2, 0x3a, 
       0x100, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x104, 0x3, 0x2, 0x2, 0x2, 0x3e, 
       0x106, 0x3, 0x2, 0x2, 0x2, 0x40, 0x108, 0x3, 0x2, 0x2, 0x2, 0x42, 
       0x114, 0x3, 0x2, 0x2, 0x2, 0x44, 0x117, 0x3, 0x2, 0x2, 0x2, 0x46, 
       0x13c, 0x3, 0x2, 0x2, 0x2, 0x48, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x4a, 
       0x141, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x4e, 
       0x151, 0x3, 0x2, 0x2, 0x2, 0x50, 0x159, 0x3, 0x2, 0x2, 0x2, 0x52, 
       0x15d, 0x3, 0x2, 0x2, 0x2, 0x54, 0x165, 0x3, 0x2, 0x2, 0x2, 0x56, 
       0x16c, 0x3, 0x2, 0x2, 0x2, 0x58, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x5a, 
       0x177, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x181, 0x3, 0x2, 0x2, 0x2, 0x5e, 
       0x190, 0x3, 0x2, 0x2, 0x2, 0x60, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x62, 
       0x19f, 0x3, 0x2, 0x2, 0x2, 0x64, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x66, 
       0x1b0, 0x3, 0x2, 0x2, 0x2, 0x68, 0x1b8, 0x3, 0x2, 0x2, 0x2, 0x6a, 
       0x1e5, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x1ea, 0x3, 0x2, 0x2, 0x2, 0x6e, 
       0x1f7, 0x3, 0x2, 0x2, 0x2, 0x70, 0x1f9, 0x3, 0x2, 0x2, 0x2, 0x72, 
       0x1ff, 0x3, 0x2, 0x2, 0x2, 0x74, 0x209, 0x3, 0x2, 0x2, 0x2, 0x76, 
       0x211, 0x3, 0x2, 0x2, 0x2, 0x78, 0x213, 0x3, 0x2, 0x2, 0x2, 0x7a, 
       0x215, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x21f, 0x3, 0x2, 0x2, 0x2, 0x7e, 
       0x227, 0x3, 0x2, 0x2, 0x2, 0x80, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x82, 
       0x238, 0x3, 0x2, 0x2, 0x2, 0x84, 0x249, 0x3, 0x2, 0x2, 0x2, 0x86, 
       0x24b, 0x3, 0x2, 0x2, 0x2, 0x88, 0x254, 0x3, 0x2, 0x2, 0x2, 0x8a, 
       0x25a, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x25e, 0x3, 0x2, 0x2, 0x2, 0x8e, 
       0x26f, 0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 0x7, 0x1e, 0x2, 0x2, 0x91, 
       0x92, 0x7, 0x19, 0x2, 0x2, 0x92, 0x3, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 
       0x7, 0x1f, 0x2, 0x2, 0x94, 0x95, 0x7, 0x19, 0x2, 0x2, 0x95, 0x5, 
       0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 0x7, 0x20, 0x2, 0x2, 0x97, 0x98, 
       0x7, 0x19, 0x2, 0x2, 0x98, 0x7, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0x7, 
       0x21, 0x2, 0x2, 0x9a, 0x9b, 0x7, 0x19, 0x2, 0x2, 0x9b, 0x9, 0x3, 
       0x2, 0x2, 0x2, 0x9c, 0x9d, 0x7, 0x22, 0x2, 0x2, 0x9d, 0x9e, 0x7, 
       0x19, 0x2, 0x2, 0x9e, 0xb, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 0x7, 0x23, 
       0x2, 0x2, 0xa0, 0xa1, 0x7, 0x19, 0x2, 0x2, 0xa1, 0xd, 0x3, 0x2, 0x2, 
       0x2, 0xa2, 0xa3, 0x7, 0x24, 0x2, 0x2, 0xa3, 0xa4, 0x7, 0x19, 0x2, 
       0x2, 0xa4, 0xf, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 0x7, 0x25, 0x2, 0x2, 
       0xa6, 0xa7, 0x7, 0x19, 0x2, 0x2, 0xa7, 0x11, 0x3, 0x2, 0x2, 0x2, 
       0xa8, 0xa9, 0x5, 0x20, 0x11, 0x2, 0xa9, 0xaa, 0x7, 0x19, 0x2, 0x2, 
       0xaa, 0x13, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x5, 0x22, 0x12, 0x2, 
       0xac, 0xad, 0x7, 0x19, 0x2, 0x2, 0xad, 0x15, 0x3, 0x2, 0x2, 0x2, 
       0xae, 0xaf, 0x5, 0x24, 0x13, 0x2, 0xaf, 0xb0, 0x7, 0x19, 0x2, 0x2, 
       0xb0, 0x17, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x5, 0x26, 0x14, 0x2, 
       0xb2, 0xb3, 0x7, 0x19, 0x2, 0x2, 0xb3, 0x19, 0x3, 0x2, 0x2, 0x2, 
       0xb4, 0xb5, 0x5, 0x28, 0x15, 0x2, 0xb5, 0xb6, 0x7, 0x19, 0x2, 0x2, 
       0xb6, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x5, 0x2a, 0x16, 0x2, 
       0xb8, 0xb9, 0x7, 0x19, 0x2, 0x2, 0xb9, 0x1d, 0x3, 0x2, 0x2, 0x2, 
       0xba, 0xca, 0x7, 0x19, 0x2, 0x2, 0xbb, 0xca, 0x5, 0x12, 0xa, 0x2, 
       0xbc, 0xca, 0x5, 0x2, 0x2, 0x2, 0xbd, 0xca, 0x5, 0x4, 0x3, 0x2, 0xbe, 
       0xca, 0x5, 0x6, 0x4, 0x2, 0xbf, 0xca, 0x5, 0x14, 0xb, 0x2, 0xc0, 
       0xca, 0x5, 0x8, 0x5, 0x2, 0xc1, 0xca, 0x5, 0xa, 0x6, 0x2, 0xc2, 0xca, 
       0x5, 0xe, 0x8, 0x2, 0xc3, 0xca, 0x5, 0xc, 0x7, 0x2, 0xc4, 0xca, 0x5, 
       0x10, 0x9, 0x2, 0xc5, 0xca, 0x5, 0x16, 0xc, 0x2, 0xc6, 0xca, 0x5, 
       0x18, 0xd, 0x2, 0xc7, 0xca, 0x5, 0x1a, 0xe, 0x2, 0xc8, 0xca, 0x5, 
       0x1c, 0xf, 0x2, 0xc9, 0xba, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xbb, 0x3, 
       0x2, 0x2, 0x2, 0xc9, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xbd, 0x3, 0x2, 
       0x2, 0x2, 0xc9, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xbf, 0x3, 0x2, 0x2, 
       0x2, 0xc9, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xc1, 0x3, 0x2, 0x2, 0x2, 
       0xc9, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc9, 
       0xc4, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xc6, 
       0x3, 0x2, 0x2, 0x2, 0xc9, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xc8, 0x3, 
       0x2, 0x2, 0x2, 0xca, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x7, 0x26, 
       0x2, 0x2, 0xcc, 0xcd, 0x7, 0x26, 0x2, 0x2, 0xcd, 0x21, 0x3, 0x2, 
       0x2, 0x2, 0xce, 0xcf, 0x7, 0x20, 0x2, 0x2, 0xcf, 0xd0, 0x7, 0x20, 
       0x2, 0x2, 0xd0, 0x23, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x7, 0x24, 
       0x2, 0x2, 0xd2, 0xd3, 0x7, 0x24, 0x2, 0x2, 0xd3, 0x25, 0x3, 0x2, 
       0x2, 0x2, 0xd4, 0xd5, 0x7, 0x23, 0x2, 0x2, 0xd5, 0xd6, 0x7, 0x23, 
       0x2, 0x2, 0xd6, 0x27, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 0x7, 0x2e, 
       0x2, 0x2, 0xd8, 0xd9, 0x7, 0x2e, 0x2, 0x2, 0xd9, 0x29, 0x3, 0x2, 
       0x2, 0x2, 0xda, 0xdb, 0x7, 0x2f, 0x2, 0x2, 0xdb, 0xdc, 0x7, 0x2f, 
       0x2, 0x2, 0xdc, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xed, 0x5, 0x20, 
       0x11, 0x2, 0xde, 0xed, 0x7, 0x1d, 0x2, 0x2, 0xdf, 0xed, 0x7, 0x1e, 
       0x2, 0x2, 0xe0, 0xed, 0x7, 0x1f, 0x2, 0x2, 0xe1, 0xed, 0x7, 0x20, 
       0x2, 0x2, 0xe2, 0xed, 0x7, 0x21, 0x2, 0x2, 0xe3, 0xed, 0x5, 0x22, 
       0x12, 0x2, 0xe4, 0xed, 0x7, 0x22, 0x2, 0x2, 0xe5, 0xed, 0x7, 0x24, 
       0x2, 0x2, 0xe6, 0xed, 0x7, 0x23, 0x2, 0x2, 0xe7, 0xed, 0x7, 0x25, 
       0x2, 0x2, 0xe8, 0xed, 0x5, 0x24, 0x13, 0x2, 0xe9, 0xed, 0x5, 0x26, 
       0x14, 0x2, 0xea, 0xed, 0x5, 0x28, 0x15, 0x2, 0xeb, 0xed, 0x5, 0x2a, 
       0x16, 0x2, 0xec, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xec, 0xde, 0x3, 0x2, 
       0x2, 0x2, 0xec, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xec, 0xe0, 0x3, 0x2, 0x2, 
       0x2, 0xec, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xec, 0xe2, 0x3, 0x2, 0x2, 0x2, 
       0xec, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xec, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xec, 
       0xe5, 0x3, 0x2, 0x2, 0x2, 0xec, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xec, 0xe7, 
       0x3, 0x2, 0x2, 0x2, 0xec, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xec, 0xe9, 0x3, 
       0x2, 0x2, 0x2, 0xec, 0xea, 0x3, 0x2, 0x2, 0x2, 0xec, 0xeb, 0x3, 0x2, 
       0x2, 0x2, 0xed, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 0x7, 0x2e, 
       0x2, 0x2, 0xef, 0x2f, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf1, 0x7, 0x2e, 
       0x2, 0x2, 0xf1, 0xf2, 0x7, 0x19, 0x2, 0x2, 0xf2, 0x31, 0x3, 0x2, 
       0x2, 0x2, 0xf3, 0xf4, 0x7, 0x2f, 0x2, 0x2, 0xf4, 0x33, 0x3, 0x2, 
       0x2, 0x2, 0xf5, 0xf6, 0x7, 0x2f, 0x2, 0x2, 0xf6, 0xf7, 0x7, 0x19, 
       0x2, 0x2, 0xf7, 0x35, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x7, 0x19, 
       0x2, 0x2, 0xf9, 0xfa, 0x7, 0x19, 0x2, 0x2, 0xfa, 0x37, 0x3, 0x2, 
       0x2, 0x2, 0xfb, 0xfc, 0x7, 0x2b, 0x2, 0x2, 0xfc, 0xfd, 0x7, 0x19, 
       0x2, 0x2, 0xfd, 0x39, 0x3, 0x2, 0x2, 0x2, 0xfe, 0x101, 0x5, 0x2e, 
       0x18, 0x2, 0xff, 0x101, 0x5, 0x30, 0x19, 0x2, 0x100, 0xfe, 0x3, 0x2, 
       0x2, 0x2, 0x100, 0xff, 0x3, 0x2, 0x2, 0x2, 0x101, 0x3b, 0x3, 0x2, 
       0x2, 0x2, 0x102, 0x105, 0x5, 0x32, 0x1a, 0x2, 0x103, 0x105, 0x5, 
       0x34, 0x1b, 0x2, 0x104, 0x102, 0x3, 0x2, 0x2, 0x2, 0x104, 0x103, 
       0x3, 0x2, 0x2, 0x2, 0x105, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x106, 0x107, 
       0x9, 0x2, 0x2, 0x2, 0x107, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x108, 0x10d, 
       0x7, 0x38, 0x2, 0x2, 0x109, 0x10a, 0x7, 0x1d, 0x2, 0x2, 0x10a, 0x10c, 
       0x7, 0x38, 0x2, 0x2, 0x10b, 0x109, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10f, 
       0x3, 0x2, 0x2, 0x2, 0x10d, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 
       0x3, 0x2, 0x2, 0x2, 0x10e, 0x41, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x10d, 
       0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 0x7, 0x2c, 0x2, 0x2, 0x111, 0x115, 
       0x7, 0x2d, 0x2, 0x2, 0x112, 0x115, 0x7, 0x24, 0x2, 0x2, 0x113, 0x115, 
       0x7, 0x26, 0x2, 0x2, 0x114, 0x110, 0x3, 0x2, 0x2, 0x2, 0x114, 0x112, 
       0x3, 0x2, 0x2, 0x2, 0x114, 0x113, 0x3, 0x2, 0x2, 0x2, 0x115, 0x43, 
       0x3, 0x2, 0x2, 0x2, 0x116, 0x118, 0x7, 0xb, 0x2, 0x2, 0x117, 0x116, 
       0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 0x3, 0x2, 0x2, 0x2, 0x118, 0x130, 
       0x3, 0x2, 0x2, 0x2, 0x119, 0x131, 0x7, 0x38, 0x2, 0x2, 0x11a, 0x11b, 
       0x7, 0x38, 0x2, 0x2, 0x11b, 0x11c, 0x7, 0x2e, 0x2, 0x2, 0x11c, 0x121, 
       0x5, 0x44, 0x23, 0x2, 0x11d, 0x11e, 0x7, 0x27, 0x2, 0x2, 0x11e, 0x120, 
       0x5, 0x44, 0x23, 0x2, 0x11f, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x120, 0x123, 
       0x3, 0x2, 0x2, 0x2, 0x121, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x121, 0x122, 
       0x3, 0x2, 0x2, 0x2, 0x122, 0x124, 0x3, 0x2, 0x2, 0x2, 0x123, 0x121, 
       0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 0x7, 0x2f, 0x2, 0x2, 0x125, 0x131, 
       0x3, 0x2, 0x2, 0x2, 0x126, 0x127, 0x7, 0x32, 0x2, 0x2, 0x127, 0x12a, 
       0x5, 0x44, 0x23, 0x2, 0x128, 0x129, 0x7, 0x27, 0x2, 0x2, 0x129, 0x12b, 
       0x5, 0x44, 0x23, 0x2, 0x12a, 0x128, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 
       0x3, 0x2, 0x2, 0x2, 0x12c, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 
       0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12f, 
       0x7, 0x33, 0x2, 0x2, 0x12f, 0x131, 0x3, 0x2, 0x2, 0x2, 0x130, 0x119, 
       0x3, 0x2, 0x2, 0x2, 0x130, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x130, 0x126, 
       0x3, 0x2, 0x2, 0x2, 0x131, 0x135, 0x3, 0x2, 0x2, 0x2, 0x132, 0x134, 
       0x5, 0x42, 0x22, 0x2, 0x133, 0x132, 0x3, 0x2, 0x2, 0x2, 0x134, 0x137, 
       0x3, 0x2, 0x2, 0x2, 0x135, 0x133, 0x3, 0x2, 0x2, 0x2, 0x135, 0x136, 
       0x3, 0x2, 0x2, 0x2, 0x136, 0x45, 0x3, 0x2, 0x2, 0x2, 0x137, 0x135, 
       0x3, 0x2, 0x2, 0x2, 0x138, 0x139, 0x7, 0x2c, 0x2, 0x2, 0x139, 0x13d, 
       0x7, 0x2d, 0x2, 0x2, 0x13a, 0x13d, 0x7, 0x24, 0x2, 0x2, 0x13b, 0x13d, 
       0x7, 0x20, 0x2, 0x2, 0x13c, 0x138, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13a, 
       0x3, 0x2, 0x2, 0x2, 0x13c, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x47, 
       0x3, 0x2, 0x2, 0x2, 0x13e, 0x13f, 0x9, 0x3, 0x2, 0x2, 0x13f, 0x49, 
       0x3, 0x2, 0x2, 0x2, 0x140, 0x142, 0x7, 0xb, 0x2, 0x2, 0x141, 0x140, 
       0x3, 0x2, 0x2, 0x2, 0x141, 0x142, 0x3, 0x2, 0x2, 0x2, 0x142, 0x144, 
       0x3, 0x2, 0x2, 0x2, 0x143, 0x145, 0x5, 0x48, 0x25, 0x2, 0x144, 0x143, 
       0x3, 0x2, 0x2, 0x2, 0x144, 0x145, 0x3, 0x2, 0x2, 0x2, 0x145, 0x146, 
       0x3, 0x2, 0x2, 0x2, 0x146, 0x14a, 0x7, 0x38, 0x2, 0x2, 0x147, 0x149, 
       0x5, 0x46, 0x24, 0x2, 0x148, 0x147, 0x3, 0x2, 0x2, 0x2, 0x149, 0x14c, 
       0x3, 0x2, 0x2, 0x2, 0x14a, 0x148, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14b, 
       0x3, 0x2, 0x2, 0x2, 0x14b, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x14a, 
       0x3, 0x2, 0x2, 0x2, 0x14d, 0x14f, 0x5, 0x44, 0x23, 0x2, 0x14e, 0x150, 
       0x7, 0x38, 0x2, 0x2, 0x14f, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x150, 
       0x3, 0x2, 0x2, 0x2, 0x150, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x151, 0x156, 
       0x5, 0x4c, 0x27, 0x2, 0x152, 0x153, 0x7, 0x27, 0x2, 0x2, 0x153, 0x155, 
       0x5, 0x4c, 0x27, 0x2, 0x154, 0x152, 0x3, 0x2, 0x2, 0x2, 0x155, 0x158, 
       0x3, 0x2, 0x2, 0x2, 0x156, 0x154, 0x3, 0x2, 0x2, 0x2, 0x156, 0x157, 
       0x3, 0x2, 0x2, 0x2, 0x157, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x158, 0x156, 
       0x3, 0x2, 0x2, 0x2, 0x159, 0x15b, 0x5, 0x4a, 0x26, 0x2, 0x15a, 0x15c, 
       0x7, 0x38, 0x2, 0x2, 0x15b, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x15c, 
       0x3, 0x2, 0x2, 0x2, 0x15c, 0x51, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x162, 
       0x5, 0x50, 0x29, 0x2, 0x15e, 0x15f, 0x7, 0x27, 0x2, 0x2, 0x15f, 0x161, 
       0x5, 0x50, 0x29, 0x2, 0x160, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x161, 0x164, 
       0x3, 0x2, 0x2, 0x2, 0x162, 0x160, 0x3, 0x2, 0x2, 0x2, 0x162, 0x163, 
       0x3, 0x2, 0x2, 0x2, 0x163, 0x53, 0x3, 0x2, 0x2, 0x2, 0x164, 0x162, 
       0x3, 0x2, 0x2, 0x2, 0x165, 0x166, 0x7, 0xe, 0x2, 0x2, 0x166, 0x167, 
       0x7, 0x32, 0x2, 0x2, 0x167, 0x168, 0x5, 0x6e, 0x38, 0x2, 0x168, 0x169, 
       0x7, 0x33, 0x2, 0x2, 0x169, 0x55, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x16d, 
       0x5, 0x76, 0x3c, 0x2, 0x16b, 0x16d, 0x5, 0x5e, 0x30, 0x2, 0x16c, 
       0x16a, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x16d, 
       0x57, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x172, 0x7, 0x30, 0x2, 0x2, 0x16f, 
       0x171, 0x5, 0x76, 0x3c, 0x2, 0x170, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x171, 
       0x174, 0x3, 0x2, 0x2, 0x2, 0x172, 0x170, 0x3, 0x2, 0x2, 0x2, 0x172, 
       0x173, 0x3, 0x2, 0x2, 0x2, 0x173, 0x175, 0x3, 0x2, 0x2, 0x2, 0x174, 
       0x172, 0x3, 0x2, 0x2, 0x2, 0x175, 0x176, 0x7, 0x31, 0x2, 0x2, 0x176, 
       0x59, 0x3, 0x2, 0x2, 0x2, 0x177, 0x17b, 0x7, 0x30, 0x2, 0x2, 0x178, 
       0x17a, 0x5, 0x56, 0x2c, 0x2, 0x179, 0x178, 0x3, 0x2, 0x2, 0x2, 0x17a, 
       0x17d, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x179, 0x3, 0x2, 0x2, 0x2, 0x17b, 
       0x17c, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x17d, 
       0x17b, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x17f, 0x5, 0x6e, 0x38, 0x2, 0x17f, 
       0x180, 0x7, 0x31, 0x2, 0x2, 0x180, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x181, 
       0x182, 0x5, 0x54, 0x2b, 0x2, 0x182, 0x189, 0x5, 0x58, 0x2d, 0x2, 
       0x183, 0x184, 0x7, 0xc, 0x2, 0x2, 0x184, 0x185, 0x5, 0x54, 0x2b, 
       0x2, 0x185, 0x186, 0x5, 0x58, 0x2d, 0x2, 0x186, 0x188, 0x3, 0x2, 
       0x2, 0x2, 0x187, 0x183, 0x3, 0x2, 0x2, 0x2, 0x188, 0x18b, 0x3, 0x2, 
       0x2, 0x2, 0x189, 0x187, 0x3, 0x2, 0x2, 0x2, 0x189, 0x18a, 0x3, 0x2, 
       0x2, 0x2, 0x18a, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x189, 0x3, 0x2, 
       0x2, 0x2, 0x18c, 0x18d, 0x7, 0xc, 0x2, 0x2, 0x18d, 0x18f, 0x5, 0x58, 
       0x2d, 0x2, 0x18e, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x18f, 0x3, 0x2, 
       0x2, 0x2, 0x18f, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x190, 0x191, 0x5, 0x54, 
       0x2b, 0x2, 0x191, 0x198, 0x5, 0x5a, 0x2e, 0x2, 0x192, 0x193, 0x7, 
       0xc, 0x2, 0x2, 0x193, 0x194, 0x5, 0x54, 0x2b, 0x2, 0x194, 0x195, 
       0x5, 0x5a, 0x2e, 0x2, 0x195, 0x197, 0x3, 0x2, 0x2, 0x2, 0x196, 0x192, 
       0x3, 0x2, 0x2, 0x2, 0x197, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x198, 0x196, 
       0x3, 0x2, 0x2, 0x2, 0x198, 0x199, 0x3, 0x2, 0x2, 0x2, 0x199, 0x5f, 
       0x3, 0x2, 0x2, 0x2, 0x19a, 0x198, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x19c, 
       0x5, 0x5e, 0x30, 0x2, 0x19c, 0x19d, 0x7, 0xc, 0x2, 0x2, 0x19d, 0x19e, 
       0x5, 0x5a, 0x2e, 0x2, 0x19e, 0x61, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a0, 
       0x7, 0x18, 0x2, 0x2, 0x1a0, 0x1a1, 0x7, 0x32, 0x2, 0x2, 0x1a1, 0x1a2, 
       0x5, 0x6e, 0x38, 0x2, 0x1a2, 0x1a3, 0x7, 0x33, 0x2, 0x2, 0x1a3, 0x1a7, 
       0x7, 0x30, 0x2, 0x2, 0x1a4, 0x1a6, 0x5, 0x76, 0x3c, 0x2, 0x1a5, 0x1a4, 
       0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a9, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a5, 
       0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1aa, 
       0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1ab, 
       0x7, 0x31, 0x2, 0x2, 0x1ab, 0x63, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1ad, 
       0x7, 0x32, 0x2, 0x2, 0x1ad, 0x1ae, 0x5, 0x6e, 0x38, 0x2, 0x1ae, 0x1af, 
       0x7, 0x33, 0x2, 0x2, 0x1af, 0x65, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1b1, 
       0x9, 0x4, 0x2, 0x2, 0x1b1, 0x67, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b9, 
       0x5, 0x40, 0x21, 0x2, 0x1b3, 0x1b4, 0x7, 0x28, 0x2, 0x2, 0x1b4, 0x1b9, 
       0x7, 0x38, 0x2, 0x2, 0x1b5, 0x1b9, 0x5, 0x3e, 0x20, 0x2, 0x1b6, 0x1b9, 
       0x5, 0x60, 0x31, 0x2, 0x1b7, 0x1b9, 0x5, 0x64, 0x33, 0x2, 0x1b8, 
       0x1b2, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x1b8, 
       0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1b8, 
       0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1b9, 0x69, 0x3, 0x2, 0x2, 0x2, 0x1ba, 
       0x1e6, 0x9, 0x5, 0x2, 0x2, 0x1bb, 0x1c4, 0x7, 0x32, 0x2, 0x2, 0x1bc, 
       0x1c1, 0x5, 0x6e, 0x38, 0x2, 0x1bd, 0x1be, 0x7, 0x27, 0x2, 0x2, 0x1be, 
       0x1c0, 0x5, 0x6e, 0x38, 0x2, 0x1bf, 0x1bd, 0x3, 0x2, 0x2, 0x2, 0x1c0, 
       0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1c1, 
       0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1c3, 
       0x1c1, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1c4, 
       0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1c6, 
       0x1e6, 0x7, 0x33, 0x2, 0x2, 0x1c7, 0x1c8, 0x7, 0x2c, 0x2, 0x2, 0x1c8, 
       0x1c9, 0x5, 0x6e, 0x38, 0x2, 0x1c9, 0x1ca, 0x7, 0x2d, 0x2, 0x2, 0x1ca, 
       0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1ce, 0x5, 0x1e, 0x10, 0x2, 0x1cc, 
       0x1ce, 0x5, 0x2c, 0x17, 0x2, 0x1cd, 0x1cb, 0x3, 0x2, 0x2, 0x2, 0x1cd, 
       0x1cc, 0x3, 0x2, 0x2, 0x2, 0x1ce, 0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1cf, 
       0x1d0, 0x5, 0x6e, 0x38, 0x2, 0x1d0, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1d1, 
       0x1d2, 0x5, 0x3a, 0x1e, 0x2, 0x1d2, 0x1d3, 0x5, 0x6e, 0x38, 0x2, 
       0x1d3, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d1, 0x3, 0x2, 0x2, 0x2, 
       0x1d5, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1d4, 0x3, 0x2, 0x2, 0x2, 
       0x1d6, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1e6, 0x3, 0x2, 0x2, 0x2, 
       0x1d8, 0x1d9, 0x5, 0x3c, 0x1f, 0x2, 0x1d9, 0x1da, 0x5, 0x6e, 0x38, 
       0x2, 0x1da, 0x1dc, 0x3, 0x2, 0x2, 0x2, 0x1db, 0x1d8, 0x3, 0x2, 0x2, 
       0x2, 0x1dc, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1db, 0x3, 0x2, 0x2, 
       0x2, 0x1dd, 0x1de, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x1e6, 0x3, 0x2, 0x2, 
       0x2, 0x1df, 0x1e2, 0x5, 0x36, 0x1c, 0x2, 0x1e0, 0x1e2, 0x5, 0x38, 
       0x1d, 0x2, 0x1e1, 0x1df, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1e0, 0x3, 0x2, 
       0x2, 0x2, 0x1e2, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e4, 0x5, 0x6e, 
       0x38, 0x2, 0x1e4, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1ba, 0x3, 0x2, 
       0x2, 0x2, 0x1e5, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1c7, 0x3, 0x2, 
       0x2, 0x2, 0x1e5, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1d4, 0x3, 0x2, 
       0x2, 0x2, 0x1e5, 0x1db, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1e1, 0x3, 0x2, 
       0x2, 0x2, 0x1e6, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1e9, 0x5, 0x66, 
       0x34, 0x2, 0x1e8, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1e9, 0x1ec, 0x3, 0x2, 
       0x2, 0x2, 0x1ea, 0x1e8, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1eb, 0x3, 0x2, 
       0x2, 0x2, 0x1eb, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1ec, 0x1ea, 0x3, 0x2, 
       0x2, 0x2, 0x1ed, 0x1f1, 0x5, 0x68, 0x35, 0x2, 0x1ee, 0x1f0, 0x5, 
       0x6a, 0x36, 0x2, 0x1ef, 0x1ee, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1f3, 
       0x3, 0x2, 0x2, 0x2, 0x1f1, 0x1ef, 0x3, 0x2, 0x2, 0x2, 0x1f1, 0x1f2, 
       0x3, 0x2, 0x2, 0x2, 0x1f2, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f1, 
       0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1f8, 0x5, 0x60, 0x31, 0x2, 0x1f5, 0x1f8, 
       0x5, 0x64, 0x33, 0x2, 0x1f6, 0x1f8, 0x5, 0x6c, 0x37, 0x2, 0x1f7, 
       0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1f7, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f7, 
       0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1f8, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x1f9, 
       0x1fa, 0x5, 0x44, 0x23, 0x2, 0x1fa, 0x1fb, 0x7, 0x38, 0x2, 0x2, 0x1fb, 
       0x1fc, 0x7, 0x19, 0x2, 0x2, 0x1fc, 0x1fd, 0x5, 0x6e, 0x38, 0x2, 0x1fd, 
       0x1fe, 0x7, 0x2a, 0x2, 0x2, 0x1fe, 0x71, 0x3, 0x2, 0x2, 0x2, 0x1ff, 
       0x200, 0x7, 0x17, 0x2, 0x2, 0x200, 0x201, 0x5, 0x40, 0x21, 0x2, 0x201, 
       0x202, 0x7, 0x2a, 0x2, 0x2, 0x202, 0x73, 0x3, 0x2, 0x2, 0x2, 0x203, 
       0x205, 0x7, 0x13, 0x2, 0x2, 0x204, 0x203, 0x3, 0x2, 0x2, 0x2, 0x204, 
       0x205, 0x3, 0x2, 0x2, 0x2, 0x205, 0x206, 0x3, 0x2, 0x2, 0x2, 0x206, 
       0x20a, 0x5, 0x6e, 0x38, 0x2, 0x207, 0x20a, 0x7, 0x5, 0x2, 0x2, 0x208, 
       0x20a, 0x7, 0x9, 0x2, 0x2, 0x209, 0x204, 0x3, 0x2, 0x2, 0x2, 0x209, 
       0x207, 0x3, 0x2, 0x2, 0x2, 0x209, 0x208, 0x3, 0x2, 0x2, 0x2, 0x20a, 
       0x20b, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x20c, 0x7, 0x2a, 0x2, 0x2, 0x20c, 
       0x75, 0x3, 0x2, 0x2, 0x2, 0x20d, 0x212, 0x5, 0x74, 0x3b, 0x2, 0x20e, 
       0x212, 0x5, 0x5c, 0x2f, 0x2, 0x20f, 0x212, 0x5, 0x62, 0x32, 0x2, 
       0x210, 0x212, 0x5, 0x70, 0x39, 0x2, 0x211, 0x20d, 0x3, 0x2, 0x2, 
       0x2, 0x211, 0x20e, 0x3, 0x2, 0x2, 0x2, 0x211, 0x20f, 0x3, 0x2, 0x2, 
       0x2, 0x211, 0x210, 0x3, 0x2, 0x2, 0x2, 0x212, 0x77, 0x3, 0x2, 0x2, 
       0x2, 0x213, 0x214, 0x9, 0x6, 0x2, 0x2, 0x214, 0x79, 0x3, 0x2, 0x2, 
       0x2, 0x215, 0x216, 0x7, 0x29, 0x2, 0x2, 0x216, 0x21b, 0x5, 0x40, 
       0x21, 0x2, 0x217, 0x218, 0x7, 0x27, 0x2, 0x2, 0x218, 0x21a, 0x5, 
       0x40, 0x21, 0x2, 0x219, 0x217, 0x3, 0x2, 0x2, 0x2, 0x21a, 0x21d, 
       0x3, 0x2, 0x2, 0x2, 0x21b, 0x219, 0x3, 0x2, 0x2, 0x2, 0x21b, 0x21c, 
       0x3, 0x2, 0x2, 0x2, 0x21c, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x21d, 0x21b, 
       0x3, 0x2, 0x2, 0x2, 0x21e, 0x220, 0x5, 0x78, 0x3d, 0x2, 0x21f, 0x21e, 
       0x3, 0x2, 0x2, 0x2, 0x21f, 0x220, 0x3, 0x2, 0x2, 0x2, 0x220, 0x222, 
       0x3, 0x2, 0x2, 0x2, 0x221, 0x223, 0x7, 0x15, 0x2, 0x2, 0x222, 0x221, 
       0x3, 0x2, 0x2, 0x2, 0x222, 0x223, 0x3, 0x2, 0x2, 0x2, 0x223, 0x224, 
       0x3, 0x2, 0x2, 0x2, 0x224, 0x225, 0x7, 0x38, 0x2, 0x2, 0x225, 0x226, 
       0x7, 0x38, 0x2, 0x2, 0x226, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x227, 0x228, 
       0x5, 0x7c, 0x3f, 0x2, 0x228, 0x229, 0x7, 0x2a, 0x2, 0x2, 0x229, 0x7f, 
       0x3, 0x2, 0x2, 0x2, 0x22a, 0x22b, 0x5, 0x7c, 0x3f, 0x2, 0x22b, 0x22c, 
       0x7, 0x32, 0x2, 0x2, 0x22c, 0x22d, 0x5, 0x4e, 0x28, 0x2, 0x22d, 0x22e, 
       0x7, 0x33, 0x2, 0x2, 0x22e, 0x232, 0x7, 0x30, 0x2, 0x2, 0x22f, 0x231, 
       0x5, 0x76, 0x3c, 0x2, 0x230, 0x22f, 0x3, 0x2, 0x2, 0x2, 0x231, 0x234, 
       0x3, 0x2, 0x2, 0x2, 0x232, 0x230, 0x3, 0x2, 0x2, 0x2, 0x232, 0x233, 
       0x3, 0x2, 0x2, 0x2, 0x233, 0x235, 0x3, 0x2, 0x2, 0x2, 0x234, 0x232, 
       0x3, 0x2, 0x2, 0x2, 0x235, 0x236, 0x7, 0x31, 0x2, 0x2, 0x236, 0x81, 
       0x3, 0x2, 0x2, 0x2, 0x237, 0x239, 0x5, 0x78, 0x3d, 0x2, 0x238, 0x237, 
       0x3, 0x2, 0x2, 0x2, 0x238, 0x239, 0x3, 0x2, 0x2, 0x2, 0x239, 0x23a, 
       0x3, 0x2, 0x2, 0x2, 0x23a, 0x23b, 0x7, 0xa, 0x2, 0x2, 0x23b, 0x23d, 
       0x7, 0x38, 0x2, 0x2, 0x23c, 0x23e, 0x5, 0x7a, 0x3e, 0x2, 0x23d, 0x23c, 
       0x3, 0x2, 0x2, 0x2, 0x23d, 0x23e, 0x3, 0x2, 0x2, 0x2, 0x23e, 0x23f, 
       0x3, 0x2, 0x2, 0x2, 0x23f, 0x244, 0x7, 0x30, 0x2, 0x2, 0x240, 0x243, 
       0x5, 0x7e, 0x40, 0x2, 0x241, 0x243, 0x5, 0x80, 0x41, 0x2, 0x242, 
       0x240, 0x3, 0x2, 0x2, 0x2, 0x242, 0x241, 0x3, 0x2, 0x2, 0x2, 0x243, 
       0x246, 0x3, 0x2, 0x2, 0x2, 0x244, 0x242, 0x3, 0x2, 0x2, 0x2, 0x244, 
       0x245, 0x3, 0x2, 0x2, 0x2, 0x245, 0x247, 0x3, 0x2, 0x2, 0x2, 0x246, 
       0x244, 0x3, 0x2, 0x2, 0x2, 0x247, 0x248, 0x7, 0x31, 0x2, 0x2, 0x248, 
       0x83, 0x3, 0x2, 0x2, 0x2, 0x249, 0x24a, 0x9, 0x7, 0x2, 0x2, 0x24a, 
       0x85, 0x3, 0x2, 0x2, 0x2, 0x24b, 0x24c, 0x7, 0x3, 0x2, 0x2, 0x24c, 
       0x24d, 0x5, 0x4a, 0x26, 0x2, 0x24d, 0x24e, 0x5, 0x84, 0x43, 0x2, 
       0x24e, 0x24f, 0x7, 0x38, 0x2, 0x2, 0x24f, 0x250, 0x7, 0x32, 0x2, 
       0x2, 0x250, 0x251, 0x5, 0x52, 0x2a, 0x2, 0x251, 0x252, 0x7, 0x33, 
       0x2, 0x2, 0x252, 0x253, 0x7, 0x2a, 0x2, 0x2, 0x253, 0x87, 0x3, 0x2, 
       0x2, 0x2, 0x254, 0x255, 0x7, 0x4, 0x2, 0x2, 0x255, 0x256, 0x7, 0x37, 
       0x2, 0x2, 0x256, 0x257, 0x7, 0x2a, 0x2, 0x2, 0x257, 0x89, 0x3, 0x2, 
       0x2, 0x2, 0x258, 0x25b, 0x5, 0x86, 0x44, 0x2, 0x259, 0x25b, 0x5, 
       0x88, 0x45, 0x2, 0x25a, 0x258, 0x3, 0x2, 0x2, 0x2, 0x25a, 0x259, 
       0x3, 0x2, 0x2, 0x2, 0x25b, 0x25c, 0x3, 0x2, 0x2, 0x2, 0x25c, 0x25a, 
       0x3, 0x2, 0x2, 0x2, 0x25c, 0x25d, 0x3, 0x2, 0x2, 0x2, 0x25d, 0x8b, 
       0x3, 0x2, 0x2, 0x2, 0x25e, 0x25f, 0x7, 0x15, 0x2, 0x2, 0x25f, 0x260, 
       0x5, 0x44, 0x23, 0x2, 0x260, 0x261, 0x7, 0xd, 0x2, 0x2, 0x261, 0x262, 
       0x7, 0x32, 0x2, 0x2, 0x262, 0x263, 0x7, 0x33, 0x2, 0x2, 0x263, 0x267, 
       0x7, 0x30, 0x2, 0x2, 0x264, 0x266, 0x5, 0x76, 0x3c, 0x2, 0x265, 0x264, 
       0x3, 0x2, 0x2, 0x2, 0x266, 0x269, 0x3, 0x2, 0x2, 0x2, 0x267, 0x265, 
       0x3, 0x2, 0x2, 0x2, 0x267, 0x268, 0x3, 0x2, 0x2, 0x2, 0x268, 0x26a, 
       0x3, 0x2, 0x2, 0x2, 0x269, 0x267, 0x3, 0x2, 0x2, 0x2, 0x26a, 0x26b, 
       0x7, 0x31, 0x2, 0x2, 0x26b, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x26c, 0x26e, 
       0x5, 0x72, 0x3a, 0x2, 0x26d, 0x26c, 0x3, 0x2, 0x2, 0x2, 0x26e, 0x271, 
       0x3, 0x2, 0x2, 0x2, 0x26f, 0x26d, 0x3, 0x2, 0x2, 0x2, 0x26f, 0x270, 
       0x3, 0x2, 0x2, 0x2, 0x270, 0x273, 0x3, 0x2, 0x2, 0x2, 0x271, 0x26f, 
       0x3, 0x2, 0x2, 0x2, 0x272, 0x274, 0x5, 0x8a, 0x46, 0x2, 0x273, 0x272, 
       0x3, 0x2, 0x2, 0x2, 0x273, 0x274, 0x3, 0x2, 0x2, 0x2, 0x274, 0x278, 
       0x3, 0x2, 0x2, 0x2, 0x275, 0x277, 0x5, 0x82, 0x42, 0x2, 0x276, 0x275, 
       0x3, 0x2, 0x2, 0x2, 0x277, 0x27a, 0x3, 0x2, 0x2, 0x2, 0x278, 0x276, 
       0x3, 0x2, 0x2, 0x2, 0x278, 0x279, 0x3, 0x2, 0x2, 0x2, 0x279, 0x27c, 
       0x3, 0x2, 0x2, 0x2, 0x27a, 0x278, 0x3, 0x2, 0x2, 0x2, 0x27b, 0x27d, 
       0x5, 0x8c, 0x47, 0x2, 0x27c, 0x27b, 0x3, 0x2, 0x2, 0x2, 0x27c, 0x27d, 
       0x3, 0x2, 0x2, 0x2, 0x27d, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x39, 0xc9, 
       0xec, 0x100, 0x104, 0x10d, 0x114, 0x117, 0x121, 0x12c, 0x130, 0x135, 
       0x13c, 0x141, 0x144, 0x14a, 0x14f, 0x156, 0x15b, 0x162, 0x16c, 0x172, 
       0x17b, 0x189, 0x18e, 0x198, 0x1a7, 0x1b8, 0x1c1, 0x1c4, 0x1cd, 0x1d6, 
       0x1dd, 0x1e1, 0x1e5, 0x1ea, 0x1f1, 0x1f7, 0x204, 0x209, 0x211, 0x21b, 
       0x21f, 0x222, 0x232, 0x238, 0x23d, 0x242, 0x244, 0x25a, 0x25c, 0x267, 
       0x26f, 0x273, 0x278, 0x27c, 
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

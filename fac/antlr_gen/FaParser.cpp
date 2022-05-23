
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
    setState(90);
    shiftLOp();
    setState(91);
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
    setState(93);
    shiftROp();
    setState(94);
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
    setState(110);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::Assign: {
        enterOuterAlt(_localctx, 1);
        setState(96);
        match(FaParser::Assign);
        break;
      }

      case FaParser::AddAssign: {
        enterOuterAlt(_localctx, 2);
        setState(97);
        match(FaParser::AddAssign);
        break;
      }

      case FaParser::SubAssign: {
        enterOuterAlt(_localctx, 3);
        setState(98);
        match(FaParser::SubAssign);
        break;
      }

      case FaParser::StarAssign: {
        enterOuterAlt(_localctx, 4);
        setState(99);
        match(FaParser::StarAssign);
        break;
      }

      case FaParser::StarStarAssign: {
        enterOuterAlt(_localctx, 5);
        setState(100);
        match(FaParser::StarStarAssign);
        break;
      }

      case FaParser::DivAssign: {
        enterOuterAlt(_localctx, 6);
        setState(101);
        match(FaParser::DivAssign);
        break;
      }

      case FaParser::ModAssign: {
        enterOuterAlt(_localctx, 7);
        setState(102);
        match(FaParser::ModAssign);
        break;
      }

      case FaParser::AndAssign: {
        enterOuterAlt(_localctx, 8);
        setState(103);
        match(FaParser::AndAssign);
        break;
      }

      case FaParser::OrAssign: {
        enterOuterAlt(_localctx, 9);
        setState(104);
        match(FaParser::OrAssign);
        break;
      }

      case FaParser::XorAssign: {
        enterOuterAlt(_localctx, 10);
        setState(105);
        match(FaParser::XorAssign);
        break;
      }

      case FaParser::AndAndAssign: {
        enterOuterAlt(_localctx, 11);
        setState(106);
        match(FaParser::AndAndAssign);
        break;
      }

      case FaParser::OrOrAssign: {
        enterOuterAlt(_localctx, 12);
        setState(107);
        match(FaParser::OrOrAssign);
        break;
      }

      case FaParser::QuotJianL: {
        enterOuterAlt(_localctx, 13);
        setState(108);
        shiftLAssign();
        break;
      }

      case FaParser::QuotJianR: {
        enterOuterAlt(_localctx, 14);
        setState(109);
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
    setState(112);
    match(FaParser::QuotJianL);
    setState(113);
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
    setState(115);
    match(FaParser::QuotJianR);
    setState(116);
    match(FaParser::QuotJianR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EndStmtContext ------------------------------------------------------------------

FaParser::EndStmtContext::EndStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::EndStmtContext::NewLine() {
  return getToken(FaParser::NewLine, 0);
}

tree::TerminalNode* FaParser::EndStmtContext::Semi() {
  return getToken(FaParser::Semi, 0);
}


size_t FaParser::EndStmtContext::getRuleIndex() const {
  return FaParser::RuleEndStmt;
}


antlrcpp::Any FaParser::EndStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitEndStmt(this);
  else
    return visitor->visitChildren(this);
}

FaParser::EndStmtContext* FaParser::endStmt() {
  EndStmtContext *_localctx = _tracker.createInstance<EndStmtContext>(_ctx, getState());
  enterRule(_localctx, 10, FaParser::RuleEndStmt);
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
    setState(118);
    _la = _input->LA(1);
    if (!(_la == FaParser::NewLine

    || _la == FaParser::Semi)) {
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
  enterRule(_localctx, 12, FaParser::RuleLtOp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(120);
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
  enterRule(_localctx, 14, FaParser::RuleLtEqualOp);

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
    match(FaParser::QuotJianL);
    setState(123);
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
  enterRule(_localctx, 16, FaParser::RuleGtOp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(125);
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
  enterRule(_localctx, 18, FaParser::RuleGtEqualOp);

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
    match(FaParser::QuotJianR);
    setState(128);
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
  enterRule(_localctx, 20, FaParser::RuleEqualOp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(130);
    match(FaParser::Assign);
    setState(131);
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
  enterRule(_localctx, 22, FaParser::RuleNotEqualOp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(133);
    match(FaParser::Exclam);
    setState(134);
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
  enterRule(_localctx, 24, FaParser::RuleExprFuncDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(136);
    match(FaParser::Assign);
    setState(137);
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
  enterRule(_localctx, 26, FaParser::RuleSelfOp2);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(152);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::AddOp: {
        enterOuterAlt(_localctx, 1);
        setState(139);
        match(FaParser::AddOp);
        break;
      }

      case FaParser::SubOp: {
        enterOuterAlt(_localctx, 2);
        setState(140);
        match(FaParser::SubOp);
        break;
      }

      case FaParser::StarOp: {
        enterOuterAlt(_localctx, 3);
        setState(141);
        match(FaParser::StarOp);
        break;
      }

      case FaParser::DivOp: {
        enterOuterAlt(_localctx, 4);
        setState(142);
        match(FaParser::DivOp);
        break;
      }

      case FaParser::StarStarOp: {
        enterOuterAlt(_localctx, 5);
        setState(143);
        match(FaParser::StarStarOp);
        break;
      }

      case FaParser::ModOp: {
        enterOuterAlt(_localctx, 6);
        setState(144);
        match(FaParser::ModOp);
        break;
      }

      case FaParser::AndOp: {
        enterOuterAlt(_localctx, 7);
        setState(145);
        match(FaParser::AndOp);
        break;
      }

      case FaParser::OrOp: {
        enterOuterAlt(_localctx, 8);
        setState(146);
        match(FaParser::OrOp);
        break;
      }

      case FaParser::XorOp: {
        enterOuterAlt(_localctx, 9);
        setState(147);
        match(FaParser::XorOp);
        break;
      }

      case FaParser::AndAndOp: {
        enterOuterAlt(_localctx, 10);
        setState(148);
        match(FaParser::AndAndOp);
        break;
      }

      case FaParser::OrOrOp: {
        enterOuterAlt(_localctx, 11);
        setState(149);
        match(FaParser::OrOrOp);
        break;
      }

      case FaParser::QuotJianL: {
        enterOuterAlt(_localctx, 12);
        setState(150);
        shiftLOp();
        break;
      }

      case FaParser::QuotJianR: {
        enterOuterAlt(_localctx, 13);
        setState(151);
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
  enterRule(_localctx, 28, FaParser::RuleCompareOp2);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(160);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(154);
      ltOp();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(155);
      ltEqualOp();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(156);
      gtOp();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(157);
      gtEqualOp();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(158);
      equalOp();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(159);
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

//----------------- AllOp2Context ------------------------------------------------------------------

FaParser::AllOp2Context::AllOp2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::SelfOp2Context* FaParser::AllOp2Context::selfOp2() {
  return getRuleContext<FaParser::SelfOp2Context>(0);
}

FaParser::CompareOp2Context* FaParser::AllOp2Context::compareOp2() {
  return getRuleContext<FaParser::CompareOp2Context>(0);
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
  enterRule(_localctx, 30, FaParser::RuleAllOp2);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(164);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(162);
      selfOp2();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(163);
      compareOp2();
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

tree::TerminalNode* FaParser::LiteralContext::NumLiteral() {
  return getToken(FaParser::NumLiteral, 0);
}

tree::TerminalNode* FaParser::LiteralContext::StringLiteral() {
  return getToken(FaParser::StringLiteral, 0);
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
  enterRule(_localctx, 32, FaParser::RuleLiteral);
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
    setState(166);
    _la = _input->LA(1);
    if (!(((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (FaParser::BoolLiteral - 64))
      | (1ULL << (FaParser::NumLiteral - 64))
      | (1ULL << (FaParser::StringLiteral - 64)))) != 0))) {
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
  enterRule(_localctx, 34, FaParser::RuleIds);
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
    setState(168);
    match(FaParser::Id);
    setState(173);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::PointOp) {
      setState(169);
      match(FaParser::PointOp);
      setState(170);
      match(FaParser::Id);
      setState(175);
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
  enterRule(_localctx, 36, FaParser::RuleQuotStmtPart);
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
    setState(176);
    match(FaParser::QuotHuaL);
    setState(180);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Break)
      | (1ULL << FaParser::Continue)
      | (1ULL << FaParser::Return)
      | (1ULL << FaParser::Func)
      | (1ULL << FaParser::Yield)
      | (1ULL << FaParser::WaveOp)
      | (1ULL << FaParser::AddAddOp)
      | (1ULL << FaParser::SubSubOp)
      | (1ULL << FaParser::Exclam)
      | (1ULL << FaParser::SubOp)
      | (1ULL << FaParser::ColonColon)
      | (1ULL << FaParser::NewLine)
      | (1ULL << FaParser::Semi)
      | (1ULL << FaParser::QuotYuanL))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (FaParser::BoolLiteral - 64))
      | (1ULL << (FaParser::NumLiteral - 64))
      | (1ULL << (FaParser::StringLiteral - 64))
      | (1ULL << (FaParser::Id - 64)))) != 0)) {
      setState(177);
      stmt();
      setState(182);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(183);
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
  enterRule(_localctx, 38, FaParser::RuleIfStmt);
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
    setState(185);
    match(FaParser::If);
    setState(186);
    expr();
    setState(187);
    quotStmtPart();
    setState(195);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(188);
        match(FaParser::Else);
        setState(189);
        match(FaParser::If);
        setState(190);
        expr();
        setState(191);
        quotStmtPart(); 
      }
      setState(197);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
    setState(200);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Else) {
      setState(198);
      match(FaParser::Else);
      setState(199);
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
  enterRule(_localctx, 40, FaParser::RuleWhileStmt);
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
    setState(202);
    match(FaParser::While);
    setState(203);
    expr();
    setState(204);
    match(FaParser::QuotHuaL);
    setState(208);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Break)
      | (1ULL << FaParser::Continue)
      | (1ULL << FaParser::Return)
      | (1ULL << FaParser::Func)
      | (1ULL << FaParser::Yield)
      | (1ULL << FaParser::WaveOp)
      | (1ULL << FaParser::AddAddOp)
      | (1ULL << FaParser::SubSubOp)
      | (1ULL << FaParser::Exclam)
      | (1ULL << FaParser::SubOp)
      | (1ULL << FaParser::ColonColon)
      | (1ULL << FaParser::NewLine)
      | (1ULL << FaParser::Semi)
      | (1ULL << FaParser::QuotYuanL))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (FaParser::BoolLiteral - 64))
      | (1ULL << (FaParser::NumLiteral - 64))
      | (1ULL << (FaParser::StringLiteral - 64))
      | (1ULL << (FaParser::Id - 64)))) != 0)) {
      setState(205);
      stmt();
      setState(210);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(211);
    match(FaParser::QuotHuaR);
   
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

tree::TerminalNode* FaParser::WhileStmt2Context::QuotHuaL() {
  return getToken(FaParser::QuotHuaL, 0);
}

tree::TerminalNode* FaParser::WhileStmt2Context::QuotHuaR() {
  return getToken(FaParser::QuotHuaR, 0);
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
  enterRule(_localctx, 42, FaParser::RuleWhileStmt2);
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
    setState(213);
    match(FaParser::Do);
    setState(214);
    match(FaParser::QuotHuaL);
    setState(218);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Break)
      | (1ULL << FaParser::Continue)
      | (1ULL << FaParser::Return)
      | (1ULL << FaParser::Func)
      | (1ULL << FaParser::Yield)
      | (1ULL << FaParser::WaveOp)
      | (1ULL << FaParser::AddAddOp)
      | (1ULL << FaParser::SubSubOp)
      | (1ULL << FaParser::Exclam)
      | (1ULL << FaParser::SubOp)
      | (1ULL << FaParser::ColonColon)
      | (1ULL << FaParser::NewLine)
      | (1ULL << FaParser::Semi)
      | (1ULL << FaParser::QuotYuanL))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (FaParser::BoolLiteral - 64))
      | (1ULL << (FaParser::NumLiteral - 64))
      | (1ULL << (FaParser::StringLiteral - 64))
      | (1ULL << (FaParser::Id - 64)))) != 0)) {
      setState(215);
      stmt();
      setState(220);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(221);
    match(FaParser::QuotHuaR);
    setState(222);
    match(FaParser::While);
    setState(223);
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

tree::TerminalNode* FaParser::ForStmtContext::QuotHuaL() {
  return getToken(FaParser::QuotHuaL, 0);
}

tree::TerminalNode* FaParser::ForStmtContext::QuotHuaR() {
  return getToken(FaParser::QuotHuaR, 0);
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
  enterRule(_localctx, 44, FaParser::RuleForStmt);
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
    setState(225);
    match(FaParser::For);
    setState(226);
    stmt();
    setState(227);
    expr();
    setState(228);
    match(FaParser::Semi);
    setState(237);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 18) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 18)) & ((1ULL << (FaParser::Func - 18))
      | (1ULL << (FaParser::WaveOp - 18))
      | (1ULL << (FaParser::AddAddOp - 18))
      | (1ULL << (FaParser::SubSubOp - 18))
      | (1ULL << (FaParser::Exclam - 18))
      | (1ULL << (FaParser::SubOp - 18))
      | (1ULL << (FaParser::ColonColon - 18))
      | (1ULL << (FaParser::QuotYuanL - 18))
      | (1ULL << (FaParser::BoolLiteral - 18))
      | (1ULL << (FaParser::NumLiteral - 18))
      | (1ULL << (FaParser::StringLiteral - 18))
      | (1ULL << (FaParser::Id - 18)))) != 0)) {
      setState(229);
      expr();
      setState(234);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FaParser::Comma) {
        setState(230);
        match(FaParser::Comma);
        setState(231);
        expr();
        setState(236);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(239);
    match(FaParser::QuotHuaL);
    setState(243);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Break)
      | (1ULL << FaParser::Continue)
      | (1ULL << FaParser::Return)
      | (1ULL << FaParser::Func)
      | (1ULL << FaParser::Yield)
      | (1ULL << FaParser::WaveOp)
      | (1ULL << FaParser::AddAddOp)
      | (1ULL << FaParser::SubSubOp)
      | (1ULL << FaParser::Exclam)
      | (1ULL << FaParser::SubOp)
      | (1ULL << FaParser::ColonColon)
      | (1ULL << FaParser::NewLine)
      | (1ULL << FaParser::Semi)
      | (1ULL << FaParser::QuotYuanL))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (FaParser::BoolLiteral - 64))
      | (1ULL << (FaParser::NumLiteral - 64))
      | (1ULL << (FaParser::StringLiteral - 64))
      | (1ULL << (FaParser::Id - 64)))) != 0)) {
      setState(240);
      stmt();
      setState(245);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(246);
    match(FaParser::QuotHuaR);
   
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

tree::TerminalNode* FaParser::ForStmt2Context::Id() {
  return getToken(FaParser::Id, 0);
}

tree::TerminalNode* FaParser::ForStmt2Context::Colon() {
  return getToken(FaParser::Colon, 0);
}

FaParser::ExprContext* FaParser::ForStmt2Context::expr() {
  return getRuleContext<FaParser::ExprContext>(0);
}

tree::TerminalNode* FaParser::ForStmt2Context::QuotHuaL() {
  return getToken(FaParser::QuotHuaL, 0);
}

tree::TerminalNode* FaParser::ForStmt2Context::QuotHuaR() {
  return getToken(FaParser::QuotHuaR, 0);
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
  enterRule(_localctx, 46, FaParser::RuleForStmt2);
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
    setState(248);
    match(FaParser::For);
    setState(249);
    match(FaParser::Id);
    setState(250);
    match(FaParser::Colon);
    setState(251);
    expr();
    setState(252);
    match(FaParser::QuotHuaL);
    setState(256);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Break)
      | (1ULL << FaParser::Continue)
      | (1ULL << FaParser::Return)
      | (1ULL << FaParser::Func)
      | (1ULL << FaParser::Yield)
      | (1ULL << FaParser::WaveOp)
      | (1ULL << FaParser::AddAddOp)
      | (1ULL << FaParser::SubSubOp)
      | (1ULL << FaParser::Exclam)
      | (1ULL << FaParser::SubOp)
      | (1ULL << FaParser::ColonColon)
      | (1ULL << FaParser::NewLine)
      | (1ULL << FaParser::Semi)
      | (1ULL << FaParser::QuotYuanL))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (FaParser::BoolLiteral - 64))
      | (1ULL << (FaParser::NumLiteral - 64))
      | (1ULL << (FaParser::StringLiteral - 64))
      | (1ULL << (FaParser::Id - 64)))) != 0)) {
      setState(253);
      stmt();
      setState(258);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(259);
    match(FaParser::QuotHuaR);
   
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
  enterRule(_localctx, 48, FaParser::RuleSwitchStmtPart);
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
    setState(261);
    expr();
    setState(264);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::When) {
      setState(262);
      match(FaParser::When);
      setState(263);
      expr();
    }
    setState(266);
    exprFuncDef();
    setState(267);
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

tree::TerminalNode* FaParser::SwitchStmtContext::QuotHuaL() {
  return getToken(FaParser::QuotHuaL, 0);
}

tree::TerminalNode* FaParser::SwitchStmtContext::QuotHuaR() {
  return getToken(FaParser::QuotHuaR, 0);
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
  enterRule(_localctx, 50, FaParser::RuleSwitchStmt);
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
    setState(269);
    match(FaParser::Switch);
    setState(270);
    expr();
    setState(271);
    match(FaParser::QuotHuaL);
    setState(275);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 18) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 18)) & ((1ULL << (FaParser::Func - 18))
      | (1ULL << (FaParser::WaveOp - 18))
      | (1ULL << (FaParser::AddAddOp - 18))
      | (1ULL << (FaParser::SubSubOp - 18))
      | (1ULL << (FaParser::Exclam - 18))
      | (1ULL << (FaParser::SubOp - 18))
      | (1ULL << (FaParser::ColonColon - 18))
      | (1ULL << (FaParser::QuotYuanL - 18))
      | (1ULL << (FaParser::BoolLiteral - 18))
      | (1ULL << (FaParser::NumLiteral - 18))
      | (1ULL << (FaParser::StringLiteral - 18))
      | (1ULL << (FaParser::Id - 18)))) != 0)) {
      setState(272);
      switchStmtPart();
      setState(277);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(278);
    match(FaParser::QuotHuaR);
   
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
  enterRule(_localctx, 52, FaParser::RuleExprOpt);
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
    setState(281);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 18) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 18)) & ((1ULL << (FaParser::Func - 18))
      | (1ULL << (FaParser::WaveOp - 18))
      | (1ULL << (FaParser::AddAddOp - 18))
      | (1ULL << (FaParser::SubSubOp - 18))
      | (1ULL << (FaParser::Exclam - 18))
      | (1ULL << (FaParser::SubOp - 18))
      | (1ULL << (FaParser::ColonColon - 18))
      | (1ULL << (FaParser::QuotYuanL - 18))
      | (1ULL << (FaParser::BoolLiteral - 18))
      | (1ULL << (FaParser::NumLiteral - 18))
      | (1ULL << (FaParser::StringLiteral - 18))
      | (1ULL << (FaParser::Id - 18)))) != 0)) {
      setState(280);
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
  enterRule(_localctx, 54, FaParser::RuleQuotExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(283);
    match(FaParser::QuotYuanL);
    setState(284);
    expr();
    setState(285);
    match(FaParser::QuotYuanR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FnExprContext ------------------------------------------------------------------

FaParser::FnExprContext::FnExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::FnExprContext::Func() {
  return getToken(FaParser::Func, 0);
}

tree::TerminalNode* FaParser::FnExprContext::QuotYuanL() {
  return getToken(FaParser::QuotYuanL, 0);
}

tree::TerminalNode* FaParser::FnExprContext::QuotYuanR() {
  return getToken(FaParser::QuotYuanR, 0);
}

tree::TerminalNode* FaParser::FnExprContext::QuotHuaL() {
  return getToken(FaParser::QuotHuaL, 0);
}

tree::TerminalNode* FaParser::FnExprContext::QuotHuaR() {
  return getToken(FaParser::QuotHuaR, 0);
}

std::vector<tree::TerminalNode *> FaParser::FnExprContext::Id() {
  return getTokens(FaParser::Id);
}

tree::TerminalNode* FaParser::FnExprContext::Id(size_t i) {
  return getToken(FaParser::Id, i);
}

std::vector<FaParser::StmtContext *> FaParser::FnExprContext::stmt() {
  return getRuleContexts<FaParser::StmtContext>();
}

FaParser::StmtContext* FaParser::FnExprContext::stmt(size_t i) {
  return getRuleContext<FaParser::StmtContext>(i);
}


size_t FaParser::FnExprContext::getRuleIndex() const {
  return FaParser::RuleFnExpr;
}


antlrcpp::Any FaParser::FnExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitFnExpr(this);
  else
    return visitor->visitChildren(this);
}

FaParser::FnExprContext* FaParser::fnExpr() {
  FnExprContext *_localctx = _tracker.createInstance<FnExprContext>(_ctx, getState());
  enterRule(_localctx, 56, FaParser::RuleFnExpr);
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
    match(FaParser::Func);
    setState(288);
    match(FaParser::QuotYuanL);
    setState(292);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Id) {
      setState(289);
      match(FaParser::Id);
      setState(294);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(295);
    match(FaParser::QuotYuanR);
    setState(296);
    match(FaParser::QuotHuaL);
    setState(300);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Break)
      | (1ULL << FaParser::Continue)
      | (1ULL << FaParser::Return)
      | (1ULL << FaParser::Func)
      | (1ULL << FaParser::Yield)
      | (1ULL << FaParser::WaveOp)
      | (1ULL << FaParser::AddAddOp)
      | (1ULL << FaParser::SubSubOp)
      | (1ULL << FaParser::Exclam)
      | (1ULL << FaParser::SubOp)
      | (1ULL << FaParser::ColonColon)
      | (1ULL << FaParser::NewLine)
      | (1ULL << FaParser::Semi)
      | (1ULL << FaParser::QuotYuanL))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (FaParser::BoolLiteral - 64))
      | (1ULL << (FaParser::NumLiteral - 64))
      | (1ULL << (FaParser::StringLiteral - 64))
      | (1ULL << (FaParser::Id - 64)))) != 0)) {
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

//----------------- ClassExprItemContext ------------------------------------------------------------------

FaParser::ClassExprItemContext::ClassExprItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::ClassExprItemContext::Id() {
  return getToken(FaParser::Id, 0);
}

tree::TerminalNode* FaParser::ClassExprItemContext::Assign() {
  return getToken(FaParser::Assign, 0);
}

FaParser::MiddleExprContext* FaParser::ClassExprItemContext::middleExpr() {
  return getRuleContext<FaParser::MiddleExprContext>(0);
}

FaParser::FnStmtContext* FaParser::ClassExprItemContext::fnStmt() {
  return getRuleContext<FaParser::FnStmtContext>(0);
}


size_t FaParser::ClassExprItemContext::getRuleIndex() const {
  return FaParser::RuleClassExprItem;
}


antlrcpp::Any FaParser::ClassExprItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitClassExprItem(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ClassExprItemContext* FaParser::classExprItem() {
  ClassExprItemContext *_localctx = _tracker.createInstance<ClassExprItemContext>(_ctx, getState());
  enterRule(_localctx, 58, FaParser::RuleClassExprItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(309);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::Id: {
        enterOuterAlt(_localctx, 1);
        setState(305);
        match(FaParser::Id);
        setState(306);
        match(FaParser::Assign);
        setState(307);
        middleExpr();
        break;
      }

      case FaParser::Func: {
        enterOuterAlt(_localctx, 2);
        setState(308);
        fnStmt();
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

//----------------- ClassExprContext ------------------------------------------------------------------

FaParser::ClassExprContext::ClassExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::ClassExprContext::QuotHuaL() {
  return getToken(FaParser::QuotHuaL, 0);
}

tree::TerminalNode* FaParser::ClassExprContext::QuotHuaR() {
  return getToken(FaParser::QuotHuaR, 0);
}

std::vector<FaParser::ClassExprItemContext *> FaParser::ClassExprContext::classExprItem() {
  return getRuleContexts<FaParser::ClassExprItemContext>();
}

FaParser::ClassExprItemContext* FaParser::ClassExprContext::classExprItem(size_t i) {
  return getRuleContext<FaParser::ClassExprItemContext>(i);
}

std::vector<tree::TerminalNode *> FaParser::ClassExprContext::NewLine() {
  return getTokens(FaParser::NewLine);
}

tree::TerminalNode* FaParser::ClassExprContext::NewLine(size_t i) {
  return getToken(FaParser::NewLine, i);
}


size_t FaParser::ClassExprContext::getRuleIndex() const {
  return FaParser::RuleClassExpr;
}


antlrcpp::Any FaParser::ClassExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitClassExpr(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ClassExprContext* FaParser::classExpr() {
  ClassExprContext *_localctx = _tracker.createInstance<ClassExprContext>(_ctx, getState());
  enterRule(_localctx, 60, FaParser::RuleClassExpr);
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
    setState(311);
    match(FaParser::QuotHuaL);
    setState(320);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Func

    || _la == FaParser::Id) {
      setState(312);
      classExprItem();
      setState(317);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FaParser::NewLine) {
        setState(313);
        match(FaParser::NewLine);
        setState(314);
        classExprItem();
        setState(319);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(322);
    match(FaParser::QuotHuaR);
   
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

tree::TerminalNode* FaParser::StrongExprBaseContext::Id() {
  return getToken(FaParser::Id, 0);
}

tree::TerminalNode* FaParser::StrongExprBaseContext::ColonColon() {
  return getToken(FaParser::ColonColon, 0);
}

FaParser::LiteralContext* FaParser::StrongExprBaseContext::literal() {
  return getRuleContext<FaParser::LiteralContext>(0);
}

FaParser::QuotExprContext* FaParser::StrongExprBaseContext::quotExpr() {
  return getRuleContext<FaParser::QuotExprContext>(0);
}

FaParser::FnExprContext* FaParser::StrongExprBaseContext::fnExpr() {
  return getRuleContext<FaParser::FnExprContext>(0);
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
  enterRule(_localctx, 62, FaParser::RuleStrongExprBase);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(331);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::ColonColon:
      case FaParser::Id: {
        enterOuterAlt(_localctx, 1);
        setState(325);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == FaParser::ColonColon) {
          setState(324);
          match(FaParser::ColonColon);
        }
        setState(327);
        match(FaParser::Id);
        break;
      }

      case FaParser::BoolLiteral:
      case FaParser::NumLiteral:
      case FaParser::StringLiteral: {
        enterOuterAlt(_localctx, 2);
        setState(328);
        literal();
        break;
      }

      case FaParser::QuotYuanL: {
        enterOuterAlt(_localctx, 3);
        setState(329);
        quotExpr();
        break;
      }

      case FaParser::Func: {
        enterOuterAlt(_localctx, 4);
        setState(330);
        fnExpr();
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

tree::TerminalNode* FaParser::StrongExprPrefixContext::WaveOp() {
  return getToken(FaParser::WaveOp, 0);
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
  enterRule(_localctx, 64, FaParser::RuleStrongExprPrefix);
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
    setState(333);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::WaveOp)
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

tree::TerminalNode* FaParser::StrongExprSuffixContext::QuotYuanL() {
  return getToken(FaParser::QuotYuanL, 0);
}

tree::TerminalNode* FaParser::StrongExprSuffixContext::QuotYuanR() {
  return getToken(FaParser::QuotYuanR, 0);
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

tree::TerminalNode* FaParser::StrongExprSuffixContext::QuotFangL() {
  return getToken(FaParser::QuotFangL, 0);
}

tree::TerminalNode* FaParser::StrongExprSuffixContext::QuotFangR() {
  return getToken(FaParser::QuotFangR, 0);
}

std::vector<FaParser::ExprOptContext *> FaParser::StrongExprSuffixContext::exprOpt() {
  return getRuleContexts<FaParser::ExprOptContext>();
}

FaParser::ExprOptContext* FaParser::StrongExprSuffixContext::exprOpt(size_t i) {
  return getRuleContext<FaParser::ExprOptContext>(i);
}

tree::TerminalNode* FaParser::StrongExprSuffixContext::PointPoint() {
  return getToken(FaParser::PointPoint, 0);
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
  enterRule(_localctx, 66, FaParser::RuleStrongExprSuffix);
  size_t _la = 0;

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
    switch (_input->LA(1)) {
      case FaParser::AddAddOp: {
        enterOuterAlt(_localctx, 1);
        setState(335);
        match(FaParser::AddAddOp);
        break;
      }

      case FaParser::SubSubOp: {
        enterOuterAlt(_localctx, 2);
        setState(336);
        match(FaParser::SubSubOp);
        break;
      }

      case FaParser::QuotYuanL: {
        enterOuterAlt(_localctx, 3);
        setState(337);
        match(FaParser::QuotYuanL);
        setState(346);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (((((_la - 18) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 18)) & ((1ULL << (FaParser::Func - 18))
          | (1ULL << (FaParser::WaveOp - 18))
          | (1ULL << (FaParser::AddAddOp - 18))
          | (1ULL << (FaParser::SubSubOp - 18))
          | (1ULL << (FaParser::Exclam - 18))
          | (1ULL << (FaParser::SubOp - 18))
          | (1ULL << (FaParser::ColonColon - 18))
          | (1ULL << (FaParser::QuotYuanL - 18))
          | (1ULL << (FaParser::BoolLiteral - 18))
          | (1ULL << (FaParser::NumLiteral - 18))
          | (1ULL << (FaParser::StringLiteral - 18))
          | (1ULL << (FaParser::Id - 18)))) != 0)) {
          setState(338);
          expr();
          setState(343);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == FaParser::Comma) {
            setState(339);
            match(FaParser::Comma);
            setState(340);
            expr();
            setState(345);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(348);
        match(FaParser::QuotYuanR);
        break;
      }

      case FaParser::QuotFangL: {
        enterOuterAlt(_localctx, 4);
        setState(349);
        match(FaParser::QuotFangL);

        setState(350);
        exprOpt();
        setState(353);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == FaParser::PointPoint) {
          setState(351);
          match(FaParser::PointPoint);
          setState(352);
          exprOpt();
        }
        setState(355);
        match(FaParser::QuotFangR);
        break;
      }

      case FaParser::PointOp: {
        enterOuterAlt(_localctx, 5);
        setState(357);
        match(FaParser::PointOp);
        setState(358);
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
  enterRule(_localctx, 68, FaParser::RuleStrongExpr);
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
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::WaveOp)
      | (1ULL << FaParser::AddAddOp)
      | (1ULL << FaParser::SubSubOp)
      | (1ULL << FaParser::Exclam)
      | (1ULL << FaParser::SubOp))) != 0)) {
      setState(361);
      strongExprPrefix();
      setState(366);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(367);
    strongExprBase();
    setState(371);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::AddAddOp)
      | (1ULL << FaParser::SubSubOp)
      | (1ULL << FaParser::PointOp)
      | (1ULL << FaParser::QuotFangL)
      | (1ULL << FaParser::QuotYuanL))) != 0)) {
      setState(368);
      strongExprSuffix();
      setState(373);
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
  enterRule(_localctx, 70, FaParser::RuleMiddleExpr);

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
    setState(374);
    strongExpr();
    setState(380);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(375);
        allOp2();
        setState(376);
        strongExpr(); 
      }
      setState(382);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
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
  enterRule(_localctx, 72, FaParser::RuleExpr);

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
    middleExpr();
    setState(389);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(384);
        allAssign();
        setState(385);
        middleExpr(); 
      }
      setState(391);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FnStmtContext ------------------------------------------------------------------

FaParser::FnStmtContext::FnStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::FnStmtContext::Func() {
  return getToken(FaParser::Func, 0);
}

std::vector<tree::TerminalNode *> FaParser::FnStmtContext::Id() {
  return getTokens(FaParser::Id);
}

tree::TerminalNode* FaParser::FnStmtContext::Id(size_t i) {
  return getToken(FaParser::Id, i);
}

tree::TerminalNode* FaParser::FnStmtContext::QuotYuanL() {
  return getToken(FaParser::QuotYuanL, 0);
}

tree::TerminalNode* FaParser::FnStmtContext::QuotYuanR() {
  return getToken(FaParser::QuotYuanR, 0);
}

tree::TerminalNode* FaParser::FnStmtContext::QuotHuaL() {
  return getToken(FaParser::QuotHuaL, 0);
}

tree::TerminalNode* FaParser::FnStmtContext::QuotHuaR() {
  return getToken(FaParser::QuotHuaR, 0);
}

std::vector<FaParser::StmtContext *> FaParser::FnStmtContext::stmt() {
  return getRuleContexts<FaParser::StmtContext>();
}

FaParser::StmtContext* FaParser::FnStmtContext::stmt(size_t i) {
  return getRuleContext<FaParser::StmtContext>(i);
}


size_t FaParser::FnStmtContext::getRuleIndex() const {
  return FaParser::RuleFnStmt;
}


antlrcpp::Any FaParser::FnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitFnStmt(this);
  else
    return visitor->visitChildren(this);
}

FaParser::FnStmtContext* FaParser::fnStmt() {
  FnStmtContext *_localctx = _tracker.createInstance<FnStmtContext>(_ctx, getState());
  enterRule(_localctx, 74, FaParser::RuleFnStmt);
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
    setState(392);
    match(FaParser::Func);
    setState(393);
    match(FaParser::Id);
    setState(394);
    match(FaParser::QuotYuanL);
    setState(398);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Id) {
      setState(395);
      match(FaParser::Id);
      setState(400);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(401);
    match(FaParser::QuotYuanR);
    setState(402);
    match(FaParser::QuotHuaL);
    setState(406);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Break)
      | (1ULL << FaParser::Continue)
      | (1ULL << FaParser::Return)
      | (1ULL << FaParser::Func)
      | (1ULL << FaParser::Yield)
      | (1ULL << FaParser::WaveOp)
      | (1ULL << FaParser::AddAddOp)
      | (1ULL << FaParser::SubSubOp)
      | (1ULL << FaParser::Exclam)
      | (1ULL << FaParser::SubOp)
      | (1ULL << FaParser::ColonColon)
      | (1ULL << FaParser::NewLine)
      | (1ULL << FaParser::Semi)
      | (1ULL << FaParser::QuotYuanL))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (FaParser::BoolLiteral - 64))
      | (1ULL << (FaParser::NumLiteral - 64))
      | (1ULL << (FaParser::StringLiteral - 64))
      | (1ULL << (FaParser::Id - 64)))) != 0)) {
      setState(403);
      stmt();
      setState(408);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(409);
    match(FaParser::QuotHuaR);
   
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

FaParser::EndStmtContext* FaParser::StmtContext::endStmt() {
  return getRuleContext<FaParser::EndStmtContext>(0);
}

FaParser::FnStmtContext* FaParser::StmtContext::fnStmt() {
  return getRuleContext<FaParser::FnStmtContext>(0);
}

tree::TerminalNode* FaParser::StmtContext::Break() {
  return getToken(FaParser::Break, 0);
}

tree::TerminalNode* FaParser::StmtContext::Continue() {
  return getToken(FaParser::Continue, 0);
}

FaParser::ExprContext* FaParser::StmtContext::expr() {
  return getRuleContext<FaParser::ExprContext>(0);
}

tree::TerminalNode* FaParser::StmtContext::Return() {
  return getToken(FaParser::Return, 0);
}

tree::TerminalNode* FaParser::StmtContext::Yield() {
  return getToken(FaParser::Yield, 0);
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
  enterRule(_localctx, 76, FaParser::RuleStmt);
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
    setState(420);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      setState(411);
      fnStmt();
      break;
    }

    case 2: {
      setState(413);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == FaParser::Return

      || _la == FaParser::Yield) {
        setState(412);
        _la = _input->LA(1);
        if (!(_la == FaParser::Return

        || _la == FaParser::Yield)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
      }
      setState(416);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 18) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 18)) & ((1ULL << (FaParser::Func - 18))
        | (1ULL << (FaParser::WaveOp - 18))
        | (1ULL << (FaParser::AddAddOp - 18))
        | (1ULL << (FaParser::SubSubOp - 18))
        | (1ULL << (FaParser::Exclam - 18))
        | (1ULL << (FaParser::SubOp - 18))
        | (1ULL << (FaParser::ColonColon - 18))
        | (1ULL << (FaParser::QuotYuanL - 18))
        | (1ULL << (FaParser::BoolLiteral - 18))
        | (1ULL << (FaParser::NumLiteral - 18))
        | (1ULL << (FaParser::StringLiteral - 18))
        | (1ULL << (FaParser::Id - 18)))) != 0)) {
        setState(415);
        expr();
      }
      break;
    }

    case 3: {
      setState(418);
      match(FaParser::Break);
      break;
    }

    case 4: {
      setState(419);
      match(FaParser::Continue);
      break;
    }

    default:
      break;
    }
    setState(422);
    endStmt();
   
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

tree::TerminalNode* FaParser::ClassItemFuncExtContext::QuotYuanL() {
  return getToken(FaParser::QuotYuanL, 0);
}

tree::TerminalNode* FaParser::ClassItemFuncExtContext::QuotYuanR() {
  return getToken(FaParser::QuotYuanR, 0);
}

tree::TerminalNode* FaParser::ClassItemFuncExtContext::QuotHuaL() {
  return getToken(FaParser::QuotHuaL, 0);
}

tree::TerminalNode* FaParser::ClassItemFuncExtContext::QuotHuaR() {
  return getToken(FaParser::QuotHuaR, 0);
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
  enterRule(_localctx, 78, FaParser::RuleClassItemFuncExt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(424);
    match(FaParser::QuotYuanL);
    setState(425);
    match(FaParser::QuotYuanR);
    setState(426);
    match(FaParser::QuotHuaL);
    setState(427);
    match(FaParser::QuotHuaR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassItemStmtContext ------------------------------------------------------------------

FaParser::ClassItemStmtContext::ClassItemStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FaParser::ClassItemStmtContext::Id() {
  return getTokens(FaParser::Id);
}

tree::TerminalNode* FaParser::ClassItemStmtContext::Id(size_t i) {
  return getToken(FaParser::Id, i);
}

FaParser::EndStmtContext* FaParser::ClassItemStmtContext::endStmt() {
  return getRuleContext<FaParser::EndStmtContext>(0);
}

tree::TerminalNode* FaParser::ClassItemStmtContext::PublicLevel() {
  return getToken(FaParser::PublicLevel, 0);
}

FaParser::ClassItemFuncExtContext* FaParser::ClassItemStmtContext::classItemFuncExt() {
  return getRuleContext<FaParser::ClassItemFuncExtContext>(0);
}


size_t FaParser::ClassItemStmtContext::getRuleIndex() const {
  return FaParser::RuleClassItemStmt;
}


antlrcpp::Any FaParser::ClassItemStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitClassItemStmt(this);
  else
    return visitor->visitChildren(this);
}

FaParser::ClassItemStmtContext* FaParser::classItemStmt() {
  ClassItemStmtContext *_localctx = _tracker.createInstance<ClassItemStmtContext>(_ctx, getState());
  enterRule(_localctx, 80, FaParser::RuleClassItemStmt);
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
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::PublicLevel) {
      setState(429);
      match(FaParser::PublicLevel);
    }
    setState(432);
    match(FaParser::Id);
    setState(433);
    match(FaParser::Id);
    setState(435);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::QuotYuanL) {
      setState(434);
      classItemFuncExt();
    }
    setState(437);
    endStmt();
   
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

std::vector<FaParser::ClassItemStmtContext *> FaParser::ClassStmtContext::classItemStmt() {
  return getRuleContexts<FaParser::ClassItemStmtContext>();
}

FaParser::ClassItemStmtContext* FaParser::ClassStmtContext::classItemStmt(size_t i) {
  return getRuleContext<FaParser::ClassItemStmtContext>(i);
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
  enterRule(_localctx, 82, FaParser::RuleClassStmt);
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
    setState(440);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::PublicLevel) {
      setState(439);
      match(FaParser::PublicLevel);
    }
    setState(442);
    match(FaParser::Class);
    setState(443);
    match(FaParser::Id);
    setState(444);
    match(FaParser::QuotHuaL);
    setState(448);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::PublicLevel

    || _la == FaParser::Id) {
      setState(445);
      classItemStmt();
      setState(450);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(451);
    match(FaParser::QuotHuaR);
   
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

FaParser::EndStmtContext* FaParser::UseStmtContext::endStmt() {
  return getRuleContext<FaParser::EndStmtContext>(0);
}

tree::TerminalNode* FaParser::UseStmtContext::Id() {
  return getToken(FaParser::Id, 0);
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
  enterRule(_localctx, 84, FaParser::RuleUseStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(453);
    match(FaParser::Use);
    setState(456);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      setState(454);
      match(FaParser::Id);
      setState(455);
      match(FaParser::Assign);
      break;
    }

    default:
      break;
    }
    setState(458);
    ids();
    setState(459);
    endStmt();
   
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

std::vector<tree::TerminalNode *> FaParser::NamespaceStmtContext::Id() {
  return getTokens(FaParser::Id);
}

tree::TerminalNode* FaParser::NamespaceStmtContext::Id(size_t i) {
  return getToken(FaParser::Id, i);
}

FaParser::EndStmtContext* FaParser::NamespaceStmtContext::endStmt() {
  return getRuleContext<FaParser::EndStmtContext>(0);
}

std::vector<tree::TerminalNode *> FaParser::NamespaceStmtContext::PointOp() {
  return getTokens(FaParser::PointOp);
}

tree::TerminalNode* FaParser::NamespaceStmtContext::PointOp(size_t i) {
  return getToken(FaParser::PointOp, i);
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
  enterRule(_localctx, 86, FaParser::RuleNamespaceStmt);
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
    match(FaParser::Namespace);
    setState(462);
    match(FaParser::Id);
    setState(467);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::PointOp) {
      setState(463);
      match(FaParser::PointOp);
      setState(464);
      match(FaParser::Id);
      setState(469);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(470);
    endStmt();
   
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

tree::TerminalNode* FaParser::ProgramContext::EOF() {
  return getToken(FaParser::EOF, 0);
}

std::vector<FaParser::UseStmtContext *> FaParser::ProgramContext::useStmt() {
  return getRuleContexts<FaParser::UseStmtContext>();
}

FaParser::UseStmtContext* FaParser::ProgramContext::useStmt(size_t i) {
  return getRuleContext<FaParser::UseStmtContext>(i);
}

FaParser::NamespaceStmtContext* FaParser::ProgramContext::namespaceStmt() {
  return getRuleContext<FaParser::NamespaceStmtContext>(0);
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
  enterRule(_localctx, 88, FaParser::RuleProgram);
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
    setState(475);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Use) {
      setState(472);
      useStmt();
      setState(477);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(479);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Namespace) {
      setState(478);
      namespaceStmt();
    }
    setState(484);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Class

    || _la == FaParser::PublicLevel) {
      setState(481);
      classStmt();
      setState(486);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(487);
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
  "shiftLAssign", "shiftRAssign", "allAssign", "shiftLOp", "shiftROp", "endStmt", 
  "ltOp", "ltEqualOp", "gtOp", "gtEqualOp", "equalOp", "notEqualOp", "exprFuncDef", 
  "selfOp2", "compareOp2", "allOp2", "literal", "ids", "quotStmtPart", "ifStmt", 
  "whileStmt", "whileStmt2", "forStmt", "forStmt2", "switchStmtPart", "switchStmt", 
  "exprOpt", "quotExpr", "fnExpr", "classExprItem", "classExpr", "strongExprBase", 
  "strongExprPrefix", "strongExprSuffix", "strongExpr", "middleExpr", "expr", 
  "fnStmt", "stmt", "classItemFuncExt", "classItemStmt", "classStmt", "useStmt", 
  "namespaceStmt", "program"
};

std::vector<std::string> FaParser::_literalNames = {
  "", "'break'", "'class'", "'continue'", "'do'", "'else'", "'for'", "'if'", 
  "'internal'", "'namespace'", "'private'", "'protected'", "'public'", "'return'", 
  "'switch'", "'use'", "'when'", "'while'", "'func'", "'yield'", "", "'='", 
  "", "", "", "", "", "", "", "", "", "", "", "'~'", "'++'", "'--'", "'!'", 
  "'..'", "'.'", "'+'", "'-'", "'*'", "'/'", "'%'", "'|'", "'&'", "'^'", 
  "", "", "", "','", "'::'", "':'", "'\n'", "';'", "'_'", "'['", "']'", 
  "'<'", "'>'", "'{'", "'}'", "'('", "')'"
};

std::vector<std::string> FaParser::_symbolicNames = {
  "", "Break", "Class", "Continue", "Do", "Else", "For", "If", "Internal", 
  "Namespace", "Private", "Protected", "Public", "Return", "Switch", "Use", 
  "When", "While", "Func", "Yield", "PublicLevel", "Assign", "AddAssign", 
  "SubAssign", "StarAssign", "DivAssign", "ModAssign", "OrAssign", "AndAssign", 
  "XorAssign", "StarStarAssign", "AndAndAssign", "OrOrAssign", "WaveOp", 
  "AddAddOp", "SubSubOp", "Exclam", "PointPoint", "PointOp", "AddOp", "SubOp", 
  "StarOp", "DivOp", "ModOp", "OrOp", "AndOp", "XorOp", "StarStarOp", "AndAndOp", 
  "OrOrOp", "Comma", "ColonColon", "Colon", "NewLine", "Semi", "Underline", 
  "QuotFangL", "QuotFangR", "QuotJianL", "QuotJianR", "QuotHuaL", "QuotHuaR", 
  "QuotYuanL", "QuotYuanR", "BoolLiteral", "NumLiteral", "String1Literal", 
  "String2Literal", "StringLiteral", "Id", "Comment1", "Comment2", "WS"
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
       0x3, 0x4a, 0x1ec, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
       0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x3, 0x2, 
       0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 
       0x4, 0x71, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 
       0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 
       0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 
       0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
       0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
       0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
       0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x9b, 0xa, 0xf, 0x3, 0x10, 
       0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 
       0xa3, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xa7, 0xa, 0x11, 
       0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 
       0xae, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0xb1, 0xb, 0x13, 0x3, 0x14, 
       0x3, 0x14, 0x7, 0x14, 0xb5, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 0xb8, 
       0xb, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
       0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 
       0xc4, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0xc7, 0xb, 0x15, 0x3, 0x15, 
       0x3, 0x15, 0x5, 0x15, 0xcb, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 
       0x16, 0x3, 0x16, 0x7, 0x16, 0xd1, 0xa, 0x16, 0xc, 0x16, 0xe, 0x16, 
       0xd4, 0xb, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 
       0x17, 0x7, 0x17, 0xdb, 0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 0xde, 0xb, 
       0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 
       0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 
       0x18, 0xeb, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0xee, 0xb, 0x18, 0x5, 
       0x18, 0xf0, 0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0xf4, 0xa, 
       0x18, 0xc, 0x18, 0xe, 0x18, 0xf7, 0xb, 0x18, 0x3, 0x18, 0x3, 0x18, 
       0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
       0x7, 0x19, 0x101, 0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 0x104, 0xb, 0x19, 
       0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 
       0x10b, 0xa, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 
       0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x7, 0x1b, 0x114, 0xa, 0x1b, 0xc, 0x1b, 
       0xe, 0x1b, 0x117, 0xb, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x5, 
       0x1c, 0x11c, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
       0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x7, 0x1e, 0x125, 0xa, 0x1e, 0xc, 
       0x1e, 0xe, 0x1e, 0x128, 0xb, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
       0x7, 0x1e, 0x12d, 0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 0x130, 0xb, 0x1e, 
       0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
       0x5, 0x1f, 0x138, 0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 
       0x20, 0x7, 0x20, 0x13e, 0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 0x141, 0xb, 
       0x20, 0x5, 0x20, 0x143, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 
       0x5, 0x21, 0x148, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 
       0x21, 0x5, 0x21, 0x14e, 0xa, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 
       0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x7, 0x23, 
       0x158, 0xa, 0x23, 0xc, 0x23, 0xe, 0x23, 0x15b, 0xb, 0x23, 0x5, 0x23, 
       0x15d, 0xa, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 
       0x23, 0x5, 0x23, 0x164, 0xa, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
       0x3, 0x23, 0x5, 0x23, 0x16a, 0xa, 0x23, 0x3, 0x24, 0x7, 0x24, 0x16d, 
       0xa, 0x24, 0xc, 0x24, 0xe, 0x24, 0x170, 0xb, 0x24, 0x3, 0x24, 0x3, 
       0x24, 0x7, 0x24, 0x174, 0xa, 0x24, 0xc, 0x24, 0xe, 0x24, 0x177, 0xb, 
       0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x7, 0x25, 0x17d, 
       0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 0x180, 0xb, 0x25, 0x3, 0x26, 0x3, 
       0x26, 0x3, 0x26, 0x3, 0x26, 0x7, 0x26, 0x186, 0xa, 0x26, 0xc, 0x26, 
       0xe, 0x26, 0x189, 0xb, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
       0x27, 0x7, 0x27, 0x18f, 0xa, 0x27, 0xc, 0x27, 0xe, 0x27, 0x192, 0xb, 
       0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x7, 0x27, 0x197, 0xa, 0x27, 
       0xc, 0x27, 0xe, 0x27, 0x19a, 0xb, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
       0x28, 0x3, 0x28, 0x5, 0x28, 0x1a0, 0xa, 0x28, 0x3, 0x28, 0x5, 0x28, 
       0x1a3, 0xa, 0x28, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x1a7, 0xa, 0x28, 
       0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 
       0x3, 0x29, 0x3, 0x2a, 0x5, 0x2a, 0x1b1, 0xa, 0x2a, 0x3, 0x2a, 0x3, 
       0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x1b6, 0xa, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 
       0x3, 0x2b, 0x5, 0x2b, 0x1bb, 0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 
       0x2b, 0x3, 0x2b, 0x7, 0x2b, 0x1c1, 0xa, 0x2b, 0xc, 0x2b, 0xe, 0x2b, 
       0x1c4, 0xb, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 
       0x2c, 0x5, 0x2c, 0x1cb, 0xa, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 
       0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x7, 0x2d, 0x1d4, 0xa, 
       0x2d, 0xc, 0x2d, 0xe, 0x2d, 0x1d7, 0xb, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
       0x3, 0x2e, 0x7, 0x2e, 0x1dc, 0xa, 0x2e, 0xc, 0x2e, 0xe, 0x2e, 0x1df, 
       0xb, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x1e2, 0xa, 0x2e, 0x3, 0x2e, 0x7, 
       0x2e, 0x1e5, 0xa, 0x2e, 0xc, 0x2e, 0xe, 0x2e, 0x1e8, 0xb, 0x2e, 0x3, 
       0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x2, 0x2, 0x2f, 0x2, 0x4, 0x6, 0x8, 0xa, 
       0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 
       0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 
       0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 
       0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x2, 0x6, 0x3, 0x2, 0x37, 0x38, 
       0x4, 0x2, 0x42, 0x43, 0x46, 0x46, 0x4, 0x2, 0x23, 0x26, 0x2a, 0x2a, 
       0x4, 0x2, 0xf, 0xf, 0x15, 0x15, 0x2, 0x20e, 0x2, 0x5c, 0x3, 0x2, 
       0x2, 0x2, 0x4, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x6, 0x70, 0x3, 0x2, 0x2, 
       0x2, 0x8, 0x72, 0x3, 0x2, 0x2, 0x2, 0xa, 0x75, 0x3, 0x2, 0x2, 0x2, 
       0xc, 0x78, 0x3, 0x2, 0x2, 0x2, 0xe, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x10, 
       0x7c, 0x3, 0x2, 0x2, 0x2, 0x12, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x14, 0x81, 
       0x3, 0x2, 0x2, 0x2, 0x16, 0x84, 0x3, 0x2, 0x2, 0x2, 0x18, 0x87, 0x3, 
       0x2, 0x2, 0x2, 0x1a, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x9a, 0x3, 0x2, 
       0x2, 0x2, 0x1e, 0xa2, 0x3, 0x2, 0x2, 0x2, 0x20, 0xa6, 0x3, 0x2, 0x2, 
       0x2, 0x22, 0xa8, 0x3, 0x2, 0x2, 0x2, 0x24, 0xaa, 0x3, 0x2, 0x2, 0x2, 
       0x26, 0xb2, 0x3, 0x2, 0x2, 0x2, 0x28, 0xbb, 0x3, 0x2, 0x2, 0x2, 0x2a, 
       0xcc, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xe3, 
       0x3, 0x2, 0x2, 0x2, 0x30, 0xfa, 0x3, 0x2, 0x2, 0x2, 0x32, 0x107, 
       0x3, 0x2, 0x2, 0x2, 0x34, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x36, 0x11b, 
       0x3, 0x2, 0x2, 0x2, 0x38, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x121, 
       0x3, 0x2, 0x2, 0x2, 0x3c, 0x137, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x139, 
       0x3, 0x2, 0x2, 0x2, 0x40, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x42, 0x14f, 
       0x3, 0x2, 0x2, 0x2, 0x44, 0x169, 0x3, 0x2, 0x2, 0x2, 0x46, 0x16e, 
       0x3, 0x2, 0x2, 0x2, 0x48, 0x178, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x181, 
       0x3, 0x2, 0x2, 0x2, 0x4c, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x1a6, 
       0x3, 0x2, 0x2, 0x2, 0x50, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x52, 0x1b0, 
       0x3, 0x2, 0x2, 0x2, 0x54, 0x1ba, 0x3, 0x2, 0x2, 0x2, 0x56, 0x1c7, 
       0x3, 0x2, 0x2, 0x2, 0x58, 0x1cf, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x1dd, 
       0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x5, 0x8, 0x5, 0x2, 0x5d, 0x5e, 0x7, 
       0x17, 0x2, 0x2, 0x5e, 0x3, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x5, 0xa, 
       0x6, 0x2, 0x60, 0x61, 0x7, 0x17, 0x2, 0x2, 0x61, 0x5, 0x3, 0x2, 0x2, 
       0x2, 0x62, 0x71, 0x7, 0x17, 0x2, 0x2, 0x63, 0x71, 0x7, 0x18, 0x2, 
       0x2, 0x64, 0x71, 0x7, 0x19, 0x2, 0x2, 0x65, 0x71, 0x7, 0x1a, 0x2, 
       0x2, 0x66, 0x71, 0x7, 0x20, 0x2, 0x2, 0x67, 0x71, 0x7, 0x1b, 0x2, 
       0x2, 0x68, 0x71, 0x7, 0x1c, 0x2, 0x2, 0x69, 0x71, 0x7, 0x1e, 0x2, 
       0x2, 0x6a, 0x71, 0x7, 0x1d, 0x2, 0x2, 0x6b, 0x71, 0x7, 0x1f, 0x2, 
       0x2, 0x6c, 0x71, 0x7, 0x21, 0x2, 0x2, 0x6d, 0x71, 0x7, 0x22, 0x2, 
       0x2, 0x6e, 0x71, 0x5, 0x2, 0x2, 0x2, 0x6f, 0x71, 0x5, 0x4, 0x3, 0x2, 
       0x70, 0x62, 0x3, 0x2, 0x2, 0x2, 0x70, 0x63, 0x3, 0x2, 0x2, 0x2, 0x70, 
       0x64, 0x3, 0x2, 0x2, 0x2, 0x70, 0x65, 0x3, 0x2, 0x2, 0x2, 0x70, 0x66, 
       0x3, 0x2, 0x2, 0x2, 0x70, 0x67, 0x3, 0x2, 0x2, 0x2, 0x70, 0x68, 0x3, 
       0x2, 0x2, 0x2, 0x70, 0x69, 0x3, 0x2, 0x2, 0x2, 0x70, 0x6a, 0x3, 0x2, 
       0x2, 0x2, 0x70, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x70, 0x6c, 0x3, 0x2, 0x2, 
       0x2, 0x70, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x70, 0x6e, 0x3, 0x2, 0x2, 0x2, 
       0x70, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x71, 0x7, 0x3, 0x2, 0x2, 0x2, 0x72, 
       0x73, 0x7, 0x3c, 0x2, 0x2, 0x73, 0x74, 0x7, 0x3c, 0x2, 0x2, 0x74, 
       0x9, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x7, 0x3d, 0x2, 0x2, 0x76, 0x77, 
       0x7, 0x3d, 0x2, 0x2, 0x77, 0xb, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x9, 
       0x2, 0x2, 0x2, 0x79, 0xd, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x7, 0x3c, 
       0x2, 0x2, 0x7b, 0xf, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x7, 0x3c, 0x2, 
       0x2, 0x7d, 0x7e, 0x7, 0x17, 0x2, 0x2, 0x7e, 0x11, 0x3, 0x2, 0x2, 
       0x2, 0x7f, 0x80, 0x7, 0x3d, 0x2, 0x2, 0x80, 0x13, 0x3, 0x2, 0x2, 
       0x2, 0x81, 0x82, 0x7, 0x3d, 0x2, 0x2, 0x82, 0x83, 0x7, 0x17, 0x2, 
       0x2, 0x83, 0x15, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0x7, 0x17, 0x2, 
       0x2, 0x85, 0x86, 0x7, 0x17, 0x2, 0x2, 0x86, 0x17, 0x3, 0x2, 0x2, 
       0x2, 0x87, 0x88, 0x7, 0x26, 0x2, 0x2, 0x88, 0x89, 0x7, 0x17, 0x2, 
       0x2, 0x89, 0x19, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 0x7, 0x17, 0x2, 
       0x2, 0x8b, 0x8c, 0x7, 0x3d, 0x2, 0x2, 0x8c, 0x1b, 0x3, 0x2, 0x2, 
       0x2, 0x8d, 0x9b, 0x7, 0x29, 0x2, 0x2, 0x8e, 0x9b, 0x7, 0x2a, 0x2, 
       0x2, 0x8f, 0x9b, 0x7, 0x2b, 0x2, 0x2, 0x90, 0x9b, 0x7, 0x2c, 0x2, 
       0x2, 0x91, 0x9b, 0x7, 0x31, 0x2, 0x2, 0x92, 0x9b, 0x7, 0x2d, 0x2, 
       0x2, 0x93, 0x9b, 0x7, 0x2f, 0x2, 0x2, 0x94, 0x9b, 0x7, 0x2e, 0x2, 
       0x2, 0x95, 0x9b, 0x7, 0x30, 0x2, 0x2, 0x96, 0x9b, 0x7, 0x32, 0x2, 
       0x2, 0x97, 0x9b, 0x7, 0x33, 0x2, 0x2, 0x98, 0x9b, 0x5, 0x8, 0x5, 
       0x2, 0x99, 0x9b, 0x5, 0xa, 0x6, 0x2, 0x9a, 0x8d, 0x3, 0x2, 0x2, 0x2, 
       0x9a, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x9a, 
       0x90, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x91, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x92, 
       0x3, 0x2, 0x2, 0x2, 0x9a, 0x93, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x94, 0x3, 
       0x2, 0x2, 0x2, 0x9a, 0x95, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x96, 0x3, 0x2, 
       0x2, 0x2, 0x9a, 0x97, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x98, 0x3, 0x2, 0x2, 
       0x2, 0x9a, 0x99, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x1d, 0x3, 0x2, 0x2, 0x2, 
       0x9c, 0xa3, 0x5, 0xe, 0x8, 0x2, 0x9d, 0xa3, 0x5, 0x10, 0x9, 0x2, 
       0x9e, 0xa3, 0x5, 0x12, 0xa, 0x2, 0x9f, 0xa3, 0x5, 0x14, 0xb, 0x2, 
       0xa0, 0xa3, 0x5, 0x16, 0xc, 0x2, 0xa1, 0xa3, 0x5, 0x18, 0xd, 0x2, 
       0xa2, 0x9c, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x9d, 0x3, 0x2, 0x2, 0x2, 0xa2, 
       0x9e, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa0, 
       0x3, 0x2, 0x2, 0x2, 0xa2, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa3, 0x1f, 0x3, 
       0x2, 0x2, 0x2, 0xa4, 0xa7, 0x5, 0x1c, 0xf, 0x2, 0xa5, 0xa7, 0x5, 
       0x1e, 0x10, 0x2, 0xa6, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa5, 0x3, 
       0x2, 0x2, 0x2, 0xa7, 0x21, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 0x9, 0x3, 
       0x2, 0x2, 0xa9, 0x23, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xaf, 0x7, 0x47, 
       0x2, 0x2, 0xab, 0xac, 0x7, 0x28, 0x2, 0x2, 0xac, 0xae, 0x7, 0x47, 
       0x2, 0x2, 0xad, 0xab, 0x3, 0x2, 0x2, 0x2, 0xae, 0xb1, 0x3, 0x2, 0x2, 
       0x2, 0xaf, 0xad, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 0x3, 0x2, 0x2, 0x2, 
       0xb0, 0x25, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xb2, 
       0xb6, 0x7, 0x3e, 0x2, 0x2, 0xb3, 0xb5, 0x5, 0x4e, 0x28, 0x2, 0xb4, 
       0xb3, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb4, 
       0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb9, 0x3, 
       0x2, 0x2, 0x2, 0xb8, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x7, 0x3f, 
       0x2, 0x2, 0xba, 0x27, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbc, 0x7, 0x9, 0x2, 
       0x2, 0xbc, 0xbd, 0x5, 0x4a, 0x26, 0x2, 0xbd, 0xc5, 0x5, 0x26, 0x14, 
       0x2, 0xbe, 0xbf, 0x7, 0x7, 0x2, 0x2, 0xbf, 0xc0, 0x7, 0x9, 0x2, 0x2, 
       0xc0, 0xc1, 0x5, 0x4a, 0x26, 0x2, 0xc1, 0xc2, 0x5, 0x26, 0x14, 0x2, 
       0xc2, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc4, 
       0xc7, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc6, 
       0x3, 0x2, 0x2, 0x2, 0xc6, 0xca, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc5, 0x3, 
       0x2, 0x2, 0x2, 0xc8, 0xc9, 0x7, 0x7, 0x2, 0x2, 0xc9, 0xcb, 0x5, 0x26, 
       0x14, 0x2, 0xca, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcb, 0x3, 0x2, 
       0x2, 0x2, 0xcb, 0x29, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0x7, 0x13, 
       0x2, 0x2, 0xcd, 0xce, 0x5, 0x4a, 0x26, 0x2, 0xce, 0xd2, 0x7, 0x3e, 
       0x2, 0x2, 0xcf, 0xd1, 0x5, 0x4e, 0x28, 0x2, 0xd0, 0xcf, 0x3, 0x2, 
       0x2, 0x2, 0xd1, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd0, 0x3, 0x2, 0x2, 
       0x2, 0xd2, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd5, 0x3, 0x2, 0x2, 0x2, 
       0xd4, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd6, 0x7, 0x3f, 0x2, 0x2, 
       0xd6, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 0x7, 0x6, 0x2, 0x2, 0xd8, 
       0xdc, 0x7, 0x3e, 0x2, 0x2, 0xd9, 0xdb, 0x5, 0x4e, 0x28, 0x2, 0xda, 
       0xd9, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xde, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xda, 
       0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdf, 0x3, 
       0x2, 0x2, 0x2, 0xde, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe0, 0x7, 0x3f, 
       0x2, 0x2, 0xe0, 0xe1, 0x7, 0x13, 0x2, 0x2, 0xe1, 0xe2, 0x5, 0x4a, 
       0x26, 0x2, 0xe2, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x7, 0x8, 
       0x2, 0x2, 0xe4, 0xe5, 0x5, 0x4e, 0x28, 0x2, 0xe5, 0xe6, 0x5, 0x4a, 
       0x26, 0x2, 0xe6, 0xef, 0x7, 0x38, 0x2, 0x2, 0xe7, 0xec, 0x5, 0x4a, 
       0x26, 0x2, 0xe8, 0xe9, 0x7, 0x34, 0x2, 0x2, 0xe9, 0xeb, 0x5, 0x4a, 
       0x26, 0x2, 0xea, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xee, 0x3, 0x2, 
       0x2, 0x2, 0xec, 0xea, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x3, 0x2, 0x2, 
       0x2, 0xed, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xee, 0xec, 0x3, 0x2, 0x2, 0x2, 
       0xef, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf0, 
       0xf1, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf5, 0x7, 0x3e, 0x2, 0x2, 0xf2, 
       0xf4, 0x5, 0x4e, 0x28, 0x2, 0xf3, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf4, 
       0xf7, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf6, 
       0x3, 0x2, 0x2, 0x2, 0xf6, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf5, 0x3, 
       0x2, 0x2, 0x2, 0xf8, 0xf9, 0x7, 0x3f, 0x2, 0x2, 0xf9, 0x2f, 0x3, 
       0x2, 0x2, 0x2, 0xfa, 0xfb, 0x7, 0x8, 0x2, 0x2, 0xfb, 0xfc, 0x7, 0x47, 
       0x2, 0x2, 0xfc, 0xfd, 0x7, 0x36, 0x2, 0x2, 0xfd, 0xfe, 0x5, 0x4a, 
       0x26, 0x2, 0xfe, 0x102, 0x7, 0x3e, 0x2, 0x2, 0xff, 0x101, 0x5, 0x4e, 
       0x28, 0x2, 0x100, 0xff, 0x3, 0x2, 0x2, 0x2, 0x101, 0x104, 0x3, 0x2, 
       0x2, 0x2, 0x102, 0x100, 0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 0x3, 0x2, 
       0x2, 0x2, 0x103, 0x105, 0x3, 0x2, 0x2, 0x2, 0x104, 0x102, 0x3, 0x2, 
       0x2, 0x2, 0x105, 0x106, 0x7, 0x3f, 0x2, 0x2, 0x106, 0x31, 0x3, 0x2, 
       0x2, 0x2, 0x107, 0x10a, 0x5, 0x4a, 0x26, 0x2, 0x108, 0x109, 0x7, 
       0x12, 0x2, 0x2, 0x109, 0x10b, 0x5, 0x4a, 0x26, 0x2, 0x10a, 0x108, 
       0x3, 0x2, 0x2, 0x2, 0x10a, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x10c, 
       0x3, 0x2, 0x2, 0x2, 0x10c, 0x10d, 0x5, 0x1a, 0xe, 0x2, 0x10d, 0x10e, 
       0x5, 0x4e, 0x28, 0x2, 0x10e, 0x33, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x110, 
       0x7, 0x10, 0x2, 0x2, 0x110, 0x111, 0x5, 0x4a, 0x26, 0x2, 0x111, 0x115, 
       0x7, 0x3e, 0x2, 0x2, 0x112, 0x114, 0x5, 0x32, 0x1a, 0x2, 0x113, 0x112, 
       0x3, 0x2, 0x2, 0x2, 0x114, 0x117, 0x3, 0x2, 0x2, 0x2, 0x115, 0x113, 
       0x3, 0x2, 0x2, 0x2, 0x115, 0x116, 0x3, 0x2, 0x2, 0x2, 0x116, 0x118, 
       0x3, 0x2, 0x2, 0x2, 0x117, 0x115, 0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 
       0x7, 0x3f, 0x2, 0x2, 0x119, 0x35, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11c, 
       0x5, 0x4a, 0x26, 0x2, 0x11b, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 
       0x3, 0x2, 0x2, 0x2, 0x11c, 0x37, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11e, 
       0x7, 0x40, 0x2, 0x2, 0x11e, 0x11f, 0x5, 0x4a, 0x26, 0x2, 0x11f, 0x120, 
       0x7, 0x41, 0x2, 0x2, 0x120, 0x39, 0x3, 0x2, 0x2, 0x2, 0x121, 0x122, 
       0x7, 0x14, 0x2, 0x2, 0x122, 0x126, 0x7, 0x40, 0x2, 0x2, 0x123, 0x125, 
       0x7, 0x47, 0x2, 0x2, 0x124, 0x123, 0x3, 0x2, 0x2, 0x2, 0x125, 0x128, 
       0x3, 0x2, 0x2, 0x2, 0x126, 0x124, 0x3, 0x2, 0x2, 0x2, 0x126, 0x127, 
       0x3, 0x2, 0x2, 0x2, 0x127, 0x129, 0x3, 0x2, 0x2, 0x2, 0x128, 0x126, 
       0x3, 0x2, 0x2, 0x2, 0x129, 0x12a, 0x7, 0x41, 0x2, 0x2, 0x12a, 0x12e, 
       0x7, 0x3e, 0x2, 0x2, 0x12b, 0x12d, 0x5, 0x4e, 0x28, 0x2, 0x12c, 0x12b, 
       0x3, 0x2, 0x2, 0x2, 0x12d, 0x130, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12c, 
       0x3, 0x2, 0x2, 0x2, 0x12e, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x131, 
       0x3, 0x2, 0x2, 0x2, 0x130, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 
       0x7, 0x3f, 0x2, 0x2, 0x132, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x133, 0x134, 
       0x7, 0x47, 0x2, 0x2, 0x134, 0x135, 0x7, 0x17, 0x2, 0x2, 0x135, 0x138, 
       0x5, 0x48, 0x25, 0x2, 0x136, 0x138, 0x5, 0x4c, 0x27, 0x2, 0x137, 
       0x133, 0x3, 0x2, 0x2, 0x2, 0x137, 0x136, 0x3, 0x2, 0x2, 0x2, 0x138, 
       0x3d, 0x3, 0x2, 0x2, 0x2, 0x139, 0x142, 0x7, 0x3e, 0x2, 0x2, 0x13a, 
       0x13f, 0x5, 0x3c, 0x1f, 0x2, 0x13b, 0x13c, 0x7, 0x37, 0x2, 0x2, 0x13c, 
       0x13e, 0x5, 0x3c, 0x1f, 0x2, 0x13d, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13e, 
       0x141, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13f, 
       0x140, 0x3, 0x2, 0x2, 0x2, 0x140, 0x143, 0x3, 0x2, 0x2, 0x2, 0x141, 
       0x13f, 0x3, 0x2, 0x2, 0x2, 0x142, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x142, 
       0x143, 0x3, 0x2, 0x2, 0x2, 0x143, 0x144, 0x3, 0x2, 0x2, 0x2, 0x144, 
       0x145, 0x7, 0x3f, 0x2, 0x2, 0x145, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x146, 
       0x148, 0x7, 0x35, 0x2, 0x2, 0x147, 0x146, 0x3, 0x2, 0x2, 0x2, 0x147, 
       0x148, 0x3, 0x2, 0x2, 0x2, 0x148, 0x149, 0x3, 0x2, 0x2, 0x2, 0x149, 
       0x14e, 0x7, 0x47, 0x2, 0x2, 0x14a, 0x14e, 0x5, 0x22, 0x12, 0x2, 0x14b, 
       0x14e, 0x5, 0x38, 0x1d, 0x2, 0x14c, 0x14e, 0x5, 0x3a, 0x1e, 0x2, 
       0x14d, 0x147, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14a, 0x3, 0x2, 0x2, 0x2, 
       0x14d, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14c, 0x3, 0x2, 0x2, 0x2, 
       0x14e, 0x41, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x150, 0x9, 0x4, 0x2, 0x2, 
       0x150, 0x43, 0x3, 0x2, 0x2, 0x2, 0x151, 0x16a, 0x7, 0x24, 0x2, 0x2, 
       0x152, 0x16a, 0x7, 0x25, 0x2, 0x2, 0x153, 0x15c, 0x7, 0x40, 0x2, 
       0x2, 0x154, 0x159, 0x5, 0x4a, 0x26, 0x2, 0x155, 0x156, 0x7, 0x34, 
       0x2, 0x2, 0x156, 0x158, 0x5, 0x4a, 0x26, 0x2, 0x157, 0x155, 0x3, 
       0x2, 0x2, 0x2, 0x158, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x159, 0x157, 0x3, 
       0x2, 0x2, 0x2, 0x159, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x15d, 0x3, 
       0x2, 0x2, 0x2, 0x15b, 0x159, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x154, 0x3, 
       0x2, 0x2, 0x2, 0x15c, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15e, 0x3, 
       0x2, 0x2, 0x2, 0x15e, 0x16a, 0x7, 0x41, 0x2, 0x2, 0x15f, 0x160, 0x7, 
       0x3a, 0x2, 0x2, 0x160, 0x163, 0x5, 0x36, 0x1c, 0x2, 0x161, 0x162, 
       0x7, 0x27, 0x2, 0x2, 0x162, 0x164, 0x5, 0x36, 0x1c, 0x2, 0x163, 0x161, 
       0x3, 0x2, 0x2, 0x2, 0x163, 0x164, 0x3, 0x2, 0x2, 0x2, 0x164, 0x165, 
       0x3, 0x2, 0x2, 0x2, 0x165, 0x166, 0x7, 0x3b, 0x2, 0x2, 0x166, 0x16a, 
       0x3, 0x2, 0x2, 0x2, 0x167, 0x168, 0x7, 0x28, 0x2, 0x2, 0x168, 0x16a, 
       0x7, 0x47, 0x2, 0x2, 0x169, 0x151, 0x3, 0x2, 0x2, 0x2, 0x169, 0x152, 
       0x3, 0x2, 0x2, 0x2, 0x169, 0x153, 0x3, 0x2, 0x2, 0x2, 0x169, 0x15f, 
       0x3, 0x2, 0x2, 0x2, 0x169, 0x167, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x45, 
       0x3, 0x2, 0x2, 0x2, 0x16b, 0x16d, 0x5, 0x42, 0x22, 0x2, 0x16c, 0x16b, 
       0x3, 0x2, 0x2, 0x2, 0x16d, 0x170, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x16c, 
       0x3, 0x2, 0x2, 0x2, 0x16e, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x171, 
       0x3, 0x2, 0x2, 0x2, 0x170, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x171, 0x175, 
       0x5, 0x40, 0x21, 0x2, 0x172, 0x174, 0x5, 0x44, 0x23, 0x2, 0x173, 
       0x172, 0x3, 0x2, 0x2, 0x2, 0x174, 0x177, 0x3, 0x2, 0x2, 0x2, 0x175, 
       0x173, 0x3, 0x2, 0x2, 0x2, 0x175, 0x176, 0x3, 0x2, 0x2, 0x2, 0x176, 
       0x47, 0x3, 0x2, 0x2, 0x2, 0x177, 0x175, 0x3, 0x2, 0x2, 0x2, 0x178, 
       0x17e, 0x5, 0x46, 0x24, 0x2, 0x179, 0x17a, 0x5, 0x20, 0x11, 0x2, 
       0x17a, 0x17b, 0x5, 0x46, 0x24, 0x2, 0x17b, 0x17d, 0x3, 0x2, 0x2, 
       0x2, 0x17c, 0x179, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x180, 0x3, 0x2, 0x2, 
       0x2, 0x17e, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x17f, 0x3, 0x2, 0x2, 
       0x2, 0x17f, 0x49, 0x3, 0x2, 0x2, 0x2, 0x180, 0x17e, 0x3, 0x2, 0x2, 
       0x2, 0x181, 0x187, 0x5, 0x48, 0x25, 0x2, 0x182, 0x183, 0x5, 0x6, 
       0x4, 0x2, 0x183, 0x184, 0x5, 0x48, 0x25, 0x2, 0x184, 0x186, 0x3, 
       0x2, 0x2, 0x2, 0x185, 0x182, 0x3, 0x2, 0x2, 0x2, 0x186, 0x189, 0x3, 
       0x2, 0x2, 0x2, 0x187, 0x185, 0x3, 0x2, 0x2, 0x2, 0x187, 0x188, 0x3, 
       0x2, 0x2, 0x2, 0x188, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x189, 0x187, 0x3, 
       0x2, 0x2, 0x2, 0x18a, 0x18b, 0x7, 0x14, 0x2, 0x2, 0x18b, 0x18c, 0x7, 
       0x47, 0x2, 0x2, 0x18c, 0x190, 0x7, 0x40, 0x2, 0x2, 0x18d, 0x18f, 
       0x7, 0x47, 0x2, 0x2, 0x18e, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x192, 
       0x3, 0x2, 0x2, 0x2, 0x190, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x190, 0x191, 
       0x3, 0x2, 0x2, 0x2, 0x191, 0x193, 0x3, 0x2, 0x2, 0x2, 0x192, 0x190, 
       0x3, 0x2, 0x2, 0x2, 0x193, 0x194, 0x7, 0x41, 0x2, 0x2, 0x194, 0x198, 
       0x7, 0x3e, 0x2, 0x2, 0x195, 0x197, 0x5, 0x4e, 0x28, 0x2, 0x196, 0x195, 
       0x3, 0x2, 0x2, 0x2, 0x197, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x198, 0x196, 
       0x3, 0x2, 0x2, 0x2, 0x198, 0x199, 0x3, 0x2, 0x2, 0x2, 0x199, 0x19b, 
       0x3, 0x2, 0x2, 0x2, 0x19a, 0x198, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x19c, 
       0x7, 0x3f, 0x2, 0x2, 0x19c, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x1a7, 
       0x5, 0x4c, 0x27, 0x2, 0x19e, 0x1a0, 0x9, 0x5, 0x2, 0x2, 0x19f, 0x19e, 
       0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x1a2, 
       0x3, 0x2, 0x2, 0x2, 0x1a1, 0x1a3, 0x5, 0x4a, 0x26, 0x2, 0x1a2, 0x1a1, 
       0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a7, 
       0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a7, 0x7, 0x3, 0x2, 0x2, 0x1a5, 0x1a7, 
       0x7, 0x5, 0x2, 0x2, 0x1a6, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x19f, 
       0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a5, 
       0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1a9, 
       0x5, 0xc, 0x7, 0x2, 0x1a9, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1ab, 
       0x7, 0x40, 0x2, 0x2, 0x1ab, 0x1ac, 0x7, 0x41, 0x2, 0x2, 0x1ac, 0x1ad, 
       0x7, 0x3e, 0x2, 0x2, 0x1ad, 0x1ae, 0x7, 0x3f, 0x2, 0x2, 0x1ae, 0x51, 
       0x3, 0x2, 0x2, 0x2, 0x1af, 0x1b1, 0x7, 0x16, 0x2, 0x2, 0x1b0, 0x1af, 
       0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1b2, 
       0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b3, 0x7, 0x47, 0x2, 0x2, 0x1b3, 0x1b5, 
       0x7, 0x47, 0x2, 0x2, 0x1b4, 0x1b6, 0x5, 0x50, 0x29, 0x2, 0x1b5, 0x1b4, 
       0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b7, 
       0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b8, 0x5, 0xc, 0x7, 0x2, 0x1b8, 0x53, 
       0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1bb, 0x7, 0x16, 0x2, 0x2, 0x1ba, 0x1b9, 
       0x3, 0x2, 0x2, 0x2, 0x1ba, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1bc, 
       0x3, 0x2, 0x2, 0x2, 0x1bc, 0x1bd, 0x7, 0x4, 0x2, 0x2, 0x1bd, 0x1be, 
       0x7, 0x47, 0x2, 0x2, 0x1be, 0x1c2, 0x7, 0x3e, 0x2, 0x2, 0x1bf, 0x1c1, 
       0x5, 0x52, 0x2a, 0x2, 0x1c0, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1c4, 
       0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c3, 
       0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c2, 
       0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c6, 0x7, 0x3f, 0x2, 0x2, 0x1c6, 0x55, 
       0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1ca, 0x7, 0x11, 0x2, 0x2, 0x1c8, 0x1c9, 
       0x7, 0x47, 0x2, 0x2, 0x1c9, 0x1cb, 0x7, 0x17, 0x2, 0x2, 0x1ca, 0x1c8, 
       0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1cb, 0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1cc, 
       0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1cd, 0x5, 0x24, 0x13, 0x2, 0x1cd, 0x1ce, 
       0x5, 0xc, 0x7, 0x2, 0x1ce, 0x57, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1d0, 
       0x7, 0xb, 0x2, 0x2, 0x1d0, 0x1d5, 0x7, 0x47, 0x2, 0x2, 0x1d1, 0x1d2, 
       0x7, 0x28, 0x2, 0x2, 0x1d2, 0x1d4, 0x7, 0x47, 0x2, 0x2, 0x1d3, 0x1d1, 
       0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1d3, 
       0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1d8, 
       0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x1d9, 
       0x5, 0xc, 0x7, 0x2, 0x1d9, 0x59, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x1dc, 
       0x5, 0x56, 0x2c, 0x2, 0x1db, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x1dc, 0x1df, 
       0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1db, 0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1de, 
       0x3, 0x2, 0x2, 0x2, 0x1de, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1dd, 
       0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1e2, 0x5, 0x58, 0x2d, 0x2, 0x1e1, 0x1e0, 
       0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1e6, 
       0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e5, 0x5, 0x54, 0x2b, 0x2, 0x1e4, 0x1e3, 
       0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1e8, 0x3, 0x2, 0x2, 0x2, 0x1e6, 0x1e4, 
       0x3, 0x2, 0x2, 0x2, 0x1e6, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1e9, 
       0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e9, 0x1ea, 
       0x7, 0x2, 0x2, 0x3, 0x1ea, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x30, 0x70, 
       0x9a, 0xa2, 0xa6, 0xaf, 0xb6, 0xc5, 0xca, 0xd2, 0xdc, 0xec, 0xef, 
       0xf5, 0x102, 0x10a, 0x115, 0x11b, 0x126, 0x12e, 0x137, 0x13f, 0x142, 
       0x147, 0x14d, 0x159, 0x15c, 0x163, 0x169, 0x16e, 0x175, 0x17e, 0x187, 
       0x190, 0x198, 0x19f, 0x1a2, 0x1a6, 0x1b0, 0x1b5, 0x1ba, 0x1c2, 0x1ca, 
       0x1d5, 0x1dd, 0x1e1, 0x1e6, 
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

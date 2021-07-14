
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
  enterRule(_localctx, 0, FaParser::RuleShiftLOp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(88);
    match(FaParser::QuotJianL);
    setState(89);
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
  enterRule(_localctx, 2, FaParser::RuleShiftROp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(91);
    match(FaParser::QuotJianR);
    setState(92);
    match(FaParser::QuotJianR);
   
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
  enterRule(_localctx, 4, FaParser::RuleLiteral);
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
    setState(94);
    _la = _input->LA(1);
    if (!(((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (FaParser::BoolLiteral - 67))
      | (1ULL << (FaParser::IntLiteral - 67))
      | (1ULL << (FaParser::FloatLiteral - 67))
      | (1ULL << (FaParser::String1Literal - 67)))) != 0))) {
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
  enterRule(_localctx, 6, FaParser::RuleIds);

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
    setState(96);
    match(FaParser::Id);
    setState(101);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(97);
        match(FaParser::PointOp);
        setState(98);
        match(FaParser::Id); 
      }
      setState(103);
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
  enterRule(_localctx, 8, FaParser::RuleTypeAfter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(108);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::QuotFangL: {
        enterOuterAlt(_localctx, 1);
        setState(104);
        match(FaParser::QuotFangL);
        setState(105);
        match(FaParser::QuotFangR);
        break;
      }

      case FaParser::AndOp: {
        enterOuterAlt(_localctx, 2);
        setState(106);
        match(FaParser::AndOp);
        break;
      }

      case FaParser::Qus: {
        enterOuterAlt(_localctx, 3);
        setState(107);
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
  enterRule(_localctx, 10, FaParser::RuleType);
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
    setState(111);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Const) {
      setState(110);
      match(FaParser::Const);
    }
    setState(136);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      setState(113);
      match(FaParser::Id);
      break;
    }

    case 2: {
      setState(114);
      match(FaParser::Id);
      setState(115);
      match(FaParser::QuotJianL);
      setState(116);
      type();
      setState(121);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FaParser::Comma) {
        setState(117);
        match(FaParser::Comma);
        setState(118);
        type();
        setState(123);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(124);
      match(FaParser::QuotJianR);
      break;
    }

    case 3: {
      setState(126);
      match(FaParser::QuotYuanL);
      setState(127);
      type();
      setState(130); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(128);
        match(FaParser::Comma);
        setState(129);
        type();
        setState(132); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == FaParser::Comma);
      setState(134);
      match(FaParser::QuotYuanR);
      break;
    }

    default:
      break;
    }
    setState(141);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::AndOp)
      | (1ULL << FaParser::Qus)
      | (1ULL << FaParser::QuotFangL))) != 0)) {
      setState(138);
      typeAfter();
      setState(143);
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
  enterRule(_localctx, 12, FaParser::RuleETypeAfter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(148);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::QuotFangL: {
        enterOuterAlt(_localctx, 1);
        setState(144);
        match(FaParser::QuotFangL);
        setState(145);
        match(FaParser::QuotFangR);
        break;
      }

      case FaParser::AndOp: {
        enterOuterAlt(_localctx, 2);
        setState(146);
        match(FaParser::AndOp);
        break;
      }

      case FaParser::StarOp: {
        enterOuterAlt(_localctx, 3);
        setState(147);
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
  enterRule(_localctx, 14, FaParser::RuleESign);
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
    setState(150);
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
  enterRule(_localctx, 16, FaParser::RuleEType);
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
    setState(153);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Const) {
      setState(152);
      match(FaParser::Const);
    }
    setState(156);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Signed

    || _la == FaParser::Unsigned) {
      setState(155);
      eSign();
    }
    setState(158);
    match(FaParser::Id);
    setState(162);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::StarOp)
      | (1ULL << FaParser::AndOp)
      | (1ULL << FaParser::QuotFangL))) != 0)) {
      setState(159);
      eTypeAfter();
      setState(164);
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
  enterRule(_localctx, 18, FaParser::RuleTypeVar);
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
    setState(165);
    type();
    setState(167);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Id) {
      setState(166);
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
  enterRule(_localctx, 20, FaParser::RuleTypeVarList);
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
    setState(169);
    typeVar();
    setState(174);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(170);
      match(FaParser::Comma);
      setState(171);
      typeVar();
      setState(176);
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
  enterRule(_localctx, 22, FaParser::RuleETypeVar);
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
    setState(177);
    eType();
    setState(179);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Id) {
      setState(178);
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
  enterRule(_localctx, 24, FaParser::RuleETypeVarList);
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
    setState(181);
    eTypeVar();
    setState(186);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(182);
      match(FaParser::Comma);
      setState(183);
      eTypeVar();
      setState(188);
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
  enterRule(_localctx, 26, FaParser::RuleIfPart);

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
    match(FaParser::If);
    setState(190);
    match(FaParser::QuotYuanL);
    setState(191);
    expr();
    setState(192);
    match(FaParser::QuotYuanR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtOrExprContext ------------------------------------------------------------------

FaParser::StmtOrExprContext::StmtOrExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::StmtContext* FaParser::StmtOrExprContext::stmt() {
  return getRuleContext<FaParser::StmtContext>(0);
}

FaParser::ExprContext* FaParser::StmtOrExprContext::expr() {
  return getRuleContext<FaParser::ExprContext>(0);
}


size_t FaParser::StmtOrExprContext::getRuleIndex() const {
  return FaParser::RuleStmtOrExpr;
}


antlrcpp::Any FaParser::StmtOrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitStmtOrExpr(this);
  else
    return visitor->visitChildren(this);
}

FaParser::StmtOrExprContext* FaParser::stmtOrExpr() {
  StmtOrExprContext *_localctx = _tracker.createInstance<StmtOrExprContext>(_ctx, getState());
  enterRule(_localctx, 28, FaParser::RuleStmtOrExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(196);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(194);
      stmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(195);
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
  enterRule(_localctx, 30, FaParser::RuleQuotStmtPart);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(207);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::QuotHuaL: {
        enterOuterAlt(_localctx, 1);
        setState(198);
        match(FaParser::QuotHuaL);
        setState(202);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << FaParser::Break)
          | (1ULL << FaParser::Continue)
          | (1ULL << FaParser::If)
          | (1ULL << FaParser::Return)
          | (1ULL << FaParser::While)
          | (1ULL << FaParser::ReverseOp)
          | (1ULL << FaParser::AddAddOp)
          | (1ULL << FaParser::SubSubOp)
          | (1ULL << FaParser::AddOp)
          | (1ULL << FaParser::SubOp)
          | (1ULL << FaParser::ColonColon))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 65)) & ((1ULL << (FaParser::QuotYuanL - 65))
          | (1ULL << (FaParser::BoolLiteral - 65))
          | (1ULL << (FaParser::IntLiteral - 65))
          | (1ULL << (FaParser::FloatLiteral - 65))
          | (1ULL << (FaParser::String1Literal - 65))
          | (1ULL << (FaParser::Id - 65)))) != 0)) {
          setState(199);
          stmt();
          setState(204);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(205);
        match(FaParser::QuotHuaR);
        break;
      }

      case FaParser::Break:
      case FaParser::Continue:
      case FaParser::If:
      case FaParser::Return:
      case FaParser::While:
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
        enterOuterAlt(_localctx, 2);
        setState(206);
        stmt();
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

std::vector<FaParser::StmtOrExprContext *> FaParser::QuotStmtExprContext::stmtOrExpr() {
  return getRuleContexts<FaParser::StmtOrExprContext>();
}

FaParser::StmtOrExprContext* FaParser::QuotStmtExprContext::stmtOrExpr(size_t i) {
  return getRuleContext<FaParser::StmtOrExprContext>(i);
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
  enterRule(_localctx, 32, FaParser::RuleQuotStmtExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(220);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::QuotHuaL: {
        enterOuterAlt(_localctx, 1);
        setState(209);
        match(FaParser::QuotHuaL);
        setState(213);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(210);
            stmtOrExpr(); 
          }
          setState(215);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
        }
        setState(216);
        expr();
        setState(217);
        match(FaParser::QuotHuaR);
        break;
      }

      case FaParser::If:
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
        enterOuterAlt(_localctx, 2);
        setState(219);
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
  enterRule(_localctx, 34, FaParser::RuleIfStmt);

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
    setState(222);
    ifPart();
    setState(223);
    quotStmtPart();
    setState(230);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(224);
        match(FaParser::Else);
        setState(225);
        ifPart();
        setState(226);
        quotStmtPart(); 
      }
      setState(232);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
    setState(235);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      setState(233);
      match(FaParser::Else);
      setState(234);
      quotStmtPart();
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
  enterRule(_localctx, 36, FaParser::RuleIfExpr);

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
    setState(237);
    ifPart();
    setState(238);
    quotStmtExpr();
    setState(245);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(239);
        match(FaParser::Else);
        setState(240);
        ifPart();
        setState(241);
        quotStmtExpr(); 
      }
      setState(247);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
    setState(250);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      setState(248);
      match(FaParser::Else);
      setState(249);
      quotStmtExpr();
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

//----------------- WhileStmtPartContext ------------------------------------------------------------------

FaParser::WhileStmtPartContext::WhileStmtPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::WhileStmtPartContext::QuotHuaL() {
  return getToken(FaParser::QuotHuaL, 0);
}

tree::TerminalNode* FaParser::WhileStmtPartContext::QuotHuaR() {
  return getToken(FaParser::QuotHuaR, 0);
}

std::vector<FaParser::StmtContext *> FaParser::WhileStmtPartContext::stmt() {
  return getRuleContexts<FaParser::StmtContext>();
}

FaParser::StmtContext* FaParser::WhileStmtPartContext::stmt(size_t i) {
  return getRuleContext<FaParser::StmtContext>(i);
}


size_t FaParser::WhileStmtPartContext::getRuleIndex() const {
  return FaParser::RuleWhileStmtPart;
}


antlrcpp::Any FaParser::WhileStmtPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitWhileStmtPart(this);
  else
    return visitor->visitChildren(this);
}

FaParser::WhileStmtPartContext* FaParser::whileStmtPart() {
  WhileStmtPartContext *_localctx = _tracker.createInstance<WhileStmtPartContext>(_ctx, getState());
  enterRule(_localctx, 38, FaParser::RuleWhileStmtPart);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(261);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::QuotHuaL: {
        enterOuterAlt(_localctx, 1);
        setState(252);
        match(FaParser::QuotHuaL);
        setState(256);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << FaParser::Break)
          | (1ULL << FaParser::Continue)
          | (1ULL << FaParser::If)
          | (1ULL << FaParser::Return)
          | (1ULL << FaParser::While)
          | (1ULL << FaParser::ReverseOp)
          | (1ULL << FaParser::AddAddOp)
          | (1ULL << FaParser::SubSubOp)
          | (1ULL << FaParser::AddOp)
          | (1ULL << FaParser::SubOp)
          | (1ULL << FaParser::ColonColon))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 65)) & ((1ULL << (FaParser::QuotYuanL - 65))
          | (1ULL << (FaParser::BoolLiteral - 65))
          | (1ULL << (FaParser::IntLiteral - 65))
          | (1ULL << (FaParser::FloatLiteral - 65))
          | (1ULL << (FaParser::String1Literal - 65))
          | (1ULL << (FaParser::Id - 65)))) != 0)) {
          setState(253);
          stmt();
          setState(258);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(259);
        match(FaParser::QuotHuaR);
        break;
      }

      case FaParser::Break:
      case FaParser::Continue:
      case FaParser::If:
      case FaParser::Return:
      case FaParser::While:
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
        enterOuterAlt(_localctx, 2);
        setState(260);
        stmt();
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

FaParser::WhileStmtPartContext* FaParser::WhileStmtContext::whileStmtPart() {
  return getRuleContext<FaParser::WhileStmtPartContext>(0);
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
    match(FaParser::While);
    setState(264);
    match(FaParser::QuotYuanL);
    setState(265);
    expr();
    setState(266);
    match(FaParser::QuotYuanR);
    setState(267);
    whileStmtPart();
   
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
  enterRule(_localctx, 42, FaParser::RuleAllAssign);
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

FaParser::ShiftLOpContext* FaParser::AllOpContext::shiftLOp() {
  return getRuleContext<FaParser::ShiftLOpContext>(0);
}

FaParser::ShiftROpContext* FaParser::AllOpContext::shiftROp() {
  return getRuleContext<FaParser::ShiftROpContext>(0);
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
  enterRule(_localctx, 44, FaParser::RuleAllOp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(286);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::QusQusOp: {
        enterOuterAlt(_localctx, 1);
        setState(271);
        match(FaParser::QusQusOp);
        break;
      }

      case FaParser::PointOp: {
        enterOuterAlt(_localctx, 2);
        setState(272);
        match(FaParser::PointOp);
        break;
      }

      case FaParser::AddOp: {
        enterOuterAlt(_localctx, 3);
        setState(273);
        match(FaParser::AddOp);
        break;
      }

      case FaParser::SubOp: {
        enterOuterAlt(_localctx, 4);
        setState(274);
        match(FaParser::SubOp);
        break;
      }

      case FaParser::StarOp: {
        enterOuterAlt(_localctx, 5);
        setState(275);
        match(FaParser::StarOp);
        break;
      }

      case FaParser::DivOp: {
        enterOuterAlt(_localctx, 6);
        setState(276);
        match(FaParser::DivOp);
        break;
      }

      case FaParser::StarStarOp: {
        enterOuterAlt(_localctx, 7);
        setState(277);
        match(FaParser::StarStarOp);
        break;
      }

      case FaParser::ModOp: {
        enterOuterAlt(_localctx, 8);
        setState(278);
        match(FaParser::ModOp);
        break;
      }

      case FaParser::AndOp: {
        enterOuterAlt(_localctx, 9);
        setState(279);
        match(FaParser::AndOp);
        break;
      }

      case FaParser::OrOp: {
        enterOuterAlt(_localctx, 10);
        setState(280);
        match(FaParser::OrOp);
        break;
      }

      case FaParser::XorOp: {
        enterOuterAlt(_localctx, 11);
        setState(281);
        match(FaParser::XorOp);
        break;
      }

      case FaParser::AndAndOp: {
        enterOuterAlt(_localctx, 12);
        setState(282);
        match(FaParser::AndAndOp);
        break;
      }

      case FaParser::OrOrOp: {
        enterOuterAlt(_localctx, 13);
        setState(283);
        match(FaParser::OrOrOp);
        break;
      }

      case FaParser::QuotJianL: {
        enterOuterAlt(_localctx, 14);
        setState(284);
        shiftLOp();
        break;
      }

      case FaParser::QuotJianR: {
        enterOuterAlt(_localctx, 15);
        setState(285);
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
  enterRule(_localctx, 46, FaParser::RuleQuotExpr);

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
    match(FaParser::QuotYuanL);
    setState(289);
    expr();
    setState(290);
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
  enterRule(_localctx, 48, FaParser::RuleExprPrefix);
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
    setState(292);
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

FaParser::LiteralContext* FaParser::ExprBodyContext::literal() {
  return getRuleContext<FaParser::LiteralContext>(0);
}

tree::TerminalNode* FaParser::ExprBodyContext::ColonColon() {
  return getToken(FaParser::ColonColon, 0);
}

tree::TerminalNode* FaParser::ExprBodyContext::Id() {
  return getToken(FaParser::Id, 0);
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
  enterRule(_localctx, 50, FaParser::RuleExprBody);

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
    switch (_input->LA(1)) {
      case FaParser::Id: {
        setState(294);
        ids();
        break;
      }

      case FaParser::ColonColon: {
        setState(295);
        match(FaParser::ColonColon);
        setState(296);
        match(FaParser::Id);
        break;
      }

      case FaParser::BoolLiteral:
      case FaParser::IntLiteral:
      case FaParser::FloatLiteral:
      case FaParser::String1Literal: {
        setState(297);
        literal();
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

std::vector<tree::TerminalNode *> FaParser::ExprSuffixContext::AddAddOp() {
  return getTokens(FaParser::AddAddOp);
}

tree::TerminalNode* FaParser::ExprSuffixContext::AddAddOp(size_t i) {
  return getToken(FaParser::AddAddOp, i);
}

std::vector<tree::TerminalNode *> FaParser::ExprSuffixContext::SubSubOp() {
  return getTokens(FaParser::SubSubOp);
}

tree::TerminalNode* FaParser::ExprSuffixContext::SubSubOp(size_t i) {
  return getToken(FaParser::SubSubOp, i);
}

std::vector<tree::TerminalNode *> FaParser::ExprSuffixContext::QuotYuanL() {
  return getTokens(FaParser::QuotYuanL);
}

tree::TerminalNode* FaParser::ExprSuffixContext::QuotYuanL(size_t i) {
  return getToken(FaParser::QuotYuanL, i);
}

std::vector<tree::TerminalNode *> FaParser::ExprSuffixContext::QuotYuanR() {
  return getTokens(FaParser::QuotYuanR);
}

tree::TerminalNode* FaParser::ExprSuffixContext::QuotYuanR(size_t i) {
  return getToken(FaParser::QuotYuanR, i);
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

std::vector<tree::TerminalNode *> FaParser::ExprSuffixContext::QuotFangL() {
  return getTokens(FaParser::QuotFangL);
}

tree::TerminalNode* FaParser::ExprSuffixContext::QuotFangL(size_t i) {
  return getToken(FaParser::QuotFangL, i);
}

std::vector<FaParser::AllAssignContext *> FaParser::ExprSuffixContext::allAssign() {
  return getRuleContexts<FaParser::AllAssignContext>();
}

FaParser::AllAssignContext* FaParser::ExprSuffixContext::allAssign(size_t i) {
  return getRuleContext<FaParser::AllAssignContext>(i);
}

std::vector<FaParser::AllOpContext *> FaParser::ExprSuffixContext::allOp() {
  return getRuleContexts<FaParser::AllOpContext>();
}

FaParser::AllOpContext* FaParser::ExprSuffixContext::allOp(size_t i) {
  return getRuleContext<FaParser::AllOpContext>(i);
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
  enterRule(_localctx, 52, FaParser::RuleExprSuffix);
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
    setState(339);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::AddAddOp:
      case FaParser::SubSubOp: {
        enterOuterAlt(_localctx, 1);
        setState(301); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(300);
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

          default:
            throw NoViableAltException(this);
          }
          setState(303); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
        break;
      }

      case FaParser::QuotYuanL: {
        enterOuterAlt(_localctx, 2);
        setState(317); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(305);
                  match(FaParser::QuotYuanL);
                  setState(314);
                  _errHandler->sync(this);

                  _la = _input->LA(1);
                  if (((((_la - 12) & ~ 0x3fULL) == 0) &&
                    ((1ULL << (_la - 12)) & ((1ULL << (FaParser::If - 12))
                    | (1ULL << (FaParser::ReverseOp - 12))
                    | (1ULL << (FaParser::AddAddOp - 12))
                    | (1ULL << (FaParser::SubSubOp - 12))
                    | (1ULL << (FaParser::AddOp - 12))
                    | (1ULL << (FaParser::SubOp - 12))
                    | (1ULL << (FaParser::ColonColon - 12))
                    | (1ULL << (FaParser::QuotYuanL - 12))
                    | (1ULL << (FaParser::BoolLiteral - 12))
                    | (1ULL << (FaParser::IntLiteral - 12))
                    | (1ULL << (FaParser::FloatLiteral - 12))
                    | (1ULL << (FaParser::String1Literal - 12))
                    | (1ULL << (FaParser::Id - 12)))) != 0)) {
                    setState(306);
                    expr();
                    setState(311);
                    _errHandler->sync(this);
                    _la = _input->LA(1);
                    while (_la == FaParser::Comma) {
                      setState(307);
                      match(FaParser::Comma);
                      setState(308);
                      expr();
                      setState(313);
                      _errHandler->sync(this);
                      _la = _input->LA(1);
                    }
                  }
                  setState(316);
                  match(FaParser::QuotYuanR);
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(319); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
        break;
      }

      case FaParser::QuotFangL: {
        enterOuterAlt(_localctx, 3);
        setState(325); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(321);
                  match(FaParser::QuotFangL);
                  setState(322);
                  expr();
                  setState(323);
                  match(FaParser::QuotFangL);
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(327); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
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
      case FaParser::QuotJianL:
      case FaParser::QuotJianR: {
        enterOuterAlt(_localctx, 4);
        setState(335); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(331);
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
                      setState(329);
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
                    case FaParser::QuotJianL:
                    case FaParser::QuotJianR: {
                      setState(330);
                      allOp();
                      break;
                    }

                  default:
                    throw NoViableAltException(this);
                  }
                  setState(333);
                  expr();
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(337); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
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

//----------------- NormalExprContext ------------------------------------------------------------------

FaParser::NormalExprContext::NormalExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::QuotExprContext* FaParser::NormalExprContext::quotExpr() {
  return getRuleContext<FaParser::QuotExprContext>(0);
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
  enterRule(_localctx, 54, FaParser::RuleNormalExpr);
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
    setState(355);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::QuotYuanL: {
        enterOuterAlt(_localctx, 1);
        setState(341);
        quotExpr();
        break;
      }

      case FaParser::ReverseOp:
      case FaParser::AddAddOp:
      case FaParser::SubSubOp:
      case FaParser::AddOp:
      case FaParser::SubOp:
      case FaParser::ColonColon:
      case FaParser::BoolLiteral:
      case FaParser::IntLiteral:
      case FaParser::FloatLiteral:
      case FaParser::String1Literal:
      case FaParser::Id: {
        enterOuterAlt(_localctx, 2);
        setState(345);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << FaParser::ReverseOp)
          | (1ULL << FaParser::AddAddOp)
          | (1ULL << FaParser::SubSubOp)
          | (1ULL << FaParser::AddOp)
          | (1ULL << FaParser::SubOp))) != 0)) {
          setState(342);
          exprPrefix();
          setState(347);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(348);
        exprBody();
        setState(352);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(349);
            exprSuffix(); 
          }
          setState(354);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
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

//----------------- ExprContext ------------------------------------------------------------------

FaParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FaParser::NormalExprContext* FaParser::ExprContext::normalExpr() {
  return getRuleContext<FaParser::NormalExprContext>(0);
}

FaParser::IfExprContext* FaParser::ExprContext::ifExpr() {
  return getRuleContext<FaParser::IfExprContext>(0);
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
  enterRule(_localctx, 56, FaParser::RuleExpr);

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
        enterOuterAlt(_localctx, 1);
        setState(357);
        normalExpr();
        break;
      }

      case FaParser::If: {
        enterOuterAlt(_localctx, 2);
        setState(358);
        ifExpr();
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
  enterRule(_localctx, 58, FaParser::RuleUseStmt);

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
    match(FaParser::Use);
    setState(362);
    ids();
    setState(363);
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
  enterRule(_localctx, 60, FaParser::RuleNormalStmt);
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
    setState(371);
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
        setState(366);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == FaParser::Return) {
          setState(365);
          match(FaParser::Return);
        }
        setState(368);
        expr();
        break;
      }

      case FaParser::Break: {
        setState(369);
        match(FaParser::Break);
        break;
      }

      case FaParser::Continue: {
        setState(370);
        match(FaParser::Continue);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(373);
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
  enterRule(_localctx, 62, FaParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(378);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(375);
      normalStmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(376);
      ifStmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(377);
      whileStmt();
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
  enterRule(_localctx, 64, FaParser::RulePublicLevel);
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
    setState(380);
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
  enterRule(_localctx, 66, FaParser::RuleClassParent);
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
    setState(382);
    match(FaParser::Colon);
    setState(383);
    ids();
    setState(388);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(384);
      match(FaParser::Comma);
      setState(385);
      ids();
      setState(390);
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
  enterRule(_localctx, 68, FaParser::RuleClassItemPart);
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
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(391);
      publicLevel();
    }
    setState(395);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Static) {
      setState(394);
      match(FaParser::Static);
    }
    setState(397);
    match(FaParser::Id);
    setState(398);
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
  enterRule(_localctx, 70, FaParser::RuleClassItemFieldBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(400);
    classItemPart();
    setState(401);
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
  enterRule(_localctx, 72, FaParser::RuleClassItemFuncBlock);
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
    setState(403);
    classItemPart();
    setState(404);
    match(FaParser::QuotYuanL);
    setState(405);
    typeVarList();
    setState(406);
    match(FaParser::QuotYuanR);
    setState(407);
    match(FaParser::QuotHuaL);
    setState(411);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Break)
      | (1ULL << FaParser::Continue)
      | (1ULL << FaParser::If)
      | (1ULL << FaParser::Return)
      | (1ULL << FaParser::While)
      | (1ULL << FaParser::ReverseOp)
      | (1ULL << FaParser::AddAddOp)
      | (1ULL << FaParser::SubSubOp)
      | (1ULL << FaParser::AddOp)
      | (1ULL << FaParser::SubOp)
      | (1ULL << FaParser::ColonColon))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & ((1ULL << (FaParser::QuotYuanL - 65))
      | (1ULL << (FaParser::BoolLiteral - 65))
      | (1ULL << (FaParser::IntLiteral - 65))
      | (1ULL << (FaParser::FloatLiteral - 65))
      | (1ULL << (FaParser::String1Literal - 65))
      | (1ULL << (FaParser::Id - 65)))) != 0)) {
      setState(408);
      stmt();
      setState(413);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(414);
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
  enterRule(_localctx, 74, FaParser::RuleClassBlock);
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
    setState(417);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(416);
      publicLevel();
    }
    setState(419);
    match(FaParser::Class);
    setState(420);
    match(FaParser::Id);
    setState(422);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Colon) {
      setState(421);
      classParent();
    }
    setState(424);
    match(FaParser::QuotHuaL);
    setState(429);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 13) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 13)) & ((1ULL << (FaParser::Internal - 13))
      | (1ULL << (FaParser::Public - 13))
      | (1ULL << (FaParser::Protected - 13))
      | (1ULL << (FaParser::Private - 13))
      | (1ULL << (FaParser::Static - 13))
      | (1ULL << (FaParser::Id - 13)))) != 0)) {
      setState(427);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
      case 1: {
        setState(425);
        classItemFieldBlock();
        break;
      }

      case 2: {
        setState(426);
        classItemFuncBlock();
        break;
      }

      default:
        break;
      }
      setState(431);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(432);
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
  enterRule(_localctx, 76, FaParser::RuleCallConvention);
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
    setState(434);
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
  enterRule(_localctx, 78, FaParser::RuleImportStmt);

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
    match(FaParser::AImport);
    setState(437);
    eType();
    setState(438);
    callConvention();
    setState(439);
    match(FaParser::Id);
    setState(440);
    match(FaParser::QuotYuanL);
    setState(441);
    eTypeVarList();
    setState(442);
    match(FaParser::QuotYuanR);
    setState(443);
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
  enterRule(_localctx, 80, FaParser::RuleLibStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(445);
    match(FaParser::ALib);
    setState(446);
    match(FaParser::String1Literal);
    setState(447);
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
  enterRule(_localctx, 82, FaParser::RuleImportBlock);
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
    setState(451); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(451);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case FaParser::AImport: {
          setState(449);
          importStmt();
          break;
        }

        case FaParser::ALib: {
          setState(450);
          libStmt();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(453); 
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
  enterRule(_localctx, 84, FaParser::RuleFaEntryMainFuncBlock);
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
    setState(455);
    match(FaParser::Static);
    setState(456);
    type();
    setState(457);
    match(FaParser::FaEntryMain);
    setState(458);
    match(FaParser::QuotYuanL);
    setState(459);
    match(FaParser::QuotYuanR);
    setState(460);
    match(FaParser::QuotHuaL);
    setState(464);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Break)
      | (1ULL << FaParser::Continue)
      | (1ULL << FaParser::If)
      | (1ULL << FaParser::Return)
      | (1ULL << FaParser::While)
      | (1ULL << FaParser::ReverseOp)
      | (1ULL << FaParser::AddAddOp)
      | (1ULL << FaParser::SubSubOp)
      | (1ULL << FaParser::AddOp)
      | (1ULL << FaParser::SubOp)
      | (1ULL << FaParser::ColonColon))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & ((1ULL << (FaParser::QuotYuanL - 65))
      | (1ULL << (FaParser::BoolLiteral - 65))
      | (1ULL << (FaParser::IntLiteral - 65))
      | (1ULL << (FaParser::FloatLiteral - 65))
      | (1ULL << (FaParser::String1Literal - 65))
      | (1ULL << (FaParser::Id - 65)))) != 0)) {
      setState(461);
      stmt();
      setState(466);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(467);
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
  enterRule(_localctx, 86, FaParser::RuleProgram);
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
    setState(472);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Use) {
      setState(469);
      useStmt();
      setState(474);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(476);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::AImport

    || _la == FaParser::ALib) {
      setState(475);
      importBlock();
    }
    setState(481);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Class)
      | (1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(478);
      classBlock();
      setState(483);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(485);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Static) {
      setState(484);
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
  "shiftLOp", "shiftROp", "literal", "ids", "typeAfter", "type", "eTypeAfter", 
  "eSign", "eType", "typeVar", "typeVarList", "eTypeVar", "eTypeVarList", 
  "ifPart", "stmtOrExpr", "quotStmtPart", "quotStmtExpr", "ifStmt", "ifExpr", 
  "whileStmtPart", "whileStmt", "allAssign", "allOp", "quotExpr", "exprPrefix", 
  "exprBody", "exprSuffix", "normalExpr", "expr", "useStmt", "normalStmt", 
  "stmt", "publicLevel", "classParent", "classItemPart", "classItemFieldBlock", 
  "classItemFuncBlock", "classBlock", "callConvention", "importStmt", "libStmt", 
  "importBlock", "faEntryMainFuncBlock", "program"
};

std::vector<std::string> FaParser::_literalNames = {
  "", "'@import'", "'@lib'", "'break'", "'__cdecl'", "'__fastcall'", "'__stdcall'", 
  "'continue'", "'class'", "'const'", "'else'", "'FaEntryMain'", "'if'", 
  "'internal'", "'public'", "'protected'", "'private'", "'return'", "'signed'", 
  "'static'", "'unsigned'", "'use'", "'while'", "'='", "'\u003F\u003F='", 
  "'+='", "'-='", "'*='", "'**='", "'/='", "'%='", "'&='", "'|='", "'^='", 
  "'&&='", "'||='", "'<<='", "'>>='", "'~'", "'++'", "'--'", "'.'", "'\u003F\u003F'", 
  "'+'", "'-'", "'*'", "'/'", "'**'", "'%'", "'&'", "'|'", "'^'", "'&&'", 
  "'||'", "'\u003F'", "','", "'::'", "':'", "';'", "'['", "']'", "'<'", 
  "'>'", "'{'", "'}'", "'('", "')'"
};

std::vector<std::string> FaParser::_symbolicNames = {
  "", "AImport", "ALib", "Break", "CC__Cdecl", "CC__FastCall", "CC__StdCall", 
  "Continue", "Class", "Const", "Else", "FaEntryMain", "If", "Internal", 
  "Public", "Protected", "Private", "Return", "Signed", "Static", "Unsigned", 
  "Use", "While", "Assign", "QusQusAssign", "AddAssign", "SubAssign", "StarAssign", 
  "StarStarAssign", "DivAssign", "ModAssign", "AndAssign", "OrAssign", "XorAssign", 
  "AndAndAssign", "OrOrAssign", "ShiftLAssign", "ShiftRAssign", "ReverseOp", 
  "AddAddOp", "SubSubOp", "PointOp", "QusQusOp", "AddOp", "SubOp", "StarOp", 
  "DivOp", "StarStarOp", "ModOp", "AndOp", "OrOp", "XorOp", "AndAndOp", 
  "OrOrOp", "Qus", "Comma", "ColonColon", "Colon", "Semi", "QuotFangL", 
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
       0x3, 0x4c, 0x1ea, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
       0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 
       0x3, 0x5, 0x7, 0x5, 0x66, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x69, 0xb, 
       0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x6f, 0xa, 
       0x6, 0x3, 0x7, 0x5, 0x7, 0x72, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
       0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x7a, 0xa, 0x7, 0xc, 
       0x7, 0xe, 0x7, 0x7d, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
       0x7, 0x3, 0x7, 0x3, 0x7, 0x6, 0x7, 0x85, 0xa, 0x7, 0xd, 0x7, 0xe, 
       0x7, 0x86, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x8b, 0xa, 0x7, 0x3, 0x7, 
       0x7, 0x7, 0x8e, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x91, 0xb, 0x7, 0x3, 
       0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x97, 0xa, 0x8, 0x3, 
       0x9, 0x3, 0x9, 0x3, 0xa, 0x5, 0xa, 0x9c, 0xa, 0xa, 0x3, 0xa, 0x5, 
       0xa, 0x9f, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xa3, 0xa, 0xa, 
       0xc, 0xa, 0xe, 0xa, 0xa6, 0xb, 0xa, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 
       0xaa, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0xaf, 0xa, 
       0xc, 0xc, 0xc, 0xe, 0xc, 0xb2, 0xb, 0xc, 0x3, 0xd, 0x3, 0xd, 0x5, 
       0xd, 0xb6, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0xbb, 
       0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0xbe, 0xb, 0xe, 0x3, 0xf, 0x3, 0xf, 
       0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xc7, 
       0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 0xcb, 0xa, 0x11, 0xc, 
       0x11, 0xe, 0x11, 0xce, 0xb, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 
       0xd2, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0xd6, 0xa, 0x12, 
       0xc, 0x12, 0xe, 0x12, 0xd9, 0xb, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
       0x12, 0x3, 0x12, 0x5, 0x12, 0xdf, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 
       0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0xe7, 0xa, 
       0x13, 0xc, 0x13, 0xe, 0x13, 0xea, 0xb, 0x13, 0x3, 0x13, 0x3, 0x13, 
       0x5, 0x13, 0xee, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
       0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0xf6, 0xa, 0x14, 0xc, 0x14, 
       0xe, 0x14, 0xf9, 0xb, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0xfd, 
       0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 0x101, 0xa, 0x15, 0xc, 
       0x15, 0xe, 0x15, 0x104, 0xb, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 
       0x108, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
       0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 
       0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 
       0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 
       0x18, 0x5, 0x18, 0x121, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
       0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
       0x3, 0x1b, 0x5, 0x1b, 0x12d, 0xa, 0x1b, 0x3, 0x1c, 0x6, 0x1c, 0x130, 
       0xa, 0x1c, 0xd, 0x1c, 0xe, 0x1c, 0x131, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
       0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x138, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 
       0x13b, 0xb, 0x1c, 0x5, 0x1c, 0x13d, 0xa, 0x1c, 0x3, 0x1c, 0x6, 0x1c, 
       0x140, 0xa, 0x1c, 0xd, 0x1c, 0xe, 0x1c, 0x141, 0x3, 0x1c, 0x3, 0x1c, 
       0x3, 0x1c, 0x3, 0x1c, 0x6, 0x1c, 0x148, 0xa, 0x1c, 0xd, 0x1c, 0xe, 
       0x1c, 0x149, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x14e, 0xa, 0x1c, 0x3, 
       0x1c, 0x3, 0x1c, 0x6, 0x1c, 0x152, 0xa, 0x1c, 0xd, 0x1c, 0xe, 0x1c, 
       0x153, 0x5, 0x1c, 0x156, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x7, 0x1d, 
       0x15a, 0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 0x15d, 0xb, 0x1d, 0x3, 0x1d, 
       0x3, 0x1d, 0x7, 0x1d, 0x161, 0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 0x164, 
       0xb, 0x1d, 0x5, 0x1d, 0x166, 0xa, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x5, 
       0x1e, 0x16a, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
       0x3, 0x20, 0x5, 0x20, 0x171, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 
       0x20, 0x5, 0x20, 0x176, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 
       0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x17d, 0xa, 0x21, 0x3, 0x22, 0x3, 
       0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x7, 0x23, 0x185, 
       0xa, 0x23, 0xc, 0x23, 0xe, 0x23, 0x188, 0xb, 0x23, 0x3, 0x24, 0x5, 
       0x24, 0x18b, 0xa, 0x24, 0x3, 0x24, 0x5, 0x24, 0x18e, 0xa, 0x24, 0x3, 
       0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 
       0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x7, 
       0x26, 0x19c, 0xa, 0x26, 0xc, 0x26, 0xe, 0x26, 0x19f, 0xb, 0x26, 0x3, 
       0x26, 0x3, 0x26, 0x3, 0x27, 0x5, 0x27, 0x1a4, 0xa, 0x27, 0x3, 0x27, 
       0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x1a9, 0xa, 0x27, 0x3, 0x27, 0x3, 
       0x27, 0x3, 0x27, 0x7, 0x27, 0x1ae, 0xa, 0x27, 0xc, 0x27, 0xe, 0x27, 
       0x1b1, 0xb, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 
       0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 
       0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 
       0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x6, 0x2b, 0x1c6, 0xa, 0x2b, 0xd, 0x2b, 
       0xe, 0x2b, 0x1c7, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 
       0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x7, 0x2c, 0x1d1, 0xa, 0x2c, 0xc, 0x2c, 
       0xe, 0x2c, 0x1d4, 0xb, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 0x7, 
       0x2d, 0x1d9, 0xa, 0x2d, 0xc, 0x2d, 0xe, 0x2d, 0x1dc, 0xb, 0x2d, 0x3, 
       0x2d, 0x5, 0x2d, 0x1df, 0xa, 0x2d, 0x3, 0x2d, 0x7, 0x2d, 0x1e2, 0xa, 
       0x2d, 0xc, 0x2d, 0xe, 0x2d, 0x1e5, 0xb, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 
       0x1e8, 0xa, 0x2d, 0x3, 0x2d, 0x2, 0x2, 0x2e, 0x2, 0x4, 0x6, 0x8, 
       0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 
       0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 
       0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 
       0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x2, 0x9, 0x3, 0x2, 0x45, 0x48, 
       0x4, 0x2, 0x14, 0x14, 0x16, 0x16, 0x3, 0x2, 0x19, 0x27, 0x4, 0x2, 
       0x28, 0x2a, 0x2d, 0x2e, 0x3, 0x2, 0x29, 0x2a, 0x3, 0x2, 0xf, 0x12, 
       0x3, 0x2, 0x6, 0x8, 0x2, 0x20c, 0x2, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x4, 
       0x5d, 0x3, 0x2, 0x2, 0x2, 0x6, 0x60, 0x3, 0x2, 0x2, 0x2, 0x8, 0x62, 
       0x3, 0x2, 0x2, 0x2, 0xa, 0x6e, 0x3, 0x2, 0x2, 0x2, 0xc, 0x71, 0x3, 
       0x2, 0x2, 0x2, 0xe, 0x96, 0x3, 0x2, 0x2, 0x2, 0x10, 0x98, 0x3, 0x2, 
       0x2, 0x2, 0x12, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x14, 0xa7, 0x3, 0x2, 0x2, 
       0x2, 0x16, 0xab, 0x3, 0x2, 0x2, 0x2, 0x18, 0xb3, 0x3, 0x2, 0x2, 0x2, 
       0x1a, 0xb7, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x1e, 
       0xc6, 0x3, 0x2, 0x2, 0x2, 0x20, 0xd1, 0x3, 0x2, 0x2, 0x2, 0x22, 0xde, 
       0x3, 0x2, 0x2, 0x2, 0x24, 0xe0, 0x3, 0x2, 0x2, 0x2, 0x26, 0xef, 0x3, 
       0x2, 0x2, 0x2, 0x28, 0x107, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x109, 0x3, 
       0x2, 0x2, 0x2, 0x2c, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x120, 0x3, 
       0x2, 0x2, 0x2, 0x30, 0x122, 0x3, 0x2, 0x2, 0x2, 0x32, 0x126, 0x3, 
       0x2, 0x2, 0x2, 0x34, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x36, 0x155, 0x3, 
       0x2, 0x2, 0x2, 0x38, 0x165, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x169, 0x3, 
       0x2, 0x2, 0x2, 0x3c, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x175, 0x3, 
       0x2, 0x2, 0x2, 0x40, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x42, 0x17e, 0x3, 
       0x2, 0x2, 0x2, 0x44, 0x180, 0x3, 0x2, 0x2, 0x2, 0x46, 0x18a, 0x3, 
       0x2, 0x2, 0x2, 0x48, 0x192, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x195, 0x3, 
       0x2, 0x2, 0x2, 0x4c, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x1b4, 0x3, 
       0x2, 0x2, 0x2, 0x50, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x52, 0x1bf, 0x3, 
       0x2, 0x2, 0x2, 0x54, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x56, 0x1c9, 0x3, 
       0x2, 0x2, 0x2, 0x58, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5b, 0x7, 
       0x3f, 0x2, 0x2, 0x5b, 0x5c, 0x7, 0x3f, 0x2, 0x2, 0x5c, 0x3, 0x3, 
       0x2, 0x2, 0x2, 0x5d, 0x5e, 0x7, 0x40, 0x2, 0x2, 0x5e, 0x5f, 0x7, 
       0x40, 0x2, 0x2, 0x5f, 0x5, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x9, 0x2, 
       0x2, 0x2, 0x61, 0x7, 0x3, 0x2, 0x2, 0x2, 0x62, 0x67, 0x7, 0x49, 0x2, 
       0x2, 0x63, 0x64, 0x7, 0x2b, 0x2, 0x2, 0x64, 0x66, 0x7, 0x49, 0x2, 
       0x2, 0x65, 0x63, 0x3, 0x2, 0x2, 0x2, 0x66, 0x69, 0x3, 0x2, 0x2, 0x2, 
       0x67, 0x65, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x3, 0x2, 0x2, 0x2, 0x68, 
       0x9, 0x3, 0x2, 0x2, 0x2, 0x69, 0x67, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 
       0x7, 0x3d, 0x2, 0x2, 0x6b, 0x6f, 0x7, 0x3e, 0x2, 0x2, 0x6c, 0x6f, 
       0x7, 0x33, 0x2, 0x2, 0x6d, 0x6f, 0x7, 0x38, 0x2, 0x2, 0x6e, 0x6a, 
       0x3, 0x2, 0x2, 0x2, 0x6e, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6d, 0x3, 
       0x2, 0x2, 0x2, 0x6f, 0xb, 0x3, 0x2, 0x2, 0x2, 0x70, 0x72, 0x7, 0xb, 
       0x2, 0x2, 0x71, 0x70, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 0x3, 0x2, 0x2, 
       0x2, 0x72, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x73, 0x8b, 0x7, 0x49, 0x2, 
       0x2, 0x74, 0x75, 0x7, 0x49, 0x2, 0x2, 0x75, 0x76, 0x7, 0x3f, 0x2, 
       0x2, 0x76, 0x7b, 0x5, 0xc, 0x7, 0x2, 0x77, 0x78, 0x7, 0x39, 0x2, 
       0x2, 0x78, 0x7a, 0x5, 0xc, 0x7, 0x2, 0x79, 0x77, 0x3, 0x2, 0x2, 0x2, 
       0x7a, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x79, 0x3, 0x2, 0x2, 0x2, 0x7b, 
       0x7c, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7b, 
       0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x7, 0x40, 0x2, 0x2, 0x7f, 0x8b, 
       0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 0x7, 0x43, 0x2, 0x2, 0x81, 0x84, 
       0x5, 0xc, 0x7, 0x2, 0x82, 0x83, 0x7, 0x39, 0x2, 0x2, 0x83, 0x85, 
       0x5, 0xc, 0x7, 0x2, 0x84, 0x82, 0x3, 0x2, 0x2, 0x2, 0x85, 0x86, 0x3, 
       0x2, 0x2, 0x2, 0x86, 0x84, 0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 0x3, 0x2, 
       0x2, 0x2, 0x87, 0x88, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x7, 0x44, 
       0x2, 0x2, 0x89, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x73, 0x3, 0x2, 0x2, 
       0x2, 0x8a, 0x74, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x80, 0x3, 0x2, 0x2, 0x2, 
       0x8b, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8e, 0x5, 0xa, 0x6, 0x2, 0x8d, 
       0x8c, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x91, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x8d, 
       0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x3, 0x2, 0x2, 0x2, 0x90, 0xd, 0x3, 
       0x2, 0x2, 0x2, 0x91, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x7, 0x3d, 
       0x2, 0x2, 0x93, 0x97, 0x7, 0x3e, 0x2, 0x2, 0x94, 0x97, 0x7, 0x33, 
       0x2, 0x2, 0x95, 0x97, 0x7, 0x2f, 0x2, 0x2, 0x96, 0x92, 0x3, 0x2, 
       0x2, 0x2, 0x96, 0x94, 0x3, 0x2, 0x2, 0x2, 0x96, 0x95, 0x3, 0x2, 0x2, 
       0x2, 0x97, 0xf, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x9, 0x3, 0x2, 0x2, 
       0x99, 0x11, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9c, 0x7, 0xb, 0x2, 0x2, 0x9b, 
       0x9a, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9e, 
       0x3, 0x2, 0x2, 0x2, 0x9d, 0x9f, 0x5, 0x10, 0x9, 0x2, 0x9e, 0x9d, 
       0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 0x3, 
       0x2, 0x2, 0x2, 0xa0, 0xa4, 0x7, 0x49, 0x2, 0x2, 0xa1, 0xa3, 0x5, 
       0xe, 0x8, 0x2, 0xa2, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa6, 0x3, 0x2, 
       0x2, 0x2, 0xa4, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x3, 0x2, 0x2, 
       0x2, 0xa5, 0x13, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa4, 0x3, 0x2, 0x2, 0x2, 
       0xa7, 0xa9, 0x5, 0xc, 0x7, 0x2, 0xa8, 0xaa, 0x7, 0x49, 0x2, 0x2, 
       0xa9, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xaa, 
       0x15, 0x3, 0x2, 0x2, 0x2, 0xab, 0xb0, 0x5, 0x14, 0xb, 0x2, 0xac, 
       0xad, 0x7, 0x39, 0x2, 0x2, 0xad, 0xaf, 0x5, 0x14, 0xb, 0x2, 0xae, 
       0xac, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xae, 
       0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb1, 0x17, 0x3, 
       0x2, 0x2, 0x2, 0xb2, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb5, 0x5, 0x12, 
       0xa, 0x2, 0xb4, 0xb6, 0x7, 0x49, 0x2, 0x2, 0xb5, 0xb4, 0x3, 0x2, 
       0x2, 0x2, 0xb5, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb6, 0x19, 0x3, 0x2, 0x2, 
       0x2, 0xb7, 0xbc, 0x5, 0x18, 0xd, 0x2, 0xb8, 0xb9, 0x7, 0x39, 0x2, 
       0x2, 0xb9, 0xbb, 0x5, 0x18, 0xd, 0x2, 0xba, 0xb8, 0x3, 0x2, 0x2, 
       0x2, 0xbb, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xba, 0x3, 0x2, 0x2, 0x2, 
       0xbc, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbd, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xbe, 
       0xbc, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x7, 0xe, 0x2, 0x2, 0xc0, 0xc1, 
       0x7, 0x43, 0x2, 0x2, 0xc1, 0xc2, 0x5, 0x3a, 0x1e, 0x2, 0xc2, 0xc3, 
       0x7, 0x44, 0x2, 0x2, 0xc3, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc7, 
       0x5, 0x40, 0x21, 0x2, 0xc5, 0xc7, 0x5, 0x3a, 0x1e, 0x2, 0xc6, 0xc4, 
       0x3, 0x2, 0x2, 0x2, 0xc6, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc7, 0x1f, 0x3, 
       0x2, 0x2, 0x2, 0xc8, 0xcc, 0x7, 0x41, 0x2, 0x2, 0xc9, 0xcb, 0x5, 
       0x40, 0x21, 0x2, 0xca, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xce, 0x3, 
       0x2, 0x2, 0x2, 0xcc, 0xca, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0x3, 0x2, 
       0x2, 0x2, 0xcd, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcc, 0x3, 0x2, 0x2, 
       0x2, 0xcf, 0xd2, 0x7, 0x42, 0x2, 0x2, 0xd0, 0xd2, 0x5, 0x40, 0x21, 
       0x2, 0xd1, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd0, 0x3, 0x2, 0x2, 0x2, 
       0xd2, 0x21, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd7, 0x7, 0x41, 0x2, 0x2, 
       0xd4, 0xd6, 0x5, 0x1e, 0x10, 0x2, 0xd5, 0xd4, 0x3, 0x2, 0x2, 0x2, 
       0xd6, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd7, 
       0xd8, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xda, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xd7, 
       0x3, 0x2, 0x2, 0x2, 0xda, 0xdb, 0x5, 0x3a, 0x1e, 0x2, 0xdb, 0xdc, 
       0x7, 0x42, 0x2, 0x2, 0xdc, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdf, 
       0x5, 0x3a, 0x1e, 0x2, 0xde, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdd, 
       0x3, 0x2, 0x2, 0x2, 0xdf, 0x23, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x5, 
       0x1c, 0xf, 0x2, 0xe1, 0xe8, 0x5, 0x20, 0x11, 0x2, 0xe2, 0xe3, 0x7, 
       0xc, 0x2, 0x2, 0xe3, 0xe4, 0x5, 0x1c, 0xf, 0x2, 0xe4, 0xe5, 0x5, 
       0x20, 0x11, 0x2, 0xe5, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe2, 0x3, 
       0x2, 0x2, 0x2, 0xe7, 0xea, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe6, 0x3, 0x2, 
       0x2, 0x2, 0xe8, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xed, 0x3, 0x2, 0x2, 
       0x2, 0xea, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xec, 0x7, 0xc, 0x2, 0x2, 
       0xec, 0xee, 0x5, 0x20, 0x11, 0x2, 0xed, 0xeb, 0x3, 0x2, 0x2, 0x2, 
       0xed, 0xee, 0x3, 0x2, 0x2, 0x2, 0xee, 0x25, 0x3, 0x2, 0x2, 0x2, 0xef, 
       0xf0, 0x5, 0x1c, 0xf, 0x2, 0xf0, 0xf7, 0x5, 0x22, 0x12, 0x2, 0xf1, 
       0xf2, 0x7, 0xc, 0x2, 0x2, 0xf2, 0xf3, 0x5, 0x1c, 0xf, 0x2, 0xf3, 
       0xf4, 0x5, 0x22, 0x12, 0x2, 0xf4, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf5, 
       0xf1, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf5, 
       0x3, 0x2, 0x2, 0x2, 0xf7, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xfc, 0x3, 
       0x2, 0x2, 0x2, 0xf9, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfb, 0x7, 0xc, 
       0x2, 0x2, 0xfb, 0xfd, 0x5, 0x22, 0x12, 0x2, 0xfc, 0xfa, 0x3, 0x2, 
       0x2, 0x2, 0xfc, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xfd, 0x27, 0x3, 0x2, 0x2, 
       0x2, 0xfe, 0x102, 0x7, 0x41, 0x2, 0x2, 0xff, 0x101, 0x5, 0x40, 0x21, 
       0x2, 0x100, 0xff, 0x3, 0x2, 0x2, 0x2, 0x101, 0x104, 0x3, 0x2, 0x2, 
       0x2, 0x102, 0x100, 0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 0x3, 0x2, 0x2, 
       0x2, 0x103, 0x105, 0x3, 0x2, 0x2, 0x2, 0x104, 0x102, 0x3, 0x2, 0x2, 
       0x2, 0x105, 0x108, 0x7, 0x42, 0x2, 0x2, 0x106, 0x108, 0x5, 0x40, 
       0x21, 0x2, 0x107, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x107, 0x106, 0x3, 0x2, 
       0x2, 0x2, 0x108, 0x29, 0x3, 0x2, 0x2, 0x2, 0x109, 0x10a, 0x7, 0x18, 
       0x2, 0x2, 0x10a, 0x10b, 0x7, 0x43, 0x2, 0x2, 0x10b, 0x10c, 0x5, 0x3a, 
       0x1e, 0x2, 0x10c, 0x10d, 0x7, 0x44, 0x2, 0x2, 0x10d, 0x10e, 0x5, 
       0x28, 0x15, 0x2, 0x10e, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x110, 0x9, 
       0x4, 0x2, 0x2, 0x110, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x111, 0x121, 0x7, 
       0x2c, 0x2, 0x2, 0x112, 0x121, 0x7, 0x2b, 0x2, 0x2, 0x113, 0x121, 
       0x7, 0x2d, 0x2, 0x2, 0x114, 0x121, 0x7, 0x2e, 0x2, 0x2, 0x115, 0x121, 
       0x7, 0x2f, 0x2, 0x2, 0x116, 0x121, 0x7, 0x30, 0x2, 0x2, 0x117, 0x121, 
       0x7, 0x31, 0x2, 0x2, 0x118, 0x121, 0x7, 0x32, 0x2, 0x2, 0x119, 0x121, 
       0x7, 0x33, 0x2, 0x2, 0x11a, 0x121, 0x7, 0x34, 0x2, 0x2, 0x11b, 0x121, 
       0x7, 0x35, 0x2, 0x2, 0x11c, 0x121, 0x7, 0x36, 0x2, 0x2, 0x11d, 0x121, 
       0x7, 0x37, 0x2, 0x2, 0x11e, 0x121, 0x5, 0x2, 0x2, 0x2, 0x11f, 0x121, 
       0x5, 0x4, 0x3, 0x2, 0x120, 0x111, 0x3, 0x2, 0x2, 0x2, 0x120, 0x112, 
       0x3, 0x2, 0x2, 0x2, 0x120, 0x113, 0x3, 0x2, 0x2, 0x2, 0x120, 0x114, 
       0x3, 0x2, 0x2, 0x2, 0x120, 0x115, 0x3, 0x2, 0x2, 0x2, 0x120, 0x116, 
       0x3, 0x2, 0x2, 0x2, 0x120, 0x117, 0x3, 0x2, 0x2, 0x2, 0x120, 0x118, 
       0x3, 0x2, 0x2, 0x2, 0x120, 0x119, 0x3, 0x2, 0x2, 0x2, 0x120, 0x11a, 
       0x3, 0x2, 0x2, 0x2, 0x120, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x120, 0x11c, 
       0x3, 0x2, 0x2, 0x2, 0x120, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x120, 0x11e, 
       0x3, 0x2, 0x2, 0x2, 0x120, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x121, 0x2f, 
       0x3, 0x2, 0x2, 0x2, 0x122, 0x123, 0x7, 0x43, 0x2, 0x2, 0x123, 0x124, 
       0x5, 0x3a, 0x1e, 0x2, 0x124, 0x125, 0x7, 0x44, 0x2, 0x2, 0x125, 0x31, 
       0x3, 0x2, 0x2, 0x2, 0x126, 0x127, 0x9, 0x5, 0x2, 0x2, 0x127, 0x33, 
       0x3, 0x2, 0x2, 0x2, 0x128, 0x12d, 0x5, 0x8, 0x5, 0x2, 0x129, 0x12a, 
       0x7, 0x3a, 0x2, 0x2, 0x12a, 0x12d, 0x7, 0x49, 0x2, 0x2, 0x12b, 0x12d, 
       0x5, 0x6, 0x4, 0x2, 0x12c, 0x128, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x129, 
       0x3, 0x2, 0x2, 0x2, 0x12c, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x35, 
       0x3, 0x2, 0x2, 0x2, 0x12e, 0x130, 0x9, 0x6, 0x2, 0x2, 0x12f, 0x12e, 
       0x3, 0x2, 0x2, 0x2, 0x130, 0x131, 0x3, 0x2, 0x2, 0x2, 0x131, 0x12f, 
       0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 0x3, 0x2, 0x2, 0x2, 0x132, 0x156, 
       0x3, 0x2, 0x2, 0x2, 0x133, 0x13c, 0x7, 0x43, 0x2, 0x2, 0x134, 0x139, 
       0x5, 0x3a, 0x1e, 0x2, 0x135, 0x136, 0x7, 0x39, 0x2, 0x2, 0x136, 0x138, 
       0x5, 0x3a, 0x1e, 0x2, 0x137, 0x135, 0x3, 0x2, 0x2, 0x2, 0x138, 0x13b, 
       0x3, 0x2, 0x2, 0x2, 0x139, 0x137, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13a, 
       0x3, 0x2, 0x2, 0x2, 0x13a, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x139, 
       0x3, 0x2, 0x2, 0x2, 0x13c, 0x134, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13d, 
       0x3, 0x2, 0x2, 0x2, 0x13d, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x140, 
       0x7, 0x44, 0x2, 0x2, 0x13f, 0x133, 0x3, 0x2, 0x2, 0x2, 0x140, 0x141, 
       0x3, 0x2, 0x2, 0x2, 0x141, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x141, 0x142, 
       0x3, 0x2, 0x2, 0x2, 0x142, 0x156, 0x3, 0x2, 0x2, 0x2, 0x143, 0x144, 
       0x7, 0x3d, 0x2, 0x2, 0x144, 0x145, 0x5, 0x3a, 0x1e, 0x2, 0x145, 0x146, 
       0x7, 0x3d, 0x2, 0x2, 0x146, 0x148, 0x3, 0x2, 0x2, 0x2, 0x147, 0x143, 
       0x3, 0x2, 0x2, 0x2, 0x148, 0x149, 0x3, 0x2, 0x2, 0x2, 0x149, 0x147, 
       0x3, 0x2, 0x2, 0x2, 0x149, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x156, 
       0x3, 0x2, 0x2, 0x2, 0x14b, 0x14e, 0x5, 0x2c, 0x17, 0x2, 0x14c, 0x14e, 
       0x5, 0x2e, 0x18, 0x2, 0x14d, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14c, 
       0x3, 0x2, 0x2, 0x2, 0x14e, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x150, 
       0x5, 0x3a, 0x1e, 0x2, 0x150, 0x152, 0x3, 0x2, 0x2, 0x2, 0x151, 0x14d, 
       0x3, 0x2, 0x2, 0x2, 0x152, 0x153, 0x3, 0x2, 0x2, 0x2, 0x153, 0x151, 
       0x3, 0x2, 0x2, 0x2, 0x153, 0x154, 0x3, 0x2, 0x2, 0x2, 0x154, 0x156, 
       0x3, 0x2, 0x2, 0x2, 0x155, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x155, 0x13f, 
       0x3, 0x2, 0x2, 0x2, 0x155, 0x147, 0x3, 0x2, 0x2, 0x2, 0x155, 0x151, 
       0x3, 0x2, 0x2, 0x2, 0x156, 0x37, 0x3, 0x2, 0x2, 0x2, 0x157, 0x166, 
       0x5, 0x30, 0x19, 0x2, 0x158, 0x15a, 0x5, 0x32, 0x1a, 0x2, 0x159, 
       0x158, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x15b, 
       0x159, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15c, 
       0x15e, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x15e, 
       0x162, 0x5, 0x34, 0x1b, 0x2, 0x15f, 0x161, 0x5, 0x36, 0x1c, 0x2, 
       0x160, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x161, 0x164, 0x3, 0x2, 0x2, 0x2, 
       0x162, 0x160, 0x3, 0x2, 0x2, 0x2, 0x162, 0x163, 0x3, 0x2, 0x2, 0x2, 
       0x163, 0x166, 0x3, 0x2, 0x2, 0x2, 0x164, 0x162, 0x3, 0x2, 0x2, 0x2, 
       0x165, 0x157, 0x3, 0x2, 0x2, 0x2, 0x165, 0x15b, 0x3, 0x2, 0x2, 0x2, 
       0x166, 0x39, 0x3, 0x2, 0x2, 0x2, 0x167, 0x16a, 0x5, 0x38, 0x1d, 0x2, 
       0x168, 0x16a, 0x5, 0x26, 0x14, 0x2, 0x169, 0x167, 0x3, 0x2, 0x2, 
       0x2, 0x169, 0x168, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x3b, 0x3, 0x2, 0x2, 
       0x2, 0x16b, 0x16c, 0x7, 0x17, 0x2, 0x2, 0x16c, 0x16d, 0x5, 0x8, 0x5, 
       0x2, 0x16d, 0x16e, 0x7, 0x3c, 0x2, 0x2, 0x16e, 0x3d, 0x3, 0x2, 0x2, 
       0x2, 0x16f, 0x171, 0x7, 0x13, 0x2, 0x2, 0x170, 0x16f, 0x3, 0x2, 0x2, 
       0x2, 0x170, 0x171, 0x3, 0x2, 0x2, 0x2, 0x171, 0x172, 0x3, 0x2, 0x2, 
       0x2, 0x172, 0x176, 0x5, 0x3a, 0x1e, 0x2, 0x173, 0x176, 0x7, 0x5, 
       0x2, 0x2, 0x174, 0x176, 0x7, 0x9, 0x2, 0x2, 0x175, 0x170, 0x3, 0x2, 
       0x2, 0x2, 0x175, 0x173, 0x3, 0x2, 0x2, 0x2, 0x175, 0x174, 0x3, 0x2, 
       0x2, 0x2, 0x176, 0x177, 0x3, 0x2, 0x2, 0x2, 0x177, 0x178, 0x7, 0x3c, 
       0x2, 0x2, 0x178, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x179, 0x17d, 0x5, 0x3e, 
       0x20, 0x2, 0x17a, 0x17d, 0x5, 0x24, 0x13, 0x2, 0x17b, 0x17d, 0x5, 
       0x2a, 0x16, 0x2, 0x17c, 0x179, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x17a, 
       0x3, 0x2, 0x2, 0x2, 0x17c, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x41, 
       0x3, 0x2, 0x2, 0x2, 0x17e, 0x17f, 0x9, 0x7, 0x2, 0x2, 0x17f, 0x43, 
       0x3, 0x2, 0x2, 0x2, 0x180, 0x181, 0x7, 0x3b, 0x2, 0x2, 0x181, 0x186, 
       0x5, 0x8, 0x5, 0x2, 0x182, 0x183, 0x7, 0x39, 0x2, 0x2, 0x183, 0x185, 
       0x5, 0x8, 0x5, 0x2, 0x184, 0x182, 0x3, 0x2, 0x2, 0x2, 0x185, 0x188, 
       0x3, 0x2, 0x2, 0x2, 0x186, 0x184, 0x3, 0x2, 0x2, 0x2, 0x186, 0x187, 
       0x3, 0x2, 0x2, 0x2, 0x187, 0x45, 0x3, 0x2, 0x2, 0x2, 0x188, 0x186, 
       0x3, 0x2, 0x2, 0x2, 0x189, 0x18b, 0x5, 0x42, 0x22, 0x2, 0x18a, 0x189, 
       0x3, 0x2, 0x2, 0x2, 0x18a, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x18d, 
       0x3, 0x2, 0x2, 0x2, 0x18c, 0x18e, 0x7, 0x15, 0x2, 0x2, 0x18d, 0x18c, 
       0x3, 0x2, 0x2, 0x2, 0x18d, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x18f, 
       0x3, 0x2, 0x2, 0x2, 0x18f, 0x190, 0x7, 0x49, 0x2, 0x2, 0x190, 0x191, 
       0x7, 0x49, 0x2, 0x2, 0x191, 0x47, 0x3, 0x2, 0x2, 0x2, 0x192, 0x193, 
       0x5, 0x46, 0x24, 0x2, 0x193, 0x194, 0x7, 0x3c, 0x2, 0x2, 0x194, 0x49, 
       0x3, 0x2, 0x2, 0x2, 0x195, 0x196, 0x5, 0x46, 0x24, 0x2, 0x196, 0x197, 
       0x7, 0x43, 0x2, 0x2, 0x197, 0x198, 0x5, 0x16, 0xc, 0x2, 0x198, 0x199, 
       0x7, 0x44, 0x2, 0x2, 0x199, 0x19d, 0x7, 0x41, 0x2, 0x2, 0x19a, 0x19c, 
       0x5, 0x40, 0x21, 0x2, 0x19b, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x19f, 
       0x3, 0x2, 0x2, 0x2, 0x19d, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x19e, 
       0x3, 0x2, 0x2, 0x2, 0x19e, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x19d, 
       0x3, 0x2, 0x2, 0x2, 0x1a0, 0x1a1, 0x7, 0x42, 0x2, 0x2, 0x1a1, 0x4b, 
       0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a4, 0x5, 0x42, 0x22, 0x2, 0x1a3, 0x1a2, 
       0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a5, 
       0x3, 0x2, 0x2, 0x2, 0x1a5, 0x1a6, 0x7, 0xa, 0x2, 0x2, 0x1a6, 0x1a8, 
       0x7, 0x49, 0x2, 0x2, 0x1a7, 0x1a9, 0x5, 0x44, 0x23, 0x2, 0x1a8, 0x1a7, 
       0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1a9, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1aa, 
       0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1af, 0x7, 0x41, 0x2, 0x2, 0x1ab, 0x1ae, 
       0x5, 0x48, 0x25, 0x2, 0x1ac, 0x1ae, 0x5, 0x4a, 0x26, 0x2, 0x1ad, 
       0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1ae, 
       0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1af, 
       0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x1b1, 
       0x1af, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b3, 0x7, 0x42, 0x2, 0x2, 0x1b3, 
       0x4d, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1b5, 0x9, 0x8, 0x2, 0x2, 0x1b5, 
       0x4f, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b7, 0x7, 0x3, 0x2, 0x2, 0x1b7, 
       0x1b8, 0x5, 0x12, 0xa, 0x2, 0x1b8, 0x1b9, 0x5, 0x4e, 0x28, 0x2, 0x1b9, 
       0x1ba, 0x7, 0x49, 0x2, 0x2, 0x1ba, 0x1bb, 0x7, 0x43, 0x2, 0x2, 0x1bb, 
       0x1bc, 0x5, 0x1a, 0xe, 0x2, 0x1bc, 0x1bd, 0x7, 0x44, 0x2, 0x2, 0x1bd, 
       0x1be, 0x7, 0x3c, 0x2, 0x2, 0x1be, 0x51, 0x3, 0x2, 0x2, 0x2, 0x1bf, 
       0x1c0, 0x7, 0x4, 0x2, 0x2, 0x1c0, 0x1c1, 0x7, 0x48, 0x2, 0x2, 0x1c1, 
       0x1c2, 0x7, 0x3c, 0x2, 0x2, 0x1c2, 0x53, 0x3, 0x2, 0x2, 0x2, 0x1c3, 
       0x1c6, 0x5, 0x50, 0x29, 0x2, 0x1c4, 0x1c6, 0x5, 0x52, 0x2a, 0x2, 
       0x1c5, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c4, 0x3, 0x2, 0x2, 0x2, 
       0x1c6, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1c5, 0x3, 0x2, 0x2, 0x2, 
       0x1c7, 0x1c8, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x55, 0x3, 0x2, 0x2, 0x2, 
       0x1c9, 0x1ca, 0x7, 0x15, 0x2, 0x2, 0x1ca, 0x1cb, 0x5, 0xc, 0x7, 0x2, 
       0x1cb, 0x1cc, 0x7, 0xd, 0x2, 0x2, 0x1cc, 0x1cd, 0x7, 0x43, 0x2, 0x2, 
       0x1cd, 0x1ce, 0x7, 0x44, 0x2, 0x2, 0x1ce, 0x1d2, 0x7, 0x41, 0x2, 
       0x2, 0x1cf, 0x1d1, 0x5, 0x40, 0x21, 0x2, 0x1d0, 0x1cf, 0x3, 0x2, 
       0x2, 0x2, 0x1d1, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d2, 0x1d0, 0x3, 0x2, 
       0x2, 0x2, 0x1d2, 0x1d3, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d5, 0x3, 0x2, 
       0x2, 0x2, 0x1d4, 0x1d2, 0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1d6, 0x7, 0x42, 
       0x2, 0x2, 0x1d6, 0x57, 0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1d9, 0x5, 0x3c, 
       0x1f, 0x2, 0x1d8, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1dc, 0x3, 0x2, 
       0x2, 0x2, 0x1da, 0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x1db, 0x3, 0x2, 
       0x2, 0x2, 0x1db, 0x1de, 0x3, 0x2, 0x2, 0x2, 0x1dc, 0x1da, 0x3, 0x2, 
       0x2, 0x2, 0x1dd, 0x1df, 0x5, 0x54, 0x2b, 0x2, 0x1de, 0x1dd, 0x3, 
       0x2, 0x2, 0x2, 0x1de, 0x1df, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1e3, 0x3, 
       0x2, 0x2, 0x2, 0x1e0, 0x1e2, 0x5, 0x4c, 0x27, 0x2, 0x1e1, 0x1e0, 
       0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e1, 
       0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1e4, 0x1e7, 
       0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1e6, 0x1e8, 
       0x5, 0x56, 0x2c, 0x2, 0x1e7, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1e8, 
       0x3, 0x2, 0x2, 0x2, 0x1e8, 0x59, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x67, 
       0x6e, 0x71, 0x7b, 0x86, 0x8a, 0x8f, 0x96, 0x9b, 0x9e, 0xa4, 0xa9, 
       0xb0, 0xb5, 0xbc, 0xc6, 0xcc, 0xd1, 0xd7, 0xde, 0xe8, 0xed, 0xf7, 
       0xfc, 0x102, 0x107, 0x120, 0x12c, 0x131, 0x139, 0x13c, 0x141, 0x149, 
       0x14d, 0x153, 0x155, 0x15b, 0x162, 0x165, 0x169, 0x170, 0x175, 0x17c, 
       0x186, 0x18a, 0x18d, 0x19d, 0x1a3, 0x1a8, 0x1ad, 0x1af, 0x1c5, 0x1c7, 
       0x1d2, 0x1da, 0x1de, 0x1e3, 0x1e7, 
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

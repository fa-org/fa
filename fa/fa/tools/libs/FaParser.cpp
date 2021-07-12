
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
    setState(82);
    match(FaParser::Id);
    setState(87);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(83);
        match(FaParser::PointOp);
        setState(84);
        match(FaParser::Id); 
      }
      setState(89);
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
  enterRule(_localctx, 2, FaParser::RuleShiftLOp);

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
    match(FaParser::QuotJianL);
    setState(91);
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
  enterRule(_localctx, 4, FaParser::RuleShiftROp);

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
    match(FaParser::QuotJianR);
    setState(94);
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
  enterRule(_localctx, 6, FaParser::RuleLiteral);
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
    setState(96);
    _la = _input->LA(1);
    if (!(((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & ((1ULL << (FaParser::BoolLiteral - 65))
      | (1ULL << (FaParser::IntLiteral - 65))
      | (1ULL << (FaParser::FloatLiteral - 65))
      | (1ULL << (FaParser::String1Literal - 65)))) != 0))) {
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
  enterRule(_localctx, 8, FaParser::RuleTypeAfter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(102);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::QuotFangL: {
        enterOuterAlt(_localctx, 1);
        setState(98);
        match(FaParser::QuotFangL);
        setState(99);
        match(FaParser::QuotFangR);
        break;
      }

      case FaParser::AndOp: {
        enterOuterAlt(_localctx, 2);
        setState(100);
        match(FaParser::AndOp);
        break;
      }

      case FaParser::Qus: {
        enterOuterAlt(_localctx, 3);
        setState(101);
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
    setState(105);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Const) {
      setState(104);
      match(FaParser::Const);
    }
    setState(130);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      setState(107);
      match(FaParser::Id);
      break;
    }

    case 2: {
      setState(108);
      match(FaParser::Id);
      setState(109);
      match(FaParser::QuotJianL);
      setState(110);
      type();
      setState(115);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FaParser::Comma) {
        setState(111);
        match(FaParser::Comma);
        setState(112);
        type();
        setState(117);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(118);
      match(FaParser::QuotJianR);
      break;
    }

    case 3: {
      setState(120);
      match(FaParser::QuotYuanL);
      setState(121);
      type();
      setState(124); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(122);
        match(FaParser::Comma);
        setState(123);
        type();
        setState(126); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == FaParser::Comma);
      setState(128);
      match(FaParser::QuotYuanR);
      break;
    }

    default:
      break;
    }
    setState(135);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::AndOp)
      | (1ULL << FaParser::Qus)
      | (1ULL << FaParser::QuotFangL))) != 0)) {
      setState(132);
      typeAfter();
      setState(137);
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
    setState(142);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::QuotFangL: {
        enterOuterAlt(_localctx, 1);
        setState(138);
        match(FaParser::QuotFangL);
        setState(139);
        match(FaParser::QuotFangR);
        break;
      }

      case FaParser::AndOp: {
        enterOuterAlt(_localctx, 2);
        setState(140);
        match(FaParser::AndOp);
        break;
      }

      case FaParser::StarOp: {
        enterOuterAlt(_localctx, 3);
        setState(141);
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
    setState(144);
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
    setState(147);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Const) {
      setState(146);
      match(FaParser::Const);
    }
    setState(150);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Signed

    || _la == FaParser::Unsigned) {
      setState(149);
      eSign();
    }
    setState(152);
    match(FaParser::Id);
    setState(156);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::StarOp)
      | (1ULL << FaParser::AndOp)
      | (1ULL << FaParser::QuotFangL))) != 0)) {
      setState(153);
      eTypeAfter();
      setState(158);
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
    setState(159);
    type();
    setState(161);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Id) {
      setState(160);
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
    setState(163);
    typeVar();
    setState(168);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(164);
      match(FaParser::Comma);
      setState(165);
      typeVar();
      setState(170);
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
    setState(171);
    eType();
    setState(173);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Id) {
      setState(172);
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
    setState(175);
    eTypeVar();
    setState(180);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(176);
      match(FaParser::Comma);
      setState(177);
      eTypeVar();
      setState(182);
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
    setState(183);
    match(FaParser::If);
    setState(184);
    match(FaParser::QuotYuanL);
    setState(185);
    expr();
    setState(186);
    match(FaParser::QuotYuanR);
   
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
  enterRule(_localctx, 28, FaParser::RuleQuotStmtPart);
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
    setState(188);
    match(FaParser::QuotHuaL);
    setState(192);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 10) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 10)) & ((1ULL << (FaParser::If - 10))
      | (1ULL << (FaParser::Return - 10))
      | (1ULL << (FaParser::Id - 10))
      | (1ULL << (FaParser::ReverseOp - 10))
      | (1ULL << (FaParser::AddAddOp - 10))
      | (1ULL << (FaParser::SubSubOp - 10))
      | (1ULL << (FaParser::AddOp - 10))
      | (1ULL << (FaParser::SubOp - 10))
      | (1ULL << (FaParser::ColonColon - 10))
      | (1ULL << (FaParser::QuotYuanL - 10))
      | (1ULL << (FaParser::BoolLiteral - 10))
      | (1ULL << (FaParser::IntLiteral - 10))
      | (1ULL << (FaParser::FloatLiteral - 10))
      | (1ULL << (FaParser::String1Literal - 10)))) != 0)) {
      setState(189);
      stmt();
      setState(194);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(195);
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
  enterRule(_localctx, 30, FaParser::RuleQuotStmtExpr);

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
    setState(197);
    match(FaParser::QuotHuaL);
    setState(201);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(198);
        stmt(); 
      }
      setState(203);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
    setState(204);
    expr();
    setState(205);
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
  enterRule(_localctx, 32, FaParser::RuleIfStmt);
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
    setState(207);
    ifPart();
    setState(208);
    quotStmtPart();
    setState(215);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(209);
        match(FaParser::Else);
        setState(210);
        ifPart();
        setState(211);
        quotStmtPart(); 
      }
      setState(217);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    }
    setState(220);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Else) {
      setState(218);
      match(FaParser::Else);
      setState(219);
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
  enterRule(_localctx, 34, FaParser::RuleIfExpr);
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
    setState(222);
    ifPart();
    setState(223);
    quotStmtExpr();
    setState(230);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(224);
        match(FaParser::Else);
        setState(225);
        ifPart();
        setState(226);
        quotStmtExpr(); 
      }
      setState(232);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
    setState(235);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Else) {
      setState(233);
      match(FaParser::Else);
      setState(234);
      quotStmtExpr();
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
  enterRule(_localctx, 36, FaParser::RuleAllAssign);
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
    setState(237);
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
  enterRule(_localctx, 38, FaParser::RuleAllOp);

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
    switch (_input->LA(1)) {
      case FaParser::QusQusOp: {
        enterOuterAlt(_localctx, 1);
        setState(239);
        match(FaParser::QusQusOp);
        break;
      }

      case FaParser::PointOp: {
        enterOuterAlt(_localctx, 2);
        setState(240);
        match(FaParser::PointOp);
        break;
      }

      case FaParser::AddOp: {
        enterOuterAlt(_localctx, 3);
        setState(241);
        match(FaParser::AddOp);
        break;
      }

      case FaParser::SubOp: {
        enterOuterAlt(_localctx, 4);
        setState(242);
        match(FaParser::SubOp);
        break;
      }

      case FaParser::StarOp: {
        enterOuterAlt(_localctx, 5);
        setState(243);
        match(FaParser::StarOp);
        break;
      }

      case FaParser::DivOp: {
        enterOuterAlt(_localctx, 6);
        setState(244);
        match(FaParser::DivOp);
        break;
      }

      case FaParser::StarStarOp: {
        enterOuterAlt(_localctx, 7);
        setState(245);
        match(FaParser::StarStarOp);
        break;
      }

      case FaParser::ModOp: {
        enterOuterAlt(_localctx, 8);
        setState(246);
        match(FaParser::ModOp);
        break;
      }

      case FaParser::AndOp: {
        enterOuterAlt(_localctx, 9);
        setState(247);
        match(FaParser::AndOp);
        break;
      }

      case FaParser::OrOp: {
        enterOuterAlt(_localctx, 10);
        setState(248);
        match(FaParser::OrOp);
        break;
      }

      case FaParser::XorOp: {
        enterOuterAlt(_localctx, 11);
        setState(249);
        match(FaParser::XorOp);
        break;
      }

      case FaParser::AndAndOp: {
        enterOuterAlt(_localctx, 12);
        setState(250);
        match(FaParser::AndAndOp);
        break;
      }

      case FaParser::OrOrOp: {
        enterOuterAlt(_localctx, 13);
        setState(251);
        match(FaParser::OrOrOp);
        break;
      }

      case FaParser::QuotJianL: {
        enterOuterAlt(_localctx, 14);
        setState(252);
        shiftLOp();
        break;
      }

      case FaParser::QuotJianR: {
        enterOuterAlt(_localctx, 15);
        setState(253);
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
  enterRule(_localctx, 40, FaParser::RuleQuotExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(256);
    match(FaParser::QuotYuanL);
    setState(257);
    expr();
    setState(258);
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
  enterRule(_localctx, 42, FaParser::RuleExprPrefix);
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
  enterRule(_localctx, 44, FaParser::RuleExprBody);

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
    switch (_input->LA(1)) {
      case FaParser::Id: {
        setState(262);
        ids();
        break;
      }

      case FaParser::ColonColon: {
        setState(263);
        match(FaParser::ColonColon);
        setState(264);
        match(FaParser::Id);
        break;
      }

      case FaParser::BoolLiteral:
      case FaParser::IntLiteral:
      case FaParser::FloatLiteral:
      case FaParser::String1Literal: {
        setState(265);
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
  enterRule(_localctx, 46, FaParser::RuleExprSuffix);
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
    setState(307);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::AddAddOp:
      case FaParser::SubSubOp: {
        enterOuterAlt(_localctx, 1);
        setState(269); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(268);
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
          setState(271); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
        break;
      }

      case FaParser::QuotYuanL: {
        enterOuterAlt(_localctx, 2);
        setState(285); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(273);
                  match(FaParser::QuotYuanL);
                  setState(282);
                  _errHandler->sync(this);

                  _la = _input->LA(1);
                  if (((((_la - 10) & ~ 0x3fULL) == 0) &&
                    ((1ULL << (_la - 10)) & ((1ULL << (FaParser::If - 10))
                    | (1ULL << (FaParser::Id - 10))
                    | (1ULL << (FaParser::ReverseOp - 10))
                    | (1ULL << (FaParser::AddAddOp - 10))
                    | (1ULL << (FaParser::SubSubOp - 10))
                    | (1ULL << (FaParser::AddOp - 10))
                    | (1ULL << (FaParser::SubOp - 10))
                    | (1ULL << (FaParser::ColonColon - 10))
                    | (1ULL << (FaParser::QuotYuanL - 10))
                    | (1ULL << (FaParser::BoolLiteral - 10))
                    | (1ULL << (FaParser::IntLiteral - 10))
                    | (1ULL << (FaParser::FloatLiteral - 10))
                    | (1ULL << (FaParser::String1Literal - 10)))) != 0)) {
                    setState(274);
                    expr();
                    setState(279);
                    _errHandler->sync(this);
                    _la = _input->LA(1);
                    while (_la == FaParser::Comma) {
                      setState(275);
                      match(FaParser::Comma);
                      setState(276);
                      expr();
                      setState(281);
                      _errHandler->sync(this);
                      _la = _input->LA(1);
                    }
                  }
                  setState(284);
                  match(FaParser::QuotYuanR);
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(287); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
        break;
      }

      case FaParser::QuotFangL: {
        enterOuterAlt(_localctx, 3);
        setState(293); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(289);
                  match(FaParser::QuotFangL);
                  setState(290);
                  expr();
                  setState(291);
                  match(FaParser::QuotFangL);
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(295); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
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
        setState(303); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(299);
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
                      setState(297);
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
                      setState(298);
                      allOp();
                      break;
                    }

                  default:
                    throw NoViableAltException(this);
                  }
                  setState(301);
                  expr();
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(305); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
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
  enterRule(_localctx, 48, FaParser::RuleNormalExpr);
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
    setState(323);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FaParser::QuotYuanL: {
        enterOuterAlt(_localctx, 1);
        setState(309);
        quotExpr();
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
      case FaParser::FloatLiteral:
      case FaParser::String1Literal: {
        enterOuterAlt(_localctx, 2);
        setState(313);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << FaParser::ReverseOp)
          | (1ULL << FaParser::AddAddOp)
          | (1ULL << FaParser::SubSubOp)
          | (1ULL << FaParser::AddOp)
          | (1ULL << FaParser::SubOp))) != 0)) {
          setState(310);
          exprPrefix();
          setState(315);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(316);
        exprBody();
        setState(320);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(317);
            exprSuffix(); 
          }
          setState(322);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
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
  enterRule(_localctx, 50, FaParser::RuleExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(327);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
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
      case FaParser::FloatLiteral:
      case FaParser::String1Literal: {
        enterOuterAlt(_localctx, 1);
        setState(325);
        normalExpr();
        break;
      }

      case FaParser::If: {
        enterOuterAlt(_localctx, 2);
        setState(326);
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
  enterRule(_localctx, 52, FaParser::RuleUseStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(329);
    match(FaParser::Use);
    setState(330);
    ids();
    setState(331);
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

FaParser::ExprContext* FaParser::NormalStmtContext::expr() {
  return getRuleContext<FaParser::ExprContext>(0);
}

tree::TerminalNode* FaParser::NormalStmtContext::Semi() {
  return getToken(FaParser::Semi, 0);
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
  enterRule(_localctx, 54, FaParser::RuleNormalStmt);

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
    expr();
    setState(334);
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

tree::TerminalNode* FaParser::StmtContext::Return() {
  return getToken(FaParser::Return, 0);
}

FaParser::IfStmtContext* FaParser::StmtContext::ifStmt() {
  return getRuleContext<FaParser::IfStmtContext>(0);
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
  enterRule(_localctx, 56, FaParser::RuleStmt);
  size_t _la = 0;

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
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(337);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == FaParser::Return) {
        setState(336);
        match(FaParser::Return);
      }
      setState(339);
      normalStmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(340);
      ifStmt();
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
  enterRule(_localctx, 58, FaParser::RulePublicLevel);
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
  enterRule(_localctx, 60, FaParser::RuleClassParent);
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
    setState(345);
    match(FaParser::Colon);
    setState(346);
    ids();
    setState(351);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Comma) {
      setState(347);
      match(FaParser::Comma);
      setState(348);
      ids();
      setState(353);
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
  enterRule(_localctx, 62, FaParser::RuleClassItemPart);
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
    setState(355);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(354);
      publicLevel();
    }
    setState(358);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Static) {
      setState(357);
      match(FaParser::Static);
    }
    setState(360);
    match(FaParser::Id);
    setState(361);
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
  enterRule(_localctx, 64, FaParser::RuleClassItemFieldBlock);

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
    classItemPart();
    setState(364);
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
  enterRule(_localctx, 66, FaParser::RuleClassItemFuncBlock);
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
    setState(366);
    classItemPart();
    setState(367);
    match(FaParser::QuotYuanL);
    setState(368);
    typeVarList();
    setState(369);
    match(FaParser::QuotYuanR);
    setState(370);
    match(FaParser::QuotHuaL);
    setState(374);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 10) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 10)) & ((1ULL << (FaParser::If - 10))
      | (1ULL << (FaParser::Return - 10))
      | (1ULL << (FaParser::Id - 10))
      | (1ULL << (FaParser::ReverseOp - 10))
      | (1ULL << (FaParser::AddAddOp - 10))
      | (1ULL << (FaParser::SubSubOp - 10))
      | (1ULL << (FaParser::AddOp - 10))
      | (1ULL << (FaParser::SubOp - 10))
      | (1ULL << (FaParser::ColonColon - 10))
      | (1ULL << (FaParser::QuotYuanL - 10))
      | (1ULL << (FaParser::BoolLiteral - 10))
      | (1ULL << (FaParser::IntLiteral - 10))
      | (1ULL << (FaParser::FloatLiteral - 10))
      | (1ULL << (FaParser::String1Literal - 10)))) != 0)) {
      setState(371);
      stmt();
      setState(376);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(377);
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
  enterRule(_localctx, 68, FaParser::RuleClassBlock);
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
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(379);
      publicLevel();
    }
    setState(382);
    match(FaParser::Class);
    setState(383);
    match(FaParser::Id);
    setState(385);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Colon) {
      setState(384);
      classParent();
    }
    setState(387);
    match(FaParser::QuotHuaL);
    setState(392);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private)
      | (1ULL << FaParser::Static)
      | (1ULL << FaParser::Id))) != 0)) {
      setState(390);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
      case 1: {
        setState(388);
        classItemFieldBlock();
        break;
      }

      case 2: {
        setState(389);
        classItemFuncBlock();
        break;
      }

      default:
        break;
      }
      setState(394);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(395);
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
  enterRule(_localctx, 70, FaParser::RuleCallConvention);
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
    setState(397);
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
  enterRule(_localctx, 72, FaParser::RuleImportStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(399);
    match(FaParser::AImport);
    setState(400);
    eType();
    setState(401);
    callConvention();
    setState(402);
    match(FaParser::Id);
    setState(403);
    match(FaParser::QuotYuanL);
    setState(404);
    eTypeVarList();
    setState(405);
    match(FaParser::QuotYuanR);
    setState(406);
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
  enterRule(_localctx, 74, FaParser::RuleLibStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(408);
    match(FaParser::ALib);
    setState(409);
    match(FaParser::String1Literal);
    setState(410);
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
  enterRule(_localctx, 76, FaParser::RuleImportBlock);
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
    setState(414); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(414);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case FaParser::AImport: {
          setState(412);
          importStmt();
          break;
        }

        case FaParser::ALib: {
          setState(413);
          libStmt();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(416); 
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
  enterRule(_localctx, 78, FaParser::RuleFaEntryMainFuncBlock);
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
    setState(418);
    match(FaParser::Static);
    setState(419);
    type();
    setState(420);
    match(FaParser::FaEntryMain);
    setState(421);
    match(FaParser::QuotYuanL);
    setState(422);
    match(FaParser::QuotYuanR);
    setState(423);
    match(FaParser::QuotHuaL);
    setState(427);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 10) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 10)) & ((1ULL << (FaParser::If - 10))
      | (1ULL << (FaParser::Return - 10))
      | (1ULL << (FaParser::Id - 10))
      | (1ULL << (FaParser::ReverseOp - 10))
      | (1ULL << (FaParser::AddAddOp - 10))
      | (1ULL << (FaParser::SubSubOp - 10))
      | (1ULL << (FaParser::AddOp - 10))
      | (1ULL << (FaParser::SubOp - 10))
      | (1ULL << (FaParser::ColonColon - 10))
      | (1ULL << (FaParser::QuotYuanL - 10))
      | (1ULL << (FaParser::BoolLiteral - 10))
      | (1ULL << (FaParser::IntLiteral - 10))
      | (1ULL << (FaParser::FloatLiteral - 10))
      | (1ULL << (FaParser::String1Literal - 10)))) != 0)) {
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
  enterRule(_localctx, 80, FaParser::RuleProgram);
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
    setState(435);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::Use) {
      setState(432);
      useStmt();
      setState(437);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(439);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::AImport

    || _la == FaParser::ALib) {
      setState(438);
      importBlock();
    }
    setState(444);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FaParser::Class)
      | (1ULL << FaParser::Internal)
      | (1ULL << FaParser::Public)
      | (1ULL << FaParser::Protected)
      | (1ULL << FaParser::Private))) != 0)) {
      setState(441);
      classBlock();
      setState(446);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(448);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FaParser::Static) {
      setState(447);
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
  "ids", "shiftLOp", "shiftROp", "literal", "typeAfter", "type", "eTypeAfter", 
  "eSign", "eType", "typeVar", "typeVarList", "eTypeVar", "eTypeVarList", 
  "ifPart", "quotStmtPart", "quotStmtExpr", "ifStmt", "ifExpr", "allAssign", 
  "allOp", "quotExpr", "exprPrefix", "exprBody", "exprSuffix", "normalExpr", 
  "expr", "useStmt", "normalStmt", "stmt", "publicLevel", "classParent", 
  "classItemPart", "classItemFieldBlock", "classItemFuncBlock", "classBlock", 
  "callConvention", "importStmt", "libStmt", "importBlock", "faEntryMainFuncBlock", 
  "program"
};

std::vector<std::string> FaParser::_literalNames = {
  "", "'@import'", "'@lib'", "'__cdecl'", "'__fastcall'", "'__stdcall'", 
  "'class'", "'const'", "'else'", "'FaEntryMain'", "'if'", "'internal'", 
  "'public'", "'protected'", "'private'", "'return'", "'signed'", "'static'", 
  "'unsigned'", "'use'", "", "'='", "'\u003F\u003F='", "'+='", "'-='", "'*='", 
  "'**='", "'/='", "'%='", "'&='", "'|='", "'^='", "'&&='", "'||='", "'<<='", 
  "'>>='", "'~'", "'++'", "'--'", "'.'", "'\u003F\u003F'", "'+'", "'-'", 
  "'*'", "'/'", "'**'", "'%'", "'&'", "'|'", "'^'", "'&&'", "'||'", "'\u003F'", 
  "','", "'::'", "':'", "';'", "'['", "']'", "'<'", "'>'", "'{'", "'}'", 
  "'('", "')'"
};

std::vector<std::string> FaParser::_symbolicNames = {
  "", "AImport", "ALib", "CC__Cdecl", "CC__FastCall", "CC__StdCall", "Class", 
  "Const", "Else", "FaEntryMain", "If", "Internal", "Public", "Protected", 
  "Private", "Return", "Signed", "Static", "Unsigned", "Use", "Id", "Assign", 
  "QusQusAssign", "AddAssign", "SubAssign", "StarAssign", "StarStarAssign", 
  "DivAssign", "ModAssign", "AndAssign", "OrAssign", "XorAssign", "AndAndAssign", 
  "OrOrAssign", "ShiftLAssign", "ShiftRAssign", "ReverseOp", "AddAddOp", 
  "SubSubOp", "PointOp", "QusQusOp", "AddOp", "SubOp", "StarOp", "DivOp", 
  "StarStarOp", "ModOp", "AndOp", "OrOp", "XorOp", "AndAndOp", "OrOrOp", 
  "Qus", "Comma", "ColonColon", "Colon", "Semi", "QuotFangL", "QuotFangR", 
  "QuotJianL", "QuotJianR", "QuotHuaL", "QuotHuaR", "QuotYuanL", "QuotYuanR", 
  "BoolLiteral", "IntLiteral", "FloatLiteral", "String1Literal", "Comment1", 
  "Comment2", "WS"
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
       0x3, 0x49, 0x1c5, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
       0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 
       0x2, 0x58, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x5b, 0xb, 0x2, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 
       0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x69, 0xa, 
       0x6, 0x3, 0x7, 0x5, 0x7, 0x6c, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
       0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x74, 0xa, 0x7, 0xc, 
       0x7, 0xe, 0x7, 0x77, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
       0x7, 0x3, 0x7, 0x3, 0x7, 0x6, 0x7, 0x7f, 0xa, 0x7, 0xd, 0x7, 0xe, 
       0x7, 0x80, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x85, 0xa, 0x7, 0x3, 0x7, 
       0x7, 0x7, 0x88, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x8b, 0xb, 0x7, 0x3, 
       0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x91, 0xa, 0x8, 0x3, 
       0x9, 0x3, 0x9, 0x3, 0xa, 0x5, 0xa, 0x96, 0xa, 0xa, 0x3, 0xa, 0x5, 
       0xa, 0x99, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x9d, 0xa, 0xa, 
       0xc, 0xa, 0xe, 0xa, 0xa0, 0xb, 0xa, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 
       0xa4, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0xa9, 0xa, 
       0xc, 0xc, 0xc, 0xe, 0xc, 0xac, 0xb, 0xc, 0x3, 0xd, 0x3, 0xd, 0x5, 
       0xd, 0xb0, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0xb5, 
       0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0xb8, 0xb, 0xe, 0x3, 0xf, 0x3, 0xf, 
       0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0xc1, 
       0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0xc4, 0xb, 0x10, 0x3, 0x10, 0x3, 
       0x10, 0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 0xca, 0xa, 0x11, 0xc, 0x11, 
       0xe, 0x11, 0xcd, 0xb, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
       0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 
       0x12, 0xd8, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0xdb, 0xb, 0x12, 0x3, 
       0x12, 0x3, 0x12, 0x5, 0x12, 0xdf, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 
       0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0xe7, 0xa, 
       0x13, 0xc, 0x13, 0xe, 0x13, 0xea, 0xb, 0x13, 0x3, 0x13, 0x3, 0x13, 
       0x5, 0x13, 0xee, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 
       0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
       0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
       0x15, 0x3, 0x15, 0x5, 0x15, 0x101, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 
       0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 
       0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x10d, 0xa, 0x18, 0x3, 0x19, 0x6, 
       0x19, 0x110, 0xa, 0x19, 0xd, 0x19, 0xe, 0x19, 0x111, 0x3, 0x19, 0x3, 
       0x19, 0x3, 0x19, 0x3, 0x19, 0x7, 0x19, 0x118, 0xa, 0x19, 0xc, 0x19, 
       0xe, 0x19, 0x11b, 0xb, 0x19, 0x5, 0x19, 0x11d, 0xa, 0x19, 0x3, 0x19, 
       0x6, 0x19, 0x120, 0xa, 0x19, 0xd, 0x19, 0xe, 0x19, 0x121, 0x3, 0x19, 
       0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x6, 0x19, 0x128, 0xa, 0x19, 0xd, 
       0x19, 0xe, 0x19, 0x129, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x12e, 0xa, 
       0x19, 0x3, 0x19, 0x3, 0x19, 0x6, 0x19, 0x132, 0xa, 0x19, 0xd, 0x19, 
       0xe, 0x19, 0x133, 0x5, 0x19, 0x136, 0xa, 0x19, 0x3, 0x1a, 0x3, 0x1a, 
       0x7, 0x1a, 0x13a, 0xa, 0x1a, 0xc, 0x1a, 0xe, 0x1a, 0x13d, 0xb, 0x1a, 
       0x3, 0x1a, 0x3, 0x1a, 0x7, 0x1a, 0x141, 0xa, 0x1a, 0xc, 0x1a, 0xe, 
       0x1a, 0x144, 0xb, 0x1a, 0x5, 0x1a, 0x146, 0xa, 0x1a, 0x3, 0x1b, 0x3, 
       0x1b, 0x5, 0x1b, 0x14a, 0xa, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
       0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x5, 0x1e, 
       0x154, 0xa, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x158, 0xa, 0x1e, 
       0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
       0x7, 0x20, 0x160, 0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 0x163, 0xb, 0x20, 
       0x3, 0x21, 0x5, 0x21, 0x166, 0xa, 0x21, 0x3, 0x21, 0x5, 0x21, 0x169, 
       0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 
       0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
       0x3, 0x23, 0x7, 0x23, 0x177, 0xa, 0x23, 0xc, 0x23, 0xe, 0x23, 0x17a, 
       0xb, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x5, 0x24, 0x17f, 0xa, 
       0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x184, 0xa, 0x24, 
       0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x7, 0x24, 0x189, 0xa, 0x24, 0xc, 
       0x24, 0xe, 0x24, 0x18c, 0xb, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 
       0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 
       0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 0x3, 0x27, 
       0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x6, 0x28, 0x1a1, 0xa, 
       0x28, 0xd, 0x28, 0xe, 0x28, 0x1a2, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 
       0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x7, 0x29, 0x1ac, 0xa, 
       0x29, 0xc, 0x29, 0xe, 0x29, 0x1af, 0xb, 0x29, 0x3, 0x29, 0x3, 0x29, 
       0x3, 0x2a, 0x7, 0x2a, 0x1b4, 0xa, 0x2a, 0xc, 0x2a, 0xe, 0x2a, 0x1b7, 
       0xb, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x1ba, 0xa, 0x2a, 0x3, 0x2a, 0x7, 
       0x2a, 0x1bd, 0xa, 0x2a, 0xc, 0x2a, 0xe, 0x2a, 0x1c0, 0xb, 0x2a, 0x3, 
       0x2a, 0x5, 0x2a, 0x1c3, 0xa, 0x2a, 0x3, 0x2a, 0x2, 0x2, 0x2b, 0x2, 
       0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
       0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 
       0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 
       0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x2, 0x9, 0x3, 0x2, 0x43, 0x46, 
       0x4, 0x2, 0x12, 0x12, 0x14, 0x14, 0x3, 0x2, 0x17, 0x25, 0x4, 0x2, 
       0x26, 0x28, 0x2b, 0x2c, 0x3, 0x2, 0x27, 0x28, 0x3, 0x2, 0xd, 0x10, 
       0x3, 0x2, 0x5, 0x7, 0x2, 0x1e2, 0x2, 0x54, 0x3, 0x2, 0x2, 0x2, 0x4, 
       0x5c, 0x3, 0x2, 0x2, 0x2, 0x6, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x8, 0x62, 
       0x3, 0x2, 0x2, 0x2, 0xa, 0x68, 0x3, 0x2, 0x2, 0x2, 0xc, 0x6b, 0x3, 
       0x2, 0x2, 0x2, 0xe, 0x90, 0x3, 0x2, 0x2, 0x2, 0x10, 0x92, 0x3, 0x2, 
       0x2, 0x2, 0x12, 0x95, 0x3, 0x2, 0x2, 0x2, 0x14, 0xa1, 0x3, 0x2, 0x2, 
       0x2, 0x16, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x18, 0xad, 0x3, 0x2, 0x2, 0x2, 
       0x1a, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x1e, 
       0xbe, 0x3, 0x2, 0x2, 0x2, 0x20, 0xc7, 0x3, 0x2, 0x2, 0x2, 0x22, 0xd1, 
       0x3, 0x2, 0x2, 0x2, 0x24, 0xe0, 0x3, 0x2, 0x2, 0x2, 0x26, 0xef, 0x3, 
       0x2, 0x2, 0x2, 0x28, 0x100, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x102, 0x3, 
       0x2, 0x2, 0x2, 0x2c, 0x106, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x10c, 0x3, 
       0x2, 0x2, 0x2, 0x30, 0x135, 0x3, 0x2, 0x2, 0x2, 0x32, 0x145, 0x3, 
       0x2, 0x2, 0x2, 0x34, 0x149, 0x3, 0x2, 0x2, 0x2, 0x36, 0x14b, 0x3, 
       0x2, 0x2, 0x2, 0x38, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x157, 0x3, 
       0x2, 0x2, 0x2, 0x3c, 0x159, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x15b, 0x3, 
       0x2, 0x2, 0x2, 0x40, 0x165, 0x3, 0x2, 0x2, 0x2, 0x42, 0x16d, 0x3, 
       0x2, 0x2, 0x2, 0x44, 0x170, 0x3, 0x2, 0x2, 0x2, 0x46, 0x17e, 0x3, 
       0x2, 0x2, 0x2, 0x48, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x191, 0x3, 
       0x2, 0x2, 0x2, 0x4c, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x1a0, 0x3, 
       0x2, 0x2, 0x2, 0x50, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x52, 0x1b5, 0x3, 
       0x2, 0x2, 0x2, 0x54, 0x59, 0x7, 0x16, 0x2, 0x2, 0x55, 0x56, 0x7, 
       0x29, 0x2, 0x2, 0x56, 0x58, 0x7, 0x16, 0x2, 0x2, 0x57, 0x55, 0x3, 
       0x2, 0x2, 0x2, 0x58, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x59, 0x57, 0x3, 0x2, 
       0x2, 0x2, 0x59, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x3, 0x3, 0x2, 0x2, 
       0x2, 0x5b, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0x3d, 0x2, 
       0x2, 0x5d, 0x5e, 0x7, 0x3d, 0x2, 0x2, 0x5e, 0x5, 0x3, 0x2, 0x2, 0x2, 
       0x5f, 0x60, 0x7, 0x3e, 0x2, 0x2, 0x60, 0x61, 0x7, 0x3e, 0x2, 0x2, 
       0x61, 0x7, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x9, 0x2, 0x2, 0x2, 0x63, 
       0x9, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 0x7, 0x3b, 0x2, 0x2, 0x65, 0x69, 
       0x7, 0x3c, 0x2, 0x2, 0x66, 0x69, 0x7, 0x31, 0x2, 0x2, 0x67, 0x69, 
       0x7, 0x36, 0x2, 0x2, 0x68, 0x64, 0x3, 0x2, 0x2, 0x2, 0x68, 0x66, 
       0x3, 0x2, 0x2, 0x2, 0x68, 0x67, 0x3, 0x2, 0x2, 0x2, 0x69, 0xb, 0x3, 
       0x2, 0x2, 0x2, 0x6a, 0x6c, 0x7, 0x9, 0x2, 0x2, 0x6b, 0x6a, 0x3, 0x2, 
       0x2, 0x2, 0x6b, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x84, 0x3, 0x2, 0x2, 
       0x2, 0x6d, 0x85, 0x7, 0x16, 0x2, 0x2, 0x6e, 0x6f, 0x7, 0x16, 0x2, 
       0x2, 0x6f, 0x70, 0x7, 0x3d, 0x2, 0x2, 0x70, 0x75, 0x5, 0xc, 0x7, 
       0x2, 0x71, 0x72, 0x7, 0x37, 0x2, 0x2, 0x72, 0x74, 0x5, 0xc, 0x7, 
       0x2, 0x73, 0x71, 0x3, 0x2, 0x2, 0x2, 0x74, 0x77, 0x3, 0x2, 0x2, 0x2, 
       0x75, 0x73, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x3, 0x2, 0x2, 0x2, 0x76, 
       0x78, 0x3, 0x2, 0x2, 0x2, 0x77, 0x75, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 
       0x7, 0x3e, 0x2, 0x2, 0x79, 0x85, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 
       0x7, 0x41, 0x2, 0x2, 0x7b, 0x7e, 0x5, 0xc, 0x7, 0x2, 0x7c, 0x7d, 
       0x7, 0x37, 0x2, 0x2, 0x7d, 0x7f, 0x5, 0xc, 0x7, 0x2, 0x7e, 0x7c, 
       0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 0x3, 0x2, 0x2, 0x2, 0x80, 0x7e, 0x3, 
       0x2, 0x2, 0x2, 0x80, 0x81, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x3, 0x2, 
       0x2, 0x2, 0x82, 0x83, 0x7, 0x42, 0x2, 0x2, 0x83, 0x85, 0x3, 0x2, 
       0x2, 0x2, 0x84, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x84, 0x6e, 0x3, 0x2, 0x2, 
       0x2, 0x84, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x85, 0x89, 0x3, 0x2, 0x2, 0x2, 
       0x86, 0x88, 0x5, 0xa, 0x6, 0x2, 0x87, 0x86, 0x3, 0x2, 0x2, 0x2, 0x88, 
       0x8b, 0x3, 0x2, 0x2, 0x2, 0x89, 0x87, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 
       0x3, 0x2, 0x2, 0x2, 0x8a, 0xd, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x89, 0x3, 
       0x2, 0x2, 0x2, 0x8c, 0x8d, 0x7, 0x3b, 0x2, 0x2, 0x8d, 0x91, 0x7, 
       0x3c, 0x2, 0x2, 0x8e, 0x91, 0x7, 0x31, 0x2, 0x2, 0x8f, 0x91, 0x7, 
       0x2d, 0x2, 0x2, 0x90, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x90, 0x8e, 0x3, 
       0x2, 0x2, 0x2, 0x90, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x91, 0xf, 0x3, 0x2, 
       0x2, 0x2, 0x92, 0x93, 0x9, 0x3, 0x2, 0x2, 0x93, 0x11, 0x3, 0x2, 0x2, 
       0x2, 0x94, 0x96, 0x7, 0x9, 0x2, 0x2, 0x95, 0x94, 0x3, 0x2, 0x2, 0x2, 
       0x95, 0x96, 0x3, 0x2, 0x2, 0x2, 0x96, 0x98, 0x3, 0x2, 0x2, 0x2, 0x97, 
       0x99, 0x5, 0x10, 0x9, 0x2, 0x98, 0x97, 0x3, 0x2, 0x2, 0x2, 0x98, 
       0x99, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9e, 
       0x7, 0x16, 0x2, 0x2, 0x9b, 0x9d, 0x5, 0xe, 0x8, 0x2, 0x9c, 0x9b, 
       0x3, 0x2, 0x2, 0x2, 0x9d, 0xa0, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9c, 0x3, 
       0x2, 0x2, 0x2, 0x9e, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x13, 0x3, 0x2, 
       0x2, 0x2, 0xa0, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa3, 0x5, 0xc, 0x7, 
       0x2, 0xa2, 0xa4, 0x7, 0x16, 0x2, 0x2, 0xa3, 0xa2, 0x3, 0x2, 0x2, 
       0x2, 0xa3, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x15, 0x3, 0x2, 0x2, 0x2, 
       0xa5, 0xaa, 0x5, 0x14, 0xb, 0x2, 0xa6, 0xa7, 0x7, 0x37, 0x2, 0x2, 
       0xa7, 0xa9, 0x5, 0x14, 0xb, 0x2, 0xa8, 0xa6, 0x3, 0x2, 0x2, 0x2, 
       0xa9, 0xac, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xaa, 
       0xab, 0x3, 0x2, 0x2, 0x2, 0xab, 0x17, 0x3, 0x2, 0x2, 0x2, 0xac, 0xaa, 
       0x3, 0x2, 0x2, 0x2, 0xad, 0xaf, 0x5, 0x12, 0xa, 0x2, 0xae, 0xb0, 
       0x7, 0x16, 0x2, 0x2, 0xaf, 0xae, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 
       0x3, 0x2, 0x2, 0x2, 0xb0, 0x19, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb6, 0x5, 
       0x18, 0xd, 0x2, 0xb2, 0xb3, 0x7, 0x37, 0x2, 0x2, 0xb3, 0xb5, 0x5, 
       0x18, 0xd, 0x2, 0xb4, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb8, 0x3, 
       0x2, 0x2, 0x2, 0xb6, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0x3, 0x2, 
       0x2, 0x2, 0xb7, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb6, 0x3, 0x2, 0x2, 
       0x2, 0xb9, 0xba, 0x7, 0xc, 0x2, 0x2, 0xba, 0xbb, 0x7, 0x41, 0x2, 
       0x2, 0xbb, 0xbc, 0x5, 0x34, 0x1b, 0x2, 0xbc, 0xbd, 0x7, 0x42, 0x2, 
       0x2, 0xbd, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xc2, 0x7, 0x3f, 0x2, 
       0x2, 0xbf, 0xc1, 0x5, 0x3a, 0x1e, 0x2, 0xc0, 0xbf, 0x3, 0x2, 0x2, 
       0x2, 0xc1, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc0, 0x3, 0x2, 0x2, 0x2, 
       0xc2, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc4, 
       0xc2, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc6, 0x7, 0x40, 0x2, 0x2, 0xc6, 
       0x1f, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xcb, 0x7, 0x3f, 0x2, 0x2, 0xc8, 
       0xca, 0x5, 0x3a, 0x1e, 0x2, 0xc9, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xca, 
       0xcd, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 
       0x3, 0x2, 0x2, 0x2, 0xcc, 0xce, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xcb, 0x3, 
       0x2, 0x2, 0x2, 0xce, 0xcf, 0x5, 0x34, 0x1b, 0x2, 0xcf, 0xd0, 0x7, 
       0x40, 0x2, 0x2, 0xd0, 0x21, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x5, 
       0x1c, 0xf, 0x2, 0xd2, 0xd9, 0x5, 0x1e, 0x10, 0x2, 0xd3, 0xd4, 0x7, 
       0xa, 0x2, 0x2, 0xd4, 0xd5, 0x5, 0x1c, 0xf, 0x2, 0xd5, 0xd6, 0x5, 
       0x1e, 0x10, 0x2, 0xd6, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd3, 0x3, 
       0x2, 0x2, 0x2, 0xd8, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xd7, 0x3, 0x2, 
       0x2, 0x2, 0xd9, 0xda, 0x3, 0x2, 0x2, 0x2, 0xda, 0xde, 0x3, 0x2, 0x2, 
       0x2, 0xdb, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x7, 0xa, 0x2, 0x2, 
       0xdd, 0xdf, 0x5, 0x1e, 0x10, 0x2, 0xde, 0xdc, 0x3, 0x2, 0x2, 0x2, 
       0xde, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xdf, 0x23, 0x3, 0x2, 0x2, 0x2, 0xe0, 
       0xe1, 0x5, 0x1c, 0xf, 0x2, 0xe1, 0xe8, 0x5, 0x20, 0x11, 0x2, 0xe2, 
       0xe3, 0x7, 0xa, 0x2, 0x2, 0xe3, 0xe4, 0x5, 0x1c, 0xf, 0x2, 0xe4, 
       0xe5, 0x5, 0x20, 0x11, 0x2, 0xe5, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe6, 
       0xe2, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xea, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe6, 
       0x3, 0x2, 0x2, 0x2, 0xe8, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xed, 0x3, 
       0x2, 0x2, 0x2, 0xea, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xec, 0x7, 0xa, 
       0x2, 0x2, 0xec, 0xee, 0x5, 0x20, 0x11, 0x2, 0xed, 0xeb, 0x3, 0x2, 
       0x2, 0x2, 0xed, 0xee, 0x3, 0x2, 0x2, 0x2, 0xee, 0x25, 0x3, 0x2, 0x2, 
       0x2, 0xef, 0xf0, 0x9, 0x4, 0x2, 0x2, 0xf0, 0x27, 0x3, 0x2, 0x2, 0x2, 
       0xf1, 0x101, 0x7, 0x2a, 0x2, 0x2, 0xf2, 0x101, 0x7, 0x29, 0x2, 0x2, 
       0xf3, 0x101, 0x7, 0x2b, 0x2, 0x2, 0xf4, 0x101, 0x7, 0x2c, 0x2, 0x2, 
       0xf5, 0x101, 0x7, 0x2d, 0x2, 0x2, 0xf6, 0x101, 0x7, 0x2e, 0x2, 0x2, 
       0xf7, 0x101, 0x7, 0x2f, 0x2, 0x2, 0xf8, 0x101, 0x7, 0x30, 0x2, 0x2, 
       0xf9, 0x101, 0x7, 0x31, 0x2, 0x2, 0xfa, 0x101, 0x7, 0x32, 0x2, 0x2, 
       0xfb, 0x101, 0x7, 0x33, 0x2, 0x2, 0xfc, 0x101, 0x7, 0x34, 0x2, 0x2, 
       0xfd, 0x101, 0x7, 0x35, 0x2, 0x2, 0xfe, 0x101, 0x5, 0x4, 0x3, 0x2, 
       0xff, 0x101, 0x5, 0x6, 0x4, 0x2, 0x100, 0xf1, 0x3, 0x2, 0x2, 0x2, 
       0x100, 0xf2, 0x3, 0x2, 0x2, 0x2, 0x100, 0xf3, 0x3, 0x2, 0x2, 0x2, 
       0x100, 0xf4, 0x3, 0x2, 0x2, 0x2, 0x100, 0xf5, 0x3, 0x2, 0x2, 0x2, 
       0x100, 0xf6, 0x3, 0x2, 0x2, 0x2, 0x100, 0xf7, 0x3, 0x2, 0x2, 0x2, 
       0x100, 0xf8, 0x3, 0x2, 0x2, 0x2, 0x100, 0xf9, 0x3, 0x2, 0x2, 0x2, 
       0x100, 0xfa, 0x3, 0x2, 0x2, 0x2, 0x100, 0xfb, 0x3, 0x2, 0x2, 0x2, 
       0x100, 0xfc, 0x3, 0x2, 0x2, 0x2, 0x100, 0xfd, 0x3, 0x2, 0x2, 0x2, 
       0x100, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x100, 0xff, 0x3, 0x2, 0x2, 0x2, 
       0x101, 0x29, 0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 0x7, 0x41, 0x2, 0x2, 
       0x103, 0x104, 0x5, 0x34, 0x1b, 0x2, 0x104, 0x105, 0x7, 0x42, 0x2, 
       0x2, 0x105, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x106, 0x107, 0x9, 0x5, 0x2, 
       0x2, 0x107, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x108, 0x10d, 0x5, 0x2, 0x2, 
       0x2, 0x109, 0x10a, 0x7, 0x38, 0x2, 0x2, 0x10a, 0x10d, 0x7, 0x16, 
       0x2, 0x2, 0x10b, 0x10d, 0x5, 0x8, 0x5, 0x2, 0x10c, 0x108, 0x3, 0x2, 
       0x2, 0x2, 0x10c, 0x109, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10b, 0x3, 0x2, 
       0x2, 0x2, 0x10d, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x110, 0x9, 0x6, 
       0x2, 0x2, 0x10f, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 0x3, 0x2, 
       0x2, 0x2, 0x111, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x111, 0x112, 0x3, 0x2, 
       0x2, 0x2, 0x112, 0x136, 0x3, 0x2, 0x2, 0x2, 0x113, 0x11c, 0x7, 0x41, 
       0x2, 0x2, 0x114, 0x119, 0x5, 0x34, 0x1b, 0x2, 0x115, 0x116, 0x7, 
       0x37, 0x2, 0x2, 0x116, 0x118, 0x5, 0x34, 0x1b, 0x2, 0x117, 0x115, 
       0x3, 0x2, 0x2, 0x2, 0x118, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x119, 0x117, 
       0x3, 0x2, 0x2, 0x2, 0x119, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11d, 
       0x3, 0x2, 0x2, 0x2, 0x11b, 0x119, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x114, 
       0x3, 0x2, 0x2, 0x2, 0x11c, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11e, 
       0x3, 0x2, 0x2, 0x2, 0x11e, 0x120, 0x7, 0x42, 0x2, 0x2, 0x11f, 0x113, 
       0x3, 0x2, 0x2, 0x2, 0x120, 0x121, 0x3, 0x2, 0x2, 0x2, 0x121, 0x11f, 
       0x3, 0x2, 0x2, 0x2, 0x121, 0x122, 0x3, 0x2, 0x2, 0x2, 0x122, 0x136, 
       0x3, 0x2, 0x2, 0x2, 0x123, 0x124, 0x7, 0x3b, 0x2, 0x2, 0x124, 0x125, 
       0x5, 0x34, 0x1b, 0x2, 0x125, 0x126, 0x7, 0x3b, 0x2, 0x2, 0x126, 0x128, 
       0x3, 0x2, 0x2, 0x2, 0x127, 0x123, 0x3, 0x2, 0x2, 0x2, 0x128, 0x129, 
       0x3, 0x2, 0x2, 0x2, 0x129, 0x127, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12a, 
       0x3, 0x2, 0x2, 0x2, 0x12a, 0x136, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12e, 
       0x5, 0x26, 0x14, 0x2, 0x12c, 0x12e, 0x5, 0x28, 0x15, 0x2, 0x12d, 
       0x12b, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12e, 
       0x12f, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x130, 0x5, 0x34, 0x1b, 0x2, 0x130, 
       0x132, 0x3, 0x2, 0x2, 0x2, 0x131, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x132, 
       0x133, 0x3, 0x2, 0x2, 0x2, 0x133, 0x131, 0x3, 0x2, 0x2, 0x2, 0x133, 
       0x134, 0x3, 0x2, 0x2, 0x2, 0x134, 0x136, 0x3, 0x2, 0x2, 0x2, 0x135, 
       0x10f, 0x3, 0x2, 0x2, 0x2, 0x135, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x135, 
       0x127, 0x3, 0x2, 0x2, 0x2, 0x135, 0x131, 0x3, 0x2, 0x2, 0x2, 0x136, 
       0x31, 0x3, 0x2, 0x2, 0x2, 0x137, 0x146, 0x5, 0x2a, 0x16, 0x2, 0x138, 
       0x13a, 0x5, 0x2c, 0x17, 0x2, 0x139, 0x138, 0x3, 0x2, 0x2, 0x2, 0x13a, 
       0x13d, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x139, 0x3, 0x2, 0x2, 0x2, 0x13b, 
       0x13c, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x13d, 
       0x13b, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x142, 0x5, 0x2e, 0x18, 0x2, 0x13f, 
       0x141, 0x5, 0x30, 0x19, 0x2, 0x140, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x141, 
       0x144, 0x3, 0x2, 0x2, 0x2, 0x142, 0x140, 0x3, 0x2, 0x2, 0x2, 0x142, 
       0x143, 0x3, 0x2, 0x2, 0x2, 0x143, 0x146, 0x3, 0x2, 0x2, 0x2, 0x144, 
       0x142, 0x3, 0x2, 0x2, 0x2, 0x145, 0x137, 0x3, 0x2, 0x2, 0x2, 0x145, 
       0x13b, 0x3, 0x2, 0x2, 0x2, 0x146, 0x33, 0x3, 0x2, 0x2, 0x2, 0x147, 
       0x14a, 0x5, 0x32, 0x1a, 0x2, 0x148, 0x14a, 0x5, 0x24, 0x13, 0x2, 
       0x149, 0x147, 0x3, 0x2, 0x2, 0x2, 0x149, 0x148, 0x3, 0x2, 0x2, 0x2, 
       0x14a, 0x35, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x14c, 0x7, 0x15, 0x2, 0x2, 
       0x14c, 0x14d, 0x5, 0x2, 0x2, 0x2, 0x14d, 0x14e, 0x7, 0x3a, 0x2, 0x2, 
       0x14e, 0x37, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x150, 0x5, 0x34, 0x1b, 0x2, 
       0x150, 0x151, 0x7, 0x3a, 0x2, 0x2, 0x151, 0x39, 0x3, 0x2, 0x2, 0x2, 
       0x152, 0x154, 0x7, 0x11, 0x2, 0x2, 0x153, 0x152, 0x3, 0x2, 0x2, 0x2, 
       0x153, 0x154, 0x3, 0x2, 0x2, 0x2, 0x154, 0x155, 0x3, 0x2, 0x2, 0x2, 
       0x155, 0x158, 0x5, 0x38, 0x1d, 0x2, 0x156, 0x158, 0x5, 0x22, 0x12, 
       0x2, 0x157, 0x153, 0x3, 0x2, 0x2, 0x2, 0x157, 0x156, 0x3, 0x2, 0x2, 
       0x2, 0x158, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15a, 0x9, 0x7, 0x2, 
       0x2, 0x15a, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x15c, 0x7, 0x39, 0x2, 
       0x2, 0x15c, 0x161, 0x5, 0x2, 0x2, 0x2, 0x15d, 0x15e, 0x7, 0x37, 0x2, 
       0x2, 0x15e, 0x160, 0x5, 0x2, 0x2, 0x2, 0x15f, 0x15d, 0x3, 0x2, 0x2, 
       0x2, 0x160, 0x163, 0x3, 0x2, 0x2, 0x2, 0x161, 0x15f, 0x3, 0x2, 0x2, 
       0x2, 0x161, 0x162, 0x3, 0x2, 0x2, 0x2, 0x162, 0x3f, 0x3, 0x2, 0x2, 
       0x2, 0x163, 0x161, 0x3, 0x2, 0x2, 0x2, 0x164, 0x166, 0x5, 0x3c, 0x1f, 
       0x2, 0x165, 0x164, 0x3, 0x2, 0x2, 0x2, 0x165, 0x166, 0x3, 0x2, 0x2, 
       0x2, 0x166, 0x168, 0x3, 0x2, 0x2, 0x2, 0x167, 0x169, 0x7, 0x13, 0x2, 
       0x2, 0x168, 0x167, 0x3, 0x2, 0x2, 0x2, 0x168, 0x169, 0x3, 0x2, 0x2, 
       0x2, 0x169, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x16b, 0x7, 0x16, 0x2, 
       0x2, 0x16b, 0x16c, 0x7, 0x16, 0x2, 0x2, 0x16c, 0x41, 0x3, 0x2, 0x2, 
       0x2, 0x16d, 0x16e, 0x5, 0x40, 0x21, 0x2, 0x16e, 0x16f, 0x7, 0x3a, 
       0x2, 0x2, 0x16f, 0x43, 0x3, 0x2, 0x2, 0x2, 0x170, 0x171, 0x5, 0x40, 
       0x21, 0x2, 0x171, 0x172, 0x7, 0x41, 0x2, 0x2, 0x172, 0x173, 0x5, 
       0x16, 0xc, 0x2, 0x173, 0x174, 0x7, 0x42, 0x2, 0x2, 0x174, 0x178, 
       0x7, 0x3f, 0x2, 0x2, 0x175, 0x177, 0x5, 0x3a, 0x1e, 0x2, 0x176, 0x175, 
       0x3, 0x2, 0x2, 0x2, 0x177, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x178, 0x176, 
       0x3, 0x2, 0x2, 0x2, 0x178, 0x179, 0x3, 0x2, 0x2, 0x2, 0x179, 0x17b, 
       0x3, 0x2, 0x2, 0x2, 0x17a, 0x178, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x17c, 
       0x7, 0x40, 0x2, 0x2, 0x17c, 0x45, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x17f, 
       0x5, 0x3c, 0x1f, 0x2, 0x17e, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x17f, 
       0x3, 0x2, 0x2, 0x2, 0x17f, 0x180, 0x3, 0x2, 0x2, 0x2, 0x180, 0x181, 
       0x7, 0x8, 0x2, 0x2, 0x181, 0x183, 0x7, 0x16, 0x2, 0x2, 0x182, 0x184, 
       0x5, 0x3e, 0x20, 0x2, 0x183, 0x182, 0x3, 0x2, 0x2, 0x2, 0x183, 0x184, 
       0x3, 0x2, 0x2, 0x2, 0x184, 0x185, 0x3, 0x2, 0x2, 0x2, 0x185, 0x18a, 
       0x7, 0x3f, 0x2, 0x2, 0x186, 0x189, 0x5, 0x42, 0x22, 0x2, 0x187, 0x189, 
       0x5, 0x44, 0x23, 0x2, 0x188, 0x186, 0x3, 0x2, 0x2, 0x2, 0x188, 0x187, 
       0x3, 0x2, 0x2, 0x2, 0x189, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x188, 
       0x3, 0x2, 0x2, 0x2, 0x18a, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x18d, 
       0x3, 0x2, 0x2, 0x2, 0x18c, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x18e, 
       0x7, 0x40, 0x2, 0x2, 0x18e, 0x47, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x190, 
       0x9, 0x8, 0x2, 0x2, 0x190, 0x49, 0x3, 0x2, 0x2, 0x2, 0x191, 0x192, 
       0x7, 0x3, 0x2, 0x2, 0x192, 0x193, 0x5, 0x12, 0xa, 0x2, 0x193, 0x194, 
       0x5, 0x48, 0x25, 0x2, 0x194, 0x195, 0x7, 0x16, 0x2, 0x2, 0x195, 0x196, 
       0x7, 0x41, 0x2, 0x2, 0x196, 0x197, 0x5, 0x1a, 0xe, 0x2, 0x197, 0x198, 
       0x7, 0x42, 0x2, 0x2, 0x198, 0x199, 0x7, 0x3a, 0x2, 0x2, 0x199, 0x4b, 
       0x3, 0x2, 0x2, 0x2, 0x19a, 0x19b, 0x7, 0x4, 0x2, 0x2, 0x19b, 0x19c, 
       0x7, 0x46, 0x2, 0x2, 0x19c, 0x19d, 0x7, 0x3a, 0x2, 0x2, 0x19d, 0x4d, 
       0x3, 0x2, 0x2, 0x2, 0x19e, 0x1a1, 0x5, 0x4a, 0x26, 0x2, 0x19f, 0x1a1, 
       0x5, 0x4c, 0x27, 0x2, 0x1a0, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x19f, 
       0x3, 0x2, 0x2, 0x2, 0x1a1, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a0, 
       0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x4f, 
       0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a5, 0x7, 0x13, 0x2, 0x2, 0x1a5, 0x1a6, 
       0x5, 0xc, 0x7, 0x2, 0x1a6, 0x1a7, 0x7, 0xb, 0x2, 0x2, 0x1a7, 0x1a8, 
       0x7, 0x41, 0x2, 0x2, 0x1a8, 0x1a9, 0x7, 0x42, 0x2, 0x2, 0x1a9, 0x1ad, 
       0x7, 0x3f, 0x2, 0x2, 0x1aa, 0x1ac, 0x5, 0x3a, 0x1e, 0x2, 0x1ab, 0x1aa, 
       0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1ab, 
       0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1b0, 
       0x3, 0x2, 0x2, 0x2, 0x1af, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1b1, 
       0x7, 0x40, 0x2, 0x2, 0x1b1, 0x51, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b4, 
       0x5, 0x36, 0x1c, 0x2, 0x1b3, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1b7, 
       0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b6, 
       0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b5, 
       0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1ba, 0x5, 0x4e, 0x28, 0x2, 0x1b9, 0x1b8, 
       0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1ba, 0x3, 0x2, 0x2, 0x2, 0x1ba, 0x1be, 
       0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1bd, 0x5, 0x46, 0x24, 0x2, 0x1bc, 0x1bb, 
       0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1be, 0x1bc, 
       0x3, 0x2, 0x2, 0x2, 0x1be, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1c2, 
       0x3, 0x2, 0x2, 0x2, 0x1c0, 0x1be, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1c3, 
       0x5, 0x50, 0x29, 0x2, 0x1c2, 0x1c1, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c3, 
       0x3, 0x2, 0x2, 0x2, 0x1c3, 0x53, 0x3, 0x2, 0x2, 0x2, 0x36, 0x59, 
       0x68, 0x6b, 0x75, 0x80, 0x84, 0x89, 0x90, 0x95, 0x98, 0x9e, 0xa3, 
       0xaa, 0xaf, 0xb6, 0xc2, 0xcb, 0xd9, 0xde, 0xe8, 0xed, 0x100, 0x10c, 
       0x111, 0x119, 0x11c, 0x121, 0x129, 0x12d, 0x133, 0x135, 0x13b, 0x142, 
       0x145, 0x149, 0x153, 0x157, 0x161, 0x165, 0x168, 0x178, 0x17e, 0x183, 
       0x188, 0x18a, 0x1a0, 0x1a2, 0x1ad, 0x1b5, 0x1b9, 0x1be, 0x1c2, 
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

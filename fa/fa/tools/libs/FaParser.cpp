
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


//----------------- UseExprContext ------------------------------------------------------------------

FaParser::UseExprContext::UseExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FaParser::UseExprContext::ID() {
  return getToken(FaParser::ID, 0);
}

tree::TerminalNode* FaParser::UseExprContext::IDs() {
  return getToken(FaParser::IDs, 0);
}


size_t FaParser::UseExprContext::getRuleIndex() const {
  return FaParser::RuleUseExpr;
}


antlrcpp::Any FaParser::UseExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitUseExpr(this);
  else
    return visitor->visitChildren(this);
}

FaParser::UseExprContext* FaParser::useExpr() {
  UseExprContext *_localctx = _tracker.createInstance<UseExprContext>(_ctx, getState());
  enterRule(_localctx, 0, FaParser::RuleUseExpr);
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
    setState(4);
    match(FaParser::T__0);
    setState(5);
    _la = _input->LA(1);
    if (!(_la == FaParser::ID

    || _la == FaParser::IDs)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(6);
    match(FaParser::T__1);
   
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

std::vector<FaParser::UseExprContext *> FaParser::ProgramContext::useExpr() {
  return getRuleContexts<FaParser::UseExprContext>();
}

FaParser::UseExprContext* FaParser::ProgramContext::useExpr(size_t i) {
  return getRuleContext<FaParser::UseExprContext>(i);
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
  enterRule(_localctx, 2, FaParser::RuleProgram);
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
    setState(11);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::T__0) {
      setState(8);
      useExpr();
      setState(13);
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
  "useExpr", "program"
};

std::vector<std::string> FaParser::_literalNames = {
  "", "'use'", "';'"
};

std::vector<std::string> FaParser::_symbolicNames = {
  "", "", "", "Comment1", "Comment2", "WS", "ID", "IDs"
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
       0x3, 0x9, 0x11, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x3, 0x2, 
       0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x7, 0x3, 0xc, 0xa, 0x3, 
       0xc, 0x3, 0xe, 0x3, 0xf, 0xb, 0x3, 0x3, 0x3, 0x2, 0x2, 0x4, 0x2, 
       0x4, 0x2, 0x3, 0x3, 0x2, 0x8, 0x9, 0x2, 0xf, 0x2, 0x6, 0x3, 0x2, 
       0x2, 0x2, 0x4, 0xd, 0x3, 0x2, 0x2, 0x2, 0x6, 0x7, 0x7, 0x3, 0x2, 
       0x2, 0x7, 0x8, 0x9, 0x2, 0x2, 0x2, 0x8, 0x9, 0x7, 0x4, 0x2, 0x2, 
       0x9, 0x3, 0x3, 0x2, 0x2, 0x2, 0xa, 0xc, 0x5, 0x2, 0x2, 0x2, 0xb, 
       0xa, 0x3, 0x2, 0x2, 0x2, 0xc, 0xf, 0x3, 0x2, 0x2, 0x2, 0xd, 0xb, 
       0x3, 0x2, 0x2, 0x2, 0xd, 0xe, 0x3, 0x2, 0x2, 0x2, 0xe, 0x5, 0x3, 
       0x2, 0x2, 0x2, 0xf, 0xd, 0x3, 0x2, 0x2, 0x2, 0x3, 0xd, 
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


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


//----------------- SContext ------------------------------------------------------------------

FaParser::SContext::SContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FaParser::SContext::ID() {
  return getTokens(FaParser::ID);
}

tree::TerminalNode* FaParser::SContext::ID(size_t i) {
  return getToken(FaParser::ID, i);
}


size_t FaParser::SContext::getRuleIndex() const {
  return FaParser::RuleS;
}


antlrcpp::Any FaParser::SContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FaVisitor*>(visitor))
    return parserVisitor->visitS(this);
  else
    return visitor->visitChildren(this);
}

FaParser::SContext* FaParser::s() {
  SContext *_localctx = _tracker.createInstance<SContext>(_ctx, getState());
  enterRule(_localctx, 0, FaParser::RuleS);
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
    setState(2);
    match(FaParser::T__0);
    setState(6);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FaParser::ID) {
      setState(3);
      match(FaParser::ID);
      setState(8);
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
  "s"
};

std::vector<std::string> FaParser::_literalNames = {
  "", "'hello'"
};

std::vector<std::string> FaParser::_symbolicNames = {
  "", "", "ID", "WS"
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
       0x3, 0x5, 0xc, 0x4, 0x2, 0x9, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 
       0x7, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0xa, 0xb, 0x2, 0x3, 0x2, 0x2, 
       0x2, 0x3, 0x2, 0x2, 0x2, 0x2, 0xb, 0x2, 0x4, 0x3, 0x2, 0x2, 0x2, 
       0x4, 0x8, 0x7, 0x3, 0x2, 0x2, 0x5, 0x7, 0x7, 0x4, 0x2, 0x2, 0x6, 
       0x5, 0x3, 0x2, 0x2, 0x2, 0x7, 0xa, 0x3, 0x2, 0x2, 0x2, 0x8, 0x6, 
       0x3, 0x2, 0x2, 0x2, 0x8, 0x9, 0x3, 0x2, 0x2, 0x2, 0x9, 0x3, 0x3, 
       0x2, 0x2, 0x2, 0xa, 0x8, 0x3, 0x2, 0x2, 0x2, 0x3, 0x8, 
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


// Generated from Fa.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  FaLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, Class = 2, PublicLevel = 3, Return = 4, Static = 5, Use = 6, 
    Id = 7, QuotFangL = 8, QuotFangR = 9, QuotJianL = 10, QuotJianR = 11, 
    QuotHuaL = 12, QuotHuaR = 13, QuotYuanL = 14, QuotYuanR = 15, BitAnd = 16, 
    BitOr = 17, BitXor = 18, Comma = 19, Colon = 20, Semi = 21, Num = 22, 
    Comment1 = 23, Comment2 = 24, WS = 25
  };

  explicit FaLexer(antlr4::CharStream *input);
  ~FaLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};



// Generated from Fa.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  FaLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, CC__Cdecl = 2, CC__FastCall = 3, CC__StdCall = 4, Class = 5, 
    Const = 6, Extern = 7, FaEntryMain = 8, Internal = 9, Public = 10, Protected = 11, 
    Private = 12, Return = 13, Static = 14, Use = 15, Volatile = 16, Id = 17, 
    QuotFangL = 18, QuotFangR = 19, QuotJianL = 20, QuotJianR = 21, QuotHuaL = 22, 
    QuotHuaR = 23, QuotYuanL = 24, QuotYuanR = 25, BitAnd = 26, BitOr = 27, 
    BitXor = 28, Comma = 29, Colon = 30, Semi = 31, Star = 32, Num = 33, 
    Comment1 = 34, Comment2 = 35, WS = 36
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


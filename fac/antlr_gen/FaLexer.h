
// Generated from Fa.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"




class  FaLexer : public antlr4::Lexer {
public:
  enum {
    Break = 1, Class = 2, Continue = 3, Do = 4, Else = 5, For = 6, If = 7, 
    Internal = 8, Namespace = 9, Private = 10, Protected = 11, Public = 12, 
    Return = 13, Switch = 14, Use = 15, When = 16, While = 17, Func = 18, 
    Yield = 19, PublicLevel = 20, Assign = 21, AddAssign = 22, SubAssign = 23, 
    StarAssign = 24, DivAssign = 25, ModAssign = 26, OrAssign = 27, AndAssign = 28, 
    XorAssign = 29, StarStarAssign = 30, AndAndAssign = 31, OrOrAssign = 32, 
    WaveOp = 33, AddAddOp = 34, SubSubOp = 35, Exclam = 36, PointPoint = 37, 
    PointOp = 38, AddOp = 39, SubOp = 40, StarOp = 41, DivOp = 42, ModOp = 43, 
    OrOp = 44, AndOp = 45, XorOp = 46, StarStarOp = 47, AndAndOp = 48, OrOrOp = 49, 
    Comma = 50, ColonColon = 51, Colon = 52, NewLine = 53, Semi = 54, Underline = 55, 
    QuotFangL = 56, QuotFangR = 57, QuotJianL = 58, QuotJianR = 59, QuotHuaL = 60, 
    QuotHuaR = 61, QuotYuanL = 62, QuotYuanR = 63, BoolLiteral = 64, NumLiteral = 65, 
    String1Literal = 66, String2Literal = 67, StringLiteral = 68, Id = 69, 
    Comment1 = 70, Comment2 = 71, WS = 72
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


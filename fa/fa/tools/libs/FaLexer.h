
// Generated from Fa.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  FaLexer : public antlr4::Lexer {
public:
  enum {
    AImport = 1, ALib = 2, Break = 3, CC__Cdecl = 4, CC__FastCall = 5, CC__StdCall = 6, 
    Continue = 7, Class = 8, Const = 9, Else = 10, FaMain = 11, For = 12, 
    If = 13, Internal = 14, New = 15, Public = 16, Protected = 17, Private = 18, 
    Return = 19, Signed = 20, Static = 21, Step = 22, Unsigned = 23, Use = 24, 
    While = 25, Assign = 26, ReverseOp = 27, AddAddOp = 28, SubSubOp = 29, 
    PointPoint = 30, PointOp = 31, AddOp = 32, SubOp = 33, StarOp = 34, 
    DivOp = 35, ModOp = 36, OrOp = 37, AndOp = 38, XorOp = 39, Qus = 40, 
    Comma = 41, ColonColon = 42, Colon = 43, Semi = 44, Exclam = 45, QuotFangL = 46, 
    QuotFangR = 47, QuotJianL = 48, QuotJianR = 49, QuotHuaL = 50, QuotHuaR = 51, 
    QuotYuanL = 52, QuotYuanR = 53, BoolLiteral = 54, IntLiteral = 55, FloatLiteral = 56, 
    String1Literal = 57, Id = 58, Comment1 = 59, Comment2 = 60, WS = 61
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



// Generated from Fa.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  FaLexer : public antlr4::Lexer {
public:
  enum {
    AImport = 1, ALib = 2, Break = 3, CC__Cdecl = 4, CC__FastCall = 5, CC__StdCall = 6, 
    Continue = 7, Class = 8, Const = 9, Else = 10, FaEntryMain = 11, If = 12, 
    Internal = 13, Public = 14, Protected = 15, Private = 16, Return = 17, 
    Signed = 18, Static = 19, Unsigned = 20, Use = 21, While = 22, Assign = 23, 
    ReverseOp = 24, AddAddOp = 25, SubSubOp = 26, PointOp = 27, AddOp = 28, 
    SubOp = 29, StarOp = 30, DivOp = 31, ModOp = 32, OrOp = 33, AndOp = 34, 
    XorOp = 35, Qus = 36, Comma = 37, ColonColon = 38, Colon = 39, Semi = 40, 
    Exclam = 41, QuotFangL = 42, QuotFangR = 43, QuotJianL = 44, QuotJianR = 45, 
    QuotHuaL = 46, QuotHuaR = 47, QuotYuanL = 48, QuotYuanR = 49, BoolLiteral = 50, 
    IntLiteral = 51, FloatLiteral = 52, String1Literal = 53, Id = 54, Comment1 = 55, 
    Comment2 = 56, WS = 57
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



// Generated from Fa.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  FaLexer : public antlr4::Lexer {
public:
  enum {
    AImport = 1, ALib = 2, Break = 3, CC__Cdecl = 4, CC__FastCall = 5, CC__StdCall = 6, 
    Continue = 7, Class = 8, Const = 9, Else = 10, FaMain = 11, If = 12, 
    Internal = 13, New = 14, Public = 15, Protected = 16, Private = 17, 
    Return = 18, Signed = 19, Static = 20, Unsigned = 21, Use = 22, While = 23, 
    Assign = 24, ReverseOp = 25, AddAddOp = 26, SubSubOp = 27, PointOp = 28, 
    AddOp = 29, SubOp = 30, StarOp = 31, DivOp = 32, ModOp = 33, OrOp = 34, 
    AndOp = 35, XorOp = 36, Qus = 37, Comma = 38, ColonColon = 39, Colon = 40, 
    Semi = 41, Exclam = 42, QuotFangL = 43, QuotFangR = 44, QuotJianL = 45, 
    QuotJianR = 46, QuotHuaL = 47, QuotHuaR = 48, QuotYuanL = 49, QuotYuanR = 50, 
    BoolLiteral = 51, IntLiteral = 52, FloatLiteral = 53, String1Literal = 54, 
    Id = 55, Comment1 = 56, Comment2 = 57, WS = 58
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


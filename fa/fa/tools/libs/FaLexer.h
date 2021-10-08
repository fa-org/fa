
// Generated from Fa.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  FaLexer : public antlr4::Lexer {
public:
  enum {
    AImport = 1, ALib = 2, Break = 3, CC__Cdecl = 4, CC__FastCall = 5, CC__StdCall = 6, 
    Continue = 7, Class = 8, Const = 9, Else = 10, Enum = 11, FaMain = 12, 
    For = 13, If = 14, Interface = 15, Internal = 16, New = 17, Public = 18, 
    Protected = 19, Private = 20, Return = 21, Signed = 22, Static = 23, 
    Step = 24, Struct = 25, Unsigned = 26, Use = 27, While = 28, Assign = 29, 
    ReverseOp = 30, AddAddOp = 31, SubSubOp = 32, PointPoint = 33, PointOp = 34, 
    AddOp = 35, SubOp = 36, StarOp = 37, DivOp = 38, ModOp = 39, OrOp = 40, 
    AndOp = 41, XorOp = 42, Qus = 43, Comma = 44, ColonColon = 45, Colon = 46, 
    Semi = 47, Exclam = 48, QuotFangL = 49, QuotFangR = 50, QuotJianL = 51, 
    QuotJianR = 52, QuotHuaL = 53, QuotHuaR = 54, QuotYuanL = 55, QuotYuanR = 56, 
    BoolLiteral = 57, IntLiteral = 58, FloatLiteral = 59, String1Literal = 60, 
    Id = 61, Comment1 = 62, Comment2 = 63, WS = 64
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


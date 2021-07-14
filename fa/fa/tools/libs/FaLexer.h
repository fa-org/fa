
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
    QusQusAssign = 24, AddAssign = 25, SubAssign = 26, StarAssign = 27, 
    StarStarAssign = 28, DivAssign = 29, ModAssign = 30, AndAssign = 31, 
    OrAssign = 32, XorAssign = 33, AndAndAssign = 34, OrOrAssign = 35, ShiftLAssign = 36, 
    ShiftRAssign = 37, ReverseOp = 38, AddAddOp = 39, SubSubOp = 40, PointOp = 41, 
    QusQusOp = 42, AddOp = 43, SubOp = 44, StarOp = 45, DivOp = 46, StarStarOp = 47, 
    ModOp = 48, AndOp = 49, OrOp = 50, XorOp = 51, AndAndOp = 52, OrOrOp = 53, 
    Qus = 54, Comma = 55, ColonColon = 56, Colon = 57, Semi = 58, QuotFangL = 59, 
    QuotFangR = 60, QuotJianL = 61, QuotJianR = 62, QuotHuaL = 63, QuotHuaR = 64, 
    QuotYuanL = 65, QuotYuanR = 66, BoolLiteral = 67, IntLiteral = 68, FloatLiteral = 69, 
    String1Literal = 70, Id = 71, Comment1 = 72, Comment2 = 73, WS = 74
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



// Generated from Fa.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  FaLexer : public antlr4::Lexer {
public:
  enum {
    AImport = 1, ALib = 2, Break = 3, CC__Cdecl = 4, CC__FastCall = 5, CC__StdCall = 6, 
    Continue = 7, Class = 8, Const = 9, Else = 10, FaEntryMain = 11, If = 12, 
    Internal = 13, Public = 14, Protected = 15, Private = 16, Return = 17, 
    Signed = 18, Static = 19, Unsigned = 20, Use = 21, While = 22, Id = 23, 
    Assign = 24, QusQusAssign = 25, AddAssign = 26, SubAssign = 27, StarAssign = 28, 
    StarStarAssign = 29, DivAssign = 30, ModAssign = 31, AndAssign = 32, 
    OrAssign = 33, XorAssign = 34, AndAndAssign = 35, OrOrAssign = 36, ShiftLAssign = 37, 
    ShiftRAssign = 38, ReverseOp = 39, AddAddOp = 40, SubSubOp = 41, PointOp = 42, 
    QusQusOp = 43, AddOp = 44, SubOp = 45, StarOp = 46, DivOp = 47, StarStarOp = 48, 
    ModOp = 49, AndOp = 50, OrOp = 51, XorOp = 52, AndAndOp = 53, OrOrOp = 54, 
    Qus = 55, Comma = 56, ColonColon = 57, Colon = 58, Semi = 59, QuotFangL = 60, 
    QuotFangR = 61, QuotJianL = 62, QuotJianR = 63, QuotHuaL = 64, QuotHuaR = 65, 
    QuotYuanL = 66, QuotYuanR = 67, BoolLiteral = 68, IntLiteral = 69, FloatLiteral = 70, 
    String1Literal = 71, Comment1 = 72, Comment2 = 73, WS = 74
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


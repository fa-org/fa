
// Generated from Fa.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  FaLexer : public antlr4::Lexer {
public:
  enum {
    AImport = 1, ALib = 2, CC__Cdecl = 3, CC__FastCall = 4, CC__StdCall = 5, 
    Class = 6, Const = 7, FaEntryMain = 8, Internal = 9, Public = 10, Protected = 11, 
    Private = 12, Return = 13, Static = 14, Use = 15, Id = 16, Assign = 17, 
    QusQusAssign = 18, AddAssign = 19, SubAssign = 20, StarAssign = 21, 
    StarStarAssign = 22, DivAssign = 23, ModAssign = 24, AndAssign = 25, 
    OrAssign = 26, XorAssign = 27, AndAndAssign = 28, OrOrAssign = 29, ShiftLAssign = 30, 
    ShiftRAssign = 31, ReverseOp = 32, AddAddOp = 33, SubSubOp = 34, PointOp = 35, 
    QusQusOp = 36, AddOp = 37, SubOp = 38, StarOp = 39, DivOp = 40, StarStarOp = 41, 
    ModOp = 42, AndOp = 43, OrOp = 44, XorOp = 45, AndAndOp = 46, OrOrOp = 47, 
    ShiftLOp = 48, ShiftROp = 49, Qus = 50, Comma = 51, ColonColon = 52, 
    Colon = 53, Semi = 54, QuotFangL = 55, QuotFangR = 56, QuotJianL = 57, 
    QuotJianR = 58, QuotHuaL = 59, QuotHuaR = 60, QuotYuanL = 61, QuotYuanR = 62, 
    BoolLiteral = 63, IntLiteral = 64, FloatLiteral = 65, String1Literal = 66, 
    Comment1 = 67, Comment2 = 68, WS = 69
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


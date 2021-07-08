
// Generated from Fa.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  FaLexer : public antlr4::Lexer {
public:
  enum {
    AImport = 1, ALib = 2, CC__Cdecl = 3, CC__FastCall = 4, CC__StdCall = 5, 
    Class = 6, Const = 7, FaEntryMain = 8, Internal = 9, Public = 10, Protected = 11, 
    Private = 12, Return = 13, Signed = 14, Static = 15, Unsigned = 16, 
    Use = 17, Id = 18, Assign = 19, QusQusAssign = 20, AddAssign = 21, SubAssign = 22, 
    StarAssign = 23, StarStarAssign = 24, DivAssign = 25, ModAssign = 26, 
    AndAssign = 27, OrAssign = 28, XorAssign = 29, AndAndAssign = 30, OrOrAssign = 31, 
    ShiftLAssign = 32, ShiftRAssign = 33, ReverseOp = 34, AddAddOp = 35, 
    SubSubOp = 36, PointOp = 37, QusQusOp = 38, AddOp = 39, SubOp = 40, 
    StarOp = 41, DivOp = 42, StarStarOp = 43, ModOp = 44, AndOp = 45, OrOp = 46, 
    XorOp = 47, AndAndOp = 48, OrOrOp = 49, Qus = 50, Comma = 51, ColonColon = 52, 
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


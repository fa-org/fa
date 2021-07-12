
// Generated from Fa.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  FaLexer : public antlr4::Lexer {
public:
  enum {
    AImport = 1, ALib = 2, CC__Cdecl = 3, CC__FastCall = 4, CC__StdCall = 5, 
    Class = 6, Const = 7, Else = 8, FaEntryMain = 9, If = 10, Internal = 11, 
    Public = 12, Protected = 13, Private = 14, Return = 15, Signed = 16, 
    Static = 17, Unsigned = 18, Use = 19, Id = 20, Assign = 21, QusQusAssign = 22, 
    AddAssign = 23, SubAssign = 24, StarAssign = 25, StarStarAssign = 26, 
    DivAssign = 27, ModAssign = 28, AndAssign = 29, OrAssign = 30, XorAssign = 31, 
    AndAndAssign = 32, OrOrAssign = 33, ShiftLAssign = 34, ShiftRAssign = 35, 
    ReverseOp = 36, AddAddOp = 37, SubSubOp = 38, PointOp = 39, QusQusOp = 40, 
    AddOp = 41, SubOp = 42, StarOp = 43, DivOp = 44, StarStarOp = 45, ModOp = 46, 
    AndOp = 47, OrOp = 48, XorOp = 49, AndAndOp = 50, OrOrOp = 51, Qus = 52, 
    Comma = 53, ColonColon = 54, Colon = 55, Semi = 56, QuotFangL = 57, 
    QuotFangR = 58, QuotJianL = 59, QuotJianR = 60, QuotHuaL = 61, QuotHuaR = 62, 
    QuotYuanL = 63, QuotYuanR = 64, BoolLiteral = 65, IntLiteral = 66, FloatLiteral = 67, 
    String1Literal = 68, Comment1 = 69, Comment2 = 70, WS = 71
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


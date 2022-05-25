
// Generated from Fa.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"




class  FaLexer : public antlr4::Lexer {
public:
  enum {
    AImport = 1, ALib = 2, Break = 3, CC__Cdecl = 4, CC__FastCall = 5, CC__StdCall = 6, 
    Continue = 7, Class = 8, Const = 9, Do = 10, Else = 11, Enum = 12, FaMain = 13, 
    For = 14, If = 15, Is = 16, Internal = 17, Mut = 18, Namespace = 19, 
    New = 20, Params = 21, Public = 22, Protected = 23, Private = 24, Return = 25, 
    Signed = 26, Static = 27, Step = 28, Switch = 29, Unsigned = 30, Use = 31, 
    When = 32, While = 33, Assign = 34, AddAssign = 35, SubAssign = 36, 
    StarAssign = 37, DivAssign = 38, ModAssign = 39, OrAssign = 40, AndAssign = 41, 
    XorAssign = 42, QusQusAssign = 43, StarStarAssign = 44, AndAndAssign = 45, 
    OrOrAssign = 46, ReverseOp = 47, AddAddOp = 48, SubSubOp = 49, Exclam = 50, 
    PointPoint = 51, PointOp = 52, AddOp = 53, SubOp = 54, StarOp = 55, 
    DivOp = 56, ModOp = 57, OrOp = 58, AndOp = 59, XorOp = 60, QusQusOp = 61, 
    StarStarOp = 62, AndAndOp = 63, OrOrOp = 64, Qus = 65, Comma = 66, ColonColon = 67, 
    Colon = 68, NewLine = 69, Semi = 70, Underline = 71, QuotFangL = 72, 
    QuotFangR = 73, QuotJianL = 74, QuotJianR = 75, QuotHuaL = 76, QuotHuaR = 77, 
    QuotYuanL = 78, QuotYuanR = 79, BoolLiteral = 80, IntLiteral = 81, FloatLiteral = 82, 
    String1Literal = 83, RawId = 84, Comment1 = 85, Comment2 = 86, WS = 87
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


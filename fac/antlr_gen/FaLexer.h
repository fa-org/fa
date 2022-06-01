
// Generated from Fa.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"




class  FaLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, AImport = 9, ALib = 10, Break = 11, CC__Cdecl = 12, CC__FastCall = 13, 
    CC__StdCall = 14, Continue = 15, Class = 16, Const = 17, Do = 18, Else = 19, 
    Enum = 20, For = 21, If = 22, Is = 23, Internal = 24, Mut = 25, Namespace = 26, 
    New = 27, Params = 28, Public = 29, Protected = 30, Private = 31, Return = 32, 
    Signed = 33, Static = 34, Step = 35, Switch = 36, Unsigned = 37, Use = 38, 
    Var = 39, When = 40, While = 41, Assign = 42, AddAssign = 43, SubAssign = 44, 
    StarAssign = 45, DivAssign = 46, ModAssign = 47, OrAssign = 48, AndAssign = 49, 
    XorAssign = 50, QusQusAssign = 51, StarStarAssign = 52, AndAndAssign = 53, 
    OrOrAssign = 54, ReverseOp = 55, AddAddOp = 56, SubSubOp = 57, Exclam = 58, 
    PointPoint = 59, PointOp = 60, AddOp = 61, SubOp = 62, StarOp = 63, 
    DivOp = 64, ModOp = 65, OrOp = 66, AndOp = 67, XorOp = 68, QusQusOp = 69, 
    StarStarOp = 70, AndAndOp = 71, OrOrOp = 72, Qus = 73, Comma = 74, ColonColon = 75, 
    Colon = 76, Lf = 77, Semi = 78, Underline = 79, BoolLiteral = 80, IntLiteral = 81, 
    FloatLiteral = 82, String1Literal = 83, RawId = 84, Comment1 = 85, Comment2 = 86, 
    WS = 87
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


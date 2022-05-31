
// Generated from Fa.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"




class  FaLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, AImport = 9, ALib = 10, Break = 11, CC__Cdecl = 12, CC__FastCall = 13, 
    CC__StdCall = 14, Continue = 15, Class = 16, Const = 17, Do = 18, Else = 19, 
    Enum = 20, Fn = 21, For = 22, If = 23, Is = 24, Internal = 25, Mut = 26, 
    Namespace = 27, New = 28, Params = 29, Public = 30, Protected = 31, 
    Private = 32, Return = 33, Signed = 34, Static = 35, Step = 36, Switch = 37, 
    Unsigned = 38, Use = 39, Var = 40, When = 41, While = 42, Assign = 43, 
    AddAssign = 44, SubAssign = 45, StarAssign = 46, DivAssign = 47, ModAssign = 48, 
    OrAssign = 49, AndAssign = 50, XorAssign = 51, QusQusAssign = 52, StarStarAssign = 53, 
    AndAndAssign = 54, OrOrAssign = 55, ReverseOp = 56, AddAddOp = 57, SubSubOp = 58, 
    Exclam = 59, PointPoint = 60, PointOp = 61, AddOp = 62, SubOp = 63, 
    StarOp = 64, DivOp = 65, ModOp = 66, OrOp = 67, AndOp = 68, XorOp = 69, 
    QusQusOp = 70, StarStarOp = 71, AndAndOp = 72, OrOrOp = 73, Qus = 74, 
    Comma = 75, ColonColon = 76, Colon = 77, Lf = 78, Semi = 79, Underline = 80, 
    BoolLiteral = 81, IntLiteral = 82, FloatLiteral = 83, String1Literal = 84, 
    RawId = 85, Comment1 = 86, Comment2 = 87, WS = 88
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


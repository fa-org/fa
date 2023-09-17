
// Generated from FaLexer.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  FaLexer : public MyLexer {
public:
  enum {
    CC__Cdecl = 1, CC__FastCall = 2, CC__StdCall = 3, Annotation = 4, Base = 5, 
    Break = 6, Calc = 7, Continue = 8, Class = 9, Cast = 10, Const = 11, 
    Disperse = 12, Do = 13, Else = 14, Enum = 15, Expr = 16, For = 17, From = 18, 
    Get = 19, If = 20, In = 21, Is = 22, Internal = 23, Mut = 24, Namespace = 25, 
    New = 26, Operator = 27, Params = 28, Public = 29, Protected = 30, Private = 31, 
    Return = 32, Run = 33, Select = 34, Set = 35, Signed = 36, Static = 37, 
    Stmt = 38, SwitchExpr = 39, Switch = 40, Type = 41, Unsigned = 42, Use = 43, 
    AstClassVar = 44, When = 45, Where = 46, While = 47, AssignOp = 48, AddAssignOp = 49, 
    SubAssignOp = 50, StarAssignOp = 51, DivAssignOp = 52, ModAssignOp = 53, 
    OrAssignOp = 54, AndAssignOp = 55, XorAssignOp = 56, QusQusAssignOp = 57, 
    StarStarAssignOp = 58, AndAndAssignOp = 59, OrOrAssignOp = 60, ReverseOp = 61, 
    AddAddOp = 62, SubSubOp = 63, Exclam = 64, PointOp = 65, AddOp = 66, 
    SubOp = 67, StarOp = 68, DivOp = 69, ModOp = 70, OrOp = 71, AndOp = 72, 
    XorOp = 73, PointPoint = 74, QusQusOp = 75, StarStarOp = 76, AndAndOp = 77, 
    OrOrOp = 78, Qus = 79, Comma = 80, ColonColon = 81, Colon = 82, Lf = 83, 
    Semi = 84, Underline = 85, QFangL = 86, QFangR = 87, LessThan = 88, 
    GreatThan = 89, QHuaL = 90, QHuaR = 91, QYuanL = 92, QYuanR = 93, LtEqualOp = 94, 
    GtEqualOp = 95, EqualOp = 96, NotEqualOp = 97, ExprFuncDef = 98, BoolLiteral = 99, 
    HexLiteral = 100, IntLiteral = 101, FloatLiteral = 102, String1Literal = 103, 
    String2Literal = 104, String3Literal = 105, FmtString1 = 106, FmtString2 = 107, 
    Id = 108, Comment1 = 109, Comment2 = 110, WS = 111, QHuaLQHuaL = 112, 
    QHuaRQHuaR = 113, QHuaLInside = 114, RegularCharInside = 115, VerbatiumDoubleQuoteInside = 116, 
    DoubleQuoteInside = 117, RegularStringInside = 118, VerbatiumInsideString = 119, 
    QHuaRInside = 120, FormatString = 121
  };

  enum {
    INTERPOLATION_STRING = 1, INTERPOLATION_FORMAT = 2
  };

  explicit FaLexer(antlr4::CharStream *input);

  ~FaLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;

  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.
  void ColonAction(antlr4::RuleContext *context, size_t actionIndex);
  void QFangLAction(antlr4::RuleContext *context, size_t actionIndex);
  void QFangRAction(antlr4::RuleContext *context, size_t actionIndex);
  void QHuaLAction(antlr4::RuleContext *context, size_t actionIndex);
  void QHuaRAction(antlr4::RuleContext *context, size_t actionIndex);
  void QYuanLAction(antlr4::RuleContext *context, size_t actionIndex);
  void QYuanRAction(antlr4::RuleContext *context, size_t actionIndex);
  void FmtString1Action(antlr4::RuleContext *context, size_t actionIndex);
  void FmtString2Action(antlr4::RuleContext *context, size_t actionIndex);
  void QHuaLInsideAction(antlr4::RuleContext *context, size_t actionIndex);
  void DoubleQuoteInsideAction(antlr4::RuleContext *context, size_t actionIndex);
  void QHuaRInsideAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.
  bool RegularCharInsideSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);
  bool VerbatiumDoubleQuoteInsideSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);
  bool RegularStringInsideSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);
  bool VerbatiumInsideStringSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);

};


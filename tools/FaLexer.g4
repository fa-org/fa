// C++�﷨
// https://github.com/antlr/grammars-v4/blob/master/cpp/CPP14Lexer.g4
// https://github.com/antlr/grammars-v4/blob/master/cpp/CPP14Parser.g4

// ANTLR�ĵ�
// https://decaf-lang.github.io/minidecaf-tutorial/
// https://wizardforcel.gitbooks.io/antlr4-short-course/content/

lexer grammar FaLexer;

options { superClass = MyLexer; }



//
// keyword
//
CC__Cdecl:					'__cdecl';
CC__FastCall:				'__fastcall';
CC__StdCall:				'__stdcall';
Annotation:					'annotation';
Base:						'base';
Break:						'break';
Calc:						'calc';
Continue:					'continue';
Class:						'class';
Cast:						'cast';
Const:						'const';
Disperse:					'disperse';
Do:							'do';
Else:						'else';
Enum:						'enum';
Expr:						'expr';
For:						'for';
From:						'from';
Get:						'get';
If:							'if';
In:							'in';
Is:							'is';
Internal:					'internal';
Mut:						'mut';
Namespace:					'namespace';
New:						'new';
Operator:					'operator';
Params:						'params';
Public:						'public';
Protected:					'protected';
Private:					'private';
Return:						'return';
Run:						'run';
Select:						'select';
Set:						'set';
Signed:						'signed';
Static:						'static';
Stmt:						'stmt';
SwitchExpr:					'switchexpr';
Switch:						'switch';
Type:						'type';
Unsigned:					'unsigned';
Use:						'use';
Var:						'var';
When:						'when';
Where:						'where';
While:						'while';



//
// element
//

// ��ֵ����
AssignOp:					'=';
AddAssignOp:				AddOp AssignOp;
SubAssignOp:				SubOp AssignOp;
StarAssignOp:				StarOp AssignOp;
DivAssignOp:				DivOp AssignOp;
ModAssignOp:				ModOp AssignOp;
OrAssignOp:					OrOp AssignOp;
AndAssignOp:				AndOp AssignOp;
XorAssignOp:				XorOp AssignOp;
QusQusAssignOp:				QusQusOp AssignOp;
StarStarAssignOp:			StarStarOp AssignOp;
AndAndAssignOp:				AndAndOp AssignOp;
OrOrAssignOp:				OrOrOp AssignOp;

// һԪ����
ReverseOp:					'~';
AddAddOp:					'++';
SubSubOp:					'--';
Exclam:						'!';
Dollar:						'$';

// ��Ԫ����
PointOp:					'.';
AddOp:						'+';
SubOp:						'-';
StarOp:						'*';
DivOp:						'/';
ModOp:						'%';
OrOp:						'|';
AndOp:						'&';
XorOp:						'^';
PointPoint:					PointOp PointOp;
QusQusOp:					Qus Qus;
StarStarOp:					StarOp StarOp;
AndAndOp:					AndOp AndOp;
OrOrOp:						OrOp OrOp;

// ��Ԫ������
Qus:						'?';
Comma:						',';
ColonColon:					'::';
Colon:						':' { this->OnColon(); };
Lf:							'\n';
Semi:						';';
Underline:					'_';

// ����
QFangL:						'[' { this->OnQuotL (); };
QFangR:						']' { this->OnQuotR (); };
LessThan:					'<';
GreatThan:					'>';
QHuaL:						'{' { this->OnQuotL (); };
QHuaR:						'}' { this->OnQuotR (); };
QYuanL:						'(' { this->OnQuotL (); };
QYuanR:						')' { this->OnQuotR (); };

// �Ƚ�
LtEqualOp:					LessThan AssignOp;
GtEqualOp:					GreatThan AssignOp;
EqualOp:					AssignOp AssignOp;
NotEqualOp:					Exclam AssignOp;
ExprFuncDef:				AssignOp GreatThan;



//
// Literal
//
fragment SimpleEscape:		'\\\'' | '\\"' | '\\\\' | '\\n' | '\\r' | ('\\' ('\r' '\n'? | '\n')) | '\\t';
fragment HexEscape:			'\\x' HEX HEX;
fragment UniEscape:			'\\u' HEX HEX HEX HEX;
fragment Schar:				SimpleEscape | HexEscape | UniEscape;
//fragment FormatChar:		Schar | '{{' | '}}' | ~[{}"\\\r\n];
//
BoolLiteral:				'true' | 'false';
HexLiteral:					'0' [xX] NUM+;
IntLiteral:					NUM+;
FloatLiteral:				NUM+ PointOp NUM+;
String1Literal:				'"' (Schar | ~["\\\r\n])* '"';
String2Literal:				'\'' (Schar | ~['\\\r\n])* '\'';
String3Literal:				'@"' (~'"' | '""')* '"';
FmtString1:					'$"' { this->OnInterpolatedRegularStringStart(); } -> pushMode(INTERPOLATION_STRING);
FmtString2:					('$@"' | '@$"')  { this->OnInterpolatedVerbatiumStringStart(); }  -> pushMode(INTERPOLATION_STRING);
//
fragment NUM:				[0-9];
fragment HEX:				NUM | [a-fA-F];
fragment ID_BEGIN:			[a-zA-Z_] | [\u0080-\u{10FFFF}];
fragment ID_AFTER:			NUM | [a-zA-Z0-9_] | [\u0080-\u{10FFFF}];
Id:							'@'? ID_BEGIN ID_AFTER*;



//
// skips
//
Comment1:					'/*' .*? '*/' -> channel (HIDDEN);
Comment2:					'//' ~ [\n]* -> channel (HIDDEN);
WS:							[ \t\r]+ -> channel (HIDDEN);



//
// mode
//
mode INTERPOLATION_STRING;
QHuaLQHuaL:					'{{';
QHuaRQHuaR:					'}}';
QHuaLInside:				'{' { this->OnQHuaLInside(); } -> skip, pushMode(DEFAULT_MODE);
RegularCharInside:			{ this->IsRegularCharInside() }? SimpleEscape;
VerbatiumDoubleQuoteInside:	{ this->IsVerbatiumDoubleQuoteInside() }? '""';
DoubleQuoteInside:			'"' { this->OnDoubleQuoteInside(); } -> popMode;
RegularStringInside:		{ this->IsRegularCharInside() }? ~('{' | '\\' | '"')+;
VerbatiumInsideString:		{ this->IsVerbatiumDoubleQuoteInside() }? ~('{' | '"')+;

mode INTERPOLATION_FORMAT;
QHuaRInside:				'}' { this->OnQHuaRInside(); } -> skip, popMode;
FormatString:				~'}'+;

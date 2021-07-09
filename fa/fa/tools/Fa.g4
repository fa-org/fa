// C++语法
// https://github.com/antlr/grammars-v4/blob/master/cpp/CPP14Lexer.g4
// https://github.com/antlr/grammars-v4/blob/master/cpp/CPP14Parser.g4

// ANTLR文档
// https://decaf-lang.github.io/minidecaf-tutorial/
// https://wizardforcel.gitbooks.io/antlr4-short-course/content/

grammar Fa;



//
// keyword
//
AImport:					'@import';
ALib:						'@lib';
CC__Cdecl:					'__cdecl';
CC__FastCall:				'__fastcall';
CC__StdCall:				'__stdcall';
Class:						'class';
Const:						'const';
FaEntryMain:				'FaEntryMain';
Internal:					'internal';
Public:						'public';
Protected:					'protected';
Private:					'private';
Return:						'return';
Signed:						'signed';
Static:						'static';
Unsigned:					'unsigned';
Use:						'use';



//
// element
//
fragment NUM:				[0-9];
fragment HEX:				NUM | [a-fA-F];
fragment ID_BEGIN:			[a-zA-Z_] | ('\\u' HEX HEX HEX HEX);
fragment ID_AFTER:			NUM | [a-zA-Z_] | ('\\u' HEX HEX HEX HEX);
Id:							ID_BEGIN ID_AFTER*;
ids:						Id (PointOp Id)*;

// 赋值运算
Assign:						'=';
QusQusAssign:				'??=';
AddAssign:					'+=';
SubAssign:					'-=';
StarAssign:					'*=';
StarStarAssign:				'**=';
DivAssign:					'/=';
ModAssign:					'%=';
AndAssign:					'&=';
OrAssign:					'|=';
XorAssign:					'^=';
AndAndAssign:				'&&=';
OrOrAssign:					'||=';
ShiftLAssign:				'<<=';
ShiftRAssign:				'>>=';

// 一元计算
ReverseOp:					'~';
AddAddOp:					'++';
SubSubOp:					'--';

// 二元计算
PointOp:					'.';
QusQusOp:					'??';
AddOp:						'+';
SubOp:						'-';
StarOp:						'*';
DivOp:						'/';
StarStarOp:					'**';
ModOp:						'%';
AndOp:						'&';
OrOp:						'|';
XorOp:						'^';
AndAndOp:					'&&';
OrOrOp:						'||';
shiftLOp:					QuotJianL QuotJianL;
shiftROp:					QuotJianR QuotJianR;

// 三元或其他
Qus:						'?';
Comma:						',';
ColonColon:					'::';
Colon:						':';
Semi:						';';

// 括号
QuotFangL:					'[';
QuotFangR:					']';
QuotJianL:					'<';
QuotJianR:					'>';
QuotHuaL:					'{';
QuotHuaR:					'}';
QuotYuanL:					'(';
QuotYuanR:					')';



//
// Literal
//
fragment SimpleEscape:		'\\\'' | '\\"' | '\\\\' | '\\n' | '\\r' | ('\\' ('\r' '\n'? | '\n')) | '\\t';
fragment HexEscape:			'\\x' HEX HEX;
fragment UniEscape:			'\\u' HEX HEX HEX HEX;
fragment Schar:				SimpleEscape | HexEscape | UniEscape | ~["\\\r\n];
//
BoolLiteral:				'true' | 'false';
IntLiteral:					NUM+;
FloatLiteral:				NUM+ PointOp NUM+;
//CharLiteral:				"'" ([\x09\x20-\x26\x28-\x5B\x5D-\x7F\u0100-\uffff] | conv_mean16) "'";
String1Literal:				'"' Schar* '"';
//String2Literal:				'`' ([\x09\x20-\x5B\x5D-\x5F\x61-\x7F\u0100-\uffff] | conv_mean16)* '`';
literal:					BoolLiteral | IntLiteral | FloatLiteral | String1Literal;



//
// type
//
typeAfter:					(QuotFangL QuotFangR) | AndOp | Qus;
type:						Const? ( Id
								| (Id QuotJianL type (Comma type)* QuotJianR)	// Lazy<int>
								| (QuotYuanL type (Comma type)+ QuotYuanR)		// (int, string)
							) typeAfter*;										// int[]&
eTypeAfter:					(QuotFangL QuotFangR) | AndOp | StarOp;
eSign:						Signed | Unsigned;
eType:						Const? eSign? Id eTypeAfter*;					// int[]&



//
// list
//
typeVar:					type Id?;
typeVarList:				typeVar (Comma typeVar)*;
eTypeVar:					eType Id?;
eTypeVarList:				eTypeVar (Comma eTypeVar)*;



//
// expr
//
allAssign:					Assign | QusQusAssign | AddAssign | SubAssign | StarAssign | StarStarAssign | DivAssign | ModAssign | AndAssign | OrAssign | XorAssign | AndAndAssign | OrOrAssign | ShiftLAssign | ShiftRAssign;
allOp:						QusQusOp | PointOp | AddOp | SubOp | StarOp | DivOp | StarStarOp | ModOp | AndOp | OrOp | XorOp | AndAndOp | OrOrOp | shiftLOp | shiftROp;
//exprAtom:					ids
//							| value
//							| (QuotYuanL expr QuotYuanR);
//expr						: (AddOp | SubOp | AddAddOp | SubSubOp)?
//							( ids																			// io.Write
//							| literal																		// 12
//							| (QuotYuanL expr QuotYuanR)													// (12+24)
//							| (expr PointOp expr)															// 10.min
//							| (expr QuotFangL expr QuotFangR)												// list [12]
//							| (expr QuotYuanL (expr (Comma expr)*)? QuotYuanR)								// Write ("")
//							| ((AddAddOp | SubSubOp | ReverseOp) expr)										// ~val
//							| (expr (AddAddOp | SubSubOp))													// val++
//							| (expr allAssign<assoc=right> expr)											// val = 12
//							);
quotExpr:					(QuotYuanL expr QuotYuanR);
exprPrefix:					(AddOp | SubOp | AddAddOp | SubSubOp | ReverseOp);								// 前缀 + - ++ -- ~
exprBody:					(ids | (ColonColon Id) | literal);												// 本体
exprSuffix:					(AddAddOp | SubSubOp)+															// 后缀 ++ --
							| (QuotYuanL (expr (Comma expr)*)? QuotYuanR)+									//      Write ("")
							| (QuotFangL expr QuotFangL)+													//      list [12]
							| ((allAssign | allOp) expr)+;													//      12 += 24
expr:						quotExpr | (exprPrefix* exprBody exprSuffix*);



//
// stmt
//
useStmt:					Use ids Semi;
stmt:						Return? expr Semi;



//
// class
//
publicLevel:				Public | Internal | Protected | Private;
classParent:				Colon ids (Comma ids)*;
classItemPart:				publicLevel? Static? Id Id;
classItemFieldBlock:		classItemPart Semi;
classItemFuncBlock:			classItemPart QuotYuanL typeVarList QuotYuanR QuotHuaL stmt* QuotHuaR;
classBlock:					publicLevel? Class Id classParent? QuotHuaL (classItemFieldBlock | classItemFuncBlock)* QuotHuaR;



//
// import
//
callConvention:				CC__Cdecl | CC__FastCall | CC__StdCall;
importStmt:					AImport eType callConvention Id QuotYuanL eTypeVarList QuotYuanR Semi;
libStmt:					ALib String1Literal Semi;
importBlock:				(importStmt | libStmt)+;



//
// fa_entry_main
//
faEntryMainFuncBlock:		Static type FaEntryMain QuotYuanL QuotYuanR QuotHuaL stmt* QuotHuaR;
program:					useStmt* importBlock? classBlock* faEntryMainFuncBlock?;



//
// skips
//
Comment1:					'/*' .*? '*/' -> channel (HIDDEN);
Comment2:					'//' ~ [\r\n]* -> channel (HIDDEN);
WS:							[ \t\r\n]+ -> channel (HIDDEN);

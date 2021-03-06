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
Break:						'break';
CC__Cdecl:					'__cdecl';
CC__FastCall:				'__fastcall';
CC__StdCall:				'__stdcall';
Continue:					'continue';
Class:						'class';
Const:						'const';
Else:						'else';
Enum:						'enum';
FaMain:						'FaMain';
For:						'for';
If:							'if';
Interface:					'interface';
Internal:					'internal';
New:						'new';
Public:						'public';
Protected:					'protected';
Private:					'private';
Return:						'return';
Signed:						'signed';
Static:						'static';
Step:						'step';
Struct:						'struct';
Unsigned:					'unsigned';
Use:						'use';
While:						'while';



//
// element
//

// 赋值运算
Assign:						'=';
addAssign:					AddOp Assign;
subAssign:					SubOp Assign;
starAssign:					StarOp Assign;
divAssign:					DivOp Assign;
modAssign:					ModOp Assign;
orAssign:					OrOp Assign;
andAssign:					AndOp Assign;
xorAssign:					XorOp Assign;
qusQusAssign:				qusQusOp Assign;
starStarAssign:				starStarOp Assign;
andAndAssign:				andAndOp Assign;
orOrAssign:					orOrOp Assign;
shiftLAssign:				shiftLOp Assign;
shiftRAssign:				shiftROp Assign;
allAssign:					Assign | qusQusAssign | addAssign | subAssign | starAssign | starStarAssign | divAssign | modAssign | andAssign | orAssign | xorAssign | andAndAssign | orOrAssign | shiftLAssign | shiftRAssign;

// 一元计算
ReverseOp:					'~';
AddAddOp:					'++';
SubSubOp:					'--';

// 二元计算
PointPoint:					'..';
PointOp:					'.';
AddOp:						'+';
SubOp:						'-';
StarOp:						'*';
DivOp:						'/';
ModOp:						'%';
OrOp:						'|';
AndOp:						'&';
XorOp:						'^';
qusQusOp:					Qus Qus;
starStarOp:					StarOp StarOp;
andAndOp:					AndOp AndOp;
orOrOp:						OrOp OrOp;
shiftLOp:					QuotJianL QuotJianL;
shiftROp:					QuotJianR QuotJianR;

// 三元或其他
Qus:						'?';
Comma:						',';
ColonColon:					'::';
Colon:						':';
Semi:						';';
Exclam:						'!';

// 括号
QuotFangL:					'[';
QuotFangR:					']';
QuotJianL:					'<';
QuotJianR:					'>';
QuotHuaL:					'{';
QuotHuaR:					'}';
QuotYuanL:					'(';
QuotYuanR:					')';

// 比较   TODO
ltOp:						QuotJianL;
ltEqualOp:					QuotJianL Assign;
gtOp:						QuotJianR;
gtEqualOp:					QuotJianR Assign;
equalOp:					Assign Assign;
notEqualOp:					Exclam Assign;
exprFuncDef:				Assign QuotJianR;


selfOp2:					AddOp | SubOp | StarOp | DivOp | starStarOp | ModOp | AndOp | OrOp | XorOp | andAndOp | orOrOp | shiftLOp | shiftROp;
compareOp2:					ltOp | ltEqualOp | gtOp | gtEqualOp | equalOp | notEqualOp;
changeOp2:					qusQusOp | compareOp2;
allOp2:						selfOp2 | changeOp2;



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
intNum:						SubOp? IntLiteral;
FloatLiteral:				NUM+ PointOp NUM+;
floatNum:					SubOp? FloatLiteral;
String1Literal:				'"' Schar* '"';
literal:					BoolLiteral | intNum | floatNum | String1Literal;

fragment NUM:				[0-9];
fragment HEX:				NUM | [a-fA-F];
fragment ID_BEGIN:			[a-zA-Z_] | ('\\u' HEX HEX HEX HEX);
fragment ID_AFTER:			NUM | [a-zA-Z_] | ('\\u' HEX HEX HEX HEX);
Id:							ID_BEGIN ID_AFTER*;
ids:						Id (PointOp Id)*;



//
// type
//
typeAfter:					(QuotFangL QuotFangR) | AndOp | Qus | (QuotJianL type (Comma type)* QuotJianR) | StarOp;
type:						(Id | (QuotYuanL type (Comma type)+ QuotYuanR)) typeAfter*;
typeNewable:				Id typeAfter*;
//eTypeAfter:					(QuotFangL QuotFangR) | AndOp | StarOp;
//eSign:						Signed | Unsigned;
//eType:						Const? eSign? Id eTypeAfter*;					// int[]&



//
// list
//
typeVar:					type Id?;
typeVarList:				typeVar (Comma typeVar)*;
//eTypeVar:					eType Id?;
//eTypeVarList:				eTypeVar (Comma eTypeVar)*;



//
// if
//
quotStmtPart:				QuotHuaL stmt* QuotHuaR;
quotStmtExpr:				QuotHuaL stmt* expr QuotHuaR;
ifStmt:						If expr quotStmtPart (Else If expr quotStmtPart)* (Else quotStmtPart)?;
ifExpr:						If expr quotStmtExpr (Else If expr quotStmtExpr)* Else quotStmtExpr;



//
// loop
//
whileStmt:					While expr QuotHuaL stmt* QuotHuaR;
numIterStmt:				For Id Colon exprOpt (Colon exprOpt)+ QuotHuaL stmt* QuotHuaR;



//
// expr
//
quotExpr:					QuotYuanL expr QuotYuanR;
exprOpt:					expr?;
newExprItem:				Id (Assign middleExpr)?;
newExpr:					New ids? QuotHuaL (newExprItem (Comma newExprItem)*)? QuotHuaR;
newArray:					New ids? QuotFangL middleExpr QuotFangR;
arrayExpr1:					QuotFangL expr PointPoint expr (Step expr)? QuotFangR;
arrayExpr2:					QuotFangL expr (Comma expr)* QuotFangR;
strongExprBase:				(ColonColon? Id) | literal | ifExpr | quotExpr | newExpr | newArray | arrayExpr1 | arrayExpr2;
strongExprPrefix:			SubOp | AddAddOp | SubSubOp | ReverseOp;										// 前缀 - ++ -- ~
strongExprSuffix			: AddAddOp | SubSubOp															// 后缀 ++ --
							| (QuotYuanL (exprOpt (Comma exprOpt)*) QuotYuanR)								//     Write ("")
							| (QuotFangL (exprOpt (Colon exprOpt)*) QuotFangR)								//     list [12]
							| (PointOp Id)																	//     wnd.Name
							;
strongExpr:					strongExprPrefix* strongExprBase strongExprSuffix*;
middleExpr:					strongExpr (allOp2 strongExpr)*;												//      a == 24    a + b - c
expr:						middleExpr (allAssign middleExpr)*;



//
// define variable
//
tmpAssignExpr:				Assign expr Semi;
defVarStmt:					type Id Assign expr Semi;



//
// stmt
//
useStmt:					Use ids Semi;
normalStmt:					((Return? expr?) | Break | Continue) Semi;
stmt:						normalStmt | ifStmt | defVarStmt | whileStmt | numIterStmt;



//
// class
//
publicLevel:				Public | Internal | Protected | Private;
classParent:				Colon ids (Comma ids)*;
classType:					Class | Struct | Interface | Enum;
classStmt:					publicLevel? classType Id classParent? QuotHuaL enumAtom* (classVar | classFunc)* QuotHuaR;
							// classParent 由 class 和 struct 专属使用
							// enumItems 由 enum 专属使用
							// enum 的 classVar 不允许使用
//
classVarExtFunc:			publicLevel? Id (Semi | classFuncBody);
classVarExt:				QuotHuaL classVarExtFunc+ QuotHuaR tmpAssignExpr?;
classVar:					publicLevel? Static? type Id (Semi | tmpAssignExpr | classVarExt);
//
classFuncName:				Id | (QuotFangL QuotFangR) | allOp2 | allAssign;
classFuncBody:				(exprFuncDef expr Semi) | (QuotHuaL stmt* QuotHuaR);
classFunc:					publicLevel? Static? type classFuncName QuotYuanL typeVarList? QuotYuanR classFuncBody;
//
enumAtom:					type? Id Comma;



//
// import
//
callConvention:				CC__Cdecl | CC__FastCall | CC__StdCall;
importStmt:					AImport type callConvention Id QuotYuanL typeVarList QuotYuanR Semi;
libStmt:					ALib String1Literal Semi;
importBlock:				(importStmt | libStmt)+;



//
// fa_entry_main
//
faMainFuncBlock:			type FaMain QuotYuanL QuotYuanR QuotHuaL stmt* QuotHuaR;
program:					useStmt* importBlock? classStmt* faMainFuncBlock?;



//
// skips
//
Comment1:					'/*' .*? '*/' -> channel (HIDDEN);
Comment2:					'//' ~ [\r\n]* -> channel (HIDDEN);
WS:							[ \t\r\n]+ -> channel (HIDDEN);

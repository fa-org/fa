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
Do:							'do';
Else:						'else';
Enum:						'enum';
FaMain:						'FaMain';
For:						'for';
If:							'if';
Interface:					'interface';
Internal:					'internal';
Mut:						'mut';
Namespace:					'namespace';
New:						'new';
Params:						'params';
Public:						'public';
Protected:					'protected';
Private:					'private';
Return:						'return';
Signed:						'signed';
Static:						'static';
Step:						'step';
Switch:						'switch';
Unsigned:					'unsigned';
Use:						'use';
When:						'when';
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
Exclam:						'!';

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
Underline:					'_';

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
//fragment ID_BEGIN:			[a-zA-Z_] | ('\\u' HEX HEX HEX HEX);
//fragment ID_AFTER:			NUM | [a-zA-Z_] | ('\\u' HEX HEX HEX HEX);
RawId:						('@' | [a-zA-Z_] | ('\\u' HEX HEX HEX HEX)) (NUM | [a-zA-Z_] | ('\\u' HEX HEX HEX HEX))*;
id:							Underline | RawId;
ids:						id (PointOp id)*;



//
// type
//
typeAfter:					(QuotFangL QuotFangR) | Qus;
typeSingle:					id (QuotJianL type (Comma type)* QuotJianR)?;
typeMulti:					QuotYuanL typeVar (Comma typeVar)+ QuotYuanR;
type:						(Mut | Params)? (typeSingle | typeMulti) typeAfter*;



//
// list
//
typeVar:					type id?;
typeVarList:				typeVar (Comma typeVar)*;
//eTypeVar:					eType id?;
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
whileStmt2:					Do QuotHuaL stmt* QuotHuaR While expr;
forStmt:					For stmt expr Semi (expr (Comma expr)*)? QuotHuaL stmt* QuotHuaR;
forStmt2:					For type id Colon expr QuotHuaL stmt* QuotHuaR;



//
// switch
//
switchStmtPart2Last:		Underline exprFuncDef stmt;
quotStmtExprWrap:			quotStmtExpr | expr;
switchExprPartLast:			Underline exprFuncDef quotStmtExprWrap Comma;
//
switchStmtPart:				expr (When expr)? exprFuncDef stmt;
switchStmt:					Switch expr QuotHuaL switchStmtPart* QuotHuaR;
switchStmtPart2:			When expr exprFuncDef stmt;
switchStmt2:				Switch QuotHuaL switchStmtPart2* switchStmtPart2Last QuotHuaR;
//
switchExprPart:				expr (When expr)? exprFuncDef quotStmtExprWrap Comma;
switchExpr:					Switch expr QuotHuaL switchExprPart* switchExprPartLast QuotHuaR;
switchExprPart2:			When expr exprFuncDef quotStmtExprWrap Comma;
switchExpr2:				Switch QuotHuaL switchExprPart2* switchExprPartLast QuotHuaR;



//
// expr
//
quotExpr:					QuotYuanL expr QuotYuanR;
exprOpt:					expr?;
newExprItem:				id (Assign middleExpr)?;
newExpr1:					New ids? QuotHuaL (newExprItem (Comma newExprItem)*)? QuotHuaR;
newExpr2:					New ids? QuotYuanL (expr (Comma expr)*)? QuotYuanR;
//newArray:					New ids? QuotFangL middleExpr QuotFangR;
arrayExpr1:					QuotFangL expr PointPoint expr (Step expr)? QuotFangR;
arrayExpr2:					QuotFangL expr (Comma expr)* QuotFangR;
strongExprBase:				(ColonColon? id) | literal | ifExpr | quotExpr | newExpr1 | newExpr2 | arrayExpr1 | arrayExpr2 | switchExpr2 | switchExpr;
strongExprPrefix:			SubOp | AddAddOp | SubSubOp | ReverseOp | Exclam;								// 前缀 - ++ -- ~ !
strongExprSuffix			: AddAddOp | SubSubOp															// 后缀 ++ --
							| (QuotYuanL (expr (Comma expr)*)? QuotYuanR)									//     Write ("")
							| (QuotFangL (exprOpt (Colon exprOpt)*) QuotFangR)								//     list [12]
							| (PointOp id)																	//     wnd.Name
							;
strongExpr:					strongExprPrefix* strongExprBase strongExprSuffix*;
middleExpr:					strongExpr (allOp2 strongExpr)*;												//     a == 24    a + b - c
expr:						middleExpr ((Qus strongExprBase Colon strongExprBase) | (allAssign middleExpr)*);



//
// define variable
//
tmpAssignExpr:				Assign middleExpr Semi;
defVarStmt:					type id Assign expr Semi;



//
// stmt
//
normalStmt:					((Return? expr?) | Break | Continue) Semi;
stmt:						ifStmt | whileStmt | whileStmt2 | forStmt | forStmt2 | quotStmtPart | switchStmt2 | switchStmt | normalStmt | defVarStmt;



//
// class
//
publicLevel:				Public | Internal | Protected | Private;
classParent:				Colon ids (Comma ids)*;
classType:					Class | Interface;
//classVariant:				QuotJianL id (Comma id)* QuotJianR;
enumStmt:					publicLevel? Enum id QuotHuaL (classEnumItem (Comma classEnumItem)* Comma?)? QuotHuaR;
classStmt:					publicLevel? classType id classParent? QuotHuaL (classVar | classFunc)* QuotHuaR;
							// classParent 由 class 和 struct 专属使用
							// enumItems 由 enum 专属使用
							// enum 的 classVar 不允许使用
//
classVarExtFunc:			publicLevel? id (Semi | classFuncBody);
classVarExt:				QuotHuaL classVarExtFunc+ QuotHuaR tmpAssignExpr?;
classVar:					publicLevel? Static? type id (Semi | tmpAssignExpr | classVarExt);
//
classFuncName:				id ((QuotFangL QuotFangR) | allOp2 | allAssign)?;
classFuncBody:				(exprFuncDef expr Semi) | (QuotHuaL stmt* QuotHuaR);
classFunc:					publicLevel? Static? type classFuncName QuotYuanL typeVarList? QuotYuanR classFuncBody;
//
classEnumItem:				id (QuotYuanL type QuotYuanR)?;



//
// file headers
//
useStmt:					Use ids Semi;
callConvention:				CC__Cdecl | CC__FastCall | CC__StdCall;
importStmt:					AImport type callConvention id QuotYuanL typeVarList QuotYuanR Semi;
libStmt:					ALib String1Literal Semi;
namespaceStmt:				Namespace ids;



//
// fa_entry_main
//
program:					(useStmt | importStmt | libStmt | namespaceStmt)* (enumStmt | classStmt)*;



//
// skips
//
Comment1:					'/*' .*? '*/' -> channel (HIDDEN);
Comment2:					'//' ~ [\r\n]* -> channel (HIDDEN);
WS:							[ \t\r\n]+ -> channel (HIDDEN);

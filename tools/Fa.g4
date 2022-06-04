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
For:						'for';
If:							'if';
Is:							'is';
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
Var:						'var';
When:						'when';
While:						'while';



//
// element
//

// 赋值运算
Assign:						'=';
AddAssign:					AddOp Assign;
SubAssign:					SubOp Assign;
StarAssign:					StarOp Assign;
DivAssign:					DivOp Assign;
ModAssign:					ModOp Assign;
OrAssign:					OrOp Assign;
AndAssign:					AndOp Assign;
XorAssign:					XorOp Assign;
QusQusAssign:				QusQusOp Assign;
StarStarAssign:				StarStarOp Assign;
AndAndAssign:				AndAndOp Assign;
OrOrAssign:					OrOrOp Assign;
shiftLAssign:				shiftLOp Assign; // 可能是
shiftRAssign:				shiftROp Assign;
allAssign:					Assign | QusQusAssign | AddAssign | SubAssign | StarAssign | StarStarAssign | DivAssign | ModAssign | AndAssign | OrAssign | XorAssign | AndAndAssign | OrOrAssign | shiftLAssign | shiftRAssign;

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
QusQusOp:					Qus Qus;
StarStarOp:					StarOp StarOp;
AndAndOp:					AndOp AndOp;
OrOrOp:						OrOp OrOp;
shiftLOp:					qJianL qJianL;
shiftROp:					qJianR qJianR;

// 三元或其他
Qus:						'?';
Comma:						',';
ColonColon:					'::';
Colon:						':';
Lf:							'\n';
Semi:						';';
Underline:					'_';
endl:						(Lf | Semi)+;
endl2:						(Lf | Comma)+;

// 括号
qFangL:						'[';
qFangR:						']';
qJianL:						'<';
qJianR:						'>';
qHuaL:						'{';
qHuaR:						'}';
qYuanL:						'(';
qYuanR:						')';
quotFangL:					qFangL endl?;
quotFangR:					endl? qFangR;
quotJianL:					qJianL endl?;
quotJianR:					endl? qJianR;
quotHuaL:					qHuaL endl?;
quotHuaR:					endl? qHuaR;
quotYuanL:					qYuanL endl?;
quotYuanR:					endl? qYuanR;

// 比较   TODO
ltOp:						qJianL;
ltEqualOp:					qJianL Assign;
gtOp:						qJianR;
gtEqualOp:					qJianR Assign;
equalOp:					Assign Assign;
notEqualOp:					Exclam Assign;
exprFuncDef:				Assign qJianR;


selfOp2:					AddOp | SubOp | StarOp | DivOp | StarStarOp | ModOp | AndOp | OrOp | XorOp | AndAndOp | OrOrOp | shiftLOp | shiftROp;
compareOp2:					ltOp | ltEqualOp | gtOp | gtEqualOp | equalOp | notEqualOp;
changeOp2:					QusQusOp | compareOp2;
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
fragment ID_BEGIN:			[a-zA-Z@] | [\u0080-\u{10FFFF}];
fragment ID_AFTER:			NUM | [a-zA-Z_] | [\u0080-\u{10FFFF}];
RawId:						(ID_BEGIN ID_AFTER*) | ('_' ID_AFTER+);
id:							Underline | RawId;
ids:						id (PointOp id)*;



//
// type
//
typeAfter:					(quotFangL quotFangR) | Qus;
typeSingle:					ids (quotJianL type (Comma type)* quotJianR)?;
typeMulti:					quotYuanL typeVar (Comma typeVar)+ quotYuanR;
type:						(typeSingle | typeMulti) typeAfter*;
typeWrap:					(Mut | Params)? type;



//
// list
//
typeVar:					type id?;
typeVarList:				typeVar (Comma typeVar)*;
typeWrapVar1:				id Colon typeWrap;
typeWrapVarList1:			typeWrapVar1 (Comma typeWrapVar1)*;
typeWrapVar2:				typeWrap id?;
typeWrapVarList2:			typeWrapVar2 (Comma typeWrapVar2)*;
typeWrapVar3:				typeWrap? id;
typeWrapVarList3:			typeWrapVar3 (Comma typeWrapVar3)*;
//eTypeVar:					eType id?;
//eTypeVarList:				eTypeVar (Comma eTypeVar)*;



//
// if
//
quotStmtPart:				quotHuaL stmt* quotHuaR;
quotStmtExpr:				quotHuaL stmt* expr quotHuaR;
ifStmt:						If expr quotStmtPart (Else If expr quotStmtPart)* (Else quotStmtPart)?;
ifExpr:						If expr quotStmtExpr (Else If expr quotStmtExpr)* Else quotStmtExpr;



//
// loop
//
whileStmt:					While expr quotHuaL stmt* quotHuaR;
whileStmt2:					Do quotHuaL stmt* quotHuaR While expr;
forStmt:					For stmt expr Semi (expr (Comma expr)*)? quotHuaL stmt* quotHuaR;
forStmt2:					For type id Colon expr quotHuaL stmt* quotHuaR;



//
// switch
//
switchStmtPart2Last:		Underline exprFuncDef stmt;
quotStmtExprWrap:			quotStmtExpr | expr;
switchExprPartLast:			Underline exprFuncDef quotStmtExprWrap Comma;
//
switchStmtPart:				expr (When expr)? exprFuncDef stmt;
switchStmt:					Switch expr quotHuaL switchStmtPart* quotHuaR;
switchStmtPart2:			When expr exprFuncDef stmt;
switchStmt2:				Switch quotHuaL switchStmtPart2* switchStmtPart2Last quotHuaR;
//
switchExprPart:				expr (When expr)? exprFuncDef quotStmtExprWrap Comma;
switchExpr:					Switch expr quotHuaL switchExprPart* switchExprPartLast quotHuaR;
switchExprPart2:			When expr exprFuncDef quotStmtExprWrap Comma;
switchExpr2:				Switch quotHuaL switchExprPart2* switchExprPartLast quotHuaR;



//
// expr
//
quotExpr:					quotYuanL expr quotYuanR;
exprOpt:					expr?;
newExprItem:				id (Assign middleExpr)?;
newExpr1:					New typeSingle quotHuaL (newExprItem (Comma newExprItem)*)? quotHuaR;
newExpr2:					New typeSingle quotYuanL (expr (Comma expr)*)? quotYuanR;
//newArray:					New typeSingle quotFangL middleExpr quotFangR;
arrayExpr1:					quotFangL expr PointPoint expr (Step expr)? quotFangR;
arrayExpr2:					quotFangL expr (Comma expr)* quotFangR;
lambdaExpr:					quotYuanL typeWrapVarList3? quotYuanR exprFuncDef (expr | (quotHuaL stmt* quotHuaR));
strongExprBase:				(ColonColon? ids) | literal | ifExpr | quotExpr | newExpr1 | newExpr2 | arrayExpr1 | arrayExpr2 | switchExpr2 | switchExpr | lambdaExpr;
strongExprPrefix:			SubOp | AddAddOp | SubSubOp | ReverseOp | Exclam;								// 前缀 - ++ -- ~ !
strongExprSuffix			: AddAddOp | SubSubOp															// 后缀 ++ --
							| (quotYuanL (expr (Comma expr)*)? quotYuanR)									//     Write ("")
							| (quotFangL (exprOpt (Colon exprOpt)*) quotFangR)								//     list [12]
							| (PointOp id)																	//     wnd.Name
							| (Is ids (quotYuanL id quotYuanR)?)											//     _a is EnumA (_val)
							;
strongExpr:					strongExprPrefix* strongExprBase strongExprSuffix*;
middleExpr:					strongExpr (allOp2 strongExpr)*;												//     a == 24    a + b - c
//expr:						middleExpr ((Qus strongExprBase Colon strongExprBase) | (allAssign middleExpr)*); // 放弃三目运算符?:
expr:						middleExpr (allAssign middleExpr)*;



//
// define variable
//
idAssignExpr:				id (Colon type)? Assign expr;
defVarStmt:					Var idAssignExpr (Comma idAssignExpr)* endl;
idAssignExpr2:				id Assign expr;
defVarStmt2:				type idAssignExpr2 (Comma idAssignExpr2)* endl;



//
// stmt
//
normalStmt:					((Return? expr?) | Break | Continue) endl;
stmt:						ifStmt | whileStmt | whileStmt2 | forStmt | forStmt2 | quotStmtPart | switchStmt2 | switchStmt | defVarStmt | defVarStmt2 | normalStmt;



//
// class
//
publicLevel:				Public | Internal | Protected | Private;
//classTemplates:				quotJianL id (Comma id)* quotJianR;
//classParent:				Colon ids (Comma ids)*;
classItemFuncExtBody:		(exprFuncDef expr Semi) | (quotHuaL stmt* quotHuaR);
//
classItemVar:				publicLevel? Static? id Colon type (Assign middleExpr)? endl;
classItemFunc:				publicLevel? Static? id quotYuanL typeWrapVarList1? quotYuanR Colon type classItemFuncExtBody endl;
classBlock:					publicLevel? Class id quotHuaL (classItemVar | classItemFunc)* quotHuaR endl;
classItemFuncExt2:			quotYuanL typeWrapVarList2? quotYuanR classItemFuncExtBody;
classItem2:					publicLevel? Static? type id classItemFuncExt2? endl;
classBlock2:				publicLevel? Class id quotHuaL classItem2* quotHuaR endl;
//
enumItem:					id (quotYuanL type (Comma type)* quotYuanR) endl2?;
enumBlock:					publicLevel? Enum id quotHuaL enumItem+ classItemFunc* quotHuaR endl;
enumBlock2:					publicLevel? Enum id quotHuaL enumItem+ classItem2* quotHuaR endl;



//
// file
//
useStmt:					Use (id Assign)? ids endl;
callConvention:				CC__Cdecl | CC__FastCall | CC__StdCall;
importStmt:					AImport type callConvention id quotYuanL typeVarList quotYuanR endl;
libStmt:					ALib String1Literal endl;
namespaceStmt:				Namespace ids endl;
program:					(useStmt | importStmt | libStmt)* namespaceStmt? (enumBlock | enumBlock2 | classBlock | classBlock2)*;



//
// entry
//
programEntry:				program EOF;
//classFuncItemEntry:			classFuncItem EOF;
//typeEntry:					type EOF;



//
// skips
//
Comment1:					'/*' .*? '*/' -> channel (HIDDEN);
Comment2:					'//' ~ [\n]* -> channel (HIDDEN);
WS:							[ \t\r]+ -> channel (HIDDEN);

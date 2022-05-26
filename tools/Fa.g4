// C++�﷨
// https://github.com/antlr/grammars-v4/blob/master/cpp/CPP14Lexer.g4
// https://github.com/antlr/grammars-v4/blob/master/cpp/CPP14Parser.g4

// ANTLR�ĵ�
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
When:						'when';
While:						'while';



//
// element
//

// ��ֵ����
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
shiftLAssign:				shiftLOp Assign; // ������
shiftRAssign:				shiftROp Assign;
allAssign:					Assign | QusQusAssign | AddAssign | SubAssign | StarAssign | StarStarAssign | DivAssign | ModAssign | AndAssign | OrAssign | XorAssign | AndAndAssign | OrOrAssign | shiftLAssign | shiftRAssign;

// һԪ����
ReverseOp:					'~';
AddAddOp:					'++';
SubSubOp:					'--';
Exclam:						'!';

// ��Ԫ����
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
shiftLOp:					quotJianL quotJianL;
shiftROp:					quotJianR quotJianR;

// ��Ԫ������
Qus:						'?';
Comma:						',';
ColonColon:					'::';
Colon:						':';
NewLine:					'\n';
Semi:						';';
Underline:					'_';
endStmt:					(NewLine | Semi)+;
endStmt2:					(NewLine | Comma)+;

// ����
quotFangL:					'[' endStmt?;
quotFangR:					endStmt? ']';
quotJianL:					'<' endStmt?;
quotJianR:					endStmt? '>';
quotHuaL:					'{' endStmt?;
quotHuaR:					endStmt? '}';
quotYuanL:					'(' endStmt?;
quotYuanR:					endStmt? ')';

// �Ƚ�   TODO
ltOp:						quotJianL;
ltEqualOp:					quotJianL Assign;
gtOp:						quotJianR;
gtEqualOp:					quotJianR Assign;
equalOp:					Assign Assign;
notEqualOp:					Exclam Assign;
exprFuncDef:				Assign quotJianR;


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
fragment ID_BEGIN:			[a-zA-Z_@] | ('\\u' HEX HEX HEX HEX);
fragment ID_AFTER:			NUM | [a-zA-Z_] | ('\\u' HEX HEX HEX HEX);
RawId:						ID_BEGIN ID_AFTER*;
id:							Underline | RawId;
ids:						id (PointOp id)*;
idExt:						ids quotJianL type (Comma type)* quotJianR PointOp id;



//
// type
//
typeAfter:					(quotFangL quotFangR) | Qus;
typeSingle:					ids (quotJianL typeWrap (Comma typeWrap)* quotJianR)?;
typeMulti:					quotYuanL typeVar (Comma typeVar)+ quotYuanR;
type:						(typeSingle | typeMulti) typeAfter*;
typeWrap:					(Mut | Params)? type;



//
// list
//
typeVar:					type id?;
typeVarList:				typeVar (Comma typeVar)*;
typeWrapVar:				typeWrap id?;
typeWrapVarList:			typeWrapVar (Comma typeWrapVar)*;
typeWrapVar2:				typeWrap? id;
typeWrapVar2List:			typeWrapVar2 (Comma typeWrapVar2)*;
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
lambdaExpr:					quotYuanL typeWrapVar2List? quotYuanR exprFuncDef (expr | (quotHuaL stmt* quotHuaR));
strongExprBase:				(ColonColon? id) | literal | ifExpr | quotExpr | newExpr1 | newExpr2 | arrayExpr1 | arrayExpr2 | switchExpr2 | switchExpr | lambdaExpr | idExt;
strongExprPrefix:			SubOp | AddAddOp | SubSubOp | ReverseOp | Exclam;								// ǰ׺ - ++ -- ~ !
strongExprSuffix			: AddAddOp | SubSubOp															// ��׺ ++ --
							| (quotYuanL (expr (Comma expr)*)? quotYuanR)									//     Write ("")
							| (quotFangL (exprOpt (Colon exprOpt)*) quotFangR)								//     list [12]
							| (PointOp id)																	//     wnd.Name
							| (Is ids (quotYuanL id quotYuanR)?)											//     _a is EnumA (_val)
							;
strongExpr:					strongExprPrefix* strongExprBase strongExprSuffix*;
middleExpr:					strongExpr (allOp2 strongExpr)*;												//     a == 24    a + b - c
//expr:						middleExpr ((Qus strongExprBase Colon strongExprBase) | (allAssign middleExpr)*); // ������Ŀ�����?:
expr:						middleExpr (allAssign middleExpr)*;



//
// define variable
//
tmpAssignExpr:				Assign middleExpr endStmt;
idAssignExpr:				id Assign expr;
defVarStmt:					type idAssignExpr (Comma idAssignExpr)* endStmt;



//
// stmt
//
normalStmt:					((Return? expr?) | Break | Continue) endStmt;
stmt:						ifStmt | whileStmt | whileStmt2 | forStmt | forStmt2 | quotStmtPart | switchStmt2 | switchStmt | defVarStmt | normalStmt;



//
// class
//
publicLevel:				Public | Internal | Protected | Private;
//classTemplates:				quotJianL id (Comma id)* quotJianR;
//classParent:				Colon ids (Comma ids)*;
//
enumItem:					id (quotYuanL type (Comma type)* quotYuanR) endStmt2?;
classItemFuncExtBody:		(exprFuncDef expr Semi) | (quotHuaL stmt* quotHuaR);
classItemFuncExt:			quotYuanL typeWrapVarList? quotYuanR classItemFuncExtBody;
classItem:					publicLevel? Static? type id classItemFuncExt? endStmt;
//
enumBlock:					publicLevel? Enum id quotHuaL enumItem+ classItem* quotHuaR endStmt;
classBlock:					publicLevel? Class id quotHuaL classItem* quotHuaR endStmt;



//
// file
//
useStmt:					Use ids endStmt;
callConvention:				CC__Cdecl | CC__FastCall | CC__StdCall;
importStmt:					AImport type callConvention id quotYuanL typeVarList quotYuanR endStmt;
libStmt:					ALib String1Literal endStmt;
namespaceStmt:				Namespace ids endStmt;
program:					(useStmt | importStmt | libStmt)* namespaceStmt? (enumBlock | classBlock)*;



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
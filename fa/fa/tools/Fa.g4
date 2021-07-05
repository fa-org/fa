// C++Óï·¨
// https://github.com/antlr/grammars-v4/blob/master/cpp/CPP14Lexer.g4
// https://github.com/antlr/grammars-v4/blob/master/cpp/CPP14Parser.g4

// ANTLRÎÄµµ
// https://decaf-lang.github.io/minidecaf-tutorial/
// https://wizardforcel.gitbooks.io/antlr4-short-course/content/

grammar Fa;



//
// keyword
//
CC__Cdecl:				'__cdecl';
CC__FastCall:			'__fastcall';
CC__StdCall:			'__stdcall';
Class:					'class';
Const:					'const';
Extern:					'extern';
FaEntryMain:			'FaEntryMain';
Internal:				'internal';
Public:					'public';
Protected:				'protected';
Private:				'private';
Return:					'return';
Static:					'static';
Use:					'use';
Volatile:				'volatile';



//
// element
//
fragment HEX:			[0-9a-fA-F];
fragment ID_BEGIN:		[a-zA-Z_] | ('\\u' HEX HEX HEX HEX);
fragment ID_AFTER:		[a-zA-Z0-9_] | ('\\u' HEX HEX HEX HEX);
Id:						ID_BEGIN ID_AFTER*;
ids:					Id ('.' Id)*;
QuotFangL:				'[';
QuotFangR:				']';
QuotJianL:				'<';
QuotJianR:				'>';
QuotHuaL:				'{';
QuotHuaR:				'}';
QuotYuanL:				'(';
QuotYuanR:				')';
BitAnd:					'&';
BitOr:					'|';
BitXor:					'^';
Comma:					',';
Colon:					':';
Semi:					';';
Star:					'*';
publicLevel:			Public | Internal | Protected | Private;



//
// value
//
Num:					[0-9]+;



//
// type
//
typeBefore:				Const | Volatile;
typeAfter:				(QuotFangL QuotFangR) | BitAnd;
type:					typeBefore? ( Id
						| (Id QuotJianL type (Comma type)* QuotJianR)	// Lazy<int>
						| (QuotYuanL type (Comma type)+ QuotYuanR)		// (int, string)
						) typeAfter*;									// int[]&
eTypeBefore:			Const;
eTypeAfter:				(QuotFangL QuotFangR) | BitAnd | Star;
eType:					eTypeBefore? Id eTypeAfter*;						// int[]&



//
// expr
//
typeVar:				type Id?;
typeVarList:			typeVar (Comma typeVar)*;
eTypeVar:				eType Id?;
eTypeVarList:			eTypeVar (Comma eTypeVar)*;



//
// stmt
//
useStmt:				Use ids Semi;
returnStmt:				Return Semi;



//
// class
//
classParent:			Colon ids (Comma ids)*;
//
classItemExpr:			publicLevel? Static? Id Id;
classItemFieldStmt:		classItemExpr Semi;
classItemFuncStmt:		classItemExpr QuotYuanL typeVarList QuotYuanR QuotHuaL QuotHuaR;
classStmt:				publicLevel? Class Id classParent? QuotHuaL (classItemFieldStmt | classItemFuncStmt)* QuotHuaR;



//
// extern
//
callConvention:			CC__Cdecl | CC__FastCall | CC__StdCall;
externStmt:				Extern eType callConvention Id QuotYuanL eTypeVarList QuotYuanR Semi;



//
// fa_entry_main
//
faEntryMainFuncStmt:	Static type FaEntryMain QuotYuanL QuotYuanR QuotHuaL QuotHuaR;
program:				useStmt* externStmt* classStmt* faEntryMainFuncStmt?;



//
// skips
//
Comment1:				'/*' .*? '*/' -> skip;
Comment2:				'//' ~ [\r\n]* -> skip;
WS:						[ \t\r\n]+ -> skip;

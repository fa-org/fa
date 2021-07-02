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
Class:					'class';
PublicLevel:			'public' | 'internal' | 'protected' | 'private';
Return:					'return';
Static:					'static';
Use:					'use';



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



//
// value
//
Num:					[0-9]+;



//
// type
//
typeAfter:				(QuotFangL QuotFangR) | BitAnd;
typeExpr				: (Id
						| (Id QuotJianL typeExpr (Comma typeExpr)* QuotJianR)	// Lazy<int>
						| (QuotYuanL typeExpr (Comma typeExpr)+ QuotYuanR)		// (int, string)
						) typeAfter*;											// int[]&



//
// expr
//



//
// stmt
//
useStmt:				Use ids Semi;
returnStmt:				Return Semi;


//
// class
//
classParent:			Colon ids (Comma ids)*;
typeVar:				typeExpr Id;
typeVarList:			typeVar (Comma typeVar)*;
//
classItemExpr:			PublicLevel? Static? Id Id;
classItemFieldStmt:		classItemExpr Semi;
classItemFuncStmt:		classItemExpr QuotYuanL typeVarList QuotYuanR QuotHuaL QuotHuaR;
classStmt:				PublicLevel? Class Id classParent? QuotHuaL (classItemFieldStmt | classItemFuncStmt)* QuotHuaR;
program:				useStmt* classStmt*;



//
// skips
//
Comment1:				'/*' .*? '*/' -> skip;
Comment2:				'//' ~ [\r\n]* -> skip;
WS:						[ \t\r\n]+ -> skip;

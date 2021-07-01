grammar Fa;



//
// element
//
fragment HEX:			[0-9a-fA-F];
fragment ID_BEGIN:		[a-zA-Z_] | ('\\u' HEX HEX HEX HEX);
fragment ID_AFTER:		[a-zA-Z0-9_] | ('\\u' HEX HEX HEX HEX);
ID:						ID_BEGIN ID_AFTER*;
IDs:					ID ('.' ID)+;



//
// expr
//
useExpr:				'use' (ID | IDs) ';';
//classItemExpr:
//classExpr:				'class'
program:				useExpr*;



//
// skips
//
Comment1:				'/*' .*? '*/' -> skip;
Comment2:				'//' ~ [\r\n]* -> skip;
WS:						[ \t\r\n]+ -> skip;

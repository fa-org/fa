grammar Fa;

s					: 'hello' ID*;
ID					: [a-z]+;
WS					: [ \t\r\n]+ -> skip;

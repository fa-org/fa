// C++语法
// https://github.com/antlr/grammars-v4/blob/master/cpp/CPP14Lexer.g4
// https://github.com/antlr/grammars-v4/blob/master/cpp/CPP14Parser.g4

// ANTLR文档
// https://decaf-lang.github.io/minidecaf-tutorial/
// https://wizardforcel.gitbooks.io/antlr4-short-course/content/

parser grammar FaParser;

options { tokenVocab=FaLexer; }



//
// element
//

// 赋值运算
shiftLAssignOp:				shiftLOp AssignOp;
shiftRAssignOp:				shiftROp AssignOp;
allAssignOp:				AssignOp | QusQusAssignOp | AddAssignOp | SubAssignOp | StarAssignOp | StarStarAssignOp | DivAssignOp | ModAssignOp | AndAssignOp | OrAssignOp | XorAssignOp | AndAndAssignOp | OrOrAssignOp | shiftLAssignOp | shiftRAssignOp;

// 一元计算

// 二元计算
shiftLOp:					LessThan LessThan;
shiftROp:					GreatThan GreatThan;

// 三元或其他
endl:						(Lf | Semi)+;
endl2:						Lf* Comma Lf*;

// 括号
quotFangL:					QFangL endl?;
quotFangR:					endl? QFangR;
quotJianL:					LessThan endl?;
quotJianR:					endl? GreatThan;
quotHuaL:					QHuaL endl?;
quotHuaR:					endl? QHuaR;
quotYuanL:					QYuanL endl?;
quotYuanR:					endl? QYuanR;

selfOp2:					AddOp | SubOp | StarOp | DivOp | StarStarOp | ModOp | AndOp | OrOp | XorOp | AndAndOp | OrOrOp | shiftLOp | shiftROp;
compareOp2:					LessThan | LtEqualOp | GreatThan | GtEqualOp | EqualOp | NotEqualOp;
changeOp2:					QusQusOp | compareOp2;
allOp2:						selfOp2 | changeOp2;



//
// Literal
//
intNum:						SubOp? IntLiteral;
floatNum:					SubOp? FloatLiteral;
formatString1Part:			(middleExpr (Colon FormatString)?) | QHuaLQHuaL | QHuaRQHuaR | RegularCharInside | RegularStringInside;
formatString1:				FmtString1 formatString1Part* DoubleQuoteInside;
formatString2Part:			(middleExpr Colon FormatString) | QHuaLQHuaL | QHuaRQHuaR | VerbatiumDoubleQuoteInside | VerbatiumInsideString;
formatString2:				FmtString2 formatString2Part* DoubleQuoteInside;
stringLiteral:				String1Literal | String2Literal | String3Literal | formatString1 | formatString2;
literal:					BoolLiteral | HexLiteral | intNum | floatNum | stringLiteral;
//
ids:						Id (PointOp Id)*;


0
//
// type
//
typeAfter:					(quotFangL quotFangR) | Dollar? Qus | Qus? Dollar | (ColonColon (Base | IntLiteral)) | (quotJianL types quotJianR);
typeTuple:					quotYuanL typeVar (Comma typeVar)+ quotYuanR;
types:						type (Comma type)*;
type:						(ids | typeTuple | Type) typeAfter*;



//
// list
//
argAttr:					Mut | Params | Disperse;
typeVar:					type Id?;
typeVarList:				typeVar (Comma typeVar)*;
typeWrapVar1:				argAttr? Id Colon type;
typeWrapVarList1:			typeWrapVar1 (Comma typeWrapVar1)*;
typeWrapVar2:				argAttr? type Id?;
typeWrapVarList2:			typeWrapVar2 (Comma typeWrapVar2)*;
typeWrapVar3:				(argAttr? type)? Id;
typeWrapVarList3:			typeWrapVar3 (Comma typeWrapVar3)*;
typeWrapVar4:				argAttr? Id (Colon type)?;
typeWrapVarList4:			typeWrapVar4 (Comma typeWrapVar4)*;



//
// if
//
quotStmtPart:				quotHuaL stmt* quotHuaR;
ifStmt:						If middleExpr quotStmtPart (Else If middleExpr quotStmtPart)* (Else quotStmtPart)? endl;
quotStmtExpr:				quotHuaL stmt* expr quotHuaR;
ifExpr:						If middleExpr quotStmtExpr (Else If middleExpr quotStmtExpr)* Else quotStmtExpr;



//
// loop
//
whileStmt:					While middleExpr quotHuaL stmt* quotHuaR endl;
whileStmt2:					Do quotHuaL stmt* quotHuaR While middleExpr endl;
forHeader1:					(Var | type) (Id | (quotYuanL Id (Comma Id)* quotYuanR)) Colon middleExpr;
forHeader2:					(defVarStmtPart | defVarStmt2Part) Semi middleExpr Semi expr;
forHeader:					forHeader1 | forHeader2;
forStmt:					For (forHeader | (quotYuanL forHeader quotYuanR)) quotHuaL stmt* quotHuaR endl;



//
// switch
//
switchStmtPart2Last:		Underline ExprFuncDef stmt;
quotStmtExprWrap:			quotStmtExpr | expr;
switchExprPartLast:			Underline ExprFuncDef quotStmtExprWrap endl2?;
//
switchStmtPart:				expr (When expr)? ExprFuncDef stmt;
switchStmt:					Switch expr quotHuaL switchStmtPart* quotHuaR endl;
switchStmtPart2:			When expr ExprFuncDef stmt;
switchStmt2:				Switch quotHuaL switchStmtPart2* switchStmtPart2Last quotHuaR endl;
//
switchExprPart:				expr (When expr)? ExprFuncDef quotStmtExprWrap endl2;
switchExpr1:				SwitchExpr expr quotHuaL switchExprPart* switchExprPartLast quotHuaR;
switchExprPart2:			When expr ExprFuncDef quotStmtExprWrap endl2;
switchExpr2:				SwitchExpr quotHuaL switchExprPart2* switchExprPartLast quotHuaR;



//
// expr
//
quotExpr:					quotYuanL expr quotYuanR;
tupleExprItem:				(Id Colon)? middleExpr;
tupleExpr:					quotYuanL tupleExprItem (Comma | (Comma tupleExprItem)+) quotYuanR;
exprOpt:					expr?;
newExprItem:				Id (AssignOp middleExpr)?;
newExpr1:					New type? quotHuaL (newExprItem (Comma newExprItem)*)? quotHuaR;
newExpr2:					New type? quotYuanL (middleExpr (Comma middleExpr)*)? quotYuanR;
arrayExpr1Cond:				(Where middleExpr);
arrayExpr1:					quotFangL From (Id | (quotYuanL Id (Comma Id)* quotYuanR)) In middleExpr arrayExpr1Cond* (Select | Run) middleExpr quotFangR;
arrayExpr2:					quotFangL (middleExpr (Comma middleExpr)*)? quotFangR;
arrayExpr3:					quotFangL middleExpr (Comma middleExpr)? PointPoint middleExpr quotFangR;
lambdaExpr:					Id | (quotYuanL (typeWrapVarList3 | typeWrapVarList4)? quotYuanR) ExprFuncDef (middleExpr | (quotHuaL stmt* quotHuaR));
strongExprBase:				(ColonColon? ids) | literal | lambdaExpr
							| quotExpr | tupleExpr | newExpr1 | newExpr2
							| arrayExpr1 | arrayExpr2 | arrayExpr3;
strongExprPrefix:			SubOp | AddAddOp | SubSubOp | ReverseOp | Exclam | (Cast (quotJianL type quotJianR)?);	// 前缀 - ++ -- ~ ! cast<>
strongExprSuffix:			AddAddOp | SubSubOp																// 后缀 ++ --
							| (quotYuanL (middleExpr (endl2 middleExpr)*)? quotYuanR)						//     Write ("")
							| (quotFangL (exprOpt (Colon exprOpt)*) quotFangR)								//     list [12]
							| (quotJianL type (Comma type)* quotJianR)										//     wnd<T>
							| (PointOp Id)																	//     wnd.Name
							| (Qus PointOp Id)																//     wnd?.Name
							| (Is type Id?)																	//     _a is EnumA (_val)
							;
strongExpr:					strongExprPrefix* strongExprBase strongExprSuffix*;
middle3OpExpr:				strongExpr Qus strongExpr Colon strongExpr;
middle2OpExpr:				strongExpr (allOp2 strongExpr)*;
middleAstExpr:				(Stmt normalStmtPart) | (Expr middle2OpExpr);
middleExpr:					Calc? (middle3OpExpr | middle2OpExpr | middleAstExpr);							//     a == 24    a + b - c
expr:						((strongExpr allAssignOp)+ (ifExpr | switchExpr2 | switchExpr1 | middleExpr)) | middleExpr;



//
// define variable
//
idAssignOpExpr:				Id (Colon type)? AssignOp middleExpr;
defVarStmtPart:				Var idAssignOpExpr (Comma idAssignOpExpr)*;
idAssignOpExpr2:			Id AssignOp middleExpr;
defVarStmt2Part:			type idAssignOpExpr2 (Comma idAssignOpExpr2)*;



//
// define type
//
defTypeStmt:				Type Id AssignOp type (OrOrOp type)* endl;



//
// stmt
//
normalStmtPart:				(Return? expr) | Return | Break | Continue | defVarStmtPart | defVarStmt2Part;
normalStmt:					normalStmtPart endl;
stmt:						ifStmt | whileStmt | whileStmt2 | forStmt | (quotStmtPart endl) | switchStmt2 | switchStmt | normalStmt;



//
// blocks base
//
publicLevel:				Public | Internal | Protected | Private;
blockTemplates:				quotJianL Id (Comma Id)* quotJianR;
itemName:					Id | (Operator (allOp2 | (QFangL QFangR)));
typeNameTuple:				(itemName Colon type) | (type itemName);
typeNameArgsTuple:			(itemName blockTemplates? quotYuanL typeWrapVarList1? quotYuanR Colon type) | (type itemName blockTemplates? quotYuanL typeWrapVarList2? quotYuanR);
nameArgsTuple:				Id quotYuanL (typeWrapVarList1 | typeWrapVarList2)? quotYuanR;
funcBody:					(ExprFuncDef expr) | (quotHuaL stmt* quotHuaR);
//classParent:				Colon ids (Comma ids)*;



//
// annotation
//
annoArg:					Id AssignOp middleExpr;
annoPart:					Id (quotHuaL ((annoArg endl2)* annoArg)? quotHuaR)? endl;
annoBlock:					annoPart* Annotation Id quotHuaL (classVar | classFunc)* quotHuaR endl;



//
// class
//
importedConstructFunc:		annoPart* publicLevel? nameArgsTuple endl;
varAccesser:				publicLevel? (Get | Set) funcBody?;
varAccesserItems:			varAccesser (endl varAccesser)*;
//
classVar:					annoPart* publicLevel? Static? typeNameTuple (quotHuaL varAccesserItems quotHuaR)? (AssignOp middleExpr)? endl;
classFunc:					annoPart* publicLevel? Static? typeNameArgsTuple funcBody? endl;
classBlock:					annoPart* publicLevel? Class Id blockTemplates? quotHuaL (classVar | classFunc | importedConstructFunc)* quotHuaR endl;
//
enumItem:					annoPart* Id (quotYuanL type quotYuanR)?;
enumBlock:					annoPart* publicLevel? Enum Id blockTemplates? quotHuaL ((enumItem endl2)* enumItem endl2?) quotHuaR endl;



//
// file
//
useStmt:					Use (Id AssignOp)? ids endl;
//callConvention:			CC__Cdecl | CC__FastCall | CC__StdCall;
//importStmt:				AImport type callConvention Id quotYuanL typeVarList quotYuanR endl;
//libStmt:					ALib String1Literal endl;
namespaceStmt:				Namespace ids endl;
program:					endl* useStmt* namespaceStmt? (defTypeStmt| annoBlock | enumBlock | classBlock)*;



//
// entry
//
programEntry:				program EOF;
//classFuncEntry:				classFunc EOF;
//typeEntry:					type EOF;
//exprEntry:					expr EOF;

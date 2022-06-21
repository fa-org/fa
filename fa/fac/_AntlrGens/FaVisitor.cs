//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     ANTLR Version: 4.9.3
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

// Generated from Fa.g4 by ANTLR 4.9.3

// Unreachable code detected
#pragma warning disable 0162
// The variable '...' is assigned but its value is never used
#pragma warning disable 0219
// Missing XML comment for publicly visible type or member '...'
#pragma warning disable 1591
// Ambiguous reference in cref attribute
#pragma warning disable 419

using Antlr4.Runtime.Misc;
using Antlr4.Runtime.Tree;
using IToken = Antlr4.Runtime.IToken;

/// <summary>
/// This interface defines a complete generic visitor for a parse tree produced
/// by <see cref="FaParser"/>.
/// </summary>
/// <typeparam name="Result">The return type of the visit operation.</typeparam>
[System.CodeDom.Compiler.GeneratedCode("ANTLR", "4.9.3")]
[System.CLSCompliant(false)]
public interface IFaVisitor<Result> : IParseTreeVisitor<Result> {
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.shiftLAssign"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitShiftLAssign([NotNull] FaParser.ShiftLAssignContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.shiftRAssign"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitShiftRAssign([NotNull] FaParser.ShiftRAssignContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.allAssign"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitAllAssign([NotNull] FaParser.AllAssignContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.shiftLOp"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitShiftLOp([NotNull] FaParser.ShiftLOpContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.shiftROp"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitShiftROp([NotNull] FaParser.ShiftROpContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.endl"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitEndl([NotNull] FaParser.EndlContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.endl2"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitEndl2([NotNull] FaParser.Endl2Context context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.qFangL"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitQFangL([NotNull] FaParser.QFangLContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.qFangR"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitQFangR([NotNull] FaParser.QFangRContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.qJianL"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitQJianL([NotNull] FaParser.QJianLContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.qJianR"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitQJianR([NotNull] FaParser.QJianRContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.qHuaL"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitQHuaL([NotNull] FaParser.QHuaLContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.qHuaR"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitQHuaR([NotNull] FaParser.QHuaRContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.qYuanL"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitQYuanL([NotNull] FaParser.QYuanLContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.qYuanR"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitQYuanR([NotNull] FaParser.QYuanRContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.quotFangL"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitQuotFangL([NotNull] FaParser.QuotFangLContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.quotFangR"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitQuotFangR([NotNull] FaParser.QuotFangRContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.quotJianL"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitQuotJianL([NotNull] FaParser.QuotJianLContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.quotJianR"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitQuotJianR([NotNull] FaParser.QuotJianRContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.quotHuaL"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitQuotHuaL([NotNull] FaParser.QuotHuaLContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.quotHuaR"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitQuotHuaR([NotNull] FaParser.QuotHuaRContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.quotYuanL"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitQuotYuanL([NotNull] FaParser.QuotYuanLContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.quotYuanR"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitQuotYuanR([NotNull] FaParser.QuotYuanRContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.ltOp"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitLtOp([NotNull] FaParser.LtOpContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.ltEqualOp"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitLtEqualOp([NotNull] FaParser.LtEqualOpContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.gtOp"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitGtOp([NotNull] FaParser.GtOpContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.gtEqualOp"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitGtEqualOp([NotNull] FaParser.GtEqualOpContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.equalOp"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitEqualOp([NotNull] FaParser.EqualOpContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.notEqualOp"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitNotEqualOp([NotNull] FaParser.NotEqualOpContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.exprFuncDef"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitExprFuncDef([NotNull] FaParser.ExprFuncDefContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.selfOp2"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitSelfOp2([NotNull] FaParser.SelfOp2Context context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.compareOp2"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitCompareOp2([NotNull] FaParser.CompareOp2Context context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.changeOp2"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitChangeOp2([NotNull] FaParser.ChangeOp2Context context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.allOp2"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitAllOp2([NotNull] FaParser.AllOp2Context context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.intNum"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitIntNum([NotNull] FaParser.IntNumContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.floatNum"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitFloatNum([NotNull] FaParser.FloatNumContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.literal"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitLiteral([NotNull] FaParser.LiteralContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.id"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitId([NotNull] FaParser.IdContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.ids"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitIds([NotNull] FaParser.IdsContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.typeAfter"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitTypeAfter([NotNull] FaParser.TypeAfterContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.typeSingle"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitTypeSingle([NotNull] FaParser.TypeSingleContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.typeMulti"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitTypeMulti([NotNull] FaParser.TypeMultiContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.type"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitType([NotNull] FaParser.TypeContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.typeWrap"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitTypeWrap([NotNull] FaParser.TypeWrapContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.typeVar"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitTypeVar([NotNull] FaParser.TypeVarContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.typeVarList"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitTypeVarList([NotNull] FaParser.TypeVarListContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.typeWrapVar1"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitTypeWrapVar1([NotNull] FaParser.TypeWrapVar1Context context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.typeWrapVarList1"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitTypeWrapVarList1([NotNull] FaParser.TypeWrapVarList1Context context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.typeWrapVar2"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitTypeWrapVar2([NotNull] FaParser.TypeWrapVar2Context context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.typeWrapVarList2"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitTypeWrapVarList2([NotNull] FaParser.TypeWrapVarList2Context context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.typeWrapVar3"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitTypeWrapVar3([NotNull] FaParser.TypeWrapVar3Context context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.typeWrapVarList3"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitTypeWrapVarList3([NotNull] FaParser.TypeWrapVarList3Context context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.quotStmtPart"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitQuotStmtPart([NotNull] FaParser.QuotStmtPartContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.quotStmtExpr"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitQuotStmtExpr([NotNull] FaParser.QuotStmtExprContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.ifStmt"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitIfStmt([NotNull] FaParser.IfStmtContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.ifExpr"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitIfExpr([NotNull] FaParser.IfExprContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.whileStmt"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitWhileStmt([NotNull] FaParser.WhileStmtContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.whileStmt2"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitWhileStmt2([NotNull] FaParser.WhileStmt2Context context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.forStmt"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitForStmt([NotNull] FaParser.ForStmtContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.forStmt2"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitForStmt2([NotNull] FaParser.ForStmt2Context context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.switchStmtPart2Last"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitSwitchStmtPart2Last([NotNull] FaParser.SwitchStmtPart2LastContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.quotStmtExprWrap"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitQuotStmtExprWrap([NotNull] FaParser.QuotStmtExprWrapContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.switchExprPartLast"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitSwitchExprPartLast([NotNull] FaParser.SwitchExprPartLastContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.switchStmtPart"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitSwitchStmtPart([NotNull] FaParser.SwitchStmtPartContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.switchStmt"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitSwitchStmt([NotNull] FaParser.SwitchStmtContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.switchStmtPart2"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitSwitchStmtPart2([NotNull] FaParser.SwitchStmtPart2Context context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.switchStmt2"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitSwitchStmt2([NotNull] FaParser.SwitchStmt2Context context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.switchExprPart"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitSwitchExprPart([NotNull] FaParser.SwitchExprPartContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.switchExpr"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitSwitchExpr([NotNull] FaParser.SwitchExprContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.switchExprPart2"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitSwitchExprPart2([NotNull] FaParser.SwitchExprPart2Context context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.switchExpr2"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitSwitchExpr2([NotNull] FaParser.SwitchExpr2Context context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.quotExpr"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitQuotExpr([NotNull] FaParser.QuotExprContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.exprOpt"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitExprOpt([NotNull] FaParser.ExprOptContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.newExprItem"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitNewExprItem([NotNull] FaParser.NewExprItemContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.newExpr1"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitNewExpr1([NotNull] FaParser.NewExpr1Context context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.newExpr2"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitNewExpr2([NotNull] FaParser.NewExpr2Context context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.arrayExpr1"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitArrayExpr1([NotNull] FaParser.ArrayExpr1Context context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.arrayExpr2"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitArrayExpr2([NotNull] FaParser.ArrayExpr2Context context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.lambdaExpr"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitLambdaExpr([NotNull] FaParser.LambdaExprContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.strongExprBase"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitStrongExprBase([NotNull] FaParser.StrongExprBaseContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.strongExprPrefix"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitStrongExprPrefix([NotNull] FaParser.StrongExprPrefixContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.strongExprSuffix"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitStrongExprSuffix([NotNull] FaParser.StrongExprSuffixContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.strongExpr"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitStrongExpr([NotNull] FaParser.StrongExprContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.middleExpr"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitMiddleExpr([NotNull] FaParser.MiddleExprContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.expr"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitExpr([NotNull] FaParser.ExprContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.idAssignExpr"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitIdAssignExpr([NotNull] FaParser.IdAssignExprContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.defVarStmt"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitDefVarStmt([NotNull] FaParser.DefVarStmtContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.idAssignExpr2"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitIdAssignExpr2([NotNull] FaParser.IdAssignExpr2Context context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.defVarStmt2"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitDefVarStmt2([NotNull] FaParser.DefVarStmt2Context context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.normalStmt"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitNormalStmt([NotNull] FaParser.NormalStmtContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.stmt"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitStmt([NotNull] FaParser.StmtContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.publicLevel"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitPublicLevel([NotNull] FaParser.PublicLevelContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.blockTemplates"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitBlockTemplates([NotNull] FaParser.BlockTemplatesContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.itemName"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitItemName([NotNull] FaParser.ItemNameContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.typeNameTuple"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitTypeNameTuple([NotNull] FaParser.TypeNameTupleContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.typeNameArgsTuple"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitTypeNameArgsTuple([NotNull] FaParser.TypeNameArgsTupleContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.funcBody"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitFuncBody([NotNull] FaParser.FuncBodyContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.annoBlock"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitAnnoBlock([NotNull] FaParser.AnnoBlockContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.annoArg"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitAnnoArg([NotNull] FaParser.AnnoArgContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.annoUsingPart"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitAnnoUsingPart([NotNull] FaParser.AnnoUsingPartContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.interfaceItemFunc"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitInterfaceItemFunc([NotNull] FaParser.InterfaceItemFuncContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.interfaceBlock"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitInterfaceBlock([NotNull] FaParser.InterfaceBlockContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.classItemVar"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitClassItemVar([NotNull] FaParser.ClassItemVarContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.classItemFunc"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitClassItemFunc([NotNull] FaParser.ClassItemFuncContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.classBlock"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitClassBlock([NotNull] FaParser.ClassBlockContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.enumItem"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitEnumItem([NotNull] FaParser.EnumItemContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.enumBlock"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitEnumBlock([NotNull] FaParser.EnumBlockContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.useStmt"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitUseStmt([NotNull] FaParser.UseStmtContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.namespaceStmt"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitNamespaceStmt([NotNull] FaParser.NamespaceStmtContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.program"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitProgram([NotNull] FaParser.ProgramContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.programEntry"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitProgramEntry([NotNull] FaParser.ProgramEntryContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.classItemFuncEntry"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitClassItemFuncEntry([NotNull] FaParser.ClassItemFuncEntryContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="FaParser.typeEntry"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitTypeEntry([NotNull] FaParser.TypeEntryContext context);
}

﻿using Antlr4.Runtime.Misc;
using Antlr4.Runtime.Tree;
using fac.ASTs;
using fac.ASTs.Structs;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.AntlrTools {
	public class FaVisitorImpl: IFaVisitor<IAst> {
		public IAst Visit (IParseTree tree) => tree.Accept (this);
		public IAst VisitChildren (IRuleNode node) {
			for (int i = 0; i < node.ChildCount; ++i) {
				try {
					var _child = node.GetChild (i);
					return _child.Accept (this);
				} catch (NotImplementedException) {
				}
			} throw new NotImplementedException ();
		}
		public IAst VisitProgramEntry (FaParser.ProgramEntryContext _ctx) => new AstProgram (_ctx.program ());
		public IAst VisitTypeEntry (FaParser.TypeEntryContext _ctx) => IAstType.FromContext (_ctx.type ());
		public IAst VisitShiftLAssign (FaParser.ShiftLAssignContext _ctx) => throw new NotImplementedException ();
		public IAst VisitShiftRAssign (FaParser.ShiftRAssignContext _ctx) => throw new NotImplementedException ();
		public IAst VisitAllAssign (FaParser.AllAssignContext _ctx) => throw new NotImplementedException ();
		public IAst VisitShiftLOp (FaParser.ShiftLOpContext _ctx) => throw new NotImplementedException ();
		public IAst VisitShiftROp (FaParser.ShiftROpContext _ctx) => throw new NotImplementedException ();
		public IAst VisitLtOp (FaParser.LtOpContext _ctx) => throw new NotImplementedException ();
		public IAst VisitLtEqualOp (FaParser.LtEqualOpContext _ctx) => throw new NotImplementedException ();
		public IAst VisitGtOp (FaParser.GtOpContext _ctx) => throw new NotImplementedException ();
		public IAst VisitGtEqualOp (FaParser.GtEqualOpContext _ctx) => throw new NotImplementedException ();
		public IAst VisitEqualOp (FaParser.EqualOpContext _ctx) => throw new NotImplementedException ();
		public IAst VisitNotEqualOp (FaParser.NotEqualOpContext _ctx) => throw new NotImplementedException ();
		public IAst VisitExprFuncDef (FaParser.ExprFuncDefContext _ctx) => throw new NotImplementedException ();
		public IAst VisitSelfOp2 (FaParser.SelfOp2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitCompareOp2 (FaParser.CompareOp2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitChangeOp2 (FaParser.ChangeOp2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitAllOp2 (FaParser.AllOp2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitIntNum (FaParser.IntNumContext _ctx) => throw new NotImplementedException ();
		public IAst VisitFloatNum (FaParser.FloatNumContext _ctx) => throw new NotImplementedException ();
		public IAst VisitLiteral (FaParser.LiteralContext _ctx) => throw new NotImplementedException ();
		public IAst VisitId (FaParser.IdContext _ctx) => throw new NotImplementedException ();
		public IAst VisitIds (FaParser.IdsContext _ctx) => throw new NotImplementedException ();
		//public IAst VisitIdExt (FaParser.IdExtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitTypeAfter (FaParser.TypeAfterContext _ctx) => throw new NotImplementedException ();
		public IAst VisitTypeSingle (FaParser.TypeSingleContext _ctx) => throw new NotImplementedException ();
		public IAst VisitTypeMulti (FaParser.TypeMultiContext _ctx) => throw new NotImplementedException ();
		public IAst VisitType (FaParser.TypeContext _ctx) => throw new NotImplementedException ();
		public IAst VisitTypeWrap (FaParser.TypeWrapContext _ctx) => throw new NotImplementedException ();
		public IAst VisitTypeVar (FaParser.TypeVarContext _ctx) => throw new NotImplementedException ();
		public IAst VisitTypeVarList (FaParser.TypeVarListContext _ctx) => throw new NotImplementedException ();
		public IAst VisitTypeVar2 (FaParser.TypeWrapVar2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitTypeWrapVar2 (FaParser.TypeWrapVar2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitQuotStmtPart (FaParser.QuotStmtPartContext _ctx) => throw new NotImplementedException ();
		public IAst VisitQuotStmtExpr (FaParser.QuotStmtExprContext _ctx) => throw new NotImplementedException ();
		public IAst VisitIfStmt (FaParser.IfStmtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitIfExpr (FaParser.IfExprContext _ctx) => throw new NotImplementedException ();
		public IAst VisitWhileStmt (FaParser.WhileStmtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitWhileStmt2 (FaParser.WhileStmt2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitForStmt (FaParser.ForStmtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitForStmt2 (FaParser.ForStmt2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitSwitchStmtPart2Last (FaParser.SwitchStmtPart2LastContext _ctx) => throw new NotImplementedException ();
		public IAst VisitQuotStmtExprWrap (FaParser.QuotStmtExprWrapContext _ctx) => throw new NotImplementedException ();
		public IAst VisitSwitchExprPartLast (FaParser.SwitchExprPartLastContext _ctx) => throw new NotImplementedException ();
		public IAst VisitSwitchStmtPart (FaParser.SwitchStmtPartContext _ctx) => throw new NotImplementedException ();
		public IAst VisitSwitchStmt (FaParser.SwitchStmtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitSwitchStmtPart2 (FaParser.SwitchStmtPart2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitSwitchStmt2 (FaParser.SwitchStmt2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitSwitchExprPart (FaParser.SwitchExprPartContext _ctx) => throw new NotImplementedException ();
		public IAst VisitSwitchExpr (FaParser.SwitchExprContext _ctx) => throw new NotImplementedException ();
		public IAst VisitSwitchExprPart2 (FaParser.SwitchExprPart2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitSwitchExpr2 (FaParser.SwitchExpr2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitQuotExpr (FaParser.QuotExprContext _ctx) => throw new NotImplementedException ();
		public IAst VisitExprOpt (FaParser.ExprOptContext _ctx) => throw new NotImplementedException ();
		public IAst VisitNewExprItem (FaParser.NewExprItemContext _ctx) => throw new NotImplementedException ();
		public IAst VisitNewExpr1 (FaParser.NewExpr1Context _ctx) => throw new NotImplementedException ();
		public IAst VisitNewExpr2 (FaParser.NewExpr2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitArrayExpr1 (FaParser.ArrayExpr1Context _ctx) => throw new NotImplementedException ();
		public IAst VisitArrayExpr2 (FaParser.ArrayExpr2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitLambdaExpr (FaParser.LambdaExprContext _ctx) => throw new NotImplementedException ();
		public IAst VisitStrongExprBase (FaParser.StrongExprBaseContext _ctx) => throw new NotImplementedException ();
		public IAst VisitStrongExprPrefix (FaParser.StrongExprPrefixContext _ctx) => throw new NotImplementedException ();
		public IAst VisitStrongExprSuffix (FaParser.StrongExprSuffixContext _ctx) => throw new NotImplementedException ();
		public IAst VisitStrongExpr (FaParser.StrongExprContext _ctx) => throw new NotImplementedException ();
		public IAst VisitMiddleExpr (FaParser.MiddleExprContext _ctx) => throw new NotImplementedException ();
		public IAst VisitExpr (FaParser.ExprContext _ctx) => throw new NotImplementedException ();
		public IAst VisitIdAssignExpr (FaParser.IdAssignExprContext _ctx) => throw new NotImplementedException ();
		public IAst VisitDefVarStmt (FaParser.DefVarStmtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitNormalStmt (FaParser.NormalStmtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitStmt (FaParser.StmtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitPublicLevel (FaParser.PublicLevelContext _ctx) => throw new NotImplementedException ();
		public IAst VisitUseStmt (FaParser.UseStmtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitCallConvention (FaParser.CallConventionContext _ctx) => throw new NotImplementedException ();
		public IAst VisitImportStmt (FaParser.ImportStmtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitLibStmt (FaParser.LibStmtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitNamespaceStmt (FaParser.NamespaceStmtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitProgram (FaParser.ProgramContext _ctx) => throw new NotImplementedException ();
		public IAst VisitTerminal (ITerminalNode node) => throw new NotImplementedException ();
		public IAst VisitErrorNode (IErrorNode node) => throw new NotImplementedException ();

		public IAst VisitEndl (FaParser.EndlContext _ctx) => throw new NotImplementedException ();
		public IAst VisitEndl2 (FaParser.Endl2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitQFangL (FaParser.QFangLContext _ctx) => throw new NotImplementedException ();
		public IAst VisitQFangR (FaParser.QFangRContext _ctx) => throw new NotImplementedException ();
		public IAst VisitQJianL (FaParser.QJianLContext _ctx) => throw new NotImplementedException ();
		public IAst VisitQJianR (FaParser.QJianRContext _ctx) => throw new NotImplementedException ();
		public IAst VisitQHuaL (FaParser.QHuaLContext _ctx) => throw new NotImplementedException ();
		public IAst VisitQHuaR (FaParser.QHuaRContext _ctx) => throw new NotImplementedException ();
		public IAst VisitQYuanL (FaParser.QYuanLContext _ctx) => throw new NotImplementedException ();
		public IAst VisitQYuanR (FaParser.QYuanRContext _ctx) => throw new NotImplementedException ();
		public IAst VisitQuotFangL (FaParser.QuotFangLContext _ctx) => throw new NotImplementedException ();
		public IAst VisitQuotFangR (FaParser.QuotFangRContext _ctx) => throw new NotImplementedException ();
		public IAst VisitQuotJianL (FaParser.QuotJianLContext _ctx) => throw new NotImplementedException ();
		public IAst VisitQuotJianR (FaParser.QuotJianRContext _ctx) => throw new NotImplementedException ();
		public IAst VisitQuotHuaL (FaParser.QuotHuaLContext _ctx) => throw new NotImplementedException ();
		public IAst VisitQuotHuaR (FaParser.QuotHuaRContext _ctx) => throw new NotImplementedException ();
		public IAst VisitQuotYuanL (FaParser.QuotYuanLContext _ctx) => throw new NotImplementedException ();
		public IAst VisitQuotYuanR (FaParser.QuotYuanRContext _ctx) => throw new NotImplementedException ();
		public IAst VisitTypeWrapVar1 (FaParser.TypeWrapVar1Context _ctx) => throw new NotImplementedException ();
		public IAst VisitTypeWrapVarList1 (FaParser.TypeWrapVarList1Context _ctx) => throw new NotImplementedException ();
		public IAst VisitTypeWrapVarList2 (FaParser.TypeWrapVarList2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitTypeWrapVar3 (FaParser.TypeWrapVar3Context _ctx) => throw new NotImplementedException ();
		public IAst VisitTypeWrapVarList3 (FaParser.TypeWrapVarList3Context _ctx) => throw new NotImplementedException ();
		public IAst VisitIdAssignExpr2 (FaParser.IdAssignExpr2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitDefVarStmt2 (FaParser.DefVarStmt2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitClassItemFuncExtBody (FaParser.ClassItemFuncExtBodyContext _ctx) => throw new NotImplementedException ();
		public IAst VisitClassItemVar (FaParser.ClassItemVarContext _ctx) => throw new NotImplementedException ();
		public IAst VisitClassItemFunc (FaParser.ClassItemFuncContext _ctx) => throw new NotImplementedException ();
		public IAst VisitClassBlock (FaParser.ClassBlockContext _ctx) => throw new NotImplementedException ();
		public IAst VisitClassItemFuncExt2 (FaParser.ClassItemFuncExt2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitClassItem2 (FaParser.ClassItem2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitClassBlock2 (FaParser.ClassBlock2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitEnumItem (FaParser.EnumItemContext _ctx) => throw new NotImplementedException ();
		public IAst VisitEnumBlock (FaParser.EnumBlockContext _ctx) => throw new NotImplementedException ();
		public IAst VisitEnumBlock2 (FaParser.EnumBlock2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitClassTemplates (FaParser.ClassTemplatesContext _ctx) => throw new NotImplementedException ();

		public IAst VisitClassItemFuncEntry (FaParser.ClassItemFuncEntryContext _ctx) => _ctx.classItemFunc () != null ?
			new AstClassFunc (Info.CurrentClass, _ctx.classItemFunc ()) : new AstClassFunc (Info.CurrentClass, _ctx.classItem2 ());
	}
}

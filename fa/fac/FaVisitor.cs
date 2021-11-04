using Antlr4.Runtime.Misc;
using Antlr4.Runtime.Tree;
using fac.ASTs;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac {
	class FaVisitor: IFaVisitor<IAstNode> {
		public IAstNode Visit (IParseTree tree) => tree.Accept (this);
		public IAstNode VisitChildren (IRuleNode node) {
			for (int i = 0; i < node.ChildCount; ++i) {
				try {
					var _child = node.GetChild (i);
					return _child.Accept (this);
				} catch (NotImplementedException) {
				}
			}
			throw new NotImplementedException ();
		}

		public IAstNode VisitProgram ([NotNull] FaParser.ProgramContext context) => new AstProgram (context);



		public IAstNode VisitAddAssign ([NotNull] FaParser.AddAssignContext context) => throw new NotImplementedException ();
		public IAstNode VisitAllAssign ([NotNull] FaParser.AllAssignContext context) => throw new NotImplementedException ();
		public IAstNode VisitAllOp2 ([NotNull] FaParser.AllOp2Context context) => throw new NotImplementedException ();
		public IAstNode VisitAndAndAssign ([NotNull] FaParser.AndAndAssignContext context) => throw new NotImplementedException ();
		public IAstNode VisitAndAndOp ([NotNull] FaParser.AndAndOpContext context) => throw new NotImplementedException ();
		public IAstNode VisitAndAssign ([NotNull] FaParser.AndAssignContext context) => throw new NotImplementedException ();
		public IAstNode VisitArrayExpr1 ([NotNull] FaParser.ArrayExpr1Context context) => throw new NotImplementedException ();
		public IAstNode VisitArrayExpr2 ([NotNull] FaParser.ArrayExpr2Context context) => throw new NotImplementedException ();
		public IAstNode VisitCallConvention ([NotNull] FaParser.CallConventionContext context) => throw new NotImplementedException ();
		public IAstNode VisitChangeOp2 ([NotNull] FaParser.ChangeOp2Context context) => throw new NotImplementedException ();
		public IAstNode VisitClassFunc ([NotNull] FaParser.ClassFuncContext context) => throw new NotImplementedException ();
		public IAstNode VisitClassFuncBody ([NotNull] FaParser.ClassFuncBodyContext context) => throw new NotImplementedException ();
		public IAstNode VisitClassFuncName ([NotNull] FaParser.ClassFuncNameContext context) => throw new NotImplementedException ();
		public IAstNode VisitClassParent ([NotNull] FaParser.ClassParentContext context) => throw new NotImplementedException ();
		public IAstNode VisitClassStmt ([NotNull] FaParser.ClassStmtContext context) => throw new NotImplementedException ();
		public IAstNode VisitClassType ([NotNull] FaParser.ClassTypeContext context) => throw new NotImplementedException ();
		public IAstNode VisitClassVar ([NotNull] FaParser.ClassVarContext context) => throw new NotImplementedException ();
		public IAstNode VisitClassVarExt ([NotNull] FaParser.ClassVarExtContext context) => throw new NotImplementedException ();
		public IAstNode VisitClassVarExtFunc ([NotNull] FaParser.ClassVarExtFuncContext context) => throw new NotImplementedException ();
		public IAstNode VisitCompareOp2 ([NotNull] FaParser.CompareOp2Context context) => throw new NotImplementedException ();
		public IAstNode VisitDefVarStmt ([NotNull] FaParser.DefVarStmtContext context) => throw new NotImplementedException ();
		public IAstNode VisitDivAssign ([NotNull] FaParser.DivAssignContext context) => throw new NotImplementedException ();
		public IAstNode VisitEnumAtom ([NotNull] FaParser.EnumAtomContext context) => throw new NotImplementedException ();
		public IAstNode VisitEqualOp ([NotNull] FaParser.EqualOpContext context) => throw new NotImplementedException ();
		public IAstNode VisitErrorNode (IErrorNode node) => throw new NotImplementedException ();
		public IAstNode VisitExpr ([NotNull] FaParser.ExprContext context) => throw new NotImplementedException ();
		public IAstNode VisitExprFuncDef ([NotNull] FaParser.ExprFuncDefContext context) => throw new NotImplementedException ();
		public IAstNode VisitExprOpt ([NotNull] FaParser.ExprOptContext context) => throw new NotImplementedException ();
		public IAstNode VisitFaMainFuncBlock ([NotNull] FaParser.FaMainFuncBlockContext context) => throw new NotImplementedException ();
		public IAstNode VisitFloatNum ([NotNull] FaParser.FloatNumContext context) => throw new NotImplementedException ();
		public IAstNode VisitGtEqualOp ([NotNull] FaParser.GtEqualOpContext context) => throw new NotImplementedException ();
		public IAstNode VisitGtOp ([NotNull] FaParser.GtOpContext context) => throw new NotImplementedException ();
		public IAstNode VisitIds ([NotNull] FaParser.IdsContext context) => throw new NotImplementedException ();
		public IAstNode VisitIfExpr ([NotNull] FaParser.IfExprContext context) => throw new NotImplementedException ();
		public IAstNode VisitIfStmt ([NotNull] FaParser.IfStmtContext context) => throw new NotImplementedException ();
		public IAstNode VisitImportStmt ([NotNull] FaParser.ImportStmtContext context) => throw new NotImplementedException ();
		public IAstNode VisitIntNum ([NotNull] FaParser.IntNumContext context) => throw new NotImplementedException ();
		public IAstNode VisitLibStmt ([NotNull] FaParser.LibStmtContext context) => throw new NotImplementedException ();
		public IAstNode VisitLiteral ([NotNull] FaParser.LiteralContext context) => throw new NotImplementedException ();
		public IAstNode VisitLtEqualOp ([NotNull] FaParser.LtEqualOpContext context) => throw new NotImplementedException ();
		public IAstNode VisitLtOp ([NotNull] FaParser.LtOpContext context) => throw new NotImplementedException ();
		public IAstNode VisitMiddleExpr ([NotNull] FaParser.MiddleExprContext context) => throw new NotImplementedException ();
		public IAstNode VisitModAssign ([NotNull] FaParser.ModAssignContext context) => throw new NotImplementedException ();
		public IAstNode VisitNamespaceStmt ([NotNull] FaParser.NamespaceStmtContext context) => throw new NotImplementedException ();
		public IAstNode VisitNewArray ([NotNull] FaParser.NewArrayContext context) => throw new NotImplementedException ();
		public IAstNode VisitNewExpr ([NotNull] FaParser.NewExprContext context) => throw new NotImplementedException ();
		public IAstNode VisitNewExprItem ([NotNull] FaParser.NewExprItemContext context) => throw new NotImplementedException ();
		public IAstNode VisitNormalStmt ([NotNull] FaParser.NormalStmtContext context) => throw new NotImplementedException ();
		public IAstNode VisitNotEqualOp ([NotNull] FaParser.NotEqualOpContext context) => throw new NotImplementedException ();
		public IAstNode VisitNumIterStmt ([NotNull] FaParser.NumIterStmtContext context) => throw new NotImplementedException ();
		public IAstNode VisitOrAssign ([NotNull] FaParser.OrAssignContext context) => throw new NotImplementedException ();
		public IAstNode VisitOrOrAssign ([NotNull] FaParser.OrOrAssignContext context) => throw new NotImplementedException ();
		public IAstNode VisitOrOrOp ([NotNull] FaParser.OrOrOpContext context) => throw new NotImplementedException ();
		public IAstNode VisitPublicLevel ([NotNull] FaParser.PublicLevelContext context) => throw new NotImplementedException ();
		public IAstNode VisitQuotExpr ([NotNull] FaParser.QuotExprContext context) => throw new NotImplementedException ();
		public IAstNode VisitQuotStmtExpr ([NotNull] FaParser.QuotStmtExprContext context) => throw new NotImplementedException ();
		public IAstNode VisitQuotStmtPart ([NotNull] FaParser.QuotStmtPartContext context) => throw new NotImplementedException ();
		public IAstNode VisitQusQusAssign ([NotNull] FaParser.QusQusAssignContext context) => throw new NotImplementedException ();
		public IAstNode VisitQusQusOp ([NotNull] FaParser.QusQusOpContext context) => throw new NotImplementedException ();
		public IAstNode VisitSelfOp2 ([NotNull] FaParser.SelfOp2Context context) => throw new NotImplementedException ();
		public IAstNode VisitShiftLAssign ([NotNull] FaParser.ShiftLAssignContext context) => throw new NotImplementedException ();
		public IAstNode VisitShiftLOp ([NotNull] FaParser.ShiftLOpContext context) => throw new NotImplementedException ();
		public IAstNode VisitShiftRAssign ([NotNull] FaParser.ShiftRAssignContext context) => throw new NotImplementedException ();
		public IAstNode VisitShiftROp ([NotNull] FaParser.ShiftROpContext context) => throw new NotImplementedException ();
		public IAstNode VisitStarAssign ([NotNull] FaParser.StarAssignContext context) => throw new NotImplementedException ();
		public IAstNode VisitStarStarAssign ([NotNull] FaParser.StarStarAssignContext context) => throw new NotImplementedException ();
		public IAstNode VisitStarStarOp ([NotNull] FaParser.StarStarOpContext context) => throw new NotImplementedException ();
		public IAstNode VisitStmt ([NotNull] FaParser.StmtContext context) => throw new NotImplementedException ();
		public IAstNode VisitStrongExpr ([NotNull] FaParser.StrongExprContext context) => throw new NotImplementedException ();
		public IAstNode VisitStrongExprBase ([NotNull] FaParser.StrongExprBaseContext context) => throw new NotImplementedException ();
		public IAstNode VisitStrongExprPrefix ([NotNull] FaParser.StrongExprPrefixContext context) => throw new NotImplementedException ();
		public IAstNode VisitStrongExprSuffix ([NotNull] FaParser.StrongExprSuffixContext context) => throw new NotImplementedException ();
		public IAstNode VisitSubAssign ([NotNull] FaParser.SubAssignContext context) => throw new NotImplementedException ();
		public IAstNode VisitTerminal (ITerminalNode node) => throw new NotImplementedException ();
		public IAstNode VisitTmpAssignExpr ([NotNull] FaParser.TmpAssignExprContext context) => throw new NotImplementedException ();
		public IAstNode VisitType ([NotNull] FaParser.TypeContext context) => throw new NotImplementedException ();
		public IAstNode VisitTypeAfter ([NotNull] FaParser.TypeAfterContext context) => throw new NotImplementedException ();
		public IAstNode VisitTypeNewable ([NotNull] FaParser.TypeNewableContext context) => throw new NotImplementedException ();
		public IAstNode VisitTypeVar ([NotNull] FaParser.TypeVarContext context) => throw new NotImplementedException ();
		public IAstNode VisitTypeVarList ([NotNull] FaParser.TypeVarListContext context) => throw new NotImplementedException ();
		public IAstNode VisitUseStmt ([NotNull] FaParser.UseStmtContext context) => throw new NotImplementedException ();
		public IAstNode VisitWhileStmt ([NotNull] FaParser.WhileStmtContext context) => throw new NotImplementedException ();
		public IAstNode VisitXorAssign ([NotNull] FaParser.XorAssignContext context) => throw new NotImplementedException ();
	}
}

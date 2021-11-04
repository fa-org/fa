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

		public IAstNode VisitProgram ([NotNull] FaParser.ProgramContext _ctx) => new AstProgram (_ctx);
		public IAstNode VisitClassStmt ([NotNull] FaParser.ClassStmtContext _ctx) => new AstClassStmt (_ctx);



		public IAstNode VisitAddAssign ([NotNull] FaParser.AddAssignContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitAllAssign ([NotNull] FaParser.AllAssignContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitAllOp2 ([NotNull] FaParser.AllOp2Context _ctx) => throw new NotImplementedException ();
		public IAstNode VisitAndAndAssign ([NotNull] FaParser.AndAndAssignContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitAndAndOp ([NotNull] FaParser.AndAndOpContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitAndAssign ([NotNull] FaParser.AndAssignContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitArrayExpr1 ([NotNull] FaParser.ArrayExpr1Context _ctx) => throw new NotImplementedException ();
		public IAstNode VisitArrayExpr2 ([NotNull] FaParser.ArrayExpr2Context _ctx) => throw new NotImplementedException ();
		public IAstNode VisitCallConvention ([NotNull] FaParser.CallConventionContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitChangeOp2 ([NotNull] FaParser.ChangeOp2Context _ctx) => throw new NotImplementedException ();
		public IAstNode VisitClassFunc ([NotNull] FaParser.ClassFuncContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitClassFuncBody ([NotNull] FaParser.ClassFuncBodyContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitClassFuncName ([NotNull] FaParser.ClassFuncNameContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitClassParent ([NotNull] FaParser.ClassParentContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitClassType ([NotNull] FaParser.ClassTypeContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitClassVar ([NotNull] FaParser.ClassVarContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitClassVarExt ([NotNull] FaParser.ClassVarExtContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitClassVarExtFunc ([NotNull] FaParser.ClassVarExtFuncContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitCompareOp2 ([NotNull] FaParser.CompareOp2Context _ctx) => throw new NotImplementedException ();
		public IAstNode VisitDefVarStmt ([NotNull] FaParser.DefVarStmtContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitDivAssign ([NotNull] FaParser.DivAssignContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitEnumAtom ([NotNull] FaParser.EnumAtomContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitEqualOp ([NotNull] FaParser.EqualOpContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitErrorNode (IErrorNode node) => throw new NotImplementedException ();
		public IAstNode VisitExpr ([NotNull] FaParser.ExprContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitExprFuncDef ([NotNull] FaParser.ExprFuncDefContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitExprOpt ([NotNull] FaParser.ExprOptContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitFaMainFuncBlock ([NotNull] FaParser.FaMainFuncBlockContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitFloatNum ([NotNull] FaParser.FloatNumContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitGtEqualOp ([NotNull] FaParser.GtEqualOpContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitGtOp ([NotNull] FaParser.GtOpContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitIds ([NotNull] FaParser.IdsContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitIfExpr ([NotNull] FaParser.IfExprContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitIfStmt ([NotNull] FaParser.IfStmtContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitImportStmt ([NotNull] FaParser.ImportStmtContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitIntNum ([NotNull] FaParser.IntNumContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitLibStmt ([NotNull] FaParser.LibStmtContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitLiteral ([NotNull] FaParser.LiteralContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitLtEqualOp ([NotNull] FaParser.LtEqualOpContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitLtOp ([NotNull] FaParser.LtOpContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitMiddleExpr ([NotNull] FaParser.MiddleExprContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitModAssign ([NotNull] FaParser.ModAssignContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitNamespaceStmt ([NotNull] FaParser.NamespaceStmtContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitNewArray ([NotNull] FaParser.NewArrayContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitNewExpr ([NotNull] FaParser.NewExprContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitNewExprItem ([NotNull] FaParser.NewExprItemContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitNormalStmt ([NotNull] FaParser.NormalStmtContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitNotEqualOp ([NotNull] FaParser.NotEqualOpContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitNumIterStmt ([NotNull] FaParser.NumIterStmtContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitOrAssign ([NotNull] FaParser.OrAssignContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitOrOrAssign ([NotNull] FaParser.OrOrAssignContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitOrOrOp ([NotNull] FaParser.OrOrOpContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitPublicLevel ([NotNull] FaParser.PublicLevelContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitQuotExpr ([NotNull] FaParser.QuotExprContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitQuotStmtExpr ([NotNull] FaParser.QuotStmtExprContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitQuotStmtPart ([NotNull] FaParser.QuotStmtPartContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitQusQusAssign ([NotNull] FaParser.QusQusAssignContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitQusQusOp ([NotNull] FaParser.QusQusOpContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitSelfOp2 ([NotNull] FaParser.SelfOp2Context _ctx) => throw new NotImplementedException ();
		public IAstNode VisitShiftLAssign ([NotNull] FaParser.ShiftLAssignContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitShiftLOp ([NotNull] FaParser.ShiftLOpContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitShiftRAssign ([NotNull] FaParser.ShiftRAssignContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitShiftROp ([NotNull] FaParser.ShiftROpContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitStarAssign ([NotNull] FaParser.StarAssignContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitStarStarAssign ([NotNull] FaParser.StarStarAssignContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitStarStarOp ([NotNull] FaParser.StarStarOpContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitStmt ([NotNull] FaParser.StmtContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitStrongExpr ([NotNull] FaParser.StrongExprContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitStrongExprBase ([NotNull] FaParser.StrongExprBaseContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitStrongExprPrefix ([NotNull] FaParser.StrongExprPrefixContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitStrongExprSuffix ([NotNull] FaParser.StrongExprSuffixContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitSubAssign ([NotNull] FaParser.SubAssignContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitTerminal (ITerminalNode node) => throw new NotImplementedException ();
		public IAstNode VisitTmpAssignExpr ([NotNull] FaParser.TmpAssignExprContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitType ([NotNull] FaParser.TypeContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitTypeAfter ([NotNull] FaParser.TypeAfterContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitTypeNewable ([NotNull] FaParser.TypeNewableContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitTypeVar ([NotNull] FaParser.TypeVarContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitTypeVarList ([NotNull] FaParser.TypeVarListContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitUseStmt ([NotNull] FaParser.UseStmtContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitWhileStmt ([NotNull] FaParser.WhileStmtContext _ctx) => throw new NotImplementedException ();
		public IAstNode VisitXorAssign ([NotNull] FaParser.XorAssignContext _ctx) => throw new NotImplementedException ();
	}
}

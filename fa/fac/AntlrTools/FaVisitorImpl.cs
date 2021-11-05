using Antlr4.Runtime.Misc;
using Antlr4.Runtime.Tree;
using fac.ASTs;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.AntlrTools {
	class FaVisitorImpl: IFaVisitor<IAst> {
		public IAst Visit (IParseTree tree) => tree.Accept (this);
		public IAst VisitChildren (IRuleNode node) {
			for (int i = 0; i < node.ChildCount; ++i) {
				try {
					var _child = node.GetChild (i);
					return _child.Accept (this);
				} catch (NotImplementedException) {
				}
			}
			throw new NotImplementedException ();
		}

		public IAst VisitProgram (FaParser.ProgramContext _ctx) => new AstProgram (_ctx);
		public IAst VisitClassStmt (FaParser.ClassStmtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitClassEnumAtom (FaParser.ClassEnumAtomContext _ctx) => throw new NotImplementedException ();
		public IAst VisitClassVar (FaParser.ClassVarContext _ctx) => throw new NotImplementedException ();
		public IAst VisitClassFunc (FaParser.ClassFuncContext _ctx) => throw new NotImplementedException ();
		public IAst VisitAddAssign (FaParser.AddAssignContext _ctx) => throw new NotImplementedException ();
		public IAst VisitAllAssign (FaParser.AllAssignContext _ctx) => throw new NotImplementedException ();
		public IAst VisitAllOp2 (FaParser.AllOp2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitAndAndAssign (FaParser.AndAndAssignContext _ctx) => throw new NotImplementedException ();
		public IAst VisitAndAndOp (FaParser.AndAndOpContext _ctx) => throw new NotImplementedException ();
		public IAst VisitAndAssign (FaParser.AndAssignContext _ctx) => throw new NotImplementedException ();
		public IAst VisitArrayExpr1 (FaParser.ArrayExpr1Context _ctx) => throw new NotImplementedException ();
		public IAst VisitArrayExpr2 (FaParser.ArrayExpr2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitCallConvention (FaParser.CallConventionContext _ctx) => throw new NotImplementedException ();
		public IAst VisitChangeOp2 (FaParser.ChangeOp2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitClassFuncBody (FaParser.ClassFuncBodyContext _ctx) => throw new NotImplementedException ();
		public IAst VisitClassFuncName (FaParser.ClassFuncNameContext _ctx) => throw new NotImplementedException ();
		public IAst VisitClassParent (FaParser.ClassParentContext _ctx) => throw new NotImplementedException ();
		public IAst VisitClassType (FaParser.ClassTypeContext _ctx) => throw new NotImplementedException ();
		public IAst VisitClassVarExt (FaParser.ClassVarExtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitClassVarExtFunc (FaParser.ClassVarExtFuncContext _ctx) => throw new NotImplementedException ();
		public IAst VisitCompareOp2 (FaParser.CompareOp2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitDefVarStmt (FaParser.DefVarStmtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitDivAssign (FaParser.DivAssignContext _ctx) => throw new NotImplementedException ();
		public IAst VisitEqualOp (FaParser.EqualOpContext _ctx) => throw new NotImplementedException ();
		public IAst VisitErrorNode (IErrorNode node) => throw new NotImplementedException ();
		public IAst VisitExpr (FaParser.ExprContext _ctx) => throw new NotImplementedException ();
		public IAst VisitExprFuncDef (FaParser.ExprFuncDefContext _ctx) => throw new NotImplementedException ();
		public IAst VisitExprOpt (FaParser.ExprOptContext _ctx) => throw new NotImplementedException ();
		public IAst VisitFloatNum (FaParser.FloatNumContext _ctx) => throw new NotImplementedException ();
		public IAst VisitGtEqualOp (FaParser.GtEqualOpContext _ctx) => throw new NotImplementedException ();
		public IAst VisitGtOp (FaParser.GtOpContext _ctx) => throw new NotImplementedException ();
		public IAst VisitIds (FaParser.IdsContext _ctx) => throw new NotImplementedException ();
		public IAst VisitIfExpr (FaParser.IfExprContext _ctx) => throw new NotImplementedException ();
		public IAst VisitIfStmt (FaParser.IfStmtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitImportStmt (FaParser.ImportStmtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitIntNum (FaParser.IntNumContext _ctx) => throw new NotImplementedException ();
		public IAst VisitLibStmt (FaParser.LibStmtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitLiteral (FaParser.LiteralContext _ctx) => throw new NotImplementedException ();
		public IAst VisitLtEqualOp (FaParser.LtEqualOpContext _ctx) => throw new NotImplementedException ();
		public IAst VisitLtOp (FaParser.LtOpContext _ctx) => throw new NotImplementedException ();
		public IAst VisitMiddleExpr (FaParser.MiddleExprContext _ctx) => throw new NotImplementedException ();
		public IAst VisitModAssign (FaParser.ModAssignContext _ctx) => throw new NotImplementedException ();
		public IAst VisitNamespaceStmt (FaParser.NamespaceStmtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitNewArray (FaParser.NewArrayContext _ctx) => throw new NotImplementedException ();
		public IAst VisitNewExpr (FaParser.NewExprContext _ctx) => throw new NotImplementedException ();
		public IAst VisitNewExprItem (FaParser.NewExprItemContext _ctx) => throw new NotImplementedException ();
		public IAst VisitNormalStmt (FaParser.NormalStmtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitNotEqualOp (FaParser.NotEqualOpContext _ctx) => throw new NotImplementedException ();
		public IAst VisitNumIterStmt (FaParser.NumIterStmtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitOrAssign (FaParser.OrAssignContext _ctx) => throw new NotImplementedException ();
		public IAst VisitOrOrAssign (FaParser.OrOrAssignContext _ctx) => throw new NotImplementedException ();
		public IAst VisitOrOrOp (FaParser.OrOrOpContext _ctx) => throw new NotImplementedException ();
		public IAst VisitPublicLevel (FaParser.PublicLevelContext _ctx) => throw new NotImplementedException ();
		public IAst VisitQuotExpr (FaParser.QuotExprContext _ctx) => throw new NotImplementedException ();
		public IAst VisitQuotStmtExpr (FaParser.QuotStmtExprContext _ctx) => throw new NotImplementedException ();
		public IAst VisitQuotStmtPart (FaParser.QuotStmtPartContext _ctx) => throw new NotImplementedException ();
		public IAst VisitQusQusAssign (FaParser.QusQusAssignContext _ctx) => throw new NotImplementedException ();
		public IAst VisitQusQusOp (FaParser.QusQusOpContext _ctx) => throw new NotImplementedException ();
		public IAst VisitSelfOp2 (FaParser.SelfOp2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitShiftLAssign (FaParser.ShiftLAssignContext _ctx) => throw new NotImplementedException ();
		public IAst VisitShiftLOp (FaParser.ShiftLOpContext _ctx) => throw new NotImplementedException ();
		public IAst VisitShiftRAssign (FaParser.ShiftRAssignContext _ctx) => throw new NotImplementedException ();
		public IAst VisitShiftROp (FaParser.ShiftROpContext _ctx) => throw new NotImplementedException ();
		public IAst VisitStarAssign (FaParser.StarAssignContext _ctx) => throw new NotImplementedException ();
		public IAst VisitStarStarAssign (FaParser.StarStarAssignContext _ctx) => throw new NotImplementedException ();
		public IAst VisitStarStarOp (FaParser.StarStarOpContext _ctx) => throw new NotImplementedException ();
		public IAst VisitStmt (FaParser.StmtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitStrongExpr (FaParser.StrongExprContext _ctx) => throw new NotImplementedException ();
		public IAst VisitStrongExprBase (FaParser.StrongExprBaseContext _ctx) => throw new NotImplementedException ();
		public IAst VisitStrongExprPrefix (FaParser.StrongExprPrefixContext _ctx) => throw new NotImplementedException ();
		public IAst VisitStrongExprSuffix (FaParser.StrongExprSuffixContext _ctx) => throw new NotImplementedException ();
		public IAst VisitSubAssign (FaParser.SubAssignContext _ctx) => throw new NotImplementedException ();
		public IAst VisitTerminal (ITerminalNode node) => throw new NotImplementedException ();
		public IAst VisitTmpAssignExpr (FaParser.TmpAssignExprContext _ctx) => throw new NotImplementedException ();
		public IAst VisitType (FaParser.TypeContext _ctx) => throw new NotImplementedException ();
		public IAst VisitTypeAfter (FaParser.TypeAfterContext _ctx) => throw new NotImplementedException ();
		public IAst VisitTypeNewable (FaParser.TypeNewableContext _ctx) => throw new NotImplementedException ();
		public IAst VisitTypeVar (FaParser.TypeVarContext _ctx) => throw new NotImplementedException ();
		public IAst VisitTypeVarList (FaParser.TypeVarListContext _ctx) => throw new NotImplementedException ();
		public IAst VisitUseStmt (FaParser.UseStmtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitWhileStmt (FaParser.WhileStmtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitXorAssign (FaParser.XorAssignContext _ctx) => throw new NotImplementedException ();
	}
}

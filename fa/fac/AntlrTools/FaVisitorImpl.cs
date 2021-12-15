using Antlr4.Runtime.Misc;
using Antlr4.Runtime.Tree;
using fac.ASTs;
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
			}
			throw new NotImplementedException ();
		}



		public IAst VisitProgram (FaParser.ProgramContext _ctx) => new AstProgram (_ctx);
		public IAst VisitType (FaParser.TypeContext _ctx) => IAstType.FromContext (_ctx);
		public IAst VisitClassFunc (FaParser.ClassFuncContext _ctx) => new AstClassFunc (_ctx);



		public IAst VisitClassStmt (FaParser.ClassStmtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitClassEnumItem (FaParser.ClassEnumItemContext _ctx) => throw new NotImplementedException ();
		public IAst VisitClassVar (FaParser.ClassVarContext _ctx) => throw new NotImplementedException ();
		public IAst VisitAllAssign (FaParser.AllAssignContext _ctx) => throw new NotImplementedException ();
		public IAst VisitAllOp2 (FaParser.AllOp2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitArrayExpr1 (FaParser.ArrayExpr1Context _ctx) => throw new NotImplementedException ();
		public IAst VisitArrayExpr2 (FaParser.ArrayExpr2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitCallConvention (FaParser.CallConventionContext _ctx) => throw new NotImplementedException ();
		public IAst VisitChangeOp2 (FaParser.ChangeOp2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitClassFuncBody (FaParser.ClassFuncBodyContext _ctx) => throw new NotImplementedException ();
		public IAst VisitClassFuncName (FaParser.ClassFuncNameContext _ctx) => throw new NotImplementedException ();
		public IAst VisitClassParent (FaParser.ClassParentContext _ctx) => throw new NotImplementedException ();
		public IAst VisitClassVarExt (FaParser.ClassVarExtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitClassVarExtFunc (FaParser.ClassVarExtFuncContext _ctx) => throw new NotImplementedException ();
		public IAst VisitCompareOp2 (FaParser.CompareOp2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitDefVarStmt (FaParser.DefVarStmtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitEqualOp (FaParser.EqualOpContext _ctx) => throw new NotImplementedException ();
		public IAst VisitErrorNode (IErrorNode node) => throw new NotImplementedException ();
		public IAst VisitExpr (FaParser.ExprContext _ctx) => throw new NotImplementedException ();
		public IAst VisitExprFuncDef (FaParser.ExprFuncDefContext _ctx) => throw new NotImplementedException ();
		public IAst VisitExprOpt (FaParser.ExprOptContext _ctx) => throw new NotImplementedException ();
		public IAst VisitFloatNum (FaParser.FloatNumContext _ctx) => throw new NotImplementedException ();
		public IAst VisitGtEqualOp (FaParser.GtEqualOpContext _ctx) => throw new NotImplementedException ();
		public IAst VisitGtOp (FaParser.GtOpContext _ctx) => throw new NotImplementedException ();
		public IAst VisitId (FaParser.IdContext _ctx) => throw new NotImplementedException ();
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
		public IAst VisitNamespaceStmt (FaParser.NamespaceStmtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitNewExpr (FaParser.NewExpr1Context _ctx) => throw new NotImplementedException ();
		public IAst VisitNewExpr (FaParser.NewExpr2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitNewExprItem (FaParser.NewExprItemContext _ctx) => throw new NotImplementedException ();
		public IAst VisitNewExpr1 (FaParser.NewExpr1Context context) => throw new NotImplementedException ();
		public IAst VisitNewExpr2 (FaParser.NewExpr2Context context) => throw new NotImplementedException ();
		public IAst VisitNormalStmt (FaParser.NormalStmtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitNotEqualOp (FaParser.NotEqualOpContext _ctx) => throw new NotImplementedException ();
		public IAst VisitWhileStmt (FaParser.WhileStmtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitWhileStmt2 (FaParser.WhileStmt2Context context) => throw new NotImplementedException ();
		public IAst VisitForStmt (FaParser.ForStmtContext context) => throw new NotImplementedException ();
		public IAst VisitForStmt2 (FaParser.ForStmt2Context context) => throw new NotImplementedException ();
		public IAst VisitPublicLevel (FaParser.PublicLevelContext _ctx) => throw new NotImplementedException ();
		public IAst VisitQuotExpr (FaParser.QuotExprContext _ctx) => throw new NotImplementedException ();
		public IAst VisitQuotStmtExpr (FaParser.QuotStmtExprContext _ctx) => throw new NotImplementedException ();
		public IAst VisitQuotStmtExprWrap (FaParser.QuotStmtExprWrapContext context) => throw new NotImplementedException ();
		public IAst VisitQuotStmtPart (FaParser.QuotStmtPartContext _ctx) => throw new NotImplementedException ();
		public IAst VisitSelfOp2 (FaParser.SelfOp2Context _ctx) => throw new NotImplementedException ();
		public IAst VisitShiftLAssign (FaParser.ShiftLAssignContext _ctx) => throw new NotImplementedException ();
		public IAst VisitShiftLOp (FaParser.ShiftLOpContext _ctx) => throw new NotImplementedException ();
		public IAst VisitShiftRAssign (FaParser.ShiftRAssignContext _ctx) => throw new NotImplementedException ();
		public IAst VisitShiftROp (FaParser.ShiftROpContext _ctx) => throw new NotImplementedException ();
		public IAst VisitStmt (FaParser.StmtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitStrongExpr (FaParser.StrongExprContext _ctx) => throw new NotImplementedException ();
		public IAst VisitStrongExprBase (FaParser.StrongExprBaseContext _ctx) => throw new NotImplementedException ();
		public IAst VisitStrongExprPrefix (FaParser.StrongExprPrefixContext _ctx) => throw new NotImplementedException ();
		public IAst VisitStrongExprSuffix (FaParser.StrongExprSuffixContext _ctx) => throw new NotImplementedException ();
		public IAst VisitTerminal (ITerminalNode node) => throw new NotImplementedException ();
		public IAst VisitTmpAssignExpr (FaParser.TmpAssignExprContext _ctx) => throw new NotImplementedException ();
		public IAst VisitTypeAfter (FaParser.TypeAfterContext _ctx) => throw new NotImplementedException ();
		public IAst VisitTypeSingle (FaParser.TypeSingleContext context) => throw new NotImplementedException ();
		public IAst VisitTypeMulti (FaParser.TypeMultiContext context) => throw new NotImplementedException ();
		public IAst VisitTypeVar (FaParser.TypeVarContext _ctx) => throw new NotImplementedException ();
		public IAst VisitTypeVarList (FaParser.TypeVarListContext _ctx) => throw new NotImplementedException ();
		public IAst VisitUseStmt (FaParser.UseStmtContext _ctx) => throw new NotImplementedException ();
		public IAst VisitEnumStmt (FaParser.EnumStmtContext context) => throw new NotImplementedException ();
		public IAst VisitSwitchStmtPart (FaParser.SwitchStmtPartContext context) => throw new NotImplementedException ();
		public IAst VisitSwitchStmt (FaParser.SwitchStmtContext context) => throw new NotImplementedException ();
		public IAst VisitSwitchExprPart (FaParser.SwitchExprPartContext context) => throw new NotImplementedException ();
		public IAst VisitSwitchExpr (FaParser.SwitchExprContext context) => throw new NotImplementedException ();
		public IAst VisitSwitchStmtPart2Last (FaParser.SwitchStmtPart2LastContext context) => throw new NotImplementedException ();
		public IAst VisitSwitchExprPartLast (FaParser.SwitchExprPartLastContext context) => throw new NotImplementedException ();
		public IAst VisitSwitchStmtPart2 (FaParser.SwitchStmtPart2Context context) => throw new NotImplementedException ();
		public IAst VisitSwitchStmt2 (FaParser.SwitchStmt2Context context) => throw new NotImplementedException ();
		public IAst VisitSwitchExprPart2 (FaParser.SwitchExprPart2Context context) => throw new NotImplementedException ();
		public IAst VisitSwitchExpr2 (FaParser.SwitchExpr2Context context) => throw new NotImplementedException ();
		public IAst VisitIdAssignExpr (FaParser.IdAssignExprContext context) => throw new NotImplementedException ();
		public IAst VisitTypeVar2 (FaParser.TypeVar2Context context) => throw new NotImplementedException ();
		public IAst VisitTypeVar2List (FaParser.TypeVar2ListContext context) => throw new NotImplementedException ();
		public IAst VisitLambdaExpr (FaParser.LambdaExprContext context) => throw new NotImplementedException ();
		public IAst VisitClassTemplates (FaParser.ClassTemplatesContext context) => throw new NotImplementedException ();
	}
}

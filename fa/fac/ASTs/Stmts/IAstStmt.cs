using fac.ASTs.Exprs;
using fac.ASTs.Exprs.Names;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Stmts {
	public abstract class IAstStmt: IAstExpr {
		public override IAstType GuessType () => throw new NotImplementedException ();

		public static IAstStmt FromExpr (FaParser.ExprContext _ctx, bool _return) {
			if (_return) {
				return new AstStmt_Return { Token = _ctx?.Start ?? null, Expr = FromContext (_ctx) };
			} else {
				return new AstStmt_ExprWrap { Token = _ctx?.Start ?? null, Expr = FromContext (_ctx) };
			}
		}

		private static IAstStmt FromIfStmt (List<FaParser.ExprContext> _conditions, List<FaParser.QuotStmtPartContext> _contents) {
			var _ifexpr = new AstStmt_If { Token = _conditions[0].Start };
			_ifexpr.Condition = FromContext (_conditions[0]);
			_ifexpr.IfTrueCodes = FromStmts (_contents[0].stmt ());
			if (_conditions.Count == 1) {
				if (_contents.Count > 1) {
					_ifexpr.IfFalseCodes = FromStmts (_contents[1].stmt ());
				} else {
					_ifexpr.IfFalseCodes = new List<IAstStmt> ();
				}
			} else {
				_ifexpr.IfFalseCodes = new List<IAstStmt> { FromIfStmt (_conditions.Skip (1).ToList (), _contents.Skip (1).ToList ()) };
			}
			return _ifexpr;
		}

		public static List<IAstStmt> FromStmt (FaParser.StmtContext _ctx) {
			var _stmts = new List<IAstStmt> ();
			if (_ctx == null) {
			} else if (_ctx.ifStmt () != null) {
				var _conditions = _ctx.ifStmt ().expr ().ToList ();
				var _contents = _ctx.ifStmt ().quotStmtPart ().ToList ();
				_stmts.Add (FromIfStmt (_conditions, _contents));
			} else if (_ctx.whileStmt () != null) {
				var _whilestmt = new AstStmt_While { Token = _ctx.Start, IsDoWhile = false };
				_whilestmt.Condition = FromContext (_ctx.whileStmt ().expr ());
				_whilestmt.Contents = FromStmts (_ctx.whileStmt ().stmt ());
				_stmts.Add (_whilestmt);
			} else if (_ctx.whileStmt2 () != null) {
				var _whilestmt = new AstStmt_While { Token = _ctx.Start, IsDoWhile = true };
				_whilestmt.Condition = FromContext (_ctx.whileStmt2 ().expr ());
				_whilestmt.Contents = FromStmts (_ctx.whileStmt2 ().stmt ());
				_stmts.Add (_whilestmt);
			} else if (_ctx.forStmt () != null) {
				var _forstmt = new AstStmt_For { Token = _ctx.Start };
				_forstmt.Initializes = FromStmt (_ctx.forStmt ().stmt ()[0]);
				_forstmt.Condition = FromContext (_ctx.forStmt ().expr ()[0]);
				_forstmt.Increment = FromExprs (_ctx.forStmt ().expr ()[1..]);
				_forstmt.BodyCodes = FromStmts (_ctx.forStmt ().stmt ()[1..]);
				_stmts.Add (_forstmt);
			} else if (_ctx.forStmt2 () != null) {
				var _forstmt2 = new AstStmt_For2 { Token = _ctx.Start };
				_forstmt2.Iterator = new AstStmt_DefVariable { Token = _ctx.forStmt2 ().type ().Start, DataType = IAstType.FromContext (_ctx.forStmt2 ().type ()), VarName = _ctx.forStmt2 ().id ().GetText (), Expr = null };
				_forstmt2.ListContainer = FromContext (_ctx.forStmt2 ().expr ());
				_forstmt2.BodyCodes = FromStmts (_ctx.forStmt2 ().stmt ());
				_stmts.Add (_forstmt2);
			} else if (_ctx.quotStmtPart () != null) {
				_stmts.Add (new AstStmt_HuaQuotWrap { Token = _ctx.Start, Stmts = FromStmts (_ctx.quotStmtPart ().stmt ()) });
			} else if (_ctx.switchStmt2 () != null) {
				var _t = new AstStmt_Switch { Token = _ctx.Start, Condition = null };
				var _switch_items = _ctx.switchStmt2 ().switchStmtPart2 ();
				_t.CaseValues = null;
				_t.CaseWhen = (from p in _switch_items select FromContext (p.expr ())).ToList ();
				_t.CaseCodes = (from p in _switch_items select FromStmt (p.stmt ()).ToSingleStmt ()).ToList ();
				if (_ctx.switchStmt2 ().switchStmtPart2Last () != null) {
					_t.CaseWhen.Add (new AstExprName_Ignore { Token = _ctx.switchStmt2 ().switchStmtPart2Last ().Underline ().Symbol });
					_t.CaseCodes.Add (FromStmt (_ctx.switchStmt2 ().switchStmtPart2Last ().stmt ()).ToSingleStmt ());
				}
				_stmts.Add (_t);
				// TODO: 移植为if else
			} else if (_ctx.switchStmt () != null) {
				var _t = new AstStmt_Switch { Token = _ctx.Start, Condition = FromContext (_ctx.switchStmt ().expr ()) };
				var _switch_items = _ctx.switchStmt ().switchStmtPart ();
				_t.CaseValues = (from p in _switch_items select FromContext (p.expr ()[0])).ToList ();
				_t.CaseWhen = (from p in _switch_items select p.expr ().Length > 1 ? FromContext (p.expr ()[1]) : null).ToList ();
				_t.CaseCodes = (from p in _switch_items select FromStmt (p.stmt ()).ToSingleStmt ()).ToList ();
				_stmts.Add (_t);
				// TODO: 移植为if else
			} else if (_ctx.normalStmt () != null) {
				if (_ctx.normalStmt ().Continue () != null) {
					_stmts.Add (new AstStmt_ExprWrap { Token = _ctx.Start, Expr = AstExprName_BuildIn.FindFromName ("continue") });
				} else if (_ctx.normalStmt ().Break () != null) {
					_stmts.Add (new AstStmt_ExprWrap { Token = _ctx.Start, Expr = AstExprName_BuildIn.FindFromName ("break") });
				} else if (_ctx.normalStmt ().Return () != null) {
					_stmts.Add (new AstStmt_Return { Token = _ctx.Start, Expr = FromContext (_ctx.normalStmt ().expr ()) });
				} else {
					_stmts.Add (new AstStmt_ExprWrap { Token = _ctx.Start, Expr = FromContext (_ctx.normalStmt ().expr ()) });
				}
			} else if (_ctx.defVarStmt () != null) {
				var _type = IAstType.FromContext (_ctx.defVarStmt ().type ());
				foreach (var _var_ctx in _ctx.defVarStmt ().idAssignExpr ()) {
					var _varstmt = new AstStmt_DefVariable { Token = _ctx.Start };
					_varstmt.DataType = _type;
					_varstmt.VarName = _var_ctx.id ().GetText ();
					_varstmt.Expr = FromContext (_var_ctx.expr ());
					_stmts.Add (_varstmt);
				}
			} else {
				throw new UnimplException (_ctx.Start);
			}
			return _stmts;
		}

		public static List<IAstExpr> FromExprs (FaParser.ExprContext[] _ctxs) => (from p in _ctxs select FromContext (p)).ToList ();

		public static List<IAstStmt> FromStmts (FaParser.StmtContext[] _ctxs) => (from p in _ctxs select FromStmt (p)).CombileStmts ();

		public override bool AllowAssign () => false;
	}
}

using fac.ASTs.Exprs;
using fac.ASTs.Exprs.Names;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Stmts {
	abstract class IAstStmt: IAstExpr {
		public override string GuessType () => "";

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

		public static IAstStmt FromContext (FaParser.StmtContext _ctx) {
			if (_ctx.normalStmt () != null) {
				if (_ctx.normalStmt ().Continue () != null) {
					return new AstStmt_ExprWrap { Token = _ctx.Start, Expr = AstExprName_BuildIn.FindFromName ("continue") };
				} else if (_ctx.normalStmt ().Break () != null) {
					return new AstStmt_ExprWrap { Token = _ctx.Start, Expr = AstExprName_BuildIn.FindFromName ("break") };
				} else if (_ctx.normalStmt ().Return () != null) {
					return new AstStmt_Return { Token = _ctx.Start, Expr = FromContext (_ctx.normalStmt ().expr ()) };
				} else {
					return new AstStmt_ExprWrap { Token = _ctx.Start, Expr = FromContext (_ctx.normalStmt ().expr ()) };
				}
			} else if (_ctx.ifStmt () != null) {
				var _conditions = _ctx.ifStmt ().expr ().ToList ();
				var _contents = _ctx.ifStmt ().quotStmtPart ().ToList ();
				return FromIfStmt (_conditions, _contents);
			} else if (_ctx.defVarStmt () != null) {
				var _varstmt = new AstStmt_DefVariable { Token = _ctx.Start };
				_varstmt.DataType = _ctx.defVarStmt ().type ().GetText ();
				_varstmt.VarName = _ctx.defVarStmt ().Id ().GetText ();
				_varstmt.Expr = FromContext (_ctx.defVarStmt ().expr ());
				return _varstmt;
			} else if (_ctx.whileStmt () != null) {
				var _whilestmt = new AstStmt_While { Token = _ctx.Start, IsDoWhile = false };
				_whilestmt.Condition = FromContext (_ctx.whileStmt ().expr ());
				_whilestmt.Contents = FromStmts (_ctx.whileStmt ().stmt ());
				return _whilestmt;
			} else if (_ctx.numIterStmt () != null) {

			}
			throw new UnimplException (_ctx.Start);
		}

		public static List<IAstStmt> FromStmts (FaParser.StmtContext[] _ctxs) => (from p in _ctxs select FromContext (p)).ToList ();

		public override bool AllowAssign () => false;
	}
}

using fac.ASTs.Exprs;
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

		public static IAstStmt FromContext (FaParser.StmtContext _ctx) {
			if (_ctx.normalStmt () != null) {
				if (_ctx.normalStmt ().Return () != null) {
					return new AstStmt_Return { Token = _ctx.Start, Expr = FromContext (_ctx.normalStmt ().expr ()) };
				} else {
					return new AstStmt_ExprWrap { Token = _ctx.Start, Expr = FromContext (_ctx.normalStmt ().expr ()) };
				}
			} else if (_ctx.ifStmt () != null) {
				//var _stmt = new AstStmt_If { Token = _ctx.Start };
				//_stmt.Condition = _ctx.ifStmt ().expr ()
			} else if (_ctx.defVarStmt () != null) {
				var _stmt = new AstStmt_DefVariable { Token = _ctx.Start };
				_stmt.DataType = _ctx.defVarStmt ().type ().GetText ();
				_stmt.VarName = _ctx.defVarStmt ().Id ().GetText ();
				_stmt.Expr = FromContext (_ctx.defVarStmt ().expr ());
				return _stmt;
			} else if (_ctx.whileStmt () != null) {

			} else if (_ctx.numIterStmt () != null) {

			}
			throw new UnimplException (_ctx.Start);
		}

		public static List<IAstStmt> FromStmts (FaParser.StmtContext[] _ctxs) => (from p in _ctxs select FromContext (p)).ToList ();
	}
}

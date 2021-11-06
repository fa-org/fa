using fac.ASTs.Exprs;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs {
	enum StmtType { Normal, If, DefVar, While, NumIter }

	class AstStmt: IAstExpr, IAst {
		public StmtType Type { init; get; }
		public IAstExpr NormalExpr { get; private set; } = null;
		public bool NormalReturn { get; private set; } = false;



		private AstStmt (StmtType _type) => Type = _type;
		public AstStmt (FaParser.StmtContext _ctx) {
			if (_ctx.normalStmt () != null) {
				Type = StmtType.Normal;
				var _expr_ctx = _ctx.normalStmt ().expr ();
				if (_expr_ctx == null)
					throw new UnimplException (_ctx);
				NormalExpr = FromContext (_expr_ctx);
			} else {
				throw new UnimplException (_ctx);
			}
		}

		public override void Traversal (Func<IAstExpr, IAstExpr> _cb) {
			if (Type == StmtType.Normal) {
				NormalExpr = _cb (NormalExpr);
			} else {
				throw new UnimplException (Token);
			}
		}

		public static AstStmt FromExpr (FaParser.ExprContext _ctx, bool _return) {
			var _stmt = new AstStmt (StmtType.Normal) { Token = _ctx.Start };
			_stmt.NormalExpr = FromContext (_ctx);
			_stmt.NormalReturn = _return;
			return _stmt;
		}

		public static List<AstStmt> FromStmts (FaParser.StmtContext[] _ctxs) => (from p in _ctxs select new AstStmt (p) { Token = p.Start }).ToList ();
	}
}

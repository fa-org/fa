using fac.ASTs.Exprs;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Stmts {
	class AstStmt_ExprWrap: IAstStmt {
		public IAstExpr Expr { get; set; }

		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			Expr = _cb (Expr, _deep, _group);
		}

		public override IAstExpr TraversalCalcType (string _expect_type) {
			if (_expect_type != "")
				throw new Exception ("语句类型不可指定期望类型");
			Expr = Expr.TraversalCalcType ("");
			return this;
		}
	}
}

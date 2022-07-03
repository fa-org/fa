using fac.ASTs.Exprs.Names;
using fac.ASTs.Stmts;
using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	public class AstExpr_OptHasValue: IAstExpr {
		public IAstExpr Child { get; set; } = null;

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			var (_list, _expr) = Child.ExpandExpr (_cache_err);
			Child = _expr;
			return (_list, this);
		}

		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) {
			Child = Child.TraversalWrap (_trav);
		}

		public override IAstType GuessType () => new AstType_Bool ();

		public override IAstExpr TraversalCalcType (IAstType? _expect_type) {
			if (_expect_type is not AstType_Bool)
				throw new NotImplementedException ();
			Child.TraversalCalcType (null);
			ExpectType = _expect_type;
			return this;
		}

		public override string GenerateCSharp (int _indent) {
			throw new NotImplementedException ();
		}

		public override string GenerateCpp (int _indent) => $"{Child.GenerateCpp (_indent)}.index () == 0";

		public override bool AllowAssign () => false;

		public static AstExpr_OptHasValue Make (IAstExpr _var) {
			return new AstExpr_OptHasValue { Child = _var, ExpectType = IAstType.FromName ("bool") };
		}
	}
}

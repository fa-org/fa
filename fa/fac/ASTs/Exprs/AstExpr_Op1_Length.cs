using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	public class AstExpr_Op1_Length: IAstExpr {
		public IAstExpr Value { get; set; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			Value = _cb (Value, _deep, _group);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			Value = Value.TraversalCalcType (null);
			ExpectType = IAstType.FromName ("int");
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () => IAstType.FromName ("int");

		public override (string, string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb) {
			var (_a, _b, _c) = Value.GenerateCSharp (_indent, _check_cb);
			return (_a, $"{_b}.Count", _c);
		}

		public override bool AllowAssign () => false;
	}
}

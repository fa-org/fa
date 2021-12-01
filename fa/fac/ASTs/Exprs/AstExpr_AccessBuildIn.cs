using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	public class AstExpr_AccessBuildIn: IAstExpr {
		public IAstExpr Value { get; set; }
		public string MemberName { get; set; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			Value = _cb (Value, _deep, _group);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			Value = Value.TraversalCalcType (null);
			if (ExpectType == null)
				throw new Exception ("此类需构造时指定类型");
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () {
			if (ExpectType == null)
				throw new Exception ("此类需构造时指定类型");
			return ExpectType;
		}

		public override (string, string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb) {
			var (_a, _b, _c) = Value.GenerateCSharp (_indent, _check_cb);
			return (_a, $"{_b}.{s_csharp_codemap [MemberName]}", _c);
		}

		public override bool AllowAssign () => false;

		private static Dictionary<string, string> s_csharp_codemap = new Dictionary<string, string> { ["Length"] = "Count" };
	}
}

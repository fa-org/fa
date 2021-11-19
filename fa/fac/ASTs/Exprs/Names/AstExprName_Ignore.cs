using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs.Names {
	class AstExprName_Ignore: IAstExprName {
		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			ExpectType = new AstType_Any { Token = Token };
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () => new AstType_Any { Token = Token };

		public override (string, string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb) => ("", "_", "");

		public override bool AllowAssign () => true;
	}
}

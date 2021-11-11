using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs.Names {
	class AstExprName_This: IAstExprName {
		public AstClass Class { init; get; }



		public override IAstExpr TraversalCalcType (string _expect_type) => AstExprTypeCast.Make (this, _expect_type);

		public override string GuessType () => Class.FullName;

		public override (string, string) GenerateCSharp (int _indent) => ("", "this");

		public override bool AllowAssign () => false;
	}
}

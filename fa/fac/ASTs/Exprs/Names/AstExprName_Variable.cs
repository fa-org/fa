using fac.ASTs.Stmts;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs.Names {
	class AstExprName_Variable: IAstExprName {
		public AstStmt_DefVariable Var { init; get; }



		public override IAstExpr TraversalCalcType (string _expect_type) {
			ExpectType = Var.DataType;
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override string GuessType () => Var.DataType;
	}
}

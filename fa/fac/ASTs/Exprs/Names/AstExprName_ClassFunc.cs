using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs.Names {
	class AstExprName_ClassFunc: IAstExprName {
		public AstClassStmt Class { init; get; }
		public int FunctionIndex { init; get; }



		public override IAstExpr TraversalCalcType (string _expect_type) {
			ExpectType = GuessType ();
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override string GuessType () => $"{Class.FullName}{Class.ClassFuncs[FunctionIndex].Name}";
	}
}

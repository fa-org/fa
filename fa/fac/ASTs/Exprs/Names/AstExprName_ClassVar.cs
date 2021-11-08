using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs.Names {
	class AstExprName_ClassVar: IAstExprName {
		public AstClassStmt Class { init; get; }
		public int VariableIndex { init; get; }



		public override IAstExpr TraversalCalcType (string _expect_type) {
			ExpectType = Class.ClassVars[VariableIndex].DataType;
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override string GuessType () => Class.ClassVars[VariableIndex].DataType;
	}
}

using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs.Names {
	public class AstExprName_This: IAstExprName {
		public IAstClass Class { init; get; }



		public override IAstExpr TraversalCalcType (IAstType _expect_type) => AstExprTypeCast.Make (this, _expect_type);

		public override IAstType GuessType () => AstType_Class.GetType (Token, Class);

		public override string GenerateCSharp (int _indent) => "this";

		public override bool AllowAssign () => false;
	}
}

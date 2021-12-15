using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs.Names {
	public class AstExprName_Class: IAstExprName {
		public IAstClass Class { init; get; }



		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			ExpectType = AstType_Class.GetType (Token, Class);
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () => AstType_Class.GetType (Token, Class);

		public override string GenerateCSharp (int _indent) => Class.FullName;

		public override bool AllowAssign () => false;
	}
}

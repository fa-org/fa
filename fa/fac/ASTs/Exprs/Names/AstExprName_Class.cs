using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs.Names {
	class AstExprName_Class: IAstExprName {
		public IAstClass Class { init; get; }



		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			ExpectType = new AstType_Class { Token = Token, Class = Class };
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () => new AstType_Class { Token = Token, Class = Class };

		public override (string, string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb) => ("", Class.FullName, "");

		public override bool AllowAssign () => false;
	}
}

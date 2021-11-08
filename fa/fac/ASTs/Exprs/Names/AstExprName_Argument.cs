using fac.AntlrTools;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs.Names {
	class AstExprName_Argument: IAstExprName {
		public AstClassFunc Func { init; get; }
		public int ArgumentIndex { init; get; }



		public override IAstExpr TraversalCalcType (string _expect_type) {
			ExpectType = Func.Arguments[ArgumentIndex]._type;
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override string GuessType () => Func.Arguments[ArgumentIndex]._type;
	}
}

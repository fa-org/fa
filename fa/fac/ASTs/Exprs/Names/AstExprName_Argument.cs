using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs.Names {
	class AstExprName_Argument: IAstExprName {
		public AstClassFunc Func { init; get; }
		public int ArgumentIndex { init; get; }
	}
}

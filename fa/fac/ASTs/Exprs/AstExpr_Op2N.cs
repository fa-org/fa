using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	class AstExpr_Op2N: IAst, IAstExpr {
		public List<IAstExpr> Values { get; set; }
		public List<string> Operators { get; set; }
	}
}

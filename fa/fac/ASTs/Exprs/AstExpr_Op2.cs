using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	class AstExpr_Op2: IAst, IAstExpr {
		public IAstExpr Value1 { get; set; }
		public IAstExpr Value2 { get; set; }
		public string Operator { get; set; }
	}
}

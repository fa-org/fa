using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	class AstExpr_Op1 {
		public IAstExpr Value1 { get; set; }
		public string Operator { get; set; }
		public bool IsPrefix { get; set; }
	}
}

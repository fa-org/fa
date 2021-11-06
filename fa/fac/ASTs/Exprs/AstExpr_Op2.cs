using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	class AstExpr_Op2: IAstExpr, IAst {
		public IAstExpr Value1 { get; set; }
		public IAstExpr Value2 { get; set; }
		public string Operator { get; set; }



		public override void Traversal (Func<IAstExpr, IAstExpr> _cb) {
			Value1 = _cb (Value1);
			Value2 = _cb (Value2);
		}
	}
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	class AstExpr_Op1: IAstExpr, IAst {
		public IAstExpr Value { get; set; }
		public string Operator { get; set; }
		public bool IsPrefix { get; set; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			Value = _cb (Value, _deep, _group);
		}
	}
}

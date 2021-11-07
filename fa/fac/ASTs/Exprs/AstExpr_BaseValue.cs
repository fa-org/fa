using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	class AstExpr_BaseValue: IAstExpr, IAst {
		public string DataType { get; set; }
		public string Value { get; set; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) { }
	}
}

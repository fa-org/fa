using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	class AstExpr_BaseId: IAstExpr, IAst {
		public string Id { get; set; }



		public override void Traversal (Func<IAstExpr, IAstExpr> _cb) { }
	}
}

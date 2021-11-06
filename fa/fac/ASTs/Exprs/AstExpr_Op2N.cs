using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	class AstExpr_Op2N: IAstExpr, IAst {
		public List<IAstExpr> Values { get; set; }
		public List<string> Operators { get; set; }



		public override void Traversal (Func<IAstExpr, IAstExpr> _cb) {
			for (int i = 0; i < Values.Count; ++i)
				Values [i] = _cb (Values[i]);
		}
	}
}

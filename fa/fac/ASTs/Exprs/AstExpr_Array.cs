using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	class AstExpr_Array: IAstExpr, IAst {
		public string ItemDataType { get; set; }
		public IAstExpr InitCount { get; set; }
		public List<IAstExpr> InitValues { get; set; }

		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			InitCount = _cb (InitCount, _deep, _group);
			for (int i = 0; i < InitValues.Count; ++i)
				InitValues[i] = _cb (InitValues[i], _deep, _group);
		}
	}
}

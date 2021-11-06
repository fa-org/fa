using fac.AntlrTools;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	class AstExpr_If: IAstExpr, IAst {
		public IAstExpr Condition { get; set; }
		public List<AstStmt> IfTrueCodes { get; set; }
		public IAstExpr IfTrue { get; set; }
		public List<AstStmt> IfFalseCodes { get; set; }
		public IAstExpr IfFalse { get; set; }



		public override void Traversal (Func<IAstExpr, IAstExpr> _cb) {
			Condition = _cb (Condition);
			for (int i = 0; i < IfTrueCodes.Count; ++i)
				IfTrueCodes[i] = _cb (IfTrueCodes[i]) as AstStmt;
			IfTrue = _cb (IfTrue);
			for (int i = 0; i < IfFalseCodes.Count; ++i)
				IfFalseCodes[i] = _cb (IfFalseCodes[i]) as AstStmt;
			IfFalse = _cb (IfFalse);
		}
	}
}

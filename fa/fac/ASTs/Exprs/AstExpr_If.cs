using fac.AntlrTools;
using fac.ASTs.Stmts;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	class AstExpr_If: IAstExpr, IAst {
		public IAstExpr Condition { get; set; }
		public List<IAstStmt> IfTrueCodes { get; set; }
		public IAstExpr IfTrue { get; set; }
		public List<IAstStmt> IfFalseCodes { get; set; }
		public IAstExpr IfFalse { get; set; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			Condition = _cb (Condition, _deep, _group);
			for (int i = 0; i < IfTrueCodes.Count; ++i)
				IfTrueCodes[i] = _cb (IfTrueCodes[i], _deep + 1, 0) as IAstStmt;
			IfTrue = _cb (IfTrue, _deep + 1, 0);
			for (int i = 0; i < IfFalseCodes.Count; ++i)
				IfFalseCodes[i] = _cb (IfFalseCodes[i], _deep + 1, 1) as IAstStmt;
			IfFalse = _cb (IfFalse, _deep + 1, 1);
		}
	}
}

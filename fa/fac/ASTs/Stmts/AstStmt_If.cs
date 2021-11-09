using fac.ASTs.Exprs;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Stmts {
	class AstStmt_If: IAstStmt {
		public IAstExpr Condition { get; set; }
		public List<IAstStmt> IfTrueCodes { get; set; }
		public List<IAstStmt> IfFalseCodes { get; set; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			Condition = _cb (Condition, _deep, _group);
			for (int i = 0; i < IfTrueCodes.Count; ++i)
				IfTrueCodes[i] = _cb (IfTrueCodes[i], _deep + 1, 0) as IAstStmt;
			for (int i = 0; i < IfFalseCodes.Count; ++i)
				IfFalseCodes[i] = _cb (IfFalseCodes[i], _deep + 1, 1) as IAstStmt;
		}

		public override IAstExpr TraversalCalcType (string _expect_type) {
			if (_expect_type != "")
				throw new Exception ("语句类型不可指定期望类型");
			Condition = Condition.TraversalCalcType ("bool");
			for (int i = 0; i < IfTrueCodes.Count; ++i)
				IfTrueCodes[i] = IfTrueCodes[i].TraversalCalcType ("") as IAstStmt;
			for (int i = 0; i < IfFalseCodes.Count; ++i)
				IfFalseCodes[i] = IfFalseCodes[i].TraversalCalcType ("") as IAstStmt;
			return this;
		}
	}
}

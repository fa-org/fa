using fac.AntlrTools;
using fac.ASTs.Stmts;
using fac.Exceptions;
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

		public override IAstExpr TraversalCalcType (string _expect_type) {
			if (_expect_type == "")
				_expect_type = GuessType ();
			//
			Condition = Condition.TraversalCalcType ("bool");
			for (int i = 0; i < IfTrueCodes.Count; ++i)
				IfTrueCodes[i] = IfTrueCodes[i].TraversalCalcType ("") as IAstStmt;
			IfTrue = IfTrue.TraversalCalcType (_expect_type);
			for (int i = 0; i < IfFalseCodes.Count; ++i)
				IfFalseCodes[i] = IfFalseCodes[i].TraversalCalcType ("") as IAstStmt;
			IfFalse = IfFalse.TraversalCalcType (_expect_type);
			ExpectType = _expect_type;
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override string GuessType () {
			return TypeFuncs.GetCompatibleType (IfTrue.GuessType (), IfFalse.GuessType ());
		}
	}
}

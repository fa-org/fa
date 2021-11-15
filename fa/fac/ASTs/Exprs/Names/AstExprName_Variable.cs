using fac.ASTs.Stmts;
using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs.Names {
	class AstExprName_Variable: IAstExprName {
		public AstStmt_DefVariable Var { init; get; }



		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			ExpectType = Var.DataType;
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () => Var.DataType;

		public override (string, string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb) {
			if (Var.DataType is AstType_OptionalWrap && _check_cb != null) {
				_check_cb ($"!{Var.VarName}.HasValue ()", $"{Var.VarName}.GetError ()");
				return ("", $"{Var.VarName}.GetValue ()", "");
			} else {
				return ("", Var.VarName, "");
			}
		}

		public override bool AllowAssign () => true;
	}
}

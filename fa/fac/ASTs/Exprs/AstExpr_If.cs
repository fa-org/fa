using fac.AntlrTools;
using fac.ASTs.Exprs.Names;
using fac.ASTs.Stmts;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	public class AstExpr_If: IAstExpr {
		public IAstExpr Condition { get; set; }
		public List<IAstStmt> IfTrueCodes { get; set; } = null;
		public IAstExpr IfTrue { get; set; }
		public List<IAstStmt> IfFalseCodes { get; set; } = null;
		public IAstExpr IfFalse { get; set; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			Condition = _cb (Condition, _deep, _group);
			IfTrueCodes.Traversal (_deep + 1, 0, _cb);
			IfTrue = _cb (IfTrue, _deep + 1, 0);
			IfFalseCodes.Traversal (_deep + 1, 1, _cb);
			IfFalse = _cb (IfFalse, _deep + 1, 1);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (_expect_type == null)
				_expect_type = GuessType ();
			//
			Condition = Condition.TraversalCalcType (IAstType.FromName ("bool"));
			IfTrueCodes.TraversalCalcType ();
			IfTrue = IfTrue.TraversalCalcType (_expect_type);
			IfFalseCodes.TraversalCalcType ();
			IfFalse = IfFalse.TraversalCalcType (_expect_type);
			ExpectType = _expect_type;
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () {
			return TypeFuncs.GetCompatibleType (true, IfTrue.GuessType (), IfFalse.GuessType ());
		}

		public override (List<IAstStmt>, IAstExpr) ExpandExpr () {
			var _temp_id = Common.GetTempId ();
			var _defvar_stmt = new AstStmt_DefVariable { Token = Token, DataType = ExpectType, VarName = _temp_id };
			var _temp_expr = new AstExprName_Variable { Token = Token, ExpectType = ExpectType, Var = _defvar_stmt };
			var _stmt_if = new AstStmt_If { Token = Token, Condition = Condition, IfTrueCodes = IfTrueCodes, IfFalseCodes = IfFalseCodes };
			_stmt_if.IfTrueCodes.Add (new AstStmt_ExprWrap { Token = IfTrue.Token, Expr = new AstExpr_Op2 { Token = IfTrue.Token, Value1 = _temp_expr, Value2 = IfTrue, Operator = "=", ExpectType = ExpectType } });
			_stmt_if.IfFalseCodes.Add (new AstStmt_ExprWrap { Token = IfFalse.Token, Expr = new AstExpr_Op2 { Token = IfFalse.Token, Value1 = _temp_expr, Value2 = IfFalse, Operator = "=", ExpectType = ExpectType } });
			var _stmts = _stmt_if.ExpandStmt ();
			_stmts.Insert (0, _defvar_stmt);
			return (_stmts, _temp_expr);
		}

		public override string GenerateCSharp (int _indent) => throw new Exception ("不应执行此处代码");

		public override bool AllowAssign () => false;
	}
}

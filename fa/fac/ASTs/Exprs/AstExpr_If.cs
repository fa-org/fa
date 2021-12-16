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



		public override void Traversal ((int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) _trav) {
			var _temp_int = Common.GetRandomInt ();
			var _trav1 = (_deep: _trav._deep + 1, _group: _temp_int, _cb: _trav._cb);
			Condition = Condition.TraversalWrap (_trav1);
			IfTrueCodes.TraversalWraps (_trav1);
			IfTrue = IfTrue.TraversalWrap (_trav1);
			_temp_int = Common.GetRandomInt ();
			_trav1 = (_deep: _trav._deep + 1, _group: _temp_int, _cb: _trav._cb);
			IfFalseCodes.TraversalWraps (_trav1);
			IfFalse = IfFalse.TraversalWrap (_trav1);
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

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			var _temp_id = Common.GetTempId ();
			var _defvar_stmt = new AstStmt_DefVariable { Token = Token, DataType = ExpectType, VarName = _temp_id };
			var _stmts = new List<IAstStmt> { _defvar_stmt };
			var _stmt_if = new AstStmt_If { Token = Token, Condition = Condition, IfTrueCodes = IfTrueCodes, IfFalseCodes = IfFalseCodes };
			_stmt_if.IfTrueCodes.Add (AstStmt_ExprWrap.MakeAssign (_defvar_stmt.GetRef (), IfTrue));
			_stmt_if.IfFalseCodes.Add (AstStmt_ExprWrap.MakeAssign (_defvar_stmt.GetRef (), IfFalse));
			_stmts.AddRange (_stmt_if.ExpandStmt (_cache_err));
			return (_stmts, _defvar_stmt.GetRef ());
		}

		public override string GenerateCSharp (int _indent) => throw new Exception ("不应执行此处代码");

		public override bool AllowAssign () => false;
	}
}

using Antlr4.Runtime;
using fac.ASTs.Exprs.Names;
using fac.ASTs.Stmts;
using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	public class AstExpr_Is_Temp: IAstExpr {
		public IAstExpr Value { get; set; }
		public string IsWhat { init; get; }
		public AstStmt_DefVariable DefVar { get; set; }



		public static AstExpr_Is_Temp FromContext2 (IToken _token, IAstExpr _expr, string _is_what, string _var = "") {
			return new AstExpr_Is_Temp {
				Token = _token,
				Value = _expr,
				IsWhat = _is_what,
				DefVar = _var != "" ? new AstStmt_DefVariable {
					Token = _token,
					VarName = _var,
				} : null,
			};
		}

		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) {
			Value = Value.TraversalWrap (_trav);
			if (DefVar != null)
				DefVar = DefVar.TraversalWrap (_trav) as AstStmt_DefVariable;
		}

		public override IAstExpr TraversalCalcType (IAstType? _expect_type) {
			if (!Value.TraversalCalcTypeWrap (null, a => Value = a))
				return null;
			var _access = AstExprName_ClassEnum_Access.FromAccess (Value, IsWhat);
			if (DefVar.DataType == null)
				DefVar.DataType = _access.AttachVar.DataType;
			var _ret = AstExpr_Is.FromExistVar (_access, DefVar);
			return _ret.TraversalCalcTypeWrap (_expect_type, a => _ret = a as AstExpr_Is) ? _ret : null;
		}

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) => throw new Exception ("不应执行此处代码");

		public override IAstType GuessType () => IAstType.FromName ("bool");

		public override string GenerateCSharp (int _indent) => throw new Exception ("不应执行此处代码");

		public override string GenerateCpp (int _indent) => throw new Exception ("不应执行此处代码");

		public override bool AllowAssign () => false;
	}
}

using Antlr4.Runtime;
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
	public class AstExpr_Is: IAstExpr {
		public AstExprName_ClassEnum_Access AccessExpr { get; set; }
		public AstStmt_DefVariable DefVar { get; set; }
		public bool IsDefVar { get => DefVar != null; }



		private AstExpr_Is () { }

		public static AstExpr_Is FromAccess (AstExprName_ClassEnum_Access _access_expr, string _var) {
			return new AstExpr_Is {
				Token = _access_expr.Token,
				AccessExpr = _access_expr,
				DefVar = _var != "" ? new AstStmt_DefVariable {
					Token = _access_expr.Token,
					DataType = _access_expr.Class.GetClassType (),
					VarName = _var,
					Expr = _access_expr,
				} : null,
			};
		}

		public static AstExpr_Is FromContext2 (IToken _token, IAstExpr _expr, string _is_what, string _var = "") {
			if (_expr.ExpectType == null)
				_expr.ExpectType = _expr.GuessType ();
			var _access = AstExprName_ClassEnum_Access.FromAccess (_expr, _is_what);
			return FromAccess (_access, _var);
		}

		//public static AstExpr_Is FromContext (IToken _token, IAstExpr _src, string _is_what, string _var) {
		//	AstStmt_DefVariable _var_stmt = _var != "" ? new AstStmt_DefVariable { Token = _token, DataType = null, VarName = _var } : null;
		//	var _is_what_expr = AstExprName_ClassEnum_Access.FromAccess (null, _src, _is_what);
		//	if (_var_stmt != null) {
		//		_var_stmt.DataType = _is_what_expr.AttachType;
		//	}
		//	return new AstExpr_Is {
		//		Token = _token,
		//		Value = _src,
		//		IsWhatExpr = _is_what_expr,
		//		DefVar = _var_stmt,
		//	};
		//}

		//public static AstExpr_Is FromContext (IToken _token, IAstExpr _src, AstExprName_ClassEnum_Access _is_what_expr, string _var) {
		//	AstStmt_DefVariable _var_stmt = _var != "" ? new AstStmt_DefVariable { Token = _token, DataType = null, VarName = _var } : null;
		//	if (_var_stmt != null) {
		//		_var_stmt.DataType = _is_what_expr.AttachType;
		//		_is_what_expr.AttachExpr = _var_stmt.GetRef ();
		//	}
		//	return new AstExpr_Is {
		//		Token = _token,
		//		Value = _src,
		//		IsWhatExpr = _is_what_expr,
		//		DefVar = _var_stmt,
		//	};
		//}

		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) {
			if (AccessExpr != null)
				AccessExpr = AccessExpr.TraversalWrap (_trav) as AstExprName_ClassEnum_Access;
			if (IsDefVar)
				DefVar = DefVar.TraversalWrap (_trav) as AstStmt_DefVariable;
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (AccessExpr != null)
				AccessExpr = AccessExpr.TraversalCalcType (null) as AstExprName_ClassEnum_Access;
			// DefVar 为虚拟变量定义对象，不需要重新计算类型
			ExpectType = IAstType.FromName ("bool");
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () => IAstType.FromName ("bool");

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			if (DefVar != null)
				throw new CodeException (Token, "带解构的 is 表达式只支持在if判定条件中使用");
			var _expr = AstExpr_Op2.MakeCondition (
				new AstExpr_Op1 { Token = Token, Value = AccessExpr.Value, IsPrefix = false, Operator = ".__index__" },
				"==",
				IAstExpr.FromValue ("int", $"{AccessExpr.EnumItemIndex}")
			);
			return (new List<IAstStmt> (), _expr);
		}

		public (IAstExpr, List<IAstStmt>) ExpandExpr_If ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			var _expr = AstExpr_Op2.MakeCondition (
				new AstExpr_Op1 { Token = Token, Value = AccessExpr.Value, IsPrefix = false, Operator = ".__index__" },
				"==",
				IAstExpr.FromValue ("int", $"{AccessExpr.EnumItemIndex}")
			);
			var _stmts = new List<IAstStmt> ();
			if (DefVar != null) {
				_stmts.Add (DefVar);
				_stmts.Add (AstStmt_ExprWrap.MakeAssign (DefVar.GetRef (), new AstExpr_Op1 { Token = Token, Value = AccessExpr.Value, IsPrefix = false, Operator = $".{AccessExpr.AttachVar.Name}", ExpectType = AccessExpr.AttachVar.DataType }));
			}
			return (_expr, _stmts);
		}

		public override string GenerateCSharp (int _indent) => throw new Exception ("不应执行此处代码");

		public override bool AllowAssign () => false;
	}
}

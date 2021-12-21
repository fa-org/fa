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
		public IAstExpr Value { get; set; }
		public AstExprName_ClassEnum IsWhatExpr { get; set; }
		public AstStmt_DefVariable DefVar { get; set; }
		public bool IsDefVar { get => DefVar != null; }



		private AstExpr_Is () { }
		public static AstExpr_Is FromContext (IToken _token, IAstExpr _src, string _is_what, string _var) {
			AstStmt_DefVariable _var_stmt = _var != "" ? new AstStmt_DefVariable { Token = _token, DataType = null, VarName = _var } : null;
			var _is_what_expr = AstExprName_ClassEnum.FindFromName (_token, _is_what, _var_stmt?.GetRef () ?? null);
			if (_var_stmt != null) {
				_var_stmt.DataType = _is_what_expr.AttachType;
			}
			return new AstExpr_Is {
				Token = _token,
				Value = _src,
				IsWhatExpr = _is_what_expr,
				DefVar = _var_stmt,
			};
		}
		public static AstExpr_Is FromContext (IToken _token, IAstExpr _src, AstExprName_ClassEnum _is_what_expr, string _var) {
			AstStmt_DefVariable _var_stmt = _var != "" ? new AstStmt_DefVariable { Token = _token, DataType = null, VarName = _var } : null;
			if (_var_stmt != null) {
				_var_stmt.DataType = _is_what_expr.AttachType;
				_is_what_expr.AttachExpr = _var_stmt.GetRef ();
			}
			return new AstExpr_Is {
				Token = _token,
				Value = _src,
				IsWhatExpr = _is_what_expr,
				DefVar = _var_stmt,
			};
		}

		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) {
			if (Value != null)
				Value = Value.TraversalWrap (_trav);
			IsWhatExpr = IsWhatExpr.TraversalWrap (_trav) as AstExprName_ClassEnum;
			if (IsDefVar)
				DefVar = DefVar.TraversalWrap (_trav) as AstStmt_DefVariable;
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (Value != null)
				Value = Value.TraversalCalcType (null);
			// DefVar 为虚拟变量定义对象，不需要重新计算类型
			ExpectType = IAstType.FromName ("bool");
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () => IAstType.FromName ("bool");

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) => throw new CodeException (Token, "is 表达式只支持在if判定条件中使用");

		public (IAstExpr, List<IAstStmt>) ExpandExpr_If ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			var _expr = AstExpr_Op2.MakeCondition (
				new AstExpr_Op1 { Token = Token, Value = Value, IsPrefix = false, Operator = ".@index" },
				"==",
				IAstExpr.FromValue ("int", $"{IsWhatExpr.EnumItemIndex}")
			);
			var _stmts = new List<IAstStmt> ();
			if (DefVar != null) {
				_stmts.Add (DefVar);
				_stmts.Add (AstStmt_ExprWrap.MakeAssign (DefVar.GetRef (), new AstExpr_Op1 { Token = Token, Value = Value, IsPrefix = false, Operator = $".{IsWhatExpr.AttachName}", ExpectType = IsWhatExpr.AttachType }));
			}
			return (_expr, _stmts);
		}

		public override string GenerateCSharp (int _indent) => throw new Exception ("不应执行此处代码");

		public override bool AllowAssign () => false;
	}
}

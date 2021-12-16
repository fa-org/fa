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
		public string IsWhat { get; set; }
		public AstStmt_DefVariable DefVar { get; set; }
		public bool IsDefVar { get => DefVar.VarName != ""; }



		private AstExpr_Is () { }
		public static AstExpr_Is FromContext (IToken _token, IAstExpr _src, string _is_what, string _var) {
			var _expr = Info.GetCurrentFuncVariableFromName (_token, _is_what);
			if (_expr is AstExprName_ClassEnum _enum) {
				// TODO;
			}
			return new AstExpr_Is {
				Token = _token,
				Value = _src,
				IsWhat = _is_what,
				DefVar = new AstStmt_DefVariable { Token = _token, DataType = null, VarName = _var },
			};
		}

		public override void Traversal ((int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) _trav) {
			Value = Value.TraversalWrap (_trav);
			if (IsDefVar)
				DefVar = DefVar.TraversalWrap (_trav) as AstStmt_DefVariable;
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			Value = Value.TraversalCalcType (null);
			// DefVar 为虚拟变量定义对象，不需要重新计算类型
			ExpectType = IAstType.FromName ("bool");
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () => IAstType.FromName ("bool");

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			var (_stmts, _val) = Value.ExpandExpr (_cache_err);
			Value = _val;
			return (_stmts, this);
		}

		public override string GenerateCSharp (int _indent) => throw new CodeException (Token, "is 表达式只支持在if判定条件中使用");

		public (string, string) GenerateCSharp_IfExpr () {
			// TODO
			throw new NotImplementedException ();
		}

		public override bool AllowAssign () => Value.AllowAssign ();
	}
}

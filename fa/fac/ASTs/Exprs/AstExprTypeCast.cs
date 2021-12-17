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
	public class AstExprTypeCast: IAstExpr {
		public IAstExpr Value { get; set; }



		private AstExprTypeCast () { }

		public static IAstExpr Make (IAstExpr _dest, IAstType _to_type) {
			if (_dest.ExpectType == null) {
				throw new Exception ("应识别类型后做转换处理");
			} else if (AllowDirectReturn (_dest.ExpectType, _to_type)) {
				return _dest;
			} else if (_dest.ExpectType is AstType_OptionalWrap _owrap1 && AllowDirectReturn (_owrap1.ItemType, _to_type)) {
				return Make (AstExpr_AccessBuildIn.Optional_GetValue (_dest), _to_type);
			} else if (_to_type is AstType_OptionalWrap _owrap2 && AllowDirectReturn (_dest.ExpectType, _owrap2.ItemType)) {
				return Make (AstExpr_AccessBuildIn.Optional_FromValue (_dest), _to_type);
			} else {
				throw new CodeException (_dest.Token, $"类型 {_dest.ExpectType} 无法转为类型 {_to_type}");
			}
		}

		private static bool AllowDirectReturn (IAstType _src, IAstType _dest) {
			if (_dest == null || _dest is AstType_Any || _src.IsSame (_dest))
				return true;
			return false;
		}

		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) => Value = Value.TraversalWrap (_trav);

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			// 只有一种情况会调用到，提前构造好转换，也就是ExpectType设置好之后
			if (ExpectType == null)
				throw new NotImplementedException ();
			Value.TraversalCalcType (null);
			return this;
		}

		public override IAstType GuessType () => Value.GuessType ();

		public virtual (List<IAstStmt>, IAstExpr) ExpandExprAssign (IAstExpr _rval, (IAstExprName _var, AstStmt_Label _pos) _cache_err) {
			var (_stmts, _expr) = Value.ExpandExprAssign (_rval, _cache_err);
			Value = _expr;
			return (_stmts, this);
		}

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			var (_stmts, _expr) = Value.ExpandExpr (_cache_err);
			Value = _expr;
			return (_stmts, this);
		}

		public override string GenerateCSharp (int _indent) => $"({ExpectType.GenerateCSharp (_indent)}) {Value.GenerateCSharp (_indent)}";

		public override bool AllowAssign () => false;
	}
}

using fac.ASTs.Exprs.Names;
using fac.ASTs.Stmts;
using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	public class AstExpr_OptFromValue: IAstExpr {
		public IAstExpr Child { get; set; } = null;

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			throw new NotImplementedException ();
		}

		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) {
			throw new NotImplementedException ();
		}

		public override IAstType GuessType () {
			var _child_type = Child.GuessType ();
			if (_child_type is AstType_OptionalWrap) {
				return _child_type;
			} else {
				return new AstType_OptionalWrap { ItemType = _child_type };
			}
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (_expect_type is AstType_OptionalWrap _owrap_type) {
				Child = Child.TraversalCalcType (_owrap_type.ItemType);
				ExpectType = _expect_type;
				return this;
			}

			throw new Exception ("AstExpr_OptFromValue 对象的数据类型只能是 AstType_OptionalWrap");
		}

		public override string GenerateCSharp (int _indent) {
			throw new NotImplementedException ();
		}

		public override string GenerateCpp (int _indent) => $"{ExpectType.GenerateCpp (_indent)} ({Child.GenerateCpp (_indent)})";

		public override bool AllowAssign () => false;

		public static AstExpr_OptAccessValue Make (IAstExpr _expr) {
			return new AstExpr_OptAccessValue { Child = _expr, Token = _expr.Token };
		}
	}
}

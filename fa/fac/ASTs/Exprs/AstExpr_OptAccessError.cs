using fac.ASTs.Exprs.Names;
using fac.ASTs.Stmts;
using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	public class AstExpr_OptAccessError: IAstExpr {
		public IAstExpr Child { get; set; } = null;

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			throw new NotImplementedException ();
		}

		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) {
			throw new NotImplementedException ();
		}

		public override IAstType GuessType () {
			var _child_type = Child.GuessType ();
			if (_child_type is not AstType_OptionalWrap)
				throw new Exception ("子表达式类型只能是 AstType_OptionalWrap 类型");
			return new AstType_Error ();
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			//Child = Child.TraversalCalcType (new AstType_OptionalWrap { ItemType = _expect_type });
			if (_expect_type is not AstType_Error)
				throw new Exception ("返回类型只能是 AstType_Error 类型");
			ExpectType = _expect_type;
			return this;
		}

		public override string GenerateCSharp (int _indent) {
			throw new NotImplementedException ();
		}

		public override string GenerateCpp (int _indent) => $"std::get<1> ({Child.GenerateCpp (_indent)})";

		public override bool AllowAssign () => false;
	}
}

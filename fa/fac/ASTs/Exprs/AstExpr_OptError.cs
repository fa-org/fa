using fac.ASTs.Exprs.Names;
using fac.ASTs.Stmts;
using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	public class AstExpr_OptError: IAstExpr {
		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			throw new NotImplementedException ();
		}

		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) {
			throw new NotImplementedException ();
		}

		public override IAstType GuessType () => null;

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (_expect_type is not AstType_OptionalWrap && _expect_type is not ) {
				ExpectType = _expect_type;
				return this;
			} else {
				throw new NotImplementedException ();
			}
		}

		public override string GenerateCSharp (int _indent) {
			throw new NotImplementedException ();
		}

		public override string GenerateCpp (int _indent) {
			return Child == null ? "std::nullopt" : $"std::get<0> ({Child.GenerateCpp (_indent)})";
		}

		public override bool AllowAssign () => false;
	}
}

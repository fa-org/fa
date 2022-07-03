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
	public class AstExpr_OptOk: IAstExpr {
		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			return (new List<IAstStmt> (), this);
		}

		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) {
		}

		public override IAstType GuessType () => new AstType_Void ();

		public override IAstExpr TraversalCalcType (IAstType? _expect_type) {
			if (_expect_type is not AstType_Void)
				throw new Exception ("AstExpr_OptOk 对象的数据类型只能是 AstType_Void");
			ExpectType = _expect_type;
			return this;
		}

		public override string GenerateCSharp (int _indent) => throw new NotImplementedException ();

		public override string GenerateCpp (int _indent) => "std::nullopt";

		public override bool AllowAssign () => false;

		public static AstExpr_OptOk Make (IToken _token = null) => new AstExpr_OptOk { Token = _token };
	}
}

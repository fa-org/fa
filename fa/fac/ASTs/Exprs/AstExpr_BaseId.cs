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
	public class AstExpr_BaseId: IAstExpr {
		public string Id { get; set; }

		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) { }

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			throw new Exception ("执行类型处理步骤时不再允许出现 AstExpr_BaseId 类型对象");
		}

		public override IAstType GuessType () {
			throw new Exception ("执行类型处理步骤时不再允许出现 AstExpr_BaseId 类型对象");
		}

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos) _cache_err) => throw new Exception ("不应执行此处代码");

		public override string GenerateCSharp (int _indent) => throw new Exception ("不应执行此处代码");

		public override bool AllowAssign () => throw new UnimplException (Token);
	}
}

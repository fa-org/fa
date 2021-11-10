using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	class AstExpr_BaseId: IAstExpr {
		public string Id { get; set; }

		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) { }

		public override IAstExpr TraversalCalcType (string _expect_type) {
			throw new Exception ("执行类型处理步骤时不再允许出现 AstExpr_BaseId 类型对象");
		}

		public override string GuessType () {
			throw new Exception ("执行类型处理步骤时不再允许出现 AstExpr_BaseId 类型对象");
		}

		public override (string, string) GenerateCSharp (int _indent) => throw new UnimplException (Token);

		public override bool AllowAssign () => throw new UnimplException (Token);
	}
}

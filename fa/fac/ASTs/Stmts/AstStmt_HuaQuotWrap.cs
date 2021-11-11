using fac.ASTs.Exprs;
using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Stmts {
	class AstStmt_HuaQuotWrap: IAstStmt {
		public IAstStmt Stmt { get; set; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			Stmt = _cb (Stmt, _deep + 1, 0) as IAstStmt;
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (_expect_type != null)
				throw new Exception ("语句类型不可指定期望类型");
			Stmt = Stmt.TraversalCalcType ("") as IAstStmt;
			return this;
		}

		public override (string, string) GenerateCSharp (int _indent) {
			var _sb = new StringBuilder ();
			_sb.AppendLine ($"{_indent.Indent ()}{{");
			var (_a, _b) = Stmt.GenerateCSharp (_indent + 1);
			_sb.Append (_a).Append (_b);
			_sb.AppendLine ($"}}");
			return ("", _sb.ToString ());
		}
	}
}

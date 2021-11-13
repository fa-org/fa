using fac.ASTs.Exprs;
using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Stmts {
	class AstStmt_If: IAstStmt {
		public IAstExpr Condition { get; set; }
		public List<IAstStmt> IfTrueCodes { get; set; }
		public List<IAstStmt> IfFalseCodes { get; set; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			Condition = _cb (Condition, _deep, _group);
			IfTrueCodes.Traversal (_deep + 1, 0, _cb);
			IfFalseCodes.Traversal (_deep + 1, 1, _cb);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (_expect_type != null)
				throw new Exception ("语句类型不可指定期望类型");
			Condition = Condition.TraversalCalcType (IAstType.FromName ("bool"));
			IfTrueCodes.TraversalCalcType ();
			IfFalseCodes.TraversalCalcType ();
			return this;
		}

		public override (string, string) GenerateCSharp (int _indent) {
			var _sb = new StringBuilder ();
			var (_a, _b) = Condition.GenerateCSharp (_indent);
			_sb.AppendLine ($"{_a}{_indent.Indent ()}if ({_b}) {{");
			_sb.AppendStmts (IfTrueCodes, _indent + 1);
			if (IfFalseCodes.Any ()) {
				_sb.AppendLine ($"{_indent.Indent ()}}} else {{");
				_sb.AppendStmts (IfFalseCodes, _indent + 1);
			}
			_sb.AppendLine ($"{_indent.Indent ()}}}");
			return ("", _sb.ToString ());
		}
	}
}

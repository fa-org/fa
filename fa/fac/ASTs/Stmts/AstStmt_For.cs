using fac.ASTs.Exprs;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Stmts {
	class AstStmt_For: IAstStmt {
		public IAstStmt Initialize { get; set; }
		public IAstExpr Condition { get; set; }
		public List<IAstExpr> Increment { get; set; }
		public List<IAstStmt> BodyCodes { get; set; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			Initialize = _cb (Initialize, _deep, _group) as IAstStmt;
			Condition = _cb (Condition, _deep, _group);
			Increment.Traversal (_deep, _group, _cb);
			BodyCodes.Traversal (_deep + 1, 0, _cb);
		}

		public override IAstExpr TraversalCalcType (string _expect_type) {
			if (_expect_type != "")
				throw new Exception ("语句类型不可指定期望类型");
			Initialize = Initialize.TraversalCalcType ("") as IAstStmt;
			Condition = Condition.TraversalCalcType ("bool");
			Increment.TraversalCalcType ();
			BodyCodes.TraversalCalcType ();
			return this;
		}

		public override (string, string) GenerateCSharp (int _indent) {
			var _sb = new StringBuilder ();
			_sb.AppendLine ($"{_indent.Indent ()}{{");
			var (_a, _b) = Initialize.GenerateCSharp (_indent + 1);
			_sb.Append ($"{_a}{_b}");
			(_a, _b) = Condition.GenerateCSharp (_indent + 1);
			if (_a != "")
				_sb.Append ($"{(_indent + 1).Indent ()}{_a}");
			_sb.AppendLine ($"{(_indent + 1).Indent ()}while ({_b}) {{");
			_sb.AppendStmts (BodyCodes, _indent + 2);
			_sb.AppendExprs (Increment, _indent + 2);
			if (_a != "")
				_sb.Append ($"{(_indent + 2).Indent ()}{_a}");
			//
			_sb.AppendLine ($"{(_indent + 1).Indent ()}}}");
			_sb.AppendLine ($"{_indent.Indent ()}}}");
			return ("", _sb.ToString ());
		}
	}
}

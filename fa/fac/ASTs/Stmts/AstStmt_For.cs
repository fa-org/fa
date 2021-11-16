using fac.AntlrTools;
using fac.ASTs.Exprs;
using fac.ASTs.Types;
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

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (_expect_type != null)
				throw new Exception ("语句类型不可指定期望类型");
			Initialize = Initialize.TraversalCalcType (null) as IAstStmt;
			if (Info.CurrentFunc.ReturnType is AstType_OptionalWrap) {
				try {
					Condition = Condition.TraversalCalcType (IAstType.FromName ("bool"));
				} catch (Exception) {
					Condition = Condition.TraversalCalcType (IAstType.FromName ("bool?"));
				}
			} else {
				Condition = Condition.TraversalCalcType (IAstType.FromName ("bool"));
			}
			Increment.TraversalCalcType ();
			BodyCodes.TraversalCalcType ();
			return this;
		}

		public override (string, string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb) {
			var _sb = new StringBuilder ();
			var _ec = new ExprChecker (null);
			_sb.AppendLine ($"{_indent.Indent ()}{{");
			var (_a, _b, _c) = Initialize.GenerateCSharp (_indent + 1, _ec.CheckFunc);
			var (_e, _f) = _ec.GenerateCSharpPrefixSuffix (_indent + 1, Initialize.Token);
			_sb.Append ($"{_e}{_a}{_b}");
			_ec = new ExprChecker (null);
			string _d;
			(_a, _b, _d) = Condition.GenerateCSharp (_indent + 1, _ec.CheckFunc);
			var (_g, _h) = _ec.GenerateCSharpPrefixSuffix (_indent + 1, Condition.Token);
			_sb.AppendLine ($"{_g}{_a}{(_indent + 1).Indent ()}while ({_b}) {{");
			_sb.AppendStmts (BodyCodes, _indent + 2);
			_sb.AppendExprs (Increment, _indent + 2);
			var (_i, _j) = _ec.GenerateCSharpPrefixSuffix (_indent + 2, Condition.Token);
			_sb.Append ($"{_i}{_a}");
			//
			_sb.AppendLine ($"{(_indent + 1).Indent ()}}}");
			_sb.AppendLine ($"{_indent.Indent ()}}}");
			return ("", _sb.ToString (), $"{_c}{_d}{_f}{_h}{_j}");
		}
	}
}

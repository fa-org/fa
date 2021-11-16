using fac.AntlrTools;
using fac.ASTs.Exprs;
using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Stmts {
	class AstStmt_While: IAstStmt {
		public bool IsDoWhile { init; get; }
		public IAstExpr Condition { get; set; }
		public List<IAstStmt> Contents { get; set; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			if (!IsDoWhile)
				Condition = _cb (Condition, _deep + 1, 0);
			Contents.Traversal (_deep + 1, 0, _cb);
			if (IsDoWhile)
				Condition = _cb (Condition, _deep + 1, 0);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (_expect_type != null)
				throw new Exception ("语句类型不可指定期望类型");
			if (Info.CurrentFunc.ReturnType is AstType_OptionalWrap) {
				try {
					Condition = Condition.TraversalCalcType (IAstType.FromName ("bool"));
				} catch (Exception) {
					Condition = Condition.TraversalCalcType (IAstType.FromName ("bool?"));
				}
			} else {
				Condition = Condition.TraversalCalcType (IAstType.FromName ("bool"));
			}
			Contents.TraversalCalcType ();
			return this;
		}

		public override (string, string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb) {
			var _sb = new StringBuilder ();
			var _ec = new ExprChecker (null);
			var (_a, _b, _c) = Condition.GenerateCSharp (IsDoWhile ? (_indent + 1) : _indent, _ec.CheckFunc);
			string _d = "", _e = "";
			if (IsDoWhile) {
				_sb.AppendLine ($"{_indent.Indent ()}do {{");
			} else {
				(_d, _e) = _ec.GenerateCSharpPrefixSuffix (_indent, Condition.Token);
				_sb.AppendLine ($"{_d}{_a}{_indent.Indent ()}while ({_b}) {{");
			}
			_sb.AppendStmts (Contents, _indent + 1);
			if (IsDoWhile) {
				(_d, _e) = _ec.GenerateCSharpPrefixSuffix (_indent + 1, Condition.Token);
				_sb.AppendLine ($"{_d}{_a}{_indent.Indent ()}}} while ({_b});");
			} else {
				_sb.AppendLine ($"{_indent.Indent ()}}}");
			}
			return ("", _sb.ToString (), $"{_c}{_e}");
		}
	}
}

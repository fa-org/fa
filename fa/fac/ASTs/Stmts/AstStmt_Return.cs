using fac.AntlrTools;
using fac.ASTs.Exprs;
using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Stmts {
	class AstStmt_Return: IAstStmt {
		public IAstExpr Expr { get; set; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			if (Expr != null)
				Expr = _cb (Expr, _deep, _group);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (_expect_type != null)
				throw new Exception ("语句类型不可指定期望类型");
			if (Expr != null) {
				if (Info.CurrentFunc.ReturnType is AstType_OptionalWrap _otype) {
					try {
						Expr = Expr.TraversalCalcType (_otype.ItemType);
						Expr = AstExprTypeCast.Make (Expr, _otype);
					} catch (Exception) {
						Expr = Expr.TraversalCalcType (_otype);
					}
				} else {
					Expr = Expr.TraversalCalcType (Info.CurrentFunc.ReturnType);
				}
			}
			return this;
		}

		public override (string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb) {
			var _sb = new StringBuilder ();
			if (Expr != null) {
				var _ec = new ExprChecker (null);
				var (_a, _b) = Expr.GenerateCSharp (_indent, _ec.CheckFunc);
				_sb.AppendLine ($"{_a}{_ec.GenerateCSharp (_indent, Expr.Token)}{_indent.Indent ()}return {_b};");
			} else {
				_sb.AppendLine ($"{_indent.Indent ()}return;");
			}
			return ("", _sb.ToString ());
		}
	}
}

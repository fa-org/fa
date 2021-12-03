using fac.AntlrTools;
using fac.ASTs.Exprs;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Stmts {
	public class AstStmt_ExprWrap: IAstStmt {
		public IAstExpr Expr { get; set; }

		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			if (Expr != null)
				Expr = _cb (Expr, _deep, _group);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (_expect_type != null)
				throw new Exception ("语句类型不可指定期望类型");
			if (Expr != null) {
				Expr = Expr.TraversalCalcType (null);

				// 异常强制处理
				if ((!(Expr is AstExpr_Op2 _op2expr && _op2expr.Operator == "=")) && Expr.ExpectType is AstType_OptionalWrap)
					throw new CodeException (Token, "此处未处理异常必须处理");
			}
			return this;
		}

		public override List<IAstStmt> ExpandStmt () {
			var (_stmts, _expr) = Expr.ExpandExpr ();
			Expr = _expr;
			_stmts.Add (this);
			return _stmts;
		}

		public override string GenerateCSharp (int _indent) => $"{_indent.Indent ()}{Expr.GenerateCSharp (_indent)}";
	}
}

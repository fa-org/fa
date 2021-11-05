using fac.AntlrTools;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	interface IAstExpr {
		public static IAstExpr FromContext (FaParser.ExprContext _ctx) {
			var _expr_ctxs = _ctx.middleExpr ();
			var _op2_ctxs = _ctx.allAssign ();
			if (_expr_ctxs.Length == 0)
				throw new UnimplException (_ctx);
			//
			var _expr = FromContext (_expr_ctxs[_expr_ctxs.Length - 1]);
			for (int i = _expr_ctxs.Length - 2; i >= 0; --i) {
				var _expr2 = new AstExpr_Op2 ();
				_expr2.Value1 = FromContext (_expr_ctxs[i]);
				_expr2.Value2 = _expr;
				_expr2.Operator = _op2_ctxs[i].GetText ();
				_expr = _expr2;
			}
			return _expr;
		}

		public static IAstExpr FromContext (FaParser.MiddleExprContext _ctx) {
			var _exprs = (from p in _ctx.strongExpr () select FromContext (p)).ToList ();

			// 处理优先级
			var _op2s = (from p in _ctx.allOp2 () select p.ToString ()).ToList ();
			var _op2l = (from p in _op2s select Operators.Op2Priority[p]).ToList ();
			for (int i = 0; i < Operators.MaxPriorityNum && _exprs.Count > 1; ++i) {
				// 比较运算符特殊处理
				if (i == Operators.ComparePriorityNum) {
					// 检查是否有连续比较运算符，如有，那么合并为单独的结构
					TODO;
				}

				// 归并进AST
				for (int j = 0; j < _op2l.Count; ++j) {
					if (_op2l[j] != i)
						continue;

					// 合并
					var _expr = new AstExpr_Op2 ();
					_expr.Value1 = _exprs[j];
					_expr.Value2 = _exprs[j + 1];
					_expr.Operator = _op2s[j];
					_exprs[j] = _expr;
					_exprs.RemoveAt (j + 1);
					_op2s.RemoveAt (j);
					_op2l.RemoveAt (j);
					--j;
				}
			}
			return _exprs[0];
		}

		public static IAstExpr FromContext (FaParser.StrongExprContext _ctx) {
			var _expr = FromContext (_ctx.strongExprBase ());
			var _prefix_ctxs = _ctx.strongExprPrefix ();
			var _suffix_ctxs = _ctx.strongExprSuffix ();
			if (_expr is IAstExpr_IBase _b) {
				// 检测是否是完整类型，如果不是，并且后续是【.字符串】成员访问，那么拼接
			}
		}

		public static IAstExpr FromContext (FaParser.StrongExprBaseContext _ctx) {

		}
	}
}

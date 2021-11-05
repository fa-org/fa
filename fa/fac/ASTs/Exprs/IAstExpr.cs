using fac.AntlrTools;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	interface IAstExpr {
		public void CheckType (string _type) => throw new NotImplementedException ();



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
			var _op2s = (from p in _ctx.allOp2 () select p.GetText ()).ToList ();
			var _op2l = (from p in _op2s select Operators.Op2Priority[p]).ToList ();
			for (int i = 0; i < Operators.MaxPriorityNum && _exprs.Count > 1; ++i) {
				// 比较运算符特殊处理
				if (i == Operators.ComparePriorityNum) {
					// 检查是否有连续比较运算符，如有，那么合并为单独的结构
					int _start = -1;
					Action<int> _combine_func = (int _count) => {
						var _expr = new AstExpr_Op2N ();
						_expr.Values = _exprs.Skip (_start).Take (_count + 1).ToList ();
						_expr.Operators = _op2s.Skip (_start).Take (_count).ToList ();
						_exprs.RemoveRange (_start, _count);
						_op2s.RemoveRange (_start, _count);
						_op2l.RemoveRange (_start, _count);
						_exprs [_start] = _expr;
						_start = -1;
					};
					int _op_num;
					for (int j = 0; j < _op2l.Count; ++j) {
						if (_op2l[j] != Operators.ComparePriorityNum) {
							_op_num = _start == -1 ? 0 : (j - _start);
							if (_op_num > 1) {
								_combine_func (_op_num);
								j -= _op_num;
							}
							continue;
						} else {
							_start = _start != -1 ? _start : j;
						}
					}
					_op_num = _start == -1 ? 0 : (_op2l.Count - _start);
					if (_op_num > 1) {
						_combine_func (_op_num);
					}
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
			foreach (var _suffix_ctx in _suffix_ctxs) {
				if (_suffix_ctx.AddAddOp () != null || _suffix_ctx.SubSubOp () != null || _suffix_ctx.Id () != null) {
					var _tmp_expr = new AstExpr_Op1 ();
					_tmp_expr.Value1 = _expr;
					_tmp_expr.Operator = _suffix_ctx.GetText ();
					_tmp_expr.IsPrefix = false;
					_expr = _tmp_expr;
				} else if (_suffix_ctx.QuotYuanL () != null) {
					var _tmp_expr = new AstExpr_OpN ();
					_tmp_expr.Value = _expr;
					_tmp_expr.Operator = "()";
					_tmp_expr.Arguments = (from p in _suffix_ctx.expr () select FromContext (p)).ToList ();
					_expr = _tmp_expr;
				} else if (_suffix_ctx.QuotFangL () != null) {
					var _tmp_expr = new AstExpr_OpN ();
					_tmp_expr.Value = _expr;
					_tmp_expr.Operator = "[]";
					_tmp_expr.Arguments = (from p in _suffix_ctx.exprOpt () select p.expr () != null ? FromContext (p.expr ()) : null).ToList ();
					if (_tmp_expr.Arguments.Count == 1 && _tmp_expr.Arguments[0] == null)
						_tmp_expr.Arguments.Clear ();
					_expr = _tmp_expr;
				} else {
					throw new UnimplException (_suffix_ctx);
				}
			}
			foreach (var _prefix_ctx in _prefix_ctxs.Reverse ()) {
				var _tmp_expr = new AstExpr_Op1 ();
				_tmp_expr.Value1 = _expr;
				_tmp_expr.Operator = _prefix_ctx.GetText ();
				_tmp_expr.IsPrefix = true;
				_expr = _tmp_expr;
			}
			return _expr;
		}

		public static IAstExpr FromContext (FaParser.StrongExprBaseContext _ctx) {
			if (_ctx.Id () != null) {
				return new AstExpr_BaseId { Id = $"{(_ctx.ColonColon () != null ? _ctx.ColonColon ().GetText () : "")}{_ctx.Id ().GetText ()}" };
			} else if (_ctx.literal () != null) {
				string _type, _value = _ctx.GetText ();
				if (_ctx.literal ().BoolLiteral () != null) {
					_type = "bool";
				} else if (_ctx.literal ().intNum () != null) {
					_type = "int";
				} else if (_ctx.literal ().floatNum () != null) {
					_type = "float";
				} else if (_ctx.literal ().String1Literal () != null) {
					_type = "string";
				} else {
					throw new UnimplException (_ctx);
				}
				return new AstExpr_BaseValue { Type = _type, Value = _value };
			} else if (_ctx.ifExpr () != null) {
				//var _expr = new AstExpr_If ();
				var _exprs = (from p in _ctx.ifExpr ().expr () select FromContext (p)).ToList ();
				var _branches = (from p in _ctx.ifExpr ().quotStmtExpr () select (AstStmt.FromStmts (p.stmt ()), FromContext (p.expr ()))).ToList ();
				while (_exprs.Count > 0) {
					var _expr = new AstExpr_If ();
					_expr.Condition = _exprs[_exprs.Count - 1];
					(_expr.IfTrueCodes, _expr.IfTrue) = _branches[_branches.Count - 2];
					(_expr.IfFalseCodes, _expr.IfFalse) = _branches[_branches.Count - 1];
					_branches[_branches.Count - 2] = (new List<AstStmt> (), _expr);
					_exprs.RemoveAt (_exprs.Count - 1);
					_branches.RemoveAt (_branches.Count - 1);
				}
				if (_branches [0].Item1.Count > 0)
					throw new Exception ("校验错误，此处不应该出现stmt代码");
				return _branches[0].Item2;
			} else if (_ctx.quotExpr () != null) {
				return FromContext (_ctx.quotExpr ().expr ());
			} else if (_ctx.newExpr () != null) {

			} else if (_ctx.newArray () != null) {

			} else if (_ctx.arrayExpr1 () != null) {

			} else if (_ctx.arrayExpr2 () != null) {

			} else {
				throw new UnimplException (_ctx);
			}
		}
	}
}

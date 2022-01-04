using Antlr4.Runtime;
using fac.ASTs.Exprs.Names;
using fac.ASTs.Stmts;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	public class AstExpr_ArrayAPI_Temp: IAstExpr {
		public IAstExpr Value { get; set; } = null;
		public ArrayApiType AccessType { get; set; }



		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) {
			if (Value != null)
				Value = Value.TraversalWrap (_trav);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			bool _success = true;
			if (Value != null) {
				if (!Value.TraversalCalcTypeWrap (null, a => Value = a))
					_success = false;
			}
			if (ExpectType == null) {
				if (AccessType == ArrayApiType._AccessItem) {
					ExpectType = (Value.ExpectType as AstType_ArrayWrap).ItemType;
				}
			}
			return _success ? AstExprTypeCast.Make (this, _expect_type) : null;
		}

		public override IAstType GuessType () {
			if (ExpectType != null)
				return ExpectType;
			if (AccessType == ArrayApiType._AccessItem) {
				if (Value.GuessType () is AstType_ArrayWrap _owrap) {
					return _owrap.ItemType;
				} else {
					throw new CodeException (Token, "目标对象非数组类型，无法使用数组随机访问");
				}
			} else {
				throw new UnimplException (Token);
			}
		}

		private List<IAstStmt> InitExpand ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			var (_stmts, _val) = Value?.ExpandExpr (_cache_err) ?? (new List<IAstStmt> (), null);
			Value = _val;
			for (int i = 0; i < (AttachArgs?.Count ?? 0); ++i) {
				var (_stmts1, _val1) = AttachArgs[i].ExpandExpr (_cache_err);
				_stmts.AddRange (_stmts1);
				AttachArgs[i] = _val1;
			}
			return _stmts;
		}

		public override (List<IAstStmt>, IAstExpr) ExpandExprAssign (IAstExpr _rval, (IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			var _stmts = InitExpand (_cache_err);
			if (AccessType == ArrayApiType._AccessItem) {
				if (_cache_err == null)
					throw new CodeException (Token, "数组随机访问可能为空值，需处理或忽略异常");

				/* 生成逻辑： val [n]
				 * var idx = n;
				 * if (idx < 0)
				 *     idx += val.Length;
				 * if (idx < 0 || idx >= val.Length) {
				 *     _cache_err = err 数组随机访问下标超过数组大小;
				 * } else {
				 *     val [idx] = _rval;
				 *     val [idx]
				 * }
				 */

				// var idx;
				var _index_defvar = new AstStmt_DefVariable { Token = Token, DataType = IAstType.FromName ("int"), Expr = AstExprTypeCast.Make (AttachArgs[0], IAstType.FromName ("int")) };
				_stmts.Add (_index_defvar);

				// if (idx < 0)
				//     idx += val.Length;
				_stmts.Add (new AstStmt_If {
					Token = Token,
					Condition = AstExpr_Op2.MakeCondition (_index_defvar.GetRef (), "<", IAstExpr.FromValue ("int", "0")),
					IfTrueCodes = new List<IAstStmt> {
						// idx += val.Length;
						AstStmt_ExprWrap.MakeOp2 (_index_defvar.GetRef (), "+=", Array_Length (Value), IAstType.FromName ("int")),
					},
				});

				// if (idx < 0 || idx >= val.Length) {
				//     _cache_err = err 数组随机访问下标超过数组大小;
				// } else {
				//     val[idx] = _rval;
				// }
				var _val_idx = Array_AccessItem (Value, _index_defvar.GetRef (), false);
				var _if_stmt = new AstStmt_If {
					Token = Token,
					Condition = AstExpr_Op2.MakeCondition (
						AstExpr_Op2.MakeCondition (_index_defvar.GetRef (), "<", IAstExpr.FromValue ("int", "0")),
						"||",
						AstExpr_Op2.MakeCondition (_index_defvar.GetRef (), ">=", Array_Length (Value))
					),
					IfTrueCodes = new List<IAstStmt> { /*用户可能忽略异常，后面判断处理异常后再添加错误处理逻辑*/ },
					IfFalseCodes = new List<IAstStmt> { AstStmt_ExprWrap.MakeAssign (_val_idx, _rval), },
				};
				if (_cache_err?._var != null) {
					_if_stmt.IfTrueCodes.Add (AstStmt_ExprWrap.MakeAssign (_cache_err?._var, IAstExpr.OptionalFromError (null, _cache_err?._var.ExpectType, fa_Error.IndexOutOfBounds)));
					_if_stmt.IfTrueCodes.Add (_cache_err?._pos.GetRef ());
				}
				_stmts.Add (_if_stmt);
				return (_stmts, _val_idx);
			}
			return (_stmts, this);
		}

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			var _stmts = InitExpand (_cache_err);
			if (AccessType == ArrayApiType._AccessItem) {
				if (_cache_err == null || _cache_err == (null, null))
					throw new CodeException (Token, "数组随机访问可能为空值，需处理异常");

				/* 生成逻辑： val [n]
				 * var idx = n;
				 * if (idx < 0)
				 *     idx += val.Length;
				 * if (idx < 0 || idx >= val.Length) {
				 *     _cache_err = err 数组随机访问超限;
				 *     goto label;
				 * }
				 * val [idx]
				 */

				// var idx;
				var _index_defvar = new AstStmt_DefVariable { Token = Token, DataType = IAstType.FromName ("int"), Expr = AstExprTypeCast.Make (AttachArgs[0], IAstType.FromName ("int")) };
				_stmts.Add (_index_defvar);

				// if (idx < 0)
				//     idx += val.Length;
				_stmts.Add (new AstStmt_If {
					Token = Token,
					Condition = AstExpr_Op2.MakeCondition (_index_defvar.GetRef (), "<", IAstExpr.FromValue ("int", "0")),
					IfTrueCodes = new List<IAstStmt> {
						// idx += val.Length;
						AstStmt_ExprWrap.MakeOp2 (_index_defvar.GetRef (), "+=", Array_Length (Value), IAstType.FromName ("int")),
					},
				});

				// if (idx < 0 || idx >= val.Length) {
				//     _cache_err = err 数组随机访问超限;
				//     goto label;
				// }
				_stmts.Add (new AstStmt_If {
					Token = Token,
					Condition = AstExpr_Op2.MakeCondition (
						AstExpr_Op2.MakeCondition (_index_defvar.GetRef (), "<", IAstExpr.FromValue ("int", "0")),
						"||",
						AstExpr_Op2.MakeCondition (_index_defvar.GetRef (), ">=", Array_Length (Value))
					),
					IfTrueCodes = new List<IAstStmt> {
						AstStmt_ExprWrap.MakeAssign (_cache_err?._var, IAstType.OptionalFromError (Token, _cache_err?._var.ExpectType, fa_Error.IndexOutOfBounds)),
						_cache_err?._pos.GetRef (),
					},
				});

				return (_stmts, Array_AccessItem (Value, _index_defvar.GetRef (), false));
			}
			return (_stmts, this);
		}

		public override string GenerateCSharp (int _indent) => throw new Exception ("不应执行此处代码");

		public override bool AllowAssign () => AccessType == ArrayApiType._AccessItem && Value.AllowAssign ();

		public bool IsChangeData () => AccessType == ArrayApiType.Add;
	}
}

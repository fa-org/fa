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
	public enum AccessBuildInType { ARR_New, ARR_Length, ARR_Add, ARR_AccessItem, OPT_HasValue, OPT_GetValue, OPT_GetError, OPT_FromValue, OPT_FromError }
	public class AstExpr_AccessBuildIn: IAstExpr {
		public IAstExpr Value { get; set; } = null;
		public AccessBuildInType AccessType { get; set; }
		public List<IAstExpr> AttachArgs { get; set; } = null;



		private AstExpr_AccessBuildIn () { }
		public static IAstExpr Array_New (IAstType _type) => new AstExpr_AccessBuildIn { AccessType = AccessBuildInType.ARR_New, ExpectType = _type };
		public static IAstExpr Array_Length (IAstExpr _array) => new AstExpr_AccessBuildIn { Token = _array.Token, Value = _array, AccessType = AccessBuildInType.ARR_Length, ExpectType = IAstType.FromName ("int") };
		public static IAstExpr Array_Add (IAstExpr _array, IAstExpr _item) => new AstExpr_AccessBuildIn { Token = _array.Token, Value = _array, AccessType = AccessBuildInType.ARR_Add, AttachArgs = new List<IAstExpr> { _item }, ExpectType = new AstType_Void () };
		public static IAstExpr Array_AccessItem (IAstExpr _array, IAstExpr _index, bool _pre_expand) {
			IAstType _item_type = null;
			if (!_pre_expand) {
				if (_array.ExpectType is not AstType_ArrayWrap)
					throw new CodeException (_array.Token, "类型必须指定为数组类型");
				_item_type = (_array.ExpectType as AstType_ArrayWrap).ItemType;
			}
			return new AstExpr_AccessBuildIn { Token = _array.Token, Value = _array, AccessType = AccessBuildInType.ARR_AccessItem, AttachArgs = new List<IAstExpr> { _index }, ExpectType = _item_type };
		}
		public static IAstExpr Optional_HasValue (IAstExpr _opt) => new AstExpr_AccessBuildIn { Token = _opt.Token, AccessType = AccessBuildInType.OPT_HasValue, Value = _opt, ExpectType = IAstType.FromName ("bool") };
		public static IAstExpr Optional_NotHasValue (IAstExpr _opt) => new AstExpr_Op1 { Token = _opt.Token, Value = Optional_HasValue (_opt), IsPrefix = true, Operator = "!", ExpectType = IAstType.FromName ("bool") };
		public static IAstExpr Optional_GetValue (IAstExpr _opt) => new AstExpr_AccessBuildIn { Token = _opt.Token, Value = _opt, AccessType = AccessBuildInType.OPT_GetValue, ExpectType = (_opt.ExpectType as AstType_OptionalWrap).ItemType };
		public static IAstExpr Optional_GetError (IAstExpr _opt) => new AstExpr_AccessBuildIn { Token = _opt.Token, Value = _opt, AccessType = AccessBuildInType.OPT_GetError, ExpectType = IAstType.FromName ("string") };
		public static IAstExpr Optional_FromValue (IAstExpr _opt) => new AstExpr_AccessBuildIn { Token = _opt.Token, AccessType = AccessBuildInType.OPT_FromValue, Value = _opt, ExpectType = new AstType_OptionalWrap { Token = _opt.Token, ItemType = _opt.ExpectType } };
		public static IAstExpr Optional_FromError (IAstType _opt_type, IAstExpr _err) => new AstExpr_AccessBuildIn { Token = _err.Token, AccessType = AccessBuildInType.OPT_FromError, ExpectType = _opt_type, AttachArgs = new List<IAstExpr> { _err } };
		public static IAstExpr Optional_FromError (IAstType _opt_type, string _err) => Optional_FromError (_opt_type, IAstExpr.FromValue ("string", _err));

		public override void Traversal ((int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) _trav) {
			if (Value != null)
				Value = Value.TraversalWrap (_trav);
			if (AttachArgs != null)
				AttachArgs.TraversalWraps (_trav);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (Value != null)
				Value = Value.TraversalCalcType (null);
			for (int i = 0; i < (AttachArgs?.Count ?? 0); ++i) {
				AttachArgs[i] = AttachArgs[i].TraversalCalcType (null);
			}
			if (ExpectType == null) {
				if (AccessType == AccessBuildInType.ARR_AccessItem) {
					ExpectType = (Value.ExpectType as AstType_ArrayWrap).ItemType;
				}
			}
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () {
			if (ExpectType != null)
				return ExpectType;
			if (AccessType == AccessBuildInType.ARR_AccessItem) {
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
			//while (Value != null) {
			//	if (AccessType == AccessBuildInType.OPT_GetValue && Value is AstExpr_AccessBuildIn _biexpr1 && _biexpr1.AccessType == AccessBuildInType.OPT_FromValue) {
			//		Value = _biexpr1.Value;
			//	} else if (AccessType == AccessBuildInType.OPT_FromValue && Value is AstExpr_AccessBuildIn _biexpr2 && _biexpr2.AccessType == AccessBuildInType.OPT_GetValue) {
			//		Value = _biexpr2.Value;
			//	} else {
			//		break;
			//	}
			//}
			//
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
			if (AccessType == AccessBuildInType.ARR_AccessItem) {
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
					Condition = AstExpr_Op2.MakeCondition (AttachArgs[0], "<", IAstExpr.FromValue ("int", "0")),
					IfTrueCodes = new List<IAstStmt> {
						// idx += val.Length;
						AstStmt_ExprWrap.MakeOp2 (_index_defvar.GetRef (), "+=", AstExpr_AccessBuildIn.Array_Length (Value), IAstType.FromName ("int")),
					},
				});

				// if (idx < 0 || idx >= val.Length) {
				//     _cache_err = err 数组随机访问下标超过数组大小;
				// } else {
				//     val[idx] = _rval;
				// }
				var _val_idx = AstExpr_AccessBuildIn.Array_AccessItem (Value, _index_defvar.GetRef (), false);
				var _if_stmt = new AstStmt_If {
					Token = Token,
					Condition = AstExpr_Op2.MakeCondition (
						AstExpr_Op2.MakeCondition (_index_defvar.GetRef (), "<", IAstExpr.FromValue ("int", "0")),
						"||",
						AstExpr_Op2.MakeCondition (_index_defvar.GetRef (), ">=", AstExpr_AccessBuildIn.Array_Length (Value))
					),
					IfTrueCodes = new List<IAstStmt> { /*用户可能忽略异常，后面判断处理异常后再添加错误处理逻辑*/ },
					IfFalseCodes = new List<IAstStmt> { AstStmt_ExprWrap.MakeAssign (_val_idx, _rval), },
				};
				if (_cache_err?._var != null) {
					_if_stmt.IfTrueCodes.Add (AstStmt_ExprWrap.MakeAssign (_cache_err?._var, AstExpr_AccessBuildIn.Optional_FromError (_cache_err?._var.ExpectType, IAstExpr.FromValue ("string", "数组随机访问下标超过数组大小"))));
					_if_stmt.IfTrueCodes.Add (_cache_err?._pos.GetRef ());
				}
				_stmts.Add (_if_stmt);
				return (_stmts, _val_idx);
			}
			return (_stmts, this);
		}

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			var _stmts = InitExpand (_cache_err);
			if (AccessType == AccessBuildInType.ARR_AccessItem) {
				if (_cache_err == null)
					throw new CodeException (Token, "数组随机访问可能为空值，需处理或忽略异常");

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
					Condition = AstExpr_Op2.MakeCondition (AttachArgs[0], "<", IAstExpr.FromValue ("int", "0")),
					IfTrueCodes = new List<IAstStmt> {
						// idx += val.Length;
						AstStmt_ExprWrap.MakeOp2 (_index_defvar.GetRef (), "+=", AstExpr_AccessBuildIn.Array_Length (Value), IAstType.FromName ("int")),
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
						AstExpr_Op2.MakeCondition (_index_defvar.GetRef (), ">=", AstExpr_AccessBuildIn.Array_Length (Value))
					),
					IfTrueCodes = new List<IAstStmt> {
						AstStmt_ExprWrap.MakeAssign (_cache_err?._var, AstExpr_AccessBuildIn.Optional_FromError (_cache_err?._var.ExpectType, IAstExpr.FromValue ("string", "数组随机访问下标超过数组大小"))),
						_cache_err?._pos.GetRef (),
					},
					IfFalseCodes = new List<IAstStmt> (),
				});

				return (_stmts, AstExpr_AccessBuildIn.Optional_FromValue (AstExpr_AccessBuildIn.Array_AccessItem (Value, _index_defvar.GetRef (), false)));
			}
			return (_stmts, this);
		}

		public override string GenerateCSharp (int _indent) {
			var _b = Value?.GenerateCSharp (_indent) ?? "";
			var _exp = ExpectType?.GenerateCSharp (_indent) ?? "";
			var _attach0 = (AttachArgs?.Count ?? 0) > 0 ? AttachArgs[0].GenerateCSharp (_indent) : "";
			return AccessType switch {
				AccessBuildInType.ARR_New => $"new {_exp} ()",
				AccessBuildInType.ARR_Length => $"{_b}.Count",
				AccessBuildInType.ARR_Add => $"{_b}.Add ({_attach0})",
				AccessBuildInType.ARR_AccessItem => $"{_b} [{_attach0}]",
				AccessBuildInType.OPT_HasValue => $"{_b}.HasValue ()",
				AccessBuildInType.OPT_GetValue => $"{_b}.GetValue ()",
				AccessBuildInType.OPT_GetError => $"{_b}.GetError ()",
				AccessBuildInType.OPT_FromValue => $"{_exp}.FromValue ({_b})",
				AccessBuildInType.OPT_FromError => $"{_exp}.FromError ({_attach0})",
				_ => throw new NotImplementedException (),
			};
		}

		public override bool AllowAssign () => AccessType == AccessBuildInType.ARR_AccessItem && Value.AllowAssign ();
	}
}

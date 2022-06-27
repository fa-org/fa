using Antlr4.Runtime;
using fac.ASTs.Exprs.Names;
using fac.ASTs.Stmts;
using fac.ASTs.Types;
using fac.ASTs.Types.Mappings;
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
		public List<IAstExpr> AttachArgs { get; set; } = null;



		public static IAstExpr Array_AccessItem (IAstExpr _array, IAstExpr _index, bool _pre_expand) {
			IAstType _item_type = null;
			if (!_pre_expand) {
				if (_array.ExpectType is AstType_ArrayWrap _arr_type) {
					_item_type = _arr_type.ItemType;
				} else {
					throw new CodeException (_array.Token, "类型必须指定为数组类型");
				}
			}
			return new AstExpr_ArrayAPI_Temp { Token = _array.Token, Value = _array, AccessType = ArrayApiType._AccessItem, AttachArgs = new List<IAstExpr> { _index }, ExpectType = _item_type };
		}

		public static AstExpr_ArrayAPI_Temp Array_MakeMethodAccess (IAstExpr _array, string _type) {
			ArrayApiType _access_type = _type switch {
				"Add" => ArrayApiType.Add,
				"AddRange" => ArrayApiType.AddRange,
				"RemoveAt" => ArrayApiType.RemoveAt,
				"IndexOf" => ArrayApiType.IndexOf,
				"LastIndexOf" => ArrayApiType.LastIndexOf,
				_ => throw new CodeException (_array.Token, $"无法识别的数组方法 {_type}"),
			};
			return new AstExpr_ArrayAPI_Temp { Token = _array.Token, Value = _array, AccessType = _access_type };
		}

		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) {
			if (Value != null)
				Value = Value.TraversalWrap (_trav);
			if (AttachArgs != null)
				AttachArgs.TraversalWraps (_trav);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (Value != null) {
				if (!Value.TraversalCalcTypeWrap (null, a => Value = a))
					return null;
				if (Value.ExpectType is AstType_ArrayWrap _arr_wrap) {
					AttachArgs[0].TraversalCalcTypeWrap (IAstType.FromName ("int"), a => AttachArgs[0] = a);
					ExpectType = _arr_wrap.ItemType;
				} else if (Value.ExpectType is AstTypeMap_Dictionary _dic_type) {
					//AttachArgs[0].TraversalCalcTypeWrap (_dic_type.KeyType, a => AttachArgs[0] = a);
					//ExpectType = _dic_type.ValueType
				}
			}
			return AstExprTypeCast.Make (this, _expect_type);
			//if (AttachArgs != null) {
			//	_success &= AttachArgs.TraversalCalcTypeWrap ();
			//}
			//if (ExpectType == null) {
			//	if (AccessType == ArrayApiType._AccessItem) {
			//		ExpectType = (Value.ExpectType as AstType_ArrayWrap).ItemType;
			//	}
			//}
			//return _success ? AstExprTypeCast.Make (this, _expect_type) : null;
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
						AstStmt_ExprWrap.MakeOp2 (_index_defvar.GetRef (), "+=", AstExpr_ArrayAPI.Array_Length (Value), IAstType.FromName ("int")),
					},
				});

				// if (idx < 0 || idx >= val.Length) {
				//     _cache_err = err 数组随机访问下标超过数组大小;
				// } else {
				//     val[idx] = _rval;
				// }
				var _val_idx = AstExpr_ArrayAPI.Array_AccessItem (Value, _index_defvar.GetRef (), false);
				var _if_stmt = new AstStmt_If {
					Token = Token,
					Condition = AstExpr_Op2.MakeCondition (
						AstExpr_Op2.MakeCondition (_index_defvar.GetRef (), "<", IAstExpr.FromValue ("int", "0")),
						"||",
						AstExpr_Op2.MakeCondition (_index_defvar.GetRef (), ">=", AstExpr_ArrayAPI.Array_Length (Value))
					),
					IfTrueCodes = new List<IAstStmt> { /*用户可能忽略异常，后面判断处理异常后再添加错误处理逻辑*/ },
					IfFalseCodes = new List<IAstStmt> { AstStmt_ExprWrap.MakeAssign (_val_idx, _rval), },
				};
				if (_cache_err?._var != null) {
					_if_stmt.IfTrueCodes.Add (AstStmt_ExprWrap.MakeAssign (_cache_err?._var, IAstExpr.OptionalFromError (null, _cache_err?._var.ExpectType, fa_Error.IndexOutOfBounds)));
					_if_stmt.IfTrueCodes.Add (_cache_err?._pos.Goto ());
				}
				_stmts.Add (_if_stmt);
				return (_stmts, _val_idx);
			} else {
				throw new Exception ("不应执行此处代码");
				//var _new_obj = new AstExpr_ArrayAPI { Token = Token, Value = Value, AccessType = AccessType, AttachArgs = AttachArgs, ExpectType = ExpectType };
				//return (_stmts, _new_obj);
			}
		}

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			var _stmts = InitExpand (_cache_err);
			if (AccessType == ArrayApiType._AccessItem) {
				if (_cache_err == null || _cache_err == (null, null)) // TODO 这个错误需 ?? 运算符给前者指定 _catch_err
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
						AstStmt_ExprWrap.MakeOp2 (_index_defvar.GetRef (), "+=", AstExpr_ArrayAPI.Array_Length (Value), IAstType.FromName ("int")),
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
						AstExpr_Op2.MakeCondition (_index_defvar.GetRef (), ">=", AstExpr_ArrayAPI.Array_Length (Value))
					),
					IfTrueCodes = new List<IAstStmt> {
						AstStmt_ExprWrap.MakeAssign (_cache_err?._var, IAstType.OptionalFromError (Token, _cache_err?._var.ExpectType, fa_Error.IndexOutOfBounds)),
						_cache_err?._pos.Goto (),
					},
				});

				return (_stmts, AstExpr_ArrayAPI.Array_AccessItem (Value, _index_defvar.GetRef (), false));
			} else if (AccessType == ArrayApiType.IndexOf || AccessType == ArrayApiType.LastIndexOf) {
				var _defvar_temp_stmt = new AstStmt_DefVariable {
					Token = Token,
					DataType = IAstType.FromName ("int"),
					Expr = new AstExpr_ArrayAPI { Token = Token, Value = Value, AccessType = AccessType, AttachArgs = AttachArgs, ExpectType = ExpectType },
				};
				_stmts.Add (_defvar_temp_stmt);
				var _defvar_stmt = new AstStmt_DefVariable {
					Token = Token,
					DataType = IAstType.FromName ("int?"),
				};
				_stmts.Add (_defvar_stmt);
				_stmts.Add (new AstStmt_If {
					Token = Token,
					Condition = AstExpr_Op2.MakeCondition (_defvar_temp_stmt.GetRef (), ">=", IAstExpr.FromValue ("int", "0")),
					IfTrueCodes = AstStmt_ExprWrap.MakeAssign (_defvar_stmt.GetRef (), _defvar_temp_stmt.GetRef ()).ExpandStmt (_cache_err),
					IfFalseCodes = AstStmt_ExprWrap.MakeAssign (_defvar_stmt.GetRef (), IAstExpr.OptionalFromError (Token, _defvar_stmt.DataType, fa_Error.NotFound)).ExpandStmt (_cache_err),
				});
				return (_stmts, _defvar_stmt.GetRef ());
			} else {
				throw new Exception ("不应执行此处代码");
				//var _new_obj = new AstExpr_ArrayAPI { Token = Token, Value = Value, AccessType = AccessType, AttachArgs = AttachArgs, ExpectType = ExpectType };
				//return (_stmts, _new_obj);
			}
		}

		public override string GenerateCSharp (int _indent) => throw new Exception ("不应执行此处代码");

		public override string GenerateCpp (int _indent) => throw new Exception ("不应执行此处代码");

		public override bool AllowAssign () => AccessType == ArrayApiType._AccessItem && Value.AllowAssign ();
	}
}

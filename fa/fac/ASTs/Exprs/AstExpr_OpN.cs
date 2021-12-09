using fac.AntlrTools;
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
	public class AstExpr_OpN: IAstExpr {
		public IAstExpr Value { get; set; }
		public string Operator { get; set; }
		public List<IAstExpr> Arguments { get; set; }



		private void CheckArguments (AstType_Func _functype) {
			if (_functype.ArgumentTypes.Count > 0 && _functype.ArgumentTypes[^1] is AstType_ArrayWrap _arrtype && _arrtype.Params) {
				if (Arguments.Count < _functype.ArgumentTypes.Count - 1)
					throw new CodeException (Token, "函数调用传入的参数数量不匹配");
				for (int i = 0; i < _functype.ArgumentTypes.Count - 1; ++i)
					Arguments[i] = Arguments[i].TraversalCalcType (_functype.ArgumentTypes[i]);
				if (_functype.ArgumentTypes.Count == Arguments.Count) {
					try {
						Arguments[^1] = Arguments[^1].TraversalCalcType (_functype.ArgumentTypes[^1]);
						return;
					} catch (Exception) {
					}
				}
				for (int i = _functype.ArgumentTypes.Count - 1; i < Arguments.Count; ++i)
					Arguments[i] = Arguments[i].TraversalCalcType (_arrtype.ItemType);
			} else {
				if (_functype.ArgumentTypes.Count != Arguments.Count)
					throw new CodeException (Token, "函数调用传入的参数数量不匹配");
				for (int i = 0; i < _functype.ArgumentTypes.Count; ++i)
					Arguments[i] = Arguments[i].TraversalCalcType (_functype.ArgumentTypes[i]);
			}
		}

		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			Value = _cb (Value, _deep, 0);
			for (int i = 0; i < Arguments.Count; ++i)
				Arguments[i] = _cb (Arguments[i], _deep, _group);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			Value = Value.TraversalCalcType (null);
			if (Value is AstExprName_ClassFunc _funcexpr) {
				if (_funcexpr.ThisObject != null)
					Arguments.Insert (0, _funcexpr.ThisObject);
				CheckArguments (_funcexpr.Class.ClassFuncs[_funcexpr.FunctionIndex].FuncType);
				if (_funcexpr.ThisObject != null)
					Arguments.RemoveAt (0);
				ExpectType = _funcexpr.Class.ClassFuncs[_funcexpr.FunctionIndex].ReturnType;
				return AstExprTypeCast.Make (this, _expect_type);
			} else {
				if (Value is AstExprName_BuildIn _biexpr)
					Value.GuessType ();
				if (Value.ExpectType is AstType_Func _functype) {
					CheckArguments (_functype);
					ExpectType = _functype.ReturnType;
					return AstExprTypeCast.Make (this, _expect_type);
				} else if (Value.ExpectType is AstType_ArrayWrap _arrtype && Operator == "[]") {
					ExpectType = new AstType_OptionalWrap { Token = Token, ItemType = _arrtype.ItemType };
					return AstExprTypeCast.Make (this, _expect_type);
				} else {
					throw new CodeException (Token, "表达式无法当做方法进行调用");
				}
			}
		}

		public override IAstType GuessType () {
			if (Value is AstExprName_ClassFunc _funcexpr) {
				return _funcexpr.Class.ClassFuncs[_funcexpr.FunctionIndex].ReturnType;
			} else if (Operator == "[]") {
				return new AstType_OptionalWrap { Token = Token, ItemType = (Value.GuessType () as AstType_ArrayWrap).ItemType };
			} else {
				return (Value.GuessType () as AstType_Func).ReturnType;
			}
		}

		public override (List<IAstStmt>, IAstExpr) ExpandExprAssign (IAstExpr _rval, (IAstExprName _var, AstStmt_Label _pos) _cache_err) {
			var (_stmts, _val) = Value.ExpandExpr (_cache_err, _check_cb);
			Value = _val;
			if (Operator == "[]") {
				if (Arguments.Count != 1)
					throw new CodeException (Token, "随机访问操作仅支持一个参数");
				/* 生成逻辑： val [n]
				 * var idx = n;
				 * if (idx < 0)
				 *     idx += val.Length;
				 * if (idx < 0 || idx >= val.Length) {
				 *     _cache_err = err 数组随机访问下标超过数组大小;
				 *     goto _cache_err;
				 * } else {
				 *     val [idx] = _rval;
				 *     val [idx]
				 * }
				 */

				// var idx;
				var _index_defvar = new AstStmt_DefVariable { Token = Token, DataType = IAstType.FromName ("int"), Expr = AstExprTypeCast.Make (Arguments[0], IAstType.FromName ("int")) };
				_stmts.AddRange (_index_defvar.ExpandStmt (_cache_err));

				// if (idx < 0)
				//     idx += val.Length;
				var (_stmts1, _val1) = Arguments[0].ExpandExpr (_cache_err, _check_cb);
				_stmts.AddRange (_stmts1);
				_stmts.Add (new AstStmt_If {
					Token = Token,
					Condition = AstExpr_Op2.MakeCondition (_val1, "<", IAstExpr.FromValue ("int", "0")),
					IfTrueCodes = new List<IAstStmt> {
						// idx += val.Length;
						AstStmt_ExprWrap.MakeOp2 (_index_defvar.GetRef (), "+=", AstExpr_AccessBuildIn.Array_Length (Value), IAstType.FromName ("int")),
					},
				});

				// if (idx < 0 || idx >= val.Length) {
				//     _cache_err = err 数组随机访问下标超过数组大小;
				//     goto _cache_err;
				// } else {
				//     val[idx] = _rval;
				// }
				var _val_idx = AstExpr_AccessBuildIn.Array_AccessItem (Value, _index_defvar.GetRef ());
				_stmts.Add (new AstStmt_If {
					Token = Token,
					Condition = AstExpr_Op2.MakeCondition (
						AstExpr_Op2.MakeCondition (_index_defvar.GetRef (), "<", IAstExpr.FromValue ("int", "0")),
						"||",
						AstExpr_Op2.MakeCondition (_index_defvar.GetRef (), ">=", AstExpr_AccessBuildIn.Array_Length (Value))
					),
					IfTrueCodes = new List<IAstStmt> {
						AstStmt_ExprWrap.MakeAssign (_cache_err._var, AstExpr_AccessBuildIn.Optional_FromError (_cache_err._var.ExpectType, IAstExpr.FromValue ("string", "数组随机访问下标超过数组大小"))),
					},
					IfFalseCodes = new List<IAstStmt> {
						AstStmt_ExprWrap.MakeAssign (_val_idx, _rval),
					},
				});
				return (_stmts, _val_idx);
			} else {
				throw new CodeException (Token, $"方法调用表达式无法赋值");
			}
		}

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos) _cache_err) {
			var (_stmts, _val) = Value.ExpandExpr (_cache_err, _check_cb);
			Value = _val;
			if (Operator == "[]") {
				// 随机访问
				if (Arguments.Count != 1)
					throw new CodeException (Token, "随机访问操作仅支持一个参数");
				/* 生成逻辑： val [n]
				 * var _item_defvar;
				 * var idx = n;
				 * if (idx < 0)
				 *     idx += val.Length;
				 * if (idx < 0 || idx >= val.Length) {
				 *     _item_defvar = err 数组随机访问超限;
				 * } else {
				 *     _item_defvar = val [idx];
				 * }
				 * _item_defvar
				 */

				// var _item_defvar;
				var _item_defvar = new AstStmt_DefVariable { Token = Token, DataType = ExpectType, Expr = null };
				_stmts.Add (_item_defvar);

				// 给 _item_defvar 赋完值后的处理逻辑
				var _err_stmt = new AstStmt_Label { Token = null };
				_cache_err = (_var: _item_defvar.GetRef (), _pos: _err_stmt);

				// var idx;
				var _index_defvar = new AstStmt_DefVariable { Token = Token, DataType = IAstType.FromName ("int"), Expr = AstExprTypeCast.Make (Arguments[0], IAstType.FromName ("int")) };
				_stmts.AddRange (_index_defvar.ExpandStmt (_cache_err));

				// if (idx < 0)
				//     idx += val.Length;
				var (_stmts1, _val1) = Arguments[0].ExpandExpr (_cache_err, _check_cb);
				_stmts.AddRange (_stmts1);
				_stmts.Add (new AstStmt_If {
					Token = Token,
					Condition = AstExpr_Op2.MakeCondition (_val1, "<", IAstExpr.FromValue ("int", "0")),
					IfTrueCodes = new List<IAstStmt> {
						// idx += val.Length;
						AstStmt_ExprWrap.MakeOp2 (_index_defvar.GetRef (), "+=", AstExpr_AccessBuildIn.Array_Length (Value), IAstType.FromName ("int")),
					},
				});

				// if (idx < 0 || idx >= val.Length) {
				//     _item_defvar = err 数组随机访问下标超过数组大小;
				// } else {
				//     _item_defvar = val[idx];
				// }
				_stmts.Add (new AstStmt_If {
					Token = Token,
					Condition = AstExpr_Op2.MakeCondition (
						AstExpr_Op2.MakeCondition (_index_defvar.GetRef (), "<", IAstExpr.FromValue ("int", "0")),
						"||",
						AstExpr_Op2.MakeCondition (_index_defvar.GetRef (), ">=", AstExpr_AccessBuildIn.Array_Length (Value))
					),
					IfTrueCodes = new List<IAstStmt> {
						AstStmt_ExprWrap.MakeAssign (_item_defvar.GetRef (), AstExpr_AccessBuildIn.Optional_FromError (_item_defvar.DataType, IAstExpr.FromValue ("string", "数组随机访问下标超过数组大小"))),
					},
					IfFalseCodes = new List<IAstStmt> {
						AstStmt_ExprWrap.MakeAssign (_item_defvar.GetRef (), AstExpr_AccessBuildIn.Optional_FromValue (AstExpr_AccessBuildIn.Array_AccessItem (Value, _index_defvar.GetRef ()))),
					},
				});

				// 下标错误部分
				_stmts.Add (_err_stmt);
				return (_stmts, _item_defvar.GetRef ());
			} else {
				for (int i = 0; i < Arguments.Count; ++i) {
					(_stmts, _val) = Arguments[i].ExpandExpr (_cache_err, _check_cb);
					_stmts.AddRange (_stmts);
					Arguments[i] = _val;
				}

				var _arg_types = (Value.ExpectType as AstType_Func).ArgumentTypes;
				if (Value is AstExprName_ClassFunc _funcexpr && _funcexpr.ThisObject != null)
					_arg_types = _arg_types.Skip (1).ToList ();
				// 如果最后一个参数为params列表
				if (_arg_types.Count > 0 && _arg_types[^1] is AstType_ArrayWrap _awrap && _awrap.Params && Value is not AstExprName_BuildIn) {
					bool _process_last = _arg_types.Count == Arguments.Count && Arguments[^1].ExpectType.IsSame (_awrap);
					if (!_process_last) {
						// 用户未处理
						(_stmts, _val) = new AstExpr_Array { Token = Arguments[_arg_types.Count - 1].Token, ItemDataType = _awrap.ItemType, InitValues = Arguments.Skip (_arg_types.Count - 1).ToList (), ExpectType = _awrap }.ExpandExpr (_cache_err, _check_cb);
						Arguments.RemoveRange (_arg_types.Count - 1, Arguments.Count - (_arg_types.Count - 1));
						_stmts.AddRange (_stmts);
						Arguments.Add (_val);
					}
				}
				return (_stmts, this);
			}
		}

		public override string GenerateCSharp (int _indent) {
			if (Operator != "()")
				throw new Exception ("不应执行此处代码");

			var _sb = new StringBuilder ();
			var _arg_types = (Value.ExpectType as AstType_Func).ArgumentTypes;
			if (Value is AstExprName_ClassFunc _funcexpr && _funcexpr.ThisObject != null)
				_arg_types = _arg_types.Skip (1).ToList ();
			var _b = Value.GenerateCSharp (_indent);
			_sb.Append ($"{_b} (");
			for (int i = 0; i < Arguments.Count; ++i) {
				_b = Arguments[i].GenerateCSharp (_indent);
				if (_arg_types[i].Mut)
					_sb.Append ($"ref ");
				_sb.Append ($"{_b}, ");
			}
			if (Value is AstExprName_BuildIn _biexpr && _biexpr.Name.EndsWith ("AllText"))
				_sb.Append ($"Encoding.UTF8, ");
			if (Arguments.Any ())
				_sb.Remove (_sb.Length - 2, 2);
			_sb.Append (Operator[1]);
			return _sb.ToString ();
		}

		public override bool AllowAssign () => Operator == "[]" ? Value.AllowAssign () : false;
	}
}

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

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos) _cache_err, Action<IAstExpr, IAstExpr> _check_cb) {
			var (_stmts, _val) = Value.ExpandExpr (_cache_err, _check_cb);
			Value = _val;
			for (int i = 0; i < Arguments.Count; ++i) {
				var (_stmts1, _val1) = Arguments[i].ExpandExpr (_cache_err, _check_cb);
				_stmts.AddRange (_stmts1);
				Arguments[i] = _val1;
			}
			if (Operator == "[]") {
				if (Arguments.Count != 1)
					throw new CodeException (Token, "随机访问操作仅支持一个参数");
				/* 生成逻辑： val [n]
				 * var _tmpval000;
				 * var idx = n;
				 * if (idx < 0)
				 *     idx += val.Length;
				 * if (idx < 0 || idx >= val.Length) {
				 *     _tmpval000 = err 数组随机访问超限;
				 * } else {
				 *     _tmpval000 = val [idx];
				 * }
				 * _tmpval000
				 */
				// var _tmpval000;
#warning TODO: 此处不用传递参数，主要以生成逻辑为主
				var _item_id = Common.GetTempId ();
				var _item_defvar = new AstStmt_DefVariable { Token = Token, DataType = ExpectType, VarName = _item_id, Expr = null };
				_stmts.Add (_item_defvar);

				// var idx = n;
				var _index_id = Common.GetTempId ();
				var _index_defvar = new AstStmt_DefVariable { Token = Token, DataType = IAstType.FromName ("int"), VarName = _index_id, Expr = AstExprTypeCast.Make (Arguments[0], IAstType.FromName ("int")) };
				_stmts.AddRange (_index_defvar.ExpandStmt ());

				// if (idx < 0)
				_stmts.Add (new AstStmt_If {
					Token = Token,
					Condition = new AstExpr_Op2 { Token = Token, Value1 = Arguments[0], Value2 = IAstExpr.FromValue ("int", "0"), Operator = "<", ExpectType = IAstType.FromName ("bool") },
					IfTrueCodes = new List<IAstStmt> {
						// idx += val.Length;
						new ast
					},
				});
				//if (idx < 0 || idx >= val.Length) {
				//	_tmpval000 = err 数组随机访问超限;
				//} else {
				//	_tmpval000 = val[idx];
				//}
			} else {
				return (_stmts, this);
			}
		}

		public override string GenerateCSharp (int _indent) {
			var _sb = new StringBuilder ();
			if (Operator == "[]") {
				var _stmts = new List<IAstStmt> ();
				if (Value.ExpectType is AstType_ArrayWrap && Arguments.Count == 1 && Arguments[0].ExpectType is AstType_Integer && _GenCSharpLevel == _GenLevel.NeedVarWrap) {
					// TODO: 生成新的expr对象，_Judge设置为false
					/* val [3+4+6]
					 * int a = 3+4+6;
					 * if (a < 0)
					 *     a += val.Length;
					 * if (a < 0)
					 *     // check_cb
					 * if (a >= val.Length)
					 *     // check_cb
					 * val [a]
					 */
					var _item_id = Common.GetTempId ();
					var _item_type = new AstType_OptionalWrap { Token = Token, ItemType = Arguments[0].ExpectType };
					var _item_defvar = new AstStmt_DefVariable { Token = Token, DataType = _item_type, VarName = _item_id, Expr = AstExprTypeCast.Make (this, _item_type) };
					_stmts.Add (_item_defvar);
					//
					_GenCSharpLevel = _GenLevel.NeedCompare;
					_psb.AppendStmts (_stmts, _indent);
					(_a, _b, _c) = _item_defvar.GetRef ().GenerateCSharp (_indent, _check_cb);
					_psb.Append (_a);
					_sb.Append (_b);
					_ssb.Append (_c);
				} else if (_GenCSharpLevel == _GenLevel.NeedCompare) {
					var _index_id = Common.GetTempId ();
					var _index_defvar = new AstStmt_DefVariable { Token = Token, DataType = Arguments[0].ExpectType, VarName = _index_id, Expr = Arguments[0] };
					var _length = new AstExpr_AccessBuildIn { Token = Token, Value = Value, AccessType = AccessBuildInType.ARR_Length, ExpectType = IAstType.FromName ("int") };
					_stmts.Add (_index_defvar);
					_stmts.Add (new AstStmt_If {
						Token = Token,
						Condition = new AstExpr_Op2 { Token = Token, Value1 = _index_defvar.GetRef (), Value2 = IAstExpr.FromValue ("int", "0"), Operator = "<", ExpectType = IAstType.FromName ("bool") },
						IfTrueCodes = new List<IAstStmt> { new AstStmt_ExprWrap { Token = Token, Expr = new AstExpr_Op2 { Token = Token, Value1 = _index_defvar.GetRef (), Value2 = _length, Operator = "+=", ExpectType = _index_defvar.GetRef ().ExpectType } } },
						IfFalseCodes = new List<IAstStmt> { },
					});
					_psb.AppendStmts (_stmts, _indent);
					_check_cb ($"{_index_id} < 0 || {_index_id} >= {_length.GenerateCSharp (_indent, _check_cb).Item2}", "\"数组随机访问范围超限\"");
					_psb.Append (_a);
					_sb.Append ($"{_b} [{_index_id}]");
					_ssb.Append (_c);
				} else {
					(_a, _b, _c) = Value.GenerateCSharp (_indent, _check_cb);
					_psb.Append (_a);
					_sb.Append ($"{_b} [");
					var _items = (from p in Arguments select p.GenerateCSharp (_indent, _check_cb)).ToList ();
					foreach (var _item in from p in _items select p.Item1)
						_psb.Append (_item);
					foreach (var _item in from p in _items select p.Item2)
						_sb.Append ($"{_item}, ");
					foreach (var _item in (from p in _items select p.Item3).Reverse ())
						_ssb.Append (_item);
					_sb.Remove (_sb.Length - 2, 2);
					_sb.Append ("]");
					_ssb.Append (_c);
				}
				return (_psb.ToString (), _sb.ToString (), _ssb.ToString ());
			}

			var _arg_types = (Value.ExpectType as AstType_Func).ArgumentTypes;
			if (Value is AstExprName_ClassFunc _funcexpr && _funcexpr.ThisObject != null)
				_arg_types = _arg_types.Skip (1).ToList ();
			(_a, _b, _c) = Value.GenerateCSharp (_indent, _check_cb);
			_psb.Append (_a);
			_ssb.Append (_c);
			_sb.Append ($"{_b} {Operator[0]}");
			// 如果最后一个参数为params列表
			if (_arg_types.Count > 0 && _arg_types[^1] is AstType_ArrayWrap _awrap && _awrap.Params && Value is not AstExprName_BuildIn) {
				bool _process_last = false;
				for (int i = 0; i < _arg_types.Count; ++i) {
					if (i == _arg_types.Count - 1) {
						if (!Arguments[^1].ExpectType.IsSame (_awrap))
							break;
						// 用户传了数组的情况
						_process_last = true;
					}
					(_a, _b, _c) = Arguments[i].GenerateCSharp (_indent, _check_cb);
					_psb.Append (_a);
					_ssb.Append (_c);
					if (_arg_types[i].Mut)
						_sb.Append ($"ref ");
					_sb.Append ($"{_b}, ");
				}
				if (!_process_last) {
					// 用户没传数组，手动拼接剩余项
					var _tmp_var_name = Common.GetTempId ();
					_psb.AppendLine ($"{_indent.Indent ()}var {_tmp_var_name} = new List<{_awrap.ItemType.GenerateCSharp_Type ()}> ();");
					StringBuilder _psb1 = new StringBuilder (), _psb2 = new StringBuilder ();
					for (int i = _arg_types.Count - 1; i < Arguments.Count; ++i) {
						(_a, _b, _c) = Arguments[i].GenerateCSharp (_indent, _check_cb);
						_psb.Append (_a);
						_psb1.AppendLine ($"{_indent.Indent ()}{_tmp_var_name}.Add ({_b});");
						_psb2.Append (_c);
					}
					_psb.Append (_psb1).Append (_psb2);
					_sb.Append ($"{_tmp_var_name}, ");
				}
			} else {
				for (int i = 0; i < Arguments.Count; ++i) {
					(_a, _b, _c) = Arguments[i].GenerateCSharp (_indent, _check_cb);
					_psb.Append (_a);
					_ssb.Append (_c);
					if (_arg_types[i].Mut)
						_sb.Append ($"ref ");
					_sb.Append ($"{_b}, ");
				}
			}
			if (Value is AstExprName_BuildIn _biexpr && _biexpr.Name.EndsWith ("AllText"))
				_sb.Append ($"Encoding.UTF8, ");
			if (Arguments.Any ())
				_sb.Remove (_sb.Length - 2, 2);
			_sb.Append (Operator[1]);
			return (_psb.ToString (), _sb.ToString (), _ssb.ToString ());
		}

		public override bool AllowAssign () => Operator == "[]" ? Value.AllowAssign () : false;

		private _GenLevel _GenCSharpLevel = _GenLevel.NeedVarWrap;
	}
	enum _GenLevel { NeedVarWrap, NeedCompare, Direct }
}

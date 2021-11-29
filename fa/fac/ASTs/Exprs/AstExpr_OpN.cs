using fac.AntlrTools;
using fac.ASTs.Exprs.Names;
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
				} else {
					throw new CodeException (Token, "表达式无法当做方法进行调用");
				}
			}
		}

		public override IAstType GuessType () {
			if (Value is AstExprName_ClassFunc _funcexpr) {
				return _funcexpr.Class.ClassFuncs[_funcexpr.FunctionIndex].ReturnType;
			} else {
				var _type = Value.GuessType () as AstType_Func;
				return _type.ReturnType;
			}
		}

		public override (string, string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb) {
			var _arg_types = (Value.ExpectType as AstType_Func).ArgumentTypes;
			if (Value is AstExprName_ClassFunc _funcexpr && _funcexpr.ThisObject != null)
				_arg_types = _arg_types.Skip (1).ToList ();
			StringBuilder _psb = new StringBuilder (), _sb = new StringBuilder (), _ssb = new StringBuilder ();
			var (_a, _b, _c) = Value.GenerateCSharp (_indent, _check_cb);
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

		public override bool AllowAssign () => false;
	}
}

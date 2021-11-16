﻿using fac.AntlrTools;
using fac.ASTs.Exprs.Names;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	class AstExpr_OpN: IAstExpr {
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
			if (Value is AstExprName_ClassFunc _funcexpr) {
				var _func_args = _funcexpr.Class.ClassFuncs[_funcexpr.FunctionIndex].Arguments;
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
					//Value = Value.TraversalCalcType (_expect_type);
					//var _func_type_tmp = Value.ExpectType as AstType_Func;
					//if (_func_type_tmp.ArgumentTypes.Count != Arguments.Count)
					//	throw new CodeException (Token, "函数调用传入的参数数量不匹配");
					////var (_ret_type, _arg_type) = TypeFuncs.ParseFuncType (Token, Value.ExpectType);
					////if (_arg_type.Count != Arguments.Count)
					////	throw new CodeException (Token, "函数调用传入的参数数量不匹配");
					//for (int i = 0; i < _func_type_tmp.ArgumentTypes.Count; ++i)
					//	Arguments[i] = Arguments[i].TraversalCalcType (_func_type_tmp.ArgumentTypes[i]);
					//ExpectType = _func_type_tmp.ReturnType;
					//return AstExprTypeCast.Make (this, _expect_type);
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
			StringBuilder _psb = new StringBuilder (), _sb = new StringBuilder (), _ssb = new StringBuilder ();
			var (_a, _b, _c) = Value.GenerateCSharp (_indent, _check_cb);
			_psb.Append (_a);
			_sb.Append ($"{_b} {Operator[0]}");
			_ssb.Append (_c);
			foreach (var _arg in Arguments) {
				(_a, _b, _c) = _arg.GenerateCSharp (_indent, _check_cb);
				_psb.Append (_a);
				_sb.Append ($"{_b}, ");
				_ssb.Append (_c);
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

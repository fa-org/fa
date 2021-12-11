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

		public override void Traversal ((int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) _trav) {
			Value = Value.TraversalWrap (_trav);
			Arguments.TraversalWraps (_trav);
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
				return (Value.GuessType () as AstType_Func).ReturnType;
			}
		}

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			var (_stmts, _val) = Value.ExpandExpr (_cache_err);
			Value = _val;
			for (int i = 0; i < Arguments.Count; ++i) {
				(_stmts, _val) = Arguments[i].ExpandExpr (_cache_err);
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
					(_stmts, _val) = new AstExpr_Array { Token = Arguments[_arg_types.Count - 1].Token, ItemDataType = _awrap.ItemType, InitValues = Arguments.Skip (_arg_types.Count - 1).ToList (), ExpectType = _awrap }.ExpandExpr (_cache_err);
					Arguments.RemoveRange (_arg_types.Count - 1, Arguments.Count - (_arg_types.Count - 1));
					_stmts.AddRange (_stmts);
					Arguments.Add (_val);
				}
			}
			return (_stmts, this);
		}

		public override string GenerateCSharp (int _indent) {
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
			_sb.Append (")");
			return _sb.ToString ();
		}

		public override bool AllowAssign () => false;
	}
}

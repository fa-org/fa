using fac.ASTs.Exprs.Names;
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

		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			Value = _cb (Value, _deep, 0);
			for (int i = 0; i < Arguments.Count; ++i)
				Arguments[i] = _cb (Arguments[i], _deep, _group);
		}

		public override IAstExpr TraversalCalcType (string _expect_type) {
			if (Value is AstExprName_ClassFunc _funcexpr) {
				var _func_args = _funcexpr.Class.ClassFuncs[_funcexpr.FunctionIndex].Arguments;
				if (_funcexpr.ThisObject != null)
					Arguments.Insert (0, _funcexpr.ThisObject);
				if (_func_args.Count != Arguments.Count)
					throw new CodeException (Token, "函数调用传入的参数数量不匹配");
				for (int i = 0; i < _func_args.Count; ++i)
					Arguments[i] = Arguments[i].TraversalCalcType (_func_args[i]._type);
				if (_funcexpr.ThisObject != null)
					Arguments.RemoveAt (0);
				return AstExprTypeCast.Make (this, _expect_type);
			} else {
				Value = Value.TraversalCalcType (_expect_type);
				if (_expect_type == "")
					return this;
				throw new UnimplException (Token);
			}
		}

		public override string GuessType () {
			if (Value is AstExprName_ClassFunc _funcexpr) {
				return _funcexpr.Class.ClassFuncs[_funcexpr.FunctionIndex].ReturnType;
			} else {
				string _type = Value.GuessType ();
				if (_type [..5] == "Func<") {
					TODO;
				}
				throw new UnimplException (Token);
			}
		}
	}
}

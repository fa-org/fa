using fac.ASTs.Exprs.Names;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	class AstExpr_OpN: IAstExpr, IAst {
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
				// 静态方法调用
				var _func_args = _funcexpr.Class.ClassFuncs[_funcexpr.FunctionIndex].Arguments;
			} else if () {
				// TODO: 参数对象、变量对象、全局对象
			} else {
				throw new UnimplException (Token);
			}
		}

		public override string GuessType () {
			if (Value is AstExprName_ClassFunc _funcexpr) {
				return _funcexpr.Class.ClassFuncs[_funcexpr.FunctionIndex].ReturnType;
			} else if () {
				// TODO: 参数对象、变量对象、全局对象
			} else {
				throw new UnimplException (Token);
			}
		}
	}
}

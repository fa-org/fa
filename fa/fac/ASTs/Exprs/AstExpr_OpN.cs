using fac.AntlrTools;
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
				ExpectType = _funcexpr.Class.ClassFuncs[_funcexpr.FunctionIndex].ReturnType;
				return AstExprTypeCast.Make (this, _expect_type);
			} else {
				Value = Value.TraversalCalcType (_expect_type);
				var (_ret_type, _arg_type) = TypeFuncs.ParseFuncType (Token, Value.ExpectType);
				if (_arg_type.Count != Arguments.Count)
					throw new CodeException (Token, "函数调用传入的参数数量不匹配");
				for (int i = 0; i < _arg_type.Count; ++i)
					Arguments[i] = Arguments[i].TraversalCalcType (_arg_type[i]);
				ExpectType = _ret_type;
				return AstExprTypeCast.Make (this, _expect_type);
			}
		}

		public override string GuessType () {
			if (Value is AstExprName_ClassFunc _funcexpr) {
				return _funcexpr.Class.ClassFuncs[_funcexpr.FunctionIndex].ReturnType;
			} else {
				string _type = Value.GuessType ();
				return TypeFuncs.ParseFuncType (Token, _type)._ret_type;
			}
		}

		public override (string, string) GenerateCSharp (int _indent) {
			StringBuilder _psb = new StringBuilder (), _sb = new StringBuilder ();
			var (_a, _b) = Value.GenerateCSharp (_indent);
			_psb.Append (_a);
			_sb.Append ($"{_b} {Operator[0]}");
			foreach (var _arg in Arguments) {
				(_a, _b) = _arg.GenerateCSharp (_indent);
				_psb.Append (_a);
				_sb.Append ($"{_b}, ");
			}
			if (Arguments.Any ())
				_sb.Remove (_sb.Length - 2, 2);
			_sb.Append (Operator[1]);
			return (_psb.ToString (), _sb.ToString ());
		}

		public override bool AllowAssign () => false;
	}
}

using Antlr4.Runtime;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs.Names {
	public abstract class IAstExprName: IAstExpr {
		public static IAstExprName FindVariableOrArgument (IToken _token, string _name) {
			// 查找变量
			var _var = Info.GetCurrentFuncVariableFromName (_name);
			if (_var != null)
				return new AstExprName_Variable { Token = _token, Var = _var };

			// 查找参数
			if (Info.CurrentFunc != null) {
				for (int i = 0; i < Info.CurrentFunc.Arguments.Count; ++i) {
					if (_name == Info.CurrentFunc.Arguments[i]._name)
						return new AstExprName_Argument { Token = _token, Func = Info.CurrentFunc, ArgumentIndex = i };
				}
			}

			return null;
		}

		public static IAstExprName FindClass (IToken _token, string _str_class) {
			var _classes = Info.GetClassFromName (_str_class);
			if (_classes.Count == 0) {
				return null;
			} else if (_classes.Count == 1) {
				return new AstExprName_Class { Token = _token, Class = _classes[0] };
			} else {
				throw new CodeException (_token, $"不明确的符号 {_str_class}。可能为{string.Join ('、', from p in _classes select p.FullName)}");
			}
		}

		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) { }
	}
}

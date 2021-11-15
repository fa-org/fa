using fac.AntlrTools;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs.Names {
	class AstExprName_Argument: IAstExprName {
		public AstClassFunc Func { init; get; }
		public int ArgumentIndex { init; get; }



		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			ExpectType = Func.Arguments[ArgumentIndex]._type;
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () => Func.Arguments[ArgumentIndex]._type;

		public override (string, string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb) {
			string _argname = Func.Arguments[ArgumentIndex]._name;
			if (Func.Arguments[ArgumentIndex]._type is AstType_OptionalWrap && _check_cb != null) {
				_check_cb ($"!{_argname}.HasValue ()", $"{_argname}.GetError ()");
				return ("", $"{_argname}.GetValue ()", "");
			} else {
				// 此处暂时不支持赋值
				throw new CodeException (Token, "参数不能赋值");
				//return ("", _argname);
			}
			
		}

		public override bool AllowAssign () => false;
	}
}

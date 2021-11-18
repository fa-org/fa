using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs.Names {
	class AstExprName_ClassVar: IAstExprName {
		public IAstClass Class { init; get; }
		public int VariableIndex { init; get; }
		public IAstExpr ThisObject { get; set; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			bool _static = Class.ClassVars[VariableIndex].Static;
			if (_static && (ThisObject != null))
				throw new CodeException (Token, "类静态方法无法通过对象访问");
			if ((!_static) && (ThisObject == null))
				throw new CodeException (Token, "类动态态方法无法通过类名访问");
			//
			if (ThisObject != null)
				ThisObject = _cb (ThisObject, _deep, _group);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			ExpectType = GuessType ();
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () => Class.ClassVars[VariableIndex].DataType;

		public override (string, string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb) {
			if (ThisObject != null) {
				var (_a, _b, _c) = ThisObject.GenerateCSharp (_indent, _check_cb);
				string _varname = $"{_b}.{Class.ClassVars[VariableIndex].Name}";
				if (Class.ClassVars[VariableIndex].DataType is AstType_OptionalWrap && _check_cb != null) {
					_check_cb ($"!{_varname}.HasValue ()", $"{_varname}.GetError ()");
					return (_a, $"{_varname}.GetValue ()", _c);
				} else {
					return (_a, $"{_varname}", _c);
				}
			} else {
				string _varname = $"{Class.FullName}.{Class.ClassVars[VariableIndex].Name}";
				if (Class.ClassVars[VariableIndex].DataType is AstType_OptionalWrap && _check_cb != null) {
					_check_cb ($"!{_varname}.HasValue ()", $"{_varname}.GetError ()");
					return ("", $"{_varname}.GetValue ()", "");
				} else {
					return ("", $"{_varname}", "");
				}
			}
		}

		public override bool AllowAssign () => true;
	}
}

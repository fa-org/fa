using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs.Names {
	class AstExprName_ClassVar: IAstExprName {
		public AstClassStmt Class { init; get; }
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

		public override IAstExpr TraversalCalcType (string _expect_type) {
			ExpectType = GuessType ();
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override string GuessType () => Class.ClassVars[VariableIndex].DataType;

		public override (string, string) GenerateCSharp (int _indent) {
			if (ThisObject != null) {
				var (_a, _b) = ThisObject.GenerateCSharp (_indent);
				return (_a, $"{_b}.{Class.ClassVars[VariableIndex].Name}");
			} else {
				return ("", $"{Class.FullName}.{Class.ClassVars[VariableIndex].Name}");
			}
		}

		public override bool AllowAssign () => true;
	}
}

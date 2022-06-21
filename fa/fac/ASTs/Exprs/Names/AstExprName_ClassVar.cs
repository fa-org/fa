using fac.ASTs.Structs;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs.Names {
	public class AstExprName_ClassVar: IAstExprName {
		public IAstClass Class { init; get; }
		public int VariableIndex { init; get; }
		public IAstExpr ThisObject { get; set; }



		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) {
			bool _static = Class.ClassVars[VariableIndex].Static;
			if (_static && (ThisObject != null))
				throw new CodeException (Token, "类静态方法无法通过对象访问");
			if ((!_static) && (ThisObject == null))
				throw new CodeException (Token, "类动态态方法无法通过类名访问");
			//
			if (ThisObject != null)
				ThisObject = ThisObject.TraversalWrap (_trav);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			ExpectType = GuessType ();
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () => Class.ClassVars[VariableIndex].DataType;

		public override string GenerateCSharp (int _indent) {
			if (ThisObject != null) {
				var _b = ThisObject.GenerateCSharp (_indent);
				return $"{_b}.{Class.ClassVars[VariableIndex].Name}";
			} else {
				return $"{Class.CSharpFullName}.{Class.ClassVars[VariableIndex].Name}";
			}
		}

		public override bool AllowAssign () => true;
	}
}

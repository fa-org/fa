using fac.ASTs.Structs;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs.Names {
	public class AstExprName_ClassFunc: IAstExprName {
		public IAstClass Class { init; get; }
		public int FunctionIndex { init; get; }
		public IAstExpr ThisObject { get; set; }



		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) {
			bool _static = Class.ClassFuncs[FunctionIndex].Static;
			if (_static && (ThisObject != null))
				throw new CodeException (Token, "类静态方法无法通过对象访问");
			if ((!_static) && (ThisObject == null))
				throw new CodeException (Token, "类动态态方法无法通过类名访问");
			//
			if (ThisObject != null)
				ThisObject = ThisObject.TraversalWrap (_trav);
		}

		public override IAstExpr TraversalCalcType (IAstType? _expect_type) {
			ExpectType = GuessType ();
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () => Class.ClassFuncs[FunctionIndex].FuncType;

		public override string GenerateCSharp (int _indent) {
			if (ThisObject != null) {
				var _b = ThisObject.GenerateCSharp (_indent);
				return $"{_b}.{Class.ClassFuncs[FunctionIndex].Name}";
			} else {
				string _full_name = Class.CSharpFullName;
				if (_full_name.StartsWith (Info.CurrentNamespace))
					_full_name = _full_name[(Info.CurrentNamespace.Length + 1)..];
				if (_full_name.StartsWith ("."))
					_full_name = _full_name[1..];
				return $"{_full_name}.{Class.ClassFuncs[FunctionIndex].Name}";
			}
		}

		public override string GenerateCpp (int _indent) {
			if (ThisObject != null) {
				var _b = ThisObject.GenerateCpp (_indent);
				return $"{_b}.{Class.ClassFuncs [FunctionIndex].Name}";
			} else {
				string _full_name = Class.CSharpFullName;
				if (_full_name.StartsWith (Info.CurrentNamespace))
					_full_name = _full_name [(Info.CurrentNamespace.Length + 1)..];
				if (_full_name.StartsWith ("."))
					_full_name = _full_name [1..];
				return $"{_full_name}.{Class.ClassFuncs [FunctionIndex].Name}";
			}
		}

		public override bool AllowAssign () => false;
	}
}

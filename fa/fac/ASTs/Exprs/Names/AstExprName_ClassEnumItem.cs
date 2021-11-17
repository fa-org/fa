using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs.Names {
	class AstExprName_ClassEnumItem: IAstExprName {
		public AstClass EnumClass { init; get; }
		public int EnumItemIndex { init; get; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) { }

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			ExpectType = GuessType ();
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () => new AstType_Class { Token = Token, Class = EnumClass, TemplateTypes = new List<IAstType> () };

		public override (string, string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb) {
			throw new NotImplementedException ();
		}

		public override bool AllowAssign () => false;
	}
}

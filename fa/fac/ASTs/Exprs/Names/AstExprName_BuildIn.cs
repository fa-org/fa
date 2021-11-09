using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs.Names {
	class AstExprName_BuildIn: IAstExprName {
		public string Name { init; get; }
		public string NameType { init; get; }



		private static Dictionary<string, AstExprName_BuildIn> sBuildIn = new Dictionary<string, AstExprName_BuildIn> {
			["Console.WriteLine"] = new AstExprName_BuildIn { Token = null, Name = "Console.WriteLine", NameType = "Func<string>" },
		};

		public static AstExprName_BuildIn FindFromName (string _name) {
			if (sBuildIn.ContainsKey (_name))
				return sBuildIn[_name];
			return null;
		}

		public override IAstExpr TraversalCalcType (string _expect_type) {
			ExpectType = NameType;
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override string GuessType () => Name;
	}
}

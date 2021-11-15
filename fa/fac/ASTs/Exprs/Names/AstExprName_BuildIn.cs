using fac.ASTs.Types;
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
			["continue"] = new AstExprName_BuildIn { Token = null, Name = "continue", NameType = "" },
			["break"] = new AstExprName_BuildIn { Token = null, Name = "break", NameType = "" },
			["Console.WriteLine"] = new AstExprName_BuildIn { Token = null, Name = "Console.WriteLine", NameType = "Action<string>" },
		};

		public static AstExprName_BuildIn FindFromName (string _name) {
			if (sBuildIn.ContainsKey (_name))
				return sBuildIn[_name];
			return null;
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (ExpectType == null)
				ExpectType = NameType != "" ? IAstType.FromName (NameType) : null;
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () {
			if (ExpectType == null)
				ExpectType = NameType != "" ? IAstType.FromName (NameType) : null;
			return ExpectType;
		}

		public override (string, string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb) => ("", sName2Output_CSharp[Name], "");

		public override bool AllowAssign () => false;

		private static Dictionary<string, string> sName2Output_CSharp = new Dictionary<string, string> {
			["continue"] = "continue",
			["break"] = "break",
			["Console.WriteLine"] = "Console.WriteLine",
		};
	}
}

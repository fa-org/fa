using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.IO;
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
			["string.Format"] = new AstExprName_BuildIn { Token = null, Name = "string.Format", NameType = "Func<string, params any[], string>" },
			["File.Exists"] = new AstExprName_BuildIn { Token = null, Name = "File.Exists", NameType = "Func<string, bool>" },
			["File.ReadAllText"] = new AstExprName_BuildIn { Token = null, Name = "File.ReadAllText", NameType = "Func<string, string>" },
			["File.WriteAllText"] = new AstExprName_BuildIn { Token = null, Name = "File.WriteAllText", NameType = "Action<string, string>" },
			["File.AppendAllText"] = new AstExprName_BuildIn { Token = null, Name = "File.AppendAllText", NameType = "Action<string, string>" },
			["@FILE"] = new AstExprName_BuildIn { Token = null, Name = "@FILE", NameType = "string" },
			["@FILECONTENT"] = new AstExprName_BuildIn { Token = null, Name = "@FILECONTENT", NameType = "string" },
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

		public override (string, string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb) => ("", Name switch {
			"continue" => "continue",
			"break" => "break",
			"Console.WriteLine" => "Console.WriteLine",
			"string.Format" => "string.Format",
			"File.Exists" => "File.Exists",
			"File.ReadAllText" => "File.ReadAllText",
			"File.WriteAllText" => "File.WriteAllText",
			"File.AppendAllText" => "File.AppendAllText",
			"@FILE" => Common.WrapStringValue (Info.CurrentFile),
			"@FILECONTENT" => Common.WrapStringValue (File.ReadAllText (Info.CurrentFile, Encoding.UTF8)),
			_ => throw new UnimplException (Token),
		}, "");

		public override bool AllowAssign () => false;
	}
}

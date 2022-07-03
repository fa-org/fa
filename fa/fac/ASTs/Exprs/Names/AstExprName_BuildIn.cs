using fac.ASTs.Stmts;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs.Names {
	public class AstExprName_BuildIn: IAstExprName {
		public string Name { init; get; }
		public string NameType { init; get; }



		private static Dictionary<string, AstExprName_BuildIn> sBuildIn = new Dictionary<string, AstExprName_BuildIn> {
			["continue"] =              new AstExprName_BuildIn { Name = "continue",           NameType = "void" },
			["break"] =                 new AstExprName_BuildIn { Name = "break",              NameType = "void" },
			//
			["Console.WriteLine"] =     new AstExprName_BuildIn { Name = "Console.WriteLine",  NameType = "Func<string, void>" },
			["Console.Write"] =         new AstExprName_BuildIn { Name = "Console.Write",      NameType = "Func<string, void>" },
			//
			["string.Format"] =         new AstExprName_BuildIn { Name = "string.Format",      NameType = "Func<string, params any[], string>" },
			//
			["File.Exists"] =           new AstExprName_BuildIn { Name = "File.Exists",        NameType = "Func<string, bool>" },
			["File.ReadAllText"] =      new AstExprName_BuildIn { Name = "File.ReadAllText",   NameType = "Func<string, string>" },
			["File.WriteAllText"] =     new AstExprName_BuildIn { Name = "File.WriteAllText",  NameType = "Func<string, string, void>" },
			["File.AppendAllText"] =    new AstExprName_BuildIn { Name = "File.AppendAllText", NameType = "Func<string, string, void>" },
			["File.Delete"] =           new AstExprName_BuildIn { Name = "File.Delete",        NameType = "Func<string, void>" },
			//
			["Directory.Exists"] =      new AstExprName_BuildIn { Name = "Directory.Exists",   NameType = "Func<string, bool>" },
			["Directory.Create"] =      new AstExprName_BuildIn { Name = "Directory.Create",   NameType = "Func<string, void>" },
			["Directory.Delete"] =      new AstExprName_BuildIn { Name = "Directory.Delete",   NameType = "Func<string, void>" },
			["Directory.GetFiles"] =    new AstExprName_BuildIn { Name = "Directory.GetFiles", NameType = "Func<string, string[]>" },
			//
			["@FILE"] =                 new AstExprName_BuildIn { Name = "@FILE",              NameType = "string" },
			["@FILEDATA"] =             new AstExprName_BuildIn { Name = "@FILEDATA",          NameType = "string" },
		};

		public static AstExprName_BuildIn FindFromName (string _name) {
			if (sBuildIn.ContainsKey (_name))
				return sBuildIn[_name];
			return null;
		}

		public override IAstExpr TraversalCalcType (IAstType? _expect_type) {
			if (ExpectType == null)
				ExpectType = IAstType.FromName (NameType);
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () {
			if (ExpectType == null)
				ExpectType = IAstType.FromName (NameType);
			return ExpectType;
		}

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			// TODO 扩展写文件之类的错误判断
			return (new List<IAstStmt> (), this);
		}

		public override string GenerateCSharp (int _indent) => Name switch {
			"Directory.Create" => "Directory.CreateDirectory",
			"@FILE" => Common.WrapStringValue (Info.CurrentFile),
			"@FILEDATA" when Info.CurrentFile.StartsWith ("res://") => new Func<string>(() => {
				var _assembly = Assembly.GetExecutingAssembly ();
				using var _stream = _assembly.GetManifestResourceStream ($"fac.{Info.CurrentFile[6..].Replace ('/', '.')}");
				using var _reader = new StreamReader (_stream, Encoding.UTF8);
				return Common.WrapStringValue (_reader.ReadToEnd ());
			}) (),
			"@FILEDATA" => Common.WrapStringValue (File.ReadAllText (Info.CurrentFile, Encoding.UTF8)),
			_ => Name,
		};

		public override string GenerateCpp (int _indent) => throw new Exception ("不应执行此处代码");

		public override bool AllowAssign () => false;
	}
}

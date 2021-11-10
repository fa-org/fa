using fac.AntlrTools;
using fac.ASTs.Exprs;
using fac.ASTs.Stmts;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs {
	class AstClassFunc: IAst {
		public PublicLevel Level { init; get; }
		public bool Static { init; get; }
		public string Name { init; get; }
		public string ReturnType { init; get; }
		public List<(string _type, string _name)> Arguments { init; get; }
		public FaParser.ClassFuncBodyContext BodyRaw { init; get; }
		public List<IAstStmt> BodyCodes { get; private set; } = null;



		public AstClassFunc (FaParser.ClassFuncContext _ctx) {
			Token = _ctx.Start;
			//
			Level = Common.ParseEnum<PublicLevel> (_ctx.publicLevel ()?.GetText ()) ?? PublicLevel.Public;
			//
			Static = _ctx.Static () != null;
			//
			Name = _ctx.classFuncName ().GetText ();
			//
			ReturnType = _ctx.type ().GetText ();
			//
			Arguments = AstElemParser.Parse (_ctx.typeVarList ());
			//
			BodyRaw = _ctx.classFuncBody ();
		}

		public void ToAST () {
			// 代码转树状结构
			if (BodyRaw.expr () != null) {
				BodyCodes = new List<IAstStmt> ();
				if (ReturnType != "void") {
					BodyCodes.Add (IAstStmt.FromExpr (BodyRaw.expr (), true));
				} else {
					BodyCodes.Add (IAstStmt.FromExpr (BodyRaw.expr (), false));
					BodyCodes.Add (IAstStmt.FromExpr (null, true));
				}
			} else {
				BodyCodes = IAstStmt.FromStmts (BodyRaw.stmt ());
				MakeSureReturn (BodyCodes);
			}
		}

		// 遍历代码，确保所有路径均return
		private void MakeSureReturn (List<IAstStmt> _stmts) {
			if (_stmts.Count == 0) {
				if (ReturnType != "void")
					throw new CodeException (Token, $"方法需返回 {ReturnType} 类型结果");
				_stmts.Add (IAstStmt.FromExpr (null, true));
			} else if (_stmts[^1] is AstStmt_Return) {
				return;
			} else if (_stmts[^1] is AstStmt_If _ifstmt) {
				MakeSureReturn (_ifstmt.IfTrueCodes);
				MakeSureReturn (_ifstmt.IfFalseCodes);
			} else {
				if (ReturnType != "void")
					throw new CodeException (Token, $"方法需返回 {ReturnType} 类型结果");
				_stmts.Add (IAstStmt.FromExpr (null, true));
			}
		}

		public override (string, string) GenerateCSharp (int _indent) {
			var _sb = new StringBuilder ();
			_sb.Append ($"{_indent.Indent ()}{Level.ToString ().ToLower ()}{(Static ? " static" : "")} {ReturnType} {Name} (");
			foreach (var _arg in Arguments)
				_sb.Append ($"{_arg._type} {_arg._name}, ");
			if (Arguments.Any ())
				_sb.Remove (_sb.Length - 2, 2);
			_sb.AppendLine (") {");
			_sb.AppendStmts (BodyCodes, _indent + 1);
			_sb.AppendLine ($"{_indent.Indent ()}}}");
			return ("", _sb.ToString ());
		}
	}
}

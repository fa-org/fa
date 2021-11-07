using fac.AntlrTools;
using fac.ASTs.Exprs;
using fac.ASTs.Stmts;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs {
	class AstClassFunc: IAst {
		public PublicLevel Level { init; get; }
		public string Name { init; get; }
		public string ReturnType { init; get; }
		public List<(string _type, string _name)> Arguments { init; get; }
		public FaParser.ClassFuncBodyContext BodyRaw { init; get; }
		public List<IAstStmt> BodyCodes { get; private set; } = null;



		public AstClassFunc (FaParser.ClassFuncContext _ctx) {
			Level = Common.ParseEnum<PublicLevel> (_ctx.publicLevel ()?.GetText ()) ?? PublicLevel.Public;
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
				BodyCodes.Add (IAstStmt.FromExpr (BodyRaw.expr (), ReturnType != "void"));
			} else {
				BodyCodes = IAstStmt.FromStmts (BodyRaw.stmt ());
				if (BodyCodes.Count == 0 || BodyCodes[^1] is not AstStmt_Return)
					BodyCodes.Add (IAstStmt.FromExpr (null, ReturnType != "void"));
			}
		}
	}
}

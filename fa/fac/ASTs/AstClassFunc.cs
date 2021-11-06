using fac.AntlrTools;
using fac.ASTs.Exprs;
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
		public List<AstStmt> BodyCodes { get; private set; } = null;



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
				BodyCodes = new List<AstStmt> ();
				BodyCodes.Add (AstStmt.FromExpr (BodyRaw.expr (), ReturnType != "void"));
			} else {
				BodyCodes = AstStmt.FromStmts (BodyRaw.stmt ());
			}
		}

		public void TraversalWrap (int _index) {
			for (int i = 0; i < BodyCodes.Count; ++i) {
				if (Info.TraversalFirst)
					BodyCodes[i] = ExprTraversals.Traversal (BodyCodes[i], _index) as AstStmt;
				BodyCodes[i].TraversalWrap ((_expr) => ExprTraversals.Traversal (_expr, _index));
				if (Info.TraversalLast)
					BodyCodes[i] = ExprTraversals.Traversal (BodyCodes[i], _index) as AstStmt;
			}
		}
	}
}

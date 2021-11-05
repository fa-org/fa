using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs {
	class AstClassVar: IAst {
		public PublicLevel Level { init; get; }
		public string Type { init; get; }
		public string Name { init; get; }
		public FaParser.ExprContext DefaultValueRaw { init; get; }
		public AstExpr_Op2 DefaultValue { get; private set; } = null;



		public AstClassVar (FaParser.ClassVarContext _ctx) {
			Level = Common.ParseEnum<PublicLevel> (_ctx.publicLevel ()?.GetText ()) ?? PublicLevel.Public;
			//
			Type = _ctx.type ().GetText ();
			//
			Name = _ctx.Id ().GetText ();
			//
			DefaultValueRaw = (_ctx.classVarExt () != null ? _ctx.classVarExt ().tmpAssignExpr () : _ctx.tmpAssignExpr ())?.expr ();
		}

		public void Compile () {
			if (DefaultValueRaw != null)
				DefaultValue = new AstExpr (DefaultValueRaw);
		}
	}
}

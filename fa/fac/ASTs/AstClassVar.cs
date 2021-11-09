using Antlr4.Runtime;
using fac.ASTs.Exprs;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs {
	class AstClassVar: IAst {
		public PublicLevel Level { init; get; }
		public bool Static { init; get; }
		public string DataType { init; get; }
		public string Name { init; get; }
		public ParserRuleContext DefaultValueRaw { init; get; }
		public IAstExpr DefaultValue { get; set; } = null;



		public AstClassVar (FaParser.ClassVarContext _ctx) {
			Token = _ctx.Start;
			//
			Level = Common.ParseEnum<PublicLevel> (_ctx.publicLevel ()?.GetText ()) ?? PublicLevel.Public;
			//
			Static = _ctx.Static () != null;
			//
			DataType = _ctx.type ().GetText ();
			//
			Name = _ctx.Id ().GetText ();
			//
			DefaultValueRaw = (_ctx.classVarExt () != null ? _ctx.classVarExt ().tmpAssignExpr () : _ctx.tmpAssignExpr ())?.middleExpr ();
		}

		public void ToAST () {
			if (DefaultValueRaw != null) {
				if (DefaultValueRaw is FaParser.ExprContext _expr_raw) {
					DefaultValue = IAstExpr.FromContext (_expr_raw);
				} else if (DefaultValueRaw is FaParser.MiddleExprContext _mexpr_raw) {
					DefaultValue = IAstExpr.FromContext (_mexpr_raw);
				} else {
					throw new NotImplementedException ();
				}
			}
		}
	}
}

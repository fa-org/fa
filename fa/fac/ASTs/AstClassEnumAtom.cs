using fac.AntlrTools;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs {
	class AstClassEnumAtom: IAst {
		public string Name { init; get; }
		public string AttachType { init; get; } = "";



		public AstClassEnumAtom (FaParser.ClassEnumAtomContext _ctx) {
			Token = _ctx.Start;
			//
			Name = _ctx.Id ().GetText ();
			//
			AttachType = _ctx.type () != null ? _ctx.type ().GetText () : "";
		}

		public override (string, string) GenerateCSharp (int _indent, string _cache_error_varname) => throw new NotImplementedException ();
	}
}

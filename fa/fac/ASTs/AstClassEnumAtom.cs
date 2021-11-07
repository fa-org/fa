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
			Name = _ctx.Id ().GetText ();
			AttachType = _ctx.type () != null ? _ctx.type ().GetText () : "";
		}
	}
}

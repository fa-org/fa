using fac.AntlrTools;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs {
	class AstClassEnumAtom: IAst {
		public string Name { init; get; }
		public List<(string _type, string _name)> AttachVars { init; get; }



		public AstClassEnumAtom (FaParser.ClassEnumAtomContext _ctx) {
			Name = _ctx.Id ().GetText ();
			AttachVars = (from p in _ctx.typeVar () select AstElemParser.Parse (p)).ToList ();
		}
	}
}

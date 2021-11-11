using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.AntlrTools {
	class AstElemParser {
		public static (IAstType _type, string _name) Parse (FaParser.TypeVarContext _ctx) {
			return (IAstType.FromTypeStr (_ctx.type ().GetText (), _ctx.type ().Start), (_ctx.Id () != null ? _ctx.Id ().GetText () : ""));
		}

		public static List<(IAstType _type, string _name)> Parse (FaParser.TypeVarListContext _ctx) {
			if (_ctx != null) {
				return (from p in _ctx.typeVar () select Parse (p)).ToList ();
			} else {
				return new List<(IAstType _type, string _name)> ();
			}
		}
	}
}

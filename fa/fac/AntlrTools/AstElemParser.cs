using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.AntlrTools {
	public class AstElemParser {
		public static (IAstType _type, ArgumentTypeExt _ext, string _name) Parse (FaParser.TypeWrapVarContext _ctx) {
			var _wrap = _ctx.typeWrap ();
			var _ext = _wrap.Mut () != null ? ArgumentTypeExt.Mut : (_wrap.Params () != null ? ArgumentTypeExt.Params : ArgumentTypeExt.None);
			return (new AstType_TempType (_wrap.type ()), _ext, (_ctx.id () != null ? _ctx.id ().GetText () : ""));
		}

		public static List<(IAstType _type, ArgumentTypeExt _ext, string _name)> Parse (FaParser.TypeWrapVarListContext _ctx) {
			if (_ctx != null) {
				return (from p in _ctx.typeWrapVar () select Parse (p)).ToList ();
			} else {
				return new List<(IAstType _type, ArgumentTypeExt _ext, string _name)> ();
			}
		}
	}
}

using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.AntlrTools {
	public class AstElemParser {
		public static (IAstType _type, ArgumentTypeExt _ext, string _name) Parse (FaParser.TypeWrapVar1Context _ctx) {
			var _wrap = _ctx.typeWrap ();
			var _ext = _wrap.Mut () != null ? ArgumentTypeExt.Mut : (_wrap.Params () != null ? ArgumentTypeExt.Params : ArgumentTypeExt.None);
			return (new AstType_TempType (_wrap.type ()), _ext, (_ctx.id () != null ? _ctx.id ().GetText () : ""));
		}

		public static (IAstType _type, ArgumentTypeExt _ext, string _name) Parse (FaParser.TypeWrapVar2Context _ctx) {
			var _wrap = _ctx.typeWrap ();
			var _ext = _wrap.Mut () != null ? ArgumentTypeExt.Mut : (_wrap.Params () != null ? ArgumentTypeExt.Params : ArgumentTypeExt.None);
			return (new AstType_TempType (_wrap.type ()), _ext, (_ctx.id () != null ? _ctx.id ().GetText () : ""));
		}

		public static (IAstType _type, ArgumentTypeExt _ext, string _name) Parse (FaParser.TypeWrapVar3Context _ctx) {
			var _wrap = _ctx.typeWrap ();
			var _ext = _wrap.Mut () != null ? ArgumentTypeExt.Mut : (_wrap.Params () != null ? ArgumentTypeExt.Params : ArgumentTypeExt.None);
			return (new AstType_TempType (_wrap.type ()), _ext, (_ctx.id () != null ? _ctx.id ().GetText () : ""));
		}

		public static List<(IAstType _type, ArgumentTypeExt _ext, string _name)> Parse (FaParser.TypeWrapVarList1Context _ctx) {
			if (_ctx != null) {
				return (from p in _ctx.typeWrapVar1 () select Parse (p)).ToList ();
			} else {
				return new List<(IAstType _type, ArgumentTypeExt _ext, string _name)> ();
			}
		}

		public static List<(IAstType _type, ArgumentTypeExt _ext, string _name)> Parse (FaParser.TypeWrapVarList2Context _ctx) {
			if (_ctx != null) {
				return (from p in _ctx.typeWrapVar2 () select Parse (p)).ToList ();
			} else {
				return new List<(IAstType _type, ArgumentTypeExt _ext, string _name)> ();
			}
		}

		public static List<(IAstType _type, ArgumentTypeExt _ext, string _name)> Parse (FaParser.TypeWrapVarList3Context _ctx) {
			if (_ctx != null) {
				return (from p in _ctx.typeWrapVar3 () select Parse (p)).ToList ();
			} else {
				return new List<(IAstType _type, ArgumentTypeExt _ext, string _name)> ();
			}
		}
	}
}

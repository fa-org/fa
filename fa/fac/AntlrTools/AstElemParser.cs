﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.AntlrTools {
	class AstElemParser {
		public static (string _type, string _name) Parse (FaParser.TypeVarContext _ctx) {
			return (_ctx.type ().GetText (), (_ctx.Id () != null ? _ctx.Id ().GetText () : ""));
		}

		public static List<(string _type, string _name)> Parse (FaParser.TypeVarListContext _ctx) {
			if (_ctx != null) {
				return (from p in _ctx.typeVar () select Parse (p)).ToList ();
			} else {
				return new List<(string _type, string _name)> ();
			}
		}
	}
}
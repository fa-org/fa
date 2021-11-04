using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static FaParser;

namespace fac.Structures {
	enum ExternApiCC { __cdecl, __fastcall, __stdcall }

	class ExternApi {
		public string ReturnType { init; get; }
		public ExternApiCC CC { init; get; }
		public string Name { init; get; }
		public List<string> ParamTypes { init; get; }



		public ExternApi (ImportStmtContext _ctx) {
			ReturnType = _ctx.type ().GetText ();
			//
			string _cc_str = _ctx.callConvention ().GetText ();
			if (!System.Enum.TryParse<ExternApiCC> (_cc_str, out var _cc))
				throw new UnimplException (_ctx.callConvention ());
			CC = _cc;
			//
			Name = _ctx.Id ().GetText ();
			//
			ParamTypes = (from p in _ctx.typeVarList ().typeVar () select p.type ().GetText ()).ToList ();
		}
	}
}

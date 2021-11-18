using fac.AntlrTools;
using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs {
	class AstClassEnumItem: IAst {
		public string Name { init; get; }
		public List<IAstType> AttachTypes { init; get; }



		public AstClassEnumItem (FaParser.ClassEnumItemContext _ctx) {
			Token = _ctx.Start;
			//
			Name = _ctx.Id ().GetText ();
			//
			AttachTypes = IAstType.FromContexts (_ctx.typeList ().type ());
		}

		public override (string, string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb) => throw new NotImplementedException ();
	}
}

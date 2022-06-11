using fac.AntlrTools;
using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Structs {
	public class AstEnumItem: IAst {
		public string Name { init; get; }
		public IAstType AttachType { get; set; } = null;



		public AstEnumItem (FaParser.EnumItemContext _ctx) {
			Token = _ctx.Start;
			Name = _ctx.id ().GetText ();
			if (_ctx.type () != null)
				AttachType = new AstType_TempType (_ctx.type ());
		}

		public void ProcessType () {
			if (AttachType is AstType_TempType _ttype)
				AttachType = _ttype.GetRealType ();
		}

		public override string GenerateCSharp (int _indent) => throw new NotImplementedException ();
	}
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	class AstType_OptionalWrap: IAstType {
		public IAstType ItemType { init; get; }



		public override string GenerateCSharp_Type () => $"fa.Optional<{ItemType.GenerateCSharp_Type ()}>";
	}
}

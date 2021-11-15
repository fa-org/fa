using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	class AstType_ArrayWrap: IAstType {
		public IAstType ItemType { init; get; }



		public override string GenerateCSharp_Type () => $"List<{ItemType.GenerateCSharp_Type ()}>";
	}
}

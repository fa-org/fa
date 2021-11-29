using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	public class AstType_ArrayWrap: IAstType {
		public bool Params { get; set; }
		public IAstType ItemType { init; get; }



		public override string ToString () => $"{ItemType}[]";
		public override string GenerateCSharp_Type () => $"List<{ItemType.GenerateCSharp_Type ()}>";
	}
}

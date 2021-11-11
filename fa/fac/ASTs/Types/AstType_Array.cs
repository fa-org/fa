using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	class AstType_Array: IAstType {
		public IAstType ItemType { init; get; }



		public override (string, string) GenerateCSharp (int _indent) => ("", $"List<{ItemType.GenerateCSharp (_indent)}>");
	}
}

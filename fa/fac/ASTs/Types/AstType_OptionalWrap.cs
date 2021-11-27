using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	class AstType_OptionalWrap: IAstType {
		public IAstType ItemType { init; get; }



		public override string ToString () => $"{ItemType}?";
		public override string GenerateCSharp_Type () => $"fa.Optional<{(ItemType is AstType_Void ? "int" : ItemType.GenerateCSharp_Type ())}>";
	}
}

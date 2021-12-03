using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	public class AstType_OptionalWrap: IAstType {
		public IAstType ItemType { init; get; }



		public override string ToString () => $"{ItemType}?";
		public override string GenerateCSharp (int _indent) => $"fa.Optional<{(ItemType is AstType_Void ? "int" : ItemType.GenerateCSharp (_indent))}>";
	}
}

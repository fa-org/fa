using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	class AstType_OptionalWrap: IAstType {
		public IAstType ItemType { init; get; }



		public override (string, string) GenerateCSharp (int _indent) {
			var (_str1, _str2) = ItemType.GenerateCSharp (_indent);
			return (_str1, $"fa.Optional<{_str2}>");
		}
	}
}

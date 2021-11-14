using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	class AstType_ArrayWrap: IAstType {
		public IAstType ItemType { init; get; }



		public override (string, string) GenerateCSharp (int _indent, string _cache_error_varname) {
			var (_a, _b) = ItemType.GenerateCSharp (_indent, _cache_error_varname);
			return (_a, $"List<{_b}>");
		}
	}
}

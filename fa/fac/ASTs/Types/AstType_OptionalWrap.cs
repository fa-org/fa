using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	class AstType_OptionalWrap: IAstType {
		public IAstType ItemType { init; get; }



		public override (string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb) {
			var (_str1, _str2) = ItemType.GenerateCSharp (_indent, _check_cb);
			return (_str1, $"fa.Optional<{_str2}>");
		}
	}
}

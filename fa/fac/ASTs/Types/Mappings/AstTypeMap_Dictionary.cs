using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types.Mappings {
	class AstTypeMap_Dictionary: IAstType {
		public IAstType KeyType { get; set; }
		public IAstType ValueType { get; set; }



		public override string ToString () => $"Dictionary<{KeyType},{ValueType}>";
		public override string GenerateCSharp (int _indent) => $"Dictionary<{KeyType.GenerateCSharp (_indent)},{ValueType.GenerateCSharp (_indent)}>";
		public override string GenerateCpp (int _indent) => $"std::map<{KeyType.GenerateCpp (_indent)},{ValueType.GenerateCpp (_indent)}>";
	}
}

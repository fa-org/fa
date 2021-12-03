using fac.ASTs.Exprs;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	public class AstType_String: IAstType {
		public override string ToString () => "string";
		public override string GenerateCSharp (int _indent) => "string";
	}
}

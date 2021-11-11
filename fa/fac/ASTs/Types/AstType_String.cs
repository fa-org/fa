using fac.ASTs.Exprs;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	class AstType_String: IAstType {
		public override (string, string) GenerateCSharp (int _indent) => ("", TypeStr);
	}
}

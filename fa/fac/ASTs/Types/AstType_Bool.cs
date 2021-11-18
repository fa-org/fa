using fac.ASTs.Exprs;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	class AstType_Bool: IAstType {
		public override string GenerateCSharp_Type () => "bool";
	}
}

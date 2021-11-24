using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	class AstType_Void: IAstType {
		public override string ToString () => "void";
		public override string GenerateCSharp_Type () => "void";
	}
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	public class AstType_Any: IAstType {
		public override string ToString () => "any";
		public override string GenerateCSharp_Type () => "object";
	}
}

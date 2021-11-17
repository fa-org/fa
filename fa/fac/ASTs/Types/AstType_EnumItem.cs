using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	class AstType_EnumItem: IAstType {
		public AstClass EnumType { get; set; }



		public override string GenerateCSharp_Type () => EnumType.FullName;
	}
}

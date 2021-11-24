using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	class AstType_Placeholder: IAstType {
		public string Name { get; set; }



		public override string ToString () => Name;
		public override string GenerateCSharp_Type () => throw new NotImplementedException ();
		// TODO 泛型约束
	}
}

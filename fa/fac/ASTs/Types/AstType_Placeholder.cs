using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	public class AstType_Placeholder: IAstType {
		public string Name { get; set; }



		public override string ToString () => Name;
		public override string GenerateCSharp (int _indent) => throw new NotImplementedException ();
		public override string GenerateCpp (int _indent) => throw new NotImplementedException ();
	}
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	class AstType_Class: IAstType {
		public AstClass Class { get; set; }



		public override (string, string) GenerateCSharp (int _indent) => ("", TypeStr);
	}
}

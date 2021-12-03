using fac.ASTs.Exprs;
using fac.ASTs.Stmts;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	public class AstType_Void: IAstType {
		public override string ToString () => "void";
		public override string GenerateCSharp (int _indent) => "void";
	}
}

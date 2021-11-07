using fac.ASTs.Stmts;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs.Names {
	class AstExprName_Variable: IAstExprName {
		public AstStmt_DefVariable Var { init; get; }
	}
}

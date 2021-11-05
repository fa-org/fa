using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	class AstExpr_If: IAst, IAstExpr {
		public IAstExpr Condition { get; set; }
		public List<AstStmt> IfTrueCodes { get; set; }
		public IAstExpr IfTrue { get; set; }
		public List<AstStmt> IfFalseCodes { get; set; }
		public IAstExpr IfFalse { get; set; }
	}
}

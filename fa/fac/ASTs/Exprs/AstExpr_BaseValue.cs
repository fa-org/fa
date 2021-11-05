using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	class AstExpr_BaseValue: IAst, IAstExpr {
		public string Type { get; set; }
		public string Value { get; set; }
	}
}

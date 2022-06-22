using fac.ASTs.Exprs;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Structs.Part {
	public class AstAnnoUsingPart {
		public AstAnnotation Anno { get; set; } = null;
		public string TempAnnoName { init; get; }
		public List<string> TempVarNames { get; set; }
		public List<AstExpr_BaseValue> InitValues { get; set; }
	}
}

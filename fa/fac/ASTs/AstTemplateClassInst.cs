using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs {
	class AstTemplateClassInst: IAst, IAstClass {
		private AstTemplateClass Class { init; get; }
		private List<IAstType> Templates { init; get; }



		public string FullName { init; get; }
		public List<AstEnumItem> ClassEnumItems { get; } = null;
		public List<AstClassVar> ClassVars { init; get; }
		public List<AstClassFunc> ClassFuncs { init; get; }

		public void Compile () => throw new Exception ("不应执行此处代码");
		public override string GenerateCSharp (int _indent) => "";

		public int GetRealAttachVarPos (int _enum_index) => -1;
	}
}

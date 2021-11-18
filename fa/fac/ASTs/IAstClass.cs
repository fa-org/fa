using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs {
	interface IAstClass {
		string FullName { get; }
		List<AstClassEnumItem> ClassEnumItems { get; }
		List<AstClassVar> ClassVars { get; }
		List<AstClassFunc> ClassFuncs { get; }
		void Compile ();
		public (string, string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb);
	}
}

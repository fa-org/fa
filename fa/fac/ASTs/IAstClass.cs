using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs {
	public interface IAstClass {
		string FullName { get; }
		List<AstEnumItem> ClassEnumItems { get; }
		List<AstClassVar> ClassVars { get; }
		List<AstClassFunc> ClassFuncs { get; }

		void Compile ();
		(string, string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb);

		// 计算枚举类型所对应的附加变量的实际映射变量位置
		public int GetRealAttachVarPos (int _enum_index) => -1;
	}
}

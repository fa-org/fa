using fac.ASTs.Structs;
using fac.ASTs.Types;
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

		AstType_Class GetClassType () => AstType_Class.GetType (null, this);
		bool Compile ();
		string GenerateCSharp (int _indent);

		// 计算枚举类型所对应的附加变量的实际映射变量位置
		public int GetRealAttachVarPos (int _enum_index) => -1;

		public static IAstClass FromContext (FaParser.EnumStmtContext _ctx) => _ctx.classTemplates () != null ? AstTemplateEnum.FromContext (_ctx) : AstEnum.FromContext (_ctx);
		public static IAstClass FromContext (FaParser.ClassStmtContext _ctx) => _ctx.classTemplates () != null ? AstTemplateClass.FromContext (_ctx) : AstClass.FromContext (_ctx);
	}
}

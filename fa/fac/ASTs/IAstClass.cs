using Antlr4.Runtime;
using fac.ASTs.Exprs.Names;
using fac.ASTs.Structs;
using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs {
	public interface IAstClass {
		public string FullName { get; }
		public string CSharpFullName { get => FullName; }
		public List<AstEnumItem> ClassEnumItems { get; }
		public List<AstClassVar> ClassVars { get; }
		public List<AstClassFunc> ClassFuncs { get; }

		public AstType_Class GetClassType () => AstType_Class.GetType (null, this);

		public void ProcessType ();
		public bool Compile ();
		public string GenerateCSharp (int _indent);

		// 计算枚举类型所对应的附加变量的实际映射变量位置
		public int GetRealAttachVarPos (int _enum_index) => -1;

		// 获取所需模板类型数量
		public int GetTemplateNum ();

		// 获取设置模板参数的模板类型实例
		public IAstClass GetInst (List<IAstType> _templates, IToken _token = null);

		public static IAstClass FromContext (FaParser.EnumStmtContext _ctx) => _ctx.classTemplates () != null ? AstTemplateEnum.FromContext (_ctx) : AstEnum.FromContext (_ctx);
		public static IAstClass FromContext (FaParser.ClassStmtContext _ctx) => _ctx.classTemplates () != null ? AstTemplateClass.FromContext (_ctx) : AstClass.FromContext (_ctx);
	}
}

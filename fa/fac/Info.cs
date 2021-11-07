using Antlr4.Runtime.Tree;
using fac.AntlrTools;
using fac.ASTs;
using fac.ASTs.Stmts;
using fac.Structures;
using System.Collections.Generic;
using System.Linq;

namespace fac {
	class Info {
		/// <summary>
		/// 项目名
		/// </summary>
		public static string ProjectName = "";

		/// <summary>
		/// 项目源码路径
		/// </summary>
		public static string SrcPath = "";

		/// <summary>
		/// 项目引用的外部库
		/// </summary>
		public static HashSet<string> ExternLibs = new HashSet<string> ();

		/// <summary>
		/// 项目编译输出路径
		/// </summary>
		public static string DestPath = "";

		/// <summary>
		/// 项目所有源码文件的AST
		/// </summary>
		public static List<AstProgram> Programs = new List<AstProgram> ();



		/// <summary>
		/// 当前源码文件
		/// </summary>
		public static string CurrentFile = "";

		/// <summary>
		/// 当前源码
		/// </summary>
		public static string CurrentCode = "";

		/// <summary>
		/// 当前相对路径
		/// </summary>
		public static string CurrentRelativeFile {
			get {
				string _s = CurrentFile.Substring (SrcPath.Length);
				return (_s[0] == '/' || _s[0] == '\\') ? _s.Substring(1) : _s;
			}
		}

		/// <summary>
		/// 当前访问者对象
		/// </summary>
		public static FaVisitorImpl Visitor { set; get; } = null;

		/// <summary>
		/// 当前命名空间
		/// </summary>
		public static string CurrentNamespace = "";

		/// <summary>
		/// 当前命名空间引用
		/// </summary>
		public static List<string> CurrentUses;

		/// <summary>
		/// 当前外部API
		/// </summary>
		public static List<ExternApi> CurrentExternApis;

		/// <summary>
		/// 当前AST节点迭代方式
		/// </summary>
		public static TraversalType CurrentTraversalType;
		public static bool TraversalFirst { get => (CurrentTraversalType & TraversalType.Root2Leaf) > 0; }
		public static bool TraversalLast { get => (CurrentTraversalType & TraversalType.Leaf2Root) > 0; }



		/// <summary>
		/// 函数内变量递归查找辅助类，List每一项代表一个生命周期，Dictionary存储的是这个生命周期中的所有变量
		/// </summary>
		public static List<(Dictionary<string, AstStmt_DefVariable> _vars, int _group)> CurrentFuncVariables { get; set; } = null;
		public static AstStmt_DefVariable GetCurrentFuncVariableFromName (string _name) {
			return (from p in CurrentFuncVariables.Reverse<(Dictionary<string, AstStmt_DefVariable> _vars, int _group)> () where p._vars.ContainsKey (_name) select p._vars[_name]).FirstOrDefault ();
		}

		/// <summary>
		/// 当前函数
		/// </summary>
		public static AstClassFunc CurrentFunc { get; set; } = null;
	}
}

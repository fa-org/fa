using Antlr4.Runtime.Tree;
using fac.AntlrTools;
using fac.ASTs;
using fac.ASTs.Stmts;
using fac.Structures;
using System.Collections.Generic;
using System.Linq;
using System.Text;

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
		public static List<AstClass> GetClassFromName (string _name) {
			var _classes = new List<AstClass> (); // 非绝对路径，收集起来，避免重复名称
			foreach (var _program in Info.Programs) {
				foreach (var _class in _program.CurrentClasses) {
					if (_class.FullName.Length >= _name.Length) {
						// 如果类名完全一致，那么直接返回
						if (_class.FullName == _name) {
							_classes.Add (_class);
							return _classes;
						}

						// 迭代当前命名空间
						var _tmp_namespace = Info.CurrentNamespace;
						while (_tmp_namespace != "") {
							if (_class.FullName == $"{_tmp_namespace}.{_name}") {
								_classes.Add (_class);
								break;
							}
							int p = _tmp_namespace.LastIndexOf ('.');
							if (p == -1) {
								_tmp_namespace = "";
							} else {
								_tmp_namespace = _tmp_namespace.Substring (0, p);
							}
						}
						if (_classes.Count > 0 && _classes[^1] == _class)
							continue;

						// 迭代use的命名空间
						foreach (var _namespace in Info.CurrentUses) {
							if (_class.FullName == $"{_namespace}.{_name}") {
								_classes.Add (_class);
								break;
							}
						}
					}
				}
			}

			return _classes;
		}



		/// <summary>
		/// 当前源码文件
		/// </summary>
		public static string CurrentFile = "";

		/// <summary>
		/// 当前源码
		/// </summary>
		public static string CurrentSourceCode = "";

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
		/// 当前类
		/// </summary>
		public static AstClass CurrentClass { get; set; } = null;

		/// <summary>
		/// 当前类方法
		/// </summary>
		public static AstClassFunc CurrentFunc { get; set; } = null;

		//
		public static string GenerateCSharp () {
			StringBuilder _psb = new StringBuilder (), _sb = new StringBuilder ();
			foreach (var _program in Programs) {
				var (_a, _b, _c) = _program.GenerateCSharp (0, null);
				_psb.Append (_a);
				_sb.Append (_b).Append (_c);
			}
			_psb.AppendLine ();
			_psb.AppendLine ();
			_psb.AppendLine ();
			_psb.AppendLine ("namespace fa {");
			_psb.AppendLine ("public class Optional<T> {");
			_psb.AppendLine ("    public T t = default;");
			_psb.AppendLine ("    public string err = \"\";");
			_psb.AppendLine ("    public bool HasValue () => err == \"\";");
			_psb.AppendLine ("    public T GetValue () => t;");
			_psb.AppendLine ("    public string GetError () => err;");
			_psb.AppendLine ("    public static Optional<T> FromValue (T _t) => new Optional<T> { t = _t };");
			_psb.AppendLine ("    public static Optional<T> FromError (string _err) => new Optional<T> { err = _err };");
			_psb.AppendLine ("}");
			_psb.AppendLine ("}");
			_psb.AppendLine ($"namespace {Info.CurrentNamespace} {{");
			_sb.AppendLine ($"}}");
			return $"{_psb}{_sb}";
		}
	}
}

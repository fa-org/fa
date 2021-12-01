using Antlr4.Runtime;
using Antlr4.Runtime.Tree;
using fac.AntlrTools;
using fac.ASTs;
using fac.ASTs.Exprs;
using fac.ASTs.Exprs.Names;
using fac.ASTs.Stmts;
using fac.ASTs.Types;
using fac.Structures;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace fac {
	public class Info {
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
		public static List<IAstClass> GetClassFromName (string _name) {
			var _classes = new List<IAstClass> (); // 非绝对路径，收集起来，避免重复名称
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
		public class FuncArgumentOrVars {
			public int Group { get; set; }
			public AstExpr_Lambda LambdaFunc { get; set; } = null;
			public AstClassFunc ClassFunc { get; set; } = null;
			public Dictionary<string, AstStmt_DefVariable> Vars { get; set; } = null;
		}
		public static List<FuncArgumentOrVars> CurrentFuncVariables { get; set; } = null;
		public static IAstExprName GetCurrentFuncVariableFromName (IToken _token, string _name) {
			for (int i = CurrentFuncVariables.Count - 1; i >= 0; --i) {
				var _item = CurrentFuncVariables[i];
				if (_item.LambdaFunc != null) {
					for (int j = 0; j < _item.LambdaFunc.Arguments.Count; ++j) {
						if (_item.LambdaFunc.Arguments[j]._name == _name)
							return new AstExprName_LambdaArgument { Token = _token, ArgumentIndex = j, Func = _item.LambdaFunc };
					}
				} else if (_item.ClassFunc != null) {
					for (int j = 0; j < _item.ClassFunc.Arguments.Count; ++j) {
						if (_name == _item.ClassFunc.Arguments[j]._name)
							return new AstExprName_Argument { Token = _token, Func = _item.ClassFunc, ArgumentIndex = j };
					}
				} else {
					if (_item.Vars.ContainsKey (_name))
						return new AstExprName_Variable { Token = _token, Var = _item.Vars[_name] };
				}
			}
			return null;
		}
		public static IAstType CurrentReturnType () {
			for (int i = CurrentFuncVariables.Count - 1; i >= 0; --i) {
				var _item = CurrentFuncVariables[i];
				if (_item.LambdaFunc != null) {
					return _item.LambdaFunc.ReturnType;
				} else if (_item.ClassFunc != null) {
					return _item.ClassFunc.ReturnType;
				}
			}
			return null;
		}

		/// <summary>
		/// 当前类
		/// </summary>
		public static IAstClass CurrentClass { get; set; } = null;

		/// <summary>
		/// 当前类方法
		/// </summary>
		public static AstClassFunc CurrentFunc { get; set; } = null;

		//
		public static string GenerateCSharp () {
			var _sb = new StringBuilder ();
			_sb.AppendLine ($"using System;");
			_sb.AppendLine ($"using System.IO;");
			_sb.AppendLine ($"using System.Text;");
			_sb.AppendLine ($"using System.Collections.Generic;");
			_sb.AppendLine ();
			_sb.AppendLine ();
			_sb.AppendLine ();
			_sb.AppendLine ("namespace fa {");
			_sb.AppendLine ("public class Optional<T> {");
			_sb.AppendLine ("    public T t = default;");
			_sb.AppendLine ("    public string err = \"\";");
			_sb.AppendLine ("    public bool HasValue () => err == \"\";");
			_sb.AppendLine ("    public T GetValue () => t;");
			_sb.AppendLine ("    public string GetError () => err;");
			_sb.AppendLine ("    public static Optional<T> FromValue (T _t) => new Optional<T> { t = _t };");
			_sb.AppendLine ("    public static Optional<T> FromError (string _err) => new Optional<T> { err = _err };");
			_sb.AppendLine ("    public static T operator | (Optional<T> t1, T t2) => t1.HasValue () ? t1.GetValue () : t2; // operator ??");
			_sb.AppendLine ("    public static Optional<T> operator | (Optional<T> t1, Optional<T> t2) => t1.HasValue () ? t1 : t2; // operator ??");
			// FIXME: 支持“?? 异常”用法，但传字符串不对，假如出现 string? 类型的 ?? 就尴尬了
			_sb.AppendLine ("}");
			_sb.AppendLine ("}");
			_sb.AppendLine ();
			_sb.AppendLine ();
			_sb.AppendLine ();
			foreach (var _program in Programs) {
				var (_a, _b, _c) = _program.GenerateCSharp (0, null);
				_sb.Append (_a).Append (_b).Append (_c);
			}
			return _sb.ToString ();
		}
	}
}

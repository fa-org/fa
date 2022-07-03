using Antlr4.Runtime;
using Antlr4.Runtime.Tree;
using fac.AntlrTools;
using fac.ASTs;
using fac.ASTs.Exprs;
using fac.ASTs.Exprs.Names;
using fac.ASTs.Stmts;
using fac.ASTs.Structs;
using fac.ASTs.Types;
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
		/// 项目编译输出路径
		/// </summary>
		public static string DestPath = "";

		/// <summary>
		/// 项目所有源码文件的AST
		/// </summary>
		public static List<AstProgram> Programs = new List<AstProgram> ();
		public static List<IAstClass> GetClassFromName (string _name) {
			var _templates = new List<IAstType> ();
			if (_name.Contains ('<')) {
				int _p = _name.IndexOf ('<');
				var _template_names = _name[(_p + 1)..^1].ItemSplit ();
				_templates = (from p in _template_names select IAstType.FromName (p)).ToList ();
				_name = _name[.._p];
			}
			return GetClassFromName (_name, _templates);
		}
		public static List<IAstClass> GetClassFromName (string _name, List<IAstType> _templates) {
			var _classes = GetTemplateClassFromName (_name, _templates.Count);
			for (int i = 0; i < _classes.Count; ++i)
				_classes[i] = _classes[i].GetInst (_templates);
			return _classes;
		}

		public static List<IAstClass> GetTemplateClassFromName (string _name, int _templates_count) {
			var _classes = new List<IAstClass> (); // 非绝对路径，收集起来，避免重复名称
			foreach (var _program in Info.Programs) {
				foreach (var _class in _program.CurrentClasses) {
					if (_class.FullName.Length >= _name.Length) {
						// 如果类名完全一致，那么直接返回
						if (_class.FullName == _name && _class.GetTemplateNum () == _templates_count) {
							_classes.Clear ();
							_classes.Add (_class);
							return _classes;
						}

						// 迭代当前命名空间
						var _tmp_namespace = Info.CurrentNamespace;
						while (_tmp_namespace != "") {
							if (_class.FullName == $"{_tmp_namespace}.{_name}" && _class.GetTemplateNum () == _templates_count) {
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
							if (_class.FullName == $"{_namespace}.{_name}" && _class.GetTemplateNum () == _templates_count) {
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
				if (CurrentFile.StartsWith ("res://")) {
					return CurrentFile[6..];
				} else {
					string _s = CurrentFile.Substring (SrcPath.Length);
					_s = (_s[0] == '/' || _s[0] == '\\') ? _s.Substring (1) : _s;
					return $"{Info.ProjectName}.{_s}";
				}
			}
		}

		/// <summary>
		/// 当前访问者对象
		/// </summary>
		public static FaVisitorImpl Visitor { set; get; } = null;

		/// <summary>
		/// 当前命名空间
		/// </summary>
		public static string CurrentNamespace { set; get; } = "";

		/// <summary>
		/// 当前命名空间引用
		/// </summary>
		public static List<string> CurrentUses { set; get; } = null;

		/// <summary>
		/// 当前AST节点迭代方式
		/// </summary>
		public static TraversalType CurrentTraversalType { set; get; } = TraversalType.Root2Leaf;
		public static bool TraversalFirst { get => (CurrentTraversalType & TraversalType.Root2Leaf) > 0; }
		public static bool TraversalLast { get => (CurrentTraversalType & TraversalType.Leaf2Root) > 0; }



		/// <summary>
		/// 函数内变量递归查找辅助类，List每一项代表一个生命周期，Dictionary存储的是这个生命周期中的所有变量
		/// </summary>
		public class FuncArgumentOrVars {
			public int Group { get; set; }
			public AstExpr_Lambda? LambdaFunc { get; set; } = null;
			public AstClassFunc? ClassFunc { get; set; } = null;
			public Dictionary<string, AstStmt_DefVariable> Vars { get; set; } = new Dictionary<string, AstStmt_DefVariable> ();
		}
		public static List<FuncArgumentOrVars> CurrentFuncVariables { get; set; } = new List<FuncArgumentOrVars> ();
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
						return _item.Vars[_name].GetRef ();
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
		public static AstClassFunc? CurrentFunc { get; set; } = null;

		public static void InitFunc (AstClassFunc? _func) {
			CurrentFunc = _func;
			CurrentFuncVariables = new List<FuncArgumentOrVars> ();
			CurrentFuncVariables.Add (new FuncArgumentOrVars { Group = 0, ClassFunc = _func });
			if (_func != null)
				CurrentFuncVariables.Add (new FuncArgumentOrVars { Group = 1, Vars = new Dictionary<string, AstStmt_DefVariable> () });
		}

		//
		public static string GenerateCSharp () {
			var _sb = new StringBuilder ();
			_sb.AppendLine ($"using System;");
			_sb.AppendLine ($"using System.IO;");
			_sb.AppendLine ($"using System.Text;");
			_sb.AppendLine ($"using System.Collections.Generic;");
			//_sb.AppendLine ();
			//_sb.AppendLine ();
			//_sb.AppendLine ();
			//_sb.AppendLine ("namespace fa {");
			//_sb.AppendLine ("public class Optional<T> {");
			//_sb.AppendLine ("    public T t = default;");
			//_sb.AppendLine ("    public string err = \"\";");
			//_sb.AppendLine ("    public bool HasValue () => err == \"\";");
			//_sb.AppendLine ("    public T GetValue () => t;");
			//_sb.AppendLine ("    public string GetError () => err;");
			//_sb.AppendLine ("    public static Optional<T> FromValue (T _t) => new Optional<T> { t = _t };");
			//_sb.AppendLine ("    public static Optional<T> FromError (string _err) => new Optional<T> { err = _err };");
			//_sb.AppendLine ("}");
			////_sb.AppendLine ("public class OptionalVoid {");
			////_sb.AppendLine ("    public string err = \"\";");
			////_sb.AppendLine ("    public bool HasValue () => err == \"\";");
			////_sb.AppendLine ("    public string GetError () => err;");
			////_sb.AppendLine ("    public static OptionalVoid FromValue () => new OptionalVoid {};");
			////_sb.AppendLine ("    public static OptionalVoid FromError (string _err) => new OptionalVoid { err = _err };");
			////_sb.AppendLine ("}");
			//_sb.AppendLine ("}");
			_sb.AppendLine ();
			_sb.AppendLine ();
			_sb.AppendLine ();
			foreach (var _program in Programs)
				_sb.Append (_program.GenerateCSharp (0));
			return _sb.ToString ();
		}

		public static string GenerateCpp () {
			var _sb = new StringBuilder ();
			_sb.AppendLine ($"#include <cstdint>");
			_sb.AppendLine ($"#include <functional>");
			_sb.AppendLine ($"#include <iostream>");
			_sb.AppendLine ($"#include <optional>");
			_sb.AppendLine ($"#include <string>");
			_sb.AppendLine ($"#include <variant>");
			_sb.AppendLine ();
			_sb.AppendLine ();
			_sb.AppendLine ();
			foreach (var _program in Programs)
				_sb.Append (_program.GenerateCpp (0));
			return _sb.ToString ();
		}
	}
}

using Antlr4.Runtime;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs.Names {
	abstract class IAstExprName: IAstExpr {
		public static IAstExprName FindVariableOrArgument (IToken _token, string _name) {
			// 查找变量
			var _var = Info.GetCurrentFuncVariableFromName (_name);
			if (_var != null)
				return new AstExprName_Variable { Token = _token, Var = _var };

			// 查找参数
			if (Info.CurrentFunc != null) {
				for (int i = 0; i < Info.CurrentFunc.Arguments.Count; ++i) {
					if (_name == Info.CurrentFunc.Arguments[i]._name)
						return new AstExprName_Argument { Token = _token, Func = Info.CurrentFunc, ArgumentIndex = i };
				}
			}

			return null;
		}

		public static IAstExprName FindClass (IToken _token, string _name) {
			// 查找类
			var _classes = new List<AstClassStmt> (); // 非绝对路径，收集起来，避免重复名称
			foreach (var _program in Info.Programs) {
				foreach (var _class in _program.CurrentClasses) {
					if (_class.FullName.Length >= _name.Length) {
						// 如果类名完全一致，那么直接返回
						if (_class.FullName == _name)
							return new AstExprName_Class { Token = _token, Class = _class };

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

			if (_classes.Count == 0) {
				return null;
			} else if (_classes.Count == 1) {
				return new AstExprName_Class { Token = _token, Class = _classes[0] };
			} else {
				throw new CodeException (_token, $"不明确的符号 {_name}。可能为{string.Join ('、', from p in _classes select p.FullName)}");
			}
		}

		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) { }
	}
}

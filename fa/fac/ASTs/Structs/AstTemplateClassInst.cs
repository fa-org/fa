using Antlr4.Runtime;
using fac.AntlrTools;
using fac.ASTs.Stmts;
using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Structs {
	public class AstTemplateClassInst: IAst, IAstClass {
		public AstTemplateClass Class { init; get; }
		public List<IAstType> Templates { init; get; }

		public string FullName { init; get; }
		public List<AstEnumItem> ClassEnumItems { get; } = null;
		public List<AstClassVar> ClassVars { init; get; }
		public List<AstClassFunc> ClassFuncs { init; get; }
		private bool m_compiled = false;



		public AstTemplateClassInst (IToken _token, AstTemplateClass _class, List<IAstType> _templates, string _fullname) {
			Token = _token;
			Class = _class;
			Templates = _templates;
			FullName = _fullname;
			ClassVars = new List<AstClassVar> ();
			foreach (var _var in Class.ClassVars) {
				if (_var.DataType is AstType_Placeholder _phtype) {
					ClassVars.Add (new AstClassVar { Token = _var.Token, Level = _var.Level, Static = _var.Static, DataType = GetImplType (_phtype.Name), Name = _var.Name, DefaultValueRaw = _var.DefaultValueRaw });
				} else {
					ClassVars.Add (_var);
				}
			}
			ClassFuncs = new List<AstClassFunc> ();
			foreach (var _func in Class.ClassFuncs) {
				ClassFuncs.Add (new AstClassFunc (this, _func, GetImplType));
			}
		}

		public IAstType GetImplType (string _ttype_name) {
			for (int i = 0; i < Class.Templates.Count; ++i) {
				if (_ttype_name == Class.Templates[i].Name)
					return Templates[i];
			}
			return null;
		}

		public AstType_Class GetClassType () => AstType_Class.GetType (Token, Class, Templates);

		public bool Compile () {
			if (m_compiled)
				return false;
			m_compiled = true;

			Info.CurrentClass = this;

			// Antlr转AST
			foreach (var _var in ClassVars)
				_var.ToAST ();
			foreach (var _func in ClassFuncs)
				_func.ToAST ();

			// 处理AST
			for (int i = 0; i < ExprTraversals.TraversalTypes.Count; ++i) {
				Info.CurrentTraversalType = ExprTraversals.TraversalTypes[i];

				// 类成员变量默认初始化值
				for (int j = 0; j < ClassVars.Count; ++j) {
					if (ClassVars[j].DefaultValue == null)
						continue;
					Info.CurrentFunc = null;
					Info.CurrentFuncVariables = new List<Info.FuncArgumentOrVars> ();
					Info.CurrentFuncVariables.Add (new Info.FuncArgumentOrVars { Group = 0, Vars = new Dictionary<string, AstStmt_DefVariable> () });
					//
					ClassVars[j].DefaultValue = ClassVars[j].DefaultValue.TraversalWrap ((_deep: 0, _group: 0, _loop: i, _cb: ExprTraversals.Traversal));
				}

				// 类成员方法
				for (int j = 0; j < ClassFuncs.Count; ++j) {
					Info.CurrentFunc = ClassFuncs[j];
					Info.CurrentFuncVariables = new List<Info.FuncArgumentOrVars> ();
					Info.CurrentFuncVariables.Add (new Info.FuncArgumentOrVars { Group = 0, ClassFunc = Info.CurrentFunc });
					Info.CurrentFuncVariables.Add (new Info.FuncArgumentOrVars { Group = 1, Vars = new Dictionary<string, AstStmt_DefVariable> () });
					//
					ClassFuncs[j].BodyCodes.TraversalWraps ((_deep: 1, _group: 0, _loop: i, _cb: ExprTraversals.Traversal));
				}
			}

			foreach (var _func in ClassFuncs)
				_func.ExpandFunc ();
			return true;
		}

		public override string GenerateCSharp (int _indent) {
			Info.CurrentClass = this;
			Info.CurrentFuncVariables = null;
			//
			var _sb = new StringBuilder ();
			_sb.AppendLine ($"{_indent.Indent ()}{Class.Level.ToString ().ToLower ()} class {FullName[(FullName.LastIndexOf ('.') + 1)..]} {{");
			foreach (var _var in ClassVars)
				_sb.Append (_var.GenerateCSharp (_indent + 1));
			foreach (var _func in ClassFuncs)
				_sb.Append (_func.GenerateCSharp (_indent + 1));
			_sb.AppendLine ($"{_indent.Indent ()}}}");
			return _sb.ToString ();
		}

		public int GetRealAttachVarPos (int _enum_index) => -1;
	}
}

using fac.AntlrTools;
using fac.ASTs.Stmts;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs {
	public class AstTemplateClass: IAst {
		public string FullName { init; get; }
		public PublicLevel Level { init; get; }
		public List<AstEnumItem> ClassEnumItems { get; } = new List<AstEnumItem> ();
		public List<AstType_Placeholder> Templates { init; get; }
		public List<AstClassVar> ClassVars { init; get; }
		public List<AstClassFunc> ClassFuncs { init; get; }



		public static AstTemplateClass FromContext (FaParser.ClassStmtContext _ctx) {
			var _templates = (from p in _ctx.classTemplates ().type () select new AstType_Placeholder { Token = p.Start, Name = p.GetText () }).ToList ();
			foreach (var _var in _templates) {
				if (_var.Name[0] != 'T')
					throw new CodeException (_var.Token, "模板名称必须以大写字母 T 开头");
			}
			return new AstTemplateClass {
				Token = _ctx.Start,
				FullName = $"{Info.CurrentNamespace}.{_ctx.id ().GetText ()}",
				Level = Common.ParseEnum<PublicLevel> (_ctx.publicLevel ()?.GetText ()) ?? PublicLevel.Public,
				Templates = _templates,
				ClassVars = (from p in _ctx.classVar () select new AstClassVar (p)).ToList (),
				ClassFuncs = (from p in _ctx.classFunc () select new AstClassFunc (p)).ToList (),
			};
		}

		public void Compile () {
			//Info.CurrentClass = this;

			//// Antlr转AST
			//foreach (var _var in ClassVars)
			//	_var.ToAST ();
			//foreach (var _func in ClassFuncs)
			//	_func.ToAST ();

			//// 处理AST
			//for (int i = 0; i < ExprTraversals.TraversalTypes.Count; ++i) {
			//	Info.CurrentTraversalType = ExprTraversals.TraversalTypes[i];

			//	// 类成员变量默认初始化值
			//	for (int j = 0; j < ClassVars.Count; ++j) {
			//		if (ClassVars[j].DefaultValue == null)
			//			continue;
			//		Info.CurrentFunc = null;
			//		Info.CurrentFuncVariables = new List<Info.FuncArgumentOrVars> ();
			//		Info.CurrentFuncVariables.Add (new Info.FuncArgumentOrVars { Group = 0, Vars = new Dictionary<string, AstStmt_DefVariable> () });
			//		//
			//		ClassVars[j].DefaultValue = ClassVars[j].DefaultValue.TraversalWrap ((_deep: 0, _group: 0, _cb: (_expr, _deep, _group) => ExprTraversals.Traversal (_expr, i, _deep, _group)));
			//	}

			//	// 类成员方法
			//	for (int j = 0; j < ClassFuncs.Count; ++j) {
			//		Info.CurrentFunc = ClassFuncs[j];
			//		Info.CurrentFuncVariables = new List<Info.FuncArgumentOrVars> ();
			//		Info.CurrentFuncVariables.Add (new Info.FuncArgumentOrVars { Group = 0, ClassFunc = Info.CurrentFunc });
			//		Info.CurrentFuncVariables.Add (new Info.FuncArgumentOrVars { Group = 1, Vars = new Dictionary<string, AstStmt_DefVariable> () });
			//		//
			//		ClassFuncs[j].BodyCodes.TraversalWraps ((_deep: 1, _group: 0, _cb: (_expr, _deep, _group) => ExprTraversals.Traversal (_expr, i, _deep, _group)));
			//	}
			//}

			//foreach (var _func in ClassFuncs)
			//	_func.ExpandFunc ();
		}

		public override string GenerateCSharp (int _indent) {
			//Info.CurrentClass = this;
			//Info.CurrentFuncVariables = null;
			////
			//var _sb = new StringBuilder ();
			//_sb.Append ($"{_indent.Indent ()}{Level.ToString ().ToLower ()} {ClassType.ToString ().ToLower ()} {FullName[(FullName.LastIndexOf ('.') + 1)..]}");
			//if (Variants?.Count > 0) {
			//	_sb.Append ('<').Append (string.Join (", ", from p in Templates select p.Name)).Append ('>');
			//}
			//_sb.AppendLine ($" {{");
			//foreach (var _var in ClassVars)
			//	_sb.Append (_var.GenerateCSharp (_indent + 1));
			//foreach (var _func in ClassFuncs)
			//	_sb.Append (_func.GenerateCSharp (_indent + 1));
			//_sb.AppendLine ($"{_indent.Indent ()}}}");
			//return _sb.ToString ();
		}
	}
}

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
	public enum AstClassType { Class, Interface, Enum }

	public class AstClass: IAst, IAstClass {
		public string FullName { init; get; }
		public PublicLevel Level { init; get; }
		public AstClassType ClassType { init; get; }
		public List<AstEnumItem> ClassEnumItems { get; } = new List<AstEnumItem> ();
		public List<AstType_Placeholder> Variants { init; get; }
		public List<AstClassVar> ClassVars { init; get; }
		public List<AstClassFunc> ClassFuncs { init; get; }



		public AstClass (FaParser.ClassStmtContext _ctx) {
			Token = _ctx.Start;
			//
			FullName = $"{Info.CurrentNamespace}.{_ctx.id ().GetText ()}";
			//
			Level = Common.ParseEnum<PublicLevel> (_ctx.publicLevel ()?.GetText ()) ?? PublicLevel.Public;
			//
			ClassType = Common.ParseEnum<AstClassType> (_ctx.classType ().GetText ()) ?? AstClassType.Class;
			//
			//if (_ctx.classVariant () != null) {
			//	Variants = (from p in _ctx.classVariant ().id () select new AstType_Placeholder { Token = p.Symbol, Name = p.GetText () }).ToList ();
			//	foreach (var _var in Variants) {
			//		if (_var.Name[0] != 'T')
			//			throw new CodeException (_var.Token, "模板名称必须以大写字母 T 开头");
			//	}
			//} else {
			//	Variants = new List<AstType_Placeholder> ();
			//}
			//
			ClassVars = (from p in _ctx.classVar () select new AstClassVar (p)).ToList ();
			if (ClassType == AstClassType.Enum && ClassVars.Count > 0)
				throw new CodeException (ClassVars[0].Token, $"{ClassType} 类型结构不允许出现成员变量");
			//
			ClassFuncs = (from p in _ctx.classFunc () select new AstClassFunc (p)).ToList ();
		}

		public void Compile () {
			Info.CurrentClass = this;

			// Antlr转AST
			foreach (var _var in ClassVars)
				_var.ToAST ();
			foreach (var _func in ClassFuncs)
				_func.ToAST ();

			// 处理AST
			for (int i = 0; i < ExprTraversals.TraversalTypes.Count; ++i) {
				Info.CurrentTraversalType = ExprTraversals.TraversalTypes [i];

				// 类成员变量默认初始化值
				for (int j = 0; j < ClassVars.Count; ++j) {
					if (ClassVars[j].DefaultValue == null)
						continue;
					Info.CurrentFunc = null;
					Info.CurrentFuncVariables = new List<Info.FuncArgumentOrVars> ();
					Info.CurrentFuncVariables.Add (new Info.FuncArgumentOrVars { Group = 0, Vars = new Dictionary<string, AstStmt_DefVariable> () });
					//
					if (Info.TraversalFirst)
						ClassVars[j].DefaultValue = ExprTraversals.Traversal (ClassVars[j].DefaultValue, i, 0, 0);
					ClassVars[j].DefaultValue.TraversalWrap (0, 0, (_expr, _deep, _group) => ExprTraversals.Traversal (_expr, i, _deep, _group));
					if (Info.TraversalLast)
						ClassVars[j].DefaultValue = ExprTraversals.Traversal (ClassVars[j].DefaultValue, i, 0, 0);
				}

				// 类成员方法
				for (int j = 0; j < ClassFuncs.Count; ++j) {
					Info.CurrentFunc = ClassFuncs[j];
					Info.CurrentFuncVariables = new List<Info.FuncArgumentOrVars> ();
					Info.CurrentFuncVariables.Add (new Info.FuncArgumentOrVars { Group = 0, ClassFunc = Info.CurrentFunc });
					Info.CurrentFuncVariables.Add (new Info.FuncArgumentOrVars { Group = 1, Vars = new Dictionary<string, AstStmt_DefVariable> () });
					//
					for (int k = 0; k < ClassFuncs[j].BodyCodes.Count; ++k) {
						if (Info.TraversalFirst)
							ClassFuncs[j].BodyCodes[k] = ExprTraversals.Traversal (ClassFuncs[j].BodyCodes[k], i, 1, 0) as IAstStmt;
						ClassFuncs[j].BodyCodes[k].TraversalWrap (1, 0, (_expr, _deep, _group) => ExprTraversals.Traversal (_expr, i, _deep, _group));
						if (Info.TraversalLast)
							ClassFuncs[j].BodyCodes[k] = ExprTraversals.Traversal (ClassFuncs[j].BodyCodes[k], i, 1, 0) as IAstStmt;
					}
				}
			}
			//foreach (var _var in ClassVars) {
			//	Info.CurrentFunc = null;
			//	Info.CurrentFuncVariables = new List<Info.FuncArgumentOrVars> ();
			//	Info.CurrentFuncVariables.Add (new Info.FuncArgumentOrVars { Group = 0, Vars = new Dictionary<string, AstStmt_DefVariable> () });
			//	if (_var.DefaultValue != null)
			//		_var.DefaultValue = _var.DefaultValue.TraversalCalcType (_var.DataType);
			//}
			//foreach (var _func in ClassFuncs) {
			//	Info.CurrentFunc = _func;
			//	Info.CurrentFuncVariables = new List<Info.FuncArgumentOrVars> ();
			//	Info.CurrentFuncVariables.Add (new Info.FuncArgumentOrVars { Group = -1, ClassFunc = Info.CurrentFunc });
			//	Info.CurrentFuncVariables.Add (new Info.FuncArgumentOrVars { Group = 0, Vars = new Dictionary<string, AstStmt_DefVariable> () });
			//	_func.BodyCodes.TraversalCalcType ();
			//}
		}

		public override string GenerateCSharp (int _indent) {
			Info.CurrentClass = this;
			Info.CurrentFuncVariables = null;
			//
			var _sb = new StringBuilder ();
			_sb.Append ($"{_indent.Indent ()}{Level.ToString ().ToLower ()} {ClassType.ToString ().ToLower ()} {FullName[(FullName.LastIndexOf ('.') + 1)..]}");
			if (Variants?.Count > 0) {
				_sb.Append ('<').Append (string.Join (", ", from p in Variants select p.Name)).Append ('>');
			}
			_sb.AppendLine ($" {{");
			foreach (var _var in ClassVars)
				_sb.Append (_var.GenerateCSharp (_indent + 1));
			foreach (var _func in ClassFuncs)
				_sb.Append (_func.GenerateCSharp (_indent + 1));
			_sb.AppendLine ($"{_indent.Indent ()}}}");
			return _sb.ToString ();
		}
	}
}

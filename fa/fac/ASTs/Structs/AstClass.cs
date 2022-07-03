using Antlr4.Runtime;
using fac.AntlrTools;
using fac.ASTs.Stmts;
using fac.ASTs.Structs.Part;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Structs {
	public class AstClass: IAst, IAstClass {
		public List<AstAnnoUsingPart> Annotations { init; get; }
		public string FullName { init; get; }
		public PublicLevel Level { init; get; }
		public List<AstEnumItem>? ClassEnumItems { get; } = null;
		public List<AstClassVar> ClassVars { init; get; }
		public List<AstClassFunc> ClassFuncs { get; set; }
		private bool m_compiled = false;



		private AstClass (FaParser.ClassBlockContext _ctx) {
			Annotations = AstAnnoUsingPart.FromContexts (_ctx.annoUsingPart ());
			Token = _ctx.Start;
			FullName = $"{Info.CurrentNamespace}.{_ctx.id ().GetText ()}";
			Level = Common.ParseEnum<PublicLevel> (_ctx.publicLevel ()?.GetText ()) ?? PublicLevel.Public;
			ClassVars = (from p in _ctx.classItemVar () select new AstClassVar (p)).ToList ();
			ClassFuncs = (from p in _ctx.classItemFunc () select new AstClassFunc (this, p)).ToList ();
		}
		public static AstClass FromContext (FaParser.ClassBlockContext _ctx) {
			return new AstClass (_ctx);
		}

		public void ProcessType () {
			Info.CurrentClass = this;
			if (ClassEnumItems != null) {
				for (int i = 0; i < ClassEnumItems.Count; ++i)
					ClassEnumItems[i].ProcessType ();
			}
			for (int i = 0; i < ClassVars.Count; ++i)
				ClassVars[i].ProcessType ();
			for (int i = 0; i < ClassFuncs.Count; ++i)
				ClassFuncs[i].ProcessType ();
		}

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
				Info.CurrentTraversalType = ExprTraversals.TraversalTypes [i];

				// 类成员变量默认初始化值
				for (int j = 0; j < ClassVars.Count; ++j) {
					if (ClassVars[j].DefaultValue == null)
						continue;
					Info.InitFunc (null);
					//
					ClassVars[j].DefaultValue = ClassVars[j].DefaultValue.TraversalWrap ((_deep: 0, _group: 0, _loop: i, _cb: ExprTraversals.Traversal));
				}

				// 类成员方法
				for (int j = 0; j < ClassFuncs.Count; ++j) {
					Info.InitFunc (ClassFuncs[j]);
					//
					if (i == 2) {
						ClassFuncs[j].BodyCodes.TraversalCalcTypeWrap ();
						ExprTraversals.Init = ExprTraversals.Complete = true;
						ClassFuncs[j].BodyCodes.TraversalWraps ((_deep: 1, _group: 0, _loop: i, _cb: ExprTraversals.Traversal));
						if (!ExprTraversals.Complete) {
							ExprTraversals.Init = false;
							Info.InitFunc (ClassFuncs[j]);
							ClassFuncs[j].BodyCodes.TraversalWraps ((_deep: 1, _group: 0, _loop: 0, _cb: ExprTraversals.Traversal));
							Info.InitFunc (ClassFuncs[j]);
							ClassFuncs[j].BodyCodes.TraversalWraps ((_deep: 1, _group: 0, _loop: 1, _cb: ExprTraversals.Traversal));
							ClassFuncs[j].BodyCodes.TraversalCalcTypeWrap ();
							Info.InitFunc (ClassFuncs[j]);
							ClassFuncs[j].BodyCodes.TraversalWraps ((_deep: 1, _group: 0, _loop: i, _cb: ExprTraversals.Traversal));
						}
					} else {
						ClassFuncs[j].BodyCodes.TraversalWraps ((_deep: 1, _group: 0, _loop: i, _cb: ExprTraversals.Traversal));
					}
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
			_sb.Append ($"{_indent.Indent ()}{Level.ToString ().ToLower ()} class {FullName[(FullName.LastIndexOf ('.') + 1)..]}");
			_sb.AppendLine ($" {{");
			foreach (var _var in ClassVars)
				_sb.Append (_var.GenerateCSharp (_indent + 1));
			foreach (var _func in ClassFuncs)
				_sb.Append (_func.GenerateCSharp (_indent + 1));
			_sb.AppendLine ($"{_indent.Indent ()}}}");
			return _sb.ToString ();
		}

		public override string GenerateCpp (int _indent) {
			Info.CurrentClass = this;
			Info.CurrentFuncVariables = null;
			//
			var _sb = new StringBuilder ();
			_sb.Append ($"{_indent.Indent ()}class {FullName[(FullName.LastIndexOf ('.') + 1)..]}");
			_sb.AppendLine ($" {{");
			foreach (var _var in ClassVars)
				_sb.Append (_var.GenerateCpp (_indent + 1));
			foreach (var _func in ClassFuncs)
				_sb.Append (_func.GenerateCpp (_indent + 1));
			_sb.AppendLine ($"{_indent.Indent ()}}};");
			return _sb.ToString ();
		}

		public int GetTemplateNum () => 0;

		public IAstClass GetInst (List<IAstType> _templates, IToken _token = null) {
			if ((_templates?.Count ?? 0) > 0)
				throw new CodeException (_token, $"非泛型类型无法指定模板参数");
			return this;
		}
	}
}

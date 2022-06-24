using Antlr4.Runtime;
using fac.AntlrTools;
using fac.ASTs.Structs.Part;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Structs {
	public class AstInterface: IAst, IAstClass {
		public List<AstAnnoUsingPart> Annotations { init; get; }
		public string FullName { init; get; }
		public PublicLevel Level { init; get; }
		public List<AstEnumItem> ClassEnumItems { get; } = new List<AstEnumItem> ();
		public List<AstType_Placeholder> Templates { init; get; }
		public List<AstClassVar> ClassVars { init; get; }
		public List<AstClassFunc> ClassFuncs { get; private set; }
		private bool m_compiled { get; set; } = false;
		public Dictionary<string, AstInterfaceInst> Insts { get; set; } = new Dictionary<string, AstInterfaceInst> ();



		private AstInterface () { }
		public static AstInterface FromContext (FaParser.InterfaceBlockContext _ctx) {
			var _templates = _ctx.blockTemplates () != null ? (from p in _ctx.blockTemplates ().id () select new AstType_Placeholder { Token = p.Start, Name = p.GetText () }).ToList () : null;
			foreach (var _var in _templates) {
				if (_var.Name [0] != 'T')
					throw new CodeException (_var.Token, "模板名称必须以大写字母 T 开头");
			}
			var _ret = new AstInterface {
				Annotations = AstAnnoUsingPart.FromContexts (_ctx.annoUsingPart ()),
				Token = _ctx.Start,
				FullName = $"{Info.CurrentNamespace}.{_ctx.id ().GetText ()}",
				Level = Common.ParseEnum<PublicLevel> (_ctx.publicLevel ()?.GetText ()) ?? PublicLevel.Public,
				Templates = _templates,
				ClassVars = (from p in _ctx.classItemVar () select new AstClassVar (p)).ToList (),
			};
			_ret.ClassFuncs = (from p in _ctx.interfaceItemFunc () select new AstClassFunc (_ret, p)).ToList ();
			return _ret;
		}

		public void ProcessType () {
			Info.CurrentClass = this;
			for (int i = 0; i < (ClassEnumItems?.Count ?? 0); ++i)
				ClassEnumItems[i].ProcessType ();
			for (int i = 0; i < (ClassVars?.Count ?? 0); ++i)
				ClassVars[i].ProcessType ();
			for (int i = 0; i < (ClassFuncs?.Count ?? 0); ++i)
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

			// 处理AST
			for (int i = 0; i < ExprTraversals.TraversalTypes.Count; ++i) {
				Info.CurrentTraversalType = ExprTraversals.TraversalTypes[i];

				// 类成员变量默认初始化值
				for (int j = 0; j < ClassVars.Count; ++j) {
					if (ClassVars[j].DefaultValue == null)
						continue;
					Info.InitFunc (null);
					//
					ClassVars[j].DefaultValue = ClassVars[j].DefaultValue.TraversalWrap ((_deep: 0, _group: 0, _loop: i, _cb: ExprTraversals.Traversal));
				}
			}
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

		public int GetTemplateNum () => Templates?.Count ?? 0;

		public IAstClass GetInst (List<IAstType> _templates, IToken _token = null) {
			//if ((_templates?.Count ?? 0) > 0)
			//	throw new CodeException (_token, $"非泛型类型无法指定模板参数");
			//return this;
			if (Templates.Count != (_templates?.Count ?? 0))
				throw new CodeException (_token, $"模板参数数量不匹配，需 {Templates?.Count ?? 0} 个参数，实际传入 {_templates?.Count ?? 0} 个参数");
			foreach (var _type in _templates) {
				if (_type is AstType_Void || _type is AstType_Any)
					throw new CodeException (_token, "不可将 void 类型或 any 类型用于模板");
			}
			string _type_str = $"{FullName}<{string.Join (",", from p in _templates select p.ToString ())}>";
			if (Insts.ContainsKey (_type_str))
				return Insts [_type_str];
			var _tcls_inst = new AstInterfaceInst(Token, this, _templates, _type_str);
			Insts [_type_str] = _tcls_inst;
			return _tcls_inst;
		}
	}
}

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
	public class AstTemplateClass: IAst, IAstClass {
		public List<AstAnnoUsingPart> Annotations { init; get; }
		public string FullName { init; get; }
		public PublicLevel Level { init; get; }
		public List<AstEnumItem>? ClassEnumItems { get; } = new List<AstEnumItem> ();
		public List<AstType_Placeholder> Templates { init; get; }
		public List<AstClassVar> ClassVars { init; get; }
		public List<AstClassFunc> ClassFuncs { get; set; }
		public List<AstConstructFunc> ConstructFuncs { get; } = new List<AstConstructFunc> ();
		public AstConstructFunc? DistructFunc { get; } = null;
		public Dictionary<string, AstTemplateClassInst> Insts { get; set; } = new Dictionary<string, AstTemplateClassInst> ();



		public static AstTemplateClass FromContext (FaParser.ClassBlockContext _ctx) {
			var _templates = (from p in _ctx.blockTemplates ().id () select new AstType_Placeholder { Token = p.Start, Name = p.GetText () }).ToList ();
			foreach (var _var in _templates) {
				if (_var.Name[0] != 'T')
					throw new CodeException (_var.Token, "模板名称必须以大写字母 T 开头");
			}
			var _ret = new AstTemplateClass {
				Annotations = AstAnnoUsingPart.FromContexts (_ctx.annoUsingPart ()),
				Token = _ctx.Start,
				FullName = $"{Info.CurrentNamespace}.{_ctx.id ().GetText ()}",
				Level = Common.ParseEnum<PublicLevel> (_ctx.publicLevel ()?.GetText ()) ?? PublicLevel.Public,
				Templates = _templates,
				ClassVars = (from p in _ctx.classItemVar () select new AstClassVar (p)).ToList (),
			};
			_ret.ClassFuncs = (from p in _ctx.classItemFunc () select new AstClassFunc (_ret, p)).ToList ();
			return _ret;
		}

		public AstType_Class GetClassType () => throw new Exception ("不应执行此处代码");

		private bool _processed_type = false;
		public void ProcessType () {
			Info.CurrentClass = this;
			for (int i = 0; i < (ClassEnumItems?.Count ?? 0); ++i)
				ClassEnumItems[i].ProcessType ();
			for (int i = 0; i < (ClassVars?.Count ?? 0); ++i)
				ClassVars[i].ProcessType ();
			for (int i = 0; i < (ClassFuncs?.Count ?? 0); ++i)
				ClassFuncs[i].ProcessType ();
			foreach (var (_, _inst) in Insts)
				_inst.ProcessType ();
			_processed_type = true;
		}

		public bool Compile () {
			bool _b = false;
			foreach (var (_, _inst) in Insts)
				_b |= _inst.Compile ();
			return _b;
		}

		public override string GenerateCSharp (int _indent) {
			return string.Join ("", from p in Insts select p.Value.GenerateCSharp (_indent));
		}

		public override string GenerateCpp (int _indent) {
			return string.Join ("", from p in Insts select p.Value.GenerateCpp (_indent));
		}

		public int GetTemplateNum () => Templates.Count;

		public IAstClass GetInst (List<IAstType> _templates, IToken _token = null) {
			if (Templates.Count != (_templates?.Count ?? 0))
				throw new CodeException (_token, $"模板参数数量不匹配，需 {Templates.Count} 个参数，实际传入 {(_templates?.Count ?? 0)} 个参数");
			foreach (var _type in _templates) {
				if (_type is AstType_Void || _type is AstType_Any)
					throw new CodeException (_token, "不可将 void 类型或 any 类型用于模板");
			}
			string _type_str = $"{FullName}<{string.Join (",", from p in _templates select p.ToString ())}>";
			if (Insts.ContainsKey (_type_str))
				return Insts[_type_str];
			var _tcls_inst = new AstTemplateClassInst(Token, this, _templates, _type_str);
			Insts[_type_str] = _tcls_inst;
			if (_processed_type)
				_tcls_inst.ProcessType ();
			return _tcls_inst;
		}
	}
}

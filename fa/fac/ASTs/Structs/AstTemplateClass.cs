using Antlr4.Runtime;
using fac.AntlrTools;
using fac.ASTs.Stmts;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Structs {
	public class AstTemplateClass: IAst, IAstClass {
		public string FullName { init; get; }
		public PublicLevel Level { init; get; }
		public List<AstEnumItem> ClassEnumItems { get; } = new List<AstEnumItem> ();
		public List<AstType_Placeholder> Templates { init; get; }
		public List<AstClassVar> ClassVars { init; get; }
		public List<AstClassFunc> ClassFuncs { get; set; }
		public Dictionary<string, AstTemplateClassInst> Insts { get; set; } = new Dictionary<string, AstTemplateClassInst> ();



		public static AstTemplateClass FromContext (FaParser.ClassStmtContext _ctx) {
			var _templates = (from p in _ctx.classTemplates ().type () select new AstType_Placeholder { Token = p.Start, Name = p.GetText () }).ToList ();
			foreach (var _var in _templates) {
				if (_var.Name[0] != 'T')
					throw new CodeException (_var.Token, "模板名称必须以大写字母 T 开头");
			}
			var _ret = new AstTemplateClass {
				Token = _ctx.Start,
				FullName = $"{Info.CurrentNamespace}.{_ctx.id ().GetText ()}",
				Level = Common.ParseEnum<PublicLevel> (_ctx.publicLevel ()?.GetText ()) ?? PublicLevel.Public,
				Templates = _templates,
				ClassVars = (from p in _ctx.classVar () select new AstClassVar (p)).ToList (),
			};
			_ret.ClassFuncs = (from p in _ctx.classFunc () select new AstClassFunc (_ret, p)).ToList ();
			return _ret;
		}

		public AstType_Class GetClassType () => throw new Exception ("不应执行此处代码");

		public void ProcessType () {
			for (int i = 0; i < (ClassEnumItems?.Count ?? 0); ++i)
				ClassEnumItems[i].ProcessType ();
			for (int i = 0; i < (ClassVars?.Count ?? 0); ++i)
				ClassVars[i].ProcessType ();
			for (int i = 0; i < (ClassFuncs?.Count ?? 0); ++i)
				ClassFuncs[i].ProcessType ();
			foreach (var (_name, _inst) in Insts)
				_inst.ProcessType ();
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

		public int GetTemplateNum () => Templates.Count;

		public IAstClass GetInst (List<IAstType> _templates, IToken _token = null) {
			if (Templates.Count != (_templates?.Count ?? 0))
				throw new CodeException (_token, $"模板参数数量不匹配，需 {Templates.Count} 个参数，实际传入 {(_templates?.Count ?? 0)} 个参数");
			string _type_str = $"{FullName}<{string.Join (",", from p in _templates select p.ToString ())}>";
			if (Insts.ContainsKey (_type_str))
				return Insts[_type_str];
			var _tcls_inst = new AstTemplateClassInst(Token, this, _templates, _type_str);
			Insts[_type_str] = _tcls_inst;
			return _tcls_inst;
		}
	}
}

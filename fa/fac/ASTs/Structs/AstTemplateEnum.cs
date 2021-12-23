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
	public class AstTemplateEnum: IAst, IAstClass {
		public string FullName { init; get; }
		public PublicLevel Level { init; get; }
		public List<AstEnumItem> ClassEnumItems { init; get; }
		public List<AstType_Placeholder> Templates { init; get; }
		public List<AstClassVar> ClassVars { init; get; }
		public List<AstClassFunc> ClassFuncs { get; set; }
		public Dictionary<string, AstTemplateEnumInst> Insts { get; set; } = new Dictionary<string, AstTemplateEnumInst> ();



		public static AstTemplateEnum FromContext (FaParser.EnumStmtContext _ctx) {
			var _templates = (from p in _ctx.classTemplates ().type () select new AstType_Placeholder { Token = p.Start, Name = p.GetText () }).ToList ();
			foreach (var _var in _templates) {
				if (_var.Name[0] != 'T')
					throw new CodeException (_var.Token, "模板名称必须以大写字母 T 开头");
			}
			var _enum_items = (from p in _ctx.classEnumItem () select new AstEnumItem (p)).ToList ();
			var _types = (from p in _enum_items where p.AttachType != null select p.AttachType).ToList ();
			for (int i = 0; i < _types.Count - 1; ++i) {
				for (int j = i + 1; j < _types.Count; ++j) {
					if (_types[i].IsSame (_types[j]))
						_types.RemoveAt (j--);
				}
			}
			var _vars = new List<AstClassVar> { new AstClassVar { Token = null, Level = PublicLevel.Public, Static = false, DataType = IAstType.FromName ("int"), Name = "@index" } };
			_vars.AddRange (from p in _types select new AstClassVar { Token = p.Token, Level = PublicLevel.Public, Static = false, DataType = p, DefaultValueRaw = null, Name = Common.GetTempId () });
			var _ret = new AstTemplateEnum {
				Token = _ctx.Start,
				FullName = $"{Info.CurrentNamespace}.{_ctx.id ().GetText ()}",
				Level = Common.ParseEnum<PublicLevel> (_ctx.publicLevel ()?.GetText ()) ?? PublicLevel.Public,
				ClassEnumItems = _enum_items,
				Templates = _templates,
				ClassVars = _vars,
				ClassFuncs = new List<AstClassFunc> (),
			};
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
			var _tcls_inst = new AstTemplateEnumInst(Token, this, _templates, _type_str);
			Insts[_type_str] = _tcls_inst;
			return _tcls_inst;
		}
	}
}

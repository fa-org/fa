using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs {
	class AstEnum: IAst, IAstClass {
		public string FullName { init; get; }
		public PublicLevel Level { init; get; }
		public List<AstClassEnumItem> ClassEnumItems { init; get; }
		public List<AstClassVar> ClassVars { init; get; }
		public List<AstClassFunc> ClassFuncs { get; } = new List<AstClassFunc> ();



		public AstEnum (FaParser.EnumStmtContext _ctx) {
			Token = _ctx.Start;
			//
			FullName = $"{Info.CurrentNamespace}.{_ctx.Id ().GetText ()}";
			//
			Level = Common.ParseEnum<PublicLevel> (_ctx.publicLevel ()?.GetText ()) ?? PublicLevel.Public;
			//
			ClassEnumItems = (from p in _ctx.classEnumItem () select new AstClassEnumItem (p)).ToList ();
			//
			var _types = (from p in ClassEnumItems where p.AttachType != null select p.AttachType).ToList ();
			for (int i = 0; i < _types.Count - 1; ++i) {
				for (int j = i + 1; j < _types.Count; ++j) {
					if (_types[i].IsSame (_types[j]))
						_types.RemoveAt (j--);
				}
			}
			ClassVars = new List<AstClassVar> { new AstClassVar { Token = null, Level = PublicLevel.Public, Static = false, DataType = IAstType.FromName ("int"), Name = "@index" } };
			ClassVars.AddRange (from p in _types select new AstClassVar { Token = p.Token, Level = PublicLevel.Public, Static = false, DataType = p, DefaultValueRaw = null, Name = Common.GetTempId () });
		}

		public void Compile () {
			Info.CurrentClass = null;
			Info.CurrentFuncVariables = null;
		}

		public override (string, string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb) {
			Info.CurrentClass = null;
			Info.CurrentFuncVariables = null;
			//
			var _sb = new StringBuilder ();
			_sb.Append ($"{_indent.Indent ()}{Level.ToString ().ToLower ()} class {FullName[(FullName.LastIndexOf ('.') + 1)..]}");
			_sb.AppendLine ($" {{");
			foreach (var _var in ClassVars) {
				var (_a, _b, _c) = _var.GenerateCSharp (_indent + 1, null);
				_sb.Append (_a).Append (_b).Append (_c);
			}
			_sb.AppendLine ($"{_indent.Indent ()}}}");
			return ("", _sb.ToString (), "");
		}
	}
}

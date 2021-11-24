using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	class AstType_Class: IAstType {
		public IAstClass Class { get; set; }
		public List<IAstType> TemplateTypes { get; set; }



		public override string ToString () => $"{Class.FullName}{((TemplateTypes?.Count ?? 0) > 0 ? $"<{string.Join (", ", from p in TemplateTypes select p.GenerateCSharp_Type ())}>" : "")}";
		public override string GenerateCSharp_Type () {
			string _full_name = Class.FullName;
			if (_full_name.StartsWith (Info.CurrentNamespace))
				_full_name = _full_name[(Info.CurrentNamespace.Length + 1)..];
			if (_full_name.StartsWith ("."))
				_full_name = _full_name[1..];
			return $"{_full_name}{((TemplateTypes?.Count ?? 0) > 0 ? $"<{string.Join (", ", from p in TemplateTypes select p.GenerateCSharp_Type ())}>" : "")}";
		}
	}
}

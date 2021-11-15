using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	class AstType_Class: IAstType {
		public AstClass Class { get; set; }
		public List<IAstType> TemplateTypes { get; set; }



		public override (string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb) {
			if ((TemplateTypes?.Count ?? 0) == 0) {
				return ("", $"{Class.FullName}");
			} else {
				return ("", $"{Class.FullName}<{string.Join (", ", (from p in TemplateTypes select p.GenerateCSharp (_indent, _check_cb).Item2))}>");
			}
		}
	}
}

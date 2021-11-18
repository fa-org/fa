using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	class AstType_Class: IAstType {
		public IAstClass Class { get; set; }
		public List<IAstType> TemplateTypes { get; set; }



		public override string GenerateCSharp_Type () => $"{Class.FullName}{((TemplateTypes?.Count ?? 0) > 0 ? $"<{string.Join (", ", from p in TemplateTypes select p.GenerateCSharp_Type ())}>" : "")}";
	}
}

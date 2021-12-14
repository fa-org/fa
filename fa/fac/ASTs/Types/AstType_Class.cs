using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	public class AstType_Class: IAstType {
		public IAstClass Class { get; set; }



		public override string ToString () => Class.FullName;
		public override string GenerateCSharp (int _indent) {
			string _full_name = Class.FullName;
			if (_full_name.StartsWith (Info.CurrentNamespace))
				_full_name = _full_name[(Info.CurrentNamespace.Length + 1)..];
			if (_full_name.StartsWith ("."))
				_full_name = _full_name[1..];
			_full_name = _full_name.Replace ($"<{Info.CurrentNamespace}.", "<").Replace ($",{Info.CurrentNamespace}.", ",");
			return _full_name;
		}
	}
}

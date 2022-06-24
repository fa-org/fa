using Antlr4.Runtime;
using fac.ASTs.Structs;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	public class AstType_Class: IAstType {
		public IAstClass Class { get; set; }



		private AstType_Class () { }
		public static AstType_Class GetType (IToken _token, IAstClass _class) {
			return new AstType_Class { Token = _token, Class = _class };
		}

		public override string ToString () {
			string _name = Class.FullName;
			if (_name == "fa.OptionalVoid") {
				return "void?";
			} else if (_name.StartsWith ("fa.Optional<")) {
				return $"{_name[12..^1]}?";
			} else {
				return _name;
			}
		}

		public override string GenerateCSharp (int _indent) {
			string _full_name = Class.CSharpFullName;
			if (_full_name.StartsWith (Info.CurrentNamespace))
				_full_name = _full_name[(Info.CurrentNamespace.Length + 1)..];
			_full_name = _full_name.Replace ($"__lt__{Info.CurrentNamespace}.", "__lt__").Replace ($"__comma__{Info.CurrentNamespace}.", "__comma__");
			return _full_name;
		}

		public override string GenerateCpp (int _indent) {
			string _full_name = Class.CSharpFullName;
			if (_full_name.StartsWith (Info.CurrentNamespace))
				_full_name = _full_name [(Info.CurrentNamespace.Length + 1)..];
			_full_name = _full_name.Replace ($"__lt__{Info.CurrentNamespace}.", "__lt__").Replace ($"__comma__{Info.CurrentNamespace}.", "__comma__");
			return _full_name;
		}
	}
}

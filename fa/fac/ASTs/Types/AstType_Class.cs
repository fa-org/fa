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
		public static AstType_Class GetType (IToken _token, IAstClass _class, List<IAstType> _templates = null, bool _mut = false) {
			if ((_templates?.Count ?? 0) > 0) {
				if (_class is AstTemplateClass _tclass) {
					_class = _tclass.GetInst (_token, _templates);
				} else if (_class is AstTemplateEnum _tenum) {
					_class = _tenum.GetInst (_token, _templates);
				} else {
					throw new CodeException (_token, "非模板类型无法指定模板参数");
				}
			} else {
				if (_class is AstTemplateClass)
					throw new CodeException (_token, "模板类型必须指定模板参数");
			}
			return new AstType_Class { Token = _token, Mut = _mut, Class = _class };
		}

		public override string ToString () => Class.FullName;

		public override string GenerateCSharp (int _indent) {
			string _full_name = Class.FullName;
			if (_full_name.StartsWith (Info.CurrentNamespace))
				_full_name = _full_name[(Info.CurrentNamespace.Length + 1)..];
			_full_name = _full_name.Replace ($"<{Info.CurrentNamespace}.", "<").Replace ($",{Info.CurrentNamespace}.", ",");
			return _full_name;
		}
	}
}

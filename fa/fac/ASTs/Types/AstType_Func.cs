using Antlr4.Runtime;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	public class AstType_Func: IAstType {
		public IAstType ReturnType { get; set; }
		public List<(IAstType _type, ArgumentTypeExt _ext)> ArgumentTypes { get; set; }



		public override string ToString () {
			var _list = new List<(IAstType _type, ArgumentTypeExt _ext)> ();
			_list.AddRange (ArgumentTypes);
			_list.Add ((_type: ReturnType, _ext: ArgumentTypeExt.None));
			return $"Func<{string.Join (", ", _list)}>";
		}
		//public static AstType_Func FromType (string _type_str, IToken _token, List<IAstType> _templates) {
		//	if (_type_str != "Func" && _type_str != "Action")
		//		return null;
		//	var _functype = new AstType_Func { Token = _token };
		//	if (_type_str == "Func") {
		//		_functype.ReturnType = _templates[^1];
		//		_templates.RemoveAt (_templates.Count - 1);
		//		_functype.ArgumentTypes = _templates;
		//	} else {
		//		_functype.ReturnType = new AstType_Void { Token = _token };
		//	}
		//	return _functype;
		//}

		public override string GenerateCSharp (int _indent) {
			string _func_type = "Action";
			List<(IAstType _type, ArgumentTypeExt _ext)> _list = ArgumentTypes;
			if (ReturnType is not AstType_Void) {
				_func_type = "Func";
				_list = new List<(IAstType _type, ArgumentTypeExt _ext)> ();
				_list.AddRange (ArgumentTypes);
				_list.Add ((_type: ReturnType, _ext: ArgumentTypeExt.None));
			}
			return @$"{_func_type}<{string.Join (", ", from p in _list
														let _s1 = (p._ext == ArgumentTypeExt.Mut ? "ref " : "")
														let _s2 = p._type.GenerateCSharp (_indent)
														select $"{_s1}{_s2}")}>";
		}

		public override string GenerateCpp (int _indent) {
			return @$"std::function<{ReturnType.GenerateCpp (_indent)} ({string.Join (", ", from p in ArgumentTypes
														let _s2 = p._type.GenerateCpp (_indent)
														select p._ext == ArgumentTypeExt.Mut ? $"{_s2}&" : $"const {_s2}&")}>";
		}
	}
}

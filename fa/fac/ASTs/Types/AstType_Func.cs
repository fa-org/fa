using Antlr4.Runtime;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	class AstType_Func: IAstType {
		public IAstType ReturnType { get; set; }
		public List<IAstType> ArgumentTypes { get; set; }



		public static AstType_Func FromType (string _type_str, IToken _token) {
			bool _last_return = false;
			if (_type_str.StartsWith ("Func<")) {
				_last_return = true;
				_type_str = _type_str[5..^1];
			} else if (_type_str.StartsWith ("Action<")) {
				_type_str = _type_str[7..^1];
			} else {
				return null;
			}
			var _functype = new AstType_Func { Token = _token, TypeStr = _type_str };
			var _sb = new StringBuilder ();
			int _level = 0;
			foreach (char _ch in _type_str) {
				if (_ch == ',' && _level == 0) {
					_functype.ArgumentTypes.Add (FromTypeStr (_sb.ToString (), _token));
					_sb.Clear ();
				} else {
					if (_ch == '{' || _ch == '(' || _ch == '<') {
						_level++;
					} else if (_ch == '}' || _ch == ')' || _ch == '>') {
						_level--;
					}
					_sb.Append (_ch);
				}
			}
			if (_sb.Length > 0)
				_functype.ArgumentTypes.Add (FromTypeStr (_sb.ToString (), _token));
			if (_last_return) {
				_functype.ReturnType = _functype.ArgumentTypes[^1];
				_functype.ArgumentTypes.RemoveAt (_functype.ArgumentTypes.Count - 1);
			} else {
				_functype.ReturnType = FromTypeStr ("void", null);
			}
			return _functype;
		}

		public override (string, string) GenerateCSharp (int _indent) => ("", TypeStr);
	}
}

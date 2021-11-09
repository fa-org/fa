using Antlr4.Runtime;
using fac.ASTs.Exprs;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.AntlrTools {
	class TypeFuncs {
		public static string GetCompatibleType (params string[] _types) {
			// 确保如果无法计算则抛异常
			_types = (from p in _types where p != "" select p).Distinct ().ToArray ();
			if (_types.Length == 0) {
				throw new Exception ("无法计算类型");
			} else if (_types.Length == 1) {
				return _types[0];
			} else {
				throw new Exception ("无法计算类型");
			}
		}

		public static bool AllowTypeCast (string _src, string _dest) {
			if (_src == "" || _dest == "" || _src == _dest)
				return true;
			return false;
		}

		public static (string _ret_type, List<string> _arg_type) ParseFuncType (IToken _token, string _str_type) {
			if (_str_type[..5] != "Func<" && _str_type[..7] != "Action<")
				throw new CodeException (_token, $"类型 {_str_type} 无法按照函数方式解析调用");
			bool _is_func = _str_type[..5] == "Func<";
			_str_type = _str_type[(_is_func ? 5 : 7)..^1];
			var _items = new List<string>();
			var _sb = new StringBuilder ();
			int _level = 0;
			foreach (char _ch  in _str_type) {
				if (_ch == ',' && _level == 0) {
					_items.Add (_sb.ToString ());
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
			if (_is_func) {
				return (_sb.ToString (), _items);
			} else {
				_items.Add (_sb.ToString ());
				return ("void", _items);
			}
		}
	}
}

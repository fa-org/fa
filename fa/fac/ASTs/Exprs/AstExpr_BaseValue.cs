using Antlr4.Runtime;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	class AstExpr_BaseValue: IAstExpr {
		public string DataType { get; set; }
		public string Value { get; set; }



		public static AstExpr_BaseValue FromCodeString (IToken _token, string _str) {
			if (_str[0] == '"') {
				var _sb = new StringBuilder ();
				bool _trans = false;
				foreach (char _ch in _str[1..^1]) {
					if (_trans) {
						if (!sTransChar.ContainsKey (_ch))
							throw new CodeException (_token, $"未识别的转义字符 \\{_ch}");
						_sb.Append (sTransChar[_ch]);
						_trans = false;
					} else if (_ch == '\\') {
						_trans = true;
					} else {
						_sb.Append (_ch);
					}
				}
				_str = _sb.ToString ();
			} else {
				throw new UnimplException (_token);
			}
			return new AstExpr_BaseValue { Token = _token, DataType = "string", Value = _str };
		}

		public override IAstExpr TraversalCalcType (string _expect_type) {
			ExpectType = DataType;
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) { }

		public override string GuessType () => DataType;

		public override (string, string) GenerateCSharp (int _indent) {
			if (DataType == "string") {
				var _sb = new StringBuilder ();
				foreach (var _ch in Value) {
					if (sTransReverse.ContainsKey (_ch)) {
						_sb.Append (sTransReverse[_ch]);
					} else {
						_sb.Append (_ch);
					}
				}
				return ("", $"\"{_sb}\"");
			} else {
				return ("", Value);
			}
		}

		public override bool AllowAssign () => false;

		private static Dictionary<char, char> sTransChar = new Dictionary<char, char> {
			['r'] = '\r', ['n'] = '\n', ['t'] = '\t', ['\''] = '\'', ['\\'] = '\\', ['\"'] = '\"',
		};
		private static Dictionary<char, string> sTransReverse = new Dictionary<char, string> {
			['\r'] = "\\r", ['\n'] = "\\n", ['\t'] = "\\t", ['\''] = "\\'", ['\\'] = "\\\\", ['\"'] = "\\\"",
		};
	}
}

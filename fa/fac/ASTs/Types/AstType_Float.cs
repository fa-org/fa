using Antlr4.Runtime;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	public class AstType_Float: IAstType {
		public int BitWidth { get; set; } = 32;



		public override string ToString () => $"float{BitWidth}";
		public static AstType_Float FromType (string _type_str, IToken _token) {
			if (!sTypeNames.Contains (_type_str))
				return null;
			var _floattype = new AstType_Float { Token = _token };
			_floattype.BitWidth = int.Parse (_type_str.Replace ("float", ""));
			return _floattype;
		}

		public override string GenerateCSharp (int _indent) => BitWidth == 32 ? "float" : (BitWidth == 64 ? "double" : throw new UnimplException (Token));

		private static HashSet<string> sTypeNames = new HashSet<string> { "float32", "float64" };
	}
}

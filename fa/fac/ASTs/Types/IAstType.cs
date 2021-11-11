using Antlr4.Runtime;
using fac.ASTs.Exprs;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	abstract class IAstType: IAstExpr {
		public string TypeStr { init; get; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) { }

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			ExpectType = null;
			return this;
		}

		public override string GuessType () => TypeStr;

		public override bool AllowAssign () => false;

		public static IAstType FromTypeStr (string _type_str, IToken _token) {
			if (_type_str.EndsWith ("[]"))
				return new AstType_Array { Token = _token, TypeStr = _type_str, ItemType = FromTypeStr (_type_str[..^2], _token) };
			//
			var _classes = Info.GetClassFromName (_type_str);
			if (_classes.Count == 1) {
				return new AstType_Class { Token = _token, TypeStr = _type_str, Class = _classes[0] };
			} else if (_classes.Count > 1) {
				throw new CodeException (_token, $"不明确的符号 {_type_str}。可能为{string.Join ('、', from p in _classes select p.FullName)}");
			}
			//
			var _floattype = AstType_Float.FromType (_type_str, _token);
			if (_floattype != null)
				return _floattype;
			//
			//
			var _inttype = AstType_Integer.FromType (_type_str, _token);
			if (_inttype != null)
				return _inttype;
			//
			if (_type_str == "string")
				return new AstType_String { Token = _token, TypeStr = _type_str };
			//
			if (_type_str == "void")
				return new AstType_Void { Token = _token, TypeStr = _type_str };
			//
			throw new CodeException (_token, $"无法识别的类型 {_type_str}");
		}
	}
}

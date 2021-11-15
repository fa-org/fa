using Antlr4.Runtime;
using fac.ASTs.Exprs;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.AntlrTools {
	class TypeFuncs {
		public static IAstType GetCompatibleType (bool _allow_optional, params IAstType[] _types) {
			// 确保如果无法计算则抛异常
			if (_types.Length == 0) {
				throw new Exception ("无法计算类型");
			} else if (_allow_optional) {
				for (int i = 1; i < _types.Length; ++i) {
					if (!_types[0].IsSame (_types[i]))
						throw new Exception ("无法计算类型");
				}
				return _types[0];
			} else {
				if (_types[0] is AstType_OptionalWrap _owrap)
					_types[0] = _owrap;
				for (int i = 1; i < _types.Length; ++i) {
					if (_types[i] is AstType_OptionalWrap _owrap1)
						_types[i] = _owrap1;
					if (!_types[0].IsSame (_types[i]))
						throw new Exception ("无法计算类型");
				}
				return _types[0];
			}
		}

		public static bool AllowTypeCast (IAstType _src, IAstType _dest) {
			if (_src == null || _dest == null || _src.IsSame (_dest)) {
				return true;
			} else {
				if (_dest is AstType_OptionalWrap _op1)
					_src.IsSame (_op1.ItemType);
				return false;
			}
		}
	}
}

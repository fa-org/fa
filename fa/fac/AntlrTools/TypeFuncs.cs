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
		public static IAstType GetCompatibleType (params IAstType[] _types) {
			// 确保如果无法计算则抛异常
			_types = (from p in _types where p != null select p).Distinct ().ToArray ();
			if (_types.Length == 0) {
				throw new Exception ("无法计算类型");
			} else if (_types.Length == 1) {
				return _types[0];
			} else {
				throw new Exception ("无法计算类型");
			}
		}

		public static bool AllowTypeCast (IAstType _src, IAstType _dest) {
			if (_src == null || _dest == null /*|| _src.TypeStr == _dest.TypeStr*/) {
				return true;
			} else {
				string _src_str = _src.GenerateCSharp (0).Item2, _dest_str = _dest.GenerateCSharp (0).Item2;
				if (_src_str == _dest_str)
					return true;
				if (_dest is AstType_OptionalWrap _op1)
					_dest = _op1.ItemType;
				_dest_str = _dest.GenerateCSharp (0).Item2;
				return (_src_str == _dest_str);
			}
		}
	}
}

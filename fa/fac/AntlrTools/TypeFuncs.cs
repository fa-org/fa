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

		public static bool AllowTypeCast (IAstType _src, IAstType _dest) {
			if (_src == null || _dest == null || _src.TypeStr == _dest.TypeStr)
				return true;
			return false;
		}
	}
}

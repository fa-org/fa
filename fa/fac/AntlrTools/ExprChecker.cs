using Antlr4.Runtime;
using fac.ASTs.Exprs.Names;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.AntlrTools {
	class ExprChecker {
		private IAstExprName m_cache_err_var = null;
		private List<(string _cond, string _errmsg)> _checks = new List<(string _cond, string _errmsg)> ();

		public ExprChecker (IAstExprName _cache_err_var) => m_cache_err_var = _cache_err_var;

		public void CheckFunc (string _cond, string _errmsg) => _checks.Add ((_cond, _errmsg));

		public string GenerateCSharp (int _indent, IToken _token) {
			if (_checks.Count == 0)
				return "";
			var _sb = new StringBuilder ();
			if (Info.CurrentFunc.ReturnType is AstType_OptionalWrap) {
				for (int i = 0; i < _checks.Count; ++i) {
					_sb.AppendLine ($"{_indent.Indent ()}{(i == 0 ? "" : $"}} else ")}if ({_checks[i]._cond}) {{");
					_sb.AppendLine ($"{(_indent + 1).Indent ()}return {Info.CurrentFunc.ReturnType.GenerateCSharp (0, null).Item2}.FromError ({_checks[i]._errmsg});");
				}
				_sb.AppendLine ($"{_indent.Indent ()}}}");
				return _sb.ToString ();
			} else if (m_cache_err_var != null) {
				for (int i = 0; i < _checks.Count; ++i) {
					_sb.AppendLine ($"{_indent.Indent ()}{(i == 0 ? "" : $"}} else ")}if ({_checks[i]._cond}) {{");
					var (_a, _b) = m_cache_err_var.GenerateCSharp (0, null);
					var (_c, _d) = m_cache_err_var.ExpectType.GenerateCSharp (0, null);
					_sb.AppendLine ($"{_a}{_c}{(_indent + 1).Indent ()}{_b} = {_d}.FromError ({_checks[i]._errmsg});");
				}
				TODO: 加else;
				_sb.AppendLine ($"{_indent.Indent ()}}}");
				return _sb.ToString ();
			} else {
				throw new CodeException (_token, "当结果可能为空时，空值必须用可空变量接收，否则函数返回值需改为可空类型");
			}
		}
	}
}

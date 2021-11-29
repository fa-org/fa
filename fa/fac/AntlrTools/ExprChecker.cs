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
	public class ExprChecker {
		private IAstExprName m_cache_err_var = null;
		private List<(string _cond, string _errmsg)> _checks = new List<(string _cond, string _errmsg)> ();

		public ExprChecker (IAstExprName _cache_err_var) => m_cache_err_var = _cache_err_var;

		public void CheckFunc (string _cond, string _errmsg) => _checks.Add ((_cond, _errmsg));

		public (string, string) GenerateCSharpPrefixSuffix (int _indent, IToken _token) {
			if (_checks.Count == 0)
				return ("", "");
			StringBuilder _sb = new StringBuilder (), _ssb = new StringBuilder ();
			for (int i = 0; i < _checks.Count; ++i) {
				if (m_cache_err_var != null) {
					_sb.AppendLine ($"{_indent.Indent ()}{(i == 0 ? "" : $"}} else ")}if ({_checks[i]._cond}) {{");
					var (_a, _b, _c) = m_cache_err_var.GenerateCSharp (0, null);
					var (_d, _e, _f) = m_cache_err_var.ExpectType.GenerateCSharp (0, null);
					_sb.Append ($"{_a}{_d}").AppendLine ($"{(_indent + 1).Indent ()}{_b} = {_e}.FromError ({_checks[i]._errmsg});").Append ($"{_c}{_f}");
				} else if (Info.CurrentFunc.ReturnType is AstType_OptionalWrap) {
					_sb.AppendLine ($"{_indent.Indent ()}{(i == 0 ? "" : $"}} else ")}if ({_checks[i]._cond}) {{");
					_sb.AppendLine ($"{(_indent + 1).Indent ()}return {Info.CurrentFunc.ReturnType.GenerateCSharp (0, null).Item2}.FromError ({_checks[i]._errmsg});");
				} else {
					throw new CodeException (_token, "当结果可能为空时，空值必须用可空变量接收，否则函数返回值需改为可空类型");
				}
			}
			_sb.AppendLine ($"{_indent.Indent ()}}} else {{");
			_ssb.AppendLine ($"{_indent.Indent ()}}}");
			return (_sb.ToString (), _ssb.ToString ());
		}
	}
}

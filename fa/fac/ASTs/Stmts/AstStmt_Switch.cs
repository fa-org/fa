using fac.AntlrTools;
using fac.ASTs.Exprs;
using fac.ASTs.Exprs.Names;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Stmts {
	class AstStmt_Switch: IAstStmt {
		public IAstExpr Condition { get; set; }
		public List<IAstExpr> CaseValues { get; set; }
		public List<IAstStmt> CaseCodes { get; set; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			Condition = _cb (Condition, _deep, _group);
			CaseValues.Traversal (_deep, _group, _cb);
			for (int i = 0; i < CaseCodes.Count; ++i)
				CaseCodes[i].Traversal (_deep + 1, i, _cb);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (_expect_type != null)
				throw new Exception ("语句类型不可指定期望类型");
			Condition = Condition.TraversalCalcType (null);
			CaseValues.TraversalCalcType ();
			CaseCodes.TraversalCalcType ();
			return this;
		}

		public override (string, string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb) {
			var _sb = new StringBuilder ();
			var _ec = new ExprChecker (null);
			var _tmp_var_name = Common.GetTempId ();
			var (_a, _b, _c) = Condition.GenerateCSharp (_indent, _check_cb);
			_sb.Append (_a).AppendLine ($"{_indent.Indent ()}{Condition.ExpectType.GenerateCSharp_Type ()} {_tmp_var_name} = {_b};").Append (_c);
			var _cases = (from p in CaseValues select p.GenerateCSharp (_indent, _check_cb)).ToList ();
			if (_cases.Count == 1 && CaseValues[0] is AstExprName_Ignore) {
				(_a, _b, _c) = CaseCodes[0].GenerateCSharp (_indent + 1, _check_cb);
				_sb.AppendLine ($"{_indent.Indent ()}{{");
				_sb.Append (_a).Append (_b).Append (_c);
				_sb.AppendLine ($"{_indent.Indent ()}}}");
			} else {
				for (int i = 0; i < _cases.Count; ++i)
					_sb.Append (_cases[i].Item1);
				for (int i = 0; i < _cases.Count; ++i) {
					_sb.Append (i > 0 ? " else " : _indent.Indent ());
					if (CaseValues[i] is AstExprName_Ignore) {
						if (i != _cases.Count - 1)
							throw new CodeException (CaseValues[i].Token, "只能在语句最后一项匹配所有条件");
						_sb.AppendLine ($"{{");
					} else {
						_sb.AppendLine ($"if ({_tmp_var_name} == {_cases[i].Item2}) {{");
					}
					(_a, _b, _c) = CaseCodes[i].GenerateCSharp (_indent + 1, _check_cb);
					_sb.Append (_a).Append (_b).Append (_c);
					_sb.Append ($"{_indent.Indent ()}}}");
				}
				_sb.AppendLine ();
				for (int i = _cases.Count - 1; i >= 0; --i)
					_sb.Append (_cases[i].Item3);
			}
			return ("", _sb.ToString (), "");
		}
	}
}

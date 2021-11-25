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
		public List<IAstExpr> CaseConds2 { get; set; }
		public List<IAstStmt> CaseCodes { get; set; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			if (Condition != null)
				Condition = _cb (Condition, _deep, _group);
			if (CaseValues != null)
				CaseValues.Traversal (_deep, _group, _cb);
			CaseConds2.Traversal (_deep, _group, _cb);
			for (int i = 0; i < CaseCodes.Count; ++i)
				CaseCodes[i] = _cb (CaseCodes[i], _deep + 1, i) as IAstStmt;
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (_expect_type != null)
				throw new Exception ("语句类型不可指定期望类型");
			if (Condition != null)
				Condition = Condition.TraversalCalcType (null);
			if (CaseValues != null)
				CaseValues.TraversalCalcType ();
			for (int i = 0; i < CaseConds2.Count; ++i) {
				if (CaseConds2[i] != null)
					CaseConds2[i] = CaseConds2[i].TraversalCalcType (CaseConds2[i] is AstExprName_Ignore ? null : IAstType.FromName ("bool"));
			}
			CaseCodes.TraversalCalcType ();
			return this;
		}

		public override (string, string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb) {
			var _sb = new StringBuilder ();
			if (Condition != null) {
				var _tmp_var_name = Common.GetTempId ();
				var (_a, _b, _c) = Condition.GenerateCSharp (_indent, _check_cb);
				if (_a != "" || _c != "")
					throw new CodeException (Condition.Token, "条件不允许带隐藏逻辑的表达式");
				_sb.AppendLine ($"{_indent.Indent ()}{Condition.ExpectType.GenerateCSharp_Type ()} {_tmp_var_name} = {_b};");
				var _cases = (from p in CaseValues select p.GenerateCSharp (_indent, _check_cb)).ToList ();
				if (_cases.Count == 1 && CaseValues[0] is AstExprName_Ignore && CaseConds2[0] == null) {
					_sb.AppendLine ($"{_indent.Indent ()}{{");
					(_a, _b, _c) = CaseCodes[0].GenerateCSharp (_indent + 1, null);
					_sb.Append (_a).Append (_b).Append (_c);
					_sb.AppendLine ($"{_indent.Indent ()}}}");
				} else {
					for (int i = 0; i < _cases.Count; ++i) {
						if (_cases[i].Item1 != "" || _cases[i].Item3 != "")
							throw new CodeException (CaseConds2[i].Token, "条件不允许带隐藏逻辑的表达式");
						//
						_sb.Append (i > 0 ? " else " : _indent.Indent ());
						if (CaseValues[i] is AstExprName_Ignore && CaseConds2[i] == null) {
							if (i != _cases.Count - 1)
								throw new CodeException (CaseValues[i].Token, "只能在语句最后一项匹配所有条件");
							_sb.AppendLine ($"{{");
						} else {
							string _left = CaseValues[i] is AstExprName_Ignore ? "" : $"{_tmp_var_name} == {_cases[i].Item2}", _right = "";
							(_a, _right, _c) = CaseConds2[i] == null ? ("", "", "") : CaseConds2[i].GenerateCSharp (_indent, _check_cb);
							if (_a != "" || _c != "")
								throw new CodeException (CaseConds2[i].Token, "条件不允许带隐藏逻辑的表达式");
							string _mid = _left != "" && _right != "" ? " && " : "";
							_sb.AppendLine ($"if ({_left}{_mid}{_right}) {{");
						}
						(_a, _b, _c) = CaseCodes[i].GenerateCSharp (_indent + 1, _check_cb);
						_sb.Append (_a).Append (_b).Append (_c);
						_sb.Append ($"{_indent.Indent ()}}}");
					}
					_sb.AppendLine ();
				}
			} else {
				string _a, _b, _c;
				if (CaseConds2[0] is AstExprName_Ignore) {
					(_a, _b, _c) = CaseCodes[0].GenerateCSharp (_indent + 1, _check_cb);
					_sb.AppendLine ($"{_indent.Indent ()}{{");
					_sb.Append (_a).Append (_b).Append (_c);
					_sb.AppendLine ($"{_indent.Indent ()}}}");
				} else {
					for (int i = 0; i < CaseConds2.Count; ++i) {
						_sb.Append (i > 0 ? " else " : _indent.Indent ());
						if (CaseConds2[i] is AstExprName_Ignore) {
							if (i != CaseConds2.Count - 1)
								throw new CodeException (CaseConds2[i].Token, "只能在语句最后一项匹配所有条件");
							_sb.AppendLine ($"{{");
						} else {
							(_a, _b, _c) = CaseConds2[i] == null ? ("", "", "") : CaseConds2[i].GenerateCSharp (_indent, _check_cb);
							if (_a != "" || _c != "")
								throw new CodeException (CaseConds2[i].Token, "条件不允许带隐藏逻辑的表达式");
							_sb.AppendLine ($"if ({_b}) {{");
						}
						(_a, _b, _c) = CaseCodes[i].GenerateCSharp (_indent + 1, _check_cb);
						_sb.Append (_a).Append (_b).Append (_c);
						_sb.Append ($"{_indent.Indent ()}}}");
					}
					_sb.AppendLine ();
				}
			}
			return ("", _sb.ToString (), "");
		}
	}
}

using fac.AntlrTools;
using fac.ASTs.Exprs.Names;
using fac.ASTs.Stmts;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	public class AstExpr_Switch: IAstExpr {
		public IAstExpr Condition { get; set; }
		public List<IAstExpr> CaseValues { get; set; }
		public List<IAstExpr> CaseWhen { get; set; }
		public List<(List<IAstStmt> _stmts, IAstExpr _expr)> CaseCodes { get; set; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			if (Condition != null)
				Condition = _cb (Condition, _deep, _group);
			if (CaseValues != null)
				CaseValues.Traversal (_deep, _group, _cb);
			CaseWhen.Traversal (_deep, _group, _cb);
			for (int i = 0; i < CaseCodes.Count; ++i) {
				for (int j = 0; j < CaseCodes[i]._stmts.Count; ++j)
					CaseCodes[i]._stmts[j] = _cb (CaseCodes[i]._stmts[j],_deep + 1, i) as IAstStmt;
				CaseCodes[i] = (_stmts: CaseCodes[i]._stmts, _expr: _cb (CaseCodes[i]._expr, _deep + 1, i));
			}
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (Condition != null)
				Condition = Condition.TraversalCalcType (null);
			if (CaseValues != null)
				CaseValues.TraversalCalcType ();
			CaseWhen.TraversalCalcType (IAstType.FromName ("bool"));
			for (int i = 0; i < CaseCodes.Count; ++i) {
				for (int j = 0; j < CaseCodes[i]._stmts.Count; ++j)
					CaseCodes[i]._stmts[j] = CaseCodes[i]._stmts[j].TraversalCalcType (null) as IAstStmt;
				CaseCodes[i] = (CaseCodes[i]._stmts, CaseCodes[i]._expr.TraversalCalcType (_expect_type));
			}
			ExpectType = _expect_type;
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () {
			return TypeFuncs.GetCompatibleType (true, (from p in CaseCodes select p._expr.GuessType ()).ToArray ());
		}

		public override (string, string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb) {
			var _sb = new StringBuilder ();
			string _tmp_var_name2 = Common.GetTempId ();
			if (Condition != null) {
				string _tmp_var_name = Common.GetTempId ();
				var (_a, _b, _c) = Condition.GenerateCSharp (_indent, _check_cb);
				if (_a != "" || _c != "")
					throw new CodeException (Condition.Token, "条件不允许带隐藏逻辑的表达式");
				_sb.AppendLine ($"{_indent.Indent ()}{Condition.ExpectType.GenerateCSharp_Type ()} {_tmp_var_name} = {_b};");
				_sb.AppendLine ($"{_indent.Indent ()}{ExpectType.GenerateCSharp_Type ()} {_tmp_var_name2};");
				var _cases = (from p in CaseValues select p.GenerateCSharp (_indent, _check_cb)).ToList ();
				if (_cases.Count == 1 && CaseValues[0] is AstExprName_Ignore && CaseWhen[0] == null) {
					for (int j = 0; j < CaseCodes[0]._stmts.Count; ++j) {
						(_a, _b, _c) = CaseCodes[0]._stmts[j].GenerateCSharp (_indent + 1, _check_cb);
						_sb.AppendLine ($"{_indent.Indent ()}{{");
						_sb.Append (_a).Append (_b).Append (_c);
						_sb.AppendLine ($"{_indent.Indent ()}}}");
					}
					(_a, _b, _c) = CaseCodes[0]._expr.GenerateCSharp (_indent + 1, _check_cb);
					_sb.AppendLine ($"{_indent.Indent ()}{{");
					_sb.Append (_a).AppendLine ($"{(_indent + 1).Indent ()}{_tmp_var_name2} = {_b};").Append (_c);
					_sb.AppendLine ($"{_indent.Indent ()}}}");
				} else {
					for (int i = 0; i < _cases.Count; ++i) {
						if (_cases[i].Item1 != "" || _cases[i].Item3 != "")
							throw new CodeException (CaseWhen[i].Token, "条件不允许带隐藏逻辑的表达式");
						//
						_sb.Append (i > 0 ? " else " : _indent.Indent ());
						if (CaseValues[i] is AstExprName_Ignore && CaseWhen[i] == null) {
							if (i != _cases.Count - 1)
								throw new CodeException (CaseValues[i].Token, "只能在语句最后一项匹配所有条件");
							_sb.AppendLine ($"{{");
						} else {
							string _left = CaseValues[i] is AstExprName_Ignore ? "" : $"{_tmp_var_name} == {_cases[i].Item2}", _right = "";
							(_a, _right, _c) = CaseWhen[i] == null ? ("", "", "") : CaseWhen[i].GenerateCSharp (_indent, _check_cb);
							if (_a != "" || _c != "")
								throw new CodeException (CaseWhen[i].Token, "条件不允许带隐藏逻辑的表达式");
							string _mid = _left != "" && _right != "" ? " && " : "";
							_sb.AppendLine ($"if ({_left}{_mid}{_right}) {{");
						}
						for (int j = 0; j < CaseCodes[i]._stmts.Count; ++j) {
							(_a, _b, _c) = CaseCodes[i]._stmts[j].GenerateCSharp (_indent + 1, _check_cb);
							_sb.Append (_a).Append (_b).Append (_c);
						}
						(_a, _b, _c) = CaseCodes[i]._expr.GenerateCSharp (_indent + 1, _check_cb);
						_sb.Append (_a).AppendLine ($"{(_indent + 1).Indent ()}{_tmp_var_name2} = {_b};").Append (_c);
						_sb.Append ($"{_indent.Indent ()}}}");
					}
					_sb.AppendLine ();
				}
			} else {
				string _a, _b, _c;
				_sb.AppendLine ($"{_indent.Indent ()}{ExpectType.GenerateCSharp_Type ()} {_tmp_var_name2};");
				if (CaseWhen[0] == null) {
					for (int j = 0; j < CaseCodes[0]._stmts.Count; ++j) {
						(_a, _b, _c) = CaseCodes[0]._stmts[j].GenerateCSharp (_indent + 1, _check_cb);
						_sb.AppendLine ($"{_indent.Indent ()}{{");
						_sb.Append (_a).Append (_b).Append (_c);
						_sb.AppendLine ($"{_indent.Indent ()}}}");
					}
					(_a, _b, _c) = CaseCodes[0]._expr.GenerateCSharp (_indent + 1, _check_cb);
					_sb.AppendLine ($"{_indent.Indent ()}{{");
					_sb.Append (_a).AppendLine ($"{(_indent + 1).Indent ()}{_tmp_var_name2} = {_b};").Append (_c);
					_sb.AppendLine ($"{_indent.Indent ()}}}");
				} else {
					for (int i = 0; i < CaseWhen.Count; ++i) {
						_sb.Append (i > 0 ? " else " : _indent.Indent ());
						if (CaseWhen[i] == null) {
							if (i != CaseWhen.Count - 1)
								throw new CodeException (CaseWhen[i].Token, "只能在语句最后一项匹配所有条件");
							_sb.AppendLine ($"{{");
						} else {
							(_a, _b, _c) = CaseWhen[i] == null ? ("", "", "") : CaseWhen[i].GenerateCSharp (_indent, _check_cb);
							if (_a != "" || _c != "")
								throw new CodeException (CaseWhen[i].Token, "条件不允许带隐藏逻辑的表达式");
							_sb.AppendLine ($"if ({_b}) {{");
						}
						for (int j = 0; j < CaseCodes[i]._stmts.Count; ++j) {
							(_a, _b, _c) = CaseCodes[i]._stmts[j].GenerateCSharp (_indent + 1, _check_cb);
							_sb.Append (_a).Append (_b).Append (_c);
						}
						(_a, _b, _c) = CaseCodes[i]._expr.GenerateCSharp (_indent + 1, _check_cb);
						_sb.Append (_a).AppendLine ($"{(_indent + 1).Indent ()}{_tmp_var_name2} = {_b};").Append (_c);
						_sb.Append ($"{_indent.Indent ()}}}");
					}
					_sb.AppendLine ();
				}
			}
			return (_sb.ToString (), _tmp_var_name2, "");
		}

		public override bool AllowAssign () => false;
	}
}

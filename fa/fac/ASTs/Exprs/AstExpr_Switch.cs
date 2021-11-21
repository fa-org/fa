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
	class AstExpr_Switch: IAstExpr {
		public IAstExpr Condition { get; set; }
		public List<IAstExpr> CaseValues { get; set; }
		public List<(List<IAstStmt> _stmts, IAstExpr _expr)> CaseCodes { get; set; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			Condition = _cb (Condition, _deep, _group);
			CaseValues.Traversal (_deep, _group, _cb);
			for (int i = 0; i < CaseCodes.Count; ++i) {
				for (int j = 0; j < CaseCodes[i]._stmts.Count; ++j)
					CaseCodes[i]._stmts[j].Traversal (_deep + 1, i, _cb);
				CaseCodes[i]._expr.Traversal (_deep + 1, i, _cb);
			}
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			Condition = Condition.TraversalCalcType (null);
			CaseValues.TraversalCalcType ();
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
			var _ec = new ExprChecker (null);
			string _tmp_var_name = Common.GetTempId (), _tmp_var_name2 = Common.GetTempId ();
			var (_a, _b, _c) = Condition.GenerateCSharp (_indent, _check_cb);
			_sb.Append (_a).AppendLine ($"{_indent.Indent ()}{Condition.ExpectType.GenerateCSharp_Type ()} {_tmp_var_name} = {_b};").Append (_c);
			_sb.AppendLine ($"{_indent.Indent ()}{ExpectType.GenerateCSharp_Type ()} {_tmp_var_name2};");
			var _cases = (from p in CaseValues select p.GenerateCSharp (_indent, _check_cb)).ToList ();
			if (_cases.Count == 1 && CaseValues[0] is AstExprName_Ignore) {
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
					for (int j = 0; j < CaseCodes[i]._stmts.Count; ++j) {
						(_a, _b, _c) = CaseCodes[i]._stmts[j].GenerateCSharp (_indent + 1, _check_cb);
						_sb.Append (_a).Append (_b).Append (_c);
					}
					(_a, _b, _c) = CaseCodes[i]._expr.GenerateCSharp (_indent + 1, _check_cb);
					_sb.Append (_a).AppendLine ($"{(_indent + 1).Indent ()}{_tmp_var_name2} = {_b};").Append (_c);
					_sb.Append ($"{_indent.Indent ()}}}");
				}
				_sb.AppendLine ();
				for (int i = _cases.Count - 1; i >= 0; --i)
					_sb.Append (_cases[i].Item3);
			}
			return (_sb.ToString (), _tmp_var_name2, "");
		}

		public override bool AllowAssign () => false;
	}
}

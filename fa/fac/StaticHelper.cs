using fac.AntlrTools;
using fac.ASTs.Exprs;
using fac.ASTs.Exprs.Names;
using fac.ASTs.Stmts;
using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace fac {
	public static class StaticHelper {
		public static string GetDisplayName (this Enum _enum) {
			var _def_name = $"{_enum}";
			var _info = _enum.GetType ().GetField (_def_name);
			var _attrs = _info.GetCustomAttributes (typeof (DisplayAttribute), false) as DisplayAttribute [];
			return _attrs.Length > 0 ? _attrs [0].Name : _def_name;
		}

		public static string Indent (this int _indent) => new string (' ', _indent * 4);

		public static void TraversalWraps (this List<IAstExpr> _exprs, (int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) {
			for (int i = 0; i < (_exprs?.Count ?? 0); ++i) {
				if (_exprs[i] != null)
					_exprs[i] = _exprs[i].TraversalWrap (_trav);
			}
		}

		public static void TraversalWraps (this List<IAstStmt> _stmts, (int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) {
			for (int i = 0; i < (_stmts?.Count ?? 0); ++i) {
				if (_stmts[i] != null)
					_stmts[i] = _stmts[i].TraversalWrap (_trav) as IAstStmt;
			}
		}

		public static void TraversalCalcType (this List<IAstExpr> _exprs, IAstType _expect_type = null) {
			for (int i = 0; i < (_exprs?.Count ?? 0); ++i) {
				if (_exprs[i] != null && _exprs[i] is not AstExprName_Ignore)
					_exprs[i] = _exprs[i].TraversalCalcType (_expect_type);
			}
		}

		public static void TraversalCalcType (this List<IAstStmt> _stmts) {
			for (int i = 0; i < (_stmts?.Count ?? 0); ++i) {
				if (_stmts[i] != null)
					_stmts[i] = _stmts[i].TraversalCalcType (null) as IAstStmt;
			}
		}

		public static void AppendStmts (this StringBuilder _sb, List<IAstStmt> _stmts, int _indent) {
			if (_stmts == null)
				return;
			foreach (var _stmt in _stmts) {
				_sb.Append (_stmt.GenerateCSharp (_indent));
			}
		}

		public static void AppendExprs (this StringBuilder _sb, List<IAstExpr> _exprs, int _indent) {
			if (_exprs == null)
				return;
			foreach (var _expr in _exprs) {
				_sb.Append ($"{_indent.Indent ()}{_expr.GenerateCSharp (_indent)};\r\n");
			}
		}

		public static List<IAstStmt> CombileStmts (this IEnumerable<List<IAstStmt>> _stmtss) {
			var _stmts = new List<IAstStmt> ();
			foreach (var _stmtss_item in _stmtss)
				_stmts.AddRange (_stmtss_item);
			return _stmts;
		}

		public static IAstStmt ToSingleStmt (this List<IAstStmt> _stmts) {
			if ((_stmts?.Count ?? 0) == 0) {
				return AstStmt_ExprWrap.MakeFromExpr (null);
			} else if (_stmts.Count == 1) {
				return _stmts[0];
			} else {
				return new AstStmt_HuaQuotWrap { Token = _stmts[0].Token, Stmts = _stmts };
			}
		}

		public static List<IAstStmt> ExpandStmts (this List<IAstStmt> _stmts, (IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			var _stmts1 = new List<IAstStmt> ();
			foreach (var _stmt in _stmts)
				_stmts1.AddRange (_stmt.ExpandStmt (_cache_err));
			return _stmts1;
		}

		public static void PreprocessCaseCond (this List<IAstExpr> _exprs) {
			for (int i = 0; i < (_exprs?.Count ?? 0); ++i) {
				if (_exprs[i] is AstExpr_OpN _opn_expr1) {
					string _enum_name = _opn_expr1.Value switch {
						AstExpr_Op1 _op1_expr => _op1_expr.GetIdRaw (),
						AstExpr_BaseId _bi_expr => _bi_expr.Id,
						_ => throw new NotSupportedException (),
					};
					if (AstExprName_ClassEnum.FindFromNameUncheckAttach (_exprs[i].Token, _enum_name) != null) {
						_exprs[i] = AstExpr_Is.FromContext (_exprs[i].Token, null, _enum_name, (_opn_expr1.Arguments[0] as AstExpr_BaseId).Id);
					}
				}
			}
		}
	}
}

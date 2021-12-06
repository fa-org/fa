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

		public static void Traversal (this List<IAstExpr> _exprs, int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			for (int i = 0; i < (_exprs?.Count ?? 0); ++i) {
				if (_exprs[i] != null) {
					if (Info.TraversalFirst)
						_exprs[i] = _cb (_exprs[i], _deep, _group);
					_exprs[i].TraversalWrap (_deep, _group, (_expr1, _deep1, _group1) => _cb (_expr1, _deep1, _group1));
					if (Info.TraversalLast)
						_exprs[i] = _cb (_exprs[i], _deep, _group);
				}
			}
		}

		public static void Traversal (this List<IAstStmt> _stmts, int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			for (int i = 0; i < (_stmts?.Count ?? 0); ++i) {
				if (_stmts[i] == null)
					continue;
				if (Info.TraversalFirst)
					_stmts[i] = _cb (_stmts[i], _deep, _group) as IAstStmt;
				_stmts[i].TraversalWrap (_deep, _group, (_expr1, _deep1, _group1) => _cb (_expr1, _deep1, _group1));
				if (Info.TraversalLast)
					_stmts[i] = _cb (_stmts[i], _deep, _group) as IAstStmt;
			}
		}

		public static void TraversalCalcType (this List<IAstExpr> _exprs, IAstType _expect_type = null) {
			for (int i = 0; i < (_exprs?.Count ?? 0); ++i) {
				if (_exprs[i] != null)
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

		public static List<IAstStmt> CombileStmts (this IEnumerable<List<IAstStmt>> _stmtss) {
			var _stmts = new List<IAstStmt> ();
			foreach (var _stmtss_item in _stmtss)
				_stmts.AddRange (_stmtss_item);
			return _stmts;
		}

		public static IAstStmt ToSingleStmt (this List<IAstStmt> _stmts) {
			if ((_stmts?.Count ?? 0) == 0) {
				return new AstStmt_ExprWrap { Token = null, Expr = null };
			} else if (_stmts.Count == 1) {
				return _stmts[0];
			} else {
				return new AstStmt_HuaQuotWrap { Token = _stmts[0].Token, Stmts = _stmts };
			}
		}

		public static List<IAstStmt> ExpandStmts (this List<IAstStmt> _stmts, (IAstExprName _var, AstStmt_Label _pos) _cache_err) {
			return (from p in _stmts select p.ExpandStmt (_cache_err)).CombileStmts ();
		}
	}
}

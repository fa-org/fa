using Antlr4.Runtime;
using fac.ASTs.Exprs;
using fac.ASTs.Stmts;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.AntlrTools {
	public class TypeFuncs {
		public static IAstType GetCompatibleType (bool _allow_optional, params IAstType[] _types) {
			// 确保如果无法计算则抛异常
			if (_types.Length == 0) {
				throw new Exception ("无法计算类型");
			} else if (_allow_optional) {
				for (int i = 1; i < _types.Length; ++i) {
					if (!_types[0].IsSame (_types[i]))
						throw new Exception ("无法计算类型");
				}
				return _types[0];
			} else {
				if (_types[0] is AstType_OptionalWrap _owrap)
					_types[0] = _owrap;
				for (int i = 1; i < _types.Length; ++i) {
					if (_types[i] is AstType_OptionalWrap _owrap1)
						_types[i] = _owrap1;
					if (!_types[0].IsSame (_types[i]))
						throw new Exception ("无法计算类型");
				}
				return _types[0];
			}
		}

		// 获取函数语句代码列表
		public static List<IAstStmt> GetFuncBodyCodes (IToken _token, IAstType _return_type, FaParser.ExprContext _expr_ctx, FaParser.StmtContext[] _stmt_ctxs) {
			List<IAstStmt> _body_codes;
			if (_expr_ctx != null) {
				_body_codes = new List<IAstStmt> ();
				string _rtype_str = _return_type.ToString ();
				if (_rtype_str != "void" && _rtype_str != "void?") {
					_body_codes.Add (IAstStmt.FromExpr (_expr_ctx, true));
				} else {
					_body_codes.Add (IAstStmt.FromExpr (_expr_ctx, false));
					_body_codes.Add (IAstStmt.FromExpr (null, true));
				}
			} else {
				_body_codes = IAstStmt.FromStmts (_stmt_ctxs);
				_make_sure_return (_token, _return_type, _body_codes);
			}
			return _body_codes;
		}

		// 遍历代码，确保所有路径均return
		private static void _make_sure_return (IToken _token, IAstType _return_type, List<IAstStmt> _stmts) {
			string _ret_type = _return_type.ToString ();
			if (_stmts.Count == 0) {
				if (_ret_type != "void" && _ret_type != "void?")
					throw new CodeException (_token, $"方法需返回 {_return_type} 类型结果");
				_stmts.Add (AstStmt_Return.Make ());
			} else if (_stmts[^1] is AstStmt_If _ifstmt) {
				_make_sure_return (_token, _return_type, _ifstmt.IfTrueCodes);
				_make_sure_return (_token, _return_type, _ifstmt.IfFalseCodes);
			} else if (_stmts[^1] is not AstStmt_Return) {
				if (_ret_type != "void" && _ret_type != "void?")
					throw new CodeException (_token, $"方法需返回 {_return_type} 类型结果");
				_stmts.Add (AstStmt_Return.Make ());
			}
		}

		public static List<IAstStmt> ExpandFuncCodes (IAstType _return_type, List<IAstStmt> _codes) {
			if (_return_type is AstType_OptionalWrap) {
				var _stmts = new List<IAstStmt> ();

				var _retvar_stmt = new AstStmt_DefVariable { DataType = _return_type };
				var _pos_stmt = new AstStmt_Label { };
				var _cache_error = (_var: _retvar_stmt.GetRef (), _pos: _pos_stmt);

				_stmts.Add (_retvar_stmt);
				_stmts.AddRange (_codes.ExpandStmts (_cache_error));
				_stmts.Add (_pos_stmt);
				_stmts.Add (AstStmt_Return.MakeFromExpr (_retvar_stmt.GetRef ()));
				return _stmts;
			} else {
				return _codes.ExpandStmts (null);
			}
		}
	}
}

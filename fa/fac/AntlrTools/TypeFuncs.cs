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

		public static bool AllowTypeCast (IAstType _src, IAstType _dest) {
			if (_src == null || _dest == null || _src.IsSame (_dest)) {
				return true;
			} else {
				if (_dest is AstType_OptionalWrap _op1)
					_src.IsSame (_op1.ItemType);
				return false;
			}
		}

		public static List<IAstStmt> GetFuncBodyCodes (IToken _token, IAstType _return_type, FaParser.ExprContext _expr_ctx, FaParser.StmtContext[] _stmt_ctxs) {
			List<IAstStmt> _body_codes;
			if (_expr_ctx != null) {
				_body_codes = new List<IAstStmt> ();
				if (_return_type is not AstType_Void) {
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
				_stmts.Add (new AstStmt_Return { Token = null, Expr = _ret_type == "void" ? null : AstExprTypeCast.ForceMake (new AstExpr_BaseValue { Token = null, DataType = IAstType.FromName ("int"), Value = "0" }, IAstType.FromName ("int?")) });
			} else if (_stmts[^1] is AstStmt_Return) {
				return;
			} else if (_stmts[^1] is AstStmt_If _ifstmt) {
				_make_sure_return (_token, _return_type, _ifstmt.IfTrueCodes);
				_make_sure_return (_token, _return_type, _ifstmt.IfFalseCodes);
			} else {
				if (_ret_type != "void" && _ret_type != "void?")
					throw new CodeException (_token, $"方法需返回 {_return_type} 类型结果");
				_stmts.Add (new AstStmt_Return { Token = null, Expr = _ret_type == "void" ? null : AstExprTypeCast.ForceMake (new AstExpr_BaseValue { Token = null, DataType = IAstType.FromName ("int"), Value = "0" }, IAstType.FromName ("int?")) });
			}
		}
	}
}

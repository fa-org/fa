using Antlr4.Runtime;
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
	public class AstStmt_ExprWrap: IAstStmt {
		public IAstExpr Expr { get; set; }
		public bool IgnoreError { get; set; } = false;



		private AstStmt_ExprWrap () { }
		public static AstStmt_ExprWrap MakeAssign (IAstExpr _dest, IAstExpr _src) {
			if (!_dest.ExpectType.IsSame (_src.ExpectType)) {
				if ($"{_src.ExpectType}" != "fa.Error" && _dest.ExpectType.IsSame (_src.ExpectType.Optional)) {
					_src = _src.OptionalFromValue ();
				} else if (_dest.ExpectType.Optional.IsSame (_src.ExpectType)) {
					_src = _src.AccessValue ();
				}
			}
			return new AstStmt_ExprWrap { Token = _src.Token, Expr = new AstExpr_Op2 { Token = _src.Token, Value1 = _dest, Value2 = _src, Operator = "=", ExpectType = _dest.ExpectType } };
		}
		public static AstStmt_ExprWrap MakeOp2 (IAstExpr _val1, string _op, IAstExpr _val2, IAstType _expect_type) => new AstStmt_ExprWrap { Token = _val1.Token, Expr = AstExpr_Op2.MakeOp2 (_val1, _op, _val2, _expect_type) };
		public static AstStmt_ExprWrap MakeCondition (IAstExpr _val1, string _op, IAstExpr _val2) => new AstStmt_ExprWrap { Token = _val1.Token, Expr = AstExpr_Op2.MakeCondition (_val1, _op, _val2) };
		public static AstStmt_ExprWrap MakeFromExpr (IAstExpr _val) {
			if (_val is AstExpr_Op2 _op2expr && (_op2expr.Value1 is AstExprName_Ignore || (_op2expr.Value1 is AstExpr_BaseId _idexpr && _idexpr.Id == "_")) && _op2expr.Operator == "=") {
				return new AstStmt_ExprWrap { Token = _val.Token, Expr = _op2expr.Value2, IgnoreError = true };
			} else {
				return new AstStmt_ExprWrap { Token = _val?.Token ?? null, Expr = _val };
			}
		}
		public static AstStmt_ExprWrap MakeContinue (IToken _token) => new AstStmt_ExprWrap { Token = _token, Expr = AstExprName_BuildIn.FindFromName ("continue") };
		public static AstStmt_ExprWrap MakeBreak (IToken _token) => new AstStmt_ExprWrap { Token = _token, Expr = AstExprName_BuildIn.FindFromName ("break") };

		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) {
			if (Expr != null)
				Expr = Expr.TraversalWrap (_trav);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (_expect_type != null)
				throw new Exception ("语句类型不可指定期望类型");
			if (Expr != null) {
				if (!Expr.TraversalCalcTypeWrap (null, a => Expr = a))
					return null;

				// 异常强制处理
				if (Expr.ExpectType.IsOptional && (!IgnoreError) && (!Info.CurrentReturnType ().IsOptional))
					throw new CodeException (Token, "此处未处理异常必须处理");
			}
			return this;
		}

		public override List<IAstStmt> ExpandStmt ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			if (Expr == null)
				return new List<IAstStmt> ();
			var (_stmts, _expr) = Expr.ExpandExpr (IgnoreError ? (_var: null, _pos: null) : _cache_err);
			if (_expr.IsSimpleExpr)
				return _stmts;
			if (_expr is AstExpr_ArrayAPI_Temp _biexpr && (!_biexpr.IsChangeData ()))
				return _stmts;

			Expr = _expr;
			_stmts.Add (this);
			return _stmts;
		}

		public override string GenerateCSharp (int _indent) => $"{_indent.Indent ()}{Expr.GenerateCSharp (_indent)};\r\n";
	}
}

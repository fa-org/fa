using fac.AntlrTools;
using fac.ASTs.Exprs;
using fac.ASTs.Exprs.Names;
using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Stmts {
	public class AstStmt_Return: IAstStmt {
		public IAstType ReturnType { get; set; } = Info.CurrentFunc.ReturnType;
		public IAstExpr Expr { get; set; } = null;



		private AstStmt_Return () { }
		public static AstStmt_Return Make () => new AstStmt_Return { Token = null };
		public static AstStmt_Return MakeFromExpr (IAstExpr _val) => new AstStmt_Return { Token = _val?.Token ?? null, Expr = _val };

		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) {
			if (Expr != null)
				Expr = Expr.TraversalWrap (_trav);
		}

		public override IAstExpr TraversalCalcType (IAstType? _expect_type) {
			if (_expect_type != null)
				throw new Exception ("语句类型不可指定期望类型");
			bool _success = true;
			if (Expr != null) {
				if (ReturnType.IsOptional) {
					if (ReturnType.UnwrapOptional is AstType_Void)
						ReturnType = new AstType_Integer { BitWidth = 32, IsSign = true }.Optional;
					try {
						_success &= Expr.TraversalCalcTypeWrap (ReturnType.UnwrapOptional, a => Expr = a);
						Expr = AstExprTypeCast.Make (Expr, ReturnType);
					} catch (Exception) {
						_success &= Expr.TraversalCalcTypeWrap (ReturnType, a => Expr = a);
					}
				} else {
					_success &= Expr.TraversalCalcTypeWrap (ReturnType, a => Expr = a);
				}
			}
			return _success ? this : null;
		}

		public override List<IAstStmt> ExpandStmt ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			if (Expr == null || Expr.IsSimpleExpr)
				return new List<IAstStmt> { this };
			var _temp_defvar = new AstStmt_DefVariable { Token = Token, DataType = Expr.ExpectType, VarName = Common.GetTempId (), Expr = Expr };
			var _stmts = _temp_defvar.ExpandStmt (_cache_err);
			Expr = _temp_defvar.GetRef ();
			_stmts.Add (this);
			return _stmts;
		}

		public override string GenerateCSharp (int _indent) {
			if (Expr == null && ReturnType.ToString () == "void?") {
				return $"{_indent.Indent ()}return new fa.OptionalVoid {{ __index__ = 0 }};\r\n";
			} else if (Expr != null) {
				return $"{_indent.Indent ()}return {Expr.GenerateCSharp (_indent)};\r\n";
			} else {
				return $"{_indent.Indent ()}return;\r\n";
			}
		}

		public override string GenerateCpp (int _indent) {
			if (Expr == null && ReturnType.ToString () == "void?") {
				return $"{_indent.Indent ()}return std::nullopt;\r\n";
			} else if (Expr != null) {
				return $"{_indent.Indent ()}return {Expr.GenerateCpp (_indent)};\r\n";
			} else {
				return $"{_indent.Indent ()}return;\r\n";
			}
		}
	}
}

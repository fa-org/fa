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
		public IAstType ReturnType { get; set; }
		public IAstExpr Expr { get; set; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			if (Expr != null)
				Expr = _cb (Expr, _deep, _group);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (_expect_type != null)
				throw new Exception ("语句类型不可指定期望类型");
			if (Expr != null) {
				if (ReturnType is AstType_OptionalWrap _otype) {
					if (_otype.ItemType is AstType_Void)
						_otype = new AstType_OptionalWrap { ItemType = new AstType_Integer { BitWidth = 32, IsSign = true } };
					try {
						Expr = Expr.TraversalCalcType (_otype.ItemType);
						Expr = AstExprTypeCast.Make (Expr, _otype);
					} catch (Exception) {
						Expr = Expr.TraversalCalcType (_otype);
					}
				} else {
					Expr = Expr.TraversalCalcType (ReturnType);
				}
			}
			return this;
		}

		public override List<IAstStmt> ExpandStmt ((IAstExprName _var, AstStmt_Label _pos) _cache_err) {
			return ExpandStmtHelper (_cache_err, (_check_cb) => {
				if (Expr == null || Expr.IsSimpleExpr)
					return new List<IAstStmt> { this };
				var _temp_defvar = new AstStmt_DefVariable { Token = Token, DataType = Expr.ExpectType, VarName = Common.GetTempId (), Expr = Expr };
				var _stmts = _temp_defvar.ExpandStmt (_cache_err);
				Expr = _temp_defvar.GetRef ();
				_stmts.Add (this);
				return _stmts;
			});
		}

		public override string GenerateCSharp (int _indent) {
			if (Expr == null && ReturnType.ToString () == "void?") {
				return $"{_indent.Indent ()}return fa.Optional<int>.FromValue (0);\r\n";
			} else if (Expr != null) {
				return $"{_indent.Indent ()}return {Expr.GenerateCSharp (_indent)};\r\n";
			} else {
				return $"{_indent.Indent ()}return;\r\n";
			}
		}
	}
}

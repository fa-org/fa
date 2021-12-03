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
		public IAstExpr Expr { get; set; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			if (Expr != null)
				Expr = _cb (Expr, _deep, _group);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (_expect_type != null)
				throw new Exception ("语句类型不可指定期望类型");
			if (Expr != null) {
				if (Info.CurrentFunc.ReturnType is AstType_OptionalWrap _otype) {
					try {
						Expr = Expr.TraversalCalcType (_otype.ItemType);
						Expr = AstExprTypeCast.Make (Expr, _otype);
					} catch (Exception) {
						Expr = Expr.TraversalCalcType (_otype);
					}
				} else {
					Expr = Expr.TraversalCalcType (Info.CurrentReturnType ());
				}
			}
			return this;
		}

		public override List<IAstStmt> ExpandStmt () {
			if (Expr == null)
				return new List<IAstStmt> { this };
			var _temp_defvar = new AstStmt_DefVariable { Token = Token, DataType = Expr.ExpectType, VarName = Common.GetTempId (), Expr = Expr };
			var _stmts = _temp_defvar.ExpandStmt ();
			Expr = new AstExprName_Variable { Token = Token, ExpectType = _temp_defvar.DataType, Var = _temp_defvar };
			_stmts.Add (this);
			return _stmts;
		}

		public override string GenerateCSharp (int _indent) {
			if (Expr == null && Info.CurrentReturnType ().ToString () == "void?") {
				return $"return fa.Optional<int>.FromValue (0);";
			} else if (Expr != null) {
				return $"return {Expr.GenerateCSharp (_indent)};";
			} else {
				return $"return;";
			}
		}
	}
}

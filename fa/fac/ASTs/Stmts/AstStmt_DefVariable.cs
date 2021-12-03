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
	public class AstStmt_DefVariable: IAstStmt {
		public IAstType DataType { get; set; }
		public string VarName { get; set; }
		public IAstExpr Expr { get; set; }



		public static List<IAstStmt> FromCtx (FaParser.DefVarStmtContext _ctx) {
			List<IAstStmt> _stmts = new List<IAstStmt> ();
			var _type = IAstType.FromContext (_ctx.type ());
			foreach (var _var_ctx in _ctx.idAssignExpr ()) {
				var _varstmt = new AstStmt_DefVariable { Token = _ctx.Start };
				_varstmt.DataType = _type;
				_varstmt.VarName = _var_ctx.id ().GetText ();
				_varstmt.Expr = FromContext (_var_ctx.expr ());
				if (_varstmt.Expr is AstExpr_Lambda _lambdaexpr)
					_lambdaexpr.InitLambda (_type);
				_stmts.Add (_varstmt);
			}
			return _stmts;
		}

		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			if (VarName == "_")
				throw new CodeException (Token, "声明的变量名不能为“_”");
			if (Expr != null)
				Expr = _cb (Expr, _deep, _group);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (_expect_type != null)
				throw new Exception ("语句类型不可指定期望类型");
			Expr = Expr.TraversalCalcType (DataType);
			return this;
		}

		public override List<IAstStmt> ExpandStmt () {
			var (_stmts, _expr) = Expr.ExpandExpr ();
			Expr = _expr;
			_stmts.Add (this);
			return _stmts;
		}

		public override string GenerateCSharp (int _indent) {
			return $"{_indent.Indent ()}{DataType.GenerateCSharp (_indent)} {VarName} = {Expr.GenerateCSharp (_indent)};";
		}
	}
}

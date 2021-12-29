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
		public string VarName { init; get; } = Common.GetTempId ();
		public IAstExpr Expr { get; set; } = null;



		public AstExprName_Variable GetRef () => new AstExprName_Variable { Token = Token, ExpectType = DataType, Var = this };

		public static List<IAstStmt> FromContext (FaParser.DefVarStmtContext _ctx) {
			List<IAstStmt> _stmts = new List<IAstStmt> ();
			var _type = IAstType.FromContext (_ctx.type ());
			foreach (var _var_ctx in _ctx.idAssignExpr ()) {
				var _varstmt = new AstStmt_DefVariable { Token = _ctx.Start, DataType = _type, VarName = _var_ctx.id ().GetText () };
				_varstmt.Expr = FromContext (_var_ctx.expr ());
				if (_varstmt.Expr is AstExpr_Lambda _lambdaexpr)
					_lambdaexpr.InitLambda (_type);
				_stmts.Add (_varstmt);
			}
			return _stmts;
		}

		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) {
			if (VarName == "_")
				throw new CodeException (Token, "声明的变量名不能为“_”");
			if (Expr != null)
				Expr = Expr.TraversalWrap (_trav);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (_expect_type != null)
				throw new Exception ("语句类型不可指定期望类型");
			if (Expr != null)
				Expr = Expr.TraversalCalcType (DataType);
			return this;
		}

		public override List<IAstStmt> ExpandStmt ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			var _stmts = new List<IAstStmt> { this };
			if (Expr == null || Expr.IsSimpleExpr)
				return _stmts;

			AstStmt_Label _label = null;
			if (DataType.IsOptional) {
				_label = new AstStmt_Label { };
				_cache_err = (_var: GetRef (), _pos: _label);
			}
			var (_stmts2, _expr) = Expr.ExpandExpr (_cache_err);
			_stmts.AddRange (_stmts2);
			Expr = null;
			_stmts.Add (AstStmt_ExprWrap.MakeAssign (GetRef (), _expr));
			if (_label != null)
				_stmts.Add (_label);
			return _stmts;
		}

		public override string GenerateCSharp (int _indent) {
			if (m_init) {
				m_init = false;
				return $"{_indent.Indent ()}{DataType.GenerateCSharp (_indent)} {VarName}{(Expr != null ? $" = {Expr.GenerateCSharp (_indent)}" : "")};\r\n";
			} else {
				return Expr != null ? $"{_indent.Indent ()}{VarName} = {Expr.GenerateCSharp (_indent)};\r\n" : "";
			}
		}

		private bool m_init = true;
	}
}

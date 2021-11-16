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
	class AstStmt_DefVariable: IAstStmt {
		public IAstType DataType { get; set; }
		public string VarName { get; set; }
		public IAstExpr Expr { get; set; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			Expr = _cb (Expr, _deep, _group);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (_expect_type != null)
				throw new Exception ("语句类型不可指定期望类型");
			Expr = Expr.TraversalCalcType (DataType);
			return this;
		}

		public override (string, string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb) {
			StringBuilder _psb = new StringBuilder (), _sb = new StringBuilder ();
			var (_a, _b, _c) = DataType.GenerateCSharp (_indent, null);
			var _ec = new ExprChecker (DataType.ResultMayOptional () ? new AstExprName_Variable { Token = Token, Var = this, ExpectType = DataType } : null);
			var (_d, _e, _f) = Expr.GenerateCSharp (_indent, _ec != null ? _ec.CheckFunc : _check_cb);
			var (_g, _h) = _ec?.GenerateCSharpPrefixSuffix (_indent, Expr.Token) ?? ("", "");
			_psb.Append (_a).AppendLine ($"{_indent.Indent ()}{_b} {VarName};").Append (_d).Append (_g);
			_sb.AppendLine ($"{_indent.Indent ()}{VarName} = {_e};");
			return (_psb.ToString (), _sb.ToString (), $"{_c}{_f}{_h}");
		}
	}
}

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
	class AstStmt_DefVariable: IAstStmt {
		public IAstType DataType { get; set; }
		public string VarName { get; set; }
		public IAstExpr Expr { get; set; }



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

		public override (string, string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb) {
			var _ec = new ExprChecker (DataType is AstType_OptionalWrap ? new AstExprName_Variable { Token = Token, Var = this, ExpectType = DataType } : null);
			var _sb = new StringBuilder ();
			_sb.AppendLine ($"{_indent.Indent ()}{DataType.GenerateCSharp_Type ()} {VarName};");
			var _tmp_expr = new AstExpr_Op2 {
				Token = Token,
				Value1 = new AstExprName_Variable { Token = Token, ExpectType = DataType, Var = this },
				Value2 = Expr,
				Operator = "=",
				ExpectType = DataType,
			};
			var (_a, _b, _c) = _tmp_expr.GenerateCSharp (_indent, _ec.CheckFunc);
			var (_d, _e) = _ec.GenerateCSharpPrefixSuffix (_indent, Expr.Token);
			_sb.Append (_a).Append (_d);
			_sb.AppendLine ($"{_indent.Indent ()}{_b};");
			_sb.Append (_e).Append (_c);
			return ("", _sb.ToString (), "");
		}
	}
}

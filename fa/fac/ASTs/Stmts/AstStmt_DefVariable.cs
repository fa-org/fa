using fac.ASTs.Exprs;
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
			if (DataType is AstType_OptionalWrap _owrap) {
				try {
					Expr = Expr.TraversalCalcType (_owrap.ItemType);
					Expr = AstExprTypeCast.Make (Expr, DataType);
				} catch (Exception) {
					Expr = Expr.TraversalCalcType (DataType);
				}
			} else {
				if (Info.CurrentFunc.ReturnType is AstType_OptionalWrap) {
					try {
						Expr = Expr.TraversalCalcType (DataType);
					} catch (Exception) {
						Expr = Expr.TraversalCalcType (new AstType_OptionalWrap { Token = Token, ItemType = DataType });
					}
				} else {
					Expr = Expr.TraversalCalcType (DataType);
				}
			}
			return this;
		}

		public override (string, string) GenerateCSharp (int _indent) {
			var (_a, _b) = DataType.GenerateCSharp (_indent);
			var (_c, _d) = Expr.GenerateCSharp (_indent);
			if (Expr.ExpectType is AstType_OptionalWrap && DataType is not AstType_OptionalWrap) {
				var _sb = new StringBuilder ();
				var (_e, _f) = Info.CurrentFunc.ReturnType.GenerateCSharp (_indent);
				_sb.Append (_a).Append (_c).Append (_e);
				_sb.AppendLine ($"{_indent.Indent ()}if (!{_d}.HasValue ())");
				_sb.AppendLine ($"{(_indent + 1).Indent ()}return {_f}.FromError ({_d}.GetError ());");
				return (_sb.ToString (), $"{_indent.Indent ()}{_b} {VarName} = {_d}.GetValue ();\n");
			} else {
				return ($"{_a}{_c}", $"{_indent.Indent ()}{_b} {VarName} = {_d};\n");
			}
		}
	}
}

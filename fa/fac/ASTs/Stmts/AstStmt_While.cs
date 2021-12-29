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
	public class AstStmt_While: IAstStmt {
		public bool IsDoWhile { init; get; }
		public IAstExpr Condition { get; set; }
		public List<IAstStmt> Contents { get; set; }



		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) {
			var _temp_int = Common.GetRandomInt ();
			if (!IsDoWhile)
				Condition = Condition.TraversalWrap (_trav);
			Contents.TraversalWraps (_trav);
			if (IsDoWhile)
				Condition = Condition.TraversalWrap (_trav);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (_expect_type != null)
				throw new Exception ("语句类型不可指定期望类型");
			if (Info.CurrentReturnType ().IsOptional) {
				try {
					Condition = Condition.TraversalCalcType (IAstType.FromName ("bool"));
				} catch (Exception) {
					Condition = Condition.TraversalCalcType (IAstType.FromName ("bool?"));
				}
			} else {
				Condition = Condition.TraversalCalcType (IAstType.FromName ("bool"));
			}
			Contents.TraversalCalcType ();
			return this;
		}

		public override List<IAstStmt> ExpandStmt ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			var (_stmts, _expr) = Condition.ExpandExpr (_cache_err);
			Condition = _expr;
			Contents = Contents.ExpandStmts (_cache_err);
			Contents.AddRange (_stmts);
			if (IsDoWhile) {
				return new List<IAstStmt> { this };
			} else {
				_stmts.Add (this);
				return _stmts;
			}
		}

		public override string GenerateCSharp (int _indent) {
			var _sb = new StringBuilder ();
			if (IsDoWhile) {
				_sb.AppendLine ($"{_indent.Indent ()}do {{");
				_sb.AppendStmts (Contents, _indent + 1);
				_sb.AppendLine ($"{_indent.Indent ()}}} while ({Condition.GenerateCSharp (_indent)});");
			} else {
				_sb.AppendLine ($"{_indent.Indent ()}while ({Condition.GenerateCSharp (_indent)}) {{");
				_sb.AppendStmts (Contents, _indent + 1);
				_sb.AppendLine ($"{_indent.Indent ()}}}");
			}
			return _sb.ToString ();
		}
	}
}

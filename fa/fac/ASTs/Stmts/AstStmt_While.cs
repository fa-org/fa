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

		public override IAstExpr TraversalCalcType (IAstType? _expect_type) {
			if (_expect_type != null)
				throw new Exception ("语句类型不可指定期望类型");
			bool _success = true;
			if (Info.CurrentReturnType ().IsOptional) {
				try {
					_success &= Condition.TraversalCalcTypeWrap (IAstType.FromName ("bool"), a => Condition = a);
				} catch (Exception) {
					_success &= Condition.TraversalCalcTypeWrap (IAstType.FromName ("bool?"), a => Condition = a);
				}
			} else {
				_success &= Condition.TraversalCalcTypeWrap (IAstType.FromName ("bool"), a => Condition = a);
			}
			_success &= Contents.TraversalCalcTypeWrap ();
			return _success ? this : null;
		}

		public override List<IAstStmt> ExpandStmt ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			var (_stmts, _expr) = Condition.ExpandExpr (_cache_err);
			Condition = _expr;
			Contents = Contents.ExpandStmts (_cache_err);
			if (IsDoWhile) {
				var _stmts1 = (from p in _stmts where p is AstStmt_DefVariable select p).ToList ();
				_stmts = (from p in _stmts where p is not AstStmt_DefVariable select p).ToList ();
				Contents.AddRange (_stmts);
				_stmts1.Add (this);
				return _stmts1;
			} else {
				Contents.AddRange (_stmts);
				_stmts.Add (this);
				return _stmts;
			}
		}

		public override string GenerateCSharp (int _indent) {
			var _sb = new StringBuilder ();
			if (IsDoWhile) {
				_sb.AppendLine ($"{_indent.Indent ()}do {{");
				_sb.AppendCSharpStmts (Contents, _indent + 1);
				_sb.AppendLine ($"{_indent.Indent ()}}} while ({Condition.GenerateCSharp (_indent)});");
			} else {
				_sb.AppendLine ($"{_indent.Indent ()}while ({Condition.GenerateCSharp (_indent)}) {{");
				_sb.AppendCSharpStmts (Contents, _indent + 1);
				_sb.AppendLine ($"{_indent.Indent ()}}}");
			}
			return _sb.ToString ();
		}

		public override string GenerateCpp (int _indent) {
			var _sb = new StringBuilder ();
			if (IsDoWhile) {
				_sb.AppendLine ($"{_indent.Indent ()}do {{");
				_sb.AppendCppStmts (Contents, _indent + 1);
				_sb.AppendLine ($"{_indent.Indent ()}}} while ({Condition.GenerateCpp (_indent)});");
			} else {
				_sb.AppendLine ($"{_indent.Indent ()}while ({Condition.GenerateCpp (_indent)}) {{");
				_sb.AppendCppStmts (Contents, _indent + 1);
				_sb.AppendLine ($"{_indent.Indent ()}}}");
			}
			return _sb.ToString ();
		}
	}
}

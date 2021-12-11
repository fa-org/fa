using fac.ASTs.Exprs;
using fac.ASTs.Exprs.Names;
using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Stmts {
	public class AstStmt_HuaQuotWrap: IAstStmt {
		public List<IAstStmt> Stmts { get; set; }

		public override void Traversal ((int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) _trav) {
			Stmts.TraversalWraps ((_deep: _trav._deep + 1, _group: Common.GetRandomInt (), _cb: _trav._cb));
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (_expect_type != null)
				throw new Exception ("语句类型不可指定期望类型");
			Stmts.TraversalCalcType ();
			return this;
		}

		public override List<IAstStmt> ExpandStmt ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			Stmts = Stmts.ExpandStmts (_cache_err);
			return new List<IAstStmt> { this };
		}

		public override string GenerateCSharp (int _indent) {
			var _sb = new StringBuilder ();
			_sb.AppendLine ($"{_indent.Indent ()}{{");
			_sb.AppendStmts (Stmts, _indent + 1);
			_sb.AppendLine ($"{_indent.Indent ()}}}");
			return _sb.ToString ();
		}
	}
}

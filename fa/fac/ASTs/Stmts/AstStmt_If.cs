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
	public class AstStmt_If: IAstStmt {
		public IAstExpr Condition { get; set; }
		public List<IAstStmt> IfTrueCodes { get; set; }
		public List<IAstStmt> IfFalseCodes { get; set; }



		public static List<IAstStmt> FromIfStmt (List<FaParser.ExprContext> _conditions, List<FaParser.StmtContext[]> _contents) {
			List<IAstStmt> _stmts = new List<IAstStmt> ();
			var _ifexpr = new AstStmt_If { Token = _conditions[0].Start };
			_ifexpr.Condition = FromContext (_conditions[0]);
			_ifexpr.IfTrueCodes = FromStmts (_contents[0]);
			if (_conditions.Count == 1) {
				if (_contents.Count > 1) {
					_ifexpr.IfFalseCodes = FromStmts (_contents[1]);
				} else {
					_ifexpr.IfFalseCodes = new List<IAstStmt> ();
				}
			} else {
				_ifexpr.IfFalseCodes = FromIfStmt (_conditions.Skip (1).ToList (), _contents.Skip (1).ToList ());
			}
			_stmts.Add (_ifexpr);
			return _stmts;
		}

		public static List<IAstStmt> FromCtx (FaParser.IfStmtContext _ctx) {
			var _conditions = _ctx.expr ().ToList ();
			var _contents = (from p in _ctx.quotStmtPart () select p.stmt ()).ToList ();
			return FromIfStmt (_conditions, _contents);
		}

		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			Condition = _cb (Condition, _deep, _group);
			IfTrueCodes.Traversal (_deep + 1, 0, _cb);
			IfFalseCodes.Traversal (_deep + 1, 1, _cb);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (_expect_type != null)
				throw new Exception ("语句类型不可指定期望类型");
			Condition = Condition.TraversalCalcType (IAstType.FromName ("bool"));
			IfTrueCodes.TraversalCalcType ();
			IfFalseCodes.TraversalCalcType ();
			return this;
		}

		public override List<IAstStmt> ExpandStmt () {
			var (_stmts, _expr) = Condition.ExpandExpr ();
			Condition = _expr;
			IfTrueCodes = (from p in IfTrueCodes select p.ExpandStmt ()).CombileStmts ();
			IfFalseCodes = (from p in IfFalseCodes select p.ExpandStmt ()).CombileStmts ();
			_stmts.Add (this);
			return _stmts;
		}

		public override string GenerateCSharp (int _indent) {
			var _sb = new StringBuilder ();
			_sb.AppendLine ($"{_indent.Indent ()}if ({Condition.GenerateCSharp (_indent)}) {{");
			_sb.AppendStmts (IfTrueCodes, _indent + 1);
			if (IfFalseCodes.Any ()) {
				_sb.AppendLine ($"{_indent.Indent ()}}} else {{");
				_sb.AppendStmts (IfFalseCodes, _indent + 1);
			}
			_sb.AppendLine ($"{_indent.Indent ()}}}");
			return _sb.ToString ();
		}
	}
}

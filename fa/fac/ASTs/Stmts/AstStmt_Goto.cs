using fac.ASTs.Exprs;
using fac.ASTs.Exprs.Names;
using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Stmts {
	public class AstStmt_Goto: IAstStmt {
		public AstStmt_Label Label { init; get; }



		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) { }

		public override IAstExpr TraversalCalcType (IAstType _expect_type) => this;

		public override List<IAstStmt> ExpandStmt ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) => new List<IAstStmt> { this };

		public override string GenerateCSharp (int _indent) => $"{_indent.Indent ()}goto {Label.LabelName};\r\n";
	}
}

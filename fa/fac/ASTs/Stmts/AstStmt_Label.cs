using fac.ASTs.Exprs;
using fac.ASTs.Exprs.Names;
using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Stmts {
	public class AstStmt_Label: IAstStmt {
		public string LabelName { get; } = Common.GetTempId ();
		private bool m_used = false;



		public AstStmt_Goto GetRef () {
			m_used = true;
			return new AstStmt_Goto { Token = Token, Label = this };
		}

		public override void Traversal ((int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) _trav) {}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) => this;

		public override List<IAstStmt> ExpandStmt ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) => new List<IAstStmt> { this };

		public override string GenerateCSharp (int _indent) => m_used ? $"{(_indent - 1).Indent ()}{LabelName}:\r\n" : "";
	}
}

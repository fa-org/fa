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
	class AstStmt_For2: IAstStmt {
		public AstStmt_DefVariable Iterator { get; set; }
		public IAstExpr ListContainer { get; set; }
		public List<IAstStmt> BodyCodes { get; set; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			Iterator = _cb (Iterator, _deep + 1, 0) as AstStmt_DefVariable;
			ListContainer = _cb (ListContainer, _deep + 1, 0);
			BodyCodes.Traversal (_deep + 1, 0, _cb);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (_expect_type != null)
				throw new Exception ("语句类型不可指定期望类型");
			// Iterator 为虚拟变量定义对象，不需要重新计算类型
			ListContainer = ListContainer.TraversalCalcType (new AstType_ArrayWrap { Token = Iterator.DataType.Token, ItemType = Iterator.DataType, Params = false });
			BodyCodes.TraversalCalcType ();
			return this;
		}

		public override (string, string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb) {
			var _sb = new StringBuilder ();
			var _ec = new ExprChecker (null);
			var (_a, _b, _c) = ListContainer.GenerateCSharp (_indent, _ec.CheckFunc);
			_sb.AppendLine ($"{_a}{_indent.Indent ()}foreach ({Iterator.DataType.GenerateCSharp_Type ()} {Iterator.VarName} in {_b}) {{");
			_sb.AppendStmts (BodyCodes, _indent + 1);
			_sb.AppendLine ($"{_indent.Indent ()}}}");
			_sb.Append (_c);
			return ("", _sb.ToString (), "");
		}
	}
}

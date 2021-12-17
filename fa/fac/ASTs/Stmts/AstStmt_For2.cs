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
	public class AstStmt_For2: IAstStmt {
		public AstStmt_DefVariable Iterator { get; set; }
		public IAstExpr ListContainer { get; set; }
		public List<IAstStmt> BodyCodes { get; set; }



		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) {
			var _rand_int = Common.GetRandomInt ();
			var _trav1 = (_deep: _trav._deep + 1, _group: _rand_int, _loop: _trav._loop, _cb: _trav._cb);
			Iterator = Iterator.TraversalWrap (_trav1) as AstStmt_DefVariable;
			ListContainer = ListContainer.TraversalWrap (_trav1);
			BodyCodes.TraversalWraps (_trav1);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (_expect_type != null)
				throw new Exception ("语句类型不可指定期望类型");
			// Iterator 为虚拟变量定义对象，不需要重新计算类型
			ListContainer = ListContainer.TraversalCalcType (new AstType_ArrayWrap { Token = Iterator.DataType.Token, ItemType = Iterator.DataType, Params = false });
			BodyCodes.TraversalCalcType ();
			return this;
		}

		public override List<IAstStmt> ExpandStmt ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			var (_stmts, _expr) = ListContainer.ExpandExpr (_cache_err);
			ListContainer = _expr;
			BodyCodes = BodyCodes.ExpandStmts (_cache_err);
			_stmts.Add (this);
			return _stmts;
		}

		public override string GenerateCSharp (int _indent) {
			var _sb = new StringBuilder ();
			_sb.AppendLine ($"{_indent.Indent ()}foreach ({Iterator.DataType.GenerateCSharp (_indent)} {Iterator.VarName} in {ListContainer.GenerateCSharp (_indent)}) {{");
			_sb.AppendStmts (BodyCodes, _indent + 1);
			_sb.AppendLine ($"{_indent.Indent ()}}}");
			return _sb.ToString ();
		}
	}
}

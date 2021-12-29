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
	public class AstStmt_For: IAstStmt {
		public List<IAstStmt> Initializes { get; set; }
		public IAstExpr Condition { get; set; }
		public List<IAstExpr> Increment { get; set; }
		public List<IAstStmt> BodyCodes { get; set; }



		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) {
			int _rand_int = Common.GetRandomInt ();
			var _trav1 = (_deep: _trav._deep + 1, _group: _rand_int, _loop: _trav._loop, _cb: _trav._cb);
			Initializes.TraversalWraps (_trav1);
			Condition = Condition.TraversalWrap (_trav1);
			Increment.TraversalWraps (_trav1);
			BodyCodes.TraversalWraps (_trav1);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (_expect_type != null)
				throw new Exception ("语句类型不可指定期望类型");
			Initializes.TraversalCalcType ();
			if (Info.CurrentReturnType ().IsOptional) {
				try {
					Condition = Condition.TraversalCalcType (IAstType.FromName ("bool"));
				} catch (Exception) {
					Condition = Condition.TraversalCalcType (IAstType.FromName ("bool?"));
				}
			} else {
				Condition = Condition.TraversalCalcType (IAstType.FromName ("bool"));
			}
			Increment.TraversalCalcType ();
			BodyCodes.TraversalCalcType ();
			return this;
		}

		public override List<IAstStmt> ExpandStmt ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			var _stmts = Initializes.ExpandStmts (_cache_err);
			(Initializes, Condition) = Condition.ExpandExpr (_cache_err);
			for (int i = 0; i < Increment.Count; ++i) {
				var (_inc_stmts, _inc_expr) = Increment[i].ExpandExpr (_cache_err);
				if (_inc_stmts.Count > 0)
					throw new CodeException (Increment[i].Token, $"此处不支持复合逻辑表达式");
				Increment[i] = _inc_expr;
			}
			BodyCodes = BodyCodes.ExpandStmts (_cache_err);
			_stmts.Add (this);
			return new List<IAstStmt> { new AstStmt_HuaQuotWrap { Token = _stmts[0].Token, Stmts = _stmts } };
		}

		public override string GenerateCSharp (int _indent) {
			var _sb = new StringBuilder ();
			// 此处 Initializes 每次判断前执行一遍
			_sb.AppendStmts (Initializes, _indent);
			//var _inc_str = string.Join (", ", from p in Increment select p.GenerateCSharp (_indent));
			_sb.AppendLine ($"{_indent.Indent ()}for (; {Condition.GenerateCSharp (_indent)}; ) {{");
			_sb.AppendStmts (BodyCodes, _indent + 1);
			_sb.AppendExprs (Increment, _indent + 1);
			_sb.AppendStmts (Initializes, _indent + 1);
			_sb.AppendLine ($"{_indent.Indent ()}}}");
			return _sb.ToString ();
		}
	}
}

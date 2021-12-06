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



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			Initializes.Traversal (_deep, _group, _cb);
			Condition = _cb (Condition, _deep, _group);
			Increment.Traversal (_deep, _group, _cb);
			BodyCodes.Traversal (_deep + 1, 0, _cb);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (_expect_type != null)
				throw new Exception ("语句类型不可指定期望类型");
			Initializes.TraversalCalcType ();
			if (Info.CurrentFunc.ReturnType is AstType_OptionalWrap) {
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

		public override List<IAstStmt> ExpandStmt ((IAstExprName _var, AstStmt_Label _pos) _cache_err) {
			return ExpandStmtHelper (_cache_err, (_check_cb) => {
				var _stmts = Initializes.ExpandStmts (_cache_err);
				(Initializes, Condition) = Condition.ExpandExpr (_cache_err, _check_cb);
				for (int i = 0; i < Increment.Count; ++i) {
					var (_inc_stmts, _inc_expr) = Increment[i].ExpandExpr (_cache_err, _check_cb);
					if (_inc_stmts.Count > 0)
						throw new CodeException (Increment[i].Token, $"此处不支持复合逻辑表达式");
					Increment[i] = _inc_expr;
				}
				BodyCodes = BodyCodes.ExpandStmts (_cache_err);
				_stmts.Add (this);
				return new List<IAstStmt> { new AstStmt_HuaQuotWrap { Token = _stmts[0].Token, Stmts = _stmts } };
			});
		}

		public override string GenerateCSharp (int _indent) {
			var _sb = new StringBuilder ();
			// 此处 Initializes 每次判断前执行一遍
			_sb.AppendStmts (Initializes, _indent);
			var _inc_str = string.Join (", ", from p in Increment select p.GenerateCSharp (_indent));
			_sb.AppendLine ($"{_indent.Indent ()}for (; {Condition.GenerateCSharp (_indent)}; {_inc_str}) {{");
			_sb.AppendStmts (BodyCodes, _indent + 1);
			_sb.AppendStmts (Initializes, _indent + 1);
			_sb.AppendLine ($"{_indent.Indent ()}}}");
			return _sb.ToString ();
		}
	}
}

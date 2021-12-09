using fac.AntlrTools;
using fac.ASTs.Exprs.Names;
using fac.ASTs.Stmts;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	public class AstExpr_Op2s: IAstExpr {
		public List<IAstExpr> Values { get; set; }
		public List<string> Operators { get; set; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			for (int i = 0; i < Values.Count; ++i)
				Values [i] = _cb (Values[i], _deep, _group);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if ((from p in Operators where !sComare.Contains (p) select p).Any ())
				throw new UnimplException (Values[0].Token);
			var _item_type = TypeFuncs.GetCompatibleType (false, (from p in Values select p.GuessType ()).ToArray ());
			for (int i = 0; i < Values.Count; ++i)
				Values[i] = Values[i].TraversalCalcType (_item_type);
			ExpectType = IAstType.FromName ("bool");
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () => IAstType.FromName ("bool");

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos) _cache_err) {
			var _stmts = new List<IAstStmt> ();
			for (int i = 0; i < Values.Count; ++i) {
				var (_stmts1, _val1) = Values[i].ExpandExpr (_cache_err, _check_cb);
				_stmts.AddRange (_stmts1);
				Values[i] = _val1;
				if (i > 0) {
					Values[i - 1] = new AstExpr_Op2 { Token = Values[i - i].Token, Value1 = Values[i - 1], Value2 = Values[i], Operator = Operators[i - 1], ExpectType = IAstType.FromName ("bool") };
				}
			}
			Values.RemoveAt (Values.Count - 1);
			while (Values.Count > 1) {
				Values [0] = new AstExpr_Op2 { Token = Values[0].Token, Value1 = Values[0], Value2 = Values[1], Operator = "&&", ExpectType = IAstType.FromName ("bool") };
				Values.RemoveAt (1);
			}
			return (_stmts, Values[0]);
		}

		public override string GenerateCSharp (int _indent) => throw new Exception ("不应执行此处代码");

		private static HashSet<string> sComare = new HashSet<string> { ">", ">=", "<", "<=" };

		public override bool AllowAssign () => false;
	}
}

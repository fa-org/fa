using fac.AntlrTools;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	class AstExpr_Op2s: IAstExpr {
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

		public override (string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb) {
			StringBuilder _psb = new StringBuilder (), _sb = new StringBuilder ();
			_sb.Append ("(");
			for (int i = 0; i < Operators.Count; ++i) {
				var (_a, _b) = Values[i].GenerateCSharp (_indent, _check_cb);
				var (_c, _d) = Values[i + 1].GenerateCSharp (_indent, _check_cb);
				_psb.Append (_a).Append (_c);
				_sb.Append ($"({_b} {Operators[i]} {_d}) && ");
			}
			_sb.Remove (_sb.Length - 4, 4);
			_sb.Append (")");
			return (_psb.ToString (), _sb.ToString ());
		}

		private static HashSet<string> sComare = new HashSet<string> { ">", ">=", "<", "<=" };

		public override bool AllowAssign () => false;
	}
}

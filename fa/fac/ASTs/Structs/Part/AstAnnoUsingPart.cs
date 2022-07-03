using Antlr4.Runtime;
using fac.ASTs.Exprs;
using fac.ASTs.Exprs.Names;
using fac.ASTs.Stmts;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Structs.Part {
	public class AstAnnoUsingPart: IAstExpr {
		public AstInterface? Anno { get; set; } = null;
		public string TempAnnoName { init; get; }
		public List<string>? TempVarNames { get; set; } = null;
		public List<IAstExpr>? InitValues { get; set; } = null;



		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) {
			var _temp_int = Common.GetRandomInt ();
			var _trav1 = (_deep: _trav._deep + 1, _group: _temp_int, _loop: _trav._loop, _cb: _trav._cb);
			InitValues.TraversalWraps (_trav1);
		}

		public override IAstExpr TraversalCalcType (IAstType? _expect_type) {
			ExpectType = new AstType_Void ();
			return this;
		}

		public override IAstType GuessType () => new AstType_Void ();

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) => throw new NotImplementedException ();

		public override bool AllowAssign () => false;

		public AstAnnoUsingPart (FaParser.AnnoUsingPartContext _ctx) {
			TempAnnoName = $"{_ctx.id ().GetText ()}Annotation";
			if ((_ctx.annoArg ()?.Length ?? 0) == 0)
				return;
			TempVarNames = new List<string> ();
			InitValues = new List<IAstExpr> ();
			foreach (var _val_ctx in _ctx.annoArg ()) {
				TempVarNames.Add (_val_ctx.id ().GetText ());
				InitValues.Add (IAstExpr.FromContext (_val_ctx.literal ()));
			}
		}

		public void ProcessType () {
			var _annos = Info.GetClassFromName (TempAnnoName);
			if (_annos.Count == 0) {
				throw new NotImplementedException ();
			} else if (_annos.Count > 1) {
				throw new CodeException (Token, $"不明确的 {TempAnnoName} 类型");
			}
			Anno = _annos [0] as AstInterface;
		}

		public override string GenerateCSharp (int _indent) => throw new UnimplException (Token);

		public override string GenerateCpp (int _indent) => throw new UnimplException (Token);

		public static List<AstAnnoUsingPart> FromContexts (FaParser.AnnoUsingPartContext [] _ctxs) => (from _p in _ctxs select new AstAnnoUsingPart (_p)).ToList ();
	}
}

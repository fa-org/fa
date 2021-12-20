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
	public class AstExpr_Switch: IAstExpr {
		public IAstExpr Condition { get; set; } = null;
		public List<IAstExpr> CaseCond { get; set; } = null;
		public List<IAstExpr> CaseWhen { get; set; }
		public List<(List<IAstStmt> _stmts, IAstExpr _expr)> CaseCodes { get; set; }



		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) {
			if (Condition != null)
				Condition = Condition.TraversalWrap (_trav);
			for (int i = 0; i < CaseCodes.Count; ++i) {
				var _trav1 = (_deep: _trav._deep + 1, _group: Common.GetRandomInt (), _loop: _trav._loop, _cb: _trav._cb);
				if (CaseCond != null && CaseCond[i] != null)
					CaseCond[i] = CaseCond[i].TraversalWrap (_trav1);
				if (CaseWhen != null && CaseWhen[i] != null)
					CaseWhen[i] = CaseWhen[i].TraversalWrap (_trav1);
				CaseCodes[i]._stmts.TraversalWraps (_trav1);
				CaseCodes[i] = (_stmts: CaseCodes[i]._stmts, CaseCodes[i]._expr.TraversalWrap (_trav1));
			}
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (Condition != null)
				Condition = Condition.TraversalCalcType (null);
			for (int i = 0; i < (CaseCond?.Count ?? 0); ++i) {
				if (CaseCond[i] is not AstExprName_Ignore) {
					CaseCond[i] = CaseCond[i].TraversalCalcType (CaseCond[i] is AstExpr_Is ? IAstType.FromName ("bool") : Condition.ExpectType);
				}
			}
			CaseWhen.TraversalCalcType (IAstType.FromName ("bool"));
			if (_expect_type == null)
				_expect_type = TypeFuncs.GetCompatibleType (true, (from p in CaseCodes select p._expr.GuessType ()).ToArray ());
			for (int i = 0; i < CaseCodes.Count; ++i) {
				for (int j = 0; j < CaseCodes[i]._stmts.Count; ++j)
					CaseCodes[i]._stmts[j] = CaseCodes[i]._stmts[j].TraversalCalcType (null) as IAstStmt;
				CaseCodes[i] = (CaseCodes[i]._stmts, CaseCodes[i]._expr.TraversalCalcType (_expect_type));
			}
			ExpectType = _expect_type;
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () {
			return TypeFuncs.GetCompatibleType (true, (from p in CaseCodes select p._expr.GuessType ()).ToArray ());
		}

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			var _temp_id = Common.GetTempId ();
			var _defvar_stmt = new AstStmt_DefVariable { Token = Token, DataType = ExpectType, VarName = _temp_id };
			var _switch_stmt = new AstStmt_Switch { Token = Token, Condition = Condition, CaseCond = CaseCond, CaseWhen = CaseWhen, CaseCodes = new List<IAstStmt> () };
			foreach (var (_stmts1, _expr1) in CaseCodes) {
				_stmts1.Add (AstStmt_ExprWrap.MakeAssign (_defvar_stmt.GetRef (), _expr1));
				_switch_stmt.CaseCodes.Add (_stmts1.Count == 1 ? _stmts1[0] : new AstStmt_HuaQuotWrap { Token = _expr1.Token, Stmts = _stmts1 });
			}
			var _stmts = new List<IAstStmt> { _defvar_stmt };
			_stmts.AddRange (_switch_stmt.ExpandStmt (_cache_err));
			return (_stmts, _defvar_stmt.GetRef ());
		}

		public override string GenerateCSharp (int _indent) => throw new Exception ("不应执行此处代码");

		public override bool AllowAssign () => false;
	}
}

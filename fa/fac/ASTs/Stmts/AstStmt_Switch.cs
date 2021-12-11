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
	public class AstStmt_Switch: IAstStmt {
		public IAstExpr Condition { get; set; } = null;
		public List<IAstExpr> CaseValues { get; set; } = null;
		public List<IAstExpr> CaseWhen { get; set; }
		public List<IAstStmt> CaseCodes { get; set; }



		public override void Traversal ((int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) _trav) {
			if (Condition != null)
				Condition = Condition.TraversalWrap (_trav);
			if (CaseValues != null)
				CaseValues.TraversalWraps (_trav);
			CaseWhen.TraversalWraps (_trav);
			for (int i = 0; i < CaseCodes.Count; ++i)
				CaseCodes[i] = CaseCodes[i].TraversalWrap (_trav) as IAstStmt;
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (_expect_type != null)
				throw new Exception ("语句类型不可指定期望类型");
			if (Condition != null)
				Condition = Condition.TraversalCalcType (null);
			if (CaseValues != null)
				CaseValues.TraversalCalcType (Condition.ExpectType);
			for (int i = 0; i < CaseWhen.Count; ++i) {
				if (CaseWhen[i] != null)
					CaseWhen[i] = CaseWhen[i].TraversalCalcType (CaseWhen[i] is AstExprName_Ignore ? null : IAstType.FromName ("bool"));
			}
			CaseCodes.TraversalCalcType ();
			return this;
		}

		public override List<IAstStmt> ExpandStmt ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			var _stmts = new List<IAstStmt> ();
			if (CaseValues != null) {
				// 带val match
				var (_stmts1, _cond1) = Condition.ExpandExpr (_cache_err);
				_stmts.AddRange (_stmts1);
				if (CaseValues.Count == 0) {
					// do nothing
				} else if (CaseValues[0] is AstExprName_Ignore && CaseWhen[0] == null) {
					_stmts.AddRange (CaseCodes[0].ExpandStmt (_cache_err));
				} else {
					var (_stmts2, _cond2) = CaseValues[0].ExpandExpr (_cache_err);
					var (_stmts3, _cond3) = CaseWhen[0]?.ExpandExpr (_cache_err) ?? (new List<IAstStmt> (), null);
					_stmts.AddRange (_stmts2);
					_stmts.AddRange (_stmts3);
					var _cond_expr = new AstExpr_Op2 { Token = CaseValues[0].Token, Value1 = _cond1, Value2 = _cond2, Operator = "==", ExpectType = IAstType.FromName ("bool") };
					if (_cond3 != null)
						_cond_expr = new AstExpr_Op2 { Token = CaseValues[0].Token, Value1 = _cond_expr, Value2 = _cond3, Operator = "&&", ExpectType = IAstType.FromName ("bool") };
					var (_stmts4, _cond4) = _cond_expr.ExpandExpr (_cache_err);
					_stmts.AddRange (_stmts4);
					_stmts.Add (new AstStmt_If {
						Token = CaseValues[0].Token,
						Condition = _cond4,
						IfTrueCodes = CaseCodes[0].ExpandStmt (_cache_err),
						IfFalseCodes = CaseCodes.Count switch {
							1 => new List<IAstStmt> (),
							_ when CaseWhen[1] is AstExprName_Ignore => CaseCodes[1].ExpandStmt (_cache_err),
							_ => new AstStmt_Switch {
								Token = CaseValues[1]?.Token ?? CaseWhen[1]?.Token ?? null,
								Condition = _cond1,
								CaseValues = CaseValues.Skip (1).ToList (),
								CaseWhen = CaseWhen.Skip (1).ToList (),
								CaseCodes = CaseCodes.Skip (1).ToList (),
							}.ExpandStmt (_cache_err),
						},
					});
				}
			} else {
				// 不带val match
				if (CaseWhen.Count == 0) {
					// do nothing
				} else if (CaseWhen[0] == null) {
					_stmts.AddRange (CaseCodes[0].ExpandStmt (_cache_err));
				} else {
					var (_stmts2, _cond2) = CaseWhen[0].ExpandExpr (_cache_err);
					_stmts.AddRange (_stmts2);
					_stmts.Add (new AstStmt_If {
						Token = CaseWhen[0].Token,
						Condition = _cond2,
						IfTrueCodes = CaseCodes[0].ExpandStmt (_cache_err),
						IfFalseCodes = CaseCodes.Count switch {
							1 => new List<IAstStmt> (),
							_ when CaseWhen[1] is AstExprName_Ignore => CaseCodes[1].ExpandStmt (_cache_err),
							_ => new AstStmt_Switch {
								Token = CaseWhen[1]?.Token ?? null,
								CaseWhen = CaseWhen.Skip (1).ToList (),
								CaseCodes = CaseCodes.Skip (1).ToList (),
							}.ExpandStmt (_cache_err),
						},
					});
				}
			}
			return _stmts;
		}

		public override string GenerateCSharp (int _indent) => throw new Exception ("不应执行此处代码");
	}
}

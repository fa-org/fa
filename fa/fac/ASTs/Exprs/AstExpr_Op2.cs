using fac.AntlrTools;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	class AstExpr_Op2: IAstExpr, IAst {
		public IAstExpr Value1 { get; set; }
		public IAstExpr Value2 { get; set; }
		public string Operator { get; set; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			Value1 = _cb (Value1, _deep, _group);
			Value2 = _cb (Value2, _deep, _group);
		}

		public override IAstExpr TraversalCalcType (string _expect_type) {
			string _exp1 = "", _exp2 = "";
			if (sCompareOp2s.Contains (Operator)) {
				// unknown
				ExpectType = "bool";
			} else if (sLogicOp2s.Contains (Operator)) {
				_exp1 = _exp2 = "bool";
				ExpectType = "bool";
			} else if (sNumOp2s.Contains (Operator) || sAssignOp2s.Contains (Operator)) {
				if (_expect_type != "")
					_exp1 = _exp2 = _expect_type;
			} else if (sQusQusOp2s.Contains (Operator)) {
				if (_expect_type != "") {
					_exp1 = _expect_type[^1] == '?' ? _expect_type : $"{_expect_type}?";
					_exp2 = _expect_type;
				}
			} else {
				throw new UnimplException (Token);
			}

			if (_exp1 == "" || _exp2 == "") {
				_exp1 = Value1.GuessType ();
				_exp2 = Value1.GuessType ();
				if (sQusQusOp2s.Contains (Operator)) {
					if (_exp1[^1] != '?')
						throw new CodeException (Token, "不可空的值类型无法使用 ?? 运算符");
					ExpectType = TypeFuncs.GetCompatibleType (_exp1, _exp2);
					if (_exp2[^1] != '?' && ExpectType[^1] == '?')
						ExpectType = ExpectType[..^1];
				} else {
					_exp1 = _exp2 = TypeFuncs.GetCompatibleType (_exp1, _exp2);
					ExpectType = _exp2;
				}
			}

			Value1 = Value1.TraversalCalcType (_exp1);
			Value2 = Value2.TraversalCalcType (_exp2);
			ExpectType = TypeFuncs.GetCompatibleType (Value1.ExpectType, Value2.ExpectType);
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override string GuessType () {
			if (sCompareOp2s.Contains (Operator) || sLogicOp2s.Contains (Operator)) {
				return "bool";
			} else if (sNumOp2s.Contains (Operator) || sAssignOp2s.Contains (Operator)) {
				return TypeFuncs.GetCompatibleType (Value1.GuessType (), Value2.GuessType ());
			} else if (sQusQusOp2s.Contains (Operator)) {
				return Value2.GuessType ();
			} else {
				throw new UnimplException (Token);
			}
		}

		private static HashSet<string> sCompareOp2s = new HashSet<string> { ">", "<", ">=", "<=", "==", "!=" };
		private static HashSet<string> sLogicOp2s = new HashSet<string> { "||", "&&" };
		private static HashSet<string> sNumOp2s = new HashSet<string> { "+", "-", "*", "/", "%", "|", "&", "^", "<<", ">>" };
		private static HashSet<string> sAssignOp2s = new HashSet<string> { "=", "+=", "-=", "*=", "/=", "%=", "|=", "&=", "^=", "<<=", ">>=" };
		private static HashSet<string> sQusQusOp2s = new HashSet<string> { "??", "??=" };
	}
}

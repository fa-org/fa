using fac.AntlrTools;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	class AstExpr_Op2: IAstExpr {
		public IAstExpr Value1 { get; set; }
		public IAstExpr Value2 { get; set; }
		public string Operator { get; set; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			Value1 = _cb (Value1, _deep, _group);
			Value2 = _cb (Value2, _deep, _group);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			IAstType _exp1 = null, _exp2 = null;
			if (sCompareOp2s.Contains (Operator)) {
				ExpectType = IAstType.FromName ("bool");
			} else if (sLogicOp2s.Contains (Operator)) {
				_exp1 = _exp2 = IAstType.FromName ("bool");
				ExpectType = IAstType.FromName ("bool");
			} else if (sNumOp2s.Contains (Operator) || sAssignOp2s.Contains (Operator)) {
				if (_expect_type != null)
					_exp1 = _exp2 = _expect_type;
			} else if (sQusQusOp2s.Contains (Operator)) {
				if (_expect_type != null) {
					_exp1 = _expect_type is AstType_OptionalWrap ? _expect_type : new AstType_OptionalWrap { Token = Token, TypeStr = $"{_expect_type.TypeStr}?", ItemType = _expect_type };
					_exp2 = _expect_type;
				}
			} else {
				throw new UnimplException (Token);
			}

			if (_exp1 == null || _exp2 == null) {
				_exp1 = Value1.GuessType ();
				_exp2 = Value1.GuessType ();
				if (sQusQusOp2s.Contains (Operator)) {
					if (_exp1 is not AstType_OptionalWrap)
						throw new CodeException (Token, "不可空的值类型无法使用 ?? 运算符");
					ExpectType = TypeFuncs.GetCompatibleType (_exp1, _exp2);
					if (_exp2 is not AstType_OptionalWrap && ExpectType is AstType_OptionalWrap _exp_type_tmp)
						ExpectType = _exp_type_tmp.ItemType;
				} else {
					_exp1 = _exp2 = TypeFuncs.GetCompatibleType (_exp1, _exp2);
					if (ExpectType == null)
						ExpectType = _exp2;
				}
			}

			Value1 = Value1.TraversalCalcType (_exp1);
			Value2 = Value2.TraversalCalcType (_exp2);
			if (ExpectType == null)
				ExpectType = TypeFuncs.GetCompatibleType (Value1.ExpectType, Value2.ExpectType);
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () {
			if (sCompareOp2s.Contains (Operator) || sLogicOp2s.Contains (Operator)) {
				return IAstType.FromName ("bool");
			} else if (sNumOp2s.Contains (Operator) || sAssignOp2s.Contains (Operator)) {
				bool _opt = Operator == "/";
				var _type = TypeFuncs.GetCompatibleType (Value1.GuessType (), Value2.GuessType ());
				if (_opt)
					_type = _type is AstType_OptionalWrap ? _type : new AstType_OptionalWrap { Token = Token, TypeStr = $"{_type.TypeStr}?", ItemType = _type };
				return _type;
			} else if (sQusQusOp2s.Contains (Operator)) {
				return Value2.GuessType ();
			} else {
				throw new UnimplException (Token);
			}
		}

		public override (string, string) GenerateCSharp (int _indent) {
			var (_a, _b) = Value1.GenerateCSharp (_indent);
			var (_c, _d) = Value2.GenerateCSharp (_indent);
			return ($"{_a}{_c}", $"{_b} {Operator} {_d}");
		}

		public override bool AllowAssign () => false;

		private static HashSet<string> sCompareOp2s = new HashSet<string> { ">", "<", ">=", "<=", "==", "!=" };
		private static HashSet<string> sLogicOp2s = new HashSet<string> { "||", "&&" };
		private static HashSet<string> sNumOp2s = new HashSet<string> { "+", "-", "*", "/", "%", "|", "&", "^", "<<", ">>" };
		public static HashSet<string> sAssignOp2s = new HashSet<string> { "=", "+=", "-=", "*=", "/=", "%=", "|=", "&=", "^=", "<<=", ">>=" };
		private static HashSet<string> sQusQusOp2s = new HashSet<string> { "??", "??=" };
	}
}

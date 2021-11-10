using fac.ASTs.Exprs.Names;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	class AstExpr_Op1: IAstExpr {
		public IAstExpr Value { get; set; }
		public string Operator { get; set; }
		public bool IsPrefix { get; set; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			Value = _cb (Value, _deep, _group);
		}

		public override IAstExpr TraversalCalcType (string _expect_type) {
			Value = Value.TraversalCalcType (_expect_type);
			ExpectType = Value.ExpectType;
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override string GuessType () {
			if (IsPrefix || Operator == "++" || Operator == "--") {
				return Value.GuessType ();
			} else if (Operator[0] == '.') {
				string _access_name = Operator[1..];
				if (Value is AstExprName_Class _cls) {
					string _expect = (from p in _cls.Class.ClassVars where p.Name == _access_name select p.DataType).FirstOrDefault ();
					if (!string.IsNullOrEmpty (_expect))
						return _expect;
					_expect = (from p in _cls.Class.ClassFuncs where p.Name == _access_name select $"{_cls.Class}.{p.Name}").FirstOrDefault ();
					if (!string.IsNullOrEmpty (_expect))
						return _expect;
				}
			}
			throw new UnimplException (Token);
		}

		public override (string, string) GenerateCSharp (int _indent) {
			var (_a, _b) = Value.GenerateCSharp (_indent);
			return (_a, (IsPrefix ? $"{Operator}{_b}" : $"{_b}{Operator}"));
		}

		public override bool AllowAssign () => false;
	}
}

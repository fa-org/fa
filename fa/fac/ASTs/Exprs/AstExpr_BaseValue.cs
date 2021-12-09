using Antlr4.Runtime;
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
	public class AstExpr_BaseValue: IAstExpr {
		public IAstType DataType { get; set; }
		public string Value { get; set; }



		public static AstExpr_BaseValue FromCodeString (IToken _token, string _str) {
			if (_str[0] == '"') {
				_str = Common.UnwrapStringValue (_str);
			} else {
				throw new UnimplException (_token);
			}
			return new AstExpr_BaseValue { Token = _token, DataType = IAstType.FromName ("string"), Value = _str };
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			ExpectType = DataType;
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) { }

		public override IAstType GuessType () => DataType;

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos) _cache_err) => (new List<IAstStmt> (), this);

		public override string GenerateCSharp (int _indent) {
			if (DataType is AstType_String) {
				return Common.WrapStringValue (Value);
			} else {
				return Value;
			}
		}

		public override bool AllowAssign () => false;
	}
}

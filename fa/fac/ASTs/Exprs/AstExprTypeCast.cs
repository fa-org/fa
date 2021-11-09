using fac.AntlrTools;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	class AstExprTypeCast: IAstExpr {
		public IAstExpr Value { get; set; }



		private AstExprTypeCast () { }

		public static IAstExpr Make (IAstExpr _dest, string _to_type) {
			if (_dest.ExpectType == "") {
				throw new Exception ("应识别类型后做转换处理");
			} else if (_dest.ExpectType == _to_type || _to_type == "") {
				return _dest;
			} else if (TypeFuncs.AllowTypeCast (_dest.ExpectType, _to_type)) {
				return new AstExprTypeCast { Token = _dest.Token, ExpectType = _to_type, Value = _dest };
			} else {
				throw new CodeException (_dest.Token, $"类型 {_dest.ExpectType} 无法转为类型 {_to_type}");
			}
		}

		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) => Value = _cb (Value, _deep, _group);

		public override IAstExpr TraversalCalcType (string _expect_type) => throw new NotImplementedException ();

		public override string GuessType () => Value.GuessType ();

		public override string GenerateCSharp (int _indent) => Value.GenerateCSharp (_indent);
	}
}

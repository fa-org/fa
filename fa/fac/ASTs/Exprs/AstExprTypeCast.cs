using fac.AntlrTools;
using fac.ASTs.Exprs.Names;
using fac.ASTs.Types;
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

		public static IAstExpr Make (IAstExpr _dest, IAstType _to_type) {
			if (_dest.ExpectType == null) {
				if (_dest is AstExprName_BuildIn)
					return _dest;
				throw new Exception ("应识别类型后做转换处理");
			} else if (_dest.ExpectType == _to_type || _to_type == null) {
				return _dest;
			} else if (TypeFuncs.AllowTypeCast (_dest.ExpectType, _to_type) || (_dest.ExpectType is AstType_OptionalWrap _owrap && _owrap.ItemType.IsSame (_to_type))) {
				return new AstExprTypeCast { Token = _dest.Token, ExpectType = _to_type, Value = _dest };
			} else {
				throw new CodeException (_dest.Token, $"类型 {_dest.ExpectType} 无法转为类型 {_to_type}");
			}
		}

		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) => Value = _cb (Value, _deep, _group);

		public override IAstExpr TraversalCalcType (IAstType _expect_type) => throw new NotImplementedException ();

		public override IAstType GuessType () => Value.GuessType ();

		public override (string, string) GenerateCSharp (int _indent, string _cache_error_varname) {
			// TODO 着重处理
			var (_a, _b) = ExpectType.GenerateCSharp (_indent);
			var (_c, _d) = Value.GenerateCSharp (_indent);
			StringBuilder _psb = new StringBuilder ().Append ($"{_a}{_c}"), _sb = new StringBuilder ();
			if (ExpectType is AstType_OptionalWrap && Value.ExpectType is not AstType_OptionalWrap) {
				_sb.Append ($"{_b}.FromValue ({_d})");
			} else if (ExpectType is not AstType_OptionalWrap && Value.ExpectType is AstType_OptionalWrap) {
				_psb.AppendLine ();
			}
			return (_psb.ToString (), $"({_b}) {_d}");
		}

		public override bool AllowAssign () => false;
	}
}

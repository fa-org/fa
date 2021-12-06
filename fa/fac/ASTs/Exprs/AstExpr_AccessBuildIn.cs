using Antlr4.Runtime;
using fac.ASTs.Exprs.Names;
using fac.ASTs.Stmts;
using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	public enum AccessBuildInType { ARR_Length, ARR_Add, ARR_AccessItem, OPT_HasValue, OPT_GetValue, OPT_GetError, OPT_FromValue, OPT_FromError }
	public class AstExpr_AccessBuildIn: IAstExpr {
		public IAstExpr Value { get; set; } = null;
		public AccessBuildInType AccessType { get; set; }
		public List<IAstExpr> AttachArgs { get; set; } = null;



		private AstExpr_AccessBuildIn () { }
		public static IAstExpr Array_Length (IAstExpr _array) => new AstExpr_AccessBuildIn { Token = _array.Token, Value = _array, AccessType = AccessBuildInType.ARR_Length, ExpectType = IAstType.FromName ("int") };
		public static IAstExpr Array_Add (IAstExpr _array, IAstExpr _item) => new AstExpr_AccessBuildIn { Token = _array.Token, Value = _array, AccessType = AccessBuildInType.ARR_Add, AttachArgs = new List<IAstExpr> { _item } };
		public static IAstExpr Array_AccessItem (IAstExpr _array, IAstExpr _index) => new AstExpr_AccessBuildIn { Token = _array.Token, Value = _array, AccessType = AccessBuildInType.ARR_AccessItem, AttachArgs = new List<IAstExpr> { _index } };
		public static IAstExpr Optional_HasValue (IAstExpr _opt) => new AstExpr_AccessBuildIn { Token = _opt.Token, AccessType = AccessBuildInType.OPT_HasValue, Value = _opt, ExpectType = IAstType.FromName ("bool") };
		public static IAstExpr Optional_NotHasValue (IAstExpr _opt) => new AstExpr_Op1 { Token = _opt.Token, Value = Optional_HasValue (_opt), IsPrefix = true, Operator = "!", ExpectType = IAstType.FromName ("bool") };
		public static IAstExpr Optional_GetValue (IAstExpr _opt) => new AstExpr_AccessBuildIn { Token = _opt.Token, Value = _opt, AccessType = AccessBuildInType.OPT_GetValue, ExpectType = (_opt.ExpectType as AstType_OptionalWrap).ItemType };
		public static IAstExpr Optional_GetError (IAstExpr _opt) => new AstExpr_AccessBuildIn { Token = _opt.Token, Value = _opt, AccessType = AccessBuildInType.OPT_GetError, ExpectType = IAstType.FromName ("string") };
		public static IAstExpr Optional_FromValue (IAstExpr _opt) => new AstExpr_AccessBuildIn { Token = _opt.Token, AccessType = AccessBuildInType.OPT_FromValue, Value = _opt, ExpectType = new AstType_OptionalWrap { Token = _opt.Token, ItemType = _opt.ExpectType } };
		public static IAstExpr Optional_FromError (IAstType _opt_type, IAstExpr _err) => new AstExpr_AccessBuildIn { Token = _err.Token, AccessType = AccessBuildInType.OPT_FromError, ExpectType = _opt_type };

		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			if (Value != null)
				Value = _cb (Value, _deep, _group);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (Value != null)
				Value = Value.TraversalCalcType (null);
			if (ExpectType == null)
				throw new Exception ("此类需构造时指定类型");
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () {
			if (ExpectType == null)
				throw new Exception ("此类需构造时指定类型");
			return ExpectType;
		}

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos) _cache_err, Action<IAstExpr, IAstExpr> _check_cb) {
			var (_stmts, _value) = Value?.ExpandExpr (_cache_err, _check_cb) ?? (new List<IAstStmt> (), null);
			Value = _value;
			if (AttachArgs != null) {
				for (int i = 0; i < AttachArgs.Count; ++i) {
					var (_stmts1, _value1) = AttachArgs[i].ExpandExpr (_cache_err, _check_cb);
					_stmts.AddRange (_stmts1);
					AttachArgs[i] = _value1;
				}
			}
			return (_stmts, this);
		}

		public override string GenerateCSharp (int _indent) {
			var _b = Value?.GenerateCSharp (_indent) ?? "";
			return AccessType switch {
				AccessBuildInType.ARR_Length => $"{_b}.Count",
				AccessBuildInType.ARR_Add => $"{_b}.Add ({AttachArgs[0].GenerateCSharp (_indent)})",
				AccessBuildInType.ARR_AccessItem => $"{_b} [{AttachArgs[0].GenerateCSharp (_indent)}]",
				AccessBuildInType.OPT_HasValue => $"{_b}.HasValue ()",
				AccessBuildInType.OPT_GetValue => $"{_b}.GetValue ()",
				AccessBuildInType.OPT_GetError => $"{_b}.GetError ()",
				AccessBuildInType.OPT_FromValue => $"{ExpectType.GenerateCSharp (_indent)}.FromValue ({_b})",
				AccessBuildInType.OPT_FromError => $"{ExpectType.GenerateCSharp (_indent)}.FromError ({AttachArgs[0].GenerateCSharp (_indent)})",
				_ => throw new NotImplementedException (),
			};
		}

		public override bool AllowAssign () => false;
	}
}

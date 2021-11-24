using fac.ASTs.Exprs.Names;
using fac.ASTs.Types;
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

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if ((!IsPrefix) && Operator == "?") {
				Value = Value.TraversalCalcType (new AstType_OptionalWrap { Token = _expect_type?.Token ?? null, Mut = false, ItemType = _expect_type });
				// 方式1：保留当前类强转
				ExpectType = _expect_type;
				return this;
				// 方式2：切换为AstExprTypeCast类
				//return AstExprTypeCast.ForceMake (Value, _expect_type);
			} else {
				Value = Value.TraversalCalcType (_expect_type);
				ExpectType = Value.ExpectType;
				return AstExprTypeCast.Make (this, _expect_type);
			}
		}

		public override IAstType GuessType () {
			if (IsPrefix || Operator == "++" || Operator == "--") {
				return Value.GuessType ();
			} else if (Operator[0] == '.') {
				string _access_name = Operator[1..];
				if (Value is AstExprName_Class _cls) {
					var _expect = (from p in _cls.Class.ClassVars where p.Name == _access_name select p.DataType).FirstOrDefault ();
					if (_expect != null)
						return _expect;
					_expect = (from p in _cls.Class.ClassFuncs where p.Name == _access_name select p.FuncType).FirstOrDefault ();
					if (_expect != null)
						return _expect;
				}
			}
			throw new UnimplException (Token);
		}

		public override (string, string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb) {
			var (_a, _b, _c) = Value.GenerateCSharp (_indent, _check_cb);
			if ((!IsPrefix) && Operator == "?") {
				var _tmp_var_name = Common.GetTempId ();
				var _psb = new StringBuilder ();
				_psb.Append (_a).AppendLine ($"{_indent.Indent ()}{Value.ExpectType.GenerateCSharp_Type ()} {_tmp_var_name} = {_b};");
				_check_cb ($"!{_tmp_var_name}.HasValue ()", $"{_tmp_var_name}.GetError ()");
				return (_psb.ToString (), $"{_tmp_var_name}.GetValue ()", "");
			} else {
				_b = Value is IAstExprName ? _b : $"({_b})";
				return (_a, (IsPrefix ? $"{Operator}{_b}" : $"{_b}{Operator}"), _c);
			}
		}

		public override bool AllowAssign () => false;
	}
}

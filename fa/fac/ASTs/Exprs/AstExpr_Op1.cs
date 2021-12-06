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
	public class AstExpr_Op1: IAstExpr {
		public IAstExpr Value { get; set; }
		public string Operator { get; set; }
		public bool IsPrefix { get; set; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			Value = _cb (Value, _deep, _group);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if ((!IsPrefix) && Operator == "?") {
				if (_expect_type != null) {
					Value = Value.TraversalCalcType (new AstType_OptionalWrap { Token = Token, Mut = false, ItemType = _expect_type });
					ExpectType = _expect_type;
				} else {
					Value = Value.TraversalCalcType (null);
					if (Value.ExpectType is AstType_OptionalWrap _otype) {
						ExpectType = _otype.ItemType;
					} else {
						throw new CodeException (Token, "? 运算符只能用于可空类型的值的计算");
					}
				}
				return this;
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
			} else if (Operator == "?") {
				var _type = Value.GuessType ();
				if (_type is AstType_OptionalWrap _otype) {
					return _otype.ItemType;
				} else {
					return _type;
				}
			}
			throw new UnimplException (Token);
		}

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos) _cache_err, Action<IAstExpr, IAstExpr> _check_cb) {
			var (_stmts, _val) = Value.ExpandExpr (_cache_err, _check_cb);
			if ((!IsPrefix) && Operator == "?") {
				// 新增代码：如果前者为空那么 return
				// 返回 _val.GetValue ()
				_check_cb (AstExpr_AccessBuildIn.Optional_NotHasValue (_val), AstExpr_AccessBuildIn.Optional_GetError (_val));
				return (_stmts, AstExpr_AccessBuildIn.Optional_GetValue (_val));
			} else {
				// 直接访问
				Value = _val;
				return (_stmts, this);
			}
		}

		public override string GenerateCSharp (int _indent) {
			if ((!IsPrefix) && Operator == "?")
				throw new Exception ("不应执行此处代码");
			var _b = Value.GenerateCSharp (_indent);
			return IsPrefix ? $"{Operator}{_b}" : $"{_b}{Operator}";
		}

		public override bool AllowAssign () => Value.AllowAssign ();
	}
}

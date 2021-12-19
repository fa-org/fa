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



		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) {
			Value = Value.TraversalWrap (_trav);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			Value = Value.TraversalCalcType (_expect_type);
			ExpectType = Value.ExpectType;
			return AstExprTypeCast.Make (this, _expect_type);
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

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			var (_stmts, _val) = Value.ExpandExpr (_cache_err);
			Value = _val;
			return (_stmts, this);
		}

		public override string GenerateCSharp (int _indent) {
			if ((!IsPrefix) && Operator == "?")
				throw new Exception ("不应执行此处代码");
			var _b = Value.GenerateCSharp (_indent);
			return IsPrefix ? $"{Operator}{_b}" : $"{_b}{Operator}";
		}

		public override bool AllowAssign () => Value.AllowAssign ();

		public string GetIdRaw () {
			if (!IsPrefix) {
				if (Value is AstExpr_Op1 _op1_expr) {
					return $"{_op1_expr.GetIdRaw ()}{Operator}";
				} else if (Value is AstExpr_BaseId _bi_expr) {
					return $"{_bi_expr.Id}{Operator}";
				}
			}
			throw new CodeException (Token, "此对象非ID");
		}
	}
}

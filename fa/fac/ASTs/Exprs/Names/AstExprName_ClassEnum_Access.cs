using fac.ASTs.Stmts;
using fac.ASTs.Structs;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs.Names {
	public class AstExprName_ClassEnum_Access: IAstExprName {
		public IAstClass EnumClass { init; get; }
		public IAstExpr Value { get; set; }
		public int EnumItemIndex { init; get; }

		public AstClassVar AttachVar { get => EnumClass.ClassVars[EnumClass.GetRealAttachVarPos (EnumItemIndex)]; }



		private AstExprName_ClassEnum_Access () { }

		public static AstExprName_ClassEnum_Access FromSwitchCond (AstExprName_ClassEnum_New _new_expr) => new AstExprName_ClassEnum_Access { Token = _new_expr.Token, EnumClass = _new_expr.EnumClass, Value = null, EnumItemIndex = _new_expr.EnumItemIndex };

		public static AstExprName_ClassEnum_Access FromAccess (IAstExpr _opt, string _enum_name) {
			var _class = (_opt.ExpectType ?? _opt.GuessType ()).AstClass;
			int _p = _enum_name.LastIndexOf ('.');
			if (_p != -1) {
				string _clsname = _enum_name[.._p];
				if (_class.FullName == _clsname || _class.FullName.EndsWith ($".{_clsname}")) {
					_enum_name = _enum_name[(_p + 1)..];
				} else {
					throw new CodeException (_opt.Token, $"无法将 {_enum_name} 转为 {_class.FullName} 类型枚举值");
				}
			}
			var _enum_index = -1;
			for (int i = 0; i < _class.ClassEnumItems.Count; ++i) {
				if (_class.ClassEnumItems[i].Name == _enum_name) {
					if (_class.ClassEnumItems[i].AttachType == null)
						throw new CodeException (_opt.Token, $"枚举成员 {_class.FullName}.{_enum_name} 不附带参数，无法访问");
					_enum_index = i;
					break;
				}
			}
			var _access = new AstExprName_ClassEnum_Access { Token = _opt.Token, EnumClass = _class, Value = _opt, EnumItemIndex = _enum_index };
			_access.ExpectType = _access.AttachVar.DataType;
			return _access;
		}

		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) {
			if (Value != null)
				Value = Value.TraversalWrap (_trav);
		}

		public override IAstExpr TraversalCalcType (IAstType? _expect_type) {
			if (Value != null) {
				if (!Value.TraversalCalcTypeWrap (EnumClass.GetClassType (), a => Value = a))
					return null;
			}
			ExpectType = GuessType ();
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () => AttachVar.DataType;

		public override (List<IAstStmt>, IAstExpr) ExpandExprAssign (IAstExpr _rval, (IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			var (_stmts, _expr) = Value.ExpandExpr (_cache_err);
			_expr = new AstExpr_Op1 { Token = Token, Value = _expr, IsPrefix = false, Operator = $".{AttachVar.Name}", ExpectType = AttachVar.DataType };
			_stmts.Add (AstStmt_ExprWrap.MakeAssign (_expr, _rval));
			return (_stmts, _expr);
		}

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			var (_stmts, _expr) = Value.ExpandExpr (_cache_err);
			_expr = new AstExpr_Op1 { Token = Token, Value = _expr, IsPrefix = false, Operator = $".{AttachVar.Name}", ExpectType = AttachVar.DataType };
			return (_stmts, _expr);
		}

		public override string GenerateCSharp (int _indent) => throw new Exception ("不应执行此处代码");

		public override string GenerateCpp (int _indent) => throw new Exception ("不应执行此处代码");

		public override bool AllowAssign () => true;
	}
}

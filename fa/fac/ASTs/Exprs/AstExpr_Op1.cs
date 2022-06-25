using fac.ASTs.Exprs.Names;
using fac.ASTs.Stmts;
using fac.ASTs.Structs;
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



		public static AstExpr_Op1 Not (IAstExpr _bool) => new AstExpr_Op1 { Token = _bool.Token, Value = _bool, IsPrefix = true, Operator = "!", ExpectType = IAstType.FromName ("bool") };

		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) {
			Value = Value.TraversalWrap (_trav);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (!Value.TraversalCalcTypeWrap (_expect_type, a => Value = a))
				return null;
			ExpectType = Value.ExpectType;
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () {
			if (IsPrefix || Operator == "++" || Operator == "--") {
				return Value.GuessType ();
			} else if (Operator[0] == '.') {
				string _access_name = Operator[1..];
				if (Value is AstExprName_Class _cls_expr) {
					var _expect = (from p in _cls_expr.Class.ClassEnumItems where p.Name == _access_name select p.AttachType).FirstOrDefault ();
					if (_expect != null)
						return _expect;
					_expect = (from p in _cls_expr.Class.ClassVars where p.Name == _access_name select p.DataType).FirstOrDefault ();
					if (_expect != null)
						return _expect;
					_expect = (from p in _cls_expr.Class.ClassFuncs where p.Name == _access_name select p.FuncType).FirstOrDefault ();
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

		public override string GenerateCpp (int _indent) {
			if ((!IsPrefix) && Operator == "?")
				throw new Exception ("不应执行此处代码");
			var _b = Value.GenerateCpp (_indent);
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

		public IAstExpr TryParse () {
			if (IsPrefix || Operator[0] != '.')
				return this;
			string _access_name = Operator[1..];
			if (Value is AstExpr_BaseId _idexpr)
				Value = _idexpr.TryParse ();
			if (Value is AstExpr_BaseId _idexpr1) {
				string _name = $"{_idexpr1.Id}.{_access_name}";

				// 查找类名称
				var _nameexpr = IAstExprName.FindClass (Value.Token, _name);
				if (_nameexpr != null)
					return _nameexpr;

				// 查找预定义名称
				var _buildinexpr = AstExprName_BuildIn.FindFromName (_name);
				if (_buildinexpr != null)
					return _buildinexpr;

				// 合并冗余名称
				return new AstExpr_BaseId { Token = Value.Token, Id = _name };
			} else {
				// 访问类成员
				// 参数0为对象，当访问静态成员时传null
				// 参数1为类对象
				Func<IAstExpr, IAstClass, IAstExpr> _access_func = (_obj, _class) => {
					for (int i = 0; i < (_class.ClassEnumItems?.Count ?? 0); ++i) {
						if (_class.ClassEnumItems[i].Name == _access_name)
							return new AstExprName_ClassEnum_New { Token = Token, EnumClass = _class, EnumItemIndex = i, AttachExpr = null };
					}
					for (int i = 0; i < _class.ClassVars.Count; ++i) {
						if (_class.ClassVars[i].Name == _access_name)
							return new AstExprName_ClassVar { Token = Token, Class = _class, VariableIndex = i, ThisObject = _obj };
					}
					for (int i = 0; i < _class.ClassFuncs.Count; ++i) {
						if (_class.ClassFuncs[i].Name == _access_name)
							return new AstExprName_ClassFunc { Token = Token, Class = _class, FunctionIndex = i, ThisObject = _obj };
					}
					throw new CodeException (Token, $"类 {_class.FullName} 不存在成员 {_access_name}");
				};

				// 访问类成员
				// 参数0为对象，当访问静态成员时传null
				// 参数1为类名
				Func<IAstExpr, IAstType, IAstExpr> _access_func2 = (_obj, _typeexpr) => {
					return _typeexpr switch {
						AstType_Class _classexpr                        => _access_func (_obj, _classexpr.Class),
						AstType_ArrayWrap when _access_name == "Length" => AstExpr_ArrayAPI.Array_Length (_obj),
						AstType_String    when _access_name == "Length" => AstExpr_ArrayAPI.Array_Length (_obj),
						AstType_ArrayWrap                               => AstExpr_ArrayAPI_Temp.Array_MakeMethodAccess (_obj, _access_name),
						_ => throw new UnimplException (_typeexpr.Token),
					};
				};

				if (Value is AstExprName_Class _classexpr) {
					return _access_func (null, _classexpr.Class);
				} else if (Value is AstExprName_Argument _argexpr) {
					var _argtype = _argexpr.Func.Arguments[_argexpr.ArgumentIndex]._type;
					return _access_func2 (_argexpr, _argtype);
				} else if (Value is AstExprName_ClassVar _cvarexpr) {
					return _access_func (_cvarexpr, _cvarexpr.Class);
				} else if (Value is AstExprName_Variable _varexpr) {
					return _access_func2 (_varexpr, _varexpr.Var.DataType);
				}
			}
			return this;
		}
	}
}

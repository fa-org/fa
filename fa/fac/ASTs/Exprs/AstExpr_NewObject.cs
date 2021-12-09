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
	public class AstExpr_NewObject: IAstExpr {
		public AstType_Class DataType { get; set; }
		public List<IAstType> Variants { get; set; }
		public List<(string _name, IAstExpr _value)> InitialValues { get; set; } = null; // 结构体初值，当有值时ConstructorArguments为空
		public List<IAstExpr> ConstructorArguments { get; set; } = null;                 // 构造函数参数，当有值时InitialValues为空



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			for (int i = 0; i < InitialValues.Count; ++i)
				InitialValues[i] = (_name: InitialValues[i]._name, _value: _cb (InitialValues[i]._value, _deep, _group));
			for (int i = 0; i < ConstructorArguments.Count; ++i)
				ConstructorArguments[i] = _cb (ConstructorArguments[i], _deep, _group);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (DataType == null) {
				if (_expect_type == null || _expect_type is not AstType_Class)
					throw new CodeException (Token, "无法猜测对象类型");
				DataType = _expect_type as AstType_Class;
			}
			if (InitialValues != null) {
				var _default_init_vals = new List<(string _name, IAstExpr _value)> ();
				foreach (var _vars in DataType.Class.ClassVars) {
					int i = 0;
					for (; i < InitialValues.Count; ++i) {
						if (InitialValues[i]._name != _vars.Name)
							continue;
						InitialValues[i] = (_name: _vars.Name, _value: InitialValues[i]._value.TraversalCalcType (_vars.DataType));
						break;
					}
					if (i == InitialValues.Count) {
						if (_vars.DefaultValue == null)
							throw new CodeException (Token, $"未指定成员变量 {_vars.Name} 的初始值");
						_default_init_vals.Add ((_name: _vars.Name, _value: _vars.DefaultValue.TraversalCalcType (_vars.DataType)));
					}
				}
				InitialValues.AddRange (_default_init_vals);
			} else {
				// TODO 检查构造函数参数
				throw new UnimplException (Token);
			}
			ExpectType = DataType;
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () => DataType;

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos) _cache_err) {
			var _stmts = new List<IAstStmt> ();
			if (InitialValues != null) {
				for (int i = 0; i < InitialValues.Count; ++i) {
					var (_stmts1, _val1) = InitialValues[i]._value.ExpandExpr (_cache_err, _check_cb);
					_stmts.AddRange (_stmts1);
					InitialValues[i] = (InitialValues[i]._name, _val1);
				}
			}
			if (ConstructorArguments != null) {
				for (int i = 0; i < ConstructorArguments.Count; ++i) {
					var (_stmts1, _val1) = ConstructorArguments[i].ExpandExpr (_cache_err, _check_cb);
					_stmts.AddRange (_stmts1);
					ConstructorArguments[i] = _val1;
				}
			}
			return (_stmts, this);
		}

		public override string GenerateCSharp (int _indent) {
			StringBuilder _sb = new StringBuilder ();
			_sb.Append ($"new {DataType}");
			if (Variants.Count > 0)
				_sb.Append ('<').Append (string.Join (", ", from p in Variants select p.GenerateCSharp (_indent))).Append ('>');

			if (InitialValues != null) {
				_sb.Append ($" {{ ");
				foreach (var _init in InitialValues) {
					var _b = _init._value.GenerateCSharp (_indent);
					_sb.Append ($"{_init._name} = {_b}, ");
				}
				if (InitialValues.Any ())
					_sb.Remove (_sb.Length - 2, 2);
				_sb.Append ($" }}");
			} else {
				_sb.Append ($" (");
				foreach (var _arg in ConstructorArguments) {
					var _b = _arg.GenerateCSharp (_indent);
					_sb.Append ($"{_b}, ");
				}
				if (ConstructorArguments.Any ())
					_sb.Remove (_sb.Length - 2, 2);
				_sb.Append ($")");
			}
			return _sb.ToString ();
		}

		public override bool AllowAssign () => false;
	}
}

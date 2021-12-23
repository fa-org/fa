using Antlr4.Runtime;
using fac.ASTs.Exprs;
using fac.ASTs.Exprs.Names;
using fac.ASTs.Stmts;
using fac.ASTs.Structs;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	public abstract class IAstType: IAstExpr {
		public bool Mut { init; get; } = false;



		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) => throw new Exception ("不应执行此处代码");

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			ExpectType = null;
			return this;
		}

		public override IAstType GuessType () => throw new NotImplementedException ();

		public override bool AllowAssign () => false;

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) => throw new Exception ("不应执行此处代码");

		public static IAstType FromContext (FaParser.TypeContext _ctx) {
			if (_ctx.Params () != null) {
				if (_ctx.typeAfter ().Length == 0 || _ctx.typeAfter ()[^1].GetText () != "[]") {
					throw new CodeException (_ctx.Start, "错误的使用 params 标识");
				}
			}
			bool _mut = _ctx.Mut () != null;

			IAstType _ret = null;
			if (_ctx.typeSingle () != null) {
				// id<xxx>、id?
				string _type_str = _ctx.typeSingle ().ids ().GetText ();

				var _templates1 = FromContexts (_ctx.typeSingle ().type ());
				if ((_templates1?.Count ?? 0) == 0) {
					// 基本数据类型
					var _floattype = AstType_Float.FromType (_type_str, _mut, _ctx.Start);
					if (_floattype != null)
						_ret = _floattype;
					var _inttype = AstType_Integer.FromType (_type_str, _mut, _ctx.Start);
					if (_inttype != null)
						_ret = _inttype;
					if (_type_str == "var") {
						return null;
					} else if (_type_str == "any") {
						_ret = new AstType_Any { Token = _ctx.Start, Mut = _mut };
					} else if (_type_str == "bool") {
						_ret = new AstType_Bool { Token = _ctx.Start, Mut = _mut };
					} else if (_type_str == "string") {
						_ret = new AstType_String { Token = _ctx.Start, Mut = _mut };
					} else if (_type_str == "void") {
						_ret = new AstType_Void { Token = _ctx.Start, Mut = _mut };
					}
				} else {
					// 函数
					if (_type_str == "Func") {
						_ret = new AstType_Func { Token = _ctx.Start, Mut = _mut, ReturnType = _templates1[^1], ArgumentTypes = _templates1.Take (_templates1.Count - 1).ToList () };
					}
				}

				// 类
				if (_ret == null) {
					var _classes = Info.GetClassFromName (_type_str, _templates1);
					if (_classes.Count == 1) {
						_ret = AstType_Class.GetType (_ctx.Start, _classes[0], _mut);
					} else if (_classes.Count > 1) {
						throw new CodeException (_ctx.Start, $"不明确的符号 {_type_str}。可能为{string.Join ('、', from p in _classes select p.FullName)}");
					}
				}

				// 模板
				if (_ret == null && _type_str[0] == 'T') {
					if (Info.CurrentClass is AstTemplateClassInst _cls_inst) {
						_ret = _cls_inst.GetImplType (_type_str);
					} else if (Info.CurrentClass == null) {
						_ret = new AstType_Placeholder { Token = _ctx.Start, Mut = _mut, Name = _type_str };
					}
				}

				if (_ret == null)
					throw new CodeException (_ctx.Start, $"无法识别的类型 {_type_str}");
			} else if (_ctx.typeMulti () != null) {
				var _tuple_types = FromContexts (_ctx.typeMulti ().typeVar ());
				_ret = new AstType_Tuple { Token = _ctx.Start, Mut = _mut, TupleTypes = _tuple_types };
			} else {
				throw new UnimplException (_ctx.Start);
			}
			foreach (var _after_ctx in _ctx.typeAfter ()) {
				string _after = _after_ctx.GetText ();
				if (_after == "[]") {
					_ret = new AstType_ArrayWrap { Token = _after_ctx.Start, Mut = _mut, Params = false, ItemType = _ret };
				} else if (_after == "?") {
					_ret = _ret.Optional;
				} else {
					throw new UnimplException (_after_ctx.Start);
				}
			}
			if (_ctx.Params () != null)
				(_ret as AstType_ArrayWrap).Params = true;
			return _ret;
		}

		public static IAstType FromName (string _name) {
			if (sTypeNames.ContainsKey (_name))
				return sTypeNames[_name];
			var _type = Common.ParseCode<IAstType> (_name);
			sTypeNames.Add (_name, _type);
			return _type;
		}
		private static Dictionary<string, IAstType> sTypeNames = new Dictionary<string, IAstType> { [""] = null };

		public static List<IAstType> FromContexts (FaParser.TypeContext[] _ctxs) => (from p in _ctxs select FromContext (p)).ToList ();

		public static (IAstType _type, string _name) FromContext (FaParser.TypeVarContext _ctx) {
			return (_type: FromContext (_ctx.type ()), _ctx.id () != null ? _ctx.id ().GetText () : "");
		}

		public static List<(IAstType _type, string _name)> FromContexts (FaParser.TypeVarContext[] _ctxs) {
			var _list = new List<(IAstType _type, string _name)> ();
			for (int i = 0; i < _ctxs.Length; ++i) {
				var _type = FromContext (_ctxs[i].type ());
				var _name = _ctxs[i].id ()?.GetText () ?? "";
				if (_name == "") {
					_name = $"Item{i}";
				} else if (_name.StartsWith ("Item")) {
					if (int.TryParse (_name[4..], out int n)) {
						if (n != i)
							throw new CodeException (_ctxs[i].id ().Start, $"此位置无法使用 {_name} 作为命名元组的项名称");
					}
				}
			}
			return _list;
		}

		public bool IsSame (IAstType _other) {
			if (_other == null)
				return false;
			return this switch {
				AstType_ArrayWrap _arrtype1 when _other is AstType_ArrayWrap _arrtype2 => _arrtype1.ItemType.IsSame (_arrtype2.ItemType),
				AstType_Bool when _other is AstType_Bool => true,
				AstType_Class _clstype1 when _other is AstType_Class _clstype2 => _clstype1.Class.FullName == _clstype2.Class.FullName,
				AstType_Float _ftype1 when _other is AstType_Float _ftype2 => _ftype1.BitWidth == _ftype2.BitWidth,
				AstType_Func _functype1 when _other is AstType_Func _functype2 => new Func<bool> (() => {
					if (_functype1.ArgumentTypes.Count != _functype2.ArgumentTypes.Count)
						return false;
					if ((from _p in _functype1.ArgumentTypes.Zip (_functype2.ArgumentTypes) where !_p.First.IsSame (_p.Second) select 1).Any ())
						return false;
					return _functype1.ReturnType.IsSame (_functype2.ReturnType);
				}).Invoke (),
				AstType_Integer _inttype1 when _other is AstType_Integer _inttype2 => _inttype1.BitWidth == _inttype2.BitWidth,
				AstType_OptionalWrap _otype1 when _other is AstType_OptionalWrap _otype2 => _otype1.ItemType.IsSame (_otype2.ItemType),
				AstType_Placeholder _ptype1 when _other is AstType_Placeholder _ptype2 => _ptype1.Name == _ptype2.Name,
				AstType_String when _other is AstType_String => true,
				AstType_Tuple _tptype1 when _other is AstType_Tuple _tptype2 => new Func<bool> (() => {
					if (_tptype1.TupleTypes.Count != _tptype2.TupleTypes.Count)
						return false;
					return !(from _p in _tptype1.TupleTypes.Zip (_tptype2.TupleTypes) where !_p.First._type.IsSame (_p.Second._type) select 1).Any ();
				}).Invoke (),
				AstType_Void when _other is AstType_Void => true,
				_ => false,
			};
		}

		public AstType_OptionalWrap Optional { get => this is AstType_OptionalWrap _owrap ? _owrap : new AstType_OptionalWrap { Token = Token, ItemType = this, Mut = Mut }; }
	}
}

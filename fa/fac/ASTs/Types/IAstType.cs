using Antlr4.Runtime;
using fac.ASTs.Exprs;
using fac.ASTs.Exprs.Names;
using fac.ASTs.Stmts;
using fac.ASTs.Structs;
using fac.ASTs.Types.Mappings;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	public abstract class IAstType: IAstExpr {
		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) => throw new Exception ("不应执行此处代码");

		public override IAstExpr TraversalCalcType (IAstType? _expect_type) {
			ExpectType = null;
			return this;
		}

		public override IAstType GuessType () => throw new NotImplementedException ();

		public override bool AllowAssign () => false;

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) => throw new Exception ("不应执行此处代码");

		public static IAstType FromContext (FaParser.TypeContext _ctx) {
			IAstType _ret = null;
			if (_ctx.typeSingle () != null) {
				_ret = FromContext (_ctx.typeSingle ());
			} else if (_ctx.typeMulti () != null) {
				var _tuple_types = FromContexts (_ctx.typeMulti ().typeVar ());
				_ret = new AstType_Tuple { Token = _ctx.Start, TupleTypes = _tuple_types };
			} else {
				throw new UnimplException (_ctx.Start);
			}
			foreach (var _after_ctx in _ctx.typeAfter ()) {
				string _after = _after_ctx.GetText ();
				if (_after == "[]") {
					_ret = new AstType_ArrayWrap { Token = _after_ctx.Start, ItemType = _ret };
				} else if (_after == "?") {
					_ret = _ret.Optional;
				} else {
					throw new UnimplException (_after_ctx.Start);
				}
			}
			return _ret;
		}

		public static IAstType FromContext (FaParser.TypeSingleContext _ctx) {
			IAstType _ret = null;
			// id<xxx>、id?
			string _type_str = _ctx.ids ().GetText ();

			var _templates1 = FromContexts (_ctx.typeWrap ());
			if ((_templates1?.Count ?? 0) == 0) {
				// 基本数据类型
				var _floattype = AstType_Float.FromType (_type_str, _ctx.Start);
				if (_floattype != null)
					_ret = _floattype;
				var _inttype = AstType_Integer.FromType (_type_str, _ctx.Start);
				if (_inttype != null)
					_ret = _inttype;
				if (_type_str == "var") {
					return null;
				} else if (_type_str == "any") {
					_ret = new AstType_Any { Token = _ctx.Start };
				} else if (_type_str == "bool") {
					_ret = new AstType_Bool { Token = _ctx.Start };
				} else if (_type_str == "string") {
					_ret = new AstType_String { Token = _ctx.Start };
				} else if (_type_str == "void") {
					_ret = new AstType_Void { Token = _ctx.Start };
				}
			} else {
				// 函数
				if (_type_str == "Func") {
					for (int i = 0; i < _templates1.Count; ++i) {
						if (i == _templates1.Count - 1) {
							if (_templates1 [i]._ext != ArgumentTypeExt.None)
								throw new CodeException (_ctx.Start, $"附加类型错误");
						} else if (i < _templates1.Count - 2) {
							if (_templates1[i]._ext == ArgumentTypeExt.Params)
								throw new CodeException (_ctx.Start, $"附加类型错误");
						}
					}
					_ret = new AstType_Func { Token = _ctx.Start, ReturnType = _templates1[^1]._type, ArgumentTypes = _templates1.Take (_templates1.Count - 1).ToList () };
				} else {
					if ((from p in _templates1 where p._ext != ArgumentTypeExt.None select 1).Any ())
						throw new CodeException (_ctx.Start, $"附加类型错误");
				}

				// 字典
				if (_type_str == "Dictionary") {
					_ret = new AstTypeMap_Dictionary { Token = _ctx.Start, KeyType = _templates1[0]._type, ValueType = _templates1[1]._type };
				}
			}

			// 类
			if (_ret == null) {
				var _templates = _templates1 != null ? (from p in _templates1 select p._type).ToList () : null;
				var _classes = Info.GetClassFromName (_type_str, _templates);
				if (_classes.Count == 1) {
					_ret = AstType_Class.GetType (_ctx.Start, _classes[0]);
				} else if (_classes.Count > 1) {
					throw new CodeException (_ctx.Start, $"不明确的符号 {_type_str}。可能为{string.Join ('、', from p in _classes select p.FullName)}");
				}
			}

			// 模板
			if (_ret == null && _type_str[0] == 'T') {
				if (Info.CurrentClass is AstTemplateClassInst _cls_inst) {
					_ret = _cls_inst.GetImplType (_type_str);
				} else if (Info.CurrentClass is AstTemplateEnumInst _enum_inst) {
					_ret = _enum_inst.GetImplType (_type_str);
				} else {
					_ret = new AstType_Placeholder { Token = _ctx.Start, Name = _type_str };
				}
			}

			if (_ret == null)
				throw new CodeException (_ctx.Start, $"无法识别的类型 {_type_str}");
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
				_list.Add ((_type, _name));
			}
			return _list;
		}

		public static List<(IAstType _type, ArgumentTypeExt _ext)> FromContexts (FaParser.TypeWrapContext[] _ctxs) => (from p in _ctxs
			let _type = FromContext (p.type ())
			let _ext = p.Mut () != null ? ArgumentTypeExt.Mut : (p.Params () != null ? ArgumentTypeExt.Params : ArgumentTypeExt.None)
			select (_type: _type, _ext: _ext)).ToList ();

		public static (IAstType _type, ArgumentTypeExt _ext, string _name) FromContext (FaParser.TypeWrapVar1Context _ctx) {
			var _wrap = _ctx.typeWrap ();
			var _ext = _wrap.Mut () != null ? ArgumentTypeExt.Mut : (_wrap.Params () != null ? ArgumentTypeExt.Params : ArgumentTypeExt.None);
			return (_type: FromContext (_wrap.type ()), _ext: _ext, _name: _ctx.id () != null ? _ctx.id ().GetText () : "");
		}

		public static (IAstType _type, ArgumentTypeExt _ext, string _name) FromContext (FaParser.TypeWrapVar2Context _ctx) {
			var _wrap = _ctx.typeWrap ();
			var _ext = _wrap.Mut () != null ? ArgumentTypeExt.Mut : (_wrap.Params () != null ? ArgumentTypeExt.Params : ArgumentTypeExt.None);
			return (_type: FromContext (_wrap.type ()), _ext: _ext, _name: _ctx.id () != null ? _ctx.id ().GetText () : "");
		}

		public static (IAstType _type, ArgumentTypeExt _ext, string _name) FromContext (FaParser.TypeWrapVar3Context _ctx) {
			var _wrap = _ctx.typeWrap ();
			var _ext = _wrap.Mut () != null ? ArgumentTypeExt.Mut : (_wrap.Params () != null ? ArgumentTypeExt.Params : ArgumentTypeExt.None);
			return (_type: FromContext (_wrap.type ()), _ext: _ext, _name: _ctx.id () != null ? _ctx.id ().GetText () : "");
		}

		public static List<(IAstType _type, ArgumentTypeExt _ext, string _name)> FromContexts (FaParser.TypeWrapVar1Context[] _ctxs) {
			var _list = new List<(IAstType _type, ArgumentTypeExt _ext, string _name)> ();
			for (int i = 0; i < _ctxs.Length; ++i) {
				var _wrap = _ctxs[i].typeWrap ();
				var _type = FromContext (_wrap.type ());
				var _ext = _wrap.Mut () != null ? ArgumentTypeExt.Mut : (_wrap.Params () != null ? ArgumentTypeExt.Params : ArgumentTypeExt.None);
				var _name = _ctxs[i].id ()?.GetText () ?? "";
				if (_name == "") {
					_name = $"Item{i}";
				} else if (_name.StartsWith ("Item")) {
					if (int.TryParse (_name[4..], out int n)) {
						if (n != i)
							throw new CodeException (_ctxs[i].id ().Start, $"此位置无法使用 {_name} 作为命名元组的项名称");
					}
				}
				_list.Add ((_type, _ext, _name));
			}
			return _list;
		}

		public static List<(IAstType _type, ArgumentTypeExt _ext, string _name)> FromContexts (FaParser.TypeWrapVar2Context[] _ctxs) {
			var _list = new List<(IAstType _type, ArgumentTypeExt _ext, string _name)> ();
			for (int i = 0; i < _ctxs.Length; ++i) {
				var _wrap = _ctxs[i].typeWrap ();
				var _type = FromContext (_wrap.type ());
				var _ext = _wrap.Mut () != null ? ArgumentTypeExt.Mut : (_wrap.Params () != null ? ArgumentTypeExt.Params : ArgumentTypeExt.None);
				var _name = _ctxs[i].id ()?.GetText () ?? "";
				if (_name == "") {
					_name = $"Item{i}";
				} else if (_name.StartsWith ("Item")) {
					if (int.TryParse (_name[4..], out int n)) {
						if (n != i)
							throw new CodeException (_ctxs[i].id ().Start, $"此位置无法使用 {_name} 作为命名元组的项名称");
					}
				}
				_list.Add ((_type, _ext, _name));
			}
			return _list;
		}

		public static List<(IAstType _type, ArgumentTypeExt _ext, string _name)> FromContexts (FaParser.TypeWrapVar3Context[] _ctxs) {
			var _list = new List<(IAstType _type, ArgumentTypeExt _ext, string _name)> ();
			for (int i = 0; i < _ctxs.Length; ++i) {
				var _wrap = _ctxs[i].typeWrap ();
				var _type = FromContext (_wrap.type ());
				var _ext = _wrap.Mut () != null ? ArgumentTypeExt.Mut : (_wrap.Params () != null ? ArgumentTypeExt.Params : ArgumentTypeExt.None);
				var _name = _ctxs[i].id ()?.GetText () ?? "";
				if (_name == "") {
					_name = $"Item{i}";
				} else if (_name.StartsWith ("Item")) {
					if (int.TryParse (_name[4..], out int n)) {
						if (n != i)
							throw new CodeException (_ctxs[i].id ().Start, $"此位置无法使用 {_name} 作为命名元组的项名称");
					}
				}
				_list.Add ((_type, _ext, _name));
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
					if ((from _p in _functype1.ArgumentTypes.Zip (_functype2.ArgumentTypes) where !(_p.First._type.IsSame (_p.Second._type) && _p.First._ext == _p.Second._ext) select 1).Any ())
						return false;
					return _functype1.ReturnType.IsSame (_functype2.ReturnType);
				}).Invoke (),
				AstType_Integer _inttype1 when _other is AstType_Integer _inttype2 => _inttype1.BitWidth == _inttype2.BitWidth,
				AstType_Placeholder _ptype1 when _other is AstType_Placeholder _ptype2 => _ptype1.Name == _ptype2.Name,
				AstType_String when _other is AstType_String => true,
				AstType_Tuple _tptype1 when _other is AstType_Tuple _tptype2 => new Func<bool> (() => {
					if (_tptype1.TupleTypes.Count != _tptype2.TupleTypes.Count)
						return false;
					return !(from _p in _tptype1.TupleTypes.Zip (_tptype2.TupleTypes) where !_p.First._type.IsSame (_p.Second._type) select 1).Any ();
				}).Invoke (),
				AstType_Void when _other is AstType_Void => true,
				AstType_TempType _ttype1 when _other is AstType_TempType _ttype2 => _ttype1.Name == _ttype2.Name && _ttype1.TypeRaw == _ttype2.TypeRaw,
				AstTypeMap_Dictionary _dictype1 when _other is AstTypeMap_Dictionary _dictype2 => _dictype1.KeyType.IsSame (_dictype2.KeyType) && _dictype1.ValueType.IsSame (_dictype2.ValueType),
				_ => false,
			};
		}

		public bool IsOptional { get => this is AstType_Class _class && _class.Class.FullName.StartsWith ("fa.Optional"); }

		public IAstType Optional { get => this is AstType_OptionalWrap ? this : new AstType_OptionalWrap { ItemType = this }; }

		public IAstType UnwrapOptional {
			get {
				if (this is AstType_Class _class) {
					string _name = _class.Class.FullName;
					return _name switch {
						"fa.OptionalVoid" => IAstType.FromName ("void"),
						_ when _name.StartsWith ("fa.Optional<") => IAstType.FromName (_name[12..^1]),
						_ => this,
					};
				} else {
					return this;
				}
			}
		}

		public IAstClass AstClass { get => this is AstType_Class _class ? _class.Class : null; }
	}
}

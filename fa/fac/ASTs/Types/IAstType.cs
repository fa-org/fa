using Antlr4.Runtime;
using fac.ASTs.Exprs;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	abstract class IAstType: IAstExpr {
		//public string TypeStr { init; get; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) { }

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			ExpectType = null;
			return this;
		}

		public override IAstType GuessType () => throw new NotImplementedException ();

		public override bool AllowAssign () => false;

		public static IAstType FromContext (FaParser.TypeContext _ctx) {
			IAstType _ret = null;
			if (_ctx.typeSingle () != null) {
				// Id<xxx>、Id?
				string _type_str = _ctx.typeSingle ().Id ().GetText ();
				var _templates1 = FromContexts (_ctx.typeSingle ().type ());
				if ((_templates1?.Count ?? 0) == 0) {
					var _floattype = AstType_Float.FromType (_type_str, _ctx.Start);
					if (_floattype != null)
						_ret = _floattype;
					//
					//
					var _inttype = AstType_Integer.FromType (_type_str, _ctx.Start);
					if (_inttype != null)
						_ret = _inttype;
					//
					if (_type_str == "string")
						_ret = new AstType_String { Token = _ctx.Start };
					//
					if (_type_str == "void")
						_ret = new AstType_Void { Token = _ctx.Start };
				}
				var _classes = Info.GetClassFromName (_type_str);
				if (_classes.Count == 1) {
					_ret = new AstType_Class { Token = _ctx.Start, Class = _classes[0], TemplateTypes = _templates1 };
				} else if (_classes.Count > 1) {
					throw new CodeException (_ctx.Start, $"不明确的符号 {_type_str}。可能为{string.Join ('、', from p in _classes select p.FullName)}");
				}
				if (_ret == null)
					throw new CodeException (_ctx.Start, $"无法识别的类型 {_type_str}");
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
					_ret = new AstType_OptionalWrap { Token = _after_ctx.Start, ItemType = _ret };
				} else {
					throw new UnimplException (_after_ctx.Start);
				}
			}
			return _ret;
		}

		public static IAstType FromName (string _name) => Common.ParseCode<IAstType> (_name);
			//IAstType _ret = null;
			//string _type_ext = "";
			//foreach (var _ch in _name.Reverse ()) {
			//	if (_ch == '[' || _ch == ']' || _ch == '?') {
			//		_type_ext = $"{_ch}{_type_ext}";
			//	} else {
			//		break;
			//	}
			//}
			//_name = _name[..^_type_ext.Length];
			//if (_name[0] != '(') {
			//	int _p = _name.IndexOf ('<');
			//	var _templates1 = new List<IAstType> ();
			//	if (_p >= 0) {
			//		string _check = _name[(_p+1)..];
			//		_name = _name[.._p];
			//		while (_check.Length > 0) {
			//			int i = _p = 0;
			//			for (; i < _check.Length; ++i) {
			//				if (_check[i] == '(' || _check[i] == '[' || _check[i] == '<' || _check[i] == '{') {
			//					_p++;
			//				} else if (_check[i] == ')' || _check[i] == ']' || _check[i] == '>' || _check[i] == '}') {
			//					_p--;
			//				} else if (_check[i] == ',' && _p == 0) {
			//					break;
			//				}
			//			}
			//			_templates1.Add (FromName (_check[..i]));
			//			_check = (i < _check.Length) ? _check[(i + 1)..] : "";
			//		}
			//	}
			//	if (_templates1.Count == 0) {
			//		var _floattype = AstType_Float.FromType (_name, null);
			//		if (_floattype != null)
			//			_ret = _floattype;
			//		//
			//		var _inttype = AstType_Integer.FromType (_name, null);
			//		if (_inttype != null)
			//			_ret = _inttype;
			//		//
			//		if (_name == "string")
			//			_ret = new AstType_String { Token = null, TypeStr = _name };
			//		//
			//		if (_name == "void")
			//			_ret = new AstType_Void { Token = null, TypeStr = _name };
			//	}
			//	var _classes = Info.GetClassFromName (_name);
			//	if (_classes.Count == 1) {
			//		_name = _templates1.Any () ? $"{_classes[0].FullName}<{string.Join (", ", from p in _templates1 select p.TypeStr)}>" : _classes[0].FullName;
			//		_ret = new AstType_Class { Token = null, TypeStr = _name, Class = _classes[0], TemplateTypes = _templates1 };
			//	} else if (_classes.Count > 1) {
			//		throw new CodeException ((IToken) null, $"不明确的符号 {_name}。可能为{string.Join ('、', from p in _classes select p.FullName)}");
			//	}
			//	if (_ret == null)
			//		throw new CodeException ((IToken) null, $"无法识别的类型 {_name}");
			//} else {
			//	_name = _name[1..^1];
			//}

		public static List<IAstType> FromContexts (FaParser.TypeContext[] _ctxs) => (from p in _ctxs select FromContext (p)).ToList ();

		public static (IAstType _type, string _name) FromContext (FaParser.TypeVarContext _ctx) {
			return (_type: FromContext (_ctx.type ()), _ctx.Id () != null ? _ctx.Id ().GetText () : "");
		}

		public static List<(IAstType _type, string _name)> FromContexts (FaParser.TypeVarContext[] _ctxs) {
			var _list = new List<(IAstType _type, string _name)> ();
			for (int i = 0; i < _ctxs.Length; ++i) {
				var _type = FromContext (_ctxs[i].type ());
				var _name = _ctxs[i].Id ()?.GetText () ?? "";
				if (_name == "") {
					_name = $"Item{i}";
				} else if (_name.StartsWith ("Item")) {
					if (int.TryParse (_name[4..], out int n)) {
						if (n != i)
							throw new CodeException (_ctxs[i].Id ().Symbol, $"此位置无法使用 {_name} 作为命名元组的项名称");
					}
				}
			}
			return _list;
		}

		public bool IsSame (IAstType _other) {
			return this switch {
				AstType_ArrayWrap _arrtype1 when _other is AstType_ArrayWrap _arrtype2 => _arrtype1.ItemType.IsSame (_arrtype2.ItemType),
				AstType_Class _clstype1 when _other is AstType_Class _clstype2 => _clstype1.Class.FullName == _clstype2.Class.FullName,
				AstType_Float _ftype1 when _other is AstType_Float _ftype2 => _ftype1.BitWidth == _ftype2.BitWidth,
				AstType_Func _functype1 when _other is AstType_Func _functype2 => new Func<bool> (() => {
					if (_functype1.ArgumentTypes.Count != _functype2.ArgumentTypes.Count)
						return false;
					if ((from _p in _functype1.ArgumentTypes.Zip (_functype2.ArgumentTypes) where !_p.First.IsSame (_p.Second) select 1).Any ())
						return false;
					return _functype1.ReturnType == _functype2.ReturnType;
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
	}
}

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

		}
	}
}

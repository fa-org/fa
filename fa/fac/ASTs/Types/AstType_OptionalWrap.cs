using Antlr4.Runtime;
using fac.ASTs.Structs;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	// c艹用的
	public class AstType_OptionalWrap: IAstType {
		public IAstType ItemType { init; get; }

		public override string GenerateCSharp (int _indent) => throw new NotImplementedException ();

		public override string GenerateCpp (int _indent) {
			if (ItemType is AstType_Void) {
				return "std::optional<fa::Error>";
			} else {
				return $"std::variant<{ItemType.GenerateCpp (_indent)}, fa::Error>";
			}
		}
	}



	// c#用的
	//public class AstType_OptionalWrap {
	//	public IAstType ItemType { init; get; }
	//	public IAstClass Class { get => BaseClass.GetInst (new List<IAstType> { ItemType }); }



	//	private static IAstClass _ErrorClass = null;
	//	public static IAstClass ErrorClass {
	//		get {
	//			if (_ErrorClass == null) {
	//				var _classes = Info.GetTemplateClassFromName ("fa.Error", 0);
	//				if (_classes.Count == 0) {
	//					throw new NotImplementedException ();
	//				} else if (_classes.Count > 1) {
	//					throw new CodeException ((IToken) null, $"不允许定义 fa.Error 类型");
	//				}
	//				_ErrorClass = _classes[0];
	//			}
	//			return _ErrorClass;
	//		}
	//	}

	//	private static IAstClass _BaseClass = null;
	//	public static IAstClass BaseClass {
	//		get {
	//			if (_BaseClass == null) {
	//				var _classes = Info.GetTemplateClassFromName ("fa.Optional", 1);
	//				if (_classes.Count == 0) {
	//					throw new NotImplementedException ();
	//				} else if (_classes.Count > 1) {
	//					throw new CodeException ((IToken) null, $"不允许定义 fa.Optional 类型");
	//				}
	//				_BaseClass = _classes[0];
	//			}
	//			return _BaseClass;
	//		}
	//	}

	//	private static IAstClass _VoidClass = null;
	//	public static IAstClass VoidClass {
	//		get {
	//			if (_VoidClass == null) {
	//				var _classes = Info.GetTemplateClassFromName ("fa.OptionalVoid", 0);
	//				if (_classes.Count == 0) {
	//					throw new NotImplementedException ();
	//				} else if (_classes.Count > 1) {
	//					throw new CodeException ((IToken) null, $"不允许定义 fa.OptionalVoid 类型");
	//				}
	//				_VoidClass = _classes[0];
	//			}
	//			return _VoidClass;
	//		}
	//	}

	//	//public static AstType_OptionalWrap VoidType { get => new AstType_OptionalWrap (null, new AstType_Void { }, true); }



	//	private AstType_OptionalWrap () => throw new Exception ("不要使用这个类");

	//	public static IAstClass GetInstClass (IAstType _type) => BaseClass.GetInst (new List<IAstType> { _type });





	//	//public AstType_OptionalWrap (IToken _token, IAstType _item_type) {
	//	//	Token = _token;
	//	//	ItemType = _item_type;
	//	//	Mut = _item_type.Mut;
	//	//	BaseClass.GetInst (new List<IAstType> { _item_type });
	//	//}

	//	//public override string ToString () => $"{ItemType}?";

	//	//public override string GenerateCSharp (int _indent) => ItemType is AstType_Void ? "fa.OptionalVoid" : $"fa.Optional__lt__{ItemType}__gt__";
	//}
}

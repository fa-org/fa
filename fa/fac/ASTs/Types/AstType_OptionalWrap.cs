using Antlr4.Runtime;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	public class AstType_OptionalWrap: IAstType {
		public IAstType ItemType { init; get; }
		public IAstClass Class { get => BaseClass.GetInst (new List<IAstType> { ItemType }); }



		private static IAstClass _ErrorClass = null;
		public static IAstClass ErrorClass {
			get {
				if (_ErrorClass == null) {
					var _classes = Info.GetTemplateClassFromName ("fa.Error", 0);
					if (_classes.Count == 0) {
						throw new NotImplementedException ();
					} else if (_classes.Count > 1) {
						throw new CodeException ((IToken) null, $"不允许定义 fa.Error 类型");
					}
					_ErrorClass = _classes[0];
				}
				return _ErrorClass;
			}
		}

		private static IAstClass _BaseClass = null;
		public static IAstClass BaseClass {
			get {
				if (_BaseClass == null) {
					var _classes = Info.GetTemplateClassFromName ("fa.Optional", 1);
					if (_classes.Count == 0) {
						throw new NotImplementedException ();
					} else if (_classes.Count > 1) {
						throw new CodeException ((IToken) null, $"不允许定义 fa.Optional 类型");
					}
					_BaseClass = _classes[0];
				}
				return _BaseClass;
			}
		}



		public AstType_OptionalWrap (IToken _token, IAstType _item_type, bool _mut) {
			Token = _token;
			ItemType = _item_type;
			Mut = _mut;
			BaseClass.GetInst (new List<IAstType> { _item_type });
		}

		public override string ToString () => $"{ItemType}?";

		public override string GenerateCSharp (int _indent) => ItemType is AstType_Void ? "fa.OptionalVoid" : $"fa.Optional__lt__{ItemType}__gt__";
	}
}

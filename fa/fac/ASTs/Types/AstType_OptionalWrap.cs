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



		private static IAstClass s_optional = null;
		public AstType_OptionalWrap (IToken _token, IAstType _item_type, bool _mut) {
			Token = _token;
			ItemType = _item_type;
			Mut = _mut;
			if (s_optional == null) {
				var _classes = Info.GetTemplateClassFromName ("fa.Optional", 1);
				if (_classes.Count == 0) {
					throw new NotImplementedException ();
				} else if (_classes.Count > 1) {
					throw new CodeException (_token, $"不允许定义 fa.Optional 类型");
				}
				s_optional = _classes[0];
			}
			s_optional.GetInst (new List<IAstType> { _item_type });
		}

		public override string ToString () => $"{ItemType}?";

		public override string GenerateCSharp (int _indent) => $"fa.Optional__lt__{(ItemType is AstType_Void ? "int32" : ItemType)}__gt__";
	}
}

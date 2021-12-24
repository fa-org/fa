using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	public class AstType_TempType: IAstType {
		public string Name { get; set; } = "";
		public FaParser.TypeContext TypeRaw { get; set; } = null;



		public AstType_TempType (string _name) => Name = _name;
		public AstType_TempType (FaParser.TypeContext _type_raw) {
			if (_type_raw == null)
				throw new NotImplementedException ();
			TypeRaw = _type_raw;
		}
		public IAstType GetRealType () {
			if (TypeRaw != null) {
				return IAstType.FromContext (TypeRaw);
			} else {
				return IAstType.FromName (Name);
			}
		}
		public override string ToString () => Name;
		public override string GenerateCSharp (int _indent) => throw new NotImplementedException ();
	}
}

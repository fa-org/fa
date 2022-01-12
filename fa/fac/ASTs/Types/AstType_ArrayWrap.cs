using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	public class AstType_ArrayWrap: IAstType {
		public IAstType ItemType { init; get; }



		public override string ToString () => $"{ItemType}[]";
		public override string GenerateCSharp (int _indent) => $"List<{ItemType.GenerateCSharp (_indent)}>";
	}
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Types {
	public class AstType_TempType: IAstType {
#warning TODO: 初始化类型全部设置为此类型
		public string Name { get; set; }



		public override string ToString () => Name;
		public override string GenerateCSharp (int _indent) => throw new NotImplementedException ();
	}
}

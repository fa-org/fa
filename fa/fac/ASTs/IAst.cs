using Antlr4.Runtime;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs {
	public abstract class IAst {
		public IToken Token { init; get; } = null;

		/// <summary>
		/// 生成C#代码
		/// </summary>
		/// <param name="_indent">缩进，1代表4个空格，2代表8个空格，以此类推</param>
		/// <returns>C#代码</returns>
		public abstract string GenerateCSharp (int _indent);

		/// <summary>
		/// 生成C++代码
		/// </summary>
		/// <param name="_indent">缩进，1代表4个空格，2代表8个空格，以此类推</param>
		/// <returns>C#代码</returns>
		public abstract string GenerateCpp (int _indent);
	}
}

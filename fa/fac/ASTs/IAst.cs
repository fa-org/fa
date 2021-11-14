using Antlr4.Runtime;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs {
	abstract class IAst {
		public IToken Token { init; get; } = null;

		/// <summary>
		/// 生成C#代码
		/// </summary>
		/// <param name="_indent">缩进，1代表4个空格，2代表8个空格，以此类推</param>
		/// <param name="_cache_error_varname">缓存错误的变量名，为空则返回错误，如果返回类型不允许错误则抛异常</param>
		/// <returns>
		/// 第一个变量不为空则代表需提前植入的C#代码。示例：fa.Optional<string> s = fa.Optional<string>.FromError ("变量未初始化");
		/// 第二个变量不为空则代表执行当前行所需条件。示例：s.HasValue ()
		/// 第三个变量代表当前语句。示例：s.GetValue ()
		/// </returns>
		public abstract (string, string, string) GenerateCSharp (int _indent, string _cache_error_varname);
	}
}

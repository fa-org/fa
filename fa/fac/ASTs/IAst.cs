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
		/// <param name="_check_cb">条件及错误内容回调，有调用则代表当前代码必须不满足指定条件</param>
		/// <returns>
		/// 第一个变量不为空则代表需提前植入的C#代码。示例：fa.Optional<string> s = fa.Optional<string>.FromError ("变量未初始化");
		/// 第二个变量代表当前语句。示例：s.GetValue ()
		/// 第三个变量代表需延后植入的C#代码
		/// </returns>
		public abstract (string, string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb);
	}
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.AntlrTools {
	public class Operators {
		/// <summary>
		/// 运算符优先级列表，小代表高优先级
		/// </summary>
		public static Dictionary<string, int> Op2Priority = new Dictionary<string, int> {
			{ ".", 0 },
			{ "**", 1 },
			{ "*", 2 }, { "/", 2 }, { "%", 2 },
			{ "+", 3 }, { "-", 3 },
			{ "<<", 4 }, { ">>", 4 },
			{ "&", 5 }, { "|", 5 }, { "^", 5 },
			{ "??", 6 },
			{ "<", 7 }, { "<=", 7 }, { ">", 7 }, { ">=", 7 }, { "==", 7 }, { "!=", 7 },
			{ "&&", 8 },
			{ "||", 9 },
		};

		/// <summary>
		/// 比较运算符的优先级数字
		/// </summary>
		public static int ComparePriorityNum { get => 7; }

		/// <summary>
		/// 最大优先级数字
		/// </summary>
		public static int MaxPriorityNum { get => 10; }
	}
}

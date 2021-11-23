using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac {
	enum LogMark {
		[Display (Name = "解析")]
		Parse,
		[Display (Name = "编译")]
		Build
	}

	class Log {
		public static void Mark (LogMark _mark) {
			if (_cache != (_mark, Info.CurrentRelativeFile)) {
				_cache = (_mark, Info.CurrentRelativeFile);
				Console.WriteLine ($"正在{_cache.Item1.GetDisplayName ()} {_cache.Item2}。。。");
			}
		}

		private static (LogMark, string) _cache = (LogMark.Parse, "");
	}
}

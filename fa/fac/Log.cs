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
			Console.WriteLine ($"正在{_mark.GetDisplayName ()} {Info.CurrentRelativeFile}");
		}
	}
}

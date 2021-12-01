﻿using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.Test {
	[TestClass]
	public class UnitTest_If {
		// if语句嵌套，命中及未命中
		[TestMethod]
		public void TestIf1 () {
			string _code = @"
use fa;

class Program {
	public static void Main () {
		int n = 10;
		if n == 7 {
			Console.Write (""error"");
		} else {
			if n == 10 {
				Console.Write (""TestIf1"");
			} else {
				Console.Write (""error"");
			}
		}
	}
}
";
			string _ret = BuildTool.RunAndGetReturn (_code);
			Assert.AreEqual (_ret, "TestIf1");
		}

		// if语句并列，命中
		[TestMethod]
		public void TestIf2 () {
			string _code = @"
use fa;

class Program {
	public static void Main () {
		int n = 10;
		if n == 7 {
			Console.Write (""error"");
		} else if n == 10 {
			Console.Write (""TestIf2"");
		} else {
			Console.Write (""error"");
		}
	}
}
";
			string _ret = BuildTool.RunAndGetReturn (_code);
			Assert.AreEqual (_ret, "TestIf2");
		}

		// if语句并列，未命中
		[TestMethod]
		public void TestIf3 () {
			string _code = @"
use fa;

class Program {
	public static void Main () {
		int n = 10;
		if n == 7 {
			Console.Write (""error"");
		} else if n == 8 {
			Console.Write (""error"");
		} else {
			Console.Write (""TestIf3"");
		}
	}
}
";
			string _ret = BuildTool.RunAndGetReturn (_code);
			Assert.AreEqual (_ret, "TestIf3");
		}

		// if表达式嵌套，命中及未命中
		[TestMethod]
		public void TestIf4 () {
			string _code = @"
use fa;

class Program {
	public static void Main () {
		int n = 10;
		string _s = if n == 7 {
			""error""
		} else {
			if n == 10 {
				""TestIf4""
			} else {
				""error""
			}
		};
		Console.Write (_s);
	}
}
";
			string _ret = BuildTool.RunAndGetReturn (_code);
			Assert.AreEqual (_ret, "TestIf4");
		}

		// if表达式并列，命中
		[TestMethod]
		public void TestIf5 () {
			string _code = @"
use fa;

class Program {
	public static void Main () {
		int n = 10;
		string _s = if n == 7 {
			""error""
		} else if n == 10 {
			""TestIf5""
		} else {
			""error""
		};
		Console.Write (_s);
	}
}
";
			string _ret = BuildTool.RunAndGetReturn (_code);
			Assert.AreEqual (_ret, "TestIf5");
		}

		// if表达式并列，未命中
		[TestMethod]
		public void TestIf6 () {
			string _code = @"
use fa;

class Program {
	public static void Main () {
		int n = 10;
		string _s = if n == 7 {
			""error""
		} else if n == 9 {
			""error""
		} else {
			""TestIf6""
		};
		Console.Write (_s);
	}
}
";
			string _ret = BuildTool.RunAndGetReturn (_code);
			Assert.AreEqual (_ret, "TestIf6");
		}

		// if语句连续条件，命中及未命中
		[TestMethod]
		public void TestIf7 () {
			string _code = @"
use fa;

class Program {
	public static void Main () {
		int n = 10;
		if 5 < n <= 7 {
			Console.Write (""error"");
		} else {
			if 9 < n <= 12 {
				Console.Write (""TestIf7"");
			} else {
				Console.Write (""error"");
			}
		}
	}
}
";
			string _ret = BuildTool.RunAndGetReturn (_code);
			Assert.AreEqual (_ret, "TestIf7");
		}
	}
}
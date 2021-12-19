using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.Test {
	[TestClass]
	public class UnitTest02_Switch {
		/// <summary>
		/// switch value 语句，跳过when
		/// </summary>
		[TestMethod]
		public void TestSwitch1 () {
			string _code = @"
use fa;

class Program {
	public static void Main () {
		int n = 10, o = 12;
		switch n {
			3              => Console.Write (""error"");
			10 when o == 7 => Console.Write (""error"");
			10             => Console.Write (""TestSwitch1"");
			_              => Console.Write (""error"");
		}
	}
}
";
			string _ret = BuildTool.RunAndGetReturn (_code);
			Assert.AreEqual (_ret, "TestSwitch1");
		}

		/// <summary>
		/// switch value 语句，命中when
		/// </summary>
		[TestMethod]
		public void TestSwitch2 () {
			string _code = @"
use fa;

class Program {
	public static void Main () {
		int n = 10, o = 12;
		switch n {
			3               => Console.Write (""error"");
			10 when o == 12 => Console.Write (""TestSwitch2"");
			10              => Console.Write (""error"");
			_               => Console.Write (""error"");
		}
	}
}
";
			string _ret = BuildTool.RunAndGetReturn (_code);
			Assert.AreEqual (_ret, "TestSwitch2");
		}

		/// <summary>
		/// switch value 语句，未命中
		/// </summary>
		[TestMethod]
		public void TestSwitch3 () {
			string _code = @"
use fa;

class Program {
	public static void Main () {
		int n = 10, o = 12;
		switch n {
			3              => Console.Write (""error"");
			10 when o == 7 => Console.Write (""error"");
			11             => Console.Write (""error"");
			_              => Console.Write (""TestSwitch3"");
		}
	}
}
";
			string _ret = BuildTool.RunAndGetReturn (_code);
			Assert.AreEqual (_ret, "TestSwitch3");
		}

		/// <summary>
		/// switch value 表达式，跳过when
		/// </summary>
		[TestMethod]
		public void TestSwitch4 () {
			string _code = @"
use fa;

class Program {
	public static void Main () {
		int n = 8, o = 12;
		string k = switch n {
			3             => ""error"",
			8 when o == 7 => ""error"",
			8             => ""TestSwitch4"",
			_             => ""error"",
		};
		Console.Write (k);
	}
}
";
			string _ret = BuildTool.RunAndGetReturn (_code);
			Assert.AreEqual (_ret, "TestSwitch4");
		}

		/// <summary>
		/// switch value 表达式，命中when
		/// </summary>
		[TestMethod]
		public void TestSwitch5 () {
			string _code = @"
use fa;

class Program {
	public static void Main () {
		int n = 8, o = 12;
		string k = switch n {
			3              => ""error"",
			8 when o == 12 => ""TestSwitch5"",
			8              => ""error"",
			_              => ""error"",
		};
		Console.Write (k);
	}
}
";
			string _ret = BuildTool.RunAndGetReturn (_code);
			Assert.AreEqual (_ret, "TestSwitch5");
		}

		/// <summary>
		/// switch value 表达式，未命中
		/// </summary>
		[TestMethod]
		public void TestSwitch6 () {
			string _code = @"
use fa;

class Program {
	public static void Main () {
		int n = 9, o = 12;
		string k = switch n {
			3              => ""error"",
			8 when o == 12 => ""error"",
			8              => ""error"",
			_              => ""TestSwitch6"",
		};
		Console.Write (k);
	}
}
";
			string _ret = BuildTool.RunAndGetReturn (_code);
			Assert.AreEqual (_ret, "TestSwitch6");
		}

		/// <summary>
		/// switch 语句，命中when
		/// </summary>
		[TestMethod]
		public void TestSwitch7 () {
			string _code = @"
use fa;

class Program {
	public static void Main () {
		int o = 12;
		switch {
			when o == 7  => Console.Write (""error"");
			when o == 12 => Console.Write (""TestSwitch7"");
			when o == 15 => Console.Write (""error"");
			_            => Console.Write (""error"");
		}
	}
}
";
			string _ret = BuildTool.RunAndGetReturn (_code);
			Assert.AreEqual (_ret, "TestSwitch7");
		}

		/// <summary>
		/// switch 语句，未命中
		/// </summary>
		[TestMethod]
		public void TestSwitch8 () {
			string _code = @"
use fa;

class Program {
	public static void Main () {
		int o = 12;
		switch {
			when o == 3  => Console.Write (""error"");
			when o == 8  => Console.Write (""error"");
			when o == 15 => Console.Write (""error"");
			_            => Console.Write (""TestSwitch8"");
		}
	}
}
";
			string _ret = BuildTool.RunAndGetReturn (_code);
			Assert.AreEqual (_ret, "TestSwitch8");
		}

		/// <summary>
		/// switch 表达式，命中when
		/// </summary>
		[TestMethod]
		public void TestSwitch9 () {
			string _code = @"
use fa;

class Program {
	public static void Main () {
		int o = 12;
		string k = switch {
			when o == 7  => ""error"",
			when o == 12 => ""TestSwitch9"",
			when o == 15 => ""error"",
			_            => ""error"",
		};
		Console.Write (k);
	}
}
";
			string _ret = BuildTool.RunAndGetReturn (_code);
			Assert.AreEqual (_ret, "TestSwitch9");
		}

		/// <summary>
		/// switch 表达式，未命中
		/// </summary>
		[TestMethod]
		public void TestSwitch10 () {
			string _code = @"
use fa;

class Program {
	public static void Main () {
		int o = 12;
		string k = switch {
			when o == 7  => ""error"",
			when o == 11 => ""error"",
			when o == 15 => ""error"",
			_            => ""TestSwitch10"",
		};
		Console.Write (k);
	}
}
";
			string _ret = BuildTool.RunAndGetReturn (_code);
			Assert.AreEqual (_ret, "TestSwitch10");
		}

		/// <summary>
		/// switch 枚举
		/// </summary>
		[TestMethod]
		public void TestSwitch11 () {
			string _code = @"
use fa;

enum TestEnum { A, B, C }

class Program {
	public static void Main () {
		TestEnum e = TestEnum.B;
		switch e {
			TestEnum.A => Console.Write (""error"");
			TestEnum.B => Console.Write (""TestSwitch11"");
			TestEnum.C => Console.Write (""error"");
		}
	}
}
";
			string _ret = BuildTool.RunAndGetReturn (_code);
			Assert.AreEqual (_ret, "TestSwitch11");
		}
	}
}

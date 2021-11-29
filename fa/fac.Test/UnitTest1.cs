using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace fac.Test {
	[TestClass]
	public class UnitTest1 {
		[TestMethod]
		public void TestMethod1 () {
			string _code = @"
use fa;

enum TestEnum { A, B (int), C }
class Program {
	public static void Main () {
		TestEnum e = TestEnum.B (2);
		switch e {
			TestEnum.A     => Console.Write (""error1"");
			TestEnum.B (6) => Console.Write (""error2"");
			TestEnum.B (2) => Console.Write (""hello"");
			TestEnum.C     => Console.Write (""error3"");
		}
	}
}
";
			string _ret = BuildTool.RunAndGetReturn (_code);
			Assert.AreEqual (_ret, "hello");
		}
	}
}

using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace fac.Test {
	[TestClass]
	public class UnitTest00_hello {
		[TestMethod]
		public void TestMethod1 () {
			string _code = @"
use fa;

class Program {
	public static void Main () {
		Console.Write (""hello"");
	}
}
";
			string _ret = BuildTool.RunAndGetReturn (_code);
			Assert.AreEqual (_ret, "hello");
		}
	}
}

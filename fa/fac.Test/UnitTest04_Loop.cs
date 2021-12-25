using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace fac.Test
{
	[TestClass]
	public class UnitTest04_Loop
	{
		[TestMethod]
		public void TestLoop1()
		{
			string code = @"

use fa;

class Program {
	public static void Main () {
		int id = 0;
		while id < 3 {
			Console.WriteLine(""Hey, User{0}"".Format(id));
			id++;
		}
	}
}

";
			string ret = BuildTool.RunAndGetReturn(code);
			Assert.AreEqual(ret, "Hey, User0\r\nHey, User1\r\nHey, User2\r\n");
		}

		[TestMethod]
		public void TestLoopd2()
		{
			string code = @"

use fa;

class Program {
	public static void Main () {
		for int id = 0; a < 3; id++ {
			Console.WriteLine(""Hey, User{0}"".Format(id));
		}
	}
}

";
			string ret = BuildTool.RunAndGetReturn(code);
			Assert.AreEqual(ret, "Hey, User0\r\nHey, User1\r\nHey, User2\r\n");
		}

		[TestMethod]
		public void TestLoop3()
		{
			string code = @"

use fa;

class Program {
	public static void Main () {
		int id = 0;
		do {
			Console.WriteLine(""Hey, User{0}"".Format(id));
			id ++;
		} while id<3;
	}
}

";
			string ret = BuildTool.RunAndGetReturn(code);
			Assert.AreEqual(ret, "Hey, User0\r\nHey, User1\r\nHey, User2\r\n");
		}
	}


}
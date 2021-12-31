using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace fac.Test
{
	[TestClass]
	public class UnitTest04_Loop
	{
		/// <summary>
		/// 测试While关键字
		/// </summary>
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

		/// <summary>
		/// 测试For关键字
		/// </summary>
		[TestMethod]
		public void TestLoop2()
		{
			string code = @"

use fa;

class Program {
	public static void Main () {
		for int id = 0; id < 3; id++ {
			Console.WriteLine(""Hey, User{0}"".Format(id));
		}
	}
}

";
			string ret = BuildTool.RunAndGetReturn(code);
			Assert.AreEqual(ret, "Hey, User0\r\nHey, User1\r\nHey, User2\r\n");
		}
		
		/// <summary>
		/// 测试DoWhile关键字
		/// </summary>
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
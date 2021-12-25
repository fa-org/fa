using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace fac.Test
{
    [TestClass]
    public class UnitTest04_Loop
    {
        [TestMethod]
        public void TestMethod1()
        {
            string code = @"

use fa;

class Program {
	public static void Main () {
		int id = 0;
		while id<3 {
			Console.WriteLine(""Hey, User{0}"".Format(id));
            id += 1;
		}
	}
}

";
            string ret = BuildTool.RunAndGetReturn(code);
            Assert.AreEqual(ret, "Hey, User0\r\nHey, User1\r\nHey, User2\r\n");
        }
    }
}
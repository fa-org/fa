using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace fac.Test {
	[TestClass]
	public class UnitTest03_Object {
		[TestMethod]
		public void TestMethod1 () {
			string _code = @"
use fa;

class Dic0 {
	public string s;
}

class Program {
	public static void Main () {
		Dic0 d = new { s = ""TestObject1"" };
		Console.Write (d.s);
	}
}
			";
			string _ret = BuildTool.RunAndGetReturn (_code);
			Assert.AreEqual (_ret, "TestObject1");
		}

		[TestMethod]
		public void TestMethod2 () {
			string _code = @"
use fa;

class Dic1<T1> {
	public T1 s;
}

class Program {
	public static void Main () {
		Dic1<string> d = new { s = ""TestObject2"" };
		Console.Write (d.s);
	}
}
			";
			string _ret = BuildTool.RunAndGetReturn (_code);
			Assert.AreEqual (_ret, "TestObject2");
		}

		[TestMethod]
		public void TestMethod3 () {
			string _code = @"
use fa;

class Dic1<T1> {
	public T1 s;
	public T1 test (T1 t) {
		T1 a = ""{0}{1}"".Format (s, t);
		return a;
	}
}

class Program {
	public static void Main () {
		Dic1<string> d = new { s = ""Test"" };
		string _s = d.test (""Object3"");
		Console.Write (_s);
	}
}
			";
			string _ret = BuildTool.RunAndGetReturn (_code);
			Assert.AreEqual (_ret, "TestObject3");
		}
	}
}

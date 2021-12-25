using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace fac.Test {
	[TestClass]
	public class UnitTest00_hello {
		/// <summary>
		/// 输出Hello
		/// </summary>
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

		/// <summary>
		/// 测试内建
		/// </summary>
		[TestMethod]
		public void TestMethod2 () {
			// 备注：所有内建方法请参见 fa/fac/ASTs/Exprs/Names/AstExprName_BuildIn.cs
			string _code = @"
use fa;

class Program {
	public static void Main () {
		// 读当前文件
		string _src1 = File.ReadAllText (@FILE);
		// 直接获取当前文件源码
		string _src2 = @FILEDATA;
		if _src1 != _src2 {
			Console.WriteLine (""error"");
		}
		// 控制台输出/控制台输出行
		Console.Write (""a"");
		Console.WriteLine (""b"");
		// 检查文件是否存在
		if !File.Exists (@FILE) {
			Console.WriteLine (""error"");
		}
		// 写文件
		File.WriteAllText (""D:\\a.fa"", ""// this file generate by fa test\r\n"");
		// 追加文件
		File.AppendAllText (""D:\\a.fa"", @FILEDATA);
		// 输出文件大小
		string _src3 = File.ReadAllText (""D:\\a.fa"");
		Console.Write (""{0}"".Format (_src3.Length));
		// 删除临时文件
		File.Delete (""D:\\a.fa"");
		//// 判断文件夹是否存在
		//bool _b = Directory.Exists (""D:\\folder"");
		//// 创建文件夹
		//Directory.Create (""D:\\folder"");
		//// 获取文件夹下所有文件名称
		//string[] _files = Directory.GetFiles (""D:\\folder"");
		//// 删除文件夹
		//Directory.Delete (""D:\\folder"");
	}
}
";
			string _ret = BuildTool.RunAndGetReturn (_code);
			Assert.AreEqual (_ret[..4], "ab\r\n");
			Assert.IsTrue (int.Parse (_ret[4..]) > 500);
		}
	}
}

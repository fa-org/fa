using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.Test {
	[TestClass]
	public class UnitTest10_Algorithm {
		[TestMethod]
		public void TestMethod1 () {
			string _code = @"
use fa;

class Program {
	public static void Sort (mut int[] numbers) {
		_ = QuickSort (numbers, 0, numbers.Length - 1);
	}

	private static void? QuickSort (mut int[] numbers, int left, int right) {
		if left > right {
			return;
		}
		int middle = numbers [(left + right) / 2];
		int i = left - 1;
		int j = right + 1;
		while true {
			while (numbers[++i] < middle) {}
			while (numbers[--j] > middle) {}
			if i >= j {
				break;
			}
			Swap(numbers, i, j);
		}
		QuickSort(numbers, left, i - 1);
		QuickSort(numbers, j + 1, right);
	}

	private static void? Swap (mut int[] numbers, int i, int j) {
		int number = numbers[i];
		numbers[i] = numbers[j];
		numbers[j] = number;
	}

	public static void Main () {
		int[] n = [45, 4123, 213, 42, 123, 53, 22];
		Sort (n);
		for int a = 0; a < n.Length; ++a {
			int nn = n[a] ?? -1;
			Console.Write (""{0} "".Format (nn));
		}
	}
}
";
			string _ret = BuildTool.RunAndGetReturn (_code);
			Assert.AreEqual (_ret, "22 42 45 53 123 213 4123 ");
		}
	}
}

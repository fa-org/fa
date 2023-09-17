# fa

fa语言编译器实现。一款专注于元编程的编程语言，目标是尽可能简化复杂的框架调用，让函数尽可能简单易懂

**[WIP] 编译器存在较大修改，暂不可用**  
**qq交流群：1018390466 欢迎一起讨论语法/实现/轮子**

*老版本C++及C#实现已在 [Release](https://github.com/fa-org/fa/releases/tag/v0.0.6.bak) 备份*

## 主要特性

- 可以很方便的在代码里嵌入元代码，改变实现。示例代码：

```fa
class Program {
	public static void Meta (mut Dictionary<string, ClassBlock> _classes) {
        var _stmt = stmt Console.WriteLine ("hello world!")
		_classes ["Program"]?.funcs["Main"]?.body_codes.Add (_stmt)
	}

	public static void Main () {
	}
}
```

- 语句加入 `calc` 关键字即可将代码标记为元代码，编译期运行。示例代码：

```fa
class Program {
	public static void Main () {
        var compile_time = calc DateTime.Now()
        Console.WriteLine ("Compile Time: {compile_time}")
	}
}
```

# fa

fa 语言编译器（开发中）

目标：

1. 体积够小，原生运行
2. 没有async/await关键字，全程异步，无线程概念
3. 调用主函数即创建进程，便捷实现进程间通讯（同一个类型需三个实现，线程不安全、原子、跨进程）
4. 编译时运行编译模块，控制编译流程
5. 对大规模并行代码，能自动识别是否能使用gpu加速或cpu扩展指令集加速，如果能则自动启用
6. 浮点数==比较为指定精度比较，精确比较使用===
7. 其他语言用起来麻烦的地方，简化开发
	- 领域驱动模型
	- 微服务自动拆分
	- 进程间调用 *（待定）*
		+ 创建进程传递参数 *（待定）*
		+ 独立进程间互相通讯 *（待定）*

已知性能警告：

1. 貌似是死循环的代码块，要求循环体内所有路径带await
	- 警告处理方式：给while循环加上 `@safe` 标注
	- 忽略警告后：编译器给所有实时运行路径加上循环一万次yield一下
2. 要求不允许循环引用
	- 警告处理方式：引用路径其中一个引用改为 `Object&?`（弱引用）
	- 忽略警告：改用RAII+GC实现

<!--
参考资料：

https://zhuanlan.zhihu.com/p/25959684
前言（就是本篇）
考不上三本也能给自己心爱的语言加上Coroutine（一） - 知乎专栏
考不上三本也能给自己心爱的语言加上Coroutine（二） - 知乎专栏
考不上三本也能给自己心爱的语言加上Coroutine（三） - 知乎专栏
考不上三本也能给自己心爱的语言加上Coroutine（四） - 知乎专栏
考不上三本也会实现数据绑定（一） - 知乎专栏
考不上三本也会实现数据绑定（二） - 知乎专栏
考不上三本也会实现数据绑定（三） （作者： @余生梦 ）
考不上三本也能实现C++编译器——前言
考不上三本也能懂系列——处理声明（一）
考不上三本也能懂系列——处理声明（二）
考不上三本也能懂系列——处理声明（三）（新！）
考不上三本也能懂系列——实现C++类型系统（一）
考不上三本也能懂系列——实现C++类型系统（二）
考不上三本也能懂系列——什么是C++的argument-dependent lookup

创建结构体
https://llvm.org/doxygen/classllvm_1_1StructType.html#a7cf5280be35cd0c973f40c7d87a11acd

-->





<!--
public class TestClass {
	public string field;
	public string func () {}

	public string Value1;
	public string Value2 = "hello";
	public string Value3 { get; set; }
	public string Value4 { get; set; } = "hello";

	CastFrom (int32 _n) {}
	CastFrom (double _n) {}
	CastFrom (string _s) {}
	int32 CastTo () => 12;
	double CastTo () => 0.0;
	string CastTo () => "";
}
-->

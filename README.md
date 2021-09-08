# fa

fa 语言编译器（开发中）

## 语言目标

通过便捷的语法写出效率堪比最优化的C++的执行效率

### 达到目标的方式

- 提前编译多种Native代码与SIMD（比如x86-64编译x86、amd64、MMX、SSE、AVX等），然后分别压缩
- 编译出的程序运行后检查当前平台支持的最快速的SIMD指令集，解压指令集代码，并执行
	+ 在加速效果非常明显的位置编译SIMD代码

## 当前进度

- [ ] 基本语法
	+ [x] 表达式（暂不完全）
	+ [ ] 类、对象、继承
	+ [ ] 异步
	+ [ ] linq
- [ ] 编译系统
	+ [x] 支持Windows x86平台（暂不完全）
	+ [ ] 支持交叉编译
	+ [ ] 支持Windows、Linux、Mac平台
- [ ] 速度、体积优化
	+ [ ] 并发优化
	+ [ ] SIMD支持
		* [ ] 计划支持：SSE4.2、AVX、AVX2、AVX512、neon
	+ [ ] 可执行代码压缩（待定）
- [ ] ...

## 基本语法特性

- 接近C#的语法
- async异步
  - 无await关键字，当async函数调用另一async函数时，自动异步
  - 通过括号方式使得多个异步任务并发执行。例如 `var (a, b) = (async1 (), async2 ());`
- 进程间调用
  - 创建子进程时，能共享对象（通过共享段或共享内存实现）
- 领域驱动模型(DDD) 的项目结构限制
  - 简化DDD库的调用
  - 使DDD更好用
- 浮点数==比较为指定精度比较，精确比较使用===
- 不需手工使用智能指针
- 文件夹代表命名空间
- 类变量没有赋予初值时，强制要求声明对象时赋初值
- 不区分栈变量、堆变量与引用变量，无需手工使用智能指针

## 示例代码

```fa
// 声明类实例
public class TestClass {
	// 字段
	public string Value1;
	public string Value2 = "hello";
	public string Value3 { get; set; }
	public string Value4 { get; set; } = "hello";

	// 可以被赋予哪些类型的值
	CastFrom (int32 _n) {}
	CastFrom (double _n) {}
	CastFrom (string _s) {}

	// 能够隐式转换为哪些类型
	int32 CastTo () => 12;
	double CastTo () => 0.0;
	string CastTo () => "";

	// 定义函数
	public string func () {}
}

// 实例化类型
var tc1 = TestClass { Value1 = "a", Value3 = "c" }; // 必填参数
var tc2 = TestClass { Value1 = "a", Value2 = "b", Value3 = "c", Value4 = "d" }; // 包括可选参数
```

### 运行效果

![img](./imgs/screen1.png)

<!--
性能警告：

1. 要求不允许循环引用
	- 警告处理方式：引用路径其中一个引用改为 `Object&?`（弱引用）
	- 忽略警告：改用RAII+GC实现
2. 貌似是死循环的代码块，要求循环体内所有路径带异步方法调用（待确认）
	- 警告处理方式：给while循环加上 `@safe` 标注
	- 忽略警告后：编译器给所有实时运行路径加上循环一万次yield一下

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

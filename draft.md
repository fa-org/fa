# fa语言草案

## 注释

同C++，包括两种注释，行注释`//`、块注释`/**/`

## 命名空间

- 项目根目录带“项目名”命名空间
- 子目录带“项目名.子目录”命名空间

示例：

- FaProject
	+ main.fa               -- 命名空间：FaProject
	+ Program.fa            -- 命名空间：FaProject
	+ Services
		* AppServices.fa    -- 命名空间：FaProject.Services
		* UserServices.fa   -- 命名空间：FaProject.Services

## 模块文件架构

```fa
// 引用fa库
use xxx;

// 引入库文件
@lib "ucrt.lib";

// 定义外部函数
@import int32 __cdecl puts (cstr);

// 定义类或结构体
public class Xxx {
	//...
}
```

## 类、结构体

类和结构体相似，都能定义包含0个或多个子元素的新类型。

相同点：

- 定义成员变量
	+ 定义普通成员变量
		* `public string name1;`
		* 成员变量在构造时必须指定初值，比如 `var a = new MyObj { name1 = "Alice" };`
	+ 定义成员变量带默认值
		* `public string name2 = "Bob";`
		* 成员变量在构造时可指定初值可不指定
	+ 定义自定权限成员变量
		* `public string name3 { get; private set; }`
		* 成员变量在构造时必须指定初值，另外无法在外部赋值
	+ 定义自定权限成员变量带默认值
		* `public string name4 { get; private set; } = "Carol";`
	+ 定义静态成员变量
		* `public static string name5 = "Dave";`
- 定义成员方法
	+ 普通成员方法
		* `public void func () {}`
		* 默认所有方法均为虚方法，可继承后重写
	+ getter/setter
		* `public string name3 { get => "Eve"; }`
- 实现接口方式
	+ 实现代码
		```fa
		class A {
			public int i = 55;
		}

		interface IFunc {
			public int func ();
		}

		class B: IFunc {
			public int func () { return 5; }
		}

		class MyCls: A, IFunc (b) {
			public B b;
		}
		```
	+ MyCls类对象实际内存布局
		```
		类型ID
		IFunc实现地址     ->      B::func（或低性能实现：forward: B）
		A a:
			类型ID（可选）
			i存储地址
		B b:
			类型ID（可选）
			IFunc实现地址     ->      B::func
		```

不同点：

- 类使用class关键字定义，结构体使用struct关键字定义
- 类可以继承自类、结构体或接口；结构体只能继承自结构体
- 类允许定义构造函数与析构函数，结构体不允许
	```fa
	public class MyObj {
		public MyObj {}
		public ~MyObj {}
	}
	```
- 不同方法参数的声明下，传值方式区别
	| | 类 | 结构体/字符串/数字 |
	| :---: | :---: | :---: |
	| 不可变引用传参 | `const TypeName val` | `TypeName val` |
	| 可变引用传参 | `TypeName val` | `ref TypeName val`  |
	| 拷贝传参 | `TypeName val` (调用位置：`val.dup`) | `dup TypeName val` |
- 当拷贝时，成员变量中的类对象成员复制指针；成员变量中的结构体成员复制所有子成员变量

## 接口

接口不允许定义成员变量，可以定义成员方法或成员方法的声明。当定义声明时，继承自此接口的类需要实现此方法，才允许实例化。

一个类只允许继承自一个类或结构体，但允许同时实现多个接口。

接口允许定义默认方法，实现此接口的类可以不再重新实现默认方法。

```fa
public interface ISchool {
	// 定义抽象方法
	public void AddStudent (string name, int32 age);

	// 定义抽象getter/setter
	public string name { get; set; }

	// 定义默认方法
	public void GetSchoolCount () => 20;

	// 定义抽象getter/setter
	public string SchoolName { get => "meow school"; }
}
```

## 枚举类型

枚举类型里的成员变量在某一时间只有一个能使用。

成员变量有两种使用方式，switch访问或者直接访问。

```fa
private enum StringData {
	string Name,
	int32 Age,
	Animal,
}

// StringData _data;
// 访问方式1：
switch _data {
	Name (_name): Console.WriteLine (_name);
	Age (_age): Console.WriteLine ($"{_age}");
	Animal: Console.WriteLine ("animal");
}
// 访问方式2
string _name = _data.Name ?? "kangkang";
_data.Name = "michael";
```

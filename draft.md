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
@import int32 __cdecl puts (cptr);

// 定义类或结构体
public class Xxx {
	//...
}
```

## 类

类能定义包含0个或多个子元素的新类型。

```fa
public class ClassA {
	public int MemberA = 0
	public int MemberA0
	public int MemberA1 { get; set; }
	public int MemberA2 { get; set; } = 2
}
public class ClassB {
	public int MemberB = 0
}
public class C: ClassA pa, ClassB pb {
	void test () {
		pa.MemberA = 10
		pb.MemberB = 20
	}
}
```

- 定义成员变量
	+ 定义普通成员变量
		* `public string name1;`
		* 成员变量在构造时必须指定初值，比如 `var a = new MyObj { name1 = "Alice" }`
	+ 定义成员变量带默认值
		* `public string name2 = "Bob"`
		* 成员变量在构造时可指定初值可不指定
	+ 定义自定权限成员变量
		* `public string name3 { get; private set; }`
		* 成员变量在构造时必须指定初值，另外无法在外部赋值
	+ 定义自定权限成员变量带默认值
		* `public string name4 { get; private set; } = "Carol"`
	+ 定义静态成员变量
		* `public static string name5 = "Dave"`
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
			public int i = 55
		}

		interface IFunc {
			public int func ()
		}

		class B: IFunc {
			public int func () { return 5; }
		}

		class MyCls: A a, B b {
			public void test_calc () {
				a.i = 43
				this.a.i = 34
			}
		}
		```
	+ 代码描述
		* B类直接实现IFunc接口
		* MyCls类继承至A、B类，并且分别定义别名a、b
		* MyCls类内部通过a、b像访问变量一样访问MyCls的父类
		* MyCls类外部直接访问MyCls的父类，就像继承一样
	+ MyCls类对象实际内存布局
		```
		类型ID
		A a:
			类型ID
			i存储地址
		B b:
			类型ID
		```
	+ MyCls类静态结构描述内存布局
		```
		// 能访问到这个结构体，就意味着知道对象是什么类型了，因此不需要描述符
		A 类型起始地址偏移
		B 类型起始地址偏移
		IFunc实现地址     ->      B::func
		```
- 可以继承自类或接口
- 允许定义构造函数与析构函数
	```fa
	public class MyObj {
		public MyObj {}
		public ~MyObj {}
	}
	```

参数传递声明方式：

| | 类/字符串/数字 |
| :---: | :---: |
| 不可变引用传参 | `TypeName val` |
| 可变引用传参 | `mut TypeName val`  |
| 拷贝传参 | `dup TypeName val` |

备注：不区分值类型与引用类型，统一按值类型方式确定

## 接口

接口不允许定义成员变量，可以定义成员方法或成员方法的声明。当定义声明时，继承自此接口的类需要实现此方法，才允许实例化。

一个类只允许继承自一个类或结构体，但允许同时实现多个接口。

接口允许定义默认方法，实现此接口的类可以不再重新实现默认方法。

```fa
public interface ISchool {
	// 定义抽象方法
	public void AddStudent (string name, int32 age)

	// 定义抽象getter/setter
	public string name { get; set; }

	// 定义默认方法
	public void GetSchoolCount () => 20

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
	Name (_name): Console.WriteLine (_name)
	Age (_age): Console.WriteLine ($"{_age}")
	Animal: Console.WriteLine ("animal")
}
// 访问方式2
string _name = _data.Name ?? "kangkang"
_data.Name = "michael"
```

## 异常处理

允许空值的返回类型代表支持异常处理，遇到异常时，假如用户没做完整的处理，并且出现UB，那么将返回null并且携带错误信息与异常栈。

如果正常的逻辑需要使用到带空的返回类型，那么不识别错误信息与错误栈即可。

示例代码：

```fa
int32? calc_div (int32 a) {
	int32? x = a / 0                                   // 执行后x的值为null
	int32 y = a / 0 ? 1                                // 执行后y的值为1
	int32 z = a / 0                                    // 执行后函数直接返回，返回值为null
	int32 z = (a / 0).unwrap (new DeviceZeroError ())  // 等价上一句
	int32? zz = new DeviceZeroError ()                 // 赋值一个错误（同时指定值为null）
	throw new DeviceZeroError ()                       // 抛异常
}

int32? calc_div_wrap1 (int32 a) {
	return calc_div (a)
}

int32? calc_div_wrap2 (int32 a) {
	int32? b = calc_div_wrap1 (a)

	// 错误处理方式1
	switch b {
		int32 (_b) => Console.WriteLine ("{b}")
		Error (_e) => {
			Console.WriteLine ("遇到异常：{_e.Message}")
			Console.WriteLine ("{_e.Stack}")
		}
	}

	// 错误处理方式2
	if b is valid {
		// 此处b临时升级为int32类型（假如b的值有被修改那么临时升级措施失效）
		Console.WriteLine ("{b}")
	} else {
		// 此处b临时升级为Error类型
		Console.WriteLine ("遇到异常：{b.Message}")
		Console.WriteLine ("{b.Stack}")
	}
}
```

如果某个函数不希望异常传递，那么可以修改返回类型为不可空类型，那么此函数必须能够处理所有可空的数据（异常），否则将编译报错。

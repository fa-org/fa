# fa语言草案

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

## 类和结构体

| | 类 | 结构体/字符串/数字 |
| :---: | :---: | :---: |
| 关键字 | class | struct |
| 构造/析构函数 | 有 | 无 |
| 数据类型 | 引用类型 | 值类型 |
| 默认参数传递方式 | 引用 | 常量 |
| 不可变引用传参声明 | `const TypeName val` | `(const) TypeName val` |
| 可变引用传参声明 | `(ref) TypeName val` | `ref TypeName val`  |
| 拷贝传参声明 | `dup TypeName val` | `dup TypeName val` |
|  |  |  |



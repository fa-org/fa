# fa语言用户手册

## 入门fa语言教程

(因fa语言暂未完全确定语法方案，因此暂无教程)

## 学习fa语言编译器原理

### 前置知识

- 编程语言前端部分
    + 了解`BNF`，学习`LL`原理
    + *（进阶）手撸基于`LL`的`Compiler Compiler`，可参考 [Facc](https://github.com/fawdlstty/Facc)*
    + 学习 [Antlr4](https://github.com/antlr/antlr4) 用法
    + 参考示例：[grammars-v4](https://github.com/antlr/grammars-v4)
- 编程语言后端部分
    + *（进阶）学会任一汇编语言（masm、nasm等），并能手工做到与C语言互译*
    + 学习 [LLVM](https://github.com/llvm/llvm-project) 及`LLVM IR`用法

### 编译

1. 准备一台安装着 Visual Studio 的电脑
2. 克隆 fa 编译器仓库（ `git clone https://github.com/fa-org/fa.git`）
3. 打开 `fa` 路径下的 `fa.sln`
4. 点击菜单 `Build` 下的 `Publish to Folder...`

> 接下来的步骤中，默认选择发布到的路径为默认（`bin/Release/net5.0/publish`），如果你更改了路径，到你设置的路径中寻找即可。

5. 前往 `fa` 路径下的 `fac/bin/Release/net5.0` 
6. 该路径下的 `fac` 或者 `fac.exe` 即为编译器

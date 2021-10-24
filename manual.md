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

- 准备Windows环境电脑，比如 Windows 11
- 安装 `Visual Studio 2019 Community`，勾选上 `使用C++的桌面开发`
- 安装vcpkg并编译支持库
    + `git clone https://github.com/microsoft/vcpkg` （最好克隆到D:\GitHub\目录下）
    + `./bootstrap-vcpkg.bat`
    + （可选）将vcpkg命令所在目录放置到Path环境变量中
    + `vcpkg install antlr4:x86-windows-static`
    + `vcpkg install llvm[clang,compiler-rt,lld,target-x86,tools]:x86-windows-static`
        * 注：此步骤将消耗100G左右存储空间，另外空闲内存最好大于10G，编译耗时大概2h
    + `vcpkg integrate install`
- 编译fa语言编译器
    + `git clone https://github.com/fawdlstty/fa`
    + 打开`仓库目录\fa\fa.sln`
    + （如果vcpkg未克隆到D:\GitHub\目录下）：修改项目的包含目录
    + 编译

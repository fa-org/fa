//#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING
//#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
//#define _CRT_SECURE_NO_WARNINGS
//#define ANTLR4CPP_STATIC
#pragma warning (disable: 4141)
#pragma warning (disable: 4146)
#pragma warning (disable: 4244)
#pragma warning (disable: 4624)



#include <conio.h>
#include <filesystem>
#include <iostream>
#include <sstream>
#include <string>

#include "AstExprOrValue.hpp"
#include "FaParser.h"
#include "FaLexer.h"
#include "CodeVisitor.hpp"
#include "FaLLVMGen.hpp"
#include "Log.hpp"

//#pragma comment (lib, "antlr4-runtime.lib")



int main (int argc, char* argv[]) {
	std::filesystem::current_path ("D:\\fa_tmp");
	extern std::string CODE;
	Log::SetCurrentFile ("Program.fa", CODE);
	std::cout << "----------开始编译----------" << std::endl;
	antlr4::ANTLRInputStream _s (CODE);
	FaLexer _lexer { &_s };
	antlr4::CommonTokenStream _cts { &_lexer };
	_cts.fill ();
	FaParser _parser { &_cts };
	CodeVisitor _visitor;
	FaLLVMGen _gen { &_visitor, "hello", "hello"};
	auto _success = _gen.Compile (_parser.program (), "hello.obj");
	if (_success) {
		std::cout << "compile success." << std::endl;
		//std::string _out = _gen.Link (R"(E:\Software\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.28.29910\bin\Hostx86\x86\link.exe)");
		std::string _out = _gen.Link ();
		std::cout << _out << std::endl;
	} else {
		std::cout << "compile failed." << std::endl;
	}
	// link /out:hello.exe /subsystem:console /entry:fa_entry_main hello.obj

	std::cout << "press any key to exit." << std::endl;
	::_getch ();
	return 0;
}

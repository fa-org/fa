//#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING
//#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
//#define _CRT_SECURE_NO_WARNINGS
//#define ANTLR4CPP_STATIC
//#pragma warning (disable: 4251)



#include <conio.h>
#include <filesystem>
#include <iostream>
#include <sstream>
#include <string>

#include "FaParser.h"
#include "FaLexer.h"
#include "CodeVisitor.hpp"
#include "FaLLVMGen.hpp"
#include "Log.hpp"

//#pragma comment (lib, "antlr4-runtime.lib")



int main (int argc, char *argv[]) {
	std::filesystem::current_path ("D:\\fa_tmp");
	std::string _code = R"(
@import int __cdecl puts (const char*);
//// MT
//@lib "libucrt.lib";
//@lib "libcmt.lib";
////@lib "libvcruntime.lib";

// MD
@lib "ucrt.lib";
@lib "msvcrt.lib";
//@lib "vcruntime.lib";

//@lib "kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib" "ole32.lib";
//@lib "advapi32.lib" "shell32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib";

static int32 FaEntryMain () {
	int32 n = if false {
		10
	} else {
		if true {
			20
		} else {
			30
		}
	};

	if n == 20 {
		::puts ("n == 20\n");
	} else {
		::puts ("n != 20\n");
	}
	return 0;
}
)";
	Log::SetCurrentFile ("Program.fa", _code);
	std::cout << "----------开始编译----------" << std::endl;
	antlr4::ANTLRInputStream _s (_code);
	FaLexer _lexer { &_s };
	antlr4::CommonTokenStream _cts { &_lexer };
	_cts.fill ();
	FaParser _parser { &_cts };
	//FaParser::ProgramContext *_ctx = _parser.program ();
	CodeVisitor _visitor;
	//auto _v = _visitor.visitProgram (_ctx).as<std::vector<std::string>> ();
	//std::cout << "----------visit begin----------" << std::endl;
	//for (auto _use_item : _v)
	//	std::cout << "    " << _use_item << std::endl;
	////std::vector<antlr4::tree::ParseTree*> _children = _ctx->children;
	////for (antlr4::tree::ParseTree *_child : _children) {
	////	std::cout << _child->children [1]->getText () << std::endl;
	////}
	FaLLVMGen _gen { &_visitor, "hello" };
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

/////////antlr4::ParserRuleContext *_root = _parser.getContext ();
///////////////FaBaseVisitor _visitor {};
///////////////antlrcpp::Any _obj = _visitor.visitS (_parser.s ());
//size_t _err_count = _parser.getNumberOfSyntaxErrors ();
//if (_err_count > 0) {
//	std::cout << "parse failed." << std::endl;
//}
//_parser.removeErrorListeners ();
// TODO: add error listener

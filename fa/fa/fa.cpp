//#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING
//#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
//#define _CRT_SECURE_NO_WARNINGS
//#define ANTLR4CPP_STATIC
//#pragma warning (disable: 4251)



#include <conio.h>
#include <iostream>
#include <sstream>
#include <string>

#include "FaParser.h"
#include "FaLexer.h"
#include "CodeVisitor.hpp"

//#pragma comment (lib, "antlr4-runtime.lib")



int main (int argc, char *argv[]) {
	std::string _code = R"(
use tesrds13_;
use sadas;
use sa.das;

class Program {
	static void Main (string args) {}
}
)";
	std::cout << "----------source begin----------" << std::endl;
	std::cout << _code << std::endl;
	std::cout << "----------source end----------" << std::endl << std::endl;
	antlr4::ANTLRInputStream _s (_code);
	FaLexer _lexer { &_s };
	antlr4::CommonTokenStream _cts { &_lexer };
	_cts.fill ();
	FaParser _parser { &_cts };
	FaParser::ProgramContext *_ctx = _parser.program ();
	CodeVisitor _visitor;
	auto _v = _visitor.visitProgram (_ctx).as<std::vector<std::string>> ();
	std::cout << "----------visit begin----------" << std::endl;
	for (auto _use_item : _v)
		std::cout << "    " << _use_item << std::endl;
	//std::vector<antlr4::tree::ParseTree*> _children = _ctx->children;
	//for (antlr4::tree::ParseTree *_child : _children) {
	//	std::cout << _child->children [1]->getText () << std::endl;
	//}

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

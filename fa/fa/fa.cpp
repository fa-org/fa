#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable: 4251)
#define ANTLR4CPP_STATIC



#include <conio.h>
#include <iostream>
#include <sstream>
#include <string>

#include "FaParser.h"
#include "FaLexer.h"
#include "CodeVisitor.hpp"

#pragma comment (lib, "antlr4-runtime.lib")



int main (int argc, char *argv[]) {
	std::string _code = R"(
use tesrds13_;
use sadas;
use sa.das;
)";
	antlr4::ANTLRInputStream _s (_code);
	FaLexer _lexer { &_s };
	antlr4::CommonTokenStream _cts { &_lexer };
	_cts.fill ();
	FaParser _parser { &_cts };
	FaParser::ProgramContext *_ctx = _parser.program ();
	CodeVisitor _visitor;
	auto _v = _visitor.visitProgram (_ctx).as<std::string> ();
	std::cout << _v << std::endl;
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

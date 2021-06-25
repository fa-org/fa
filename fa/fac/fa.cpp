#include <conio.h>
#include <iostream>
#include <string>

//#define ONLY_GEN_AST
#include "FaGenAST.hpp"
#ifndef ONLY_GEN_AST
#	include "FaUseAST.hpp"
#	include "FaLink.hpp"
#	include "ASTs/ProgramAST.hpp"
#endif



int main (int argc, char *argv[]) {
#ifdef ONLY_GEN_AST
	FaGenAST::generate ();
	std::cout << "代码已生成。" << std::endl;
#else
	std::cout << "输入序号指定执行逻辑：" << std::endl;
	std::cout << "    1. 生成AST代码" << std::endl;
	std::cout << "    2. 执行AST树" << std::endl;
	std::cout << "    其他. 退出" << std::endl;
	std::string _s;
	std::cin >> _s;
	if (_s == "1") {
		FaGenAST::generate ();
		std::cout << "代码已生成。" << std::endl;
	} else if (_s == "2") {
		auto _ast_parser = std::make_shared<AstParser> ();
		std::string _code = R"(
use fa;

class Program {
	void Main (string[] args) {}
}
)";
		auto _root = _ast_parser->Parse<ProgramAST> (_code);
		std::cout << std::endl;
		if (_root) {
			_root->PrintTree (0);
		} else {
			auto _err = _ast_parser->GetError ();
			std::cout << "Error in Line " << _err.Line << ": " << _err.ErrorInfo << std::endl;
			std::cout << _err.LineCode << std::endl;
			std::cout << std::string (_err.LinePos, ' ') << "^" << std::endl;
		}
	}
#endif
	std::cout << "Press any key to exit..." << std::endl;
	::_getch ();
	return 0;
}

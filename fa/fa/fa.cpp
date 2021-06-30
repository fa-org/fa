#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <conio.h>
#include <iostream>
#include <sstream>
#include <string>

#include "FaParser.h"
#include "FaLexer.h"
#include "FaVisitor.h"
#include "FaBaseVisitor.h"

//#pragma comment (lib, "antlr4-runtime.lib")



int main (int argc, char *argv[]) {
	std::string _code = "hello kangkang michael";
	antlr4::ANTLRInputStream _s (_code);
	FaLexer _lexer { &_s };
	antlr4::CommonTokenStream _cts { &_lexer };
	_cts.fill ();
	FaParser _parser { &_cts };
	FaParser::SContext *_ctx = _parser.s ();
	std::vector<antlr4::tree::TerminalNode *> _id = _ctx->ID ();
	/////////antlr4::ParserRuleContext *_root = _parser.getContext ();
	///////////////FaBaseVisitor _visitor {};
	///////////////antlrcpp::Any _obj = _visitor.visitS (_parser.s ());
	//size_t _err_count = _parser.getNumberOfSyntaxErrors ();
	//if (_err_count > 0) {
	//	std::cout << "parse failed." << std::endl;
	//} else {
	//	std::vector<antlr4::Token *> _tokens = _cts.getTokens ();
	//	for (const antlr4::Token *_token : _tokens) {
	//		std::cout << _token->getText () << "    " << _token->toString () << std::endl;
	//	}
	//}
	//_parser.removeErrorListeners ();
	// TODO: add error listener

	std::cout << "press any key to exit." << std::endl;
	::_getch ();
	return 0;
}

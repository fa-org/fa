#include <filesystem>
#include <iostream>
#include <memory>
#include <string>

#pragma warning (push)
#pragma warning (disable: 4141)
#pragma warning (disable: 4146)
#pragma warning (disable: 4244)
#pragma warning (disable: 4624)
#include "antlr_gen/FaLexer.h"
#include "antlr_gen/FaParser.h"
#pragma warning (pop)

#include "tools/File.hpp"
#include "FaCodeVisitor.hpp"



int main () {
	std::string _code = File::ReadAllText ("main.fa");
	std::string _namespace = "global";

	auto _stream = std::make_shared<antlr4::ANTLRInputStream> (_code);
	auto _lexer = std::make_shared<FaLexer> (_stream.get ());
	auto _cts = std::make_shared<antlr4::CommonTokenStream> (_lexer.get ());
	_cts->fill ();
	auto _parser = std::make_shared<FaParser> (_cts.get ());
	FaCodeVisitor _visitor {};

	_visitor.visit (_parser->program ());

	//std::filesystem::current_path ("D:\\fa_tmp");
	return 0;
}

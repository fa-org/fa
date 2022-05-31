#ifndef __AST_PROGRAM_HPP__
#define __AST_PROGRAM_HPP__



#include <memory>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

#include "AstEnum.hpp"
#include "AstClass.hpp"
#include "../IAst.hpp"
#include "../../Exception.hpp"
#include "../../Common.hpp"



struct AstProgram: public IAst {
	std::vector<std::tuple<std::string, std::string>> m_uses;
	std::string m_namespace = "";
	std::vector<std::shared_ptr<AstEnum>> m_enums;
	std::vector<std::shared_ptr<AstClass>> m_classes;

	AstProgram (FaParser::ProgramContext *_ctx): IAst (_ctx->start) {
		for (auto _use_stmt : _ctx->useStmt ())
			m_uses.push_back ({ GetId (_use_stmt->id ()), GetId (_use_stmt->ids ()) });
		if (_ctx->namespaceStmt ())
			m_namespace = GetId (_ctx->namespaceStmt ()->ids ());
		for (auto _enum : _ctx->enumBlock ())
			m_enums.push_back (AstEnum::FromCtx (_enum));
		for (auto _enum : _ctx->enumBlock2 ())
			m_enums.push_back (AstEnum::FromCtx (_enum));
		for (auto _class : _ctx->classBlock ())
			m_classes.push_back (AstClass::FromCtx (_class));
		for (auto _class : _ctx->classBlock2 ())
			m_classes.push_back (AstClass::FromCtx (_class));
	}

	std::string GenCppCode (size_t) override {
		std::stringstream _ss {};
		_ss << "#include <iostream>\n";
		_ss << "#include <string>\n";
		_ss << "\n";
		_ss << "\n";
		_ss << "\n";
		for (auto _enum : m_enums)
			_ss << _enum->GenCppCode (0);
		_ss << "\n";
		for (auto _class : m_classes)
			_ss << _class->GenCppCode (0);
		_ss << "\n";
		_ss << "int main () {\n";
		_ss << "    Program::Main ();\n";
		_ss << "    return 0;\n";
		_ss << "}\n";
		return _ss.str ();
	}

	static std::shared_ptr<AstProgram> FromCtx (FaParser::ProgramContext *_ctx) {
		return std::make_shared<AstProgram> (_ctx);
	}
};



#endif //__AST_PROGRAM_HPP__

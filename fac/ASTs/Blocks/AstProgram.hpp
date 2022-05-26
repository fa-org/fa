#ifndef __AST_PROGRAM_HPP__
#define __AST_PROGRAM_HPP__



#include <memory>
#include <string>
#include <tuple>
#include <vector>

#include "AstEnum.hpp"
#include "AstClass.hpp"
#include "../../Exception.hpp"



struct AstProgram {
	std::vector<std::tuple<std::string, std::string>> m_uses;
	std::string m_namespace = "";
	std::vector<std::shared_ptr<AstEnum>> m_enums;
	std::vector<std::shared_ptr<AstClass>> m_classes;

	AstProgram (FaParser::ProgramContext *ctx) {
		for (auto _use_stmt : ctx->useStmt ())
			m_uses.push_back ({ _use_stmt->ids () ? _use_stmt->ids ()->getText () : "", _use_stmt->ids ()->getText () });
		if (ctx->namespaceStmt ())
			m_namespace = ctx->namespaceStmt ()->getText ();
		for (auto _enum : ctx->enumBlock ()) {
			m_enums.push_back (AstEnum::FromCtx (_enum));
		}
		for (auto _class : ctx->classBlock ()) {
			m_classes.push_back (AstClass::FromCtx (_class));
		}
	}

	static std::shared_ptr<AstProgram> FromCtx (FaParser::ProgramContext *_ctx) {
		return std::make_shared<AstProgram> (_ctx);
	}
};



#endif //__AST_PROGRAM_HPP__

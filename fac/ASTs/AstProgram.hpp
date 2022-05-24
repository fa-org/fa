#ifndef __AST_PROGRAM_HPP__
#define __AST_PROGRAM_HPP__



#include <memory>
#include <string>
#include <tuple>
#include <vector>

#include "AstEnum.hpp"
#include "AstClass.hpp"



struct AstProgram {
	std::vector<std::tuple<std::string, std::string>> m_uses;
	std::string m_namespace = "";
	std::vector<std::shared_ptr<AstEnum>> m_enums;
	std::vector<std::shared_ptr<AstClass>> m_classes;

	AstProgram (FaParser::ProgramContext *ctx) {
		for (auto _use_stmt : ctx->useStmt ())
			m_uses.push_back ({ _use_stmt->Id () ? _use_stmt->Id ()->getText () : "", _use_stmt->ids ()->getText () });
		//
		m_namespace = ctx->namespaceStmt ()->getText ();
		//
	}
};



#endif //__AST_PROGRAM_HPP__

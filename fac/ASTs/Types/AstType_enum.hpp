#ifndef __AST_TYPE_ENUM_HPP__
#define __AST_TYPE_ENUM_HPP__



#include "IAstType.hpp"
#include "../Blocks/AstEnum.hpp"



struct AstType_enum: public IAstType {
	std::shared_ptr<AstEnum> m_enum;

	AstType_enum (antlr4::Token *_token, std::shared_ptr<AstEnum> _enum): IAstType (_token), m_enum (_enum) {}

	std::string GenCppCode () override { return m_enum->m_name; }

	static PAstType Make (antlr4::Token *_token, std::shared_ptr<AstEnum> _enum) {
		return new AstType_enum { _token, _enum };
	}
};



#endif //__AST_TYPE_ENUM_HPP__

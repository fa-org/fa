#ifndef __AST_TYPE_ENUM_HPP__
#define __AST_TYPE_ENUM_HPP__



#include "IAstType.hpp"
#include "../Blocks/AstEnum.hpp"



struct AstType_enum: public IAstType {
	std::shared_ptr<AstEnum> m_enum;

	AstType_enum (std::shared_ptr<AstEnum> _enum): m_enum (_enum) {}
	std::string GenCppCode () override { return m_enum->m_name; }
};



#endif //__AST_TYPE_ENUM_HPP__

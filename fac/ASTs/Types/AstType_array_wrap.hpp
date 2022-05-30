#ifndef __AST_TYPE_ARRAY_WRAP_HPP__
#define __AST_TYPE_ARRAY_WRAP_HPP__



#include <format>
#include <memory>

#include "IAstType.hpp"



struct AstType_array_wrap: public IAstType {
	std::shared_ptr<IAstType> m_base_type;

	AstType_array_wrap (antlr4::Token *_token, std::shared_ptr<IAstType> _base_type): IAstType (_token), m_base_type (_base_type) {}

	std::string GenCppCode () override { return std::format ("{}[]", m_base_type->GenCppCode ()); }
};



#endif //__AST_TYPE_ARRAY_WRAP_HPP__

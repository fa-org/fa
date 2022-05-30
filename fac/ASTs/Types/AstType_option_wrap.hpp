#ifndef __AST_TYPE_OPTION_WRAP_HPP__
#define __AST_TYPE_OPTION_WRAP_HPP__



#include <memory>

#include "IAstType.hpp"



struct AstType_option_wrap: public IAstType {
	std::shared_ptr<IAstType> m_base_type;

	AstType_option_wrap (antlr4::Token *_token, std::shared_ptr<IAstType> _base_type): IAstType (_token), m_base_type (_base_type) {
		if (dynamic_cast<AstType_option_wrap *> (_base_type.get ()))
			throw Exception ("option wrap cannot assign option wrap base type");
	}
	std::string GenCppCode () override { return std::format ("std::optional<{}>", m_base_type->GenCppCode ()); }
};



#endif //__AST_TYPE_OPTION_WRAP_HPP__

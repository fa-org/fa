#ifndef __AST_TYPE_OPTION_WRAP_HPP__
#define __AST_TYPE_OPTION_WRAP_HPP__



#include <memory>

#include "IAstType.hpp"



struct AstType_option_wrap: public IAstType {
	PAstType m_base_type;

	AstType_option_wrap (antlr4::Token *_token, PAstType _base_type): IAstType (_token), m_base_type (_base_type) {
		if (dynamic_cast<AstType_option_wrap *> (_base_type.get ()))
			throw Exception ("option wrap cannot assign option wrap base type");
	}

	std::string GenCppCode (size_t _indent) override { return std::format ("std::optional<{}>", m_base_type->GenCppCode (_indent)); }

	void GetChildTypes (std::function<void (PAstType &)> _cb) override { _cb (m_base_type); }

	static PAstType Make (antlr4::Token *_token, PAstType _base_type) { return new AstType_option_wrap { _token, _base_type }; }
};



#endif //__AST_TYPE_OPTION_WRAP_HPP__

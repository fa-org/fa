#ifndef __AST_TYPE_ARRAY_WRAP_HPP__
#define __AST_TYPE_ARRAY_WRAP_HPP__



#include <format>
#include <memory>

#include "IAstType.hpp"



struct AstType_array_wrap: public IAstType {
	PAstType m_base_type;

	AstType_array_wrap (antlr4::Token *_token, PAstType _base_type): IAstType (_token), m_base_type (_base_type) {}

	std::string GenCppCode (size_t _indent) override { return std::format ("{}[]", m_base_type->GenCppCode (_indent)); }

	void GetChildTypes (std::function<void (PAstType &)> _cb) override { _cb (m_base_type); }

	static PAstType Make (antlr4::Token *_token, PAstType _base_type) { return new AstType_array_wrap { _token, _base_type }; }
};



#endif //__AST_TYPE_ARRAY_WRAP_HPP__

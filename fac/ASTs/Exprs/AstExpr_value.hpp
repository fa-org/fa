#ifndef __AST_EXPR_VALUE_HPP__
#define __AST_EXPR_VALUE_HPP__



#include <memory>
#include <string>

#include "IAstExpr.hpp"
#include "../Types/IAstType.hpp"



struct AstExpr_value: public IAstExpr {
	PAstType m_type;
	std::string m_value;

	AstExpr_value (antlr4::Token *_token, PAstType _type, std::string _value):
		IAstExpr (_token), m_type (_type), m_value (_value) {}

	std::string GenCppCode (size_t _indent) override { return m_value; }

	static PAstExpr Make (antlr4::Token *_token, PAstType _type, std::string _value) {
		return new AstExpr_value { _token, _type, _value };
	}
};



#endif //__AST_EXPR_VALUE_HPP__

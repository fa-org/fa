#ifndef __AST_TYPE_FLOAT_HPP__
#define __AST_TYPE_FLOAT_HPP__



#include "IAstType.hpp"



struct AstType_float: public IAstType {
	size_t m_bit_width;

	AstType_float (antlr4::Token *_token, size_t _bit_width): IAstType (_token), m_bit_width (_bit_width) {}

	std::string GenCppCode (size_t _indent) override { return m_bit_width == 32 ? "float" : "double"; }

	void GetChildTypes (std::function<void (PAstType &)> _cb) override {}

	static PAstType Make (antlr4::Token *_token, size_t _bit_width) { return new AstType_float { _token, _bit_width }; }
};



#endif //__AST_TYPE_FLOAT_HPP__

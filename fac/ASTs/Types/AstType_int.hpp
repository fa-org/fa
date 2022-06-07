#ifndef __AST_TYPE_INT_HPP__
#define __AST_TYPE_INT_HPP__



#include "IAstType.hpp"



struct AstType_int: public IAstType {
	size_t m_bit_width;
	bool m_sign;

	AstType_int (antlr4::Token *_token, size_t _bit_width, bool _sign): IAstType (_token), m_bit_width (_bit_width), m_sign (_sign) {}

	std::string GenCppCode (size_t _indent) override { return std::format ("{}int{}_t", m_sign ? "" : "u", m_bit_width); }

	void GetChildTypes (std::function<void (PAstType &)> _cb) override {}

	static PAstType Make (antlr4::Token *_token, size_t _bit_width, bool _sign) { return new AstType_int { _token, _bit_width, _sign }; }
};



#endif //__AST_TYPE_INT_HPP__

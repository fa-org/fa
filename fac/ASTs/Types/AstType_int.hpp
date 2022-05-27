#ifndef __AST_TYPE_INT_HPP__
#define __AST_TYPE_INT_HPP__



#include "IAstType.hpp"



struct AstType_int: public IAstType {
	size_t m_bit_width;
	bool m_sign;

	AstType_int (size_t _bit_width, bool _sign): m_bit_width (_bit_width), m_sign (_sign) {}
	std::string GenCppCode () override { return std::format ("{}int{}_t", m_sign ? "" : "u", m_bit_width); }
};



#endif //__AST_TYPE_INT_HPP__

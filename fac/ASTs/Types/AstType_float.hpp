#ifndef __AST_TYPE_FLOAT_HPP__
#define __AST_TYPE_FLOAT_HPP__



#include "IAstType.hpp"



struct AstType_float: public IAstType {
	size_t m_bit_width;

	AstType_float (size_t _bit_width): m_bit_width (_bit_width) {}
	std::string GenCppCode () override { return m_bit_width == 32 ? "float" : "double"; }
};



#endif //__AST_TYPE_FLOAT_HPP__

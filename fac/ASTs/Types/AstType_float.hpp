#ifndef __AST_TYPE_FLOAT_HPP__
#define __AST_TYPE_FLOAT_HPP__



#include "IAstType.hpp"



struct AstType_float: public IAstType {
	size_t m_bit_width;

	AstType_float (antlr4::Token *_token, size_t _bit_width): IAstType (_token), m_bit_width (_bit_width) {}

	std::string GenCppCode () override { return m_bit_width == 32 ? "float" : "double"; }

	static std::shared_ptr<IAstType> Make (antlr4::Token *_token, size_t _bit_width) {
		return std::shared_ptr<IAstType> ((IAstType *) new AstType_float { _token, _bit_width });
	}
};



#endif //__AST_TYPE_FLOAT_HPP__

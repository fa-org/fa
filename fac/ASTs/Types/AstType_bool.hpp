#ifndef __AST_TYPE_BOOL_HPP__
#define __AST_TYPE_BOOL_HPP__



#include "IAstType.hpp"



struct AstType_bool: public IAstType {
	AstType_bool (antlr4::Token *_token): IAstType (_token) {}

	std::string GenCppCode () override { return "bool"; }

	static PAstType Make (antlr4::Token *_token) {
		return new AstType_bool { _token };
	}
};



#endif //__AST_TYPE_BOOL_HPP__

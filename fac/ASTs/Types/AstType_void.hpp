#ifndef __AST_TYPE_VOID_HPP__
#define __AST_TYPE_VOID_HPP__



#include "IAstType.hpp"



struct AstType_void: public IAstType {
	std::string GenCppCode () override { return "void"; }

	AstType_void (antlr4::Token *_token): IAstType (_token) {}

	static PAstType Make (antlr4::Token *_token) {
		return new AstType_void { _token };
	}
};



#endif //__AST_TYPE_VOID_HPP__

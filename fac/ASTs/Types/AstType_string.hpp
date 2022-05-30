#ifndef __AST_TYPE_STRING_HPP__
#define __AST_TYPE_STRING_HPP__



#include "IAstType.hpp"



struct AstType_string: public IAstType {
	std::string GenCppCode () override { return "std::string"; }

	AstType_string (antlr4::Token *_token): IAstType (_token) {}

	static std::shared_ptr<IAstType> Make (antlr4::Token *_token) {
		return std::shared_ptr<IAstType> ((IAstType *) new AstType_string { _token });
	}
};



#endif //__AST_TYPE_STRING_HPP__

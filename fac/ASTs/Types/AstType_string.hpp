#ifndef __AST_TYPE_STRING_HPP__
#define __AST_TYPE_STRING_HPP__



#include "IAstType.hpp"



struct AstType_string: public IAstType {
	std::string GenCppCode () override { return "std::string"; }
};



#endif //__AST_TYPE_STRING_HPP__

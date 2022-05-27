#ifndef __AST_TYPE_BOOL_HPP__
#define __AST_TYPE_BOOL_HPP__



#include "IAstType.hpp"



struct AstType_bool: public IAstType {
	std::string GenCppCode () override { return "bool"; }
};



#endif //__AST_TYPE_BOOL_HPP__

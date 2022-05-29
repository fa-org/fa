#ifndef __AST_TYPE_STRING_HPP__
#define __AST_TYPE_STRING_HPP__



#include "IAstType.hpp"



struct AstType_string: public IAstType {
	std::string GenCppCode () override { return "std::string"; }

	static std::shared_ptr<IAstType> Make () {
		return std::shared_ptr<IAstType> ((IAstType *) new AstType_string {});
	}
};



#endif //__AST_TYPE_STRING_HPP__

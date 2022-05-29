#ifndef __AST_TYPE_VOID_HPP__
#define __AST_TYPE_VOID_HPP__



#include "IAstType.hpp"



struct AstType_void: public IAstType {
	std::string GenCppCode () override { return "void"; }

	static std::shared_ptr<IAstType> Make () {
		return std::shared_ptr<IAstType> ((IAstType *) new AstType_void {});
	}
};



#endif //__AST_TYPE_VOID_HPP__

#ifndef __AST_TYPE_CLASS_HPP__
#define __AST_TYPE_CLASS_HPP__



#include "IAstType.hpp"
#include "../Blocks/AstClass.hpp"



struct AstType_class: public IAstType {
	std::shared_ptr<AstClass> m_class;

	AstType_class (antlr4::Token *_token, std::shared_ptr<AstClass> _class): IAstType (_token), m_class (_class) {}

	std::string GenCppCode () override { return m_class->m_name; }

	static PAstType Make (antlr4::Token *_token, std::shared_ptr<AstClass> _class) {
		return new AstType_class { _token, _class };
	}
};



#endif //__AST_TYPE_CLASS_HPP__

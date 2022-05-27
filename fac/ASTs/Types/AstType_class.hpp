#ifndef __AST_TYPE_CLASS_HPP__
#define __AST_TYPE_CLASS_HPP__



#include "IAstType.hpp"
#include "../Blocks/AstClass.hpp"



struct AstType_class: public IAstType {
	std::shared_ptr<AstClass> m_class;

	AstType_class (std::shared_ptr<AstClass> _class): m_class (_class) {}
	std::string GenCppCode () override { return m_class->m_name; }
};



#endif //__AST_TYPE_CLASS_HPP__

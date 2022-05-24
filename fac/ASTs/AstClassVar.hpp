#ifndef __AST_CLASS_VAR_HPP__
#define __AST_CLASS_VAR_HPP__



#include <memory>
#include <string>

#include "AstType.hpp"



struct AstClassVar {
	std::shared_ptr<AstType> m_type;
	std::string m_name = "";
};



#endif //__AST_CLASS_VAR_HPP__

#ifndef __AST_CLASS_VAR_HPP__
#define __AST_CLASS_VAR_HPP__



#include <memory>
#include <string>

#include "../Types/AstType.hpp"
#include "../../Common.hpp"



struct AstClassVar {
	PublicLevel m_level;
	std::string m_name = "";
	std::shared_ptr<AstType> m_type;
};



#endif //__AST_CLASS_VAR_HPP__

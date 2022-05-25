#ifndef __AST_ENUM_ITEM_HPP__
#define __AST_ENUM_ITEM_HPP__



#include <memory>
#include <string>
#include <vector>

#include "AstType.hpp"



struct AstEnumItem {
	std::string m_name = "";
	std::vector<std::shared_ptr<AstType>> m_attach_types;
};



#endif //__AST_ENUM_ITEM_HPP__

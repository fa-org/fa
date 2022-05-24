#ifndef __AST_ENUM_HPP__
#define __AST_ENUM_HPP__



#include <memory>
#include <string>
#include <vector>

#include "AstEnumItem.hpp"



struct AstEnum {
	std::vector<std::shared_ptr<AstEnumItem>> m_items;
};



#endif //__AST_ENUM_HPP__

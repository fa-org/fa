#ifndef __IAST_HPP__
#define __IAST_HPP__



#include <string>

#include "../antlr_gen/FaParser.h"



struct IAst {
	antlr4::Token *m_token = nullptr;

	IAst (antlr4::Token *_token): m_token (_token) {}

	virtual std::string GenCppCode (size_t _indent) = 0;
};

#endif //__IAST_HPP__

#ifndef __AST_TYPE_TEMP_HPP__
#define __AST_TYPE_TEMP_HPP__



#include "IAstType.hpp"



struct AstType_temp: public IAstType {
	std::string m_name = "";

	AstType_temp (std::string _name): m_name (_name) {}
	std::string GenCppCode () override { throw Exception ("cannot gen code at uncomplete type"); }
};



#endif //__AST_TYPE_TEMP_HPP__

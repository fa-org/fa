#ifndef __AST_TYPE_TEMP_HPP__
#define __AST_TYPE_TEMP_HPP__



#include "IAstType.hpp"



struct AstType_temp: public IAstType {
	std::string m_name = "";
	std::vector<PAstType> m_templates;

	AstType_temp (antlr4::Token *_token, std::string _name): IAstType (_token), m_name (_name) {}
	AstType_temp (antlr4::Token *_token, std::string _name, std::vector<PAstType> _templates): IAstType (_token), m_name (_name), m_templates (_templates) {}
	std::string GenCppCode () override { throw Exception ("cannot gen code at uncomplete type"); }

	static PAstType Make (antlr4::Token *_token, std::string _name) {
		return PAstType ((IAstType *) new AstType_temp { _token, _name });
	}

	static PAstType Make (antlr4::Token *_token, std::string _name, std::vector<PAstType> _templates) {
		return new AstType_temp { _token, _name, _templates };
	}
};



#endif //__AST_TYPE_TEMP_HPP__

#ifndef __AST_TYPE_TEMP_HPP__
#define __AST_TYPE_TEMP_HPP__



#include "IAstType.hpp"



struct AstType_temp: public IAstType {
	std::string m_name = "";
	std::vector<std::shared_ptr<IAstType>> m_templates;

	AstType_temp (std::string _name): m_name (_name) {}
	AstType_temp (std::string _name, std::vector<std::shared_ptr<IAstType>> _templates): m_name (_name), m_templates (_templates) {}
	std::string GenCppCode () override { throw Exception ("cannot gen code at uncomplete type"); }

	static std::shared_ptr<IAstType> Make (std::string _name) {
		return std::shared_ptr<IAstType> ((IAstType *) new AstType_temp { _name });
	}

	static std::shared_ptr<IAstType> Make (std::string _name, std::vector<std::shared_ptr<IAstType>> _templates) {
		return std::shared_ptr<IAstType> ((IAstType *) new AstType_temp { _name, _templates });
	}
};



#endif //__AST_TYPE_TEMP_HPP__

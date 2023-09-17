#ifndef __AST_TYPE_CLASS_TEMPLATE_HPP__
#define __AST_TYPE_CLASS_TEMPLATE_HPP__



#include "IAstType.hpp"
#include "../Blocks/AstClass.hpp"



struct AstType_class_template_item: public IAstType {
	std::shared_ptr<AstClass> m_class;
	size_t m_template_index = 0;

	AstType_class_template_item (antlr4::Token *_token): IAstType (_token) {}
	AstType_class_template_item (antlr4::Token *_token, std::shared_ptr<AstClass> _class, size_t _template_index): IAstType (_token), m_class (_class), m_template_index (_template_index) {}

	PAstType ProcessDeclareType () override {
		m_class->m_tpl_inst_types [m_template_index];
	}

	std::vector<AstType_unsure_wrap *> GetTypeTemplates () override { throw fa::Exception (m_token, "not implement"); }

	bool NeedSure () override { return true; }

	std::string GetTypeName () {
		return std::format ("{}::{}", m_class->m_full_name, CompileEnv::CurrentClass->m_tpl_names[m_template_index]);
	}

	static PAstType Make (antlr4::Token *_token, std::shared_ptr<AstClass> _class, size_t _template_index) {
		return std::shared_ptr<IAstType> (new AstType_class_template_item { _token, _class, _template_index });
	}
};



#endif //__AST_TYPE_CLASS_TEMPLATE_HPP__

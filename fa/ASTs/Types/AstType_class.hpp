#ifndef __AST_TYPE_CLASS_COMPLETE_HPP__
#define __AST_TYPE_CLASS_COMPLETE_HPP__



#include "IAstType.hpp"
#include "../Blocks/AstClass.hpp"



struct AstType_class: public IAstType {
	std::shared_ptr<AstClass> m_class;
	std::vector<PAstType> m_template_types;

	AstType_class (antlr4::Token *_token): IAstType (_token) {}
	AstType_class (antlr4::Token *_token, std::shared_ptr<AstClass> _class, std::vector<PAstType> _template_types): IAstType (_token), m_class (_class), m_template_types (_template_types) {}

	PAstType ProcessDeclareType () override {
		for (size_t i = 0; i < m_template_types.size (); ++i)
			m_template_types [i] = m_template_types [i]->ProcessDeclareType ();
		return shared_from_this ();
	}

	std::vector<AstType_unsure_wrap *> GetTypeTemplates () override { throw fa::Exception (m_token, "not implement"); }

	bool NeedSure () override {
		for (size_t i = 0; i < m_template_types.size (); ++i) {
			if (m_template_types [i]->NeedSure ())
				return true;
		}
		return false;
	}

	std::string GetTypeName ();

	static PAstType Make (antlr4::Token *_token, std::shared_ptr<AstClass> _class, std::vector<PAstType> _template_types) {
		return std::shared_ptr<IAstType> (new AstType_class { _token, _class, _template_types });
	}
};



#endif //__AST_TYPE_CLASS_COMPLETE_HPP__

#ifndef __AST_TYPE_TEMP_HPP__
#define __AST_TYPE_TEMP_HPP__



#include "IAstType.hpp"
#include "../../common/CompileEnv.hpp"



struct AstType_temp_name: public IAstType {
	std::string m_name;
	std::vector<PAstType> m_templates;

	AstType_temp_name (antlr4::Token *_token): IAstType (_token), m_name ("") {}
	AstType_temp_name (antlr4::Token *_token, std::string _name): IAstType (_token), m_name (_name) {}
	AstType_temp_name (antlr4::Token *_token, std::string _name, std::vector<PAstType> _templates): IAstType (_token), m_name (_name), m_templates (_templates) {}

	void SetMembers (fa::ParseType _type, std::vector<AstObj *> _values) override {
		if (_type == fa::ParseType::Part_Member) {
			for (auto _value : _values)
				m_templates.push_back (std::shared_ptr<IAstType> (dynamic_cast<IAstType *> (_value)));
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	void SetValues (fa::ParseValueType _type, std::vector<fa::ParseValue_t> _values) override {
		if (_type == fa::ParseValueType::Name) {
			m_name = std::get<std::string> (_values [0]);
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	PAstType ProcessDeclareType () override;

	std::vector<AstType_unsure_wrap *> GetTypeTemplates () override {
		throw fa::Exception (m_token, "not implement");
	}

	bool NeedSure () override { return true; }

	std::string GetTypeName () { return ProcessDeclareType ()->GetTypeName (); }

	static PAstType Make (antlr4::Token *_token, std::string _name) {
		return std::shared_ptr<IAstType> (new AstType_temp_name { _token, _name });
	}

	static PAstType Make (antlr4::Token *_token, std::string _name, std::vector<PAstType> _templates) {
		return std::shared_ptr<IAstType> (new AstType_temp_name { _token, _name, _templates });
	}
};



#endif //__AST_TYPE_TEMP_HPP__

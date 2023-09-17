#ifndef __AST_ENUM_ITEM_HPP__
#define __AST_ENUM_ITEM_HPP__



#include <memory>
#include <string>
#include <vector>

#include "IAstBlock.hpp"
#include "../Types/IAstType.hpp"



struct AstEnumItem: public IAstBlock {
	std::string m_name = "";
	std::optional<PAstType> m_attach_type;

	AstEnumItem (antlr4::Token *_token): IAstBlock (_token), m_attach_type (std::nullopt) {}

	void SetMembers (fa::ParseType _type, std::vector<AstObj *> _values) override {
		if (_type == fa::ParseType::AnnoPart) {
			if (_values.size () > 0)
				throw fa::Exception (m_token, "not implement");
		} else if (_type == fa::ParseType::Part_Type) {
			throw fa::Exception (m_token, "not implement");
		} else if (_type == fa::ParseType::Part_Member) {
			m_attach_type = std::shared_ptr<IAstType> (dynamic_cast<IAstType *> (_values [0]));
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

	void ProcessDeclareType () override {
		if (m_attach_type.has_value ())
			m_attach_type = m_attach_type.value ()->ProcessDeclareType ();
	}

	void ProcessCodeType () override {}
};



#endif //__AST_ENUM_ITEM_HPP__

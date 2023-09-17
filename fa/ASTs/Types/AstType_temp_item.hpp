#ifndef __AST_TYPE_TEMP_ITEM_HPP__
#define __AST_TYPE_TEMP_ITEM_HPP__



#include <format>
#include <map>
#include <memory>

#include "IAstType.hpp"



struct AstType_temp_item: public IAstType {
	PAstType m_base_type;
	int m_access;

	AstType_temp_item (antlr4::Token *_token): IAstType (_token), m_base_type (nullptr), m_access (-1) {}
	AstType_temp_item (antlr4::Token *_token, PAstType _base_type, std::string _access_str): IAstType (_token), m_base_type (_base_type) {
		if (_access_str == "base") {
			m_access = -1;
		} else {
			m_access = std::stoi (_access_str);
			if (std::format ("{}", m_access) != _access_str)
				throw fa::Exception (m_token, "无法识别的访问类型：{}", _access_str);
		}
	}

	PAstType ProcessDeclareType () override {
		m_base_type = m_base_type->ProcessDeclareType ();
		return shared_from_this ();
	}

	std::vector<AstType_unsure_wrap *> GetTypeTemplates () override {
		throw fa::Exception (m_token, "not implement");
	}

	bool NeedSure () override { return m_base_type->NeedSure (); }

	std::string GetTypeName () { throw fa::Exception (m_token, "not implement"); }

	static PAstType Make (antlr4::Token *_token, PAstType _base_type, std::string _access_str) {
		return std::shared_ptr<IAstType> (new AstType_temp_item { _token, _base_type, _access_str });
	}
};



#endif //__AST_TYPE_TEMP_ITEM_HPP__

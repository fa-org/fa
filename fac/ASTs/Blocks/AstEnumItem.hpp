#ifndef __AST_ENUM_ITEM_HPP__
#define __AST_ENUM_ITEM_HPP__



#include <memory>
#include <string>
#include <vector>

#include "IAstBlock.hpp"
#include "../Types/IAstType.hpp"



struct AstEnumItem: public IAstBlock {
	std::string m_name = "";
	std::vector<PAstType> m_attach_types;

	AstEnumItem (FaParser::EnumItemContext *_ctx): IAstBlock (_ctx->id ()->start) {
		m_name = GetId (_ctx->id ());
		m_attach_types = IAstType::FromCtx (_ctx->type ());
	}

	void ProcessCode () override {
		for (auto &_attach_type : m_attach_types)
			_attach_type->ProcessCode ();
	}

	std::string GenCppCode (size_t _indent) override {
		throw NOT_IMPLEMENT ();
	}

	static std::shared_ptr<AstEnumItem> FromCtx (FaParser::EnumItemContext *_ctx) {
		return std::make_shared<AstEnumItem> (_ctx);
	}
};



#endif //__AST_ENUM_ITEM_HPP__

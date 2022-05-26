#ifndef __AST_ENUM_ITEM_HPP__
#define __AST_ENUM_ITEM_HPP__



#include <memory>
#include <string>
#include <vector>

#include "../Types/IAstType.hpp"



struct AstEnumItem {
	std::string m_name = "";
	std::vector<std::shared_ptr<IAstType>> m_attach_types;

	AstEnumItem (FaParser::EnumItemContext *_ctx) {
		m_name = _ctx->id ()->getText ();
		m_attach_types = IAstType::FromCtx (_ctx->type ());
	}

	static std::shared_ptr<AstEnumItem> FromCtx (FaParser::EnumItemContext *_ctx) {
		return std::make_shared<AstEnumItem> (_ctx);
	}
};



#endif //__AST_ENUM_ITEM_HPP__

#ifndef __AST_ENUM_HPP__
#define __AST_ENUM_HPP__



#include <memory>
#include <string>
#include <vector>

#include "AstEnumItem.hpp"
#include "AstEnumFunc.hpp"



struct AstEnum {
	PublicLevel m_level;
	std::string m_name = "";
	std::vector<std::shared_ptr<AstEnumItem>> m_items;
	std::vector<std::shared_ptr<AstEnumFunc>> m_funcs;

	AstEnum (FaParser::EnumBlockContext *_ctx) {
		m_level = GetPublicLevel (_ctx->publicLevel ());
		m_name = _ctx->id ()->getText ();
		for (auto _item : _ctx->enumItem ())
			m_items.push_back (AstEnumItem::FromCtx (_item));
		for (auto _item : _ctx->classItem ())
			m_funcs.push_back (AstEnumFunc::FromCtx (_item));
	}

	static std::shared_ptr<AstEnum> FromCtx (FaParser::EnumBlockContext *_ctx) {
		return std::make_shared<AstEnum> (_ctx);
	}
};



#endif //__AST_ENUM_HPP__

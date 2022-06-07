#ifndef __AST_ENUM_HPP__
#define __AST_ENUM_HPP__



#include <memory>
#include <string>
#include <vector>

#include "IAstBlock.hpp"
#include "AstEnumItem.hpp"
#include "AstClassFunc.hpp"



struct AstEnum: public IAstBlock {
	PublicLevel m_level;
	std::string m_name = "";
	std::vector<std::shared_ptr<AstEnumItem>> m_items;
	std::vector<std::shared_ptr<AstClassFunc>> m_funcs;

	AstEnum (FaParser::EnumBlockContext *_ctx): IAstBlock (_ctx->id ()->start) {
		m_level = GetPublicLevel (_ctx->publicLevel ());
		m_name = GetId (_ctx->id ());
		for (auto _item : _ctx->enumItem ())
			m_items.push_back (AstEnumItem::FromCtx (_item));
		for (auto _item : _ctx->classItemFunc ())
			m_funcs.push_back (AstClassFunc::FromCtx (_item));
	}

	AstEnum (FaParser::EnumBlock2Context *_ctx): IAstBlock (_ctx->id ()->start) {
		m_level = GetPublicLevel (_ctx->publicLevel ());
		m_name = GetId (_ctx->id ());
		for (auto _item : _ctx->enumItem ())
			m_items.push_back (AstEnumItem::FromCtx (_item));
		for (auto _item : _ctx->classItem2 ())
			m_funcs.push_back (AstClassFunc::FromCtx (_item));
	}

	std::string GenCppCode (size_t _indent) override {
		throw NOT_IMPLEMENT ();
	}

	static std::shared_ptr<AstEnum> FromCtx (FaParser::EnumBlockContext *_ctx) {
		return std::make_shared<AstEnum> (_ctx);
	}

	static std::shared_ptr<AstEnum> FromCtx (FaParser::EnumBlock2Context *_ctx) {
		return std::make_shared<AstEnum> (_ctx);
	}
};



#endif //__AST_ENUM_HPP__

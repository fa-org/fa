#ifndef __AST_TYPE_HPP__
#define __AST_TYPE_HPP__



#include <memory>
#include <string>
#include <tuple>
#include <vector>

#include "../../Common.hpp"



struct AstType {
	bool m_mut = false;
	bool m_params = false;

	AstType (FaParser::TypeContext *_ctx) {
	}

	static std::shared_ptr<AstType> FromCtx (FaParser::TypeContext *_ctx) {
		// TODO
	}

	static std::shared_ptr<AstType> FromCtx (FaParser::TypeWrapContext *_ctx) {
		auto _type = FromCtx (_ctx->type ());
		if (_ctx->Mut ())
			_type->m_mut = true;
		if (_ctx->Params ())
			_type->m_params = true;
		return _type;
	}

	static std::tuple<std::shared_ptr<AstType>, std::string> FromCtx (FaParser::TypeWrapVarContext *_ctx) {
		return { FromCtx (_ctx->typeWrap ()), GetId (_ctx->id ()) };
	}

	static std::tuple<std::shared_ptr<AstType>, std::string> FromCtx (FaParser::TypeWrapVar2Context *_ctx) {
		return { FromCtx (_ctx->typeWrap ()), GetId (_ctx->id ()) };
	}

	static std::tuple<std::vector<std::shared_ptr<AstType>>, std::vector<std::string>> FromCtx (FaParser::TypeWrapVarListContext *_ctx) {
		std::vector<std::shared_ptr<AstType>> _types;
		std::vector<std::string> _names;
		for (auto _item_ctx : _ctx->typeWrapVar ()) {
			auto [_type, _name] = FromCtx (_item_ctx);
			_types.push_back (_type);
			_names.push_back (_name);
		}
		return { _types, _names };
	}

	static std::tuple<std::vector<std::shared_ptr<AstType>>, std::vector<std::string>> FromCtx (FaParser::TypeWrapVar2ListContext *_ctx) {
		std::vector<std::shared_ptr<AstType>> _types;
		std::vector<std::string> _names;
		for (auto _item_ctx : _ctx->typeWrapVar2 ()) {
			auto [_type, _name] = FromCtx (_item_ctx);
			_types.push_back (_type);
			_names.push_back (_name);
		}
		return { _types, _names };
	}
};



#endif //__AST_TYPE_HPP__

#ifndef __AST_TYPE_HPP__
#define __AST_TYPE_HPP__



#include <memory>
#include <string>
#include <tuple>
#include <vector>

#include "../../Common.hpp"
#include "../../Exception.hpp"



struct IAstType {
	bool m_mut = false;
	bool m_params = false;

	static std::shared_ptr<IAstType> FromCtx (FaParser::TypeContext *_ctx) {
		// TODO
		//throw Exception::NotImplement ();
		return std::shared_ptr<IAstType> (new IAstType ());
	}

	static std::vector<std::shared_ptr<IAstType>> FromCtx (std::vector<FaParser::TypeContext *> _ctxs) {
		std::vector<std::shared_ptr<IAstType>> _v;
		for (auto _ctx : _ctxs)
			_v.push_back (FromCtx (_ctx));
		return _v;
	}

	static std::shared_ptr<IAstType> FromCtx (FaParser::TypeWrapContext *_ctx) {
		auto _type = FromCtx (_ctx->type ());
		if (_ctx->Mut ())
			_type->m_mut = true;
		if (_ctx->Params ())
			_type->m_params = true;
		return _type;
	}

	static std::vector<std::shared_ptr<IAstType>> FromCtx (std::vector<FaParser::TypeWrapContext *> _ctxs) {
		std::vector<std::shared_ptr<IAstType>> _v;
		for (auto _ctx : _ctxs)
			_v.push_back (FromCtx (_ctx));
		return _v;
	}

	static std::tuple<std::shared_ptr<IAstType>, std::string> FromCtx (FaParser::TypeWrapVarContext *_ctx) {
		return { FromCtx (_ctx->typeWrap ()), GetId (_ctx->id ()) };
	}

	static std::tuple<std::shared_ptr<IAstType>, std::string> FromCtx (FaParser::TypeWrapVar2Context *_ctx) {
		return { FromCtx (_ctx->typeWrap ()), GetId (_ctx->id ()) };
	}

	static std::tuple<std::vector<std::shared_ptr<IAstType>>, std::vector<std::string>> FromCtx (FaParser::TypeWrapVarListContext *_ctx) {
		std::vector<std::shared_ptr<IAstType>> _types;
		std::vector<std::string> _names;
		for (auto _item_ctx : _ctx->typeWrapVar ()) {
			auto [_type, _name] = FromCtx (_item_ctx);
			_types.push_back (_type);
			_names.push_back (_name);
		}
		return { _types, _names };
	}

	static std::tuple<std::vector<std::shared_ptr<IAstType>>, std::vector<std::string>> FromCtx (FaParser::TypeWrapVar2ListContext *_ctx) {
		std::vector<std::shared_ptr<IAstType>> _types;
		std::vector<std::string> _names;
		for (auto _item_ctx : _ctx->typeWrapVar2 ()) {
			auto [_type, _name] = FromCtx (_item_ctx);
			_types.push_back (_type);
			_names.push_back (_name);
		}
		return { _types, _names };
	}

protected:
	IAstType () {}
	IAstType (const IAstType &) = delete;
};



#endif //__AST_TYPE_HPP__

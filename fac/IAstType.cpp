#include <functional>
#include <map>

#include "ASTs/Types/IAstType.hpp"

#include "ASTs/Types/AstType_array_wrap.hpp"
#include "ASTs/Types/AstType_bool.hpp"
#include "ASTs/Types/AstType_class.hpp"
#include "ASTs/Types/AstType_enum.hpp"
#include "ASTs/Types/AstType_float.hpp"
#include "ASTs/Types/AstType_int.hpp"
#include "ASTs/Types/AstType_option_wrap.hpp"
#include "ASTs/Types/AstType_string.hpp"
#include "ASTs/Types/AstType_temp.hpp"
#include "ASTs/Types/AstType_tuple_wrap.hpp"
#include "ASTs/Types/AstType_void.hpp"



std::tuple<std::shared_ptr<IAstType>, std::string> IAstType::FromCtx (FaParser::TypeVarContext *_ctx) {
	if (!_ctx)
		return { nullptr, "" };
	throw NOT_IMPLEMENT ();
}



std::tuple<std::vector<std::shared_ptr<IAstType>>, std::vector<std::string>> IAstType::FromCtx (std::vector<FaParser::TypeVarContext *> _ctx) {
	std::vector<std::shared_ptr<IAstType>> _vtype;
	std::vector<std::string> _vname;
	for (auto _item : _ctx) {
		auto [_type, _name] = FromCtx (_item);
		_vtype.push_back (_type);
		_vname.push_back (_name);
	}
	return { _vtype, _vname };
}



std::shared_ptr<IAstType> IAstType::FromCtx (FaParser::TypeSingleContext *_ctx) {
	std::string _id = GetId (_ctx->ids ());
	if (!_ctx->quotJianL ()) {
		static std::map<std::string, std::function<std::shared_ptr<IAstType> (antlr4::Token *)>> s_base_types {
			{ "bool",    [] (antlr4::Token *_token) { return AstType_bool::Make (_token); } },
			{ "float32", [] (antlr4::Token *_token) { return AstType_float::Make (_token, 32); } },
			{ "float64", [] (antlr4::Token *_token) { return AstType_float::Make (_token, 64); } },
			{ "int",     [] (antlr4::Token *_token) { return AstType_int::Make (_token, 32, true); } },
			{ "int8",    [] (antlr4::Token *_token) { return AstType_int::Make (_token, 8, true); } },
			{ "int16",   [] (antlr4::Token *_token) { return AstType_int::Make (_token, 16, true); } },
			{ "int32",   [] (antlr4::Token *_token) { return AstType_int::Make (_token, 32, true); } },
			{ "int64",   [] (antlr4::Token *_token) { return AstType_int::Make (_token, 64, true); } },
			{ "uint",    [] (antlr4::Token *_token) { return AstType_int::Make (_token, 32, false); } },
			{ "uint8",   [] (antlr4::Token *_token) { return AstType_int::Make (_token, 8, false); } },
			{ "uint16",  [] (antlr4::Token *_token) { return AstType_int::Make (_token, 16, false); } },
			{ "uint32",  [] (antlr4::Token *_token) { return AstType_int::Make (_token, 32, false); } },
			{ "uint64",  [] (antlr4::Token *_token) { return AstType_int::Make (_token, 64, false); } },
			{ "string",  [] (antlr4::Token *_token) { return AstType_string::Make (_token); } },
			{ "void",    [] (antlr4::Token *_token) { return AstType_void::Make (_token); } },
		};
		if (s_base_types.contains (_id))
			return s_base_types [_id] (_ctx->start);
		return AstType_temp::Make (_ctx->start, _id);
	} else {
	}

	throw NOT_IMPLEMENT ();
}



std::shared_ptr<IAstType> IAstType::FromCtx (FaParser::TypeMultiContext *_ctx) {
	auto [_types, _names] = FromCtx (_ctx->typeVar ());
	return AstType_tuple_wrap::Make (_ctx->start, _types, _names);
}



std::shared_ptr<IAstType> IAstType::FromCtx (FaParser::TypeContext *_ctx) {
	if (!_ctx)
		return nullptr;
	std::shared_ptr<IAstType> _ret;
	if (_ctx->typeSingle ()) {
		_ret = FromCtx (_ctx->typeSingle ());
	} else {
		_ret = FromCtx (_ctx->typeMulti ());
	}
	for (auto _after : _ctx->typeAfter ()) {
		if (_after->quotFangL ()) {
			_ret = AstType_array_wrap::Make (_after->start, _ret);
		} else {
			_ret = AstType_option_wrap::Make (_after->start, _ret);
		}
	}
	return _ret;
}



std::vector<std::shared_ptr<IAstType>> IAstType::FromCtx (std::vector<FaParser::TypeContext *> _ctxs) {
	std::vector<std::shared_ptr<IAstType>> _v;
	for (auto _ctx : _ctxs)
		_v.push_back (FromCtx (_ctx));
	return _v;
}



std::shared_ptr<IAstType> IAstType::FromCtx (FaParser::TypeWrapContext *_ctx) {
	auto _type = FromCtx (_ctx->type ());
	if (_ctx->Mut ())
		_type->m_mut = true;
	if (_ctx->Params ())
		_type->m_params = true;
	return _type;
}



std::vector<std::shared_ptr<IAstType>> IAstType::FromCtx (std::vector<FaParser::TypeWrapContext *> _ctxs) {
	std::vector<std::shared_ptr<IAstType>> _v;
	for (auto _ctx : _ctxs)
		_v.push_back (FromCtx (_ctx));
	return _v;
}



std::tuple<std::shared_ptr<IAstType>, std::string> IAstType::FromCtx (FaParser::TypeWrapVar1Context *_ctx) {
	return { FromCtx (_ctx->typeWrap ()), GetId (_ctx->id ()) };
}



std::tuple<std::shared_ptr<IAstType>, std::string> IAstType::FromCtx (FaParser::TypeWrapVar2Context *_ctx) {
	return { FromCtx (_ctx->typeWrap ()), GetId (_ctx->id ()) };
}



std::tuple<std::vector<std::shared_ptr<IAstType>>, std::vector<std::string>> IAstType::FromCtx (FaParser::TypeWrapVarList1Context *_ctx) {
	std::vector<std::shared_ptr<IAstType>> _types;
	std::vector<std::string> _names;
	if (_ctx) {
		for (auto _item_ctx : _ctx->typeWrapVar1 ()) {
			auto [_type, _name] = FromCtx (_item_ctx);
			_types.push_back (_type);
			_names.push_back (_name);
		}
	}
	return { _types, _names };
}



std::tuple<std::vector<std::shared_ptr<IAstType>>, std::vector<std::string>> IAstType::FromCtx (FaParser::TypeWrapVarList2Context *_ctx) {
	std::vector<std::shared_ptr<IAstType>> _types;
	std::vector<std::string> _names;
	if (_ctx) {
		for (auto _item_ctx : _ctx->typeWrapVar2 ()) {
			auto [_type, _name] = FromCtx (_item_ctx);
			_types.push_back (_type);
			_names.push_back (_name);
		}
	}
	return { _types, _names };
}

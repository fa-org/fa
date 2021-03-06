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



bool PAstType::IsSame (PAstType &_other) {
	return (*this)->GenCppCode (0) == _other->GenCppCode (0);
}



void PAstType::ProcessCode () {
	if (auto _array_wrap = dynamic_cast<AstType_array_wrap *> (get ())) {
		_array_wrap->m_base_type.ProcessCode ();
	} else if (auto _option_wrap = dynamic_cast<AstType_option_wrap *> (get ())) {
		_option_wrap->m_base_type.ProcessCode ();
	} else if (auto _temp = dynamic_cast<AstType_temp *> (get ())) {
		throw NOT_IMPLEMENT ();
	} else if (auto _tuple_wrap = dynamic_cast<AstType_tuple_wrap *> (get ())) {
		for (auto &_type : _tuple_wrap->m_base_types)
			_type.ProcessCode ();
	}
}



std::tuple<PAstType, std::string> IAstType::FromCtx (FaParser::TypeVarContext *_ctx) {
	if (!_ctx)
		return { nullptr, "" };
	throw NOT_IMPLEMENT ();
}



std::tuple<std::vector<PAstType>, std::vector<std::string>> IAstType::FromCtx (std::vector<FaParser::TypeVarContext *> _ctx) {
	std::vector<PAstType> _vtype;
	std::vector<std::string> _vname;
	for (auto _item : _ctx) {
		auto [_type, _name] = FromCtx (_item);
		_vtype.push_back (_type);
		_vname.push_back (_name);
	}
	return { _vtype, _vname };
}



PAstType IAstType::FromCtx (FaParser::TypeSingleContext *_ctx) {
	std::string _id = GetId (_ctx->ids ());
	if (!_ctx->quotJianL ()) {
		static std::map<std::string, std::function<PAstType (antlr4::Token *)>> s_base_types {
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



PAstType IAstType::FromCtx (FaParser::TypeMultiContext *_ctx) {
	auto [_types, _names] = FromCtx (_ctx->typeVar ());
	return AstType_tuple_wrap::Make (_ctx->start, _types, _names);
}



PAstType IAstType::FromCtx (FaParser::TypeContext *_ctx) {
	if (!_ctx)
		return nullptr;
	PAstType _ret;
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



std::vector<PAstType> IAstType::FromCtx (std::vector<FaParser::TypeContext *> _ctxs) {
	std::vector<PAstType> _v;
	for (auto _ctx : _ctxs)
		_v.push_back (FromCtx (_ctx));
	return _v;
}



PAstType IAstType::FromCtx (FaParser::TypeWrapContext *_ctx) {
	auto _type = FromCtx (_ctx->type ());
	if (_ctx->Mut ())
		_type->m_mut = true;
	if (_ctx->Params ())
		_type->m_params = true;
	return _type;
}



std::vector<PAstType> IAstType::FromCtx (std::vector<FaParser::TypeWrapContext *> _ctxs) {
	std::vector<PAstType> _v;
	for (auto _ctx : _ctxs)
		_v.push_back (FromCtx (_ctx));
	return _v;
}



std::tuple<PAstType, std::string> IAstType::FromCtx (FaParser::TypeWrapVar1Context *_ctx) {
	return { FromCtx (_ctx->typeWrap ()), GetId (_ctx->id ()) };
}



std::tuple<PAstType, std::string> IAstType::FromCtx (FaParser::TypeWrapVar2Context *_ctx) {
	return { FromCtx (_ctx->typeWrap ()), GetId (_ctx->id ()) };
}



std::tuple<std::vector<PAstType>, std::vector<std::string>> IAstType::FromCtx (FaParser::TypeWrapVarList1Context *_ctx) {
	std::vector<PAstType> _types;
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



std::tuple<std::vector<PAstType>, std::vector<std::string>> IAstType::FromCtx (FaParser::TypeWrapVarList2Context *_ctx) {
	std::vector<PAstType> _types;
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

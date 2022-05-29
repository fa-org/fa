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
		static std::map<std::string, std::function<std::shared_ptr<IAstType> ()>> s_base_types {
			{ "bool",    [] () { return AstType_bool::Make (); } },
			{ "float32", [] () { return AstType_float::Make (32); } },
			{ "float64", [] () { return AstType_float::Make (64); } },
			{ "int",     [] () { return AstType_int::Make (32, true); } },
			{ "int8",    [] () { return AstType_int::Make (8, true); } },
			{ "int16",   [] () { return AstType_int::Make (16, true); } },
			{ "int32",   [] () { return AstType_int::Make (32, true); } },
			{ "int64",   [] () { return AstType_int::Make (64, true); } },
			{ "uint",    [] () { return AstType_int::Make (32, false); } },
			{ "uint8",   [] () { return AstType_int::Make (8, false); } },
			{ "uint16",  [] () { return AstType_int::Make (16, false); } },
			{ "uint32",  [] () { return AstType_int::Make (32, false); } },
			{ "uint64",  [] () { return AstType_int::Make (64, false); } },
			{ "string",  [] () { return AstType_string::Make (); } },
			{ "void",    [] () { return AstType_void::Make (); } },
		};
		if (s_base_types.contains (_id))
			return s_base_types [_id] ();
		return AstType_temp::Make (_id);
	} else {
	}

	throw NOT_IMPLEMENT ();
}



std::shared_ptr<IAstType> IAstType::FromCtx (FaParser::TypeMultiContext *_ctx) {
	auto [_types, _names] = FromCtx (_ctx->typeVar ());
	return AstType_tuple_wrap::Make (_types, _names);
}



std::shared_ptr<IAstType> IAstType::FromCtx (FaParser::TypeContext *_ctx) {
	std::shared_ptr<IAstType> _ret;
	if (_ctx->typeSingle ()) {
		_ret = FromCtx (_ctx->typeSingle ());
	} else {
		_ret = FromCtx (_ctx->typeMulti ());
	}
	for (auto _after : _ctx->typeAfter ()) {
		if (_after->quotFangL ()) {
			_ret = std::make_shared<AstType_array_wrap> (_ret);
		} else {
			_ret = std::make_shared<AstType_option_wrap> (_ret);
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



std::tuple<std::shared_ptr<IAstType>, std::string> IAstType::FromCtx (FaParser::TypeWrapVarContext *_ctx) {
	return { FromCtx (_ctx->typeWrap ()), GetId (_ctx->id ()) };
}



std::tuple<std::shared_ptr<IAstType>, std::string> IAstType::FromCtx (FaParser::TypeWrapVar2Context *_ctx) {
	return { FromCtx (_ctx->typeWrap ()), GetId (_ctx->id ()) };
}



std::tuple<std::vector<std::shared_ptr<IAstType>>, std::vector<std::string>> IAstType::FromCtx (FaParser::TypeWrapVarListContext *_ctx) {
	std::vector<std::shared_ptr<IAstType>> _types;
	std::vector<std::string> _names;
	if (_ctx) {
		for (auto _item_ctx : _ctx->typeWrapVar ()) {
			auto [_type, _name] = FromCtx (_item_ctx);
			_types.push_back (_type);
			_names.push_back (_name);
		}
	}
	return { _types, _names };
}



std::tuple<std::vector<std::shared_ptr<IAstType>>, std::vector<std::string>> IAstType::FromCtx (FaParser::TypeWrapVar2ListContext *_ctx) {
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

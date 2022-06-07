#ifndef __AST_CLASS_FUNC_HPP__
#define __AST_CLASS_FUNC_HPP__



#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "IAstBlock.hpp"
#include "../Stmts/IAstStmt.hpp"
#include "../Types/IAstType.hpp"
#include "../../Common.hpp"
#include "../../Exception.hpp"



struct AstClassFunc: public IAstBlock {
	PublicLevel m_level;
	bool m_static;
	std::string m_name;
	PAstType m_ret_type;
	std::vector<PAstType> m_arg_types;
	std::vector<std::string> m_arg_names;
	std::vector<PAstStmt> m_contents;

	AstClassFunc (FaParser::ClassItemFuncContext *_ctx): IAstBlock (_ctx->id ()->start) {
		m_level = GetPublicLevel (_ctx->publicLevel ());
		m_static = !!_ctx->Static ();
		m_name = GetId (_ctx->id ());
		m_ret_type = IAstType::FromCtx (_ctx->type ());
		std::tie (m_arg_types, m_arg_names) = IAstType::FromCtx (_ctx->typeWrapVarList1 ());
		m_contents = IAstStmt::FromCtx (_ctx->classItemFuncExtBody ());
	}

	AstClassFunc (FaParser::ClassItem2Context *_ctx): IAstBlock (_ctx->id ()->start) {
		if (!_ctx->classItemFuncExt2 ())
			throw Exception ("It's looks not a func");
		m_level = GetPublicLevel (_ctx->publicLevel ());
		m_static = !!_ctx->Static ();
		m_name = GetId (_ctx->id ());
		m_ret_type = IAstType::FromCtx (_ctx->type ());
		std::tie (m_arg_types, m_arg_names) = IAstType::FromCtx (_ctx->classItemFuncExt2 ()->typeWrapVarList2 ());
		m_contents = IAstStmt::FromCtx (_ctx->classItemFuncExt2 ()->classItemFuncExtBody ());
	}

	std::string GenCppCode (size_t _indent) override {
		std::stringstream _ss {};
		_ss << std::format ("{}{}{} {} (", Indent (_indent), m_static ? "static " : "", m_ret_type->GenCppCode (_indent), m_name);
		for (size_t i = 0; i < m_arg_types.size (); ++i) {
			if (i > 0)
				_ss << ", ";
			_ss << std::format ("{} {}", m_arg_types [i]->GenCppCode (_indent), m_arg_names [i]);
		}
		_ss << ") {\n";
		for (auto _content : m_contents)
			_ss << _content->GenCppCode (_indent + 1);
		_ss << std::format ("{}}}\n", Indent (_indent));
		return _ss.str ();
	}

	static std::shared_ptr<AstClassFunc> FromCtx (FaParser::ClassItemFuncContext *_ctx) {
		return std::make_shared<AstClassFunc> (_ctx);
	}

	static std::shared_ptr<AstClassFunc> FromCtx (FaParser::ClassItem2Context *_ctx) {
		return std::make_shared<AstClassFunc> (_ctx);
	}
};



#endif //__AST_CLASS_FUNC_HPP__

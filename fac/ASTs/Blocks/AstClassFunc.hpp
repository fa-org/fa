#ifndef __AST_CLASS_FUNC_HPP__
#define __AST_CLASS_FUNC_HPP__



#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "../IAst.hpp"
#include "../Stmts/IAstStmt.hpp"
#include "../Types/IAstType.hpp"
#include "../../Common.hpp"
#include "../../Exception.hpp"



struct AstClassFunc: public IAst {
	PublicLevel m_level;
	std::string m_name;
	std::shared_ptr<IAstType> m_ret_type;
	std::vector<std::shared_ptr<IAstType>> m_arg_types;
	std::vector<std::string> m_arg_names;
	std::vector<std::shared_ptr<IAstStmt>> m_contents;

	AstClassFunc (FaParser::ClassItemContext *_ctx) {
		if (!_ctx->classItemFuncExt ())
			throw Exception ("It's looks not a func");
		m_level = GetPublicLevel (_ctx->publicLevel ());
		m_name = GetId (_ctx->id ());
		m_ret_type = IAstType::FromCtx (_ctx->type ());
		std::tie (m_arg_types, m_arg_names) = IAstType::FromCtx (_ctx->classItemFuncExt ()->typeWrapVarList ());
		m_contents = IAstStmt::FromCtx (_ctx->classItemFuncExt ()->classItemFuncExtBody ());
	}

	std::string GenCppCode (size_t _indent) override {
		std::stringstream _ss {};
		_ss << std::format ("{}{} {} (", Indent (_indent), m_ret_type->GenCppCode (), m_name);
		for (size_t i = 0; i < m_arg_types.size (); ++i) {
			if (i > 0)
				_ss << ", ";
			_ss << std::format ("{} {}", m_arg_types [i]->GenCppCode (), m_arg_names [i]);
		}
		_ss << ") {\n";
		for (auto _content : m_contents)
			_ss << _content->GenCppCode (_indent + 1);
		_ss << std::format ("{}}}\n", Indent (_indent));
		return _ss.str ();
	}

	static std::shared_ptr<AstClassFunc> FromCtx (FaParser::ClassItemContext *_ctx) {
		return std::make_shared<AstClassFunc> (_ctx);
	}
};



#endif //__AST_CLASS_FUNC_HPP__

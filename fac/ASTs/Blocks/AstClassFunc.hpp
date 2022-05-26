#ifndef __AST_CLASS_FUNC_HPP__
#define __AST_CLASS_FUNC_HPP__



#include <memory>
#include <string>
#include <vector>

#include "../Stmts/IAstStmt.hpp"
#include "../Types/IAstType.hpp"
#include "../../Common.hpp"
#include "../../Exception.hpp"



struct AstClassFunc {
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
		m_ret_type = IAstType::FromCtx (_ctx->type ());
		std::tie (m_arg_types, m_arg_names) = IAstType::FromCtx (_ctx->classItemFuncExt ()->typeWrapVarList ());
		m_contents = IAstStmt::FromCtx (_ctx->classItemFuncExt ()->classItemFuncExtBody ());
	}

	static std::shared_ptr<AstClassFunc> FromCtx (FaParser::ClassItemContext *_ctx) {
		return std::make_shared<AstClassFunc> (_ctx);
	}
};



#endif //__AST_CLASS_FUNC_HPP__
#ifndef __AST_CLASS_FUNC_HPP__
#define __AST_CLASS_FUNC_HPP__



#include <memory>
#include <string>
#include <vector>

#include "../Stmts/AstStmt.hpp"
#include "../Types/AstType.hpp"
#include "../../Common.hpp"



struct AstClassFunc {
	PublicLevel m_level;
	std::string m_name;
	std::shared_ptr<AstType> m_ret_type;
	std::vector<std::shared_ptr<AstType>> m_arg_types;
	std::vector<std::string> m_arg_names;
	std::vector<std::shared_ptr<AstStmt>> m_contents;

	AstClassFunc (FaParser::ClassItemContext *_ctx) {
		if (!_ctx->classItemFuncExt ())
			throw Exception ("It's looks not a func");
		m_level = GetPublicLevel (_ctx->publicLevel ());
		m_ret_type = std::make_shared<AstType> (_ctx->type ());
		std::tie (m_arg_types, m_arg_names) = AstType::FromCtx (_ctx->classItemFuncExt ()->typeWrapVarList ());
		m_contents = AstStmt::FromCtx (_ctx->classItemFuncExt ()->classItemFuncExtBody ());
	}
};



#endif //__AST_CLASS_FUNC_HPP__

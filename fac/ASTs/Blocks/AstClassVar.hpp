#ifndef __AST_CLASS_VAR_HPP__
#define __AST_CLASS_VAR_HPP__



#include <memory>
#include <string>

#include "IAstBlock.hpp"
#include "../Types/IAstType.hpp"
#include "../../Common.hpp"
#include "../../Exception.hpp"



struct AstClassVar: public IAstBlock {
	PublicLevel m_level;
	std::string m_name = "";
	PAstType m_type;

	AstClassVar (FaParser::ClassItem2Context *_ctx): IAstBlock (_ctx->id ()->start) {
		if (_ctx->classItemFuncExt2 ())
			throw Exception ("It's looks not a var");
		m_level = GetPublicLevel (_ctx->publicLevel ());
		m_type = IAstType::FromCtx (_ctx->type ());
		m_name = GetId (_ctx->id ());
	}

	AstClassVar (FaParser::ClassItemVarContext *_ctx): IAstBlock (_ctx->id ()->start) {
		m_level = GetPublicLevel (_ctx->publicLevel ());
		m_type = IAstType::FromCtx (_ctx->type ());
		m_name = GetId (_ctx->id ());
	}

	void ProcessCode () override {
		throw NOT_IMPLEMENT ();
	}

	std::string GenCppCode (size_t _indent) override {
		return std::format ("{}{} {};\n", Indent (_indent), m_type->GenCppCode (_indent), m_name);
	}

	static std::shared_ptr<AstClassVar> FromCtx (FaParser::ClassItem2Context *_ctx) {
		return std::make_shared<AstClassVar> (_ctx);
	}

	static std::shared_ptr<AstClassVar> FromCtx (FaParser::ClassItemVarContext *_ctx) {
		return std::make_shared<AstClassVar> (_ctx);
	}
};



#endif //__AST_CLASS_VAR_HPP__

#ifndef __AST_CLASS_VALUE_VAR_HPP__
#define __AST_CLASS_VALUE_VAR_HPP__



#include <memory>
#include <string>

#include "IAstBlock.hpp"
#include "../Exprs/IAstExpr.hpp"
#include "../Stmts/IAstStmt.hpp"
#include "../Types/IAstType.hpp"
#include "../../common/Evaluation.hpp"



struct AstClassValueVar;
using PAstClassValueVar = std::shared_ptr<AstClassValueVar>;

struct AstClassValueVar: public IAstBlock {
	fa::PublicLevel m_level;
	std::string m_name = "";
	PAstType m_type;
	std::optional<PAstExpr> m_init_value;

	AstClassValueVar (antlr4::Token *_token): IAstBlock (_token), m_level (fa::PublicLevel::Public), m_type (nullptr), m_init_value (std::nullopt) {}

	void ProcessDeclareType () override {
		if (m_type)
			m_type = m_type->ProcessDeclareType ();
	}

	void ProcessCodeType () override {
		if (m_init_value.has_value ()) {
			m_init_value = m_init_value.value ()->ProcessCodeType (m_type);
		}
	}

	PAstExpr GetRef () {
		throw fa::Exception (m_token, "not implement");
	}

	//static std::map<std::string, std::shared_ptr<AstClassValueVar>> FromCtxs (std::vector<FaParser::ClassVarContext *> _ctx) {
	//	std::map<std::string, std::shared_ptr<AstClassValueVar>> _v;
	//	for (auto &_ctx_item : _ctx) {
	//		auto _item = FromCtx (_ctx_item);
	//		_v [_item->m_name] = _item;
	//	}
	//	return _v;
	//}

	//static std::map<std::string, std::shared_ptr<AstClassValueVar>> FromCtxs (std::vector<FaParser::TypeNameAssignOpTupleContext *> _ctx) {
	//	std::map<std::string, std::shared_ptr<AstClassValueVar>> _v;
	//	for (auto &_ctx_item : _ctx) {
	//		auto _item = FromCtx (_ctx_item);
	//		_v [_item->m_name] = _item;
	//	}
	//	return _v;
	//}
};



#endif //__AST_CLASS_VALUE_VAR_HPP__

#ifndef __AST_EXPR_TYPE_WRAP_HPP__
#define __AST_EXPR_TYPE_WRAP_HPP__



#include <map>
#include <memory>
#include <sstream>
#include <string>

#include "IAstExpr.hpp"
#include "../Types/IAstType.hpp"
#include "../../common/CompileEnv.hpp"



struct AstExpr_type_wrap: public IAstExpr {
	PAstType m_type;

	AstExpr_type_wrap (antlr4::Token *_token): IAstExpr (_token), m_type (nullptr) {}
	AstExpr_type_wrap (antlr4::Token *_token, PAstType _type): IAstExpr (_token), m_type (_type) {}

	std::optional<PAstType> GuessType () override { throw fa::Exception (m_token, "not implement"); }

	PAstExpr ProcessCodeType (std::optional<PAstType> _type) override { throw fa::Exception (m_token, "not implement"); }

	std::optional<PAstExpr> Evaluate (Evaluation &_eval) override { throw fa::Exception (m_token, "not implement"); }

	static PAstExpr Make (antlr4::Token *_token, PAstType _type) {
		return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstExpr_type_wrap { _token, _type });
	}
};



#endif //__AST_EXPR_TYPE_WRAP_HPP__

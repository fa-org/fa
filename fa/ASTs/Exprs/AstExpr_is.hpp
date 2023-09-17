#ifndef __AST_EXPR_IS_HPP__
#define __AST_EXPR_IS_HPP__



#include <memory>
#include <string>

#include "IAstExpr.hpp"
#include "../Types/IAstType.hpp"



struct AstExpr_is: public IAstExpr {
	PAstExpr m_base;
	PAstType m_to_type;
	std::string m_to_varname = "";

	AstExpr_is (antlr4::Token *_token): IAstExpr (_token), m_base (nullptr), m_to_type (nullptr) {}
	AstExpr_is (antlr4::Token *_token, PAstExpr _base, PAstType _to_type, std::string _to_varname):
		IAstExpr (_token), m_base (_base), m_to_type (_to_type), m_to_varname (_to_varname) {}

	std::optional<PAstType> GuessType () override { throw fa::Exception (m_token, "not implement"); }

	PAstExpr ProcessCodeType (std::optional<PAstType> _type) override { throw fa::Exception (m_token, "not implement"); }

	std::optional<PAstExpr> Evaluate (Evaluation &_eval) override { throw fa::Exception (m_token, "not implement"); }

	static PAstExpr Make (antlr4::Token *_token, PAstExpr _base, PAstType _to_type, std::string _to_varname) {
		return std::shared_ptr<IAstExpr> (new AstExpr_is { _token, _base, _to_type, _to_varname });
	}
};



#endif //__AST_EXPR_IS_HPP__

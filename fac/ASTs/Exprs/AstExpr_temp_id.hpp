#ifndef __AST_EXPR_TEMP_ID_HPP__
#define __AST_EXPR_TEMP_ID_HPP__



#include <memory>
#include <string>

#include "IAstExpr.hpp"



struct AstExpr_temp_id: public IAstExpr {
	std::string m_id;

	AstExpr_temp_id (antlr4::Token *_token, std::string _id):
		IAstExpr (_token), m_id (_id) {}

	std::string GenCppCode (size_t _indent) override { throw NOT_IMPLEMENT (); }

	static std::shared_ptr<IAstExpr> Make (antlr4::Token *_token, std::string _id) {
		return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstExpr_temp_id { _token, _id });
	}
};



#endif //__AST_EXPR_TEMP_ID_HPP__

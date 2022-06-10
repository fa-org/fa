#ifndef __AST_EXPR_TEMP_ID_HPP__
#define __AST_EXPR_TEMP_ID_HPP__



#include <memory>
#include <string>

#include "IAstExpr.hpp"



struct AstExpr_temp_id: public IAstExpr {
	std::string m_id;

	AstExpr_temp_id (antlr4::Token *_token, std::string _id):
		IAstExpr (_token), m_id (_id) {}



	void GetChildTypes (std::function<void (PAstType &)> _cb) override {}
	void GetChildExprs (std::function<void (PAstExpr &)> _cb) override {}
	void GetChildStmts (std::function<void (PAstStmt &)> _cb) override {}



	PAstType GuessType () override { throw NOT_IMPLEMENT (); }

	void ProcessCode (PAstType _type) override { throw NOT_IMPLEMENT (); }

	std::string GenCppCode (size_t _indent) override { throw NOT_IMPLEMENT (); }



	static PAstExpr Make (antlr4::Token *_token, std::string _id) { return new AstExpr_temp_id { _token, _id }; }
};



#endif //__AST_EXPR_TEMP_ID_HPP__

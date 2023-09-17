#ifndef __AST_STMT_BREAK_HPP__
#define __AST_STMT_BREAK_HPP__



#include <memory>
#include <vector>

#include "IAstStmt.hpp"
#include "../Exprs/IAstExpr.hpp"



struct AstStmt_break: public IAstStmt {
	AstStmt_break (antlr4::Token *_token): IAstStmt (_token) {}

	PAstStmt ProcessCodeType () override { return shared_from_this (); }

	void Evaluate (Evaluation &_eval) override { throw fa::Exception (m_token, "not implement"); }

	static PAstStmt Make (antlr4::Token *_token) {
		return std::shared_ptr<IAstStmt> (new AstStmt_break { _token });
	}
};



#endif //__AST_STMT_BREAK_HPP__

#ifndef __AST_STMT_EXPR_WRAP_HPP__
#define __AST_STMT_EXPR_WRAP_HPP__



#include <format>
#include <memory>
#include <vector>

#include "IAstStmt.hpp"
#include "../Exprs/IAstExpr.hpp"



struct AstStmt_expr_wrap: public IAstStmt {
	PAstExpr m_expr;

	AstStmt_expr_wrap (antlr4::Token *_token): IAstStmt (_token), m_expr (nullptr) {}
	AstStmt_expr_wrap (PAstExpr _expr): IAstStmt (_expr->m_token),  m_expr (_expr) {}

	void SetMembers (fa::ParseType _type, std::vector<AstObj *> _values) override {
		if (_type == fa::ParseType::Part_Member) {
			m_expr = std::shared_ptr<IAstExpr> (dynamic_cast<IAstExpr *> (_values [0]));
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	PAstStmt ProcessCodeType () override {
		m_expr = m_expr->ProcessCodeType (std::nullopt);
		return shared_from_this ();
	}

	void Evaluate (Evaluation &_eval) override { m_expr->Evaluate (_eval); }

	static PAstStmt Make (PAstExpr _expr) { return std::shared_ptr<IAstStmt> (new AstStmt_expr_wrap { _expr }); }
};



#endif //__AST_STMT_EXPR_WRAP_HPP__

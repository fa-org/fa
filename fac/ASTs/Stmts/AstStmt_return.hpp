#ifndef __AST_STMT_RETURN_HPP__
#define __AST_STMT_RETURN_HPP__



#include <format>
#include <memory>
#include <vector>

#include "IAstStmt.hpp"
#include "../Exprs/IAstExpr.hpp"
#include "../../Common.hpp"



struct AstStmt_return: public IAstStmt {
	std::shared_ptr<IAstExpr> m_expr;

	AstStmt_return (antlr4::Token *_token, std::shared_ptr<IAstExpr> _expr): IAstStmt (_token), m_expr (_expr) {}

	std::string GenCppCode (size_t _indent) override {
		if (m_expr) {
			return std::format ("{}return {};\n", Indent (_indent), m_expr->GenCppCode (_indent));
		} else {
			return std::format ("{}return;\n", Indent (_indent));
		}
	}

	static std::shared_ptr<IAstStmt> FromExpr (antlr4::Token *_token, std::shared_ptr<IAstExpr> _expr) {
		return std::shared_ptr<IAstStmt> ((IAstStmt *) new AstStmt_return { _token, _expr });
	}
};



#endif //__AST_STMT_RETURN_HPP__

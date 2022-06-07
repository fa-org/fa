#ifndef __AST_STMT_RETURN_HPP__
#define __AST_STMT_RETURN_HPP__



#include <format>
#include <memory>
#include <vector>

#include "IAstStmt.hpp"
#include "../Exprs/IAstExpr.hpp"
#include "../../Common.hpp"



struct AstStmt_return: public IAstStmt {
	PAstExpr m_expr;

	AstStmt_return (antlr4::Token *_token, PAstExpr _expr): IAstStmt (_token), m_expr (_expr) {}

	std::string GenCppCode (size_t _indent) override {
		if (m_expr) {
			return std::format ("{}return {};\n", Indent (_indent), m_expr->GenCppCode (_indent));
		} else {
			return std::format ("{}return;\n", Indent (_indent));
		}
	}

	void GetChildTypes (std::function<void (PAstType &)> _cb) override {}

	void GetChildExprs (std::function<void (PAstExpr &)> _cb) override { _cb (m_expr); }

	void GetChildStmts (std::function<void (PAstStmt &)> _cb) override {}

	static PAstStmt FromExpr (antlr4::Token *_token, PAstExpr _expr) {
		return new AstStmt_return { _token, _expr };
	}
};



#endif //__AST_STMT_RETURN_HPP__

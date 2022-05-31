#ifndef __AST_STMT_DEFINE_VAR_HPP__
#define __AST_STMT_DEFINE_VAR_HPP__



#include <format>
#include <memory>
#include <string>
#include <vector>

#include "IAstStmt.hpp"
#include "../Types/IAstType.hpp"
#include "../Exprs/IAstExpr.hpp"



struct AstStmt_define_var: public IAstStmt {
	std::shared_ptr<IAstType> m_type;
	std::string m_name;
	std::shared_ptr<IAstExpr> m_expr;

	AstStmt_define_var (antlr4::Token *_token, std::shared_ptr<IAstType> _type, std::string _name, std::shared_ptr<IAstExpr> _expr):
		IAstStmt (_token), m_type (_type), m_name (_name), m_expr (_expr) {}

	std::string GenCppCode (size_t _indent) override { return std::format ("{}{} {} = {};\n", Indent (_indent), m_type->GenCppCode (), m_name, m_expr->GenCppCode (_indent)); }

	static std::shared_ptr<IAstStmt> Make (antlr4::Token *_token, std::shared_ptr<IAstType> _type, std::string _name, std::shared_ptr<IAstExpr> _expr) {
		return std::shared_ptr<IAstStmt> ((IAstStmt *) new AstStmt_define_var { _token, _type, _name, _expr });
	}
};



#endif //__AST_STMT_DEFINE_VAR_HPP__

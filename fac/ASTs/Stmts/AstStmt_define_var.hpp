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
	PAstType m_type;
	std::string m_name;
	PAstExpr m_expr;

	AstStmt_define_var (antlr4::Token *_token, PAstType _type, std::string _name, PAstExpr _expr):
		IAstStmt (_token), m_type (_type), m_name (_name), m_expr (_expr) {}

	std::string GenCppCode (size_t _indent) override { return std::format ("{}{} {} = {};\n", Indent (_indent), m_type->GenCppCode (), m_name, m_expr->GenCppCode (_indent)); }

	static PAstStmt Make (antlr4::Token *_token, PAstType _type, std::string _name, PAstExpr _expr) {
		return new AstStmt_define_var { _token, _type, _name, _expr };
	}
};



#endif //__AST_STMT_DEFINE_VAR_HPP__

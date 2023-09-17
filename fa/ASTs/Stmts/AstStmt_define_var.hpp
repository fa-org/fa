#ifndef __AST_STMT_DEFINE_VAR_HPP__
#define __AST_STMT_DEFINE_VAR_HPP__



#include <format>
#include <memory>
#include <optional>
#include <string>
#include <vector>

#include "IAstStmt.hpp"
#include "../Types/AstType_class.hpp"
#include "../Types/IAstType.hpp"
#include "../Exprs/IAstExpr.hpp"
#include "../../common/Evaluation.hpp"



struct AstStmt_define_var: public IAstStmt {
	std::optional<PAstType> m_type = std::nullopt;
	std::string m_name = "";
	std::optional<PAstExpr> m_expr = std::nullopt;

	AstStmt_define_var (antlr4::Token *_token): IAstStmt (_token) {}
	AstStmt_define_var (antlr4::Token *_token, std::optional<PAstType> _type, std::string _name, std::optional<PAstExpr> _expr): IAstStmt (_token), m_type (_type), m_name (_name), m_expr (_expr) {}

	PAstStmt ProcessCodeType () override;

	void Evaluate (Evaluation &_eval) override;

	static PAstStmt Make (antlr4::Token *_token, std::optional<PAstType> _type, std::string _name, std::optional<PAstExpr> _expr = std::nullopt) {
		return std::shared_ptr<IAstStmt> (new AstStmt_define_var { _token, _type, _name, _expr });
	}
};



#endif //__AST_STMT_DEFINE_VAR_HPP__

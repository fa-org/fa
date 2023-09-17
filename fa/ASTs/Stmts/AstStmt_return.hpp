#ifndef __AST_STMT_RETURN_HPP__
#define __AST_STMT_RETURN_HPP__



#include <format>
#include <memory>
#include <optional>
#include <vector>

#include "IAstStmt.hpp"
#include "../Blocks/AstClassFuncEmpty.hpp"
#include "../Exprs/IAstExpr.hpp"
#include "../Types/IAstType.hpp"
#include "../../common/CompileEnv.hpp"



struct AstStmt_return: public IAstStmt {
	std::optional<PAstExpr> m_expr;

	AstStmt_return (antlr4::Token *_token): IAstStmt (_token), m_expr (std::nullopt) {}
	AstStmt_return (antlr4::Token *_token, PAstExpr _expr): IAstStmt (_token), m_expr (_expr) {}

	void SetMembers (fa::ParseType _type, std::vector<AstObj *> _values) override {
		if (_type == fa::ParseType::Part_Member) {
			m_expr = std::shared_ptr<IAstExpr> (dynamic_cast<IAstExpr *> (_values [0]));
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	PAstStmt ProcessCodeType () override {
		if (m_expr.has_value ())
			m_expr = m_expr.value ()->ProcessCodeType (CompileEnv::CurrentFunc->m_ret_type);
		return shared_from_this ();
	}

	void Evaluate (Evaluation &_eval) override {
		_eval.m_return = true;
		if (m_expr.has_value ())
			_eval.m_return_expr = m_expr.value ()->Evaluate (_eval);
	}

	static PAstStmt FromExpr (antlr4::Token *_token, PAstExpr _expr) {
		return std::shared_ptr<IAstStmt> (new AstStmt_return { _token, _expr });
	}
};



#endif //__AST_STMT_RETURN_HPP__

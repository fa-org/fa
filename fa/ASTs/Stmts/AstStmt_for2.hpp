#ifndef __AST_STMT_FOR2_HPP__
#define __AST_STMT_FOR2_HPP__



#include <format>
#include <memory>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

#include "AstStmt_define_var.hpp"
#include "IAstStmt.hpp"
#include "../Types/AstType_class.hpp"
#include "../Types/IAstType.hpp"
#include "../Exprs/IAstExpr.hpp"
#include "../../common/Evaluation.hpp"



struct AstStmt_for2: public IAstStmt {
	std::optional<PAstStmt> m_init_stmt;
	std::optional<PAstExpr> m_cond_expr;
	std::optional<PAstExpr> m_inc_expr;
	std::vector<PAstStmt> m_body;

	AstStmt_for2 (antlr4::Token *_token): IAstStmt (_token), m_init_stmt (std::nullopt), m_cond_expr (std::nullopt), m_inc_expr (std::nullopt) {}

	void SetMembers (fa::ParseType _type, std::vector<AstObj *> _values) override {
		if (_type == fa::ParseType::Part_Init) {
			m_init_stmt = std::shared_ptr<IAstStmt> (dynamic_cast<IAstStmt *> (_values [0]));
		} else if (_type == fa::ParseType::Part_Condition) {
			m_cond_expr = std::shared_ptr<IAstExpr> (dynamic_cast<IAstExpr *> (_values [0]));
		} else if (_type == fa::ParseType::Part_Increment) {
			m_inc_expr = std::shared_ptr<IAstExpr> (dynamic_cast<IAstExpr *> (_values [0]));
		} else if (_type == fa::ParseType::Part_Member2) {
			for (size_t i = 0; i < _values.size (); ++i) {
				m_body.push_back (std::shared_ptr<IAstStmt> (dynamic_cast<IAstStmt *> (_values [i])));
			}
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	PAstStmt ProcessCodeType () override {
		// ÕûÀí´úÂë
		if (m_init_stmt.has_value ())
			m_init_stmt = m_init_stmt.value ()->ProcessCodeType ();
		if (m_cond_expr.has_value ())
			m_cond_expr = m_cond_expr.value ()->ProcessCodeType (AstType_bool::Make (m_token));
		if (m_inc_expr.has_value ())
			m_inc_expr = m_inc_expr.value ()->ProcessCodeType (std::nullopt);
		for (auto &_item : m_body)
			_item = _item->ProcessCodeType ();
		return shared_from_this ();
	}

	void Evaluate (Evaluation &_eval) override { throw fa::Exception (m_token, "not implement"); }
};



#endif //__AST_STMT_FOR2_HPP__

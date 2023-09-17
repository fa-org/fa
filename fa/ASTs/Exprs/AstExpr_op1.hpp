#ifndef __AST_EXPR_OP1_HPP__
#define __AST_EXPR_OP1_HPP__



#include <memory>
#include <string>

#include "NameExprs/IAstNameExpr.hpp"
#include "AstExpr_temp_name.hpp"
#include "IAstExpr.hpp"
#include "../Stmts/IAstStmt.hpp"



struct AstExpr_op1: public IAstExpr {
	PAstExpr m_base;
	std::string m_op = "";
	bool m_prefix;

	AstExpr_op1 (antlr4::Token *_token): IAstExpr (_token), m_base (nullptr), m_prefix (true) {}
	AstExpr_op1 (antlr4::Token *_token, PAstExpr _base, std::string _op, bool _prefix):
		IAstExpr (_token), m_base (_base), m_op (_op), m_prefix (_prefix) {}

	void SetMembers (fa::ParseType _type, std::vector<AstObj *> _values) override {
		if (_type == fa::ParseType::Part_Member) {
			m_base = std::shared_ptr<IAstExpr> (dynamic_cast<IAstExpr *> (_values [0]));
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	void SetValues (fa::ParseValueType _type, std::vector<fa::ParseValue_t> _values) override {
		if (_type == fa::ParseValueType::Operator) {
			m_op = std::get<std::string> (_values [0]);
			if (m_op [0] == ' ') {
				m_prefix = false;
				m_op.erase (m_op.begin ());
			} else {
				m_prefix = true;
			}
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	std::optional<PAstType> GuessType () override { throw fa::Exception (m_token, "not implement"); }

	PAstExpr ProcessCodeType (std::optional<PAstType> _type) override {
		m_base = m_base->ProcessCodeType (_type);
		return shared_from_this ();
	}

	std::optional<PAstExpr> Evaluate (Evaluation &_eval) override { throw fa::Exception (m_token, "not implement"); }

	static PAstExpr Make (antlr4::Token *_token, PAstExpr _base, std::string _op, bool _prefix) {
		return std::shared_ptr<IAstExpr> (new AstExpr_op1 { _token, _base, _op, _prefix });
	}
};



#endif //__AST_EXPR_OP1_HPP__

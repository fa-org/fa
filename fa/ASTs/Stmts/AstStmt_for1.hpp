#ifndef __AST_STMT_FOR1_HPP__
#define __AST_STMT_FOR1_HPP__



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



struct AstStmt_for1: public IAstStmt {
	std::vector<PAstType> m_var_types;
	std::vector<std::string> m_var_names;
	bool m_var_unwrap = false;
	PAstExpr m_arr_expr;
	std::vector<PAstStmt> m_body;

	AstStmt_for1 (antlr4::Token *_token): IAstStmt (_token), m_arr_expr (nullptr) {}
	AstStmt_for1 (antlr4::Token *_token, PAstExpr _arr_expr): IAstStmt (_token), m_arr_expr (_arr_expr) {}

	void SetMembers (fa::ParseType _type, std::vector<AstObj *> _values) override {
		if (_type == fa::ParseType::Part_Member) {
			m_arr_expr = std::shared_ptr<IAstExpr> (dynamic_cast<IAstExpr *> (_values [0]));
		} else if (_type == fa::ParseType::Part_Member2) {
			for (size_t i = 0; i < _values.size (); ++i)
				m_body.push_back (std::shared_ptr<IAstStmt> (dynamic_cast<IAstStmt *> (_values [i])));
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	void SetValues (fa::ParseValueType _type, std::vector<fa::ParseValue_t> _values) override {
		if (_type == fa::ParseValueType::VarName) {
			for (size_t i = 0; i < _values.size (); ++i) {
				m_var_names.push_back (std::get<std::string> (_values [i]));
			}
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	PAstStmt ProcessCodeType () override;

	void Evaluate (Evaluation &_eval) override;
};



#endif //__AST_STMT_FOR1_HPP__

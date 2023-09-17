#ifndef __AST_STMT_DEFINE_VAR_GROUP_HPP__
#define __AST_STMT_DEFINE_VAR_GROUP_HPP__



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
#include "AstStmt_define_var.hpp"



struct AstStmt_define_var_group: public IAstStmt {
	std::vector<PAstStmt> m_vars;

	AstStmt_define_var_group (antlr4::Token *_token): IAstStmt (_token) {}
	AstStmt_define_var_group (antlr4::Token *_token, std::optional<PAstType> _type, std::string _name, std::optional<PAstExpr> _expr): IAstStmt (_token) {
		m_vars.push_back (AstStmt_define_var::Make (_token, _type, _name, _expr));
	}

	void SetMembers (fa::ParseType _type, std::vector<AstObj *> _values) override {
		while (m_vars.size () < _values.size ())
			m_vars.push_back (AstStmt_define_var::Make (m_token, std::nullopt, "", std::nullopt));
		if (_type == fa::ParseType::Part_Type) {
			for (size_t i = 0; i < _values.size (); ++i) {
				auto _var = dynamic_cast<AstStmt_define_var *> (m_vars [i].get ());
				_var->m_type = std::shared_ptr<IAstType> (dynamic_cast<IAstType *> (_values [i]));
			}
		} else if (_type == fa::ParseType::Part_Value) {
			for (size_t i = 0; i < _values.size (); ++i) {
				auto _var = dynamic_cast<AstStmt_define_var *> (m_vars [i].get ());
				_var->m_expr = std::shared_ptr<IAstExpr> (dynamic_cast<IAstExpr *> (_values [i]));
			}
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	void SetValues (fa::ParseValueType _type, std::vector<fa::ParseValue_t> _values) override {
		while (m_vars.size () < _values.size ())
			m_vars.push_back (AstStmt_define_var::Make (m_token, std::nullopt, "", std::nullopt));
		if (_type == fa::ParseValueType::Name) {
			for (size_t i = 0; i < _values.size (); ++i) {
				auto _var = dynamic_cast<AstStmt_define_var *> (m_vars [i].get ());
				_var->m_name = std::get<std::string> (_values [i]);
			}
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	PAstStmt ProcessCodeType () override {
		for (size_t i = 0; i < m_vars.size (); ++i)
			m_vars [i]->ProcessCodeType ();
		return shared_from_this ();
	}

	void Evaluate (Evaluation &_eval) override {
		for (size_t i = 0; i < m_vars.size (); ++i)
			m_vars [i]->Evaluate (_eval);
	}

	static PAstStmt Make (antlr4::Token *_token, std::optional<PAstType> _type, std::string _name, std::optional<PAstExpr> _expr = std::nullopt) {
		return std::shared_ptr<IAstStmt> (new AstStmt_define_var_group { _token, _type, _name, _expr });
	}
};



#endif //__AST_STMT_DEFINE_VAR_GROUP_HPP__

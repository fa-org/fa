#ifndef __AST_NAME_EXPR_VARIABLE_HPP__
#define __AST_NAME_EXPR_VARIABLE_HPP__



#include <memory>
#include <optional>
#include <tuple>
#include <vector>

#include "IAstNameExpr.hpp"
#include "../AstExpr_array1.hpp"
#include "../../Stmts/AstStmt_define_var_group.hpp"
#include "../../Stmts/AstStmt_for1.hpp"
#include "../../Stmts/IAstStmt.hpp"



struct AstNameExpr_var: public IAstNameExpr {
	std::string m_varname = "";
	std::variant<PAstStmt, PAstExpr> m_defvar;

	AstNameExpr_var (antlr4::Token *_token, std::string _varname, std::variant<PAstStmt, PAstExpr> _defvar):
		IAstNameExpr (_token), m_varname (_varname), m_defvar (_defvar) {
		if (m_defvar.index () == 0) {
			if (auto _defvar = dynamic_cast<AstStmt_define_var *> (std::get<PAstStmt> (m_defvar).get ())) {
				if (_defvar->m_name == _varname) {
					m_real_type = _defvar->m_type;
					return;
				}
			} else if (auto _for_stmt = dynamic_cast<AstStmt_for1 *> (std::get<PAstStmt> (m_defvar).get ())) {
				for (size_t i = 0; i < _for_stmt->m_var_names.size (); ++i) {
					if (_for_stmt->m_var_names [i] == _varname) {
						m_real_type = _for_stmt->m_var_types [i];
						return;
					}
				}
			}
		} else {
			if (auto _array1_expr = dynamic_cast<AstExpr_array1 *> (std::get<PAstExpr> (m_defvar).get ())) {
				for (size_t i = 0; i < _array1_expr->m_var_names.size (); ++i) {
					if (_array1_expr->m_var_names [i] == _varname) {
						m_real_type = _array1_expr->m_var_types [i];
						return;
					}
				}
			}
		}
		throw fa::Exception (_token, "not implement");
	}

	std::optional<PAstExpr> Evaluate (Evaluation &_eval) override {
		if (auto _oval = _eval.m_vars.Find (shared_from_this ()))
			return _oval.value ();
		throw fa::Exception (m_token, "not implement");
	}

	bool IsSameVar (IAstNameExpr *_other) const override {
		auto _other1 = dynamic_cast<typename decltype (this)> (_other);
		if (!_other1)
			return false;
		if (m_defvar.index () != _other1->m_defvar.index ())
			return false;
		if (m_defvar.index () == 0) {
			return std::get<0> (m_defvar).get () == std::get<0> (_other1->m_defvar).get ();
		} else {
			return std::get<1> (m_defvar).get () == std::get<1> (_other1->m_defvar).get ();
		}
	}

	std::string GetName () const override { return m_varname; }

	static PAstExpr Make (antlr4::Token *_token, std::string _varname, std::variant<PAstStmt, PAstExpr> _defvar) {
		return std::shared_ptr<IAstExpr> (new AstNameExpr_var { _token, _varname, _defvar });
	}
};



#endif //__AST_NAME_EXPR_VARIABLE_HPP__

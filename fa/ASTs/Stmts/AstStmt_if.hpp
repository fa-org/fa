#ifndef __AST_STMT_IF_HPP__
#define __AST_STMT_IF_HPP__



#include <format>
#include <memory>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

#include "AstStmt_define_var.hpp"
#include "IAstStmt.hpp"
#include "../Exprs/IAstExpr.hpp"
#include "../Stmts/IAstStmt.hpp"
#include "../Types/AstType_class.hpp"
#include "../Types/IAstType.hpp"
#include "../../common/Evaluation.hpp"



struct AstStmt_if: public IAstStmt {
	PAstExpr m_cond_expr;
	std::vector<PAstStmt> m_true_stmts, m_false_stmts;

	AstStmt_if (antlr4::Token *_token): IAstStmt (_token), m_cond_expr (nullptr) {}
	AstStmt_if (antlr4::Token *_token, PAstExpr _cond_expr, std::vector<PAstStmt> _true_stmts, std::vector<PAstStmt> _false_stmts): IAstStmt (_token), m_cond_expr (_cond_expr) {}

	void SetMembers (fa::ParseType _type, std::vector<AstObj *> _values) override {
		AstStmt_if *_ptr = this;
		if (_type == fa::ParseType::Part_Condition) {
			for (size_t i = 0; i < _values.size (); ++i) {
				_ptr->m_cond_expr = std::shared_ptr<IAstExpr> (dynamic_cast<IAstExpr *> (_values [i]));
				if (i < _values.size () - 1) {
					auto _ptr2 = new AstStmt_if (m_token);
					_ptr->m_false_stmts.push_back (std::shared_ptr<IAstStmt> (_ptr2));
					_ptr = _ptr2;
				}
			}
		} else if (_type == fa::ParseType::Part_Member2) {
			for (size_t i = 0; i < _values.size (); ++i) {
				auto _p = std::shared_ptr<IAstStmt> (dynamic_cast<IAstStmt *> (_values [i]));
				if (i < _values.size () - 1) {
					_ptr->m_true_stmts.push_back (_p);
					_ptr = dynamic_cast<AstStmt_if *> (_ptr->m_false_stmts [0].get ());
				} else {
					_ptr->m_false_stmts.push_back (_p);
				}
			}
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	PAstStmt ProcessCodeType () override {
		m_cond_expr = m_cond_expr->ProcessCodeType (AstType_bool::Make (m_token));
		auto _process_items = [this] (std::vector<PAstStmt> &_stmts) {
			CompileEnv::CurrentFuncVariables.AddLevel ();
			for (size_t i = 0; i < _stmts.size (); ++i)
				_stmts [i] = _stmts [i]->ProcessCodeType ();
			CompileEnv::CurrentFuncVariables.RemoveLevel ();
		};
		_process_items (m_true_stmts);
		_process_items (m_false_stmts);
		return shared_from_this ();
	}

	void Evaluate (Evaluation &_eval) override { throw fa::Exception (m_token, "not implement"); }
};



#endif //__AST_STMT_IF_HPP__

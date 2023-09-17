#ifndef __AST_EXPR_IF_HPP__
#define __AST_EXPR_IF_HPP__



#include <memory>
#include <string>

#include "AstExpr_op2.hpp"
#include "IAstExpr.hpp"
#include "NameExprs/AstNameExpr_var.hpp"
#include "../Stmts/AstStmt_define_var.hpp"
#include "../Stmts/AstStmt_expr_wrap.hpp"
#include "../Stmts/AstStmt_if.hpp"
#include "../Stmts/IAstStmt.hpp"
#include "../Types/AstType_bool.hpp"



struct AstExpr_if: public IAstExpr {
	PAstExpr m_cond_expr;
	std::vector<PAstStmt> m_true_stmts, m_false_stmts;
	PAstExpr m_true_value, m_false_value;

	AstExpr_if (antlr4::Token *_token, PAstExpr _cond_expr, std::vector<PAstStmt> _true_stmts, std::vector<PAstStmt> _false_stmts, PAstExpr _true_value, PAstExpr _false_value):
		IAstExpr (_token), m_cond_expr (_cond_expr), m_true_stmts (_true_stmts), m_false_stmts (_false_stmts), m_true_value (_true_value), m_false_value (_false_value) {}
	AstExpr_if (antlr4::Token *_token, PAstExpr _cond_expr, PAstExpr _true_value, PAstExpr _false_value):
		IAstExpr (_token), m_cond_expr (_cond_expr), m_true_value (_true_value), m_false_value (_false_value) {}
	AstExpr_if (antlr4::Token *_token): IAstExpr (_token), m_cond_expr (nullptr), m_true_value (nullptr), m_false_value (nullptr) {}

	void SetMembers (fa::ParseType _type, std::vector<AstObj *> _values) override {
		if (_type == fa::ParseType::Part_Condition) {
			m_cond_expr = std::shared_ptr<IAstExpr> (dynamic_cast<IAstExpr *> (_values [0]));
		} else if (_type == fa::ParseType::Part_TrueContent) {
			m_true_value = std::shared_ptr<IAstExpr> (dynamic_cast<IAstExpr *> (_values [0]));
		} else if (_type == fa::ParseType::Part_FalseContent) {
			m_false_value = std::shared_ptr<IAstExpr> (dynamic_cast<IAstExpr *> (_values [0]));
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	std::optional<PAstType> GuessType () override { throw fa::Exception (m_token, "not implement"); }

	PAstExpr ProcessCodeType (std::optional<PAstType> _type) override {
		m_cond_expr = m_cond_expr->ProcessCodeType (AstType_bool::Make (m_token));
		auto _process_items = [this, _type] (std::vector<PAstStmt> &_stmts, PAstExpr _value) -> PAstExpr {
			CompileEnv::CurrentFuncVariables.AddLevel ();
			for (size_t i = 0; i < _stmts.size (); ++i)
				_stmts [i] = _stmts [i]->ProcessCodeType ();
			auto _ret = _value->ProcessCodeType (_type);
			CompileEnv::CurrentFuncVariables.RemoveLevel ();
			return _ret;
		};
		std::string _base_type_name = _type.value ()->GetTypeName ();
		auto _true_value = _process_items (m_true_stmts, m_true_value);
		std::string _true_type_name = _true_value->m_real_type.value ()->GetTypeName ();
		auto _false_value = _process_items (m_false_stmts, m_false_value);
		std::string _false_type_name = _false_value->m_real_type.value ()->GetTypeName ();
		m_true_value = _true_value;
		m_false_value = _false_value;
		if (!_true_value->m_real_type->IsSame (_false_value->m_real_type.value ()))
			throw fa::Exception (m_token, "type not match");
		return shared_from_this ();
	}

	std::optional<PAstExpr> Evaluate (Evaluation &_eval) override { throw fa::Exception (m_token, "not implement"); }

	static PAstExpr MakeFrom3OpExpr (antlr4::Token *_token, std::vector<PAstExpr> _exprs) {
		if (_exprs.size () != 3)
			throw fa::Exception (_exprs[0]->m_token, "表达式格式不合法");
		return std::shared_ptr<IAstExpr> (new AstExpr_if { _token, _exprs [0], _exprs [1], _exprs [2] });
	}
};



#endif //__AST_EXPR_IF_HPP__

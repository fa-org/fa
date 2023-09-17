#ifndef __AST_EXPR_CALC_WRAP_HPP__
#define __AST_EXPR_CALC_WRAP_HPP__



#include <memory>
#include <string>

#include "NameExprs/IAstNameExpr.hpp"
#include "AstExpr_temp_name.hpp"
#include "IAstExpr.hpp"
#include "../Stmts/IAstStmt.hpp"
#include "../Types/AstType_array_wrap.hpp"
#include "../../common/Evaluation.hpp"



struct AstExpr_CalcWrap: public IAstExpr {
	PAstExpr m_base;

	AstExpr_CalcWrap (antlr4::Token *_token): IAstExpr (_token), m_base (nullptr) {}
	AstExpr_CalcWrap (antlr4::Token *_token, PAstExpr _base): IAstExpr (_token), m_base (_base) {}

	void SetMembers (fa::ParseType _type, std::vector<AstObj *> _values) override {
		if (_type == fa::ParseType::Part_Member) {
			m_base = std::shared_ptr<IAstExpr> (dynamic_cast<IAstExpr *> (_values [0]));
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	std::optional<PAstType> GuessType () override { throw fa::Exception (m_token, "not implement"); }

	PAstExpr ProcessCodeType (std::optional<PAstType> _type) override { return Evaluation::Expr (m_base); }

	std::optional<PAstExpr> Evaluate (Evaluation &_eval) override { throw fa::Exception (m_token, "not implement"); }

	static PAstExpr Make (antlr4::Token *_token, PAstExpr _base) {
		return std::shared_ptr<IAstExpr> (new AstExpr_CalcWrap { _token, _base });
	}
};



#endif //__AST_EXPR_CALC_WRAP_HPP__

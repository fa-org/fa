#ifndef __AST_EXPR_TEMPLATE_WRAP_HPP__
#define __AST_EXPR_TEMPLATE_WRAP_HPP__



#include <memory>
#include <string>

#include "IAstExpr.hpp"
#include "../Exprs/AstExpr_type_wrap.hpp"
#include "../Stmts/IAstStmt.hpp"
#include "../Types/IAstType.hpp"
#include "../../common/Evaluation.hpp"
#include "../../common/CompileEnv.hpp"



struct AstExpr_template_wrap: public IAstExpr {
	PAstExpr m_base;
	std::vector<PAstType> m_types;

	AstExpr_template_wrap (antlr4::Token *_token): IAstExpr (_token), m_base (nullptr) {}
	AstExpr_template_wrap (antlr4::Token *_token, PAstExpr _base, std::vector<PAstType> _types): IAstExpr (_token), m_base (_base), m_types (_types) {}

	void SetMembers (fa::ParseType _type, std::vector<AstObj *> _values) override {
		if (_type == fa::ParseType::Part_Member) {
			m_base = std::shared_ptr<IAstExpr> (dynamic_cast<IAstExpr *> (_values [0]));
		} else if (_type == fa::ParseType::Type) {
			for (auto _value : _values)
				m_types.push_back (std::shared_ptr<IAstType> (dynamic_cast<IAstType *> (_value)));
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	std::optional<PAstType> GuessType () override {
		//auto _oval = CompileEnv::FindName (m_token, m_name);
		//if (_oval.has_value ()) {
		//	PAstExpr _expr = _oval.value ();
		//	if (auto _type = dynamic_cast<AstExpr_type_wrap *> (_expr.get ())) {
		//		return _type->m_type;
		//	} else {
		//		return _expr->GuessType ();
		//	}
		//}
		throw fa::Exception (m_token, "not implement");
	}

	PAstExpr ProcessCodeType (std::optional<PAstType> _type) override {
		throw fa::Exception (m_token, "not implement");
	}

	std::optional<PAstExpr> Evaluate (Evaluation &_eval) override { throw fa::Exception (m_token, "not implement"); }

	static PAstExpr Make (antlr4::Token *_token, PAstExpr _base, std::vector<PAstType> _types) {
		return std::shared_ptr<IAstExpr> (new AstExpr_template_wrap { _token, _base, _types });
	}
};



#endif //__AST_EXPR_TEMPLATE_WRAP_HPP__

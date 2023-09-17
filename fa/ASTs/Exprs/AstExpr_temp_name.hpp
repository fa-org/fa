#ifndef __AST_EXPR_TEMP_NAME_HPP__
#define __AST_EXPR_TEMP_NAME_HPP__



#include <memory>
#include <string>

#include "IAstExpr.hpp"
#include "../Exprs/AstExpr_type_wrap.hpp"
#include "../Stmts/IAstStmt.hpp"
#include "../../common/CompileEnv.hpp"
#include "../../common/Evaluation.hpp"



struct AstExpr_temp_name: public IAstExpr {
	std::string m_name = "";

	AstExpr_temp_name (antlr4::Token *_token): IAstExpr (_token) {}
	AstExpr_temp_name (antlr4::Token *_token, std::string _name):
		IAstExpr (_token), m_name (_name) {}

	void SetValues (fa::ParseValueType _type, std::vector<fa::ParseValue_t> _values) override {
		if (_type == fa::ParseValueType::Name) {
			m_name = std::get<std::string> (_values [0]);
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	std::optional<PAstType> GuessType () override {
		auto _oval = CompileEnv::FindName (m_token, m_name, {});
		if (_oval.has_value ()) {
			PAstExpr _expr = _oval.value ();
			if (auto _type = dynamic_cast<AstExpr_type_wrap *> (_expr.get ())) {
				return _type->m_type;
			} else {
				return _expr->GuessType ();
			}
		}
		throw fa::Exception (m_token, "not implement");
	}

	PAstExpr ProcessCodeType (std::optional<PAstType> _type) override {
		auto _oval = CompileEnv::FindName (m_token, m_name, {});
		if (_oval.has_value ()) {
			return _oval.value ()->ProcessCodeType (_type);
		}
		throw fa::Exception (m_token, "not implement");
	}

	std::optional<PAstExpr> Evaluate (Evaluation &_eval) override {
		if (auto _ovar = _eval.m_vars.Find (m_name); _ovar.has_value ())
			return _ovar.value ();
		throw fa::Exception (m_token, "not implement");
	}

	static PAstExpr Make (antlr4::Token *_token, std::string _name) {
		return std::shared_ptr<IAstExpr> (new AstExpr_temp_name { _token, _name });
	}
};



#endif //__AST_EXPR_TEMP_NAME_HPP__

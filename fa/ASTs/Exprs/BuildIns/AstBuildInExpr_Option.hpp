#ifndef __AST_BUILD_IN_EXPR_OPTION_HPP__
#define __AST_BUILD_IN_EXPR_OPTION_HPP__



#include <map>
#include <memory>
#include <set>
#include <string>
#include <optional>

#include "../AstExpr_value.hpp"
#include "IAstBuildInExpr.hpp"



struct AstBuildInExpr_Option: public IAstBuildInExpr {
	PAstType m_tvalue;
	std::optional<AstValue_t> m_value;

	AstBuildInExpr_Option (antlr4::Token *_token, PAstType _tvalue, std::optional<AstValue_t> _value):
		IAstBuildInExpr (_token), m_tvalue (_tvalue), m_value (_value) {
		m_real_type = CompileEnv::FindName (_token, "fa.Option", {}).value ()->TryAsType ();
	}

	PAstExpr ProcessCodeType (std::optional<PAstType> _type) override {
		m_tvalue = m_tvalue->ProcessDeclareType ();
		return shared_from_this ();
	}

	std::optional<PAstType> GuessType () override { throw fa::Exception (m_token, "not implement"); }

	std::optional<PAstExpr> Invoke (Evaluation &_eval, std::string _func_name, std::vector<PAstExpr> _args) {
		if (_func_name == "HasValue") {
			return AstExpr_value::Make (m_token, AstValue_t (m_value.has_value ()));
		} else if (_func_name == "Value") {
			if (!m_value.has_value ())
				throw fa::Exception (m_token, "not implement");
			return AstExpr_value::Make (m_token, m_value.value ());
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	static std::optional<PAstExpr> StaticInvoke (antlr4::Token *_token, Evaluation &_eval, std::string _func_name, std::vector<PAstType> _templates, std::vector<PAstExpr> _args) {
		throw fa::Exception (_token, "not implement");
	}

	static PAstExpr Make (antlr4::Token *_token, PAstType _tvalue, std::optional<AstValue_t> _value) {
		return std::shared_ptr<IAstExpr> (new AstBuildInExpr_Option { _token, _tvalue, _value });
	}
};



#endif //__AST_BUILD_IN_EXPR_OPTION_HPP__

#ifndef __AST_BUILD_IN_EXPR_CONSOLE_HPP__
#define __AST_BUILD_IN_EXPR_CONSOLE_HPP__



#include <map>
#include <memory>
#include <set>
#include <string>

#include "IAstBuildInExpr.hpp"



struct AstBuildInExpr_Console: public IAstBuildInExpr {
	AstBuildInExpr_Console (antlr4::Token *_token): IAstBuildInExpr (_token) {
		m_real_type = CompileEnv::FindName (_token, "fa.Console", {}).value ()->TryAsType ();
	}

	PAstExpr ProcessCodeType (std::optional<PAstType> _type) override {
		return shared_from_this ();
	}

	std::optional<PAstType> GuessType () override { throw fa::Exception (m_token, "not implement"); }

	std::optional<PAstExpr> Invoke (Evaluation &_eval, std::string _func_name, std::vector<PAstExpr> _args) override {
		if (_func_name == "Write") {
			auto _val0_ref = _args [0]->Evaluate (_eval);
			auto _pval0_ref = dynamic_cast<AstExpr_value *> (_val0_ref.value ().get ());
			auto &_val0 = _pval0_ref->m_value;
			std::cout << std::get<std::string> (_val0);
			return std::nullopt;
		} else if (_func_name == "WriteLine") {
			auto _val0_ref = _args [0]->Evaluate (_eval);
			auto _pval0_ref = dynamic_cast<AstExpr_value *> (_val0_ref.value ().get ());
			auto &_val0 = _pval0_ref->m_value;
			std::cout << std::get<std::string> (_val0) << "\n";
			return std::nullopt;
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	static std::optional<PAstExpr> StaticInvoke (antlr4::Token *_token, Evaluation &_eval, std::string _func_name, std::vector<PAstType> _templates, std::vector<PAstExpr> _args) {
		throw fa::Exception (_token, "not implement");
	}

	static PAstExpr Make (antlr4::Token *_token) {
		return std::shared_ptr<IAstExpr> (new AstBuildInExpr_Console { _token });
	}
};



#endif //__AST_BUILD_IN_EXPR_CONSOLE_HPP__

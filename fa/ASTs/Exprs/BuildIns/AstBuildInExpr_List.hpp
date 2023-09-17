#ifndef __AST_BUILD_IN_EXPR_LIST_HPP__
#define __AST_BUILD_IN_EXPR_LIST_HPP__



#include <map>
#include <memory>
#include <set>
#include <string>

#include "IAstBuildInExpr.hpp"



struct AstBuildInExpr_List: public IAstBuildInExpr {
	PAstType m_tvalue;
	std::vector<AstValue_t> m_values;

	AstBuildInExpr_List (antlr4::Token *_token, PAstType _tvalue): IAstBuildInExpr (_token), m_tvalue (_tvalue) {
		m_real_type = CompileEnv::FindName (_token, "fa.List", {}).value ()->TryAsType ();
	}

	PAstExpr ProcessCodeType (std::optional<PAstType> _type) override {
		m_tvalue = m_tvalue->ProcessDeclareType ();
		return shared_from_this ();
	}

	std::optional<PAstType> GuessType () override { throw fa::Exception (m_token, "not implement"); }

	std::optional<PAstExpr> Invoke (Evaluation &_eval, std::string _func_name, std::vector<PAstExpr> _args) {
		if (_func_name == "RemoveAt") {
			if (_args.size () != 1)
				return AstExpr_value::Make (m_token, false);
			auto _val = _args [0]->Evaluate (_eval).value ();
			auto _pval = dynamic_cast<AstExpr_value *> (_val.get ());
			if (!_pval)
				return AstExpr_value::Make (m_token, false);
			if (_pval->m_value.index () != 1)
				throw fa::Exception (m_token, "not implement");
			int64_t _idx = std::get<1> (_pval->m_value);
			if ((int64_t) m_values.size () <= _idx)
				throw fa::Exception (m_token, "not implement");
			m_values.erase (m_values.begin () + _idx);
			return std::nullopt;
		} else if (_func_name == "Add") {
			if (_args.size () != 2)
				return AstExpr_value::Make (m_token, false);
			auto _valk = _args [0]->Evaluate (_eval).value ();
			auto _pvalk = dynamic_cast<AstExpr_value *> (_valk.get ());
			if (!_pvalk)
				return AstExpr_value::Make (m_token, false);
			m_values.push_back (_pvalk->m_value);
			return std::nullopt;
		} else if (_func_name == "Clear") {
			m_values.clear ();
			return std::nullopt;
		} else if (_func_name == "IsEmpty") {
			return AstExpr_value::Make (m_token, m_values.empty ());
		} else if (_func_name == "Count") {
			return AstExpr_value::Make (m_token, m_values.size ());
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	static std::optional<PAstExpr> StaticInvoke (antlr4::Token *_token, Evaluation &_eval, std::string _func_name, std::vector<PAstType> _templates, std::vector<PAstExpr> _args) {
		throw fa::Exception (_token, "not implement");
	}

	static PAstExpr Make (antlr4::Token *_token, PAstType _tvalue) {
		return std::shared_ptr<IAstExpr> (new AstBuildInExpr_List { _token, _tvalue });
	}
};



#endif //__AST_BUILD_IN_EXPR_LIST_HPP__

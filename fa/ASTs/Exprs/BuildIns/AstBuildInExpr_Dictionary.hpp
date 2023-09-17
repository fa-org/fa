#ifndef __AST_BUILD_IN_EXPR_DICTIONARY_HPP__
#define __AST_BUILD_IN_EXPR_DICTIONARY_HPP__



#include <map>
#include <memory>
#include <set>
#include <string>

#include "IAstBuildInExpr.hpp"



struct AstBuildInExpr_Dictionary: public IAstBuildInExpr {
	PAstType m_tkey, m_tvalue;
	std::map<AstValue_t, AstValue_t, AstValueCmp_t> m_values;

	AstBuildInExpr_Dictionary (antlr4::Token *_token, PAstType _tkey, PAstType _tvalue):
		IAstBuildInExpr (_token), m_tkey (_tkey), m_tvalue (_tvalue) {
		m_real_type = CompileEnv::FindName (_token, "fa.Dictionary", {}).value ()->TryAsType ();
	}

	PAstExpr ProcessCodeType (std::optional<PAstType> _type) override {
		m_tkey = m_tkey->ProcessDeclareType ();
		m_tvalue = m_tvalue->ProcessDeclareType ();
		return shared_from_this ();
	}

	std::optional<PAstType> GuessType () override { throw fa::Exception (m_token, "not implement"); }

	std::optional<PAstExpr> Invoke (Evaluation &_eval, std::string _func_name, std::vector<PAstExpr> _args) {
		if (_func_name == "Contains" || _func_name == "Remove") {
			if (_args.size () != 1)
				return AstExpr_value::Make (m_token, false);
			auto _val = _args [0]->Evaluate (_eval);
			auto _pval = dynamic_cast<AstExpr_value *> (_val.value ().get ());
			if (!_pval)
				return AstExpr_value::Make (m_token, false);
			//
			if (_func_name == "Contains") {
				return AstExpr_value::Make (m_token, m_values.contains (_pval->m_value));
			} else {
				m_values.erase (_pval->m_value);
				return std::nullopt;
			}
		} else if (_func_name == "Add") {
			if (_args.size () != 2)
				return AstExpr_value::Make (m_token, false);
			auto _valk = _args [0]->Evaluate (_eval);
			auto _pvalk = dynamic_cast<AstExpr_value *> (_valk.value ().get ());
			if (!_pvalk)
				return AstExpr_value::Make (m_token, false);
			auto _valv = _args [1]->Evaluate (_eval);
			auto _pvalv = dynamic_cast<AstExpr_value *> (_valv.value ().get ());
			if (!_pvalv)
				return AstExpr_value::Make (m_token, false);
			m_values.emplace (_pvalk->m_value, _pvalv->m_value);
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

	static PAstExpr Make (antlr4::Token *_token, PAstType _tkey, PAstType _tvalue) {
		return std::shared_ptr<IAstExpr> (new AstBuildInExpr_Dictionary { _token, _tkey, _tvalue });
	}
};



#endif //__AST_BUILD_IN_EXPR_DICTIONARY_HPP__

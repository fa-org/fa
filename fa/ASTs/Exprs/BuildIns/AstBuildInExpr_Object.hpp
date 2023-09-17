#ifndef __AST_BUILD_IN_EXPR_OBJECT_HPP__
#define __AST_BUILD_IN_EXPR_OBJECT_HPP__



#include <map>
#include <memory>
#include <set>
#include <string>

#include "IAstBuildInExpr.hpp"



struct AstBuildInExpr_Object: public IAstBuildInExpr {
	AstBuildInExpr_Object (antlr4::Token *_token): IAstBuildInExpr (_token) {
		m_real_type = CompileEnv::FindName (_token, "fa.Object", {}).value ()->TryAsType ();
	}

	PAstExpr ProcessCodeType (std::optional<PAstType> _type) override {
		return shared_from_this ();
	}

	std::optional<PAstType> GuessType () override { throw fa::Exception (m_token, "not implement"); }

	std::optional<PAstExpr> Invoke (Evaluation &_eval, std::string _func_name, std::vector<PAstExpr> _args) {
		//if (_func_name == "ToString") {
		//	auto _val0_ref = dynamic_cast<AstExpr_value *> (_args [0]->Evaluate (_eval).value ().get ());
		//	auto &_val0 = _val0_ref->m_value;
		//	auto _val1_ref = dynamic_cast<AstExpr_value *> (_args [1]->Evaluate (_eval).value ().get ());
		//	std::string _val1 = std::get<std::string> (_val1_ref->m_value);
		//	std::string _fmtstr = std::format ("{{:{}}}", _val1);
		//	std::string _result = "";
		//	switch (_val0.index ()) {
		//		case 0: _result = std::vformat (_fmtstr, std::make_format_args (std::get<0> (_val0))); break;
		//		case 1: _result = std::vformat (_fmtstr, std::make_format_args (std::get<1> (_val0))); break;
		//		case 2: _result = std::vformat (_fmtstr, std::make_format_args (std::get<2> (_val0))); break;
		//		case 3: _result = std::vformat (_fmtstr, std::make_format_args (std::get<3> (_val0))); break;
		//		case 4: _result = std::get<4> (_val0); break;
		//	}
		//	return AstExpr_value::Make (m_token, _result);
		//} else {
		//	throw fa::Exception (m_token, "not implement");
		//}
		throw fa::Exception (m_token, "not implement");
	}

	static std::optional<PAstExpr> StaticInvoke (antlr4::Token *_token, Evaluation &_eval, std::string _func_name, std::vector<PAstType> _templates, std::vector<PAstExpr> _args) {
		throw fa::Exception (_token, "not implement");
	}

	static PAstExpr Make (antlr4::Token *_token) {
		return std::shared_ptr<IAstExpr> (new AstBuildInExpr_Object { _token });
	}
};



#endif //__AST_BUILD_IN_EXPR_OBJECT_HPP__

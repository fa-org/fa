#ifndef __AST_BUILD_IN_EXPR_STRING_HPP__
#define __AST_BUILD_IN_EXPR_STRING_HPP__



#include <map>
#include <memory>
#include <ranges>
#include <set>
#include <sstream>
#include <string>

#include "IAstBuildInExpr.hpp"



struct AstBuildInExpr_String: public IAstBuildInExpr {
	std::string m_value;

	AstBuildInExpr_String (antlr4::Token *_token): IAstBuildInExpr (_token) {
		m_real_type = CompileEnv::FindName (_token, "fa.String", {}).value ()->TryAsType ();
	}

	PAstExpr ProcessCodeType (std::optional<PAstType> _type) override { return shared_from_this (); }

	std::optional<PAstType> GuessType () override { throw fa::Exception (m_token, "not implement"); }

	std::optional<PAstExpr> Invoke (Evaluation &_eval, std::string _func_name, std::vector<PAstExpr> _args) {
		//if (_func_name == "Format") {
		//	if (_args.empty ()) {
		//		return AstExpr_value::Make (m_token, "[ERROR_ARGUMENT_COUNT]");
		//	}
		//	auto _val = dynamic_cast<AstExpr_value *> (_args [0]->Evaluate (_eval).get ());
		//	_args.erase (_args.begin ());
		//	std::string_view _fmtstr = std::get<std::string> (_val->m_value);
		//	std::stringstream _ss {};
		//	while (_fmtstr.size () > 0) {
		//		size_t p = _fmtstr.find ('{'), q = _fmtstr.find ('}');
		//		if (p == std::string::npos && q == std::string::npos) {
		//			_ss << _fmtstr;
		//			break;
		//		} else {
		//			p = p == std::string::npos ? q : (q == std::string::npos ? p : std::min (p, q));
		//			if (p > 0) {
		//				_ss << _fmtstr.substr (0, p);
		//				_fmtstr = _fmtstr.substr (p);
		//			}
		//			if (_fmtstr [0] == '}') {
		//				_ss << '}';
		//				_fmtstr = _fmtstr.substr (2);
		//			} else if (_fmtstr [1] == '{') {
		//				_ss << '{';
		//				_fmtstr = _fmtstr.substr (2);
		//			} else {
		//				p = _fmtstr.find ('}') + 1;
		//				if (p == std::string::npos)
		//					return AstExpr_value::Make (m_token, "[ERROR_FORMAT_STRING]");
		//				std::string_view _fmtstr2 = _fmtstr.substr (0, p + 1);
		//				_fmtstr = _fmtstr.substr (p + 1);
		//				if (_args.empty ())
		//					return AstExpr_value::Make (m_token, "[ERROR_FORMAT_ARG_COUNT]");
		//				auto _val2_ref = dynamic_cast<AstExpr_value *> (_args [0]->Evaluate (_eval).get ());
		//				auto &_val2 = _val2_ref->m_value;
		//				switch (_val2.index ()) {
		//					case 0: _ss << std::vformat (_fmtstr2, std::make_format_args (std::get<0> (_val2))); break;
		//					case 1: _ss << std::vformat (_fmtstr2, std::make_format_args (std::get<1> (_val2))); break;
		//					case 2: _ss << std::vformat (_fmtstr2, std::make_format_args (std::get<2> (_val2))); break;
		//					case 3: _ss << std::vformat (_fmtstr2, std::make_format_args (std::get<3> (_val2))); break;
		//					case 4: _ss << std::vformat (_fmtstr2, std::make_format_args (std::get<1> (_val2))); break;
		//				}
		//				_args.erase (_args.begin ());
		//			}
		//		}
		//	}
		//} else
		 if (_func_name == "Join") {
			std::stringstream _ss {};
			for (size_t i = 0; i < _args.size (); ++i) {
				if (i > 0)
					_ss << m_value;
				auto _val = _args [i]->Evaluate (_eval);
				auto _pval = dynamic_cast<AstExpr_value *> (_val.value ().get ());
				_ss << std::get<std::string> (_pval->m_value);
			}
			return AstExpr_value::Make (m_token, _ss.str ());
		} else if (_func_name == "Contains" || _func_name == "IndexOf") {
			//
		} else if (_func_name == "IndexOfAny") {
			//
		} else if (_func_name == "RIndexOf") {
			//
		} else if (_func_name == "RIndexOfAny") {
			//
		} else if (_func_name == "Remove") {
			//
		} else if (_func_name == "Add") {
			//
		} else if (_func_name == "Clear") {
			m_value = "";
			return std::nullopt;
		} else if (_func_name == "IsEmpty") {
			return AstExpr_value::Make (m_token, m_value.empty ());
		} else if (_func_name == "Length") {
			return AstExpr_value::Make (m_token, m_value.size ());
		} else {
			throw fa::Exception (m_token, "not implement");
		}
		throw fa::Exception (m_token, "not implement");
	}

	static std::optional<PAstExpr> StaticInvoke (antlr4::Token *_token, Evaluation &_eval, std::string _func_name, std::vector<PAstType> _templates, std::vector<PAstExpr> _args) {
		throw fa::Exception (_token, "not implement");
	}

	static PAstExpr Make (antlr4::Token *_token) {
		return std::shared_ptr<IAstExpr> (new AstBuildInExpr_String { _token });
	}
};



#endif //__AST_BUILD_IN_EXPR_STRING_HPP__

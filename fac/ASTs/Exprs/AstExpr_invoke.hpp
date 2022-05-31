#ifndef __AST_EXPR_INVOKE_HPP__
#define __AST_EXPR_INVOKE_HPP__



#include <memory>
#include <sstream>
#include <string>

#include "IAstExpr.hpp"



struct AstExpr_invoke: public IAstExpr {
	std::shared_ptr<IAstExpr> m_base;
	std::vector<std::shared_ptr<IAstExpr>> m_args;
	std::string m_op;

	AstExpr_invoke (antlr4::Token *_token, std::shared_ptr<IAstExpr> _base, std::vector<std::shared_ptr<IAstExpr>> _args, std::string _op):
		IAstExpr (_token), m_base (_base), m_args (_args), m_op (_op) {}

	std::string GenCppCode (size_t _indent) override {
		std::stringstream _ss {};
		_ss << std::format ("{} (", m_base->GenCppCode (_indent));
		for (size_t i = 0; i < m_args.size (); ++i) {
			if (i > 0)
				_ss << ", ";
			_ss << m_args [i]->GenCppCode (_indent);
		}
		_ss << ")";
		return _ss.str ();
	}

	static std::shared_ptr<IAstExpr> Make (antlr4::Token *_token, std::shared_ptr<IAstExpr> _base, std::vector<std::shared_ptr<IAstExpr>> _args, std::string _op) {
		return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstExpr_invoke { _token, _base, _args, _op });
	}
};



#endif //__AST_EXPR_INVOKE_HPP__

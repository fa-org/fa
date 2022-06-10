#ifndef __AST_EXPR_INVOKE_HPP__
#define __AST_EXPR_INVOKE_HPP__



#include <memory>
#include <sstream>
#include <string>

#include "IAstExpr.hpp"



struct AstExpr_invoke: public IAstExpr {
	PAstExpr m_base;
	std::vector<PAstExpr> m_args;
	std::string m_op;

	AstExpr_invoke (antlr4::Token *_token, PAstExpr _base, std::vector<PAstExpr> _args, std::string _op):
		IAstExpr (_token), m_base (_base), m_args (_args), m_op (_op) {}



	void GetChildTypes (std::function<void (PAstType &)> _cb) override {}

	void GetChildExprs (std::function<void (PAstExpr &)> _cb) override {
		_cb (m_base);
		for (auto &_arg : m_args)
			_cb (_arg);
	}

	void GetChildStmts (std::function<void (PAstStmt &)> _cb) override {}



	PAstType GuessType () override { throw NOT_IMPLEMENT (); }

	void ProcessCode (PAstType _type) override { throw NOT_IMPLEMENT (); }

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



	static PAstExpr Make (antlr4::Token *_token, PAstExpr _base, std::vector<PAstExpr> _args, std::string _op) {
		return new AstExpr_invoke { _token, _base, _args, _op };
	}
};



#endif //__AST_EXPR_INVOKE_HPP__

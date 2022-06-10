#ifndef __AST_EXPR_VALUE_HPP__
#define __AST_EXPR_VALUE_HPP__



#include <memory>
#include <string>

#include "IAstExpr.hpp"
#include "../Types/IAstType.hpp"



struct AstExpr_value: public IAstExpr {
	PAstType m_type;
	std::string m_value;

	AstExpr_value (antlr4::Token *_token, PAstType _type, std::string _value):
		IAstExpr (_token), m_type (_type), m_value (_value) {}



	PAstType GuessType () override { return m_real_type ? m_real_type : m_type; }

	void ProcessCode (PAstType _type) override {
		if (m_real_type) {
			throw NOT_IMPLEMENT ();
		} else if (m_type.IsSame (_type)) {
			m_real_type = _type;
			return;
		} else {
			throw NOT_IMPLEMENT ();
		}
	}

	std::string GenCppCode (size_t _indent) override { return m_value; }



	void GetChildTypes (std::function<void (PAstType &)> _cb) override { _cb (m_type); }
	void GetChildExprs (std::function<void (PAstExpr &)> _cb) override {}
	void GetChildStmts (std::function<void (PAstStmt &)> _cb) override {}



	static PAstExpr Make (antlr4::Token *_token, PAstType _type, std::string _value) { return new AstExpr_value { _token, _type, _value }; }
};



#endif //__AST_EXPR_VALUE_HPP__

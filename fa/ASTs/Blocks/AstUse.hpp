#ifndef __AST_USE_HPP__
#define __AST_USE_HPP__



#include <map>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "AstClassVar.hpp"
#include "IAstBlock.hpp"
#include "../Exprs/IAstExpr.hpp"
#include "../Exprs/AstExpr_value.hpp"
#include "../Stmts/IAstStmt.hpp"



struct AstUse: public IAstBlock, public std::enable_shared_from_this<AstUse> {
	std::string m_library = "", m_nick = "";

	AstUse (antlr4::Token *_token): IAstBlock (_token) {}

	void SetValues (fa::ParseValueType _type, std::vector<fa::ParseValue_t> _values) override {
		if (_type == fa::ParseValueType::Name) {
			m_nick = std::get<std::string> (_values [0]);
		} else if (_type == fa::ParseValueType::Value) {
			m_library = std::get<std::string> (_values [0]);
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	void ProcessDeclareType () override {
		throw fa::Exception (m_token, "not implement");
	}

	void ProcessCodeType () override {
		throw fa::Exception (m_token, "not implement");
	}
};
using PAstUse = std::shared_ptr<AstUse>;



#endif //__AST_USE_HPP__

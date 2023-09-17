#ifndef __AST_TYPE_INT_HPP__
#define __AST_TYPE_INT_HPP__



#include "IAstType.hpp"



struct AstType_int: public IAstType {
	size_t m_bit_width;
	bool m_sign;

	AstType_int (antlr4::Token *_token): IAstType (_token), m_bit_width (0), m_sign (true) {}
	AstType_int (antlr4::Token *_token, size_t _bit_width, bool _sign): IAstType (_token), m_bit_width (_bit_width), m_sign (_sign) {}

	PAstType ProcessDeclareType () override { return shared_from_this (); }

	std::vector<AstType_unsure_wrap *> GetTypeTemplates () override { return {}; }

	bool NeedSure () override { return false; }

	std::string GetTypeName () {
		std::string _name = m_sign ? "int" : "uint";
		return m_bit_width > 0 ? std::format ("{}{}", _name, m_bit_width) : _name;
	}

	static PAstType Make (antlr4::Token *_token, size_t _bit_width, bool _sign) {
		return std::shared_ptr<IAstType> (new AstType_int { _token, _bit_width, _sign });
	}
};



#endif //__AST_TYPE_INT_HPP__

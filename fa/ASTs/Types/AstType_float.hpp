#ifndef __AST_TYPE_FLOAT_HPP__
#define __AST_TYPE_FLOAT_HPP__



#include "IAstType.hpp"



struct AstType_float: public IAstType {
	size_t m_bit_width;

	AstType_float (antlr4::Token *_token): IAstType (_token), m_bit_width (0) {}
	AstType_float (antlr4::Token *_token, size_t _bit_width): IAstType (_token), m_bit_width (_bit_width) {}

	PAstType ProcessDeclareType () override { return shared_from_this (); }

	std::vector<AstType_unsure_wrap *> GetTypeTemplates () override { return {}; }

	bool NeedSure () override { return false; }

	std::string GetTypeName () { return m_bit_width > 0 ? std::format ("float{}", m_bit_width) : "float"; }

	static PAstType Make (antlr4::Token *_token, size_t _bit_width) {
		return std::shared_ptr<IAstType> (new AstType_float { _token, _bit_width });
	}
};



#endif //__AST_TYPE_FLOAT_HPP__

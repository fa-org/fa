#ifndef __AST_TYPE_BOOL_HPP__
#define __AST_TYPE_BOOL_HPP__



#include "IAstType.hpp"



struct AstType_bool: public IAstType {
	AstType_bool (antlr4::Token *_token): IAstType (_token) {}

	PAstType ProcessDeclareType () override { return shared_from_this (); }

	std::vector<AstType_unsure_wrap *> GetTypeTemplates () override { return {}; }

	bool NeedSure () override { return false; }

	std::string GetTypeName () { return "bool"; }

	static PAstType Make (antlr4::Token *_token) {
		return std::shared_ptr<IAstType> (new AstType_bool { _token });
	}
};



#endif //__AST_TYPE_BOOL_HPP__

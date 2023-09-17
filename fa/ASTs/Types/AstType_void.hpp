#ifndef __AST_TYPE_VOID_HPP__
#define __AST_TYPE_VOID_HPP__



#include "IAstType.hpp"



struct AstType_void: public IAstType {
	AstType_void (antlr4::Token *_token): IAstType (_token) {}

	PAstType ProcessDeclareType () override { return shared_from_this (); }

	std::vector<AstType_unsure_wrap *> GetTypeTemplates () override { return {}; }

	bool NeedSure () override { return false; }

	std::string GetTypeName () { return "void"; }

	static PAstType Make (antlr4::Token *_token) { return std::shared_ptr<IAstType> (new AstType_void { _token }); }
};



#endif //__AST_TYPE_VOID_HPP__

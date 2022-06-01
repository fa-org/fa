#ifndef __AST_TYPE_HPP__
#define __AST_TYPE_HPP__



#include <memory>
#include <string>
#include <tuple>
#include <vector>

#include "../IAst.hpp"
#include "../../Common.hpp"
#include "../../Exception.hpp"



struct IAstType: public IAst {
	bool m_mut = false;
	bool m_params = false;

	IAstType (antlr4::Token *_token): IAst (_token) {}

	std::string GenCppCode (size_t _indent) override { throw NOT_IMPLEMENT (); }
	virtual std::string GenCppCode () = 0;

	static std::tuple<std::shared_ptr<IAstType>, std::string> FromCtx (FaParser::TypeVarContext *_ctx);
	static std::tuple<std::vector<std::shared_ptr<IAstType>>, std::vector<std::string>> FromCtx (std::vector<FaParser::TypeVarContext *> _ctx);
	static std::shared_ptr<IAstType> FromCtx (FaParser::TypeSingleContext *_ctx);
	static std::shared_ptr<IAstType> FromCtx (FaParser::TypeMultiContext *_ctx);
	static std::shared_ptr<IAstType> FromCtx (FaParser::TypeContext *_ctx);
	static std::vector<std::shared_ptr<IAstType>> FromCtx (std::vector<FaParser::TypeContext *> _ctxs);
	static std::shared_ptr<IAstType> FromCtx (FaParser::TypeWrapContext *_ctx);
	static std::vector<std::shared_ptr<IAstType>> FromCtx (std::vector<FaParser::TypeWrapContext *> _ctxs);
	static std::tuple<std::shared_ptr<IAstType>, std::string> FromCtx (FaParser::TypeWrapVar1Context *_ctx);
	static std::tuple<std::shared_ptr<IAstType>, std::string> FromCtx (FaParser::TypeWrapVar2Context *_ctx);
	static std::tuple<std::vector<std::shared_ptr<IAstType>>, std::vector<std::string>> FromCtx (FaParser::TypeWrapVarList1Context *_ctx);
	static std::tuple<std::vector<std::shared_ptr<IAstType>>, std::vector<std::string>> FromCtx (FaParser::TypeWrapVarList2Context *_ctx);
};



#endif //__AST_TYPE_HPP__

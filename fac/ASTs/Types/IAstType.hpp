#ifndef __AST_TYPE_HPP__
#define __AST_TYPE_HPP__



#include <functional>
#include <memory>
#include <string>
#include <tuple>
#include <vector>

#include "../IAst.hpp"
#include "../../Common.hpp"
#include "../../Exception.hpp"



struct IAstType;
struct PAstType: public std::shared_ptr<IAstType> {
	PAstType (IAstType *_type = nullptr): std::shared_ptr<IAstType> (_type) {}
};

struct IAstType: public IAst {
	bool m_mut = false;
	bool m_params = false;

	IAstType (antlr4::Token *_token): IAst (_token) {}

	void GetChildExprs (std::function<void (PAstExpr &)> _cb) override {}
	void GetChildStmts (std::function<void (PAstStmt &)> _cb) override {}

	static std::tuple<PAstType, std::string> FromCtx (FaParser::TypeVarContext *_ctx);
	static std::tuple<std::vector<PAstType>, std::vector<std::string>> FromCtx (std::vector<FaParser::TypeVarContext *> _ctx);
	static PAstType FromCtx (FaParser::TypeSingleContext *_ctx);
	static PAstType FromCtx (FaParser::TypeMultiContext *_ctx);
	static PAstType FromCtx (FaParser::TypeContext *_ctx);
	static std::vector<PAstType> FromCtx (std::vector<FaParser::TypeContext *> _ctxs);
	static PAstType FromCtx (FaParser::TypeWrapContext *_ctx);
	static std::vector<PAstType> FromCtx (std::vector<FaParser::TypeWrapContext *> _ctxs);
	static std::tuple<PAstType, std::string> FromCtx (FaParser::TypeWrapVar1Context *_ctx);
	static std::tuple<PAstType, std::string> FromCtx (FaParser::TypeWrapVar2Context *_ctx);
	static std::tuple<std::vector<PAstType>, std::vector<std::string>> FromCtx (FaParser::TypeWrapVarList1Context *_ctx);
	static std::tuple<std::vector<PAstType>, std::vector<std::string>> FromCtx (FaParser::TypeWrapVarList2Context *_ctx);
};



#endif //__AST_TYPE_HPP__

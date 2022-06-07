#ifndef __IAST_HPP__
#define __IAST_HPP__



#include <functional>
#include <string>

#include "../antlr_gen/FaParser.h"



struct PAstType;
struct PAstExpr;
struct PAstStmt;

struct IAst {
	antlr4::Token *m_token = nullptr;

	IAst (antlr4::Token *_token): m_token (_token) {}

	virtual std::string GenCppCode (size_t _indent) = 0;

	virtual void GetChildTypes (std::function<void (PAstType &)> _cb) = 0;
	virtual void GetChildExprs (std::function<void (PAstExpr &)> _cb) = 0;
	virtual void GetChildStmts (std::function<void (PAstStmt &)> _cb) = 0;
};

#endif //__IAST_HPP__

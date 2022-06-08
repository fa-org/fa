#ifndef __IAST_BLOCK_HPP__
#define __IAST_BLOCK_HPP__



#include <functional>

#include "../IAst.hpp"



struct IAstBlock: public IAst {
	IAstBlock (antlr4::Token *_token): IAst (_token) {}

	void GetChildTypes (std::function<void (PAstType &)> _cb) override {}
	void GetChildExprs (std::function<void (PAstExpr &)> _cb) override {}
	void GetChildStmts (std::function<void (PAstStmt &)> _cb) override {}

	virtual void ProcessCode () = 0;
};



#endif //__IAST_BLOCK_HPP__

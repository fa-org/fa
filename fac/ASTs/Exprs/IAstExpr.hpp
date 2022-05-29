#ifndef __AST_EXPR_HPP__
#define __AST_EXPR_HPP__



#include <memory>
#include <vector>

#include "../IAst.hpp"
#include "../../Exception.hpp"



struct IAstExpr: public IAst {
	std::string GenCppCode (size_t _indent) override { throw NOT_IMPLEMENT (); }

	virtual std::string GenCppCode () = 0;

	static std::shared_ptr<IAstExpr> FromCtx (FaParser::ExprContext *_ctx);
};



#endif //__AST_EXPR_HPP__

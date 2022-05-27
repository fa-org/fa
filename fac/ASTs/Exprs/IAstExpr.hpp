#ifndef __AST_EXPR_HPP__
#define __AST_EXPR_HPP__



#include <memory>
#include <vector>

#include "../IAst.hpp"



struct IAstExpr: public IAst {
	static std::shared_ptr<IAstExpr> FromCtx (FaParser::ExprContext *_ctx);
};



#endif //__AST_EXPR_HPP__

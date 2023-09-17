#ifndef __AST_STMT_HPP__
#define __AST_STMT_HPP__



#include <memory>
#include <vector>

#include "../IAst.hpp"



struct Evaluation;
struct IAstStmt;
struct PAstStmt;

struct PAstStmt: public std::shared_ptr<IAstStmt> {
	PAstStmt (std::shared_ptr<IAstStmt> _stmt): std::shared_ptr<IAstStmt> (_stmt) {}
};

struct IAstStmt: public IAst, public std::enable_shared_from_this<IAstStmt>  {
	IAstStmt (antlr4::Token *_token): IAst (_token) {}

	virtual PAstStmt ProcessCodeType () = 0;
	virtual void Evaluate (Evaluation &_eval) = 0;
};



#endif //__AST_STMT_HPP__

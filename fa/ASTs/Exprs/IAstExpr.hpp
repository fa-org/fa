#ifndef __AST_EXPR_HPP__
#define __AST_EXPR_HPP__



#include <memory>
#include <optional>
#include <tuple>
#include <vector>

#include "../IAst.hpp"
#include "../Types/IAstType.hpp"



struct IAstExpr;
struct Evaluation;

struct PAstExpr: public std::shared_ptr<IAstExpr> {
	PAstExpr (std::shared_ptr<IAstExpr> _expr): std::shared_ptr<IAstExpr> (_expr) {}
};

struct IAstExpr: public IAst, public std::enable_shared_from_this<IAstExpr> {
	std::optional<PAstType> m_real_type;

	IAstExpr (antlr4::Token *_token): IAst (_token) {}
	std::optional<PAstType> TryAsType ();

	virtual std::optional<PAstType> GuessType () = 0;
	virtual PAstExpr ProcessCodeType (std::optional<PAstType> _type) = 0;
	virtual PAstExpr ProcessCodeTypeL (std::optional<PAstType> _type) { throw fa::Exception (m_token, "表达式不支持左值"); }
	virtual std::optional<PAstExpr> Evaluate (Evaluation &_eval) = 0;
};



#endif //__AST_EXPR_HPP__

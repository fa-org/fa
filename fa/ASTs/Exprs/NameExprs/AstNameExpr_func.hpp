#ifndef __AST_NAME_EXPR_FUNC_HPP__
#define __AST_NAME_EXPR_FUNC_HPP__



#include <memory>
#include <optional>
#include <tuple>
#include <vector>

#include "IAstNameExpr.hpp"



using TFunc = std::function<std::optional<PAstExpr> (Evaluation &_eval, std::vector<PAstExpr> _args)>;

struct AstNameExpr_func: public IAstNameExpr {
	TFunc m_func;
	AstNameExpr_func (antlr4::Token *_token, TFunc _func): IAstNameExpr (_token), m_func (_func) {}

	std::optional<PAstExpr> Evaluate (Evaluation &_eval) override { return shared_from_this (); }

	bool IsSameVar (IAstNameExpr *_other) const override { return GetName () == _other->GetName (); }

	std::string GetName () const override { throw fa::Exception (m_token, "not implement"); }

	static PAstExpr Make (antlr4::Token *_token, TFunc _func) {
		return std::shared_ptr<IAstExpr> (new AstNameExpr_func (_token, _func));
	}
};



#endif //__AST_NAME_EXPR_FUNC_HPP__

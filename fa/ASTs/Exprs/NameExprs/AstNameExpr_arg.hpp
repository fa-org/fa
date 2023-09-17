#ifndef __AST_NAME_EXPR_ARGUMENT_HPP__
#define __AST_NAME_EXPR_ARGUMENT_HPP__



#include <memory>
#include <optional>
#include <tuple>
#include <vector>

#include "IAstNameExpr.hpp"



struct AstClassFuncEmpty;

struct AstNameExpr_argument: public IAstNameExpr {
	std::shared_ptr<AstClassFuncEmpty> m_func;
	size_t m_arg_index;

	AstNameExpr_argument (antlr4::Token *_token): IAstNameExpr (_token), m_arg_index (-1) {}
	AstNameExpr_argument (antlr4::Token *_token, std::shared_ptr<AstClassFuncEmpty> _func, size_t _arg_index);

	std::optional<PAstExpr> Evaluate (Evaluation &_eval) override;

	std::string GenCppCodeForArg (size_t _indent, std::string _func_name);

	bool IsSameVar (IAstNameExpr *_other) const override;

	std::string GetName () const override;

	static PAstExpr Make (antlr4::Token *_token, std::shared_ptr<AstClassFuncEmpty> _func, size_t _arg_index) {
		return std::shared_ptr<IAstExpr> (new AstNameExpr_argument (_token, _func, _arg_index));
	}
};



#endif //__AST_NAME_EXPR_ARGUMENT_HPP__

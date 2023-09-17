#ifndef __AST_NAME_EXPR_HPP__
#define __AST_NAME_EXPR_HPP__



#include <memory>
#include <optional>
#include <tuple>
#include <vector>

#include "../IAstExpr.hpp"



struct IAstNameExpr: public IAstExpr {
	IAstNameExpr (antlr4::Token *_token): IAstExpr (_token) {}

	std::optional<PAstType> GuessType () override { return m_real_type.value (); }

	PAstExpr ProcessCodeType (std::optional<PAstType> _type) override { return shared_from_this (); }

	virtual bool IsSameVar (IAstNameExpr *_other) const = 0;

	virtual std::string GetName () const = 0;
};



#endif //__AST_NAME_EXPR_HPP__

#ifndef __AST_NAME_EXPR_CLASS_FUNC_HPP__
#define __AST_NAME_EXPR_CLASS_FUNC_HPP__



#include <memory>
#include <optional>
#include <tuple>
#include <vector>

#include "IAstNameExpr.hpp"



struct AstClassFuncEmpty;



struct AstNameExpr_class_func: public IAstNameExpr {
	std::optional<PAstExpr> m_base;
	std::shared_ptr<AstClassFuncEmpty> m_func;
	std::vector<PAstType> m_class_template_types;
	std::vector<PAstType> m_func_template_types;
	AstNameExpr_class_func (antlr4::Token *_token): IAstNameExpr (_token) {}
	AstNameExpr_class_func (antlr4::Token *_token, std::optional<PAstExpr> _base, std::shared_ptr<AstClassFuncEmpty> _func, std::vector<PAstType> _class_template_types, std::vector<PAstType> _func_template_types);

	std::optional<PAstExpr> Evaluate (Evaluation &_eval) override { return shared_from_this (); }

	bool IsSameVar (IAstNameExpr *_other) const override;

	std::string GetName () const override;

	static PAstExpr Make (antlr4::Token *_token, std::optional<PAstExpr> _base, std::shared_ptr<AstClassFuncEmpty> _func, std::vector<PAstType> _class_template_types, std::vector<PAstType> _func_template_types) {
		return std::shared_ptr<IAstExpr> (new AstNameExpr_class_func (_token, _base, _func, _class_template_types, _func_template_types));
	}
};



#endif //__AST_NAME_EXPR_CLASS_FUNC_HPP__

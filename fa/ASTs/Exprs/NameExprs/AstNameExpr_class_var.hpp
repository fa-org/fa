#ifndef __AST_NAME_EXPR_CLASSVAR_HPP__
#define __AST_NAME_EXPR_CLASSVAR_HPP__



#include <memory>
#include <optional>
#include <tuple>
#include <vector>

#include "IAstNameExpr.hpp"



struct AstClass;



struct AstNameExpr_class_var: public IAstNameExpr {
	std::optional<PAstExpr> m_base;
	std::shared_ptr<AstClass> m_class;
	std::vector<PAstType> m_template_types;
	std::string m_varname = "";

	AstNameExpr_class_var (antlr4::Token *_token): IAstNameExpr (_token) {}
	AstNameExpr_class_var (antlr4::Token *_token, std::optional<PAstExpr> _base, std::shared_ptr<AstClass> _class, std::vector<PAstType> _template_types, std::string _varname);

	std::optional<PAstExpr> Evaluate (Evaluation &_eval) override { throw fa::Exception (m_token, "not implement"); }

	bool IsSameVar (IAstNameExpr *_other) const override;

	std::string GetName () const override { return m_varname; }

	static PAstExpr Make (antlr4::Token *_token, std::optional<PAstExpr> _base, std::shared_ptr<AstClass> _class, std::vector<PAstType> _template_types, std::string _varname) {
		return std::shared_ptr<IAstExpr> (new AstNameExpr_class_var (_token, _base, _class, _template_types, _varname));
	}
};



#endif //__AST_NAME_EXPR_CLASSVAR_HPP__

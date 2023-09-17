#ifndef __AST_NAME_EXPR_ENUMITEM_HPP__
#define __AST_NAME_EXPR_ENUMITEM_HPP__



#include <memory>
#include <optional>
#include <tuple>
#include <vector>

#include "IAstNameExpr.hpp"
#include "../../Types/AstType_class.hpp"



struct AstClass;



struct AstNameExpr_enumitem: public IAstNameExpr {
	std::optional<PAstExpr> m_base;
	std::shared_ptr<AstClass> m_enum;
	std::vector<PAstType> m_template_types;
	size_t m_index = 0;

	AstNameExpr_enumitem (antlr4::Token *_token): IAstNameExpr (_token) {}
	AstNameExpr_enumitem (antlr4::Token *_token, std::optional<PAstExpr> _base, std::shared_ptr<AstClass> _enum, std::vector<PAstType> _template_types, size_t _index):
		IAstNameExpr (_token), m_base (_base), m_enum (_enum), m_template_types (_template_types), m_index (_index) {
		m_real_type = AstType_class::Make (_token, _enum, _template_types);
	}

	std::optional<PAstExpr> Evaluate (Evaluation &_eval) override { throw fa::Exception (m_token, "not implement"); }

	bool IsSameVar (IAstNameExpr *_other) const override;

	std::string GetName () const override;

	static PAstExpr Make (antlr4::Token *_token, std::optional<PAstExpr> _base, std::shared_ptr<AstClass> _enum, std::vector<PAstType> _template_types, size_t _index) {
		return std::shared_ptr<IAstExpr> (new AstNameExpr_enumitem (_token, _base, _enum, _template_types, _index));
	}
};



#endif //__AST_NAME_EXPR_ENUMITEM_HPP__

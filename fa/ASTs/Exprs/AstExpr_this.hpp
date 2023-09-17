#ifndef __AST_EXPR_THIS_HPP__
#define __AST_EXPR_THIS_HPP__



#include <map>
#include <memory>
#include <sstream>
#include <string>

#include "IAstExpr.hpp"
#include "../Types/AstType_class.hpp"
#include "../Types/IAstType.hpp"
#include "../../common/CompileEnv.hpp"



struct AstClass;



struct AstExpr_this: public IAstExpr {
	AstExpr_this (antlr4::Token *_token): IAstExpr (_token) {}
	AstExpr_this (antlr4::Token *_token, std::shared_ptr<AstClass> _class, std::vector<PAstType> _template_types): IAstExpr (_token) {
		m_real_type = AstType_class::Make (_token, _class, _template_types);
	}



	std::optional<PAstType> GuessType () override { return m_real_type; }

	PAstExpr ProcessCodeType (std::optional<PAstType> _type) { return shared_from_this (); }

	std::optional<PAstExpr> Evaluate (Evaluation &_eval) override { throw fa::Exception (m_token, "not implement"); }

	static PAstExpr Make (antlr4::Token *_token, std::shared_ptr<AstClass> _class, std::vector<PAstType> _template_types) {
		return std::shared_ptr<IAstExpr> ((IAstExpr *) new AstExpr_this { _token, _class, _template_types });
	}
};



#endif //__AST_EXPR_THIS_HPP__

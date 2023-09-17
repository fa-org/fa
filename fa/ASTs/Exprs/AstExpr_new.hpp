#ifndef __AST_EXPR_NEW_HPP__
#define __AST_EXPR_NEW_HPP__



#include <map>
#include <memory>
#include <sstream>
#include <string>

#include "IAstExpr.hpp"
#include "../Types/AstType_class.hpp"
#include "../Types/AstType_temp_name.hpp"
#include "../Types/IAstType.hpp"
#include "../../common/CompileEnv.hpp"



struct AstExpr_new: public IAstExpr {
	std::map<std::string, PAstExpr> m_init_values;

	AstExpr_new (antlr4::Token *_token): IAstExpr (_token) {}

	std::optional<PAstType> GuessType () override {
		if (!m_real_type.has_value ())
			return std::nullopt;
		if (auto _temp_type = dynamic_cast<AstType_temp_name *> (m_real_type.value ().get ()))
			m_real_type = _temp_type->ProcessDeclareType ();
		return m_real_type;
	}

	PAstExpr ProcessCodeType (std::optional<PAstType> _type) override;

	std::optional<PAstExpr> Evaluate (Evaluation &_eval) override { throw fa::Exception (m_token, "not implement"); }
};



#endif //__AST_EXPR_NEW_HPP__

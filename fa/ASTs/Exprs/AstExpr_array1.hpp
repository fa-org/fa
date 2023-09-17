#ifndef __AST_EXPR_ARRAY3_HPP__
#define __AST_EXPR_ARRAY3_HPP__



#include <memory>
#include <sstream>
#include <string>

#include "IAstExpr.hpp"
#include "../Types/AstType_bool.hpp"
#include "../Types/AstType_tuple_wrap.hpp"
#include "../Types/AstType_void.hpp"
#include "../Types/IAstType.hpp"



enum class Arr1CondType { Where, Skip, Take };

struct AstExpr_array1_condition {
	Arr1CondType m_type;
	PAstExpr m_expr;
};



struct AstExpr_array1: public IAstExpr {
	std::vector<PAstType> m_var_types;
	std::vector<std::string> m_var_names;
	PAstExpr m_arr_expr;
	std::vector<AstExpr_array1_condition> m_conds;
	bool m_var_unwrap = false;
	std::optional<PAstExpr> m_select_expr;
	std::optional<PAstExpr> m_run_expr;

	AstExpr_array1 (antlr4::Token *_token): IAstExpr (_token), m_arr_expr (nullptr) {}

	std::optional<PAstType> GuessType () override;

	PAstExpr ProcessCodeType (std::optional<PAstType> _type) override;

	std::optional<PAstExpr> Evaluate (Evaluation &_eval) override { throw fa::Exception (m_token, "not implement"); }
};



#endif //__AST_EXPR_ARRAY3_HPP__

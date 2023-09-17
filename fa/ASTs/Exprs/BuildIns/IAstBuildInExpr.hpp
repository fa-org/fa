#ifndef __IAST_BUILD_IN_EXPR_HPP__
#define __IAST_BUILD_IN_EXPR_HPP__



#include <map>
#include <memory>
#include <set>
#include <string>

#include "../IAstExpr.hpp"
#include "../../../common/Evaluation.hpp"



struct IAstBuildInExpr: public IAstExpr {
	IAstBuildInExpr (antlr4::Token *_token): IAstExpr (_token) {}

	std::optional<PAstExpr> Evaluate (Evaluation &_eval) override { return shared_from_this (); }

	virtual std::optional<PAstExpr> Invoke (Evaluation &_eval, std::string _func_name, std::vector<PAstExpr> _args) = 0;

	static std::optional<PAstExpr> StaticInvoke (antlr4::Token *_token, Evaluation &_eval, std::string _class_name, std::string _func_name, std::vector<PAstType> _templates, std::vector<PAstExpr> _args);

	static std::optional<PAstExpr> CreateBuildInExpr (antlr4::Token *_token, std::string _name, std::vector<PAstType> _templates);
};



#endif //__IAST_BUILD_IN_EXPR_HPP__

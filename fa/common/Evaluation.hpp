#ifndef __EVALUATION_HPP__
#define __EVALUATION_HPP__



#include <map>

#include "../ASTs/Exprs/NameExprs/AstNameExpr_arg.hpp"
#include "../ASTs/Exprs/IAstExpr.hpp"
#include "../ASTs/Stmts/IAstStmt.hpp"



struct RuntimeVariableItems {
	std::map<PAstExpr, PAstExpr> m_vars;

	virtual std::optional<PAstExpr> Find (PAstExpr _var) {
		for (auto &[_item_var, _item_val] : m_vars) {
			if (_item_var.get () == _var.get ())
				return _item_val;
			if (auto _argvar1 = dynamic_cast<IAstNameExpr *> (_item_var.get ())) {
				if (auto _argvar2 = dynamic_cast<IAstNameExpr *> (_var.get ())) {
					if (_argvar1->IsSameVar (_argvar2))
						return _item_val;
				}
			}
		}
		return std::nullopt;
	}
	virtual std::optional<PAstExpr> Find (std::string _name) {
		for (auto &[_item_var, _item_val] : m_vars) {
			if (auto _argvar1 = dynamic_cast<IAstNameExpr *> (_item_var.get ())) {
				if (_argvar1->GetName () == _name)
					return _item_val;
			}
		}
		return std::nullopt;
	}
	virtual void Add (PAstExpr _var, PAstExpr _value) {
		m_vars.emplace (_var, _value);
	}
};
using PRuntimeVariableItems = std::shared_ptr<RuntimeVariableItems>;
struct RuntimeStackVariables {
	std::vector<PRuntimeVariableItems> m_stack;

	void Clear () { m_stack.clear (); }
	void AddLevel () { m_stack.push_back (std::make_shared<RuntimeVariableItems> ()); }
	void RemoveLevel () { m_stack.erase (m_stack.begin () + m_stack.size () - 1); }
	void Add (PAstExpr _var, PAstExpr _value) {
		if (Find (_var).has_value ())
			throw fa::Exception (_var->m_token, "not implement");
		(*m_stack.rbegin ())->Add (_var, _value);
	}
	std::optional<PAstExpr> Find (PAstExpr _var) {
		for (auto &_item : m_stack) {
			if (auto _oval = _item->Find (_var))
				return _oval.value ();
		}
		return std::nullopt;
	}
	std::optional<PAstExpr> Find (std::string _name) {
		for (auto &_item : m_stack) {
			if (auto _oval = _item->Find (_name))
				return _oval.value ();
		}
		return std::nullopt;
	}
};

struct AstClassFuncEmpty;

struct Evaluation {
	static std::optional<PAstExpr> Expr (PAstExpr _expr) {
		Evaluation _eval {};
		return _expr->Evaluate (_eval);
	}
	static std::optional<PAstExpr> Expr (std::tuple<std::vector<PAstStmt>, PAstExpr> _xexpr) {
		return Expr (std::get<0> (_xexpr), std::get<1> (_xexpr));
	}
	static std::optional<PAstExpr> Expr (std::vector<PAstStmt> _stmts, PAstExpr _expr) {
		Evaluation _eval {};
		for (auto &_stmt : _stmts)
			_stmt->Evaluate (_eval);
		return _expr->Evaluate (_eval);
	}
	static std::optional<PAstExpr> CallFunction (antlr4::Token *_token, std::shared_ptr<AstClassFuncEmpty> _func, std::optional<PAstExpr> _this, std::vector<PAstExpr> _args);

	RuntimeStackVariables m_vars;
	bool m_return = false;
	std::optional<PAstExpr> m_return_expr = std::nullopt;

private:
	Evaluation () {}
};



#endif //__EVALUATION_HPP__

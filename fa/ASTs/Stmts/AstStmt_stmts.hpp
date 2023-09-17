#ifndef __AST_STMT_STMTS_HPP__
#define __AST_STMT_STMTS_HPP__



#include <format>
#include <memory>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

#include "AstStmt_define_var.hpp"
#include "IAstStmt.hpp"
#include "../Types/AstType_class.hpp"
#include "../Types/IAstType.hpp"
#include "../Exprs/IAstExpr.hpp"
#include "../../common/Evaluation.hpp"



struct AstStmt_stmts: public IAstStmt {
	std::vector<PAstStmt> m_body;

	AstStmt_stmts (antlr4::Token *_token): IAstStmt (_token) {}

	void SetMembers (fa::ParseType _type, std::vector<AstObj *> _values) override {
		if (_type == fa::ParseType::Part_Member) {
			for (auto _value : _values)
				m_body.push_back (std::shared_ptr<IAstStmt> (dynamic_cast<IAstStmt *> (_value)));
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	PAstStmt ProcessCodeType () override {
		CompileEnv::CurrentFuncVariables.AddLevel ();
		for (int i = 0; i < m_body.size (); ++i)
			m_body [i] = m_body [i]->ProcessCodeType ();
		CompileEnv::CurrentFuncVariables.RemoveLevel ();
		return shared_from_this ();
	}

	void Evaluate (Evaluation &_eval) override { throw fa::Exception (m_token, "not implement"); }
};



#endif //__AST_STMT_STMTS_HPP__

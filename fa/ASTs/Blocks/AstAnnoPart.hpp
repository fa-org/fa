#include "AstClassVar.hpp"

#ifndef __AST_ANNOTATION_PART_HPP__
#define __AST_ANNOTATION_PART_HPP__



#include <map>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "IAstBlock.hpp"
#include "../Exprs/IAstExpr.hpp"
#include "../Exprs/AstExpr_value.hpp"
#include "../Stmts/IAstStmt.hpp"



struct AstClass;
struct AstAnnoPart;
using PAstAnnoPart = std::shared_ptr<AstAnnoPart>;

struct AstAnnoPart: public IAstBlock, public std::enable_shared_from_this<AstAnnoPart> {
	std::string m_tmp_name = "";
	std::shared_ptr<AstClass> m_parent;
	std::map<std::string, PAstExpr> m_var_values;
private:
	std::vector<std::string> m_tmp_vars;

public:
	AstAnnoPart (antlr4::Token *_token): IAstBlock (_token) {}

	void SetValues (fa::ParseValueType _type, std::vector<fa::ParseValue_t> _values) override {
		if (_type == fa::ParseValueType::Name) {
			m_tmp_name = std::get<std::string> (_values [0]);
		} else if (_type == fa::ParseValueType::Part_Name) {
			for (auto &_value : _values)
				m_tmp_vars.push_back (std::get<std::string> (_value));
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	void SetMembers (fa::ParseType _type, std::vector<AstObj *> _values) override {
		if (_type == fa::ParseType::Part_Member) {
			for (auto &_value : _values) {
				m_var_values.emplace (m_tmp_vars [0], std::shared_ptr<IAstExpr> (dynamic_cast<IAstExpr *> (_value)));
				m_tmp_vars.erase (m_tmp_vars.begin ());
			}
			if (m_tmp_vars.size () != 0)
				throw fa::Exception (m_token, "not implement");
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	void ProcessDeclareType ();

	void ProcessCodeType ();

	PAstExpr GetValue (std::string _name);

	PAstAnnoPart Clone ();
};



#endif //__AST_ANNOTATION_PART_HPP__

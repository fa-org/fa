#ifndef __AST_CLASS_VAR_HPP__
#define __AST_CLASS_VAR_HPP__



#include <memory>
#include <string>

#include "IAstBlock.hpp"
#include "../Exprs/IAstExpr.hpp"
#include "../Stmts/IAstStmt.hpp"
#include "../Types/IAstType.hpp"
#include "../Types/AstType_void.hpp"
#include "../../common/CompileEnv.hpp"



struct AstAnnoPart;
struct AstClass;
struct AstClassFuncEmpty;

template<typename TAstAnnoPart>
struct _AstClassVar: public IAstBlock {
	AstClass *m_parent = nullptr;
	std::vector<std::shared_ptr<TAstAnnoPart>> m_anno_parts;
	fa::PublicLevel m_level;
	bool m_static = false;
	std::string m_name = "";
	std::optional<PAstType> m_type;
	std::map<std::string, std::shared_ptr<AstClassFuncEmpty>> m_funcs;
	std::optional<PAstExpr> m_init_value;

	_AstClassVar (antlr4::Token *_token);

	void SetValues (fa::ParseValueType _type, std::vector<fa::ParseValue_t> _values) override {
		if (_type == fa::ParseValueType::PublicLevel) {
			m_level = std::get<fa::PublicLevel> (_values [0]);
		} else if (_type == fa::ParseValueType::Static) {
			m_static = std::get<bool> (_values [0]);
		} else if (_type == fa::ParseValueType::Name) {
			m_name = std::get<std::string> (_values [0]);
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	void SetMembers (fa::ParseType _type, std::vector<AstObj *> _values) override;

	void ProcessDeclareType () override {
		CompileEnv::CurrentClass = m_parent->shared_from_this ();
		CompileEnv::CurrentFunc = nullptr;
		if (m_type.has_value ())
			m_type = m_type.value ()->ProcessDeclareType ();
	}

	void ProcessCodeType () override {
		CompileEnv::CurrentClass = m_parent->shared_from_this ();
		CompileEnv::CurrentFunc = nullptr;
		if (m_init_value.has_value ()) {
			m_init_value = m_init_value.value ()->ProcessCodeType (m_type);
			if (!m_type.has_value ())
				m_type = m_init_value.value ()->m_real_type.value ();
		}
	}

	PAstExpr GetRef () {
		throw fa::Exception (m_token, "not implement");
	}

	std::shared_ptr<_AstClassVar<AstAnnoPart>> Clone (std::shared_ptr<AstClass> _cls);
};

using AstClassVar = _AstClassVar<AstAnnoPart>;
using PAstClassVar = std::shared_ptr<AstClassVar>;



#endif //__AST_CLASS_VAR_HPP__

#ifndef __ICLASS_HPP__
#define __ICLASS_HPP__



#include <map>
#include <memory>
#include <string>
#include <vector>

#include "IAstBlock.hpp"
#include "AstAnnoPart.hpp"
#include "AstEnumItem.hpp"
#include "AstClassVar.hpp"
#include "../Types/AstType_class.hpp"



enum class ClassType { Class, Enum, Anno };
inline std::string GetClassTypeName (ClassType type) {
	if (type == ClassType::Class) { return "class"; }
	if (type == ClassType::Enum) { return "enum"; }
	if (type == ClassType::Anno) { return "anno"; }
	throw fa::Exception (nullptr, "not implement");
}
inline ClassType GetClassTypeFromName (std::string type) {
	if (type == "class") return ClassType::Class;
	if (type == "enum") return ClassType::Enum;
	if (type == "anno") return ClassType::Anno;
	throw fa::Exception (nullptr, "not implement");
}

struct AstClass: public IAstBlock, public std::enable_shared_from_this<AstClass> {
	std::vector<std::shared_ptr<AstAnnoPart>> m_anno_parts;
	fa::PublicLevel m_level = fa::PublicLevel::Public;
	ClassType m_class_type = ClassType::Class;
	std::string m_full_name = "";
	std::string m_name = "";
	std::vector<std::shared_ptr<AstEnumItem>> m_enum_items;
	std::map<std::string, std::shared_ptr<AstClassVar>> m_vars;
	std::map<std::string, std::shared_ptr<AstClassFuncEmpty>> m_funcs;
	bool m_processed_declare = false, m_processed_code = false;
	// no template class:   m_tpl_names.size() == 0 & m_tpl_inst_types.size() == 0
	// template class:      m_tpl_names.size() > 0 & m_tpl_inst_types.size() == 0
	// template inst class: m_tpl_names.size() > 0 & m_tpl_inst_types.size() > 0
	std::vector<std::string> m_tpl_names;
	std::vector<PAstType> m_tpl_inst_types;
	std::map<std::string, std::shared_ptr<AstClass>> m_tpl_insts;

	AstClass (antlr4::Token *_token, ClassType _type): IAstBlock (_token) { m_class_type = _type; }
	AstClass (antlr4::Token *_token, std::string _type): IAstBlock (_token) { m_class_type = GetClassTypeFromName (_type); }

	void SetMembers (fa::ParseType _type, std::vector<AstObj *> _values) override;

	void SetValues (fa::ParseValueType _type, std::vector<fa::ParseValue_t> _values) override;

	std::vector<fa::ParseValue_t> GetValues (fa::ParseValueType _type) override {
		if (_type == fa::ParseValueType::Name) {
			return { m_name };
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	void ProcessDeclareType () override;

	void ProcessCodeType () override;

	PAstType GetType ();

	bool IsSameClass (const AstClass *_other) const { return m_full_name == _other->m_full_name; }

	std::shared_ptr<AstClass> GetInst (std::vector<PAstType> _tpl_inst_types);
	bool IsPureClass () { return m_tpl_names.size () == 0; }
	bool IsTemplateClass () { return m_tpl_names.size () > 0 || m_tpl_inst_types.size () == 0; }
	bool IsTemplateInstClass () { return m_tpl_inst_types.size () > 0; }
};



#endif //__ICLASS_HPP__

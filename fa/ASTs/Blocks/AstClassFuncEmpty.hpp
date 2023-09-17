#ifndef __AST_EMPTY_FUNC_HPP__
#define __AST_EMPTY_FUNC_HPP__



#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "../../common/StrUtils.hpp"
#include "../Blocks/AstAnnoPart.hpp"
#include "../Exprs/NameExprs/AstNameExpr_arg.hpp"
#include "../Stmts/IAstStmt.hpp"
#include "../Types/IAstType.hpp"
#include "../Types/AstType_func.hpp"
#include "../../common/CompileEnv.hpp"



struct AstClass;

struct AstClassFuncEmpty: public IAstBlock, public std::enable_shared_from_this<AstClassFuncEmpty> {
	AstClass *m_parent = nullptr;
	std::vector<std::shared_ptr<AstAnnoPart>> m_anno_parts;
	fa::PublicLevel m_level = fa::PublicLevel::Public;
	bool m_static = true;
	std::string m_name = "";
	std::vector<std::string> m_tpl_names;
	PAstType m_ret_type { nullptr };
	std::vector<fa::ArgAttr> m_arg_attrs;
	std::vector<PAstType> m_arg_types;
	std::vector<std::string> m_arg_names;
	bool m_processed_code = false;
	std::vector<std::string> m_tpl_names;
	std::vector<PAstType> m_tpl_inst_types;
	std::map<std::string, std::shared_ptr<AstClassFuncEmpty>> m_tpl_insts;

	AstClassFuncEmpty (antlr4::Token *_token): IAstBlock (_token) {}

	void SetMembers (fa::ParseType _type, std::vector<AstObj *> _values) override;

	void SetValues (fa::ParseValueType _type, std::vector<fa::ParseValue_t> _values) override {
		if (_type == fa::ParseValueType::PublicLevel) {
			m_level = std::get<fa::PublicLevel> (_values [0]);
		} else if (_type == fa::ParseValueType::Static) {
			m_static = std::get<bool> (_values [0]);
		} else if (_type == fa::ParseValueType::Name) {
			m_name = std::get<std::string> (_values [0]);
		} else if (_type == fa::ParseValueType::Templates) {
			for (auto &_value : _values)
				m_tpl_names.push_back (std::get<std::string> (_value));
		} else if (_type == fa::ParseValueType::Part_ArgAttr) {
			for (auto _value : _values)
				m_arg_attrs.push_back (std::get<fa::ArgAttr> (_value));
		} else if (_type == fa::ParseValueType::Part_ArgName) {
			for (auto _value : _values)
				m_arg_names.push_back (std::get<std::string> (_value));
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	void ProcessDeclareType () override;

	void ProcessCodeType () override;

	PAstType GetFuncType () {
		CompileEnv::PushEnv ();
		ProcessDeclareType ();
		CompileEnv::PopEnv ();
		return AstType_func::Make (m_token, m_ret_type, m_arg_attrs, m_arg_types);
	}

	PAstExpr GetArgumentRef (antlr4::Token *_token, size_t _arg_index) {
		return AstNameExpr_argument::Make (_token, shared_from_this (), _arg_index);
	}

	virtual std::shared_ptr<AstClassFuncEmpty> Clone (std::shared_ptr<AstClass> _cls) {
		auto _new_func = std::make_shared<AstClassFuncEmpty> (m_token);
		do_Clone (_new_func.get (), _cls);
		return _new_func;
	}

	void MarkTemplateType (std::vector<PAstType> &_template_types) {
		for (size_t i = 0; i < _template_types.size (); ++i)
			_template_types [i] = _template_types [i]->ProcessDeclareType ();
		std::string _type_name = StrUtils::GetName(_template_types);
		//
		if (m_tpl_insts.contains (_type_name))
			return;
		std::shared_ptr<AstClassFuncEmpty> _ptr = m_processed_code ? ProcessInstanceCodeType (_type_name, _template_types) : nullptr;
		m_tpl_insts.emplace (_type_name, AstClassFuncInst {_template_types, _ptr});
	}

	bool IsSameFunc (const AstClassFuncEmpty *_other) const;

	virtual std::shared_ptr<AstClassFuncEmpty> GetInst (std::vector<PAstType> _tpl_inst_types);

protected:
	void do_Clone (AstClassFuncEmpty *_new_func, std::shared_ptr<AstClass> _cls);
};



#endif //__AST_EMPTY_FUNC_HPP__

#ifndef __AST_CLASS_FUNC_HPP__
#define __AST_CLASS_FUNC_HPP__



#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "AstClassFuncEmpty.hpp"
#include "../Stmts/IAstStmt.hpp"
#include "../Types/AstType_func.hpp"
#include "../Types/IAstType.hpp"
#include "../../common/CompileEnv.hpp"



struct AstClass;

struct AstClassFunc: public AstClassFuncEmpty {
	std::vector<PAstStmt> m_contents;

	AstClassFunc (antlr4::Token *_token): AstClassFuncEmpty (_token) {}

	void SetMembers (fa::ParseType _type, std::vector<AstObj *> _values) override {
		if (_type == fa::ParseType::Part_FuncBody) {
			for (auto _value : _values) {
				m_contents.push_back (std::shared_ptr<IAstStmt> (dynamic_cast<IAstStmt *> (_value)));
			}
		} else {
			return AstClassFuncEmpty::SetMembers (_type, _values);
		}
	}

	void ProcessDeclareType () override {
		AstClassFuncEmpty::ProcessDeclareType ();
	}

	void ProcessCodeType () override {
		if (m_processed_code)
			return;
		AstClassFuncEmpty::ProcessCodeType ();
		CompileEnv::CurrentFuncVariables.Clear ();
		CompileEnv::CurrentFuncVariables.AddFunc (shared_from_this ());
		for (auto &_stmt : m_contents)
			_stmt = _stmt->ProcessCodeType ();
		CompileEnv::CurrentFuncVariables.RemoveFunc (shared_from_this ());
	}

	PAstType GetFuncType () {
		CompileEnv::PushEnv ();
		ProcessDeclareType ();
		CompileEnv::PopEnv ();
		return AstType_func::Make (m_token, m_ret_type, m_arg_attrs, m_arg_types);
	}

	std::shared_ptr<AstClassFuncEmpty> Clone (std::shared_ptr<AstClass> _cls) override {
		auto _new_func = new AstClassFunc (m_token);
		do_Clone (_new_func, _cls);
		for (auto &_item : m_contents)
			_new_func->m_contents.push_back (_item->ProcessCodeType ());
		return std::shared_ptr<AstClassFuncEmpty> (_new_func);
	}

	virtual std::shared_ptr<AstClassFuncEmpty> GetInst (std::vector<PAstType> _tpl_inst_types) {
		if (_tpl_inst_types.size () == 0) {
			throw fa::Exception (m_token, "not implement");
		}
		if (m_tpl_inst_types.size () != 0) {
			throw fa::Exception (m_token, "not implement");
		}
		if (_tpl_inst_types.size () != m_tpl_names.size ()) {
			throw fa::Exception (m_token, "not implement");
		}
		auto _new_func = new AstClassFunc (m_token);
		_new_func->m_parent = m_parent;
		_new_func->m_anno_parts = m_anno_parts;
		_new_func->m_level = m_level;
		_new_func->m_static = m_static;
		_new_func->m_name = m_name;
		_new_func->m_tpl_names = m_tpl_names;
		_new_func->m_ret_type = m_ret_type;
		_new_func->m_arg_attrs = m_arg_attrs;
		_new_func->m_arg_types = m_arg_types;
		_new_func->m_arg_names = m_arg_names;
		_new_func->m_tpl_names = m_tpl_names;
		_new_func->m_tpl_inst_types = _tpl_inst_types;
		for (size_t i = 0; i < _tpl_inst_types.size (); ++i)
			_tpl_inst_types [i] = _tpl_inst_types [i]->ProcessDeclareType ();
		for (auto &_stmt : m_contents) {
			_new_func->m_contents.push_back (_stmt->Clone ());
		}
		std::string _type_name = StrUtils::GetName (_tpl_inst_types);
		auto _new_func2 = std::shared_ptr<AstClassFuncEmpty> (_new_func);
		m_tpl_insts.insert (std::make_pair (_type_name, _new_func2));
		return _new_func2;
	}
};



#endif //__AST_CLASS_FUNC_HPP__

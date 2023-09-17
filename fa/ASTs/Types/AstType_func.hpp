#ifndef __AST_TYPE_FUNC_HPP__
#define __AST_TYPE_FUNC_HPP__



#include <format>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "IAstType.hpp"



struct AstType_func: public IAstType {
	PAstType m_ret_type;
	std::vector<fa::ArgAttr> m_arg_attrs;
	std::vector<PAstType> m_arg_types;

	AstType_func (antlr4::Token *_token): IAstType (_token), m_ret_type (nullptr) {}
	AstType_func (antlr4::Token *_token, PAstType _ret_type, std::vector<fa::ArgAttr> _arg_attrs, std::vector<PAstType> _arg_types):
		IAstType (_token), m_ret_type (_ret_type), m_arg_attrs (_arg_attrs), m_arg_types (_arg_types) {}

	PAstType ProcessDeclareType () override {
		m_ret_type = m_ret_type->ProcessDeclareType ();
		for (size_t i = 0; i < m_arg_types.size (); ++i)
			m_arg_types [i] = m_arg_types [i]->ProcessDeclareType ();
		return shared_from_this ();
	}

	std::vector<AstType_unsure_wrap *> GetTypeTemplates () override {
		std::vector<AstType_unsure_wrap *> _v = m_ret_type->GetTypeTemplates (), _v2;
		for (size_t i = 0; i < m_arg_types.size (); ++i) {
			_v2 = m_arg_types [i]->GetTypeTemplates ();
			_v.insert (_v.end (), _v2.begin (), _v2.end ());
		}
		return _v;
	}

	bool NeedSure () override {
		if (m_ret_type->NeedSure ())
			return true;
		for (auto &_arg_type : m_arg_types) {
			if (_arg_type->NeedSure ())
				return true;
		}
		return false;
	}

	std::string GetTypeName () override {
		std::stringstream _ss {};
		_ss << "AstClassFunc<" << m_ret_type->GetTypeName ();
		for (size_t i = 0; i < m_arg_types.size (); ++i) {
			_ss << ", ";
			_ss << m_arg_types [i]->GetTypeName ();
		}
		_ss << ">";
		return _ss.str ();
	}

	static PAstType Make (antlr4::Token *_token, PAstType _ret_type, std::vector<fa::ArgAttr> _arg_attrs, std::vector<PAstType> _arg_types) {
		return std::shared_ptr<IAstType> (new AstType_func { _token, _ret_type, _arg_attrs, _arg_types });
	}
};



#endif //__AST_TYPE_FUNC_HPP__

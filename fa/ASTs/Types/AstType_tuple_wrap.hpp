#ifndef __AST_TYPE_TUPLE_WRAP_HPP__
#define __AST_TYPE_TUPLE_WRAP_HPP__



#include <format>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "IAstType.hpp"



struct AstType_tuple_wrap: public IAstType {
	std::vector<PAstType> m_base_types;
	std::vector<std::string> m_base_names;

	AstType_tuple_wrap (antlr4::Token *_token, std::vector<PAstType> _base_types, std::vector<std::string> _base_names): IAstType (_token) {
		m_base_types.assign (_base_types.begin (), _base_types.end ());
		m_base_names.assign (_base_names.begin (), _base_names.end ());
	}

	PAstType ProcessDeclareType () override {
		for (size_t i = 0; i < m_base_types.size (); ++i)
			m_base_types [i] = m_base_types [i]->ProcessDeclareType ();
		return shared_from_this ();
	}

	std::vector<AstType_unsure_wrap *> GetTypeTemplates () override {
		std::vector<AstType_unsure_wrap *> _v, _v2;
		for (size_t i = 0; i < m_base_types.size (); ++i) {
			_v2 = m_base_types [i]->GetTypeTemplates ();
			_v.insert (_v.end (), _v2.begin (), _v2.end ());
		}
		return _v;
	}

	bool NeedSure () override {
		for (auto &_base_type : m_base_types) {
			if (_base_type->NeedSure ())
				return true;
		}
		return false;
	}

	std::string GetTypeName () {
		std::stringstream _ss {};
		_ss << "(";
		for (size_t i = 0; i < m_base_types.size (); ++i) {
			if (i > 0)
				_ss << ", ";
			_ss << m_base_types [i]->GetTypeName ();
		}
		_ss << ")";
		return _ss.str ();
	}

	static PAstType Make (antlr4::Token *_token, std::vector<PAstType> _base_types, std::vector<std::string> _base_names) {
		return std::shared_ptr<IAstType> (new AstType_tuple_wrap { _token, _base_types, _base_names });
	}
};



#endif //__AST_TYPE_TUPLE_WRAP_HPP__

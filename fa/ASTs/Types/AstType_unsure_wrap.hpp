#ifndef __AST_TYPE_UNSURE_WRAP_HPP__
#define __AST_TYPE_UNSURE_WRAP_HPP__



#include <format>
#include <memory>
#include <sstream>

#include "IAstType.hpp"



struct AstType_unsure_wrap: public IAstType {
	std::vector<PAstType> m_base_types;
	std::string m_full_name;
	std::string m_name;

	AstType_unsure_wrap (antlr4::Token *_token): IAstType (_token) {}
	AstType_unsure_wrap (antlr4::Token *_token, std::vector<PAstType> _base_types, std::string _name):
		IAstType (_token), m_base_types (_base_types), m_name (_name) {}

	void SetValues (fa::ParseValueType _type, std::vector<fa::ParseValue_t> _values) override {
		if (_type == fa::ParseValueType::Name) {
			m_name = std::get<std::string> (_values [0]);
		} else if (_type == fa::ParseValueType::FullName) {
			m_full_name = std::get<std::string> (_values [0]);
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	void SetMembers (fa::ParseType _type, std::vector<AstObj *> _values) override {
		if (_type == fa::ParseType::Part_Member) {
			for (auto _value : _values)
				m_base_types.push_back (std::shared_ptr<IAstType> (dynamic_cast<IAstType *> (_value)));
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	std::vector<fa::ParseValue_t> GetValues (fa::ParseValueType _type) override {
		if (_type == fa::ParseValueType::Name) {
			return { m_name };
		} else {
			throw fa::Exception (m_token, "not implement");
		}
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

	std::string GetTypeName () { return m_full_name; }

	static PAstType Make (antlr4::Token *_token, std::vector<PAstType> _base_types, std::string _type_name) {
		return std::shared_ptr<IAstType> (new AstType_unsure_wrap { _token, _base_types, _type_name });
	}

	std::string GenCppExpandType () {
		return m_name;
		//std::stringstream _ss {};
		//for (size_t i = 0; i < m_base_types.size (); ++i) {
		//	if (i > 0)
		//		_ss << " || ";
		//	if (auto _unsure_wrap = dynamic_cast<AstType_unsure_wrap *> (m_base_types [i].get ())) {
		//		_ss << _unsure_wrap->GenCppExpandType ();
		//	} else {
		//		_ss << std::format ("std::is_same<T, {}>::value", m_base_types [i]->GenCppCode (0));
		//	}
		//}
		//return _ss.str ();
	}
};



#endif //__AST_TYPE_UNSURE_WRAP_HPP__

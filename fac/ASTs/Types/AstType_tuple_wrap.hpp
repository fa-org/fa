#ifndef __AST_TYPE_TUPLE_WRAP_HPP__
#define __AST_TYPE_TUPLE_WRAP_HPP__



#include <format>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "IAstType.hpp"



struct AstType_tuple_wrap: public IAstType {
	std::vector<std::shared_ptr<IAstType>> m_base_types;
	std::vector<std::string> m_base_names;

	AstType_tuple_wrap (std::vector<std::shared_ptr<IAstType>> _base_types, std::vector<std::string> _base_names) {
		m_base_types.assign (_base_types.begin (), _base_types.end ());
		m_base_names.assign (_base_names.begin (), _base_names.end ());
	}
	std::string GenCppCode () override {
		std::stringstream _ss {};
		_ss << "std::tuple<";
		for (size_t i = 0; i < m_base_types.size (); ++i) {
			if (i > 0)
				_ss << ", ";
			_ss << m_base_types [i]->GenCppCode ();
		}
		_ss << ">";
		return _ss.str ();
	}

	static std::shared_ptr<IAstType> Make (std::vector<std::shared_ptr<IAstType>> _base_types, std::vector<std::string> _base_names) {
		return std::shared_ptr<IAstType> ((IAstType *) new AstType_tuple_wrap { _base_types, _base_names });
	}
};



#endif //__AST_TYPE_TUPLE_WRAP_HPP__

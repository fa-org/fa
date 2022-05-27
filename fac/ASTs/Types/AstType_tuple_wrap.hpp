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

	AstType_tuple_wrap (std::vector<std::shared_ptr<IAstType>> _base_types): m_base_types (_base_types) {}
	std::string GenCppCode () override {
		std::stringstream _ss;
		_ss << "std::tuple<";
		for (size_t i = 0; i < m_base_types.size (); ++i) {
			if (i > 0)
				_ss << ", ";
			_ss << m_base_types [i]->GenCppCode ();
		}
		_ss << ">";
		return _ss.str ();
	}
};



#endif //__AST_TYPE_TUPLE_WRAP_HPP__

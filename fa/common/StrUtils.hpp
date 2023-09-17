#ifndef __STR_UTILS_HPP__
#define __STR_UTILS_HPP__



#include <sstream>
#include <string>
#include <vector>

#include "../ASTs/Types/IAstType.hpp"



struct StrUtils {
	static std::string GetName (std::vector<PAstType> &_template_types) {
		std::stringstream _ss;
		for (size_t i = 0; i < _template_types.size (); ++i) {
			if (i > 0)
				_ss << ", ";
			_ss << _template_types [i];
		}
		return _ss.str ();
	}
};



#endif //__STR_UTILS_HPP__

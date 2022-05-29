#ifndef __IAST_HPP__
#define __IAST_HPP__



#include <string>

#include "../antlr_gen/FaParser.h"



struct IAst {
	virtual std::string GenCppCode (size_t _indent) = 0;
};

#endif //__IAST_HPP__

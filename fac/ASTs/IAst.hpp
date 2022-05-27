#ifndef __IAST_HPP__
#define __IAST_HPP__



#include <string>



struct IAst {
	virtual std::string GenCppCode () = 0;
};

#endif //__IAST_HPP__

#ifndef __IAST_BLOCK_HPP__
#define __IAST_BLOCK_HPP__



#include <functional>

#include "../IAst.hpp"



struct IAstBlock: public IAst {
	IAstBlock (antlr4::Token *_token): IAst (_token) {}

	virtual void ProcessDeclareType () = 0;
	virtual void ProcessCodeType () = 0;
};



#endif //__IAST_BLOCK_HPP__

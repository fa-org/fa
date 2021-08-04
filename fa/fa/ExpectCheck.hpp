#ifndef __EXPECT_CHECK_HPP__
#define __EXPECT_CHECK_HPP__



#include <string>

#include <antlr4-runtime/Token.h>

#include "Log.hpp"



class ExpectCheck {
public:
	static bool DoCheck (std::string _type, std::string _expect_type, antlr4::Token *_t) {
		if (_type == "") {
			LOG_ERROR (_t, "未推断出原始类型");
			return false;
		} else if (_expect_type == "" || _type == _expect_type) {
			return true;
		} else {
			LOG_TODO (_t);
			return false;
		}
	}
};



#endif //__EXPECT_CHECK_HPP__

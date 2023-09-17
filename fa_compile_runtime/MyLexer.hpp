#ifndef __MY_LEXER_HPP__
#define __MY_LEXER_HPP__



#include <stack>

#ifndef ANTLR4CPP_STATIC
#	define ANTLR4CPP_STATIC
#endif
#include <antlr4-runtime/antlr4-runtime.h>



struct MyLexer: public antlr4::Lexer {
	int interpolatedStringLevel = 0;
	std::stack<bool> interpolatedVerbatiums;
	std::stack<int> curlyLevels;
	bool verbatium = false;

	MyLexer (antlr4::CharStream *input): antlr4::Lexer (input) {}

	void OnColon () {
		if (interpolatedStringLevel > 0 && curlyLevels.top () == 1) {
			int ind = 1;
			bool switchToFormatString = true;
			char _la = (char) _input->LA (ind);
			while (_la != '}') {
				if (_la == ':' || _la == ')') {
					switchToFormatString = false;
					break;
				}
				ind++;
				_la = (char) _input->LA (ind);
			}
			if (switchToFormatString) {
				size_t get_INTERPOLATION_FORMAT ();
				setMode (get_INTERPOLATION_FORMAT ());
			}
		}
	}
	void OnQuotL () {
		if (interpolatedStringLevel > 0)
			curlyLevels.top () += 1;
	}
	void OnQuotR () {
		if (interpolatedStringLevel > 0) {
			curlyLevels.top () -= 1;
			if (curlyLevels.top () == 0) {
				curlyLevels.pop ();
				skip ();
				popMode ();
			}
		}
	}
	void OnInterpolatedRegularStringStart () {
		interpolatedStringLevel++;
		interpolatedVerbatiums.push (false);
		verbatium = false;
	}
	void OnInterpolatedVerbatiumStringStart () {
		interpolatedStringLevel++;
		interpolatedVerbatiums.push (true);
		verbatium = true;
	}
	void OnQHuaLInside () { curlyLevels.push(1); }
	void OnQHuaRInside () { curlyLevels.pop(); }
	void OnDoubleQuoteInside () {
		interpolatedStringLevel--;
        interpolatedVerbatiums.pop();
        verbatium = (interpolatedVerbatiums.size() > 0 ? interpolatedVerbatiums.top() : false);
	}
	bool IsRegularCharInside () { return !verbatium; }
	bool IsVerbatiumDoubleQuoteInside () { return verbatium; }
};



#endif //__MY_LEXER_HPP__

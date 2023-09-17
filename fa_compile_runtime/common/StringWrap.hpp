#ifndef __STRING_WRAP_HPP__
#define __STRING_WRAP_HPP__



#include <filesystem>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <string_view>



struct StringWrap {
	static std::string GetRealValue (antlr4::tree::TerminalNode *_node) {
		return GetRealValue (_node->getSymbol (), _node->getText ());
	}
	static std::string GetRealValue (antlr4::ParserRuleContext *_ctx) {
		return GetRealValue (_ctx->start, _ctx->getText ());
	}

	static std::string GetRealValue (antlr4::Token *_token, std::string _src) {
		char _qch = _src [_src.size () - 1];
		_src = _src.substr (0, _src.size () - 1);
		bool _escape = true;
		while (true) {
			char _ch = _src [0];
			_src.erase (_src.begin ());
			if (_ch == '@') {
				_escape = false;
			} else if (_ch == '\'' || _ch == '"') {
				break;
			}
		}
		std::stringstream _dest;
		if (_escape) {
			for (size_t i = 0; i < _src.size (); ++i) {
				if (_src [i] == '\\') {
					_dest << _get_encoded_char (_src [++i]);
				} else {
					_dest << _src [i];
				}
			}
		} else {
			for (size_t i = 0; i < _src.size (); ++i) {
				_dest << _src[i];
				if (_src [i] == _qch)
					++i;
			}
		}
		return _dest.str ();
	}

	static std::string GetEscapeString (std::string _src) {
		static std::map<char, std::string> s_map { { '\a', "\\a" }, { '\b', "\\b" }, { '\f', "\\f" }, {'\n', "\\n" }, {'\r', "\\r" }, {'\t', "\\t" }, {'\v', "\\v" }, {'\0', "\\0" }};

		std::stringstream _ss {};
		_ss << "\"";
		for (char _ch : _src) {
			if (s_map.contains (_ch)) {
				_ss << s_map [_ch];
			} else {
				_ss << _ch;
			}
		}
		_ss << "\"";
		return _ss.str ();
	}

private:
	static char _get_encoded_char (char _ch) {
		static std::map<char, char> s_map { { 'a', '\a' }, { 'b', '\b' }, { 'f', '\f' }, { 'n', '\n' }, { 'r', '\r' }, { 't', '\t' }, { 'v', '\v' }, { '0', '\0' } };
		auto _p = s_map.find (_ch);
		return _p == s_map.end () ? _ch : _p->second;
	}
};



#endif //__STRING_WRAP_HPP__

#ifndef __STRING_PROCESSOR_HPP__
#define __STRING_PROCESSOR_HPP__



#include <format>
#include <iostream>
#include <optional>
#include <string>

#include <antlr4-runtime/Token.h>

#include "Log.hpp"



class StringProcessor {
	static std::optional<char> _char_to_hex (char _ch, antlr4::Token* _t) {
		if (_ch >= '0' && _ch <= '9') {
			return _ch - '0';
		} else if (_ch >= 'A' && _ch <= 'F') {
			return _ch - 'A' + 10;
		} else if (_ch >= 'a' && _ch <= 'f') {
			return _ch - 'a' + 10;
		}
		LOG_ERROR (_t, std::format ("字符 '{}' 无法转为十六进制数字", _ch));
		return std::nullopt;
	}

public:
	static std::optional<std::string> TransformMean (std::string _s, antlr4::Token* _t) {
		std::string _tmp = _s;
		std::optional<char> _c1, _c2;
		for (size_t i = 0; i < _s.size (); ++i) {
			if (_s [i] == '\\') {
				switch (_s [i + 1]) {
					case 'r':
						_s [i] = '\r';
						_s.erase (i + 1);
						break;
					case 'n':
						_s [i] = '\n';
						_s.erase (i + 1);
						break;
					case 't':
						_s [i] = '\t';
						_s.erase (i + 1);
						break;
					case '\'':
						_s [i] = '\'';
						_s.erase (i + 1);
						break;
					case '\"':
						_s [i] = '\"';
						_s.erase (i + 1);
						break;
					case '\\':
						_s [i] = '\\';
						_s.erase (i + 1);
						break;
					case 'x':
						_c1 = _char_to_hex (_s [i + 2], _t), _c2 = _char_to_hex (_s [i + 3], _t);
						if ((!_c1.has_value ()) || (!_c2.has_value ())) {
							LOG_ERROR (_t, std::format ("    转义字符串 \"{}\" 失败", _tmp));
							return std::nullopt;
						}
						_s [i] = (_c1.value () << 4) + _c2.value ();
						_s.erase (i + 1, 3);
						break;
					case 'u':
						_c1 = _char_to_hex (_s [i + 2], _t), _c2 = _char_to_hex (_s [i + 3], _t);
						if ((!_c1.has_value ()) || (!_c2.has_value ())) {
							LOG_ERROR (_t, std::format ("    转义字符串 \"{}\" 失败", _tmp));
							return std::nullopt;
						}
						_s [i] = (_c1.value () << 4) + _c2.value ();
						//
						_c1 = _char_to_hex (_s [i + 4], _t), _c2 = _char_to_hex (_s [i + 5], _t);
						if ((!_c1.has_value ()) || (!_c2.has_value ())) {
							LOG_ERROR (_t, std::format ("    转义字符串 \"{}\" 失败", _tmp));
							return std::nullopt;
						}
						_s [i + 1] = (_c1.value () << 4) + _c2.value ();
						_s.erase (i + 2, 4);
						break;
					default:
						LOG_ERROR (_t, std::format ("字符 '{}' 无法转义", _s [i + 1]));
						break;
				}
			}
		}
		return _s;
	}
};



#endif //__STRING_PROCESSOR_HPP__

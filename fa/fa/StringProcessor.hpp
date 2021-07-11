#ifndef __STRING_PROCESSOR_HPP__
#define __STRING_PROCESSOR_HPP__



#include <iostream>
#include <string>



class StringProcessor {
	static int _char_to_hex (char _ch) {
		if (_ch >= '0' && _ch <= '9') {
			return _ch - '0';
		} else if (_ch >= 'A' && _ch <= 'F') {
			return _ch - 'A' + 10;
		} else if (_ch >= 'a' && _ch <= 'f') {
			return _ch - 'a' + 10;
		}
		std::cout << "error in" << "char" << std::endl;
		return -1;
	}

public:
	static std::string TransformMean (std::string _s, bool _remove_quot) {
		if (_remove_quot)
			_s.substr (1, _s.size () - 2);
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
						_s [i] = (char) ((_char_to_hex (_s [i + 2]) << 4) + _char_to_hex (_s [i + 3]));
						_s.erase (i + 1, 3);
						break;
					case 'u':
						_s [i] = (char) ((_char_to_hex (_s [i + 2]) << 4) + _char_to_hex (_s [i + 3]));
						_s [i + 1] = (char) ((_char_to_hex (_s [i + 4]) << 4) + _char_to_hex (_s [i + 5]));
						_s.erase (i + 2, 4);
						break;
				}
			}
		}
	}
};



#endif //__STRING_PROCESSOR_HPP__

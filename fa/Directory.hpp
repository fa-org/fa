#ifndef __DIRECTORY_HPP__
#define __DIRECTORY_HPP__



#include <filesystem>
#include <fstream>
#include <string>



struct Directory {
	static std::string GetCurrentPath () {
		return std::filesystem::current_path ().generic_string ();
	}

	static void SetCurrentPath (std::string _path) {
		std::filesystem::current_path (_path);
	}

	static std::string AppendPath (std::string _path1, std::string _path2) {
		if (_path1.size () == 0) {
			return _path2;
		} else if (_path2.size () == 0) {
			return _path1;
		} else {
			bool _sp1 = _path1 [_path1.size () - 1] == '/', _sp2 = _path2 [0] == '/';
			if (_sp1 != _sp2) {
				return _path1 + _path2;
			} else if (_sp1) {
				return _path1 + _path2.substr (1);
			} else {
				return _path1 + "/" + _path2;
			}
		}
	}
};



#endif //__DIRECTORY_HPP__

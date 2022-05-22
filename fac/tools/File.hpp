#ifndef __FILE_HPP__
#define __FILE_HPP__



#include <filesystem>
#include <fstream>
#include <string>



struct File {
	static std::string ReadAllText (std::string _file) {
		std::ifstream ifs (_file, std::ios::binary);
		//m_bytes = std::string ((std::istreambuf_iterator<char> (ifs)), std::istreambuf_iterator<char> ()); // low performance
		ifs.seekg (0, std::ios::end);
		size_t _fsz = (size_t) ifs.tellg ();
		ifs.seekg (0, std::ios::beg);
		std::string _data;
		_data.resize (_fsz);
		ifs.read (&_data [0], (std::streamsize) _fsz);
		ifs.close ();
		return _data;
	}
};



#endif //__FILE_HPP__

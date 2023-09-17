#ifndef __FILE_HPP__
#define __FILE_HPP__



#include <filesystem>
#include <fstream>
#include <string>



struct File {
	static std::string ReadAllText (std::string _file) {
		std::ifstream _ifs (_file, std::ios::binary);
		//m_bytes = std::string ((std::istreambuf_iterator<char> (ifs)), std::istreambuf_iterator<char> ()); // low performance
		_ifs.seekg (0, std::ios::end);
		size_t _fsz = (size_t) _ifs.tellg ();
		if (_fsz == std::string::npos)
			return "";
		_ifs.seekg (0, std::ios::beg);
		std::string _data;
		_data.resize (_fsz);
		_ifs.read (&_data [0], (std::streamsize) _fsz);
		_ifs.close ();
		return _data;
	}

	static void WriteAllText (std::string _file, std::string _data) {
		std::ofstream _ofs (_file, std::ios::binary | std::ios::trunc);
		_ofs.write (_data.data (), _data.size ());
		_ofs.close ();
	}

	static bool IsExist (std::string _path) {
		return std::filesystem::exists (_path) && !std::filesystem::is_directory (_path);
	}

	static bool Delete (std::string _path) {
		return std::filesystem::remove (_path);
	}

	static bool Copy (std::string _src, std::string _dest) { return std::filesystem::copy_file (_src, _dest); }
	static bool Move (std::string _src, std::string _dest) {
		if (IsExist (_src)) {
			std::filesystem::rename (_src, _dest);
			return true;
		}
		return false;
	}
};



#endif //__FILE_HPP__

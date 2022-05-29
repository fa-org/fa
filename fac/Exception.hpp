#ifndef __EXCEPTION_HPP__
#define __EXCEPTION_HPP__



#include <exception>
#include <format>
#include <string>



struct Exception: public std::exception {
	Exception (std::string _err): m_err (_err) {}
	//template<typename ...Args>
	//Exception (std::string _err, Args ..._args) {
	//	m_err = sizeof... (_args) == 0 ? _err : std::vformat (_err, std::make_format_args (_args...));
	//}
	const char* what() const noexcept override { return m_err.c_str (); }

	static Exception NotImplement (const char *_file, int _line) { return Exception (std::format ("not implement in {}:{}", _file, _line)); }

private:
	std::string m_err = "";
};

#define NOT_IMPLEMENT() Exception::NotImplement(__FILE__, __LINE__)



#endif //__EXCEPTION_HPP__

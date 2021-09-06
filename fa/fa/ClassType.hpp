#ifndef __CLASS_TYPE_HPP__
#define __CLASS_TYPE_HPP__



#include <format>
#include <map>
#include <memory>
#include <optional>
#include <set>
#include <string>
#include <tuple>
#include <vector>

//#include "AstValue.hpp"

#include <llvm/IR/Type.h>



enum class PublicLevel { Unknown, Public, Internal, Protected, Private };

class ClassType;



// 类变量的 getter setter 函数
class ClassVarFunc {
public:
	PublicLevel						m_pv;					// 公开级别
	std::string						m_name;					// getter setter 名称
	FaParser::ClassFuncBodyContext*	m_func;					// 函数体

	ClassVarFunc (PublicLevel _pv, std::string _name, FaParser::ClassFuncBodyContext* _func)
		: m_pv (_pv), m_name (_name), m_func (_func) {}
};



// 类变量
class ClassVar {
public:
	PublicLevel						m_pv;					// 公开级别
	bool							m_is_static;			// 是否静态
	std::string						m_type;					// 变量类型
	std::string						m_name;					// 变量名称
	FaParser::ExprContext*			m_init_value = nullptr;	// 初始值
	std::vector<ClassVarFunc>		m_var_funcs;			// 变量 getter setter 函数

	ClassVar (PublicLevel _pv, bool _is_static, std::string _type, std::string _name)
		: m_pv (_pv), m_is_static (_is_static), m_type (_type), m_name (_name) {}

	void SetInitValue (FaParser::ExprContext* _init_value) { m_init_value = _init_value; }

	std::tuple<bool, std::string> AddVarFunc (PublicLevel _pv, std::string _name, FaParser::ClassFuncBodyContext* _func) {
		static std::set<std::string> s_valid_names { "get", "set" };
		if (!s_valid_names.contains (_name))
			return { false, std::format ("类变量不支持 {} 方法", _name) };

		for (auto& _vfunc : m_var_funcs) {
			if (_vfunc.m_name == _name)
				return { false, std::format ("{} 方法已存在", _name) };
		}
		m_var_funcs.push_back (ClassVarFunc { _pv, _name, _func });
		return { true, "" };
	}
};



class ClassFunc {
public:
	ClassFunc () {}
};



class ClassType: public std::enable_shared_from_this<ClassType> {
public:
	PublicLevel								m_level;
	std::string								m_name;
	std::vector<std::string>				m_parents;
	std::vector<std::shared_ptr<ClassVar>>	m_vars;
	llvm::Type								*m_type = nullptr;

	ClassType (PublicLevel _level, std::string _name): m_level (_level), m_name (_name) {}
	void AddParents (std::vector<std::string> &_parents) {
		m_parents.assign (_parents.cbegin (), _parents.cend ());
	}
	std::shared_ptr<ClassVar> AddVar (PublicLevel _pv, bool _is_static, std::string _type, std::string _name) {
		auto _var = std::make_shared<ClassVar> (shared_from_this (), _name, _type, _type);
		m_vars.push_back (_var);
		return _var;
	}

	std::optional<std::shared_ptr<ClassVar>> GetVar (std::string _name) {
		for (auto _var : m_vars) {
			if (_var->m_name == _name)
				return _var;
		}
		return std::nullopt;
	}
};



class ClassTypes {
public:
	std::optional<std::shared_ptr<ClassType>> GetClass (std::string _name) {
		if (m_classes.contains (_name)) {
			return m_classes [_name];
		} else {
			return std::nullopt;
		}
	}
	std::shared_ptr<ClassType> CreateNewClass (PublicLevel _level, std::string _name) {
		auto _cls = std::make_shared<ClassType> (_level, _name);
		m_classes [_name] = _cls;
		return _cls;
	}

private:
	std::map<std::string, std::shared_ptr<ClassType>> m_classes;
};



#endif //__CLASS_TYPE_HPP__

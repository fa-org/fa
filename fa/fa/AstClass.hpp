#ifndef __AST_CLASS_HPP__
#define __AST_CLASS_HPP__



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



// 类变量的 getter setter 函数
class AstClassVarFunc {
public:
	PublicLevel						m_pv;					// 公开级别
	std::string						m_name;					// getter setter 名称
	FaParser::ClassFuncBodyContext*	m_func;					// 函数体

	AstClassVarFunc (PublicLevel _pv, std::string _name, FaParser::ClassFuncBodyContext* _func)
		: m_pv (_pv), m_name (_name), m_func (_func) {}
};



// 类变量
class AstClassVar {
public:
	PublicLevel						m_pv;					// 公开级别
	bool							m_is_static;			// 是否静态
	std::string						m_type;					// 变量类型
	std::string						m_name;					// 变量名称
	FaParser::ExprContext		   *m_init_value = nullptr;	// 初始值
	std::vector<AstClassVarFunc>	m_var_funcs;			// 变量 getter setter 函数

	AstClassVar (PublicLevel _pv, bool _is_static, std::string _type, std::string _name)
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
		m_var_funcs.push_back (AstClassVarFunc { _pv, _name, _func });
		return { true, "" };
	}
};



// 类方法
class AstClassFunc {
public:
	PublicLevel						m_pv;					// 公开级别
	bool							m_is_static;			// 是否静态
	std::string						m_name;					// 方法名称
	std::string						m_ret_type;				// 返回类型
	std::vector<std::string>		m_arg_types;			// 参数类型列表
	std::vector<std::string>		m_arg_names;			// 参数名称列表
	FaParser::ClassFuncBodyContext *m_func = nullptr;		// 函数体

	AstClassFunc (PublicLevel _pv, bool _is_static, std::string _name)
		: m_pv (_pv), m_is_static (_is_static), m_name (_name) {}

	void SetReturnType (std::string _ret_type) { m_ret_type = _ret_type; }

	void SetArgumentTypeName (std::string _type, std::string _name) {
		m_arg_types.push_back (_type);
		m_arg_names.push_back (_name);
	}

	void SetFuncBody (FaParser::ClassFuncBodyContext *_func) { m_func = _func; }
};



class AstClass {
public:
	PublicLevel									m_level;
	std::string									m_name;
	std::vector<std::string>					m_parents;
	std::vector<std::shared_ptr<AstClassVar>>	m_vars;
	std::vector<std::shared_ptr<AstClassFunc>>	m_funcs;
	llvm::Type									*m_type = nullptr;

	AstClass (PublicLevel _level, std::string _name): m_level (_level), m_name (_name) {}
	void AddParents (std::vector<std::string> &_parents) {
		m_parents.assign (_parents.cbegin (), _parents.cend ());
	}

	std::shared_ptr<AstClassVar> AddVar (PublicLevel _pv, bool _is_static, std::string _type, std::string _name) {
		auto _var = std::make_shared<AstClassVar> (_pv, _is_static, _type, _name);
		m_vars.push_back (_var);
		return _var;
	}

	std::shared_ptr<AstClassFunc> AddFunc (PublicLevel _pv, bool _is_static, std::string _name) {
		auto _func = std::make_shared<AstClassFunc> (_pv, _is_static, _name);
		m_funcs.push_back (_func);
		return _func;
	}

	std::optional<std::shared_ptr<AstClassVar>> GetVar (std::string _name) {
		for (auto _var : m_vars) {
			if (_var->m_name == _name)
				return _var;
		}
		return std::nullopt;
	}
};



class AstClasses {
public:
	std::optional<std::shared_ptr<AstClass>> GetClass (std::string _name) {
		if (m_classes.contains (_name)) {
			return m_classes [_name];
		} else {
			return std::nullopt;
		}
	}
	std::shared_ptr<AstClass> CreateNewClass (PublicLevel _level, std::string _name) {
		auto _cls = std::make_shared<AstClass> (_level, _name);
		m_classes [_name] = _cls;
		return _cls;
	}

private:
	std::map<std::string, std::shared_ptr<AstClass>> m_classes;
};



#endif //__AST_CLASS_HPP__

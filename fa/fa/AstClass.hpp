#ifndef __AST_CLASS_HPP__
#define __AST_CLASS_HPP__



#include <format>
#include <functional>
#include <map>
#include <memory>
#include <optional>
#include <set>
#include <string>
#include <tuple>
#include <vector>

//#include "AstValue.hpp"

#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Type.h>

#include <FaParser.h>
#include "FuncType.hpp"



enum class PublicLevel { Unknown, Public, Internal, Protected, Private };

enum class AstClassType { Class, Struct, Interface, Enum };
enum class AstClassItemType { Var, GetterSetter, Func, Constructor, EnumItem };

class AstValue;



// 抽象类成员类型
class IAstClassItem {
public:
	virtual AstClassItemType GetType () = 0;
	virtual std::optional<AstValue> GetAstValue () = 0; // 获取静态变量或函数等
	virtual bool IsStatic () = 0;
	virtual std::string GetStringType () = 0;
};



// 类变量的 getter setter 函数
class AstClassVarFunc {
public:
	PublicLevel						m_pv;					// 公开级别
	std::string						m_name;					// getter setter 名称
	FaParser::ClassFuncBodyContext*	m_func;					// 函数体

	AstClassVarFunc (PublicLevel _pv, std::string _name, FaParser::ClassFuncBodyContext* _func)
		: m_pv (_pv), m_name (_name), m_func (_func) {}
};



// 类成员变量
class AstClassVar: public IAstClassItem {
public:
	antlr4::Token*					m_t = nullptr;			//
	PublicLevel						m_pv;					// 公开级别
	bool							m_is_static;			// 是否静态
	std::string						m_type;					// 变量类型
	std::string						m_name;					// 变量名称
	FaParser::ExprContext*			m_init_value = nullptr;	// 初始值
	std::vector<AstClassVarFunc>	m_var_funcs;			// 变量 getter setter 函数

	AstClassItemType GetType () override { return m_var_funcs.size () > 0 ? AstClassItemType::GetterSetter : AstClassItemType::Var; }
	std::optional<AstValue> GetAstValue () override {
		// TODO 移动实现到cpp里
		if (!m_is_static)
			return std::nullopt;
		// TODO 此处扔全局静态变量
		return std::nullopt;
	}
	bool IsStatic () override { return m_is_static; }
	std::string GetStringType () override { return m_type; }

	AstClassVar (antlr4::Token* _t, PublicLevel _pv, bool _is_static, std::string _type, std::string _name)
		: m_t (_t), m_pv (_pv), m_is_static (_is_static), m_type (_type), m_name (_name) {}

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



// 类成员方法
class AstClassFunc: public IAstClassItem {
public:
	PublicLevel								m_pv;						// 公开级别
	bool									m_is_static;				// 是否静态
	std::string								m_name;						// 方法名称
	std::string								m_name_abi;					// 接口实际方法名称
	std::string								m_ret_type;					// 返回类型
	antlr4::Token*							m_ret_type_t = nullptr;		//
	std::vector<std::string>				m_arg_types;				// 参数类型列表
	std::vector<antlr4::Token*>				m_arg_type_ts;				// 参数类型列表
	std::vector<std::string>				m_arg_names;				// 参数名称列表
	FaParser::ClassFuncBodyContext*			m_func = nullptr;			// 函数体

	AstClassItemType GetType () override { return AstClassItemType::Func; }
	std::optional<AstValue> GetAstValue () override {
		// TODO 实现
		std::nullopt;
	}
	bool IsStatic () override { return m_is_static; }
	std::string GetStringType () override { return m_name_abi; }

	AstClassFunc (PublicLevel _pv, bool _is_static, std::string _name)
		: m_pv (_pv), m_is_static (_is_static), m_name (_name) {}

	void SetReturnType (FaParser::TypeContext* _ret_type_raw) {
		m_ret_type = _ret_type_raw->getText ();
		m_ret_type_t = _ret_type_raw->start;
	}

	void SetArgumentTypeName (FaParser::TypeContext* _arg_type_raw, std::string _name) {
		SetArgumentTypeName (_arg_type_raw->getText (), _arg_type_raw->start, _name);
	}
	void SetArgumentTypeName (std::string _arg_type, antlr4::Token* _arg_type_t, std::string _name) {
		m_arg_types.push_back (_arg_type);
		m_arg_type_ts.push_back (_arg_type_t);
		m_arg_names.push_back (_name);
	}

	void SetFuncBody (FaParser::ClassFuncBodyContext* _func) { m_func = _func; }
};



// 枚举类型成员
class AstClassEnumItem: public IAstClassItem {
public:
	AstClassItemType GetType () override { return AstClassItemType::EnumItem; }
	std::optional<AstValue> GetAstValue () override {
		// TODO 返回常量值
		return std::nullopt;
	}
	bool IsStatic () override { return true; }
	std::string GetStringType () override { return "TODO???????????"; }
	// TODO
};



// 抽象结构体类型
class IAstClass {
public:
	PublicLevel									m_level;
	std::string									m_module_name;
	std::string									m_name;
	std::vector<std::shared_ptr<AstClassFunc>>	m_funcs;

	IAstClass (PublicLevel _level, std::string _module_name, std::string _name):
		m_level (_level), m_module_name (_module_name), m_name (_name) {}

	virtual AstClassType GetType () = 0;
	virtual std::optional<llvm::Type*> GetLlvmType (std::function<std::optional<llvm::Type*> (std::string, antlr4::Token*)> _cb) = 0;
	virtual std::optional<size_t> GetVarIndex (std::string _name) { return std::nullopt; }
	virtual std::optional<std::shared_ptr<IAstClassItem>> GetMember (std::string _name) {
		for (auto _func : m_funcs) {
			if (_func->m_name == _name)
				return std::shared_ptr<IAstClassItem> ((IAstClassItem*) _func.get ());
		}
		return std::nullopt;
	}

	std::shared_ptr<AstClassFunc> AddFunc (PublicLevel _pv, bool _is_static, std::string _name) {
		auto _func = std::make_shared<AstClassFunc> (_pv, _is_static, _name);
		m_funcs.push_back (_func);
		return _func;
	}
};



// 类
class AstClass: public IAstClass {
public:
	std::vector<std::string>					m_parents;
	std::vector<std::shared_ptr<AstClassVar>>	m_vars;
	llvm::StructType*							m_type = nullptr;

	AstClassType GetType () override { return AstClassType::Class; }

	std::optional<llvm::Type*> GetLlvmType (std::function<std::optional<llvm::Type*> (std::string, antlr4::Token*)> _cb) override {
		if (!m_type) {
			std::vector<llvm::Type*> _v;
			for (auto _var : m_vars) {
				auto _otype = _cb (_var->m_type, _var->m_t);
				if (!_otype.has_value ())
					return std::nullopt;
				_v.push_back (_otype.value ());
			}
			if (m_vars.size () == 0) {
				auto _otype = _cb ("int8", nullptr);
				if (!_otype.has_value ())
					return std::nullopt;
				_v.push_back (_otype.value ());
			}
			m_type = llvm::StructType::create (_v);
		}
		return (llvm::Type*) m_type;
	}

	std::optional<std::shared_ptr<IAstClassItem>> GetMember (std::string _name) override {
		for (auto _var : m_vars) {
			if (_var->m_name == _name)
				return std::shared_ptr<IAstClassItem> ((IAstClassItem*) _var.get ());
		}
		return IAstClass::GetMember (_name);
	}



	void AddParents (std::vector<std::string> &_parents) {
		m_parents.assign (_parents.cbegin (), _parents.cend ());
	}

	void AddVar (std::shared_ptr<AstClassVar> _var) {
		m_vars.push_back (_var);
	}

	std::optional<std::shared_ptr<AstClassVar>> GetVar (std::string _name) { // 此方法功能与 GetMember 重复
		for (auto _var : m_vars) {
			if (_var->m_name == _name)
				return _var;
		}
		return std::nullopt;
	}

	std::optional<size_t> GetVarIndex (std::string _name) override {
		for (size_t i = 0; i < m_vars.size (); ++i) {
			if (m_vars [i]->m_name == _name)
				return i;
		}
		return std::nullopt;
	}
};



// 类集合
class AstClasses {
public:
	std::optional<std::shared_ptr<IAstClass>> GetClass (std::string _name, std::string _namesapce) {
		if (m_classes.contains (_name))
			return m_classes [_name];
		size_t _p = _namesapce.find ('.');
		std::string _tmp;
		while (_p != std::string::npos) {
			_tmp = std::format ("{}.{}", _namesapce.substr (0, _p), _name);
			if (m_classes.contains (_tmp))
				return m_classes [_tmp];
			_p = _namesapce.find ('.', _p + 1);
		};
		if (_namesapce != "") {
			_tmp = std::format ("{}.{}", _namesapce, _name);
			if (m_classes.contains (_tmp))
				return m_classes [_tmp];
		}
		return std::nullopt;
	}

	std::shared_ptr<AstClass> CreateNewClass (PublicLevel _level, std::string _module_name, std::string _name) {
		auto _cls = std::make_shared<AstClass> (_level, _module_name, _name);
		m_classes [_name] = _cls;
		return _cls;
	}

	bool EnumClasses (std::string _module_name, std::function<bool (std::shared_ptr<IAstClass>)> _cb) {
		for (auto &[_key, _val] : m_classes) {
			if (_val->m_module_name != _module_name)
				continue;
			if (!_cb (_val))
				return false;
		}
		return true;
	}

private:
	std::map<std::string, std::shared_ptr<IAstClass>> m_classes;
};



#endif //__AST_CLASS_HPP__

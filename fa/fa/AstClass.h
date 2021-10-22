#ifndef __AST_CLASS_H__
#define __AST_CLASS_H__



#include <functional>
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <tuple>
#include <vector>

//#include "AstValue.h"

#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Type.h>

#include <FaParser.h>



enum class PublicLevel { Unknown, Public, Internal, Protected, Private };

enum class AstClassType { Class, Struct, Interface, Enum };
enum class AstClassItemType { Var, GetterSetter, Func, Constructor, EnumItem };

class AstValue;
class FuncTypes;



// 抽象类成员类型
class IAstClassItem {
public:
	virtual AstClassItemType GetType () = 0;
	virtual bool IsStatic () = 0;
	virtual std::string GetStringType () = 0;
};



// 类变量的 getter setter 函数
class AstClassVarFunc {
public:
	PublicLevel						m_pv;					// 公开级别
	std::string						m_name;					// getter setter 名称
	FaParser::ClassFuncBodyContext*	m_func;					// 函数体

	AstClassVarFunc (PublicLevel _pv, std::string _name, FaParser::ClassFuncBodyContext* _func);
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

	AstClassItemType GetType () override;
	std::optional<AstValue> GetAstValue ();
	bool IsStatic () override;
	std::string GetStringType () override;

	AstClassVar (antlr4::Token* _t, PublicLevel _pv, bool _is_static, std::string _type, std::string _name);

	void SetInitValue (FaParser::ExprContext* _init_value);

	std::tuple<bool, std::string> AddVarFunc (PublicLevel _pv, std::string _name, FaParser::ClassFuncBodyContext* _func);
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

	AstClassItemType GetType () override;
	std::optional<AstValue> GetAstValue (std::shared_ptr<FuncTypes> _global_funcs);
	bool IsStatic () override;
	std::string GetStringType () override;

	AstClassFunc (PublicLevel _pv, bool _is_static, std::string _name);

	void SetReturnType (FaParser::TypeContext* _ret_type_raw);

	void SetArgumentTypeName (FaParser::TypeContext* _arg_type_raw, std::string _name);
	void SetArgumentTypeName (std::string _arg_type, antlr4::Token* _arg_type_t, std::string _name);

	void SetFuncBody (FaParser::ClassFuncBodyContext* _func);
};



// 枚举类型成员
class AstClassEnumItem: public IAstClassItem {
public:
	AstClassItemType GetType () override;
	std::optional<AstValue> GetAstValue ();
	bool IsStatic () override;
	std::string GetStringType () override;
	// TODO
};



// 抽象结构体类型
class IAstClass {
public:
	PublicLevel									m_level;
	std::string									m_module_name;
	std::string									m_name;
	std::vector<std::shared_ptr<AstClassFunc>>	m_funcs;

	IAstClass (PublicLevel _level, std::string _module_name, std::string _name);

	virtual AstClassType GetType () = 0;
	virtual std::optional<llvm::Type*> GetLlvmType (std::function<std::optional<llvm::Type*> (std::string, antlr4::Token*)> _cb) = 0;
	virtual std::optional<size_t> GetVarIndex (std::string _name);
	virtual std::optional<AstClassVar*> GetVar (size_t _idx) = 0;
	virtual std::optional<IAstClassItem*> GetMember (std::string _name);
	virtual bool GetVars (std::function<bool (AstClassVar*)> _cb) = 0;

	std::shared_ptr<AstClassFunc> AddFunc (PublicLevel _pv, bool _is_static, std::string _name);
};



// 类
class AstClass: public IAstClass {
public:
	std::vector<std::string>					m_parents;
	std::vector<std::shared_ptr<AstClassVar>>	m_vars;
	llvm::StructType*							m_type = nullptr;

	AstClass (PublicLevel _level, std::string _module_name, std::string _name);

	AstClassType GetType () override;

	std::optional<llvm::Type*> GetLlvmType (std::function<std::optional<llvm::Type*> (std::string, antlr4::Token*)> _cb) override;

	std::optional<IAstClassItem*> GetMember (std::string _name) override;

	bool GetVars (std::function<bool (AstClassVar*)> _cb) override;



	void AddParents (std::vector<std::string> &_parents);

	void AddVar (std::shared_ptr<AstClassVar> _var);

	std::optional<size_t> GetVarIndex (std::string _name) override;

	std::optional<AstClassVar*> GetVar (size_t _idx) override;
};



// 类集合
class AstClasses {
public:
	std::optional<std::shared_ptr<IAstClass>> GetClass (std::string _name, std::string _namesapce);

	std::shared_ptr<AstClass> CreateNewClass (PublicLevel _level, std::string _module_name, std::string _name);

	bool EnumClasses (std::string _module_name, std::function<bool (std::shared_ptr<IAstClass>)> _cb);

private:
	std::map<std::string, std::shared_ptr<IAstClass>> m_classes;
};



#endif //__AST_CLASS_H__

#include "AstValue.h"
#include "AstClass.h"
#include "FuncType.h"

#include <format>
#include <set>



AstClassVarFunc::AstClassVarFunc (PublicLevel _pv, std::string _name, FaParser::ClassFuncBodyContext* _func)
	: m_pv (_pv), m_name (_name), m_func (_func) {}



// 类成员变量
AstClassItemType AstClassVar::GetType () { return m_var_funcs.size () > 0 ? AstClassItemType::GetterSetter : AstClassItemType::Var; }
std::optional<AstValue> AstClassVar::GetAstValue () {
	LOG_TODO (nullptr);
	if (!m_is_static)
		return std::nullopt;
	// TODO 此处扔全局静态变量
	return std::nullopt;
}

bool AstClassVar::IsStatic () { return m_is_static; }

std::string AstClassVar::GetStringType () { return m_type; }

AstClassVar::AstClassVar (antlr4::Token* _t, PublicLevel _pv, bool _is_static, std::string _type, std::string _name)
	: m_t (_t), m_pv (_pv), m_is_static (_is_static), m_type (_type), m_name (_name) {}

void AstClassVar::SetInitValue (FaParser::ExprContext* _init_value) { m_init_value = _init_value; }

std::tuple<bool, std::string> AstClassVar::AddVarFunc (PublicLevel _pv, std::string _name, FaParser::ClassFuncBodyContext* _func) {
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



// 类成员方法
AstClassItemType AstClassFunc::GetType () { return AstClassItemType::Func; }

std::optional<AstValue> AstClassFunc::GetAstValue (std::shared_ptr<FuncTypes> _global_funcs) {
	auto _of = _global_funcs->GetFunc (m_name_abi);
	if (!_of.has_value ()) {
		LOG_ERROR (nullptr, "方法对应符号不存在");
		return std::nullopt;
	}
	auto _fp = _global_funcs->GetFuncPtr (m_name_abi);
	return AstValue { _of.value (), _fp };
}

bool AstClassFunc::IsStatic () { return m_is_static; }

std::string AstClassFunc::GetStringType () { return m_name_abi; }

AstClassFunc::AstClassFunc (PublicLevel _pv, bool _is_static, std::string _name)
	: m_pv (_pv), m_is_static (_is_static), m_name (_name) {}

void AstClassFunc::SetReturnType (FaParser::TypeContext* _ret_type_raw) {
	m_ret_type = _ret_type_raw->getText ();
	m_ret_type_t = _ret_type_raw->start;
}

void AstClassFunc::SetArgumentTypeName (FaParser::TypeContext* _arg_type_raw, std::string _name) {
	SetArgumentTypeName (_arg_type_raw->getText (), _arg_type_raw->start, _name);
}

void AstClassFunc::SetArgumentTypeName (std::string _arg_type, antlr4::Token* _arg_type_t, std::string _name) {
	m_arg_types.push_back (_arg_type);
	m_arg_type_ts.push_back (_arg_type_t);
	m_arg_names.push_back (_name);
}

void AstClassFunc::SetFuncBody (FaParser::ClassFuncBodyContext* _func) { m_func = _func; }



// 枚举类型成员
AstClassItemType AstClassEnumItem::GetType () { return AstClassItemType::EnumItem; }

std::optional<AstValue> AstClassEnumItem::GetAstValue () {
	// TODO 返回常量值
	return std::nullopt;
}

bool AstClassEnumItem::IsStatic () { return true; }

std::string AstClassEnumItem::GetStringType () { return "TODO???????????"; }



// 抽象结构体类型
IAstClass::IAstClass (PublicLevel _level, std::string _module_name, std::string _name):
	m_level (_level), m_module_name (_module_name), m_name (_name) {}

std::optional<IAstClassItem*> IAstClass::GetMember (std::string _name) {
	for (auto _func : m_funcs) {
		if (_func->m_name == _name)
			return (IAstClassItem*) _func.get ();
	}
	return std::nullopt;
}

std::shared_ptr<AstClassFunc> IAstClass::AddFunc (PublicLevel _pv, bool _is_static, std::string _name) {
	auto _func = std::make_shared<AstClassFunc> (_pv, _is_static, _name);
	m_funcs.push_back (_func);
	return _func;
}



// 类
AstClass::AstClass (PublicLevel _level, std::string _module_name, std::string _name): IAstClass (_level, _module_name, _name) {}

AstClassType AstClass::GetType () { return AstClassType::Class; }

std::optional<llvm::Type*> AstClass::GetLlvmType (std::function<std::optional<llvm::Type*> (std::string, antlr4::Token*)> _cb) {
	if (!m_type) {
		std::vector<llvm::Type*> _v;
		for (auto _var : m_vars1) {
			if (_var->m_type.substr (_var->m_type.size () - 2) == "[]") {
				_v.push_back (_cb ("int32", nullptr).value ());
				_v.push_back (_cb ("int32", nullptr).value ());
				_v.push_back (_cb ("cptr", nullptr).value ());
			} else {
				auto _otype = _cb (_var->m_type, _var->m_t);
				if (!_otype.has_value ())
					return std::nullopt;
				_v.push_back (_otype.value ());
			}
		}
		if (m_vars1.size () == 0) {
			auto _otype = _cb ("int8", nullptr);
			if (!_otype.has_value ())
				return std::nullopt;
			_v.push_back (_otype.value ());
		}
		m_type = llvm::StructType::create (_v);
	}
	return (llvm::Type*) m_type;
}

std::optional<IAstClassItem*> AstClass::GetMember (std::string _name) {
	for (auto _var : m_vars1) {
		if (_var->m_name == _name)
			return (IAstClassItem*) _var.get ();
	}
	return IAstClass::GetMember (_name);
}

size_t AstClass::GetVars (std::function<CallbackFunc (AstClassVar*)> _cb) {
	for (size_t i = 0; i < m_vars1.size (); ++i) {
		if (_cb (m_vars1 [i].get ()) == CallbackFunc::Break)
			return i;
	}
	return m_vars1.size ();
}

AstClassVar* AstClass::GetVarFromPos (size_t _pos) {
	for (size_t i = 0; i < m_vars1.size (); ++i) {
		if (m_vars1 [i]->m_ast_pos == _pos)
			return m_vars1 [i].get ();
	}
	LOG_TODO (nullptr);
	return nullptr;
}



void AstClass::AddParents (std::vector<std::string> &_parents) {
	m_parents.assign (_parents.cbegin (), _parents.cend ());
}

void AstClass::AddVar (std::shared_ptr<AstClassVar> _var) {
	if (!_var->IsStatic ()) {
		_var->m_ast_pos = m_ast_pos_cache++;							// AST树变量占位
		_var->m_llvm_pos = m_llvm_pos_cache++;							// LLVM结构体变量占位
		if (_var->m_type.substr (_var->m_type.size () - 2) == "[]")
			m_llvm_pos_cache += 2;										// 数组类型打散后多了Size与Capacity变量
	}
	m_vars1.push_back (_var);
}



// 类集合
std::optional<std::shared_ptr<IAstClass>> AstClasses::GetClass (std::string _name, std::string _namesapce, std::vector<std::string>& _uses) {
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
	// TODO 检查use的命名空间
	for (std::string _use : _uses) {
		_tmp = std::format ("{}.{}", _use, _name);
		if (m_classes.contains (_tmp))
			return m_classes [_tmp];
	}
	return std::nullopt;
}

std::shared_ptr<AstClass> AstClasses::CreateNewClass (PublicLevel _level, std::string _module_name, std::string _name) {
	auto _cls = std::make_shared<AstClass> (_level, _module_name, _name);
	m_classes [_name] = _cls;
	return _cls;
}

bool AstClasses::EnumClasses (std::string _module_name, std::function<bool (std::shared_ptr<IAstClass>)> _cb) {
	for (auto &[_key, _val] : m_classes) {
		if (_val->m_module_name != _module_name)
			continue;
		if (!_cb (_val))
			return false;
	}
	return true;
}

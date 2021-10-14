#include "AstValue.hpp"
#include "AstClass.hpp"



AstClassVarFunc::AstClassVarFunc (PublicLevel _pv, std::string _name, FaParser::ClassFuncBodyContext* _func)
	: m_pv (_pv), m_name (_name), m_func (_func) {}



// 类成员变量
AstClassItemType AstClassVar::GetType () { return m_var_funcs.size () > 0 ? AstClassItemType::GetterSetter : AstClassItemType::Var; }
std::optional<AstValue> AstClassVar::GetAstValue () {
	// TODO 移动实现到cpp里
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

std::optional<AstValue> AstClassFunc::GetAstValue () {
	// TODO 实现
	return std::nullopt;
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

std::optional<size_t> IAstClass::GetVarIndex (std::string _name) { return std::nullopt; }

std::optional<std::shared_ptr<IAstClassItem>> IAstClass::GetMember (std::string _name) {
	for (auto _func : m_funcs) {
		if (_func->m_name == _name)
			return std::shared_ptr<IAstClassItem> ((IAstClassItem*) _func.get ());
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

std::optional<std::shared_ptr<IAstClassItem>> AstClass::GetMember (std::string _name) {
	for (auto _var : m_vars) {
		if (_var->m_name == _name)
			return std::shared_ptr<IAstClassItem> ((IAstClassItem*) _var.get ());
	}
	return IAstClass::GetMember (_name);
}



void AstClass::AddParents (std::vector<std::string> &_parents) {
	m_parents.assign (_parents.cbegin (), _parents.cend ());
}

void AstClass::AddVar (std::shared_ptr<AstClassVar> _var) {
	m_vars.push_back (_var);
}

std::optional<size_t> AstClass::GetVarIndex (std::string _name) {
	for (size_t i = 0; i < m_vars.size (); ++i) {
		if (m_vars [i]->m_name == _name)
			return i;
	}
	return std::nullopt;
}



// 类集合
std::optional<std::shared_ptr<IAstClass>> AstClasses::GetClass (std::string _name, std::string _namesapce) {
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

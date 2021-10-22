#include "AstValue.h"



AstValue AstValue::FromVoid () { AstValue _v {}; _v.m_type = AstObjectType::Void; return _v; }

std::optional<AstValue> AstValue::FromValue (std::shared_ptr<ValueBuilder> _value_builder, std::string _value, std::string _type, antlr4::Token* _t) {
	std::optional<std::tuple<llvm::Value*, std::string>> _oval = _value_builder->Build (_type, _value, _t);
	if (!_oval.has_value ())
		return std::nullopt;
	auto [_val, _value_type] = _oval.value ();
	return AstValue { _val, _value_type };
}

AstValue::AstValue () {}

//AstValue::AstValue (std::nullopt_t) {}

AstValue::AstValue (std::shared_ptr<ValueBuilder> _value_builder, FaParser::LiteralContext* _literal) {
	m_value_type = "";
	if (_literal->BoolLiteral ()) {
		m_value_type = "bool";
	} else if (_literal->intNum ()) {
		m_value_type = "int";
	} else if (_literal->floatNum ()) {
		m_value_type = "float64";
	} else if (_literal->String1Literal ()) {
		m_value_type = "cptr";
	} else {
		LOG_ERROR (_literal->start, "未知数据类型");
		return;
	}
	std::optional<std::tuple<llvm::Value*, std::string>> _oval = _value_builder->Build (m_value_type, _literal->getText (), _literal->start);
	if (_oval.has_value ()) {
		m_type = AstObjectType::Value;
		std::tie (m_value, m_value_type) = _oval.value ();
	}
}

AstValue::AstValue (llvm::AllocaInst* _var, std::string _value_type): m_type (_var ? AstObjectType::Var : AstObjectType::Void), m_value (_var), m_value_type (_value_type) {}

AstValue::AstValue (llvm::AllocaInst* _arr, llvm::AllocaInst* _arr_size, llvm::AllocaInst* _arr_capacity, std::string _value_type) :
	m_type (AstObjectType::ArrVar), m_value (_arr), m_value_size (_arr_size), m_value_capacity (_arr_capacity), m_value_type (_value_type) {}

AstValue::AstValue (llvm::Value* _value, std::string _value_type) : m_type (_value ? AstObjectType::Value : AstObjectType::Void), m_value (_value), m_value_type (_value_type) {}

AstValue::AstValue (std::shared_ptr<FuncType> _func, llvm::Function* _fp) : m_type (AstObjectType::Func), m_func (_func), m_fp (_fp), m_value_type (_func->m_name) {}

AstValue::AstValue (std::string _member) : m_member (_member), m_type (AstObjectType::MemberStr) {}

//AstValue &AstValue::operator= (const llvm::AllocaInst* _val) { AstValue _o { const_cast<llvm::AllocaInst*> (_val) }; return operator= (_o); }
//AstValue &AstValue::operator= (const llvm::Value* _val) { AstValue _o { const_cast<llvm::Value*> (_val) }; return operator= (_o); }
//AstValue &AstValue::operator= (const llvm::Function* _val) { AstValue _o { const_cast<llvm::Function*> (_val) }; return operator= (_o); }

AstValue& AstValue::operator= (const AstValue& _o) {
	m_type = _o.m_type;
	m_value = _o.m_value;
	m_value_size = _o.m_value_size;
	m_value_capacity = _o.m_value_capacity;
	m_func = _o.m_func;
	m_member = _o.m_member;
	m_value_type = _o.m_value_type;
	return*this;
}

//bool AstValue::IsValid () const { return m_type != AstObjectType::None; }

bool AstValue::IsVoid () const { return m_type == AstObjectType::Void; }

bool AstValue::IsValue () const { return m_type == AstObjectType::Value || m_type == AstObjectType::Var; }

bool AstValue::IsVariable () const { return m_type == AstObjectType::Var; }

bool AstValue::IsFunction () const { return m_type == AstObjectType::Func; }

bool AstValue::IsTypeStr () const { return m_type == AstObjectType::Value || m_type == AstObjectType::Var || m_type == AstObjectType::TypeStr; }

bool AstValue::IsMember () const { return m_type == AstObjectType::MemberStr; }

llvm::Value* AstValue::Value (llvm::IRBuilder<>& _builder) {
	if (m_type == AstObjectType::Value) {
		return m_value;
	} else if (m_type == AstObjectType::Var) {
		return _builder.CreateLoad (m_value);
	} else {
		return nullptr;
	}
}

llvm::Value* AstValue::ValueRaw () { return m_value; }

llvm::CallInst* AstValue::FuncInvoke (llvm::IRBuilder<>& _builder, std::vector<llvm::Value*>& _args) {
	if (m_type != AstObjectType::Func || m_func == nullptr)
		return nullptr;
	return _builder.CreateCall (m_fp, _args);
}

std::optional<AstValue> AstValue::DoOper1 (llvm::IRBuilder<>& _builder, std::shared_ptr<ValueBuilder> _value_builder, std::string _op, antlr4::Token* _t) {
	if (!IsValue ())
		return std::nullopt;
	llvm::Value* _tmp = Value (_builder);
	if (_op == "+") {
		return*this;
	} else {
		std::string _typestr = TypeMap::GetTypeName (m_value->getType ());
		if (_op == "-") {
			auto _tmp2 = _value_builder->Build (m_value_type, "0", _t);
			if (!_tmp2.has_value ())
				return std::nullopt;
			auto [_tmp_val, _] = _tmp2.value ();
			return AstValue { _builder.CreateSub (_tmp_val, _tmp), m_value_type };
		} else if (_op == "++" || _op == "--") {
			auto _tmp2 = _value_builder->Build (m_value_type, "1", _t);
			if (!_tmp2.has_value ())
				return std::nullopt;
			auto [_tmp_val, _] = _tmp2.value ();
			AstValue _v;
			if (_op == "++") {
				_v = AstValue { _builder.CreateAdd (Value (_builder), _tmp_val), m_value_type };
			} else {
				_v = AstValue { _builder.CreateSub (Value (_builder), _tmp_val), m_value_type };
			}
			if (!m_value)
				return std::nullopt;
			_builder.CreateStore (_v.Value (_builder), m_value);
			return*this;
		} else if (_op == "~") {
			if (m_value_type != "bool") {
				LOG_ERROR (_t, "非bool类型数据无法取反");
				return std::nullopt;
			}
			auto _tmp2 = _value_builder->Build (m_value_type, "true", _t);
			if (!_tmp2.has_value ())
				return std::nullopt;
			auto [_tmp_val, _] = _tmp2.value ();
			return AstValue { _builder.CreateSub (_tmp_val, _tmp), m_value_type };
		}
	}

	LOG_ERROR (_t, std::format ("暂不支持的运算符 {}", _op));
	return std::nullopt;
}

std::optional<AstValue> AstValue::DoOper2 (llvm::IRBuilder<>& _builder, std::shared_ptr<ValueBuilder> _value_builder, std::string _op, AstValue& _other, antlr4::Token* _t, std::shared_ptr<FuncTypes> _global_funcs, AstClasses& _global_classes, std::string _namespace) {
	std::optional<AstValue> _tmp;
	if (_op.size () == 1) {
		switch (_op [0]) {
		case '+': return AstValue { _builder.CreateAdd (Value (_builder), _other.Value (_builder)), m_value_type };
		case '-': return AstValue { _builder.CreateSub (Value (_builder), _other.Value (_builder)), m_value_type };
		case '*': return AstValue { _builder.CreateMul (Value (_builder), _other.Value (_builder)), m_value_type };
		case '/': return AstValue { _builder.CreateSDiv (Value (_builder), _other.Value (_builder)), m_value_type };
		case '%': return AstValue { _builder.CreateSRem (Value (_builder), _other.Value (_builder)), m_value_type };
		case '|': return AstValue { _builder.CreateOr (Value (_builder), _other.Value (_builder)), m_value_type };
		case '&': return AstValue { _builder.CreateAnd (Value (_builder), _other.Value (_builder)), m_value_type };
		case '^': return AstValue { _builder.CreateXor (Value (_builder), _other.Value (_builder)), m_value_type };
		case '<': return AstValue { _builder.CreateICmpSLT (Value (_builder), _other.Value (_builder)), "bool" };
		case '>': return AstValue { _builder.CreateICmpSGT (Value (_builder), _other.Value (_builder)), "bool" };
		case '=':
			_builder.CreateStore (_other.Value (_builder), m_value);
			return *this;
		case '.':
			// 如果是临时类型那么拼凑命名空间
			if (m_type == AstObjectType::MemberStr) {
				auto _ocls = _global_classes.GetClass (m_member, _namespace);
				// 未找到类，那么继续拼接
				if (!_ocls.has_value ()) {
					if (_other.m_type != AstObjectType::MemberStr) {
						LOG_ERROR (_t, "未知操作");
						return std::nullopt;
					}
					return AstValue { std::format ("{}.{}", m_member, _other.m_member) };
				}

				// 找到了类但非访问类型
				if (_other.m_type != AstObjectType::MemberStr) {
					LOG_ERROR (_t, std::format ("无法对类 {} 进行其他操作", m_member));
					return std::nullopt;
				}

				auto _oitem = _ocls.value ()->GetMember (_other.m_member);
				// 如果成员不存在
				if (!_oitem.has_value ()) {
					LOG_ERROR (_t, std::format ("类 {} 不包括成员 {}", m_member, _other.m_member));
					return std::nullopt;
				}

				auto _item = _oitem.value ();
				// 如果成员非静态
				if (!_item->IsStatic ()) {
					LOG_ERROR (_t, std::format ("类成员 {}.{} 不允许静态方式访问", m_member, _other.m_member));
					return std::nullopt;
				}

				if (_item->GetType () == AstClassItemType::Var) {
					// TODO: 访问全局变量
					LOG_TODO (_t);
					return std::nullopt;
				} else if (_item->GetType () == AstClassItemType::Func) {
					auto _func = dynamic_cast<AstClassFunc*> (_item);
					auto _of = _global_funcs->GetFunc (_func->m_name_abi);
					if (_of.has_value ()) {
						auto _fp = _global_funcs->GetFuncPtr (_func->m_name_abi);
						return AstValue { _of.value (), _fp };
					}
				}
			}

			//如果是成员方法那么返回方法地址
			{
				std::string _func_name = std::format ("{}.{}", m_value_type, _other.m_member);
				auto _ofunc = _global_funcs->GetFunc (_func_name);
				if (_ofunc.has_value ()) {
					auto _fp = _global_funcs->GetFuncPtr (_func_name);
					return AstValue { _ofunc.value (), _fp };
				}
			}

			// TODO 待确认是否加入：如果是成员变量那么给出偏移计算
			LOG_TODO (_t);
			return std::nullopt;
		}
	} else if (_op.size () == 2) {
		if (_op [0] == _op [1]) {
			switch (_op [0]) {
			case '?':
				{
					std::string _tmp_value_type = "";
					if (m_value_type [m_value_type.size () - 1] == '?') {
						_tmp_value_type = m_value_type.substr (0, m_value_type.size () - 1);
					} else if (m_value_type [m_value_type.size () - 2] == '?') {
						_tmp_value_type = m_value_type.substr (0, m_value_type.size () - 1);
						_tmp_value_type [_tmp_value_type.size () - 1] = m_value_type [m_value_type.size () - 1];
					} else {
						LOG_ERROR (_t, "目标类型不可为空，无法使用 ?? 运算符");
						return std::nullopt;
					}
					return AstValue { _builder.CreateAdd (Value (_builder), _other.Value (_builder)), _tmp_value_type };
				}
			case '*': return AstValue { _builder.CreateAdd (Value (_builder), _other.Value (_builder)), m_value_type };
			case '&': return AstValue { _builder.CreateAnd (Value (_builder), _other.Value (_builder)), m_value_type };
			case '|': return AstValue { _builder.CreateOr (Value (_builder), _other.Value (_builder)), m_value_type };
			case '<': return AstValue { _builder.CreateShl (Value (_builder), _other.Value (_builder)), m_value_type };
			case '>':
				_tmp = _other.DoOper1 (_builder, _value_builder, "-", _t);
				if (!_tmp.has_value ())
					return std::nullopt;
				return AstValue { _builder.CreateShl (Value (_builder), _tmp.value ().Value (_builder)), m_value_type };
			case '=':
				return AstValue { _builder.CreateICmpEQ (Value (_builder), _other.Value (_builder)), "bool" };
			}
		} else if (_op [1] == '=') {
			switch (_op [0]) {
			case '<': return AstValue { _builder.CreateICmpSLE (Value (_builder), _other.Value (_builder)), "bool" };
			case '>': return AstValue { _builder.CreateICmpSGE (Value (_builder), _other.Value (_builder)), "bool" };
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '|':
			case '&':
			case '^':
				_tmp = DoOper2 (_builder, _value_builder, _op.substr (0, 1), _other, _t, _global_funcs, _global_classes, _namespace);
				if (!_tmp.has_value ())
					return std::nullopt;
				return DoOper2 (_builder, _value_builder, "=", _tmp.value (), _t, _global_funcs, _global_classes, _namespace);
			case '!': return AstValue { _builder.CreateICmpNE (Value (_builder), _other.Value (_builder)), "bool" };
			}
		}
	} else if (_op.size () == 3) {
		if (_op == "<<=" || _op == ">>=") {
			_tmp = DoOper2 (_builder, _value_builder, _op.substr (0, 2), _other, _t, _global_funcs, _global_classes, _namespace);
			if (!_tmp.has_value ())
				return std::nullopt;
			return DoOper2 (_builder, _value_builder, "=", _tmp.value (), _t, _global_funcs, _global_classes, _namespace);
		}
	}

	LOG_ERROR (_t, std::format ("暂不支持的运算符 {}", _op));
	return std::nullopt;
}

std::string AstValue::GetType () { return m_value_type; }

void AstValue::SetType (std::string _value_type) { m_value_type = _value_type; }

bool AstValue::GetTmpVarFlag () { return m_tmp_var_flag; }

void AstValue::SetTmpVarFlag (bool _tmp_var_flag) { m_tmp_var_flag = _tmp_var_flag; }

AstValue AstValue::GetArrSize () { return AstValue { m_value_size, "int32" }; }

AstValue AstValue::GetArrCapacity () { return AstValue { m_value_capacity, "int32" }; }

std::string AstValue::GetFuncReturnType () { return m_func->m_ret_type; }

std::tuple<std::string, std::vector<std::string>> AstValue::GetFuncType () { return { m_func->m_ret_type, m_func->m_arg_types }; }

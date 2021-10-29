#include "ValueBuilder.h"
#include "AstValue.h"



ValueBuilder::ValueBuilder (std::shared_ptr<TypeMap> _type_map, std::shared_ptr<llvm::LLVMContext> _ctx, std::shared_ptr<llvm::Module> _module)
	: m_type_map (_type_map), m_ctx (_ctx), m_module (_module) {
	m_builder = std::make_shared<llvm::IRBuilder<>> (*m_ctx);
}

std::optional<AstValue> ValueBuilder::Build (std::string _type, std::string _value, antlr4::Token* _t) {
	if (_type != "" && _type [0] == '$')
		_type = _type.substr (1);
	if (_type == "bool") {
		if (_value == "true") {
			return AstValue { llvm::ConstantInt::getTrue (*m_ctx), "bool" };
		} else if (_value == "false") {
			return AstValue { llvm::ConstantInt::getFalse (*m_ctx), "bool" };
		}
	} else if (_type == "uint8[]") {
		_value = _value.substr (1, _value.size () - 2);
		std::optional<std::string> _otmp_value = StringProcessor::TransformMean (_value, _t);
		if (_otmp_value.has_value ()) {
			std::string _tmp_value = _otmp_value.value ();
			llvm::Constant* _arr = m_builder->CreateGlobalStringPtr (_tmp_value, "", 0, m_module.get ());
			auto _oint32_type = m_type_map->GetType ("int32");
			llvm::Type* _int32_type = _oint32_type.value ();
			llvm::GlobalVariable* _asize = new llvm::GlobalVariable (_int32_type, true, llvm::GlobalValue::PrivateLinkage, nullptr);
			AstValue _asize_value = Build ("int32", std::format ("{}", _tmp_value.size ()), nullptr).value ();
			_asize->setInitializer ((llvm::Constant*) _asize_value.ValueRaw ());
			return AstValue { (llvm::AllocaInst*) _arr, (llvm::AllocaInst*) _asize, (llvm::AllocaInst*) _asize, "uint8[]" };
		}
	} else if (_type.find ("int") != std::string::npos) {
		if (_type == "int") {
			int64_t _i = std::stoll (_value);
			if (_i <= 2147483647L && _i >= -2147483648L) {
				_type = "int32";
			} else {
				_type = "int64";
			}
		}
		std::optional<llvm::Type*> _tp = m_type_map->GetType (_type, _t);
		if (!_tp.has_value ())
			return std::nullopt;
		std::optional<llvm::APInt> _int;
		if (_type [0] == 'u') {
			uint64_t _i = std::stoull (_value);
			if (_type == "uint8") {
				_int = llvm::APInt (8, _i, false);
			} else if (_type == "uint16") {
				_int = llvm::APInt (16, _i, false);
			} else if (_type == "uint32") {
				_int = llvm::APInt (32, _i, false);
			} else if (_type == "uint64") {
				_int = llvm::APInt (64, _i, false);
			}
		} else {
			int64_t _i = std::stoll (_value);
			if (_type == "int8") {
				_int = llvm::APInt (8, (uint64_t) _i, true);
			} else if (_type == "int16") {
				_int = llvm::APInt (16, (uint64_t) _i, true);
			} else if (_type == "int32") {
				_int = llvm::APInt (32, (uint64_t) _i, true);
			} else if (_type == "int64") {
				_int = llvm::APInt (64, (uint64_t) _i, true);
			}
		}
		if (_int.has_value ()) {
			llvm::Constant* _intval = llvm::ConstantInt::get (_tp.value (), _int.value ());
			return AstValue { _intval, _type };
		}
	}

	LOG_ERROR (_t, std::format ("值 \"{}\" 无法转为 \"{}\" 类型。", _value, _type));
	return std::nullopt;
}

#ifndef _TYPE_MAP_HPP__
#define _TYPE_MAP_HPP__



#include <optional>
#include <string>

#include <llvm/IR/Type.h>

#include <fmt/core.h>

#include "FaVisitor.h"
#include "FaParser.h"
#include "InfoOut.hpp"



//template<int bitsize>
class TypeMap {
public:
	TypeMap (FaVisitor *_visitor, std::shared_ptr<llvm::LLVMContext> _ctx): m_visitor (_visitor), m_ctx (_ctx) {}

	std::optional<llvm::Type *> GetType (FaParser::TypeContext *_type_ctx) {
		auto _name = _type_ctx->getText ();
		return GetType (_name);
	}

	std::optional<llvm::Type *> GetType (std::string _name) {
		if (_name == "void") {
			return llvm::Type::getVoidTy (*m_ctx);
		} else if (_name == "int8" || _name == "bool") {
			return (llvm::Type *) llvm::Type::getInt8Ty (*m_ctx);
		} else if (_name == "int16") {
			return (llvm::Type *) llvm::Type::getInt16Ty (*m_ctx);
		} else if (_name == "int32") {
			return (llvm::Type *) llvm::Type::getInt32Ty (*m_ctx);
		} else if (_name == "int64") {
			return (llvm::Type *) llvm::Type::getInt64Ty (*m_ctx);
		} else if (_name == "float16") {
			return llvm::Type::getBFloatTy (*m_ctx);
		} else if (_name == "float32") {
			return llvm::Type::getFloatTy (*m_ctx);
		} else if (_name == "float64") {
			return llvm::Type::getDoubleTy (*m_ctx);
		}
		LOG_ERROR (fmt::format ("无法识别的类型 [{}]", _name));
		return std::nullopt;
	}

	std::optional<std::vector<llvm::Type *>> GetTypes (std::vector<FaParser::TypeContext *> _types_raw) {
		std::vector<llvm::Type *> _types;
		for (FaParser::TypeContext *_type_raw : _types_raw) {
			std::optional<llvm::Type *> _type = GetType (_type_raw);
			if (!_type.has_value ())
				return std::nullopt;
			_types.push_back (_type.value ());
		}
		return _types;
	}

	std::optional<llvm::Type *> GetExternType (FaParser::ETypeContext *_etype_ctx) {
		auto [_sign, _name, _ptr_level] = m_visitor->visitEType (_etype_ctx).as<std::tuple<bool, std::string, size_t>> ();
		// _sign 好像暂时用不到
		if (_name == "void") {
			if (_ptr_level == 0) {
				return (llvm::Type *) llvm::Type::getVoidTy (*m_ctx);
			} else {
				return (llvm::Type *) llvm::Type::getInt8PtrTy (*m_ctx);
			}
		} else if (_name == "char") {
			if (_ptr_level == 0) {
				return (llvm::Type *) llvm::Type::getInt8Ty (*m_ctx);
			} else {
				return (llvm::Type *) llvm::Type::getInt8PtrTy (*m_ctx);
			}
		} else if (_name == "short") {
			if (_ptr_level == 0) {
				return (llvm::Type *) llvm::Type::getInt16Ty (*m_ctx);
			} else {
				return (llvm::Type *) llvm::Type::getInt16PtrTy (*m_ctx);
			}
		} else if (_name == "int") {
			if (_ptr_level == 0) {
				return (llvm::Type *) llvm::Type::getInt32Ty (*m_ctx);
			} else {
				return (llvm::Type *) llvm::Type::getInt32PtrTy (*m_ctx);
			}
		} else if (_name == "long") {
			if (_ptr_level == 0) {
				return (llvm::Type *) llvm::Type::getInt64Ty (*m_ctx);
			} else {
				return (llvm::Type *) llvm::Type::getInt64PtrTy (*m_ctx);
			}
		} else if (_name == "float") {
			if (_ptr_level == 0) {
				return (llvm::Type *) llvm::Type::getFloatTy (*m_ctx);
			} else {
				return (llvm::Type *) llvm::Type::getFloatPtrTy (*m_ctx);
			}
		} else if (_name == "double") {
			if (_ptr_level == 0) {
				return (llvm::Type *) llvm::Type::getDoubleTy (*m_ctx);
			} else {
				return (llvm::Type *) llvm::Type::getDoublePtrTy (*m_ctx);
			}
		}
		LOG_ERROR (fmt::format ("无法识别的外部接口函数类型 [{}]", _name));
		return std::nullopt;
	}

	std::optional<std::vector<llvm::Type *>> GetExternTypes (std::vector<FaParser::ETypeContext *> _types_raw) {
		std::vector<llvm::Type *> _types;
		for (FaParser::ETypeContext *_type_raw : _types_raw) {
			std::optional<llvm::Type *> _type = GetExternType (_type_raw);
			if (!_type.has_value ())
				return std::nullopt;
			_types.push_back (_type.value ());
		}
		return _types;
	}

private:
	FaVisitor *m_visitor = nullptr;
	std::shared_ptr<llvm::LLVMContext> m_ctx = nullptr;
};



#endif //_TYPE_MAP_HPP__

#ifndef _TYPE_MAP_HPP__
#define _TYPE_MAP_HPP__



#include <optional>
#include <string>
#include <tuple>

#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>

#include <fmt/core.h>

#include "FaVisitor.h"
#include "FaParser.h"
#include "Log.hpp"



//template<int bitsize>
class TypeMap {
public:
	TypeMap (FaVisitor *_visitor, std::shared_ptr<llvm::LLVMContext> _ctx): m_visitor (_visitor), m_ctx (_ctx) {}

	std::optional<llvm::Type *> GetType (FaParser::TypeContext *_type_ctx) {
		auto _name = _type_ctx->getText ();
		return GetType (_name, _type_ctx->start);
	}

	std::optional<llvm::Type *> GetType (std::string _name, antlr4::Token *_t) {
		if (_name == "void") {
			return llvm::Type::getVoidTy (*m_ctx);
		} else if (_name == "bool") {
			return (llvm::Type *) llvm::Type::getInt1Ty (*m_ctx);
		} else if (_name == "int8") {
			return (llvm::Type *) llvm::Type::getInt8Ty (*m_ctx);
		} else if (_name == "int16") {
			return (llvm::Type *) llvm::Type::getInt16Ty (*m_ctx);
		} else if (_name == "int32") {
			return (llvm::Type *) llvm::Type::getInt32Ty (*m_ctx);
		} else if (_name == "int64") {
			return (llvm::Type *) llvm::Type::getInt64Ty (*m_ctx);
		} else if (_name == "int128") {
			return (llvm::Type *) llvm::Type::getInt128Ty (*m_ctx);
		} else if (_name == "float16") {
			return llvm::Type::getBFloatTy (*m_ctx);
		} else if (_name == "float32") {
			return llvm::Type::getFloatTy (*m_ctx);
		} else if (_name == "float64") {
			return llvm::Type::getDoubleTy (*m_ctx);
		} else if (_name == "float128") {
			return llvm::Type::getFP128Ty (*m_ctx);
		}
		LOG_ERROR (_t, fmt::format ("无法识别的类型 [{}]", _name));
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

	static std::string GetTypeName (llvm::Type *_type) {
		switch (_type->getTypeID ()) {
		case llvm::Type::HalfTyID:
		case llvm::Type::BFloatTyID:
			return "float16";
		case llvm::Type::FloatTyID:
			return "float32";
		case llvm::Type::DoubleTyID:
			return "float64";
		case llvm::Type::FP128TyID:
			return "float128";
		case llvm::Type::VoidTyID:
			return "void";
		case llvm::Type::IntegerTyID:
		{
			llvm::IntegerType *_itype = (llvm::IntegerType *) _type;
			unsigned int _bit_width = _itype->getBitWidth ();
			if (_bit_width == 1) {
				return "bool";
			} else if (_bit_width == 8) {
				return "int8";
			} else if (_bit_width == 16) {
				return "int16";
			} else if (_bit_width == 32) {
				return "int32";
			} else if (_bit_width == 64) {
				return "int64";
			} else if (_bit_width == 128) {
				return "int128";
			}
		}
		break;
		}
		return "";
	}



	std::optional<std::tuple<llvm::Type *, std::string>> GetExternType (FaParser::ETypeContext *_etype_ctx) {
		auto [_sign, _name, _ptr_level] = m_visitor->visitEType (_etype_ctx).as<std::tuple<bool, std::string, size_t>> ();
		// _sign 好像暂时用不到
		if (_name == "void") {
			if (_ptr_level == 0) {
				return std::make_tuple ((llvm::Type *) llvm::Type::getVoidTy (*m_ctx), std::string ("void"));
			} else {
				return std::make_tuple ((llvm::Type *) llvm::Type::getInt8PtrTy (*m_ctx), std::string ("int8*"));
			}
		} else if (_name == "char") {
			if (_ptr_level == 0) {
				return std::make_tuple ((llvm::Type *) llvm::Type::getInt8Ty (*m_ctx), std::string ("int8"));
			} else {
				return std::make_tuple ((llvm::Type *) llvm::Type::getInt8PtrTy (*m_ctx), std::string ("int8*"));
			}
		} else if (_name == "short") {
			if (_ptr_level == 0) {
				return std::make_tuple ((llvm::Type *) llvm::Type::getInt16Ty (*m_ctx), std::string ("int16"));
			} else {
				return std::make_tuple ((llvm::Type *) llvm::Type::getInt16PtrTy (*m_ctx), std::string ("int16*"));
			}
		} else if (_name == "int") {
			if (_ptr_level == 0) {
				return std::make_tuple ((llvm::Type *) llvm::Type::getInt32Ty (*m_ctx), std::string ("int32"));
			} else {
				return std::make_tuple ((llvm::Type *) llvm::Type::getInt32PtrTy (*m_ctx), std::string ("int32*"));
			}
		} else if (_name == "long") {
			if (_ptr_level == 0) {
				return std::make_tuple ((llvm::Type *) llvm::Type::getInt64Ty (*m_ctx), std::string ("int64"));
			} else {
				return std::make_tuple ((llvm::Type *) llvm::Type::getInt64PtrTy (*m_ctx), std::string ("int64*"));
			}
		} else if (_name == "float") {
			if (_ptr_level == 0) {
				return std::make_tuple ((llvm::Type *) llvm::Type::getFloatTy (*m_ctx), std::string ("float32"));
			} else {
				return std::make_tuple ((llvm::Type *) llvm::Type::getFloatPtrTy (*m_ctx), std::string ("float32*"));
			}
		} else if (_name == "double") {
			if (_ptr_level == 0) {
				return std::make_tuple ((llvm::Type *) llvm::Type::getDoubleTy (*m_ctx), std::string ("float64"));
			} else {
				return std::make_tuple ((llvm::Type *) llvm::Type::getDoublePtrTy (*m_ctx), std::string ("float64*"));
			}
		}
		LOG_ERROR (_etype_ctx->start, fmt::format ("无法识别的外部接口函数类型 [{}]", _name));
		return std::nullopt;
	}

	std::optional<std::tuple<std::vector<llvm::Type *>, std::vector<std::string>>> GetExternTypes (std::vector<FaParser::ETypeContext *> _types_raw) {
		std::vector<llvm::Type *> _types;
		std::vector<std::string> _type_strs;
		for (FaParser::ETypeContext *_type_raw : _types_raw) {
			auto _type = GetExternType (_type_raw);
			if (!_type.has_value ())
				return std::nullopt;
			auto [_type0, _type_str] = _type.value ();
			_types.push_back (_type0);
			_type_strs.push_back (_type_str);
		}
		return std::make_tuple (_types, _type_strs);
	}

private:
	FaVisitor *m_visitor = nullptr;
	std::shared_ptr<llvm::LLVMContext> m_ctx = nullptr;
};



#endif //_TYPE_MAP_HPP__

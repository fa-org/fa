#ifndef _TYPE_MAP_HPP__
#define _TYPE_MAP_HPP__



#include <format>
#include <functional>
#include <initializer_list>
#include <map>
#include <optional>
#include <string>
#include <tuple>

#include <llvm/ADT/StringRef.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/TableGen/Record.h>

#include "FaVisitor.h"
#include "FaParser.h"
#include "Log.hpp"
#include "AstClass.h"



//template<int bitsize>
class TypeMap {
public:
	TypeMap (FaVisitor* _visitor, std::shared_ptr<llvm::LLVMContext> _ctx, AstClasses& _global_classes, std::string _namespace, std::vector<std::string>& _uses): m_visitor (_visitor), m_ctx (_ctx), m_global_classes (_global_classes), m_namespace (_namespace), m_uses (_uses) {}

	static std::optional<std::tuple<std::string, std::string>> GetOp2OperatorExpectType (std::string _exp_type, std::string _op, antlr4::Token* _t) {
		if (_op.size () == 1) {
			switch (_op[0]) {
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '|':
			case '&':
			case '^':
			case '<':
			case '>':
				return std::make_tuple (_exp_type, _exp_type);
			case '=':
				return std::make_tuple (std::format ("${}", _exp_type), _exp_type);
			case '.':
				return std::make_tuple<std::string, std::string> ("", "");
			}
		} else if (_op.size () == 2) {
			if (_op [0] == _op [1]) {
				switch (_op [0]) {
				case '?':
					return std::make_tuple (std::format ("{}?", _exp_type), _exp_type);
				case '*':
					return std::make_tuple (_exp_type, "int");
				case '&':
				case '|':
					return std::make_tuple ("bool", "bool");
				case '<':
				case '>':
					return std::make_tuple (_exp_type, "int");
				}
			} else if (_op [1] == '=') {
				switch (_op [0]) {
				case '<':
				case '>':
				case '+':
				case '-':
				case '*':
				case '/':
				case '%':
				case '|':
				case '&':
				case '^':
					return std::make_tuple (std::format ("${}", _exp_type), _exp_type);
				}
			}
		} else if (_op.size () == 3) {
			if (_op == "<<=" || _op == ">>=") {
				return std::make_tuple (std::format ("${}", _exp_type), _exp_type);
			}
		}

		LOG_ERROR (_t, std::format ("未识别的运算符 {}。（期望类型：{}）", _op, _exp_type));
		return std::nullopt;
	}

	std::optional<std::tuple<llvm::Type* , std::string>> GetTypeT (FaParser::TypeContext* _type_ctx) {
		auto _stype = _type_ctx->getText ();
		auto _otype = GetType (_stype, _type_ctx->start);
		if (_otype.has_value ()) {
			return std::make_tuple (_otype.value (), _stype);
		} else {
			return std::nullopt;
		}
	}

	std::optional<llvm::Type*> GetType (FaParser::TypeContext* _type_ctx) {
		auto _stype = _type_ctx->getText ();
		return GetType (_stype, _type_ctx->start);
	}

	std::optional<llvm::Type*> GetType (std::string _stype, antlr4::Token* _t = nullptr) {
		if (_stype == "void") {
			return llvm::Type::getVoidTy (*m_ctx);
		} else if (_stype == "bool") {
			return (llvm::Type* ) llvm::Type::getInt1Ty (*m_ctx);
		} else if (_stype == "int8") {
			return (llvm::Type* ) llvm::Type::getInt8Ty (*m_ctx);
		} else if (_stype == "int16") {
			return (llvm::Type* ) llvm::Type::getInt16Ty (*m_ctx);
		} else if (_stype == "int32") {
			return (llvm::Type* ) llvm::Type::getInt32Ty (*m_ctx);
		} else if (_stype == "int64") {
			return (llvm::Type* ) llvm::Type::getInt64Ty (*m_ctx);
		} else if (_stype == "int128") {
			return (llvm::Type* ) llvm::Type::getInt128Ty (*m_ctx);
		} else if (_stype == "float16") {
			return llvm::Type::getBFloatTy (*m_ctx);
		} else if (_stype == "float32") {
			return llvm::Type::getFloatTy (*m_ctx);
		} else if (_stype == "float64") {
			return llvm::Type::getDoubleTy (*m_ctx);
		} else if (_stype == "float128") {
			return llvm::Type::getFP128Ty (*m_ctx);
		} else if (_stype == "cptr") {
			return llvm::Type::getInt8PtrTy (*m_ctx);
		} else {
			auto _ocls = m_global_classes.GetClass (_stype, m_namespace, m_uses);
			if (_ocls.has_value ())
				return _ocls.value ()->GetLlvmType ([&] (std::string _stype, antlr4::Token* _t) { return GetType (_stype, _t); });
		}
		LOG_ERROR (_t, std::format ("无法识别的类型 [{}]", _stype));
		return std::nullopt;
	}

	std::optional<std::vector<llvm::Type*>> GetTypes (std::vector<FaParser::TypeContext*> _types_raw) {
		std::vector<llvm::Type*> _types;
		for (FaParser::TypeContext* _type_raw : _types_raw) {
			std::optional<llvm::Type*> _type = GetType (_type_raw);
			if (!_type.has_value ())
				return std::nullopt;
			_types.push_back (_type.value ());
		}
		return _types;
	}

	std::optional<std::tuple<std::vector<llvm::Type*>, std::vector<std::string>>> GetTypesT (std::vector<FaParser::TypeContext*> _types_raw) {
		std::vector<llvm::Type*> _types;
		std::vector<std::string> _type_strs;
		for (FaParser::TypeContext* _type_raw : _types_raw) {
			std::string _type_str = _type_raw->getText ();
			std::optional<llvm::Type*> _type = GetType (_type_str, _type_raw->start);
			if (!_type.has_value ())
				return std::nullopt;
			_types.push_back (_type.value ());
			_type_strs.push_back (_type_str);
		}
		return std::make_tuple (_types, _type_strs);
	}

	// 获取类型名称
	static std::string GetTypeName (llvm::Type* _type) {
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
			llvm::IntegerType* _itype = (llvm::IntegerType* ) _type;
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

	// 识别类型是否为可选类型
	static bool IsOptional (std::string _stype) {
		return* _stype.crbegin () == '?';
	}

	// 获取同时兼容存储多种类型的类型
	static std::optional<std::string> GetCompatibleType (antlr4::Token* _t, std::initializer_list<std::string> _types) {
		std::vector<std::string> _v { _types };
		return GetCompatibleType (_t, _v);
	}
	static std::optional<std::string> GetCompatibleType (antlr4::Token* _t, std::vector<std::string> &_types) {
		// 标记变量类型
		bool _var = false;
		bool _ref = false;
		bool _option = false;
		for (size_t i = 0; i < _types.size (); ++i) {
			if (_types [i].size () > 0 &&* _types [i].cbegin () == '$') {
				_var = true;
				_types [i].erase (_types [i].begin ());
			}
			if (_types [i].size () > 0 &&* _types [i].crbegin () == '?') {
				_option = true;
				_types [i].erase (_types [i].begin () + (_types [i].size () - 1));
			}
			if (_types [i].size () > 0 &&* _types [i].crbegin () == '&') {
				_ref = true;
				_types [i].erase (_types [i].begin () + (_types [i].size () - 1));
			}
			if (_types [i] == "") {
				_types.erase (_types.begin () + i);
				i--;
			}
		}

		// 移除所有重复元素
		for (size_t i = 1; i < _types.size (); ++i) {
			for (size_t j = 0; j < i; ++j) {
				if (_types [i] == _types [j]) {
					_types.erase (_types.begin () + i);
					--i;
					break;
				}
			}
		}

		// 以第一个元素为基准，合并元素
		while (_types.size () > 1) {
			if (CanImplicitConvTo (*_types.rbegin (), _types [0])) {
				_types.erase (_types.begin () + (_types.size () - 1));
			} else if (CanImplicitConvTo (_types [0],* _types.rbegin ())) {
				_types [0] =* _types.rbegin ();
				_types.erase (_types.begin () + (_types.size () - 1));
			} else {
				LOG_ERROR (_t, std::format ("不兼容的变量类型：{}、{}", _types [0],* _types.rbegin ()));
				return std::nullopt;
			}
		}

		// 如果只剩一个元素
		if (_types.size () == 1) {
			return std::format ("{}{}", _var ? "$" : "", _types [0]);
		}

		LOG_TODO (_t);
		return std::nullopt;
	}

	static bool CanImplicitConvTo (std::string _src, std::string _dest) {
		if (_dest == "") {
			return true;
		} else if (_src == "") {
			return false;
		} else if (_dest == "$") {
			return _src [0] == '$';
		}

		// 移除&符号
		size_t _p = _src.size ();
		if (_src [_p - 1] == '&') {
			_src = _src.erase (_p - 1);
		} else if (_src [_p - 2] == '&') {
			_src = _src.erase (_p - 2);
		}
		_p = _dest.size ();
		if (_dest [_p - 1] == '&') {
			_dest = _dest.erase (_p - 1);
		} else if (_dest [_p - 2] == '&') {
			_dest = _dest.erase (_p - 2);
		}

		// 识别可赋值类型
		bool _s = _src [0] == '$', _d = _dest [0] == '$';
		if ((!_s) && _d) {
			return false;
		} else if (_s && (!_d)) {
			_src = _src.substr (1);
		}

		// 识别可空类型
		_s =* _src.crbegin () == '?';
		_d =* _dest.crbegin () == '?';
		if ((!_s) && _d) {
			_dest = _dest.substr (0, _dest.size () - 1);
		} else if (_s && (!_d)) {
			return false;
		} else if (_s && _d) {
			_src = _src.substr (0, _src.size () - 1);
			_dest = _dest.substr (0, _dest.size () - 1);
		}

		if (_src == _dest)
			return true;
		if (_src == "cptr" && _dest == "hello.fa.string")
			return true;
	 	// TODO
		return false;
	}



	//std::optional<std::tuple<llvm::Type* , std::string>> GetExternType (FaParser::ETypeContext* _etype_ctx) {
	//	auto [_sign, _name, _ptr_level] = m_visitor->visitEType (_etype_ctx).as<std::tuple<bool, std::string, size_t>> ();
	//	// _sign 好像暂时用不到
	//	if (_name == "void") {
	//		if (_ptr_level == 0) {
	//			return std::make_tuple ((llvm::Type* ) llvm::Type::getVoidTy (*m_ctx), std::string ("void"));
	//		} else {
	//			return std::make_tuple ((llvm::Type* ) llvm::Type::getInt8PtrTy (*m_ctx), std::string ("int8*"));
	//		}
	//	} else if (_name == "char") {
	//		if (_ptr_level == 0) {
	//			return std::make_tuple ((llvm::Type* ) llvm::Type::getInt8Ty (*m_ctx), std::string ("int8"));
	//		} else {
	//			return std::make_tuple ((llvm::Type* ) llvm::Type::getInt8PtrTy (*m_ctx), std::string ("int8*"));
	//		}
	//	} else if (_name == "short") {
	//		if (_ptr_level == 0) {
	//			return std::make_tuple ((llvm::Type* ) llvm::Type::getInt16Ty (*m_ctx), std::string ("int16"));
	//		} else {
	//			return std::make_tuple ((llvm::Type* ) llvm::Type::getInt16PtrTy (*m_ctx), std::string ("int16*"));
	//		}
	//	} else if (_name == "int") {
	//		if (_ptr_level == 0) {
	//			return std::make_tuple ((llvm::Type* ) llvm::Type::getInt32Ty (*m_ctx), std::string ("int32"));
	//		} else {
	//			return std::make_tuple ((llvm::Type* ) llvm::Type::getInt32PtrTy (*m_ctx), std::string ("int32*"));
	//		}
	//	} else if (_name == "long") {
	//		if (_ptr_level == 0) {
	//			return std::make_tuple ((llvm::Type* ) llvm::Type::getInt64Ty (*m_ctx), std::string ("int64"));
	//		} else {
	//			return std::make_tuple ((llvm::Type* ) llvm::Type::getInt64PtrTy (*m_ctx), std::string ("int64*"));
	//		}
	//	} else if (_name == "float") {
	//		if (_ptr_level == 0) {
	//			return std::make_tuple ((llvm::Type* ) llvm::Type::getFloatTy (*m_ctx), std::string ("float32"));
	//		} else {
	//			return std::make_tuple ((llvm::Type* ) llvm::Type::getFloatPtrTy (*m_ctx), std::string ("float32*"));
	//		}
	//	} else if (_name == "double") {
	//		if (_ptr_level == 0) {
	//			return std::make_tuple ((llvm::Type* ) llvm::Type::getDoubleTy (*m_ctx), std::string ("float64"));
	//		} else {
	//			return std::make_tuple ((llvm::Type* ) llvm::Type::getDoublePtrTy (*m_ctx), std::string ("float64*"));
	//		}
	//	}
	//	LOG_ERROR (_etype_ctx->start, std::format ("无法识别的外部接口函数类型 [{}]", _name));
	//	return std::nullopt;
	//}

	//std::optional<std::tuple<std::vector<llvm::Type*>, std::vector<std::string>>> GetExternTypes (std::vector<FaParser::ETypeContext*> _types_raw) {
	//	std::vector<llvm::Type*> _types;
	//	std::vector<std::string> _type_strs;
	//	for (FaParser::ETypeContext* _type_raw : _types_raw) {
	//		auto _type = GetExternType (_type_raw);
	//		if (!_type.has_value ())
	//			return std::nullopt;
	//		auto [_type0, _type_str] = _type.value ();
	//		_types.push_back (_type0);
	//		_type_strs.push_back (_type_str);
	//	}
	//	return std::make_tuple (_types, _type_strs);
	//}

private:
	FaVisitor*							m_visitor = nullptr;
	std::shared_ptr<llvm::LLVMContext>	m_ctx = nullptr;
	AstClasses&							m_global_classes;
	std::string							m_namespace;
	std::vector<std::string>&			m_uses;
};



#endif //_TYPE_MAP_HPP__

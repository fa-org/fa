#ifndef __VALUE_BUILDER_HPP__
#define __VALUE_BUILDER_HPP__



#include <llvm/ADT/APFloat.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/Constant.h>
#include <llvm/IR/ConstantFolder.h>
#include <llvm/IR/ConstantRange.h>
#include <llvm/IR/Constants.h>

#include "FaVisitor.h"
#include "FaParser.h"
#include "TypeMap.hpp"



class ValueBuilder {
public:
	ValueBuilder (FaVisitor *_visitor, std::shared_ptr<llvm::LLVMContext> _ctx): m_visitor (_visitor), m_ctx (_ctx) {
		m_etype_map = std::make_shared<TypeMap> (_visitor, m_ctx);
		m_builder = std::make_shared<llvm::IRBuilder<>> (*m_ctx);
	}

	llvm::Value *Build (std::string _type, std::string _value) {
		if (_type == "bool") {
			if (_value == "true") {
				return llvm::ConstantInt::getTrue (*m_ctx);
			} else {
				return llvm::ConstantInt::getFalse (*m_ctx);
			}
		}

		if (_type == "string") {
			return m_builder->CreateGlobalStringPtr (_value);
		}

		llvm::Type *_t = m_etype_map->GetType (_type);
		if (_type.find ("int") != std::string::npos) {
			llvm::APInt _int;
			bool _valid = true;
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
				} else {
					_valid = false;
				}
			} else {
				int64_t _i = std::stoll (_value);
				if (_type == "uint8") {
					_int = llvm::APInt (8, (uint64_t) _i, true);
				} else if (_type == "uint16") {
					_int = llvm::APInt (16, (uint64_t) _i, true);
				} else if (_type == "uint32") {
					_int = llvm::APInt (32, (uint64_t) _i, true);
				} else if (_type == "uint64") {
					_int = llvm::APInt (64, (uint64_t) _i, true);
				} else {
					_valid = false;
				}
			}
			if (_valid)
				return llvm::ConstantInt::get (_t, _int);
		}

		// TODO: 其他类型
		return nullptr;
	}

private:
	FaVisitor *m_visitor = nullptr;
	std::shared_ptr<llvm::LLVMContext> m_ctx = nullptr;
	std::shared_ptr<TypeMap> m_etype_map;
	std::shared_ptr<llvm::IRBuilder<>> m_builder;
};



#endif //__VALUE_BUILDER_HPP__

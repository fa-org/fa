#ifndef __VALUE_BUILDER_HPP__
#define __VALUE_BUILDER_HPP__



#include <llvm/ADT/APFloat.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>

#include "FaVisitor.h"
#include "FaParser.h"
#include "TypeMap.hpp"



class ValueBuilder {
public:
	ValueBuilder (FaVisitor *_visitor, llvm::LLVMContext *_ctx): m_visitor (_visitor), m_ctx (_ctx) {
		m_etype_map = std::make_shared<TypeMap> (_visitor, *m_ctx);
	}

	llvm::Value *Build (std::string _type, std::string _value) {
		if (_type == "bool") {
			return llvm::ConstantInt::get (m_etype_map->GetType (_type), llvm::APInt (8, _value == "true" ? 1 : 0, true));
		} else if (_type == "int32") {
			return llvm::ConstantInt::get (m_etype_map->GetType (_type), llvm::APInt (32, 0, true));
		} else if (_type == "uint32") {
			return llvm::ConstantInt::get (m_etype_map->GetType (_type), llvm::APInt (32, 0, false));
		} else {
			// TODO
		}
	}

private:
	FaVisitor *m_visitor = nullptr;
	llvm::LLVMContext *m_ctx = nullptr;
	std::shared_ptr<TypeMap> m_etype_map;
};



#endif //__VALUE_BUILDER_HPP__

#ifndef __VALUE_BUILDER_HPP__
#define __VALUE_BUILDER_HPP__



#include <format>
#include <functional>
#include <optional>
#include <string>
#include <tuple>

#include <llvm/ADT/APFloat.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/Constant.h>
#include <llvm/IR/ConstantFolder.h>
#include <llvm/IR/ConstantRange.h>
#include <llvm/IR/Constants.h>

#include "FaVisitor.h"
#include "FaParser.h"
#include "TypeMap.hpp"
#include "StringProcessor.hpp"
#include "Log.hpp"

class AstValue;



class ValueBuilder {
public:
	ValueBuilder (std::shared_ptr<TypeMap> _type_map, std::shared_ptr<llvm::LLVMContext> _ctx, std::shared_ptr<llvm::Module> _module);
	std::optional<AstValue> Build (std::string _type, std::string _value, antlr4::Token* _t);

	//std::optional<AstValue> BuildArray (std::string _type, AstValue &_capacity, std::function<std::optional<AstValue> (size_t _index)> _cb) {
	//	std::vector<llvm::Type*> _v;
	//	_v.push_back (m_type_map->GetArrayType (_type, _capacity).value ());
	//	_v.push_back (m_type_map->GetType ("int32").value ());
	//	_v.push_back (m_type_map->GetType ("int32").value ());
	//	auto _stype = llvm::StructType::create (_v);
	//	llvm::AllocaInst* _inst = m_builder->CreateAlloca (_stype);
	//	//llvm::Value* _val_size = m_builder->CreateStructGEP (_inst, 0);
	//	//llvm::Value* _val_capacity = m_builder->CreateStructGEP (_inst, 1);
	//	AstValue _val_capacity { m_builder->CreateStructGEP (_inst, 1), _capacity.GetType () };
	//}

private:
	std::shared_ptr<llvm::LLVMContext> m_ctx = nullptr;
	std::shared_ptr<TypeMap> m_type_map;
	std::shared_ptr<llvm::IRBuilder<>> m_builder;
	std::shared_ptr<llvm::Module> m_module;
};



#endif //__VALUE_BUILDER_HPP__

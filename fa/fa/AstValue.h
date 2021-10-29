#ifndef __AST_VALUE_HPP__
#define __AST_VALUE_HPP__



#include <format>
#include <functional>
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <tuple>

#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/IRBuilder.h>

#include <FaParser.h>
#include "ValueBuilder.h"
#include "TypeMap.hpp"
#include "Log.hpp"
#include "FuncType.h"

class FuncType;



class AstValue {
	enum class AstObjectType { /*None,*/ Void, Value, Var, Func, TypeStr, MemberStr, ArrVar };

public:
	static AstValue FromVoid ();
	static std::optional<AstValue> FromValue (std::shared_ptr<ValueBuilder> _value_builder, std::string _value, std::string _type, antlr4::Token* _t = nullptr);
	AstValue ();
	//AstValue (std::nullopt_t);
	AstValue (std::shared_ptr<ValueBuilder> _value_builder, FaParser::LiteralContext* _literal);
	AstValue (llvm::AllocaInst* _var, std::string _value_type);
	AstValue (llvm::AllocaInst* _arr, llvm::AllocaInst* _arr_size, llvm::AllocaInst* _arr_capacity, std::string _value_type);
	AstValue (llvm::Value* _value, std::string _value_type);
	AstValue (std::shared_ptr<FuncType> _func, llvm::Function* _fp);
	AstValue (std::string _member);
	//AstValue &operator= (const llvm::AllocaInst* _val);
	//AstValue &operator= (const llvm::Value* _val);
	//AstValue &operator= (const llvm::Function* _val);
	AstValue& operator= (const AstValue& _o) = default;

	//bool IsValid () const;
	bool IsVoid () const;
	bool IsValue () const;
	bool IsVariable () const;
	bool IsFunction () const;
	bool IsTypeStr () const;
	bool IsMember () const;

	llvm::Value* Value (llvm::IRBuilder<>& _builder);
	llvm::Value* ValueRaw ();
	llvm::CallInst* FuncInvoke (llvm::IRBuilder<>& _builder, std::vector<llvm::Value*>& _args);
	std::optional<AstValue> DoOper1 (llvm::IRBuilder<>& _builder, std::shared_ptr<ValueBuilder> _value_builder, std::string _op, antlr4::Token* _t);
	std::optional<AstValue> DoOper2 (llvm::IRBuilder<>& _builder, std::shared_ptr<ValueBuilder> _value_builder, std::string _op, AstValue& _other, antlr4::Token* _t, std::shared_ptr<FuncTypes> _global_funcs, AstClasses& _global_classes, std::string _namespace, std::vector<std::string>& _uses);

	std::string GetType ();
	void SetType (std::string _value_type);

	bool GetTmpVarFlag ();
	void SetTmpVarFlag (bool _tmp_var_flag);

	AstValue GetArrSize ();
	AstValue GetArrCapacity ();

	std::string GetFuncReturnType ();
	std::tuple<std::string, std::vector<std::string>> GetFuncType ();

private:
	AstObjectType				m_type = AstObjectType::Void;
	llvm::Value*				m_value = nullptr, * m_value_size = nullptr, * m_value_capacity = nullptr;
	llvm::Function*				m_fp = nullptr;
	std::string					m_value_type = "";
	bool						m_tmp_var_flag = false;

public:
	std::shared_ptr<FuncType>	m_func;
	std::string					m_member = "";
};



#endif //__AST_VALUE_HPP__

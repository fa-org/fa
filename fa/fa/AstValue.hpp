#ifndef __AST_VALUE_HPP__
#define __AST_VALUE_HPP__



#include <optional>
#include <string>

#include <llvm/IR/Value.h>

#include <FaParser.h>
#include "ValueBuilder.hpp"
#include "Log.hpp"



class AstValue {
	enum class AstValueType { None, Value, Variable };

public:
	AstValue () {}
	AstValue (std::shared_ptr<ValueBuilder> _value_builder, FaParser::LiteralContext *_literal) {
		std::optional<llvm::Value *> _val;
		if (_literal->BoolLiteral ()) {
			_val = _value_builder->Build ("bool", _literal->getText (), _literal->start);
		} else if (_literal->IntLiteral ()) {
			_val = _value_builder->Build ("int32", _literal->getText (), _literal->start);
		} else if (_literal->FloatLiteral ()) {
			_val = _value_builder->Build ("float64", _literal->getText (), _literal->start);
		} else if (_literal->String1Literal ()) {
			std::string _data1 = _literal->getText ();
			_data1 = _data1.substr (1, _data1.size () - 2);
			std::string _data2;
			_data2.reserve (_data1.size ());
			_val = _value_builder->Build ("string", _literal->getText (), _literal->start);
		} else {
			LOG_ERROR (_literal->start, "未知的表达式");
		}

		if (_val.has_value ()) {
			m_type = AstValueType::Value;
			m_value = _val.value ();
		}
	}

private:
	AstValueType m_type = AstValueType::None;
	llvm::Value *m_value = nullptr;
};



#endif //__AST_VALUE_HPP__

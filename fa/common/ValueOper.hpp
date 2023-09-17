#ifndef __VALUE_OPER_HPP__
#define __VALUE_OPER_HPP__



#include <cstdint>
#include <cstdlib>
#include <string>
#include <type_traits>
#include <variant>

#include "../ASTs/Exprs/AstExpr_value.hpp"
#include "../ASTs/Types/AstType_bool.hpp"
#include "../ASTs/Types/AstType_class.hpp"
#include "../ASTs/Types/AstType_float.hpp"
#include "../ASTs/Types/AstType_int.hpp"
#include "../ASTs/Types/IAstType.hpp"



struct PAstExpr;



struct ValueOper {
	inline static std::set<std::string> s_op_compares { ">", ">=", "<", "<=", "==", "!=" };
	inline static std::set<std::string> s_op_algorithms { "??", "+", "-", "*", "**", "/", "%", "&", "|", "^", "&&", "||", "<<", ">>" };
	inline static std::set<std::string> s_op_assigns { "=", "??=", "+=", "-=", "*=", "**=", "/=", "%=", "&=", "|=", "^=", "&&=", "||=", "<<=", ">>=" };

	static PAstExpr DoOper2 (antlr4::Token *_token, std::string _op, AstValue_t _v1, AstValue_t _v2) {
		//if (_v1.index () == _v2.index ()) {
		//	if (s_op_compares.contains (_op)) {
		//		if (_op == "==") {
		//			return AstExpr_value::MakeBool (_token, _v1 == _v2);
		//		} else if (_op == "!=") {
		//			return AstExpr_value::MakeBool (_token, _v1 != _v2);
		//		} else {
		//			switch (_v1.index ()) {
		//				case 2:
		//				{
		//					int64_t _n1 = std::get<2> (_v1), _n2 = std::get<2> (_v2);
		//					if (_op == ">") {
		//						return AstExpr_value::MakeBool (_token, _n1 > _n2);
		//					} else if (_op == ">=") {
		//						return AstExpr_value::MakeBool (_token, _n1 >= _n2);
		//					} else if (_op == "<") {
		//						return AstExpr_value::MakeBool (_token, _n1 < _n2);
		//					} else if (_op == "<=") {
		//						return AstExpr_value::MakeBool (_token, _n1 <= _n2);
		//					}
		//				}
		//				case 3:
		//				{
		//					uint64_t _n1 = std::get<3> (_v1), _n2 = std::get<3> (_v2);
		//					if (_op == ">") {
		//						return AstExpr_value::MakeBool (_token, _n1 > _n2);
		//					} else if (_op == ">=") {
		//						return AstExpr_value::MakeBool (_token, _n1 >= _n2);
		//					} else if (_op == "<") {
		//						return AstExpr_value::MakeBool (_token, _n1 < _n2);
		//					} else if (_op == "<=") {
		//						return AstExpr_value::MakeBool (_token, _n1 <= _n2);
		//					}
		//				}
		//				case 4:
		//				{
		//					double _d1 = std::get<4> (_v1), _d2 = std::get<4> (_v2);
		//					if (_op == ">" || _op == ">=") {
		//						return AstExpr_value::MakeBool (_token, _d1 + 0.000001 >= _d2);
		//					} else {
		//						return AstExpr_value::MakeBool (_token, _d1 - 0.000001 <= _d2);
		//					}
		//				}
		//			}
		//		}
		//	} else if (s_op_algorithms.contains (_op)) {
		//		switch (_v1.index ()) {
		//			case 0:
		//			{
		//				std::string _s1 = std::get<0> (_v1), _s2 = std::get<0> (_v2);
		//				if (_op == "+") {
		//					return AstExpr_value::MakeString (_token, _s1 + _s2);
		//				} else if (_op == "||") {
		//					return AstExpr_value::MakeString (_token, _s1 != "" ? _s1 : _s2);
		//				}
		//			}
		//			case 1:
		//			{
		//				bool _b1 = std::get<1> (_v1), _b2 = std::get<1> (_v2);
		//				if (_op == "&&") {
		//					return AstExpr_value::MakeBool (_token, _b1 && _b2);
		//				} else if (_op == "||") {
		//					return AstExpr_value::MakeBool (_token, _b1 || _b2);
		//				}
		//			}
		//			case 2:
		//			{
		//				int64_t _n1 = std::get<2> (_v1), _n2 = std::get<2> (_v2);
		//				auto _int_type = AstType_int::Make (_token, 64, true);
		//				int64_t _val = 0;
		//				if (_op == "+") {
		//					_val = _n1 + _n2;
		//				} else if (_op == "-") {
		//					_val = _n1 - _n2;
		//				} else if (_op == "*") {
		//					_val = _n1 * _n2;
		//				} else if (_op == "/") {
		//					_val = _n1 / _n2;
		//				} else if (_op == "%") {
		//					_val = _n1 % _n2;
		//				} else if (_op == "**") {
		//					_val = (int64_t) ::pow (_n1, _n2);
		//				}
		//				return AstExpr_value::Make (_token, _int_type, std::format ("{}", _val));
		//			}
		//			case 3:
		//			{
		//				uint64_t _n1 = std::get<3> (_v1), _n2 = std::get<3> (_v2);
		//				auto _int_type = AstType_int::Make (_token, 64, false);
		//				uint64_t _val = 0;
		//				if (_op == "+") {
		//					_val = _n1 + _n2;
		//				} else if (_op == "-") {
		//					_val = _n1 - _n2;
		//				} else if (_op == "*") {
		//					_val = _n1 * _n2;
		//				} else if (_op == "/") {
		//					_val = _n1 / _n2;
		//				} else if (_op == "%") {
		//					_val = _n1 % _n2;
		//				} else if (_op == "**") {
		//					_val = (uint64_t) ::pow (_n1, _n2);
		//				}
		//				return AstExpr_value::Make (_token, _int_type, std::format ("{}", _val));
		//			}
		//			case 4:
		//			{
		//				double _d1 = std::get<4> (_v1), _d2 = std::get<4> (_v2), _val = 0.0;
		//				if (_op == "+") {
		//					_val = _d1 + _d2;
		//				} else if (_op == "-") {
		//					_val = _d1 - _d2;
		//				} else if (_op == "*") {
		//					_val = _d1 * _d2;
		//				} else if (_op == "/") {
		//					_val = _d1 / _d2;
		//				} else if (_op == "**") {
		//					_val = ::pow (_d1, _d2);
		//				} else {
		//					throw fa::Exception (_token, "not implement");
		//				}
		//				return AstExpr_value::MakeFloat64 (_token, std::format ("{}", _d1 + _d2));
		//			}
		//		}
		//	} else if (s_op_assigns.contains (_op)) {

		//	}
		//} else {

		//}
		throw fa::Exception (_token, "not implement");
	}
};



#endif //__VALUE_OPER_HPP__

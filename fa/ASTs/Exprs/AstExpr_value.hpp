#ifndef __AST_EXPR_VALUE_HPP__
#define __AST_EXPR_VALUE_HPP__



#include <memory>
#include <string>
#include <type_traits>

#include "AstExpr_type_wrap.hpp"
#include "IAstExpr.hpp"
#include "../Types/AstType_bool.hpp"
#include "../Types/AstType_float.hpp"
#include "../Types/AstType_int.hpp"
#include "../Types/AstType_temp_name.hpp"
#include "../Types/AstType_unsure_wrap.hpp"
#include "../Types/IAstType.hpp"
#include "../Stmts/IAstStmt.hpp"



struct AstExpr_value: public IAstExpr {
	AstValue_t m_value;

	AstExpr_value (antlr4::Token *_token): IAstExpr (_token) {}
	AstExpr_value (antlr4::Token *_token, AstValue_t _value): IAstExpr (_token), m_value (_value) {
		if (!s_literal_name.contains (_value.index ()))
			throw fa::Exception (m_token, "not implement");
		auto _ovtype = CompileEnv::FindName (_token, s_literal_name [_value.index ()], {});
		if (_ovtype.has_value ()) {
			if (auto _type = dynamic_cast<AstExpr_type_wrap *> (_ovtype.value ().get ())) {
				m_real_type = _type->m_type;
			}
		}
		m_real_type = AstType_temp_name::Make (_token, s_literal_name [_value.index ()]);
	}

	void SetMembers (fa::ParseType _type, std::vector<AstObj *> _values) override {
		if (_type == fa::ParseType::Part_ValueExpr) {
			m_value = std::shared_ptr<IAstExpr> (dynamic_cast<IAstExpr *> (_values [0]));
		} else if (_type == fa::ParseType::Part_ValueStmt) {
			m_value = std::shared_ptr<IAstStmt> (dynamic_cast<IAstStmt *> (_values [0]));
		} else if (_type == fa::ParseType::Part_ValueType) {
			m_value = std::shared_ptr<IAstType> (dynamic_cast<IAstType *> (_values [0]));
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	void SetValues (fa::ParseValueType _type, std::vector<fa::ParseValue_t> _values) override {
		if (_type == fa::ParseValueType::Value) {
			switch ((uint8_t) _values [0].index ()) {
				case 0:
					m_value = std::get<0> (_values [0]);
					m_real_type = AstType_temp_name::Make (m_token, "string");
					return;
				case 1:
					m_value = std::get<1> (_values [0]);
					m_real_type = AstType_bool::Make (m_token);
					return;
				case 2:
					m_value = std::get<2> (_values [0]);
					m_real_type = AstType_int::Make (m_token, 0, true);
					return;
				case 3:
					m_value = std::get<3> (_values [0]);
					m_real_type = AstType_int::Make (m_token, 0, false);
					return;
				case 4:
					m_value = std::get<4> (_values [0]);
					m_real_type = AstType_float::Make (m_token, 0);
					return;
			}
		}
		throw fa::Exception (m_token, "not implement");
	}

	std::optional<PAstType> GuessType () override { return m_real_type.value (); }

	PAstExpr ProcessCodeType (std::optional<PAstType> _type) override {
		if (_type == std::nullopt)
			_type = m_real_type;

		if (_type.has_value ()) {
			//m_real_type = m_real_type.value ()->ProcessDeclareType ();
			if (m_real_type.value ().IsSame (_type.value ())) {
				if (!dynamic_cast<AstType_unsure_wrap *> (_type.value ().get ()))
					m_real_type = _type;
				return shared_from_this ();
			}

			// TODO 判断是否能直接隐式转换
			if (auto _inttypesrc = dynamic_cast<AstType_int *> (m_real_type.value ().get ())) {
				if (auto _inttype = dynamic_cast<AstType_int *> (_type.value ().get ())) {
					if (_inttypesrc->m_bit_width == 0) {
						if (_inttype->m_bit_width == 0) {
							m_real_type = AstType_int::Make (m_token, 64, true);
						} else {
							m_real_type = _type;
						}
					} else {
						if (_inttypesrc->m_sign && !_inttype->m_sign)
							throw fa::Exception (m_token, "有符号数无法转为无符号类型");
						if (_inttypesrc->m_bit_width > _inttype->m_bit_width)
							throw fa::Exception (m_token, "类型无法存储太大的数字");
						m_real_type = _type;
					}
					return shared_from_this ();
				} else if (auto _inttype = dynamic_cast<AstType_float *> (_type.value ().get ())) {
					m_real_type = _type;
					return shared_from_this ();
				}
			}
		}
		throw fa::Exception (m_token, "not implement");
	}

	std::optional<PAstExpr> Evaluate (Evaluation &_eval) override { return shared_from_this (); }

	static PAstExpr Make (antlr4::Token *_token, AstValue_t _value) {
		return std::shared_ptr<IAstExpr> (new AstExpr_value { _token, _value });
	}
};



#endif //__AST_EXPR_VALUE_HPP__

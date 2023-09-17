#ifndef __AST_EXPR_OP2_HPP__
#define __AST_EXPR_OP2_HPP__



#include <memory>
#include <set>
#include <string>

#include "AstExpr_op1.hpp"
#include "AstExpr_temp_name.hpp"
#include "IAstExpr.hpp"
#include "../Stmts/IAstStmt.hpp"
#include "../Types/AstType_bool.hpp"
#include "../Types/AstType_float.hpp"
#include "../Types/AstType_int.hpp"
#include "../Types/AstType_class.hpp"
#include "../../common/CompileEnv.hpp"
#include "../../common/ValueOper.hpp"



struct AstExpr_op2: public IAstExpr {
	PAstExpr m_left, m_right;
	std::string m_op = "";

	AstExpr_op2 (antlr4::Token *_token): IAstExpr (_token), m_left (nullptr), m_right (nullptr) {}
	AstExpr_op2 (antlr4::Token *_token, PAstExpr _left, std::string _op, PAstExpr _right):
		IAstExpr (_token), m_left (_left), m_op (_op), m_right (_right) {}

	void SetMembers (fa::ParseType _type, std::vector<AstObj *> _values) override {
		if (_type == fa::ParseType::Part_Member) {
			m_left = std::shared_ptr<IAstExpr> (dynamic_cast<IAstExpr *> (_values [0]));
		} else if (_type == fa::ParseType::Part_Member2) {
			m_right = std::shared_ptr<IAstExpr> (dynamic_cast<IAstExpr *> (_values [0]));
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	void SetValues (fa::ParseValueType _type, std::vector<fa::ParseValue_t> _values) override {
		if (_type == fa::ParseValueType::Operator) {
			m_op = std::get<std::string> (_values [0]);
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	std::optional<PAstType> GuessType () override { throw fa::Exception (m_token, "not implement"); }

	PAstExpr ProcessCodeType (std::optional<PAstType> _type) override {
		if (ValueOper::s_op_compares.contains (m_op)) {
			return ProcessCodeType_compare (_type);
		} else if (ValueOper::s_op_algorithms.contains (m_op)) {
			return ProcessCodeType_algorithm (_type);
		} else if (ValueOper::s_op_assigns.contains (m_op)) {
			return ProcessCodeType_assign (_type);
		} else if (m_op == "." || m_op == "?.") {
			m_left = m_left->ProcessCodeType (std::nullopt);
			std::string _name = dynamic_cast<AstExpr_temp_name *> (m_right.get ())->m_name;
			auto _oret = CompileEnv::FindName (m_left, _name, {});
			if (!_oret.has_value ()) {
				//auto _arr_type = dynamic_cast<AstType_class *> (m_left->m_real_type.value ().get ());
				//if (_arr_type && _arr_type->m_type_name == "fa.List") {
				//	return AstExpr_buildin_access::Make (m_token, m_left, _name);
				//}
				throw fa::Exception (m_token, "无法识别的符号 {}", _name);
			}
			auto _ret = _oret.value ()->ProcessCodeType (_type);
			if (m_op == "?.") {
				auto _ret_type = _ret->m_real_type.value ();
				if (auto _ret_ptype = dynamic_cast<AstType_class *> (_ret_type.get ()); (!_ret_ptype) || _ret_ptype->m_class->m_full_name != "fa.Option") {
					_ret->m_real_type = CompileEnv::FindName (m_token, "fa.Option", { _ret_type }).value ()->TryAsType ();
				}
			}
			return _ret;
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	PAstExpr ProcessCodeType_compare (std::optional<PAstType> _type) {
		auto _left = m_left->ProcessCodeType (std::nullopt);
		auto _right = m_right->ProcessCodeType (std::nullopt);
		if (auto _left_int = dynamic_cast<AstType_int *> (_left->m_real_type.value ().get ())) {
			if (auto _right_int = dynamic_cast<AstType_int *> (_right->m_real_type.value ().get ())) {
				if (_left_int->m_sign != _right_int->m_sign && _left_int->m_bit_width > 0 && _right_int->m_bit_width > 0)
					throw fa::Exception (m_token, "有符号数字与无符号数字不能直接判断");
				if (_left_int->m_bit_width < _right_int->m_bit_width) {
					m_left = m_left->ProcessCodeType (_right->m_real_type);
					m_right = _right;
				} else if (_left_int->m_bit_width > _right_int->m_bit_width) {
					m_left = _left;
					m_right = m_right->ProcessCodeType (_left->m_real_type);
				} else {
					m_left = _left;
					m_right = _right;
				}
				m_real_type = AstType_bool::Make (m_token);
				return shared_from_this ();
			}
		}
		throw fa::Exception (m_token, "not implement");
	}

	PAstExpr ProcessCodeType_algorithm (std::optional<PAstType> _type) {
		 if (m_op == "??") {
			m_left = m_left->ProcessCodeType (std::nullopt);
			m_right = m_right->ProcessCodeType (std::nullopt);
			auto _opt_expr = dynamic_cast<AstType_class *> (m_left->m_real_type.value ().get ());
			if (_opt_expr && _opt_expr->m_class->m_full_name == "fa.Option") {
				if (m_left->m_real_type.value ().IsSame (m_right->m_real_type.value ()) || _opt_expr->m_template_types[0].IsSame (m_right->m_real_type.value ())) {
					m_real_type = m_right->m_real_type;
					return shared_from_this ();
				}
			}
		} else if (m_op == "&&" || m_op == "||") {
			m_left = m_left->ProcessCodeType (AstType_bool::Make (m_token));
			m_right = m_right->ProcessCodeType (AstType_bool::Make (m_token));
			m_real_type = AstType_bool::Make (m_token);
			return shared_from_this ();
		} else {
			if (m_op == "*") {
				PAstExpr _left { nullptr };
				_left = m_left->ProcessCodeType (std::nullopt);
				if (_left->m_real_type.value ()->GetTypeName () == "fa.String") {
					// TODO 字符串拷贝多次
					m_right = m_right->ProcessCodeType (AstType_int::Make (m_token, 0, false));
					throw fa::Exception (m_token, "not implement");
				}
			}
			m_left = m_left->ProcessCodeType (AstType_int::Make (m_token, 0, false));
			m_right = m_right->ProcessCodeType (AstType_int::Make (m_token, 0, false));
			m_real_type = m_left->m_real_type;
			return shared_from_this ();
		}
		throw fa::Exception (m_token, "not implement");
	}

	PAstExpr ProcessCodeType_assign (std::optional<PAstType> _type) {
		if (m_op == "=") {
			try {
				m_left = m_left->ProcessCodeType (_type);
				m_right = m_right->ProcessCodeType (m_left->m_real_type.value ());
			} catch (...) {
				m_right = m_right->ProcessCodeType (std::nullopt);
				m_left = m_left->ProcessCodeType (m_right->m_real_type.value ());
			}
			m_real_type = m_left->m_real_type;
			return shared_from_this ();
		} else if (m_op == "??=") {
			m_left = m_left->ProcessCodeType (std::nullopt);
			m_right = m_right->ProcessCodeType (std::nullopt);
			auto _opt_expr = dynamic_cast<AstType_class *> (m_left->m_real_type.value ().get ());
			if (_opt_expr && _opt_expr->m_class->m_full_name == "fa.Option") {
				if (m_left->m_real_type.value ().IsSame (m_right->m_real_type.value ()) || _opt_expr->m_template_types[0].IsSame (m_right->m_real_type.value ())) {
					m_real_type = m_right->m_real_type;
					return shared_from_this ();
				}
			}
		} else if (m_op == "&&=" || m_op == "||=") {
			m_left = m_left->ProcessCodeType (AstType_bool::Make (m_token));
			m_right = m_right->ProcessCodeType (AstType_bool::Make (m_token));
			m_real_type = m_left->m_real_type;
			return shared_from_this ();
		} else {
			m_left = m_left->ProcessCodeType (std::nullopt);
			m_right = m_right->ProcessCodeType (m_left->m_real_type);
			m_real_type = m_left->m_real_type;
			return shared_from_this ();
		}
		throw fa::Exception (m_token, "not implement");
	}

	std::optional<PAstExpr> Evaluate (Evaluation &_eval) override {
		auto _left = dynamic_cast <AstExpr_value *> (m_left->Evaluate (_eval).value ().get ());
		auto _right = dynamic_cast <AstExpr_value *> (m_right->Evaluate (_eval).value ().get ());
		return ValueOper::DoOper2 (m_token, m_op, _left->m_value, _right->m_value);
	}

	static PAstExpr Make (antlr4::Token *_token, PAstExpr _left, std::string _op, PAstExpr _right) {
		return std::shared_ptr<IAstExpr> (new AstExpr_op2 { _token, _left, _op, _right });
	}
};



#endif //__AST_EXPR_OP2_HPP__

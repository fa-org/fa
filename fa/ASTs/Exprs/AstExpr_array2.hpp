#ifndef __AST_EXPR_ARRAY2_HPP__
#define __AST_EXPR_ARRAY2_HPP__



#include <memory>
#include <sstream>
#include <string>

#include "IAstExpr.hpp"
#include "../Types/AstType_class.hpp"
#include "../Types/IAstType.hpp"



struct AstExpr_array2: public IAstExpr {
	std::vector<PAstExpr> m_items;

	AstExpr_array2 (antlr4::Token *_token): IAstExpr (_token) {}
	AstExpr_array2 (antlr4::Token *_token, std::vector<PAstExpr> _items):
		IAstExpr (_token), m_items (_items) {}



	std::optional<PAstType> GuessType () override {
		if (m_items.size () == 0)
			return std::nullopt;
		auto _ttype = m_items [0]->GuessType ();
		if (!_ttype.has_value ())
			return std::nullopt;
		for (size_t i = 1; i < m_items.size (); ++i) {
			auto _ttype2 = m_items [i]->GuessType ();
			if (!_ttype2.has_value ())
				return std::nullopt;
			if (!_ttype.value ().IsSame (_ttype2.value ()))
				return std::nullopt;
		}
		if (auto _otype = CompileEnv::FindName (m_token, "fa.List", { _ttype.value () }); _otype.has_value ())
			return _otype.value ()->TryAsType ();
		return std::nullopt;
	}

	PAstExpr ProcessCodeType (std::optional<PAstType> _type) override {
		if (_type != std::nullopt)
			m_real_type = _type;
		if (m_real_type == std::nullopt)
			m_real_type = GuessType ();
		if (m_real_type == std::nullopt)
			throw fa::Exception (m_token, "无法识别列表元素数据类型");
		auto _arr_type = dynamic_cast<AstType_class *> (m_real_type.value ().get ());
		if (_arr_type && _arr_type->m_class->m_full_name == "fa.List") {
			for (size_t i = 0; i < m_items.size (); ++i) {
				m_items [i] = m_items [i]->ProcessCodeType (_arr_type->m_template_types [0]);
			}
			return shared_from_this ();
		} else {
			throw fa::Exception (m_token, "类型错误，列表只能为列表类型");
		}
	}

	std::optional<PAstExpr> Evaluate (Evaluation &_eval) override { throw fa::Exception (m_token, "not implement"); }

	static PAstExpr Make (antlr4::Token *_token, std::vector<PAstExpr> _items) {
		return std::shared_ptr<IAstExpr> (new AstExpr_array2 { _token, _items });
	}
};



#endif //__AST_EXPR_ARRAY2_HPP__

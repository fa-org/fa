#ifndef __AST_TYPE_FUNC_TEMPLATE_HPP__
#define __AST_TYPE_FUNC_TEMPLATE_HPP__



#include <format>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "IAstType.hpp"



struct AstClassFuncEmpty;

struct AstType_func_template: public IAstType {
	std::shared_ptr<AstClassFuncEmpty> m_empty_func;
	size_t m_template_index = 0;

	AstType_func_template (antlr4::Token *_token): IAstType (_token), m_empty_func (nullptr) {}
	AstType_func_template (antlr4::Token *_token, std::shared_ptr<AstClassFuncEmpty> _empty_func, size_t _template_index):
		IAstType (_token), m_empty_func (_empty_func), m_template_index (_template_index) {}

	PAstType ProcessDeclareType () override {
		if (m_func_cb) {
			if (auto _ret = m_func_cb (this); _ret.has_value ())
				return _ret.value ();
		}
		throw fa::Exception (m_token, "not implement");
	}

	std::vector<AstType_unsure_wrap *> GetTypeTemplates () override {
		throw fa::Exception (m_token, "not implement");
	}

	bool NeedSure () override { return true; }

	std::string GetTypeName () override {
		throw fa::Exception (m_token, "not implement");
	}

	static PAstType Make (antlr4::Token *_token, std::shared_ptr<AstClassFuncEmpty> _empty_func, size_t _template_index) {
		return std::shared_ptr<IAstType> (new AstType_func_template { _token, _empty_func, _template_index });
	}

	static void SetFuncTemplateProcessor (std::function<std::optional<PAstType> (AstType_func_template *type)> _cb) { m_func_cb = _cb; }

private:
	inline static std::function<std::optional<PAstType> (AstType_func_template *type)> m_class_cb, m_func_cb;
};



#endif //__AST_TYPE_FUNC_TEMPLATE_HPP__

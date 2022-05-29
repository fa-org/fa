#ifndef __AST_CLASS_HPP__
#define __AST_CLASS_HPP__



#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "AstClassVar.hpp"
#include "AstClassFunc.hpp"
#include "../IAst.hpp"
#include "../../Common.hpp"



struct AstClass: public IAst {
	PublicLevel m_level;
	std::string m_name = "";
	std::vector<std::shared_ptr<AstClassVar>> m_vars;
	std::vector<std::shared_ptr<AstClassFunc>> m_funcs;

	AstClass (FaParser::ClassBlockContext *_ctx) {
		m_level = GetPublicLevel (_ctx->publicLevel ());
		m_name = GetId (_ctx->id ());
		for (auto _item : _ctx->classItem ()) {
			if (_item->classItemFuncExt ()) {
				m_funcs.push_back (AstClassFunc::FromCtx (_item));
			} else {
				m_vars.push_back (AstClassVar::FromCtx (_item));
			}
		}
	}

	std::string GenCppCode (size_t _indent) override {
		std::stringstream _ss {};
		_ss << std::format ("{}struct {} {{\n", Indent (_indent), m_name);
		_ss << std::format ("{}public:\n", Indent (_indent));
		for (auto _var : m_vars)
			_ss << _var->GenCppCode (_indent + 1);
		for (auto _func : m_funcs)
			_ss << _func->GenCppCode (_indent + 1);
		_ss << std::format ("{}}};\n", Indent (_indent));
		return _ss.str ();
	}

	static std::shared_ptr<AstClass> FromCtx (FaParser::ClassBlockContext *_ctx) {
		return std::make_shared<AstClass> (_ctx);
	}
};



#endif //__AST_CLASS_HPP__
